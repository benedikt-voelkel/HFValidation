import ROOT
import glob
from os.path import join
import uproot
import pandas as pd

TOP_DIR = "/data2/HeavyFlavour/pp_data_2018/01-07-2019/71_20190629-1549/merged"

GLOB_SIGNATURE = join(TOP_DIR, "**", "AnalysisResults.root")

print(f"Globbing files from {GLOB_SIGNATURE}")


all_root_files = glob.glob(GLOB_SIGNATURE, recursive=True)

rejected_due_to_trigger_hist = 0
rejected_due_to_trigger_bitmap = 0

for root_file in all_root_files:
    print(root_file)
    rf = ROOT.TFile(root_file)
    tree = rf.Get("PWGHF_TreeCreator/tree_event_char")
    
    event_char_hist = rf.Get("PWGHF_TreeCreator/coutputEntriesTreeCreatorHF_D0_Ds_2Lc_pp")
    rejected_due_to_trigger_hist += event_char_hist.GetBinContent(6)

    values = uproot.open(root_file)["PWGHF_TreeCreator/tree_event_char"].pandas.df(branches="is_ev_rej")["is_ev_rej"].values & 1<<6
    values = values[values>0]
    print(values)
    rejected_due_to_trigger_bitmap += len(values) 

    print(f"Rejected first due to trigger in this ROOT file: {rejected_due_to_trigger_hist} times")
    print(f"Rejected generally due to trigger in this ROOT file: {rejected_due_to_trigger_bitmap} times")

print(f"Rejected first due to trigger {rejected_due_to_trigger_hist} times")
print(f"Rejected generally due to trigger {rejected_due_to_trigger_bitmap} times")
