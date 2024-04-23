/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: MPC_MMC_qudratic_paper_v1v7.h
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

#ifndef RTW_HEADER_MPC_MMC_qudratic_paper_v1v7_h_
#define RTW_HEADER_MPC_MMC_qudratic_paper_v1v7_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef MPC_MMC_qudratic_paper_v1v7_COMMON_INCLUDES_
# define MPC_MMC_qudratic_paper_v1v7_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                        /* MPC_MMC_qudratic_paper_v1v7_COMMON_INCLUDES_ */

#include "MPC_MMC_qudratic_paper_v1v7_types.h"
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
  real_T Delay_DSTATE[10];             /* '<Root>/Delay' */
  real_T Delay2_DSTATE[5];             /* '<Root>/Delay2' */
  real_T Delay1_DSTATE[5];             /* '<Root>/Delay1' */
} D_Work_MPC_MMC_qudratic_paper_v;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T set_point[5];                 /* '<Root>/set_point' */
  real_T measument[5];                 /* '<Root>/measument' */
  real_T U_lim[5];                     /* '<Root>/U_lim' */
  real_T du_lim[5];                    /* '<Root>/du_lim' */
} ExternalInputs_MPC_MMC_qudratic;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Xf[10];                       /* '<Root>/IntOut3' */
  real_T u[5];                         /* '<Root>/IntOut4' */
  real_T delta_u[5];                   /* '<Root>/IntOut1' */
} ExternalOutputs_MPC_MMC_qudrati;

/* Parameters (default storage) */
struct Parameters_MPC_MMC_qudratic_pap_ {
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
struct tag_RTM_MPC_MMC_qudratic_paper_ {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern Parameters_MPC_MMC_qudratic_pap MPC_MMC_qudratic_paper_v1v7_P;

/* Block states (default storage) */
extern D_Work_MPC_MMC_qudratic_paper_v MPC_MMC_qudratic_paper_v1_DWork;

/* External inputs (root inport signals with default storage) */
extern ExternalInputs_MPC_MMC_qudratic MPC_MMC_qudratic_paper_v1v7_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExternalOutputs_MPC_MMC_qudrati MPC_MMC_qudratic_paper_v1v7_Y;

/* Model entry point functions */
extern void MPC_MMC_qudratic_paper_v1v7_initialize(void);
extern void MPC_MMC_qudratic_paper_v1v7_step(void);

/* Real-time Model object */
extern RT_MODEL_MPC_MMC_qudratic_paper *const MPC_MMC_qudratic_paper_v1v7_M;

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
 * '<Root>' : 'MPC_MMC_qudratic_paper_v1v7'
 * '<S1>'   : 'MPC_MMC_qudratic_paper_v1v7/MATLAB Function'
 */
#endif                           /* RTW_HEADER_MPC_MMC_qudratic_paper_v1v7_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
