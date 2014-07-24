/* Produced by CVXGEN, 2013-10-23 17:15:23 -0400.  */
/* CVXGEN is Copyright (C) 2006-2012 Jacob Mattingley, jem@cvxgen.com. */
/* The code in this file is Copyright (C) 2006-2012 Jacob Mattingley. */
/* CVXGEN, or solvers produced by CVXGEN, cannot be used for commercial */
/* applications without prior written permission from Jacob Mattingley. */

/* Filename: testsolver.c. */
/* Description: Basic test harness for solver.c. */
#include "solver.h"
Vars vars;
Params params;
Workspace work;
Settings settings;
#define NUMTESTS 0
int main(int argc, char **argv) {
  int num_iters;
#if (NUMTESTS > 0)
  int i;
  double time;
  double time_per;
#endif
  set_defaults();
  setup_indexing();
  load_default_data();
  /* Solve problem instance for the record. */
  settings.verbose = 1;
  num_iters = solve();
#ifndef ZERO_LIBRARY_MODE
#if (NUMTESTS > 0)
  /* Now solve multiple problem instances for timing purposes. */
  settings.verbose = 0;
  tic();
  for (i = 0; i < NUMTESTS; i++) {
    solve();
  }
  time = tocq();
  printf("Timed %d solves over %.3f seconds.\n", NUMTESTS, time);
  time_per = time / NUMTESTS;
  if (time_per > 1) {
    printf("Actual time taken per solve: %.3g s.\n", time_per);
  } else if (time_per > 1e-3) {
    printf("Actual time taken per solve: %.3g ms.\n", 1e3*time_per);
  } else {
    printf("Actual time taken per solve: %.3g us.\n", 1e6*time_per);
  }
#endif
#endif
  return 0;
}
void load_default_data(void) {
  params.data_1[0] = 0.20319161029830202;
  params.data_1[1] = 0.8325912904724193;
  params.model_1[0] = -0.8363810443482227;
  params.model_1[1] = 0.04331042079065206;
  params.lambda[0] = 1.7858939086953094;
  params.data_2[0] = 1.5851723557337523;
  params.data_2[1] = -1.497658758144655;
  params.model_2[0] = -1.171028487447253;
  params.model_2[1] = -1.7941311867966805;
  params.data_3[0] = -0.23676062539745413;
  params.data_3[1] = -1.8804951564857322;
  params.model_3[0] = -0.17266710242115568;
  params.model_3[1] = 0.596576190459043;
  params.data_4[0] = -0.8860508694080989;
  params.data_4[1] = 0.7050196079205251;
  params.model_4[0] = 0.3634512696654033;
  params.model_4[1] = -1.9040724704913385;
  params.data_5[0] = 0.23541635196352795;
  params.data_5[1] = -0.9629902123701384;
  params.model_5[0] = -0.3395952119597214;
  params.model_5[1] = -0.865899672914725;
  params.data_6[0] = 0.7725516732519853;
  params.data_6[1] = -0.23818512931704205;
  params.model_6[0] = -1.372529046100147;
  params.model_6[1] = 0.17859607212737894;
  params.data_7[0] = 1.1212590580454682;
  params.data_7[1] = -0.774545870495281;
  params.model_7[0] = -1.1121684642712744;
  params.model_7[1] = -0.44811496977740495;
  params.data_8[0] = 1.7455345994417217;
  params.data_8[1] = 1.9039816898917352;
  params.model_8[0] = 0.6895347036512547;
  params.model_8[1] = 1.6113364341535923;
  params.data_9[0] = 1.383003485172717;
  params.data_9[1] = -0.48802383468444344;
  params.model_9[0] = -1.631131964513103;
  params.model_9[1] = 0.6136436100941447;
  params.data_10[0] = 0.2313630495538037;
  params.data_10[1] = -0.5537409477496875;
  params.model_10[0] = -1.0997819806406723;
  params.model_10[1] = -0.3739203344950055;
  params.data_11[0] = -0.12423900520332376;
  params.data_11[1] = -0.923057686995755;
  params.model_11[0] = -0.8328289030982696;
  params.model_11[1] = -0.16925440270808823;
  params.data_12[0] = 1.442135651787706;
  params.data_12[1] = 0.34501161787128565;
  params.model_12[0] = -0.8660485502711608;
  params.model_12[1] = -0.8880899735055947;
  params.data_13[0] = -0.1815116979122129;
  params.data_13[1] = -1.17835862158005;
  params.model_13[0] = -1.1944851558277074;
  params.model_13[1] = 0.05614023926976763;
  params.data_14[0] = -1.6510825248767813;
  params.data_14[1] = -0.06565787059365391;
  params.model_14[0] = -0.5512951504486665;
  params.model_14[1] = 0.8307464872626844;
  params.data_15[0] = 0.9869848924080182;
  params.data_15[1] = 0.7643716874230573;
  params.model_15[0] = 0.7567216550196565;
  params.model_15[1] = -0.5055995034042868;
  params.data_16[0] = 0.6725392189410702;
  params.data_16[1] = -0.6406053441727284;
  params.model_16[0] = 0.29117547947550015;
  params.model_16[1] = -0.6967713677405021;
  params.data_17[0] = -0.21941980294587182;
  params.data_17[1] = -1.753884276680243;
  params.model_17[0] = -1.0292983112626475;
  params.model_17[1] = 1.8864104246942706;
  params.data_18[0] = -1.077663182579704;
  params.data_18[1] = 0.7659100437893209;
  params.model_18[0] = 0.6019074328549583;
  params.model_18[1] = 0.8957565577499285;
  params.data_19[0] = -0.09964555746227477;
  params.data_19[1] = 0.38665509840745127;
  params.model_19[0] = -1.7321223042686946;
  params.model_19[1] = -1.7097514487110663;
  params.data_20[0] = -1.2040958948116867;
  params.data_20[1] = -1.3925560119658358;
  params.model_20[0] = -1.5995826216742213;
  params.model_20[1] = -1.4828245415645833;
  params.data_21[0] = 0.21311092723061398;
  params.data_21[1] = -1.248740700304487;
  params.model_21[0] = 1.808404972124833;
  params.model_21[1] = 0.7264471152297065;
  params.data_22[0] = 0.16407869343908477;
  params.data_22[1] = 0.8287224032315907;
  params.model_22[0] = -0.9444533161899464;
  params.model_22[1] = 1.7069027370149112;
  params.data_23[0] = 1.3567722311998827;
  params.data_23[1] = 0.9052779937121489;
  params.model_23[0] = -0.07904017565835986;
  params.model_23[1] = 1.3684127435065871;
  params.data_24[0] = 0.979009293697437;
  params.data_24[1] = 0.6413036255984501;
  params.model_24[0] = 1.6559010680237511;
  params.model_24[1] = 0.5346622551502991;
  params.data_25[0] = -0.5362376605895625;
  params.data_25[1] = 0.2113782926017822;
  params.model_25[0] = -1.2144776931994525;
  params.model_25[1] = -1.2317108144255875;
  params.data_26[0] = 0.9026784957312834;
  params.data_26[1] = 1.1397468137245244;
  params.model_26[0] = 1.8883934547350631;
  params.model_26[1] = 1.4038856681660068;
  params.data_27[0] = 0.17437730638329096;
  params.data_27[1] = -1.6408365219077408;
  params.model_27[0] = -0.04450702153554875;
  params.model_27[1] = 1.7117453902485025;
  params.data_28[0] = 1.1504727980139053;
  params.data_28[1] = -0.05962309578364744;
  params.model_28[0] = -0.1788825540764547;
  params.model_28[1] = -1.1280569263625857;
  params.data_29[0] = -1.2911464767927057;
  params.data_29[1] = -1.7055053231225696;
  params.model_29[0] = 1.56957275034837;
  params.model_29[1] = 0.5607064675962357;
  params.data_30[0] = -1.4266707301147146;
  params.data_30[1] = -0.3434923211351708;
  params.model_30[0] = -1.8035643024085055;
  params.model_30[1] = -1.1625066019105454;
  params.data_31[0] = 0.9228324965161532;
  params.data_31[1] = 0.6044910817663975;
  params.model_31[0] = -0.0840868104920891;
  params.model_31[1] = -0.900877978017443;
  params.data_32[0] = 0.608892500264739;
  params.data_32[1] = 1.8257980452695217;
  params.model_32[0] = -0.25791777529922877;
  params.model_32[1] = -1.7194699796493191;
  params.data_33[0] = -1.7690740487081298;
  params.data_33[1] = -1.6685159248097703;
  params.model_33[0] = 1.8388287490128845;
  params.model_33[1] = 0.16304334474597537;
  params.data_34[0] = 1.3498497306788897;
  params.data_34[1] = -1.3198658230514613;
  params.model_34[0] = -0.9586197090843394;
  params.model_34[1] = 0.7679100474913709;
  params.data_35[0] = 1.5822813125679343;
  params.data_35[1] = -0.6372460621593619;
  params.model_35[0] = -1.741307208038867;
  params.model_35[1] = 1.456478677642575;
  params.data_36[0] = -0.8365102166820959;
  params.data_36[1] = 0.9643296255982503;
  params.model_36[0] = -1.367865381194024;
  params.model_36[1] = 0.7798537405635035;
  params.data_37[0] = 1.3656784761245926;
  params.data_37[1] = 0.9086083149868371;
  params.model_37[0] = -0.5635699005460344;
  params.model_37[1] = 0.9067590059607915;
  params.data_38[0] = -1.4421315032701587;
  params.data_38[1] = -0.7447235390671119;
  params.model_38[0] = -0.32166897326822186;
  params.model_38[1] = 1.5088481557772684;
  params.data_39[0] = -1.385039165715428;
  params.data_39[1] = 1.5204991609972622;
  params.model_39[0] = 1.1958572768832156;
  params.model_39[1] = 1.8864971883119228;
  params.data_40[0] = -0.5291880667861584;
  params.data_40[1] = -1.1802409243688836;
  params.model_40[0] = -1.037718718661604;
  params.model_40[1] = 1.3114512056856835;
  params.data_41[0] = 1.8609125943756615;
  params.data_41[1] = 0.7952399935216938;
  params.model_41[0] = -0.07001183290468038;
  params.model_41[1] = -0.8518009412754686;
  params.data_42[0] = 1.3347515373726386;
  params.data_42[1] = 1.4887180335977037;
  params.model_42[0] = -1.6314736327976336;
  params.model_42[1] = -1.1362021159208933;
  params.data_43[0] = 1.327044361831466;
  params.data_43[1] = 1.3932155883179842;
  params.model_43[0] = -0.7413880049440107;
  params.model_43[1] = -0.8828216126125747;
  params.data_44[0] = -0.27673991192616;
  params.data_44[1] = 0.15778600105866714;
  params.model_44[0] = -1.6177327399735457;
  params.model_44[1] = 1.3476485548544606;
  params.data_45[0] = 0.13893948140528378;
  params.data_45[1] = 1.0998712601636944;
  params.model_45[0] = -1.0766549376946926;
  params.model_45[1] = 1.8611734044254629;
  params.data_46[0] = 1.0041092292735172;
  params.data_46[1] = -0.6276245424321543;
  params.model_46[0] = 1.794110587839819;
  params.model_46[1] = 0.8020471158650913;
  params.data_47[0] = 1.362244341944948;
  params.data_47[1] = -1.8180107765765245;
  params.model_47[0] = -1.7774338357932473;
  params.model_47[1] = 0.9709490941985153;
  params.data_48[0] = -0.7812542682064318;
  params.data_48[1] = 0.0671374633729811;
  params.model_48[0] = -1.374950305314906;
  params.model_48[1] = 1.9118096386279388;
  params.data_49[0] = 0.011004190697677885;
  params.data_49[1] = 1.3160043138989015;
  params.model_49[0] = -1.7038488148800144;
  params.model_49[1] = -0.08433819112864738;
  params.data_50[0] = -1.7508820783768964;
  params.data_50[1] = 1.536965724350949;
  params.model_50[0] = -0.21675928514816478;
  params.model_50[1] = -1.725800326952653;
  params.penalty[0] = 0.15299256463191413;
}
