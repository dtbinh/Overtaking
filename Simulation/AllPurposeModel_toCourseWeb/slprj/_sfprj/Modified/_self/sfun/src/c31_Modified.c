/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Modified_sfun.h"
#include "c31_Modified.h"
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
static const char * c31_debug_family_names[9] = { "C0", "mu", "Rw", "nargin",
  "nargout", "s_xy4", "F_z4", "Par", "F_xywSS4" };

/* Function Declarations */
static void initialize_c31_Modified(SFc31_ModifiedInstanceStruct *chartInstance);
static void initialize_params_c31_Modified(SFc31_ModifiedInstanceStruct
  *chartInstance);
static void enable_c31_Modified(SFc31_ModifiedInstanceStruct *chartInstance);
static void disable_c31_Modified(SFc31_ModifiedInstanceStruct *chartInstance);
static void c31_update_debugger_state_c31_Modified(SFc31_ModifiedInstanceStruct *
  chartInstance);
static const mxArray *get_sim_state_c31_Modified(SFc31_ModifiedInstanceStruct
  *chartInstance);
static void set_sim_state_c31_Modified(SFc31_ModifiedInstanceStruct
  *chartInstance, const mxArray *c31_st);
static void finalize_c31_Modified(SFc31_ModifiedInstanceStruct *chartInstance);
static void sf_gateway_c31_Modified(SFc31_ModifiedInstanceStruct *chartInstance);
static void mdl_start_c31_Modified(SFc31_ModifiedInstanceStruct *chartInstance);
static void c31_chartstep_c31_Modified(SFc31_ModifiedInstanceStruct
  *chartInstance);
static void initSimStructsc31_Modified(SFc31_ModifiedInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c31_machineNumber, uint32_T
  c31_chartNumber, uint32_T c31_instanceNumber);
static const mxArray *c31_sf_marshallOut(void *chartInstanceVoid, void
  *c31_inData);
static c31_whl_vec4 c31_emlrt_marshallIn(SFc31_ModifiedInstanceStruct
  *chartInstance, const mxArray *c31_b_F_xywSS4, const char_T *c31_identifier);
static c31_whl_vec4 c31_b_emlrt_marshallIn(SFc31_ModifiedInstanceStruct
  *chartInstance, const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId);
static real_T c31_c_emlrt_marshallIn(SFc31_ModifiedInstanceStruct *chartInstance,
  const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId);
static void c31_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c31_mxArrayInData, const char_T *c31_varName, void *c31_outData);
static const mxArray *c31_b_sf_marshallOut(void *chartInstanceVoid, void
  *c31_inData);
static void c31_d_emlrt_marshallIn(SFc31_ModifiedInstanceStruct *chartInstance,
  const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId,
  c31_struct_iBlsPBO3AGnt69vDoTx5zD *c31_y);
static void c31_e_emlrt_marshallIn(SFc31_ModifiedInstanceStruct *chartInstance,
  const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId,
  c31_struct_Nst2vGTExxHsg85EUOj9EH *c31_y);
static c31_struct_HhckT6rntEraqECYVIDvCC c31_f_emlrt_marshallIn
  (SFc31_ModifiedInstanceStruct *chartInstance, const mxArray *c31_u, const
   emlrtMsgIdentifier *c31_parentId);
static void c31_g_emlrt_marshallIn(SFc31_ModifiedInstanceStruct *chartInstance,
  const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId,
  c31_struct_ZCmOWPuqBDw16FSOVVD00 *c31_y);
static void c31_h_emlrt_marshallIn(SFc31_ModifiedInstanceStruct *chartInstance,
  const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId, real_T c31_y[4]);
static void c31_i_emlrt_marshallIn(SFc31_ModifiedInstanceStruct *chartInstance,
  const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId,
  c31_struct_ZKAzdrl7umDGJoC14aoVKC *c31_y);
static void c31_j_emlrt_marshallIn(SFc31_ModifiedInstanceStruct *chartInstance,
  const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId, real_T c31_y[3]);
static c31_struct_r4FNviKwHfdhB8nQjvQv9 c31_k_emlrt_marshallIn
  (SFc31_ModifiedInstanceStruct *chartInstance, const mxArray *c31_u, const
   emlrtMsgIdentifier *c31_parentId);
static c31_struct_Y9F1qlBi9AhssksPwemA4G c31_l_emlrt_marshallIn
  (SFc31_ModifiedInstanceStruct *chartInstance, const mxArray *c31_u, const
   emlrtMsgIdentifier *c31_parentId);
static void c31_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c31_mxArrayInData, const char_T *c31_varName, void *c31_outData);
static const mxArray *c31_c_sf_marshallOut(void *chartInstanceVoid, void
  *c31_inData);
static void c31_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c31_mxArrayInData, const char_T *c31_varName, void *c31_outData);
static void c31_info_helper(const mxArray **c31_info);
static const mxArray *c31_emlrt_marshallOut(const char * c31_u);
static const mxArray *c31_b_emlrt_marshallOut(const uint32_T c31_u);
static void c31_eml_scalar_eg(SFc31_ModifiedInstanceStruct *chartInstance);
static const mxArray *c31_d_sf_marshallOut(void *chartInstanceVoid, void
  *c31_inData);
static int32_T c31_m_emlrt_marshallIn(SFc31_ModifiedInstanceStruct
  *chartInstance, const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId);
static void c31_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c31_mxArrayInData, const char_T *c31_varName, void *c31_outData);
static const mxArray *c31_s_xy4_bus_io(void *chartInstanceVoid, void *c31_pData);
static uint8_T c31_n_emlrt_marshallIn(SFc31_ModifiedInstanceStruct
  *chartInstance, const mxArray *c31_b_is_active_c31_Modified, const char_T
  *c31_identifier);
static uint8_T c31_o_emlrt_marshallIn(SFc31_ModifiedInstanceStruct
  *chartInstance, const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId);
static void init_dsm_address_info(SFc31_ModifiedInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc31_ModifiedInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c31_Modified(SFc31_ModifiedInstanceStruct *chartInstance)
{
  chartInstance->c31_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c31_is_active_c31_Modified = 0U;
}

static void initialize_params_c31_Modified(SFc31_ModifiedInstanceStruct
  *chartInstance)
{
  const mxArray *c31_m0 = NULL;
  const mxArray *c31_mxField;
  const mxArray *c31_m1 = NULL;
  const mxArray *c31_b_mxField;
  c31_struct_iBlsPBO3AGnt69vDoTx5zD c31_r0;
  const mxArray *c31_m2 = NULL;
  const mxArray *c31_c_mxField;
  const mxArray *c31_m3 = NULL;
  const mxArray *c31_d_mxField;
  const mxArray *c31_m4 = NULL;
  const mxArray *c31_e_mxField;
  const mxArray *c31_m5 = NULL;
  const mxArray *c31_f_mxField;
  const mxArray *c31_m6 = NULL;
  const mxArray *c31_g_mxField;
  const mxArray *c31_m7 = NULL;
  const mxArray *c31_h_mxField;
  const mxArray *c31_m8 = NULL;
  const mxArray *c31_i_mxField;
  const mxArray *c31_m9 = NULL;
  const mxArray *c31_j_mxField;
  const mxArray *c31_m10 = NULL;
  const mxArray *c31_k_mxField;
  const mxArray *c31_m11 = NULL;
  const mxArray *c31_l_mxField;
  const mxArray *c31_m12 = NULL;
  const mxArray *c31_m_mxField;
  const mxArray *c31_m13 = NULL;
  const mxArray *c31_n_mxField;
  c31_m0 = sf_mex_get_sfun_param(chartInstance->S, 0, 1);
  c31_mxField = sf_mex_getfield(c31_m0, "Env", "Par", 0);
  c31_m1 = sf_mex_dup(c31_mxField);
  c31_b_mxField = sf_mex_getfield(c31_m1, "g", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_b_mxField), &c31_r0.Env.g, 1, 0, 0U,
                      0, 0U, 0);
  c31_b_mxField = sf_mex_getfield(c31_m1, "left1", "Par", 0);
  c31_m2 = sf_mex_dup(c31_b_mxField);
  c31_c_mxField = sf_mex_getfield(c31_m2, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_c_mxField), &c31_r0.Env.left1.x, 1,
                      0, 0U, 0, 0U, 0);
  c31_c_mxField = sf_mex_getfield(c31_m2, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_c_mxField), &c31_r0.Env.left1.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c31_m2);
  c31_b_mxField = sf_mex_getfield(c31_m1, "right1", "Par", 0);
  c31_m3 = sf_mex_dup(c31_b_mxField);
  c31_d_mxField = sf_mex_getfield(c31_m3, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_d_mxField), &c31_r0.Env.right1.x, 1,
                      0, 0U, 0, 0U, 0);
  c31_d_mxField = sf_mex_getfield(c31_m3, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_d_mxField), &c31_r0.Env.right1.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c31_m3);
  c31_b_mxField = sf_mex_getfield(c31_m1, "right2", "Par", 0);
  c31_m4 = sf_mex_dup(c31_b_mxField);
  c31_e_mxField = sf_mex_getfield(c31_m4, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_e_mxField), &c31_r0.Env.right2.x, 1,
                      0, 0U, 0, 0U, 0);
  c31_e_mxField = sf_mex_getfield(c31_m4, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_e_mxField), &c31_r0.Env.right2.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c31_m4);
  c31_b_mxField = sf_mex_getfield(c31_m1, "left2", "Par", 0);
  c31_m5 = sf_mex_dup(c31_b_mxField);
  c31_f_mxField = sf_mex_getfield(c31_m5, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_f_mxField), &c31_r0.Env.left2.x, 1,
                      0, 0U, 0, 0U, 0);
  c31_f_mxField = sf_mex_getfield(c31_m5, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_f_mxField), &c31_r0.Env.left2.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c31_m5);
  c31_b_mxField = sf_mex_getfield(c31_m1, "right3", "Par", 0);
  c31_m6 = sf_mex_dup(c31_b_mxField);
  c31_g_mxField = sf_mex_getfield(c31_m6, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_g_mxField), &c31_r0.Env.right3.x, 1,
                      0, 0U, 0, 0U, 0);
  c31_g_mxField = sf_mex_getfield(c31_m6, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_g_mxField), &c31_r0.Env.right3.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c31_m6);
  c31_b_mxField = sf_mex_getfield(c31_m1, "mu", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_b_mxField), &c31_r0.Env.mu, 1, 0, 0U,
                      0, 0U, 0);
  sf_mex_destroy(&c31_m1);
  c31_mxField = sf_mex_getfield(c31_m0, "Veh", "Par", 0);
  c31_m7 = sf_mex_dup(c31_mxField);
  c31_h_mxField = sf_mex_getfield(c31_m7, "m", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_h_mxField), &c31_r0.Veh.m, 1, 0, 0U,
                      0, 0U, 0);
  c31_h_mxField = sf_mex_getfield(c31_m7, "Jz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_h_mxField), &c31_r0.Veh.Jz, 1, 0, 0U,
                      0, 0U, 0);
  c31_h_mxField = sf_mex_getfield(c31_m7, "m_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_h_mxField), &c31_r0.Veh.m_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c31_h_mxField = sf_mex_getfield(c31_m7, "Jx_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_h_mxField), &c31_r0.Veh.Jx_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c31_h_mxField = sf_mex_getfield(c31_m7, "Jy_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_h_mxField), &c31_r0.Veh.Jy_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c31_h_mxField = sf_mex_getfield(c31_m7, "lf", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_h_mxField), &c31_r0.Veh.lf, 1, 0, 0U,
                      0, 0U, 0);
  c31_h_mxField = sf_mex_getfield(c31_m7, "lr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_h_mxField), &c31_r0.Veh.lr, 1, 0, 0U,
                      0, 0U, 0);
  c31_h_mxField = sf_mex_getfield(c31_m7, "L", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_h_mxField), &c31_r0.Veh.L, 1, 0, 0U,
                      0, 0U, 0);
  c31_h_mxField = sf_mex_getfield(c31_m7, "TrackWidth", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_h_mxField), &c31_r0.Veh.TrackWidth,
                      1, 0, 0U, 0, 0U, 0);
  c31_h_mxField = sf_mex_getfield(c31_m7, "h", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_h_mxField), &c31_r0.Veh.h, 1, 0, 0U,
                      0, 0U, 0);
  c31_h_mxField = sf_mex_getfield(c31_m7, "HalfRohACd", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_h_mxField), &c31_r0.Veh.HalfRohACd,
                      1, 0, 0U, 0, 0U, 0);
  c31_h_mxField = sf_mex_getfield(c31_m7, "F_z4_static", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_h_mxField), c31_r0.Veh.F_z4_static,
                      1, 0, 0U, 1, 0U, 2, 1, 4);
  c31_h_mxField = sf_mex_getfield(c31_m7, "Rw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_h_mxField), &c31_r0.Veh.Rw, 1, 0, 0U,
                      0, 0U, 0);
  c31_h_mxField = sf_mex_getfield(c31_m7, "r_long", "Par", 0);
  c31_m8 = sf_mex_dup(c31_h_mxField);
  c31_i_mxField = sf_mex_getfield(c31_m8, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_i_mxField), c31_r0.Veh.r_long.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c31_i_mxField = sf_mex_getfield(c31_m8, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_i_mxField), c31_r0.Veh.r_long.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c31_i_mxField = sf_mex_getfield(c31_m8, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_i_mxField), c31_r0.Veh.r_long.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c31_i_mxField = sf_mex_getfield(c31_m8, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_i_mxField), c31_r0.Veh.r_long.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c31_m8);
  c31_h_mxField = sf_mex_getfield(c31_m7, "r_lat", "Par", 0);
  c31_m9 = sf_mex_dup(c31_h_mxField);
  c31_j_mxField = sf_mex_getfield(c31_m9, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_j_mxField), c31_r0.Veh.r_lat.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c31_j_mxField = sf_mex_getfield(c31_m9, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_j_mxField), c31_r0.Veh.r_lat.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c31_j_mxField = sf_mex_getfield(c31_m9, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_j_mxField), c31_r0.Veh.r_lat.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c31_j_mxField = sf_mex_getfield(c31_m9, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_j_mxField), c31_r0.Veh.r_lat.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c31_m9);
  c31_h_mxField = sf_mex_getfield(c31_m7, "r_lever", "Par", 0);
  c31_m10 = sf_mex_dup(c31_h_mxField);
  c31_k_mxField = sf_mex_getfield(c31_m10, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_k_mxField), c31_r0.Veh.r_lever.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c31_k_mxField = sf_mex_getfield(c31_m10, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_k_mxField), c31_r0.Veh.r_lever.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c31_k_mxField = sf_mex_getfield(c31_m10, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_k_mxField), c31_r0.Veh.r_lever.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c31_k_mxField = sf_mex_getfield(c31_m10, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_k_mxField), c31_r0.Veh.r_lever.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c31_m10);
  c31_h_mxField = sf_mex_getfield(c31_m7, "r_pivot", "Par", 0);
  c31_m11 = sf_mex_dup(c31_h_mxField);
  c31_l_mxField = sf_mex_getfield(c31_m11, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_l_mxField), c31_r0.Veh.r_pivot.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c31_l_mxField = sf_mex_getfield(c31_m11, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_l_mxField), c31_r0.Veh.r_pivot.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c31_l_mxField = sf_mex_getfield(c31_m11, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_l_mxField), c31_r0.Veh.r_pivot.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c31_l_mxField = sf_mex_getfield(c31_m11, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_l_mxField), c31_r0.Veh.r_pivot.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c31_m11);
  c31_h_mxField = sf_mex_getfield(c31_m7, "cw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_h_mxField), &c31_r0.Veh.cw, 1, 0, 0U,
                      0, 0U, 0);
  c31_h_mxField = sf_mex_getfield(c31_m7, "carb_f", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_h_mxField), &c31_r0.Veh.carb_f, 1, 0,
                      0U, 0, 0U, 0);
  c31_h_mxField = sf_mex_getfield(c31_m7, "carb_r", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_h_mxField), &c31_r0.Veh.carb_r, 1, 0,
                      0U, 0, 0U, 0);
  c31_h_mxField = sf_mex_getfield(c31_m7, "dw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_h_mxField), &c31_r0.Veh.dw, 1, 0, 0U,
                      0, 0U, 0);
  c31_h_mxField = sf_mex_getfield(c31_m7, "Jw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_h_mxField), &c31_r0.Veh.Jw, 1, 0, 0U,
                      0, 0U, 0);
  c31_h_mxField = sf_mex_getfield(c31_m7, "C0", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_h_mxField), &c31_r0.Veh.C0, 1, 0, 0U,
                      0, 0U, 0);
  c31_h_mxField = sf_mex_getfield(c31_m7, "RelaxLength", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_h_mxField), &c31_r0.Veh.RelaxLength,
                      1, 0, 0U, 0, 0U, 0);
  c31_h_mxField = sf_mex_getfield(c31_m7, "RRC", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_h_mxField), &c31_r0.Veh.RRC, 1, 0,
                      0U, 0, 0U, 0);
  c31_h_mxField = sf_mex_getfield(c31_m7, "Pmax", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_h_mxField), &c31_r0.Veh.Pmax, 1, 0,
                      0U, 0, 0U, 0);
  c31_h_mxField = sf_mex_getfield(c31_m7, "PropDistrFrnt", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_h_mxField),
                      &c31_r0.Veh.PropDistrFrnt, 1, 0, 0U, 0, 0U, 0);
  c31_h_mxField = sf_mex_getfield(c31_m7, "BrkDistrFrnt", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_h_mxField), &c31_r0.Veh.BrkDistrFrnt,
                      1, 0, 0U, 0, 0U, 0);
  c31_h_mxField = sf_mex_getfield(c31_m7, "SteRatio", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_h_mxField), &c31_r0.Veh.SteRatio, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c31_m7);
  c31_mxField = sf_mex_getfield(c31_m0, "Drvr", "Par", 0);
  c31_m12 = sf_mex_dup(c31_mxField);
  c31_m_mxField = sf_mex_getfield(c31_m12, "v_set", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_m_mxField), &c31_r0.Drvr.v_set, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c31_m12);
  c31_mxField = sf_mex_getfield(c31_m0, "Init", "Par", 0);
  c31_m13 = sf_mex_dup(c31_mxField);
  c31_n_mxField = sf_mex_getfield(c31_m13, "v_x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_n_mxField), &c31_r0.Init.v_x, 1, 0,
                      0U, 0, 0U, 0);
  c31_n_mxField = sf_mex_getfield(c31_m13, "F_fz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_n_mxField), &c31_r0.Init.F_fz, 1, 0,
                      0U, 0, 0U, 0);
  c31_n_mxField = sf_mex_getfield(c31_m13, "F_rz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c31_n_mxField), &c31_r0.Init.F_rz, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c31_m13);
  sf_mex_destroy(&c31_m0);
  chartInstance->c31_Par = c31_r0;
}

static void enable_c31_Modified(SFc31_ModifiedInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c31_Modified(SFc31_ModifiedInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c31_update_debugger_state_c31_Modified(SFc31_ModifiedInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c31_Modified(SFc31_ModifiedInstanceStruct
  *chartInstance)
{
  const mxArray *c31_st;
  const mxArray *c31_y = NULL;
  const mxArray *c31_b_y = NULL;
  real_T c31_u;
  const mxArray *c31_c_y = NULL;
  real_T c31_b_u;
  const mxArray *c31_d_y = NULL;
  real_T c31_c_u;
  const mxArray *c31_e_y = NULL;
  real_T c31_d_u;
  const mxArray *c31_f_y = NULL;
  uint8_T c31_hoistedGlobal;
  uint8_T c31_e_u;
  const mxArray *c31_g_y = NULL;
  c31_st = NULL;
  c31_st = NULL;
  c31_y = NULL;
  sf_mex_assign(&c31_y, sf_mex_createcellmatrix(2, 1), false);
  c31_b_y = NULL;
  sf_mex_assign(&c31_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c31_u = *(real_T *)&((char_T *)chartInstance->c31_F_xywSS4)[0];
  c31_c_y = NULL;
  sf_mex_assign(&c31_c_y, sf_mex_create("y", &c31_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c31_b_y, c31_c_y, "fl", "fl", 0);
  c31_b_u = *(real_T *)&((char_T *)chartInstance->c31_F_xywSS4)[8];
  c31_d_y = NULL;
  sf_mex_assign(&c31_d_y, sf_mex_create("y", &c31_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c31_b_y, c31_d_y, "fr", "fr", 0);
  c31_c_u = *(real_T *)&((char_T *)chartInstance->c31_F_xywSS4)[16];
  c31_e_y = NULL;
  sf_mex_assign(&c31_e_y, sf_mex_create("y", &c31_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c31_b_y, c31_e_y, "rl", "rl", 0);
  c31_d_u = *(real_T *)&((char_T *)chartInstance->c31_F_xywSS4)[24];
  c31_f_y = NULL;
  sf_mex_assign(&c31_f_y, sf_mex_create("y", &c31_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c31_b_y, c31_f_y, "rr", "rr", 0);
  sf_mex_setcell(c31_y, 0, c31_b_y);
  c31_hoistedGlobal = chartInstance->c31_is_active_c31_Modified;
  c31_e_u = c31_hoistedGlobal;
  c31_g_y = NULL;
  sf_mex_assign(&c31_g_y, sf_mex_create("y", &c31_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c31_y, 1, c31_g_y);
  sf_mex_assign(&c31_st, c31_y, false);
  return c31_st;
}

static void set_sim_state_c31_Modified(SFc31_ModifiedInstanceStruct
  *chartInstance, const mxArray *c31_st)
{
  const mxArray *c31_u;
  c31_whl_vec4 c31_r1;
  chartInstance->c31_doneDoubleBufferReInit = true;
  c31_u = sf_mex_dup(c31_st);
  c31_r1 = c31_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c31_u,
    0)), "F_xywSS4");
  *(real_T *)&((char_T *)chartInstance->c31_F_xywSS4)[0] = c31_r1.fl;
  *(real_T *)&((char_T *)chartInstance->c31_F_xywSS4)[8] = c31_r1.fr;
  *(real_T *)&((char_T *)chartInstance->c31_F_xywSS4)[16] = c31_r1.rl;
  *(real_T *)&((char_T *)chartInstance->c31_F_xywSS4)[24] = c31_r1.rr;
  chartInstance->c31_is_active_c31_Modified = c31_n_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c31_u, 1)),
     "is_active_c31_Modified");
  sf_mex_destroy(&c31_u);
  c31_update_debugger_state_c31_Modified(chartInstance);
  sf_mex_destroy(&c31_st);
}

static void finalize_c31_Modified(SFc31_ModifiedInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c31_Modified(SFc31_ModifiedInstanceStruct *chartInstance)
{
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 30U, chartInstance->c31_sfEvent);
  chartInstance->c31_sfEvent = CALL_EVENT;
  c31_chartstep_c31_Modified(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_ModifiedMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c31_Modified(SFc31_ModifiedInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c31_chartstep_c31_Modified(SFc31_ModifiedInstanceStruct
  *chartInstance)
{
  c31_whl_vec4 c31_b_s_xy4;
  c31_whl_vec4 c31_b_F_z4;
  c31_struct_iBlsPBO3AGnt69vDoTx5zD c31_b_Par;
  uint32_T c31_debug_family_var_map[9];
  real_T c31_C0;
  real_T c31_mu;
  real_T c31_Rw;
  real_T c31_nargin = 3.0;
  real_T c31_nargout = 1.0;
  c31_whl_vec4 c31_b_F_xywSS4;
  real_T c31_varargin_1;
  real_T c31_varargin_2;
  real_T c31_b_varargin_2;
  real_T c31_varargin_3;
  real_T c31_x;
  real_T c31_y;
  real_T c31_b_x;
  real_T c31_b_y;
  real_T c31_xk;
  real_T c31_yk;
  real_T c31_c_x;
  real_T c31_c_y;
  real_T c31_minval;
  real_T c31_b_varargin_1;
  real_T c31_c_varargin_2;
  real_T c31_d_x;
  real_T c31_e_x;
  real_T c31_b_xk;
  real_T c31_f_x;
  real_T c31_maxval;
  real_T c31_c_varargin_1;
  real_T c31_d_varargin_2;
  real_T c31_e_varargin_2;
  real_T c31_b_varargin_3;
  real_T c31_g_x;
  real_T c31_d_y;
  real_T c31_h_x;
  real_T c31_e_y;
  real_T c31_c_xk;
  real_T c31_b_yk;
  real_T c31_i_x;
  real_T c31_f_y;
  real_T c31_b_minval;
  real_T c31_d_varargin_1;
  real_T c31_f_varargin_2;
  real_T c31_j_x;
  real_T c31_k_x;
  real_T c31_d_xk;
  real_T c31_l_x;
  real_T c31_b_maxval;
  real_T c31_e_varargin_1;
  real_T c31_g_varargin_2;
  real_T c31_h_varargin_2;
  real_T c31_c_varargin_3;
  real_T c31_m_x;
  real_T c31_g_y;
  real_T c31_n_x;
  real_T c31_h_y;
  real_T c31_e_xk;
  real_T c31_c_yk;
  real_T c31_o_x;
  real_T c31_i_y;
  real_T c31_c_minval;
  real_T c31_f_varargin_1;
  real_T c31_i_varargin_2;
  real_T c31_p_x;
  real_T c31_q_x;
  real_T c31_f_xk;
  real_T c31_r_x;
  real_T c31_c_maxval;
  real_T c31_g_varargin_1;
  real_T c31_j_varargin_2;
  real_T c31_k_varargin_2;
  real_T c31_d_varargin_3;
  real_T c31_s_x;
  real_T c31_j_y;
  real_T c31_t_x;
  real_T c31_k_y;
  real_T c31_g_xk;
  real_T c31_d_yk;
  real_T c31_u_x;
  real_T c31_l_y;
  real_T c31_d_minval;
  real_T c31_h_varargin_1;
  real_T c31_l_varargin_2;
  real_T c31_v_x;
  real_T c31_w_x;
  real_T c31_h_xk;
  real_T c31_x_x;
  real_T c31_d_maxval;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 30U, chartInstance->c31_sfEvent);
  c31_b_s_xy4.fl = *(real_T *)&((char_T *)chartInstance->c31_s_xy4)[0];
  c31_b_s_xy4.fr = *(real_T *)&((char_T *)chartInstance->c31_s_xy4)[8];
  c31_b_s_xy4.rl = *(real_T *)&((char_T *)chartInstance->c31_s_xy4)[16];
  c31_b_s_xy4.rr = *(real_T *)&((char_T *)chartInstance->c31_s_xy4)[24];
  c31_b_F_z4.fl = *(real_T *)&((char_T *)chartInstance->c31_F_z4)[0];
  c31_b_F_z4.fr = *(real_T *)&((char_T *)chartInstance->c31_F_z4)[8];
  c31_b_F_z4.rl = *(real_T *)&((char_T *)chartInstance->c31_F_z4)[16];
  c31_b_F_z4.rr = *(real_T *)&((char_T *)chartInstance->c31_F_z4)[24];
  c31_b_Par = chartInstance->c31_Par;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c31_debug_family_names,
    c31_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c31_C0, 0U, c31_c_sf_marshallOut,
    c31_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c31_mu, 1U, c31_c_sf_marshallOut,
    c31_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c31_Rw, 2U, c31_c_sf_marshallOut,
    c31_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c31_nargin, 3U, c31_c_sf_marshallOut,
    c31_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c31_nargout, 4U, c31_c_sf_marshallOut,
    c31_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c31_b_s_xy4, 5U, c31_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c31_b_F_z4, 6U, c31_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c31_b_Par, 7U, c31_b_sf_marshallOut,
    c31_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c31_b_F_xywSS4, 8U, c31_sf_marshallOut,
    c31_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 4);
  c31_C0 = c31_b_Par.Veh.C0;
  _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 5);
  c31_mu = c31_b_Par.Env.mu;
  _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 6);
  c31_Rw = c31_b_Par.Veh.Rw;
  _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 8);
  c31_varargin_1 = c31_C0 * c31_b_s_xy4.fl;
  c31_varargin_2 = c31_mu;
  c31_b_varargin_2 = c31_varargin_1;
  c31_varargin_3 = c31_varargin_2;
  c31_x = c31_b_varargin_2;
  c31_y = c31_varargin_3;
  c31_b_x = c31_x;
  c31_b_y = c31_y;
  c31_eml_scalar_eg(chartInstance);
  c31_xk = c31_b_x;
  c31_yk = c31_b_y;
  c31_c_x = c31_xk;
  c31_c_y = c31_yk;
  c31_eml_scalar_eg(chartInstance);
  c31_minval = muDoubleScalarMin(c31_c_x, c31_c_y);
  c31_b_varargin_1 = c31_b_F_z4.fl;
  c31_c_varargin_2 = c31_b_varargin_1;
  c31_d_x = c31_c_varargin_2;
  c31_e_x = c31_d_x;
  c31_eml_scalar_eg(chartInstance);
  c31_b_xk = c31_e_x;
  c31_f_x = c31_b_xk;
  c31_eml_scalar_eg(chartInstance);
  c31_maxval = muDoubleScalarMax(c31_f_x, 0.0);
  c31_b_F_xywSS4.fl = c31_minval * c31_maxval;
  _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 9);
  c31_c_varargin_1 = c31_C0 * c31_b_s_xy4.fr;
  c31_d_varargin_2 = c31_mu;
  c31_e_varargin_2 = c31_c_varargin_1;
  c31_b_varargin_3 = c31_d_varargin_2;
  c31_g_x = c31_e_varargin_2;
  c31_d_y = c31_b_varargin_3;
  c31_h_x = c31_g_x;
  c31_e_y = c31_d_y;
  c31_eml_scalar_eg(chartInstance);
  c31_c_xk = c31_h_x;
  c31_b_yk = c31_e_y;
  c31_i_x = c31_c_xk;
  c31_f_y = c31_b_yk;
  c31_eml_scalar_eg(chartInstance);
  c31_b_minval = muDoubleScalarMin(c31_i_x, c31_f_y);
  c31_d_varargin_1 = c31_b_F_z4.fr;
  c31_f_varargin_2 = c31_d_varargin_1;
  c31_j_x = c31_f_varargin_2;
  c31_k_x = c31_j_x;
  c31_eml_scalar_eg(chartInstance);
  c31_d_xk = c31_k_x;
  c31_l_x = c31_d_xk;
  c31_eml_scalar_eg(chartInstance);
  c31_b_maxval = muDoubleScalarMax(c31_l_x, 0.0);
  c31_b_F_xywSS4.fr = c31_b_minval * c31_b_maxval;
  _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 10);
  c31_e_varargin_1 = c31_C0 * c31_b_s_xy4.rl;
  c31_g_varargin_2 = c31_mu;
  c31_h_varargin_2 = c31_e_varargin_1;
  c31_c_varargin_3 = c31_g_varargin_2;
  c31_m_x = c31_h_varargin_2;
  c31_g_y = c31_c_varargin_3;
  c31_n_x = c31_m_x;
  c31_h_y = c31_g_y;
  c31_eml_scalar_eg(chartInstance);
  c31_e_xk = c31_n_x;
  c31_c_yk = c31_h_y;
  c31_o_x = c31_e_xk;
  c31_i_y = c31_c_yk;
  c31_eml_scalar_eg(chartInstance);
  c31_c_minval = muDoubleScalarMin(c31_o_x, c31_i_y);
  c31_f_varargin_1 = c31_b_F_z4.rl;
  c31_i_varargin_2 = c31_f_varargin_1;
  c31_p_x = c31_i_varargin_2;
  c31_q_x = c31_p_x;
  c31_eml_scalar_eg(chartInstance);
  c31_f_xk = c31_q_x;
  c31_r_x = c31_f_xk;
  c31_eml_scalar_eg(chartInstance);
  c31_c_maxval = muDoubleScalarMax(c31_r_x, 0.0);
  c31_b_F_xywSS4.rl = c31_c_minval * c31_c_maxval;
  _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 11);
  c31_g_varargin_1 = c31_C0 * c31_b_s_xy4.rr;
  c31_j_varargin_2 = c31_mu;
  c31_k_varargin_2 = c31_g_varargin_1;
  c31_d_varargin_3 = c31_j_varargin_2;
  c31_s_x = c31_k_varargin_2;
  c31_j_y = c31_d_varargin_3;
  c31_t_x = c31_s_x;
  c31_k_y = c31_j_y;
  c31_eml_scalar_eg(chartInstance);
  c31_g_xk = c31_t_x;
  c31_d_yk = c31_k_y;
  c31_u_x = c31_g_xk;
  c31_l_y = c31_d_yk;
  c31_eml_scalar_eg(chartInstance);
  c31_d_minval = muDoubleScalarMin(c31_u_x, c31_l_y);
  c31_h_varargin_1 = c31_b_F_z4.rr;
  c31_l_varargin_2 = c31_h_varargin_1;
  c31_v_x = c31_l_varargin_2;
  c31_w_x = c31_v_x;
  c31_eml_scalar_eg(chartInstance);
  c31_h_xk = c31_w_x;
  c31_x_x = c31_h_xk;
  c31_eml_scalar_eg(chartInstance);
  c31_d_maxval = muDoubleScalarMax(c31_x_x, 0.0);
  c31_b_F_xywSS4.rr = c31_d_minval * c31_d_maxval;
  _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
  *(real_T *)&((char_T *)chartInstance->c31_F_xywSS4)[0] = c31_b_F_xywSS4.fl;
  *(real_T *)&((char_T *)chartInstance->c31_F_xywSS4)[8] = c31_b_F_xywSS4.fr;
  *(real_T *)&((char_T *)chartInstance->c31_F_xywSS4)[16] = c31_b_F_xywSS4.rl;
  *(real_T *)&((char_T *)chartInstance->c31_F_xywSS4)[24] = c31_b_F_xywSS4.rr;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 30U, chartInstance->c31_sfEvent);
}

static void initSimStructsc31_Modified(SFc31_ModifiedInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c31_machineNumber, uint32_T
  c31_chartNumber, uint32_T c31_instanceNumber)
{
  (void)c31_machineNumber;
  (void)c31_chartNumber;
  (void)c31_instanceNumber;
}

static const mxArray *c31_sf_marshallOut(void *chartInstanceVoid, void
  *c31_inData)
{
  const mxArray *c31_mxArrayOutData = NULL;
  c31_whl_vec4 c31_u;
  const mxArray *c31_y = NULL;
  real_T c31_b_u;
  const mxArray *c31_b_y = NULL;
  real_T c31_c_u;
  const mxArray *c31_c_y = NULL;
  real_T c31_d_u;
  const mxArray *c31_d_y = NULL;
  real_T c31_e_u;
  const mxArray *c31_e_y = NULL;
  SFc31_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc31_ModifiedInstanceStruct *)chartInstanceVoid;
  c31_mxArrayOutData = NULL;
  c31_u = *(c31_whl_vec4 *)c31_inData;
  c31_y = NULL;
  sf_mex_assign(&c31_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c31_b_u = c31_u.fl;
  c31_b_y = NULL;
  sf_mex_assign(&c31_b_y, sf_mex_create("y", &c31_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c31_y, c31_b_y, "fl", "fl", 0);
  c31_c_u = c31_u.fr;
  c31_c_y = NULL;
  sf_mex_assign(&c31_c_y, sf_mex_create("y", &c31_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c31_y, c31_c_y, "fr", "fr", 0);
  c31_d_u = c31_u.rl;
  c31_d_y = NULL;
  sf_mex_assign(&c31_d_y, sf_mex_create("y", &c31_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c31_y, c31_d_y, "rl", "rl", 0);
  c31_e_u = c31_u.rr;
  c31_e_y = NULL;
  sf_mex_assign(&c31_e_y, sf_mex_create("y", &c31_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c31_y, c31_e_y, "rr", "rr", 0);
  sf_mex_assign(&c31_mxArrayOutData, c31_y, false);
  return c31_mxArrayOutData;
}

static c31_whl_vec4 c31_emlrt_marshallIn(SFc31_ModifiedInstanceStruct
  *chartInstance, const mxArray *c31_b_F_xywSS4, const char_T *c31_identifier)
{
  c31_whl_vec4 c31_y;
  emlrtMsgIdentifier c31_thisId;
  c31_thisId.fIdentifier = c31_identifier;
  c31_thisId.fParent = NULL;
  c31_y = c31_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c31_b_F_xywSS4),
    &c31_thisId);
  sf_mex_destroy(&c31_b_F_xywSS4);
  return c31_y;
}

static c31_whl_vec4 c31_b_emlrt_marshallIn(SFc31_ModifiedInstanceStruct
  *chartInstance, const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId)
{
  c31_whl_vec4 c31_y;
  emlrtMsgIdentifier c31_thisId;
  static const char * c31_fieldNames[4] = { "fl", "fr", "rl", "rr" };

  c31_thisId.fParent = c31_parentId;
  sf_mex_check_struct(c31_parentId, c31_u, 4, c31_fieldNames, 0U, NULL);
  c31_thisId.fIdentifier = "fl";
  c31_y.fl = c31_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c31_u, "fl", "fl", 0)), &c31_thisId);
  c31_thisId.fIdentifier = "fr";
  c31_y.fr = c31_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c31_u, "fr", "fr", 0)), &c31_thisId);
  c31_thisId.fIdentifier = "rl";
  c31_y.rl = c31_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c31_u, "rl", "rl", 0)), &c31_thisId);
  c31_thisId.fIdentifier = "rr";
  c31_y.rr = c31_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c31_u, "rr", "rr", 0)), &c31_thisId);
  sf_mex_destroy(&c31_u);
  return c31_y;
}

static real_T c31_c_emlrt_marshallIn(SFc31_ModifiedInstanceStruct *chartInstance,
  const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId)
{
  real_T c31_y;
  real_T c31_d0;
  (void)chartInstance;
  sf_mex_import(c31_parentId, sf_mex_dup(c31_u), &c31_d0, 1, 0, 0U, 0, 0U, 0);
  c31_y = c31_d0;
  sf_mex_destroy(&c31_u);
  return c31_y;
}

static void c31_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c31_mxArrayInData, const char_T *c31_varName, void *c31_outData)
{
  const mxArray *c31_b_F_xywSS4;
  const char_T *c31_identifier;
  emlrtMsgIdentifier c31_thisId;
  c31_whl_vec4 c31_y;
  SFc31_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc31_ModifiedInstanceStruct *)chartInstanceVoid;
  c31_b_F_xywSS4 = sf_mex_dup(c31_mxArrayInData);
  c31_identifier = c31_varName;
  c31_thisId.fIdentifier = c31_identifier;
  c31_thisId.fParent = NULL;
  c31_y = c31_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c31_b_F_xywSS4),
    &c31_thisId);
  sf_mex_destroy(&c31_b_F_xywSS4);
  *(c31_whl_vec4 *)c31_outData = c31_y;
  sf_mex_destroy(&c31_mxArrayInData);
}

static const mxArray *c31_b_sf_marshallOut(void *chartInstanceVoid, void
  *c31_inData)
{
  const mxArray *c31_mxArrayOutData;
  c31_struct_iBlsPBO3AGnt69vDoTx5zD c31_u;
  const mxArray *c31_y = NULL;
  c31_struct_Nst2vGTExxHsg85EUOj9EH c31_b_u;
  const mxArray *c31_b_y = NULL;
  real_T c31_c_u;
  const mxArray *c31_c_y = NULL;
  c31_struct_HhckT6rntEraqECYVIDvCC c31_d_u;
  const mxArray *c31_d_y = NULL;
  real_T c31_e_u;
  const mxArray *c31_e_y = NULL;
  real_T c31_f_u;
  const mxArray *c31_f_y = NULL;
  const mxArray *c31_g_y = NULL;
  real_T c31_g_u;
  const mxArray *c31_h_y = NULL;
  real_T c31_h_u;
  const mxArray *c31_i_y = NULL;
  const mxArray *c31_j_y = NULL;
  real_T c31_i_u;
  const mxArray *c31_k_y = NULL;
  real_T c31_j_u;
  const mxArray *c31_l_y = NULL;
  const mxArray *c31_m_y = NULL;
  real_T c31_k_u;
  const mxArray *c31_n_y = NULL;
  real_T c31_l_u;
  const mxArray *c31_o_y = NULL;
  const mxArray *c31_p_y = NULL;
  real_T c31_m_u;
  const mxArray *c31_q_y = NULL;
  real_T c31_n_u;
  const mxArray *c31_r_y = NULL;
  real_T c31_o_u;
  const mxArray *c31_s_y = NULL;
  c31_struct_ZCmOWPuqBDw16FSOVVD00 c31_p_u;
  const mxArray *c31_t_y = NULL;
  real_T c31_q_u;
  const mxArray *c31_u_y = NULL;
  real_T c31_r_u;
  const mxArray *c31_v_y = NULL;
  real_T c31_s_u;
  const mxArray *c31_w_y = NULL;
  real_T c31_t_u;
  const mxArray *c31_x_y = NULL;
  real_T c31_u_u;
  const mxArray *c31_y_y = NULL;
  real_T c31_v_u;
  const mxArray *c31_ab_y = NULL;
  real_T c31_w_u;
  const mxArray *c31_bb_y = NULL;
  real_T c31_x_u;
  const mxArray *c31_cb_y = NULL;
  real_T c31_y_u;
  const mxArray *c31_db_y = NULL;
  real_T c31_ab_u;
  const mxArray *c31_eb_y = NULL;
  real_T c31_bb_u;
  const mxArray *c31_fb_y = NULL;
  int32_T c31_i0;
  real_T c31_cb_u[4];
  const mxArray *c31_gb_y = NULL;
  real_T c31_db_u;
  const mxArray *c31_hb_y = NULL;
  c31_struct_ZKAzdrl7umDGJoC14aoVKC c31_eb_u;
  const mxArray *c31_ib_y = NULL;
  int32_T c31_i1;
  real_T c31_fb_u[3];
  const mxArray *c31_jb_y = NULL;
  int32_T c31_i2;
  real_T c31_gb_u[3];
  const mxArray *c31_kb_y = NULL;
  int32_T c31_i3;
  real_T c31_hb_u[3];
  const mxArray *c31_lb_y = NULL;
  int32_T c31_i4;
  real_T c31_ib_u[3];
  const mxArray *c31_mb_y = NULL;
  const mxArray *c31_nb_y = NULL;
  int32_T c31_i5;
  real_T c31_jb_u[3];
  const mxArray *c31_ob_y = NULL;
  int32_T c31_i6;
  real_T c31_kb_u[3];
  const mxArray *c31_pb_y = NULL;
  int32_T c31_i7;
  real_T c31_lb_u[3];
  const mxArray *c31_qb_y = NULL;
  int32_T c31_i8;
  real_T c31_mb_u[3];
  const mxArray *c31_rb_y = NULL;
  const mxArray *c31_sb_y = NULL;
  int32_T c31_i9;
  real_T c31_nb_u[3];
  const mxArray *c31_tb_y = NULL;
  int32_T c31_i10;
  real_T c31_ob_u[3];
  const mxArray *c31_ub_y = NULL;
  int32_T c31_i11;
  real_T c31_pb_u[3];
  const mxArray *c31_vb_y = NULL;
  int32_T c31_i12;
  real_T c31_qb_u[3];
  const mxArray *c31_wb_y = NULL;
  const mxArray *c31_xb_y = NULL;
  int32_T c31_i13;
  real_T c31_rb_u[3];
  const mxArray *c31_yb_y = NULL;
  int32_T c31_i14;
  real_T c31_sb_u[3];
  const mxArray *c31_ac_y = NULL;
  int32_T c31_i15;
  real_T c31_tb_u[3];
  const mxArray *c31_bc_y = NULL;
  int32_T c31_i16;
  real_T c31_ub_u[3];
  const mxArray *c31_cc_y = NULL;
  real_T c31_vb_u;
  const mxArray *c31_dc_y = NULL;
  real_T c31_wb_u;
  const mxArray *c31_ec_y = NULL;
  real_T c31_xb_u;
  const mxArray *c31_fc_y = NULL;
  real_T c31_yb_u;
  const mxArray *c31_gc_y = NULL;
  real_T c31_ac_u;
  const mxArray *c31_hc_y = NULL;
  real_T c31_bc_u;
  const mxArray *c31_ic_y = NULL;
  real_T c31_cc_u;
  const mxArray *c31_jc_y = NULL;
  real_T c31_dc_u;
  const mxArray *c31_kc_y = NULL;
  real_T c31_ec_u;
  const mxArray *c31_lc_y = NULL;
  real_T c31_fc_u;
  const mxArray *c31_mc_y = NULL;
  real_T c31_gc_u;
  const mxArray *c31_nc_y = NULL;
  real_T c31_hc_u;
  const mxArray *c31_oc_y = NULL;
  c31_struct_r4FNviKwHfdhB8nQjvQv9 c31_ic_u;
  const mxArray *c31_pc_y = NULL;
  real_T c31_jc_u;
  const mxArray *c31_qc_y = NULL;
  c31_struct_Y9F1qlBi9AhssksPwemA4G c31_kc_u;
  const mxArray *c31_rc_y = NULL;
  real_T c31_lc_u;
  const mxArray *c31_sc_y = NULL;
  real_T c31_mc_u;
  const mxArray *c31_tc_y = NULL;
  real_T c31_nc_u;
  const mxArray *c31_uc_y = NULL;
  SFc31_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc31_ModifiedInstanceStruct *)chartInstanceVoid;
  c31_mxArrayOutData = NULL;
  c31_mxArrayOutData = NULL;
  c31_u = *(c31_struct_iBlsPBO3AGnt69vDoTx5zD *)c31_inData;
  c31_y = NULL;
  sf_mex_assign(&c31_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c31_b_u = c31_u.Env;
  c31_b_y = NULL;
  sf_mex_assign(&c31_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c31_c_u = c31_b_u.g;
  c31_c_y = NULL;
  sf_mex_assign(&c31_c_y, sf_mex_create("y", &c31_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c31_b_y, c31_c_y, "g", "g", 0);
  c31_d_u = c31_b_u.left1;
  c31_d_y = NULL;
  sf_mex_assign(&c31_d_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c31_e_u = c31_d_u.x;
  c31_e_y = NULL;
  sf_mex_assign(&c31_e_y, sf_mex_create("y", &c31_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c31_d_y, c31_e_y, "x", "x", 0);
  c31_f_u = c31_d_u.y;
  c31_f_y = NULL;
  sf_mex_assign(&c31_f_y, sf_mex_create("y", &c31_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c31_d_y, c31_f_y, "y", "y", 0);
  sf_mex_addfield(c31_b_y, c31_d_y, "left1", "left1", 0);
  c31_d_u = c31_b_u.right1;
  c31_g_y = NULL;
  sf_mex_assign(&c31_g_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c31_g_u = c31_d_u.x;
  c31_h_y = NULL;
  sf_mex_assign(&c31_h_y, sf_mex_create("y", &c31_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c31_g_y, c31_h_y, "x", "x", 0);
  c31_h_u = c31_d_u.y;
  c31_i_y = NULL;
  sf_mex_assign(&c31_i_y, sf_mex_create("y", &c31_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c31_g_y, c31_i_y, "y", "y", 0);
  sf_mex_addfield(c31_b_y, c31_g_y, "right1", "right1", 0);
  c31_d_u = c31_b_u.right2;
  c31_j_y = NULL;
  sf_mex_assign(&c31_j_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c31_i_u = c31_d_u.x;
  c31_k_y = NULL;
  sf_mex_assign(&c31_k_y, sf_mex_create("y", &c31_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c31_j_y, c31_k_y, "x", "x", 0);
  c31_j_u = c31_d_u.y;
  c31_l_y = NULL;
  sf_mex_assign(&c31_l_y, sf_mex_create("y", &c31_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c31_j_y, c31_l_y, "y", "y", 0);
  sf_mex_addfield(c31_b_y, c31_j_y, "right2", "right2", 0);
  c31_d_u = c31_b_u.left2;
  c31_m_y = NULL;
  sf_mex_assign(&c31_m_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c31_k_u = c31_d_u.x;
  c31_n_y = NULL;
  sf_mex_assign(&c31_n_y, sf_mex_create("y", &c31_k_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c31_m_y, c31_n_y, "x", "x", 0);
  c31_l_u = c31_d_u.y;
  c31_o_y = NULL;
  sf_mex_assign(&c31_o_y, sf_mex_create("y", &c31_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c31_m_y, c31_o_y, "y", "y", 0);
  sf_mex_addfield(c31_b_y, c31_m_y, "left2", "left2", 0);
  c31_d_u = c31_b_u.right3;
  c31_p_y = NULL;
  sf_mex_assign(&c31_p_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c31_m_u = c31_d_u.x;
  c31_q_y = NULL;
  sf_mex_assign(&c31_q_y, sf_mex_create("y", &c31_m_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c31_p_y, c31_q_y, "x", "x", 0);
  c31_n_u = c31_d_u.y;
  c31_r_y = NULL;
  sf_mex_assign(&c31_r_y, sf_mex_create("y", &c31_n_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c31_p_y, c31_r_y, "y", "y", 0);
  sf_mex_addfield(c31_b_y, c31_p_y, "right3", "right3", 0);
  c31_o_u = c31_b_u.mu;
  c31_s_y = NULL;
  sf_mex_assign(&c31_s_y, sf_mex_create("y", &c31_o_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c31_b_y, c31_s_y, "mu", "mu", 0);
  sf_mex_addfield(c31_y, c31_b_y, "Env", "Env", 0);
  c31_p_u = c31_u.Veh;
  c31_t_y = NULL;
  sf_mex_assign(&c31_t_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c31_q_u = c31_p_u.m;
  c31_u_y = NULL;
  sf_mex_assign(&c31_u_y, sf_mex_create("y", &c31_q_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c31_t_y, c31_u_y, "m", "m", 0);
  c31_r_u = c31_p_u.Jz;
  c31_v_y = NULL;
  sf_mex_assign(&c31_v_y, sf_mex_create("y", &c31_r_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c31_t_y, c31_v_y, "Jz", "Jz", 0);
  c31_s_u = c31_p_u.m_sprung;
  c31_w_y = NULL;
  sf_mex_assign(&c31_w_y, sf_mex_create("y", &c31_s_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c31_t_y, c31_w_y, "m_sprung", "m_sprung", 0);
  c31_t_u = c31_p_u.Jx_sprung;
  c31_x_y = NULL;
  sf_mex_assign(&c31_x_y, sf_mex_create("y", &c31_t_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c31_t_y, c31_x_y, "Jx_sprung", "Jx_sprung", 0);
  c31_u_u = c31_p_u.Jy_sprung;
  c31_y_y = NULL;
  sf_mex_assign(&c31_y_y, sf_mex_create("y", &c31_u_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c31_t_y, c31_y_y, "Jy_sprung", "Jy_sprung", 0);
  c31_v_u = c31_p_u.lf;
  c31_ab_y = NULL;
  sf_mex_assign(&c31_ab_y, sf_mex_create("y", &c31_v_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c31_t_y, c31_ab_y, "lf", "lf", 0);
  c31_w_u = c31_p_u.lr;
  c31_bb_y = NULL;
  sf_mex_assign(&c31_bb_y, sf_mex_create("y", &c31_w_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c31_t_y, c31_bb_y, "lr", "lr", 0);
  c31_x_u = c31_p_u.L;
  c31_cb_y = NULL;
  sf_mex_assign(&c31_cb_y, sf_mex_create("y", &c31_x_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c31_t_y, c31_cb_y, "L", "L", 0);
  c31_y_u = c31_p_u.TrackWidth;
  c31_db_y = NULL;
  sf_mex_assign(&c31_db_y, sf_mex_create("y", &c31_y_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c31_t_y, c31_db_y, "TrackWidth", "TrackWidth", 0);
  c31_ab_u = c31_p_u.h;
  c31_eb_y = NULL;
  sf_mex_assign(&c31_eb_y, sf_mex_create("y", &c31_ab_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c31_t_y, c31_eb_y, "h", "h", 0);
  c31_bb_u = c31_p_u.HalfRohACd;
  c31_fb_y = NULL;
  sf_mex_assign(&c31_fb_y, sf_mex_create("y", &c31_bb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c31_t_y, c31_fb_y, "HalfRohACd", "HalfRohACd", 0);
  for (c31_i0 = 0; c31_i0 < 4; c31_i0++) {
    c31_cb_u[c31_i0] = c31_p_u.F_z4_static[c31_i0];
  }

  c31_gb_y = NULL;
  sf_mex_assign(&c31_gb_y, sf_mex_create("y", c31_cb_u, 0, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_addfield(c31_t_y, c31_gb_y, "F_z4_static", "F_z4_static", 0);
  c31_db_u = c31_p_u.Rw;
  c31_hb_y = NULL;
  sf_mex_assign(&c31_hb_y, sf_mex_create("y", &c31_db_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c31_t_y, c31_hb_y, "Rw", "Rw", 0);
  c31_eb_u = c31_p_u.r_long;
  c31_ib_y = NULL;
  sf_mex_assign(&c31_ib_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c31_i1 = 0; c31_i1 < 3; c31_i1++) {
    c31_fb_u[c31_i1] = c31_eb_u.fl[c31_i1];
  }

  c31_jb_y = NULL;
  sf_mex_assign(&c31_jb_y, sf_mex_create("y", c31_fb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c31_ib_y, c31_jb_y, "fl", "fl", 0);
  for (c31_i2 = 0; c31_i2 < 3; c31_i2++) {
    c31_gb_u[c31_i2] = c31_eb_u.fr[c31_i2];
  }

  c31_kb_y = NULL;
  sf_mex_assign(&c31_kb_y, sf_mex_create("y", c31_gb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c31_ib_y, c31_kb_y, "fr", "fr", 0);
  for (c31_i3 = 0; c31_i3 < 3; c31_i3++) {
    c31_hb_u[c31_i3] = c31_eb_u.rl[c31_i3];
  }

  c31_lb_y = NULL;
  sf_mex_assign(&c31_lb_y, sf_mex_create("y", c31_hb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c31_ib_y, c31_lb_y, "rl", "rl", 0);
  for (c31_i4 = 0; c31_i4 < 3; c31_i4++) {
    c31_ib_u[c31_i4] = c31_eb_u.rr[c31_i4];
  }

  c31_mb_y = NULL;
  sf_mex_assign(&c31_mb_y, sf_mex_create("y", c31_ib_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c31_ib_y, c31_mb_y, "rr", "rr", 0);
  sf_mex_addfield(c31_t_y, c31_ib_y, "r_long", "r_long", 0);
  c31_eb_u = c31_p_u.r_lat;
  c31_nb_y = NULL;
  sf_mex_assign(&c31_nb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c31_i5 = 0; c31_i5 < 3; c31_i5++) {
    c31_jb_u[c31_i5] = c31_eb_u.fl[c31_i5];
  }

  c31_ob_y = NULL;
  sf_mex_assign(&c31_ob_y, sf_mex_create("y", c31_jb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c31_nb_y, c31_ob_y, "fl", "fl", 0);
  for (c31_i6 = 0; c31_i6 < 3; c31_i6++) {
    c31_kb_u[c31_i6] = c31_eb_u.fr[c31_i6];
  }

  c31_pb_y = NULL;
  sf_mex_assign(&c31_pb_y, sf_mex_create("y", c31_kb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c31_nb_y, c31_pb_y, "fr", "fr", 0);
  for (c31_i7 = 0; c31_i7 < 3; c31_i7++) {
    c31_lb_u[c31_i7] = c31_eb_u.rl[c31_i7];
  }

  c31_qb_y = NULL;
  sf_mex_assign(&c31_qb_y, sf_mex_create("y", c31_lb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c31_nb_y, c31_qb_y, "rl", "rl", 0);
  for (c31_i8 = 0; c31_i8 < 3; c31_i8++) {
    c31_mb_u[c31_i8] = c31_eb_u.rr[c31_i8];
  }

  c31_rb_y = NULL;
  sf_mex_assign(&c31_rb_y, sf_mex_create("y", c31_mb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c31_nb_y, c31_rb_y, "rr", "rr", 0);
  sf_mex_addfield(c31_t_y, c31_nb_y, "r_lat", "r_lat", 0);
  c31_eb_u = c31_p_u.r_lever;
  c31_sb_y = NULL;
  sf_mex_assign(&c31_sb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c31_i9 = 0; c31_i9 < 3; c31_i9++) {
    c31_nb_u[c31_i9] = c31_eb_u.fl[c31_i9];
  }

  c31_tb_y = NULL;
  sf_mex_assign(&c31_tb_y, sf_mex_create("y", c31_nb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c31_sb_y, c31_tb_y, "fl", "fl", 0);
  for (c31_i10 = 0; c31_i10 < 3; c31_i10++) {
    c31_ob_u[c31_i10] = c31_eb_u.fr[c31_i10];
  }

  c31_ub_y = NULL;
  sf_mex_assign(&c31_ub_y, sf_mex_create("y", c31_ob_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c31_sb_y, c31_ub_y, "fr", "fr", 0);
  for (c31_i11 = 0; c31_i11 < 3; c31_i11++) {
    c31_pb_u[c31_i11] = c31_eb_u.rl[c31_i11];
  }

  c31_vb_y = NULL;
  sf_mex_assign(&c31_vb_y, sf_mex_create("y", c31_pb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c31_sb_y, c31_vb_y, "rl", "rl", 0);
  for (c31_i12 = 0; c31_i12 < 3; c31_i12++) {
    c31_qb_u[c31_i12] = c31_eb_u.rr[c31_i12];
  }

  c31_wb_y = NULL;
  sf_mex_assign(&c31_wb_y, sf_mex_create("y", c31_qb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c31_sb_y, c31_wb_y, "rr", "rr", 0);
  sf_mex_addfield(c31_t_y, c31_sb_y, "r_lever", "r_lever", 0);
  c31_eb_u = c31_p_u.r_pivot;
  c31_xb_y = NULL;
  sf_mex_assign(&c31_xb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c31_i13 = 0; c31_i13 < 3; c31_i13++) {
    c31_rb_u[c31_i13] = c31_eb_u.fl[c31_i13];
  }

  c31_yb_y = NULL;
  sf_mex_assign(&c31_yb_y, sf_mex_create("y", c31_rb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c31_xb_y, c31_yb_y, "fl", "fl", 0);
  for (c31_i14 = 0; c31_i14 < 3; c31_i14++) {
    c31_sb_u[c31_i14] = c31_eb_u.fr[c31_i14];
  }

  c31_ac_y = NULL;
  sf_mex_assign(&c31_ac_y, sf_mex_create("y", c31_sb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c31_xb_y, c31_ac_y, "fr", "fr", 0);
  for (c31_i15 = 0; c31_i15 < 3; c31_i15++) {
    c31_tb_u[c31_i15] = c31_eb_u.rl[c31_i15];
  }

  c31_bc_y = NULL;
  sf_mex_assign(&c31_bc_y, sf_mex_create("y", c31_tb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c31_xb_y, c31_bc_y, "rl", "rl", 0);
  for (c31_i16 = 0; c31_i16 < 3; c31_i16++) {
    c31_ub_u[c31_i16] = c31_eb_u.rr[c31_i16];
  }

  c31_cc_y = NULL;
  sf_mex_assign(&c31_cc_y, sf_mex_create("y", c31_ub_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c31_xb_y, c31_cc_y, "rr", "rr", 0);
  sf_mex_addfield(c31_t_y, c31_xb_y, "r_pivot", "r_pivot", 0);
  c31_vb_u = c31_p_u.cw;
  c31_dc_y = NULL;
  sf_mex_assign(&c31_dc_y, sf_mex_create("y", &c31_vb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c31_t_y, c31_dc_y, "cw", "cw", 0);
  c31_wb_u = c31_p_u.carb_f;
  c31_ec_y = NULL;
  sf_mex_assign(&c31_ec_y, sf_mex_create("y", &c31_wb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c31_t_y, c31_ec_y, "carb_f", "carb_f", 0);
  c31_xb_u = c31_p_u.carb_r;
  c31_fc_y = NULL;
  sf_mex_assign(&c31_fc_y, sf_mex_create("y", &c31_xb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c31_t_y, c31_fc_y, "carb_r", "carb_r", 0);
  c31_yb_u = c31_p_u.dw;
  c31_gc_y = NULL;
  sf_mex_assign(&c31_gc_y, sf_mex_create("y", &c31_yb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c31_t_y, c31_gc_y, "dw", "dw", 0);
  c31_ac_u = c31_p_u.Jw;
  c31_hc_y = NULL;
  sf_mex_assign(&c31_hc_y, sf_mex_create("y", &c31_ac_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c31_t_y, c31_hc_y, "Jw", "Jw", 0);
  c31_bc_u = c31_p_u.C0;
  c31_ic_y = NULL;
  sf_mex_assign(&c31_ic_y, sf_mex_create("y", &c31_bc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c31_t_y, c31_ic_y, "C0", "C0", 0);
  c31_cc_u = c31_p_u.RelaxLength;
  c31_jc_y = NULL;
  sf_mex_assign(&c31_jc_y, sf_mex_create("y", &c31_cc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c31_t_y, c31_jc_y, "RelaxLength", "RelaxLength", 0);
  c31_dc_u = c31_p_u.RRC;
  c31_kc_y = NULL;
  sf_mex_assign(&c31_kc_y, sf_mex_create("y", &c31_dc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c31_t_y, c31_kc_y, "RRC", "RRC", 0);
  c31_ec_u = c31_p_u.Pmax;
  c31_lc_y = NULL;
  sf_mex_assign(&c31_lc_y, sf_mex_create("y", &c31_ec_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c31_t_y, c31_lc_y, "Pmax", "Pmax", 0);
  c31_fc_u = c31_p_u.PropDistrFrnt;
  c31_mc_y = NULL;
  sf_mex_assign(&c31_mc_y, sf_mex_create("y", &c31_fc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c31_t_y, c31_mc_y, "PropDistrFrnt", "PropDistrFrnt", 0);
  c31_gc_u = c31_p_u.BrkDistrFrnt;
  c31_nc_y = NULL;
  sf_mex_assign(&c31_nc_y, sf_mex_create("y", &c31_gc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c31_t_y, c31_nc_y, "BrkDistrFrnt", "BrkDistrFrnt", 0);
  c31_hc_u = c31_p_u.SteRatio;
  c31_oc_y = NULL;
  sf_mex_assign(&c31_oc_y, sf_mex_create("y", &c31_hc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c31_t_y, c31_oc_y, "SteRatio", "SteRatio", 0);
  sf_mex_addfield(c31_y, c31_t_y, "Veh", "Veh", 0);
  c31_ic_u = c31_u.Drvr;
  c31_pc_y = NULL;
  sf_mex_assign(&c31_pc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c31_jc_u = c31_ic_u.v_set;
  c31_qc_y = NULL;
  sf_mex_assign(&c31_qc_y, sf_mex_create("y", &c31_jc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c31_pc_y, c31_qc_y, "v_set", "v_set", 0);
  sf_mex_addfield(c31_y, c31_pc_y, "Drvr", "Drvr", 0);
  c31_kc_u = c31_u.Init;
  c31_rc_y = NULL;
  sf_mex_assign(&c31_rc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c31_lc_u = c31_kc_u.v_x;
  c31_sc_y = NULL;
  sf_mex_assign(&c31_sc_y, sf_mex_create("y", &c31_lc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c31_rc_y, c31_sc_y, "v_x", "v_x", 0);
  c31_mc_u = c31_kc_u.F_fz;
  c31_tc_y = NULL;
  sf_mex_assign(&c31_tc_y, sf_mex_create("y", &c31_mc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c31_rc_y, c31_tc_y, "F_fz", "F_fz", 0);
  c31_nc_u = c31_kc_u.F_rz;
  c31_uc_y = NULL;
  sf_mex_assign(&c31_uc_y, sf_mex_create("y", &c31_nc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c31_rc_y, c31_uc_y, "F_rz", "F_rz", 0);
  sf_mex_addfield(c31_y, c31_rc_y, "Init", "Init", 0);
  sf_mex_assign(&c31_mxArrayOutData, c31_y, false);
  return c31_mxArrayOutData;
}

static void c31_d_emlrt_marshallIn(SFc31_ModifiedInstanceStruct *chartInstance,
  const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId,
  c31_struct_iBlsPBO3AGnt69vDoTx5zD *c31_y)
{
  emlrtMsgIdentifier c31_thisId;
  static const char * c31_fieldNames[4] = { "Env", "Veh", "Drvr", "Init" };

  c31_thisId.fParent = c31_parentId;
  sf_mex_check_struct(c31_parentId, c31_u, 4, c31_fieldNames, 0U, NULL);
  c31_thisId.fIdentifier = "Env";
  c31_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c31_u, "Env",
    "Env", 0)), &c31_thisId, &c31_y->Env);
  c31_thisId.fIdentifier = "Veh";
  c31_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c31_u, "Veh",
    "Veh", 0)), &c31_thisId, &c31_y->Veh);
  c31_thisId.fIdentifier = "Drvr";
  c31_y->Drvr = c31_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c31_u, "Drvr", "Drvr", 0)), &c31_thisId);
  c31_thisId.fIdentifier = "Init";
  c31_y->Init = c31_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c31_u, "Init", "Init", 0)), &c31_thisId);
  sf_mex_destroy(&c31_u);
}

static void c31_e_emlrt_marshallIn(SFc31_ModifiedInstanceStruct *chartInstance,
  const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId,
  c31_struct_Nst2vGTExxHsg85EUOj9EH *c31_y)
{
  emlrtMsgIdentifier c31_thisId;
  static const char * c31_fieldNames[7] = { "g", "left1", "right1", "right2",
    "left2", "right3", "mu" };

  c31_thisId.fParent = c31_parentId;
  sf_mex_check_struct(c31_parentId, c31_u, 7, c31_fieldNames, 0U, NULL);
  c31_thisId.fIdentifier = "g";
  c31_y->g = c31_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c31_u, "g", "g", 0)), &c31_thisId);
  c31_thisId.fIdentifier = "left1";
  c31_y->left1 = c31_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c31_u, "left1", "left1", 0)), &c31_thisId);
  c31_thisId.fIdentifier = "right1";
  c31_y->right1 = c31_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c31_u, "right1", "right1", 0)), &c31_thisId);
  c31_thisId.fIdentifier = "right2";
  c31_y->right2 = c31_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c31_u, "right2", "right2", 0)), &c31_thisId);
  c31_thisId.fIdentifier = "left2";
  c31_y->left2 = c31_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c31_u, "left2", "left2", 0)), &c31_thisId);
  c31_thisId.fIdentifier = "right3";
  c31_y->right3 = c31_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c31_u, "right3", "right3", 0)), &c31_thisId);
  c31_thisId.fIdentifier = "mu";
  c31_y->mu = c31_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c31_u, "mu", "mu", 0)), &c31_thisId);
  sf_mex_destroy(&c31_u);
}

static c31_struct_HhckT6rntEraqECYVIDvCC c31_f_emlrt_marshallIn
  (SFc31_ModifiedInstanceStruct *chartInstance, const mxArray *c31_u, const
   emlrtMsgIdentifier *c31_parentId)
{
  c31_struct_HhckT6rntEraqECYVIDvCC c31_y;
  emlrtMsgIdentifier c31_thisId;
  static const char * c31_fieldNames[2] = { "x", "y" };

  c31_thisId.fParent = c31_parentId;
  sf_mex_check_struct(c31_parentId, c31_u, 2, c31_fieldNames, 0U, NULL);
  c31_thisId.fIdentifier = "x";
  c31_y.x = c31_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c31_u, "x", "x", 0)), &c31_thisId);
  c31_thisId.fIdentifier = "y";
  c31_y.y = c31_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c31_u, "y", "y", 0)), &c31_thisId);
  sf_mex_destroy(&c31_u);
  return c31_y;
}

static void c31_g_emlrt_marshallIn(SFc31_ModifiedInstanceStruct *chartInstance,
  const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId,
  c31_struct_ZCmOWPuqBDw16FSOVVD00 *c31_y)
{
  emlrtMsgIdentifier c31_thisId;
  static const char * c31_fieldNames[29] = { "m", "Jz", "m_sprung", "Jx_sprung",
    "Jy_sprung", "lf", "lr", "L", "TrackWidth", "h", "HalfRohACd", "F_z4_static",
    "Rw", "r_long", "r_lat", "r_lever", "r_pivot", "cw", "carb_f", "carb_r",
    "dw", "Jw", "C0", "RelaxLength", "RRC", "Pmax", "PropDistrFrnt",
    "BrkDistrFrnt", "SteRatio" };

  c31_thisId.fParent = c31_parentId;
  sf_mex_check_struct(c31_parentId, c31_u, 29, c31_fieldNames, 0U, NULL);
  c31_thisId.fIdentifier = "m";
  c31_y->m = c31_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c31_u, "m", "m", 0)), &c31_thisId);
  c31_thisId.fIdentifier = "Jz";
  c31_y->Jz = c31_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c31_u, "Jz", "Jz", 0)), &c31_thisId);
  c31_thisId.fIdentifier = "m_sprung";
  c31_y->m_sprung = c31_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c31_u, "m_sprung", "m_sprung", 0)), &c31_thisId);
  c31_thisId.fIdentifier = "Jx_sprung";
  c31_y->Jx_sprung = c31_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c31_u, "Jx_sprung", "Jx_sprung", 0)), &c31_thisId);
  c31_thisId.fIdentifier = "Jy_sprung";
  c31_y->Jy_sprung = c31_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c31_u, "Jy_sprung", "Jy_sprung", 0)), &c31_thisId);
  c31_thisId.fIdentifier = "lf";
  c31_y->lf = c31_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c31_u, "lf", "lf", 0)), &c31_thisId);
  c31_thisId.fIdentifier = "lr";
  c31_y->lr = c31_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c31_u, "lr", "lr", 0)), &c31_thisId);
  c31_thisId.fIdentifier = "L";
  c31_y->L = c31_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c31_u, "L", "L", 0)), &c31_thisId);
  c31_thisId.fIdentifier = "TrackWidth";
  c31_y->TrackWidth = c31_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c31_u, "TrackWidth", "TrackWidth", 0)), &c31_thisId);
  c31_thisId.fIdentifier = "h";
  c31_y->h = c31_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c31_u, "h", "h", 0)), &c31_thisId);
  c31_thisId.fIdentifier = "HalfRohACd";
  c31_y->HalfRohACd = c31_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c31_u, "HalfRohACd", "HalfRohACd", 0)), &c31_thisId);
  c31_thisId.fIdentifier = "F_z4_static";
  c31_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c31_u,
    "F_z4_static", "F_z4_static", 0)), &c31_thisId, c31_y->F_z4_static);
  c31_thisId.fIdentifier = "Rw";
  c31_y->Rw = c31_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c31_u, "Rw", "Rw", 0)), &c31_thisId);
  c31_thisId.fIdentifier = "r_long";
  c31_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c31_u,
    "r_long", "r_long", 0)), &c31_thisId, &c31_y->r_long);
  c31_thisId.fIdentifier = "r_lat";
  c31_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c31_u,
    "r_lat", "r_lat", 0)), &c31_thisId, &c31_y->r_lat);
  c31_thisId.fIdentifier = "r_lever";
  c31_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c31_u,
    "r_lever", "r_lever", 0)), &c31_thisId, &c31_y->r_lever);
  c31_thisId.fIdentifier = "r_pivot";
  c31_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c31_u,
    "r_pivot", "r_pivot", 0)), &c31_thisId, &c31_y->r_pivot);
  c31_thisId.fIdentifier = "cw";
  c31_y->cw = c31_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c31_u, "cw", "cw", 0)), &c31_thisId);
  c31_thisId.fIdentifier = "carb_f";
  c31_y->carb_f = c31_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c31_u, "carb_f", "carb_f", 0)), &c31_thisId);
  c31_thisId.fIdentifier = "carb_r";
  c31_y->carb_r = c31_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c31_u, "carb_r", "carb_r", 0)), &c31_thisId);
  c31_thisId.fIdentifier = "dw";
  c31_y->dw = c31_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c31_u, "dw", "dw", 0)), &c31_thisId);
  c31_thisId.fIdentifier = "Jw";
  c31_y->Jw = c31_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c31_u, "Jw", "Jw", 0)), &c31_thisId);
  c31_thisId.fIdentifier = "C0";
  c31_y->C0 = c31_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c31_u, "C0", "C0", 0)), &c31_thisId);
  c31_thisId.fIdentifier = "RelaxLength";
  c31_y->RelaxLength = c31_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c31_u, "RelaxLength", "RelaxLength", 0)), &c31_thisId);
  c31_thisId.fIdentifier = "RRC";
  c31_y->RRC = c31_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c31_u, "RRC", "RRC", 0)), &c31_thisId);
  c31_thisId.fIdentifier = "Pmax";
  c31_y->Pmax = c31_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c31_u, "Pmax", "Pmax", 0)), &c31_thisId);
  c31_thisId.fIdentifier = "PropDistrFrnt";
  c31_y->PropDistrFrnt = c31_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c31_u, "PropDistrFrnt", "PropDistrFrnt", 0)), &c31_thisId);
  c31_thisId.fIdentifier = "BrkDistrFrnt";
  c31_y->BrkDistrFrnt = c31_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c31_u, "BrkDistrFrnt", "BrkDistrFrnt", 0)), &c31_thisId);
  c31_thisId.fIdentifier = "SteRatio";
  c31_y->SteRatio = c31_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c31_u, "SteRatio", "SteRatio", 0)), &c31_thisId);
  sf_mex_destroy(&c31_u);
}

static void c31_h_emlrt_marshallIn(SFc31_ModifiedInstanceStruct *chartInstance,
  const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId, real_T c31_y[4])
{
  real_T c31_dv0[4];
  int32_T c31_i17;
  (void)chartInstance;
  sf_mex_import(c31_parentId, sf_mex_dup(c31_u), c31_dv0, 1, 0, 0U, 1, 0U, 2, 1,
                4);
  for (c31_i17 = 0; c31_i17 < 4; c31_i17++) {
    c31_y[c31_i17] = c31_dv0[c31_i17];
  }

  sf_mex_destroy(&c31_u);
}

static void c31_i_emlrt_marshallIn(SFc31_ModifiedInstanceStruct *chartInstance,
  const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId,
  c31_struct_ZKAzdrl7umDGJoC14aoVKC *c31_y)
{
  emlrtMsgIdentifier c31_thisId;
  static const char * c31_fieldNames[4] = { "fl", "fr", "rl", "rr" };

  c31_thisId.fParent = c31_parentId;
  sf_mex_check_struct(c31_parentId, c31_u, 4, c31_fieldNames, 0U, NULL);
  c31_thisId.fIdentifier = "fl";
  c31_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c31_u, "fl",
    "fl", 0)), &c31_thisId, c31_y->fl);
  c31_thisId.fIdentifier = "fr";
  c31_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c31_u, "fr",
    "fr", 0)), &c31_thisId, c31_y->fr);
  c31_thisId.fIdentifier = "rl";
  c31_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c31_u, "rl",
    "rl", 0)), &c31_thisId, c31_y->rl);
  c31_thisId.fIdentifier = "rr";
  c31_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c31_u, "rr",
    "rr", 0)), &c31_thisId, c31_y->rr);
  sf_mex_destroy(&c31_u);
}

static void c31_j_emlrt_marshallIn(SFc31_ModifiedInstanceStruct *chartInstance,
  const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId, real_T c31_y[3])
{
  real_T c31_dv1[3];
  int32_T c31_i18;
  (void)chartInstance;
  sf_mex_import(c31_parentId, sf_mex_dup(c31_u), c31_dv1, 1, 0, 0U, 1, 0U, 2, 3,
                1);
  for (c31_i18 = 0; c31_i18 < 3; c31_i18++) {
    c31_y[c31_i18] = c31_dv1[c31_i18];
  }

  sf_mex_destroy(&c31_u);
}

static c31_struct_r4FNviKwHfdhB8nQjvQv9 c31_k_emlrt_marshallIn
  (SFc31_ModifiedInstanceStruct *chartInstance, const mxArray *c31_u, const
   emlrtMsgIdentifier *c31_parentId)
{
  c31_struct_r4FNviKwHfdhB8nQjvQv9 c31_y;
  emlrtMsgIdentifier c31_thisId;
  static const char * c31_fieldNames[1] = { "v_set" };

  c31_thisId.fParent = c31_parentId;
  sf_mex_check_struct(c31_parentId, c31_u, 1, c31_fieldNames, 0U, NULL);
  c31_thisId.fIdentifier = "v_set";
  c31_y.v_set = c31_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c31_u, "v_set", "v_set", 0)),
    &c31_thisId);
  sf_mex_destroy(&c31_u);
  return c31_y;
}

static c31_struct_Y9F1qlBi9AhssksPwemA4G c31_l_emlrt_marshallIn
  (SFc31_ModifiedInstanceStruct *chartInstance, const mxArray *c31_u, const
   emlrtMsgIdentifier *c31_parentId)
{
  c31_struct_Y9F1qlBi9AhssksPwemA4G c31_y;
  emlrtMsgIdentifier c31_thisId;
  static const char * c31_fieldNames[3] = { "v_x", "F_fz", "F_rz" };

  c31_thisId.fParent = c31_parentId;
  sf_mex_check_struct(c31_parentId, c31_u, 3, c31_fieldNames, 0U, NULL);
  c31_thisId.fIdentifier = "v_x";
  c31_y.v_x = c31_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c31_u, "v_x", "v_x", 0)), &c31_thisId);
  c31_thisId.fIdentifier = "F_fz";
  c31_y.F_fz = c31_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c31_u, "F_fz", "F_fz", 0)), &c31_thisId);
  c31_thisId.fIdentifier = "F_rz";
  c31_y.F_rz = c31_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c31_u, "F_rz", "F_rz", 0)), &c31_thisId);
  sf_mex_destroy(&c31_u);
  return c31_y;
}

static void c31_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c31_mxArrayInData, const char_T *c31_varName, void *c31_outData)
{
  const mxArray *c31_b_Par;
  const char_T *c31_identifier;
  emlrtMsgIdentifier c31_thisId;
  c31_struct_iBlsPBO3AGnt69vDoTx5zD c31_y;
  SFc31_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc31_ModifiedInstanceStruct *)chartInstanceVoid;
  c31_b_Par = sf_mex_dup(c31_mxArrayInData);
  c31_identifier = c31_varName;
  c31_thisId.fIdentifier = c31_identifier;
  c31_thisId.fParent = NULL;
  c31_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c31_b_Par), &c31_thisId,
    &c31_y);
  sf_mex_destroy(&c31_b_Par);
  *(c31_struct_iBlsPBO3AGnt69vDoTx5zD *)c31_outData = c31_y;
  sf_mex_destroy(&c31_mxArrayInData);
}

static const mxArray *c31_c_sf_marshallOut(void *chartInstanceVoid, void
  *c31_inData)
{
  const mxArray *c31_mxArrayOutData = NULL;
  real_T c31_u;
  const mxArray *c31_y = NULL;
  SFc31_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc31_ModifiedInstanceStruct *)chartInstanceVoid;
  c31_mxArrayOutData = NULL;
  c31_u = *(real_T *)c31_inData;
  c31_y = NULL;
  sf_mex_assign(&c31_y, sf_mex_create("y", &c31_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c31_mxArrayOutData, c31_y, false);
  return c31_mxArrayOutData;
}

static void c31_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c31_mxArrayInData, const char_T *c31_varName, void *c31_outData)
{
  const mxArray *c31_nargout;
  const char_T *c31_identifier;
  emlrtMsgIdentifier c31_thisId;
  real_T c31_y;
  SFc31_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc31_ModifiedInstanceStruct *)chartInstanceVoid;
  c31_nargout = sf_mex_dup(c31_mxArrayInData);
  c31_identifier = c31_varName;
  c31_thisId.fIdentifier = c31_identifier;
  c31_thisId.fParent = NULL;
  c31_y = c31_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c31_nargout),
    &c31_thisId);
  sf_mex_destroy(&c31_nargout);
  *(real_T *)c31_outData = c31_y;
  sf_mex_destroy(&c31_mxArrayInData);
}

const mxArray *sf_c31_Modified_get_eml_resolved_functions_info(void)
{
  const mxArray *c31_nameCaptureInfo = NULL;
  c31_nameCaptureInfo = NULL;
  sf_mex_assign(&c31_nameCaptureInfo, sf_mex_createstruct("structure", 2, 11, 1),
                false);
  c31_info_helper(&c31_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c31_nameCaptureInfo);
  return c31_nameCaptureInfo;
}

static void c31_info_helper(const mxArray **c31_info)
{
  const mxArray *c31_rhs0 = NULL;
  const mxArray *c31_lhs0 = NULL;
  const mxArray *c31_rhs1 = NULL;
  const mxArray *c31_lhs1 = NULL;
  const mxArray *c31_rhs2 = NULL;
  const mxArray *c31_lhs2 = NULL;
  const mxArray *c31_rhs3 = NULL;
  const mxArray *c31_lhs3 = NULL;
  const mxArray *c31_rhs4 = NULL;
  const mxArray *c31_lhs4 = NULL;
  const mxArray *c31_rhs5 = NULL;
  const mxArray *c31_lhs5 = NULL;
  const mxArray *c31_rhs6 = NULL;
  const mxArray *c31_lhs6 = NULL;
  const mxArray *c31_rhs7 = NULL;
  const mxArray *c31_lhs7 = NULL;
  const mxArray *c31_rhs8 = NULL;
  const mxArray *c31_lhs8 = NULL;
  const mxArray *c31_rhs9 = NULL;
  const mxArray *c31_lhs9 = NULL;
  const mxArray *c31_rhs10 = NULL;
  const mxArray *c31_lhs10 = NULL;
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("min"), "name", "name", 0);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(1311255318U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c31_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c31_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 1);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(1378295984U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c31_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c31_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 2);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 2);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c31_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c31_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 3);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c31_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c31_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 4);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 4);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c31_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c31_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 5);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 5);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c31_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c31_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 6);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 6);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c31_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c31_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 7);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 7);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c31_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c31_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 8);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 8);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c31_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c31_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(""), "context", "context", 9);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("max"), "name", "name", 9);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(1311255316U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c31_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c31_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 10);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(1378295984U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c31_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c31_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_lhs10), "lhs", "lhs",
                  10);
  sf_mex_destroy(&c31_rhs0);
  sf_mex_destroy(&c31_lhs0);
  sf_mex_destroy(&c31_rhs1);
  sf_mex_destroy(&c31_lhs1);
  sf_mex_destroy(&c31_rhs2);
  sf_mex_destroy(&c31_lhs2);
  sf_mex_destroy(&c31_rhs3);
  sf_mex_destroy(&c31_lhs3);
  sf_mex_destroy(&c31_rhs4);
  sf_mex_destroy(&c31_lhs4);
  sf_mex_destroy(&c31_rhs5);
  sf_mex_destroy(&c31_lhs5);
  sf_mex_destroy(&c31_rhs6);
  sf_mex_destroy(&c31_lhs6);
  sf_mex_destroy(&c31_rhs7);
  sf_mex_destroy(&c31_lhs7);
  sf_mex_destroy(&c31_rhs8);
  sf_mex_destroy(&c31_lhs8);
  sf_mex_destroy(&c31_rhs9);
  sf_mex_destroy(&c31_lhs9);
  sf_mex_destroy(&c31_rhs10);
  sf_mex_destroy(&c31_lhs10);
}

static const mxArray *c31_emlrt_marshallOut(const char * c31_u)
{
  const mxArray *c31_y = NULL;
  c31_y = NULL;
  sf_mex_assign(&c31_y, sf_mex_create("y", c31_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c31_u)), false);
  return c31_y;
}

static const mxArray *c31_b_emlrt_marshallOut(const uint32_T c31_u)
{
  const mxArray *c31_y = NULL;
  c31_y = NULL;
  sf_mex_assign(&c31_y, sf_mex_create("y", &c31_u, 7, 0U, 0U, 0U, 0), false);
  return c31_y;
}

static void c31_eml_scalar_eg(SFc31_ModifiedInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *c31_d_sf_marshallOut(void *chartInstanceVoid, void
  *c31_inData)
{
  const mxArray *c31_mxArrayOutData = NULL;
  int32_T c31_u;
  const mxArray *c31_y = NULL;
  SFc31_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc31_ModifiedInstanceStruct *)chartInstanceVoid;
  c31_mxArrayOutData = NULL;
  c31_u = *(int32_T *)c31_inData;
  c31_y = NULL;
  sf_mex_assign(&c31_y, sf_mex_create("y", &c31_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c31_mxArrayOutData, c31_y, false);
  return c31_mxArrayOutData;
}

static int32_T c31_m_emlrt_marshallIn(SFc31_ModifiedInstanceStruct
  *chartInstance, const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId)
{
  int32_T c31_y;
  int32_T c31_i19;
  (void)chartInstance;
  sf_mex_import(c31_parentId, sf_mex_dup(c31_u), &c31_i19, 1, 6, 0U, 0, 0U, 0);
  c31_y = c31_i19;
  sf_mex_destroy(&c31_u);
  return c31_y;
}

static void c31_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c31_mxArrayInData, const char_T *c31_varName, void *c31_outData)
{
  const mxArray *c31_b_sfEvent;
  const char_T *c31_identifier;
  emlrtMsgIdentifier c31_thisId;
  int32_T c31_y;
  SFc31_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc31_ModifiedInstanceStruct *)chartInstanceVoid;
  c31_b_sfEvent = sf_mex_dup(c31_mxArrayInData);
  c31_identifier = c31_varName;
  c31_thisId.fIdentifier = c31_identifier;
  c31_thisId.fParent = NULL;
  c31_y = c31_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c31_b_sfEvent),
    &c31_thisId);
  sf_mex_destroy(&c31_b_sfEvent);
  *(int32_T *)c31_outData = c31_y;
  sf_mex_destroy(&c31_mxArrayInData);
}

static const mxArray *c31_s_xy4_bus_io(void *chartInstanceVoid, void *c31_pData)
{
  const mxArray *c31_mxVal = NULL;
  c31_whl_vec4 c31_tmp;
  SFc31_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc31_ModifiedInstanceStruct *)chartInstanceVoid;
  c31_mxVal = NULL;
  c31_tmp.fl = *(real_T *)&((char_T *)(c31_whl_vec4 *)c31_pData)[0];
  c31_tmp.fr = *(real_T *)&((char_T *)(c31_whl_vec4 *)c31_pData)[8];
  c31_tmp.rl = *(real_T *)&((char_T *)(c31_whl_vec4 *)c31_pData)[16];
  c31_tmp.rr = *(real_T *)&((char_T *)(c31_whl_vec4 *)c31_pData)[24];
  sf_mex_assign(&c31_mxVal, c31_sf_marshallOut(chartInstance, &c31_tmp), false);
  return c31_mxVal;
}

static uint8_T c31_n_emlrt_marshallIn(SFc31_ModifiedInstanceStruct
  *chartInstance, const mxArray *c31_b_is_active_c31_Modified, const char_T
  *c31_identifier)
{
  uint8_T c31_y;
  emlrtMsgIdentifier c31_thisId;
  c31_thisId.fIdentifier = c31_identifier;
  c31_thisId.fParent = NULL;
  c31_y = c31_o_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c31_b_is_active_c31_Modified), &c31_thisId);
  sf_mex_destroy(&c31_b_is_active_c31_Modified);
  return c31_y;
}

static uint8_T c31_o_emlrt_marshallIn(SFc31_ModifiedInstanceStruct
  *chartInstance, const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId)
{
  uint8_T c31_y;
  uint8_T c31_u0;
  (void)chartInstance;
  sf_mex_import(c31_parentId, sf_mex_dup(c31_u), &c31_u0, 1, 3, 0U, 0, 0U, 0);
  c31_y = c31_u0;
  sf_mex_destroy(&c31_u);
  return c31_y;
}

static void init_dsm_address_info(SFc31_ModifiedInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc31_ModifiedInstanceStruct *chartInstance)
{
  chartInstance->c31_s_xy4 = (c31_whl_vec4 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c31_F_xywSS4 = (c31_whl_vec4 *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c31_F_z4 = (c31_whl_vec4 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
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

void sf_c31_Modified_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2570276215U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1510473816U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1298603881U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3121002101U);
}

mxArray* sf_c31_Modified_get_post_codegen_info(void);
mxArray *sf_c31_Modified_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("02t5ILhxBbimPyrbO4goBD");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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
    mxArray* mxPostCodegenInfo = sf_c31_Modified_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c31_Modified_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c31_Modified_jit_fallback_info(void)
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

mxArray *sf_c31_Modified_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c31_Modified_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c31_Modified(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[47],T\"F_xywSS4\",},{M[8],M[0],T\"is_active_c31_Modified\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c31_Modified_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc31_ModifiedInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc31_ModifiedInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ModifiedMachineNumber_,
           31,
           1,
           1,
           0,
           4,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"s_xy4");
          _SFD_SET_DATA_PROPS(1,2,0,1,"F_xywSS4");
          _SFD_SET_DATA_PROPS(2,1,1,0,"F_z4");
          _SFD_SET_DATA_PROPS(3,10,0,0,"Par");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,532);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c31_s_xy4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c31_s_xy4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c31_s_xy4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c31_b_sf_marshallOut,(MexInFcnForType)
          c31_b_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c31_s_xy4);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c31_F_xywSS4);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c31_F_z4);
        _SFD_SET_DATA_VALUE_PTR(3U, &chartInstance->c31_Par);
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
  return "pCGJpivanLlOQcKqfmeI7D";
}

static void sf_opaque_initialize_c31_Modified(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc31_ModifiedInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c31_Modified((SFc31_ModifiedInstanceStruct*)
    chartInstanceVar);
  initialize_c31_Modified((SFc31_ModifiedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c31_Modified(void *chartInstanceVar)
{
  enable_c31_Modified((SFc31_ModifiedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c31_Modified(void *chartInstanceVar)
{
  disable_c31_Modified((SFc31_ModifiedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c31_Modified(void *chartInstanceVar)
{
  sf_gateway_c31_Modified((SFc31_ModifiedInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c31_Modified(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c31_Modified((SFc31_ModifiedInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c31_Modified(SimStruct* S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c31_Modified((SFc31_ModifiedInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c31_Modified(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc31_ModifiedInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Modified_optimization_info();
    }

    finalize_c31_Modified((SFc31_ModifiedInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc31_Modified((SFc31_ModifiedInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c31_Modified(SimStruct *S)
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
    initialize_params_c31_Modified((SFc31_ModifiedInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c31_Modified(SimStruct *S)
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
      31);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,31,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,31,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,31);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,31,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,31,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,31);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1127168671U));
  ssSetChecksum1(S,(211819700U));
  ssSetChecksum2(S,(78811287U));
  ssSetChecksum3(S,(4229325603U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c31_Modified(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c31_Modified(SimStruct *S)
{
  SFc31_ModifiedInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc31_ModifiedInstanceStruct *)utMalloc(sizeof
    (SFc31_ModifiedInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc31_ModifiedInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c31_Modified;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c31_Modified;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c31_Modified;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c31_Modified;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c31_Modified;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c31_Modified;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c31_Modified;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c31_Modified;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c31_Modified;
  chartInstance->chartInfo.mdlStart = mdlStart_c31_Modified;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c31_Modified;
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

void c31_Modified_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c31_Modified(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c31_Modified(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c31_Modified(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c31_Modified_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
