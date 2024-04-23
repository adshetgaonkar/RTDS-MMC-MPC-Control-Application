/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: VDC_cont_4T_V3_types.h
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

#ifndef RTW_HEADER_VDC_cont_4T_V3_types_h_
#define RTW_HEADER_VDC_cont_4T_V3_types_h_
#include "rtwtypes.h"

/* Custom Type definition for MATLAB Function: '<Root>/MATLAB Function1' */
#ifndef struct_tag_s1oCjVb6Z7BG8RpZcUOHDiE
#define struct_tag_s1oCjVb6Z7BG8RpZcUOHDiE

struct tag_s1oCjVb6Z7BG8RpZcUOHDiE
{
  real_T A[4];
  real_T Ap;
  real_T Ap_a;
  real_T B[2];
  real_T Bp;
  real_T Bp_a;
  real_T C[2];
  real_T Cp;
  real_T Cp_a;
  real_T Dp;
  real_T F;
  real_T G;
  real_T Lzerot[4];
  real_T M[16];
  real_T M0[4];
  real_T M1[4];
  real_T N;
  real_T N_sim;
  real_T Na_c;
  real_T Na_r;
  real_T Nb_c;
  real_T Nb_r;
  real_T Nc;
  real_T Np;
  real_T Omega[16];
  real_T Psi[8];
  real_T Q[4];
  real_T R;
  real_T Ts;
  real_T Xf[2];
  real_T a;
  real_T deltau_max;
  real_T deltau_min;
  real_T b_gamma[2];
  real_T m1;
  real_T n1;
  real_T n_in;
  real_T r;
  real_T u;
  real_T u_max;
  real_T u_min;
  real_T up;
  real_T xm;
  real_T y;
};

#endif                                 /*struct_tag_s1oCjVb6Z7BG8RpZcUOHDiE*/

#ifndef typedef_s1oCjVb6Z7BG8RpZcUOHDiE_VDC_con
#define typedef_s1oCjVb6Z7BG8RpZcUOHDiE_VDC_con

typedef struct tag_s1oCjVb6Z7BG8RpZcUOHDiE s1oCjVb6Z7BG8RpZcUOHDiE_VDC_con;

#endif                               /*typedef_s1oCjVb6Z7BG8RpZcUOHDiE_VDC_con*/

/* Parameters (default storage) */
typedef struct Parameters_VDC_cont_4T_V3_ Parameters_VDC_cont_4T_V3;

/* Forward declaration for rtModel */
typedef struct tag_RTM_VDC_cont_4T_V3 RT_MODEL_VDC_cont_4T_V3;

#endif                                 /* RTW_HEADER_VDC_cont_4T_V3_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */