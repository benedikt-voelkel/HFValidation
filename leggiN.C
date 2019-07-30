void leggiN(){

  TFile *f=TFile::Open("AnalysisResults.root");

  TDirectoryFile *dirT = (TDirectoryFile*)f->Get("PWGHF_TreeCreator");
  //TDirectoryFile *dirL = (TDirectoryFile*)f->Get("PWG3_D2H_InvMassLambdac");
  TDirectoryFile *dirL = (TDirectoryFile*)f->Get("PWG3_D2H_Lc2pK0s_0");
  TList *list=(TList*)dirL->Get("coutputLcpptest");
  TH1F *hLc=(TH1F*)list->FindObject("hMassPt5TC");
  TH1F *hMtree=(TH1F*)hLc->Clone("clone");
  hMtree->Reset("icse");
//0 1-2; 1 2-3; 2 3-4; 3 4-5; 4 5-6; 5 6-8
  Float_t cut=6;
  Float_t cut2=8.;

  TTree *tree=(TTree*)dirT->Get("tree_LctopKpi");
  TTree *treeEv=(TTree*)dirT->Get("tree_event_char");

  Int_t nev=tree->GetEntries();
  Int_t nevEv=treeEv->GetEntries();
  //cout<< " nev " << nev << " nevEv " << nevEv << endl;

  Int_t cand_type;
  Float_t pt_cand,inv_mass,dist_12,dist_23,d_len, y_cand;
  UInt_t ev_id, ev_id_Ev;
  Int_t is_ev_rej, run_number, run_number_Ev;

  tree->SetBranchAddress("cand_type",&cand_type);
  tree->SetBranchAddress("y_cand",&y_cand);
  tree->SetBranchAddress("pt_cand",&pt_cand);
  tree->SetBranchAddress("inv_mass",&inv_mass);
  tree->SetBranchAddress("dist_12",&dist_12);
  tree->SetBranchAddress("dist_23",&dist_23);
  tree->SetBranchAddress("d_len",&d_len);
  tree->SetBranchAddress("ev_id",&ev_id);
  tree->SetBranchAddress("run_number",&run_number);

  treeEv->SetBranchAddress("is_ev_rej",&is_ev_rej);
  treeEv->SetBranchAddress("ev_id",&ev_id_Ev);
  treeEv->SetBranchAddress("run_number",&run_number_Ev);

  std::vector<int> vec_evt(0);
  std::vector<int> vec_run(0);
  for(int i=0; i<nevEv; i++){
    treeEv->GetEntry(i);
    if(is_ev_rej==0){
      vec_evt.push_back(ev_id_Ev);
      //      vec_run.push_back(run_number_Ev);
      //cout<< " ev_id_Ev " << ev_id_Ev << endl;
  }
  }
  for(Int_t k=0;k<nev;k++){
    tree->GetEntry(k);
    Bool_t fid=kFALSE;
    Bool_t isSelected = kFALSE;

    //    for(int j=0; j<vec_evt.size(); j++){

    //  if(ev_id == vec_evt.at(j)){
    //    cout<< " ev_id == " << ev_id << " ve_evt " << vec_evt.at(j)  << endl;
    //    isSelected = kTRUE;
    //   }
    // }

    if(pt_cand > 5.) {
      // applying cut for pt > 5 GeV
      if (TMath::Abs(y_cand) < 0.8) fid=kTRUE;
    } else {
      // appliying smooth cut for pt < 5 GeV
      Double_t maxFiducialY = -0.2/15*pt_cand*pt_cand+1.9/15*pt_cand+0.5;
      Double_t minFiducialY = 0.2/15*pt_cand*pt_cand-1.9/15*pt_cand-0.5;
      if (y_cand > minFiducialY && y_cand < maxFiducialY) fid=kTRUE;
    }
    //fid
    for(int j=0; j<vec_evt.size(); j++){
      if(ev_id == vec_evt.at(j)){
        if(cand_type>>0&1){
          if(ev_id == vec_evt.at(j)){
            isSelected=kTRUE;
            //cout<< " ev_id == " << ev_id << " ve_evt " << vec_evt.at(j)  << endl;
            if(isSelected) {
              if(pt_cand>cut && pt_cand<cut2 && fid){
//              isSelected=kFALSE;
//              fid=kFALSE;
                hMtree->Fill(inv_mass);
              }//pt and fid
            }//is selected
          }//ev i
          }//cand selected
        }//loop tree
      }//loop vector
  }//loop tree

      //cri

      //tree->Draw("inv_mass","pt_cand>4 && pt_cand<5 &&  cand_type>>0&1 && dist_12<0.5 && dist_23<0.5 && d_len<0.5");
      hLc->SetLineColor(kRed);
      hLc->SetMarkerColor(kRed);
      hMtree->Draw();
      hLc->Draw("sames");

    }
