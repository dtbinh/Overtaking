#ifndef __c19_AllPurposeModel_TyreRelaxation_h__
#define __c19_AllPurposeModel_TyreRelaxation_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef struct_whl_vec4_tag
#define struct_whl_vec4_tag

struct whl_vec4_tag
{
  real_T fl;
  real_T fr;
  real_T rl;
  real_T rr;
};

#endif                                 /*struct_whl_vec4_tag*/

#ifndef typedef_c19_whl_vec4
#define typedef_c19_whl_vec4

typedef struct whl_vec4_tag c19_whl_vec4;

#endif                                 /*typedef_c19_whl_vec4*/

#ifndef typedef_SFc19_AllPurposeModel_TyreRelaxationInstanceStruct
#define typedef_SFc19_AllPurposeModel_TyreRelaxationInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c19_sfEvent;
  boolean_T c19_isStable;
  boolean_T c19_doneDoubleBufferReInit;
  uint8_T c19_is_active_c19_AllPurposeModel_TyreRelaxation;
  c19_whl_vec4 *c19_F_xw4;
  c19_whl_vec4 *c19_F_yw4;
  c19_whl_vec4 *c19_F_xv4;
  c19_whl_vec4 *c19_F_yv4;
  c19_whl_vec4 *c19_delta_w4;
} SFc19_AllPurposeModel_TyreRelaxationInstanceStruct;

#endif                                 /*typedef_SFc19_AllPurposeModel_TyreRelaxationInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c19_AllPurposeModel_TyreRelaxation_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c19_AllPurposeModel_TyreRelaxation_get_check_sum(mxArray *plhs[]);
extern void c19_AllPurposeModel_TyreRelaxation_method_dispatcher(SimStruct *S,
  int_T method, void *data);

#endif
