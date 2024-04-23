/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: VDC_control_tennet.h
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

#ifndef RTW_HEADER_VDC_control_tennet_h_
#define RTW_HEADER_VDC_control_tennet_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef VDC_control_tennet_COMMON_INCLUDES_
# define VDC_control_tennet_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* VDC_control_tennet_COMMON_INCLUDES_ */

#include "VDC_control_tennet_types.h"
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
  real_T Memory1_PreviousInput[2];     /* '<Root>/Memory1' */
  real_T Memory2_PreviousInput;        /* '<Root>/Memory2' */
  real_T Memory_PreviousInput;         /* '<Root>/Memory' */
} D_Work_VDC_control_tennet;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T setpoint;                     /* '<Root>/setpoint' */
  real_T Measument;                    /* '<Root>/Measument ' */
  real_T U_lim;                        /* '<Root>/U_lim' */
  real_T dU_lim;                       /* '<Root>/dU_lim' */
} ExternalInputs_VDC_control_tenn;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Xf[2];                        /* '<Root>/IntOut3' */
  real_T u;                            /* '<Root>/IntOut4' */
  real_T delta_u;                      /* '<Root>/IntOut1' */
} ExternalOutputs_VDC_control_ten;

/* Parameters (default storage) */
struct Parameters_VDC_control_tennet_ {
  real_T Memory1_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<Root>/Memory1'
                                        */
  real_T Memory2_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<Root>/Memory2'
                                        */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<Root>/Memory'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_VDC_control_tennet {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern Parameters_VDC_control_tennet VDC_control_tennet_P;

/* Block states (default storage) */
extern D_Work_VDC_control_tennet VDC_control_tennet_DWork;

/* External inputs (root inport signals with default storage) */
extern ExternalInputs_VDC_control_tenn VDC_control_tennet_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExternalOutputs_VDC_control_ten VDC_control_tennet_Y;

/* Model entry point functions */
extern void VDC_control_tennet_initialize(void);
extern void VDC_control_tennet_step(void);

/* Real-time Model object */
extern RT_MODEL_VDC_control_tennet *const VDC_control_tennet_M;

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
 * '<Root>' : 'VDC_control_tennet'
 * '<S1>'   : 'VDC_control_tennet/MATLAB Function1'
 */
#endif                                 /* RTW_HEADER_VDC_control_tennet_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
