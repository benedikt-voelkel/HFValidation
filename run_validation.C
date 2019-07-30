// AOD names
const std::string NAME_AOD("AliAOD.root");
const std::string NAME_VERTIXING_AOD("AliAOD.VertexingHF.root");
const std::vector<std::string> AOD_INPUT_PATHS = { "/home/bvolkel/ALICE/software/aliceDev/ML/HF/validation/data/2018_data/l/289242/000i1"};/*,
                                                   "/home/bvolkel/ALICE/software/aliceDev/ML/HF/validation/data/2018_data/l/289242/0002" };*/
// Number of events to be processed
const Int_t PROCESS_N_EVENTS = 5000;
// Arguments for HFTreeCreator task
const std::string MACRO_PATH_HF_TREE_CREATOR(gSystem->ExpandPathName("/home/bvolkel/ALICE/software/aliceDev/ML/HF/validation/macros/AddTaskHFTreeCreator.C"));
const std::string MACRO_PATH_STD_LC_V0BACHELOR(gSystem->ExpandPathName("/home/bvolkel/ALICE/software/aliceDev/ML/HF/validation/macros/AddTaskLc2V0bachelor.C"));
const std::string MACRO_PATH_STD_LC(gSystem->ExpandPathName("/home/bvolkel/ALICE/software/aliceDev/ML/HF/validation/macros/AddTaskLambdac.C"));

// Collision system to be analysed
enum ECollSystem {kpp=0, kpPb, kPbPb}; // 0 = pp, 1 = pPb, 2 = PbPb
// Where to get files from (not needed now)
const std::string IN_DIR_NAME("HFTreeCreator");
// Cut file
const std::string CUT_FILE_PATH("/home/bvolkel/ALICE/software/aliceDev/ML/HF/validation/data/cutfiles/tree_creator/D0DsDplusDstarLcBplusCuts_pp.root");
//const std::string CUT_FILE_PATH_STD("/home/bvolkel/ALICE/software/aliceDev/ML/HF/validation/data/cutfiles/std/D0toKpiCutsValidation.root");
// Turn on (1) or off (0) AOD protection flag
const Int_t AOD_PROTECTION = 1;
// The collision system
const Int_t COLL_SYSTEM = kpp;
// Run on MC, yes or no. Also decide about gen and signal tree
const Bool_t IS_RUN_ON_MC = kFALSE;
const Bool_t WRITE_ONLY_SIGNAL_TREES = kFALSE;
const Bool_t FILL_MC_GEN_TREES = kFALSE;

const Int_t FILL_TREE_D0 = 0;
const Int_t FILL_TREE_Ds = 0;
const Int_t FILL_TREE_Dplus = 0;
const Int_t FILL_TREE_Dstar = 0;
const Int_t FILL_TREE_LcTopKpi = 1;
const Int_t FILL_TREE_Lc2V0bachelor = 0;
const Int_t FILL_TREE_Bplus = 0;

const Int_t PID_OPT_D0 = AliHFTreeHandler::kNsigmaPID;
const Int_t PID_OPT_Ds = AliHFTreeHandler::kNsigmaPID;
const Int_t PID_OPT_Dplus = AliHFTreeHandler::kNsigmaPID;
const Int_t PID_OPT_Dstar = AliHFTreeHandler::kNsigmaPID;
const Int_t PID_OPT_LctopKpi = AliHFTreeHandler::kNsigmaPID;
const Int_t PID_OPT_Lc2V0bachelor = AliHFTreeHandler::kNsigmaPID;
const Int_t PID_OPT_Bplus = AliHFTreeHandler::kNsigmaPID;

const Int_t SINGLE_TRACK_VARS_OPT = AliHFTreeHandler::kRedSingleTrackVars;
const Bool_t FILL_PARTICLE_TREE = kFALSE;
const Bool_t FILL_TRACKLET_TREE = kFALSE;
const Int_t FILL_NJET_TREES = 0;
const Bool_t FILL_JET_CONSTITUENT_TREES = kFALSE;

// Standard task pK0s
const Bool_t ON_THE_FLY = kFALSE;
const Bool_t WRITE_VARIABLE_TREE = kFALSE;
const Int_t N_TOUR = 0;
const Bool_t ADDITIONAL_CHECKS = kFALSE;
const Bool_t TRACK_ROTATION = kFALSE;
const Int_t N_ROT = 9;
const Double_t PT_MIN = 0.;
const Double_t PT_MAX = 999.;
const Double_t MIN_ROT_ANGLE = 5.*TMath::Pi()/6.;
const Double_t MAX_ROT_ANGLE = 7.*TMath::Pi()/6.;
const Bool_t USE_TPC_PID_TO_FILL_TREE = kFALSE;
const Char_t SIGN = 2;
const Bool_t ORIGIN = kFALSE;
const Bool_t REC_SEC_VTX = kFALSE;


////////////////////////////////////////////////////////////////////////////////
// Lc std task
////////////////////////////////////////////////////////////////////////////////
const std::string FIN_NAME("LcTask.root");
const Bool_t STORE_NTUPLE = kTRUE;
// const READ_MC = kFALSE;
const Bool_t MC_PID = kFALSE;
const Bool_t REAL_PID = kTRUE;
const Bool_t RES_PID = kFALSE;
const Bool_t USE_KF = kFALSE;
const Bool_t FILL_VAR_HISTS = kTRUE;
const Bool_t PRIOR_HISTS = kFALSE;
const Bool_t MULTIPLICITY_HISTS = kFALSE;
const Int_t SYST = 0;
const Int_t BIT = 1;
const std::string POSTNAME("validation");



std::map<std::string,std::pair<std::string,std::string>> DEFAULT_CUT_FILE_OBJECTS = {
                                        std::make_pair("D0", std::make_pair("D0toKpiFilteringCuts", "D0toKpiAnalysisCuts")),
                                        std::make_pair("Ds", std::make_pair("DstoKKpiFilteringCuts", "DstoKKpiAnalysisCuts")),
                                        std::make_pair("Dplus", std::make_pair("DplustoKpipiFilteringCuts", "DplustoKpipiAnalysisCuts")),
                                        std::make_pair("Dstar", std::make_pair("DstartoKpipiFilteringCuts", "DstartoKpipiAnalysisCuts")),
                                        std::make_pair("Lc2V0bachelor", std::make_pair("Lc2V0bachelorFilteringCuts", "Lc2V0bachelorAnalysisCuts")),
                                        std::make_pair("Lc2pKpi", std::make_pair("LctopKpiFilteringCuts", "LctopKpiAnalysisCuts")),
                                        std::make_pair("Bplus", std::make_pair("BplustoD0piFilteringCuts", "BplustoD0piAnalysisCuts")),
                                      };

// Run full chain
// Args:
//  directories: all directories each containing both AliAOD.root and AliAOD.VertexingHF.root
void run_validation()
{
  // create the analysis manager and input handler
  AliAnalysisManager *mgr = new AliAnalysisManager("ValidationManager");
  AliAODInputHandler *aodH = new AliAODInputHandler();
  mgr->SetInputEventHandler(aodH);

  // Physics selection and PID response
  AliPhysicsSelectionTask *physseltask =
    reinterpret_cast<AliPhysicsSelectionTask *>(gInterpreter->ProcessLine(Form(".x %s (%d)",
                                                                               gSystem->ExpandPathName("$ALICE_PHYSICS/OADB/macros/AddTaskPhysicsSelection.C"),
                                                                               IS_RUN_ON_MC)));
  AliAnalysisTaskPIDResponse *pidResp =
    reinterpret_cast<AliAnalysisTaskPIDResponse *>(gInterpreter->ProcessLine(Form(".x %s (%d)",
                                                                                  gSystem->ExpandPathName("$ALICE_ROOT/ANALYSIS/macros/AddTaskPIDResponse.C"),
                                                                                  IS_RUN_ON_MC)));



  if(FILL_TREE_Lc2V0bachelor == 1) {
    AliAnalysisTaskSELc2V0bachelor *stdTask =
      reinterpret_cast<AliAnalysisTaskSELc2V0bachelor*>(gInterpreter->ProcessLine(Form(".x %s (\"%s\",              \
                                                                                               %d, %d, %d, %d, %d,  \
                                                                                               %d, %d,              \
                                                                                               %f, %f, %f, %f,      \
                                                                                               %d, '%c', %d, %d,    \
                                                                                               \"%s\")",
                                                                                        MACRO_PATH_STD_LC_V0BACHELOR.c_str(),

                                                                                        CUT_FILE_PATH.c_str(),

                                                                                        IS_RUN_ON_MC,
                                                                                        ON_THE_FLY,
                                                                                        WRITE_VARIABLE_TREE,
                                                                                        N_TOUR,
                                                                                        ADDITIONAL_CHECKS,

                                                                                        TRACK_ROTATION,
                                                                                        N_ROT,

                                                                                        PT_MIN,
                                                                                        PT_MAX,
                                                                                        MIN_ROT_ANGLE,
                                                                                        MAX_ROT_ANGLE,

                                                                                        USE_TPC_PID_TO_FILL_TREE,
                                                                                        SIGN,
                                                                                        ORIGIN,
                                                                                        REC_SEC_VTX,

                                                                                        DEFAULT_CUT_FILE_OBJECTS["Lc2V0bachelor"].first.c_str()) ) );
  }

  if(FILL_TREE_LcTopKpi == 1) {
    AliAnalysisTaskSELc2V0bachelor *stdTask =
      reinterpret_cast<AliAnalysisTaskSELc2V0bachelor*>(gInterpreter->ProcessLine(Form(".x %s (\"%s\",        \
                                                                                               %d,            \
                                                                                               %d,            \
                                                                                               %d, %d, %d,    \
                                                                                               %d,            \
                                                                                               %d, %d, %d,    \
                                                                                               %d, %d,        \
                                                                                               \"%s\",        \
                                                                                               \"%s\", \"%s\")",
                                                                                        MACRO_PATH_STD_LC.c_str(),

                                                                                        CUT_FILE_PATH.c_str(),

                                                                                        STORE_NTUPLE,

                                                                                        IS_RUN_ON_MC,

                                                                                        MC_PID,
                                                                                        REAL_PID,
                                                                                        RES_PID,

                                                                                        USE_KF,

                                                                                        FILL_VAR_HISTS,
                                                                                        PRIOR_HISTS,
                                                                                        MULTIPLICITY_HISTS,

                                                                                        SYST,
                                                                                        BIT,

                                                                                        POSTNAME.c_str(),

                                                                                        DEFAULT_CUT_FILE_OBJECTS["Lc2pKpi"].first.c_str(),
                                                                                        DEFAULT_CUT_FILE_OBJECTS["Lc2pKpi"].second.c_str()) ) );
  }
  AliAnalysisTaskSEHFTreeCreator *treeCreatorTask =
    reinterpret_cast<AliAnalysisTaskSEHFTreeCreator*>(gInterpreter->ProcessLine(Form(".x %s (%d, %d, \"%s\", \"%s\", %d,  \
                                                                                             %d, %d,                      \
                                                                                             %d, \"%s\", \"%s\",          \
                                                                                             %d, \"%s\", \"%s\",          \
                                                                                             %d, \"%s\", \"%s\",          \
                                                                                             %d, \"%s\", \"%s\",          \
                                                                                             %d, \"%s\", \"%s\",          \
                                                                                             %d, \"%s\", \"%s\",          \
                                                                                             %d, \"%s\", \"%s\",          \
                                                                                             %d, %d, %d, %d, %d, %d, %d,  \
                                                                                             %d, %d, %d, %d, %d)",
                                                                                     MACRO_PATH_HF_TREE_CREATOR.c_str(),

                                                                                     IS_RUN_ON_MC,
                                                                                     COLL_SYSTEM,
                                                                                     IN_DIR_NAME.c_str(),
                                                                                     CUT_FILE_PATH.c_str(),
                                                                                     AOD_PROTECTION,

                                                                                     WRITE_ONLY_SIGNAL_TREES,
                                                                                     FILL_MC_GEN_TREES,

                                                                                     FILL_TREE_D0,
                                                                                     DEFAULT_CUT_FILE_OBJECTS["D0"].first.c_str(),
                                                                                     DEFAULT_CUT_FILE_OBJECTS["D0"].second.c_str(),

                                                                                     FILL_TREE_Ds,
                                                                                     DEFAULT_CUT_FILE_OBJECTS["Ds"].first.c_str(),
                                                                                     DEFAULT_CUT_FILE_OBJECTS["Ds"].second.c_str(),

                                                                                     FILL_TREE_Dplus,
                                                                                     DEFAULT_CUT_FILE_OBJECTS["Dplus"].first.c_str(),
                                                                                     DEFAULT_CUT_FILE_OBJECTS["Dplus"].second.c_str(),

                                                                                     FILL_TREE_Dstar,
                                                                                     DEFAULT_CUT_FILE_OBJECTS["Dstar"].first.c_str(),
                                                                                     DEFAULT_CUT_FILE_OBJECTS["Dstar"].second.c_str(),

                                                                                     FILL_TREE_LcTopKpi,
                                                                                     DEFAULT_CUT_FILE_OBJECTS["Lc2pKpi"].first.c_str(),
                                                                                     DEFAULT_CUT_FILE_OBJECTS["Lc2pKpi"].second.c_str(),

                                                                                     FILL_TREE_Lc2V0bachelor,
                                                                                     DEFAULT_CUT_FILE_OBJECTS["Lc2V0bachelor"].first.c_str(),
                                                                                     DEFAULT_CUT_FILE_OBJECTS["Lc2V0bachelor"].second.c_str(),

                                                                                     FILL_TREE_Bplus,
                                                                                     DEFAULT_CUT_FILE_OBJECTS["Bplus"].first.c_str(),
                                                                                     DEFAULT_CUT_FILE_OBJECTS["Bplus"].second.c_str(),

                                                                                     PID_OPT_D0,
                                                                                     PID_OPT_Ds,
                                                                                     PID_OPT_Dplus,
                                                                                     PID_OPT_Dstar,
                                                                                     PID_OPT_LctopKpi,
                                                                                     PID_OPT_Lc2V0bachelor,
                                                                                     PID_OPT_Bplus,

                                                                                     SINGLE_TRACK_VARS_OPT,
                                                                                     FILL_PARTICLE_TREE,
                                                                                     FILL_TRACKLET_TREE,
                                                                                     FILL_NJET_TREES,
                                                                                     FILL_JET_CONSTITUENT_TREES) ) );

  if(!mgr->InitAnalysis()) {
    return;
  }
  mgr->SetDebugLevel(2);
  mgr->PrintStatus();
  mgr->SetUseProgressBar(1, 25);

  // AOD and vertixing chains
  TChain* chainAOD = new TChain("aodTree");
  TChain *chainAODfriend = new TChain("aodTree");
  // Adding all files requested
  for(auto& path : AOD_INPUT_PATHS) {
    chainAOD->Add(Form("%s/%s", path.c_str(), NAME_AOD.c_str()));
    chainAODfriend->Add(Form("%s/%s", path.c_str(), NAME_VERTIXING_AOD.c_str()));
  }
  // And connect
  chainAOD->AddFriend(chainAODfriend);

  // start the analysis locally, reading the events from the tchain
  mgr->StartAnalysis("local", chainAOD, PROCESS_N_EVENTS, 0);

}
