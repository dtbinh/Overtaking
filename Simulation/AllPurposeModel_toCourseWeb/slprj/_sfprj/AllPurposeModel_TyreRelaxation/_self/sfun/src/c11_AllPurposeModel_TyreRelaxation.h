#ifndef __c11_AllPurposeModel_TyreRelaxation_h__
#define __c11_AllPurposeModel_TyreRelaxation_h__

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

#ifndef typedef_c11_whl_vec4
#define typedef_c11_whl_vec4

typedef struct whl_vec4_tag c11_whl_vec4;

#endif                                 /*typedef_c11_whl_vec4*/

#ifndef struct_oorp_vec3_tag
#define struct_oorp_vec3_tag

struct oorp_vec3_tag
{
  real_T z;
  real_T rotx;
  real_T roty;
};

#endif                                 /*struct_oorp_vec3_tag*/

#ifndef typedef_c11_oorp_vec3
#define typedef_c11_oorp_vec3

typedef struct oorp_vec3_tag c11_oorp_vec3;

#endif                                 /*typedef_c11_oorp_vec3*/

#ifndef struct_struct_HhckT6rntEraqECYVIDvCC_tag
#define struct_struct_HhckT6rntEraqECYVIDvCC_tag

struct struct_HhckT6rntEraqECYVIDvCC_tag
{
  real_T x;
  real_T y;
};

#endif                                 /*struct_struct_HhckT6rntEraqECYVIDvCC_tag*/

#ifndef typedef_c11_struct_HhckT6rntEraqECYVIDvCC
#define typedef_c11_struct_HhckT6rntEraqECYVIDvCC

typedef struct struct_HhckT6rntEraqECYVIDvCC_tag
  c11_struct_HhckT6rntEraqECYVIDvCC;

#endif                                 /*typedef_c11_struct_HhckT6rntEraqECYVIDvCC*/

#ifndef struct_struct_Nst2vGTExxHsg85EUOj9EH_tag
#define struct_struct_Nst2vGTExxHsg85EUOj9EH_tag

struct struct_Nst2vGTExxHsg85EUOj9EH_tag
{
  real_T g;
  c11_struct_HhckT6rntEraqECYVIDvCC left1;
  c11_struct_HhckT6rntEraqECYVIDvCC right1;
  c11_struct_HhckT6rntEraqECYVIDvCC right2;
  c11_struct_HhckT6rntEraqECYVIDvCC left2;
  c11_struct_HhckT6rntEraqECYVIDvCC right3;
  real_T mu;
};

#endif                                 /*struct_struct_Nst2vGTExxHsg85EUOj9EH_tag*/

#ifndef typedef_c11_struct_Nst2vGTExxHsg85EUOj9EH
#define typedef_c11_struct_Nst2vGTExxHsg85EUOj9EH

typedef struct struct_Nst2vGTExxHsg85EUOj9EH_tag
  c11_struct_Nst2vGTExxHsg85EUOj9EH;

#endif                                 /*typedef_c11_struct_Nst2vGTExxHsg85EUOj9EH*/

#ifndef struct_struct_r4FNviKwHfdhB8nQjvQv9_tag
#define struct_struct_r4FNviKwHfdhB8nQjvQv9_tag

struct struct_r4FNviKwHfdhB8nQjvQv9_tag
{
  real_T v_set;
};

#endif                                 /*struct_struct_r4FNviKwHfdhB8nQjvQv9_tag*/

#ifndef typedef_c11_struct_r4FNviKwHfdhB8nQjvQv9
#define typedef_c11_struct_r4FNviKwHfdhB8nQjvQv9

typedef struct struct_r4FNviKwHfdhB8nQjvQv9_tag c11_struct_r4FNviKwHfdhB8nQjvQv9;

#endif                                 /*typedef_c11_struct_r4FNviKwHfdhB8nQjvQv9*/

#ifndef struct_struct_Y9F1qlBi9AhssksPwemA4G_tag
#define struct_struct_Y9F1qlBi9AhssksPwemA4G_tag

struct struct_Y9F1qlBi9AhssksPwemA4G_tag
{
  real_T v_x;
  real_T F_fz;
  real_T F_rz;
};

#endif                                 /*struct_struct_Y9F1qlBi9AhssksPwemA4G_tag*/

#ifndef typedef_c11_struct_Y9F1qlBi9AhssksPwemA4G
#define typedef_c11_struct_Y9F1qlBi9AhssksPwemA4G

typedef struct struct_Y9F1qlBi9AhssksPwemA4G_tag
  c11_struct_Y9F1qlBi9AhssksPwemA4G;

#endif                                 /*typedef_c11_struct_Y9F1qlBi9AhssksPwemA4G*/

#ifndef struct_struct_ZKAzdrl7umDGJoC14aoVKC_tag
#define struct_struct_ZKAzdrl7umDGJoC14aoVKC_tag

struct struct_ZKAzdrl7umDGJoC14aoVKC_tag
{
  real_T fl[3];
  real_T fr[3];
  real_T rl[3];
  real_T rr[3];
};

#endif                                 /*struct_struct_ZKAzdrl7umDGJoC14aoVKC_tag*/

#ifndef typedef_c11_struct_ZKAzdrl7umDGJoC14aoVKC
#define typedef_c11_struct_ZKAzdrl7umDGJoC14aoVKC

typedef struct struct_ZKAzdrl7umDGJoC14aoVKC_tag
  c11_struct_ZKAzdrl7umDGJoC14aoVKC;

#endif                                 /*typedef_c11_struct_ZKAzdrl7umDGJoC14aoVKC*/

#ifndef struct_struct_ZCmOWPuqBDw16FSOVVD00_tag
#define struct_struct_ZCmOWPuqBDw16FSOVVD00_tag

struct struct_ZCmOWPuqBDw16FSOVVD00_tag
{
  real_T m;
  real_T Jz;
  real_T m_sprung;
  real_T Jx_sprung;
  real_T Jy_sprung;
  real_T lf;
  real_T lr;
  real_T L;
  real_T TrackWidth;
  real_T h;
  real_T HalfRohACd;
  real_T F_z4_static[4];
  real_T Rw;
  c11_struct_ZKAzdrl7umDGJoC14aoVKC r_long;
  c11_struct_ZKAzdrl7umDGJoC14aoVKC r_lat;
  c11_struct_ZKAzdrl7umDGJoC14aoVKC r_lever;
  c11_struct_ZKAzdrl7umDGJoC14aoVKC r_pivot;
  real_T cw;
  real_T carb_f;
  real_T carb_r;
  real_T dw;
  real_T Jw;
  real_T C0;
  real_T RelaxLength;
  real_T RRC;
  real_T Pmax;
  real_T PropDistrFrnt;
  real_T BrkDistrFrnt;
  real_T SteRatio;
};

#endif                                 /*struct_struct_ZCmOWPuqBDw16FSOVVD00_tag*/

#ifndef typedef_c11_struct_ZCmOWPuqBDw16FSOVVD00
#define typedef_c11_struct_ZCmOWPuqBDw16FSOVVD00

typedef struct struct_ZCmOWPuqBDw16FSOVVD00_tag c11_struct_ZCmOWPuqBDw16FSOVVD00;

#endif                                 /*typedef_c11_struct_ZCmOWPuqBDw16FSOVVD00*/

#ifndef struct_struct_iBlsPBO3AGnt69vDoTx5zD_tag
#define struct_struct_iBlsPBO3AGnt69vDoTx5zD_tag

struct struct_iBlsPBO3AGnt69vDoTx5zD_tag
{
  c11_struct_Nst2vGTExxHsg85EUOj9EH Env;
  c11_struct_ZCmOWPuqBDw16FSOVVD00 Veh;
  c11_struct_r4FNviKwHfdhB8nQjvQv9 Drvr;
  c11_struct_Y9F1qlBi9AhssksPwemA4G Init;
};

#endif                                 /*struct_struct_iBlsPBO3AGnt69vDoTx5zD_tag*/

#ifndef typedef_c11_struct_iBlsPBO3AGnt69vDoTx5zD
#define typedef_c11_struct_iBlsPBO3AGnt69vDoTx5zD

typedef struct struct_iBlsPBO3AGnt69vDoTx5zD_tag
  c11_struct_iBlsPBO3AGnt69vDoTx5zD;

#endif                                 /*typedef_c11_struct_iBlsPBO3AGnt69vDoTx5zD*/

#ifndef typedef_SFc11_AllPurposeModel_TyreRelaxationInstanceStruct
#define typedef_SFc11_AllPurposeModel_TyreRelaxationInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c11_sfEvent;
  boolean_T c11_isStable;
  boolean_T c11_doneDoubleBufferReInit;
  uint8_T c11_is_active_c11_AllPurposeModel_TyreRelaxation;
  c11_struct_iBlsPBO3AGnt69vDoTx5zD c11_Par;
  c11_whl_vec4 *c11_F_xv4;
  c11_oorp_vec3 *c11_derv_oorp3;
  c11_whl_vec4 *c11_F_yv4;
  c11_whl_vec4 *c11_F_z4;
} SFc11_AllPurposeModel_TyreRelaxationInstanceStruct;

#endif                                 /*typedef_SFc11_AllPurposeModel_TyreRelaxationInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c11_AllPurposeModel_TyreRelaxation_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c11_AllPurposeModel_TyreRelaxation_get_check_sum(mxArray *plhs[]);
extern void c11_AllPurposeModel_TyreRelaxation_method_dispatcher(SimStruct *S,
  int_T method, void *data);

#endif
