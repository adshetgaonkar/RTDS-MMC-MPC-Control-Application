/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: VDC_cont_4T_V3.h
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

#ifndef RTW_HEADER_VDC_cont_4T_V3_h_
#define RTW_HEADER_VDC_cont_4T_V3_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef VDC_cont_4T_V3_COMMON_INCLUDES_
# define VDC_cont_4T_V3_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* VDC_cont_4T_V3_COMMON_INCLUDES_ */

#include "VDC_cont_4T_V3_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay_DSTATE[2];              /* '<Root>/Delay' */
  real_T Delay2_DSTATE;                /* '<Root>/Delay2' */
  real_T Delay1_DSTATE;                /* '<Root>/Delay1' */
} D_Work_VDC_cont_4T_V3;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Set_point;                    /* '<Root>/Set_point' */
  real_T Mesur;                        /* '<Root>/Mesur' */
  real_T U_lim;                        /* '<Root>/U_lim' */
  real_T Rate_lim;                     /* '<Root>/Rate_lim' */
} ExternalInputs_VDC_cont_4T_V3;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Xf[2];                        /* '<Root>/IntOut3' */
  real_T u;                            /* '<Root>/IntOut4' */
  real_T delta_u;                      /* '<Root>/IntOut1' */
} ExternalOutputs_VDC_cont_4T_V3;

/* Parameters (default storage) */
struct Parameters_VDC_cont_4T_V3_ {
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<Root>/Delay'
                                        */
  real_T Delay2_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<Root>/Delay2'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<Root>/Delay1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_VDC_cont_4T_V3 {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern Parameters_VDC_cont_4T_V3 VDC_cont_4T_V3_P;

/* Block states (default storage) */
extern D_Work_VDC_cont_4T_V3 VDC_cont_4T_V3_DWork;

/* External inputs (root inport signals with default storage) */
extern ExternalInputs_VDC_cont_4T_V3 VDC_cont_4T_V3_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExternalOutputs_VDC_cont_4T_V3 VDC_cont_4T_V3_Y;

/* Model entry point functions */
extern void VDC_cont_4T_V3_initialize(void);
extern void VDC_cont_4T_V3_step(void);

/* Real-time Model object */
extern RT_MODEL_VDC_cont_4T_V3 *const VDC_cont_4T_V3_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'VDC_cont_4T_V3'
 * '<S1>'   : 'VDC_cont_4T_V3/MATLAB Function1'
 */
#endif                                 /* RTW_HEADER_VDC_cont_4T_V3_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
