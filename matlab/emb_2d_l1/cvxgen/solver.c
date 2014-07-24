/* Produced by CVXGEN, 2013-10-23 17:15:15 -0400.  */
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
  for (i = 0; i < 200; i++)
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
  work.y = work.x + 308;
  work.s = work.x + 412;
  work.z = work.x + 612;
  vars.R_1 = work.x + 0;
  vars.R_2 = work.x + 2;
  vars.T_1 = work.x + 4;
  vars.T_2 = work.x + 5;
  vars.Z_1 = work.x + 6;
  vars.Z_2 = work.x + 8;
  vars.Z_3 = work.x + 10;
  vars.Z_4 = work.x + 12;
  vars.Z_5 = work.x + 14;
  vars.Z_6 = work.x + 16;
  vars.Z_7 = work.x + 18;
  vars.Z_8 = work.x + 20;
  vars.Z_9 = work.x + 22;
  vars.Z_10 = work.x + 24;
  vars.Z_11 = work.x + 26;
  vars.Z_12 = work.x + 28;
  vars.Z_13 = work.x + 30;
  vars.Z_14 = work.x + 32;
  vars.Z_15 = work.x + 34;
  vars.Z_16 = work.x + 36;
  vars.Z_17 = work.x + 38;
  vars.Z_18 = work.x + 40;
  vars.Z_19 = work.x + 42;
  vars.Z_20 = work.x + 44;
  vars.Z_21 = work.x + 46;
  vars.Z_22 = work.x + 48;
  vars.Z_23 = work.x + 50;
  vars.Z_24 = work.x + 52;
  vars.Z_25 = work.x + 54;
  vars.Z_26 = work.x + 56;
  vars.Z_27 = work.x + 58;
  vars.Z_28 = work.x + 60;
  vars.Z_29 = work.x + 62;
  vars.Z_30 = work.x + 64;
  vars.Z_31 = work.x + 66;
  vars.Z_32 = work.x + 68;
  vars.Z_33 = work.x + 70;
  vars.Z_34 = work.x + 72;
  vars.Z_35 = work.x + 74;
  vars.Z_36 = work.x + 76;
  vars.Z_37 = work.x + 78;
  vars.Z_38 = work.x + 80;
  vars.Z_39 = work.x + 82;
  vars.Z_40 = work.x + 84;
  vars.Z_41 = work.x + 86;
  vars.Z_42 = work.x + 88;
  vars.Z_43 = work.x + 90;
  vars.Z_44 = work.x + 92;
  vars.Z_45 = work.x + 94;
  vars.Z_46 = work.x + 96;
  vars.Z_47 = work.x + 98;
  vars.Z_48 = work.x + 100;
  vars.Z_49 = work.x + 102;
  vars.Z_50 = work.x + 104;
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
  vars.T[1] = vars.T_1;
  vars.Z[1] = vars.Z_1;
  vars.R[2] = vars.R_2;
  vars.T[2] = vars.T_2;
  vars.Z[2] = vars.Z_2;
  vars.Z[3] = vars.Z_3;
  vars.Z[4] = vars.Z_4;
  vars.Z[5] = vars.Z_5;
  vars.Z[6] = vars.Z_6;
  vars.Z[7] = vars.Z_7;
  vars.Z[8] = vars.Z_8;
  vars.Z[9] = vars.Z_9;
  vars.Z[10] = vars.Z_10;
  vars.Z[11] = vars.Z_11;
  vars.Z[12] = vars.Z_12;
  vars.Z[13] = vars.Z_13;
  vars.Z[14] = vars.Z_14;
  vars.Z[15] = vars.Z_15;
  vars.Z[16] = vars.Z_16;
  vars.Z[17] = vars.Z_17;
  vars.Z[18] = vars.Z_18;
  vars.Z[19] = vars.Z_19;
  vars.Z[20] = vars.Z_20;
  vars.Z[21] = vars.Z_21;
  vars.Z[22] = vars.Z_22;
  vars.Z[23] = vars.Z_23;
  vars.Z[24] = vars.Z_24;
  vars.Z[25] = vars.Z_25;
  vars.Z[26] = vars.Z_26;
  vars.Z[27] = vars.Z_27;
  vars.Z[28] = vars.Z_28;
  vars.Z[29] = vars.Z_29;
  vars.Z[30] = vars.Z_30;
  vars.Z[31] = vars.Z_31;
  vars.Z[32] = vars.Z_32;
  vars.Z[33] = vars.Z_33;
  vars.Z[34] = vars.Z_34;
  vars.Z[35] = vars.Z_35;
  vars.Z[36] = vars.Z_36;
  vars.Z[37] = vars.Z_37;
  vars.Z[38] = vars.Z_38;
  vars.Z[39] = vars.Z_39;
  vars.Z[40] = vars.Z_40;
  vars.Z[41] = vars.Z_41;
  vars.Z[42] = vars.Z_42;
  vars.Z[43] = vars.Z_43;
  vars.Z[44] = vars.Z_44;
  vars.Z[45] = vars.Z_45;
  vars.Z[46] = vars.Z_46;
  vars.Z[47] = vars.Z_47;
  vars.Z[48] = vars.Z_48;
  vars.Z[49] = vars.Z_49;
  vars.Z[50] = vars.Z_50;
}
void setup_indexing(void) {
  setup_pointers();
  setup_indexed_params();
  setup_indexed_optvars();
}
void set_start(void) {
  int i;
  for (i = 0; i < 308; i++)
    work.x[i] = 0;
  for (i = 0; i < 104; i++)
    work.y[i] = 0;
  for (i = 0; i < 200; i++)
    work.s[i] = (work.h[i] > 0) ? work.h[i] : settings.s_init;
  for (i = 0; i < 200; i++)
    work.z[i] = settings.z_init;
}
double eval_objv(void) {
  int i;
  double objv;
  /* Borrow space in work.rhs. */
  multbyP(work.rhs, work.x);
  objv = 0;
  for (i = 0; i < 308; i++)
    objv += work.x[i]*work.rhs[i];
  objv *= 0.5;
  for (i = 0; i < 308; i++)
    objv += work.q[i]*work.x[i];
  objv += 0;
  return objv;
}
void fillrhs_aff(void) {
  int i;
  double *r1, *r2, *r3, *r4;
  r1 = work.rhs;
  r2 = work.rhs + 308;
  r3 = work.rhs + 508;
  r4 = work.rhs + 708;
  /* r1 = -A^Ty - G^Tz - Px - q. */
  multbymAT(r1, work.y);
  multbymGT(work.buffer, work.z);
  for (i = 0; i < 308; i++)
    r1[i] += work.buffer[i];
  multbyP(work.buffer, work.x);
  for (i = 0; i < 308; i++)
    r1[i] -= work.buffer[i] + work.q[i];
  /* r2 = -z. */
  for (i = 0; i < 200; i++)
    r2[i] = -work.z[i];
  /* r3 = -Gx - s + h. */
  multbymG(r3, work.x);
  for (i = 0; i < 200; i++)
    r3[i] += -work.s[i] + work.h[i];
  /* r4 = -Ax + b. */
  multbymA(r4, work.x);
  for (i = 0; i < 104; i++)
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
  r2 = work.rhs + 308;
  ds_aff = work.lhs_aff + 308;
  dz_aff = work.lhs_aff + 508;
  mu = 0;
  for (i = 0; i < 200; i++)
    mu += work.s[i]*work.z[i];
  /* Don't finish calculating mu quite yet. */
  /* Find min(min(ds./s), min(dz./z)). */
  minval = 0;
  for (i = 0; i < 200; i++)
    if (ds_aff[i] < minval*work.s[i])
      minval = ds_aff[i]/work.s[i];
  for (i = 0; i < 200; i++)
    if (dz_aff[i] < minval*work.z[i])
      minval = dz_aff[i]/work.z[i];
  /* Find alpha. */
  if (-1 < minval)
      alpha = 1;
  else
      alpha = -1/minval;
  sigma = 0;
  for (i = 0; i < 200; i++)
    sigma += (work.s[i] + alpha*ds_aff[i])*
      (work.z[i] + alpha*dz_aff[i]);
  sigma /= mu;
  sigma = sigma*sigma*sigma;
  /* Finish calculating mu now. */
  mu *= 0.005;
  smu = sigma*mu;
  /* Fill-in the rhs. */
  for (i = 0; i < 308; i++)
    work.rhs[i] = 0;
  for (i = 508; i < 812; i++)
    work.rhs[i] = 0;
  for (i = 0; i < 200; i++)
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
    for (i = 0; i < 812; i++) {
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
    for (i = 0; i < 812; i++) {
      var[i] -= new_var[i];
    }
  }
#ifndef ZERO_LIBRARY_MODE
  if (settings.verbose_refinement) {
    /* Check the residual once more, but only if we're reporting it, since */
    /* it's expensive. */
    norm2 = 0;
    matrix_multiply(residual, var);
    for (i = 0; i < 812; i++) {
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
  for (i = 0; i < 200; i++)
    work.buffer[i] += -work.s[i] + work.h[i];
  /* Now find the squared norm. */
  norm2_squared = 0;
  for (i = 0; i < 200; i++)
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
  for (i = 0; i < 104; i++)
    work.buffer[i] += work.b[i];
  /* Now find the squared norm. */
  norm2_squared = 0;
  for (i = 0; i < 104; i++)
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
  for (i = 0; i < 200; i++)
    work.s_inv_z[i] = 1;
  fill_KKT();
  ldl_factor();
  fillrhs_start();
  /* Borrow work.lhs_aff for the solution. */
  ldl_solve(work.rhs, work.lhs_aff);
  /* Don't do any refinement for now. Precision doesn't matter too much. */
  x = work.lhs_aff;
  s = work.lhs_aff + 308;
  z = work.lhs_aff + 508;
  y = work.lhs_aff + 708;
  /* Just set x and y as is. */
  for (i = 0; i < 308; i++)
    work.x[i] = x[i];
  for (i = 0; i < 104; i++)
    work.y[i] = y[i];
  /* Now complete the initialization. Start with s. */
  /* Must have alpha > max(z). */
  alpha = -1e99;
  for (i = 0; i < 200; i++)
    if (alpha < z[i])
      alpha = z[i];
  if (alpha < 0) {
    for (i = 0; i < 200; i++)
      work.s[i] = -z[i];
  } else {
    alpha += 1;
    for (i = 0; i < 200; i++)
      work.s[i] = -z[i] + alpha;
  }
  /* Now initialize z. */
  /* Now must have alpha > max(-z). */
  alpha = -1e99;
  for (i = 0; i < 200; i++)
    if (alpha < -z[i])
      alpha = -z[i];
  if (alpha < 0) {
    for (i = 0; i < 200; i++)
      work.z[i] = z[i];
  } else {
    alpha += 1;
    for (i = 0; i < 200; i++)
      work.z[i] = z[i] + alpha;
  }
}
void fillrhs_start(void) {
  /* Fill rhs with (-q, 0, h, b). */
  int i;
  double *r1, *r2, *r3, *r4;
  r1 = work.rhs;
  r2 = work.rhs + 308;
  r3 = work.rhs + 508;
  r4 = work.rhs + 708;
  for (i = 0; i < 308; i++)
    r1[i] = -work.q[i];
  for (i = 0; i < 200; i++)
    r2[i] = 0;
  for (i = 0; i < 200; i++)
    r3[i] = work.h[i];
  for (i = 0; i < 104; i++)
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
    for (i = 0; i < 200; i++) {
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
    for (i = 0; i < 812; i++)
      work.lhs_aff[i] += work.lhs_cc[i];
    /* Rename aff to reflect its new meaning. */
    dx = work.lhs_aff;
    ds = work.lhs_aff + 308;
    dz = work.lhs_aff + 508;
    dy = work.lhs_aff + 708;
    /* Find min(min(ds./s), min(dz./z)). */
    minval = 0;
    for (i = 0; i < 200; i++)
      if (ds[i] < minval*work.s[i])
        minval = ds[i]/work.s[i];
    for (i = 0; i < 200; i++)
      if (dz[i] < minval*work.z[i])
        minval = dz[i]/work.z[i];
    /* Find alpha. */
    if (-0.99 < minval)
      alpha = 1;
    else
      alpha = -0.99/minval;
    /* Update the primal and dual variables. */
    for (i = 0; i < 308; i++)
      work.x[i] += alpha*dx[i];
    for (i = 0; i < 200; i++)
      work.s[i] += alpha*ds[i];
    for (i = 0; i < 200; i++)
      work.z[i] += alpha*dz[i];
    for (i = 0; i < 104; i++)
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
