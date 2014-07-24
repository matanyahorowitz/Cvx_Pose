% Produced by CVXGEN, 2013-10-23 17:05:38 -0400.
% CVXGEN is Copyright (C) 2006-2012 Jacob Mattingley, jem@cvxgen.com.
% The code in this file is Copyright (C) 2006-2012 Jacob Mattingley.
% CVXGEN, or solvers produced by CVXGEN, cannot be used for commercial
% applications without prior written permission from Jacob Mattingley.

% Filename: cvxsolve.m.
% Description: Solution file, via cvx, for use with sample.m.
function [vars, status] = cvxsolve(params, settings)
if isfield(params, 'data_1')
  data_1 = params.data_1;
elseif isfield(params, 'data')
  data_1 = params.data{1};
else
  error 'could not find data_1'
end
if isfield(params, 'data_2')
  data_2 = params.data_2;
elseif isfield(params, 'data')
  data_2 = params.data{2};
else
  error 'could not find data_2'
end
if isfield(params, 'data_3')
  data_3 = params.data_3;
elseif isfield(params, 'data')
  data_3 = params.data{3};
else
  error 'could not find data_3'
end
if isfield(params, 'data_4')
  data_4 = params.data_4;
elseif isfield(params, 'data')
  data_4 = params.data{4};
else
  error 'could not find data_4'
end
if isfield(params, 'data_5')
  data_5 = params.data_5;
elseif isfield(params, 'data')
  data_5 = params.data{5};
else
  error 'could not find data_5'
end
if isfield(params, 'data_6')
  data_6 = params.data_6;
elseif isfield(params, 'data')
  data_6 = params.data{6};
else
  error 'could not find data_6'
end
if isfield(params, 'data_7')
  data_7 = params.data_7;
elseif isfield(params, 'data')
  data_7 = params.data{7};
else
  error 'could not find data_7'
end
if isfield(params, 'data_8')
  data_8 = params.data_8;
elseif isfield(params, 'data')
  data_8 = params.data{8};
else
  error 'could not find data_8'
end
if isfield(params, 'data_9')
  data_9 = params.data_9;
elseif isfield(params, 'data')
  data_9 = params.data{9};
else
  error 'could not find data_9'
end
if isfield(params, 'data_10')
  data_10 = params.data_10;
elseif isfield(params, 'data')
  data_10 = params.data{10};
else
  error 'could not find data_10'
end
if isfield(params, 'data_11')
  data_11 = params.data_11;
elseif isfield(params, 'data')
  data_11 = params.data{11};
else
  error 'could not find data_11'
end
if isfield(params, 'data_12')
  data_12 = params.data_12;
elseif isfield(params, 'data')
  data_12 = params.data{12};
else
  error 'could not find data_12'
end
if isfield(params, 'data_13')
  data_13 = params.data_13;
elseif isfield(params, 'data')
  data_13 = params.data{13};
else
  error 'could not find data_13'
end
if isfield(params, 'data_14')
  data_14 = params.data_14;
elseif isfield(params, 'data')
  data_14 = params.data{14};
else
  error 'could not find data_14'
end
if isfield(params, 'data_15')
  data_15 = params.data_15;
elseif isfield(params, 'data')
  data_15 = params.data{15};
else
  error 'could not find data_15'
end
if isfield(params, 'data_16')
  data_16 = params.data_16;
elseif isfield(params, 'data')
  data_16 = params.data{16};
else
  error 'could not find data_16'
end
if isfield(params, 'data_17')
  data_17 = params.data_17;
elseif isfield(params, 'data')
  data_17 = params.data{17};
else
  error 'could not find data_17'
end
if isfield(params, 'data_18')
  data_18 = params.data_18;
elseif isfield(params, 'data')
  data_18 = params.data{18};
else
  error 'could not find data_18'
end
if isfield(params, 'data_19')
  data_19 = params.data_19;
elseif isfield(params, 'data')
  data_19 = params.data{19};
else
  error 'could not find data_19'
end
if isfield(params, 'data_20')
  data_20 = params.data_20;
elseif isfield(params, 'data')
  data_20 = params.data{20};
else
  error 'could not find data_20'
end
if isfield(params, 'data_21')
  data_21 = params.data_21;
elseif isfield(params, 'data')
  data_21 = params.data{21};
else
  error 'could not find data_21'
end
if isfield(params, 'data_22')
  data_22 = params.data_22;
elseif isfield(params, 'data')
  data_22 = params.data{22};
else
  error 'could not find data_22'
end
if isfield(params, 'data_23')
  data_23 = params.data_23;
elseif isfield(params, 'data')
  data_23 = params.data{23};
else
  error 'could not find data_23'
end
if isfield(params, 'data_24')
  data_24 = params.data_24;
elseif isfield(params, 'data')
  data_24 = params.data{24};
else
  error 'could not find data_24'
end
if isfield(params, 'data_25')
  data_25 = params.data_25;
elseif isfield(params, 'data')
  data_25 = params.data{25};
else
  error 'could not find data_25'
end
if isfield(params, 'data_26')
  data_26 = params.data_26;
elseif isfield(params, 'data')
  data_26 = params.data{26};
else
  error 'could not find data_26'
end
if isfield(params, 'data_27')
  data_27 = params.data_27;
elseif isfield(params, 'data')
  data_27 = params.data{27};
else
  error 'could not find data_27'
end
if isfield(params, 'data_28')
  data_28 = params.data_28;
elseif isfield(params, 'data')
  data_28 = params.data{28};
else
  error 'could not find data_28'
end
if isfield(params, 'data_29')
  data_29 = params.data_29;
elseif isfield(params, 'data')
  data_29 = params.data{29};
else
  error 'could not find data_29'
end
if isfield(params, 'data_30')
  data_30 = params.data_30;
elseif isfield(params, 'data')
  data_30 = params.data{30};
else
  error 'could not find data_30'
end
if isfield(params, 'data_31')
  data_31 = params.data_31;
elseif isfield(params, 'data')
  data_31 = params.data{31};
else
  error 'could not find data_31'
end
if isfield(params, 'data_32')
  data_32 = params.data_32;
elseif isfield(params, 'data')
  data_32 = params.data{32};
else
  error 'could not find data_32'
end
if isfield(params, 'data_33')
  data_33 = params.data_33;
elseif isfield(params, 'data')
  data_33 = params.data{33};
else
  error 'could not find data_33'
end
if isfield(params, 'data_34')
  data_34 = params.data_34;
elseif isfield(params, 'data')
  data_34 = params.data{34};
else
  error 'could not find data_34'
end
if isfield(params, 'data_35')
  data_35 = params.data_35;
elseif isfield(params, 'data')
  data_35 = params.data{35};
else
  error 'could not find data_35'
end
if isfield(params, 'data_36')
  data_36 = params.data_36;
elseif isfield(params, 'data')
  data_36 = params.data{36};
else
  error 'could not find data_36'
end
if isfield(params, 'data_37')
  data_37 = params.data_37;
elseif isfield(params, 'data')
  data_37 = params.data{37};
else
  error 'could not find data_37'
end
if isfield(params, 'data_38')
  data_38 = params.data_38;
elseif isfield(params, 'data')
  data_38 = params.data{38};
else
  error 'could not find data_38'
end
if isfield(params, 'data_39')
  data_39 = params.data_39;
elseif isfield(params, 'data')
  data_39 = params.data{39};
else
  error 'could not find data_39'
end
if isfield(params, 'data_40')
  data_40 = params.data_40;
elseif isfield(params, 'data')
  data_40 = params.data{40};
else
  error 'could not find data_40'
end
if isfield(params, 'data_41')
  data_41 = params.data_41;
elseif isfield(params, 'data')
  data_41 = params.data{41};
else
  error 'could not find data_41'
end
if isfield(params, 'data_42')
  data_42 = params.data_42;
elseif isfield(params, 'data')
  data_42 = params.data{42};
else
  error 'could not find data_42'
end
if isfield(params, 'data_43')
  data_43 = params.data_43;
elseif isfield(params, 'data')
  data_43 = params.data{43};
else
  error 'could not find data_43'
end
if isfield(params, 'data_44')
  data_44 = params.data_44;
elseif isfield(params, 'data')
  data_44 = params.data{44};
else
  error 'could not find data_44'
end
if isfield(params, 'data_45')
  data_45 = params.data_45;
elseif isfield(params, 'data')
  data_45 = params.data{45};
else
  error 'could not find data_45'
end
if isfield(params, 'data_46')
  data_46 = params.data_46;
elseif isfield(params, 'data')
  data_46 = params.data{46};
else
  error 'could not find data_46'
end
if isfield(params, 'data_47')
  data_47 = params.data_47;
elseif isfield(params, 'data')
  data_47 = params.data{47};
else
  error 'could not find data_47'
end
if isfield(params, 'data_48')
  data_48 = params.data_48;
elseif isfield(params, 'data')
  data_48 = params.data{48};
else
  error 'could not find data_48'
end
if isfield(params, 'data_49')
  data_49 = params.data_49;
elseif isfield(params, 'data')
  data_49 = params.data{49};
else
  error 'could not find data_49'
end
if isfield(params, 'data_50')
  data_50 = params.data_50;
elseif isfield(params, 'data')
  data_50 = params.data{50};
else
  error 'could not find data_50'
end
if isfield(params, 'data_51')
  data_51 = params.data_51;
elseif isfield(params, 'data')
  data_51 = params.data{51};
else
  error 'could not find data_51'
end
if isfield(params, 'data_52')
  data_52 = params.data_52;
elseif isfield(params, 'data')
  data_52 = params.data{52};
else
  error 'could not find data_52'
end
if isfield(params, 'data_53')
  data_53 = params.data_53;
elseif isfield(params, 'data')
  data_53 = params.data{53};
else
  error 'could not find data_53'
end
if isfield(params, 'data_54')
  data_54 = params.data_54;
elseif isfield(params, 'data')
  data_54 = params.data{54};
else
  error 'could not find data_54'
end
if isfield(params, 'data_55')
  data_55 = params.data_55;
elseif isfield(params, 'data')
  data_55 = params.data{55};
else
  error 'could not find data_55'
end
if isfield(params, 'data_56')
  data_56 = params.data_56;
elseif isfield(params, 'data')
  data_56 = params.data{56};
else
  error 'could not find data_56'
end
if isfield(params, 'data_57')
  data_57 = params.data_57;
elseif isfield(params, 'data')
  data_57 = params.data{57};
else
  error 'could not find data_57'
end
if isfield(params, 'data_58')
  data_58 = params.data_58;
elseif isfield(params, 'data')
  data_58 = params.data{58};
else
  error 'could not find data_58'
end
if isfield(params, 'data_59')
  data_59 = params.data_59;
elseif isfield(params, 'data')
  data_59 = params.data{59};
else
  error 'could not find data_59'
end
if isfield(params, 'data_60')
  data_60 = params.data_60;
elseif isfield(params, 'data')
  data_60 = params.data{60};
else
  error 'could not find data_60'
end
if isfield(params, 'data_61')
  data_61 = params.data_61;
elseif isfield(params, 'data')
  data_61 = params.data{61};
else
  error 'could not find data_61'
end
if isfield(params, 'data_62')
  data_62 = params.data_62;
elseif isfield(params, 'data')
  data_62 = params.data{62};
else
  error 'could not find data_62'
end
if isfield(params, 'data_63')
  data_63 = params.data_63;
elseif isfield(params, 'data')
  data_63 = params.data{63};
else
  error 'could not find data_63'
end
if isfield(params, 'data_64')
  data_64 = params.data_64;
elseif isfield(params, 'data')
  data_64 = params.data{64};
else
  error 'could not find data_64'
end
if isfield(params, 'data_65')
  data_65 = params.data_65;
elseif isfield(params, 'data')
  data_65 = params.data{65};
else
  error 'could not find data_65'
end
if isfield(params, 'data_66')
  data_66 = params.data_66;
elseif isfield(params, 'data')
  data_66 = params.data{66};
else
  error 'could not find data_66'
end
if isfield(params, 'data_67')
  data_67 = params.data_67;
elseif isfield(params, 'data')
  data_67 = params.data{67};
else
  error 'could not find data_67'
end
if isfield(params, 'data_68')
  data_68 = params.data_68;
elseif isfield(params, 'data')
  data_68 = params.data{68};
else
  error 'could not find data_68'
end
if isfield(params, 'data_69')
  data_69 = params.data_69;
elseif isfield(params, 'data')
  data_69 = params.data{69};
else
  error 'could not find data_69'
end
if isfield(params, 'data_70')
  data_70 = params.data_70;
elseif isfield(params, 'data')
  data_70 = params.data{70};
else
  error 'could not find data_70'
end
if isfield(params, 'data_71')
  data_71 = params.data_71;
elseif isfield(params, 'data')
  data_71 = params.data{71};
else
  error 'could not find data_71'
end
if isfield(params, 'data_72')
  data_72 = params.data_72;
elseif isfield(params, 'data')
  data_72 = params.data{72};
else
  error 'could not find data_72'
end
if isfield(params, 'data_73')
  data_73 = params.data_73;
elseif isfield(params, 'data')
  data_73 = params.data{73};
else
  error 'could not find data_73'
end
if isfield(params, 'data_74')
  data_74 = params.data_74;
elseif isfield(params, 'data')
  data_74 = params.data{74};
else
  error 'could not find data_74'
end
if isfield(params, 'data_75')
  data_75 = params.data_75;
elseif isfield(params, 'data')
  data_75 = params.data{75};
else
  error 'could not find data_75'
end
if isfield(params, 'data_76')
  data_76 = params.data_76;
elseif isfield(params, 'data')
  data_76 = params.data{76};
else
  error 'could not find data_76'
end
if isfield(params, 'data_77')
  data_77 = params.data_77;
elseif isfield(params, 'data')
  data_77 = params.data{77};
else
  error 'could not find data_77'
end
if isfield(params, 'data_78')
  data_78 = params.data_78;
elseif isfield(params, 'data')
  data_78 = params.data{78};
else
  error 'could not find data_78'
end
if isfield(params, 'data_79')
  data_79 = params.data_79;
elseif isfield(params, 'data')
  data_79 = params.data{79};
else
  error 'could not find data_79'
end
if isfield(params, 'data_80')
  data_80 = params.data_80;
elseif isfield(params, 'data')
  data_80 = params.data{80};
else
  error 'could not find data_80'
end
if isfield(params, 'data_81')
  data_81 = params.data_81;
elseif isfield(params, 'data')
  data_81 = params.data{81};
else
  error 'could not find data_81'
end
if isfield(params, 'data_82')
  data_82 = params.data_82;
elseif isfield(params, 'data')
  data_82 = params.data{82};
else
  error 'could not find data_82'
end
if isfield(params, 'data_83')
  data_83 = params.data_83;
elseif isfield(params, 'data')
  data_83 = params.data{83};
else
  error 'could not find data_83'
end
if isfield(params, 'data_84')
  data_84 = params.data_84;
elseif isfield(params, 'data')
  data_84 = params.data{84};
else
  error 'could not find data_84'
end
if isfield(params, 'data_85')
  data_85 = params.data_85;
elseif isfield(params, 'data')
  data_85 = params.data{85};
else
  error 'could not find data_85'
end
if isfield(params, 'data_86')
  data_86 = params.data_86;
elseif isfield(params, 'data')
  data_86 = params.data{86};
else
  error 'could not find data_86'
end
if isfield(params, 'data_87')
  data_87 = params.data_87;
elseif isfield(params, 'data')
  data_87 = params.data{87};
else
  error 'could not find data_87'
end
if isfield(params, 'data_88')
  data_88 = params.data_88;
elseif isfield(params, 'data')
  data_88 = params.data{88};
else
  error 'could not find data_88'
end
if isfield(params, 'data_89')
  data_89 = params.data_89;
elseif isfield(params, 'data')
  data_89 = params.data{89};
else
  error 'could not find data_89'
end
if isfield(params, 'data_90')
  data_90 = params.data_90;
elseif isfield(params, 'data')
  data_90 = params.data{90};
else
  error 'could not find data_90'
end
if isfield(params, 'data_91')
  data_91 = params.data_91;
elseif isfield(params, 'data')
  data_91 = params.data{91};
else
  error 'could not find data_91'
end
if isfield(params, 'data_92')
  data_92 = params.data_92;
elseif isfield(params, 'data')
  data_92 = params.data{92};
else
  error 'could not find data_92'
end
if isfield(params, 'data_93')
  data_93 = params.data_93;
elseif isfield(params, 'data')
  data_93 = params.data{93};
else
  error 'could not find data_93'
end
if isfield(params, 'data_94')
  data_94 = params.data_94;
elseif isfield(params, 'data')
  data_94 = params.data{94};
else
  error 'could not find data_94'
end
if isfield(params, 'data_95')
  data_95 = params.data_95;
elseif isfield(params, 'data')
  data_95 = params.data{95};
else
  error 'could not find data_95'
end
if isfield(params, 'data_96')
  data_96 = params.data_96;
elseif isfield(params, 'data')
  data_96 = params.data{96};
else
  error 'could not find data_96'
end
if isfield(params, 'data_97')
  data_97 = params.data_97;
elseif isfield(params, 'data')
  data_97 = params.data{97};
else
  error 'could not find data_97'
end
if isfield(params, 'data_98')
  data_98 = params.data_98;
elseif isfield(params, 'data')
  data_98 = params.data{98};
else
  error 'could not find data_98'
end
if isfield(params, 'data_99')
  data_99 = params.data_99;
elseif isfield(params, 'data')
  data_99 = params.data{99};
else
  error 'could not find data_99'
end
if isfield(params, 'data_100')
  data_100 = params.data_100;
elseif isfield(params, 'data')
  data_100 = params.data{100};
else
  error 'could not find data_100'
end
if isfield(params, 'model_1')
  model_1 = params.model_1;
elseif isfield(params, 'model')
  model_1 = params.model{1};
else
  error 'could not find model_1'
end
if isfield(params, 'model_2')
  model_2 = params.model_2;
elseif isfield(params, 'model')
  model_2 = params.model{2};
else
  error 'could not find model_2'
end
if isfield(params, 'model_3')
  model_3 = params.model_3;
elseif isfield(params, 'model')
  model_3 = params.model{3};
else
  error 'could not find model_3'
end
if isfield(params, 'model_4')
  model_4 = params.model_4;
elseif isfield(params, 'model')
  model_4 = params.model{4};
else
  error 'could not find model_4'
end
if isfield(params, 'model_5')
  model_5 = params.model_5;
elseif isfield(params, 'model')
  model_5 = params.model{5};
else
  error 'could not find model_5'
end
if isfield(params, 'model_6')
  model_6 = params.model_6;
elseif isfield(params, 'model')
  model_6 = params.model{6};
else
  error 'could not find model_6'
end
if isfield(params, 'model_7')
  model_7 = params.model_7;
elseif isfield(params, 'model')
  model_7 = params.model{7};
else
  error 'could not find model_7'
end
if isfield(params, 'model_8')
  model_8 = params.model_8;
elseif isfield(params, 'model')
  model_8 = params.model{8};
else
  error 'could not find model_8'
end
if isfield(params, 'model_9')
  model_9 = params.model_9;
elseif isfield(params, 'model')
  model_9 = params.model{9};
else
  error 'could not find model_9'
end
if isfield(params, 'model_10')
  model_10 = params.model_10;
elseif isfield(params, 'model')
  model_10 = params.model{10};
else
  error 'could not find model_10'
end
if isfield(params, 'model_11')
  model_11 = params.model_11;
elseif isfield(params, 'model')
  model_11 = params.model{11};
else
  error 'could not find model_11'
end
if isfield(params, 'model_12')
  model_12 = params.model_12;
elseif isfield(params, 'model')
  model_12 = params.model{12};
else
  error 'could not find model_12'
end
if isfield(params, 'model_13')
  model_13 = params.model_13;
elseif isfield(params, 'model')
  model_13 = params.model{13};
else
  error 'could not find model_13'
end
if isfield(params, 'model_14')
  model_14 = params.model_14;
elseif isfield(params, 'model')
  model_14 = params.model{14};
else
  error 'could not find model_14'
end
if isfield(params, 'model_15')
  model_15 = params.model_15;
elseif isfield(params, 'model')
  model_15 = params.model{15};
else
  error 'could not find model_15'
end
if isfield(params, 'model_16')
  model_16 = params.model_16;
elseif isfield(params, 'model')
  model_16 = params.model{16};
else
  error 'could not find model_16'
end
if isfield(params, 'model_17')
  model_17 = params.model_17;
elseif isfield(params, 'model')
  model_17 = params.model{17};
else
  error 'could not find model_17'
end
if isfield(params, 'model_18')
  model_18 = params.model_18;
elseif isfield(params, 'model')
  model_18 = params.model{18};
else
  error 'could not find model_18'
end
if isfield(params, 'model_19')
  model_19 = params.model_19;
elseif isfield(params, 'model')
  model_19 = params.model{19};
else
  error 'could not find model_19'
end
if isfield(params, 'model_20')
  model_20 = params.model_20;
elseif isfield(params, 'model')
  model_20 = params.model{20};
else
  error 'could not find model_20'
end
if isfield(params, 'model_21')
  model_21 = params.model_21;
elseif isfield(params, 'model')
  model_21 = params.model{21};
else
  error 'could not find model_21'
end
if isfield(params, 'model_22')
  model_22 = params.model_22;
elseif isfield(params, 'model')
  model_22 = params.model{22};
else
  error 'could not find model_22'
end
if isfield(params, 'model_23')
  model_23 = params.model_23;
elseif isfield(params, 'model')
  model_23 = params.model{23};
else
  error 'could not find model_23'
end
if isfield(params, 'model_24')
  model_24 = params.model_24;
elseif isfield(params, 'model')
  model_24 = params.model{24};
else
  error 'could not find model_24'
end
if isfield(params, 'model_25')
  model_25 = params.model_25;
elseif isfield(params, 'model')
  model_25 = params.model{25};
else
  error 'could not find model_25'
end
if isfield(params, 'model_26')
  model_26 = params.model_26;
elseif isfield(params, 'model')
  model_26 = params.model{26};
else
  error 'could not find model_26'
end
if isfield(params, 'model_27')
  model_27 = params.model_27;
elseif isfield(params, 'model')
  model_27 = params.model{27};
else
  error 'could not find model_27'
end
if isfield(params, 'model_28')
  model_28 = params.model_28;
elseif isfield(params, 'model')
  model_28 = params.model{28};
else
  error 'could not find model_28'
end
if isfield(params, 'model_29')
  model_29 = params.model_29;
elseif isfield(params, 'model')
  model_29 = params.model{29};
else
  error 'could not find model_29'
end
if isfield(params, 'model_30')
  model_30 = params.model_30;
elseif isfield(params, 'model')
  model_30 = params.model{30};
else
  error 'could not find model_30'
end
if isfield(params, 'model_31')
  model_31 = params.model_31;
elseif isfield(params, 'model')
  model_31 = params.model{31};
else
  error 'could not find model_31'
end
if isfield(params, 'model_32')
  model_32 = params.model_32;
elseif isfield(params, 'model')
  model_32 = params.model{32};
else
  error 'could not find model_32'
end
if isfield(params, 'model_33')
  model_33 = params.model_33;
elseif isfield(params, 'model')
  model_33 = params.model{33};
else
  error 'could not find model_33'
end
if isfield(params, 'model_34')
  model_34 = params.model_34;
elseif isfield(params, 'model')
  model_34 = params.model{34};
else
  error 'could not find model_34'
end
if isfield(params, 'model_35')
  model_35 = params.model_35;
elseif isfield(params, 'model')
  model_35 = params.model{35};
else
  error 'could not find model_35'
end
if isfield(params, 'model_36')
  model_36 = params.model_36;
elseif isfield(params, 'model')
  model_36 = params.model{36};
else
  error 'could not find model_36'
end
if isfield(params, 'model_37')
  model_37 = params.model_37;
elseif isfield(params, 'model')
  model_37 = params.model{37};
else
  error 'could not find model_37'
end
if isfield(params, 'model_38')
  model_38 = params.model_38;
elseif isfield(params, 'model')
  model_38 = params.model{38};
else
  error 'could not find model_38'
end
if isfield(params, 'model_39')
  model_39 = params.model_39;
elseif isfield(params, 'model')
  model_39 = params.model{39};
else
  error 'could not find model_39'
end
if isfield(params, 'model_40')
  model_40 = params.model_40;
elseif isfield(params, 'model')
  model_40 = params.model{40};
else
  error 'could not find model_40'
end
if isfield(params, 'model_41')
  model_41 = params.model_41;
elseif isfield(params, 'model')
  model_41 = params.model{41};
else
  error 'could not find model_41'
end
if isfield(params, 'model_42')
  model_42 = params.model_42;
elseif isfield(params, 'model')
  model_42 = params.model{42};
else
  error 'could not find model_42'
end
if isfield(params, 'model_43')
  model_43 = params.model_43;
elseif isfield(params, 'model')
  model_43 = params.model{43};
else
  error 'could not find model_43'
end
if isfield(params, 'model_44')
  model_44 = params.model_44;
elseif isfield(params, 'model')
  model_44 = params.model{44};
else
  error 'could not find model_44'
end
if isfield(params, 'model_45')
  model_45 = params.model_45;
elseif isfield(params, 'model')
  model_45 = params.model{45};
else
  error 'could not find model_45'
end
if isfield(params, 'model_46')
  model_46 = params.model_46;
elseif isfield(params, 'model')
  model_46 = params.model{46};
else
  error 'could not find model_46'
end
if isfield(params, 'model_47')
  model_47 = params.model_47;
elseif isfield(params, 'model')
  model_47 = params.model{47};
else
  error 'could not find model_47'
end
if isfield(params, 'model_48')
  model_48 = params.model_48;
elseif isfield(params, 'model')
  model_48 = params.model{48};
else
  error 'could not find model_48'
end
if isfield(params, 'model_49')
  model_49 = params.model_49;
elseif isfield(params, 'model')
  model_49 = params.model{49};
else
  error 'could not find model_49'
end
if isfield(params, 'model_50')
  model_50 = params.model_50;
elseif isfield(params, 'model')
  model_50 = params.model{50};
else
  error 'could not find model_50'
end
if isfield(params, 'model_51')
  model_51 = params.model_51;
elseif isfield(params, 'model')
  model_51 = params.model{51};
else
  error 'could not find model_51'
end
if isfield(params, 'model_52')
  model_52 = params.model_52;
elseif isfield(params, 'model')
  model_52 = params.model{52};
else
  error 'could not find model_52'
end
if isfield(params, 'model_53')
  model_53 = params.model_53;
elseif isfield(params, 'model')
  model_53 = params.model{53};
else
  error 'could not find model_53'
end
if isfield(params, 'model_54')
  model_54 = params.model_54;
elseif isfield(params, 'model')
  model_54 = params.model{54};
else
  error 'could not find model_54'
end
if isfield(params, 'model_55')
  model_55 = params.model_55;
elseif isfield(params, 'model')
  model_55 = params.model{55};
else
  error 'could not find model_55'
end
if isfield(params, 'model_56')
  model_56 = params.model_56;
elseif isfield(params, 'model')
  model_56 = params.model{56};
else
  error 'could not find model_56'
end
if isfield(params, 'model_57')
  model_57 = params.model_57;
elseif isfield(params, 'model')
  model_57 = params.model{57};
else
  error 'could not find model_57'
end
if isfield(params, 'model_58')
  model_58 = params.model_58;
elseif isfield(params, 'model')
  model_58 = params.model{58};
else
  error 'could not find model_58'
end
if isfield(params, 'model_59')
  model_59 = params.model_59;
elseif isfield(params, 'model')
  model_59 = params.model{59};
else
  error 'could not find model_59'
end
if isfield(params, 'model_60')
  model_60 = params.model_60;
elseif isfield(params, 'model')
  model_60 = params.model{60};
else
  error 'could not find model_60'
end
if isfield(params, 'model_61')
  model_61 = params.model_61;
elseif isfield(params, 'model')
  model_61 = params.model{61};
else
  error 'could not find model_61'
end
if isfield(params, 'model_62')
  model_62 = params.model_62;
elseif isfield(params, 'model')
  model_62 = params.model{62};
else
  error 'could not find model_62'
end
if isfield(params, 'model_63')
  model_63 = params.model_63;
elseif isfield(params, 'model')
  model_63 = params.model{63};
else
  error 'could not find model_63'
end
if isfield(params, 'model_64')
  model_64 = params.model_64;
elseif isfield(params, 'model')
  model_64 = params.model{64};
else
  error 'could not find model_64'
end
if isfield(params, 'model_65')
  model_65 = params.model_65;
elseif isfield(params, 'model')
  model_65 = params.model{65};
else
  error 'could not find model_65'
end
if isfield(params, 'model_66')
  model_66 = params.model_66;
elseif isfield(params, 'model')
  model_66 = params.model{66};
else
  error 'could not find model_66'
end
if isfield(params, 'model_67')
  model_67 = params.model_67;
elseif isfield(params, 'model')
  model_67 = params.model{67};
else
  error 'could not find model_67'
end
if isfield(params, 'model_68')
  model_68 = params.model_68;
elseif isfield(params, 'model')
  model_68 = params.model{68};
else
  error 'could not find model_68'
end
if isfield(params, 'model_69')
  model_69 = params.model_69;
elseif isfield(params, 'model')
  model_69 = params.model{69};
else
  error 'could not find model_69'
end
if isfield(params, 'model_70')
  model_70 = params.model_70;
elseif isfield(params, 'model')
  model_70 = params.model{70};
else
  error 'could not find model_70'
end
if isfield(params, 'model_71')
  model_71 = params.model_71;
elseif isfield(params, 'model')
  model_71 = params.model{71};
else
  error 'could not find model_71'
end
if isfield(params, 'model_72')
  model_72 = params.model_72;
elseif isfield(params, 'model')
  model_72 = params.model{72};
else
  error 'could not find model_72'
end
if isfield(params, 'model_73')
  model_73 = params.model_73;
elseif isfield(params, 'model')
  model_73 = params.model{73};
else
  error 'could not find model_73'
end
if isfield(params, 'model_74')
  model_74 = params.model_74;
elseif isfield(params, 'model')
  model_74 = params.model{74};
else
  error 'could not find model_74'
end
if isfield(params, 'model_75')
  model_75 = params.model_75;
elseif isfield(params, 'model')
  model_75 = params.model{75};
else
  error 'could not find model_75'
end
if isfield(params, 'model_76')
  model_76 = params.model_76;
elseif isfield(params, 'model')
  model_76 = params.model{76};
else
  error 'could not find model_76'
end
if isfield(params, 'model_77')
  model_77 = params.model_77;
elseif isfield(params, 'model')
  model_77 = params.model{77};
else
  error 'could not find model_77'
end
if isfield(params, 'model_78')
  model_78 = params.model_78;
elseif isfield(params, 'model')
  model_78 = params.model{78};
else
  error 'could not find model_78'
end
if isfield(params, 'model_79')
  model_79 = params.model_79;
elseif isfield(params, 'model')
  model_79 = params.model{79};
else
  error 'could not find model_79'
end
if isfield(params, 'model_80')
  model_80 = params.model_80;
elseif isfield(params, 'model')
  model_80 = params.model{80};
else
  error 'could not find model_80'
end
if isfield(params, 'model_81')
  model_81 = params.model_81;
elseif isfield(params, 'model')
  model_81 = params.model{81};
else
  error 'could not find model_81'
end
if isfield(params, 'model_82')
  model_82 = params.model_82;
elseif isfield(params, 'model')
  model_82 = params.model{82};
else
  error 'could not find model_82'
end
if isfield(params, 'model_83')
  model_83 = params.model_83;
elseif isfield(params, 'model')
  model_83 = params.model{83};
else
  error 'could not find model_83'
end
if isfield(params, 'model_84')
  model_84 = params.model_84;
elseif isfield(params, 'model')
  model_84 = params.model{84};
else
  error 'could not find model_84'
end
if isfield(params, 'model_85')
  model_85 = params.model_85;
elseif isfield(params, 'model')
  model_85 = params.model{85};
else
  error 'could not find model_85'
end
if isfield(params, 'model_86')
  model_86 = params.model_86;
elseif isfield(params, 'model')
  model_86 = params.model{86};
else
  error 'could not find model_86'
end
if isfield(params, 'model_87')
  model_87 = params.model_87;
elseif isfield(params, 'model')
  model_87 = params.model{87};
else
  error 'could not find model_87'
end
if isfield(params, 'model_88')
  model_88 = params.model_88;
elseif isfield(params, 'model')
  model_88 = params.model{88};
else
  error 'could not find model_88'
end
if isfield(params, 'model_89')
  model_89 = params.model_89;
elseif isfield(params, 'model')
  model_89 = params.model{89};
else
  error 'could not find model_89'
end
if isfield(params, 'model_90')
  model_90 = params.model_90;
elseif isfield(params, 'model')
  model_90 = params.model{90};
else
  error 'could not find model_90'
end
if isfield(params, 'model_91')
  model_91 = params.model_91;
elseif isfield(params, 'model')
  model_91 = params.model{91};
else
  error 'could not find model_91'
end
if isfield(params, 'model_92')
  model_92 = params.model_92;
elseif isfield(params, 'model')
  model_92 = params.model{92};
else
  error 'could not find model_92'
end
if isfield(params, 'model_93')
  model_93 = params.model_93;
elseif isfield(params, 'model')
  model_93 = params.model{93};
else
  error 'could not find model_93'
end
if isfield(params, 'model_94')
  model_94 = params.model_94;
elseif isfield(params, 'model')
  model_94 = params.model{94};
else
  error 'could not find model_94'
end
if isfield(params, 'model_95')
  model_95 = params.model_95;
elseif isfield(params, 'model')
  model_95 = params.model{95};
else
  error 'could not find model_95'
end
if isfield(params, 'model_96')
  model_96 = params.model_96;
elseif isfield(params, 'model')
  model_96 = params.model{96};
else
  error 'could not find model_96'
end
if isfield(params, 'model_97')
  model_97 = params.model_97;
elseif isfield(params, 'model')
  model_97 = params.model{97};
else
  error 'could not find model_97'
end
if isfield(params, 'model_98')
  model_98 = params.model_98;
elseif isfield(params, 'model')
  model_98 = params.model{98};
else
  error 'could not find model_98'
end
if isfield(params, 'model_99')
  model_99 = params.model_99;
elseif isfield(params, 'model')
  model_99 = params.model{99};
else
  error 'could not find model_99'
end
if isfield(params, 'model_100')
  model_100 = params.model_100;
elseif isfield(params, 'model')
  model_100 = params.model{100};
else
  error 'could not find model_100'
end
penalty = params.penalty;
cvx_begin
  % Caution: automatically generated by cvxgen. May be incorrect.
  variable R_1(2, 1);
  variable R_2(2, 1);

  minimize( - (data_1(1)*R_1'*model_1 + data_1(1)*R_1'*model_1 + data_2(1)*R_1'*model_2 + data_2(1)*R_1'*model_2 + data_3(1)*R_1'*model_3 + data_3(1)*R_1'*model_3 + data_4(1)*R_1'*model_4 + data_4(1)*R_1'*model_4 + data_5(1)*R_1'*model_5 + data_5(1)*R_1'*model_5 + data_6(1)*R_1'*model_6 + data_6(1)*R_1'*model_6 + data_7(1)*R_1'*model_7 + data_7(1)*R_1'*model_7 + data_8(1)*R_1'*model_8 + data_8(1)*R_1'*model_8 + data_9(1)*R_1'*model_9 + data_9(1)*R_1'*model_9 + data_10(1)*R_1'*model_10 + data_10(1)*R_1'*model_10 + data_11(1)*R_1'*model_11 + data_11(1)*R_1'*model_11 + data_12(1)*R_1'*model_12 + data_12(1)*R_1'*model_12 + data_13(1)*R_1'*model_13 + data_13(1)*R_1'*model_13 + data_14(1)*R_1'*model_14 + data_14(1)*R_1'*model_14 + data_15(1)*R_1'*model_15 + data_15(1)*R_1'*model_15 + data_16(1)*R_1'*model_16 + data_16(1)*R_1'*model_16 + data_17(1)*R_1'*model_17 + data_17(1)*R_1'*model_17 + data_18(1)*R_1'*model_18 + data_18(1)*R_1'*model_18 + data_19(1)*R_1'*model_19 + data_19(1)*R_1'*model_19 + data_20(1)*R_1'*model_20 + data_20(1)*R_1'*model_20 + data_21(1)*R_1'*model_21 + data_21(1)*R_1'*model_21 + data_22(1)*R_1'*model_22 + data_22(1)*R_1'*model_22 + data_23(1)*R_1'*model_23 + data_23(1)*R_1'*model_23 + data_24(1)*R_1'*model_24 + data_24(1)*R_1'*model_24 + data_25(1)*R_1'*model_25 + data_25(1)*R_1'*model_25 + data_26(1)*R_1'*model_26 + data_26(1)*R_1'*model_26 + data_27(1)*R_1'*model_27 + data_27(1)*R_1'*model_27 + data_28(1)*R_1'*model_28 + data_28(1)*R_1'*model_28 + data_29(1)*R_1'*model_29 + data_29(1)*R_1'*model_29 + data_30(1)*R_1'*model_30 + data_30(1)*R_1'*model_30 + data_31(1)*R_1'*model_31 + data_31(1)*R_1'*model_31 + data_32(1)*R_1'*model_32 + data_32(1)*R_1'*model_32 + data_33(1)*R_1'*model_33 + data_33(1)*R_1'*model_33 + data_34(1)*R_1'*model_34 + data_34(1)*R_1'*model_34 + data_35(1)*R_1'*model_35 + data_35(1)*R_1'*model_35 + data_36(1)*R_1'*model_36 + data_36(1)*R_1'*model_36 + data_37(1)*R_1'*model_37 + data_37(1)*R_1'*model_37 + data_38(1)*R_1'*model_38 + data_38(1)*R_1'*model_38 + data_39(1)*R_1'*model_39 + data_39(1)*R_1'*model_39 + data_40(1)*R_1'*model_40 + data_40(1)*R_1'*model_40 + data_41(1)*R_1'*model_41 + data_41(1)*R_1'*model_41 + data_42(1)*R_1'*model_42 + data_42(1)*R_1'*model_42 + data_43(1)*R_1'*model_43 + data_43(1)*R_1'*model_43 + data_44(1)*R_1'*model_44 + data_44(1)*R_1'*model_44 + data_45(1)*R_1'*model_45 + data_45(1)*R_1'*model_45 + data_46(1)*R_1'*model_46 + data_46(1)*R_1'*model_46 + data_47(1)*R_1'*model_47 + data_47(1)*R_1'*model_47 + data_48(1)*R_1'*model_48 + data_48(1)*R_1'*model_48 + data_49(1)*R_1'*model_49 + data_49(1)*R_1'*model_49 + data_50(1)*R_1'*model_50 + data_50(1)*R_1'*model_50 + data_51(1)*R_1'*model_51 + data_51(1)*R_1'*model_51 + data_52(1)*R_1'*model_52 + data_52(1)*R_1'*model_52 + data_53(1)*R_1'*model_53 + data_53(1)*R_1'*model_53 + data_54(1)*R_1'*model_54 + data_54(1)*R_1'*model_54 + data_55(1)*R_1'*model_55 + data_55(1)*R_1'*model_55 + data_56(1)*R_1'*model_56 + data_56(1)*R_1'*model_56 + data_57(1)*R_1'*model_57 + data_57(1)*R_1'*model_57 + data_58(1)*R_1'*model_58 + data_58(1)*R_1'*model_58 + data_59(1)*R_1'*model_59 + data_59(1)*R_1'*model_59 + data_60(1)*R_1'*model_60 + data_60(1)*R_1'*model_60 + data_61(1)*R_1'*model_61 + data_61(1)*R_1'*model_61 + data_62(1)*R_1'*model_62 + data_62(1)*R_1'*model_62 + data_63(1)*R_1'*model_63 + data_63(1)*R_1'*model_63 + data_64(1)*R_1'*model_64 + data_64(1)*R_1'*model_64 + data_65(1)*R_1'*model_65 + data_65(1)*R_1'*model_65 + data_66(1)*R_1'*model_66 + data_66(1)*R_1'*model_66 + data_67(1)*R_1'*model_67 + data_67(1)*R_1'*model_67 + data_68(1)*R_1'*model_68 + data_68(1)*R_1'*model_68 + data_69(1)*R_1'*model_69 + data_69(1)*R_1'*model_69 + data_70(1)*R_1'*model_70 + data_70(1)*R_1'*model_70 + data_71(1)*R_1'*model_71 + data_71(1)*R_1'*model_71 + data_72(1)*R_1'*model_72 + data_72(1)*R_1'*model_72 + data_73(1)*R_1'*model_73 + data_73(1)*R_1'*model_73 + data_74(1)*R_1'*model_74 + data_74(1)*R_1'*model_74 + data_75(1)*R_1'*model_75 + data_75(1)*R_1'*model_75 + data_76(1)*R_1'*model_76 + data_76(1)*R_1'*model_76 + data_77(1)*R_1'*model_77 + data_77(1)*R_1'*model_77 + data_78(1)*R_1'*model_78 + data_78(1)*R_1'*model_78 + data_79(1)*R_1'*model_79 + data_79(1)*R_1'*model_79 + data_80(1)*R_1'*model_80 + data_80(1)*R_1'*model_80 + data_81(1)*R_1'*model_81 + data_81(1)*R_1'*model_81 + data_82(1)*R_1'*model_82 + data_82(1)*R_1'*model_82 + data_83(1)*R_1'*model_83 + data_83(1)*R_1'*model_83 + data_84(1)*R_1'*model_84 + data_84(1)*R_1'*model_84 + data_85(1)*R_1'*model_85 + data_85(1)*R_1'*model_85 + data_86(1)*R_1'*model_86 + data_86(1)*R_1'*model_86 + data_87(1)*R_1'*model_87 + data_87(1)*R_1'*model_87 + data_88(1)*R_1'*model_88 + data_88(1)*R_1'*model_88 + data_89(1)*R_1'*model_89 + data_89(1)*R_1'*model_89 + data_90(1)*R_1'*model_90 + data_90(1)*R_1'*model_90 + data_91(1)*R_1'*model_91 + data_91(1)*R_1'*model_91 + data_92(1)*R_1'*model_92 + data_92(1)*R_1'*model_92 + data_93(1)*R_1'*model_93 + data_93(1)*R_1'*model_93 + data_94(1)*R_1'*model_94 + data_94(1)*R_1'*model_94 + data_95(1)*R_1'*model_95 + data_95(1)*R_1'*model_95 + data_96(1)*R_1'*model_96 + data_96(1)*R_1'*model_96 + data_97(1)*R_1'*model_97 + data_97(1)*R_1'*model_97 + data_98(1)*R_1'*model_98 + data_98(1)*R_1'*model_98 + data_99(1)*R_1'*model_99 + data_99(1)*R_1'*model_99 + data_100(1)*R_1'*model_100 + data_100(1)*R_1'*model_100) + penalty*(square(R_1(1)) + square(R_1(2))));
  subject to
    R_1(1) == R_2(2);
    R_1(2) == -R_2(1);
cvx_end
vars.R_1 = R_1;
vars.R{1} = R_1;
vars.R_2 = R_2;
vars.R{2} = R_2;
status.cvx_status = cvx_status;
% Provide a drop-in replacement for csolve.
status.optval = cvx_optval;
status.converged = strcmp(cvx_status, 'Solved');
