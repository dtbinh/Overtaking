#ifndef __c20_Modified2_h__
#define __c20_Modified2_h__

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

#ifndef typedef_c20_whl_vec4
#define typedef_c20_whl_vec4

typedef struct whl_vec4_tag c20_whl_vec4;

#endif                                 /*typedef_c20_whl_vec4*/

#ifndef typedef_SFc20_Modified2InstanceStruct
#define typedef_SFc20_Modified2InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c20_sfEvent;
  boolean_T c20_isStable;
  boolean_T c20_doneDoubleBufferReInit;
  uint8_T c20_is_active_c20_Modified2;
  c20_whl_vec4 *c20_v_xv4;
  c20_whl_vec4 *c20_v_xw4;
  c20_whl_vec4 *c20_v_yw4;
  c20_whl_vec4 *c20_v_yv4;
  c20_whl_vec4 *c20_delta_w4;
} SFc20_Modified2InstanceStruct;

#endif                                 /*typedef_SFc20_Modified2InstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c20_Modified2_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c20_Modified2_get_check_sum(mxArray *plhs[]);
extern void c20_Modified2_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
