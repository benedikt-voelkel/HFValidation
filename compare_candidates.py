import ROOT
import pandas as pd
import uproot

analysis_results_same_cut_obj = "AnalysisResults_sameCut.root"
analysis_results_ded_cut_obj = "AnalysisResults_dedCut.root"


sel_ev_ids_same_cut = uproot.open(analysis_results_same_cut_obj)["PWGHF_TreeCreator/tree_event_char"].pandas.df(branches=["is_ev_rej","ev_id"]).query("is_ev_rej==0")["ev_id"]
sel_ev_ids_ded_cut = uproot.open(analysis_results_ded_cut_obj)["PWGHF_TreeCreator/tree_event_char"].pandas.df(branches=["is_ev_rej","ev_id"]).query("is_ev_rej==0")["ev_id"]

df_cand_same_cut = uproot.open(analysis_results_same_cut_obj)["PWGHF_TreeCreator/tree_D0"].pandas.df(branches=["ev_id", "cand_type"])
df_cand_ded_cut = uproot.open(analysis_results_ded_cut_obj)["PWGHF_TreeCreator/tree_D0"].pandas.df(branches=["ev_id", "cand_type"])

df_cand_same_cut = df_cand_same_cut[df_cand_same_cut["ev_id"].isin(sel_ev_ids_same_cut)]
df_cand_ded_cut = df_cand_ded_cut[df_cand_ded_cut["ev_id"].isin(sel_ev_ids_ded_cut)]

print(df_cand_same_cut)
print(df_cand_ded_cut)

df_diff_1 = df_cand_same_cut[~df_cand_same_cut.apply(tuple,1).isin(df_cand_ded_cut.apply(tuple,1))]
df_diff_2 = df_cand_ded_cut[~df_cand_ded_cut.apply(tuple,1).isin(df_cand_same_cut.apply(tuple,1))]

print(df_diff_1)
print("#################")
print(df_diff_2)



