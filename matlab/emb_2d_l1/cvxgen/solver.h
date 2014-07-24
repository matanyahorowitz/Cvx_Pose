/* Produced by CVXGEN, 2013-10-23 17:15:23 -0400.  */
/* CVXGEN is Copyright (C) 2006-2012 Jacob Mattingley, jem@cvxgen.com. */
/* The code in this file is Copyright (C) 2006-2012 Jacob Mattingley. */
/* CVXGEN, or solvers produced by CVXGEN, cannot be used for commercial */
/* applications without prior written permission from Jacob Mattingley. */

/* Filename: solver.h. */
/* Description: Header file with relevant definitions. */
#ifndef SOLVER_H
#define SOLVER_H
/* Uncomment the next line to remove all library dependencies. */
/*#define ZERO_LIBRARY_MODE */
#ifdef MATLAB_MEX_FILE
/* Matlab functions. MATLAB_MEX_FILE will be defined by the mex compiler. */
/* If you are not using the mex compiler, this functionality will not intrude, */
/* as it will be completely disabled at compile-time. */
#include "mex.h"
#else
#ifndef ZERO_LIBRARY_MODE
#include <stdio.h>
#endif
#endif
/* Space must be allocated somewhere (testsolver.c, csolve.c or your own */
/* program) for the global variables vars, params, work and settings. */
/* At the bottom of this file, they are externed. */
#ifndef ZERO_LIBRARY_MODE
#include <math.h>
#define pm(A, m, n) printmatrix(#A, A, m, n, 1)
#endif
typedef struct Params_t {
  double data_1[2];
  double model_1[2];
  double lambda[1];
  double data_2[2];
  double model_2[2];
  double data_3[2];
  double model_3[2];
  double data_4[2];
  double model_4[2];
  double data_5[2];
  double model_5[2];
  double data_6[2];
  double model_6[2];
  double data_7[2];
  double model_7[2];
  double data_8[2];
  double model_8[2];
  double data_9[2];
  double model_9[2];
  double data_10[2];
  double model_10[2];
  double data_11[2];
  double model_11[2];
  double data_12[2];
  double model_12[2];
  double data_13[2];
  double model_13[2];
  double data_14[2];
  double model_14[2];
  double data_15[2];
  double model_15[2];
  double data_16[2];
  double model_16[2];
  double data_17[2];
  double model_17[2];
  double data_18[2];
  double model_18[2];
  double data_19[2];
  double model_19[2];
  double data_20[2];
  double model_20[2];
  double data_21[2];
  double model_21[2];
  double data_22[2];
  double model_22[2];
  double data_23[2];
  double model_23[2];
  double data_24[2];
  double model_24[2];
  double data_25[2];
  double model_25[2];
  double data_26[2];
  double model_26[2];
  double data_27[2];
  double model_27[2];
  double data_28[2];
  double model_28[2];
  double data_29[2];
  double model_29[2];
  double data_30[2];
  double model_30[2];
  double data_31[2];
  double model_31[2];
  double data_32[2];
  double model_32[2];
  double data_33[2];
  double model_33[2];
  double data_34[2];
  double model_34[2];
  double data_35[2];
  double model_35[2];
  double data_36[2];
  double model_36[2];
  double data_37[2];
  double model_37[2];
  double data_38[2];
  double model_38[2];
  double data_39[2];
  double model_39[2];
  double data_40[2];
  double model_40[2];
  double data_41[2];
  double model_41[2];
  double data_42[2];
  double model_42[2];
  double data_43[2];
  double model_43[2];
  double data_44[2];
  double model_44[2];
  double data_45[2];
  double model_45[2];
  double data_46[2];
  double model_46[2];
  double data_47[2];
  double model_47[2];
  double data_48[2];
  double model_48[2];
  double data_49[2];
  double model_49[2];
  double data_50[2];
  double model_50[2];
  double penalty[1];
  double *data[51];
  double *model[51];
} Params;
typedef struct Vars_t {
  double *t_01; /* 1 rows. */
  double *t_02; /* 1 rows. */
  double *t_03; /* 1 rows. */
  double *t_04; /* 1 rows. */
  double *t_05; /* 1 rows. */
  double *t_06; /* 1 rows. */
  double *t_07; /* 1 rows. */
  double *t_08; /* 1 rows. */
  double *t_09; /* 1 rows. */
  double *t_10; /* 1 rows. */
  double *t_11; /* 1 rows. */
  double *t_12; /* 1 rows. */
  double *t_13; /* 1 rows. */
  double *t_14; /* 1 rows. */
  double *t_15; /* 1 rows. */
  double *t_16; /* 1 rows. */
  double *t_17; /* 1 rows. */
  double *t_18; /* 1 rows. */
  double *t_19; /* 1 rows. */
  double *t_20; /* 1 rows. */
  double *t_21; /* 1 rows. */
  double *t_22; /* 1 rows. */
  double *t_23; /* 1 rows. */
  double *t_24; /* 1 rows. */
  double *t_25; /* 1 rows. */
  double *t_26; /* 1 rows. */
  double *t_27; /* 1 rows. */
  double *t_28; /* 1 rows. */
  double *t_29; /* 1 rows. */
  double *t_30; /* 1 rows. */
  double *t_31; /* 1 rows. */
  double *t_32; /* 1 rows. */
  double *t_33; /* 1 rows. */
  double *t_34; /* 1 rows. */
  double *t_35; /* 1 rows. */
  double *t_36; /* 1 rows. */
  double *t_37; /* 1 rows. */
  double *t_38; /* 1 rows. */
  double *t_39; /* 1 rows. */
  double *t_40; /* 1 rows. */
  double *t_41; /* 1 rows. */
  double *t_42; /* 1 rows. */
  double *t_43; /* 1 rows. */
  double *t_44; /* 1 rows. */
  double *t_45; /* 1 rows. */
  double *t_46; /* 1 rows. */
  double *t_47; /* 1 rows. */
  double *t_48; /* 1 rows. */
  double *t_49; /* 1 rows. */
  double *t_50; /* 1 rows. */
  double *t_51; /* 1 rows. */
  double *t_52; /* 1 rows. */
  double *t_53; /* 1 rows. */
  double *t_54; /* 1 rows. */
  double *t_55; /* 1 rows. */
  double *t_56; /* 1 rows. */
  double *t_57; /* 1 rows. */
  double *t_58; /* 1 rows. */
  double *t_59; /* 1 rows. */
  double *t_60; /* 1 rows. */
  double *t_61; /* 1 rows. */
  double *t_62; /* 1 rows. */
  double *t_63; /* 1 rows. */
  double *t_64; /* 1 rows. */
  double *t_65; /* 1 rows. */
  double *t_66; /* 1 rows. */
  double *t_67; /* 1 rows. */
  double *t_68; /* 1 rows. */
  double *t_69; /* 1 rows. */
  double *t_70; /* 1 rows. */
  double *t_71; /* 1 rows. */
  double *t_72; /* 1 rows. */
  double *t_73; /* 1 rows. */
  double *t_74; /* 1 rows. */
  double *t_75; /* 1 rows. */
  double *t_76; /* 1 rows. */
  double *t_77; /* 1 rows. */
  double *t_78; /* 1 rows. */
  double *t_79; /* 1 rows. */
  double *t_80; /* 1 rows. */
  double *t_81; /* 1 rows. */
  double *t_82; /* 1 rows. */
  double *t_83; /* 1 rows. */
  double *t_84; /* 1 rows. */
  double *t_85; /* 1 rows. */
  double *t_86; /* 1 rows. */
  double *t_87; /* 1 rows. */
  double *t_88; /* 1 rows. */
  double *t_89; /* 1 rows. */
  double *t_90; /* 1 rows. */
  double *t_91; /* 1 rows. */
  double *t_92; /* 1 rows. */
  double *t_93; /* 1 rows. */
  double *t_94; /* 1 rows. */
  double *t_95; /* 1 rows. */
  double *t_96; /* 1 rows. */
  double *t_97; /* 1 rows. */
  double *t_98; /* 1 rows. */
  double *t_99; /* 1 rows. */
  double *t_100; /* 1 rows. */
  double *t_101; /* 1 rows. */
  double *t_102; /* 1 rows. */
  double *t_103; /* 1 rows. */
  double *t_104; /* 1 rows. */
  double *t_105; /* 1 rows. */
  double *t_106; /* 1 rows. */
  double *t_107; /* 1 rows. */
  double *t_108; /* 1 rows. */
  double *t_109; /* 1 rows. */
  double *t_110; /* 1 rows. */
  double *t_111; /* 1 rows. */
  double *t_112; /* 1 rows. */
  double *t_113; /* 1 rows. */
  double *t_114; /* 1 rows. */
  double *t_115; /* 1 rows. */
  double *t_116; /* 1 rows. */
  double *t_117; /* 1 rows. */
  double *t_118; /* 1 rows. */
  double *t_119; /* 1 rows. */
  double *t_120; /* 1 rows. */
  double *t_121; /* 1 rows. */
  double *t_122; /* 1 rows. */
  double *t_123; /* 1 rows. */
  double *t_124; /* 1 rows. */
  double *t_125; /* 1 rows. */
  double *t_126; /* 1 rows. */
  double *t_127; /* 1 rows. */
  double *t_128; /* 1 rows. */
  double *t_129; /* 1 rows. */
  double *t_130; /* 1 rows. */
  double *t_131; /* 1 rows. */
  double *t_132; /* 1 rows. */
  double *t_133; /* 1 rows. */
  double *t_134; /* 1 rows. */
  double *t_135; /* 1 rows. */
  double *t_136; /* 1 rows. */
  double *t_137; /* 1 rows. */
  double *t_138; /* 1 rows. */
  double *t_139; /* 1 rows. */
  double *t_140; /* 1 rows. */
  double *t_141; /* 1 rows. */
  double *t_142; /* 1 rows. */
  double *t_143; /* 1 rows. */
  double *t_144; /* 1 rows. */
  double *t_145; /* 1 rows. */
  double *t_146; /* 1 rows. */
  double *t_147; /* 1 rows. */
  double *t_148; /* 1 rows. */
  double *t_149; /* 1 rows. */
  double *t_150; /* 1 rows. */
  double *t_151; /* 1 rows. */
  double *t_152; /* 1 rows. */
  double *t_153; /* 1 rows. */
  double *t_154; /* 1 rows. */
  double *t_155; /* 1 rows. */
  double *t_156; /* 1 rows. */
  double *t_157; /* 1 rows. */
  double *t_158; /* 1 rows. */
  double *t_159; /* 1 rows. */
  double *t_160; /* 1 rows. */
  double *t_161; /* 1 rows. */
  double *t_162; /* 1 rows. */
  double *t_163; /* 1 rows. */
  double *t_164; /* 1 rows. */
  double *t_165; /* 1 rows. */
  double *t_166; /* 1 rows. */
  double *t_167; /* 1 rows. */
  double *t_168; /* 1 rows. */
  double *t_169; /* 1 rows. */
  double *t_170; /* 1 rows. */
  double *t_171; /* 1 rows. */
  double *t_172; /* 1 rows. */
  double *t_173; /* 1 rows. */
  double *t_174; /* 1 rows. */
  double *t_175; /* 1 rows. */
  double *t_176; /* 1 rows. */
  double *t_177; /* 1 rows. */
  double *t_178; /* 1 rows. */
  double *t_179; /* 1 rows. */
  double *t_180; /* 1 rows. */
  double *t_181; /* 1 rows. */
  double *t_182; /* 1 rows. */
  double *t_183; /* 1 rows. */
  double *t_184; /* 1 rows. */
  double *t_185; /* 1 rows. */
  double *t_186; /* 1 rows. */
  double *t_187; /* 1 rows. */
  double *t_188; /* 1 rows. */
  double *t_189; /* 1 rows. */
  double *t_190; /* 1 rows. */
  double *t_191; /* 1 rows. */
  double *t_192; /* 1 rows. */
  double *t_193; /* 1 rows. */
  double *t_194; /* 1 rows. */
  double *t_195; /* 1 rows. */
  double *t_196; /* 1 rows. */
  double *t_197; /* 1 rows. */
  double *t_198; /* 1 rows. */
  double *t_199; /* 1 rows. */
  double *t_200; /* 1 rows. */
  double *t_201; /* 1 rows. */
  double *t_202; /* 1 rows. */
  double *Z_1; /* 2 rows. */
  double *Z_2; /* 2 rows. */
  double *Z_3; /* 2 rows. */
  double *Z_4; /* 2 rows. */
  double *Z_5; /* 2 rows. */
  double *Z_6; /* 2 rows. */
  double *Z_7; /* 2 rows. */
  double *Z_8; /* 2 rows. */
  double *Z_9; /* 2 rows. */
  double *Z_10; /* 2 rows. */
  double *Z_11; /* 2 rows. */
  double *Z_12; /* 2 rows. */
  double *Z_13; /* 2 rows. */
  double *Z_14; /* 2 rows. */
  double *Z_15; /* 2 rows. */
  double *Z_16; /* 2 rows. */
  double *Z_17; /* 2 rows. */
  double *Z_18; /* 2 rows. */
  double *Z_19; /* 2 rows. */
  double *Z_20; /* 2 rows. */
  double *Z_21; /* 2 rows. */
  double *Z_22; /* 2 rows. */
  double *Z_23; /* 2 rows. */
  double *Z_24; /* 2 rows. */
  double *Z_25; /* 2 rows. */
  double *Z_26; /* 2 rows. */
  double *Z_27; /* 2 rows. */
  double *Z_28; /* 2 rows. */
  double *Z_29; /* 2 rows. */
  double *Z_30; /* 2 rows. */
  double *Z_31; /* 2 rows. */
  double *Z_32; /* 2 rows. */
  double *Z_33; /* 2 rows. */
  double *Z_34; /* 2 rows. */
  double *Z_35; /* 2 rows. */
  double *Z_36; /* 2 rows. */
  double *Z_37; /* 2 rows. */
  double *Z_38; /* 2 rows. */
  double *Z_39; /* 2 rows. */
  double *Z_40; /* 2 rows. */
  double *Z_41; /* 2 rows. */
  double *Z_42; /* 2 rows. */
  double *Z_43; /* 2 rows. */
  double *Z_44; /* 2 rows. */
  double *Z_45; /* 2 rows. */
  double *Z_46; /* 2 rows. */
  double *Z_47; /* 2 rows. */
  double *Z_48; /* 2 rows. */
  double *Z_49; /* 2 rows. */
  double *Z_50; /* 2 rows. */
  double *R_1; /* 2 rows. */
  double *T_1; /* 1 rows. */
  double *R_2; /* 2 rows. */
  double *T_2; /* 1 rows. */
  double *R[3];
  double *T[3];
  double *Z[51];
} Vars;
typedef struct Workspace_t {
  double h[200];
  double s_inv[200];
  double s_inv_z[200];
  double b[104];
  double q[308];
  double rhs[812];
  double x[812];
  double *s;
  double *z;
  double *y;
  double lhs_aff[812];
  double lhs_cc[812];
  double buffer[812];
  double buffer2[812];
  double KKT[1610];
  double L[1217];
  double d[812];
  double v[812];
  double d_inv[812];
  double gap;
  double optval;
  double ineq_resid_squared;
  double eq_resid_squared;
  double block_33[1];
  /* Pre-op symbols. */
  int converged;
} Workspace;
typedef struct Settings_t {
  double resid_tol;
  double eps;
  int max_iters;
  int refine_steps;
  int better_start;
  /* Better start obviates the need for s_init and z_init. */
  double s_init;
  double z_init;
  int verbose;
  /* Show extra details of the iterative refinement steps. */
  int verbose_refinement;
  int debug;
  /* For regularization. Minimum value of abs(D_ii) in the kkt D factor. */
  double kkt_reg;
} Settings;
extern Vars vars;
extern Params params;
extern Workspace work;
extern Settings settings;
/* Function definitions in ldl.c: */
void ldl_solve(double *target, double *var);
void ldl_factor(void);
double check_factorization(void);
void matrix_multiply(double *result, double *source);
double check_residual(double *target, double *multiplicand);
void fill_KKT(void);

/* Function definitions in matrix_support.c: */
void multbymA(double *lhs, double *rhs);
void multbymAT(double *lhs, double *rhs);
void multbymG(double *lhs, double *rhs);
void multbymGT(double *lhs, double *rhs);
void multbyP(double *lhs, double *rhs);
void fillq(void);
void fillh(void);
void fillb(void);
void pre_ops(void);

/* Function definitions in solver.c: */
double eval_gap(void);
void set_defaults(void);
void setup_pointers(void);
void setup_indexed_params(void);
void setup_indexed_optvars(void);
void setup_indexing(void);
void set_start(void);
double eval_objv(void);
void fillrhs_aff(void);
void fillrhs_cc(void);
void refine(double *target, double *var);
double calc_ineq_resid_squared(void);
double calc_eq_resid_squared(void);
void better_start(void);
void fillrhs_start(void);
long solve(void);

/* Function definitions in testsolver.c: */
int main(int argc, char **argv);
void load_default_data(void);

/* Function definitions in util.c: */
void tic(void);
float toc(void);
float tocq(void);
void printmatrix(char *name, double *A, int m, int n, int sparse);
double unif(double lower, double upper);
float ran1(long*idum, int reset);
float randn_internal(long *idum, int reset);
double randn(void);
void reset_rand(void);

#endif
