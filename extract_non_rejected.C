void extract_non_rejected()
{
  TFile file("AnalysisResults.root", "READ");

  TDirectory* dirLc2V0bachelor = file.GetDirectory("PWGHF_TreeCreator");
  TTree* treeEvent = (TTree*)dirLc2V0bachelor->Get("tree_event_char");
  TTree* treeCand = (TTree*)dirLc2V0bachelor->Get("tree_Lc2V0bachelor");

  TDirectory* dirLc2V0bachelorStd = file.GetDirectory("/PWG3_D2H_Lc2pK0S_0");///chist0");
  //dirLc2V0bachelorStd->cd("chist0");
  std::cout << dirLc2V0bachelorStd << std::endl;
  std::cout << dirLc2V0bachelorStd->GetName() << std::endl;
  dirLc2V0bachelorStd->ls();
  TH1* cHist = (TH1*)((TList*)dirLc2V0bachelorStd->Get("chist0"))->At(0);


  Int_t is_ev_rej;
  UInt_t ev_id;
  Int_t run_number;

  UInt_t ev_id_cand;
  Int_t run_number_cand;

  treeEvent->SetBranchAddress("is_ev_rej", &is_ev_rej);
  treeEvent->SetBranchAddress("ev_id", &ev_id);
  treeEvent->SetBranchAddress("run_number", &run_number);

  treeCand->SetBranchAddress("ev_id", &ev_id_cand);
  treeCand->SetBranchAddress("run_number", &run_number_cand);


  Int_t sel = 0;
  Int_t rej = 0;

  std::vector<UInt_t> evIdsEvents;
  //std::vector<Int_t> runNumbersEvents;


  Int_t nEntries = treeEvent->GetEntriesFast();

  for(int i = 0; i < nEntries; i++) {
    treeEvent->GetEvent(i);

    if(is_ev_rej == 0) {
      evIdsEvents.push_back(ev_id);
      //runNumbersEvents.push_back(run_number)
      sel++;
    } else {
      rej++;
    }
  }


  std::cout << "### EVENT TREE ###\n"
            << "Selected: " << sel << "\n"
            << "Rejected: " << rej << "\n"
            << "Total: " << nEntries << "\n"
            << "STD analysis selected: " << cHist->GetBinContent(8) << "\n";



  Int_t selCand = 0;

  Int_t nEntriesCand = treeCand->GetEntriesFast();
  for(int i = 0; i < nEntriesCand; i++) {
    treeCand->GetEvent(i);
    for(int j = 0; j < evIdsEvents.size(); j++) {
      if(ev_id_cand == evIdsEvents[j]) {
        selCand++;
      }
    }
  }
  std::cout << "### CAND TREE ###\n"
            << "Selected: " << selCand << "\n"
            << "Total: " << nEntriesCand << std::endl;
  file.Close();
}
