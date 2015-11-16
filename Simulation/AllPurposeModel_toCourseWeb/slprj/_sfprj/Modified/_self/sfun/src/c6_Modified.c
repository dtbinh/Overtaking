/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Modified_sfun.h"
#include "c6_Modified.h"
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
static const char * c6_debug_family_names[7] = { "nargin", "nargout", "w_4",
  "F_xywSS4", "F_xyw4", "Par", "derF_xyw4" };

/* Function Declarations */
static void initialize_c6_Modified(SFc6_ModifiedInstanceStruct *chartInstance);
static void initialize_params_c6_Modified(SFc6_ModifiedInstanceStruct
  *chartInstance);
static void enable_c6_Modified(SFc6_ModifiedInstanceStruct *chartInstance);
static void disable_c6_Modified(SFc6_ModifiedInstanceStruct *chartInstance);
static void c6_update_debugger_state_c6_Modified(SFc6_ModifiedInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c6_Modified(SFc6_ModifiedInstanceStruct
  *chartInstance);
static void set_sim_state_c6_Modified(SFc6_ModifiedInstanceStruct *chartInstance,
  const mxArray *c6_st);
static void finalize_c6_Modified(SFc6_ModifiedInstanceStruct *chartInstance);
static void sf_gateway_c6_Modified(SFc6_ModifiedInstanceStruct *chartInstance);
static void mdl_start_c6_Modified(SFc6_ModifiedInstanceStruct *chartInstance);
static void initSimStructsc6_Modified(SFc6_ModifiedInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber, uint32_T c6_instanceNumber);
static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData);
static c6_whl_vec4 c6_emlrt_marshallIn(SFc6_ModifiedInstanceStruct
  *chartInstance, const mxArray *c6_b_derF_xyw4, const char_T *c6_identifier);
static c6_whl_vec4 c6_b_emlrt_marshallIn(SFc6_ModifiedInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static real_T c6_c_emlrt_marshallIn(SFc6_ModifiedInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static void c6_d_emlrt_marshallIn(SFc6_ModifiedInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  c6_struct_iBlsPBO3AGnt69vDoTx5zD *c6_y);
static void c6_e_emlrt_marshallIn(SFc6_ModifiedInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  c6_struct_Nst2vGTExxHsg85EUOj9EH *c6_y);
static c6_struct_HhckT6rntEraqECYVIDvCC c6_f_emlrt_marshallIn
  (SFc6_ModifiedInstanceStruct *chartInstance, const mxArray *c6_u, const
   emlrtMsgIdentifier *c6_parentId);
static void c6_g_emlrt_marshallIn(SFc6_ModifiedInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  c6_struct_ZCmOWPuqBDw16FSOVVD00 *c6_y);
static void c6_h_emlrt_marshallIn(SFc6_ModifiedInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, real_T c6_y[4]);
static void c6_i_emlrt_marshallIn(SFc6_ModifiedInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  c6_struct_ZKAzdrl7umDGJoC14aoVKC *c6_y);
static void c6_j_emlrt_marshallIn(SFc6_ModifiedInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, real_T c6_y[3]);
static c6_struct_r4FNviKwHfdhB8nQjvQv9 c6_k_emlrt_marshallIn
  (SFc6_ModifiedInstanceStruct *chartInstance, const mxArray *c6_u, const
   emlrtMsgIdentifier *c6_parentId);
static c6_struct_Y9F1qlBi9AhssksPwemA4G c6_l_emlrt_marshallIn
  (SFc6_ModifiedInstanceStruct *chartInstance, const mxArray *c6_u, const
   emlrtMsgIdentifier *c6_parentId);
static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static void c6_info_helper(const mxArray **c6_info);
static const mxArray *c6_emlrt_marshallOut(const char * c6_u);
static const mxArray *c6_b_emlrt_marshallOut(const uint32_T c6_u);
static const mxArray *c6_d_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static int32_T c6_m_emlrt_marshallIn(SFc6_ModifiedInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_w_4_bus_io(void *chartInstanceVoid, void *c6_pData);
static uint8_T c6_n_emlrt_marshallIn(SFc6_ModifiedInstanceStruct *chartInstance,
  const mxArray *c6_b_is_active_c6_Modified, const char_T *c6_identifier);
static uint8_T c6_o_emlrt_marshallIn(SFc6_ModifiedInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void init_dsm_address_info(SFc6_ModifiedInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc6_ModifiedInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c6_Modified(SFc6_ModifiedInstanceStruct *chartInstance)
{
  chartInstance->c6_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c6_is_active_c6_Modified = 0U;
}

static void initialize_params_c6_Modified(SFc6_ModifiedInstanceStruct
  *chartInstance)
{
  const mxArray *c6_m0 = NULL;
  const mxArray *c6_mxField;
  const mxArray *c6_m1 = NULL;
  const mxArray *c6_b_mxField;
  c6_struct_iBlsPBO3AGnt69vDoTx5zD c6_r0;
  const mxArray *c6_m2 = NULL;
  const mxArray *c6_c_mxField;
  const mxArray *c6_m3 = NULL;
  const mxArray *c6_d_mxField;
  const mxArray *c6_m4 = NULL;
  const mxArray *c6_e_mxField;
  const mxArray *c6_m5 = NULL;
  const mxArray *c6_f_mxField;
  const mxArray *c6_m6 = NULL;
  const mxArray *c6_g_mxField;
  const mxArray *c6_m7 = NULL;
  const mxArray *c6_h_mxField;
  const mxArray *c6_m8 = NULL;
  const mxArray *c6_i_mxField;
  const mxArray *c6_m9 = NULL;
  const mxArray *c6_j_mxField;
  const mxArray *c6_m10 = NULL;
  const mxArray *c6_k_mxField;
  const mxArray *c6_m11 = NULL;
  const mxArray *c6_l_mxField;
  const mxArray *c6_m12 = NULL;
  const mxArray *c6_m_mxField;
  const mxArray *c6_m13 = NULL;
  const mxArray *c6_n_mxField;
  c6_m0 = sf_mex_get_sfun_param(chartInstance->S, 0, 1);
  c6_mxField = sf_mex_getfield(c6_m0, "Env", "Par", 0);
  c6_m1 = sf_mex_dup(c6_mxField);
  c6_b_mxField = sf_mex_getfield(c6_m1, "g", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_b_mxField), &c6_r0.Env.g, 1, 0, 0U, 0,
                      0U, 0);
  c6_b_mxField = sf_mex_getfield(c6_m1, "left1", "Par", 0);
  c6_m2 = sf_mex_dup(c6_b_mxField);
  c6_c_mxField = sf_mex_getfield(c6_m2, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_c_mxField), &c6_r0.Env.left1.x, 1, 0,
                      0U, 0, 0U, 0);
  c6_c_mxField = sf_mex_getfield(c6_m2, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_c_mxField), &c6_r0.Env.left1.y, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c6_m2);
  c6_b_mxField = sf_mex_getfield(c6_m1, "right1", "Par", 0);
  c6_m3 = sf_mex_dup(c6_b_mxField);
  c6_d_mxField = sf_mex_getfield(c6_m3, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_d_mxField), &c6_r0.Env.right1.x, 1, 0,
                      0U, 0, 0U, 0);
  c6_d_mxField = sf_mex_getfield(c6_m3, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_d_mxField), &c6_r0.Env.right1.y, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c6_m3);
  c6_b_mxField = sf_mex_getfield(c6_m1, "right2", "Par", 0);
  c6_m4 = sf_mex_dup(c6_b_mxField);
  c6_e_mxField = sf_mex_getfield(c6_m4, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_e_mxField), &c6_r0.Env.right2.x, 1, 0,
                      0U, 0, 0U, 0);
  c6_e_mxField = sf_mex_getfield(c6_m4, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_e_mxField), &c6_r0.Env.right2.y, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c6_m4);
  c6_b_mxField = sf_mex_getfield(c6_m1, "left2", "Par", 0);
  c6_m5 = sf_mex_dup(c6_b_mxField);
  c6_f_mxField = sf_mex_getfield(c6_m5, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_f_mxField), &c6_r0.Env.left2.x, 1, 0,
                      0U, 0, 0U, 0);
  c6_f_mxField = sf_mex_getfield(c6_m5, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_f_mxField), &c6_r0.Env.left2.y, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c6_m5);
  c6_b_mxField = sf_mex_getfield(c6_m1, "right3", "Par", 0);
  c6_m6 = sf_mex_dup(c6_b_mxField);
  c6_g_mxField = sf_mex_getfield(c6_m6, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_g_mxField), &c6_r0.Env.right3.x, 1, 0,
                      0U, 0, 0U, 0);
  c6_g_mxField = sf_mex_getfield(c6_m6, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_g_mxField), &c6_r0.Env.right3.y, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c6_m6);
  c6_b_mxField = sf_mex_getfield(c6_m1, "mu", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_b_mxField), &c6_r0.Env.mu, 1, 0, 0U,
                      0, 0U, 0);
  sf_mex_destroy(&c6_m1);
  c6_mxField = sf_mex_getfield(c6_m0, "Veh", "Par", 0);
  c6_m7 = sf_mex_dup(c6_mxField);
  c6_h_mxField = sf_mex_getfield(c6_m7, "m", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_h_mxField), &c6_r0.Veh.m, 1, 0, 0U, 0,
                      0U, 0);
  c6_h_mxField = sf_mex_getfield(c6_m7, "Jz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_h_mxField), &c6_r0.Veh.Jz, 1, 0, 0U,
                      0, 0U, 0);
  c6_h_mxField = sf_mex_getfield(c6_m7, "m_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_h_mxField), &c6_r0.Veh.m_sprung, 1, 0,
                      0U, 0, 0U, 0);
  c6_h_mxField = sf_mex_getfield(c6_m7, "Jx_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_h_mxField), &c6_r0.Veh.Jx_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c6_h_mxField = sf_mex_getfield(c6_m7, "Jy_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_h_mxField), &c6_r0.Veh.Jy_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c6_h_mxField = sf_mex_getfield(c6_m7, "lf", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_h_mxField), &c6_r0.Veh.lf, 1, 0, 0U,
                      0, 0U, 0);
  c6_h_mxField = sf_mex_getfield(c6_m7, "lr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_h_mxField), &c6_r0.Veh.lr, 1, 0, 0U,
                      0, 0U, 0);
  c6_h_mxField = sf_mex_getfield(c6_m7, "L", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_h_mxField), &c6_r0.Veh.L, 1, 0, 0U, 0,
                      0U, 0);
  c6_h_mxField = sf_mex_getfield(c6_m7, "TrackWidth", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_h_mxField), &c6_r0.Veh.TrackWidth, 1,
                      0, 0U, 0, 0U, 0);
  c6_h_mxField = sf_mex_getfield(c6_m7, "h", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_h_mxField), &c6_r0.Veh.h, 1, 0, 0U, 0,
                      0U, 0);
  c6_h_mxField = sf_mex_getfield(c6_m7, "HalfRohACd", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_h_mxField), &c6_r0.Veh.HalfRohACd, 1,
                      0, 0U, 0, 0U, 0);
  c6_h_mxField = sf_mex_getfield(c6_m7, "F_z4_static", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_h_mxField), c6_r0.Veh.F_z4_static, 1,
                      0, 0U, 1, 0U, 2, 1, 4);
  c6_h_mxField = sf_mex_getfield(c6_m7, "Rw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_h_mxField), &c6_r0.Veh.Rw, 1, 0, 0U,
                      0, 0U, 0);
  c6_h_mxField = sf_mex_getfield(c6_m7, "r_long", "Par", 0);
  c6_m8 = sf_mex_dup(c6_h_mxField);
  c6_i_mxField = sf_mex_getfield(c6_m8, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_i_mxField), c6_r0.Veh.r_long.fl, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  c6_i_mxField = sf_mex_getfield(c6_m8, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_i_mxField), c6_r0.Veh.r_long.fr, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  c6_i_mxField = sf_mex_getfield(c6_m8, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_i_mxField), c6_r0.Veh.r_long.rl, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  c6_i_mxField = sf_mex_getfield(c6_m8, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_i_mxField), c6_r0.Veh.r_long.rr, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c6_m8);
  c6_h_mxField = sf_mex_getfield(c6_m7, "r_lat", "Par", 0);
  c6_m9 = sf_mex_dup(c6_h_mxField);
  c6_j_mxField = sf_mex_getfield(c6_m9, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_j_mxField), c6_r0.Veh.r_lat.fl, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  c6_j_mxField = sf_mex_getfield(c6_m9, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_j_mxField), c6_r0.Veh.r_lat.fr, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  c6_j_mxField = sf_mex_getfield(c6_m9, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_j_mxField), c6_r0.Veh.r_lat.rl, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  c6_j_mxField = sf_mex_getfield(c6_m9, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_j_mxField), c6_r0.Veh.r_lat.rr, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c6_m9);
  c6_h_mxField = sf_mex_getfield(c6_m7, "r_lever", "Par", 0);
  c6_m10 = sf_mex_dup(c6_h_mxField);
  c6_k_mxField = sf_mex_getfield(c6_m10, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_k_mxField), c6_r0.Veh.r_lever.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c6_k_mxField = sf_mex_getfield(c6_m10, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_k_mxField), c6_r0.Veh.r_lever.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c6_k_mxField = sf_mex_getfield(c6_m10, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_k_mxField), c6_r0.Veh.r_lever.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c6_k_mxField = sf_mex_getfield(c6_m10, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_k_mxField), c6_r0.Veh.r_lever.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c6_m10);
  c6_h_mxField = sf_mex_getfield(c6_m7, "r_pivot", "Par", 0);
  c6_m11 = sf_mex_dup(c6_h_mxField);
  c6_l_mxField = sf_mex_getfield(c6_m11, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_l_mxField), c6_r0.Veh.r_pivot.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c6_l_mxField = sf_mex_getfield(c6_m11, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_l_mxField), c6_r0.Veh.r_pivot.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c6_l_mxField = sf_mex_getfield(c6_m11, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_l_mxField), c6_r0.Veh.r_pivot.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c6_l_mxField = sf_mex_getfield(c6_m11, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_l_mxField), c6_r0.Veh.r_pivot.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c6_m11);
  c6_h_mxField = sf_mex_getfield(c6_m7, "cw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_h_mxField), &c6_r0.Veh.cw, 1, 0, 0U,
                      0, 0U, 0);
  c6_h_mxField = sf_mex_getfield(c6_m7, "carb_f", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_h_mxField), &c6_r0.Veh.carb_f, 1, 0,
                      0U, 0, 0U, 0);
  c6_h_mxField = sf_mex_getfield(c6_m7, "carb_r", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_h_mxField), &c6_r0.Veh.carb_r, 1, 0,
                      0U, 0, 0U, 0);
  c6_h_mxField = sf_mex_getfield(c6_m7, "dw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_h_mxField), &c6_r0.Veh.dw, 1, 0, 0U,
                      0, 0U, 0);
  c6_h_mxField = sf_mex_getfield(c6_m7, "Jw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_h_mxField), &c6_r0.Veh.Jw, 1, 0, 0U,
                      0, 0U, 0);
  c6_h_mxField = sf_mex_getfield(c6_m7, "C0", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_h_mxField), &c6_r0.Veh.C0, 1, 0, 0U,
                      0, 0U, 0);
  c6_h_mxField = sf_mex_getfield(c6_m7, "RelaxLength", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_h_mxField), &c6_r0.Veh.RelaxLength, 1,
                      0, 0U, 0, 0U, 0);
  c6_h_mxField = sf_mex_getfield(c6_m7, "RRC", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_h_mxField), &c6_r0.Veh.RRC, 1, 0, 0U,
                      0, 0U, 0);
  c6_h_mxField = sf_mex_getfield(c6_m7, "Pmax", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_h_mxField), &c6_r0.Veh.Pmax, 1, 0, 0U,
                      0, 0U, 0);
  c6_h_mxField = sf_mex_getfield(c6_m7, "PropDistrFrnt", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_h_mxField), &c6_r0.Veh.PropDistrFrnt,
                      1, 0, 0U, 0, 0U, 0);
  c6_h_mxField = sf_mex_getfield(c6_m7, "BrkDistrFrnt", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_h_mxField), &c6_r0.Veh.BrkDistrFrnt,
                      1, 0, 0U, 0, 0U, 0);
  c6_h_mxField = sf_mex_getfield(c6_m7, "SteRatio", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_h_mxField), &c6_r0.Veh.SteRatio, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c6_m7);
  c6_mxField = sf_mex_getfield(c6_m0, "Drvr", "Par", 0);
  c6_m12 = sf_mex_dup(c6_mxField);
  c6_m_mxField = sf_mex_getfield(c6_m12, "v_set", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_m_mxField), &c6_r0.Drvr.v_set, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c6_m12);
  c6_mxField = sf_mex_getfield(c6_m0, "Init", "Par", 0);
  c6_m13 = sf_mex_dup(c6_mxField);
  c6_n_mxField = sf_mex_getfield(c6_m13, "v_x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_n_mxField), &c6_r0.Init.v_x, 1, 0, 0U,
                      0, 0U, 0);
  c6_n_mxField = sf_mex_getfield(c6_m13, "F_fz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_n_mxField), &c6_r0.Init.F_fz, 1, 0,
                      0U, 0, 0U, 0);
  c6_n_mxField = sf_mex_getfield(c6_m13, "F_rz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c6_n_mxField), &c6_r0.Init.F_rz, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c6_m13);
  sf_mex_destroy(&c6_m0);
  chartInstance->c6_Par = c6_r0;
}

static void enable_c6_Modified(SFc6_ModifiedInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c6_Modified(SFc6_ModifiedInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c6_update_debugger_state_c6_Modified(SFc6_ModifiedInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c6_Modified(SFc6_ModifiedInstanceStruct
  *chartInstance)
{
  const mxArray *c6_st;
  const mxArray *c6_y = NULL;
  const mxArray *c6_b_y = NULL;
  real_T c6_u;
  const mxArray *c6_c_y = NULL;
  real_T c6_b_u;
  const mxArray *c6_d_y = NULL;
  real_T c6_c_u;
  const mxArray *c6_e_y = NULL;
  real_T c6_d_u;
  const mxArray *c6_f_y = NULL;
  uint8_T c6_hoistedGlobal;
  uint8_T c6_e_u;
  const mxArray *c6_g_y = NULL;
  c6_st = NULL;
  c6_st = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_createcellmatrix(2, 1), false);
  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c6_u = *(real_T *)&((char_T *)chartInstance->c6_derF_xyw4)[0];
  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c6_b_y, c6_c_y, "fl", "fl", 0);
  c6_b_u = *(real_T *)&((char_T *)chartInstance->c6_derF_xyw4)[8];
  c6_d_y = NULL;
  sf_mex_assign(&c6_d_y, sf_mex_create("y", &c6_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c6_b_y, c6_d_y, "fr", "fr", 0);
  c6_c_u = *(real_T *)&((char_T *)chartInstance->c6_derF_xyw4)[16];
  c6_e_y = NULL;
  sf_mex_assign(&c6_e_y, sf_mex_create("y", &c6_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c6_b_y, c6_e_y, "rl", "rl", 0);
  c6_d_u = *(real_T *)&((char_T *)chartInstance->c6_derF_xyw4)[24];
  c6_f_y = NULL;
  sf_mex_assign(&c6_f_y, sf_mex_create("y", &c6_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c6_b_y, c6_f_y, "rr", "rr", 0);
  sf_mex_setcell(c6_y, 0, c6_b_y);
  c6_hoistedGlobal = chartInstance->c6_is_active_c6_Modified;
  c6_e_u = c6_hoistedGlobal;
  c6_g_y = NULL;
  sf_mex_assign(&c6_g_y, sf_mex_create("y", &c6_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c6_y, 1, c6_g_y);
  sf_mex_assign(&c6_st, c6_y, false);
  return c6_st;
}

static void set_sim_state_c6_Modified(SFc6_ModifiedInstanceStruct *chartInstance,
  const mxArray *c6_st)
{
  const mxArray *c6_u;
  c6_whl_vec4 c6_r1;
  chartInstance->c6_doneDoubleBufferReInit = true;
  c6_u = sf_mex_dup(c6_st);
  c6_r1 = c6_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 0)),
    "derF_xyw4");
  *(real_T *)&((char_T *)chartInstance->c6_derF_xyw4)[0] = c6_r1.fl;
  *(real_T *)&((char_T *)chartInstance->c6_derF_xyw4)[8] = c6_r1.fr;
  *(real_T *)&((char_T *)chartInstance->c6_derF_xyw4)[16] = c6_r1.rl;
  *(real_T *)&((char_T *)chartInstance->c6_derF_xyw4)[24] = c6_r1.rr;
  chartInstance->c6_is_active_c6_Modified = c6_n_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c6_u, 1)), "is_active_c6_Modified");
  sf_mex_destroy(&c6_u);
  c6_update_debugger_state_c6_Modified(chartInstance);
  sf_mex_destroy(&c6_st);
}

static void finalize_c6_Modified(SFc6_ModifiedInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c6_Modified(SFc6_ModifiedInstanceStruct *chartInstance)
{
  c6_whl_vec4 c6_b_w_4;
  c6_whl_vec4 c6_b_F_xywSS4;
  c6_whl_vec4 c6_b_F_xyw4;
  c6_struct_iBlsPBO3AGnt69vDoTx5zD c6_b_Par;
  uint32_T c6_debug_family_var_map[7];
  real_T c6_nargin = 4.0;
  real_T c6_nargout = 1.0;
  c6_whl_vec4 c6_b_derF_xyw4;
  real_T c6_x;
  real_T c6_b_x;
  real_T c6_y;
  real_T c6_A;
  real_T c6_B;
  real_T c6_c_x;
  real_T c6_b_y;
  real_T c6_d_x;
  real_T c6_c_y;
  real_T c6_e_x;
  real_T c6_d_y;
  real_T c6_e_y;
  real_T c6_f_x;
  real_T c6_g_x;
  real_T c6_f_y;
  real_T c6_b_A;
  real_T c6_b_B;
  real_T c6_h_x;
  real_T c6_g_y;
  real_T c6_i_x;
  real_T c6_h_y;
  real_T c6_j_x;
  real_T c6_i_y;
  real_T c6_j_y;
  real_T c6_k_x;
  real_T c6_l_x;
  real_T c6_k_y;
  real_T c6_c_A;
  real_T c6_c_B;
  real_T c6_m_x;
  real_T c6_l_y;
  real_T c6_n_x;
  real_T c6_m_y;
  real_T c6_o_x;
  real_T c6_n_y;
  real_T c6_o_y;
  real_T c6_p_x;
  real_T c6_q_x;
  real_T c6_p_y;
  real_T c6_d_A;
  real_T c6_d_B;
  real_T c6_r_x;
  real_T c6_q_y;
  real_T c6_s_x;
  real_T c6_r_y;
  real_T c6_t_x;
  real_T c6_s_y;
  real_T c6_t_y;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, chartInstance->c6_sfEvent);
  chartInstance->c6_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c6_sfEvent);
  c6_b_w_4.fl = *(real_T *)&((char_T *)chartInstance->c6_w_4)[0];
  c6_b_w_4.fr = *(real_T *)&((char_T *)chartInstance->c6_w_4)[8];
  c6_b_w_4.rl = *(real_T *)&((char_T *)chartInstance->c6_w_4)[16];
  c6_b_w_4.rr = *(real_T *)&((char_T *)chartInstance->c6_w_4)[24];
  c6_b_F_xywSS4.fl = *(real_T *)&((char_T *)chartInstance->c6_F_xywSS4)[0];
  c6_b_F_xywSS4.fr = *(real_T *)&((char_T *)chartInstance->c6_F_xywSS4)[8];
  c6_b_F_xywSS4.rl = *(real_T *)&((char_T *)chartInstance->c6_F_xywSS4)[16];
  c6_b_F_xywSS4.rr = *(real_T *)&((char_T *)chartInstance->c6_F_xywSS4)[24];
  c6_b_F_xyw4.fl = *(real_T *)&((char_T *)chartInstance->c6_F_xyw4)[0];
  c6_b_F_xyw4.fr = *(real_T *)&((char_T *)chartInstance->c6_F_xyw4)[8];
  c6_b_F_xyw4.rl = *(real_T *)&((char_T *)chartInstance->c6_F_xyw4)[16];
  c6_b_F_xyw4.rr = *(real_T *)&((char_T *)chartInstance->c6_F_xyw4)[24];
  c6_b_Par = chartInstance->c6_Par;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c6_debug_family_names,
    c6_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 0U, c6_c_sf_marshallOut,
    c6_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 1U, c6_c_sf_marshallOut,
    c6_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_b_w_4, 2U, c6_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_b_F_xywSS4, 3U, c6_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_b_F_xyw4, 4U, c6_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_Par, 5U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_derF_xyw4, 6U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 4);
  c6_x = c6_b_Par.Veh.Rw * c6_b_w_4.fl;
  c6_b_x = c6_x;
  c6_y = muDoubleScalarAbs(c6_b_x);
  c6_A = (c6_b_F_xywSS4.fl - c6_b_F_xyw4.fl) * c6_y;
  c6_B = c6_b_Par.Veh.RelaxLength;
  c6_c_x = c6_A;
  c6_b_y = c6_B;
  c6_d_x = c6_c_x;
  c6_c_y = c6_b_y;
  c6_e_x = c6_d_x;
  c6_d_y = c6_c_y;
  c6_e_y = c6_e_x / c6_d_y;
  c6_b_derF_xyw4.fl = c6_e_y;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 5);
  c6_f_x = c6_b_Par.Veh.Rw * c6_b_w_4.fr;
  c6_g_x = c6_f_x;
  c6_f_y = muDoubleScalarAbs(c6_g_x);
  c6_b_A = (c6_b_F_xywSS4.fr - c6_b_F_xyw4.fr) * c6_f_y;
  c6_b_B = c6_b_Par.Veh.RelaxLength;
  c6_h_x = c6_b_A;
  c6_g_y = c6_b_B;
  c6_i_x = c6_h_x;
  c6_h_y = c6_g_y;
  c6_j_x = c6_i_x;
  c6_i_y = c6_h_y;
  c6_j_y = c6_j_x / c6_i_y;
  c6_b_derF_xyw4.fr = c6_j_y;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 6);
  c6_k_x = c6_b_Par.Veh.Rw * c6_b_w_4.rl;
  c6_l_x = c6_k_x;
  c6_k_y = muDoubleScalarAbs(c6_l_x);
  c6_c_A = (c6_b_F_xywSS4.rl - c6_b_F_xyw4.rl) * c6_k_y;
  c6_c_B = c6_b_Par.Veh.RelaxLength;
  c6_m_x = c6_c_A;
  c6_l_y = c6_c_B;
  c6_n_x = c6_m_x;
  c6_m_y = c6_l_y;
  c6_o_x = c6_n_x;
  c6_n_y = c6_m_y;
  c6_o_y = c6_o_x / c6_n_y;
  c6_b_derF_xyw4.rl = c6_o_y;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 7);
  c6_p_x = c6_b_Par.Veh.Rw * c6_b_w_4.rr;
  c6_q_x = c6_p_x;
  c6_p_y = muDoubleScalarAbs(c6_q_x);
  c6_d_A = (c6_b_F_xywSS4.rr - c6_b_F_xyw4.rr) * c6_p_y;
  c6_d_B = c6_b_Par.Veh.RelaxLength;
  c6_r_x = c6_d_A;
  c6_q_y = c6_d_B;
  c6_s_x = c6_r_x;
  c6_r_y = c6_q_y;
  c6_t_x = c6_s_x;
  c6_s_y = c6_r_y;
  c6_t_y = c6_t_x / c6_s_y;
  c6_b_derF_xyw4.rr = c6_t_y;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, -7);
  _SFD_SYMBOL_SCOPE_POP();
  *(real_T *)&((char_T *)chartInstance->c6_derF_xyw4)[0] = c6_b_derF_xyw4.fl;
  *(real_T *)&((char_T *)chartInstance->c6_derF_xyw4)[8] = c6_b_derF_xyw4.fr;
  *(real_T *)&((char_T *)chartInstance->c6_derF_xyw4)[16] = c6_b_derF_xyw4.rl;
  *(real_T *)&((char_T *)chartInstance->c6_derF_xyw4)[24] = c6_b_derF_xyw4.rr;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c6_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_ModifiedMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c6_Modified(SFc6_ModifiedInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc6_Modified(SFc6_ModifiedInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber, uint32_T c6_instanceNumber)
{
  (void)c6_machineNumber;
  (void)c6_chartNumber;
  (void)c6_instanceNumber;
}

static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  c6_whl_vec4 c6_u;
  const mxArray *c6_y = NULL;
  real_T c6_b_u;
  const mxArray *c6_b_y = NULL;
  real_T c6_c_u;
  const mxArray *c6_c_y = NULL;
  real_T c6_d_u;
  const mxArray *c6_d_y = NULL;
  real_T c6_e_u;
  const mxArray *c6_e_y = NULL;
  SFc6_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc6_ModifiedInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(c6_whl_vec4 *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c6_b_u = c6_u.fl;
  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c6_y, c6_b_y, "fl", "fl", 0);
  c6_c_u = c6_u.fr;
  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", &c6_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c6_y, c6_c_y, "fr", "fr", 0);
  c6_d_u = c6_u.rl;
  c6_d_y = NULL;
  sf_mex_assign(&c6_d_y, sf_mex_create("y", &c6_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c6_y, c6_d_y, "rl", "rl", 0);
  c6_e_u = c6_u.rr;
  c6_e_y = NULL;
  sf_mex_assign(&c6_e_y, sf_mex_create("y", &c6_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c6_y, c6_e_y, "rr", "rr", 0);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static c6_whl_vec4 c6_emlrt_marshallIn(SFc6_ModifiedInstanceStruct
  *chartInstance, const mxArray *c6_b_derF_xyw4, const char_T *c6_identifier)
{
  c6_whl_vec4 c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_derF_xyw4),
    &c6_thisId);
  sf_mex_destroy(&c6_b_derF_xyw4);
  return c6_y;
}

static c6_whl_vec4 c6_b_emlrt_marshallIn(SFc6_ModifiedInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  c6_whl_vec4 c6_y;
  emlrtMsgIdentifier c6_thisId;
  static const char * c6_fieldNames[4] = { "fl", "fr", "rl", "rr" };

  c6_thisId.fParent = c6_parentId;
  sf_mex_check_struct(c6_parentId, c6_u, 4, c6_fieldNames, 0U, NULL);
  c6_thisId.fIdentifier = "fl";
  c6_y.fl = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c6_u,
    "fl", "fl", 0)), &c6_thisId);
  c6_thisId.fIdentifier = "fr";
  c6_y.fr = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c6_u,
    "fr", "fr", 0)), &c6_thisId);
  c6_thisId.fIdentifier = "rl";
  c6_y.rl = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c6_u,
    "rl", "rl", 0)), &c6_thisId);
  c6_thisId.fIdentifier = "rr";
  c6_y.rr = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c6_u,
    "rr", "rr", 0)), &c6_thisId);
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static real_T c6_c_emlrt_marshallIn(SFc6_ModifiedInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  real_T c6_y;
  real_T c6_d0;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_d0, 1, 0, 0U, 0, 0U, 0);
  c6_y = c6_d0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_derF_xyw4;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  c6_whl_vec4 c6_y;
  SFc6_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc6_ModifiedInstanceStruct *)chartInstanceVoid;
  c6_b_derF_xyw4 = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_derF_xyw4),
    &c6_thisId);
  sf_mex_destroy(&c6_b_derF_xyw4);
  *(c6_whl_vec4 *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData;
  c6_struct_iBlsPBO3AGnt69vDoTx5zD c6_u;
  const mxArray *c6_y = NULL;
  c6_struct_Nst2vGTExxHsg85EUOj9EH c6_b_u;
  const mxArray *c6_b_y = NULL;
  real_T c6_c_u;
  const mxArray *c6_c_y = NULL;
  c6_struct_HhckT6rntEraqECYVIDvCC c6_d_u;
  const mxArray *c6_d_y = NULL;
  real_T c6_e_u;
  const mxArray *c6_e_y = NULL;
  real_T c6_f_u;
  const mxArray *c6_f_y = NULL;
  const mxArray *c6_g_y = NULL;
  real_T c6_g_u;
  const mxArray *c6_h_y = NULL;
  real_T c6_h_u;
  const mxArray *c6_i_y = NULL;
  const mxArray *c6_j_y = NULL;
  real_T c6_i_u;
  const mxArray *c6_k_y = NULL;
  real_T c6_j_u;
  const mxArray *c6_l_y = NULL;
  const mxArray *c6_m_y = NULL;
  real_T c6_k_u;
  const mxArray *c6_n_y = NULL;
  real_T c6_l_u;
  const mxArray *c6_o_y = NULL;
  const mxArray *c6_p_y = NULL;
  real_T c6_m_u;
  const mxArray *c6_q_y = NULL;
  real_T c6_n_u;
  const mxArray *c6_r_y = NULL;
  real_T c6_o_u;
  const mxArray *c6_s_y = NULL;
  c6_struct_ZCmOWPuqBDw16FSOVVD00 c6_p_u;
  const mxArray *c6_t_y = NULL;
  real_T c6_q_u;
  const mxArray *c6_u_y = NULL;
  real_T c6_r_u;
  const mxArray *c6_v_y = NULL;
  real_T c6_s_u;
  const mxArray *c6_w_y = NULL;
  real_T c6_t_u;
  const mxArray *c6_x_y = NULL;
  real_T c6_u_u;
  const mxArray *c6_y_y = NULL;
  real_T c6_v_u;
  const mxArray *c6_ab_y = NULL;
  real_T c6_w_u;
  const mxArray *c6_bb_y = NULL;
  real_T c6_x_u;
  const mxArray *c6_cb_y = NULL;
  real_T c6_y_u;
  const mxArray *c6_db_y = NULL;
  real_T c6_ab_u;
  const mxArray *c6_eb_y = NULL;
  real_T c6_bb_u;
  const mxArray *c6_fb_y = NULL;
  int32_T c6_i0;
  real_T c6_cb_u[4];
  const mxArray *c6_gb_y = NULL;
  real_T c6_db_u;
  const mxArray *c6_hb_y = NULL;
  c6_struct_ZKAzdrl7umDGJoC14aoVKC c6_eb_u;
  const mxArray *c6_ib_y = NULL;
  int32_T c6_i1;
  real_T c6_fb_u[3];
  const mxArray *c6_jb_y = NULL;
  int32_T c6_i2;
  real_T c6_gb_u[3];
  const mxArray *c6_kb_y = NULL;
  int32_T c6_i3;
  real_T c6_hb_u[3];
  const mxArray *c6_lb_y = NULL;
  int32_T c6_i4;
  real_T c6_ib_u[3];
  const mxArray *c6_mb_y = NULL;
  const mxArray *c6_nb_y = NULL;
  int32_T c6_i5;
  real_T c6_jb_u[3];
  const mxArray *c6_ob_y = NULL;
  int32_T c6_i6;
  real_T c6_kb_u[3];
  const mxArray *c6_pb_y = NULL;
  int32_T c6_i7;
  real_T c6_lb_u[3];
  const mxArray *c6_qb_y = NULL;
  int32_T c6_i8;
  real_T c6_mb_u[3];
  const mxArray *c6_rb_y = NULL;
  const mxArray *c6_sb_y = NULL;
  int32_T c6_i9;
  real_T c6_nb_u[3];
  const mxArray *c6_tb_y = NULL;
  int32_T c6_i10;
  real_T c6_ob_u[3];
  const mxArray *c6_ub_y = NULL;
  int32_T c6_i11;
  real_T c6_pb_u[3];
  const mxArray *c6_vb_y = NULL;
  int32_T c6_i12;
  real_T c6_qb_u[3];
  const mxArray *c6_wb_y = NULL;
  const mxArray *c6_xb_y = NULL;
  int32_T c6_i13;
  real_T c6_rb_u[3];
  const mxArray *c6_yb_y = NULL;
  int32_T c6_i14;
  real_T c6_sb_u[3];
  const mxArray *c6_ac_y = NULL;
  int32_T c6_i15;
  real_T c6_tb_u[3];
  const mxArray *c6_bc_y = NULL;
  int32_T c6_i16;
  real_T c6_ub_u[3];
  const mxArray *c6_cc_y = NULL;
  real_T c6_vb_u;
  const mxArray *c6_dc_y = NULL;
  real_T c6_wb_u;
  const mxArray *c6_ec_y = NULL;
  real_T c6_xb_u;
  const mxArray *c6_fc_y = NULL;
  real_T c6_yb_u;
  const mxArray *c6_gc_y = NULL;
  real_T c6_ac_u;
  const mxArray *c6_hc_y = NULL;
  real_T c6_bc_u;
  const mxArray *c6_ic_y = NULL;
  real_T c6_cc_u;
  const mxArray *c6_jc_y = NULL;
  real_T c6_dc_u;
  const mxArray *c6_kc_y = NULL;
  real_T c6_ec_u;
  const mxArray *c6_lc_y = NULL;
  real_T c6_fc_u;
  const mxArray *c6_mc_y = NULL;
  real_T c6_gc_u;
  const mxArray *c6_nc_y = NULL;
  real_T c6_hc_u;
  const mxArray *c6_oc_y = NULL;
  c6_struct_r4FNviKwHfdhB8nQjvQv9 c6_ic_u;
  const mxArray *c6_pc_y = NULL;
  real_T c6_jc_u;
  const mxArray *c6_qc_y = NULL;
  c6_struct_Y9F1qlBi9AhssksPwemA4G c6_kc_u;
  const mxArray *c6_rc_y = NULL;
  real_T c6_lc_u;
  const mxArray *c6_sc_y = NULL;
  real_T c6_mc_u;
  const mxArray *c6_tc_y = NULL;
  real_T c6_nc_u;
  const mxArray *c6_uc_y = NULL;
  SFc6_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc6_ModifiedInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_mxArrayOutData = NULL;
  c6_u = *(c6_struct_iBlsPBO3AGnt69vDoTx5zD *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c6_b_u = c6_u.Env;
  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c6_c_u = c6_b_u.g;
  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", &c6_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c6_b_y, c6_c_y, "g", "g", 0);
  c6_d_u = c6_b_u.left1;
  c6_d_y = NULL;
  sf_mex_assign(&c6_d_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c6_e_u = c6_d_u.x;
  c6_e_y = NULL;
  sf_mex_assign(&c6_e_y, sf_mex_create("y", &c6_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c6_d_y, c6_e_y, "x", "x", 0);
  c6_f_u = c6_d_u.y;
  c6_f_y = NULL;
  sf_mex_assign(&c6_f_y, sf_mex_create("y", &c6_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c6_d_y, c6_f_y, "y", "y", 0);
  sf_mex_addfield(c6_b_y, c6_d_y, "left1", "left1", 0);
  c6_d_u = c6_b_u.right1;
  c6_g_y = NULL;
  sf_mex_assign(&c6_g_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c6_g_u = c6_d_u.x;
  c6_h_y = NULL;
  sf_mex_assign(&c6_h_y, sf_mex_create("y", &c6_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c6_g_y, c6_h_y, "x", "x", 0);
  c6_h_u = c6_d_u.y;
  c6_i_y = NULL;
  sf_mex_assign(&c6_i_y, sf_mex_create("y", &c6_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c6_g_y, c6_i_y, "y", "y", 0);
  sf_mex_addfield(c6_b_y, c6_g_y, "right1", "right1", 0);
  c6_d_u = c6_b_u.right2;
  c6_j_y = NULL;
  sf_mex_assign(&c6_j_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c6_i_u = c6_d_u.x;
  c6_k_y = NULL;
  sf_mex_assign(&c6_k_y, sf_mex_create("y", &c6_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c6_j_y, c6_k_y, "x", "x", 0);
  c6_j_u = c6_d_u.y;
  c6_l_y = NULL;
  sf_mex_assign(&c6_l_y, sf_mex_create("y", &c6_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c6_j_y, c6_l_y, "y", "y", 0);
  sf_mex_addfield(c6_b_y, c6_j_y, "right2", "right2", 0);
  c6_d_u = c6_b_u.left2;
  c6_m_y = NULL;
  sf_mex_assign(&c6_m_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c6_k_u = c6_d_u.x;
  c6_n_y = NULL;
  sf_mex_assign(&c6_n_y, sf_mex_create("y", &c6_k_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c6_m_y, c6_n_y, "x", "x", 0);
  c6_l_u = c6_d_u.y;
  c6_o_y = NULL;
  sf_mex_assign(&c6_o_y, sf_mex_create("y", &c6_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c6_m_y, c6_o_y, "y", "y", 0);
  sf_mex_addfield(c6_b_y, c6_m_y, "left2", "left2", 0);
  c6_d_u = c6_b_u.right3;
  c6_p_y = NULL;
  sf_mex_assign(&c6_p_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c6_m_u = c6_d_u.x;
  c6_q_y = NULL;
  sf_mex_assign(&c6_q_y, sf_mex_create("y", &c6_m_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c6_p_y, c6_q_y, "x", "x", 0);
  c6_n_u = c6_d_u.y;
  c6_r_y = NULL;
  sf_mex_assign(&c6_r_y, sf_mex_create("y", &c6_n_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c6_p_y, c6_r_y, "y", "y", 0);
  sf_mex_addfield(c6_b_y, c6_p_y, "right3", "right3", 0);
  c6_o_u = c6_b_u.mu;
  c6_s_y = NULL;
  sf_mex_assign(&c6_s_y, sf_mex_create("y", &c6_o_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c6_b_y, c6_s_y, "mu", "mu", 0);
  sf_mex_addfield(c6_y, c6_b_y, "Env", "Env", 0);
  c6_p_u = c6_u.Veh;
  c6_t_y = NULL;
  sf_mex_assign(&c6_t_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c6_q_u = c6_p_u.m;
  c6_u_y = NULL;
  sf_mex_assign(&c6_u_y, sf_mex_create("y", &c6_q_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c6_t_y, c6_u_y, "m", "m", 0);
  c6_r_u = c6_p_u.Jz;
  c6_v_y = NULL;
  sf_mex_assign(&c6_v_y, sf_mex_create("y", &c6_r_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c6_t_y, c6_v_y, "Jz", "Jz", 0);
  c6_s_u = c6_p_u.m_sprung;
  c6_w_y = NULL;
  sf_mex_assign(&c6_w_y, sf_mex_create("y", &c6_s_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c6_t_y, c6_w_y, "m_sprung", "m_sprung", 0);
  c6_t_u = c6_p_u.Jx_sprung;
  c6_x_y = NULL;
  sf_mex_assign(&c6_x_y, sf_mex_create("y", &c6_t_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c6_t_y, c6_x_y, "Jx_sprung", "Jx_sprung", 0);
  c6_u_u = c6_p_u.Jy_sprung;
  c6_y_y = NULL;
  sf_mex_assign(&c6_y_y, sf_mex_create("y", &c6_u_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c6_t_y, c6_y_y, "Jy_sprung", "Jy_sprung", 0);
  c6_v_u = c6_p_u.lf;
  c6_ab_y = NULL;
  sf_mex_assign(&c6_ab_y, sf_mex_create("y", &c6_v_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c6_t_y, c6_ab_y, "lf", "lf", 0);
  c6_w_u = c6_p_u.lr;
  c6_bb_y = NULL;
  sf_mex_assign(&c6_bb_y, sf_mex_create("y", &c6_w_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c6_t_y, c6_bb_y, "lr", "lr", 0);
  c6_x_u = c6_p_u.L;
  c6_cb_y = NULL;
  sf_mex_assign(&c6_cb_y, sf_mex_create("y", &c6_x_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c6_t_y, c6_cb_y, "L", "L", 0);
  c6_y_u = c6_p_u.TrackWidth;
  c6_db_y = NULL;
  sf_mex_assign(&c6_db_y, sf_mex_create("y", &c6_y_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c6_t_y, c6_db_y, "TrackWidth", "TrackWidth", 0);
  c6_ab_u = c6_p_u.h;
  c6_eb_y = NULL;
  sf_mex_assign(&c6_eb_y, sf_mex_create("y", &c6_ab_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c6_t_y, c6_eb_y, "h", "h", 0);
  c6_bb_u = c6_p_u.HalfRohACd;
  c6_fb_y = NULL;
  sf_mex_assign(&c6_fb_y, sf_mex_create("y", &c6_bb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c6_t_y, c6_fb_y, "HalfRohACd", "HalfRohACd", 0);
  for (c6_i0 = 0; c6_i0 < 4; c6_i0++) {
    c6_cb_u[c6_i0] = c6_p_u.F_z4_static[c6_i0];
  }

  c6_gb_y = NULL;
  sf_mex_assign(&c6_gb_y, sf_mex_create("y", c6_cb_u, 0, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_addfield(c6_t_y, c6_gb_y, "F_z4_static", "F_z4_static", 0);
  c6_db_u = c6_p_u.Rw;
  c6_hb_y = NULL;
  sf_mex_assign(&c6_hb_y, sf_mex_create("y", &c6_db_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c6_t_y, c6_hb_y, "Rw", "Rw", 0);
  c6_eb_u = c6_p_u.r_long;
  c6_ib_y = NULL;
  sf_mex_assign(&c6_ib_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c6_i1 = 0; c6_i1 < 3; c6_i1++) {
    c6_fb_u[c6_i1] = c6_eb_u.fl[c6_i1];
  }

  c6_jb_y = NULL;
  sf_mex_assign(&c6_jb_y, sf_mex_create("y", c6_fb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c6_ib_y, c6_jb_y, "fl", "fl", 0);
  for (c6_i2 = 0; c6_i2 < 3; c6_i2++) {
    c6_gb_u[c6_i2] = c6_eb_u.fr[c6_i2];
  }

  c6_kb_y = NULL;
  sf_mex_assign(&c6_kb_y, sf_mex_create("y", c6_gb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c6_ib_y, c6_kb_y, "fr", "fr", 0);
  for (c6_i3 = 0; c6_i3 < 3; c6_i3++) {
    c6_hb_u[c6_i3] = c6_eb_u.rl[c6_i3];
  }

  c6_lb_y = NULL;
  sf_mex_assign(&c6_lb_y, sf_mex_create("y", c6_hb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c6_ib_y, c6_lb_y, "rl", "rl", 0);
  for (c6_i4 = 0; c6_i4 < 3; c6_i4++) {
    c6_ib_u[c6_i4] = c6_eb_u.rr[c6_i4];
  }

  c6_mb_y = NULL;
  sf_mex_assign(&c6_mb_y, sf_mex_create("y", c6_ib_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c6_ib_y, c6_mb_y, "rr", "rr", 0);
  sf_mex_addfield(c6_t_y, c6_ib_y, "r_long", "r_long", 0);
  c6_eb_u = c6_p_u.r_lat;
  c6_nb_y = NULL;
  sf_mex_assign(&c6_nb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c6_i5 = 0; c6_i5 < 3; c6_i5++) {
    c6_jb_u[c6_i5] = c6_eb_u.fl[c6_i5];
  }

  c6_ob_y = NULL;
  sf_mex_assign(&c6_ob_y, sf_mex_create("y", c6_jb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c6_nb_y, c6_ob_y, "fl", "fl", 0);
  for (c6_i6 = 0; c6_i6 < 3; c6_i6++) {
    c6_kb_u[c6_i6] = c6_eb_u.fr[c6_i6];
  }

  c6_pb_y = NULL;
  sf_mex_assign(&c6_pb_y, sf_mex_create("y", c6_kb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c6_nb_y, c6_pb_y, "fr", "fr", 0);
  for (c6_i7 = 0; c6_i7 < 3; c6_i7++) {
    c6_lb_u[c6_i7] = c6_eb_u.rl[c6_i7];
  }

  c6_qb_y = NULL;
  sf_mex_assign(&c6_qb_y, sf_mex_create("y", c6_lb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c6_nb_y, c6_qb_y, "rl", "rl", 0);
  for (c6_i8 = 0; c6_i8 < 3; c6_i8++) {
    c6_mb_u[c6_i8] = c6_eb_u.rr[c6_i8];
  }

  c6_rb_y = NULL;
  sf_mex_assign(&c6_rb_y, sf_mex_create("y", c6_mb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c6_nb_y, c6_rb_y, "rr", "rr", 0);
  sf_mex_addfield(c6_t_y, c6_nb_y, "r_lat", "r_lat", 0);
  c6_eb_u = c6_p_u.r_lever;
  c6_sb_y = NULL;
  sf_mex_assign(&c6_sb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c6_i9 = 0; c6_i9 < 3; c6_i9++) {
    c6_nb_u[c6_i9] = c6_eb_u.fl[c6_i9];
  }

  c6_tb_y = NULL;
  sf_mex_assign(&c6_tb_y, sf_mex_create("y", c6_nb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c6_sb_y, c6_tb_y, "fl", "fl", 0);
  for (c6_i10 = 0; c6_i10 < 3; c6_i10++) {
    c6_ob_u[c6_i10] = c6_eb_u.fr[c6_i10];
  }

  c6_ub_y = NULL;
  sf_mex_assign(&c6_ub_y, sf_mex_create("y", c6_ob_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c6_sb_y, c6_ub_y, "fr", "fr", 0);
  for (c6_i11 = 0; c6_i11 < 3; c6_i11++) {
    c6_pb_u[c6_i11] = c6_eb_u.rl[c6_i11];
  }

  c6_vb_y = NULL;
  sf_mex_assign(&c6_vb_y, sf_mex_create("y", c6_pb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c6_sb_y, c6_vb_y, "rl", "rl", 0);
  for (c6_i12 = 0; c6_i12 < 3; c6_i12++) {
    c6_qb_u[c6_i12] = c6_eb_u.rr[c6_i12];
  }

  c6_wb_y = NULL;
  sf_mex_assign(&c6_wb_y, sf_mex_create("y", c6_qb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c6_sb_y, c6_wb_y, "rr", "rr", 0);
  sf_mex_addfield(c6_t_y, c6_sb_y, "r_lever", "r_lever", 0);
  c6_eb_u = c6_p_u.r_pivot;
  c6_xb_y = NULL;
  sf_mex_assign(&c6_xb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c6_i13 = 0; c6_i13 < 3; c6_i13++) {
    c6_rb_u[c6_i13] = c6_eb_u.fl[c6_i13];
  }

  c6_yb_y = NULL;
  sf_mex_assign(&c6_yb_y, sf_mex_create("y", c6_rb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c6_xb_y, c6_yb_y, "fl", "fl", 0);
  for (c6_i14 = 0; c6_i14 < 3; c6_i14++) {
    c6_sb_u[c6_i14] = c6_eb_u.fr[c6_i14];
  }

  c6_ac_y = NULL;
  sf_mex_assign(&c6_ac_y, sf_mex_create("y", c6_sb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c6_xb_y, c6_ac_y, "fr", "fr", 0);
  for (c6_i15 = 0; c6_i15 < 3; c6_i15++) {
    c6_tb_u[c6_i15] = c6_eb_u.rl[c6_i15];
  }

  c6_bc_y = NULL;
  sf_mex_assign(&c6_bc_y, sf_mex_create("y", c6_tb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c6_xb_y, c6_bc_y, "rl", "rl", 0);
  for (c6_i16 = 0; c6_i16 < 3; c6_i16++) {
    c6_ub_u[c6_i16] = c6_eb_u.rr[c6_i16];
  }

  c6_cc_y = NULL;
  sf_mex_assign(&c6_cc_y, sf_mex_create("y", c6_ub_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c6_xb_y, c6_cc_y, "rr", "rr", 0);
  sf_mex_addfield(c6_t_y, c6_xb_y, "r_pivot", "r_pivot", 0);
  c6_vb_u = c6_p_u.cw;
  c6_dc_y = NULL;
  sf_mex_assign(&c6_dc_y, sf_mex_create("y", &c6_vb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c6_t_y, c6_dc_y, "cw", "cw", 0);
  c6_wb_u = c6_p_u.carb_f;
  c6_ec_y = NULL;
  sf_mex_assign(&c6_ec_y, sf_mex_create("y", &c6_wb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c6_t_y, c6_ec_y, "carb_f", "carb_f", 0);
  c6_xb_u = c6_p_u.carb_r;
  c6_fc_y = NULL;
  sf_mex_assign(&c6_fc_y, sf_mex_create("y", &c6_xb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c6_t_y, c6_fc_y, "carb_r", "carb_r", 0);
  c6_yb_u = c6_p_u.dw;
  c6_gc_y = NULL;
  sf_mex_assign(&c6_gc_y, sf_mex_create("y", &c6_yb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c6_t_y, c6_gc_y, "dw", "dw", 0);
  c6_ac_u = c6_p_u.Jw;
  c6_hc_y = NULL;
  sf_mex_assign(&c6_hc_y, sf_mex_create("y", &c6_ac_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c6_t_y, c6_hc_y, "Jw", "Jw", 0);
  c6_bc_u = c6_p_u.C0;
  c6_ic_y = NULL;
  sf_mex_assign(&c6_ic_y, sf_mex_create("y", &c6_bc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c6_t_y, c6_ic_y, "C0", "C0", 0);
  c6_cc_u = c6_p_u.RelaxLength;
  c6_jc_y = NULL;
  sf_mex_assign(&c6_jc_y, sf_mex_create("y", &c6_cc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c6_t_y, c6_jc_y, "RelaxLength", "RelaxLength", 0);
  c6_dc_u = c6_p_u.RRC;
  c6_kc_y = NULL;
  sf_mex_assign(&c6_kc_y, sf_mex_create("y", &c6_dc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c6_t_y, c6_kc_y, "RRC", "RRC", 0);
  c6_ec_u = c6_p_u.Pmax;
  c6_lc_y = NULL;
  sf_mex_assign(&c6_lc_y, sf_mex_create("y", &c6_ec_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c6_t_y, c6_lc_y, "Pmax", "Pmax", 0);
  c6_fc_u = c6_p_u.PropDistrFrnt;
  c6_mc_y = NULL;
  sf_mex_assign(&c6_mc_y, sf_mex_create("y", &c6_fc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c6_t_y, c6_mc_y, "PropDistrFrnt", "PropDistrFrnt", 0);
  c6_gc_u = c6_p_u.BrkDistrFrnt;
  c6_nc_y = NULL;
  sf_mex_assign(&c6_nc_y, sf_mex_create("y", &c6_gc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c6_t_y, c6_nc_y, "BrkDistrFrnt", "BrkDistrFrnt", 0);
  c6_hc_u = c6_p_u.SteRatio;
  c6_oc_y = NULL;
  sf_mex_assign(&c6_oc_y, sf_mex_create("y", &c6_hc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c6_t_y, c6_oc_y, "SteRatio", "SteRatio", 0);
  sf_mex_addfield(c6_y, c6_t_y, "Veh", "Veh", 0);
  c6_ic_u = c6_u.Drvr;
  c6_pc_y = NULL;
  sf_mex_assign(&c6_pc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c6_jc_u = c6_ic_u.v_set;
  c6_qc_y = NULL;
  sf_mex_assign(&c6_qc_y, sf_mex_create("y", &c6_jc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c6_pc_y, c6_qc_y, "v_set", "v_set", 0);
  sf_mex_addfield(c6_y, c6_pc_y, "Drvr", "Drvr", 0);
  c6_kc_u = c6_u.Init;
  c6_rc_y = NULL;
  sf_mex_assign(&c6_rc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c6_lc_u = c6_kc_u.v_x;
  c6_sc_y = NULL;
  sf_mex_assign(&c6_sc_y, sf_mex_create("y", &c6_lc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c6_rc_y, c6_sc_y, "v_x", "v_x", 0);
  c6_mc_u = c6_kc_u.F_fz;
  c6_tc_y = NULL;
  sf_mex_assign(&c6_tc_y, sf_mex_create("y", &c6_mc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c6_rc_y, c6_tc_y, "F_fz", "F_fz", 0);
  c6_nc_u = c6_kc_u.F_rz;
  c6_uc_y = NULL;
  sf_mex_assign(&c6_uc_y, sf_mex_create("y", &c6_nc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c6_rc_y, c6_uc_y, "F_rz", "F_rz", 0);
  sf_mex_addfield(c6_y, c6_rc_y, "Init", "Init", 0);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static void c6_d_emlrt_marshallIn(SFc6_ModifiedInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  c6_struct_iBlsPBO3AGnt69vDoTx5zD *c6_y)
{
  emlrtMsgIdentifier c6_thisId;
  static const char * c6_fieldNames[4] = { "Env", "Veh", "Drvr", "Init" };

  c6_thisId.fParent = c6_parentId;
  sf_mex_check_struct(c6_parentId, c6_u, 4, c6_fieldNames, 0U, NULL);
  c6_thisId.fIdentifier = "Env";
  c6_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c6_u, "Env",
    "Env", 0)), &c6_thisId, &c6_y->Env);
  c6_thisId.fIdentifier = "Veh";
  c6_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c6_u, "Veh",
    "Veh", 0)), &c6_thisId, &c6_y->Veh);
  c6_thisId.fIdentifier = "Drvr";
  c6_y->Drvr = c6_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c6_u, "Drvr", "Drvr", 0)), &c6_thisId);
  c6_thisId.fIdentifier = "Init";
  c6_y->Init = c6_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c6_u, "Init", "Init", 0)), &c6_thisId);
  sf_mex_destroy(&c6_u);
}

static void c6_e_emlrt_marshallIn(SFc6_ModifiedInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  c6_struct_Nst2vGTExxHsg85EUOj9EH *c6_y)
{
  emlrtMsgIdentifier c6_thisId;
  static const char * c6_fieldNames[7] = { "g", "left1", "right1", "right2",
    "left2", "right3", "mu" };

  c6_thisId.fParent = c6_parentId;
  sf_mex_check_struct(c6_parentId, c6_u, 7, c6_fieldNames, 0U, NULL);
  c6_thisId.fIdentifier = "g";
  c6_y->g = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c6_u,
    "g", "g", 0)), &c6_thisId);
  c6_thisId.fIdentifier = "left1";
  c6_y->left1 = c6_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c6_u, "left1", "left1", 0)), &c6_thisId);
  c6_thisId.fIdentifier = "right1";
  c6_y->right1 = c6_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c6_u, "right1", "right1", 0)),
    &c6_thisId);
  c6_thisId.fIdentifier = "right2";
  c6_y->right2 = c6_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c6_u, "right2", "right2", 0)),
    &c6_thisId);
  c6_thisId.fIdentifier = "left2";
  c6_y->left2 = c6_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c6_u, "left2", "left2", 0)), &c6_thisId);
  c6_thisId.fIdentifier = "right3";
  c6_y->right3 = c6_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c6_u, "right3", "right3", 0)),
    &c6_thisId);
  c6_thisId.fIdentifier = "mu";
  c6_y->mu = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c6_u, "mu", "mu", 0)), &c6_thisId);
  sf_mex_destroy(&c6_u);
}

static c6_struct_HhckT6rntEraqECYVIDvCC c6_f_emlrt_marshallIn
  (SFc6_ModifiedInstanceStruct *chartInstance, const mxArray *c6_u, const
   emlrtMsgIdentifier *c6_parentId)
{
  c6_struct_HhckT6rntEraqECYVIDvCC c6_y;
  emlrtMsgIdentifier c6_thisId;
  static const char * c6_fieldNames[2] = { "x", "y" };

  c6_thisId.fParent = c6_parentId;
  sf_mex_check_struct(c6_parentId, c6_u, 2, c6_fieldNames, 0U, NULL);
  c6_thisId.fIdentifier = "x";
  c6_y.x = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c6_u,
    "x", "x", 0)), &c6_thisId);
  c6_thisId.fIdentifier = "y";
  c6_y.y = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c6_u,
    "y", "y", 0)), &c6_thisId);
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_g_emlrt_marshallIn(SFc6_ModifiedInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  c6_struct_ZCmOWPuqBDw16FSOVVD00 *c6_y)
{
  emlrtMsgIdentifier c6_thisId;
  static const char * c6_fieldNames[29] = { "m", "Jz", "m_sprung", "Jx_sprung",
    "Jy_sprung", "lf", "lr", "L", "TrackWidth", "h", "HalfRohACd", "F_z4_static",
    "Rw", "r_long", "r_lat", "r_lever", "r_pivot", "cw", "carb_f", "carb_r",
    "dw", "Jw", "C0", "RelaxLength", "RRC", "Pmax", "PropDistrFrnt",
    "BrkDistrFrnt", "SteRatio" };

  c6_thisId.fParent = c6_parentId;
  sf_mex_check_struct(c6_parentId, c6_u, 29, c6_fieldNames, 0U, NULL);
  c6_thisId.fIdentifier = "m";
  c6_y->m = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c6_u,
    "m", "m", 0)), &c6_thisId);
  c6_thisId.fIdentifier = "Jz";
  c6_y->Jz = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c6_u, "Jz", "Jz", 0)), &c6_thisId);
  c6_thisId.fIdentifier = "m_sprung";
  c6_y->m_sprung = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c6_u, "m_sprung", "m_sprung", 0)), &c6_thisId);
  c6_thisId.fIdentifier = "Jx_sprung";
  c6_y->Jx_sprung = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c6_u, "Jx_sprung", "Jx_sprung", 0)), &c6_thisId);
  c6_thisId.fIdentifier = "Jy_sprung";
  c6_y->Jy_sprung = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c6_u, "Jy_sprung", "Jy_sprung", 0)), &c6_thisId);
  c6_thisId.fIdentifier = "lf";
  c6_y->lf = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c6_u, "lf", "lf", 0)), &c6_thisId);
  c6_thisId.fIdentifier = "lr";
  c6_y->lr = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c6_u, "lr", "lr", 0)), &c6_thisId);
  c6_thisId.fIdentifier = "L";
  c6_y->L = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c6_u,
    "L", "L", 0)), &c6_thisId);
  c6_thisId.fIdentifier = "TrackWidth";
  c6_y->TrackWidth = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c6_u, "TrackWidth", "TrackWidth", 0)), &c6_thisId);
  c6_thisId.fIdentifier = "h";
  c6_y->h = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c6_u,
    "h", "h", 0)), &c6_thisId);
  c6_thisId.fIdentifier = "HalfRohACd";
  c6_y->HalfRohACd = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c6_u, "HalfRohACd", "HalfRohACd", 0)), &c6_thisId);
  c6_thisId.fIdentifier = "F_z4_static";
  c6_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c6_u,
    "F_z4_static", "F_z4_static", 0)), &c6_thisId, c6_y->F_z4_static);
  c6_thisId.fIdentifier = "Rw";
  c6_y->Rw = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c6_u, "Rw", "Rw", 0)), &c6_thisId);
  c6_thisId.fIdentifier = "r_long";
  c6_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c6_u, "r_long",
    "r_long", 0)), &c6_thisId, &c6_y->r_long);
  c6_thisId.fIdentifier = "r_lat";
  c6_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c6_u, "r_lat",
    "r_lat", 0)), &c6_thisId, &c6_y->r_lat);
  c6_thisId.fIdentifier = "r_lever";
  c6_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c6_u,
    "r_lever", "r_lever", 0)), &c6_thisId, &c6_y->r_lever);
  c6_thisId.fIdentifier = "r_pivot";
  c6_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c6_u,
    "r_pivot", "r_pivot", 0)), &c6_thisId, &c6_y->r_pivot);
  c6_thisId.fIdentifier = "cw";
  c6_y->cw = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c6_u, "cw", "cw", 0)), &c6_thisId);
  c6_thisId.fIdentifier = "carb_f";
  c6_y->carb_f = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c6_u, "carb_f", "carb_f", 0)),
    &c6_thisId);
  c6_thisId.fIdentifier = "carb_r";
  c6_y->carb_r = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c6_u, "carb_r", "carb_r", 0)),
    &c6_thisId);
  c6_thisId.fIdentifier = "dw";
  c6_y->dw = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c6_u, "dw", "dw", 0)), &c6_thisId);
  c6_thisId.fIdentifier = "Jw";
  c6_y->Jw = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c6_u, "Jw", "Jw", 0)), &c6_thisId);
  c6_thisId.fIdentifier = "C0";
  c6_y->C0 = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c6_u, "C0", "C0", 0)), &c6_thisId);
  c6_thisId.fIdentifier = "RelaxLength";
  c6_y->RelaxLength = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c6_u, "RelaxLength", "RelaxLength", 0)), &c6_thisId);
  c6_thisId.fIdentifier = "RRC";
  c6_y->RRC = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c6_u, "RRC", "RRC", 0)), &c6_thisId);
  c6_thisId.fIdentifier = "Pmax";
  c6_y->Pmax = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c6_u, "Pmax", "Pmax", 0)), &c6_thisId);
  c6_thisId.fIdentifier = "PropDistrFrnt";
  c6_y->PropDistrFrnt = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c6_u, "PropDistrFrnt", "PropDistrFrnt", 0)), &c6_thisId);
  c6_thisId.fIdentifier = "BrkDistrFrnt";
  c6_y->BrkDistrFrnt = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c6_u, "BrkDistrFrnt", "BrkDistrFrnt", 0)), &c6_thisId);
  c6_thisId.fIdentifier = "SteRatio";
  c6_y->SteRatio = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c6_u, "SteRatio", "SteRatio", 0)), &c6_thisId);
  sf_mex_destroy(&c6_u);
}

static void c6_h_emlrt_marshallIn(SFc6_ModifiedInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, real_T c6_y[4])
{
  real_T c6_dv0[4];
  int32_T c6_i17;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv0, 1, 0, 0U, 1, 0U, 2, 1, 4);
  for (c6_i17 = 0; c6_i17 < 4; c6_i17++) {
    c6_y[c6_i17] = c6_dv0[c6_i17];
  }

  sf_mex_destroy(&c6_u);
}

static void c6_i_emlrt_marshallIn(SFc6_ModifiedInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  c6_struct_ZKAzdrl7umDGJoC14aoVKC *c6_y)
{
  emlrtMsgIdentifier c6_thisId;
  static const char * c6_fieldNames[4] = { "fl", "fr", "rl", "rr" };

  c6_thisId.fParent = c6_parentId;
  sf_mex_check_struct(c6_parentId, c6_u, 4, c6_fieldNames, 0U, NULL);
  c6_thisId.fIdentifier = "fl";
  c6_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c6_u, "fl",
    "fl", 0)), &c6_thisId, c6_y->fl);
  c6_thisId.fIdentifier = "fr";
  c6_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c6_u, "fr",
    "fr", 0)), &c6_thisId, c6_y->fr);
  c6_thisId.fIdentifier = "rl";
  c6_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c6_u, "rl",
    "rl", 0)), &c6_thisId, c6_y->rl);
  c6_thisId.fIdentifier = "rr";
  c6_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c6_u, "rr",
    "rr", 0)), &c6_thisId, c6_y->rr);
  sf_mex_destroy(&c6_u);
}

static void c6_j_emlrt_marshallIn(SFc6_ModifiedInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, real_T c6_y[3])
{
  real_T c6_dv1[3];
  int32_T c6_i18;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv1, 1, 0, 0U, 1, 0U, 2, 3, 1);
  for (c6_i18 = 0; c6_i18 < 3; c6_i18++) {
    c6_y[c6_i18] = c6_dv1[c6_i18];
  }

  sf_mex_destroy(&c6_u);
}

static c6_struct_r4FNviKwHfdhB8nQjvQv9 c6_k_emlrt_marshallIn
  (SFc6_ModifiedInstanceStruct *chartInstance, const mxArray *c6_u, const
   emlrtMsgIdentifier *c6_parentId)
{
  c6_struct_r4FNviKwHfdhB8nQjvQv9 c6_y;
  emlrtMsgIdentifier c6_thisId;
  static const char * c6_fieldNames[1] = { "v_set" };

  c6_thisId.fParent = c6_parentId;
  sf_mex_check_struct(c6_parentId, c6_u, 1, c6_fieldNames, 0U, NULL);
  c6_thisId.fIdentifier = "v_set";
  c6_y.v_set = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c6_u, "v_set", "v_set", 0)), &c6_thisId);
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static c6_struct_Y9F1qlBi9AhssksPwemA4G c6_l_emlrt_marshallIn
  (SFc6_ModifiedInstanceStruct *chartInstance, const mxArray *c6_u, const
   emlrtMsgIdentifier *c6_parentId)
{
  c6_struct_Y9F1qlBi9AhssksPwemA4G c6_y;
  emlrtMsgIdentifier c6_thisId;
  static const char * c6_fieldNames[3] = { "v_x", "F_fz", "F_rz" };

  c6_thisId.fParent = c6_parentId;
  sf_mex_check_struct(c6_parentId, c6_u, 3, c6_fieldNames, 0U, NULL);
  c6_thisId.fIdentifier = "v_x";
  c6_y.v_x = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c6_u, "v_x", "v_x", 0)), &c6_thisId);
  c6_thisId.fIdentifier = "F_fz";
  c6_y.F_fz = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c6_u, "F_fz", "F_fz", 0)), &c6_thisId);
  c6_thisId.fIdentifier = "F_rz";
  c6_y.F_rz = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c6_u, "F_rz", "F_rz", 0)), &c6_thisId);
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_Par;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  c6_struct_iBlsPBO3AGnt69vDoTx5zD c6_y;
  SFc6_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc6_ModifiedInstanceStruct *)chartInstanceVoid;
  c6_b_Par = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_Par), &c6_thisId, &c6_y);
  sf_mex_destroy(&c6_b_Par);
  *(c6_struct_iBlsPBO3AGnt69vDoTx5zD *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  real_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc6_ModifiedInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(real_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_nargout;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y;
  SFc6_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc6_ModifiedInstanceStruct *)chartInstanceVoid;
  c6_nargout = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_nargout), &c6_thisId);
  sf_mex_destroy(&c6_nargout);
  *(real_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

const mxArray *sf_c6_Modified_get_eml_resolved_functions_info(void)
{
  const mxArray *c6_nameCaptureInfo = NULL;
  c6_nameCaptureInfo = NULL;
  sf_mex_assign(&c6_nameCaptureInfo, sf_mex_createstruct("structure", 2, 10, 1),
                false);
  c6_info_helper(&c6_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c6_nameCaptureInfo);
  return c6_nameCaptureInfo;
}

static void c6_info_helper(const mxArray **c6_info)
{
  const mxArray *c6_rhs0 = NULL;
  const mxArray *c6_lhs0 = NULL;
  const mxArray *c6_rhs1 = NULL;
  const mxArray *c6_lhs1 = NULL;
  const mxArray *c6_rhs2 = NULL;
  const mxArray *c6_lhs2 = NULL;
  const mxArray *c6_rhs3 = NULL;
  const mxArray *c6_lhs3 = NULL;
  const mxArray *c6_rhs4 = NULL;
  const mxArray *c6_lhs4 = NULL;
  const mxArray *c6_rhs5 = NULL;
  const mxArray *c6_lhs5 = NULL;
  const mxArray *c6_rhs6 = NULL;
  const mxArray *c6_lhs6 = NULL;
  const mxArray *c6_rhs7 = NULL;
  const mxArray *c6_lhs7 = NULL;
  const mxArray *c6_rhs8 = NULL;
  const mxArray *c6_lhs8 = NULL;
  const mxArray *c6_rhs9 = NULL;
  const mxArray *c6_lhs9 = NULL;
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("abs"), "name", "name", 0);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1363713852U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c6_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c6_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 2);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1286818712U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c6_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "context", "context", 3);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("mrdivide"), "name", "name", 3);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410807648U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1370009886U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c6_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 4);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 4);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1389717774U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c6_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 5);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("rdivide"), "name", "name", 5);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1363713880U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c6_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 6);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c6_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 7);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c6_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_div"), "name", "name", 8);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1386423952U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c6_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 9);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c6_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs9), "lhs", "lhs", 9);
  sf_mex_destroy(&c6_rhs0);
  sf_mex_destroy(&c6_lhs0);
  sf_mex_destroy(&c6_rhs1);
  sf_mex_destroy(&c6_lhs1);
  sf_mex_destroy(&c6_rhs2);
  sf_mex_destroy(&c6_lhs2);
  sf_mex_destroy(&c6_rhs3);
  sf_mex_destroy(&c6_lhs3);
  sf_mex_destroy(&c6_rhs4);
  sf_mex_destroy(&c6_lhs4);
  sf_mex_destroy(&c6_rhs5);
  sf_mex_destroy(&c6_lhs5);
  sf_mex_destroy(&c6_rhs6);
  sf_mex_destroy(&c6_lhs6);
  sf_mex_destroy(&c6_rhs7);
  sf_mex_destroy(&c6_lhs7);
  sf_mex_destroy(&c6_rhs8);
  sf_mex_destroy(&c6_lhs8);
  sf_mex_destroy(&c6_rhs9);
  sf_mex_destroy(&c6_lhs9);
}

static const mxArray *c6_emlrt_marshallOut(const char * c6_u)
{
  const mxArray *c6_y = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c6_u)), false);
  return c6_y;
}

static const mxArray *c6_b_emlrt_marshallOut(const uint32_T c6_u)
{
  const mxArray *c6_y = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 7, 0U, 0U, 0U, 0), false);
  return c6_y;
}

static const mxArray *c6_d_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc6_ModifiedInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(int32_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static int32_T c6_m_emlrt_marshallIn(SFc6_ModifiedInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  int32_T c6_y;
  int32_T c6_i19;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_i19, 1, 6, 0U, 0, 0U, 0);
  c6_y = c6_i19;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_sfEvent;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  int32_T c6_y;
  SFc6_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc6_ModifiedInstanceStruct *)chartInstanceVoid;
  c6_b_sfEvent = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_sfEvent),
    &c6_thisId);
  sf_mex_destroy(&c6_b_sfEvent);
  *(int32_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_w_4_bus_io(void *chartInstanceVoid, void *c6_pData)
{
  const mxArray *c6_mxVal = NULL;
  c6_whl_vec4 c6_tmp;
  SFc6_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc6_ModifiedInstanceStruct *)chartInstanceVoid;
  c6_mxVal = NULL;
  c6_tmp.fl = *(real_T *)&((char_T *)(c6_whl_vec4 *)c6_pData)[0];
  c6_tmp.fr = *(real_T *)&((char_T *)(c6_whl_vec4 *)c6_pData)[8];
  c6_tmp.rl = *(real_T *)&((char_T *)(c6_whl_vec4 *)c6_pData)[16];
  c6_tmp.rr = *(real_T *)&((char_T *)(c6_whl_vec4 *)c6_pData)[24];
  sf_mex_assign(&c6_mxVal, c6_sf_marshallOut(chartInstance, &c6_tmp), false);
  return c6_mxVal;
}

static uint8_T c6_n_emlrt_marshallIn(SFc6_ModifiedInstanceStruct *chartInstance,
  const mxArray *c6_b_is_active_c6_Modified, const char_T *c6_identifier)
{
  uint8_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_o_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c6_b_is_active_c6_Modified), &c6_thisId);
  sf_mex_destroy(&c6_b_is_active_c6_Modified);
  return c6_y;
}

static uint8_T c6_o_emlrt_marshallIn(SFc6_ModifiedInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  uint8_T c6_y;
  uint8_T c6_u0;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_u0, 1, 3, 0U, 0, 0U, 0);
  c6_y = c6_u0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void init_dsm_address_info(SFc6_ModifiedInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc6_ModifiedInstanceStruct *chartInstance)
{
  chartInstance->c6_w_4 = (c6_whl_vec4 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c6_F_xywSS4 = (c6_whl_vec4 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c6_derF_xyw4 = (c6_whl_vec4 *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c6_F_xyw4 = (c6_whl_vec4 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
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

void sf_c6_Modified_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2847882799U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3438778853U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2174887641U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3720852981U);
}

mxArray* sf_c6_Modified_get_post_codegen_info(void);
mxArray *sf_c6_Modified_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("Rjl2e1nfR9I8I6RQGORYrG");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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
    mxArray* mxPostCodegenInfo = sf_c6_Modified_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c6_Modified_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c6_Modified_jit_fallback_info(void)
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

mxArray *sf_c6_Modified_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c6_Modified_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c6_Modified(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[7],T\"derF_xyw4\",},{M[8],M[0],T\"is_active_c6_Modified\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c6_Modified_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc6_ModifiedInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc6_ModifiedInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ModifiedMachineNumber_,
           6,
           1,
           1,
           0,
           5,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"w_4");
          _SFD_SET_DATA_PROPS(1,1,1,0,"F_xywSS4");
          _SFD_SET_DATA_PROPS(2,2,0,1,"derF_xyw4");
          _SFD_SET_DATA_PROPS(3,1,1,0,"F_xyw4");
          _SFD_SET_DATA_PROPS(4,10,0,0,"Par");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,404);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_w_4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_w_4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_w_4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_w_4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_b_sf_marshallOut,(MexInFcnForType)c6_b_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c6_w_4);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c6_F_xywSS4);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c6_derF_xyw4);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c6_F_xyw4);
        _SFD_SET_DATA_VALUE_PTR(4U, &chartInstance->c6_Par);
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
  return "wwm8gkqEZWOVzaAPFLk9DF";
}

static void sf_opaque_initialize_c6_Modified(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc6_ModifiedInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c6_Modified((SFc6_ModifiedInstanceStruct*) chartInstanceVar);
  initialize_c6_Modified((SFc6_ModifiedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c6_Modified(void *chartInstanceVar)
{
  enable_c6_Modified((SFc6_ModifiedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c6_Modified(void *chartInstanceVar)
{
  disable_c6_Modified((SFc6_ModifiedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c6_Modified(void *chartInstanceVar)
{
  sf_gateway_c6_Modified((SFc6_ModifiedInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c6_Modified(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c6_Modified((SFc6_ModifiedInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c6_Modified(SimStruct* S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c6_Modified((SFc6_ModifiedInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c6_Modified(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc6_ModifiedInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Modified_optimization_info();
    }

    finalize_c6_Modified((SFc6_ModifiedInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc6_Modified((SFc6_ModifiedInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c6_Modified(SimStruct *S)
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
    initialize_params_c6_Modified((SFc6_ModifiedInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c6_Modified(SimStruct *S)
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
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,6);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,6,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,6,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,6);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,6,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,6,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,6);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2080609482U));
  ssSetChecksum1(S,(216413167U));
  ssSetChecksum2(S,(2562681437U));
  ssSetChecksum3(S,(1945286189U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c6_Modified(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c6_Modified(SimStruct *S)
{
  SFc6_ModifiedInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc6_ModifiedInstanceStruct *)utMalloc(sizeof
    (SFc6_ModifiedInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc6_ModifiedInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c6_Modified;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c6_Modified;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c6_Modified;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c6_Modified;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c6_Modified;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c6_Modified;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c6_Modified;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c6_Modified;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c6_Modified;
  chartInstance->chartInfo.mdlStart = mdlStart_c6_Modified;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c6_Modified;
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

void c6_Modified_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c6_Modified(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c6_Modified(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c6_Modified(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c6_Modified_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
