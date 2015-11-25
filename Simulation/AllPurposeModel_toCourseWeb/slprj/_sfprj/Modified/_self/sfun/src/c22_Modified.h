#ifndef __c22_Modified_h__
#define __c22_Modified_h__

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

#ifndef typedef_c22_whl_vec4
#define typedef_c22_whl_vec4

typedef struct whl_vec4_tag c22_whl_vec4;

#endif                                 /*typedef_c22_whl_vec4*/

#ifndef typedef_SFc22_ModifiedInstanceStruct
#define typedef_SFc22_ModifiedInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c22_sfEvent;
  boolean_T c22_isStable;
  boolean_T c22_doneDoubleBufferReInit;
  uint8_T c22_is_active_c22_Modified;
  c22_whl_vec4 *c22_v_xv4;
  c22_whl_vec4 *c22_v_xw4;
  c22_whl_vec4 *c22_v_yw4;
  c22_whl_vec4 *c22_v_yv4;
  c22_whl_vec4 *c22_delta_w4;
} SFc22_ModifiedInstanceStruct;

#endif                                 /*typedef_SFc22_ModifiedInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c22_Modified_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c22_Modified_get_check_sum(mxArray *plhs[]);
extern void c22_Modified_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
