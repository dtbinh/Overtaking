/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Modified_sfun.h"
#include "c32_Modified.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Modified_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c32_debug_family_names[11] = { "Jw", "nargin", "nargout",
  "T_s4", "T_us4", "F_xv4", "F_yv4", "F_z4", "w_w4", "Par", "derw_w4" };

/* Function Declarations */
static void initialize_c32_Modified(SFc32_ModifiedInstanceStruct *chartInstance);
static void initialize_params_c32_Modified(SFc32_ModifiedInstanceStruct
  *chartInstance);
static void enable_c32_Modified(SFc32_ModifiedInstanceStruct *chartInstance);
static void disable_c32_Modified(SFc32_ModifiedInstanceStruct *chartInstance);
static void c32_update_debugger_state_c32_Modified(SFc32_ModifiedInstanceStruct *
  chartInstance);
static const mxArray *get_sim_state_c32_Modified(SFc32_ModifiedInstanceStruct
  *chartInstance);
static void set_sim_state_c32_Modified(SFc32_ModifiedInstanceStruct
  *chartInstance, const mxArray *c32_st);
static void finalize_c32_Modified(SFc32_ModifiedInstanceStruct *chartInstance);
static void sf_gateway_c32_Modified(SFc32_ModifiedInstanceStruct *chartInstance);
static void mdl_start_c32_Modified(SFc32_ModifiedInstanceStruct *chartInstance);
static void initSimStructsc32_Modified(SFc32_ModifiedInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c32_machineNumber, uint32_T
  c32_chartNumber, uint32_T c32_instanceNumber);
static const mxArray *c32_sf_marshallOut(void *chartInstanceVoid, void
  *c32_inData);
static c32_whl_vec4 c32_emlrt_marshallIn(SFc32_ModifiedInstanceStruct
  *chartInstance, const mxArray *c32_b_derw_w4, const char_T *c32_identifier);
static c32_whl_vec4 c32_b_emlrt_marshallIn(SFc32_ModifiedInstanceStruct
  *chartInstance, const mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId);
static real_T c32_c_emlrt_marshallIn(SFc32_ModifiedInstanceStruct *chartInstance,
  const mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId);
static void c32_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c32_mxArrayInData, const char_T *c32_varName, void *c32_outData);
static const mxArray *c32_b_sf_marshallOut(void *chartInstanceVoid, void
  *c32_inData);
static void c32_d_emlrt_marshallIn(SFc32_ModifiedInstanceStruct *chartInstance,
  const mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId,
  c32_struct_iBlsPBO3AGnt69vDoTx5zD *c32_y);
static void c32_e_emlrt_marshallIn(SFc32_ModifiedInstanceStruct *chartInstance,
  const mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId,
  c32_struct_Nst2vGTExxHsg85EUOj9EH *c32_y);
static c32_struct_HhckT6rntEraqECYVIDvCC c32_f_emlrt_marshallIn
  (SFc32_ModifiedInstanceStruct *chartInstance, const mxArray *c32_u, const
   emlrtMsgIdentifier *c32_parentId);
static void c32_g_emlrt_marshallIn(SFc32_ModifiedInstanceStruct *chartInstance,
  const mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId,
  c32_struct_ZCmOWPuqBDw16FSOVVD00 *c32_y);
static void c32_h_emlrt_marshallIn(SFc32_ModifiedInstanceStruct *chartInstance,
  const mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId, real_T c32_y[4]);
static void c32_i_emlrt_marshallIn(SFc32_ModifiedInstanceStruct *chartInstance,
  const mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId,
  c32_struct_ZKAzdrl7umDGJoC14aoVKC *c32_y);
static void c32_j_emlrt_marshallIn(SFc32_ModifiedInstanceStruct *chartInstance,
  const mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId, real_T c32_y[3]);
static c32_struct_r4FNviKwHfdhB8nQjvQv9 c32_k_emlrt_marshallIn
  (SFc32_ModifiedInstanceStruct *chartInstance, const mxArray *c32_u, const
   emlrtMsgIdentifier *c32_parentId);
static c32_struct_Y9F1qlBi9AhssksPwemA4G c32_l_emlrt_marshallIn
  (SFc32_ModifiedInstanceStruct *chartInstance, const mxArray *c32_u, const
   emlrtMsgIdentifier *c32_parentId);
static void c32_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c32_mxArrayInData, const char_T *c32_varName, void *c32_outData);
static const mxArray *c32_c_sf_marshallOut(void *chartInstanceVoid, void
  *c32_inData);
static void c32_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c32_mxArrayInData, const char_T *c32_varName, void *c32_outData);
static void c32_info_helper(const mxArray **c32_info);
static const mxArray *c32_emlrt_marshallOut(const char * c32_u);
static const mxArray *c32_b_emlrt_marshallOut(const uint32_T c32_u);
static const mxArray *c32_d_sf_marshallOut(void *chartInstanceVoid, void
  *c32_inData);
static int32_T c32_m_emlrt_marshallIn(SFc32_ModifiedInstanceStruct
  *chartInstance, const mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId);
static void c32_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c32_mxArrayInData, const char_T *c32_varName, void *c32_outData);
static const mxArray *c32_T_s4_bus_io(void *chartInstanceVoid, void *c32_pData);
static uint8_T c32_n_emlrt_marshallIn(SFc32_ModifiedInstanceStruct
  *chartInstance, const mxArray *c32_b_is_active_c32_Modified, const char_T
  *c32_identifier);
static uint8_T c32_o_emlrt_marshallIn(SFc32_ModifiedInstanceStruct
  *chartInstance, const mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId);
static void init_dsm_address_info(SFc32_ModifiedInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc32_ModifiedInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c32_Modified(SFc32_ModifiedInstanceStruct *chartInstance)
{
  chartInstance->c32_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c32_is_active_c32_Modified = 0U;
}

static void initialize_params_c32_Modified(SFc32_ModifiedInstanceStruct
  *chartInstance)
{
  const mxArray *c32_m0 = NULL;
  const mxArray *c32_mxField;
  const mxArray *c32_m1 = NULL;
  const mxArray *c32_b_mxField;
  c32_struct_iBlsPBO3AGnt69vDoTx5zD c32_r0;
  const mxArray *c32_m2 = NULL;
  const mxArray *c32_c_mxField;
  const mxArray *c32_m3 = NULL;
  const mxArray *c32_d_mxField;
  const mxArray *c32_m4 = NULL;
  const mxArray *c32_e_mxField;
  const mxArray *c32_m5 = NULL;
  const mxArray *c32_f_mxField;
  const mxArray *c32_m6 = NULL;
  const mxArray *c32_g_mxField;
  const mxArray *c32_m7 = NULL;
  const mxArray *c32_h_mxField;
  const mxArray *c32_m8 = NULL;
  const mxArray *c32_i_mxField;
  const mxArray *c32_m9 = NULL;
  const mxArray *c32_j_mxField;
  const mxArray *c32_m10 = NULL;
  const mxArray *c32_k_mxField;
  const mxArray *c32_m11 = NULL;
  const mxArray *c32_l_mxField;
  const mxArray *c32_m12 = NULL;
  const mxArray *c32_m_mxField;
  const mxArray *c32_m13 = NULL;
  const mxArray *c32_n_mxField;
  c32_m0 = sf_mex_get_sfun_param(chartInstance->S, 0, 1);
  c32_mxField = sf_mex_getfield(c32_m0, "Env", "Par", 0);
  c32_m1 = sf_mex_dup(c32_mxField);
  c32_b_mxField = sf_mex_getfield(c32_m1, "g", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_b_mxField), &c32_r0.Env.g, 1, 0, 0U,
                      0, 0U, 0);
  c32_b_mxField = sf_mex_getfield(c32_m1, "left1", "Par", 0);
  c32_m2 = sf_mex_dup(c32_b_mxField);
  c32_c_mxField = sf_mex_getfield(c32_m2, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_c_mxField), &c32_r0.Env.left1.x, 1,
                      0, 0U, 0, 0U, 0);
  c32_c_mxField = sf_mex_getfield(c32_m2, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_c_mxField), &c32_r0.Env.left1.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c32_m2);
  c32_b_mxField = sf_mex_getfield(c32_m1, "right1", "Par", 0);
  c32_m3 = sf_mex_dup(c32_b_mxField);
  c32_d_mxField = sf_mex_getfield(c32_m3, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_d_mxField), &c32_r0.Env.right1.x, 1,
                      0, 0U, 0, 0U, 0);
  c32_d_mxField = sf_mex_getfield(c32_m3, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_d_mxField), &c32_r0.Env.right1.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c32_m3);
  c32_b_mxField = sf_mex_getfield(c32_m1, "right2", "Par", 0);
  c32_m4 = sf_mex_dup(c32_b_mxField);
  c32_e_mxField = sf_mex_getfield(c32_m4, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_e_mxField), &c32_r0.Env.right2.x, 1,
                      0, 0U, 0, 0U, 0);
  c32_e_mxField = sf_mex_getfield(c32_m4, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_e_mxField), &c32_r0.Env.right2.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c32_m4);
  c32_b_mxField = sf_mex_getfield(c32_m1, "left2", "Par", 0);
  c32_m5 = sf_mex_dup(c32_b_mxField);
  c32_f_mxField = sf_mex_getfield(c32_m5, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_f_mxField), &c32_r0.Env.left2.x, 1,
                      0, 0U, 0, 0U, 0);
  c32_f_mxField = sf_mex_getfield(c32_m5, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_f_mxField), &c32_r0.Env.left2.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c32_m5);
  c32_b_mxField = sf_mex_getfield(c32_m1, "right3", "Par", 0);
  c32_m6 = sf_mex_dup(c32_b_mxField);
  c32_g_mxField = sf_mex_getfield(c32_m6, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_g_mxField), &c32_r0.Env.right3.x, 1,
                      0, 0U, 0, 0U, 0);
  c32_g_mxField = sf_mex_getfield(c32_m6, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_g_mxField), &c32_r0.Env.right3.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c32_m6);
  c32_b_mxField = sf_mex_getfield(c32_m1, "mu", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_b_mxField), &c32_r0.Env.mu, 1, 0, 0U,
                      0, 0U, 0);
  sf_mex_destroy(&c32_m1);
  c32_mxField = sf_mex_getfield(c32_m0, "Veh", "Par", 0);
  c32_m7 = sf_mex_dup(c32_mxField);
  c32_h_mxField = sf_mex_getfield(c32_m7, "m", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_h_mxField), &c32_r0.Veh.m, 1, 0, 0U,
                      0, 0U, 0);
  c32_h_mxField = sf_mex_getfield(c32_m7, "Jz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_h_mxField), &c32_r0.Veh.Jz, 1, 0, 0U,
                      0, 0U, 0);
  c32_h_mxField = sf_mex_getfield(c32_m7, "m_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_h_mxField), &c32_r0.Veh.m_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c32_h_mxField = sf_mex_getfield(c32_m7, "Jx_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_h_mxField), &c32_r0.Veh.Jx_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c32_h_mxField = sf_mex_getfield(c32_m7, "Jy_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_h_mxField), &c32_r0.Veh.Jy_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c32_h_mxField = sf_mex_getfield(c32_m7, "lf", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_h_mxField), &c32_r0.Veh.lf, 1, 0, 0U,
                      0, 0U, 0);
  c32_h_mxField = sf_mex_getfield(c32_m7, "lr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_h_mxField), &c32_r0.Veh.lr, 1, 0, 0U,
                      0, 0U, 0);
  c32_h_mxField = sf_mex_getfield(c32_m7, "L", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_h_mxField), &c32_r0.Veh.L, 1, 0, 0U,
                      0, 0U, 0);
  c32_h_mxField = sf_mex_getfield(c32_m7, "TrackWidth", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_h_mxField), &c32_r0.Veh.TrackWidth,
                      1, 0, 0U, 0, 0U, 0);
  c32_h_mxField = sf_mex_getfield(c32_m7, "h", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_h_mxField), &c32_r0.Veh.h, 1, 0, 0U,
                      0, 0U, 0);
  c32_h_mxField = sf_mex_getfield(c32_m7, "HalfRohACd", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_h_mxField), &c32_r0.Veh.HalfRohACd,
                      1, 0, 0U, 0, 0U, 0);
  c32_h_mxField = sf_mex_getfield(c32_m7, "F_z4_static", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_h_mxField), c32_r0.Veh.F_z4_static,
                      1, 0, 0U, 1, 0U, 2, 1, 4);
  c32_h_mxField = sf_mex_getfield(c32_m7, "Rw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_h_mxField), &c32_r0.Veh.Rw, 1, 0, 0U,
                      0, 0U, 0);
  c32_h_mxField = sf_mex_getfield(c32_m7, "r_long", "Par", 0);
  c32_m8 = sf_mex_dup(c32_h_mxField);
  c32_i_mxField = sf_mex_getfield(c32_m8, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_i_mxField), c32_r0.Veh.r_long.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c32_i_mxField = sf_mex_getfield(c32_m8, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_i_mxField), c32_r0.Veh.r_long.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c32_i_mxField = sf_mex_getfield(c32_m8, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_i_mxField), c32_r0.Veh.r_long.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c32_i_mxField = sf_mex_getfield(c32_m8, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_i_mxField), c32_r0.Veh.r_long.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c32_m8);
  c32_h_mxField = sf_mex_getfield(c32_m7, "r_lat", "Par", 0);
  c32_m9 = sf_mex_dup(c32_h_mxField);
  c32_j_mxField = sf_mex_getfield(c32_m9, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_j_mxField), c32_r0.Veh.r_lat.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c32_j_mxField = sf_mex_getfield(c32_m9, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_j_mxField), c32_r0.Veh.r_lat.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c32_j_mxField = sf_mex_getfield(c32_m9, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_j_mxField), c32_r0.Veh.r_lat.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c32_j_mxField = sf_mex_getfield(c32_m9, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_j_mxField), c32_r0.Veh.r_lat.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c32_m9);
  c32_h_mxField = sf_mex_getfield(c32_m7, "r_lever", "Par", 0);
  c32_m10 = sf_mex_dup(c32_h_mxField);
  c32_k_mxField = sf_mex_getfield(c32_m10, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_k_mxField), c32_r0.Veh.r_lever.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c32_k_mxField = sf_mex_getfield(c32_m10, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_k_mxField), c32_r0.Veh.r_lever.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c32_k_mxField = sf_mex_getfield(c32_m10, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_k_mxField), c32_r0.Veh.r_lever.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c32_k_mxField = sf_mex_getfield(c32_m10, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_k_mxField), c32_r0.Veh.r_lever.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c32_m10);
  c32_h_mxField = sf_mex_getfield(c32_m7, "r_pivot", "Par", 0);
  c32_m11 = sf_mex_dup(c32_h_mxField);
  c32_l_mxField = sf_mex_getfield(c32_m11, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_l_mxField), c32_r0.Veh.r_pivot.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c32_l_mxField = sf_mex_getfield(c32_m11, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_l_mxField), c32_r0.Veh.r_pivot.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c32_l_mxField = sf_mex_getfield(c32_m11, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_l_mxField), c32_r0.Veh.r_pivot.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c32_l_mxField = sf_mex_getfield(c32_m11, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_l_mxField), c32_r0.Veh.r_pivot.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c32_m11);
  c32_h_mxField = sf_mex_getfield(c32_m7, "cw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_h_mxField), &c32_r0.Veh.cw, 1, 0, 0U,
                      0, 0U, 0);
  c32_h_mxField = sf_mex_getfield(c32_m7, "carb_f", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_h_mxField), &c32_r0.Veh.carb_f, 1, 0,
                      0U, 0, 0U, 0);
  c32_h_mxField = sf_mex_getfield(c32_m7, "carb_r", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_h_mxField), &c32_r0.Veh.carb_r, 1, 0,
                      0U, 0, 0U, 0);
  c32_h_mxField = sf_mex_getfield(c32_m7, "dw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_h_mxField), &c32_r0.Veh.dw, 1, 0, 0U,
                      0, 0U, 0);
  c32_h_mxField = sf_mex_getfield(c32_m7, "Jw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_h_mxField), &c32_r0.Veh.Jw, 1, 0, 0U,
                      0, 0U, 0);
  c32_h_mxField = sf_mex_getfield(c32_m7, "C0", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_h_mxField), &c32_r0.Veh.C0, 1, 0, 0U,
                      0, 0U, 0);
  c32_h_mxField = sf_mex_getfield(c32_m7, "RelaxLength", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_h_mxField), &c32_r0.Veh.RelaxLength,
                      1, 0, 0U, 0, 0U, 0);
  c32_h_mxField = sf_mex_getfield(c32_m7, "RRC", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_h_mxField), &c32_r0.Veh.RRC, 1, 0,
                      0U, 0, 0U, 0);
  c32_h_mxField = sf_mex_getfield(c32_m7, "Pmax", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_h_mxField), &c32_r0.Veh.Pmax, 1, 0,
                      0U, 0, 0U, 0);
  c32_h_mxField = sf_mex_getfield(c32_m7, "PropDistrFrnt", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_h_mxField),
                      &c32_r0.Veh.PropDistrFrnt, 1, 0, 0U, 0, 0U, 0);
  c32_h_mxField = sf_mex_getfield(c32_m7, "BrkDistrFrnt", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_h_mxField), &c32_r0.Veh.BrkDistrFrnt,
                      1, 0, 0U, 0, 0U, 0);
  c32_h_mxField = sf_mex_getfield(c32_m7, "SteRatio", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_h_mxField), &c32_r0.Veh.SteRatio, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c32_m7);
  c32_mxField = sf_mex_getfield(c32_m0, "Drvr", "Par", 0);
  c32_m12 = sf_mex_dup(c32_mxField);
  c32_m_mxField = sf_mex_getfield(c32_m12, "v_set", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_m_mxField), &c32_r0.Drvr.v_set, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c32_m12);
  c32_mxField = sf_mex_getfield(c32_m0, "Init", "Par", 0);
  c32_m13 = sf_mex_dup(c32_mxField);
  c32_n_mxField = sf_mex_getfield(c32_m13, "v_x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_n_mxField), &c32_r0.Init.v_x, 1, 0,
                      0U, 0, 0U, 0);
  c32_n_mxField = sf_mex_getfield(c32_m13, "F_fz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_n_mxField), &c32_r0.Init.F_fz, 1, 0,
                      0U, 0, 0U, 0);
  c32_n_mxField = sf_mex_getfield(c32_m13, "F_rz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c32_n_mxField), &c32_r0.Init.F_rz, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c32_m13);
  sf_mex_destroy(&c32_m0);
  chartInstance->c32_Par = c32_r0;
}

static void enable_c32_Modified(SFc32_ModifiedInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c32_Modified(SFc32_ModifiedInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c32_update_debugger_state_c32_Modified(SFc32_ModifiedInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c32_Modified(SFc32_ModifiedInstanceStruct
  *chartInstance)
{
  const mxArray *c32_st;
  const mxArray *c32_y = NULL;
  const mxArray *c32_b_y = NULL;
  real_T c32_u;
  const mxArray *c32_c_y = NULL;
  real_T c32_b_u;
  const mxArray *c32_d_y = NULL;
  real_T c32_c_u;
  const mxArray *c32_e_y = NULL;
  real_T c32_d_u;
  const mxArray *c32_f_y = NULL;
  uint8_T c32_hoistedGlobal;
  uint8_T c32_e_u;
  const mxArray *c32_g_y = NULL;
  c32_st = NULL;
  c32_st = NULL;
  c32_y = NULL;
  sf_mex_assign(&c32_y, sf_mex_createcellmatrix(2, 1), false);
  c32_b_y = NULL;
  sf_mex_assign(&c32_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c32_u = *(real_T *)&((char_T *)chartInstance->c32_derw_w4)[0];
  c32_c_y = NULL;
  sf_mex_assign(&c32_c_y, sf_mex_create("y", &c32_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c32_b_y, c32_c_y, "fl", "fl", 0);
  c32_b_u = *(real_T *)&((char_T *)chartInstance->c32_derw_w4)[8];
  c32_d_y = NULL;
  sf_mex_assign(&c32_d_y, sf_mex_create("y", &c32_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c32_b_y, c32_d_y, "fr", "fr", 0);
  c32_c_u = *(real_T *)&((char_T *)chartInstance->c32_derw_w4)[16];
  c32_e_y = NULL;
  sf_mex_assign(&c32_e_y, sf_mex_create("y", &c32_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c32_b_y, c32_e_y, "rl", "rl", 0);
  c32_d_u = *(real_T *)&((char_T *)chartInstance->c32_derw_w4)[24];
  c32_f_y = NULL;
  sf_mex_assign(&c32_f_y, sf_mex_create("y", &c32_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c32_b_y, c32_f_y, "rr", "rr", 0);
  sf_mex_setcell(c32_y, 0, c32_b_y);
  c32_hoistedGlobal = chartInstance->c32_is_active_c32_Modified;
  c32_e_u = c32_hoistedGlobal;
  c32_g_y = NULL;
  sf_mex_assign(&c32_g_y, sf_mex_create("y", &c32_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c32_y, 1, c32_g_y);
  sf_mex_assign(&c32_st, c32_y, false);
  return c32_st;
}

static void set_sim_state_c32_Modified(SFc32_ModifiedInstanceStruct
  *chartInstance, const mxArray *c32_st)
{
  const mxArray *c32_u;
  c32_whl_vec4 c32_r1;
  chartInstance->c32_doneDoubleBufferReInit = true;
  c32_u = sf_mex_dup(c32_st);
  c32_r1 = c32_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c32_u,
    0)), "derw_w4");
  *(real_T *)&((char_T *)chartInstance->c32_derw_w4)[0] = c32_r1.fl;
  *(real_T *)&((char_T *)chartInstance->c32_derw_w4)[8] = c32_r1.fr;
  *(real_T *)&((char_T *)chartInstance->c32_derw_w4)[16] = c32_r1.rl;
  *(real_T *)&((char_T *)chartInstance->c32_derw_w4)[24] = c32_r1.rr;
  chartInstance->c32_is_active_c32_Modified = c32_n_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c32_u, 1)),
     "is_active_c32_Modified");
  sf_mex_destroy(&c32_u);
  c32_update_debugger_state_c32_Modified(chartInstance);
  sf_mex_destroy(&c32_st);
}

static void finalize_c32_Modified(SFc32_ModifiedInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c32_Modified(SFc32_ModifiedInstanceStruct *chartInstance)
{
  c32_whl_vec4 c32_b_T_s4;
  c32_whl_vec4 c32_b_T_us4;
  c32_whl_vec4 c32_b_F_xv4;
  c32_whl_vec4 c32_b_F_yv4;
  c32_whl_vec4 c32_b_F_z4;
  c32_whl_vec4 c32_b_w_w4;
  c32_struct_iBlsPBO3AGnt69vDoTx5zD c32_b_Par;
  uint32_T c32_debug_family_var_map[11];
  real_T c32_Jw;
  real_T c32_nargin = 7.0;
  real_T c32_nargout = 1.0;
  c32_whl_vec4 c32_b_derw_w4;
  real_T c32_x;
  real_T c32_b_x;
  real_T c32_A;
  real_T c32_B;
  real_T c32_c_x;
  real_T c32_y;
  real_T c32_d_x;
  real_T c32_b_y;
  real_T c32_e_x;
  real_T c32_c_y;
  real_T c32_d_y;
  real_T c32_f_x;
  real_T c32_g_x;
  real_T c32_b_A;
  real_T c32_b_B;
  real_T c32_h_x;
  real_T c32_e_y;
  real_T c32_i_x;
  real_T c32_f_y;
  real_T c32_j_x;
  real_T c32_g_y;
  real_T c32_h_y;
  real_T c32_k_x;
  real_T c32_l_x;
  real_T c32_c_A;
  real_T c32_c_B;
  real_T c32_m_x;
  real_T c32_i_y;
  real_T c32_n_x;
  real_T c32_j_y;
  real_T c32_o_x;
  real_T c32_k_y;
  real_T c32_l_y;
  real_T c32_p_x;
  real_T c32_q_x;
  real_T c32_d_A;
  real_T c32_d_B;
  real_T c32_r_x;
  real_T c32_m_y;
  real_T c32_s_x;
  real_T c32_n_y;
  real_T c32_t_x;
  real_T c32_o_y;
  real_T c32_p_y;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 31U, chartInstance->c32_sfEvent);
  chartInstance->c32_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 31U, chartInstance->c32_sfEvent);
  c32_b_T_s4.fl = *(real_T *)&((char_T *)chartInstance->c32_T_s4)[0];
  c32_b_T_s4.fr = *(real_T *)&((char_T *)chartInstance->c32_T_s4)[8];
  c32_b_T_s4.rl = *(real_T *)&((char_T *)chartInstance->c32_T_s4)[16];
  c32_b_T_s4.rr = *(real_T *)&((char_T *)chartInstance->c32_T_s4)[24];
  c32_b_T_us4.fl = *(real_T *)&((char_T *)chartInstance->c32_T_us4)[0];
  c32_b_T_us4.fr = *(real_T *)&((char_T *)chartInstance->c32_T_us4)[8];
  c32_b_T_us4.rl = *(real_T *)&((char_T *)chartInstance->c32_T_us4)[16];
  c32_b_T_us4.rr = *(real_T *)&((char_T *)chartInstance->c32_T_us4)[24];
  c32_b_F_xv4.fl = *(real_T *)&((char_T *)chartInstance->c32_F_xv4)[0];
  c32_b_F_xv4.fr = *(real_T *)&((char_T *)chartInstance->c32_F_xv4)[8];
  c32_b_F_xv4.rl = *(real_T *)&((char_T *)chartInstance->c32_F_xv4)[16];
  c32_b_F_xv4.rr = *(real_T *)&((char_T *)chartInstance->c32_F_xv4)[24];
  c32_b_F_yv4.fl = *(real_T *)&((char_T *)chartInstance->c32_F_yv4)[0];
  c32_b_F_yv4.fr = *(real_T *)&((char_T *)chartInstance->c32_F_yv4)[8];
  c32_b_F_yv4.rl = *(real_T *)&((char_T *)chartInstance->c32_F_yv4)[16];
  c32_b_F_yv4.rr = *(real_T *)&((char_T *)chartInstance->c32_F_yv4)[24];
  c32_b_F_z4.fl = *(real_T *)&((char_T *)chartInstance->c32_F_z4)[0];
  c32_b_F_z4.fr = *(real_T *)&((char_T *)chartInstance->c32_F_z4)[8];
  c32_b_F_z4.rl = *(real_T *)&((char_T *)chartInstance->c32_F_z4)[16];
  c32_b_F_z4.rr = *(real_T *)&((char_T *)chartInstance->c32_F_z4)[24];
  c32_b_w_w4.fl = *(real_T *)&((char_T *)chartInstance->c32_w_w4)[0];
  c32_b_w_w4.fr = *(real_T *)&((char_T *)chartInstance->c32_w_w4)[8];
  c32_b_w_w4.rl = *(real_T *)&((char_T *)chartInstance->c32_w_w4)[16];
  c32_b_w_w4.rr = *(real_T *)&((char_T *)chartInstance->c32_w_w4)[24];
  c32_b_Par = chartInstance->c32_Par;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 11U, 11U, c32_debug_family_names,
    c32_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c32_Jw, 0U, c32_c_sf_marshallOut,
    c32_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c32_nargin, 1U, c32_c_sf_marshallOut,
    c32_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c32_nargout, 2U, c32_c_sf_marshallOut,
    c32_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c32_b_T_s4, 3U, c32_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c32_b_T_us4, 4U, c32_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c32_b_F_xv4, 5U, c32_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c32_b_F_yv4, 6U, c32_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c32_b_F_z4, 7U, c32_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c32_b_w_w4, 8U, c32_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c32_b_Par, 9U, c32_b_sf_marshallOut,
    c32_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c32_b_derw_w4, 10U, c32_sf_marshallOut,
    c32_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c32_sfEvent, 5);
  c32_Jw = c32_b_Par.Veh.Jw;
  _SFD_EML_CALL(0U, chartInstance->c32_sfEvent, 7);
  c32_x = c32_b_w_w4.fl;
  c32_b_x = c32_x;
  c32_b_x = muDoubleScalarSign(c32_b_x);
  c32_A = ((c32_b_T_us4.fl + c32_b_T_s4.fl) - c32_b_F_xv4.fl * c32_b_Par.Veh.Rw)
    - c32_b_x * c32_b_F_z4.fl * c32_b_Par.Veh.RRC * c32_b_Par.Veh.Rw;
  c32_B = c32_Jw;
  c32_c_x = c32_A;
  c32_y = c32_B;
  c32_d_x = c32_c_x;
  c32_b_y = c32_y;
  c32_e_x = c32_d_x;
  c32_c_y = c32_b_y;
  c32_d_y = c32_e_x / c32_c_y;
  c32_b_derw_w4.fl = c32_d_y;
  _SFD_EML_CALL(0U, chartInstance->c32_sfEvent, 8);
  c32_f_x = c32_b_w_w4.fr;
  c32_g_x = c32_f_x;
  c32_g_x = muDoubleScalarSign(c32_g_x);
  c32_b_A = ((c32_b_T_us4.fr + c32_b_T_s4.fr) - c32_b_F_xv4.fr *
             c32_b_Par.Veh.Rw) - c32_g_x * c32_b_F_z4.fr * c32_b_Par.Veh.RRC *
    c32_b_Par.Veh.Rw;
  c32_b_B = c32_Jw;
  c32_h_x = c32_b_A;
  c32_e_y = c32_b_B;
  c32_i_x = c32_h_x;
  c32_f_y = c32_e_y;
  c32_j_x = c32_i_x;
  c32_g_y = c32_f_y;
  c32_h_y = c32_j_x / c32_g_y;
  c32_b_derw_w4.fr = c32_h_y;
  _SFD_EML_CALL(0U, chartInstance->c32_sfEvent, 9);
  c32_k_x = c32_b_w_w4.rl;
  c32_l_x = c32_k_x;
  c32_l_x = muDoubleScalarSign(c32_l_x);
  c32_c_A = ((c32_b_T_us4.rl + c32_b_T_s4.rl) - c32_b_F_xv4.rl *
             c32_b_Par.Veh.Rw) - c32_l_x * c32_b_F_z4.rl * c32_b_Par.Veh.RRC *
    c32_b_Par.Veh.Rw;
  c32_c_B = c32_Jw;
  c32_m_x = c32_c_A;
  c32_i_y = c32_c_B;
  c32_n_x = c32_m_x;
  c32_j_y = c32_i_y;
  c32_o_x = c32_n_x;
  c32_k_y = c32_j_y;
  c32_l_y = c32_o_x / c32_k_y;
  c32_b_derw_w4.rl = c32_l_y;
  _SFD_EML_CALL(0U, chartInstance->c32_sfEvent, 10);
  c32_p_x = c32_b_w_w4.rr;
  c32_q_x = c32_p_x;
  c32_q_x = muDoubleScalarSign(c32_q_x);
  c32_d_A = ((c32_b_T_us4.rr + c32_b_T_s4.rr) - c32_b_F_xv4.rr *
             c32_b_Par.Veh.Rw) - c32_q_x * c32_b_F_z4.rr * c32_b_Par.Veh.RRC *
    c32_b_Par.Veh.Rw;
  c32_d_B = c32_Jw;
  c32_r_x = c32_d_A;
  c32_m_y = c32_d_B;
  c32_s_x = c32_r_x;
  c32_n_y = c32_m_y;
  c32_t_x = c32_s_x;
  c32_o_y = c32_n_y;
  c32_p_y = c32_t_x / c32_o_y;
  c32_b_derw_w4.rr = c32_p_y;
  _SFD_EML_CALL(0U, chartInstance->c32_sfEvent, -10);
  _SFD_SYMBOL_SCOPE_POP();
  *(real_T *)&((char_T *)chartInstance->c32_derw_w4)[0] = c32_b_derw_w4.fl;
  *(real_T *)&((char_T *)chartInstance->c32_derw_w4)[8] = c32_b_derw_w4.fr;
  *(real_T *)&((char_T *)chartInstance->c32_derw_w4)[16] = c32_b_derw_w4.rl;
  *(real_T *)&((char_T *)chartInstance->c32_derw_w4)[24] = c32_b_derw_w4.rr;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 31U, chartInstance->c32_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_ModifiedMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c32_Modified(SFc32_ModifiedInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc32_Modified(SFc32_ModifiedInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c32_machineNumber, uint32_T
  c32_chartNumber, uint32_T c32_instanceNumber)
{
  (void)c32_machineNumber;
  (void)c32_chartNumber;
  (void)c32_instanceNumber;
}

static const mxArray *c32_sf_marshallOut(void *chartInstanceVoid, void
  *c32_inData)
{
  const mxArray *c32_mxArrayOutData = NULL;
  c32_whl_vec4 c32_u;
  const mxArray *c32_y = NULL;
  real_T c32_b_u;
  const mxArray *c32_b_y = NULL;
  real_T c32_c_u;
  const mxArray *c32_c_y = NULL;
  real_T c32_d_u;
  const mxArray *c32_d_y = NULL;
  real_T c32_e_u;
  const mxArray *c32_e_y = NULL;
  SFc32_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc32_ModifiedInstanceStruct *)chartInstanceVoid;
  c32_mxArrayOutData = NULL;
  c32_u = *(c32_whl_vec4 *)c32_inData;
  c32_y = NULL;
  sf_mex_assign(&c32_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c32_b_u = c32_u.fl;
  c32_b_y = NULL;
  sf_mex_assign(&c32_b_y, sf_mex_create("y", &c32_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c32_y, c32_b_y, "fl", "fl", 0);
  c32_c_u = c32_u.fr;
  c32_c_y = NULL;
  sf_mex_assign(&c32_c_y, sf_mex_create("y", &c32_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c32_y, c32_c_y, "fr", "fr", 0);
  c32_d_u = c32_u.rl;
  c32_d_y = NULL;
  sf_mex_assign(&c32_d_y, sf_mex_create("y", &c32_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c32_y, c32_d_y, "rl", "rl", 0);
  c32_e_u = c32_u.rr;
  c32_e_y = NULL;
  sf_mex_assign(&c32_e_y, sf_mex_create("y", &c32_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c32_y, c32_e_y, "rr", "rr", 0);
  sf_mex_assign(&c32_mxArrayOutData, c32_y, false);
  return c32_mxArrayOutData;
}

static c32_whl_vec4 c32_emlrt_marshallIn(SFc32_ModifiedInstanceStruct
  *chartInstance, const mxArray *c32_b_derw_w4, const char_T *c32_identifier)
{
  c32_whl_vec4 c32_y;
  emlrtMsgIdentifier c32_thisId;
  c32_thisId.fIdentifier = c32_identifier;
  c32_thisId.fParent = NULL;
  c32_y = c32_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c32_b_derw_w4),
    &c32_thisId);
  sf_mex_destroy(&c32_b_derw_w4);
  return c32_y;
}

static c32_whl_vec4 c32_b_emlrt_marshallIn(SFc32_ModifiedInstanceStruct
  *chartInstance, const mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId)
{
  c32_whl_vec4 c32_y;
  emlrtMsgIdentifier c32_thisId;
  static const char * c32_fieldNames[4] = { "fl", "fr", "rl", "rr" };

  c32_thisId.fParent = c32_parentId;
  sf_mex_check_struct(c32_parentId, c32_u, 4, c32_fieldNames, 0U, NULL);
  c32_thisId.fIdentifier = "fl";
  c32_y.fl = c32_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c32_u, "fl", "fl", 0)), &c32_thisId);
  c32_thisId.fIdentifier = "fr";
  c32_y.fr = c32_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c32_u, "fr", "fr", 0)), &c32_thisId);
  c32_thisId.fIdentifier = "rl";
  c32_y.rl = c32_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c32_u, "rl", "rl", 0)), &c32_thisId);
  c32_thisId.fIdentifier = "rr";
  c32_y.rr = c32_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c32_u, "rr", "rr", 0)), &c32_thisId);
  sf_mex_destroy(&c32_u);
  return c32_y;
}

static real_T c32_c_emlrt_marshallIn(SFc32_ModifiedInstanceStruct *chartInstance,
  const mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId)
{
  real_T c32_y;
  real_T c32_d0;
  (void)chartInstance;
  sf_mex_import(c32_parentId, sf_mex_dup(c32_u), &c32_d0, 1, 0, 0U, 0, 0U, 0);
  c32_y = c32_d0;
  sf_mex_destroy(&c32_u);
  return c32_y;
}

static void c32_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c32_mxArrayInData, const char_T *c32_varName, void *c32_outData)
{
  const mxArray *c32_b_derw_w4;
  const char_T *c32_identifier;
  emlrtMsgIdentifier c32_thisId;
  c32_whl_vec4 c32_y;
  SFc32_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc32_ModifiedInstanceStruct *)chartInstanceVoid;
  c32_b_derw_w4 = sf_mex_dup(c32_mxArrayInData);
  c32_identifier = c32_varName;
  c32_thisId.fIdentifier = c32_identifier;
  c32_thisId.fParent = NULL;
  c32_y = c32_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c32_b_derw_w4),
    &c32_thisId);
  sf_mex_destroy(&c32_b_derw_w4);
  *(c32_whl_vec4 *)c32_outData = c32_y;
  sf_mex_destroy(&c32_mxArrayInData);
}

static const mxArray *c32_b_sf_marshallOut(void *chartInstanceVoid, void
  *c32_inData)
{
  const mxArray *c32_mxArrayOutData;
  c32_struct_iBlsPBO3AGnt69vDoTx5zD c32_u;
  const mxArray *c32_y = NULL;
  c32_struct_Nst2vGTExxHsg85EUOj9EH c32_b_u;
  const mxArray *c32_b_y = NULL;
  real_T c32_c_u;
  const mxArray *c32_c_y = NULL;
  c32_struct_HhckT6rntEraqECYVIDvCC c32_d_u;
  const mxArray *c32_d_y = NULL;
  real_T c32_e_u;
  const mxArray *c32_e_y = NULL;
  real_T c32_f_u;
  const mxArray *c32_f_y = NULL;
  const mxArray *c32_g_y = NULL;
  real_T c32_g_u;
  const mxArray *c32_h_y = NULL;
  real_T c32_h_u;
  const mxArray *c32_i_y = NULL;
  const mxArray *c32_j_y = NULL;
  real_T c32_i_u;
  const mxArray *c32_k_y = NULL;
  real_T c32_j_u;
  const mxArray *c32_l_y = NULL;
  const mxArray *c32_m_y = NULL;
  real_T c32_k_u;
  const mxArray *c32_n_y = NULL;
  real_T c32_l_u;
  const mxArray *c32_o_y = NULL;
  const mxArray *c32_p_y = NULL;
  real_T c32_m_u;
  const mxArray *c32_q_y = NULL;
  real_T c32_n_u;
  const mxArray *c32_r_y = NULL;
  real_T c32_o_u;
  const mxArray *c32_s_y = NULL;
  c32_struct_ZCmOWPuqBDw16FSOVVD00 c32_p_u;
  const mxArray *c32_t_y = NULL;
  real_T c32_q_u;
  const mxArray *c32_u_y = NULL;
  real_T c32_r_u;
  const mxArray *c32_v_y = NULL;
  real_T c32_s_u;
  const mxArray *c32_w_y = NULL;
  real_T c32_t_u;
  const mxArray *c32_x_y = NULL;
  real_T c32_u_u;
  const mxArray *c32_y_y = NULL;
  real_T c32_v_u;
  const mxArray *c32_ab_y = NULL;
  real_T c32_w_u;
  const mxArray *c32_bb_y = NULL;
  real_T c32_x_u;
  const mxArray *c32_cb_y = NULL;
  real_T c32_y_u;
  const mxArray *c32_db_y = NULL;
  real_T c32_ab_u;
  const mxArray *c32_eb_y = NULL;
  real_T c32_bb_u;
  const mxArray *c32_fb_y = NULL;
  int32_T c32_i0;
  real_T c32_cb_u[4];
  const mxArray *c32_gb_y = NULL;
  real_T c32_db_u;
  const mxArray *c32_hb_y = NULL;
  c32_struct_ZKAzdrl7umDGJoC14aoVKC c32_eb_u;
  const mxArray *c32_ib_y = NULL;
  int32_T c32_i1;
  real_T c32_fb_u[3];
  const mxArray *c32_jb_y = NULL;
  int32_T c32_i2;
  real_T c32_gb_u[3];
  const mxArray *c32_kb_y = NULL;
  int32_T c32_i3;
  real_T c32_hb_u[3];
  const mxArray *c32_lb_y = NULL;
  int32_T c32_i4;
  real_T c32_ib_u[3];
  const mxArray *c32_mb_y = NULL;
  const mxArray *c32_nb_y = NULL;
  int32_T c32_i5;
  real_T c32_jb_u[3];
  const mxArray *c32_ob_y = NULL;
  int32_T c32_i6;
  real_T c32_kb_u[3];
  const mxArray *c32_pb_y = NULL;
  int32_T c32_i7;
  real_T c32_lb_u[3];
  const mxArray *c32_qb_y = NULL;
  int32_T c32_i8;
  real_T c32_mb_u[3];
  const mxArray *c32_rb_y = NULL;
  const mxArray *c32_sb_y = NULL;
  int32_T c32_i9;
  real_T c32_nb_u[3];
  const mxArray *c32_tb_y = NULL;
  int32_T c32_i10;
  real_T c32_ob_u[3];
  const mxArray *c32_ub_y = NULL;
  int32_T c32_i11;
  real_T c32_pb_u[3];
  const mxArray *c32_vb_y = NULL;
  int32_T c32_i12;
  real_T c32_qb_u[3];
  const mxArray *c32_wb_y = NULL;
  const mxArray *c32_xb_y = NULL;
  int32_T c32_i13;
  real_T c32_rb_u[3];
  const mxArray *c32_yb_y = NULL;
  int32_T c32_i14;
  real_T c32_sb_u[3];
  const mxArray *c32_ac_y = NULL;
  int32_T c32_i15;
  real_T c32_tb_u[3];
  const mxArray *c32_bc_y = NULL;
  int32_T c32_i16;
  real_T c32_ub_u[3];
  const mxArray *c32_cc_y = NULL;
  real_T c32_vb_u;
  const mxArray *c32_dc_y = NULL;
  real_T c32_wb_u;
  const mxArray *c32_ec_y = NULL;
  real_T c32_xb_u;
  const mxArray *c32_fc_y = NULL;
  real_T c32_yb_u;
  const mxArray *c32_gc_y = NULL;
  real_T c32_ac_u;
  const mxArray *c32_hc_y = NULL;
  real_T c32_bc_u;
  const mxArray *c32_ic_y = NULL;
  real_T c32_cc_u;
  const mxArray *c32_jc_y = NULL;
  real_T c32_dc_u;
  const mxArray *c32_kc_y = NULL;
  real_T c32_ec_u;
  const mxArray *c32_lc_y = NULL;
  real_T c32_fc_u;
  const mxArray *c32_mc_y = NULL;
  real_T c32_gc_u;
  const mxArray *c32_nc_y = NULL;
  real_T c32_hc_u;
  const mxArray *c32_oc_y = NULL;
  c32_struct_r4FNviKwHfdhB8nQjvQv9 c32_ic_u;
  const mxArray *c32_pc_y = NULL;
  real_T c32_jc_u;
  const mxArray *c32_qc_y = NULL;
  c32_struct_Y9F1qlBi9AhssksPwemA4G c32_kc_u;
  const mxArray *c32_rc_y = NULL;
  real_T c32_lc_u;
  const mxArray *c32_sc_y = NULL;
  real_T c32_mc_u;
  const mxArray *c32_tc_y = NULL;
  real_T c32_nc_u;
  const mxArray *c32_uc_y = NULL;
  SFc32_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc32_ModifiedInstanceStruct *)chartInstanceVoid;
  c32_mxArrayOutData = NULL;
  c32_mxArrayOutData = NULL;
  c32_u = *(c32_struct_iBlsPBO3AGnt69vDoTx5zD *)c32_inData;
  c32_y = NULL;
  sf_mex_assign(&c32_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c32_b_u = c32_u.Env;
  c32_b_y = NULL;
  sf_mex_assign(&c32_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c32_c_u = c32_b_u.g;
  c32_c_y = NULL;
  sf_mex_assign(&c32_c_y, sf_mex_create("y", &c32_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c32_b_y, c32_c_y, "g", "g", 0);
  c32_d_u = c32_b_u.left1;
  c32_d_y = NULL;
  sf_mex_assign(&c32_d_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c32_e_u = c32_d_u.x;
  c32_e_y = NULL;
  sf_mex_assign(&c32_e_y, sf_mex_create("y", &c32_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c32_d_y, c32_e_y, "x", "x", 0);
  c32_f_u = c32_d_u.y;
  c32_f_y = NULL;
  sf_mex_assign(&c32_f_y, sf_mex_create("y", &c32_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c32_d_y, c32_f_y, "y", "y", 0);
  sf_mex_addfield(c32_b_y, c32_d_y, "left1", "left1", 0);
  c32_d_u = c32_b_u.right1;
  c32_g_y = NULL;
  sf_mex_assign(&c32_g_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c32_g_u = c32_d_u.x;
  c32_h_y = NULL;
  sf_mex_assign(&c32_h_y, sf_mex_create("y", &c32_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c32_g_y, c32_h_y, "x", "x", 0);
  c32_h_u = c32_d_u.y;
  c32_i_y = NULL;
  sf_mex_assign(&c32_i_y, sf_mex_create("y", &c32_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c32_g_y, c32_i_y, "y", "y", 0);
  sf_mex_addfield(c32_b_y, c32_g_y, "right1", "right1", 0);
  c32_d_u = c32_b_u.right2;
  c32_j_y = NULL;
  sf_mex_assign(&c32_j_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c32_i_u = c32_d_u.x;
  c32_k_y = NULL;
  sf_mex_assign(&c32_k_y, sf_mex_create("y", &c32_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c32_j_y, c32_k_y, "x", "x", 0);
  c32_j_u = c32_d_u.y;
  c32_l_y = NULL;
  sf_mex_assign(&c32_l_y, sf_mex_create("y", &c32_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c32_j_y, c32_l_y, "y", "y", 0);
  sf_mex_addfield(c32_b_y, c32_j_y, "right2", "right2", 0);
  c32_d_u = c32_b_u.left2;
  c32_m_y = NULL;
  sf_mex_assign(&c32_m_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c32_k_u = c32_d_u.x;
  c32_n_y = NULL;
  sf_mex_assign(&c32_n_y, sf_mex_create("y", &c32_k_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c32_m_y, c32_n_y, "x", "x", 0);
  c32_l_u = c32_d_u.y;
  c32_o_y = NULL;
  sf_mex_assign(&c32_o_y, sf_mex_create("y", &c32_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c32_m_y, c32_o_y, "y", "y", 0);
  sf_mex_addfield(c32_b_y, c32_m_y, "left2", "left2", 0);
  c32_d_u = c32_b_u.right3;
  c32_p_y = NULL;
  sf_mex_assign(&c32_p_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c32_m_u = c32_d_u.x;
  c32_q_y = NULL;
  sf_mex_assign(&c32_q_y, sf_mex_create("y", &c32_m_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c32_p_y, c32_q_y, "x", "x", 0);
  c32_n_u = c32_d_u.y;
  c32_r_y = NULL;
  sf_mex_assign(&c32_r_y, sf_mex_create("y", &c32_n_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c32_p_y, c32_r_y, "y", "y", 0);
  sf_mex_addfield(c32_b_y, c32_p_y, "right3", "right3", 0);
  c32_o_u = c32_b_u.mu;
  c32_s_y = NULL;
  sf_mex_assign(&c32_s_y, sf_mex_create("y", &c32_o_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c32_b_y, c32_s_y, "mu", "mu", 0);
  sf_mex_addfield(c32_y, c32_b_y, "Env", "Env", 0);
  c32_p_u = c32_u.Veh;
  c32_t_y = NULL;
  sf_mex_assign(&c32_t_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c32_q_u = c32_p_u.m;
  c32_u_y = NULL;
  sf_mex_assign(&c32_u_y, sf_mex_create("y", &c32_q_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c32_t_y, c32_u_y, "m", "m", 0);
  c32_r_u = c32_p_u.Jz;
  c32_v_y = NULL;
  sf_mex_assign(&c32_v_y, sf_mex_create("y", &c32_r_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c32_t_y, c32_v_y, "Jz", "Jz", 0);
  c32_s_u = c32_p_u.m_sprung;
  c32_w_y = NULL;
  sf_mex_assign(&c32_w_y, sf_mex_create("y", &c32_s_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c32_t_y, c32_w_y, "m_sprung", "m_sprung", 0);
  c32_t_u = c32_p_u.Jx_sprung;
  c32_x_y = NULL;
  sf_mex_assign(&c32_x_y, sf_mex_create("y", &c32_t_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c32_t_y, c32_x_y, "Jx_sprung", "Jx_sprung", 0);
  c32_u_u = c32_p_u.Jy_sprung;
  c32_y_y = NULL;
  sf_mex_assign(&c32_y_y, sf_mex_create("y", &c32_u_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c32_t_y, c32_y_y, "Jy_sprung", "Jy_sprung", 0);
  c32_v_u = c32_p_u.lf;
  c32_ab_y = NULL;
  sf_mex_assign(&c32_ab_y, sf_mex_create("y", &c32_v_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c32_t_y, c32_ab_y, "lf", "lf", 0);
  c32_w_u = c32_p_u.lr;
  c32_bb_y = NULL;
  sf_mex_assign(&c32_bb_y, sf_mex_create("y", &c32_w_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c32_t_y, c32_bb_y, "lr", "lr", 0);
  c32_x_u = c32_p_u.L;
  c32_cb_y = NULL;
  sf_mex_assign(&c32_cb_y, sf_mex_create("y", &c32_x_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c32_t_y, c32_cb_y, "L", "L", 0);
  c32_y_u = c32_p_u.TrackWidth;
  c32_db_y = NULL;
  sf_mex_assign(&c32_db_y, sf_mex_create("y", &c32_y_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c32_t_y, c32_db_y, "TrackWidth", "TrackWidth", 0);
  c32_ab_u = c32_p_u.h;
  c32_eb_y = NULL;
  sf_mex_assign(&c32_eb_y, sf_mex_create("y", &c32_ab_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c32_t_y, c32_eb_y, "h", "h", 0);
  c32_bb_u = c32_p_u.HalfRohACd;
  c32_fb_y = NULL;
  sf_mex_assign(&c32_fb_y, sf_mex_create("y", &c32_bb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c32_t_y, c32_fb_y, "HalfRohACd", "HalfRohACd", 0);
  for (c32_i0 = 0; c32_i0 < 4; c32_i0++) {
    c32_cb_u[c32_i0] = c32_p_u.F_z4_static[c32_i0];
  }

  c32_gb_y = NULL;
  sf_mex_assign(&c32_gb_y, sf_mex_create("y", c32_cb_u, 0, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_addfield(c32_t_y, c32_gb_y, "F_z4_static", "F_z4_static", 0);
  c32_db_u = c32_p_u.Rw;
  c32_hb_y = NULL;
  sf_mex_assign(&c32_hb_y, sf_mex_create("y", &c32_db_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c32_t_y, c32_hb_y, "Rw", "Rw", 0);
  c32_eb_u = c32_p_u.r_long;
  c32_ib_y = NULL;
  sf_mex_assign(&c32_ib_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c32_i1 = 0; c32_i1 < 3; c32_i1++) {
    c32_fb_u[c32_i1] = c32_eb_u.fl[c32_i1];
  }

  c32_jb_y = NULL;
  sf_mex_assign(&c32_jb_y, sf_mex_create("y", c32_fb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c32_ib_y, c32_jb_y, "fl", "fl", 0);
  for (c32_i2 = 0; c32_i2 < 3; c32_i2++) {
    c32_gb_u[c32_i2] = c32_eb_u.fr[c32_i2];
  }

  c32_kb_y = NULL;
  sf_mex_assign(&c32_kb_y, sf_mex_create("y", c32_gb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c32_ib_y, c32_kb_y, "fr", "fr", 0);
  for (c32_i3 = 0; c32_i3 < 3; c32_i3++) {
    c32_hb_u[c32_i3] = c32_eb_u.rl[c32_i3];
  }

  c32_lb_y = NULL;
  sf_mex_assign(&c32_lb_y, sf_mex_create("y", c32_hb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c32_ib_y, c32_lb_y, "rl", "rl", 0);
  for (c32_i4 = 0; c32_i4 < 3; c32_i4++) {
    c32_ib_u[c32_i4] = c32_eb_u.rr[c32_i4];
  }

  c32_mb_y = NULL;
  sf_mex_assign(&c32_mb_y, sf_mex_create("y", c32_ib_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c32_ib_y, c32_mb_y, "rr", "rr", 0);
  sf_mex_addfield(c32_t_y, c32_ib_y, "r_long", "r_long", 0);
  c32_eb_u = c32_p_u.r_lat;
  c32_nb_y = NULL;
  sf_mex_assign(&c32_nb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c32_i5 = 0; c32_i5 < 3; c32_i5++) {
    c32_jb_u[c32_i5] = c32_eb_u.fl[c32_i5];
  }

  c32_ob_y = NULL;
  sf_mex_assign(&c32_ob_y, sf_mex_create("y", c32_jb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c32_nb_y, c32_ob_y, "fl", "fl", 0);
  for (c32_i6 = 0; c32_i6 < 3; c32_i6++) {
    c32_kb_u[c32_i6] = c32_eb_u.fr[c32_i6];
  }

  c32_pb_y = NULL;
  sf_mex_assign(&c32_pb_y, sf_mex_create("y", c32_kb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c32_nb_y, c32_pb_y, "fr", "fr", 0);
  for (c32_i7 = 0; c32_i7 < 3; c32_i7++) {
    c32_lb_u[c32_i7] = c32_eb_u.rl[c32_i7];
  }

  c32_qb_y = NULL;
  sf_mex_assign(&c32_qb_y, sf_mex_create("y", c32_lb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c32_nb_y, c32_qb_y, "rl", "rl", 0);
  for (c32_i8 = 0; c32_i8 < 3; c32_i8++) {
    c32_mb_u[c32_i8] = c32_eb_u.rr[c32_i8];
  }

  c32_rb_y = NULL;
  sf_mex_assign(&c32_rb_y, sf_mex_create("y", c32_mb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c32_nb_y, c32_rb_y, "rr", "rr", 0);
  sf_mex_addfield(c32_t_y, c32_nb_y, "r_lat", "r_lat", 0);
  c32_eb_u = c32_p_u.r_lever;
  c32_sb_y = NULL;
  sf_mex_assign(&c32_sb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c32_i9 = 0; c32_i9 < 3; c32_i9++) {
    c32_nb_u[c32_i9] = c32_eb_u.fl[c32_i9];
  }

  c32_tb_y = NULL;
  sf_mex_assign(&c32_tb_y, sf_mex_create("y", c32_nb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c32_sb_y, c32_tb_y, "fl", "fl", 0);
  for (c32_i10 = 0; c32_i10 < 3; c32_i10++) {
    c32_ob_u[c32_i10] = c32_eb_u.fr[c32_i10];
  }

  c32_ub_y = NULL;
  sf_mex_assign(&c32_ub_y, sf_mex_create("y", c32_ob_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c32_sb_y, c32_ub_y, "fr", "fr", 0);
  for (c32_i11 = 0; c32_i11 < 3; c32_i11++) {
    c32_pb_u[c32_i11] = c32_eb_u.rl[c32_i11];
  }

  c32_vb_y = NULL;
  sf_mex_assign(&c32_vb_y, sf_mex_create("y", c32_pb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c32_sb_y, c32_vb_y, "rl", "rl", 0);
  for (c32_i12 = 0; c32_i12 < 3; c32_i12++) {
    c32_qb_u[c32_i12] = c32_eb_u.rr[c32_i12];
  }

  c32_wb_y = NULL;
  sf_mex_assign(&c32_wb_y, sf_mex_create("y", c32_qb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c32_sb_y, c32_wb_y, "rr", "rr", 0);
  sf_mex_addfield(c32_t_y, c32_sb_y, "r_lever", "r_lever", 0);
  c32_eb_u = c32_p_u.r_pivot;
  c32_xb_y = NULL;
  sf_mex_assign(&c32_xb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c32_i13 = 0; c32_i13 < 3; c32_i13++) {
    c32_rb_u[c32_i13] = c32_eb_u.fl[c32_i13];
  }

  c32_yb_y = NULL;
  sf_mex_assign(&c32_yb_y, sf_mex_create("y", c32_rb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c32_xb_y, c32_yb_y, "fl", "fl", 0);
  for (c32_i14 = 0; c32_i14 < 3; c32_i14++) {
    c32_sb_u[c32_i14] = c32_eb_u.fr[c32_i14];
  }

  c32_ac_y = NULL;
  sf_mex_assign(&c32_ac_y, sf_mex_create("y", c32_sb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c32_xb_y, c32_ac_y, "fr", "fr", 0);
  for (c32_i15 = 0; c32_i15 < 3; c32_i15++) {
    c32_tb_u[c32_i15] = c32_eb_u.rl[c32_i15];
  }

  c32_bc_y = NULL;
  sf_mex_assign(&c32_bc_y, sf_mex_create("y", c32_tb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c32_xb_y, c32_bc_y, "rl", "rl", 0);
  for (c32_i16 = 0; c32_i16 < 3; c32_i16++) {
    c32_ub_u[c32_i16] = c32_eb_u.rr[c32_i16];
  }

  c32_cc_y = NULL;
  sf_mex_assign(&c32_cc_y, sf_mex_create("y", c32_ub_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c32_xb_y, c32_cc_y, "rr", "rr", 0);
  sf_mex_addfield(c32_t_y, c32_xb_y, "r_pivot", "r_pivot", 0);
  c32_vb_u = c32_p_u.cw;
  c32_dc_y = NULL;
  sf_mex_assign(&c32_dc_y, sf_mex_create("y", &c32_vb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c32_t_y, c32_dc_y, "cw", "cw", 0);
  c32_wb_u = c32_p_u.carb_f;
  c32_ec_y = NULL;
  sf_mex_assign(&c32_ec_y, sf_mex_create("y", &c32_wb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c32_t_y, c32_ec_y, "carb_f", "carb_f", 0);
  c32_xb_u = c32_p_u.carb_r;
  c32_fc_y = NULL;
  sf_mex_assign(&c32_fc_y, sf_mex_create("y", &c32_xb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c32_t_y, c32_fc_y, "carb_r", "carb_r", 0);
  c32_yb_u = c32_p_u.dw;
  c32_gc_y = NULL;
  sf_mex_assign(&c32_gc_y, sf_mex_create("y", &c32_yb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c32_t_y, c32_gc_y, "dw", "dw", 0);
  c32_ac_u = c32_p_u.Jw;
  c32_hc_y = NULL;
  sf_mex_assign(&c32_hc_y, sf_mex_create("y", &c32_ac_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c32_t_y, c32_hc_y, "Jw", "Jw", 0);
  c32_bc_u = c32_p_u.C0;
  c32_ic_y = NULL;
  sf_mex_assign(&c32_ic_y, sf_mex_create("y", &c32_bc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c32_t_y, c32_ic_y, "C0", "C0", 0);
  c32_cc_u = c32_p_u.RelaxLength;
  c32_jc_y = NULL;
  sf_mex_assign(&c32_jc_y, sf_mex_create("y", &c32_cc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c32_t_y, c32_jc_y, "RelaxLength", "RelaxLength", 0);
  c32_dc_u = c32_p_u.RRC;
  c32_kc_y = NULL;
  sf_mex_assign(&c32_kc_y, sf_mex_create("y", &c32_dc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c32_t_y, c32_kc_y, "RRC", "RRC", 0);
  c32_ec_u = c32_p_u.Pmax;
  c32_lc_y = NULL;
  sf_mex_assign(&c32_lc_y, sf_mex_create("y", &c32_ec_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c32_t_y, c32_lc_y, "Pmax", "Pmax", 0);
  c32_fc_u = c32_p_u.PropDistrFrnt;
  c32_mc_y = NULL;
  sf_mex_assign(&c32_mc_y, sf_mex_create("y", &c32_fc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c32_t_y, c32_mc_y, "PropDistrFrnt", "PropDistrFrnt", 0);
  c32_gc_u = c32_p_u.BrkDistrFrnt;
  c32_nc_y = NULL;
  sf_mex_assign(&c32_nc_y, sf_mex_create("y", &c32_gc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c32_t_y, c32_nc_y, "BrkDistrFrnt", "BrkDistrFrnt", 0);
  c32_hc_u = c32_p_u.SteRatio;
  c32_oc_y = NULL;
  sf_mex_assign(&c32_oc_y, sf_mex_create("y", &c32_hc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c32_t_y, c32_oc_y, "SteRatio", "SteRatio", 0);
  sf_mex_addfield(c32_y, c32_t_y, "Veh", "Veh", 0);
  c32_ic_u = c32_u.Drvr;
  c32_pc_y = NULL;
  sf_mex_assign(&c32_pc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c32_jc_u = c32_ic_u.v_set;
  c32_qc_y = NULL;
  sf_mex_assign(&c32_qc_y, sf_mex_create("y", &c32_jc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c32_pc_y, c32_qc_y, "v_set", "v_set", 0);
  sf_mex_addfield(c32_y, c32_pc_y, "Drvr", "Drvr", 0);
  c32_kc_u = c32_u.Init;
  c32_rc_y = NULL;
  sf_mex_assign(&c32_rc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c32_lc_u = c32_kc_u.v_x;
  c32_sc_y = NULL;
  sf_mex_assign(&c32_sc_y, sf_mex_create("y", &c32_lc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c32_rc_y, c32_sc_y, "v_x", "v_x", 0);
  c32_mc_u = c32_kc_u.F_fz;
  c32_tc_y = NULL;
  sf_mex_assign(&c32_tc_y, sf_mex_create("y", &c32_mc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c32_rc_y, c32_tc_y, "F_fz", "F_fz", 0);
  c32_nc_u = c32_kc_u.F_rz;
  c32_uc_y = NULL;
  sf_mex_assign(&c32_uc_y, sf_mex_create("y", &c32_nc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c32_rc_y, c32_uc_y, "F_rz", "F_rz", 0);
  sf_mex_addfield(c32_y, c32_rc_y, "Init", "Init", 0);
  sf_mex_assign(&c32_mxArrayOutData, c32_y, false);
  return c32_mxArrayOutData;
}

static void c32_d_emlrt_marshallIn(SFc32_ModifiedInstanceStruct *chartInstance,
  const mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId,
  c32_struct_iBlsPBO3AGnt69vDoTx5zD *c32_y)
{
  emlrtMsgIdentifier c32_thisId;
  static const char * c32_fieldNames[4] = { "Env", "Veh", "Drvr", "Init" };

  c32_thisId.fParent = c32_parentId;
  sf_mex_check_struct(c32_parentId, c32_u, 4, c32_fieldNames, 0U, NULL);
  c32_thisId.fIdentifier = "Env";
  c32_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c32_u, "Env",
    "Env", 0)), &c32_thisId, &c32_y->Env);
  c32_thisId.fIdentifier = "Veh";
  c32_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c32_u, "Veh",
    "Veh", 0)), &c32_thisId, &c32_y->Veh);
  c32_thisId.fIdentifier = "Drvr";
  c32_y->Drvr = c32_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c32_u, "Drvr", "Drvr", 0)), &c32_thisId);
  c32_thisId.fIdentifier = "Init";
  c32_y->Init = c32_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c32_u, "Init", "Init", 0)), &c32_thisId);
  sf_mex_destroy(&c32_u);
}

static void c32_e_emlrt_marshallIn(SFc32_ModifiedInstanceStruct *chartInstance,
  const mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId,
  c32_struct_Nst2vGTExxHsg85EUOj9EH *c32_y)
{
  emlrtMsgIdentifier c32_thisId;
  static const char * c32_fieldNames[7] = { "g", "left1", "right1", "right2",
    "left2", "right3", "mu" };

  c32_thisId.fParent = c32_parentId;
  sf_mex_check_struct(c32_parentId, c32_u, 7, c32_fieldNames, 0U, NULL);
  c32_thisId.fIdentifier = "g";
  c32_y->g = c32_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c32_u, "g", "g", 0)), &c32_thisId);
  c32_thisId.fIdentifier = "left1";
  c32_y->left1 = c32_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c32_u, "left1", "left1", 0)), &c32_thisId);
  c32_thisId.fIdentifier = "right1";
  c32_y->right1 = c32_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c32_u, "right1", "right1", 0)), &c32_thisId);
  c32_thisId.fIdentifier = "right2";
  c32_y->right2 = c32_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c32_u, "right2", "right2", 0)), &c32_thisId);
  c32_thisId.fIdentifier = "left2";
  c32_y->left2 = c32_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c32_u, "left2", "left2", 0)), &c32_thisId);
  c32_thisId.fIdentifier = "right3";
  c32_y->right3 = c32_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c32_u, "right3", "right3", 0)), &c32_thisId);
  c32_thisId.fIdentifier = "mu";
  c32_y->mu = c32_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c32_u, "mu", "mu", 0)), &c32_thisId);
  sf_mex_destroy(&c32_u);
}

static c32_struct_HhckT6rntEraqECYVIDvCC c32_f_emlrt_marshallIn
  (SFc32_ModifiedInstanceStruct *chartInstance, const mxArray *c32_u, const
   emlrtMsgIdentifier *c32_parentId)
{
  c32_struct_HhckT6rntEraqECYVIDvCC c32_y;
  emlrtMsgIdentifier c32_thisId;
  static const char * c32_fieldNames[2] = { "x", "y" };

  c32_thisId.fParent = c32_parentId;
  sf_mex_check_struct(c32_parentId, c32_u, 2, c32_fieldNames, 0U, NULL);
  c32_thisId.fIdentifier = "x";
  c32_y.x = c32_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c32_u, "x", "x", 0)), &c32_thisId);
  c32_thisId.fIdentifier = "y";
  c32_y.y = c32_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c32_u, "y", "y", 0)), &c32_thisId);
  sf_mex_destroy(&c32_u);
  return c32_y;
}

static void c32_g_emlrt_marshallIn(SFc32_ModifiedInstanceStruct *chartInstance,
  const mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId,
  c32_struct_ZCmOWPuqBDw16FSOVVD00 *c32_y)
{
  emlrtMsgIdentifier c32_thisId;
  static const char * c32_fieldNames[29] = { "m", "Jz", "m_sprung", "Jx_sprung",
    "Jy_sprung", "lf", "lr", "L", "TrackWidth", "h", "HalfRohACd", "F_z4_static",
    "Rw", "r_long", "r_lat", "r_lever", "r_pivot", "cw", "carb_f", "carb_r",
    "dw", "Jw", "C0", "RelaxLength", "RRC", "Pmax", "PropDistrFrnt",
    "BrkDistrFrnt", "SteRatio" };

  c32_thisId.fParent = c32_parentId;
  sf_mex_check_struct(c32_parentId, c32_u, 29, c32_fieldNames, 0U, NULL);
  c32_thisId.fIdentifier = "m";
  c32_y->m = c32_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c32_u, "m", "m", 0)), &c32_thisId);
  c32_thisId.fIdentifier = "Jz";
  c32_y->Jz = c32_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c32_u, "Jz", "Jz", 0)), &c32_thisId);
  c32_thisId.fIdentifier = "m_sprung";
  c32_y->m_sprung = c32_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c32_u, "m_sprung", "m_sprung", 0)), &c32_thisId);
  c32_thisId.fIdentifier = "Jx_sprung";
  c32_y->Jx_sprung = c32_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c32_u, "Jx_sprung", "Jx_sprung", 0)), &c32_thisId);
  c32_thisId.fIdentifier = "Jy_sprung";
  c32_y->Jy_sprung = c32_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c32_u, "Jy_sprung", "Jy_sprung", 0)), &c32_thisId);
  c32_thisId.fIdentifier = "lf";
  c32_y->lf = c32_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c32_u, "lf", "lf", 0)), &c32_thisId);
  c32_thisId.fIdentifier = "lr";
  c32_y->lr = c32_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c32_u, "lr", "lr", 0)), &c32_thisId);
  c32_thisId.fIdentifier = "L";
  c32_y->L = c32_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c32_u, "L", "L", 0)), &c32_thisId);
  c32_thisId.fIdentifier = "TrackWidth";
  c32_y->TrackWidth = c32_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c32_u, "TrackWidth", "TrackWidth", 0)), &c32_thisId);
  c32_thisId.fIdentifier = "h";
  c32_y->h = c32_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c32_u, "h", "h", 0)), &c32_thisId);
  c32_thisId.fIdentifier = "HalfRohACd";
  c32_y->HalfRohACd = c32_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c32_u, "HalfRohACd", "HalfRohACd", 0)), &c32_thisId);
  c32_thisId.fIdentifier = "F_z4_static";
  c32_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c32_u,
    "F_z4_static", "F_z4_static", 0)), &c32_thisId, c32_y->F_z4_static);
  c32_thisId.fIdentifier = "Rw";
  c32_y->Rw = c32_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c32_u, "Rw", "Rw", 0)), &c32_thisId);
  c32_thisId.fIdentifier = "r_long";
  c32_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c32_u,
    "r_long", "r_long", 0)), &c32_thisId, &c32_y->r_long);
  c32_thisId.fIdentifier = "r_lat";
  c32_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c32_u,
    "r_lat", "r_lat", 0)), &c32_thisId, &c32_y->r_lat);
  c32_thisId.fIdentifier = "r_lever";
  c32_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c32_u,
    "r_lever", "r_lever", 0)), &c32_thisId, &c32_y->r_lever);
  c32_thisId.fIdentifier = "r_pivot";
  c32_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c32_u,
    "r_pivot", "r_pivot", 0)), &c32_thisId, &c32_y->r_pivot);
  c32_thisId.fIdentifier = "cw";
  c32_y->cw = c32_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c32_u, "cw", "cw", 0)), &c32_thisId);
  c32_thisId.fIdentifier = "carb_f";
  c32_y->carb_f = c32_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c32_u, "carb_f", "carb_f", 0)), &c32_thisId);
  c32_thisId.fIdentifier = "carb_r";
  c32_y->carb_r = c32_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c32_u, "carb_r", "carb_r", 0)), &c32_thisId);
  c32_thisId.fIdentifier = "dw";
  c32_y->dw = c32_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c32_u, "dw", "dw", 0)), &c32_thisId);
  c32_thisId.fIdentifier = "Jw";
  c32_y->Jw = c32_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c32_u, "Jw", "Jw", 0)), &c32_thisId);
  c32_thisId.fIdentifier = "C0";
  c32_y->C0 = c32_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c32_u, "C0", "C0", 0)), &c32_thisId);
  c32_thisId.fIdentifier = "RelaxLength";
  c32_y->RelaxLength = c32_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c32_u, "RelaxLength", "RelaxLength", 0)), &c32_thisId);
  c32_thisId.fIdentifier = "RRC";
  c32_y->RRC = c32_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c32_u, "RRC", "RRC", 0)), &c32_thisId);
  c32_thisId.fIdentifier = "Pmax";
  c32_y->Pmax = c32_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c32_u, "Pmax", "Pmax", 0)), &c32_thisId);
  c32_thisId.fIdentifier = "PropDistrFrnt";
  c32_y->PropDistrFrnt = c32_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c32_u, "PropDistrFrnt", "PropDistrFrnt", 0)), &c32_thisId);
  c32_thisId.fIdentifier = "BrkDistrFrnt";
  c32_y->BrkDistrFrnt = c32_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c32_u, "BrkDistrFrnt", "BrkDistrFrnt", 0)), &c32_thisId);
  c32_thisId.fIdentifier = "SteRatio";
  c32_y->SteRatio = c32_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c32_u, "SteRatio", "SteRatio", 0)), &c32_thisId);
  sf_mex_destroy(&c32_u);
}

static void c32_h_emlrt_marshallIn(SFc32_ModifiedInstanceStruct *chartInstance,
  const mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId, real_T c32_y[4])
{
  real_T c32_dv0[4];
  int32_T c32_i17;
  (void)chartInstance;
  sf_mex_import(c32_parentId, sf_mex_dup(c32_u), c32_dv0, 1, 0, 0U, 1, 0U, 2, 1,
                4);
  for (c32_i17 = 0; c32_i17 < 4; c32_i17++) {
    c32_y[c32_i17] = c32_dv0[c32_i17];
  }

  sf_mex_destroy(&c32_u);
}

static void c32_i_emlrt_marshallIn(SFc32_ModifiedInstanceStruct *chartInstance,
  const mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId,
  c32_struct_ZKAzdrl7umDGJoC14aoVKC *c32_y)
{
  emlrtMsgIdentifier c32_thisId;
  static const char * c32_fieldNames[4] = { "fl", "fr", "rl", "rr" };

  c32_thisId.fParent = c32_parentId;
  sf_mex_check_struct(c32_parentId, c32_u, 4, c32_fieldNames, 0U, NULL);
  c32_thisId.fIdentifier = "fl";
  c32_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c32_u, "fl",
    "fl", 0)), &c32_thisId, c32_y->fl);
  c32_thisId.fIdentifier = "fr";
  c32_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c32_u, "fr",
    "fr", 0)), &c32_thisId, c32_y->fr);
  c32_thisId.fIdentifier = "rl";
  c32_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c32_u, "rl",
    "rl", 0)), &c32_thisId, c32_y->rl);
  c32_thisId.fIdentifier = "rr";
  c32_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c32_u, "rr",
    "rr", 0)), &c32_thisId, c32_y->rr);
  sf_mex_destroy(&c32_u);
}

static void c32_j_emlrt_marshallIn(SFc32_ModifiedInstanceStruct *chartInstance,
  const mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId, real_T c32_y[3])
{
  real_T c32_dv1[3];
  int32_T c32_i18;
  (void)chartInstance;
  sf_mex_import(c32_parentId, sf_mex_dup(c32_u), c32_dv1, 1, 0, 0U, 1, 0U, 2, 3,
                1);
  for (c32_i18 = 0; c32_i18 < 3; c32_i18++) {
    c32_y[c32_i18] = c32_dv1[c32_i18];
  }

  sf_mex_destroy(&c32_u);
}

static c32_struct_r4FNviKwHfdhB8nQjvQv9 c32_k_emlrt_marshallIn
  (SFc32_ModifiedInstanceStruct *chartInstance, const mxArray *c32_u, const
   emlrtMsgIdentifier *c32_parentId)
{
  c32_struct_r4FNviKwHfdhB8nQjvQv9 c32_y;
  emlrtMsgIdentifier c32_thisId;
  static const char * c32_fieldNames[1] = { "v_set" };

  c32_thisId.fParent = c32_parentId;
  sf_mex_check_struct(c32_parentId, c32_u, 1, c32_fieldNames, 0U, NULL);
  c32_thisId.fIdentifier = "v_set";
  c32_y.v_set = c32_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c32_u, "v_set", "v_set", 0)),
    &c32_thisId);
  sf_mex_destroy(&c32_u);
  return c32_y;
}

static c32_struct_Y9F1qlBi9AhssksPwemA4G c32_l_emlrt_marshallIn
  (SFc32_ModifiedInstanceStruct *chartInstance, const mxArray *c32_u, const
   emlrtMsgIdentifier *c32_parentId)
{
  c32_struct_Y9F1qlBi9AhssksPwemA4G c32_y;
  emlrtMsgIdentifier c32_thisId;
  static const char * c32_fieldNames[3] = { "v_x", "F_fz", "F_rz" };

  c32_thisId.fParent = c32_parentId;
  sf_mex_check_struct(c32_parentId, c32_u, 3, c32_fieldNames, 0U, NULL);
  c32_thisId.fIdentifier = "v_x";
  c32_y.v_x = c32_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c32_u, "v_x", "v_x", 0)), &c32_thisId);
  c32_thisId.fIdentifier = "F_fz";
  c32_y.F_fz = c32_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c32_u, "F_fz", "F_fz", 0)), &c32_thisId);
  c32_thisId.fIdentifier = "F_rz";
  c32_y.F_rz = c32_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c32_u, "F_rz", "F_rz", 0)), &c32_thisId);
  sf_mex_destroy(&c32_u);
  return c32_y;
}

static void c32_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c32_mxArrayInData, const char_T *c32_varName, void *c32_outData)
{
  const mxArray *c32_b_Par;
  const char_T *c32_identifier;
  emlrtMsgIdentifier c32_thisId;
  c32_struct_iBlsPBO3AGnt69vDoTx5zD c32_y;
  SFc32_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc32_ModifiedInstanceStruct *)chartInstanceVoid;
  c32_b_Par = sf_mex_dup(c32_mxArrayInData);
  c32_identifier = c32_varName;
  c32_thisId.fIdentifier = c32_identifier;
  c32_thisId.fParent = NULL;
  c32_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c32_b_Par), &c32_thisId,
    &c32_y);
  sf_mex_destroy(&c32_b_Par);
  *(c32_struct_iBlsPBO3AGnt69vDoTx5zD *)c32_outData = c32_y;
  sf_mex_destroy(&c32_mxArrayInData);
}

static const mxArray *c32_c_sf_marshallOut(void *chartInstanceVoid, void
  *c32_inData)
{
  const mxArray *c32_mxArrayOutData = NULL;
  real_T c32_u;
  const mxArray *c32_y = NULL;
  SFc32_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc32_ModifiedInstanceStruct *)chartInstanceVoid;
  c32_mxArrayOutData = NULL;
  c32_u = *(real_T *)c32_inData;
  c32_y = NULL;
  sf_mex_assign(&c32_y, sf_mex_create("y", &c32_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c32_mxArrayOutData, c32_y, false);
  return c32_mxArrayOutData;
}

static void c32_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c32_mxArrayInData, const char_T *c32_varName, void *c32_outData)
{
  const mxArray *c32_nargout;
  const char_T *c32_identifier;
  emlrtMsgIdentifier c32_thisId;
  real_T c32_y;
  SFc32_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc32_ModifiedInstanceStruct *)chartInstanceVoid;
  c32_nargout = sf_mex_dup(c32_mxArrayInData);
  c32_identifier = c32_varName;
  c32_thisId.fIdentifier = c32_identifier;
  c32_thisId.fParent = NULL;
  c32_y = c32_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c32_nargout),
    &c32_thisId);
  sf_mex_destroy(&c32_nargout);
  *(real_T *)c32_outData = c32_y;
  sf_mex_destroy(&c32_mxArrayInData);
}

const mxArray *sf_c32_Modified_get_eml_resolved_functions_info(void)
{
  const mxArray *c32_nameCaptureInfo = NULL;
  c32_nameCaptureInfo = NULL;
  sf_mex_assign(&c32_nameCaptureInfo, sf_mex_createstruct("structure", 2, 10, 1),
                false);
  c32_info_helper(&c32_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c32_nameCaptureInfo);
  return c32_nameCaptureInfo;
}

static void c32_info_helper(const mxArray **c32_info)
{
  const mxArray *c32_rhs0 = NULL;
  const mxArray *c32_lhs0 = NULL;
  const mxArray *c32_rhs1 = NULL;
  const mxArray *c32_lhs1 = NULL;
  const mxArray *c32_rhs2 = NULL;
  const mxArray *c32_lhs2 = NULL;
  const mxArray *c32_rhs3 = NULL;
  const mxArray *c32_lhs3 = NULL;
  const mxArray *c32_rhs4 = NULL;
  const mxArray *c32_lhs4 = NULL;
  const mxArray *c32_rhs5 = NULL;
  const mxArray *c32_lhs5 = NULL;
  const mxArray *c32_rhs6 = NULL;
  const mxArray *c32_lhs6 = NULL;
  const mxArray *c32_rhs7 = NULL;
  const mxArray *c32_lhs7 = NULL;
  const mxArray *c32_rhs8 = NULL;
  const mxArray *c32_lhs8 = NULL;
  const mxArray *c32_rhs9 = NULL;
  const mxArray *c32_lhs9 = NULL;
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("sign"), "name", "name", 0);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1363713856U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c32_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c32_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c32_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c32_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("eml_scalar_sign"), "name",
                  "name", 2);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sign.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1356541494U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c32_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c32_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(""), "context", "context", 3);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("mrdivide"), "name", "name",
                  3);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1410807648U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1370009886U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c32_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c32_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 4);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 4);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1389717774U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c32_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c32_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 5);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("rdivide"), "name", "name", 5);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1363713880U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c32_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c32_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 6);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c32_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c32_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 7);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c32_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c32_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("eml_div"), "name", "name", 8);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1386423952U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c32_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c32_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 9);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c32_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c32_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs9), "lhs", "lhs",
                  9);
  sf_mex_destroy(&c32_rhs0);
  sf_mex_destroy(&c32_lhs0);
  sf_mex_destroy(&c32_rhs1);
  sf_mex_destroy(&c32_lhs1);
  sf_mex_destroy(&c32_rhs2);
  sf_mex_destroy(&c32_lhs2);
  sf_mex_destroy(&c32_rhs3);
  sf_mex_destroy(&c32_lhs3);
  sf_mex_destroy(&c32_rhs4);
  sf_mex_destroy(&c32_lhs4);
  sf_mex_destroy(&c32_rhs5);
  sf_mex_destroy(&c32_lhs5);
  sf_mex_destroy(&c32_rhs6);
  sf_mex_destroy(&c32_lhs6);
  sf_mex_destroy(&c32_rhs7);
  sf_mex_destroy(&c32_lhs7);
  sf_mex_destroy(&c32_rhs8);
  sf_mex_destroy(&c32_lhs8);
  sf_mex_destroy(&c32_rhs9);
  sf_mex_destroy(&c32_lhs9);
}

static const mxArray *c32_emlrt_marshallOut(const char * c32_u)
{
  const mxArray *c32_y = NULL;
  c32_y = NULL;
  sf_mex_assign(&c32_y, sf_mex_create("y", c32_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c32_u)), false);
  return c32_y;
}

static const mxArray *c32_b_emlrt_marshallOut(const uint32_T c32_u)
{
  const mxArray *c32_y = NULL;
  c32_y = NULL;
  sf_mex_assign(&c32_y, sf_mex_create("y", &c32_u, 7, 0U, 0U, 0U, 0), false);
  return c32_y;
}

static const mxArray *c32_d_sf_marshallOut(void *chartInstanceVoid, void
  *c32_inData)
{
  const mxArray *c32_mxArrayOutData = NULL;
  int32_T c32_u;
  const mxArray *c32_y = NULL;
  SFc32_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc32_ModifiedInstanceStruct *)chartInstanceVoid;
  c32_mxArrayOutData = NULL;
  c32_u = *(int32_T *)c32_inData;
  c32_y = NULL;
  sf_mex_assign(&c32_y, sf_mex_create("y", &c32_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c32_mxArrayOutData, c32_y, false);
  return c32_mxArrayOutData;
}

static int32_T c32_m_emlrt_marshallIn(SFc32_ModifiedInstanceStruct
  *chartInstance, const mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId)
{
  int32_T c32_y;
  int32_T c32_i19;
  (void)chartInstance;
  sf_mex_import(c32_parentId, sf_mex_dup(c32_u), &c32_i19, 1, 6, 0U, 0, 0U, 0);
  c32_y = c32_i19;
  sf_mex_destroy(&c32_u);
  return c32_y;
}

static void c32_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c32_mxArrayInData, const char_T *c32_varName, void *c32_outData)
{
  const mxArray *c32_b_sfEvent;
  const char_T *c32_identifier;
  emlrtMsgIdentifier c32_thisId;
  int32_T c32_y;
  SFc32_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc32_ModifiedInstanceStruct *)chartInstanceVoid;
  c32_b_sfEvent = sf_mex_dup(c32_mxArrayInData);
  c32_identifier = c32_varName;
  c32_thisId.fIdentifier = c32_identifier;
  c32_thisId.fParent = NULL;
  c32_y = c32_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c32_b_sfEvent),
    &c32_thisId);
  sf_mex_destroy(&c32_b_sfEvent);
  *(int32_T *)c32_outData = c32_y;
  sf_mex_destroy(&c32_mxArrayInData);
}

static const mxArray *c32_T_s4_bus_io(void *chartInstanceVoid, void *c32_pData)
{
  const mxArray *c32_mxVal = NULL;
  c32_whl_vec4 c32_tmp;
  SFc32_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc32_ModifiedInstanceStruct *)chartInstanceVoid;
  c32_mxVal = NULL;
  c32_tmp.fl = *(real_T *)&((char_T *)(c32_whl_vec4 *)c32_pData)[0];
  c32_tmp.fr = *(real_T *)&((char_T *)(c32_whl_vec4 *)c32_pData)[8];
  c32_tmp.rl = *(real_T *)&((char_T *)(c32_whl_vec4 *)c32_pData)[16];
  c32_tmp.rr = *(real_T *)&((char_T *)(c32_whl_vec4 *)c32_pData)[24];
  sf_mex_assign(&c32_mxVal, c32_sf_marshallOut(chartInstance, &c32_tmp), false);
  return c32_mxVal;
}

static uint8_T c32_n_emlrt_marshallIn(SFc32_ModifiedInstanceStruct
  *chartInstance, const mxArray *c32_b_is_active_c32_Modified, const char_T
  *c32_identifier)
{
  uint8_T c32_y;
  emlrtMsgIdentifier c32_thisId;
  c32_thisId.fIdentifier = c32_identifier;
  c32_thisId.fParent = NULL;
  c32_y = c32_o_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c32_b_is_active_c32_Modified), &c32_thisId);
  sf_mex_destroy(&c32_b_is_active_c32_Modified);
  return c32_y;
}

static uint8_T c32_o_emlrt_marshallIn(SFc32_ModifiedInstanceStruct
  *chartInstance, const mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId)
{
  uint8_T c32_y;
  uint8_T c32_u0;
  (void)chartInstance;
  sf_mex_import(c32_parentId, sf_mex_dup(c32_u), &c32_u0, 1, 3, 0U, 0, 0U, 0);
  c32_y = c32_u0;
  sf_mex_destroy(&c32_u);
  return c32_y;
}

static void init_dsm_address_info(SFc32_ModifiedInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc32_ModifiedInstanceStruct *chartInstance)
{
  chartInstance->c32_T_s4 = (c32_whl_vec4 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c32_T_us4 = (c32_whl_vec4 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c32_derw_w4 = (c32_whl_vec4 *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c32_F_xv4 = (c32_whl_vec4 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c32_F_yv4 = (c32_whl_vec4 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c32_F_z4 = (c32_whl_vec4 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c32_w_w4 = (c32_whl_vec4 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c32_Modified_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1652723854U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(230350706U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1632871624U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1815351536U);
}

mxArray* sf_c32_Modified_get_post_codegen_info(void);
mxArray *sf_c32_Modified_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("L4WY8Uz3OjKjg0SwXKv0zG");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c32_Modified_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c32_Modified_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c32_Modified_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "incompatibleSymbol", };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 3, infoFields);
  mxArray *fallbackReason = mxCreateString("feature_off");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxArray *fallbackType = mxCreateString("early");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c32_Modified_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c32_Modified_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c32_Modified(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[7],T\"derw_w4\",},{M[8],M[0],T\"is_active_c32_Modified\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c32_Modified_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc32_ModifiedInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc32_ModifiedInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ModifiedMachineNumber_,
           32,
           1,
           1,
           0,
           8,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_ModifiedMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_ModifiedMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _ModifiedMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"T_s4");
          _SFD_SET_DATA_PROPS(1,1,1,0,"T_us4");
          _SFD_SET_DATA_PROPS(2,2,0,1,"derw_w4");
          _SFD_SET_DATA_PROPS(3,1,1,0,"F_xv4");
          _SFD_SET_DATA_PROPS(4,1,1,0,"F_yv4");
          _SFD_SET_DATA_PROPS(5,1,1,0,"F_z4");
          _SFD_SET_DATA_PROPS(6,1,1,0,"w_w4");
          _SFD_SET_DATA_PROPS(7,10,0,0,"Par");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,661);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c32_T_s4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c32_T_s4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c32_T_s4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c32_T_s4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c32_T_s4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c32_T_s4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c32_T_s4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c32_b_sf_marshallOut,(MexInFcnForType)
          c32_b_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c32_T_s4);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c32_T_us4);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c32_derw_w4);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c32_F_xv4);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c32_F_yv4);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c32_F_z4);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c32_w_w4);
        _SFD_SET_DATA_VALUE_PTR(7U, &chartInstance->c32_Par);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _ModifiedMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "eNOzoSQLev7mB2ZCyUgDCC";
}

static void sf_opaque_initialize_c32_Modified(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc32_ModifiedInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c32_Modified((SFc32_ModifiedInstanceStruct*)
    chartInstanceVar);
  initialize_c32_Modified((SFc32_ModifiedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c32_Modified(void *chartInstanceVar)
{
  enable_c32_Modified((SFc32_ModifiedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c32_Modified(void *chartInstanceVar)
{
  disable_c32_Modified((SFc32_ModifiedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c32_Modified(void *chartInstanceVar)
{
  sf_gateway_c32_Modified((SFc32_ModifiedInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c32_Modified(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c32_Modified((SFc32_ModifiedInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c32_Modified(SimStruct* S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c32_Modified((SFc32_ModifiedInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c32_Modified(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc32_ModifiedInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Modified_optimization_info();
    }

    finalize_c32_Modified((SFc32_ModifiedInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc32_Modified((SFc32_ModifiedInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c32_Modified(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    initialize_params_c32_Modified((SFc32_ModifiedInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c32_Modified(SimStruct *S)
{
  /* Actual parameters from chart:
     Par
   */
  const char_T *rtParamNames[] = { "Par" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0],
    sf_get_param_data_type_id(S,0));
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Modified_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      32);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,32,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,32,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,32);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,32,6);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,32,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 6; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,32);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2084893742U));
  ssSetChecksum1(S,(701899271U));
  ssSetChecksum2(S,(1817712654U));
  ssSetChecksum3(S,(1496547664U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c32_Modified(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c32_Modified(SimStruct *S)
{
  SFc32_ModifiedInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc32_ModifiedInstanceStruct *)utMalloc(sizeof
    (SFc32_ModifiedInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc32_ModifiedInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c32_Modified;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c32_Modified;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c32_Modified;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c32_Modified;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c32_Modified;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c32_Modified;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c32_Modified;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c32_Modified;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c32_Modified;
  chartInstance->chartInfo.mdlStart = mdlStart_c32_Modified;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c32_Modified;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  crtInfo->checksum = SF_RUNTIME_INFO_CHECKSUM;
  crtInfo->instanceInfo = (&(chartInstance->chartInfo));
  crtInfo->isJITEnabled = false;
  crtInfo->compiledInfo = NULL;
  ssSetUserData(S,(void *)(crtInfo));  /* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c32_Modified_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c32_Modified(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c32_Modified(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c32_Modified(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c32_Modified_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
