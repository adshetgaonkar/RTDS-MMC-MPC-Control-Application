/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: VDC_cont_4T_V3.c
 *
 * Code generated for Simulink model 'VDC_cont_4T_V3'.
 *
 * Model version                  : 1.33
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Wed Aug  3 19:21:16 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "VDC_cont_4T_V3.h"
#include "VDC_cont_4T_V3_private.h"

/* Block states (default storage) */
D_Work_VDC_cont_4T_V3 VDC_cont_4T_V3_DWork;

/* External inputs (root inport signals with default storage) */
ExternalInputs_VDC_cont_4T_V3 VDC_cont_4T_V3_U;

/* External outputs (root outports fed by signals with default storage) */
ExternalOutputs_VDC_cont_4T_V3 VDC_cont_4T_V3_Y;

/* Real-time model */
RT_MODEL_VDC_cont_4T_V3 VDC_cont_4T_V3_M_;
RT_MODEL_VDC_cont_4T_V3 *const VDC_cont_4T_V3_M = &VDC_cont_4T_V3_M_;

/* Forward declaration for local functions */
static void VDC_cont_4T_V3_xgetrf(real_T A[16], int32_T ipiv[4], int32_T *info);
static void VDC_cont_4T_V3_mldivide(const real_T A[16], real_T B[4]);
static void VDC_cont_4T_V3_mldivide_p(const real_T A[16], real_T B[16]);

/* Function for MATLAB Function: '<Root>/MATLAB Function1' */
static void VDC_cont_4T_V3_xgetrf(real_T A[16], int32_T ipiv[4], int32_T *info)
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
  ipiv[0] = 1;
  ipiv[1] = 2;
  ipiv[2] = 3;
  ipiv[3] = 4;
  *info = 0;
  for (j = 0; j < 3; j++) {
    c = j * 5;
    iy = 0;
    ix = c;
    smax = fabs(A[c]);
    for (k = 2; k <= 4 - j; k++) {
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
        smax = A[j];
        A[j] = A[iy];
        A[iy] = smax;
        ix = j + 4;
        iy += 4;
        smax = A[ix];
        A[ix] = A[iy];
        A[iy] = smax;
        ix += 4;
        iy += 4;
        smax = A[ix];
        A[ix] = A[iy];
        A[iy] = smax;
        ix += 4;
        iy += 4;
        smax = A[ix];
        A[ix] = A[iy];
        A[iy] = smax;
      }

      iy = (c - j) + 4;
      for (ix = c + 1; ix < iy; ix++) {
        A[ix] /= A[c];
      }
    } else {
      *info = j + 1;
    }

    iy = c;
    ix = c + 4;
    for (k = 0; k <= 2 - j; k++) {
      if (A[ix] != 0.0) {
        smax = -A[ix];
        c_ix = c + 1;
        d = (iy - j) + 8;
        for (ijA = iy + 5; ijA < d; ijA++) {
          A[ijA] += A[c_ix] * smax;
          c_ix++;
        }
      }

      ix += 4;
      iy += 4;
    }
  }

  if ((*info == 0) && (!(A[15] != 0.0))) {
    *info = 4;
  }
}

/* Function for MATLAB Function: '<Root>/MATLAB Function1' */
static void VDC_cont_4T_V3_mldivide(const real_T A[16], real_T B[4])
{
  real_T temp;
  real_T b_A[16];
  int32_T ipiv[4];
  int32_T info;
  memcpy(&b_A[0], &A[0], sizeof(real_T) << 4U);
  VDC_cont_4T_V3_xgetrf(b_A, ipiv, &info);
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

  if (B[0] != 0.0) {
    for (info = 1; info + 1 < 5; info++) {
      B[info] -= B[0] * b_A[info];
    }
  }

  if (B[1] != 0.0) {
    for (info = 2; info + 1 < 5; info++) {
      B[info] -= b_A[info + 4] * B[1];
    }
  }

  if (B[2] != 0.0) {
    for (info = 3; info + 1 < 5; info++) {
      B[info] -= b_A[info + 8] * B[2];
    }
  }

  if (B[3] != 0.0) {
    B[3] /= b_A[15];
    for (info = 0; info < 3; info++) {
      B[info] -= b_A[info + 12] * B[3];
    }
  }

  if (B[2] != 0.0) {
    B[2] /= b_A[10];
    for (info = 0; info < 2; info++) {
      B[info] -= b_A[info + 8] * B[2];
    }
  }

  if (B[1] != 0.0) {
    B[1] /= b_A[5];
    B[0] -= B[1] * b_A[4];
  }

  if (B[0] != 0.0) {
    B[0] /= b_A[0];
  }
}

/* Function for MATLAB Function: '<Root>/MATLAB Function1' */
static void VDC_cont_4T_V3_mldivide_p(const real_T A[16], real_T B[16])
{
  real_T temp;
  int32_T ip;
  real_T b_A[16];
  int32_T ipiv[4];
  int32_T info;
  int32_T i;
  int32_T tmp;
  memcpy(&b_A[0], &A[0], sizeof(real_T) << 4U);
  VDC_cont_4T_V3_xgetrf(b_A, ipiv, &info);
  for (info = 0; info < 3; info++) {
    if (info + 1 != ipiv[info]) {
      ip = ipiv[info] - 1;
      temp = B[info];
      B[info] = B[ip];
      B[ip] = temp;
      temp = B[info + 4];
      B[info + 4] = B[ip + 4];
      B[ip + 4] = temp;
      temp = B[info + 8];
      B[info + 8] = B[ip + 8];
      B[ip + 8] = temp;
      temp = B[info + 12];
      B[info + 12] = B[ip + 12];
      B[ip + 12] = temp;
    }
  }

  for (info = 0; info < 4; info++) {
    ip = info << 2;
    if (B[ip] != 0.0) {
      for (i = 2; i < 5; i++) {
        tmp = (i + ip) - 1;
        B[tmp] -= b_A[i - 1] * B[ip];
      }
    }

    if (B[ip + 1] != 0.0) {
      for (i = 3; i < 5; i++) {
        tmp = (i + ip) - 1;
        B[tmp] -= B[ip + 1] * b_A[i + 3];
      }
    }

    if (B[ip + 2] != 0.0) {
      B[ip + 3] -= B[ip + 2] * b_A[11];
    }
  }

  for (info = 0; info < 4; info++) {
    ip = info << 2;
    if (B[ip + 3] != 0.0) {
      B[ip + 3] /= b_A[15];
      for (i = 0; i < 3; i++) {
        tmp = i + ip;
        B[tmp] -= B[ip + 3] * b_A[i + 12];
      }
    }

    if (B[ip + 2] != 0.0) {
      B[ip + 2] /= b_A[10];
      for (i = 0; i < 2; i++) {
        tmp = i + ip;
        B[tmp] -= B[ip + 2] * b_A[i + 8];
      }
    }

    if (B[ip + 1] != 0.0) {
      B[ip + 1] /= b_A[5];
      B[ip] -= B[ip + 1] * b_A[4];
    }

    if (B[ip] != 0.0) {
      B[ip] /= b_A[0];
    }
  }
}

/* Model step function */
void VDC_cont_4T_V3_step(void)
{
  real_T b_gamma[4];
  real_T eta[4];
  real_T y[4];
  real_T kk;
  real_T P[16];
  real_T d[4];
  real_T b[16];
  static const real_T e[16] = { 0.31224989991991997, -0.296637404923924,
    0.28180553467772779, -0.26771525794384132, -0.31224989991991997,
    0.296637404923924, -0.28180553467772779, 0.26771525794384132,
    0.31224989991991997, -0.296637404923924, 0.28180553467772779,
    -0.26771525794384132, -0.31224989991991997, 0.296637404923924,
    -0.28180553467772779, 0.26771525794384132 };

  real_T rtb_Delay2;
  int32_T b_i;
  int32_T i;
  real_T rtb_Xf_idx_0;
  real_T rtb_Xf_idx_1;
  int32_T P_tmp;
  int32_T P_tmp_tmp;
  static const real_T c[16] = { -0.20012972220389164, 2.9758171162289815E-5,
    5.1101624339098339E-6, -1.1427865120395268E-5, 2.9758171162289815E-5,
    -0.20000860271058235, 2.7488789038753919E-7, 1.9959859078840037E-6,
    5.1101624339098339E-6, 2.7488789038753919E-7, -0.20000142579818997,
    1.0329504133298862E-6, -1.1427865120395268E-5, 1.9959859078840037E-6,
    1.0329504133298862E-6, -0.20000134572771436 };

  static const real_T a[8] = { 1.3659290710147793, -0.34004401100089515,
    -0.030595607520886428, 0.10848129757365015, 0.05308373308103901,
    -0.015645156325539995, 0.001085043413350602, 0.0028521734450397637 };

  static const real_T A_cons[16] = { 0.31224989991991997, -0.31224989991991997,
    0.31224989991991997, -0.31224989991991997, -0.296637404923924,
    0.296637404923924, -0.296637404923924, 0.296637404923924,
    0.28180553467772779, -0.28180553467772779, 0.28180553467772779,
    -0.28180553467772779, -0.26771525794384132, 0.26771525794384132,
    -0.26771525794384132, 0.26771525794384132 };

  static const real_T H[16] = { 0.20012972220389164, -2.9758171162289815E-5,
    -5.1101624339098339E-6, 1.1427865120395268E-5, -2.9758171162289815E-5,
    0.20000860271058235, -2.7488789038753919E-7, -1.9959859078840037E-6,
    -5.1101624339098339E-6, -2.7488789038753919E-7, 0.20000142579818997,
    -1.0329504133298862E-6, 1.1427865120395268E-5, -1.9959859078840037E-6,
    -1.0329504133298862E-6, 0.20000134572771436 };

  boolean_T exitg1;

  /* Delay: '<Root>/Delay2' */
  rtb_Delay2 = VDC_cont_4T_V3_DWork.Delay2_DSTATE;

  /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
   *  Delay: '<Root>/Delay'
   *  Delay: '<Root>/Delay1'
   *  Inport: '<Root>/Mesur'
   *  Inport: '<Root>/Rate_lim'
   *  Inport: '<Root>/Set_point'
   *  Inport: '<Root>/U_lim'
   */
  /* MATLAB Function 'MATLAB Function1': '<S1>:1' */
  /* '<S1>:1:8' */
  /* '<S1>:1:11' */
  /* '<S1>:1:5' */
  /* '<S1>:1:7' */
  b_gamma[0] = VDC_cont_4T_V3_U.U_lim - rtb_Delay2;
  b_gamma[1] = VDC_cont_4T_V3_U.U_lim + rtb_Delay2;
  b_gamma[2] = VDC_cont_4T_V3_U.Rate_lim;
  b_gamma[3] = VDC_cont_4T_V3_U.Rate_lim;

  /* '<S1>:1:8' */
  kk = VDC_cont_4T_V3_DWork.Delay_DSTATE[0];
  rtb_Xf_idx_0 = VDC_cont_4T_V3_DWork.Delay_DSTATE[1];
  for (i = 0; i < 4; i++) {
    rtb_Xf_idx_1 = a[i + 4] * rtb_Xf_idx_0 + a[i] * kk;
    eta[i] = rtb_Xf_idx_1;
    y[i] = rtb_Xf_idx_1;
  }

  VDC_cont_4T_V3_mldivide(c, eta);
  kk = 0.0;
  for (i = 0; i < 4; i++) {
    if (((A_cons[i + 4] * eta[1] + A_cons[i] * eta[0]) + A_cons[i + 8] * eta[2])
        + A_cons[i + 12] * eta[3] > b_gamma[i]) {
      kk++;
    }
  }

  if (!(kk == 0.0)) {
    memcpy(&b[0], &e[0], sizeof(real_T) << 4U);
    VDC_cont_4T_V3_mldivide_p(H, b);
    for (i = 0; i < 4; i++) {
      for (b_i = 0; b_i < 4; b_i++) {
        P_tmp_tmp = b_i << 2;
        P_tmp = i + P_tmp_tmp;
        P[P_tmp] = 0.0;
        P[P_tmp] += b[P_tmp_tmp] * A_cons[i];
        P[P_tmp] += b[P_tmp_tmp + 1] * A_cons[i + 4];
        P[P_tmp] += b[P_tmp_tmp + 2] * A_cons[i + 8];
        P[P_tmp] += b[P_tmp_tmp + 3] * A_cons[i + 12];
      }

      eta[i] = y[i];
    }

    VDC_cont_4T_V3_mldivide(H, eta);
    for (i = 0; i < 4; i++) {
      d[i] = (((A_cons[i + 4] * eta[1] + A_cons[i] * eta[0]) + A_cons[i + 8] *
               eta[2]) + A_cons[i + 12] * eta[3]) + b_gamma[i];
      b_gamma[i] = 0.0;
    }

    i = 0;
    exitg1 = false;
    while ((!exitg1) && (i < 38)) {
      kk = 0.0;
      for (b_i = 0; b_i < 4; b_i++) {
        rtb_Xf_idx_0 = b_gamma[b_i];
        P_tmp_tmp = (b_i << 2) + b_i;
        rtb_Xf_idx_1 = -(((((P[b_i + 4] * b_gamma[1] + P[b_i] * b_gamma[0]) +
                            P[b_i + 8] * b_gamma[2]) + P[b_i + 12] * b_gamma[3])
                          - P[P_tmp_tmp] * b_gamma[b_i]) + d[b_i]) / P[P_tmp_tmp];
        if ((0.0 > rtb_Xf_idx_1) || rtIsNaN(rtb_Xf_idx_1)) {
          b_gamma[b_i] = 0.0;
        } else {
          b_gamma[b_i] = rtb_Xf_idx_1;
        }

        rtb_Xf_idx_0 = b_gamma[b_i] - rtb_Xf_idx_0;
        kk += rtb_Xf_idx_0 * rtb_Xf_idx_0;
      }

      if (kk < 1.0E-7) {
        exitg1 = true;
      } else {
        i++;
      }
    }

    memcpy(&b[0], &e[0], sizeof(real_T) << 4U);
    VDC_cont_4T_V3_mldivide_p(H, b);
    VDC_cont_4T_V3_mldivide(c, y);
    for (b_i = 0; b_i < 4; b_i++) {
      eta[b_i] = y[b_i] - (((b[b_i + 4] * b_gamma[1] + b[b_i] * b_gamma[0]) +
                            b[b_i + 8] * b_gamma[2]) + b[b_i + 12] * b_gamma[3]);
    }
  }

  /* '<S1>:1:11' */
  kk = ((0.31224989991991997 * eta[0] + -0.296637404923924 * eta[1]) +
        0.28180553467772779 * eta[2]) + -0.26771525794384132 * eta[3];

  /* '<S1>:1:14' */
  /* '<S1>:1:18' */
  /* '<S1>:1:19' */
  rtb_Xf_idx_0 = VDC_cont_4T_V3_U.Mesur - VDC_cont_4T_V3_DWork.Delay1_DSTATE;
  rtb_Xf_idx_1 = VDC_cont_4T_V3_U.Mesur - VDC_cont_4T_V3_U.Set_point;
  rtb_Delay2 += kk;

  /* Outport: '<Root>/IntOut4' */
  VDC_cont_4T_V3_Y.u = rtb_Delay2;

  /* Outport: '<Root>/IntOut1' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function1'
   */
  VDC_cont_4T_V3_Y.delta_u = kk;

  /* Outport: '<Root>/IntOut3' */
  VDC_cont_4T_V3_Y.Xf[0] = rtb_Xf_idx_0;

  /* Update for Delay: '<Root>/Delay' incorporates:
   *  Outport: '<Root>/IntOut3'
   */
  VDC_cont_4T_V3_DWork.Delay_DSTATE[0] = rtb_Xf_idx_0;

  /* Outport: '<Root>/IntOut3' */
  VDC_cont_4T_V3_Y.Xf[1] = rtb_Xf_idx_1;

  /* Update for Delay: '<Root>/Delay' incorporates:
   *  Outport: '<Root>/IntOut3'
   */
  VDC_cont_4T_V3_DWork.Delay_DSTATE[1] = rtb_Xf_idx_1;

  /* Update for Delay: '<Root>/Delay2' */
  VDC_cont_4T_V3_DWork.Delay2_DSTATE = rtb_Delay2;

  /* Update for Delay: '<Root>/Delay1' incorporates:
   *  Inport: '<Root>/Mesur'
   */
  VDC_cont_4T_V3_DWork.Delay1_DSTATE = VDC_cont_4T_V3_U.Mesur;
}

/* Model initialize function */
void VDC_cont_4T_V3_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(VDC_cont_4T_V3_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&VDC_cont_4T_V3_DWork, 0,
                sizeof(D_Work_VDC_cont_4T_V3));

  /* external inputs */
  (void)memset(&VDC_cont_4T_V3_U, 0, sizeof(ExternalInputs_VDC_cont_4T_V3));

  /* external outputs */
  (void) memset((void *)&VDC_cont_4T_V3_Y, 0,
                sizeof(ExternalOutputs_VDC_cont_4T_V3));

  /* InitializeConditions for Delay: '<Root>/Delay' */
  VDC_cont_4T_V3_DWork.Delay_DSTATE[0] = VDC_cont_4T_V3_P.Delay_InitialCondition;
  VDC_cont_4T_V3_DWork.Delay_DSTATE[1] = VDC_cont_4T_V3_P.Delay_InitialCondition;

  /* InitializeConditions for Delay: '<Root>/Delay2' */
  VDC_cont_4T_V3_DWork.Delay2_DSTATE = VDC_cont_4T_V3_P.Delay2_InitialCondition;

  /* InitializeConditions for Delay: '<Root>/Delay1' */
  VDC_cont_4T_V3_DWork.Delay1_DSTATE = VDC_cont_4T_V3_P.Delay1_InitialCondition;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
