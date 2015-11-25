#ifndef __c17_Modified_h__
#define __c17_Modified_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef struct_irp_vec3_tag
#define struct_irp_vec3_tag

struct irp_vec3_tag
{
  real_T x;
  real_T y;
  real_T rotz;
};

#endif                                 /*struct_irp_vec3_tag*/

#ifndef typedef_c17_irp_vec3
#define typedef_c17_irp_vec3

typedef struct irp_vec3_tag c17_irp_vec3;

#endif                                 /*typedef_c17_irp_vec3*/

#ifndef typedef_SFc17_ModifiedInstanceStruct
#define typedef_SFc17_ModifiedInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c17_sfEvent;
  boolean_T c17_isStable;
  boolean_T c17_doneDoubleBufferReInit;
  uint8_T c17_is_active_c17_Modified;
  c17_irp_vec3 *c17_v_irp3;
  real_T *c17_p_z;
  c17_irp_vec3 *c17_derpos_irp3;
} SFc17_ModifiedInstanceStruct;

#endif                                 /*typedef_SFc17_ModifiedInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c17_Modified_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c17_Modified_get_check_sum(mxArray *plhs[]);
extern void c17_Modified_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
