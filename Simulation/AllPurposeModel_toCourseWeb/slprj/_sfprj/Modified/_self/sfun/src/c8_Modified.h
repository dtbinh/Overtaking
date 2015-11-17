#ifndef __c8_Modified_h__
#define __c8_Modified_h__

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

#ifndef typedef_c8_irp_vec3
#define typedef_c8_irp_vec3

typedef struct irp_vec3_tag c8_irp_vec3;

#endif                                 /*typedef_c8_irp_vec3*/

#ifndef typedef_SFc8_ModifiedInstanceStruct
#define typedef_SFc8_ModifiedInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c8_sfEvent;
  boolean_T c8_isStable;
  boolean_T c8_doneDoubleBufferReInit;
  uint8_T c8_is_active_c8_Modified;
  c8_irp_vec3 *c8_v_irp3;
  real_T *c8_p_z;
  c8_irp_vec3 *c8_derpos_irp3;
} SFc8_ModifiedInstanceStruct;

#endif                                 /*typedef_SFc8_ModifiedInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c8_Modified_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c8_Modified_get_check_sum(mxArray *plhs[]);
extern void c8_Modified_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
