% csolve  Solves a custom quadratic program very rapidly.
%
% [vars, status] = csolve(params, settings)
%
% solves the convex optimization problem
%
%   minimize(quad_form(data_1(1) - (R_1'*model_1 + T_1) - Z_1(1), eye(1)) + lambda*norm(Z_1(1), 1) + quad_form(data_1(2) - (R_2'*model_1 + T_2) - Z_1(2), eye(1)) + lambda*norm(Z_1(2), 1) + quad_form(data_2(1) - (R_1'*model_2 + T_1) - Z_2(1), eye(1)) + lambda*norm(Z_2(1), 1) + quad_form(data_2(2) - (R_2'*model_2 + T_2) - Z_2(2), eye(1)) + lambda*norm(Z_2(2), 1) + quad_form(data_3(1) - (R_1'*model_3 + T_1) - Z_3(1), eye(1)) + lambda*norm(Z_3(1), 1) + quad_form(data_3(2) - (R_2'*model_3 + T_2) - Z_3(2), eye(1)) + lambda*norm(Z_3(2), 1) + quad_form(data_4(1) - (R_1'*model_4 + T_1) - Z_4(1), eye(1)) + lambda*norm(Z_4(1), 1) + quad_form(data_4(2) - (R_2'*model_4 + T_2) - Z_4(2), eye(1)) + lambda*norm(Z_4(2), 1) + quad_form(data_5(1) - (R_1'*model_5 + T_1) - Z_5(1), eye(1)) + lambda*norm(Z_5(1), 1) + quad_form(data_5(2) - (R_2'*model_5 + T_2) - Z_5(2), eye(1)) + lambda*norm(Z_5(2), 1) + quad_form(data_6(1) - (R_1'*model_6 + T_1) - Z_6(1), eye(1)) + lambda*norm(Z_6(1), 1) + quad_form(data_6(2) - (R_2'*model_6 + T_2) - Z_6(2), eye(1)) + lambda*norm(Z_6(2), 1) + quad_form(data_7(1) - (R_1'*model_7 + T_1) - Z_7(1), eye(1)) + lambda*norm(Z_7(1), 1) + quad_form(data_7(2) - (R_2'*model_7 + T_2) - Z_7(2), eye(1)) + lambda*norm(Z_7(2), 1) + quad_form(data_8(1) - (R_1'*model_8 + T_1) - Z_8(1), eye(1)) + lambda*norm(Z_8(1), 1) + quad_form(data_8(2) - (R_2'*model_8 + T_2) - Z_8(2), eye(1)) + lambda*norm(Z_8(2), 1) + quad_form(data_9(1) - (R_1'*model_9 + T_1) - Z_9(1), eye(1)) + lambda*norm(Z_9(1), 1) + quad_form(data_9(2) - (R_2'*model_9 + T_2) - Z_9(2), eye(1)) + lambda*norm(Z_9(2), 1) + quad_form(data_10(1) - (R_1'*model_10 + T_1) - Z_10(1), eye(1)) + lambda*norm(Z_10(1), 1) + quad_form(data_10(2) - (R_2'*model_10 + T_2) - Z_10(2), eye(1)) + lambda*norm(Z_10(2), 1) + quad_form(data_11(1) - (R_1'*model_11 + T_1) - Z_11(1), eye(1)) + lambda*norm(Z_11(1), 1) + quad_form(data_11(2) - (R_2'*model_11 + T_2) - Z_11(2), eye(1)) + lambda*norm(Z_11(2), 1) + quad_form(data_12(1) - (R_1'*model_12 + T_1) - Z_12(1), eye(1)) + lambda*norm(Z_12(1), 1) + quad_form(data_12(2) - (R_2'*model_12 + T_2) - Z_12(2), eye(1)) + lambda*norm(Z_12(2), 1) + quad_form(data_13(1) - (R_1'*model_13 + T_1) - Z_13(1), eye(1)) + lambda*norm(Z_13(1), 1) + quad_form(data_13(2) - (R_2'*model_13 + T_2) - Z_13(2), eye(1)) + lambda*norm(Z_13(2), 1) + quad_form(data_14(1) - (R_1'*model_14 + T_1) - Z_14(1), eye(1)) + lambda*norm(Z_14(1), 1) + quad_form(data_14(2) - (R_2'*model_14 + T_2) - Z_14(2), eye(1)) + lambda*norm(Z_14(2), 1) + quad_form(data_15(1) - (R_1'*model_15 + T_1) - Z_15(1), eye(1)) + lambda*norm(Z_15(1), 1) + quad_form(data_15(2) - (R_2'*model_15 + T_2) - Z_15(2), eye(1)) + lambda*norm(Z_15(2), 1) + quad_form(data_16(1) - (R_1'*model_16 + T_1) - Z_16(1), eye(1)) + lambda*norm(Z_16(1), 1) + quad_form(data_16(2) - (R_2'*model_16 + T_2) - Z_16(2), eye(1)) + lambda*norm(Z_16(2), 1) + quad_form(data_17(1) - (R_1'*model_17 + T_1) - Z_17(1), eye(1)) + lambda*norm(Z_17(1), 1) + quad_form(data_17(2) - (R_2'*model_17 + T_2) - Z_17(2), eye(1)) + lambda*norm(Z_17(2), 1) + quad_form(data_18(1) - (R_1'*model_18 + T_1) - Z_18(1), eye(1)) + lambda*norm(Z_18(1), 1) + quad_form(data_18(2) - (R_2'*model_18 + T_2) - Z_18(2), eye(1)) + lambda*norm(Z_18(2), 1) + quad_form(data_19(1) - (R_1'*model_19 + T_1) - Z_19(1), eye(1)) + lambda*norm(Z_19(1), 1) + quad_form(data_19(2) - (R_2'*model_19 + T_2) - Z_19(2), eye(1)) + lambda*norm(Z_19(2), 1) + quad_form(data_20(1) - (R_1'*model_20 + T_1) - Z_20(1), eye(1)) + lambda*norm(Z_20(1), 1) + quad_form(data_20(2) - (R_2'*model_20 + T_2) - Z_20(2), eye(1)) + lambda*norm(Z_20(2), 1) + quad_form(data_21(1) - (R_1'*model_21 + T_1) - Z_21(1), eye(1)) + lambda*norm(Z_21(1), 1) + quad_form(data_21(2) - (R_2'*model_21 + T_2) - Z_21(2), eye(1)) + lambda*norm(Z_21(2), 1) + quad_form(data_22(1) - (R_1'*model_22 + T_1) - Z_22(1), eye(1)) + lambda*norm(Z_22(1), 1) + quad_form(data_22(2) - (R_2'*model_22 + T_2) - Z_22(2), eye(1)) + lambda*norm(Z_22(2), 1) + quad_form(data_23(1) - (R_1'*model_23 + T_1) - Z_23(1), eye(1)) + lambda*norm(Z_23(1), 1) + quad_form(data_23(2) - (R_2'*model_23 + T_2) - Z_23(2), eye(1)) + lambda*norm(Z_23(2), 1) + quad_form(data_24(1) - (R_1'*model_24 + T_1) - Z_24(1), eye(1)) + lambda*norm(Z_24(1), 1) + quad_form(data_24(2) - (R_2'*model_24 + T_2) - Z_24(2), eye(1)) + lambda*norm(Z_24(2), 1) + quad_form(data_25(1) - (R_1'*model_25 + T_1) - Z_25(1), eye(1)) + lambda*norm(Z_25(1), 1) + quad_form(data_25(2) - (R_2'*model_25 + T_2) - Z_25(2), eye(1)) + lambda*norm(Z_25(2), 1) + quad_form(data_26(1) - (R_1'*model_26 + T_1) - Z_26(1), eye(1)) + lambda*norm(Z_26(1), 1) + quad_form(data_26(2) - (R_2'*model_26 + T_2) - Z_26(2), eye(1)) + lambda*norm(Z_26(2), 1) + quad_form(data_27(1) - (R_1'*model_27 + T_1) - Z_27(1), eye(1)) + lambda*norm(Z_27(1), 1) + quad_form(data_27(2) - (R_2'*model_27 + T_2) - Z_27(2), eye(1)) + lambda*norm(Z_27(2), 1) + quad_form(data_28(1) - (R_1'*model_28 + T_1) - Z_28(1), eye(1)) + lambda*norm(Z_28(1), 1) + quad_form(data_28(2) - (R_2'*model_28 + T_2) - Z_28(2), eye(1)) + lambda*norm(Z_28(2), 1) + quad_form(data_29(1) - (R_1'*model_29 + T_1) - Z_29(1), eye(1)) + lambda*norm(Z_29(1), 1) + quad_form(data_29(2) - (R_2'*model_29 + T_2) - Z_29(2), eye(1)) + lambda*norm(Z_29(2), 1) + quad_form(data_30(1) - (R_1'*model_30 + T_1) - Z_30(1), eye(1)) + lambda*norm(Z_30(1), 1) + quad_form(data_30(2) - (R_2'*model_30 + T_2) - Z_30(2), eye(1)) + lambda*norm(Z_30(2), 1) + quad_form(data_31(1) - (R_1'*model_31 + T_1) - Z_31(1), eye(1)) + lambda*norm(Z_31(1), 1) + quad_form(data_31(2) - (R_2'*model_31 + T_2) - Z_31(2), eye(1)) + lambda*norm(Z_31(2), 1) + quad_form(data_32(1) - (R_1'*model_32 + T_1) - Z_32(1), eye(1)) + lambda*norm(Z_32(1), 1) + quad_form(data_32(2) - (R_2'*model_32 + T_2) - Z_32(2), eye(1)) + lambda*norm(Z_32(2), 1) + quad_form(data_33(1) - (R_1'*model_33 + T_1) - Z_33(1), eye(1)) + lambda*norm(Z_33(1), 1) + quad_form(data_33(2) - (R_2'*model_33 + T_2) - Z_33(2), eye(1)) + lambda*norm(Z_33(2), 1) + quad_form(data_34(1) - (R_1'*model_34 + T_1) - Z_34(1), eye(1)) + lambda*norm(Z_34(1), 1) + quad_form(data_34(2) - (R_2'*model_34 + T_2) - Z_34(2), eye(1)) + lambda*norm(Z_34(2), 1) + quad_form(data_35(1) - (R_1'*model_35 + T_1) - Z_35(1), eye(1)) + lambda*norm(Z_35(1), 1) + quad_form(data_35(2) - (R_2'*model_35 + T_2) - Z_35(2), eye(1)) + lambda*norm(Z_35(2), 1) + quad_form(data_36(1) - (R_1'*model_36 + T_1) - Z_36(1), eye(1)) + lambda*norm(Z_36(1), 1) + quad_form(data_36(2) - (R_2'*model_36 + T_2) - Z_36(2), eye(1)) + lambda*norm(Z_36(2), 1) + quad_form(data_37(1) - (R_1'*model_37 + T_1) - Z_37(1), eye(1)) + lambda*norm(Z_37(1), 1) + quad_form(data_37(2) - (R_2'*model_37 + T_2) - Z_37(2), eye(1)) + lambda*norm(Z_37(2), 1) + quad_form(data_38(1) - (R_1'*model_38 + T_1) - Z_38(1), eye(1)) + lambda*norm(Z_38(1), 1) + quad_form(data_38(2) - (R_2'*model_38 + T_2) - Z_38(2), eye(1)) + lambda*norm(Z_38(2), 1) + quad_form(data_39(1) - (R_1'*model_39 + T_1) - Z_39(1), eye(1)) + lambda*norm(Z_39(1), 1) + quad_form(data_39(2) - (R_2'*model_39 + T_2) - Z_39(2), eye(1)) + lambda*norm(Z_39(2), 1) + quad_form(data_40(1) - (R_1'*model_40 + T_1) - Z_40(1), eye(1)) + lambda*norm(Z_40(1), 1) + quad_form(data_40(2) - (R_2'*model_40 + T_2) - Z_40(2), eye(1)) + lambda*norm(Z_40(2), 1) + quad_form(data_41(1) - (R_1'*model_41 + T_1) - Z_41(1), eye(1)) + lambda*norm(Z_41(1), 1) + quad_form(data_41(2) - (R_2'*model_41 + T_2) - Z_41(2), eye(1)) + lambda*norm(Z_41(2), 1) + quad_form(data_42(1) - (R_1'*model_42 + T_1) - Z_42(1), eye(1)) + lambda*norm(Z_42(1), 1) + quad_form(data_42(2) - (R_2'*model_42 + T_2) - Z_42(2), eye(1)) + lambda*norm(Z_42(2), 1) + quad_form(data_43(1) - (R_1'*model_43 + T_1) - Z_43(1), eye(1)) + lambda*norm(Z_43(1), 1) + quad_form(data_43(2) - (R_2'*model_43 + T_2) - Z_43(2), eye(1)) + lambda*norm(Z_43(2), 1) + quad_form(data_44(1) - (R_1'*model_44 + T_1) - Z_44(1), eye(1)) + lambda*norm(Z_44(1), 1) + quad_form(data_44(2) - (R_2'*model_44 + T_2) - Z_44(2), eye(1)) + lambda*norm(Z_44(2), 1) + quad_form(data_45(1) - (R_1'*model_45 + T_1) - Z_45(1), eye(1)) + lambda*norm(Z_45(1), 1) + quad_form(data_45(2) - (R_2'*model_45 + T_2) - Z_45(2), eye(1)) + lambda*norm(Z_45(2), 1) + quad_form(data_46(1) - (R_1'*model_46 + T_1) - Z_46(1), eye(1)) + lambda*norm(Z_46(1), 1) + quad_form(data_46(2) - (R_2'*model_46 + T_2) - Z_46(2), eye(1)) + lambda*norm(Z_46(2), 1) + quad_form(data_47(1) - (R_1'*model_47 + T_1) - Z_47(1), eye(1)) + lambda*norm(Z_47(1), 1) + quad_form(data_47(2) - (R_2'*model_47 + T_2) - Z_47(2), eye(1)) + lambda*norm(Z_47(2), 1) + quad_form(data_48(1) - (R_1'*model_48 + T_1) - Z_48(1), eye(1)) + lambda*norm(Z_48(1), 1) + quad_form(data_48(2) - (R_2'*model_48 + T_2) - Z_48(2), eye(1)) + lambda*norm(Z_48(2), 1) + quad_form(data_49(1) - (R_1'*model_49 + T_1) - Z_49(1), eye(1)) + lambda*norm(Z_49(1), 1) + quad_form(data_49(2) - (R_2'*model_49 + T_2) - Z_49(2), eye(1)) + lambda*norm(Z_49(2), 1) + quad_form(data_50(1) - (R_1'*model_50 + T_1) - Z_50(1), eye(1)) + lambda*norm(Z_50(1), 1) + quad_form(data_50(2) - (R_2'*model_50 + T_2) - Z_50(2), eye(1)) + lambda*norm(Z_50(2), 1) + penalty*(square(R_1(1)) + square(R_1(2))))
%   subject to
%     R_1(1) == R_2(2)
%     R_1(2) == -R_2(1)
%
% with variables
%      R_1   2 x 1
%      R_2   2 x 1
%      T_1   1 x 1
%      T_2   1 x 1
%      Z_1   2 x 1
%      Z_2   2 x 1
%      Z_3   2 x 1
%      Z_4   2 x 1
%      Z_5   2 x 1
%      Z_6   2 x 1
%      Z_7   2 x 1
%      Z_8   2 x 1
%      Z_9   2 x 1
%     Z_10   2 x 1
%     Z_11   2 x 1
%     Z_12   2 x 1
%     Z_13   2 x 1
%     Z_14   2 x 1
%     Z_15   2 x 1
%     Z_16   2 x 1
%     Z_17   2 x 1
%     Z_18   2 x 1
%     Z_19   2 x 1
%     Z_20   2 x 1
%     Z_21   2 x 1
%     Z_22   2 x 1
%     Z_23   2 x 1
%     Z_24   2 x 1
%     Z_25   2 x 1
%     Z_26   2 x 1
%     Z_27   2 x 1
%     Z_28   2 x 1
%     Z_29   2 x 1
%     Z_30   2 x 1
%     Z_31   2 x 1
%     Z_32   2 x 1
%     Z_33   2 x 1
%     Z_34   2 x 1
%     Z_35   2 x 1
%     Z_36   2 x 1
%     Z_37   2 x 1
%     Z_38   2 x 1
%     Z_39   2 x 1
%     Z_40   2 x 1
%     Z_41   2 x 1
%     Z_42   2 x 1
%     Z_43   2 x 1
%     Z_44   2 x 1
%     Z_45   2 x 1
%     Z_46   2 x 1
%     Z_47   2 x 1
%     Z_48   2 x 1
%     Z_49   2 x 1
%     Z_50   2 x 1
%
% and parameters
%   data_1   2 x 1
%   data_2   2 x 1
%   data_3   2 x 1
%   data_4   2 x 1
%   data_5   2 x 1
%   data_6   2 x 1
%   data_7   2 x 1
%   data_8   2 x 1
%   data_9   2 x 1
%  data_10   2 x 1
%  data_11   2 x 1
%  data_12   2 x 1
%  data_13   2 x 1
%  data_14   2 x 1
%  data_15   2 x 1
%  data_16   2 x 1
%  data_17   2 x 1
%  data_18   2 x 1
%  data_19   2 x 1
%  data_20   2 x 1
%  data_21   2 x 1
%  data_22   2 x 1
%  data_23   2 x 1
%  data_24   2 x 1
%  data_25   2 x 1
%  data_26   2 x 1
%  data_27   2 x 1
%  data_28   2 x 1
%  data_29   2 x 1
%  data_30   2 x 1
%  data_31   2 x 1
%  data_32   2 x 1
%  data_33   2 x 1
%  data_34   2 x 1
%  data_35   2 x 1
%  data_36   2 x 1
%  data_37   2 x 1
%  data_38   2 x 1
%  data_39   2 x 1
%  data_40   2 x 1
%  data_41   2 x 1
%  data_42   2 x 1
%  data_43   2 x 1
%  data_44   2 x 1
%  data_45   2 x 1
%  data_46   2 x 1
%  data_47   2 x 1
%  data_48   2 x 1
%  data_49   2 x 1
%  data_50   2 x 1
%   lambda   1 x 1    positive
%  model_1   2 x 1
%  model_2   2 x 1
%  model_3   2 x 1
%  model_4   2 x 1
%  model_5   2 x 1
%  model_6   2 x 1
%  model_7   2 x 1
%  model_8   2 x 1
%  model_9   2 x 1
% model_10   2 x 1
% model_11   2 x 1
% model_12   2 x 1
% model_13   2 x 1
% model_14   2 x 1
% model_15   2 x 1
% model_16   2 x 1
% model_17   2 x 1
% model_18   2 x 1
% model_19   2 x 1
% model_20   2 x 1
% model_21   2 x 1
% model_22   2 x 1
% model_23   2 x 1
% model_24   2 x 1
% model_25   2 x 1
% model_26   2 x 1
% model_27   2 x 1
% model_28   2 x 1
% model_29   2 x 1
% model_30   2 x 1
% model_31   2 x 1
% model_32   2 x 1
% model_33   2 x 1
% model_34   2 x 1
% model_35   2 x 1
% model_36   2 x 1
% model_37   2 x 1
% model_38   2 x 1
% model_39   2 x 1
% model_40   2 x 1
% model_41   2 x 1
% model_42   2 x 1
% model_43   2 x 1
% model_44   2 x 1
% model_45   2 x 1
% model_46   2 x 1
% model_47   2 x 1
% model_48   2 x 1
% model_49   2 x 1
% model_50   2 x 1
%  penalty   1 x 1    positive
%
% Note:
%   - Check status.converged, which will be 1 if optimization succeeded.
%   - You don't have to specify settings if you don't want to.
%   - To hide output, use settings.verbose = 0.
%   - To change iterations, use settings.max_iters = 20.
%   - You may wish to compare with cvxsolve to check the solver is correct.
%
% Specify params.data_1, ..., params.penalty, then run
%   [vars, status] = csolve(params, settings)
% Produced by CVXGEN, 2013-10-23 17:15:03 -0400.
% CVXGEN is Copyright (C) 2006-2012 Jacob Mattingley, jem@cvxgen.com.
% The code in this file is Copyright (C) 2006-2012 Jacob Mattingley.
% CVXGEN, or solvers produced by CVXGEN, cannot be used for commercial
% applications without prior written permission from Jacob Mattingley.

% Filename: csolve.m.
% Description: Help file for the Matlab solver interface.
