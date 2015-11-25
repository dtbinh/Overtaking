/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Modified_sfun.h"
#include "c30_Modified.h"
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
static const char * c30_debug_family_names[10] = { "Rw", "nargin", "nargout",
  "w_4", "v_xw4", "v_yw4", "Par", "s_x4", "s_y4", "s_xy4" };

/* Function Declarations */
static void initialize_c30_Modified(SFc30_ModifiedInstanceStruct *chartInstance);
static void initialize_params_c30_Modified(SFc30_ModifiedInstanceStruct
  *chartInstance);
static void enable_c30_Modified(SFc30_ModifiedInstanceStruct *chartInstance);
static void disable_c30_Modified(SFc30_ModifiedInstanceStruct *chartInstance);
static void c30_update_debugger_state_c30_Modified(SFc30_ModifiedInstanceStruct *
  chartInstance);
static const mxArray *get_sim_state_c30_Modified(SFc30_ModifiedInstanceStruct
  *chartInstance);
static void set_sim_state_c30_Modified(SFc30_ModifiedInstanceStruct
  *chartInstance, const mxArray *c30_st);
static void finalize_c30_Modified(SFc30_ModifiedInstanceStruct *chartInstance);
static void sf_gateway_c30_Modified(SFc30_ModifiedInstanceStruct *chartInstance);
static void mdl_start_c30_Modified(SFc30_ModifiedInstanceStruct *chartInstance);
static void c30_chartstep_c30_Modified(SFc30_ModifiedInstanceStruct
  *chartInstance);
static void initSimStructsc30_Modified(SFc30_ModifiedInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c30_machineNumber, uint32_T
  c30_chartNumber, uint32_T c30_instanceNumber);
static const mxArray *c30_sf_marshallOut(void *chartInstanceVoid, void
  *c30_inData);
static c30_whl_vec4 c30_emlrt_marshallIn(SFc30_ModifiedInstanceStruct
  *chartInstance, const mxArray *c30_b_s_xy4, const char_T *c30_identifier);
static c30_whl_vec4 c30_b_emlrt_marshallIn(SFc30_ModifiedInstanceStruct
  *chartInstance, const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId);
static real_T c30_c_emlrt_marshallIn(SFc30_ModifiedInstanceStruct *chartInstance,
  const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId);
static void c30_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c30_mxArrayInData, const char_T *c30_varName, void *c30_outData);
static const mxArray *c30_b_sf_marshallOut(void *chartInstanceVoid, void
  *c30_inData);
static void c30_d_emlrt_marshallIn(SFc30_ModifiedInstanceStruct *chartInstance,
  const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId,
  c30_struct_iBlsPBO3AGnt69vDoTx5zD *c30_y);
static void c30_e_emlrt_marshallIn(SFc30_ModifiedInstanceStruct *chartInstance,
  const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId,
  c30_struct_Nst2vGTExxHsg85EUOj9EH *c30_y);
static c30_struct_HhckT6rntEraqECYVIDvCC c30_f_emlrt_marshallIn
  (SFc30_ModifiedInstanceStruct *chartInstance, const mxArray *c30_u, const
   emlrtMsgIdentifier *c30_parentId);
static void c30_g_emlrt_marshallIn(SFc30_ModifiedInstanceStruct *chartInstance,
  const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId,
  c30_struct_ZCmOWPuqBDw16FSOVVD00 *c30_y);
static void c30_h_emlrt_marshallIn(SFc30_ModifiedInstanceStruct *chartInstance,
  const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId, real_T c30_y[4]);
static void c30_i_emlrt_marshallIn(SFc30_ModifiedInstanceStruct *chartInstance,
  const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId,
  c30_struct_ZKAzdrl7umDGJoC14aoVKC *c30_y);
static void c30_j_emlrt_marshallIn(SFc30_ModifiedInstanceStruct *chartInstance,
  const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId, real_T c30_y[3]);
static c30_struct_r4FNviKwHfdhB8nQjvQv9 c30_k_emlrt_marshallIn
  (SFc30_ModifiedInstanceStruct *chartInstance, const mxArray *c30_u, const
   emlrtMsgIdentifier *c30_parentId);
static c30_struct_Y9F1qlBi9AhssksPwemA4G c30_l_emlrt_marshallIn
  (SFc30_ModifiedInstanceStruct *chartInstance, const mxArray *c30_u, const
   emlrtMsgIdentifier *c30_parentId);
static void c30_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c30_mxArrayInData, const char_T *c30_varName, void *c30_outData);
static const mxArray *c30_c_sf_marshallOut(void *chartInstanceVoid, void
  *c30_inData);
static void c30_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c30_mxArrayInData, const char_T *c30_varName, void *c30_outData);
static void c30_info_helper(const mxArray **c30_info);
static const mxArray *c30_emlrt_marshallOut(const char * c30_u);
static const mxArray *c30_b_emlrt_marshallOut(const uint32_T c30_u);
static real_T c30_abs(SFc30_ModifiedInstanceStruct *chartInstance, real_T c30_x);
static real_T c30_mpower(SFc30_ModifiedInstanceStruct *chartInstance, real_T
  c30_a);
static void c30_eml_scalar_eg(SFc30_ModifiedInstanceStruct *chartInstance);
static void c30_eml_error(SFc30_ModifiedInstanceStruct *chartInstance);
static const mxArray *c30_d_sf_marshallOut(void *chartInstanceVoid, void
  *c30_inData);
static int32_T c30_m_emlrt_marshallIn(SFc30_ModifiedInstanceStruct
  *chartInstance, const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId);
static void c30_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c30_mxArrayInData, const char_T *c30_varName, void *c30_outData);
static const mxArray *c30_w_4_bus_io(void *chartInstanceVoid, void *c30_pData);
static uint8_T c30_n_emlrt_marshallIn(SFc30_ModifiedInstanceStruct
  *chartInstance, const mxArray *c30_b_is_active_c30_Modified, const char_T
  *c30_identifier);
static uint8_T c30_o_emlrt_marshallIn(SFc30_ModifiedInstanceStruct
  *chartInstance, const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId);
static void init_dsm_address_info(SFc30_ModifiedInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc30_ModifiedInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c30_Modified(SFc30_ModifiedInstanceStruct *chartInstance)
{
  chartInstance->c30_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c30_is_active_c30_Modified = 0U;
}

static void initialize_params_c30_Modified(SFc30_ModifiedInstanceStruct
  *chartInstance)
{
  const mxArray *c30_m0 = NULL;
  const mxArray *c30_mxField;
  const mxArray *c30_m1 = NULL;
  const mxArray *c30_b_mxField;
  c30_struct_iBlsPBO3AGnt69vDoTx5zD c30_r0;
  const mxArray *c30_m2 = NULL;
  const mxArray *c30_c_mxField;
  const mxArray *c30_m3 = NULL;
  const mxArray *c30_d_mxField;
  const mxArray *c30_m4 = NULL;
  const mxArray *c30_e_mxField;
  const mxArray *c30_m5 = NULL;
  const mxArray *c30_f_mxField;
  const mxArray *c30_m6 = NULL;
  const mxArray *c30_g_mxField;
  const mxArray *c30_m7 = NULL;
  const mxArray *c30_h_mxField;
  const mxArray *c30_m8 = NULL;
  const mxArray *c30_i_mxField;
  const mxArray *c30_m9 = NULL;
  const mxArray *c30_j_mxField;
  const mxArray *c30_m10 = NULL;
  const mxArray *c30_k_mxField;
  const mxArray *c30_m11 = NULL;
  const mxArray *c30_l_mxField;
  const mxArray *c30_m12 = NULL;
  const mxArray *c30_m_mxField;
  const mxArray *c30_m13 = NULL;
  const mxArray *c30_n_mxField;
  c30_m0 = sf_mex_get_sfun_param(chartInstance->S, 0, 1);
  c30_mxField = sf_mex_getfield(c30_m0, "Env", "Par", 0);
  c30_m1 = sf_mex_dup(c30_mxField);
  c30_b_mxField = sf_mex_getfield(c30_m1, "g", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_b_mxField), &c30_r0.Env.g, 1, 0, 0U,
                      0, 0U, 0);
  c30_b_mxField = sf_mex_getfield(c30_m1, "left1", "Par", 0);
  c30_m2 = sf_mex_dup(c30_b_mxField);
  c30_c_mxField = sf_mex_getfield(c30_m2, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_c_mxField), &c30_r0.Env.left1.x, 1,
                      0, 0U, 0, 0U, 0);
  c30_c_mxField = sf_mex_getfield(c30_m2, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_c_mxField), &c30_r0.Env.left1.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c30_m2);
  c30_b_mxField = sf_mex_getfield(c30_m1, "right1", "Par", 0);
  c30_m3 = sf_mex_dup(c30_b_mxField);
  c30_d_mxField = sf_mex_getfield(c30_m3, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_d_mxField), &c30_r0.Env.right1.x, 1,
                      0, 0U, 0, 0U, 0);
  c30_d_mxField = sf_mex_getfield(c30_m3, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_d_mxField), &c30_r0.Env.right1.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c30_m3);
  c30_b_mxField = sf_mex_getfield(c30_m1, "right2", "Par", 0);
  c30_m4 = sf_mex_dup(c30_b_mxField);
  c30_e_mxField = sf_mex_getfield(c30_m4, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_e_mxField), &c30_r0.Env.right2.x, 1,
                      0, 0U, 0, 0U, 0);
  c30_e_mxField = sf_mex_getfield(c30_m4, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_e_mxField), &c30_r0.Env.right2.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c30_m4);
  c30_b_mxField = sf_mex_getfield(c30_m1, "left2", "Par", 0);
  c30_m5 = sf_mex_dup(c30_b_mxField);
  c30_f_mxField = sf_mex_getfield(c30_m5, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_f_mxField), &c30_r0.Env.left2.x, 1,
                      0, 0U, 0, 0U, 0);
  c30_f_mxField = sf_mex_getfield(c30_m5, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_f_mxField), &c30_r0.Env.left2.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c30_m5);
  c30_b_mxField = sf_mex_getfield(c30_m1, "right3", "Par", 0);
  c30_m6 = sf_mex_dup(c30_b_mxField);
  c30_g_mxField = sf_mex_getfield(c30_m6, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_g_mxField), &c30_r0.Env.right3.x, 1,
                      0, 0U, 0, 0U, 0);
  c30_g_mxField = sf_mex_getfield(c30_m6, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_g_mxField), &c30_r0.Env.right3.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c30_m6);
  c30_b_mxField = sf_mex_getfield(c30_m1, "mu", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_b_mxField), &c30_r0.Env.mu, 1, 0, 0U,
                      0, 0U, 0);
  sf_mex_destroy(&c30_m1);
  c30_mxField = sf_mex_getfield(c30_m0, "Veh", "Par", 0);
  c30_m7 = sf_mex_dup(c30_mxField);
  c30_h_mxField = sf_mex_getfield(c30_m7, "m", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_h_mxField), &c30_r0.Veh.m, 1, 0, 0U,
                      0, 0U, 0);
  c30_h_mxField = sf_mex_getfield(c30_m7, "Jz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_h_mxField), &c30_r0.Veh.Jz, 1, 0, 0U,
                      0, 0U, 0);
  c30_h_mxField = sf_mex_getfield(c30_m7, "m_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_h_mxField), &c30_r0.Veh.m_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c30_h_mxField = sf_mex_getfield(c30_m7, "Jx_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_h_mxField), &c30_r0.Veh.Jx_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c30_h_mxField = sf_mex_getfield(c30_m7, "Jy_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_h_mxField), &c30_r0.Veh.Jy_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c30_h_mxField = sf_mex_getfield(c30_m7, "lf", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_h_mxField), &c30_r0.Veh.lf, 1, 0, 0U,
                      0, 0U, 0);
  c30_h_mxField = sf_mex_getfield(c30_m7, "lr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_h_mxField), &c30_r0.Veh.lr, 1, 0, 0U,
                      0, 0U, 0);
  c30_h_mxField = sf_mex_getfield(c30_m7, "L", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_h_mxField), &c30_r0.Veh.L, 1, 0, 0U,
                      0, 0U, 0);
  c30_h_mxField = sf_mex_getfield(c30_m7, "TrackWidth", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_h_mxField), &c30_r0.Veh.TrackWidth,
                      1, 0, 0U, 0, 0U, 0);
  c30_h_mxField = sf_mex_getfield(c30_m7, "h", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_h_mxField), &c30_r0.Veh.h, 1, 0, 0U,
                      0, 0U, 0);
  c30_h_mxField = sf_mex_getfield(c30_m7, "HalfRohACd", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_h_mxField), &c30_r0.Veh.HalfRohACd,
                      1, 0, 0U, 0, 0U, 0);
  c30_h_mxField = sf_mex_getfield(c30_m7, "F_z4_static", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_h_mxField), c30_r0.Veh.F_z4_static,
                      1, 0, 0U, 1, 0U, 2, 1, 4);
  c30_h_mxField = sf_mex_getfield(c30_m7, "Rw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_h_mxField), &c30_r0.Veh.Rw, 1, 0, 0U,
                      0, 0U, 0);
  c30_h_mxField = sf_mex_getfield(c30_m7, "r_long", "Par", 0);
  c30_m8 = sf_mex_dup(c30_h_mxField);
  c30_i_mxField = sf_mex_getfield(c30_m8, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_i_mxField), c30_r0.Veh.r_long.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c30_i_mxField = sf_mex_getfield(c30_m8, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_i_mxField), c30_r0.Veh.r_long.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c30_i_mxField = sf_mex_getfield(c30_m8, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_i_mxField), c30_r0.Veh.r_long.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c30_i_mxField = sf_mex_getfield(c30_m8, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_i_mxField), c30_r0.Veh.r_long.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c30_m8);
  c30_h_mxField = sf_mex_getfield(c30_m7, "r_lat", "Par", 0);
  c30_m9 = sf_mex_dup(c30_h_mxField);
  c30_j_mxField = sf_mex_getfield(c30_m9, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_j_mxField), c30_r0.Veh.r_lat.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c30_j_mxField = sf_mex_getfield(c30_m9, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_j_mxField), c30_r0.Veh.r_lat.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c30_j_mxField = sf_mex_getfield(c30_m9, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_j_mxField), c30_r0.Veh.r_lat.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c30_j_mxField = sf_mex_getfield(c30_m9, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_j_mxField), c30_r0.Veh.r_lat.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c30_m9);
  c30_h_mxField = sf_mex_getfield(c30_m7, "r_lever", "Par", 0);
  c30_m10 = sf_mex_dup(c30_h_mxField);
  c30_k_mxField = sf_mex_getfield(c30_m10, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_k_mxField), c30_r0.Veh.r_lever.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c30_k_mxField = sf_mex_getfield(c30_m10, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_k_mxField), c30_r0.Veh.r_lever.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c30_k_mxField = sf_mex_getfield(c30_m10, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_k_mxField), c30_r0.Veh.r_lever.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c30_k_mxField = sf_mex_getfield(c30_m10, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_k_mxField), c30_r0.Veh.r_lever.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c30_m10);
  c30_h_mxField = sf_mex_getfield(c30_m7, "r_pivot", "Par", 0);
  c30_m11 = sf_mex_dup(c30_h_mxField);
  c30_l_mxField = sf_mex_getfield(c30_m11, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_l_mxField), c30_r0.Veh.r_pivot.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c30_l_mxField = sf_mex_getfield(c30_m11, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_l_mxField), c30_r0.Veh.r_pivot.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c30_l_mxField = sf_mex_getfield(c30_m11, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_l_mxField), c30_r0.Veh.r_pivot.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c30_l_mxField = sf_mex_getfield(c30_m11, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_l_mxField), c30_r0.Veh.r_pivot.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c30_m11);
  c30_h_mxField = sf_mex_getfield(c30_m7, "cw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_h_mxField), &c30_r0.Veh.cw, 1, 0, 0U,
                      0, 0U, 0);
  c30_h_mxField = sf_mex_getfield(c30_m7, "carb_f", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_h_mxField), &c30_r0.Veh.carb_f, 1, 0,
                      0U, 0, 0U, 0);
  c30_h_mxField = sf_mex_getfield(c30_m7, "carb_r", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_h_mxField), &c30_r0.Veh.carb_r, 1, 0,
                      0U, 0, 0U, 0);
  c30_h_mxField = sf_mex_getfield(c30_m7, "dw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_h_mxField), &c30_r0.Veh.dw, 1, 0, 0U,
                      0, 0U, 0);
  c30_h_mxField = sf_mex_getfield(c30_m7, "Jw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_h_mxField), &c30_r0.Veh.Jw, 1, 0, 0U,
                      0, 0U, 0);
  c30_h_mxField = sf_mex_getfield(c30_m7, "C0", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_h_mxField), &c30_r0.Veh.C0, 1, 0, 0U,
                      0, 0U, 0);
  c30_h_mxField = sf_mex_getfield(c30_m7, "RelaxLength", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_h_mxField), &c30_r0.Veh.RelaxLength,
                      1, 0, 0U, 0, 0U, 0);
  c30_h_mxField = sf_mex_getfield(c30_m7, "RRC", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_h_mxField), &c30_r0.Veh.RRC, 1, 0,
                      0U, 0, 0U, 0);
  c30_h_mxField = sf_mex_getfield(c30_m7, "Pmax", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_h_mxField), &c30_r0.Veh.Pmax, 1, 0,
                      0U, 0, 0U, 0);
  c30_h_mxField = sf_mex_getfield(c30_m7, "PropDistrFrnt", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_h_mxField),
                      &c30_r0.Veh.PropDistrFrnt, 1, 0, 0U, 0, 0U, 0);
  c30_h_mxField = sf_mex_getfield(c30_m7, "BrkDistrFrnt", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_h_mxField), &c30_r0.Veh.BrkDistrFrnt,
                      1, 0, 0U, 0, 0U, 0);
  c30_h_mxField = sf_mex_getfield(c30_m7, "SteRatio", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_h_mxField), &c30_r0.Veh.SteRatio, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c30_m7);
  c30_mxField = sf_mex_getfield(c30_m0, "Drvr", "Par", 0);
  c30_m12 = sf_mex_dup(c30_mxField);
  c30_m_mxField = sf_mex_getfield(c30_m12, "v_set", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_m_mxField), &c30_r0.Drvr.v_set, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c30_m12);
  c30_mxField = sf_mex_getfield(c30_m0, "Init", "Par", 0);
  c30_m13 = sf_mex_dup(c30_mxField);
  c30_n_mxField = sf_mex_getfield(c30_m13, "v_x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_n_mxField), &c30_r0.Init.v_x, 1, 0,
                      0U, 0, 0U, 0);
  c30_n_mxField = sf_mex_getfield(c30_m13, "F_fz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_n_mxField), &c30_r0.Init.F_fz, 1, 0,
                      0U, 0, 0U, 0);
  c30_n_mxField = sf_mex_getfield(c30_m13, "F_rz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c30_n_mxField), &c30_r0.Init.F_rz, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c30_m13);
  sf_mex_destroy(&c30_m0);
  chartInstance->c30_Par = c30_r0;
}

static void enable_c30_Modified(SFc30_ModifiedInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c30_Modified(SFc30_ModifiedInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c30_update_debugger_state_c30_Modified(SFc30_ModifiedInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c30_Modified(SFc30_ModifiedInstanceStruct
  *chartInstance)
{
  const mxArray *c30_st;
  const mxArray *c30_y = NULL;
  const mxArray *c30_b_y = NULL;
  real_T c30_u;
  const mxArray *c30_c_y = NULL;
  real_T c30_b_u;
  const mxArray *c30_d_y = NULL;
  real_T c30_c_u;
  const mxArray *c30_e_y = NULL;
  real_T c30_d_u;
  const mxArray *c30_f_y = NULL;
  const mxArray *c30_g_y = NULL;
  real_T c30_e_u;
  const mxArray *c30_h_y = NULL;
  real_T c30_f_u;
  const mxArray *c30_i_y = NULL;
  real_T c30_g_u;
  const mxArray *c30_j_y = NULL;
  real_T c30_h_u;
  const mxArray *c30_k_y = NULL;
  const mxArray *c30_l_y = NULL;
  real_T c30_i_u;
  const mxArray *c30_m_y = NULL;
  real_T c30_j_u;
  const mxArray *c30_n_y = NULL;
  real_T c30_k_u;
  const mxArray *c30_o_y = NULL;
  real_T c30_l_u;
  const mxArray *c30_p_y = NULL;
  uint8_T c30_hoistedGlobal;
  uint8_T c30_m_u;
  const mxArray *c30_q_y = NULL;
  c30_st = NULL;
  c30_st = NULL;
  c30_y = NULL;
  sf_mex_assign(&c30_y, sf_mex_createcellmatrix(4, 1), false);
  c30_b_y = NULL;
  sf_mex_assign(&c30_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c30_u = *(real_T *)&((char_T *)chartInstance->c30_s_x4)[0];
  c30_c_y = NULL;
  sf_mex_assign(&c30_c_y, sf_mex_create("y", &c30_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c30_b_y, c30_c_y, "fl", "fl", 0);
  c30_b_u = *(real_T *)&((char_T *)chartInstance->c30_s_x4)[8];
  c30_d_y = NULL;
  sf_mex_assign(&c30_d_y, sf_mex_create("y", &c30_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c30_b_y, c30_d_y, "fr", "fr", 0);
  c30_c_u = *(real_T *)&((char_T *)chartInstance->c30_s_x4)[16];
  c30_e_y = NULL;
  sf_mex_assign(&c30_e_y, sf_mex_create("y", &c30_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c30_b_y, c30_e_y, "rl", "rl", 0);
  c30_d_u = *(real_T *)&((char_T *)chartInstance->c30_s_x4)[24];
  c30_f_y = NULL;
  sf_mex_assign(&c30_f_y, sf_mex_create("y", &c30_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c30_b_y, c30_f_y, "rr", "rr", 0);
  sf_mex_setcell(c30_y, 0, c30_b_y);
  c30_g_y = NULL;
  sf_mex_assign(&c30_g_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c30_e_u = *(real_T *)&((char_T *)chartInstance->c30_s_xy4)[0];
  c30_h_y = NULL;
  sf_mex_assign(&c30_h_y, sf_mex_create("y", &c30_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c30_g_y, c30_h_y, "fl", "fl", 0);
  c30_f_u = *(real_T *)&((char_T *)chartInstance->c30_s_xy4)[8];
  c30_i_y = NULL;
  sf_mex_assign(&c30_i_y, sf_mex_create("y", &c30_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c30_g_y, c30_i_y, "fr", "fr", 0);
  c30_g_u = *(real_T *)&((char_T *)chartInstance->c30_s_xy4)[16];
  c30_j_y = NULL;
  sf_mex_assign(&c30_j_y, sf_mex_create("y", &c30_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c30_g_y, c30_j_y, "rl", "rl", 0);
  c30_h_u = *(real_T *)&((char_T *)chartInstance->c30_s_xy4)[24];
  c30_k_y = NULL;
  sf_mex_assign(&c30_k_y, sf_mex_create("y", &c30_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c30_g_y, c30_k_y, "rr", "rr", 0);
  sf_mex_setcell(c30_y, 1, c30_g_y);
  c30_l_y = NULL;
  sf_mex_assign(&c30_l_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c30_i_u = *(real_T *)&((char_T *)chartInstance->c30_s_y4)[0];
  c30_m_y = NULL;
  sf_mex_assign(&c30_m_y, sf_mex_create("y", &c30_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c30_l_y, c30_m_y, "fl", "fl", 0);
  c30_j_u = *(real_T *)&((char_T *)chartInstance->c30_s_y4)[8];
  c30_n_y = NULL;
  sf_mex_assign(&c30_n_y, sf_mex_create("y", &c30_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c30_l_y, c30_n_y, "fr", "fr", 0);
  c30_k_u = *(real_T *)&((char_T *)chartInstance->c30_s_y4)[16];
  c30_o_y = NULL;
  sf_mex_assign(&c30_o_y, sf_mex_create("y", &c30_k_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c30_l_y, c30_o_y, "rl", "rl", 0);
  c30_l_u = *(real_T *)&((char_T *)chartInstance->c30_s_y4)[24];
  c30_p_y = NULL;
  sf_mex_assign(&c30_p_y, sf_mex_create("y", &c30_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c30_l_y, c30_p_y, "rr", "rr", 0);
  sf_mex_setcell(c30_y, 2, c30_l_y);
  c30_hoistedGlobal = chartInstance->c30_is_active_c30_Modified;
  c30_m_u = c30_hoistedGlobal;
  c30_q_y = NULL;
  sf_mex_assign(&c30_q_y, sf_mex_create("y", &c30_m_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c30_y, 3, c30_q_y);
  sf_mex_assign(&c30_st, c30_y, false);
  return c30_st;
}

static void set_sim_state_c30_Modified(SFc30_ModifiedInstanceStruct
  *chartInstance, const mxArray *c30_st)
{
  const mxArray *c30_u;
  c30_whl_vec4 c30_r1;
  c30_whl_vec4 c30_r2;
  c30_whl_vec4 c30_r3;
  chartInstance->c30_doneDoubleBufferReInit = true;
  c30_u = sf_mex_dup(c30_st);
  c30_r1 = c30_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c30_u,
    0)), "s_x4");
  *(real_T *)&((char_T *)chartInstance->c30_s_x4)[0] = c30_r1.fl;
  *(real_T *)&((char_T *)chartInstance->c30_s_x4)[8] = c30_r1.fr;
  *(real_T *)&((char_T *)chartInstance->c30_s_x4)[16] = c30_r1.rl;
  *(real_T *)&((char_T *)chartInstance->c30_s_x4)[24] = c30_r1.rr;
  c30_r2 = c30_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c30_u,
    1)), "s_xy4");
  *(real_T *)&((char_T *)chartInstance->c30_s_xy4)[0] = c30_r2.fl;
  *(real_T *)&((char_T *)chartInstance->c30_s_xy4)[8] = c30_r2.fr;
  *(real_T *)&((char_T *)chartInstance->c30_s_xy4)[16] = c30_r2.rl;
  *(real_T *)&((char_T *)chartInstance->c30_s_xy4)[24] = c30_r2.rr;
  c30_r3 = c30_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c30_u,
    2)), "s_y4");
  *(real_T *)&((char_T *)chartInstance->c30_s_y4)[0] = c30_r3.fl;
  *(real_T *)&((char_T *)chartInstance->c30_s_y4)[8] = c30_r3.fr;
  *(real_T *)&((char_T *)chartInstance->c30_s_y4)[16] = c30_r3.rl;
  *(real_T *)&((char_T *)chartInstance->c30_s_y4)[24] = c30_r3.rr;
  chartInstance->c30_is_active_c30_Modified = c30_n_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c30_u, 3)),
     "is_active_c30_Modified");
  sf_mex_destroy(&c30_u);
  c30_update_debugger_state_c30_Modified(chartInstance);
  sf_mex_destroy(&c30_st);
}

static void finalize_c30_Modified(SFc30_ModifiedInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c30_Modified(SFc30_ModifiedInstanceStruct *chartInstance)
{
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 29U, chartInstance->c30_sfEvent);
  chartInstance->c30_sfEvent = CALL_EVENT;
  c30_chartstep_c30_Modified(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_ModifiedMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c30_Modified(SFc30_ModifiedInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c30_chartstep_c30_Modified(SFc30_ModifiedInstanceStruct
  *chartInstance)
{
  c30_whl_vec4 c30_b_w_4;
  c30_whl_vec4 c30_b_v_xw4;
  c30_whl_vec4 c30_b_v_yw4;
  c30_struct_iBlsPBO3AGnt69vDoTx5zD c30_b_Par;
  uint32_T c30_debug_family_var_map[10];
  real_T c30_Rw;
  real_T c30_nargin = 4.0;
  real_T c30_nargout = 3.0;
  c30_whl_vec4 c30_b_s_x4;
  c30_whl_vec4 c30_b_s_y4;
  c30_whl_vec4 c30_b_s_xy4;
  real_T c30_A;
  real_T c30_x;
  real_T c30_b_x;
  real_T c30_c_x;
  real_T c30_y;
  real_T c30_b_A;
  real_T c30_B;
  real_T c30_d_x;
  real_T c30_b_y;
  real_T c30_e_x;
  real_T c30_c_y;
  real_T c30_f_x;
  real_T c30_d_y;
  real_T c30_e_y;
  real_T c30_c_A;
  real_T c30_g_x;
  real_T c30_h_x;
  real_T c30_i_x;
  real_T c30_f_y;
  real_T c30_d_A;
  real_T c30_b_B;
  real_T c30_j_x;
  real_T c30_g_y;
  real_T c30_k_x;
  real_T c30_h_y;
  real_T c30_l_x;
  real_T c30_i_y;
  real_T c30_j_y;
  real_T c30_e_A;
  real_T c30_m_x;
  real_T c30_n_x;
  real_T c30_o_x;
  real_T c30_k_y;
  real_T c30_f_A;
  real_T c30_c_B;
  real_T c30_p_x;
  real_T c30_l_y;
  real_T c30_q_x;
  real_T c30_m_y;
  real_T c30_r_x;
  real_T c30_n_y;
  real_T c30_o_y;
  real_T c30_g_A;
  real_T c30_s_x;
  real_T c30_t_x;
  real_T c30_u_x;
  real_T c30_p_y;
  real_T c30_h_A;
  real_T c30_d_B;
  real_T c30_v_x;
  real_T c30_q_y;
  real_T c30_w_x;
  real_T c30_r_y;
  real_T c30_x_x;
  real_T c30_s_y;
  real_T c30_t_y;
  real_T c30_y_x;
  real_T c30_ab_x;
  real_T c30_u_y;
  real_T c30_i_A;
  real_T c30_bb_x;
  real_T c30_cb_x;
  real_T c30_db_x;
  real_T c30_v_y;
  real_T c30_j_A;
  real_T c30_e_B;
  real_T c30_eb_x;
  real_T c30_w_y;
  real_T c30_fb_x;
  real_T c30_x_y;
  real_T c30_gb_x;
  real_T c30_y_y;
  real_T c30_ab_y;
  real_T c30_hb_x;
  real_T c30_ib_x;
  real_T c30_bb_y;
  real_T c30_k_A;
  real_T c30_jb_x;
  real_T c30_kb_x;
  real_T c30_lb_x;
  real_T c30_cb_y;
  real_T c30_l_A;
  real_T c30_f_B;
  real_T c30_mb_x;
  real_T c30_db_y;
  real_T c30_nb_x;
  real_T c30_eb_y;
  real_T c30_ob_x;
  real_T c30_fb_y;
  real_T c30_gb_y;
  real_T c30_pb_x;
  real_T c30_qb_x;
  real_T c30_hb_y;
  real_T c30_m_A;
  real_T c30_rb_x;
  real_T c30_sb_x;
  real_T c30_tb_x;
  real_T c30_ib_y;
  real_T c30_n_A;
  real_T c30_g_B;
  real_T c30_ub_x;
  real_T c30_jb_y;
  real_T c30_vb_x;
  real_T c30_kb_y;
  real_T c30_wb_x;
  real_T c30_lb_y;
  real_T c30_mb_y;
  real_T c30_xb_x;
  real_T c30_yb_x;
  real_T c30_nb_y;
  real_T c30_o_A;
  real_T c30_ac_x;
  real_T c30_bc_x;
  real_T c30_cc_x;
  real_T c30_ob_y;
  real_T c30_p_A;
  real_T c30_h_B;
  real_T c30_dc_x;
  real_T c30_pb_y;
  real_T c30_ec_x;
  real_T c30_qb_y;
  real_T c30_fc_x;
  real_T c30_rb_y;
  real_T c30_sb_y;
  real_T c30_gc_x;
  real_T c30_hc_x;
  real_T c30_ic_x;
  real_T c30_jc_x;
  real_T c30_kc_x;
  real_T c30_lc_x;
  real_T c30_mc_x;
  real_T c30_nc_x;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 29U, chartInstance->c30_sfEvent);
  c30_b_w_4.fl = *(real_T *)&((char_T *)chartInstance->c30_w_4)[0];
  c30_b_w_4.fr = *(real_T *)&((char_T *)chartInstance->c30_w_4)[8];
  c30_b_w_4.rl = *(real_T *)&((char_T *)chartInstance->c30_w_4)[16];
  c30_b_w_4.rr = *(real_T *)&((char_T *)chartInstance->c30_w_4)[24];
  c30_b_v_xw4.fl = *(real_T *)&((char_T *)chartInstance->c30_v_xw4)[0];
  c30_b_v_xw4.fr = *(real_T *)&((char_T *)chartInstance->c30_v_xw4)[8];
  c30_b_v_xw4.rl = *(real_T *)&((char_T *)chartInstance->c30_v_xw4)[16];
  c30_b_v_xw4.rr = *(real_T *)&((char_T *)chartInstance->c30_v_xw4)[24];
  c30_b_v_yw4.fl = *(real_T *)&((char_T *)chartInstance->c30_v_yw4)[0];
  c30_b_v_yw4.fr = *(real_T *)&((char_T *)chartInstance->c30_v_yw4)[8];
  c30_b_v_yw4.rl = *(real_T *)&((char_T *)chartInstance->c30_v_yw4)[16];
  c30_b_v_yw4.rr = *(real_T *)&((char_T *)chartInstance->c30_v_yw4)[24];
  c30_b_Par = chartInstance->c30_Par;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 10U, 10U, c30_debug_family_names,
    c30_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c30_Rw, 0U, c30_c_sf_marshallOut,
    c30_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c30_nargin, 1U, c30_c_sf_marshallOut,
    c30_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c30_nargout, 2U, c30_c_sf_marshallOut,
    c30_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c30_b_w_4, 3U, c30_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c30_b_v_xw4, 4U, c30_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c30_b_v_yw4, 5U, c30_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c30_b_Par, 6U, c30_b_sf_marshallOut,
    c30_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c30_b_s_x4, 7U, c30_sf_marshallOut,
    c30_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c30_b_s_y4, 8U, c30_sf_marshallOut,
    c30_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c30_b_s_xy4, 9U, c30_sf_marshallOut,
    c30_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 4);
  c30_Rw = c30_b_Par.Veh.Rw;
  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 6);
  c30_A = c30_abs(chartInstance, c30_Rw * c30_b_w_4.fl + c30_b_v_xw4.fl);
  c30_x = c30_A;
  c30_b_x = c30_x;
  c30_c_x = c30_b_x;
  c30_y = c30_c_x / 2.0;
  c30_b_A = c30_Rw * c30_b_w_4.fl - c30_b_v_xw4.fl;
  c30_B = c30_y;
  c30_d_x = c30_b_A;
  c30_b_y = c30_B;
  c30_e_x = c30_d_x;
  c30_c_y = c30_b_y;
  c30_f_x = c30_e_x;
  c30_d_y = c30_c_y;
  c30_e_y = c30_f_x / c30_d_y;
  c30_b_s_x4.fl = c30_e_y;
  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 7);
  c30_c_A = c30_abs(chartInstance, c30_Rw * c30_b_w_4.fr + c30_b_v_xw4.fr);
  c30_g_x = c30_c_A;
  c30_h_x = c30_g_x;
  c30_i_x = c30_h_x;
  c30_f_y = c30_i_x / 2.0;
  c30_d_A = c30_Rw * c30_b_w_4.fr - c30_b_v_xw4.fr;
  c30_b_B = c30_f_y;
  c30_j_x = c30_d_A;
  c30_g_y = c30_b_B;
  c30_k_x = c30_j_x;
  c30_h_y = c30_g_y;
  c30_l_x = c30_k_x;
  c30_i_y = c30_h_y;
  c30_j_y = c30_l_x / c30_i_y;
  c30_b_s_x4.fr = c30_j_y;
  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 8);
  c30_e_A = c30_abs(chartInstance, c30_Rw * c30_b_w_4.rl + c30_b_v_xw4.rl);
  c30_m_x = c30_e_A;
  c30_n_x = c30_m_x;
  c30_o_x = c30_n_x;
  c30_k_y = c30_o_x / 2.0;
  c30_f_A = c30_Rw * c30_b_w_4.rl - c30_b_v_xw4.rl;
  c30_c_B = c30_k_y;
  c30_p_x = c30_f_A;
  c30_l_y = c30_c_B;
  c30_q_x = c30_p_x;
  c30_m_y = c30_l_y;
  c30_r_x = c30_q_x;
  c30_n_y = c30_m_y;
  c30_o_y = c30_r_x / c30_n_y;
  c30_b_s_x4.rl = c30_o_y;
  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 9);
  c30_g_A = c30_abs(chartInstance, c30_Rw * c30_b_w_4.rr + c30_b_v_xw4.rr);
  c30_s_x = c30_g_A;
  c30_t_x = c30_s_x;
  c30_u_x = c30_t_x;
  c30_p_y = c30_u_x / 2.0;
  c30_h_A = c30_Rw * c30_b_w_4.rr - c30_b_v_xw4.rr;
  c30_d_B = c30_p_y;
  c30_v_x = c30_h_A;
  c30_q_y = c30_d_B;
  c30_w_x = c30_v_x;
  c30_r_y = c30_q_y;
  c30_x_x = c30_w_x;
  c30_s_y = c30_r_y;
  c30_t_y = c30_x_x / c30_s_y;
  c30_b_s_x4.rr = c30_t_y;
  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 11);
  c30_y_x = c30_Rw * c30_b_w_4.fl + c30_b_v_xw4.fl;
  c30_ab_x = c30_y_x;
  c30_u_y = muDoubleScalarAbs(c30_ab_x);
  c30_i_A = c30_u_y;
  c30_bb_x = c30_i_A;
  c30_cb_x = c30_bb_x;
  c30_db_x = c30_cb_x;
  c30_v_y = c30_db_x / 2.0;
  c30_j_A = c30_b_v_yw4.fl;
  c30_e_B = c30_v_y;
  c30_eb_x = c30_j_A;
  c30_w_y = c30_e_B;
  c30_fb_x = c30_eb_x;
  c30_x_y = c30_w_y;
  c30_gb_x = c30_fb_x;
  c30_y_y = c30_x_y;
  c30_ab_y = c30_gb_x / c30_y_y;
  c30_b_s_y4.fl = c30_ab_y;
  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 12);
  c30_hb_x = c30_Rw * c30_b_w_4.fr + c30_b_v_xw4.fr;
  c30_ib_x = c30_hb_x;
  c30_bb_y = muDoubleScalarAbs(c30_ib_x);
  c30_k_A = c30_bb_y;
  c30_jb_x = c30_k_A;
  c30_kb_x = c30_jb_x;
  c30_lb_x = c30_kb_x;
  c30_cb_y = c30_lb_x / 2.0;
  c30_l_A = c30_b_v_yw4.fr;
  c30_f_B = c30_cb_y;
  c30_mb_x = c30_l_A;
  c30_db_y = c30_f_B;
  c30_nb_x = c30_mb_x;
  c30_eb_y = c30_db_y;
  c30_ob_x = c30_nb_x;
  c30_fb_y = c30_eb_y;
  c30_gb_y = c30_ob_x / c30_fb_y;
  c30_b_s_y4.fr = c30_gb_y;
  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 13);
  c30_pb_x = c30_Rw * c30_b_w_4.rl + c30_b_v_xw4.rl;
  c30_qb_x = c30_pb_x;
  c30_hb_y = muDoubleScalarAbs(c30_qb_x);
  c30_m_A = c30_hb_y;
  c30_rb_x = c30_m_A;
  c30_sb_x = c30_rb_x;
  c30_tb_x = c30_sb_x;
  c30_ib_y = c30_tb_x / 2.0;
  c30_n_A = c30_b_v_yw4.rl;
  c30_g_B = c30_ib_y;
  c30_ub_x = c30_n_A;
  c30_jb_y = c30_g_B;
  c30_vb_x = c30_ub_x;
  c30_kb_y = c30_jb_y;
  c30_wb_x = c30_vb_x;
  c30_lb_y = c30_kb_y;
  c30_mb_y = c30_wb_x / c30_lb_y;
  c30_b_s_y4.rl = c30_mb_y;
  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 14);
  c30_xb_x = c30_Rw * c30_b_w_4.rr + c30_b_v_xw4.rr;
  c30_yb_x = c30_xb_x;
  c30_nb_y = muDoubleScalarAbs(c30_yb_x);
  c30_o_A = c30_nb_y;
  c30_ac_x = c30_o_A;
  c30_bc_x = c30_ac_x;
  c30_cc_x = c30_bc_x;
  c30_ob_y = c30_cc_x / 2.0;
  c30_p_A = c30_b_v_yw4.rr;
  c30_h_B = c30_ob_y;
  c30_dc_x = c30_p_A;
  c30_pb_y = c30_h_B;
  c30_ec_x = c30_dc_x;
  c30_qb_y = c30_pb_y;
  c30_fc_x = c30_ec_x;
  c30_rb_y = c30_qb_y;
  c30_sb_y = c30_fc_x / c30_rb_y;
  c30_b_s_y4.rr = c30_sb_y;
  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 16);
  c30_gc_x = c30_mpower(chartInstance, c30_b_s_x4.fl) + c30_mpower(chartInstance,
    c30_b_s_y4.fl);
  c30_hc_x = c30_gc_x;
  if (c30_hc_x < 0.0) {
    c30_eml_error(chartInstance);
  }

  c30_hc_x = muDoubleScalarSqrt(c30_hc_x);
  c30_b_s_xy4.fl = c30_hc_x;
  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 17);
  c30_ic_x = c30_mpower(chartInstance, c30_b_s_x4.fr) + c30_mpower(chartInstance,
    c30_b_s_y4.fr);
  c30_jc_x = c30_ic_x;
  if (c30_jc_x < 0.0) {
    c30_eml_error(chartInstance);
  }

  c30_jc_x = muDoubleScalarSqrt(c30_jc_x);
  c30_b_s_xy4.fr = c30_jc_x;
  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 18);
  c30_kc_x = c30_mpower(chartInstance, c30_b_s_x4.rl) + c30_mpower(chartInstance,
    c30_b_s_y4.rl);
  c30_lc_x = c30_kc_x;
  if (c30_lc_x < 0.0) {
    c30_eml_error(chartInstance);
  }

  c30_lc_x = muDoubleScalarSqrt(c30_lc_x);
  c30_b_s_xy4.rl = c30_lc_x;
  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 19);
  c30_mc_x = c30_mpower(chartInstance, c30_b_s_x4.rr) + c30_mpower(chartInstance,
    c30_b_s_y4.rr);
  c30_nc_x = c30_mc_x;
  if (c30_nc_x < 0.0) {
    c30_eml_error(chartInstance);
  }

  c30_nc_x = muDoubleScalarSqrt(c30_nc_x);
  c30_b_s_xy4.rr = c30_nc_x;
  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, -19);
  _SFD_SYMBOL_SCOPE_POP();
  *(real_T *)&((char_T *)chartInstance->c30_s_x4)[0] = c30_b_s_x4.fl;
  *(real_T *)&((char_T *)chartInstance->c30_s_x4)[8] = c30_b_s_x4.fr;
  *(real_T *)&((char_T *)chartInstance->c30_s_x4)[16] = c30_b_s_x4.rl;
  *(real_T *)&((char_T *)chartInstance->c30_s_x4)[24] = c30_b_s_x4.rr;
  *(real_T *)&((char_T *)chartInstance->c30_s_y4)[0] = c30_b_s_y4.fl;
  *(real_T *)&((char_T *)chartInstance->c30_s_y4)[8] = c30_b_s_y4.fr;
  *(real_T *)&((char_T *)chartInstance->c30_s_y4)[16] = c30_b_s_y4.rl;
  *(real_T *)&((char_T *)chartInstance->c30_s_y4)[24] = c30_b_s_y4.rr;
  *(real_T *)&((char_T *)chartInstance->c30_s_xy4)[0] = c30_b_s_xy4.fl;
  *(real_T *)&((char_T *)chartInstance->c30_s_xy4)[8] = c30_b_s_xy4.fr;
  *(real_T *)&((char_T *)chartInstance->c30_s_xy4)[16] = c30_b_s_xy4.rl;
  *(real_T *)&((char_T *)chartInstance->c30_s_xy4)[24] = c30_b_s_xy4.rr;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 29U, chartInstance->c30_sfEvent);
}

static void initSimStructsc30_Modified(SFc30_ModifiedInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c30_machineNumber, uint32_T
  c30_chartNumber, uint32_T c30_instanceNumber)
{
  (void)c30_machineNumber;
  (void)c30_chartNumber;
  (void)c30_instanceNumber;
}

static const mxArray *c30_sf_marshallOut(void *chartInstanceVoid, void
  *c30_inData)
{
  const mxArray *c30_mxArrayOutData = NULL;
  c30_whl_vec4 c30_u;
  const mxArray *c30_y = NULL;
  real_T c30_b_u;
  const mxArray *c30_b_y = NULL;
  real_T c30_c_u;
  const mxArray *c30_c_y = NULL;
  real_T c30_d_u;
  const mxArray *c30_d_y = NULL;
  real_T c30_e_u;
  const mxArray *c30_e_y = NULL;
  SFc30_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc30_ModifiedInstanceStruct *)chartInstanceVoid;
  c30_mxArrayOutData = NULL;
  c30_u = *(c30_whl_vec4 *)c30_inData;
  c30_y = NULL;
  sf_mex_assign(&c30_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c30_b_u = c30_u.fl;
  c30_b_y = NULL;
  sf_mex_assign(&c30_b_y, sf_mex_create("y", &c30_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c30_y, c30_b_y, "fl", "fl", 0);
  c30_c_u = c30_u.fr;
  c30_c_y = NULL;
  sf_mex_assign(&c30_c_y, sf_mex_create("y", &c30_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c30_y, c30_c_y, "fr", "fr", 0);
  c30_d_u = c30_u.rl;
  c30_d_y = NULL;
  sf_mex_assign(&c30_d_y, sf_mex_create("y", &c30_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c30_y, c30_d_y, "rl", "rl", 0);
  c30_e_u = c30_u.rr;
  c30_e_y = NULL;
  sf_mex_assign(&c30_e_y, sf_mex_create("y", &c30_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c30_y, c30_e_y, "rr", "rr", 0);
  sf_mex_assign(&c30_mxArrayOutData, c30_y, false);
  return c30_mxArrayOutData;
}

static c30_whl_vec4 c30_emlrt_marshallIn(SFc30_ModifiedInstanceStruct
  *chartInstance, const mxArray *c30_b_s_xy4, const char_T *c30_identifier)
{
  c30_whl_vec4 c30_y;
  emlrtMsgIdentifier c30_thisId;
  c30_thisId.fIdentifier = c30_identifier;
  c30_thisId.fParent = NULL;
  c30_y = c30_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c30_b_s_xy4),
    &c30_thisId);
  sf_mex_destroy(&c30_b_s_xy4);
  return c30_y;
}

static c30_whl_vec4 c30_b_emlrt_marshallIn(SFc30_ModifiedInstanceStruct
  *chartInstance, const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId)
{
  c30_whl_vec4 c30_y;
  emlrtMsgIdentifier c30_thisId;
  static const char * c30_fieldNames[4] = { "fl", "fr", "rl", "rr" };

  c30_thisId.fParent = c30_parentId;
  sf_mex_check_struct(c30_parentId, c30_u, 4, c30_fieldNames, 0U, NULL);
  c30_thisId.fIdentifier = "fl";
  c30_y.fl = c30_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c30_u, "fl", "fl", 0)), &c30_thisId);
  c30_thisId.fIdentifier = "fr";
  c30_y.fr = c30_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c30_u, "fr", "fr", 0)), &c30_thisId);
  c30_thisId.fIdentifier = "rl";
  c30_y.rl = c30_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c30_u, "rl", "rl", 0)), &c30_thisId);
  c30_thisId.fIdentifier = "rr";
  c30_y.rr = c30_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c30_u, "rr", "rr", 0)), &c30_thisId);
  sf_mex_destroy(&c30_u);
  return c30_y;
}

static real_T c30_c_emlrt_marshallIn(SFc30_ModifiedInstanceStruct *chartInstance,
  const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId)
{
  real_T c30_y;
  real_T c30_d0;
  (void)chartInstance;
  sf_mex_import(c30_parentId, sf_mex_dup(c30_u), &c30_d0, 1, 0, 0U, 0, 0U, 0);
  c30_y = c30_d0;
  sf_mex_destroy(&c30_u);
  return c30_y;
}

static void c30_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c30_mxArrayInData, const char_T *c30_varName, void *c30_outData)
{
  const mxArray *c30_b_s_xy4;
  const char_T *c30_identifier;
  emlrtMsgIdentifier c30_thisId;
  c30_whl_vec4 c30_y;
  SFc30_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc30_ModifiedInstanceStruct *)chartInstanceVoid;
  c30_b_s_xy4 = sf_mex_dup(c30_mxArrayInData);
  c30_identifier = c30_varName;
  c30_thisId.fIdentifier = c30_identifier;
  c30_thisId.fParent = NULL;
  c30_y = c30_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c30_b_s_xy4),
    &c30_thisId);
  sf_mex_destroy(&c30_b_s_xy4);
  *(c30_whl_vec4 *)c30_outData = c30_y;
  sf_mex_destroy(&c30_mxArrayInData);
}

static const mxArray *c30_b_sf_marshallOut(void *chartInstanceVoid, void
  *c30_inData)
{
  const mxArray *c30_mxArrayOutData;
  c30_struct_iBlsPBO3AGnt69vDoTx5zD c30_u;
  const mxArray *c30_y = NULL;
  c30_struct_Nst2vGTExxHsg85EUOj9EH c30_b_u;
  const mxArray *c30_b_y = NULL;
  real_T c30_c_u;
  const mxArray *c30_c_y = NULL;
  c30_struct_HhckT6rntEraqECYVIDvCC c30_d_u;
  const mxArray *c30_d_y = NULL;
  real_T c30_e_u;
  const mxArray *c30_e_y = NULL;
  real_T c30_f_u;
  const mxArray *c30_f_y = NULL;
  const mxArray *c30_g_y = NULL;
  real_T c30_g_u;
  const mxArray *c30_h_y = NULL;
  real_T c30_h_u;
  const mxArray *c30_i_y = NULL;
  const mxArray *c30_j_y = NULL;
  real_T c30_i_u;
  const mxArray *c30_k_y = NULL;
  real_T c30_j_u;
  const mxArray *c30_l_y = NULL;
  const mxArray *c30_m_y = NULL;
  real_T c30_k_u;
  const mxArray *c30_n_y = NULL;
  real_T c30_l_u;
  const mxArray *c30_o_y = NULL;
  const mxArray *c30_p_y = NULL;
  real_T c30_m_u;
  const mxArray *c30_q_y = NULL;
  real_T c30_n_u;
  const mxArray *c30_r_y = NULL;
  real_T c30_o_u;
  const mxArray *c30_s_y = NULL;
  c30_struct_ZCmOWPuqBDw16FSOVVD00 c30_p_u;
  const mxArray *c30_t_y = NULL;
  real_T c30_q_u;
  const mxArray *c30_u_y = NULL;
  real_T c30_r_u;
  const mxArray *c30_v_y = NULL;
  real_T c30_s_u;
  const mxArray *c30_w_y = NULL;
  real_T c30_t_u;
  const mxArray *c30_x_y = NULL;
  real_T c30_u_u;
  const mxArray *c30_y_y = NULL;
  real_T c30_v_u;
  const mxArray *c30_ab_y = NULL;
  real_T c30_w_u;
  const mxArray *c30_bb_y = NULL;
  real_T c30_x_u;
  const mxArray *c30_cb_y = NULL;
  real_T c30_y_u;
  const mxArray *c30_db_y = NULL;
  real_T c30_ab_u;
  const mxArray *c30_eb_y = NULL;
  real_T c30_bb_u;
  const mxArray *c30_fb_y = NULL;
  int32_T c30_i0;
  real_T c30_cb_u[4];
  const mxArray *c30_gb_y = NULL;
  real_T c30_db_u;
  const mxArray *c30_hb_y = NULL;
  c30_struct_ZKAzdrl7umDGJoC14aoVKC c30_eb_u;
  const mxArray *c30_ib_y = NULL;
  int32_T c30_i1;
  real_T c30_fb_u[3];
  const mxArray *c30_jb_y = NULL;
  int32_T c30_i2;
  real_T c30_gb_u[3];
  const mxArray *c30_kb_y = NULL;
  int32_T c30_i3;
  real_T c30_hb_u[3];
  const mxArray *c30_lb_y = NULL;
  int32_T c30_i4;
  real_T c30_ib_u[3];
  const mxArray *c30_mb_y = NULL;
  const mxArray *c30_nb_y = NULL;
  int32_T c30_i5;
  real_T c30_jb_u[3];
  const mxArray *c30_ob_y = NULL;
  int32_T c30_i6;
  real_T c30_kb_u[3];
  const mxArray *c30_pb_y = NULL;
  int32_T c30_i7;
  real_T c30_lb_u[3];
  const mxArray *c30_qb_y = NULL;
  int32_T c30_i8;
  real_T c30_mb_u[3];
  const mxArray *c30_rb_y = NULL;
  const mxArray *c30_sb_y = NULL;
  int32_T c30_i9;
  real_T c30_nb_u[3];
  const mxArray *c30_tb_y = NULL;
  int32_T c30_i10;
  real_T c30_ob_u[3];
  const mxArray *c30_ub_y = NULL;
  int32_T c30_i11;
  real_T c30_pb_u[3];
  const mxArray *c30_vb_y = NULL;
  int32_T c30_i12;
  real_T c30_qb_u[3];
  const mxArray *c30_wb_y = NULL;
  const mxArray *c30_xb_y = NULL;
  int32_T c30_i13;
  real_T c30_rb_u[3];
  const mxArray *c30_yb_y = NULL;
  int32_T c30_i14;
  real_T c30_sb_u[3];
  const mxArray *c30_ac_y = NULL;
  int32_T c30_i15;
  real_T c30_tb_u[3];
  const mxArray *c30_bc_y = NULL;
  int32_T c30_i16;
  real_T c30_ub_u[3];
  const mxArray *c30_cc_y = NULL;
  real_T c30_vb_u;
  const mxArray *c30_dc_y = NULL;
  real_T c30_wb_u;
  const mxArray *c30_ec_y = NULL;
  real_T c30_xb_u;
  const mxArray *c30_fc_y = NULL;
  real_T c30_yb_u;
  const mxArray *c30_gc_y = NULL;
  real_T c30_ac_u;
  const mxArray *c30_hc_y = NULL;
  real_T c30_bc_u;
  const mxArray *c30_ic_y = NULL;
  real_T c30_cc_u;
  const mxArray *c30_jc_y = NULL;
  real_T c30_dc_u;
  const mxArray *c30_kc_y = NULL;
  real_T c30_ec_u;
  const mxArray *c30_lc_y = NULL;
  real_T c30_fc_u;
  const mxArray *c30_mc_y = NULL;
  real_T c30_gc_u;
  const mxArray *c30_nc_y = NULL;
  real_T c30_hc_u;
  const mxArray *c30_oc_y = NULL;
  c30_struct_r4FNviKwHfdhB8nQjvQv9 c30_ic_u;
  const mxArray *c30_pc_y = NULL;
  real_T c30_jc_u;
  const mxArray *c30_qc_y = NULL;
  c30_struct_Y9F1qlBi9AhssksPwemA4G c30_kc_u;
  const mxArray *c30_rc_y = NULL;
  real_T c30_lc_u;
  const mxArray *c30_sc_y = NULL;
  real_T c30_mc_u;
  const mxArray *c30_tc_y = NULL;
  real_T c30_nc_u;
  const mxArray *c30_uc_y = NULL;
  SFc30_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc30_ModifiedInstanceStruct *)chartInstanceVoid;
  c30_mxArrayOutData = NULL;
  c30_mxArrayOutData = NULL;
  c30_u = *(c30_struct_iBlsPBO3AGnt69vDoTx5zD *)c30_inData;
  c30_y = NULL;
  sf_mex_assign(&c30_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c30_b_u = c30_u.Env;
  c30_b_y = NULL;
  sf_mex_assign(&c30_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c30_c_u = c30_b_u.g;
  c30_c_y = NULL;
  sf_mex_assign(&c30_c_y, sf_mex_create("y", &c30_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c30_b_y, c30_c_y, "g", "g", 0);
  c30_d_u = c30_b_u.left1;
  c30_d_y = NULL;
  sf_mex_assign(&c30_d_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c30_e_u = c30_d_u.x;
  c30_e_y = NULL;
  sf_mex_assign(&c30_e_y, sf_mex_create("y", &c30_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c30_d_y, c30_e_y, "x", "x", 0);
  c30_f_u = c30_d_u.y;
  c30_f_y = NULL;
  sf_mex_assign(&c30_f_y, sf_mex_create("y", &c30_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c30_d_y, c30_f_y, "y", "y", 0);
  sf_mex_addfield(c30_b_y, c30_d_y, "left1", "left1", 0);
  c30_d_u = c30_b_u.right1;
  c30_g_y = NULL;
  sf_mex_assign(&c30_g_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c30_g_u = c30_d_u.x;
  c30_h_y = NULL;
  sf_mex_assign(&c30_h_y, sf_mex_create("y", &c30_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c30_g_y, c30_h_y, "x", "x", 0);
  c30_h_u = c30_d_u.y;
  c30_i_y = NULL;
  sf_mex_assign(&c30_i_y, sf_mex_create("y", &c30_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c30_g_y, c30_i_y, "y", "y", 0);
  sf_mex_addfield(c30_b_y, c30_g_y, "right1", "right1", 0);
  c30_d_u = c30_b_u.right2;
  c30_j_y = NULL;
  sf_mex_assign(&c30_j_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c30_i_u = c30_d_u.x;
  c30_k_y = NULL;
  sf_mex_assign(&c30_k_y, sf_mex_create("y", &c30_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c30_j_y, c30_k_y, "x", "x", 0);
  c30_j_u = c30_d_u.y;
  c30_l_y = NULL;
  sf_mex_assign(&c30_l_y, sf_mex_create("y", &c30_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c30_j_y, c30_l_y, "y", "y", 0);
  sf_mex_addfield(c30_b_y, c30_j_y, "right2", "right2", 0);
  c30_d_u = c30_b_u.left2;
  c30_m_y = NULL;
  sf_mex_assign(&c30_m_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c30_k_u = c30_d_u.x;
  c30_n_y = NULL;
  sf_mex_assign(&c30_n_y, sf_mex_create("y", &c30_k_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c30_m_y, c30_n_y, "x", "x", 0);
  c30_l_u = c30_d_u.y;
  c30_o_y = NULL;
  sf_mex_assign(&c30_o_y, sf_mex_create("y", &c30_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c30_m_y, c30_o_y, "y", "y", 0);
  sf_mex_addfield(c30_b_y, c30_m_y, "left2", "left2", 0);
  c30_d_u = c30_b_u.right3;
  c30_p_y = NULL;
  sf_mex_assign(&c30_p_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c30_m_u = c30_d_u.x;
  c30_q_y = NULL;
  sf_mex_assign(&c30_q_y, sf_mex_create("y", &c30_m_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c30_p_y, c30_q_y, "x", "x", 0);
  c30_n_u = c30_d_u.y;
  c30_r_y = NULL;
  sf_mex_assign(&c30_r_y, sf_mex_create("y", &c30_n_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c30_p_y, c30_r_y, "y", "y", 0);
  sf_mex_addfield(c30_b_y, c30_p_y, "right3", "right3", 0);
  c30_o_u = c30_b_u.mu;
  c30_s_y = NULL;
  sf_mex_assign(&c30_s_y, sf_mex_create("y", &c30_o_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c30_b_y, c30_s_y, "mu", "mu", 0);
  sf_mex_addfield(c30_y, c30_b_y, "Env", "Env", 0);
  c30_p_u = c30_u.Veh;
  c30_t_y = NULL;
  sf_mex_assign(&c30_t_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c30_q_u = c30_p_u.m;
  c30_u_y = NULL;
  sf_mex_assign(&c30_u_y, sf_mex_create("y", &c30_q_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c30_t_y, c30_u_y, "m", "m", 0);
  c30_r_u = c30_p_u.Jz;
  c30_v_y = NULL;
  sf_mex_assign(&c30_v_y, sf_mex_create("y", &c30_r_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c30_t_y, c30_v_y, "Jz", "Jz", 0);
  c30_s_u = c30_p_u.m_sprung;
  c30_w_y = NULL;
  sf_mex_assign(&c30_w_y, sf_mex_create("y", &c30_s_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c30_t_y, c30_w_y, "m_sprung", "m_sprung", 0);
  c30_t_u = c30_p_u.Jx_sprung;
  c30_x_y = NULL;
  sf_mex_assign(&c30_x_y, sf_mex_create("y", &c30_t_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c30_t_y, c30_x_y, "Jx_sprung", "Jx_sprung", 0);
  c30_u_u = c30_p_u.Jy_sprung;
  c30_y_y = NULL;
  sf_mex_assign(&c30_y_y, sf_mex_create("y", &c30_u_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c30_t_y, c30_y_y, "Jy_sprung", "Jy_sprung", 0);
  c30_v_u = c30_p_u.lf;
  c30_ab_y = NULL;
  sf_mex_assign(&c30_ab_y, sf_mex_create("y", &c30_v_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c30_t_y, c30_ab_y, "lf", "lf", 0);
  c30_w_u = c30_p_u.lr;
  c30_bb_y = NULL;
  sf_mex_assign(&c30_bb_y, sf_mex_create("y", &c30_w_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c30_t_y, c30_bb_y, "lr", "lr", 0);
  c30_x_u = c30_p_u.L;
  c30_cb_y = NULL;
  sf_mex_assign(&c30_cb_y, sf_mex_create("y", &c30_x_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c30_t_y, c30_cb_y, "L", "L", 0);
  c30_y_u = c30_p_u.TrackWidth;
  c30_db_y = NULL;
  sf_mex_assign(&c30_db_y, sf_mex_create("y", &c30_y_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c30_t_y, c30_db_y, "TrackWidth", "TrackWidth", 0);
  c30_ab_u = c30_p_u.h;
  c30_eb_y = NULL;
  sf_mex_assign(&c30_eb_y, sf_mex_create("y", &c30_ab_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c30_t_y, c30_eb_y, "h", "h", 0);
  c30_bb_u = c30_p_u.HalfRohACd;
  c30_fb_y = NULL;
  sf_mex_assign(&c30_fb_y, sf_mex_create("y", &c30_bb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c30_t_y, c30_fb_y, "HalfRohACd", "HalfRohACd", 0);
  for (c30_i0 = 0; c30_i0 < 4; c30_i0++) {
    c30_cb_u[c30_i0] = c30_p_u.F_z4_static[c30_i0];
  }

  c30_gb_y = NULL;
  sf_mex_assign(&c30_gb_y, sf_mex_create("y", c30_cb_u, 0, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_addfield(c30_t_y, c30_gb_y, "F_z4_static", "F_z4_static", 0);
  c30_db_u = c30_p_u.Rw;
  c30_hb_y = NULL;
  sf_mex_assign(&c30_hb_y, sf_mex_create("y", &c30_db_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c30_t_y, c30_hb_y, "Rw", "Rw", 0);
  c30_eb_u = c30_p_u.r_long;
  c30_ib_y = NULL;
  sf_mex_assign(&c30_ib_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c30_i1 = 0; c30_i1 < 3; c30_i1++) {
    c30_fb_u[c30_i1] = c30_eb_u.fl[c30_i1];
  }

  c30_jb_y = NULL;
  sf_mex_assign(&c30_jb_y, sf_mex_create("y", c30_fb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c30_ib_y, c30_jb_y, "fl", "fl", 0);
  for (c30_i2 = 0; c30_i2 < 3; c30_i2++) {
    c30_gb_u[c30_i2] = c30_eb_u.fr[c30_i2];
  }

  c30_kb_y = NULL;
  sf_mex_assign(&c30_kb_y, sf_mex_create("y", c30_gb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c30_ib_y, c30_kb_y, "fr", "fr", 0);
  for (c30_i3 = 0; c30_i3 < 3; c30_i3++) {
    c30_hb_u[c30_i3] = c30_eb_u.rl[c30_i3];
  }

  c30_lb_y = NULL;
  sf_mex_assign(&c30_lb_y, sf_mex_create("y", c30_hb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c30_ib_y, c30_lb_y, "rl", "rl", 0);
  for (c30_i4 = 0; c30_i4 < 3; c30_i4++) {
    c30_ib_u[c30_i4] = c30_eb_u.rr[c30_i4];
  }

  c30_mb_y = NULL;
  sf_mex_assign(&c30_mb_y, sf_mex_create("y", c30_ib_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c30_ib_y, c30_mb_y, "rr", "rr", 0);
  sf_mex_addfield(c30_t_y, c30_ib_y, "r_long", "r_long", 0);
  c30_eb_u = c30_p_u.r_lat;
  c30_nb_y = NULL;
  sf_mex_assign(&c30_nb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c30_i5 = 0; c30_i5 < 3; c30_i5++) {
    c30_jb_u[c30_i5] = c30_eb_u.fl[c30_i5];
  }

  c30_ob_y = NULL;
  sf_mex_assign(&c30_ob_y, sf_mex_create("y", c30_jb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c30_nb_y, c30_ob_y, "fl", "fl", 0);
  for (c30_i6 = 0; c30_i6 < 3; c30_i6++) {
    c30_kb_u[c30_i6] = c30_eb_u.fr[c30_i6];
  }

  c30_pb_y = NULL;
  sf_mex_assign(&c30_pb_y, sf_mex_create("y", c30_kb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c30_nb_y, c30_pb_y, "fr", "fr", 0);
  for (c30_i7 = 0; c30_i7 < 3; c30_i7++) {
    c30_lb_u[c30_i7] = c30_eb_u.rl[c30_i7];
  }

  c30_qb_y = NULL;
  sf_mex_assign(&c30_qb_y, sf_mex_create("y", c30_lb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c30_nb_y, c30_qb_y, "rl", "rl", 0);
  for (c30_i8 = 0; c30_i8 < 3; c30_i8++) {
    c30_mb_u[c30_i8] = c30_eb_u.rr[c30_i8];
  }

  c30_rb_y = NULL;
  sf_mex_assign(&c30_rb_y, sf_mex_create("y", c30_mb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c30_nb_y, c30_rb_y, "rr", "rr", 0);
  sf_mex_addfield(c30_t_y, c30_nb_y, "r_lat", "r_lat", 0);
  c30_eb_u = c30_p_u.r_lever;
  c30_sb_y = NULL;
  sf_mex_assign(&c30_sb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c30_i9 = 0; c30_i9 < 3; c30_i9++) {
    c30_nb_u[c30_i9] = c30_eb_u.fl[c30_i9];
  }

  c30_tb_y = NULL;
  sf_mex_assign(&c30_tb_y, sf_mex_create("y", c30_nb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c30_sb_y, c30_tb_y, "fl", "fl", 0);
  for (c30_i10 = 0; c30_i10 < 3; c30_i10++) {
    c30_ob_u[c30_i10] = c30_eb_u.fr[c30_i10];
  }

  c30_ub_y = NULL;
  sf_mex_assign(&c30_ub_y, sf_mex_create("y", c30_ob_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c30_sb_y, c30_ub_y, "fr", "fr", 0);
  for (c30_i11 = 0; c30_i11 < 3; c30_i11++) {
    c30_pb_u[c30_i11] = c30_eb_u.rl[c30_i11];
  }

  c30_vb_y = NULL;
  sf_mex_assign(&c30_vb_y, sf_mex_create("y", c30_pb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c30_sb_y, c30_vb_y, "rl", "rl", 0);
  for (c30_i12 = 0; c30_i12 < 3; c30_i12++) {
    c30_qb_u[c30_i12] = c30_eb_u.rr[c30_i12];
  }

  c30_wb_y = NULL;
  sf_mex_assign(&c30_wb_y, sf_mex_create("y", c30_qb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c30_sb_y, c30_wb_y, "rr", "rr", 0);
  sf_mex_addfield(c30_t_y, c30_sb_y, "r_lever", "r_lever", 0);
  c30_eb_u = c30_p_u.r_pivot;
  c30_xb_y = NULL;
  sf_mex_assign(&c30_xb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c30_i13 = 0; c30_i13 < 3; c30_i13++) {
    c30_rb_u[c30_i13] = c30_eb_u.fl[c30_i13];
  }

  c30_yb_y = NULL;
  sf_mex_assign(&c30_yb_y, sf_mex_create("y", c30_rb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c30_xb_y, c30_yb_y, "fl", "fl", 0);
  for (c30_i14 = 0; c30_i14 < 3; c30_i14++) {
    c30_sb_u[c30_i14] = c30_eb_u.fr[c30_i14];
  }

  c30_ac_y = NULL;
  sf_mex_assign(&c30_ac_y, sf_mex_create("y", c30_sb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c30_xb_y, c30_ac_y, "fr", "fr", 0);
  for (c30_i15 = 0; c30_i15 < 3; c30_i15++) {
    c30_tb_u[c30_i15] = c30_eb_u.rl[c30_i15];
  }

  c30_bc_y = NULL;
  sf_mex_assign(&c30_bc_y, sf_mex_create("y", c30_tb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c30_xb_y, c30_bc_y, "rl", "rl", 0);
  for (c30_i16 = 0; c30_i16 < 3; c30_i16++) {
    c30_ub_u[c30_i16] = c30_eb_u.rr[c30_i16];
  }

  c30_cc_y = NULL;
  sf_mex_assign(&c30_cc_y, sf_mex_create("y", c30_ub_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c30_xb_y, c30_cc_y, "rr", "rr", 0);
  sf_mex_addfield(c30_t_y, c30_xb_y, "r_pivot", "r_pivot", 0);
  c30_vb_u = c30_p_u.cw;
  c30_dc_y = NULL;
  sf_mex_assign(&c30_dc_y, sf_mex_create("y", &c30_vb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c30_t_y, c30_dc_y, "cw", "cw", 0);
  c30_wb_u = c30_p_u.carb_f;
  c30_ec_y = NULL;
  sf_mex_assign(&c30_ec_y, sf_mex_create("y", &c30_wb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c30_t_y, c30_ec_y, "carb_f", "carb_f", 0);
  c30_xb_u = c30_p_u.carb_r;
  c30_fc_y = NULL;
  sf_mex_assign(&c30_fc_y, sf_mex_create("y", &c30_xb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c30_t_y, c30_fc_y, "carb_r", "carb_r", 0);
  c30_yb_u = c30_p_u.dw;
  c30_gc_y = NULL;
  sf_mex_assign(&c30_gc_y, sf_mex_create("y", &c30_yb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c30_t_y, c30_gc_y, "dw", "dw", 0);
  c30_ac_u = c30_p_u.Jw;
  c30_hc_y = NULL;
  sf_mex_assign(&c30_hc_y, sf_mex_create("y", &c30_ac_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c30_t_y, c30_hc_y, "Jw", "Jw", 0);
  c30_bc_u = c30_p_u.C0;
  c30_ic_y = NULL;
  sf_mex_assign(&c30_ic_y, sf_mex_create("y", &c30_bc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c30_t_y, c30_ic_y, "C0", "C0", 0);
  c30_cc_u = c30_p_u.RelaxLength;
  c30_jc_y = NULL;
  sf_mex_assign(&c30_jc_y, sf_mex_create("y", &c30_cc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c30_t_y, c30_jc_y, "RelaxLength", "RelaxLength", 0);
  c30_dc_u = c30_p_u.RRC;
  c30_kc_y = NULL;
  sf_mex_assign(&c30_kc_y, sf_mex_create("y", &c30_dc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c30_t_y, c30_kc_y, "RRC", "RRC", 0);
  c30_ec_u = c30_p_u.Pmax;
  c30_lc_y = NULL;
  sf_mex_assign(&c30_lc_y, sf_mex_create("y", &c30_ec_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c30_t_y, c30_lc_y, "Pmax", "Pmax", 0);
  c30_fc_u = c30_p_u.PropDistrFrnt;
  c30_mc_y = NULL;
  sf_mex_assign(&c30_mc_y, sf_mex_create("y", &c30_fc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c30_t_y, c30_mc_y, "PropDistrFrnt", "PropDistrFrnt", 0);
  c30_gc_u = c30_p_u.BrkDistrFrnt;
  c30_nc_y = NULL;
  sf_mex_assign(&c30_nc_y, sf_mex_create("y", &c30_gc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c30_t_y, c30_nc_y, "BrkDistrFrnt", "BrkDistrFrnt", 0);
  c30_hc_u = c30_p_u.SteRatio;
  c30_oc_y = NULL;
  sf_mex_assign(&c30_oc_y, sf_mex_create("y", &c30_hc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c30_t_y, c30_oc_y, "SteRatio", "SteRatio", 0);
  sf_mex_addfield(c30_y, c30_t_y, "Veh", "Veh", 0);
  c30_ic_u = c30_u.Drvr;
  c30_pc_y = NULL;
  sf_mex_assign(&c30_pc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c30_jc_u = c30_ic_u.v_set;
  c30_qc_y = NULL;
  sf_mex_assign(&c30_qc_y, sf_mex_create("y", &c30_jc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c30_pc_y, c30_qc_y, "v_set", "v_set", 0);
  sf_mex_addfield(c30_y, c30_pc_y, "Drvr", "Drvr", 0);
  c30_kc_u = c30_u.Init;
  c30_rc_y = NULL;
  sf_mex_assign(&c30_rc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c30_lc_u = c30_kc_u.v_x;
  c30_sc_y = NULL;
  sf_mex_assign(&c30_sc_y, sf_mex_create("y", &c30_lc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c30_rc_y, c30_sc_y, "v_x", "v_x", 0);
  c30_mc_u = c30_kc_u.F_fz;
  c30_tc_y = NULL;
  sf_mex_assign(&c30_tc_y, sf_mex_create("y", &c30_mc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c30_rc_y, c30_tc_y, "F_fz", "F_fz", 0);
  c30_nc_u = c30_kc_u.F_rz;
  c30_uc_y = NULL;
  sf_mex_assign(&c30_uc_y, sf_mex_create("y", &c30_nc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c30_rc_y, c30_uc_y, "F_rz", "F_rz", 0);
  sf_mex_addfield(c30_y, c30_rc_y, "Init", "Init", 0);
  sf_mex_assign(&c30_mxArrayOutData, c30_y, false);
  return c30_mxArrayOutData;
}

static void c30_d_emlrt_marshallIn(SFc30_ModifiedInstanceStruct *chartInstance,
  const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId,
  c30_struct_iBlsPBO3AGnt69vDoTx5zD *c30_y)
{
  emlrtMsgIdentifier c30_thisId;
  static const char * c30_fieldNames[4] = { "Env", "Veh", "Drvr", "Init" };

  c30_thisId.fParent = c30_parentId;
  sf_mex_check_struct(c30_parentId, c30_u, 4, c30_fieldNames, 0U, NULL);
  c30_thisId.fIdentifier = "Env";
  c30_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c30_u, "Env",
    "Env", 0)), &c30_thisId, &c30_y->Env);
  c30_thisId.fIdentifier = "Veh";
  c30_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c30_u, "Veh",
    "Veh", 0)), &c30_thisId, &c30_y->Veh);
  c30_thisId.fIdentifier = "Drvr";
  c30_y->Drvr = c30_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c30_u, "Drvr", "Drvr", 0)), &c30_thisId);
  c30_thisId.fIdentifier = "Init";
  c30_y->Init = c30_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c30_u, "Init", "Init", 0)), &c30_thisId);
  sf_mex_destroy(&c30_u);
}

static void c30_e_emlrt_marshallIn(SFc30_ModifiedInstanceStruct *chartInstance,
  const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId,
  c30_struct_Nst2vGTExxHsg85EUOj9EH *c30_y)
{
  emlrtMsgIdentifier c30_thisId;
  static const char * c30_fieldNames[7] = { "g", "left1", "right1", "right2",
    "left2", "right3", "mu" };

  c30_thisId.fParent = c30_parentId;
  sf_mex_check_struct(c30_parentId, c30_u, 7, c30_fieldNames, 0U, NULL);
  c30_thisId.fIdentifier = "g";
  c30_y->g = c30_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c30_u, "g", "g", 0)), &c30_thisId);
  c30_thisId.fIdentifier = "left1";
  c30_y->left1 = c30_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c30_u, "left1", "left1", 0)), &c30_thisId);
  c30_thisId.fIdentifier = "right1";
  c30_y->right1 = c30_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c30_u, "right1", "right1", 0)), &c30_thisId);
  c30_thisId.fIdentifier = "right2";
  c30_y->right2 = c30_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c30_u, "right2", "right2", 0)), &c30_thisId);
  c30_thisId.fIdentifier = "left2";
  c30_y->left2 = c30_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c30_u, "left2", "left2", 0)), &c30_thisId);
  c30_thisId.fIdentifier = "right3";
  c30_y->right3 = c30_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c30_u, "right3", "right3", 0)), &c30_thisId);
  c30_thisId.fIdentifier = "mu";
  c30_y->mu = c30_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c30_u, "mu", "mu", 0)), &c30_thisId);
  sf_mex_destroy(&c30_u);
}

static c30_struct_HhckT6rntEraqECYVIDvCC c30_f_emlrt_marshallIn
  (SFc30_ModifiedInstanceStruct *chartInstance, const mxArray *c30_u, const
   emlrtMsgIdentifier *c30_parentId)
{
  c30_struct_HhckT6rntEraqECYVIDvCC c30_y;
  emlrtMsgIdentifier c30_thisId;
  static const char * c30_fieldNames[2] = { "x", "y" };

  c30_thisId.fParent = c30_parentId;
  sf_mex_check_struct(c30_parentId, c30_u, 2, c30_fieldNames, 0U, NULL);
  c30_thisId.fIdentifier = "x";
  c30_y.x = c30_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c30_u, "x", "x", 0)), &c30_thisId);
  c30_thisId.fIdentifier = "y";
  c30_y.y = c30_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c30_u, "y", "y", 0)), &c30_thisId);
  sf_mex_destroy(&c30_u);
  return c30_y;
}

static void c30_g_emlrt_marshallIn(SFc30_ModifiedInstanceStruct *chartInstance,
  const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId,
  c30_struct_ZCmOWPuqBDw16FSOVVD00 *c30_y)
{
  emlrtMsgIdentifier c30_thisId;
  static const char * c30_fieldNames[29] = { "m", "Jz", "m_sprung", "Jx_sprung",
    "Jy_sprung", "lf", "lr", "L", "TrackWidth", "h", "HalfRohACd", "F_z4_static",
    "Rw", "r_long", "r_lat", "r_lever", "r_pivot", "cw", "carb_f", "carb_r",
    "dw", "Jw", "C0", "RelaxLength", "RRC", "Pmax", "PropDistrFrnt",
    "BrkDistrFrnt", "SteRatio" };

  c30_thisId.fParent = c30_parentId;
  sf_mex_check_struct(c30_parentId, c30_u, 29, c30_fieldNames, 0U, NULL);
  c30_thisId.fIdentifier = "m";
  c30_y->m = c30_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c30_u, "m", "m", 0)), &c30_thisId);
  c30_thisId.fIdentifier = "Jz";
  c30_y->Jz = c30_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c30_u, "Jz", "Jz", 0)), &c30_thisId);
  c30_thisId.fIdentifier = "m_sprung";
  c30_y->m_sprung = c30_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c30_u, "m_sprung", "m_sprung", 0)), &c30_thisId);
  c30_thisId.fIdentifier = "Jx_sprung";
  c30_y->Jx_sprung = c30_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c30_u, "Jx_sprung", "Jx_sprung", 0)), &c30_thisId);
  c30_thisId.fIdentifier = "Jy_sprung";
  c30_y->Jy_sprung = c30_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c30_u, "Jy_sprung", "Jy_sprung", 0)), &c30_thisId);
  c30_thisId.fIdentifier = "lf";
  c30_y->lf = c30_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c30_u, "lf", "lf", 0)), &c30_thisId);
  c30_thisId.fIdentifier = "lr";
  c30_y->lr = c30_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c30_u, "lr", "lr", 0)), &c30_thisId);
  c30_thisId.fIdentifier = "L";
  c30_y->L = c30_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c30_u, "L", "L", 0)), &c30_thisId);
  c30_thisId.fIdentifier = "TrackWidth";
  c30_y->TrackWidth = c30_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c30_u, "TrackWidth", "TrackWidth", 0)), &c30_thisId);
  c30_thisId.fIdentifier = "h";
  c30_y->h = c30_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c30_u, "h", "h", 0)), &c30_thisId);
  c30_thisId.fIdentifier = "HalfRohACd";
  c30_y->HalfRohACd = c30_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c30_u, "HalfRohACd", "HalfRohACd", 0)), &c30_thisId);
  c30_thisId.fIdentifier = "F_z4_static";
  c30_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c30_u,
    "F_z4_static", "F_z4_static", 0)), &c30_thisId, c30_y->F_z4_static);
  c30_thisId.fIdentifier = "Rw";
  c30_y->Rw = c30_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c30_u, "Rw", "Rw", 0)), &c30_thisId);
  c30_thisId.fIdentifier = "r_long";
  c30_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c30_u,
    "r_long", "r_long", 0)), &c30_thisId, &c30_y->r_long);
  c30_thisId.fIdentifier = "r_lat";
  c30_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c30_u,
    "r_lat", "r_lat", 0)), &c30_thisId, &c30_y->r_lat);
  c30_thisId.fIdentifier = "r_lever";
  c30_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c30_u,
    "r_lever", "r_lever", 0)), &c30_thisId, &c30_y->r_lever);
  c30_thisId.fIdentifier = "r_pivot";
  c30_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c30_u,
    "r_pivot", "r_pivot", 0)), &c30_thisId, &c30_y->r_pivot);
  c30_thisId.fIdentifier = "cw";
  c30_y->cw = c30_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c30_u, "cw", "cw", 0)), &c30_thisId);
  c30_thisId.fIdentifier = "carb_f";
  c30_y->carb_f = c30_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c30_u, "carb_f", "carb_f", 0)), &c30_thisId);
  c30_thisId.fIdentifier = "carb_r";
  c30_y->carb_r = c30_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c30_u, "carb_r", "carb_r", 0)), &c30_thisId);
  c30_thisId.fIdentifier = "dw";
  c30_y->dw = c30_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c30_u, "dw", "dw", 0)), &c30_thisId);
  c30_thisId.fIdentifier = "Jw";
  c30_y->Jw = c30_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c30_u, "Jw", "Jw", 0)), &c30_thisId);
  c30_thisId.fIdentifier = "C0";
  c30_y->C0 = c30_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c30_u, "C0", "C0", 0)), &c30_thisId);
  c30_thisId.fIdentifier = "RelaxLength";
  c30_y->RelaxLength = c30_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c30_u, "RelaxLength", "RelaxLength", 0)), &c30_thisId);
  c30_thisId.fIdentifier = "RRC";
  c30_y->RRC = c30_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c30_u, "RRC", "RRC", 0)), &c30_thisId);
  c30_thisId.fIdentifier = "Pmax";
  c30_y->Pmax = c30_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c30_u, "Pmax", "Pmax", 0)), &c30_thisId);
  c30_thisId.fIdentifier = "PropDistrFrnt";
  c30_y->PropDistrFrnt = c30_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c30_u, "PropDistrFrnt", "PropDistrFrnt", 0)), &c30_thisId);
  c30_thisId.fIdentifier = "BrkDistrFrnt";
  c30_y->BrkDistrFrnt = c30_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c30_u, "BrkDistrFrnt", "BrkDistrFrnt", 0)), &c30_thisId);
  c30_thisId.fIdentifier = "SteRatio";
  c30_y->SteRatio = c30_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c30_u, "SteRatio", "SteRatio", 0)), &c30_thisId);
  sf_mex_destroy(&c30_u);
}

static void c30_h_emlrt_marshallIn(SFc30_ModifiedInstanceStruct *chartInstance,
  const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId, real_T c30_y[4])
{
  real_T c30_dv0[4];
  int32_T c30_i17;
  (void)chartInstance;
  sf_mex_import(c30_parentId, sf_mex_dup(c30_u), c30_dv0, 1, 0, 0U, 1, 0U, 2, 1,
                4);
  for (c30_i17 = 0; c30_i17 < 4; c30_i17++) {
    c30_y[c30_i17] = c30_dv0[c30_i17];
  }

  sf_mex_destroy(&c30_u);
}

static void c30_i_emlrt_marshallIn(SFc30_ModifiedInstanceStruct *chartInstance,
  const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId,
  c30_struct_ZKAzdrl7umDGJoC14aoVKC *c30_y)
{
  emlrtMsgIdentifier c30_thisId;
  static const char * c30_fieldNames[4] = { "fl", "fr", "rl", "rr" };

  c30_thisId.fParent = c30_parentId;
  sf_mex_check_struct(c30_parentId, c30_u, 4, c30_fieldNames, 0U, NULL);
  c30_thisId.fIdentifier = "fl";
  c30_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c30_u, "fl",
    "fl", 0)), &c30_thisId, c30_y->fl);
  c30_thisId.fIdentifier = "fr";
  c30_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c30_u, "fr",
    "fr", 0)), &c30_thisId, c30_y->fr);
  c30_thisId.fIdentifier = "rl";
  c30_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c30_u, "rl",
    "rl", 0)), &c30_thisId, c30_y->rl);
  c30_thisId.fIdentifier = "rr";
  c30_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c30_u, "rr",
    "rr", 0)), &c30_thisId, c30_y->rr);
  sf_mex_destroy(&c30_u);
}

static void c30_j_emlrt_marshallIn(SFc30_ModifiedInstanceStruct *chartInstance,
  const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId, real_T c30_y[3])
{
  real_T c30_dv1[3];
  int32_T c30_i18;
  (void)chartInstance;
  sf_mex_import(c30_parentId, sf_mex_dup(c30_u), c30_dv1, 1, 0, 0U, 1, 0U, 2, 3,
                1);
  for (c30_i18 = 0; c30_i18 < 3; c30_i18++) {
    c30_y[c30_i18] = c30_dv1[c30_i18];
  }

  sf_mex_destroy(&c30_u);
}

static c30_struct_r4FNviKwHfdhB8nQjvQv9 c30_k_emlrt_marshallIn
  (SFc30_ModifiedInstanceStruct *chartInstance, const mxArray *c30_u, const
   emlrtMsgIdentifier *c30_parentId)
{
  c30_struct_r4FNviKwHfdhB8nQjvQv9 c30_y;
  emlrtMsgIdentifier c30_thisId;
  static const char * c30_fieldNames[1] = { "v_set" };

  c30_thisId.fParent = c30_parentId;
  sf_mex_check_struct(c30_parentId, c30_u, 1, c30_fieldNames, 0U, NULL);
  c30_thisId.fIdentifier = "v_set";
  c30_y.v_set = c30_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c30_u, "v_set", "v_set", 0)),
    &c30_thisId);
  sf_mex_destroy(&c30_u);
  return c30_y;
}

static c30_struct_Y9F1qlBi9AhssksPwemA4G c30_l_emlrt_marshallIn
  (SFc30_ModifiedInstanceStruct *chartInstance, const mxArray *c30_u, const
   emlrtMsgIdentifier *c30_parentId)
{
  c30_struct_Y9F1qlBi9AhssksPwemA4G c30_y;
  emlrtMsgIdentifier c30_thisId;
  static const char * c30_fieldNames[3] = { "v_x", "F_fz", "F_rz" };

  c30_thisId.fParent = c30_parentId;
  sf_mex_check_struct(c30_parentId, c30_u, 3, c30_fieldNames, 0U, NULL);
  c30_thisId.fIdentifier = "v_x";
  c30_y.v_x = c30_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c30_u, "v_x", "v_x", 0)), &c30_thisId);
  c30_thisId.fIdentifier = "F_fz";
  c30_y.F_fz = c30_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c30_u, "F_fz", "F_fz", 0)), &c30_thisId);
  c30_thisId.fIdentifier = "F_rz";
  c30_y.F_rz = c30_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c30_u, "F_rz", "F_rz", 0)), &c30_thisId);
  sf_mex_destroy(&c30_u);
  return c30_y;
}

static void c30_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c30_mxArrayInData, const char_T *c30_varName, void *c30_outData)
{
  const mxArray *c30_b_Par;
  const char_T *c30_identifier;
  emlrtMsgIdentifier c30_thisId;
  c30_struct_iBlsPBO3AGnt69vDoTx5zD c30_y;
  SFc30_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc30_ModifiedInstanceStruct *)chartInstanceVoid;
  c30_b_Par = sf_mex_dup(c30_mxArrayInData);
  c30_identifier = c30_varName;
  c30_thisId.fIdentifier = c30_identifier;
  c30_thisId.fParent = NULL;
  c30_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c30_b_Par), &c30_thisId,
    &c30_y);
  sf_mex_destroy(&c30_b_Par);
  *(c30_struct_iBlsPBO3AGnt69vDoTx5zD *)c30_outData = c30_y;
  sf_mex_destroy(&c30_mxArrayInData);
}

static const mxArray *c30_c_sf_marshallOut(void *chartInstanceVoid, void
  *c30_inData)
{
  const mxArray *c30_mxArrayOutData = NULL;
  real_T c30_u;
  const mxArray *c30_y = NULL;
  SFc30_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc30_ModifiedInstanceStruct *)chartInstanceVoid;
  c30_mxArrayOutData = NULL;
  c30_u = *(real_T *)c30_inData;
  c30_y = NULL;
  sf_mex_assign(&c30_y, sf_mex_create("y", &c30_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c30_mxArrayOutData, c30_y, false);
  return c30_mxArrayOutData;
}

static void c30_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c30_mxArrayInData, const char_T *c30_varName, void *c30_outData)
{
  const mxArray *c30_nargout;
  const char_T *c30_identifier;
  emlrtMsgIdentifier c30_thisId;
  real_T c30_y;
  SFc30_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc30_ModifiedInstanceStruct *)chartInstanceVoid;
  c30_nargout = sf_mex_dup(c30_mxArrayInData);
  c30_identifier = c30_varName;
  c30_thisId.fIdentifier = c30_identifier;
  c30_thisId.fParent = NULL;
  c30_y = c30_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c30_nargout),
    &c30_thisId);
  sf_mex_destroy(&c30_nargout);
  *(real_T *)c30_outData = c30_y;
  sf_mex_destroy(&c30_mxArrayInData);
}

const mxArray *sf_c30_Modified_get_eml_resolved_functions_info(void)
{
  const mxArray *c30_nameCaptureInfo = NULL;
  c30_nameCaptureInfo = NULL;
  sf_mex_assign(&c30_nameCaptureInfo, sf_mex_createstruct("structure", 2, 26, 1),
                false);
  c30_info_helper(&c30_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c30_nameCaptureInfo);
  return c30_nameCaptureInfo;
}

static void c30_info_helper(const mxArray **c30_info)
{
  const mxArray *c30_rhs0 = NULL;
  const mxArray *c30_lhs0 = NULL;
  const mxArray *c30_rhs1 = NULL;
  const mxArray *c30_lhs1 = NULL;
  const mxArray *c30_rhs2 = NULL;
  const mxArray *c30_lhs2 = NULL;
  const mxArray *c30_rhs3 = NULL;
  const mxArray *c30_lhs3 = NULL;
  const mxArray *c30_rhs4 = NULL;
  const mxArray *c30_lhs4 = NULL;
  const mxArray *c30_rhs5 = NULL;
  const mxArray *c30_lhs5 = NULL;
  const mxArray *c30_rhs6 = NULL;
  const mxArray *c30_lhs6 = NULL;
  const mxArray *c30_rhs7 = NULL;
  const mxArray *c30_lhs7 = NULL;
  const mxArray *c30_rhs8 = NULL;
  const mxArray *c30_lhs8 = NULL;
  const mxArray *c30_rhs9 = NULL;
  const mxArray *c30_lhs9 = NULL;
  const mxArray *c30_rhs10 = NULL;
  const mxArray *c30_lhs10 = NULL;
  const mxArray *c30_rhs11 = NULL;
  const mxArray *c30_lhs11 = NULL;
  const mxArray *c30_rhs12 = NULL;
  const mxArray *c30_lhs12 = NULL;
  const mxArray *c30_rhs13 = NULL;
  const mxArray *c30_lhs13 = NULL;
  const mxArray *c30_rhs14 = NULL;
  const mxArray *c30_lhs14 = NULL;
  const mxArray *c30_rhs15 = NULL;
  const mxArray *c30_lhs15 = NULL;
  const mxArray *c30_rhs16 = NULL;
  const mxArray *c30_lhs16 = NULL;
  const mxArray *c30_rhs17 = NULL;
  const mxArray *c30_lhs17 = NULL;
  const mxArray *c30_rhs18 = NULL;
  const mxArray *c30_lhs18 = NULL;
  const mxArray *c30_rhs19 = NULL;
  const mxArray *c30_lhs19 = NULL;
  const mxArray *c30_rhs20 = NULL;
  const mxArray *c30_lhs20 = NULL;
  const mxArray *c30_rhs21 = NULL;
  const mxArray *c30_lhs21 = NULL;
  const mxArray *c30_rhs22 = NULL;
  const mxArray *c30_lhs22 = NULL;
  const mxArray *c30_rhs23 = NULL;
  const mxArray *c30_lhs23 = NULL;
  const mxArray *c30_rhs24 = NULL;
  const mxArray *c30_lhs24 = NULL;
  const mxArray *c30_rhs25 = NULL;
  const mxArray *c30_lhs25 = NULL;
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("abs"), "name", "name", 0);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1363713852U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c30_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c30_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c30_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c30_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 2);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1286818712U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c30_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c30_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(""), "context", "context", 3);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("mrdivide"), "name", "name",
                  3);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1410807648U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1370009886U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c30_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c30_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 4);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 4);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1389717774U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c30_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c30_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 5);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("rdivide"), "name", "name", 5);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1363713880U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c30_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c30_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 6);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c30_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c30_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 7);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c30_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c30_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_div"), "name", "name", 8);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1386423952U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c30_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c30_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 9);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c30_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c30_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(""), "context", "context", 10);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("mpower"), "name", "name", 10);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c30_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c30_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 11);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c30_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c30_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 12);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("ismatrix"), "name", "name",
                  12);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1331304858U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c30_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c30_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("power"), "name", "name", 13);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1395328506U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c30_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c30_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 14);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c30_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c30_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 15);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 15);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c30_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c30_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 16);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c30_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c30_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 17);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 17);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c30_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c30_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 18);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 18);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c30_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c30_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 19);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("floor"), "name", "name", 19);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1363713854U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c30_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c30_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 20);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c30_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c30_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 21);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1286818726U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c30_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c30_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power"),
                  "context", "context", 22);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 22);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c30_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c30_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(""), "context", "context", 23);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("sqrt"), "name", "name", 23);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "resolved",
                  "resolved", 23);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1343830386U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c30_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c30_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "context",
                  "context", 24);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_error"), "name", "name",
                  24);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 24);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1343830358U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c30_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c30_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "context",
                  "context", 25);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_scalar_sqrt"), "name",
                  "name", 25);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1286818738U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c30_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c30_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs25), "lhs", "lhs",
                  25);
  sf_mex_destroy(&c30_rhs0);
  sf_mex_destroy(&c30_lhs0);
  sf_mex_destroy(&c30_rhs1);
  sf_mex_destroy(&c30_lhs1);
  sf_mex_destroy(&c30_rhs2);
  sf_mex_destroy(&c30_lhs2);
  sf_mex_destroy(&c30_rhs3);
  sf_mex_destroy(&c30_lhs3);
  sf_mex_destroy(&c30_rhs4);
  sf_mex_destroy(&c30_lhs4);
  sf_mex_destroy(&c30_rhs5);
  sf_mex_destroy(&c30_lhs5);
  sf_mex_destroy(&c30_rhs6);
  sf_mex_destroy(&c30_lhs6);
  sf_mex_destroy(&c30_rhs7);
  sf_mex_destroy(&c30_lhs7);
  sf_mex_destroy(&c30_rhs8);
  sf_mex_destroy(&c30_lhs8);
  sf_mex_destroy(&c30_rhs9);
  sf_mex_destroy(&c30_lhs9);
  sf_mex_destroy(&c30_rhs10);
  sf_mex_destroy(&c30_lhs10);
  sf_mex_destroy(&c30_rhs11);
  sf_mex_destroy(&c30_lhs11);
  sf_mex_destroy(&c30_rhs12);
  sf_mex_destroy(&c30_lhs12);
  sf_mex_destroy(&c30_rhs13);
  sf_mex_destroy(&c30_lhs13);
  sf_mex_destroy(&c30_rhs14);
  sf_mex_destroy(&c30_lhs14);
  sf_mex_destroy(&c30_rhs15);
  sf_mex_destroy(&c30_lhs15);
  sf_mex_destroy(&c30_rhs16);
  sf_mex_destroy(&c30_lhs16);
  sf_mex_destroy(&c30_rhs17);
  sf_mex_destroy(&c30_lhs17);
  sf_mex_destroy(&c30_rhs18);
  sf_mex_destroy(&c30_lhs18);
  sf_mex_destroy(&c30_rhs19);
  sf_mex_destroy(&c30_lhs19);
  sf_mex_destroy(&c30_rhs20);
  sf_mex_destroy(&c30_lhs20);
  sf_mex_destroy(&c30_rhs21);
  sf_mex_destroy(&c30_lhs21);
  sf_mex_destroy(&c30_rhs22);
  sf_mex_destroy(&c30_lhs22);
  sf_mex_destroy(&c30_rhs23);
  sf_mex_destroy(&c30_lhs23);
  sf_mex_destroy(&c30_rhs24);
  sf_mex_destroy(&c30_lhs24);
  sf_mex_destroy(&c30_rhs25);
  sf_mex_destroy(&c30_lhs25);
}

static const mxArray *c30_emlrt_marshallOut(const char * c30_u)
{
  const mxArray *c30_y = NULL;
  c30_y = NULL;
  sf_mex_assign(&c30_y, sf_mex_create("y", c30_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c30_u)), false);
  return c30_y;
}

static const mxArray *c30_b_emlrt_marshallOut(const uint32_T c30_u)
{
  const mxArray *c30_y = NULL;
  c30_y = NULL;
  sf_mex_assign(&c30_y, sf_mex_create("y", &c30_u, 7, 0U, 0U, 0U, 0), false);
  return c30_y;
}

static real_T c30_abs(SFc30_ModifiedInstanceStruct *chartInstance, real_T c30_x)
{
  real_T c30_b_x;
  (void)chartInstance;
  c30_b_x = c30_x;
  return muDoubleScalarAbs(c30_b_x);
}

static real_T c30_mpower(SFc30_ModifiedInstanceStruct *chartInstance, real_T
  c30_a)
{
  real_T c30_b_a;
  real_T c30_c_a;
  real_T c30_ak;
  real_T c30_d_a;
  c30_b_a = c30_a;
  c30_c_a = c30_b_a;
  c30_eml_scalar_eg(chartInstance);
  c30_ak = c30_c_a;
  c30_d_a = c30_ak;
  c30_eml_scalar_eg(chartInstance);
  return c30_d_a * c30_d_a;
}

static void c30_eml_scalar_eg(SFc30_ModifiedInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c30_eml_error(SFc30_ModifiedInstanceStruct *chartInstance)
{
  int32_T c30_i19;
  static char_T c30_cv0[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c30_u[30];
  const mxArray *c30_y = NULL;
  int32_T c30_i20;
  static char_T c30_cv1[4] = { 's', 'q', 'r', 't' };

  char_T c30_b_u[4];
  const mxArray *c30_b_y = NULL;
  (void)chartInstance;
  for (c30_i19 = 0; c30_i19 < 30; c30_i19++) {
    c30_u[c30_i19] = c30_cv0[c30_i19];
  }

  c30_y = NULL;
  sf_mex_assign(&c30_y, sf_mex_create("y", c30_u, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  for (c30_i20 = 0; c30_i20 < 4; c30_i20++) {
    c30_b_u[c30_i20] = c30_cv1[c30_i20];
  }

  c30_b_y = NULL;
  sf_mex_assign(&c30_b_y, sf_mex_create("y", c30_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c30_y, 14, c30_b_y));
}

static const mxArray *c30_d_sf_marshallOut(void *chartInstanceVoid, void
  *c30_inData)
{
  const mxArray *c30_mxArrayOutData = NULL;
  int32_T c30_u;
  const mxArray *c30_y = NULL;
  SFc30_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc30_ModifiedInstanceStruct *)chartInstanceVoid;
  c30_mxArrayOutData = NULL;
  c30_u = *(int32_T *)c30_inData;
  c30_y = NULL;
  sf_mex_assign(&c30_y, sf_mex_create("y", &c30_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c30_mxArrayOutData, c30_y, false);
  return c30_mxArrayOutData;
}

static int32_T c30_m_emlrt_marshallIn(SFc30_ModifiedInstanceStruct
  *chartInstance, const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId)
{
  int32_T c30_y;
  int32_T c30_i21;
  (void)chartInstance;
  sf_mex_import(c30_parentId, sf_mex_dup(c30_u), &c30_i21, 1, 6, 0U, 0, 0U, 0);
  c30_y = c30_i21;
  sf_mex_destroy(&c30_u);
  return c30_y;
}

static void c30_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c30_mxArrayInData, const char_T *c30_varName, void *c30_outData)
{
  const mxArray *c30_b_sfEvent;
  const char_T *c30_identifier;
  emlrtMsgIdentifier c30_thisId;
  int32_T c30_y;
  SFc30_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc30_ModifiedInstanceStruct *)chartInstanceVoid;
  c30_b_sfEvent = sf_mex_dup(c30_mxArrayInData);
  c30_identifier = c30_varName;
  c30_thisId.fIdentifier = c30_identifier;
  c30_thisId.fParent = NULL;
  c30_y = c30_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c30_b_sfEvent),
    &c30_thisId);
  sf_mex_destroy(&c30_b_sfEvent);
  *(int32_T *)c30_outData = c30_y;
  sf_mex_destroy(&c30_mxArrayInData);
}

static const mxArray *c30_w_4_bus_io(void *chartInstanceVoid, void *c30_pData)
{
  const mxArray *c30_mxVal = NULL;
  c30_whl_vec4 c30_tmp;
  SFc30_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc30_ModifiedInstanceStruct *)chartInstanceVoid;
  c30_mxVal = NULL;
  c30_tmp.fl = *(real_T *)&((char_T *)(c30_whl_vec4 *)c30_pData)[0];
  c30_tmp.fr = *(real_T *)&((char_T *)(c30_whl_vec4 *)c30_pData)[8];
  c30_tmp.rl = *(real_T *)&((char_T *)(c30_whl_vec4 *)c30_pData)[16];
  c30_tmp.rr = *(real_T *)&((char_T *)(c30_whl_vec4 *)c30_pData)[24];
  sf_mex_assign(&c30_mxVal, c30_sf_marshallOut(chartInstance, &c30_tmp), false);
  return c30_mxVal;
}

static uint8_T c30_n_emlrt_marshallIn(SFc30_ModifiedInstanceStruct
  *chartInstance, const mxArray *c30_b_is_active_c30_Modified, const char_T
  *c30_identifier)
{
  uint8_T c30_y;
  emlrtMsgIdentifier c30_thisId;
  c30_thisId.fIdentifier = c30_identifier;
  c30_thisId.fParent = NULL;
  c30_y = c30_o_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c30_b_is_active_c30_Modified), &c30_thisId);
  sf_mex_destroy(&c30_b_is_active_c30_Modified);
  return c30_y;
}

static uint8_T c30_o_emlrt_marshallIn(SFc30_ModifiedInstanceStruct
  *chartInstance, const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId)
{
  uint8_T c30_y;
  uint8_T c30_u0;
  (void)chartInstance;
  sf_mex_import(c30_parentId, sf_mex_dup(c30_u), &c30_u0, 1, 3, 0U, 0, 0U, 0);
  c30_y = c30_u0;
  sf_mex_destroy(&c30_u);
  return c30_y;
}

static void init_dsm_address_info(SFc30_ModifiedInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc30_ModifiedInstanceStruct *chartInstance)
{
  chartInstance->c30_w_4 = (c30_whl_vec4 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c30_v_xw4 = (c30_whl_vec4 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c30_v_yw4 = (c30_whl_vec4 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c30_s_x4 = (c30_whl_vec4 *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c30_s_y4 = (c30_whl_vec4 *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c30_s_xy4 = (c30_whl_vec4 *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
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

void sf_c30_Modified_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4022474432U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4017876916U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1371627090U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(853444754U);
}

mxArray* sf_c30_Modified_get_post_codegen_info(void);
mxArray *sf_c30_Modified_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("wSDJnyulOS8BTX1P0GxauC");
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c30_Modified_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c30_Modified_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c30_Modified_jit_fallback_info(void)
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

mxArray *sf_c30_Modified_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c30_Modified_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c30_Modified(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[11],T\"s_x4\",},{M[1],M[48],T\"s_xy4\",},{M[1],M[12],T\"s_y4\",},{M[8],M[0],T\"is_active_c30_Modified\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c30_Modified_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc30_ModifiedInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc30_ModifiedInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ModifiedMachineNumber_,
           30,
           1,
           1,
           0,
           7,
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
          _SFD_SET_DATA_PROPS(1,1,1,0,"v_xw4");
          _SFD_SET_DATA_PROPS(2,1,1,0,"v_yw4");
          _SFD_SET_DATA_PROPS(3,2,0,1,"s_x4");
          _SFD_SET_DATA_PROPS(4,2,0,1,"s_y4");
          _SFD_SET_DATA_PROPS(5,10,0,0,"Par");
          _SFD_SET_DATA_PROPS(6,2,0,1,"s_xy4");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,657);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c30_w_4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c30_w_4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c30_w_4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c30_w_4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c30_w_4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c30_b_sf_marshallOut,(MexInFcnForType)
          c30_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c30_w_4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c30_w_4);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c30_v_xw4);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c30_v_yw4);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c30_s_x4);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c30_s_y4);
        _SFD_SET_DATA_VALUE_PTR(5U, &chartInstance->c30_Par);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c30_s_xy4);
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
  return "QtcePKxe4H9FFy5hhEFE6E";
}

static void sf_opaque_initialize_c30_Modified(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc30_ModifiedInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c30_Modified((SFc30_ModifiedInstanceStruct*)
    chartInstanceVar);
  initialize_c30_Modified((SFc30_ModifiedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c30_Modified(void *chartInstanceVar)
{
  enable_c30_Modified((SFc30_ModifiedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c30_Modified(void *chartInstanceVar)
{
  disable_c30_Modified((SFc30_ModifiedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c30_Modified(void *chartInstanceVar)
{
  sf_gateway_c30_Modified((SFc30_ModifiedInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c30_Modified(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c30_Modified((SFc30_ModifiedInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c30_Modified(SimStruct* S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c30_Modified((SFc30_ModifiedInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c30_Modified(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc30_ModifiedInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Modified_optimization_info();
    }

    finalize_c30_Modified((SFc30_ModifiedInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc30_Modified((SFc30_ModifiedInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c30_Modified(SimStruct *S)
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
    initialize_params_c30_Modified((SFc30_ModifiedInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c30_Modified(SimStruct *S)
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
      30);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,30,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,30,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,30);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,30,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,30,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,30);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(722671706U));
  ssSetChecksum1(S,(2134343439U));
  ssSetChecksum2(S,(3879458914U));
  ssSetChecksum3(S,(465210218U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c30_Modified(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c30_Modified(SimStruct *S)
{
  SFc30_ModifiedInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc30_ModifiedInstanceStruct *)utMalloc(sizeof
    (SFc30_ModifiedInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc30_ModifiedInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c30_Modified;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c30_Modified;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c30_Modified;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c30_Modified;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c30_Modified;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c30_Modified;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c30_Modified;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c30_Modified;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c30_Modified;
  chartInstance->chartInfo.mdlStart = mdlStart_c30_Modified;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c30_Modified;
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

void c30_Modified_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c30_Modified(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c30_Modified(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c30_Modified(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c30_Modified_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
