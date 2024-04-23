/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Traditional_MPC_MMC_qudratic.h
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

#ifndef RTW_HEADER_Traditional_MPC_MMC_qudratic_h_
#define RTW_HEADER_Traditional_MPC_MMC_qudratic_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef Traditional_MPC_MMC_qudratic_COMMON_INCLUDES_
# define Traditional_MPC_MMC_qudratic_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                       /* Traditional_MPC_MMC_qudratic_COMMON_INCLUDES_ */

#include "Traditional_MPC_MMC_qudratic_types.h"
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
  real_T Memory_PreviousInput[10];     /* '<Root>/Memory' */
  real_T Memory2_PreviousInput[5];     /* '<Root>/Memory2' */
  real_T Memory1_PreviousInput[5];     /* '<Root>/Memory1' */
} D_Work_Traditional_MPC_MMC_qudr;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T set_point[5];                 /* '<Root>/set_point' */
  real_T kthstate[5];                  /* '<Root>/kth-state' */
  real_T u_max[5];                     /* '<Root>/u_max' */
  real_T u_min[5];                     /* '<Root>/u_min' */
  real_T du_max;                       /* '<Root>/du_max' */
  real_T du_min;                       /* '<Root>/du_min' */
  real_T y_max;                        /* '<Root>/y_max' */
  real_T y_min;                        /* '<Root>/y_min' */
} ExternalInputs_Traditional_MPC_;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Xf[10];                       /* '<Root>/IntOut3' */
  real_T u[5];                         /* '<Root>/IntOut4' */
  real_T delta_u[5];                   /* '<Root>/IntOut1' */
  real_T error[5];                     /* '<Root>/IntOut2' */
  real_T J;                            /* '<Root>/IntOut5' */
} ExternalOutputs_Traditional_MPC;

/* Parameters (default storage) */
struct Parameters_Traditional_MPC_MMC__ {
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<Root>/Memory'
                                        */
  real_T Memory2_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<Root>/Memory2'
                                        */
  real_T Memory1_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<Root>/Memory1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Traditional_MPC_MMC_qud {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern Parameters_Traditional_MPC_MMC_ Traditional_MPC_MMC_qudratic_P;

/* Block states (default storage) */
extern D_Work_Traditional_MPC_MMC_qudr Traditional_MPC_MMC_qudra_DWork;

/* External inputs (root inport signals with default storage) */
extern ExternalInputs_Traditional_MPC_ Traditional_MPC_MMC_qudratic_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExternalOutputs_Traditional_MPC Traditional_MPC_MMC_qudratic_Y;

/* Model entry point functions */
extern void Traditional_MPC_MMC_qudratic_initialize(void);
extern void Traditional_MPC_MMC_qudratic_step(void);

/* Real-time Model object */
extern RT_MODEL_Traditional_MPC_MMC_qu *const Traditional_MPC_MMC_qudratic_M;

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
 * '<Root>' : 'Traditional_MPC_MMC_qudratic'
 * '<S1>'   : 'Traditional_MPC_MMC_qudratic/MATLAB Function'
 */
#endif                          /* RTW_HEADER_Traditional_MPC_MMC_qudratic_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
