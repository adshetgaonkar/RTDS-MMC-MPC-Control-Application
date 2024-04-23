/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: VDC_control_tennet.c
 *
 * Code generated for Simulink model 'VDC_control_tennet'.
 *
 * Model version                  : 1.35
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Mon Mar  7 12:05:54 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "VDC_control_tennet.h"
#include "VDC_control_tennet_private.h"

/* Block states (default storage) */
D_Work_VDC_control_tennet VDC_control_tennet_DWork;

/* External inputs (root inport signals with default storage) */
ExternalInputs_VDC_control_tenn VDC_control_tennet_U;

/* External outputs (root outports fed by signals with default storage) */
ExternalOutputs_VDC_control_ten VDC_control_tennet_Y;

/* Real-time model */
RT_MODEL_VDC_control_tennet VDC_control_tennet_M_;
RT_MODEL_VDC_control_tennet *const VDC_control_tennet_M = &VDC_control_tennet_M_;

/* Forward declaration for local functions */
static void VDC_control_tennet_xgetrf(real_T A[25], int32_T ipiv[5], int32_T
  *info);
static void VDC_control_tennet_mldivide(const real_T A[25], real_T B[5]);
static void VDC_control_tennet_mldivide_p(const real_T A[25], real_T B[20]);

/* Function for MATLAB Function: '<Root>/MATLAB Function1' */
static void VDC_control_tennet_xgetrf(real_T A[25], int32_T ipiv[5], int32_T
  *info)
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

/* Function for MATLAB Function: '<Root>/MATLAB Function1' */
static void VDC_control_tennet_mldivide(const real_T A[25], real_T B[5])
{
  real_T temp;
  real_T b_A[25];
  int32_T ipiv[5];
  int32_T info;
  int32_T kAcol;
  int32_T i;
  memcpy(&b_A[0], &A[0], 25U * sizeof(real_T));
  VDC_control_tennet_xgetrf(b_A, ipiv, &info);
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

/* Function for MATLAB Function: '<Root>/MATLAB Function1' */
static void VDC_control_tennet_mldivide_p(const real_T A[25], real_T B[20])
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
  VDC_control_tennet_xgetrf(b_A, ipiv, &info);
  for (info = 0; info < 4; info++) {
    if (info + 1 != ipiv[info]) {
      ip = ipiv[info] - 1;
      temp = B[info];
      B[info] = B[ip];
      B[ip] = temp;
      temp = B[info + 5];
      B[info + 5] = B[ip + 5];
      B[ip + 5] = temp;
      temp = B[info + 10];
      B[info + 10] = B[ip + 10];
      B[ip + 10] = temp;
      temp = B[info + 15];
      B[info + 15] = B[ip + 15];
      B[ip + 15] = temp;
    }
  }

  for (info = 0; info < 4; info++) {
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

  for (info = 0; info < 4; info++) {
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

/* Model step function */
void VDC_control_tennet_step(void)
{
  real_T b_gamma[4];
  real_T eta[5];
  real_T y[5];
  real_T kk;
  real_T P[16];
  real_T d[4];
  real_T b[20];
  static const real_T e[20] = { 0.8, -0.48, 0.288, -0.17279999999999998, 0.10368,
    -0.8, 0.48, -0.288, 0.17279999999999998, -0.10368, 0.8, -0.48, 0.288,
    -0.17279999999999998, 0.10368, -0.8, 0.48, -0.288, 0.17279999999999998,
    -0.10368 };

  real_T rtb_Memory2;
  int32_T b_i;
  int32_T i;
  int32_T i_0;
  real_T rtb_Xf_idx_0;
  real_T rtb_Xf_idx_1;
  int32_T P_tmp;
  static const real_T c[25] = { -0.20000831387397722, -6.6151883256164076E-6,
    -4.9850764538311731E-6, -3.4853779842401375E-6, -2.1809379531050157E-6,
    -6.6151883256164076E-6, -0.20000533439670487, -4.0767053986653518E-6,
    -2.8876463050733652E-6, -1.8285517895913953E-6, -4.9850764538311731E-6,
    -4.0767053986653518E-6, -0.20000317163626694, -2.2897172338251689E-6,
    -1.4760480200062908E-6, -3.4853779842401375E-6, -2.8876463050733652E-6,
    -2.2897172338251689E-6, -0.20000169513122029, -1.1233793516198315E-6,
    -2.1809379531050157E-6, -1.8285517895913953E-6, -1.4760480200062908E-6,
    -1.1233793516198315E-6, -0.20000077380415909 };

  static const real_T a[10] = { 0.27990671676804207, 0.22176541677609002,
    0.16642067325378923, 0.11591724876268, 0.07228044640306186,
    0.013501470480765452, 0.010049238001718397, 0.0071079726699562968,
    0.0046777421898389453, 0.00275802652213155 };

  static const real_T H[25] = { 0.20000831387397722, 6.6151883256164076E-6,
    4.9850764538311731E-6, 3.4853779842401375E-6, 2.1809379531050157E-6,
    6.6151883256164076E-6, 0.20000533439670487, 4.0767053986653518E-6,
    2.8876463050733652E-6, 1.8285517895913953E-6, 4.9850764538311731E-6,
    4.0767053986653518E-6, 0.20000317163626694, 2.2897172338251689E-6,
    1.4760480200062908E-6, 3.4853779842401375E-6, 2.8876463050733652E-6,
    2.2897172338251689E-6, 0.20000169513122029, 1.1233793516198315E-6,
    2.1809379531050157E-6, 1.8285517895913953E-6, 1.4760480200062908E-6,
    1.1233793516198315E-6, 0.20000077380415909 };

  static const real_T A_cons[20] = { 0.8, -0.8, 0.8, -0.8, -0.48, 0.48, -0.48,
    0.48, 0.288, -0.288, 0.288, -0.288, -0.17279999999999998,
    0.17279999999999998, -0.17279999999999998, 0.17279999999999998, 0.10368,
    -0.10368, 0.10368, -0.10368 };

  static const real_T b_a[5] = { 0.8, -0.48, 0.288, -0.17279999999999998,
    0.10368 };

  boolean_T exitg1;

  /* Memory: '<Root>/Memory2' */
  rtb_Memory2 = VDC_control_tennet_DWork.Memory2_PreviousInput;

  /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
   *  Inport: '<Root>/Measument '
   *  Inport: '<Root>/U_lim'
   *  Inport: '<Root>/dU_lim'
   *  Inport: '<Root>/setpoint'
   *  Memory: '<Root>/Memory'
   *  Memory: '<Root>/Memory1'
   */
  /* MATLAB Function 'MATLAB Function1': '<S1>:1' */
  /* '<S1>:1:8' */
  /* '<S1>:1:11' */
  /* '<S1>:1:5' */
  /* '<S1>:1:7' */
  b_gamma[0] = VDC_control_tennet_U.U_lim - rtb_Memory2;
  b_gamma[1] = VDC_control_tennet_U.U_lim + rtb_Memory2;
  b_gamma[2] = VDC_control_tennet_U.dU_lim;
  b_gamma[3] = VDC_control_tennet_U.dU_lim;

  /* '<S1>:1:8' */
  kk = VDC_control_tennet_DWork.Memory1_PreviousInput[0];
  rtb_Xf_idx_0 = VDC_control_tennet_DWork.Memory1_PreviousInput[1];
  for (i = 0; i < 5; i++) {
    rtb_Xf_idx_1 = a[i + 5] * rtb_Xf_idx_0 + a[i] * kk;
    eta[i] = rtb_Xf_idx_1;
    y[i] = rtb_Xf_idx_1;
  }

  VDC_control_tennet_mldivide(c, eta);
  kk = 0.0;
  for (i = 0; i < 4; i++) {
    rtb_Xf_idx_0 = 0.0;
    for (b_i = 0; b_i < 5; b_i++) {
      rtb_Xf_idx_0 += A_cons[(b_i << 2) + i] * eta[b_i];
    }

    if (rtb_Xf_idx_0 > b_gamma[i]) {
      kk++;
    }
  }

  if (!(kk == 0.0)) {
    memcpy(&b[0], &e[0], 20U * sizeof(real_T));
    VDC_control_tennet_mldivide_p(H, b);
    for (b_i = 0; b_i < 4; b_i++) {
      for (i = 0; i < 4; i++) {
        P_tmp = i + (b_i << 2);
        P[P_tmp] = 0.0;
        for (i_0 = 0; i_0 < 5; i_0++) {
          P[P_tmp] += A_cons[(i_0 << 2) + i] * b[5 * b_i + i_0];
        }
      }
    }

    for (i = 0; i < 5; i++) {
      eta[i] = y[i];
    }

    VDC_control_tennet_mldivide(H, eta);
    for (i = 0; i < 4; i++) {
      kk = 0.0;
      for (b_i = 0; b_i < 5; b_i++) {
        kk += A_cons[(b_i << 2) + i] * eta[b_i];
      }

      d[i] = kk + b_gamma[i];
      b_gamma[i] = 0.0;
    }

    i = 0;
    exitg1 = false;
    while ((!exitg1) && (i < 38)) {
      kk = 0.0;
      for (b_i = 0; b_i < 4; b_i++) {
        rtb_Xf_idx_0 = b_gamma[b_i];
        P_tmp = (b_i << 2) + b_i;
        rtb_Xf_idx_1 = -(((((P[b_i + 4] * b_gamma[1] + P[b_i] * b_gamma[0]) +
                            P[b_i + 8] * b_gamma[2]) + P[b_i + 12] * b_gamma[3])
                          - P[P_tmp] * b_gamma[b_i]) + d[b_i]) / P[P_tmp];
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

    memcpy(&b[0], &e[0], 20U * sizeof(real_T));
    VDC_control_tennet_mldivide_p(H, b);
    VDC_control_tennet_mldivide(c, y);
    for (b_i = 0; b_i < 5; b_i++) {
      eta[b_i] = y[b_i] - (((b[b_i + 5] * b_gamma[1] + b[b_i] * b_gamma[0]) +
                            b[b_i + 10] * b_gamma[2]) + b[b_i + 15] * b_gamma[3]);
    }
  }

  /* '<S1>:1:11' */
  kk = 0.0;
  for (b_i = 0; b_i < 5; b_i++) {
    kk += b_a[b_i] * eta[b_i];
  }

  /* '<S1>:1:14' */
  /* '<S1>:1:18' */
  /* '<S1>:1:19' */
  rtb_Xf_idx_0 = VDC_control_tennet_U.Measument -
    VDC_control_tennet_DWork.Memory_PreviousInput;
  rtb_Xf_idx_1 = VDC_control_tennet_U.Measument - VDC_control_tennet_U.setpoint;
  rtb_Memory2 += kk;

  /* Outport: '<Root>/IntOut4' */
  VDC_control_tennet_Y.u = rtb_Memory2;

  /* Outport: '<Root>/IntOut1' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function1'
   */
  VDC_control_tennet_Y.delta_u = kk;

  /* Outport: '<Root>/IntOut3' */
  VDC_control_tennet_Y.Xf[0] = rtb_Xf_idx_0;

  /* Update for Memory: '<Root>/Memory1' incorporates:
   *  Outport: '<Root>/IntOut3'
   */
  VDC_control_tennet_DWork.Memory1_PreviousInput[0] = rtb_Xf_idx_0;

  /* Outport: '<Root>/IntOut3' */
  VDC_control_tennet_Y.Xf[1] = rtb_Xf_idx_1;

  /* Update for Memory: '<Root>/Memory1' incorporates:
   *  Outport: '<Root>/IntOut3'
   */
  VDC_control_tennet_DWork.Memory1_PreviousInput[1] = rtb_Xf_idx_1;

  /* Update for Memory: '<Root>/Memory2' */
  VDC_control_tennet_DWork.Memory2_PreviousInput = rtb_Memory2;

  /* Update for Memory: '<Root>/Memory' incorporates:
   *  Inport: '<Root>/Measument '
   */
  VDC_control_tennet_DWork.Memory_PreviousInput = VDC_control_tennet_U.Measument;
}

/* Model initialize function */
void VDC_control_tennet_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(VDC_control_tennet_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&VDC_control_tennet_DWork, 0,
                sizeof(D_Work_VDC_control_tennet));

  /* external inputs */
  (void)memset(&VDC_control_tennet_U, 0, sizeof(ExternalInputs_VDC_control_tenn));

  /* external outputs */
  (void) memset((void *)&VDC_control_tennet_Y, 0,
                sizeof(ExternalOutputs_VDC_control_ten));

  /* InitializeConditions for Memory: '<Root>/Memory1' */
  VDC_control_tennet_DWork.Memory1_PreviousInput[0] =
    VDC_control_tennet_P.Memory1_InitialCondition;
  VDC_control_tennet_DWork.Memory1_PreviousInput[1] =
    VDC_control_tennet_P.Memory1_InitialCondition;

  /* InitializeConditions for Memory: '<Root>/Memory2' */
  VDC_control_tennet_DWork.Memory2_PreviousInput =
    VDC_control_tennet_P.Memory2_InitialCondition;

  /* InitializeConditions for Memory: '<Root>/Memory' */
  VDC_control_tennet_DWork.Memory_PreviousInput =
    VDC_control_tennet_P.Memory_InitialCondition;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
