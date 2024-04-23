/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: MPC_MMC_qudratic_paper_v1v7_types.h
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

#ifndef RTW_HEADER_MPC_MMC_qudratic_paper_v1v7_types_h_
#define RTW_HEADER_MPC_MMC_qudratic_paper_v1v7_types_h_
#include "rtwtypes.h"

/* Custom Type definition for MATLAB Function: '<Root>/MATLAB Function' */
#ifndef struct_tag_s7QmIWr36wDiANM4T41dCRC
#define struct_tag_s7QmIWr36wDiANM4T41dCRC

struct tag_s7QmIWr36wDiANM4T41dCRC
{
  real_T A[100];
  real_T A_ac[25];
  real_T Ap_ac[25];
  real_T B[50];
  real_T B_ac[25];
  real_T Bp_ac[25];
  real_T C[50];
  real_T C_ac[25];
  real_T Cp_ac[25];
  real_T D_ac[25];
  real_T F[25];
  real_T G[25];
  real_T L_ac_eq;
  real_T L_dc_eq;
  real_T Larm;
  real_T Lf;
  real_T Lzerot[100];
  real_T M[400];
  real_T M0[100];
  real_T M1[100];
  real_T N[5];
  real_T N_sim;
  real_T Na_c;
  real_T Na_r;
  real_T Nb_c;
  real_T Nb_r;
  real_T Np;
  real_T Omega[400];
  real_T Psi[200];
  real_T Q[100];
  real_T R[25];
  real_T R_ac_eq;
  real_T R_dc_eq;
  real_T Rarm;
  real_T Rf;
  real_T T;
  real_T Xf[10];
  real_T a[5];
  real_T deltau_max[5];
  real_T deltau_min[5];
  real_T m1;
  real_T n1;
  real_T n_in;
  real_T r[5];
  real_T u[5];
  real_T u_max[5];
  real_T u_min[5];
  real_T up[5];
  real_T w;
  real_T xm[5];
  real_T y[5];
};

#endif                                 /*struct_tag_s7QmIWr36wDiANM4T41dCRC*/

#ifndef typedef_s7QmIWr36wDiANM4T41dCRC_MPC_MMC
#define typedef_s7QmIWr36wDiANM4T41dCRC_MPC_MMC

typedef struct tag_s7QmIWr36wDiANM4T41dCRC s7QmIWr36wDiANM4T41dCRC_MPC_MMC;

#endif                               /*typedef_s7QmIWr36wDiANM4T41dCRC_MPC_MMC*/

/* Parameters (default storage) */
typedef struct Parameters_MPC_MMC_qudratic_pap_ Parameters_MPC_MMC_qudratic_pap;

/* Forward declaration for rtModel */
typedef struct tag_RTM_MPC_MMC_qudratic_paper_ RT_MODEL_MPC_MMC_qudratic_paper;

#endif                     /* RTW_HEADER_MPC_MMC_qudratic_paper_v1v7_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
