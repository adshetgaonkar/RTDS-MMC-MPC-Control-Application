/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: MPC_grid_forming_v1v1.h
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

#ifndef RTW_HEADER_MPC_grid_forming_v1v1_h_
#define RTW_HEADER_MPC_grid_forming_v1v1_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef MPC_grid_forming_v1v1_COMMON_INCLUDES_
# define MPC_grid_forming_v1v1_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                              /* MPC_grid_forming_v1v1_COMMON_INCLUDES_ */

#include "MPC_grid_forming_v1v1_types.h"
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
  real_T Delay1_DSTATE;                /* '<Root>/Delay1' */
} D_Work_MPC_grid_forming_v1v1;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Inport;                       /* '<Root>/Inport' */
  real_T Inport1;                      /* '<Root>/Inport1' */
  real_T Inport2;                      /* '<Root>/Inport2' */
} ExternalInputs_MPC_grid_forming;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Xf[2];                        /* '<Root>/IntOut3' */
  real_T u;                            /* '<Root>/IntOut4' */
  real_T delta_u;                      /* '<Root>/IntOut1' */
} ExternalOutputs_MPC_grid_formin;

/* Parameters (default storage) */
struct Parameters_MPC_grid_forming_v1v_ {
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<Root>/Delay'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<Root>/Delay1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_MPC_grid_forming_v1v1 {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern Parameters_MPC_grid_forming_v1v MPC_grid_forming_v1v1_P;

/* Block states (default storage) */
extern D_Work_MPC_grid_forming_v1v1 MPC_grid_forming_v1v1_DWork;

/* External inputs (root inport signals with default storage) */
extern ExternalInputs_MPC_grid_forming MPC_grid_forming_v1v1_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExternalOutputs_MPC_grid_formin MPC_grid_forming_v1v1_Y;

/* Model entry point functions */
extern void MPC_grid_forming_v1v1_initialize(void);
extern void MPC_grid_forming_v1v1_step(void);

/* Real-time Model object */
extern RT_MODEL_MPC_grid_forming_v1v1 *const MPC_grid_forming_v1v1_M;

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
 * '<Root>' : 'MPC_grid_forming_v1v1'
 * '<S1>'   : 'MPC_grid_forming_v1v1/MATLAB Function1'
 */
#endif                                 /* RTW_HEADER_MPC_grid_forming_v1v1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
