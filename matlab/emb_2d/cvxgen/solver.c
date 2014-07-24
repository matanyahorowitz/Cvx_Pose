/* Produced by CVXGEN, 2013-10-23 17:05:38 -0400.  */
/* CVXGEN is Copyright (C) 2006-2012 Jacob Mattingley, jem@cvxgen.com. */
/* The code in this file is Copyright (C) 2006-2012 Jacob Mattingley. */
/* CVXGEN, or solvers produced by CVXGEN, cannot be used for commercial */
/* applications without prior written permission from Jacob Mattingley. */

/* Filename: solver.c. */
/* Description: Main solver file. */
#include "solver.h"
double eval_gap(void) {
  int i;
  double gap;
  gap = 0;
  for (i = 0; i < 0; i++)
    gap += work.z[i]*work.s[i];
  return gap;
}
void set_defaults(void) {
  settings.resid_tol = 1e-6;
  settings.eps = 1e-4;
  settings.max_iters = 25;
  settings.refine_steps = 1;
  settings.s_init = 1;
  settings.z_init = 1;
  settings.debug = 0;
  settings.verbose = 1;
  settings.verbose_refinement = 0;
  settings.better_start = 1;
  settings.kkt_reg = 1e-7;
}
void setup_pointers(void) {
  work.y = work.x + 6;
  work.s = work.x + 10;
  work.z = work.x + 10;
  vars.R_1 = work.x + 0;
  vars.R_2 = work.x + 2;
}
void setup_indexed_params(void) {
  /* In CVXGEN, you can say */
  /*   parameters */
  /*     A[i] (5,3), i=1..4 */
  /*   end */
  /* This function sets up A[2] to be a pointer to A_2, which is a length-15 */
  /* vector of doubles. */
  /* If you access parameters that you haven't defined in CVXGEN, the result */
  /* is undefined. */
  params.data[1] = params.data_1;
  params.model[1] = params.model_1;
  params.data[2] = params.data_2;
  params.model[2] = params.model_2;
  params.data[3] = params.data_3;
  params.model[3] = params.model_3;
  params.data[4] = params.data_4;
  params.model[4] = params.model_4;
  params.data[5] = params.data_5;
  params.model[5] = params.model_5;
  params.data[6] = params.data_6;
  params.model[6] = params.model_6;
  params.data[7] = params.data_7;
  params.model[7] = params.model_7;
  params.data[8] = params.data_8;
  params.model[8] = params.model_8;
  params.data[9] = params.data_9;
  params.model[9] = params.model_9;
  params.data[10] = params.data_10;
  params.model[10] = params.model_10;
  params.data[11] = params.data_11;
  params.model[11] = params.model_11;
  params.data[12] = params.data_12;
  params.model[12] = params.model_12;
  params.data[13] = params.data_13;
  params.model[13] = params.model_13;
  params.data[14] = params.data_14;
  params.model[14] = params.model_14;
  params.data[15] = params.data_15;
  params.model[15] = params.model_15;
  params.data[16] = params.data_16;
  params.model[16] = params.model_16;
  params.data[17] = params.data_17;
  params.model[17] = params.model_17;
  params.data[18] = params.data_18;
  params.model[18] = params.model_18;
  params.data[19] = params.data_19;
  params.model[19] = params.model_19;
  params.data[20] = params.data_20;
  params.model[20] = params.model_20;
  params.data[21] = params.data_21;
  params.model[21] = params.model_21;
  params.data[22] = params.data_22;
  params.model[22] = params.model_22;
  params.data[23] = params.data_23;
  params.model[23] = params.model_23;
  params.data[24] = params.data_24;
  params.model[24] = params.model_24;
  params.data[25] = params.data_25;
  params.model[25] = params.model_25;
  params.data[26] = params.data_26;
  params.model[26] = params.model_26;
  params.data[27] = params.data_27;
  params.model[27] = params.model_27;
  params.data[28] = params.data_28;
  params.model[28] = params.model_28;
  params.data[29] = params.data_29;
  params.model[29] = params.model_29;
  params.data[30] = params.data_30;
  params.model[30] = params.model_30;
  params.data[31] = params.data_31;
  params.model[31] = params.model_31;
  params.data[32] = params.data_32;
  params.model[32] = params.model_32;
  params.data[33] = params.data_33;
  params.model[33] = params.model_33;
  params.data[34] = params.data_34;
  params.model[34] = params.model_34;
  params.data[35] = params.data_35;
  params.model[35] = params.model_35;
  params.data[36] = params.data_36;
  params.model[36] = params.model_36;
  params.data[37] = params.data_37;
  params.model[37] = params.model_37;
  params.data[38] = params.data_38;
  params.model[38] = params.model_38;
  params.data[39] = params.data_39;
  params.model[39] = params.model_39;
  params.data[40] = params.data_40;
  params.model[40] = params.model_40;
  params.data[41] = params.data_41;
  params.model[41] = params.model_41;
  params.data[42] = params.data_42;
  params.model[42] = params.model_42;
  params.data[43] = params.data_43;
  params.model[43] = params.model_43;
  params.data[44] = params.data_44;
  params.model[44] = params.model_44;
  params.data[45] = params.data_45;
  params.model[45] = params.model_45;
  params.data[46] = params.data_46;
  params.model[46] = params.model_46;
  params.data[47] = params.data_47;
  params.model[47] = params.model_47;
  params.data[48] = params.data_48;
  params.model[48] = params.model_48;
  params.data[49] = params.data_49;
  params.model[49] = params.model_49;
  params.data[50] = params.data_50;
  params.model[50] = params.model_50;
  params.data[51] = params.data_51;
  params.model[51] = params.model_51;
  params.data[52] = params.data_52;
  params.model[52] = params.model_52;
  params.data[53] = params.data_53;
  params.model[53] = params.model_53;
  params.data[54] = params.data_54;
  params.model[54] = params.model_54;
  params.data[55] = params.data_55;
  params.model[55] = params.model_55;
  params.data[56] = params.data_56;
  params.model[56] = params.model_56;
  params.data[57] = params.data_57;
  params.model[57] = params.model_57;
  params.data[58] = params.data_58;
  params.model[58] = params.model_58;
  params.data[59] = params.data_59;
  params.model[59] = params.model_59;
  params.data[60] = params.data_60;
  params.model[60] = params.model_60;
  params.data[61] = params.data_61;
  params.model[61] = params.model_61;
  params.data[62] = params.data_62;
  params.model[62] = params.model_62;
  params.data[63] = params.data_63;
  params.model[63] = params.model_63;
  params.data[64] = params.data_64;
  params.model[64] = params.model_64;
  params.data[65] = params.data_65;
  params.model[65] = params.model_65;
  params.data[66] = params.data_66;
  params.model[66] = params.model_66;
  params.data[67] = params.data_67;
  params.model[67] = params.model_67;
  params.data[68] = params.data_68;
  params.model[68] = params.model_68;
  params.data[69] = params.data_69;
  params.model[69] = params.model_69;
  params.data[70] = params.data_70;
  params.model[70] = params.model_70;
  params.data[71] = params.data_71;
  params.model[71] = params.model_71;
  params.data[72] = params.data_72;
  params.model[72] = params.model_72;
  params.data[73] = params.data_73;
  params.model[73] = params.model_73;
  params.data[74] = params.data_74;
  params.model[74] = params.model_74;
  params.data[75] = params.data_75;
  params.model[75] = params.model_75;
  params.data[76] = params.data_76;
  params.model[76] = params.model_76;
  params.data[77] = params.data_77;
  params.model[77] = params.model_77;
  params.data[78] = params.data_78;
  params.model[78] = params.model_78;
  params.data[79] = params.data_79;
  params.model[79] = params.model_79;
  params.data[80] = params.data_80;
  params.model[80] = params.model_80;
  params.data[81] = params.data_81;
  params.model[81] = params.model_81;
  params.data[82] = params.data_82;
  params.model[82] = params.model_82;
  params.data[83] = params.data_83;
  params.model[83] = params.model_83;
  params.data[84] = params.data_84;
  params.model[84] = params.model_84;
  params.data[85] = params.data_85;
  params.model[85] = params.model_85;
  params.data[86] = params.data_86;
  params.model[86] = params.model_86;
  params.data[87] = params.data_87;
  params.model[87] = params.model_87;
  params.data[88] = params.data_88;
  params.model[88] = params.model_88;
  params.data[89] = params.data_89;
  params.model[89] = params.model_89;
  params.data[90] = params.data_90;
  params.model[90] = params.model_90;
  params.data[91] = params.data_91;
  params.model[91] = params.model_91;
  params.data[92] = params.data_92;
  params.model[92] = params.model_92;
  params.data[93] = params.data_93;
  params.model[93] = params.model_93;
  params.data[94] = params.data_94;
  params.model[94] = params.model_94;
  params.data[95] = params.data_95;
  params.model[95] = params.model_95;
  params.data[96] = params.data_96;
  params.model[96] = params.model_96;
  params.data[97] = params.data_97;
  params.model[97] = params.model_97;
  params.data[98] = params.data_98;
  params.model[98] = params.model_98;
  params.data[99] = params.data_99;
  params.model[99] = params.model_99;
  params.data[100] = params.data_100;
  params.model[100] = params.model_100;
}
void setup_indexed_optvars(void) {
  /* In CVXGEN, you can say */
  /*   variables */
  /*     x[i] (5), i=2..4 */
  /*   end */
  /* This function sets up x[3] to be a pointer to x_3, which is a length-5 */
  /* vector of doubles. */
  /* If you access variables that you haven't defined in CVXGEN, the result */
  /* is undefined. */
  vars.R[1] = vars.R_1;
  vars.R[2] = vars.R_2;
}
void setup_indexing(void) {
  setup_pointers();
  setup_indexed_params();
  setup_indexed_optvars();
}
void set_start(void) {
  int i;
  for (i = 0; i < 6; i++)
    work.x[i] = 0;
  for (i = 0; i < 4; i++)
    work.y[i] = 0;
  for (i = 0; i < 0; i++)
    work.s[i] = (work.h[i] > 0) ? work.h[i] : settings.s_init;
  for (i = 0; i < 0; i++)
    work.z[i] = settings.z_init;
}
double eval_objv(void) {
  int i;
  double objv;
  /* Borrow space in work.rhs. */
  multbyP(work.rhs, work.x);
  objv = 0;
  for (i = 0; i < 6; i++)
    objv += work.x[i]*work.rhs[i];
  objv *= 0.5;
  for (i = 0; i < 6; i++)
    objv += work.q[i]*work.x[i];
  objv += 0;
  return objv;
}
void fillrhs_aff(void) {
  int i;
  double *r1, *r2, *r3, *r4;
  r1 = work.rhs;
  r2 = work.rhs + 6;
  r3 = work.rhs + 6;
  r4 = work.rhs + 6;
  /* r1 = -A^Ty - G^Tz - Px - q. */
  multbymAT(r1, work.y);
  multbymGT(work.buffer, work.z);
  for (i = 0; i < 6; i++)
    r1[i] += work.buffer[i];
  multbyP(work.buffer, work.x);
  for (i = 0; i < 6; i++)
    r1[i] -= work.buffer[i] + work.q[i];
  /* r2 = -z. */
  for (i = 0; i < 0; i++)
    r2[i] = -work.z[i];
  /* r3 = -Gx - s + h. */
  multbymG(r3, work.x);
  for (i = 0; i < 0; i++)
    r3[i] += -work.s[i] + work.h[i];
  /* r4 = -Ax + b. */
  multbymA(r4, work.x);
  for (i = 0; i < 4; i++)
    r4[i] += work.b[i];
}
void fillrhs_cc(void) {
  int i;
  double *r2;
  double *ds_aff, *dz_aff;
  double mu;
  double alpha;
  double sigma;
  double smu;
  double minval;
  r2 = work.rhs + 6;
  ds_aff = work.lhs_aff + 6;
  dz_aff = work.lhs_aff + 6;
  mu = 0;
  for (i = 0; i < 0; i++)
    mu += work.s[i]*work.z[i];
  /* Don't finish calculating mu quite yet. */
  /* Find min(min(ds./s), min(dz./z)). */
  minval = 0;
  for (i = 0; i < 0; i++)
    if (ds_aff[i] < minval*work.s[i])
      minval = ds_aff[i]/work.s[i];
  for (i = 0; i < 0; i++)
    if (dz_aff[i] < minval*work.z[i])
      minval = dz_aff[i]/work.z[i];
  /* Find alpha. */
  if (-1 < minval)
      alpha = 1;
  else
      alpha = -1/minval;
  sigma = 0;
  for (i = 0; i < 0; i++)
    sigma += (work.s[i] + alpha*ds_aff[i])*
      (work.z[i] + alpha*dz_aff[i]);
  sigma /= mu;
  sigma = sigma*sigma*sigma;
  /* Finish calculating mu now. */
  smu = sigma*mu;
  /* Fill-in the rhs. */
  for (i = 0; i < 6; i++)
    work.rhs[i] = 0;
  for (i = 6; i < 10; i++)
    work.rhs[i] = 0;
  for (i = 0; i < 0; i++)
    r2[i] = work.s_inv[i]*(smu - ds_aff[i]*dz_aff[i]);
}
void refine(double *target, double *var) {
  int i, j;
  double *residual = work.buffer;
  double norm2;
  double *new_var = work.buffer2;
  for (j = 0; j < settings.refine_steps; j++) {
    norm2 = 0;
    matrix_multiply(residual, var);
    for (i = 0; i < 10; i++) {
      residual[i] = residual[i] - target[i];
      norm2 += residual[i]*residual[i];
    }
#ifndef ZERO_LIBRARY_MODE
    if (settings.verbose_refinement) {
      if (j == 0)
        printf("Initial residual before refinement has norm squared %.6g.\n", norm2);
      else
        printf("After refinement we get squared norm %.6g.\n", norm2);
    }
#endif
    /* Solve to find new_var = KKT \ (target - A*var). */
    ldl_solve(residual, new_var);
    /* Update var += new_var, or var += KKT \ (target - A*var). */
    for (i = 0; i < 10; i++) {
      var[i] -= new_var[i];
    }
  }
#ifndef ZERO_LIBRARY_MODE
  if (settings.verbose_refinement) {
    /* Check the residual once more, but only if we're reporting it, since */
    /* it's expensive. */
    norm2 = 0;
    matrix_multiply(residual, var);
    for (i = 0; i < 10; i++) {
      residual[i] = residual[i] - target[i];
      norm2 += residual[i]*residual[i];
    }
    if (j == 0)
      printf("Initial residual before refinement has norm squared %.6g.\n", norm2);
    else
      printf("After refinement we get squared norm %.6g.\n", norm2);
  }
#endif
}
double calc_ineq_resid_squared(void) {
  /* Calculates the norm ||-Gx - s + h||. */
  double norm2_squared;
  int i;
  /* Find -Gx. */
  multbymG(work.buffer, work.x);
  /* Add -s + h. */
  for (i = 0; i < 0; i++)
    work.buffer[i] += -work.s[i] + work.h[i];
  /* Now find the squared norm. */
  norm2_squared = 0;
  for (i = 0; i < 0; i++)
    norm2_squared += work.buffer[i]*work.buffer[i];
  return norm2_squared;
}
double calc_eq_resid_squared(void) {
  /* Calculates the norm ||-Ax + b||. */
  double norm2_squared;
  int i;
  /* Find -Ax. */
  multbymA(work.buffer, work.x);
  /* Add +b. */
  for (i = 0; i < 4; i++)
    work.buffer[i] += work.b[i];
  /* Now find the squared norm. */
  norm2_squared = 0;
  for (i = 0; i < 4; i++)
    norm2_squared += work.buffer[i]*work.buffer[i];
  return norm2_squared;
}
void better_start(void) {
  /* Calculates a better starting point, using a similar approach to CVXOPT. */
  /* Not yet speed optimized. */
  int i;
  double *x, *s, *z, *y;
  double alpha;
  work.block_33[0] = -1;
  /* Make sure sinvz is 1 to make hijacked KKT system ok. */
  for (i = 0; i < 0; i++)
    work.s_inv_z[i] = 1;
  fill_KKT();
  ldl_factor();
  fillrhs_start();
  /* Borrow work.lhs_aff for the solution. */
  ldl_solve(work.rhs, work.lhs_aff);
  /* Don't do any refinement for now. Precision doesn't matter too much. */
  x = work.lhs_aff;
  s = work.lhs_aff + 6;
  z = work.lhs_aff + 6;
  y = work.lhs_aff + 6;
  /* Just set x and y as is. */
  for (i = 0; i < 6; i++)
    work.x[i] = x[i];
  for (i = 0; i < 4; i++)
    work.y[i] = y[i];
  /* Now complete the initialization. Start with s. */
  /* Must have alpha > max(z). */
  alpha = -1e99;
  for (i = 0; i < 0; i++)
    if (alpha < z[i])
      alpha = z[i];
  if (alpha < 0) {
    for (i = 0; i < 0; i++)
      work.s[i] = -z[i];
  } else {
    alpha += 1;
    for (i = 0; i < 0; i++)
      work.s[i] = -z[i] + alpha;
  }
  /* Now initialize z. */
  /* Now must have alpha > max(-z). */
  alpha = -1e99;
  for (i = 0; i < 0; i++)
    if (alpha < -z[i])
      alpha = -z[i];
  if (alpha < 0) {
    for (i = 0; i < 0; i++)
      work.z[i] = z[i];
  } else {
    alpha += 1;
    for (i = 0; i < 0; i++)
      work.z[i] = z[i] + alpha;
  }
}
void fillrhs_start(void) {
  /* Fill rhs with (-q, 0, h, b). */
  int i;
  double *r1, *r2, *r3, *r4;
  r1 = work.rhs;
  r2 = work.rhs + 6;
  r3 = work.rhs + 6;
  r4 = work.rhs + 6;
  for (i = 0; i < 6; i++)
    r1[i] = -work.q[i];
  for (i = 0; i < 0; i++)
    r2[i] = 0;
  for (i = 0; i < 0; i++)
    r3[i] = work.h[i];
  for (i = 0; i < 4; i++)
    r4[i] = work.b[i];
}
long solve(void) {
  int i;
  int iter;
  double *dx, *ds, *dy, *dz;
  double minval;
  double alpha;
  work.converged = 0;
  setup_pointers();
  pre_ops();
#ifndef ZERO_LIBRARY_MODE
  if (settings.verbose)
    printf("iter     objv        gap       |Ax-b|    |Gx+s-h|    step\n");
#endif
  fillq();
  fillh();
  fillb();
  if (settings.better_start)
    better_start();
  else
    set_start();
  for (iter = 0; iter < settings.max_iters; iter++) {
    for (i = 0; i < 0; i++) {
      work.s_inv[i] = 1.0 / work.s[i];
      work.s_inv_z[i] = work.s_inv[i]*work.z[i];
    }
    work.block_33[0] = 0;
    fill_KKT();
    ldl_factor();
    /* Affine scaling directions. */
    fillrhs_aff();
    ldl_solve(work.rhs, work.lhs_aff);
    refine(work.rhs, work.lhs_aff);
    /* Centering plus corrector directions. */
    fillrhs_cc();
    ldl_solve(work.rhs, work.lhs_cc);
    refine(work.rhs, work.lhs_cc);
    /* Add the two together and store in aff. */
    for (i = 0; i < 10; i++)
      work.lhs_aff[i] += work.lhs_cc[i];
    /* Rename aff to reflect its new meaning. */
    dx = work.lhs_aff;
    ds = work.lhs_aff + 6;
    dz = work.lhs_aff + 6;
    dy = work.lhs_aff + 6;
    /* Find min(min(ds./s), min(dz./z)). */
    minval = 0;
    for (i = 0; i < 0; i++)
      if (ds[i] < minval*work.s[i])
        minval = ds[i]/work.s[i];
    for (i = 0; i < 0; i++)
      if (dz[i] < minval*work.z[i])
        minval = dz[i]/work.z[i];
    /* Find alpha. */
    if (-0.99 < minval)
      alpha = 1;
    else
      alpha = -0.99/minval;
    /* Update the primal and dual variables. */
    for (i = 0; i < 6; i++)
      work.x[i] += alpha*dx[i];
    for (i = 0; i < 0; i++)
      work.s[i] += alpha*ds[i];
    for (i = 0; i < 0; i++)
      work.z[i] += alpha*dz[i];
    for (i = 0; i < 4; i++)
      work.y[i] += alpha*dy[i];
    work.gap = eval_gap();
    work.eq_resid_squared = calc_eq_resid_squared();
    work.ineq_resid_squared = calc_ineq_resid_squared();
#ifndef ZERO_LIBRARY_MODE
    if (settings.verbose) {
      work.optval = eval_objv();
      printf("%3d   %10.3e  %9.2e  %9.2e  %9.2e  % 6.4f\n",
          iter+1, work.optval, work.gap, sqrt(work.eq_resid_squared),
          sqrt(work.ineq_resid_squared), alpha);
    }
#endif
    /* Test termination conditions. Requires optimality, and satisfied */
    /* constraints. */
    if (   (work.gap < settings.eps)
        && (work.eq_resid_squared <= settings.resid_tol*settings.resid_tol)
        && (work.ineq_resid_squared <= settings.resid_tol*settings.resid_tol)
       ) {
      work.converged = 1;
      work.optval = eval_objv();
      return iter+1;
    }
  }
  return iter;
}
