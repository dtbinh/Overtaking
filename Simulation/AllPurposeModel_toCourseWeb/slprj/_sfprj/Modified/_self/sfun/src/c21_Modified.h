#ifndef __c21_Modified_h__
#define __c21_Modified_h__

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

#ifndef typedef_c21_whl_vec4
#define typedef_c21_whl_vec4

typedef struct whl_vec4_tag c21_whl_vec4;

#endif                                 /*typedef_c21_whl_vec4*/

#ifndef typedef_SFc21_ModifiedInstanceStruct
#define typedef_SFc21_ModifiedInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c21_sfEvent;
  boolean_T c21_isStable;
  boolean_T c21_doneDoubleBufferReInit;
  uint8_T c21_is_active_c21_Modified;
  c21_whl_vec4 *c21_F_xw4;
  c21_whl_vec4 *c21_F_yw4;
  c21_whl_vec4 *c21_F_xv4;
  c21_whl_vec4 *c21_F_yv4;
  c21_whl_vec4 *c21_delta_w4;
} SFc21_ModifiedInstanceStruct;

#endif                                 /*typedef_SFc21_ModifiedInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c21_Modified_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c21_Modified_get_check_sum(mxArray *plhs[]);
extern void c21_Modified_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
