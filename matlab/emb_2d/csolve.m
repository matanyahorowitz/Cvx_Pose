% csolve  Solves a custom quadratic program very rapidly.
%
% [vars, status] = csolve(params, settings)
%
% solves the convex optimization problem
%
%   minimize( - (data_1(1)*R_1'*model_1 + data_1(1)*R_1'*model_1 + data_2(1)*R_1'*model_2 + data_2(1)*R_1'*model_2 + data_3(1)*R_1'*model_3 + data_3(1)*R_1'*model_3 + data_4(1)*R_1'*model_4 + data_4(1)*R_1'*model_4 + data_5(1)*R_1'*model_5 + data_5(1)*R_1'*model_5 + data_6(1)*R_1'*model_6 + data_6(1)*R_1'*model_6 + data_7(1)*R_1'*model_7 + data_7(1)*R_1'*model_7 + data_8(1)*R_1'*model_8 + data_8(1)*R_1'*model_8 + data_9(1)*R_1'*model_9 + data_9(1)*R_1'*model_9 + data_10(1)*R_1'*model_10 + data_10(1)*R_1'*model_10 + data_11(1)*R_1'*model_11 + data_11(1)*R_1'*model_11 + data_12(1)*R_1'*model_12 + data_12(1)*R_1'*model_12 + data_13(1)*R_1'*model_13 + data_13(1)*R_1'*model_13 + data_14(1)*R_1'*model_14 + data_14(1)*R_1'*model_14 + data_15(1)*R_1'*model_15 + data_15(1)*R_1'*model_15 + data_16(1)*R_1'*model_16 + data_16(1)*R_1'*model_16 + data_17(1)*R_1'*model_17 + data_17(1)*R_1'*model_17 + data_18(1)*R_1'*model_18 + data_18(1)*R_1'*model_18 + data_19(1)*R_1'*model_19 + data_19(1)*R_1'*model_19 + data_20(1)*R_1'*model_20 + data_20(1)*R_1'*model_20 + data_21(1)*R_1'*model_21 + data_21(1)*R_1'*model_21 + data_22(1)*R_1'*model_22 + data_22(1)*R_1'*model_22 + data_23(1)*R_1'*model_23 + data_23(1)*R_1'*model_23 + data_24(1)*R_1'*model_24 + data_24(1)*R_1'*model_24 + data_25(1)*R_1'*model_25 + data_25(1)*R_1'*model_25 + data_26(1)*R_1'*model_26 + data_26(1)*R_1'*model_26 + data_27(1)*R_1'*model_27 + data_27(1)*R_1'*model_27 + data_28(1)*R_1'*model_28 + data_28(1)*R_1'*model_28 + data_29(1)*R_1'*model_29 + data_29(1)*R_1'*model_29 + data_30(1)*R_1'*model_30 + data_30(1)*R_1'*model_30 + data_31(1)*R_1'*model_31 + data_31(1)*R_1'*model_31 + data_32(1)*R_1'*model_32 + data_32(1)*R_1'*model_32 + data_33(1)*R_1'*model_33 + data_33(1)*R_1'*model_33 + data_34(1)*R_1'*model_34 + data_34(1)*R_1'*model_34 + data_35(1)*R_1'*model_35 + data_35(1)*R_1'*model_35 + data_36(1)*R_1'*model_36 + data_36(1)*R_1'*model_36 + data_37(1)*R_1'*model_37 + data_37(1)*R_1'*model_37 + data_38(1)*R_1'*model_38 + data_38(1)*R_1'*model_38 + data_39(1)*R_1'*model_39 + data_39(1)*R_1'*model_39 + data_40(1)*R_1'*model_40 + data_40(1)*R_1'*model_40 + data_41(1)*R_1'*model_41 + data_41(1)*R_1'*model_41 + data_42(1)*R_1'*model_42 + data_42(1)*R_1'*model_42 + data_43(1)*R_1'*model_43 + data_43(1)*R_1'*model_43 + data_44(1)*R_1'*model_44 + data_44(1)*R_1'*model_44 + data_45(1)*R_1'*model_45 + data_45(1)*R_1'*model_45 + data_46(1)*R_1'*model_46 + data_46(1)*R_1'*model_46 + data_47(1)*R_1'*model_47 + data_47(1)*R_1'*model_47 + data_48(1)*R_1'*model_48 + data_48(1)*R_1'*model_48 + data_49(1)*R_1'*model_49 + data_49(1)*R_1'*model_49 + data_50(1)*R_1'*model_50 + data_50(1)*R_1'*model_50 + data_51(1)*R_1'*model_51 + data_51(1)*R_1'*model_51 + data_52(1)*R_1'*model_52 + data_52(1)*R_1'*model_52 + data_53(1)*R_1'*model_53 + data_53(1)*R_1'*model_53 + data_54(1)*R_1'*model_54 + data_54(1)*R_1'*model_54 + data_55(1)*R_1'*model_55 + data_55(1)*R_1'*model_55 + data_56(1)*R_1'*model_56 + data_56(1)*R_1'*model_56 + data_57(1)*R_1'*model_57 + data_57(1)*R_1'*model_57 + data_58(1)*R_1'*model_58 + data_58(1)*R_1'*model_58 + data_59(1)*R_1'*model_59 + data_59(1)*R_1'*model_59 + data_60(1)*R_1'*model_60 + data_60(1)*R_1'*model_60 + data_61(1)*R_1'*model_61 + data_61(1)*R_1'*model_61 + data_62(1)*R_1'*model_62 + data_62(1)*R_1'*model_62 + data_63(1)*R_1'*model_63 + data_63(1)*R_1'*model_63 + data_64(1)*R_1'*model_64 + data_64(1)*R_1'*model_64 + data_65(1)*R_1'*model_65 + data_65(1)*R_1'*model_65 + data_66(1)*R_1'*model_66 + data_66(1)*R_1'*model_66 + data_67(1)*R_1'*model_67 + data_67(1)*R_1'*model_67 + data_68(1)*R_1'*model_68 + data_68(1)*R_1'*model_68 + data_69(1)*R_1'*model_69 + data_69(1)*R_1'*model_69 + data_70(1)*R_1'*model_70 + data_70(1)*R_1'*model_70 + data_71(1)*R_1'*model_71 + data_71(1)*R_1'*model_71 + data_72(1)*R_1'*model_72 + data_72(1)*R_1'*model_72 + data_73(1)*R_1'*model_73 + data_73(1)*R_1'*model_73 + data_74(1)*R_1'*model_74 + data_74(1)*R_1'*model_74 + data_75(1)*R_1'*model_75 + data_75(1)*R_1'*model_75 + data_76(1)*R_1'*model_76 + data_76(1)*R_1'*model_76 + data_77(1)*R_1'*model_77 + data_77(1)*R_1'*model_77 + data_78(1)*R_1'*model_78 + data_78(1)*R_1'*model_78 + data_79(1)*R_1'*model_79 + data_79(1)*R_1'*model_79 + data_80(1)*R_1'*model_80 + data_80(1)*R_1'*model_80 + data_81(1)*R_1'*model_81 + data_81(1)*R_1'*model_81 + data_82(1)*R_1'*model_82 + data_82(1)*R_1'*model_82 + data_83(1)*R_1'*model_83 + data_83(1)*R_1'*model_83 + data_84(1)*R_1'*model_84 + data_84(1)*R_1'*model_84 + data_85(1)*R_1'*model_85 + data_85(1)*R_1'*model_85 + data_86(1)*R_1'*model_86 + data_86(1)*R_1'*model_86 + data_87(1)*R_1'*model_87 + data_87(1)*R_1'*model_87 + data_88(1)*R_1'*model_88 + data_88(1)*R_1'*model_88 + data_89(1)*R_1'*model_89 + data_89(1)*R_1'*model_89 + data_90(1)*R_1'*model_90 + data_90(1)*R_1'*model_90 + data_91(1)*R_1'*model_91 + data_91(1)*R_1'*model_91 + data_92(1)*R_1'*model_92 + data_92(1)*R_1'*model_92 + data_93(1)*R_1'*model_93 + data_93(1)*R_1'*model_93 + data_94(1)*R_1'*model_94 + data_94(1)*R_1'*model_94 + data_95(1)*R_1'*model_95 + data_95(1)*R_1'*model_95 + data_96(1)*R_1'*model_96 + data_96(1)*R_1'*model_96 + data_97(1)*R_1'*model_97 + data_97(1)*R_1'*model_97 + data_98(1)*R_1'*model_98 + data_98(1)*R_1'*model_98 + data_99(1)*R_1'*model_99 + data_99(1)*R_1'*model_99 + data_100(1)*R_1'*model_100 + data_100(1)*R_1'*model_100) + penalty*(square(R_1(1)) + square(R_1(2))))
%   subject to
%     R_1(1) == R_2(2)
%     R_1(2) == -R_2(1)
%
% with variables
%      R_1   2 x 1
%      R_2   2 x 1
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
%  data_51   2 x 1
%  data_52   2 x 1
%  data_53   2 x 1
%  data_54   2 x 1
%  data_55   2 x 1
%  data_56   2 x 1
%  data_57   2 x 1
%  data_58   2 x 1
%  data_59   2 x 1
%  data_60   2 x 1
%  data_61   2 x 1
%  data_62   2 x 1
%  data_63   2 x 1
%  data_64   2 x 1
%  data_65   2 x 1
%  data_66   2 x 1
%  data_67   2 x 1
%  data_68   2 x 1
%  data_69   2 x 1
%  data_70   2 x 1
%  data_71   2 x 1
%  data_72   2 x 1
%  data_73   2 x 1
%  data_74   2 x 1
%  data_75   2 x 1
%  data_76   2 x 1
%  data_77   2 x 1
%  data_78   2 x 1
%  data_79   2 x 1
%  data_80   2 x 1
%  data_81   2 x 1
%  data_82   2 x 1
%  data_83   2 x 1
%  data_84   2 x 1
%  data_85   2 x 1
%  data_86   2 x 1
%  data_87   2 x 1
%  data_88   2 x 1
%  data_89   2 x 1
%  data_90   2 x 1
%  data_91   2 x 1
%  data_92   2 x 1
%  data_93   2 x 1
%  data_94   2 x 1
%  data_95   2 x 1
%  data_96   2 x 1
%  data_97   2 x 1
%  data_98   2 x 1
%  data_99   2 x 1
% data_100   2 x 1
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
% model_51   2 x 1
% model_52   2 x 1
% model_53   2 x 1
% model_54   2 x 1
% model_55   2 x 1
% model_56   2 x 1
% model_57   2 x 1
% model_58   2 x 1
% model_59   2 x 1
% model_60   2 x 1
% model_61   2 x 1
% model_62   2 x 1
% model_63   2 x 1
% model_64   2 x 1
% model_65   2 x 1
% model_66   2 x 1
% model_67   2 x 1
% model_68   2 x 1
% model_69   2 x 1
% model_70   2 x 1
% model_71   2 x 1
% model_72   2 x 1
% model_73   2 x 1
% model_74   2 x 1
% model_75   2 x 1
% model_76   2 x 1
% model_77   2 x 1
% model_78   2 x 1
% model_79   2 x 1
% model_80   2 x 1
% model_81   2 x 1
% model_82   2 x 1
% model_83   2 x 1
% model_84   2 x 1
% model_85   2 x 1
% model_86   2 x 1
% model_87   2 x 1
% model_88   2 x 1
% model_89   2 x 1
% model_90   2 x 1
% model_91   2 x 1
% model_92   2 x 1
% model_93   2 x 1
% model_94   2 x 1
% model_95   2 x 1
% model_96   2 x 1
% model_97   2 x 1
% model_98   2 x 1
% model_99   2 x 1
% model_100   2 x 1
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
% Produced by CVXGEN, 2013-10-23 17:05:38 -0400.
% CVXGEN is Copyright (C) 2006-2012 Jacob Mattingley, jem@cvxgen.com.
% The code in this file is Copyright (C) 2006-2012 Jacob Mattingley.
% CVXGEN, or solvers produced by CVXGEN, cannot be used for commercial
% applications without prior written permission from Jacob Mattingley.

% Filename: csolve.m.
% Description: Help file for the Matlab solver interface.
