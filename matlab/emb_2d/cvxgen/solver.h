/* Produced by CVXGEN, 2013-10-23 17:05:38 -0400.  */
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
  double data_51[2];
  double model_51[2];
  double data_52[2];
  double model_52[2];
  double data_53[2];
  double model_53[2];
  double data_54[2];
  double model_54[2];
  double data_55[2];
  double model_55[2];
  double data_56[2];
  double model_56[2];
  double data_57[2];
  double model_57[2];
  double data_58[2];
  double model_58[2];
  double data_59[2];
  double model_59[2];
  double data_60[2];
  double model_60[2];
  double data_61[2];
  double model_61[2];
  double data_62[2];
  double model_62[2];
  double data_63[2];
  double model_63[2];
  double data_64[2];
  double model_64[2];
  double data_65[2];
  double model_65[2];
  double data_66[2];
  double model_66[2];
  double data_67[2];
  double model_67[2];
  double data_68[2];
  double model_68[2];
  double data_69[2];
  double model_69[2];
  double data_70[2];
  double model_70[2];
  double data_71[2];
  double model_71[2];
  double data_72[2];
  double model_72[2];
  double data_73[2];
  double model_73[2];
  double data_74[2];
  double model_74[2];
  double data_75[2];
  double model_75[2];
  double data_76[2];
  double model_76[2];
  double data_77[2];
  double model_77[2];
  double data_78[2];
  double model_78[2];
  double data_79[2];
  double model_79[2];
  double data_80[2];
  double model_80[2];
  double data_81[2];
  double model_81[2];
  double data_82[2];
  double model_82[2];
  double data_83[2];
  double model_83[2];
  double data_84[2];
  double model_84[2];
  double data_85[2];
  double model_85[2];
  double data_86[2];
  double model_86[2];
  double data_87[2];
  double model_87[2];
  double data_88[2];
  double model_88[2];
  double data_89[2];
  double model_89[2];
  double data_90[2];
  double model_90[2];
  double data_91[2];
  double model_91[2];
  double data_92[2];
  double model_92[2];
  double data_93[2];
  double model_93[2];
  double data_94[2];
  double model_94[2];
  double data_95[2];
  double model_95[2];
  double data_96[2];
  double model_96[2];
  double data_97[2];
  double model_97[2];
  double data_98[2];
  double model_98[2];
  double data_99[2];
  double model_99[2];
  double data_100[2];
  double model_100[2];
  double penalty[1];
  double *data[101];
  double *model[101];
} Params;
typedef struct Vars_t {
  double *R_1; /* 2 rows. */
  double *t_01; /* 1 rows. */
  double *t_02; /* 1 rows. */
  double *R_2; /* 2 rows. */
  double *R[3];
} Vars;
typedef struct Workspace_t {
  double *h;
  double *s_inv;
  double *s_inv_z;
  double b[4];
  double q[6];
  double rhs[10];
  double x[10];
  double *s;
  double *z;
  double *y;
  double lhs_aff[10];
  double lhs_cc[10];
  double buffer[10];
  double buffer2[10];
  double KKT[10];
  double L[10];
  double d[10];
  double v[10];
  double d_inv[10];
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
