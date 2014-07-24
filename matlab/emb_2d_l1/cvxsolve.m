% Produced by CVXGEN, 2013-10-23 17:15:03 -0400.
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
lambda = params.lambda;
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
penalty = params.penalty;
cvx_begin
  % Caution: automatically generated by cvxgen. May be incorrect.
  variable R_1(2, 1);
  variable T_1;
  variable Z_1(2, 1);
  variable R_2(2, 1);
  variable T_2;
  variable Z_2(2, 1);
  variable Z_3(2, 1);
  variable Z_4(2, 1);
  variable Z_5(2, 1);
  variable Z_6(2, 1);
  variable Z_7(2, 1);
  variable Z_8(2, 1);
  variable Z_9(2, 1);
  variable Z_10(2, 1);
  variable Z_11(2, 1);
  variable Z_12(2, 1);
  variable Z_13(2, 1);
  variable Z_14(2, 1);
  variable Z_15(2, 1);
  variable Z_16(2, 1);
  variable Z_17(2, 1);
  variable Z_18(2, 1);
  variable Z_19(2, 1);
  variable Z_20(2, 1);
  variable Z_21(2, 1);
  variable Z_22(2, 1);
  variable Z_23(2, 1);
  variable Z_24(2, 1);
  variable Z_25(2, 1);
  variable Z_26(2, 1);
  variable Z_27(2, 1);
  variable Z_28(2, 1);
  variable Z_29(2, 1);
  variable Z_30(2, 1);
  variable Z_31(2, 1);
  variable Z_32(2, 1);
  variable Z_33(2, 1);
  variable Z_34(2, 1);
  variable Z_35(2, 1);
  variable Z_36(2, 1);
  variable Z_37(2, 1);
  variable Z_38(2, 1);
  variable Z_39(2, 1);
  variable Z_40(2, 1);
  variable Z_41(2, 1);
  variable Z_42(2, 1);
  variable Z_43(2, 1);
  variable Z_44(2, 1);
  variable Z_45(2, 1);
  variable Z_46(2, 1);
  variable Z_47(2, 1);
  variable Z_48(2, 1);
  variable Z_49(2, 1);
  variable Z_50(2, 1);

  minimize(quad_form(data_1(1) - (R_1'*model_1 + T_1) - Z_1(1), eye(1)) + lambda*norm(Z_1(1), 1) + quad_form(data_1(2) - (R_2'*model_1 + T_2) - Z_1(2), eye(1)) + lambda*norm(Z_1(2), 1) + quad_form(data_2(1) - (R_1'*model_2 + T_1) - Z_2(1), eye(1)) + lambda*norm(Z_2(1), 1) + quad_form(data_2(2) - (R_2'*model_2 + T_2) - Z_2(2), eye(1)) + lambda*norm(Z_2(2), 1) + quad_form(data_3(1) - (R_1'*model_3 + T_1) - Z_3(1), eye(1)) + lambda*norm(Z_3(1), 1) + quad_form(data_3(2) - (R_2'*model_3 + T_2) - Z_3(2), eye(1)) + lambda*norm(Z_3(2), 1) + quad_form(data_4(1) - (R_1'*model_4 + T_1) - Z_4(1), eye(1)) + lambda*norm(Z_4(1), 1) + quad_form(data_4(2) - (R_2'*model_4 + T_2) - Z_4(2), eye(1)) + lambda*norm(Z_4(2), 1) + quad_form(data_5(1) - (R_1'*model_5 + T_1) - Z_5(1), eye(1)) + lambda*norm(Z_5(1), 1) + quad_form(data_5(2) - (R_2'*model_5 + T_2) - Z_5(2), eye(1)) + lambda*norm(Z_5(2), 1) + quad_form(data_6(1) - (R_1'*model_6 + T_1) - Z_6(1), eye(1)) + lambda*norm(Z_6(1), 1) + quad_form(data_6(2) - (R_2'*model_6 + T_2) - Z_6(2), eye(1)) + lambda*norm(Z_6(2), 1) + quad_form(data_7(1) - (R_1'*model_7 + T_1) - Z_7(1), eye(1)) + lambda*norm(Z_7(1), 1) + quad_form(data_7(2) - (R_2'*model_7 + T_2) - Z_7(2), eye(1)) + lambda*norm(Z_7(2), 1) + quad_form(data_8(1) - (R_1'*model_8 + T_1) - Z_8(1), eye(1)) + lambda*norm(Z_8(1), 1) + quad_form(data_8(2) - (R_2'*model_8 + T_2) - Z_8(2), eye(1)) + lambda*norm(Z_8(2), 1) + quad_form(data_9(1) - (R_1'*model_9 + T_1) - Z_9(1), eye(1)) + lambda*norm(Z_9(1), 1) + quad_form(data_9(2) - (R_2'*model_9 + T_2) - Z_9(2), eye(1)) + lambda*norm(Z_9(2), 1) + quad_form(data_10(1) - (R_1'*model_10 + T_1) - Z_10(1), eye(1)) + lambda*norm(Z_10(1), 1) + quad_form(data_10(2) - (R_2'*model_10 + T_2) - Z_10(2), eye(1)) + lambda*norm(Z_10(2), 1) + quad_form(data_11(1) - (R_1'*model_11 + T_1) - Z_11(1), eye(1)) + lambda*norm(Z_11(1), 1) + quad_form(data_11(2) - (R_2'*model_11 + T_2) - Z_11(2), eye(1)) + lambda*norm(Z_11(2), 1) + quad_form(data_12(1) - (R_1'*model_12 + T_1) - Z_12(1), eye(1)) + lambda*norm(Z_12(1), 1) + quad_form(data_12(2) - (R_2'*model_12 + T_2) - Z_12(2), eye(1)) + lambda*norm(Z_12(2), 1) + quad_form(data_13(1) - (R_1'*model_13 + T_1) - Z_13(1), eye(1)) + lambda*norm(Z_13(1), 1) + quad_form(data_13(2) - (R_2'*model_13 + T_2) - Z_13(2), eye(1)) + lambda*norm(Z_13(2), 1) + quad_form(data_14(1) - (R_1'*model_14 + T_1) - Z_14(1), eye(1)) + lambda*norm(Z_14(1), 1) + quad_form(data_14(2) - (R_2'*model_14 + T_2) - Z_14(2), eye(1)) + lambda*norm(Z_14(2), 1) + quad_form(data_15(1) - (R_1'*model_15 + T_1) - Z_15(1), eye(1)) + lambda*norm(Z_15(1), 1) + quad_form(data_15(2) - (R_2'*model_15 + T_2) - Z_15(2), eye(1)) + lambda*norm(Z_15(2), 1) + quad_form(data_16(1) - (R_1'*model_16 + T_1) - Z_16(1), eye(1)) + lambda*norm(Z_16(1), 1) + quad_form(data_16(2) - (R_2'*model_16 + T_2) - Z_16(2), eye(1)) + lambda*norm(Z_16(2), 1) + quad_form(data_17(1) - (R_1'*model_17 + T_1) - Z_17(1), eye(1)) + lambda*norm(Z_17(1), 1) + quad_form(data_17(2) - (R_2'*model_17 + T_2) - Z_17(2), eye(1)) + lambda*norm(Z_17(2), 1) + quad_form(data_18(1) - (R_1'*model_18 + T_1) - Z_18(1), eye(1)) + lambda*norm(Z_18(1), 1) + quad_form(data_18(2) - (R_2'*model_18 + T_2) - Z_18(2), eye(1)) + lambda*norm(Z_18(2), 1) + quad_form(data_19(1) - (R_1'*model_19 + T_1) - Z_19(1), eye(1)) + lambda*norm(Z_19(1), 1) + quad_form(data_19(2) - (R_2'*model_19 + T_2) - Z_19(2), eye(1)) + lambda*norm(Z_19(2), 1) + quad_form(data_20(1) - (R_1'*model_20 + T_1) - Z_20(1), eye(1)) + lambda*norm(Z_20(1), 1) + quad_form(data_20(2) - (R_2'*model_20 + T_2) - Z_20(2), eye(1)) + lambda*norm(Z_20(2), 1) + quad_form(data_21(1) - (R_1'*model_21 + T_1) - Z_21(1), eye(1)) + lambda*norm(Z_21(1), 1) + quad_form(data_21(2) - (R_2'*model_21 + T_2) - Z_21(2), eye(1)) + lambda*norm(Z_21(2), 1) + quad_form(data_22(1) - (R_1'*model_22 + T_1) - Z_22(1), eye(1)) + lambda*norm(Z_22(1), 1) + quad_form(data_22(2) - (R_2'*model_22 + T_2) - Z_22(2), eye(1)) + lambda*norm(Z_22(2), 1) + quad_form(data_23(1) - (R_1'*model_23 + T_1) - Z_23(1), eye(1)) + lambda*norm(Z_23(1), 1) + quad_form(data_23(2) - (R_2'*model_23 + T_2) - Z_23(2), eye(1)) + lambda*norm(Z_23(2), 1) + quad_form(data_24(1) - (R_1'*model_24 + T_1) - Z_24(1), eye(1)) + lambda*norm(Z_24(1), 1) + quad_form(data_24(2) - (R_2'*model_24 + T_2) - Z_24(2), eye(1)) + lambda*norm(Z_24(2), 1) + quad_form(data_25(1) - (R_1'*model_25 + T_1) - Z_25(1), eye(1)) + lambda*norm(Z_25(1), 1) + quad_form(data_25(2) - (R_2'*model_25 + T_2) - Z_25(2), eye(1)) + lambda*norm(Z_25(2), 1) + quad_form(data_26(1) - (R_1'*model_26 + T_1) - Z_26(1), eye(1)) + lambda*norm(Z_26(1), 1) + quad_form(data_26(2) - (R_2'*model_26 + T_2) - Z_26(2), eye(1)) + lambda*norm(Z_26(2), 1) + quad_form(data_27(1) - (R_1'*model_27 + T_1) - Z_27(1), eye(1)) + lambda*norm(Z_27(1), 1) + quad_form(data_27(2) - (R_2'*model_27 + T_2) - Z_27(2), eye(1)) + lambda*norm(Z_27(2), 1) + quad_form(data_28(1) - (R_1'*model_28 + T_1) - Z_28(1), eye(1)) + lambda*norm(Z_28(1), 1) + quad_form(data_28(2) - (R_2'*model_28 + T_2) - Z_28(2), eye(1)) + lambda*norm(Z_28(2), 1) + quad_form(data_29(1) - (R_1'*model_29 + T_1) - Z_29(1), eye(1)) + lambda*norm(Z_29(1), 1) + quad_form(data_29(2) - (R_2'*model_29 + T_2) - Z_29(2), eye(1)) + lambda*norm(Z_29(2), 1) + quad_form(data_30(1) - (R_1'*model_30 + T_1) - Z_30(1), eye(1)) + lambda*norm(Z_30(1), 1) + quad_form(data_30(2) - (R_2'*model_30 + T_2) - Z_30(2), eye(1)) + lambda*norm(Z_30(2), 1) + quad_form(data_31(1) - (R_1'*model_31 + T_1) - Z_31(1), eye(1)) + lambda*norm(Z_31(1), 1) + quad_form(data_31(2) - (R_2'*model_31 + T_2) - Z_31(2), eye(1)) + lambda*norm(Z_31(2), 1) + quad_form(data_32(1) - (R_1'*model_32 + T_1) - Z_32(1), eye(1)) + lambda*norm(Z_32(1), 1) + quad_form(data_32(2) - (R_2'*model_32 + T_2) - Z_32(2), eye(1)) + lambda*norm(Z_32(2), 1) + quad_form(data_33(1) - (R_1'*model_33 + T_1) - Z_33(1), eye(1)) + lambda*norm(Z_33(1), 1) + quad_form(data_33(2) - (R_2'*model_33 + T_2) - Z_33(2), eye(1)) + lambda*norm(Z_33(2), 1) + quad_form(data_34(1) - (R_1'*model_34 + T_1) - Z_34(1), eye(1)) + lambda*norm(Z_34(1), 1) + quad_form(data_34(2) - (R_2'*model_34 + T_2) - Z_34(2), eye(1)) + lambda*norm(Z_34(2), 1) + quad_form(data_35(1) - (R_1'*model_35 + T_1) - Z_35(1), eye(1)) + lambda*norm(Z_35(1), 1) + quad_form(data_35(2) - (R_2'*model_35 + T_2) - Z_35(2), eye(1)) + lambda*norm(Z_35(2), 1) + quad_form(data_36(1) - (R_1'*model_36 + T_1) - Z_36(1), eye(1)) + lambda*norm(Z_36(1), 1) + quad_form(data_36(2) - (R_2'*model_36 + T_2) - Z_36(2), eye(1)) + lambda*norm(Z_36(2), 1) + quad_form(data_37(1) - (R_1'*model_37 + T_1) - Z_37(1), eye(1)) + lambda*norm(Z_37(1), 1) + quad_form(data_37(2) - (R_2'*model_37 + T_2) - Z_37(2), eye(1)) + lambda*norm(Z_37(2), 1) + quad_form(data_38(1) - (R_1'*model_38 + T_1) - Z_38(1), eye(1)) + lambda*norm(Z_38(1), 1) + quad_form(data_38(2) - (R_2'*model_38 + T_2) - Z_38(2), eye(1)) + lambda*norm(Z_38(2), 1) + quad_form(data_39(1) - (R_1'*model_39 + T_1) - Z_39(1), eye(1)) + lambda*norm(Z_39(1), 1) + quad_form(data_39(2) - (R_2'*model_39 + T_2) - Z_39(2), eye(1)) + lambda*norm(Z_39(2), 1) + quad_form(data_40(1) - (R_1'*model_40 + T_1) - Z_40(1), eye(1)) + lambda*norm(Z_40(1), 1) + quad_form(data_40(2) - (R_2'*model_40 + T_2) - Z_40(2), eye(1)) + lambda*norm(Z_40(2), 1) + quad_form(data_41(1) - (R_1'*model_41 + T_1) - Z_41(1), eye(1)) + lambda*norm(Z_41(1), 1) + quad_form(data_41(2) - (R_2'*model_41 + T_2) - Z_41(2), eye(1)) + lambda*norm(Z_41(2), 1) + quad_form(data_42(1) - (R_1'*model_42 + T_1) - Z_42(1), eye(1)) + lambda*norm(Z_42(1), 1) + quad_form(data_42(2) - (R_2'*model_42 + T_2) - Z_42(2), eye(1)) + lambda*norm(Z_42(2), 1) + quad_form(data_43(1) - (R_1'*model_43 + T_1) - Z_43(1), eye(1)) + lambda*norm(Z_43(1), 1) + quad_form(data_43(2) - (R_2'*model_43 + T_2) - Z_43(2), eye(1)) + lambda*norm(Z_43(2), 1) + quad_form(data_44(1) - (R_1'*model_44 + T_1) - Z_44(1), eye(1)) + lambda*norm(Z_44(1), 1) + quad_form(data_44(2) - (R_2'*model_44 + T_2) - Z_44(2), eye(1)) + lambda*norm(Z_44(2), 1) + quad_form(data_45(1) - (R_1'*model_45 + T_1) - Z_45(1), eye(1)) + lambda*norm(Z_45(1), 1) + quad_form(data_45(2) - (R_2'*model_45 + T_2) - Z_45(2), eye(1)) + lambda*norm(Z_45(2), 1) + quad_form(data_46(1) - (R_1'*model_46 + T_1) - Z_46(1), eye(1)) + lambda*norm(Z_46(1), 1) + quad_form(data_46(2) - (R_2'*model_46 + T_2) - Z_46(2), eye(1)) + lambda*norm(Z_46(2), 1) + quad_form(data_47(1) - (R_1'*model_47 + T_1) - Z_47(1), eye(1)) + lambda*norm(Z_47(1), 1) + quad_form(data_47(2) - (R_2'*model_47 + T_2) - Z_47(2), eye(1)) + lambda*norm(Z_47(2), 1) + quad_form(data_48(1) - (R_1'*model_48 + T_1) - Z_48(1), eye(1)) + lambda*norm(Z_48(1), 1) + quad_form(data_48(2) - (R_2'*model_48 + T_2) - Z_48(2), eye(1)) + lambda*norm(Z_48(2), 1) + quad_form(data_49(1) - (R_1'*model_49 + T_1) - Z_49(1), eye(1)) + lambda*norm(Z_49(1), 1) + quad_form(data_49(2) - (R_2'*model_49 + T_2) - Z_49(2), eye(1)) + lambda*norm(Z_49(2), 1) + quad_form(data_50(1) - (R_1'*model_50 + T_1) - Z_50(1), eye(1)) + lambda*norm(Z_50(1), 1) + quad_form(data_50(2) - (R_2'*model_50 + T_2) - Z_50(2), eye(1)) + lambda*norm(Z_50(2), 1) + penalty*(square(R_1(1)) + square(R_1(2))));
  subject to
    R_1(1) == R_2(2);
    R_1(2) == -R_2(1);
cvx_end
vars.R_1 = R_1;
vars.R{1} = R_1;
vars.R_2 = R_2;
vars.R{2} = R_2;
vars.T_1 = T_1;
vars.T{1} = T_1;
vars.T_2 = T_2;
vars.T{2} = T_2;
vars.Z_1 = Z_1;
vars.Z{1} = Z_1;
vars.Z_2 = Z_2;
vars.Z{2} = Z_2;
vars.Z_3 = Z_3;
vars.Z{3} = Z_3;
vars.Z_4 = Z_4;
vars.Z{4} = Z_4;
vars.Z_5 = Z_5;
vars.Z{5} = Z_5;
vars.Z_6 = Z_6;
vars.Z{6} = Z_6;
vars.Z_7 = Z_7;
vars.Z{7} = Z_7;
vars.Z_8 = Z_8;
vars.Z{8} = Z_8;
vars.Z_9 = Z_9;
vars.Z{9} = Z_9;
vars.Z_10 = Z_10;
vars.Z{10} = Z_10;
vars.Z_11 = Z_11;
vars.Z{11} = Z_11;
vars.Z_12 = Z_12;
vars.Z{12} = Z_12;
vars.Z_13 = Z_13;
vars.Z{13} = Z_13;
vars.Z_14 = Z_14;
vars.Z{14} = Z_14;
vars.Z_15 = Z_15;
vars.Z{15} = Z_15;
vars.Z_16 = Z_16;
vars.Z{16} = Z_16;
vars.Z_17 = Z_17;
vars.Z{17} = Z_17;
vars.Z_18 = Z_18;
vars.Z{18} = Z_18;
vars.Z_19 = Z_19;
vars.Z{19} = Z_19;
vars.Z_20 = Z_20;
vars.Z{20} = Z_20;
vars.Z_21 = Z_21;
vars.Z{21} = Z_21;
vars.Z_22 = Z_22;
vars.Z{22} = Z_22;
vars.Z_23 = Z_23;
vars.Z{23} = Z_23;
vars.Z_24 = Z_24;
vars.Z{24} = Z_24;
vars.Z_25 = Z_25;
vars.Z{25} = Z_25;
vars.Z_26 = Z_26;
vars.Z{26} = Z_26;
vars.Z_27 = Z_27;
vars.Z{27} = Z_27;
vars.Z_28 = Z_28;
vars.Z{28} = Z_28;
vars.Z_29 = Z_29;
vars.Z{29} = Z_29;
vars.Z_30 = Z_30;
vars.Z{30} = Z_30;
vars.Z_31 = Z_31;
vars.Z{31} = Z_31;
vars.Z_32 = Z_32;
vars.Z{32} = Z_32;
vars.Z_33 = Z_33;
vars.Z{33} = Z_33;
vars.Z_34 = Z_34;
vars.Z{34} = Z_34;
vars.Z_35 = Z_35;
vars.Z{35} = Z_35;
vars.Z_36 = Z_36;
vars.Z{36} = Z_36;
vars.Z_37 = Z_37;
vars.Z{37} = Z_37;
vars.Z_38 = Z_38;
vars.Z{38} = Z_38;
vars.Z_39 = Z_39;
vars.Z{39} = Z_39;
vars.Z_40 = Z_40;
vars.Z{40} = Z_40;
vars.Z_41 = Z_41;
vars.Z{41} = Z_41;
vars.Z_42 = Z_42;
vars.Z{42} = Z_42;
vars.Z_43 = Z_43;
vars.Z{43} = Z_43;
vars.Z_44 = Z_44;
vars.Z{44} = Z_44;
vars.Z_45 = Z_45;
vars.Z{45} = Z_45;
vars.Z_46 = Z_46;
vars.Z{46} = Z_46;
vars.Z_47 = Z_47;
vars.Z{47} = Z_47;
vars.Z_48 = Z_48;
vars.Z{48} = Z_48;
vars.Z_49 = Z_49;
vars.Z{49} = Z_49;
vars.Z_50 = Z_50;
vars.Z{50} = Z_50;
status.cvx_status = cvx_status;
% Provide a drop-in replacement for csolve.
status.optval = cvx_optval;
status.converged = strcmp(cvx_status, 'Solved');
