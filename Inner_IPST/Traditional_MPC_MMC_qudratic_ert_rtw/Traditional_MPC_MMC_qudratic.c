/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Traditional_MPC_MMC_qudratic.c
 *
 * Code generated for Simulink model 'Traditional_MPC_MMC_qudratic'.
 *
 * Model version                  : 1.34
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Wed Feb  9 19:52:32 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Traditional_MPC_MMC_qudratic.h"
#include "Traditional_MPC_MMC_qudratic_private.h"

/* Block states (default storage) */
D_Work_Traditional_MPC_MMC_qudr Traditional_MPC_MMC_qudra_DWork;

/* External inputs (root inport signals with default storage) */
ExternalInputs_Traditional_MPC_ Traditional_MPC_MMC_qudratic_U;

/* External outputs (root outports fed by signals with default storage) */
ExternalOutputs_Traditional_MPC Traditional_MPC_MMC_qudratic_Y;

/* Real-time model */
RT_MODEL_Traditional_MPC_MMC_qu Traditional_MPC_MMC_qudratic_M_;
RT_MODEL_Traditional_MPC_MMC_qu *const Traditional_MPC_MMC_qudratic_M =
  &Traditional_MPC_MMC_qudratic_M_;

/* Forward declaration for local functions */
static void Traditional_MPC_MMC_qudr_xgetrf(real_T A[25], int32_T ipiv[5],
  int32_T *info);
static void Traditional_MPC_MMC_qu_mldivide(const real_T A[25], real_T B[5]);
static void Traditional_MPC_MMC__mldivide_g(const real_T A[25], real_T B[110]);
static void Traditional_MPC_MMC_qudr_QPhild(const real_T H[25], const real_T f[5],
  const real_T A_cons[110], const real_T b[22], real_T eta[5]);

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static void Traditional_MPC_MMC_qudr_xgetrf(real_T A[25], int32_T ipiv[5],
  int32_T *info)
{
  int32_T j;
  int32_T c;
  int32_T ix;
  real_T smax;
  int32_T k;
  int32_T iy;
  real_T y;
  int32_T c_ix;
  int32_T d;
  int32_T ijA;
  for (j = 0; j < 5; j++) {
    ipiv[j] = j + 1;
  }

  *info = 0;
  for (j = 0; j < 4; j++) {
    c = j * 6;
    iy = 0;
    ix = c;
    smax = fabs(A[c]);
    for (k = 2; k <= 5 - j; k++) {
      ix++;
      y = fabs(A[ix]);
      if (y > smax) {
        iy = k - 1;
        smax = y;
      }
    }

    if (A[c + iy] != 0.0) {
      if (iy != 0) {
        iy += j;
        ipiv[j] = iy + 1;
        ix = j;
        for (k = 0; k < 5; k++) {
          smax = A[ix];
          A[ix] = A[iy];
          A[iy] = smax;
          ix += 5;
          iy += 5;
        }
      }

      iy = (c - j) + 5;
      for (ix = c + 1; ix < iy; ix++) {
        A[ix] /= A[c];
      }
    } else {
      *info = j + 1;
    }

    iy = c;
    ix = c + 5;
    for (k = 0; k <= 3 - j; k++) {
      if (A[ix] != 0.0) {
        smax = -A[ix];
        c_ix = c + 1;
        d = (iy - j) + 10;
        for (ijA = iy + 6; ijA < d; ijA++) {
          A[ijA] += A[c_ix] * smax;
          c_ix++;
        }
      }

      ix += 5;
      iy += 5;
    }
  }

  if ((*info == 0) && (!(A[24] != 0.0))) {
    *info = 5;
  }
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static void Traditional_MPC_MMC_qu_mldivide(const real_T A[25], real_T B[5])
{
  real_T temp;
  real_T b_A[25];
  int32_T ipiv[5];
  int32_T info;
  int32_T kAcol;
  int32_T i;
  memcpy(&b_A[0], &A[0], 25U * sizeof(real_T));
  Traditional_MPC_MMC_qudr_xgetrf(b_A, ipiv, &info);
  if (ipiv[0] != 1) {
    temp = B[0];
    B[0] = B[ipiv[0] - 1];
    B[ipiv[0] - 1] = temp;
  }

  if (ipiv[1] != 2) {
    temp = B[1];
    B[1] = B[ipiv[1] - 1];
    B[ipiv[1] - 1] = temp;
  }

  if (ipiv[2] != 3) {
    temp = B[2];
    B[2] = B[ipiv[2] - 1];
    B[ipiv[2] - 1] = temp;
  }

  if (ipiv[3] != 4) {
    temp = B[3];
    B[3] = B[ipiv[3] - 1];
    B[ipiv[3] - 1] = temp;
  }

  for (info = 0; info < 5; info++) {
    kAcol = 5 * info;
    if (B[info] != 0.0) {
      for (i = info + 1; i + 1 < 6; i++) {
        B[i] -= b_A[i + kAcol] * B[info];
      }
    }
  }

  for (info = 4; info >= 0; info--) {
    kAcol = 5 * info;
    if (B[info] != 0.0) {
      B[info] /= b_A[info + kAcol];
      for (i = 0; i < info; i++) {
        B[i] -= b_A[i + kAcol] * B[info];
      }
    }
  }
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static void Traditional_MPC_MMC__mldivide_g(const real_T A[25], real_T B[110])
{
  real_T temp;
  int32_T ip;
  real_T b_A[25];
  int32_T ipiv[5];
  int32_T info;
  int32_T xj;
  int32_T kAcol;
  int32_T i;
  int32_T tmp;
  int32_T tmp_0;
  memcpy(&b_A[0], &A[0], 25U * sizeof(real_T));
  Traditional_MPC_MMC_qudr_xgetrf(b_A, ipiv, &info);
  for (info = 0; info < 4; info++) {
    if (info + 1 != ipiv[info]) {
      ip = ipiv[info] - 1;
      for (xj = 0; xj < 22; xj++) {
        kAcol = 5 * xj + info;
        temp = B[kAcol];
        tmp = 5 * xj + ip;
        B[kAcol] = B[tmp];
        B[tmp] = temp;
      }
    }
  }

  for (info = 0; info < 22; info++) {
    ip = 5 * info;
    for (xj = 0; xj < 5; xj++) {
      kAcol = 5 * xj;
      tmp = xj + ip;
      if (B[tmp] != 0.0) {
        for (i = xj + 2; i < 6; i++) {
          tmp_0 = (i + ip) - 1;
          B[tmp_0] -= b_A[(i + kAcol) - 1] * B[tmp];
        }
      }
    }
  }

  for (info = 0; info < 22; info++) {
    ip = 5 * info;
    for (xj = 4; xj >= 0; xj--) {
      kAcol = 5 * xj;
      tmp = xj + ip;
      if (B[tmp] != 0.0) {
        B[tmp] /= b_A[xj + kAcol];
        for (i = 0; i < xj; i++) {
          tmp_0 = i + ip;
          B[tmp_0] -= B[tmp] * b_A[i + kAcol];
        }
      }
    }
  }
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static void Traditional_MPC_MMC_qudr_QPhild(const real_T H[25], const real_T f[5],
  const real_T A_cons[110], const real_T b[22], real_T eta[5])
{
  real_T kk;
  real_T P[484];
  real_T d[22];
  real_T lambda[22];
  real_T b_b[110];
  real_T c_b[5];
  real_T b_b_tmp[110];
  int32_T b_i;
  int32_T i;
  real_T H_0[25];
  real_T A_cons_0;
  real_T P_0;
  int32_T i_0;
  int32_T u1_tmp;
  boolean_T exitg1;
  for (i = 0; i < 5; i++) {
    eta[i] = f[i];
  }

  for (u1_tmp = 0; u1_tmp < 25; u1_tmp++) {
    H_0[u1_tmp] = -H[u1_tmp];
  }

  Traditional_MPC_MMC_qu_mldivide(H_0, eta);
  kk = 0.0;
  for (i = 0; i < 22; i++) {
    A_cons_0 = 0.0;
    for (u1_tmp = 0; u1_tmp < 5; u1_tmp++) {
      A_cons_0 += A_cons[22 * u1_tmp + i] * eta[u1_tmp];
    }

    if (A_cons_0 > b[i]) {
      kk++;
    }
  }

  if (!(kk == 0.0)) {
    for (u1_tmp = 0; u1_tmp < 22; u1_tmp++) {
      for (i = 0; i < 5; i++) {
        b_b_tmp[i + 5 * u1_tmp] = A_cons[22 * i + u1_tmp];
      }
    }

    memcpy(&b_b[0], &b_b_tmp[0], 110U * sizeof(real_T));
    Traditional_MPC_MMC__mldivide_g(H, b_b);
    for (u1_tmp = 0; u1_tmp < 22; u1_tmp++) {
      for (i = 0; i < 22; i++) {
        b_i = i + 22 * u1_tmp;
        P[b_i] = 0.0;
        for (i_0 = 0; i_0 < 5; i_0++) {
          P[b_i] += A_cons[22 * i_0 + i] * b_b[5 * u1_tmp + i_0];
        }
      }
    }

    for (i = 0; i < 5; i++) {
      c_b[i] = f[i];
    }

    Traditional_MPC_MMC_qu_mldivide(H, c_b);
    for (i = 0; i < 22; i++) {
      kk = 0.0;
      for (u1_tmp = 0; u1_tmp < 5; u1_tmp++) {
        kk += A_cons[22 * u1_tmp + i] * c_b[u1_tmp];
      }

      d[i] = kk + b[i];
      lambda[i] = 0.0;
    }

    i = 0;
    exitg1 = false;
    while ((!exitg1) && (i < 38)) {
      kk = 0.0;
      for (b_i = 0; b_i < 22; b_i++) {
        A_cons_0 = lambda[b_i];
        P_0 = 0.0;
        for (u1_tmp = 0; u1_tmp < 22; u1_tmp++) {
          P_0 += P[22 * u1_tmp + b_i] * lambda[u1_tmp];
        }

        u1_tmp = 22 * b_i + b_i;
        P_0 = -((P_0 - P[u1_tmp] * lambda[b_i]) + d[b_i]) / P[u1_tmp];
        if ((0.0 > P_0) || rtIsNaN(P_0)) {
          lambda[b_i] = 0.0;
        } else {
          lambda[b_i] = P_0;
        }

        A_cons_0 = lambda[b_i] - A_cons_0;
        kk += A_cons_0 * A_cons_0;
      }

      if (kk < 1.0E-10) {
        exitg1 = true;
      } else {
        i++;
      }
    }

    memcpy(&b_b[0], &b_b_tmp[0], 110U * sizeof(real_T));
    Traditional_MPC_MMC__mldivide_g(H, b_b);
    for (i = 0; i < 5; i++) {
      c_b[i] = f[i];
    }

    for (u1_tmp = 0; u1_tmp < 25; u1_tmp++) {
      H_0[u1_tmp] = -H[u1_tmp];
    }

    Traditional_MPC_MMC_qu_mldivide(H_0, c_b);
    for (u1_tmp = 0; u1_tmp < 5; u1_tmp++) {
      kk = 0.0;
      for (i = 0; i < 22; i++) {
        kk += b_b[5 * i + u1_tmp] * lambda[i];
      }

      eta[u1_tmp] = c_b[u1_tmp] - kk;
    }
  }
}

/* Model step function */
void Traditional_MPC_MMC_qudratic_step(void)
{
  real_T g[5];
  real_T rtb_Memory[10];
  real_T rtb_Memory2[5];
  real_T rtb_deltau[5];
  real_T rtb_e[5];
  int32_T i;
  real_T tmp[22];
  real_T f_a[5];
  real_T b_a[5];
  real_T c_a[5];
  real_T tmp_0[5];
  real_T h_a;
  int32_T i_0;
  real_T rtb_Memory2_o;
  real_T h_a_tmp;
  int32_T a_tmp;
  static const real_T e_a[25] = { 0.99999999862857147, -3.9999999966476194E-5,
    0.0, 0.0, 0.0, 3.9999999966476194E-5, 0.99999999862857147, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.99999999942857143, 0.0, 0.0, 0.0, 0.0, 0.0, 0.99999993710570145,
    1.9999998744780695E-5, 0.0, 0.0, 0.0, -1.9999998744780695E-5,
    0.99999993710570145 };

  static const real_T f_a_0[25] = { -5.7142857111292513E-6,
    1.1428570788355223E-10, -0.0, 0.0, -0.0, -1.1428570788355222E-10,
    -5.7142857111292522E-6, -0.0, 0.0, -0.0, -0.0, 0.0, -5.7142857112779657E-6,
    0.0, -0.0, -0.0, 0.0, -0.0, 1.0362693974986372E-5, 1.0362694214141444E-10,
    -0.0, 0.0, -0.0, -1.0362694214141179E-10, 1.0362693974986372E-5 };

  static const int8_T a[25] = { 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0, 1 };

  static const real_T b_a_0[25] = { -0.0030171424136516221,
    -1.3074284455250352E-6, 0.0, 0.0, 0.0, 1.3074284455250352E-6,
    -0.0030171424136516225, 0.0, 0.0, 0.0, 0.0, 0.0, -0.0030171428377392551, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.005471498681898522, -1.1854909973102506E-6, 0.0, 0.0,
    0.0, 1.1854909973102518E-6, 0.005471498681898522 };

  static const real_T c_a_0[50] = { -0.065371422112884991, 1.3074285151248935E-6,
    0.0, 0.0, 0.0, -1.3074285151248617E-6, -0.065371422112885033, 0.0, 0.0, 0.0,
    0.0, 0.0, -0.0653714276267048, 0.0, 0.0, 0.0, 0.0, 0.0, 0.11854903545409806,
    1.1854903272607471E-6, 0.0, 0.0, 0.0, -1.1854903272607196E-6,
    0.11854903545409806, -0.0030171424136516221, -1.3074284455250352E-6, 0.0,
    0.0, 0.0, 1.3074284455250352E-6, -0.0030171424136516225, 0.0, 0.0, 0.0, 0.0,
    0.0, -0.0030171428377392551, 0.0, 0.0, 0.0, 0.0, 0.0, 0.005471498681898522,
    -1.1854909973102506E-6, 0.0, 0.0, 0.0, 1.1854909973102518E-6,
    0.005471498681898522 };

  static const real_T d_a[25] = { -0.0030158349852060966, -0.0030184498420971475,
    -0.0030171428377392551, 0.0054726841728958324, 0.0054703131909012116,
    -0.0030158349852060966, -0.0030184498420971475, -0.0030171428377392551,
    0.0054726841728958324, 0.0054703131909012116, -0.0030158349852060966,
    -0.0030184498420971475, -0.0030171428377392551, 0.0054726841728958324,
    0.0054703131909012116, -0.0030158349852060966, -0.0030184498420971475,
    -0.0030171428377392551, 0.0054726841728958324, 0.0054703131909012116,
    -0.0030158349852060966, -0.0030184498420971475, -0.0030171428377392551,
    0.0054726841728958324, 0.0054703131909012116 };

  static const real_T h_a_0[10] = { 0.0, 0.0, 0.0, 31.999964609435363,
    -0.010559985283843616, 0.0, 0.0, 0.0, 1.0, 0.0 };

  static const real_T b[25] = { 0.20000037355098366, -8.7089773252662577E-26,
    0.0, 0.0, 0.0, -8.7089773252662577E-26, 0.20000037355098366, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.20000037355101505, 0.0, 0.0, 0.0, 0.0, 0.0, 0.20000122848745258,
    2.7641300437200276E-25, 0.0, 0.0, 0.0, 2.7641300437200276E-25,
    0.20000122848745258 };

  static const real_T c[110] = { 1.0, 0.0, 0.0, 0.0, 0.0, -1.0, -0.0, -0.0, -0.0,
    -0.0, 1.0, 0.0, 0.0, 0.0, 0.0, -1.0, -0.0, -0.0, -0.0, -0.0, 0.0, -0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, -0.0, -1.0, -0.0, -0.0, -0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    -0.0, -1.0, -0.0, -0.0, -0.0, 0.0, -0.0, 0.0, 0.0, 1.0, 0.0, 0.0, -0.0, -0.0,
    -1.0, -0.0, -0.0, 0.0, 0.0, 1.0, 0.0, 0.0, -0.0, -0.0, -1.0, -0.0, -0.0, 0.0,
    -0.0, 0.0, 0.0, 0.0, 1.0, 0.0, -0.0, -0.0, -0.0, -1.0, -0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, -0.0, -0.0, -0.0, -1.0, -0.0, 0.00033160586234206885,
    -0.00033160586234206885, 0.0, 0.0, 0.0, 0.0, 1.0, -0.0, -0.0, -0.0, -0.0,
    -1.0, 0.0, 0.0, 0.0, 0.0, 1.0, -0.0, -0.0, -0.0, -0.0, -1.0,
    -1.0611384420129266E-7, 1.0611384420129266E-7 };

  static const int8_T g_a[25] = { -1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, -1, 0, 0,
    0, 0, 0, -1, 0, 0, 0, 0, 0, -1 };

  /* Memory: '<Root>/Memory' */
  memcpy(&rtb_Memory[0], &Traditional_MPC_MMC_qudra_DWork.Memory_PreviousInput[0],
         10U * sizeof(real_T));

  /* MATLAB Function 'MATLAB Function': '<S1>:1' */
  /* '<S1>:1:6' */
  /* '<S1>:1:7' */
  /* '<S1>:1:9' */
  /* '<S1>:1:11' */
  /* '<S1>:1:14' */
  /* '<S1>:1:8' */
  for (i = 0; i < 5; i++) {
    /* Memory: '<Root>/Memory2' */
    rtb_Memory2_o = Traditional_MPC_MMC_qudra_DWork.Memory2_PreviousInput[i];

    /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
     *  Inport: '<Root>/kth-state'
     */
    rtb_e[i] = rtb_Memory2_o;
    rtb_deltau[i] = 0.0;
    for (i_0 = 0; i_0 < 5; i_0++) {
      rtb_deltau[i] += e_a[5 * i_0 + i] *
        Traditional_MPC_MMC_qudratic_U.kthstate[i_0];
    }

    /* Memory: '<Root>/Memory2' */
    rtb_Memory2[i] = rtb_Memory2_o;
  }

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  Inport: '<Root>/du_max'
   *  Inport: '<Root>/du_min'
   *  Inport: '<Root>/kth-state'
   *  Inport: '<Root>/set_point'
   *  Inport: '<Root>/u_max'
   *  Inport: '<Root>/u_min'
   *  Inport: '<Root>/y_max'
   *  Inport: '<Root>/y_min'
   *  Memory: '<Root>/Memory1'
   */
  for (i_0 = 0; i_0 < 5; i_0++) {
    f_a[i_0] = 0.0;
    for (i = 0; i < 5; i++) {
      f_a[i_0] += f_a_0[5 * i + i_0] * rtb_e[i];
    }

    g[i_0] = rtb_deltau[i_0] + f_a[i_0];
  }

  for (i_0 = 0; i_0 < 5; i_0++) {
    rtb_Memory2_o = 0.0;
    for (i = 0; i < 5; i++) {
      rtb_Memory2_o += (real_T)a[5 * i + i_0] * g[i];
    }

    rtb_e[i_0] = rtb_Memory2_o - Traditional_MPC_MMC_qudratic_U.kthstate[i_0];
  }

  /* '<S1>:1:9' */
  for (i_0 = 0; i_0 < 5; i_0++) {
    b_a[i_0] = 0.0;
    for (i = 0; i < 5; i++) {
      b_a[i_0] += b_a_0[5 * i + i_0] *
        Traditional_MPC_MMC_qudratic_U.set_point[i];
    }

    c_a[i_0] = 0.0;
    for (i = 0; i < 10; i++) {
      c_a[i_0] += c_a_0[5 * i + i_0] * rtb_Memory[i];
    }

    tmp_0[i_0] = rtb_e[i_0];
  }

  /* '<S1>:1:11' */
  /* '<S1>:1:14' */
  for (i_0 = 0; i_0 < 5; i_0++) {
    rtb_Memory2_o = 0.0;
    for (i = 0; i < 5; i++) {
      rtb_Memory2_o += d_a[5 * i + i_0] * tmp_0[i];
    }

    g[i_0] = -((b_a[i_0] - c_a[i_0]) - rtb_Memory2_o);
    rtb_deltau[i_0] = Traditional_MPC_MMC_qudratic_U.u_max[i_0] -
      rtb_Memory2[i_0];
    f_a[i_0] = Traditional_MPC_MMC_qudratic_U.u_min[i_0] - rtb_Memory2[i_0];
  }

  rtb_Memory2_o = 0.0;
  h_a = 0.0;
  for (i_0 = 0; i_0 < 10; i_0++) {
    h_a_tmp = h_a_0[i_0] * rtb_Memory[i_0];
    rtb_Memory2_o += h_a_tmp;
    h_a += h_a_tmp;
  }

  for (i_0 = 0; i_0 < 5; i_0++) {
    b_a[i_0] = 0.0;
    c_a[i_0] = 0.0;
    for (i = 0; i < 5; i++) {
      a_tmp = 5 * i + i_0;
      b_a[i_0] += (real_T)a[a_tmp] * rtb_deltau[i];
      c_a[i_0] += (real_T)g_a[a_tmp] * f_a[i];
    }

    tmp[i_0] = Traditional_MPC_MMC_qudratic_U.du_max;
    tmp[i_0 + 5] = Traditional_MPC_MMC_qudratic_U.du_min;
    tmp[i_0 + 10] = b_a[i_0];
    tmp[i_0 + 15] = c_a[i_0];
  }

  tmp[20] = Traditional_MPC_MMC_qudratic_U.y_max - rtb_Memory2_o;
  tmp[21] = -Traditional_MPC_MMC_qudratic_U.y_min + h_a;
  Traditional_MPC_MMC_qudr_QPhild(b, g, c, tmp, rtb_deltau);

  /* '<S1>:1:15' */
  /* '<S1>:1:16' */
  /* '<S1>:1:17' */
  /* '<S1>:1:19' */
  /* '<S1>:1:20' */
  for (i = 0; i < 5; i++) {
    rtb_Memory[i] = Traditional_MPC_MMC_qudratic_U.kthstate[i] -
      Traditional_MPC_MMC_qudra_DWork.Memory1_PreviousInput[i];
    rtb_Memory[i + 5] = Traditional_MPC_MMC_qudratic_U.kthstate[i];
    rtb_Memory2[i] += rtb_deltau[i];
  }

  /* Outport: '<Root>/IntOut3' */
  memcpy(&Traditional_MPC_MMC_qudratic_Y.Xf[0], &rtb_Memory[0], 10U * sizeof
         (real_T));

  /* MATLAB Function: '<Root>/MATLAB Function' */
  h_a = 0.0;
  rtb_Memory2_o = 0.0;
  for (i = 0; i < 5; i++) {
    /* Outport: '<Root>/IntOut4' */
    Traditional_MPC_MMC_qudratic_Y.u[i] = rtb_Memory2[i];

    /* Outport: '<Root>/IntOut1' */
    Traditional_MPC_MMC_qudratic_Y.delta_u[i] = rtb_deltau[i];

    /* Outport: '<Root>/IntOut2' */
    Traditional_MPC_MMC_qudratic_Y.error[i] = rtb_e[i];

    /* MATLAB Function: '<Root>/MATLAB Function' */
    f_a[i] = 0.0;
    for (i_0 = 0; i_0 < 5; i_0++) {
      f_a[i] += b[5 * i + i_0] * rtb_deltau[i_0];
    }

    h_a += f_a[i] * rtb_deltau[i];
    rtb_Memory2_o += 2.0 * rtb_deltau[i] * g[i];
  }

  /* Outport: '<Root>/IntOut5' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function'
   */
  Traditional_MPC_MMC_qudratic_Y.J = h_a + rtb_Memory2_o;

  /* Update for Memory: '<Root>/Memory' */
  memcpy(&Traditional_MPC_MMC_qudra_DWork.Memory_PreviousInput[0], &rtb_Memory[0],
         10U * sizeof(real_T));
  for (i = 0; i < 5; i++) {
    /* Update for Memory: '<Root>/Memory2' */
    Traditional_MPC_MMC_qudra_DWork.Memory2_PreviousInput[i] = rtb_Memory2[i];

    /* Update for Memory: '<Root>/Memory1' incorporates:
     *  Inport: '<Root>/kth-state'
     */
    Traditional_MPC_MMC_qudra_DWork.Memory1_PreviousInput[i] =
      Traditional_MPC_MMC_qudratic_U.kthstate[i];
  }
}

/* Model initialize function */
void Traditional_MPC_MMC_qudratic_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(Traditional_MPC_MMC_qudratic_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&Traditional_MPC_MMC_qudra_DWork, 0,
                sizeof(D_Work_Traditional_MPC_MMC_qudr));

  /* external inputs */
  (void)memset(&Traditional_MPC_MMC_qudratic_U, 0, sizeof
               (ExternalInputs_Traditional_MPC_));

  /* external outputs */
  (void) memset((void *)&Traditional_MPC_MMC_qudratic_Y, 0,
                sizeof(ExternalOutputs_Traditional_MPC));

  {
    int32_T i;

    /* InitializeConditions for Memory: '<Root>/Memory' */
    for (i = 0; i < 10; i++) {
      Traditional_MPC_MMC_qudra_DWork.Memory_PreviousInput[i] =
        Traditional_MPC_MMC_qudratic_P.Memory_InitialCondition;
    }

    /* End of InitializeConditions for Memory: '<Root>/Memory' */
    for (i = 0; i < 5; i++) {
      /* InitializeConditions for Memory: '<Root>/Memory2' */
      Traditional_MPC_MMC_qudra_DWork.Memory2_PreviousInput[i] =
        Traditional_MPC_MMC_qudratic_P.Memory2_InitialCondition;

      /* InitializeConditions for Memory: '<Root>/Memory1' */
      Traditional_MPC_MMC_qudra_DWork.Memory1_PreviousInput[i] =
        Traditional_MPC_MMC_qudratic_P.Memory1_InitialCondition;
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
