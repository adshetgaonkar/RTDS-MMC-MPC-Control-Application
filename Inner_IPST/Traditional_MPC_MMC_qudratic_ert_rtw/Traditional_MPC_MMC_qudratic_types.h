/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Traditional_MPC_MMC_qudratic_types.h
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

#ifndef RTW_HEADER_Traditional_MPC_MMC_qudratic_types_h_
#define RTW_HEADER_Traditional_MPC_MMC_qudratic_types_h_
#include "rtwtypes.h"

/* Custom Type definition for MATLAB Function: '<Root>/MATLAB Function' */
#ifndef struct_tag_sYHDqHJ8bm50cQoV8kXYNgH
#define struct_tag_sYHDqHJ8bm50cQoV8kXYNgH

struct tag_sYHDqHJ8bm50cQoV8kXYNgH
{
  real_T A_ac[25];
  real_T A_bigC[25];
  real_T A_e[100];
  real_T A_tem[25];
  struct {
    struct {
      real_T f1[25];
    } _data;
  } Ac_tem;

  real_T Am[25];
  real_T Ap[25];
  real_T Ar_tem[25];
  real_T B_ac[25];
  real_T B_e[50];
  real_T Bm[25];
  real_T Bp[25];
  real_T C_LHS[110];
  real_T C_ac[25];
  real_T C_e[50];
  real_T Cm[25];
  real_T Cp[25];
  real_T D_ac[25];
  real_T F[1600];
  real_T G[25];
  real_T H[25];
  real_T Im[25];
  real_T Iu[25];
  real_T L_ac_eq;
  real_T L_dc_eq;
  real_T Larm;
  real_T Lf;
  real_T N;
  real_T N_sim;
  real_T Na_c;
  real_T Na_r;
  real_T Nb_c;
  real_T Nb_r;
  real_T Nc;
  real_T Np;
  real_T Phi[800];
  real_T PhiT_Q_F[50];
  real_T PhiT_Q_Ie[25];
  real_T PhiT_Q_R_bar[25];
  real_T Q[25600];
  real_T R[25];
  real_T R_ac_eq;
  real_T R_bar[800];
  real_T R_dc_eq;
  real_T Rarm;
  real_T Rf;
  real_T T;
  real_T Xf[10];
  real_T bduMax[5];
  real_T bduMin[5];
  real_T bigIm[25];
  real_T duMax[5];
  real_T e[5];
  real_T h[1600];
  real_T i;
  real_T kk;
  real_T m;
  real_T n;
  real_T n1;
  real_T q;
  real_T r[500];
  real_T r1[100];
  real_T r2[100];
  real_T r3[100];
  real_T r4[100];
  real_T r5[100];
  real_T u[5];
  real_T uMax[5];
  real_T uMin[5];
  real_T up[5];
  real_T v[800];
  real_T w;
  real_T xm[5];
  real_T y[5];
  real_T yMax;
  real_T yMin;
};

#endif                                 /*struct_tag_sYHDqHJ8bm50cQoV8kXYNgH*/

#ifndef typedef_sYHDqHJ8bm50cQoV8kXYNgH_Traditi
#define typedef_sYHDqHJ8bm50cQoV8kXYNgH_Traditi

typedef struct tag_sYHDqHJ8bm50cQoV8kXYNgH sYHDqHJ8bm50cQoV8kXYNgH_Traditi;

#endif                               /*typedef_sYHDqHJ8bm50cQoV8kXYNgH_Traditi*/

/* Parameters (default storage) */
typedef struct Parameters_Traditional_MPC_MMC__ Parameters_Traditional_MPC_MMC_;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Traditional_MPC_MMC_qud RT_MODEL_Traditional_MPC_MMC_qu;

#endif                    /* RTW_HEADER_Traditional_MPC_MMC_qudratic_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
