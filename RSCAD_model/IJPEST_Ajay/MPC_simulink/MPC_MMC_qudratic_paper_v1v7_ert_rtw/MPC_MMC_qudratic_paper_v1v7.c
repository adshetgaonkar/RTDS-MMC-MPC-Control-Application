/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: MPC_MMC_qudratic_paper_v1v7.c
 *
 * Code generated for Simulink model 'MPC_MMC_qudratic_paper_v1v7'.
 *
 * Model version                  : 1.32
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Fri Jun 24 11:37:29 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "MPC_MMC_qudratic_paper_v1v7.h"
#include "MPC_MMC_qudratic_paper_v1v7_private.h"

/* Block states (default storage) */
D_Work_MPC_MMC_qudratic_paper_v MPC_MMC_qudratic_paper_v1_DWork;

/* External inputs (root inport signals with default storage) */
ExternalInputs_MPC_MMC_qudratic MPC_MMC_qudratic_paper_v1v7_U;

/* External outputs (root outports fed by signals with default storage) */
ExternalOutputs_MPC_MMC_qudrati MPC_MMC_qudratic_paper_v1v7_Y;

/* Real-time model */
RT_MODEL_MPC_MMC_qudratic_paper MPC_MMC_qudratic_paper_v1v7_M_;
RT_MODEL_MPC_MMC_qudratic_paper *const MPC_MMC_qudratic_paper_v1v7_M =
  &MPC_MMC_qudratic_paper_v1v7_M_;

/* Forward declaration for local functions */
static void MPC_MMC_qudratic_paper_v_xgetrf(real_T A[400], int32_T ipiv[20],
  int32_T *info);
static void MPC_MMC_qudratic_paper_mldivide(const real_T A[400], real_T B[20]);
static void MPC_MMC_qudratic_pap_mldivide_g(const real_T A[400], real_T B[400]);
static void MPC_MMC_qudratic_paper_v_QPhild(const real_T H[400], const real_T f
  [20], const real_T A_cons[400], const real_T b[20], real_T eta[20]);

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static void MPC_MMC_qudratic_paper_v_xgetrf(real_T A[400], int32_T ipiv[20],
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
  for (j = 0; j < 20; j++) {
    ipiv[j] = j + 1;
  }

  *info = 0;
  for (j = 0; j < 19; j++) {
    c = j * 21;
    iy = 0;
    ix = c;
    smax = fabs(A[c]);
    for (k = 2; k <= 20 - j; k++) {
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
        for (k = 0; k < 20; k++) {
          smax = A[ix];
          A[ix] = A[iy];
          A[iy] = smax;
          ix += 20;
          iy += 20;
        }
      }

      iy = (c - j) + 20;
      for (ix = c + 1; ix < iy; ix++) {
        A[ix] /= A[c];
      }
    } else {
      *info = j + 1;
    }

    iy = c;
    ix = c + 20;
    for (k = 0; k <= 18 - j; k++) {
      if (A[ix] != 0.0) {
        smax = -A[ix];
        c_ix = c + 1;
        d = (iy - j) + 40;
        for (ijA = iy + 21; ijA < d; ijA++) {
          A[ijA] += A[c_ix] * smax;
          c_ix++;
        }
      }

      ix += 20;
      iy += 20;
    }
  }

  if ((*info == 0) && (!(A[399] != 0.0))) {
    *info = 20;
  }
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static void MPC_MMC_qudratic_paper_mldivide(const real_T A[400], real_T B[20])
{
  real_T temp;
  real_T b_A[400];
  int32_T ipiv[20];
  int32_T info;
  int32_T kAcol;
  int32_T i;
  memcpy(&b_A[0], &A[0], 400U * sizeof(real_T));
  MPC_MMC_qudratic_paper_v_xgetrf(b_A, ipiv, &info);
  for (info = 0; info < 19; info++) {
    if (info + 1 != ipiv[info]) {
      temp = B[info];
      B[info] = B[ipiv[info] - 1];
      B[ipiv[info] - 1] = temp;
    }
  }

  for (info = 0; info < 20; info++) {
    kAcol = 20 * info;
    if (B[info] != 0.0) {
      for (i = info + 1; i + 1 < 21; i++) {
        B[i] -= b_A[i + kAcol] * B[info];
      }
    }
  }

  for (info = 19; info >= 0; info--) {
    kAcol = 20 * info;
    if (B[info] != 0.0) {
      B[info] /= b_A[info + kAcol];
      for (i = 0; i < info; i++) {
        B[i] -= b_A[i + kAcol] * B[info];
      }
    }
  }
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static void MPC_MMC_qudratic_pap_mldivide_g(const real_T A[400], real_T B[400])
{
  real_T temp;
  int32_T ip;
  real_T b_A[400];
  int32_T ipiv[20];
  int32_T info;
  int32_T xj;
  int32_T kAcol;
  int32_T i;
  int32_T tmp;
  int32_T tmp_0;
  memcpy(&b_A[0], &A[0], 400U * sizeof(real_T));
  MPC_MMC_qudratic_paper_v_xgetrf(b_A, ipiv, &info);
  for (info = 0; info < 19; info++) {
    if (info + 1 != ipiv[info]) {
      ip = ipiv[info] - 1;
      for (xj = 0; xj < 20; xj++) {
        kAcol = 20 * xj + info;
        temp = B[kAcol];
        tmp = 20 * xj + ip;
        B[kAcol] = B[tmp];
        B[tmp] = temp;
      }
    }
  }

  for (info = 0; info < 20; info++) {
    ip = 20 * info;
    for (xj = 0; xj < 20; xj++) {
      kAcol = 20 * xj;
      tmp = xj + ip;
      if (B[tmp] != 0.0) {
        for (i = xj + 2; i < 21; i++) {
          tmp_0 = (i + ip) - 1;
          B[tmp_0] -= b_A[(i + kAcol) - 1] * B[tmp];
        }
      }
    }
  }

  for (info = 0; info < 20; info++) {
    ip = 20 * info;
    for (xj = 19; xj >= 0; xj--) {
      kAcol = 20 * xj;
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
static void MPC_MMC_qudratic_paper_v_QPhild(const real_T H[400], const real_T f
  [20], const real_T A_cons[400], const real_T b[20], real_T eta[20])
{
  real_T kk;
  real_T P[400];
  real_T d[20];
  real_T lambda[20];
  real_T lambda_p[20];
  int32_T i;
  real_T b_b[400];
  int32_T b_i;
  real_T H_0[400];
  real_T A_cons_0;
  real_T P_0;
  int32_T P_tmp;
  int32_T u1_tmp;
  boolean_T exitg1;
  memcpy(&eta[0], &f[0], 20U * sizeof(real_T));
  for (u1_tmp = 0; u1_tmp < 400; u1_tmp++) {
    H_0[u1_tmp] = -H[u1_tmp];
  }

  MPC_MMC_qudratic_paper_mldivide(H_0, eta);
  kk = 0.0;
  for (i = 0; i < 20; i++) {
    A_cons_0 = 0.0;
    for (u1_tmp = 0; u1_tmp < 20; u1_tmp++) {
      A_cons_0 += A_cons[20 * u1_tmp + i] * eta[u1_tmp];
    }

    if (A_cons_0 > b[i]) {
      kk++;
    }
  }

  if (!(kk == 0.0)) {
    for (u1_tmp = 0; u1_tmp < 20; u1_tmp++) {
      for (b_i = 0; b_i < 20; b_i++) {
        H_0[b_i + 20 * u1_tmp] = A_cons[20 * b_i + u1_tmp];
      }
    }

    memcpy(&b_b[0], &H_0[0], 400U * sizeof(real_T));
    MPC_MMC_qudratic_pap_mldivide_g(H, b_b);
    for (i = 0; i < 20; i++) {
      for (u1_tmp = 0; u1_tmp < 20; u1_tmp++) {
        P_tmp = i + 20 * u1_tmp;
        P[P_tmp] = 0.0;
        for (b_i = 0; b_i < 20; b_i++) {
          P[P_tmp] += A_cons[20 * b_i + i] * b_b[20 * u1_tmp + b_i];
        }
      }

      lambda_p[i] = f[i];
    }

    MPC_MMC_qudratic_paper_mldivide(H, lambda_p);
    for (i = 0; i < 20; i++) {
      kk = 0.0;
      for (u1_tmp = 0; u1_tmp < 20; u1_tmp++) {
        kk += A_cons[20 * u1_tmp + i] * lambda_p[u1_tmp];
      }

      d[i] = kk + b[i];
      lambda[i] = 0.0;
    }

    i = 0;
    exitg1 = false;
    while ((!exitg1) && (i < 38)) {
      kk = 0.0;
      for (b_i = 0; b_i < 20; b_i++) {
        A_cons_0 = lambda[b_i];
        P_0 = 0.0;
        for (u1_tmp = 0; u1_tmp < 20; u1_tmp++) {
          P_0 += P[20 * u1_tmp + b_i] * lambda[u1_tmp];
        }

        u1_tmp = 20 * b_i + b_i;
        P_0 = -((P_0 - P[u1_tmp] * lambda[b_i]) + d[b_i]) / P[u1_tmp];
        if ((0.0 > P_0) || rtIsNaN(P_0)) {
          lambda[b_i] = 0.0;
        } else {
          lambda[b_i] = P_0;
        }

        A_cons_0 = lambda[b_i] - A_cons_0;
        kk += A_cons_0 * A_cons_0;
      }

      if (kk < 1.0E-7) {
        exitg1 = true;
      } else {
        i++;
      }
    }

    memcpy(&b_b[0], &H_0[0], 400U * sizeof(real_T));
    MPC_MMC_qudratic_pap_mldivide_g(H, b_b);
    memcpy(&lambda_p[0], &f[0], 20U * sizeof(real_T));
    for (u1_tmp = 0; u1_tmp < 400; u1_tmp++) {
      H_0[u1_tmp] = -H[u1_tmp];
    }

    MPC_MMC_qudratic_paper_mldivide(H_0, lambda_p);
    for (u1_tmp = 0; u1_tmp < 20; u1_tmp++) {
      kk = 0.0;
      for (b_i = 0; b_i < 20; b_i++) {
        kk += b_b[20 * b_i + u1_tmp] * lambda[b_i];
      }

      eta[u1_tmp] = lambda_p[u1_tmp] - kk;
    }
  }
}

/* Model step function */
void MPC_MMC_qudratic_paper_v1v7_step(void)
{
  real_T eta[20];
  real_T rtb_Xf[10];
  real_T rtb_deltau[5];
  real_T rtb_Delay2[5];
  int32_T i;
  real_T b_a[20];
  real_T tmp[20];
  int32_T i_0;
  static const real_T b_a_0[200] = { -0.22547211838937034, -0.14121965258946534,
    -0.07029550043666663, -0.020689785982641606, 3.0298227549118312E-5,
    5.8187221206890672E-5, 5.01349033829784E-5, 2.4223674702204298E-5, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -3.0298227549118227E-5,
    -5.8187221206890604E-5, -5.0134903382978373E-5, -2.4223674702204308E-5,
    -0.22547211838937048, -0.14121965258946539, -0.070295500436666644,
    -0.020689785982641602, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.22547217572047895,
    -0.14121969092144826, -0.0702955280504913, -0.020689800932858486, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.41191923565449268, 0.25799689830903522, 0.1284242426319189,
    0.037798600528619934, 2.7676186976570054E-5, 5.3151636853359056E-5,
    4.5796185865082839E-5, 2.2127344156813792E-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -2.7676186976570237E-5, -5.3151636853359131E-5,
    -4.579618586508288E-5, -2.2127344156813792E-5, 0.41191923565449245,
    0.25799689830903505, 0.12842424263191882, 0.03779860052861992,
    -0.010694355841797509, -0.0060145645680077979, -0.0026902678864824804,
    -0.000677397377215728, -8.0564622991428762E-6, -3.3779646235599068E-6,
    -9.406115505800108E-7, 2.334720503358968E-9, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 8.0564622991428746E-6, 3.3779646235599072E-6,
    9.4061155058001048E-7, -2.334720503359246E-9, -0.010694355841797513,
    -0.0060145645680077979, -0.0026902678864824813, -0.00067739737721572788, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, -0.010694360016272081, -0.0060145657251854728,
    -0.002690267965406844, -0.000677397272711929, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.019537750557552927, 0.010988139818870236, 0.00491491025975853,
    0.0012375527997055729, -7.3592577592370106E-6, -3.0856373720027132E-6,
    -8.5921197614507112E-7, 2.1324977968086896E-9, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 7.3592577592370089E-6, 3.0856373720027124E-6,
    8.5921197614506974E-7, -2.1324977968090668E-9, 0.019537750557552927,
    0.010988139818870236, 0.0049149102597585322, 0.0012375527997055737 };

  static const real_T b[400] = { 0.20000540180479043, 3.430422508163483E-6,
    1.7329376911227334E-6, 5.19601525199873E-7, 2.6789220933330766E-25,
    -9.4225561655593027E-10, -9.896389216361753E-10, -5.2895221367836428E-10,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    3.430422508163483E-6, 0.20000227316646832, 1.2079902217576319E-6,
    3.8724936882171303E-7, 9.4225561655593027E-10, -3.8298829891939292E-25,
    -3.4991123721471468E-10, -2.7472202623824562E-10, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.7329376911227334E-6,
    1.2079902217576319E-6, 0.20000069445870156, 2.5207864281639848E-7,
    9.89638921636176E-10, 3.4991123721471447E-10, 4.2113494467061052E-26,
    -9.6847957007169856E-11, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 5.19601525199873E-7, 3.8724936882171303E-7, 2.5207864281639848E-7,
    0.20000011565176209, 5.289522136783648E-10, 2.7472202623824573E-10,
    9.684795700717E-11, 2.4615606934045187E-26, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 2.6789220933330766E-25, 9.4225561655593027E-10,
    9.89638921636176E-10, 5.289522136783648E-10, 0.20000540180479043,
    3.4304225081634843E-6, 1.7329376911227342E-6, 5.1960152519987309E-7, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    -9.4225561655593027E-10, -3.8298829891939292E-25, 3.4991123721471447E-10,
    2.7472202623824573E-10, 3.4304225081634843E-6, 0.20000227316646832,
    1.2079902217576321E-6, 3.8724936882171292E-7, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -9.896389216361753E-10,
    -3.4991123721471468E-10, 4.2113494467061052E-26, 9.684795700717E-11,
    1.7329376911227342E-6, 1.2079902217576321E-6, 0.20000069445870156,
    2.5207864281639843E-7, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, -5.2895221367836428E-10, -2.7472202623824562E-10,
    -9.6847957007169856E-11, 2.4615606934045187E-26, 5.1960152519987309E-7,
    3.8724936882171292E-7, 2.5207864281639843E-7, 0.20000011565176209, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.2000054018058261, 3.4304230800482132E-6,
    1.7329381082057288E-6, 5.196017817193968E-7, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 3.4304230800482132E-6,
    0.20000227316659655, 1.2079902688933508E-6, 3.8724942586726995E-7, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.7329381082057288E-6, 1.2079902688933508E-6, 0.20000069445865432,
    2.5207862111481361E-7, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 5.196017817193968E-7, 3.8724942586726995E-7,
    2.5207862111481361E-7, 0.20000011565173639, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.20001802928220469, 1.1449519927229005E-5, 5.7839262058216761E-6,
    1.7342449100163824E-6, -3.1623060092336368E-24, 1.5724543027311637E-9,
    1.6515289748850176E-9, 8.8272620199961E-10, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.1449519927229005E-5, 0.200007587016198,
    4.0318401883770649E-6, 1.2925007041783891E-6, -1.5724543027311666E-9,
    -6.5464913059190534E-25, 5.83938990320685E-10, 4.5846185369759573E-10, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 5.7839262058216761E-6,
    4.0318401883770649E-6, 0.20000231785587877, 8.4134905358666821E-7,
    -1.6515289748850195E-9, -5.8393899032068624E-10, -5.7347982059571686E-25,
    1.6162194475109684E-10, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.7342449100163824E-6, 1.2925007041783891E-6,
    8.4134905358666821E-7, 0.20000038600464576, -8.8272620199961022E-10,
    -4.5846185369759594E-10, -1.6162194475109718E-10, -8.0076673167039692E-26,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    -3.1623060092336368E-24, -1.5724543027311666E-9, -1.6515289748850195E-9,
    -8.8272620199961022E-10, 0.20001802928220469, 1.1449519927229003E-5,
    5.7839262058216769E-6, 1.734244910016383E-6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.5724543027311637E-9, -6.5464913059190534E-25,
    -5.8393899032068624E-10, -4.5846185369759594E-10, 1.1449519927229003E-5,
    0.200007587016198, 4.0318401883770649E-6, 1.2925007041783897E-6, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.6515289748850176E-9,
    5.83938990320685E-10, -5.7347982059571686E-25, -1.6162194475109718E-10,
    5.7839262058216769E-6, 4.0318401883770649E-6, 0.20000231785587877,
    8.4134905358666842E-7, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 8.8272620199961E-10, 4.5846185369759573E-10, 1.6162194475109684E-10,
    -8.0076673167039692E-26, 1.734244910016383E-6, 1.2925007041783897E-6,
    8.4134905358666842E-7, 0.20000038600464576 };

  static const real_T c[400] = { 0.66143782776614768, 0.0, 0.0, 0.0, 0.0,
    -0.66143782776614768, -0.0, -0.0, -0.0, -0.0, 0.66143782776614768, 0.0, 0.0,
    0.0, 0.0, -0.66143782776614768, -0.0, -0.0, -0.0, -0.0, -0.49607837082461076,
    0.0, 0.0, 0.0, 0.0, 0.49607837082461076, -0.0, -0.0, -0.0, -0.0,
    -0.49607837082461076, 0.0, 0.0, 0.0, 0.0, 0.49607837082461076, -0.0, -0.0,
    -0.0, -0.0, 0.37205877811845806, 0.0, 0.0, 0.0, 0.0, -0.37205877811845806,
    -0.0, -0.0, -0.0, -0.0, 0.37205877811845806, 0.0, 0.0, 0.0, 0.0,
    -0.37205877811845806, -0.0, -0.0, -0.0, -0.0, -0.27904408358884353, 0.0, 0.0,
    0.0, 0.0, 0.27904408358884353, -0.0, -0.0, -0.0, -0.0, -0.27904408358884353,
    0.0, 0.0, 0.0, 0.0, 0.27904408358884353, -0.0, -0.0, -0.0, -0.0, 0.0,
    0.66143782776614768, 0.0, 0.0, 0.0, -0.0, -0.66143782776614768, -0.0, -0.0,
    -0.0, 0.0, 0.66143782776614768, 0.0, 0.0, 0.0, -0.0, -0.66143782776614768,
    -0.0, -0.0, -0.0, 0.0, -0.49607837082461076, 0.0, 0.0, 0.0, -0.0,
    0.49607837082461076, -0.0, -0.0, -0.0, 0.0, -0.49607837082461076, 0.0, 0.0,
    0.0, -0.0, 0.49607837082461076, -0.0, -0.0, -0.0, 0.0, 0.37205877811845806,
    0.0, 0.0, 0.0, -0.0, -0.37205877811845806, -0.0, -0.0, -0.0, 0.0,
    0.37205877811845806, 0.0, 0.0, 0.0, -0.0, -0.37205877811845806, -0.0, -0.0,
    -0.0, 0.0, -0.27904408358884353, 0.0, 0.0, 0.0, -0.0, 0.27904408358884353,
    -0.0, -0.0, -0.0, 0.0, -0.27904408358884353, 0.0, 0.0, 0.0, -0.0,
    0.27904408358884353, -0.0, -0.0, -0.0, 0.0, 0.0, 0.66143782776614768, 0.0,
    0.0, -0.0, -0.0, -0.66143782776614768, -0.0, -0.0, 0.0, 0.0,
    0.66143782776614768, 0.0, 0.0, -0.0, -0.0, -0.66143782776614768, -0.0, -0.0,
    0.0, 0.0, -0.49607837082461076, 0.0, 0.0, -0.0, -0.0, 0.49607837082461076,
    -0.0, -0.0, 0.0, 0.0, -0.49607837082461076, 0.0, 0.0, -0.0, -0.0,
    0.49607837082461076, -0.0, -0.0, 0.0, 0.0, 0.37205877811845806, 0.0, 0.0,
    -0.0, -0.0, -0.37205877811845806, -0.0, -0.0, 0.0, 0.0, 0.37205877811845806,
    0.0, 0.0, -0.0, -0.0, -0.37205877811845806, -0.0, -0.0, 0.0, 0.0,
    -0.27904408358884353, 0.0, 0.0, -0.0, -0.0, 0.27904408358884353, -0.0, -0.0,
    0.0, 0.0, -0.27904408358884353, 0.0, 0.0, -0.0, -0.0, 0.27904408358884353,
    -0.0, -0.0, 0.0, 0.0, 0.0, 0.66143782776614768, 0.0, -0.0, -0.0, -0.0,
    -0.66143782776614768, -0.0, 0.0, 0.0, 0.0, 0.66143782776614768, 0.0, -0.0,
    -0.0, -0.0, -0.66143782776614768, -0.0, 0.0, 0.0, 0.0, -0.49607837082461076,
    0.0, -0.0, -0.0, -0.0, 0.49607837082461076, -0.0, 0.0, 0.0, 0.0,
    -0.49607837082461076, 0.0, -0.0, -0.0, -0.0, 0.49607837082461076, -0.0, 0.0,
    0.0, 0.0, 0.37205877811845806, 0.0, -0.0, -0.0, -0.0, -0.37205877811845806,
    -0.0, 0.0, 0.0, 0.0, 0.37205877811845806, 0.0, -0.0, -0.0, -0.0,
    -0.37205877811845806, -0.0, 0.0, 0.0, 0.0, -0.27904408358884353, 0.0, -0.0,
    -0.0, -0.0, 0.27904408358884353, -0.0, 0.0, 0.0, 0.0, -0.27904408358884353,
    0.0, -0.0, -0.0, -0.0, 0.27904408358884353, -0.0, 0.0, 0.0, 0.0, 0.0,
    0.66143782776614768, -0.0, -0.0, -0.0, -0.0, -0.66143782776614768, 0.0, 0.0,
    0.0, 0.0, 0.66143782776614768, -0.0, -0.0, -0.0, -0.0, -0.66143782776614768,
    0.0, 0.0, 0.0, 0.0, -0.49607837082461076, -0.0, -0.0, -0.0, -0.0,
    0.49607837082461076, 0.0, 0.0, 0.0, 0.0, -0.49607837082461076, -0.0, -0.0,
    -0.0, -0.0, 0.49607837082461076, 0.0, 0.0, 0.0, 0.0, 0.37205877811845806,
    -0.0, -0.0, -0.0, -0.0, -0.37205877811845806, 0.0, 0.0, 0.0, 0.0,
    0.37205877811845806, -0.0, -0.0, -0.0, -0.0, -0.37205877811845806, 0.0, 0.0,
    0.0, 0.0, -0.27904408358884353, -0.0, -0.0, -0.0, -0.0, 0.27904408358884353,
    0.0, 0.0, 0.0, 0.0, -0.27904408358884353, -0.0, -0.0, -0.0, -0.0,
    0.27904408358884353 };

  static const real_T a[100] = { 0.66143782776614768, 0.0, 0.0, 0.0, 0.0,
    -0.49607837082461076, 0.0, 0.0, 0.0, 0.0, 0.37205877811845806, 0.0, 0.0, 0.0,
    0.0, -0.27904408358884353, 0.0, 0.0, 0.0, 0.0, 0.0, 0.66143782776614768, 0.0,
    0.0, 0.0, 0.0, -0.49607837082461076, 0.0, 0.0, 0.0, 0.0, 0.37205877811845806,
    0.0, 0.0, 0.0, 0.0, -0.27904408358884353, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.66143782776614768, 0.0, 0.0, 0.0, 0.0, -0.49607837082461076, 0.0, 0.0, 0.0,
    0.0, 0.37205877811845806, 0.0, 0.0, 0.0, 0.0, -0.27904408358884353, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.66143782776614768, 0.0, 0.0, 0.0, 0.0, -0.49607837082461076,
    0.0, 0.0, 0.0, 0.0, 0.37205877811845806, 0.0, 0.0, 0.0, 0.0,
    -0.27904408358884353, 0.0, 0.0, 0.0, 0.0, 0.0, 0.66143782776614768, 0.0, 0.0,
    0.0, 0.0, -0.49607837082461076, 0.0, 0.0, 0.0, 0.0, 0.37205877811845806, 0.0,
    0.0, 0.0, 0.0, -0.27904408358884353 };

  real_T *tmp_0;

  /* Delay: '<Root>/Delay2' */
  for (i = 0; i < 5; i++) {
    rtb_Delay2[i] = MPC_MMC_qudratic_paper_v1_DWork.Delay2_DSTATE[i];
  }

  /* End of Delay: '<Root>/Delay2' */

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  Delay: '<Root>/Delay'
   *  Delay: '<Root>/Delay1'
   *  Inport: '<Root>/U_lim'
   *  Inport: '<Root>/du_lim'
   *  Inport: '<Root>/measument'
   *  Inport: '<Root>/set_point'
   */
  /* MATLAB Function 'MATLAB Function': '<S1>:1' */
  /* '<S1>:1:5' */
  /* '<S1>:1:7' */
  /* '<S1>:1:3' */
  /* '<S1>:1:4' */
  tmp_0 = &MPC_MMC_qudratic_paper_v1_DWork.Delay_DSTATE[0];
  for (i_0 = 0; i_0 < 20; i_0++) {
    b_a[i_0] = 0.0;
    for (i = 0; i < 10; i++) {
      b_a[i_0] += b_a_0[20 * i + i_0] * tmp_0[i];
    }
  }

  for (i_0 = 0; i_0 < 5; i_0++) {
    tmp[i_0] = MPC_MMC_qudratic_paper_v1v7_U.U_lim[i_0] - rtb_Delay2[i_0];
    tmp[i_0 + 5] = MPC_MMC_qudratic_paper_v1v7_U.U_lim[i_0] + rtb_Delay2[i_0];
    tmp[i_0 + 10] = MPC_MMC_qudratic_paper_v1v7_U.du_lim[i_0];
    tmp[i_0 + 15] = MPC_MMC_qudratic_paper_v1v7_U.du_lim[i_0];
  }

  MPC_MMC_qudratic_paper_v_QPhild(b, b_a, c, tmp, eta);

  /* '<S1>:1:7' */
  /* '<S1>:1:8' */
  /* '<S1>:1:11' */
  /* '<S1>:1:12' */
  for (i = 0; i < 5; i++) {
    rtb_deltau[i] = 0.0;
    for (i_0 = 0; i_0 < 20; i_0++) {
      rtb_deltau[i] += a[5 * i_0 + i] * eta[i_0];
    }

    rtb_Xf[i] = MPC_MMC_qudratic_paper_v1v7_U.measument[i] -
      MPC_MMC_qudratic_paper_v1_DWork.Delay1_DSTATE[i];
    rtb_Xf[i + 5] = MPC_MMC_qudratic_paper_v1v7_U.measument[i] -
      MPC_MMC_qudratic_paper_v1v7_U.set_point[i];
    rtb_Delay2[i] += rtb_deltau[i];
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function' */

  /* Outport: '<Root>/IntOut3' */
  memcpy(&MPC_MMC_qudratic_paper_v1v7_Y.Xf[0], &rtb_Xf[0], 10U * sizeof(real_T));
  for (i = 0; i < 5; i++) {
    /* Outport: '<Root>/IntOut4' */
    MPC_MMC_qudratic_paper_v1v7_Y.u[i] = rtb_Delay2[i];

    /* Outport: '<Root>/IntOut1' */
    MPC_MMC_qudratic_paper_v1v7_Y.delta_u[i] = rtb_deltau[i];
  }

  /* Update for Delay: '<Root>/Delay' */
  memcpy(&MPC_MMC_qudratic_paper_v1_DWork.Delay_DSTATE[0], &rtb_Xf[0], 10U *
         sizeof(real_T));
  for (i = 0; i < 5; i++) {
    /* Update for Delay: '<Root>/Delay2' */
    MPC_MMC_qudratic_paper_v1_DWork.Delay2_DSTATE[i] = rtb_Delay2[i];

    /* Update for Delay: '<Root>/Delay1' incorporates:
     *  Inport: '<Root>/measument'
     */
    MPC_MMC_qudratic_paper_v1_DWork.Delay1_DSTATE[i] =
      MPC_MMC_qudratic_paper_v1v7_U.measument[i];
  }
}

/* Model initialize function */
void MPC_MMC_qudratic_paper_v1v7_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(MPC_MMC_qudratic_paper_v1v7_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&MPC_MMC_qudratic_paper_v1_DWork, 0,
                sizeof(D_Work_MPC_MMC_qudratic_paper_v));

  /* external inputs */
  (void)memset(&MPC_MMC_qudratic_paper_v1v7_U, 0, sizeof
               (ExternalInputs_MPC_MMC_qudratic));

  /* external outputs */
  (void) memset((void *)&MPC_MMC_qudratic_paper_v1v7_Y, 0,
                sizeof(ExternalOutputs_MPC_MMC_qudrati));

  {
    int32_T i;

    /* InitializeConditions for Delay: '<Root>/Delay' */
    for (i = 0; i < 10; i++) {
      MPC_MMC_qudratic_paper_v1_DWork.Delay_DSTATE[i] =
        MPC_MMC_qudratic_paper_v1v7_P.Delay_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<Root>/Delay' */
    for (i = 0; i < 5; i++) {
      /* InitializeConditions for Delay: '<Root>/Delay2' */
      MPC_MMC_qudratic_paper_v1_DWork.Delay2_DSTATE[i] =
        MPC_MMC_qudratic_paper_v1v7_P.Delay2_InitialCondition;

      /* InitializeConditions for Delay: '<Root>/Delay1' */
      MPC_MMC_qudratic_paper_v1_DWork.Delay1_DSTATE[i] =
        MPC_MMC_qudratic_paper_v1v7_P.Delay1_InitialCondition;
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
