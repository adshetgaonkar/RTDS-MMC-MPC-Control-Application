/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: MPC_grid_forming_v1v1.c
 *
 * Code generated for Simulink model 'MPC_grid_forming_v1v1'.
 *
 * Model version                  : 1.31
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Tue Oct 26 07:50:22 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "MPC_grid_forming_v1v1.h"
#include "MPC_grid_forming_v1v1_private.h"

/* Block states (default storage) */
D_Work_MPC_grid_forming_v1v1 MPC_grid_forming_v1v1_DWork;

/* External inputs (root inport signals with default storage) */
ExternalInputs_MPC_grid_forming MPC_grid_forming_v1v1_U;

/* External outputs (root outports fed by signals with default storage) */
ExternalOutputs_MPC_grid_formin MPC_grid_forming_v1v1_Y;

/* Real-time model */
RT_MODEL_MPC_grid_forming_v1v1 MPC_grid_forming_v1v1_M_;
RT_MODEL_MPC_grid_forming_v1v1 *const MPC_grid_forming_v1v1_M =
  &MPC_grid_forming_v1v1_M_;

/* Forward declaration for local functions */
static void MPC_grid_forming_v1v1_xgetrf(real_T A[16], int32_T ipiv[4], int32_T *
  info);
static void MPC_grid_forming_v1v1_mldivide(const real_T A[16], real_T B[4]);
static void MPC_grid_forming_v1v_mldivide_p(const real_T A[16], real_T B[16]);

/* Function for MATLAB Function: '<Root>/MATLAB Function1' */
static void MPC_grid_forming_v1v1_xgetrf(real_T A[16], int32_T ipiv[4], int32_T *
  info)
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
static void MPC_grid_forming_v1v1_mldivide(const real_T A[16], real_T B[4])
{
  real_T temp;
  real_T b_A[16];
  int32_T ipiv[4];
  int32_T info;
  memcpy(&b_A[0], &A[0], sizeof(real_T) << 4U);
  MPC_grid_forming_v1v1_xgetrf(b_A, ipiv, &info);
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
static void MPC_grid_forming_v1v_mldivide_p(const real_T A[16], real_T B[16])
{
  real_T temp;
  int32_T ip;
  real_T b_A[16];
  int32_T ipiv[4];
  int32_T info;
  int32_T i;
  int32_T tmp;
  memcpy(&b_A[0], &A[0], sizeof(real_T) << 4U);
  MPC_grid_forming_v1v1_xgetrf(b_A, ipiv, &info);
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
void MPC_grid_forming_v1v1_step(void)
{
  real_T b_gamma[4];
  real_T eta[4];
  real_T y[4];
  real_T kk;
  real_T P[16];
  real_T d[4];
  real_T b[16];
  static const real_T e[16] = { 0.00774590859744585, -0.0077456762201879269,
    0.0077454438499013206, -0.0077452114865858247, -0.00774590859744585,
    0.0077456762201879269, -0.0077454438499013206, 0.0077452114865858247,
    0.00774590859744585, -0.0077456762201879269, 0.0077454438499013206,
    -0.0077452114865858247, -0.00774590859744585, 0.0077456762201879269,
    -0.0077454438499013206, 0.0077452114865858247 };

  int32_T b_i;
  int32_T i;
  real_T rtb_Xf_idx_0;
  real_T rtb_Xf_idx_1;
  int32_T P_tmp;
  int32_T P_tmp_tmp;
  static const real_T c[16] = { -0.002000185860327016, 1.8582634387492393E-7,
    -1.8579236556403315E-7, 1.8575839208293112E-7, 1.8582634387492393E-7,
    -0.0020001857923671188, 1.8575839519194639E-7, -1.857244280940364E-7,
    -1.8579236556403315E-7, 1.8575839519194639E-7, -0.0020001857244296485,
    1.85690468932722E-7, 1.8575839208293112E-7, -1.857244280940364E-7,
    1.85690468932722E-7, -0.0020001856565145986 };

  static const real_T a[8] = { 0.0082398634660753, -0.0082384104982132413,
    0.00823695773184475, -0.0082355051669465787, 0.0010643471674100958,
    -0.001064171535856069, 0.0010639959276783147, -0.0010638203428742095 };

  static const real_T A_cons[16] = { 0.00774590859744585, -0.00774590859744585,
    0.00774590859744585, -0.00774590859744585, -0.0077456762201879269,
    0.0077456762201879269, -0.0077456762201879269, 0.0077456762201879269,
    0.0077454438499013206, -0.0077454438499013206, 0.0077454438499013206,
    -0.0077454438499013206, -0.0077452114865858247, 0.0077452114865858247,
    -0.0077452114865858247, 0.0077452114865858247 };

  static const real_T H[16] = { 0.002000185860327016, -1.8582634387492393E-7,
    1.8579236556403315E-7, -1.8575839208293112E-7, -1.8582634387492393E-7,
    0.0020001857923671188, -1.8575839519194639E-7, 1.857244280940364E-7,
    1.8579236556403315E-7, -1.8575839519194639E-7, 0.0020001857244296485,
    -1.85690468932722E-7, -1.8575839208293112E-7, 1.857244280940364E-7,
    -1.85690468932722E-7, 0.0020001856565145986 };

  boolean_T exitg1;

  /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
   *  Delay: '<Root>/Delay'
   *  Delay: '<Root>/Delay1'
   *  Inport: '<Root>/Inport'
   *  Inport: '<Root>/Inport1'
   *  Inport: '<Root>/Inport2'
   */
  /* MATLAB Function 'MATLAB Function1': '<S1>:1' */
  /* '<S1>:1:8' */
  /* '<S1>:1:12' */
  /* '<S1>:1:4' */
  /* '<S1>:1:7' */
  b_gamma[0] = 1.1 - MPC_grid_forming_v1v1_U.Inport2;
  b_gamma[1] = MPC_grid_forming_v1v1_U.Inport2 + 1.1;
  b_gamma[2] = 0.02;
  b_gamma[3] = 0.02;

  /* '<S1>:1:8' */
  kk = MPC_grid_forming_v1v1_DWork.Delay_DSTATE[0];
  rtb_Xf_idx_0 = MPC_grid_forming_v1v1_DWork.Delay_DSTATE[1];
  for (i = 0; i < 4; i++) {
    rtb_Xf_idx_1 = a[i + 4] * rtb_Xf_idx_0 + a[i] * kk;
    eta[i] = rtb_Xf_idx_1;
    y[i] = rtb_Xf_idx_1;
  }

  MPC_grid_forming_v1v1_mldivide(c, eta);
  kk = 0.0;
  for (i = 0; i < 4; i++) {
    if (((A_cons[i + 4] * eta[1] + A_cons[i] * eta[0]) + A_cons[i + 8] * eta[2])
        + A_cons[i + 12] * eta[3] > b_gamma[i]) {
      kk++;
    }
  }

  if (!(kk == 0.0)) {
    memcpy(&b[0], &e[0], sizeof(real_T) << 4U);
    MPC_grid_forming_v1v_mldivide_p(H, b);
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

    MPC_grid_forming_v1v1_mldivide(H, eta);
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
    MPC_grid_forming_v1v_mldivide_p(H, b);
    MPC_grid_forming_v1v1_mldivide(c, y);
    for (b_i = 0; b_i < 4; b_i++) {
      eta[b_i] = y[b_i] - (((b[b_i + 4] * b_gamma[1] + b[b_i] * b_gamma[0]) +
                            b[b_i + 8] * b_gamma[2]) + b[b_i + 12] * b_gamma[3]);
    }
  }

  /* '<S1>:1:12' */
  kk = ((0.00774590859744585 * eta[0] + -0.0077456762201879269 * eta[1]) +
        0.0077454438499013206 * eta[2]) + -0.0077452114865858247 * eta[3];

  /* '<S1>:1:15' */
  /* '<S1>:1:19' */
  /* '<S1>:1:20' */
  rtb_Xf_idx_0 = MPC_grid_forming_v1v1_U.Inport1 -
    MPC_grid_forming_v1v1_DWork.Delay1_DSTATE;
  rtb_Xf_idx_1 = MPC_grid_forming_v1v1_U.Inport1 -
    MPC_grid_forming_v1v1_U.Inport;

  /* Outport: '<Root>/IntOut4' incorporates:
   *  Inport: '<Root>/Inport2'
   *  MATLAB Function: '<Root>/MATLAB Function1'
   */
  MPC_grid_forming_v1v1_Y.u = MPC_grid_forming_v1v1_U.Inport2 + kk;

  /* Outport: '<Root>/IntOut1' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function1'
   */
  MPC_grid_forming_v1v1_Y.delta_u = kk;

  /* Outport: '<Root>/IntOut3' */
  MPC_grid_forming_v1v1_Y.Xf[0] = rtb_Xf_idx_0;

  /* Update for Delay: '<Root>/Delay' incorporates:
   *  Outport: '<Root>/IntOut3'
   */
  MPC_grid_forming_v1v1_DWork.Delay_DSTATE[0] = rtb_Xf_idx_0;

  /* Outport: '<Root>/IntOut3' */
  MPC_grid_forming_v1v1_Y.Xf[1] = rtb_Xf_idx_1;

  /* Update for Delay: '<Root>/Delay' incorporates:
   *  Outport: '<Root>/IntOut3'
   */
  MPC_grid_forming_v1v1_DWork.Delay_DSTATE[1] = rtb_Xf_idx_1;

  /* Update for Delay: '<Root>/Delay1' incorporates:
   *  Inport: '<Root>/Inport1'
   */
  MPC_grid_forming_v1v1_DWork.Delay1_DSTATE = MPC_grid_forming_v1v1_U.Inport1;
}

/* Model initialize function */
void MPC_grid_forming_v1v1_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(MPC_grid_forming_v1v1_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&MPC_grid_forming_v1v1_DWork, 0,
                sizeof(D_Work_MPC_grid_forming_v1v1));

  /* external inputs */
  (void)memset(&MPC_grid_forming_v1v1_U, 0, sizeof
               (ExternalInputs_MPC_grid_forming));

  /* external outputs */
  (void) memset((void *)&MPC_grid_forming_v1v1_Y, 0,
                sizeof(ExternalOutputs_MPC_grid_formin));

  /* InitializeConditions for Delay: '<Root>/Delay' */
  MPC_grid_forming_v1v1_DWork.Delay_DSTATE[0] =
    MPC_grid_forming_v1v1_P.Delay_InitialCondition;
  MPC_grid_forming_v1v1_DWork.Delay_DSTATE[1] =
    MPC_grid_forming_v1v1_P.Delay_InitialCondition;

  /* InitializeConditions for Delay: '<Root>/Delay1' */
  MPC_grid_forming_v1v1_DWork.Delay1_DSTATE =
    MPC_grid_forming_v1v1_P.Delay1_InitialCondition;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
