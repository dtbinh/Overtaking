/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Modified2_sfun.h"
#include "c26_Modified2.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Modified2_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c26_debug_family_names[11] = { "Jw", "nargin", "nargout",
  "T_s4", "T_us4", "F_xv4", "F_yv4", "F_z4", "w_w4", "Par", "derw_w4" };

/* Function Declarations */
static void initialize_c26_Modified2(SFc26_Modified2InstanceStruct
  *chartInstance);
static void initialize_params_c26_Modified2(SFc26_Modified2InstanceStruct
  *chartInstance);
static void enable_c26_Modified2(SFc26_Modified2InstanceStruct *chartInstance);
static void disable_c26_Modified2(SFc26_Modified2InstanceStruct *chartInstance);
static void c26_update_debugger_state_c26_Modified2
  (SFc26_Modified2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c26_Modified2(SFc26_Modified2InstanceStruct *
  chartInstance);
static void set_sim_state_c26_Modified2(SFc26_Modified2InstanceStruct
  *chartInstance, const mxArray *c26_st);
static void finalize_c26_Modified2(SFc26_Modified2InstanceStruct *chartInstance);
static void sf_gateway_c26_Modified2(SFc26_Modified2InstanceStruct
  *chartInstance);
static void mdl_start_c26_Modified2(SFc26_Modified2InstanceStruct *chartInstance);
static void initSimStructsc26_Modified2(SFc26_Modified2InstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c26_machineNumber, uint32_T
  c26_chartNumber, uint32_T c26_instanceNumber);
static const mxArray *c26_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData);
static c26_whl_vec4 c26_emlrt_marshallIn(SFc26_Modified2InstanceStruct
  *chartInstance, const mxArray *c26_b_derw_w4, const char_T *c26_identifier);
static c26_whl_vec4 c26_b_emlrt_marshallIn(SFc26_Modified2InstanceStruct
  *chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId);
static real_T c26_c_emlrt_marshallIn(SFc26_Modified2InstanceStruct
  *chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId);
static void c26_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c26_mxArrayInData, const char_T *c26_varName, void *c26_outData);
static const mxArray *c26_b_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData);
static void c26_d_emlrt_marshallIn(SFc26_Modified2InstanceStruct *chartInstance,
  const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId,
  c26_struct_iBlsPBO3AGnt69vDoTx5zD *c26_y);
static void c26_e_emlrt_marshallIn(SFc26_Modified2InstanceStruct *chartInstance,
  const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId,
  c26_struct_Nst2vGTExxHsg85EUOj9EH *c26_y);
static c26_struct_HhckT6rntEraqECYVIDvCC c26_f_emlrt_marshallIn
  (SFc26_Modified2InstanceStruct *chartInstance, const mxArray *c26_u, const
   emlrtMsgIdentifier *c26_parentId);
static void c26_g_emlrt_marshallIn(SFc26_Modified2InstanceStruct *chartInstance,
  const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId,
  c26_struct_ZCmOWPuqBDw16FSOVVD00 *c26_y);
static void c26_h_emlrt_marshallIn(SFc26_Modified2InstanceStruct *chartInstance,
  const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId, real_T c26_y[4]);
static void c26_i_emlrt_marshallIn(SFc26_Modified2InstanceStruct *chartInstance,
  const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId,
  c26_struct_ZKAzdrl7umDGJoC14aoVKC *c26_y);
static void c26_j_emlrt_marshallIn(SFc26_Modified2InstanceStruct *chartInstance,
  const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId, real_T c26_y[3]);
static c26_struct_r4FNviKwHfdhB8nQjvQv9 c26_k_emlrt_marshallIn
  (SFc26_Modified2InstanceStruct *chartInstance, const mxArray *c26_u, const
   emlrtMsgIdentifier *c26_parentId);
static c26_struct_Y9F1qlBi9AhssksPwemA4G c26_l_emlrt_marshallIn
  (SFc26_Modified2InstanceStruct *chartInstance, const mxArray *c26_u, const
   emlrtMsgIdentifier *c26_parentId);
static void c26_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c26_mxArrayInData, const char_T *c26_varName, void *c26_outData);
static const mxArray *c26_c_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData);
static void c26_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c26_mxArrayInData, const char_T *c26_varName, void *c26_outData);
static void c26_info_helper(const mxArray **c26_info);
static const mxArray *c26_emlrt_marshallOut(const char * c26_u);
static const mxArray *c26_b_emlrt_marshallOut(const uint32_T c26_u);
static const mxArray *c26_d_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData);
static int32_T c26_m_emlrt_marshallIn(SFc26_Modified2InstanceStruct
  *chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId);
static void c26_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c26_mxArrayInData, const char_T *c26_varName, void *c26_outData);
static const mxArray *c26_T_s4_bus_io(void *chartInstanceVoid, void *c26_pData);
static uint8_T c26_n_emlrt_marshallIn(SFc26_Modified2InstanceStruct
  *chartInstance, const mxArray *c26_b_is_active_c26_Modified2, const char_T
  *c26_identifier);
static uint8_T c26_o_emlrt_marshallIn(SFc26_Modified2InstanceStruct
  *chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId);
static void init_dsm_address_info(SFc26_Modified2InstanceStruct *chartInstance);
static void init_simulink_io_address(SFc26_Modified2InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c26_Modified2(SFc26_Modified2InstanceStruct
  *chartInstance)
{
  chartInstance->c26_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c26_is_active_c26_Modified2 = 0U;
}

static void initialize_params_c26_Modified2(SFc26_Modified2InstanceStruct
  *chartInstance)
{
  const mxArray *c26_m0 = NULL;
  const mxArray *c26_mxField;
  const mxArray *c26_m1 = NULL;
  const mxArray *c26_b_mxField;
  c26_struct_iBlsPBO3AGnt69vDoTx5zD c26_r0;
  const mxArray *c26_m2 = NULL;
  const mxArray *c26_c_mxField;
  const mxArray *c26_m3 = NULL;
  const mxArray *c26_d_mxField;
  const mxArray *c26_m4 = NULL;
  const mxArray *c26_e_mxField;
  const mxArray *c26_m5 = NULL;
  const mxArray *c26_f_mxField;
  const mxArray *c26_m6 = NULL;
  const mxArray *c26_g_mxField;
  const mxArray *c26_m7 = NULL;
  const mxArray *c26_h_mxField;
  const mxArray *c26_m8 = NULL;
  const mxArray *c26_i_mxField;
  const mxArray *c26_m9 = NULL;
  const mxArray *c26_j_mxField;
  const mxArray *c26_m10 = NULL;
  const mxArray *c26_k_mxField;
  const mxArray *c26_m11 = NULL;
  const mxArray *c26_l_mxField;
  const mxArray *c26_m12 = NULL;
  const mxArray *c26_m_mxField;
  const mxArray *c26_m13 = NULL;
  const mxArray *c26_n_mxField;
  c26_m0 = sf_mex_get_sfun_param(chartInstance->S, 0, 1);
  c26_mxField = sf_mex_getfield(c26_m0, "Env", "Par", 0);
  c26_m1 = sf_mex_dup(c26_mxField);
  c26_b_mxField = sf_mex_getfield(c26_m1, "g", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_b_mxField), &c26_r0.Env.g, 1, 0, 0U,
                      0, 0U, 0);
  c26_b_mxField = sf_mex_getfield(c26_m1, "left1", "Par", 0);
  c26_m2 = sf_mex_dup(c26_b_mxField);
  c26_c_mxField = sf_mex_getfield(c26_m2, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_c_mxField), &c26_r0.Env.left1.x, 1,
                      0, 0U, 0, 0U, 0);
  c26_c_mxField = sf_mex_getfield(c26_m2, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_c_mxField), &c26_r0.Env.left1.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c26_m2);
  c26_b_mxField = sf_mex_getfield(c26_m1, "right1", "Par", 0);
  c26_m3 = sf_mex_dup(c26_b_mxField);
  c26_d_mxField = sf_mex_getfield(c26_m3, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_d_mxField), &c26_r0.Env.right1.x, 1,
                      0, 0U, 0, 0U, 0);
  c26_d_mxField = sf_mex_getfield(c26_m3, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_d_mxField), &c26_r0.Env.right1.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c26_m3);
  c26_b_mxField = sf_mex_getfield(c26_m1, "right2", "Par", 0);
  c26_m4 = sf_mex_dup(c26_b_mxField);
  c26_e_mxField = sf_mex_getfield(c26_m4, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_e_mxField), &c26_r0.Env.right2.x, 1,
                      0, 0U, 0, 0U, 0);
  c26_e_mxField = sf_mex_getfield(c26_m4, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_e_mxField), &c26_r0.Env.right2.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c26_m4);
  c26_b_mxField = sf_mex_getfield(c26_m1, "left2", "Par", 0);
  c26_m5 = sf_mex_dup(c26_b_mxField);
  c26_f_mxField = sf_mex_getfield(c26_m5, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_f_mxField), &c26_r0.Env.left2.x, 1,
                      0, 0U, 0, 0U, 0);
  c26_f_mxField = sf_mex_getfield(c26_m5, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_f_mxField), &c26_r0.Env.left2.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c26_m5);
  c26_b_mxField = sf_mex_getfield(c26_m1, "right3", "Par", 0);
  c26_m6 = sf_mex_dup(c26_b_mxField);
  c26_g_mxField = sf_mex_getfield(c26_m6, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_g_mxField), &c26_r0.Env.right3.x, 1,
                      0, 0U, 0, 0U, 0);
  c26_g_mxField = sf_mex_getfield(c26_m6, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_g_mxField), &c26_r0.Env.right3.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c26_m6);
  c26_b_mxField = sf_mex_getfield(c26_m1, "mu", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_b_mxField), &c26_r0.Env.mu, 1, 0, 0U,
                      0, 0U, 0);
  sf_mex_destroy(&c26_m1);
  c26_mxField = sf_mex_getfield(c26_m0, "Veh", "Par", 0);
  c26_m7 = sf_mex_dup(c26_mxField);
  c26_h_mxField = sf_mex_getfield(c26_m7, "m", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_h_mxField), &c26_r0.Veh.m, 1, 0, 0U,
                      0, 0U, 0);
  c26_h_mxField = sf_mex_getfield(c26_m7, "Jz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_h_mxField), &c26_r0.Veh.Jz, 1, 0, 0U,
                      0, 0U, 0);
  c26_h_mxField = sf_mex_getfield(c26_m7, "m_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_h_mxField), &c26_r0.Veh.m_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c26_h_mxField = sf_mex_getfield(c26_m7, "Jx_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_h_mxField), &c26_r0.Veh.Jx_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c26_h_mxField = sf_mex_getfield(c26_m7, "Jy_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_h_mxField), &c26_r0.Veh.Jy_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c26_h_mxField = sf_mex_getfield(c26_m7, "lf", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_h_mxField), &c26_r0.Veh.lf, 1, 0, 0U,
                      0, 0U, 0);
  c26_h_mxField = sf_mex_getfield(c26_m7, "lr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_h_mxField), &c26_r0.Veh.lr, 1, 0, 0U,
                      0, 0U, 0);
  c26_h_mxField = sf_mex_getfield(c26_m7, "L", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_h_mxField), &c26_r0.Veh.L, 1, 0, 0U,
                      0, 0U, 0);
  c26_h_mxField = sf_mex_getfield(c26_m7, "TrackWidth", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_h_mxField), &c26_r0.Veh.TrackWidth,
                      1, 0, 0U, 0, 0U, 0);
  c26_h_mxField = sf_mex_getfield(c26_m7, "h", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_h_mxField), &c26_r0.Veh.h, 1, 0, 0U,
                      0, 0U, 0);
  c26_h_mxField = sf_mex_getfield(c26_m7, "HalfRohACd", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_h_mxField), &c26_r0.Veh.HalfRohACd,
                      1, 0, 0U, 0, 0U, 0);
  c26_h_mxField = sf_mex_getfield(c26_m7, "F_z4_static", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_h_mxField), c26_r0.Veh.F_z4_static,
                      1, 0, 0U, 1, 0U, 2, 1, 4);
  c26_h_mxField = sf_mex_getfield(c26_m7, "Rw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_h_mxField), &c26_r0.Veh.Rw, 1, 0, 0U,
                      0, 0U, 0);
  c26_h_mxField = sf_mex_getfield(c26_m7, "r_long", "Par", 0);
  c26_m8 = sf_mex_dup(c26_h_mxField);
  c26_i_mxField = sf_mex_getfield(c26_m8, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_i_mxField), c26_r0.Veh.r_long.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c26_i_mxField = sf_mex_getfield(c26_m8, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_i_mxField), c26_r0.Veh.r_long.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c26_i_mxField = sf_mex_getfield(c26_m8, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_i_mxField), c26_r0.Veh.r_long.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c26_i_mxField = sf_mex_getfield(c26_m8, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_i_mxField), c26_r0.Veh.r_long.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c26_m8);
  c26_h_mxField = sf_mex_getfield(c26_m7, "r_lat", "Par", 0);
  c26_m9 = sf_mex_dup(c26_h_mxField);
  c26_j_mxField = sf_mex_getfield(c26_m9, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_j_mxField), c26_r0.Veh.r_lat.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c26_j_mxField = sf_mex_getfield(c26_m9, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_j_mxField), c26_r0.Veh.r_lat.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c26_j_mxField = sf_mex_getfield(c26_m9, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_j_mxField), c26_r0.Veh.r_lat.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c26_j_mxField = sf_mex_getfield(c26_m9, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_j_mxField), c26_r0.Veh.r_lat.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c26_m9);
  c26_h_mxField = sf_mex_getfield(c26_m7, "r_lever", "Par", 0);
  c26_m10 = sf_mex_dup(c26_h_mxField);
  c26_k_mxField = sf_mex_getfield(c26_m10, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_k_mxField), c26_r0.Veh.r_lever.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c26_k_mxField = sf_mex_getfield(c26_m10, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_k_mxField), c26_r0.Veh.r_lever.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c26_k_mxField = sf_mex_getfield(c26_m10, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_k_mxField), c26_r0.Veh.r_lever.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c26_k_mxField = sf_mex_getfield(c26_m10, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_k_mxField), c26_r0.Veh.r_lever.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c26_m10);
  c26_h_mxField = sf_mex_getfield(c26_m7, "r_pivot", "Par", 0);
  c26_m11 = sf_mex_dup(c26_h_mxField);
  c26_l_mxField = sf_mex_getfield(c26_m11, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_l_mxField), c26_r0.Veh.r_pivot.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c26_l_mxField = sf_mex_getfield(c26_m11, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_l_mxField), c26_r0.Veh.r_pivot.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c26_l_mxField = sf_mex_getfield(c26_m11, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_l_mxField), c26_r0.Veh.r_pivot.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c26_l_mxField = sf_mex_getfield(c26_m11, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_l_mxField), c26_r0.Veh.r_pivot.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c26_m11);
  c26_h_mxField = sf_mex_getfield(c26_m7, "cw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_h_mxField), &c26_r0.Veh.cw, 1, 0, 0U,
                      0, 0U, 0);
  c26_h_mxField = sf_mex_getfield(c26_m7, "carb_f", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_h_mxField), &c26_r0.Veh.carb_f, 1, 0,
                      0U, 0, 0U, 0);
  c26_h_mxField = sf_mex_getfield(c26_m7, "carb_r", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_h_mxField), &c26_r0.Veh.carb_r, 1, 0,
                      0U, 0, 0U, 0);
  c26_h_mxField = sf_mex_getfield(c26_m7, "dw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_h_mxField), &c26_r0.Veh.dw, 1, 0, 0U,
                      0, 0U, 0);
  c26_h_mxField = sf_mex_getfield(c26_m7, "Jw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_h_mxField), &c26_r0.Veh.Jw, 1, 0, 0U,
                      0, 0U, 0);
  c26_h_mxField = sf_mex_getfield(c26_m7, "C0", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_h_mxField), &c26_r0.Veh.C0, 1, 0, 0U,
                      0, 0U, 0);
  c26_h_mxField = sf_mex_getfield(c26_m7, "RelaxLength", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_h_mxField), &c26_r0.Veh.RelaxLength,
                      1, 0, 0U, 0, 0U, 0);
  c26_h_mxField = sf_mex_getfield(c26_m7, "RRC", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_h_mxField), &c26_r0.Veh.RRC, 1, 0,
                      0U, 0, 0U, 0);
  c26_h_mxField = sf_mex_getfield(c26_m7, "Pmax", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_h_mxField), &c26_r0.Veh.Pmax, 1, 0,
                      0U, 0, 0U, 0);
  c26_h_mxField = sf_mex_getfield(c26_m7, "PropDistrFrnt", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_h_mxField),
                      &c26_r0.Veh.PropDistrFrnt, 1, 0, 0U, 0, 0U, 0);
  c26_h_mxField = sf_mex_getfield(c26_m7, "BrkDistrFrnt", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_h_mxField), &c26_r0.Veh.BrkDistrFrnt,
                      1, 0, 0U, 0, 0U, 0);
  c26_h_mxField = sf_mex_getfield(c26_m7, "SteRatio", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_h_mxField), &c26_r0.Veh.SteRatio, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c26_m7);
  c26_mxField = sf_mex_getfield(c26_m0, "Drvr", "Par", 0);
  c26_m12 = sf_mex_dup(c26_mxField);
  c26_m_mxField = sf_mex_getfield(c26_m12, "v_set", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_m_mxField), &c26_r0.Drvr.v_set, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c26_m12);
  c26_mxField = sf_mex_getfield(c26_m0, "Init", "Par", 0);
  c26_m13 = sf_mex_dup(c26_mxField);
  c26_n_mxField = sf_mex_getfield(c26_m13, "v_x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_n_mxField), &c26_r0.Init.v_x, 1, 0,
                      0U, 0, 0U, 0);
  c26_n_mxField = sf_mex_getfield(c26_m13, "F_fz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_n_mxField), &c26_r0.Init.F_fz, 1, 0,
                      0U, 0, 0U, 0);
  c26_n_mxField = sf_mex_getfield(c26_m13, "F_rz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c26_n_mxField), &c26_r0.Init.F_rz, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c26_m13);
  sf_mex_destroy(&c26_m0);
  chartInstance->c26_Par = c26_r0;
}

static void enable_c26_Modified2(SFc26_Modified2InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c26_Modified2(SFc26_Modified2InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c26_update_debugger_state_c26_Modified2
  (SFc26_Modified2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c26_Modified2(SFc26_Modified2InstanceStruct *
  chartInstance)
{
  const mxArray *c26_st;
  const mxArray *c26_y = NULL;
  const mxArray *c26_b_y = NULL;
  real_T c26_u;
  const mxArray *c26_c_y = NULL;
  real_T c26_b_u;
  const mxArray *c26_d_y = NULL;
  real_T c26_c_u;
  const mxArray *c26_e_y = NULL;
  real_T c26_d_u;
  const mxArray *c26_f_y = NULL;
  uint8_T c26_hoistedGlobal;
  uint8_T c26_e_u;
  const mxArray *c26_g_y = NULL;
  c26_st = NULL;
  c26_st = NULL;
  c26_y = NULL;
  sf_mex_assign(&c26_y, sf_mex_createcellmatrix(2, 1), false);
  c26_b_y = NULL;
  sf_mex_assign(&c26_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c26_u = *(real_T *)&((char_T *)chartInstance->c26_derw_w4)[0];
  c26_c_y = NULL;
  sf_mex_assign(&c26_c_y, sf_mex_create("y", &c26_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c26_b_y, c26_c_y, "fl", "fl", 0);
  c26_b_u = *(real_T *)&((char_T *)chartInstance->c26_derw_w4)[8];
  c26_d_y = NULL;
  sf_mex_assign(&c26_d_y, sf_mex_create("y", &c26_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c26_b_y, c26_d_y, "fr", "fr", 0);
  c26_c_u = *(real_T *)&((char_T *)chartInstance->c26_derw_w4)[16];
  c26_e_y = NULL;
  sf_mex_assign(&c26_e_y, sf_mex_create("y", &c26_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c26_b_y, c26_e_y, "rl", "rl", 0);
  c26_d_u = *(real_T *)&((char_T *)chartInstance->c26_derw_w4)[24];
  c26_f_y = NULL;
  sf_mex_assign(&c26_f_y, sf_mex_create("y", &c26_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c26_b_y, c26_f_y, "rr", "rr", 0);
  sf_mex_setcell(c26_y, 0, c26_b_y);
  c26_hoistedGlobal = chartInstance->c26_is_active_c26_Modified2;
  c26_e_u = c26_hoistedGlobal;
  c26_g_y = NULL;
  sf_mex_assign(&c26_g_y, sf_mex_create("y", &c26_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c26_y, 1, c26_g_y);
  sf_mex_assign(&c26_st, c26_y, false);
  return c26_st;
}

static void set_sim_state_c26_Modified2(SFc26_Modified2InstanceStruct
  *chartInstance, const mxArray *c26_st)
{
  const mxArray *c26_u;
  c26_whl_vec4 c26_r1;
  chartInstance->c26_doneDoubleBufferReInit = true;
  c26_u = sf_mex_dup(c26_st);
  c26_r1 = c26_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c26_u,
    0)), "derw_w4");
  *(real_T *)&((char_T *)chartInstance->c26_derw_w4)[0] = c26_r1.fl;
  *(real_T *)&((char_T *)chartInstance->c26_derw_w4)[8] = c26_r1.fr;
  *(real_T *)&((char_T *)chartInstance->c26_derw_w4)[16] = c26_r1.rl;
  *(real_T *)&((char_T *)chartInstance->c26_derw_w4)[24] = c26_r1.rr;
  chartInstance->c26_is_active_c26_Modified2 = c26_n_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c26_u, 1)),
     "is_active_c26_Modified2");
  sf_mex_destroy(&c26_u);
  c26_update_debugger_state_c26_Modified2(chartInstance);
  sf_mex_destroy(&c26_st);
}

static void finalize_c26_Modified2(SFc26_Modified2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c26_Modified2(SFc26_Modified2InstanceStruct
  *chartInstance)
{
  c26_whl_vec4 c26_b_T_s4;
  c26_whl_vec4 c26_b_T_us4;
  c26_whl_vec4 c26_b_F_xv4;
  c26_whl_vec4 c26_b_F_yv4;
  c26_whl_vec4 c26_b_F_z4;
  c26_whl_vec4 c26_b_w_w4;
  c26_struct_iBlsPBO3AGnt69vDoTx5zD c26_b_Par;
  uint32_T c26_debug_family_var_map[11];
  real_T c26_Jw;
  real_T c26_nargin = 7.0;
  real_T c26_nargout = 1.0;
  c26_whl_vec4 c26_b_derw_w4;
  real_T c26_x;
  real_T c26_b_x;
  real_T c26_A;
  real_T c26_B;
  real_T c26_c_x;
  real_T c26_y;
  real_T c26_d_x;
  real_T c26_b_y;
  real_T c26_e_x;
  real_T c26_c_y;
  real_T c26_d_y;
  real_T c26_f_x;
  real_T c26_g_x;
  real_T c26_b_A;
  real_T c26_b_B;
  real_T c26_h_x;
  real_T c26_e_y;
  real_T c26_i_x;
  real_T c26_f_y;
  real_T c26_j_x;
  real_T c26_g_y;
  real_T c26_h_y;
  real_T c26_k_x;
  real_T c26_l_x;
  real_T c26_c_A;
  real_T c26_c_B;
  real_T c26_m_x;
  real_T c26_i_y;
  real_T c26_n_x;
  real_T c26_j_y;
  real_T c26_o_x;
  real_T c26_k_y;
  real_T c26_l_y;
  real_T c26_p_x;
  real_T c26_q_x;
  real_T c26_d_A;
  real_T c26_d_B;
  real_T c26_r_x;
  real_T c26_m_y;
  real_T c26_s_x;
  real_T c26_n_y;
  real_T c26_t_x;
  real_T c26_o_y;
  real_T c26_p_y;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 14U, chartInstance->c26_sfEvent);
  chartInstance->c26_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 14U, chartInstance->c26_sfEvent);
  c26_b_T_s4.fl = *(real_T *)&((char_T *)chartInstance->c26_T_s4)[0];
  c26_b_T_s4.fr = *(real_T *)&((char_T *)chartInstance->c26_T_s4)[8];
  c26_b_T_s4.rl = *(real_T *)&((char_T *)chartInstance->c26_T_s4)[16];
  c26_b_T_s4.rr = *(real_T *)&((char_T *)chartInstance->c26_T_s4)[24];
  c26_b_T_us4.fl = *(real_T *)&((char_T *)chartInstance->c26_T_us4)[0];
  c26_b_T_us4.fr = *(real_T *)&((char_T *)chartInstance->c26_T_us4)[8];
  c26_b_T_us4.rl = *(real_T *)&((char_T *)chartInstance->c26_T_us4)[16];
  c26_b_T_us4.rr = *(real_T *)&((char_T *)chartInstance->c26_T_us4)[24];
  c26_b_F_xv4.fl = *(real_T *)&((char_T *)chartInstance->c26_F_xv4)[0];
  c26_b_F_xv4.fr = *(real_T *)&((char_T *)chartInstance->c26_F_xv4)[8];
  c26_b_F_xv4.rl = *(real_T *)&((char_T *)chartInstance->c26_F_xv4)[16];
  c26_b_F_xv4.rr = *(real_T *)&((char_T *)chartInstance->c26_F_xv4)[24];
  c26_b_F_yv4.fl = *(real_T *)&((char_T *)chartInstance->c26_F_yv4)[0];
  c26_b_F_yv4.fr = *(real_T *)&((char_T *)chartInstance->c26_F_yv4)[8];
  c26_b_F_yv4.rl = *(real_T *)&((char_T *)chartInstance->c26_F_yv4)[16];
  c26_b_F_yv4.rr = *(real_T *)&((char_T *)chartInstance->c26_F_yv4)[24];
  c26_b_F_z4.fl = *(real_T *)&((char_T *)chartInstance->c26_F_z4)[0];
  c26_b_F_z4.fr = *(real_T *)&((char_T *)chartInstance->c26_F_z4)[8];
  c26_b_F_z4.rl = *(real_T *)&((char_T *)chartInstance->c26_F_z4)[16];
  c26_b_F_z4.rr = *(real_T *)&((char_T *)chartInstance->c26_F_z4)[24];
  c26_b_w_w4.fl = *(real_T *)&((char_T *)chartInstance->c26_w_w4)[0];
  c26_b_w_w4.fr = *(real_T *)&((char_T *)chartInstance->c26_w_w4)[8];
  c26_b_w_w4.rl = *(real_T *)&((char_T *)chartInstance->c26_w_w4)[16];
  c26_b_w_w4.rr = *(real_T *)&((char_T *)chartInstance->c26_w_w4)[24];
  c26_b_Par = chartInstance->c26_Par;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 11U, 11U, c26_debug_family_names,
    c26_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c26_Jw, 0U, c26_c_sf_marshallOut,
    c26_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c26_nargin, 1U, c26_c_sf_marshallOut,
    c26_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c26_nargout, 2U, c26_c_sf_marshallOut,
    c26_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c26_b_T_s4, 3U, c26_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c26_b_T_us4, 4U, c26_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c26_b_F_xv4, 5U, c26_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c26_b_F_yv4, 6U, c26_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c26_b_F_z4, 7U, c26_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c26_b_w_w4, 8U, c26_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c26_b_Par, 9U, c26_b_sf_marshallOut,
    c26_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c26_b_derw_w4, 10U, c26_sf_marshallOut,
    c26_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 5);
  c26_Jw = c26_b_Par.Veh.Jw;
  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 7);
  c26_x = c26_b_w_w4.fl;
  c26_b_x = c26_x;
  c26_b_x = muDoubleScalarSign(c26_b_x);
  c26_A = ((c26_b_T_us4.fl + c26_b_T_s4.fl) - c26_b_F_xv4.fl * c26_b_Par.Veh.Rw)
    - c26_b_x * c26_b_F_z4.fl * c26_b_Par.Veh.RRC * c26_b_Par.Veh.Rw;
  c26_B = c26_Jw;
  c26_c_x = c26_A;
  c26_y = c26_B;
  c26_d_x = c26_c_x;
  c26_b_y = c26_y;
  c26_e_x = c26_d_x;
  c26_c_y = c26_b_y;
  c26_d_y = c26_e_x / c26_c_y;
  c26_b_derw_w4.fl = c26_d_y;
  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 8);
  c26_f_x = c26_b_w_w4.fr;
  c26_g_x = c26_f_x;
  c26_g_x = muDoubleScalarSign(c26_g_x);
  c26_b_A = ((c26_b_T_us4.fr + c26_b_T_s4.fr) - c26_b_F_xv4.fr *
             c26_b_Par.Veh.Rw) - c26_g_x * c26_b_F_z4.fr * c26_b_Par.Veh.RRC *
    c26_b_Par.Veh.Rw;
  c26_b_B = c26_Jw;
  c26_h_x = c26_b_A;
  c26_e_y = c26_b_B;
  c26_i_x = c26_h_x;
  c26_f_y = c26_e_y;
  c26_j_x = c26_i_x;
  c26_g_y = c26_f_y;
  c26_h_y = c26_j_x / c26_g_y;
  c26_b_derw_w4.fr = c26_h_y;
  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 9);
  c26_k_x = c26_b_w_w4.rl;
  c26_l_x = c26_k_x;
  c26_l_x = muDoubleScalarSign(c26_l_x);
  c26_c_A = ((c26_b_T_us4.rl + c26_b_T_s4.rl) - c26_b_F_xv4.rl *
             c26_b_Par.Veh.Rw) - c26_l_x * c26_b_F_z4.rl * c26_b_Par.Veh.RRC *
    c26_b_Par.Veh.Rw;
  c26_c_B = c26_Jw;
  c26_m_x = c26_c_A;
  c26_i_y = c26_c_B;
  c26_n_x = c26_m_x;
  c26_j_y = c26_i_y;
  c26_o_x = c26_n_x;
  c26_k_y = c26_j_y;
  c26_l_y = c26_o_x / c26_k_y;
  c26_b_derw_w4.rl = c26_l_y;
  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 10);
  c26_p_x = c26_b_w_w4.rr;
  c26_q_x = c26_p_x;
  c26_q_x = muDoubleScalarSign(c26_q_x);
  c26_d_A = ((c26_b_T_us4.rr + c26_b_T_s4.rr) - c26_b_F_xv4.rr *
             c26_b_Par.Veh.Rw) - c26_q_x * c26_b_F_z4.rr * c26_b_Par.Veh.RRC *
    c26_b_Par.Veh.Rw;
  c26_d_B = c26_Jw;
  c26_r_x = c26_d_A;
  c26_m_y = c26_d_B;
  c26_s_x = c26_r_x;
  c26_n_y = c26_m_y;
  c26_t_x = c26_s_x;
  c26_o_y = c26_n_y;
  c26_p_y = c26_t_x / c26_o_y;
  c26_b_derw_w4.rr = c26_p_y;
  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, -10);
  _SFD_SYMBOL_SCOPE_POP();
  *(real_T *)&((char_T *)chartInstance->c26_derw_w4)[0] = c26_b_derw_w4.fl;
  *(real_T *)&((char_T *)chartInstance->c26_derw_w4)[8] = c26_b_derw_w4.fr;
  *(real_T *)&((char_T *)chartInstance->c26_derw_w4)[16] = c26_b_derw_w4.rl;
  *(real_T *)&((char_T *)chartInstance->c26_derw_w4)[24] = c26_b_derw_w4.rr;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 14U, chartInstance->c26_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Modified2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c26_Modified2(SFc26_Modified2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc26_Modified2(SFc26_Modified2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c26_machineNumber, uint32_T
  c26_chartNumber, uint32_T c26_instanceNumber)
{
  (void)c26_machineNumber;
  (void)c26_chartNumber;
  (void)c26_instanceNumber;
}

static const mxArray *c26_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData)
{
  const mxArray *c26_mxArrayOutData = NULL;
  c26_whl_vec4 c26_u;
  const mxArray *c26_y = NULL;
  real_T c26_b_u;
  const mxArray *c26_b_y = NULL;
  real_T c26_c_u;
  const mxArray *c26_c_y = NULL;
  real_T c26_d_u;
  const mxArray *c26_d_y = NULL;
  real_T c26_e_u;
  const mxArray *c26_e_y = NULL;
  SFc26_Modified2InstanceStruct *chartInstance;
  chartInstance = (SFc26_Modified2InstanceStruct *)chartInstanceVoid;
  c26_mxArrayOutData = NULL;
  c26_u = *(c26_whl_vec4 *)c26_inData;
  c26_y = NULL;
  sf_mex_assign(&c26_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c26_b_u = c26_u.fl;
  c26_b_y = NULL;
  sf_mex_assign(&c26_b_y, sf_mex_create("y", &c26_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c26_y, c26_b_y, "fl", "fl", 0);
  c26_c_u = c26_u.fr;
  c26_c_y = NULL;
  sf_mex_assign(&c26_c_y, sf_mex_create("y", &c26_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c26_y, c26_c_y, "fr", "fr", 0);
  c26_d_u = c26_u.rl;
  c26_d_y = NULL;
  sf_mex_assign(&c26_d_y, sf_mex_create("y", &c26_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c26_y, c26_d_y, "rl", "rl", 0);
  c26_e_u = c26_u.rr;
  c26_e_y = NULL;
  sf_mex_assign(&c26_e_y, sf_mex_create("y", &c26_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c26_y, c26_e_y, "rr", "rr", 0);
  sf_mex_assign(&c26_mxArrayOutData, c26_y, false);
  return c26_mxArrayOutData;
}

static c26_whl_vec4 c26_emlrt_marshallIn(SFc26_Modified2InstanceStruct
  *chartInstance, const mxArray *c26_b_derw_w4, const char_T *c26_identifier)
{
  c26_whl_vec4 c26_y;
  emlrtMsgIdentifier c26_thisId;
  c26_thisId.fIdentifier = c26_identifier;
  c26_thisId.fParent = NULL;
  c26_y = c26_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c26_b_derw_w4),
    &c26_thisId);
  sf_mex_destroy(&c26_b_derw_w4);
  return c26_y;
}

static c26_whl_vec4 c26_b_emlrt_marshallIn(SFc26_Modified2InstanceStruct
  *chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId)
{
  c26_whl_vec4 c26_y;
  emlrtMsgIdentifier c26_thisId;
  static const char * c26_fieldNames[4] = { "fl", "fr", "rl", "rr" };

  c26_thisId.fParent = c26_parentId;
  sf_mex_check_struct(c26_parentId, c26_u, 4, c26_fieldNames, 0U, NULL);
  c26_thisId.fIdentifier = "fl";
  c26_y.fl = c26_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c26_u, "fl", "fl", 0)), &c26_thisId);
  c26_thisId.fIdentifier = "fr";
  c26_y.fr = c26_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c26_u, "fr", "fr", 0)), &c26_thisId);
  c26_thisId.fIdentifier = "rl";
  c26_y.rl = c26_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c26_u, "rl", "rl", 0)), &c26_thisId);
  c26_thisId.fIdentifier = "rr";
  c26_y.rr = c26_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c26_u, "rr", "rr", 0)), &c26_thisId);
  sf_mex_destroy(&c26_u);
  return c26_y;
}

static real_T c26_c_emlrt_marshallIn(SFc26_Modified2InstanceStruct
  *chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId)
{
  real_T c26_y;
  real_T c26_d0;
  (void)chartInstance;
  sf_mex_import(c26_parentId, sf_mex_dup(c26_u), &c26_d0, 1, 0, 0U, 0, 0U, 0);
  c26_y = c26_d0;
  sf_mex_destroy(&c26_u);
  return c26_y;
}

static void c26_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c26_mxArrayInData, const char_T *c26_varName, void *c26_outData)
{
  const mxArray *c26_b_derw_w4;
  const char_T *c26_identifier;
  emlrtMsgIdentifier c26_thisId;
  c26_whl_vec4 c26_y;
  SFc26_Modified2InstanceStruct *chartInstance;
  chartInstance = (SFc26_Modified2InstanceStruct *)chartInstanceVoid;
  c26_b_derw_w4 = sf_mex_dup(c26_mxArrayInData);
  c26_identifier = c26_varName;
  c26_thisId.fIdentifier = c26_identifier;
  c26_thisId.fParent = NULL;
  c26_y = c26_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c26_b_derw_w4),
    &c26_thisId);
  sf_mex_destroy(&c26_b_derw_w4);
  *(c26_whl_vec4 *)c26_outData = c26_y;
  sf_mex_destroy(&c26_mxArrayInData);
}

static const mxArray *c26_b_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData)
{
  const mxArray *c26_mxArrayOutData;
  c26_struct_iBlsPBO3AGnt69vDoTx5zD c26_u;
  const mxArray *c26_y = NULL;
  c26_struct_Nst2vGTExxHsg85EUOj9EH c26_b_u;
  const mxArray *c26_b_y = NULL;
  real_T c26_c_u;
  const mxArray *c26_c_y = NULL;
  c26_struct_HhckT6rntEraqECYVIDvCC c26_d_u;
  const mxArray *c26_d_y = NULL;
  real_T c26_e_u;
  const mxArray *c26_e_y = NULL;
  real_T c26_f_u;
  const mxArray *c26_f_y = NULL;
  const mxArray *c26_g_y = NULL;
  real_T c26_g_u;
  const mxArray *c26_h_y = NULL;
  real_T c26_h_u;
  const mxArray *c26_i_y = NULL;
  const mxArray *c26_j_y = NULL;
  real_T c26_i_u;
  const mxArray *c26_k_y = NULL;
  real_T c26_j_u;
  const mxArray *c26_l_y = NULL;
  const mxArray *c26_m_y = NULL;
  real_T c26_k_u;
  const mxArray *c26_n_y = NULL;
  real_T c26_l_u;
  const mxArray *c26_o_y = NULL;
  const mxArray *c26_p_y = NULL;
  real_T c26_m_u;
  const mxArray *c26_q_y = NULL;
  real_T c26_n_u;
  const mxArray *c26_r_y = NULL;
  real_T c26_o_u;
  const mxArray *c26_s_y = NULL;
  c26_struct_ZCmOWPuqBDw16FSOVVD00 c26_p_u;
  const mxArray *c26_t_y = NULL;
  real_T c26_q_u;
  const mxArray *c26_u_y = NULL;
  real_T c26_r_u;
  const mxArray *c26_v_y = NULL;
  real_T c26_s_u;
  const mxArray *c26_w_y = NULL;
  real_T c26_t_u;
  const mxArray *c26_x_y = NULL;
  real_T c26_u_u;
  const mxArray *c26_y_y = NULL;
  real_T c26_v_u;
  const mxArray *c26_ab_y = NULL;
  real_T c26_w_u;
  const mxArray *c26_bb_y = NULL;
  real_T c26_x_u;
  const mxArray *c26_cb_y = NULL;
  real_T c26_y_u;
  const mxArray *c26_db_y = NULL;
  real_T c26_ab_u;
  const mxArray *c26_eb_y = NULL;
  real_T c26_bb_u;
  const mxArray *c26_fb_y = NULL;
  int32_T c26_i0;
  real_T c26_cb_u[4];
  const mxArray *c26_gb_y = NULL;
  real_T c26_db_u;
  const mxArray *c26_hb_y = NULL;
  c26_struct_ZKAzdrl7umDGJoC14aoVKC c26_eb_u;
  const mxArray *c26_ib_y = NULL;
  int32_T c26_i1;
  real_T c26_fb_u[3];
  const mxArray *c26_jb_y = NULL;
  int32_T c26_i2;
  real_T c26_gb_u[3];
  const mxArray *c26_kb_y = NULL;
  int32_T c26_i3;
  real_T c26_hb_u[3];
  const mxArray *c26_lb_y = NULL;
  int32_T c26_i4;
  real_T c26_ib_u[3];
  const mxArray *c26_mb_y = NULL;
  const mxArray *c26_nb_y = NULL;
  int32_T c26_i5;
  real_T c26_jb_u[3];
  const mxArray *c26_ob_y = NULL;
  int32_T c26_i6;
  real_T c26_kb_u[3];
  const mxArray *c26_pb_y = NULL;
  int32_T c26_i7;
  real_T c26_lb_u[3];
  const mxArray *c26_qb_y = NULL;
  int32_T c26_i8;
  real_T c26_mb_u[3];
  const mxArray *c26_rb_y = NULL;
  const mxArray *c26_sb_y = NULL;
  int32_T c26_i9;
  real_T c26_nb_u[3];
  const mxArray *c26_tb_y = NULL;
  int32_T c26_i10;
  real_T c26_ob_u[3];
  const mxArray *c26_ub_y = NULL;
  int32_T c26_i11;
  real_T c26_pb_u[3];
  const mxArray *c26_vb_y = NULL;
  int32_T c26_i12;
  real_T c26_qb_u[3];
  const mxArray *c26_wb_y = NULL;
  const mxArray *c26_xb_y = NULL;
  int32_T c26_i13;
  real_T c26_rb_u[3];
  const mxArray *c26_yb_y = NULL;
  int32_T c26_i14;
  real_T c26_sb_u[3];
  const mxArray *c26_ac_y = NULL;
  int32_T c26_i15;
  real_T c26_tb_u[3];
  const mxArray *c26_bc_y = NULL;
  int32_T c26_i16;
  real_T c26_ub_u[3];
  const mxArray *c26_cc_y = NULL;
  real_T c26_vb_u;
  const mxArray *c26_dc_y = NULL;
  real_T c26_wb_u;
  const mxArray *c26_ec_y = NULL;
  real_T c26_xb_u;
  const mxArray *c26_fc_y = NULL;
  real_T c26_yb_u;
  const mxArray *c26_gc_y = NULL;
  real_T c26_ac_u;
  const mxArray *c26_hc_y = NULL;
  real_T c26_bc_u;
  const mxArray *c26_ic_y = NULL;
  real_T c26_cc_u;
  const mxArray *c26_jc_y = NULL;
  real_T c26_dc_u;
  const mxArray *c26_kc_y = NULL;
  real_T c26_ec_u;
  const mxArray *c26_lc_y = NULL;
  real_T c26_fc_u;
  const mxArray *c26_mc_y = NULL;
  real_T c26_gc_u;
  const mxArray *c26_nc_y = NULL;
  real_T c26_hc_u;
  const mxArray *c26_oc_y = NULL;
  c26_struct_r4FNviKwHfdhB8nQjvQv9 c26_ic_u;
  const mxArray *c26_pc_y = NULL;
  real_T c26_jc_u;
  const mxArray *c26_qc_y = NULL;
  c26_struct_Y9F1qlBi9AhssksPwemA4G c26_kc_u;
  const mxArray *c26_rc_y = NULL;
  real_T c26_lc_u;
  const mxArray *c26_sc_y = NULL;
  real_T c26_mc_u;
  const mxArray *c26_tc_y = NULL;
  real_T c26_nc_u;
  const mxArray *c26_uc_y = NULL;
  SFc26_Modified2InstanceStruct *chartInstance;
  chartInstance = (SFc26_Modified2InstanceStruct *)chartInstanceVoid;
  c26_mxArrayOutData = NULL;
  c26_mxArrayOutData = NULL;
  c26_u = *(c26_struct_iBlsPBO3AGnt69vDoTx5zD *)c26_inData;
  c26_y = NULL;
  sf_mex_assign(&c26_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c26_b_u = c26_u.Env;
  c26_b_y = NULL;
  sf_mex_assign(&c26_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c26_c_u = c26_b_u.g;
  c26_c_y = NULL;
  sf_mex_assign(&c26_c_y, sf_mex_create("y", &c26_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c26_b_y, c26_c_y, "g", "g", 0);
  c26_d_u = c26_b_u.left1;
  c26_d_y = NULL;
  sf_mex_assign(&c26_d_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c26_e_u = c26_d_u.x;
  c26_e_y = NULL;
  sf_mex_assign(&c26_e_y, sf_mex_create("y", &c26_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c26_d_y, c26_e_y, "x", "x", 0);
  c26_f_u = c26_d_u.y;
  c26_f_y = NULL;
  sf_mex_assign(&c26_f_y, sf_mex_create("y", &c26_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c26_d_y, c26_f_y, "y", "y", 0);
  sf_mex_addfield(c26_b_y, c26_d_y, "left1", "left1", 0);
  c26_d_u = c26_b_u.right1;
  c26_g_y = NULL;
  sf_mex_assign(&c26_g_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c26_g_u = c26_d_u.x;
  c26_h_y = NULL;
  sf_mex_assign(&c26_h_y, sf_mex_create("y", &c26_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c26_g_y, c26_h_y, "x", "x", 0);
  c26_h_u = c26_d_u.y;
  c26_i_y = NULL;
  sf_mex_assign(&c26_i_y, sf_mex_create("y", &c26_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c26_g_y, c26_i_y, "y", "y", 0);
  sf_mex_addfield(c26_b_y, c26_g_y, "right1", "right1", 0);
  c26_d_u = c26_b_u.right2;
  c26_j_y = NULL;
  sf_mex_assign(&c26_j_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c26_i_u = c26_d_u.x;
  c26_k_y = NULL;
  sf_mex_assign(&c26_k_y, sf_mex_create("y", &c26_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c26_j_y, c26_k_y, "x", "x", 0);
  c26_j_u = c26_d_u.y;
  c26_l_y = NULL;
  sf_mex_assign(&c26_l_y, sf_mex_create("y", &c26_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c26_j_y, c26_l_y, "y", "y", 0);
  sf_mex_addfield(c26_b_y, c26_j_y, "right2", "right2", 0);
  c26_d_u = c26_b_u.left2;
  c26_m_y = NULL;
  sf_mex_assign(&c26_m_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c26_k_u = c26_d_u.x;
  c26_n_y = NULL;
  sf_mex_assign(&c26_n_y, sf_mex_create("y", &c26_k_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c26_m_y, c26_n_y, "x", "x", 0);
  c26_l_u = c26_d_u.y;
  c26_o_y = NULL;
  sf_mex_assign(&c26_o_y, sf_mex_create("y", &c26_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c26_m_y, c26_o_y, "y", "y", 0);
  sf_mex_addfield(c26_b_y, c26_m_y, "left2", "left2", 0);
  c26_d_u = c26_b_u.right3;
  c26_p_y = NULL;
  sf_mex_assign(&c26_p_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c26_m_u = c26_d_u.x;
  c26_q_y = NULL;
  sf_mex_assign(&c26_q_y, sf_mex_create("y", &c26_m_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c26_p_y, c26_q_y, "x", "x", 0);
  c26_n_u = c26_d_u.y;
  c26_r_y = NULL;
  sf_mex_assign(&c26_r_y, sf_mex_create("y", &c26_n_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c26_p_y, c26_r_y, "y", "y", 0);
  sf_mex_addfield(c26_b_y, c26_p_y, "right3", "right3", 0);
  c26_o_u = c26_b_u.mu;
  c26_s_y = NULL;
  sf_mex_assign(&c26_s_y, sf_mex_create("y", &c26_o_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c26_b_y, c26_s_y, "mu", "mu", 0);
  sf_mex_addfield(c26_y, c26_b_y, "Env", "Env", 0);
  c26_p_u = c26_u.Veh;
  c26_t_y = NULL;
  sf_mex_assign(&c26_t_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c26_q_u = c26_p_u.m;
  c26_u_y = NULL;
  sf_mex_assign(&c26_u_y, sf_mex_create("y", &c26_q_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c26_t_y, c26_u_y, "m", "m", 0);
  c26_r_u = c26_p_u.Jz;
  c26_v_y = NULL;
  sf_mex_assign(&c26_v_y, sf_mex_create("y", &c26_r_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c26_t_y, c26_v_y, "Jz", "Jz", 0);
  c26_s_u = c26_p_u.m_sprung;
  c26_w_y = NULL;
  sf_mex_assign(&c26_w_y, sf_mex_create("y", &c26_s_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c26_t_y, c26_w_y, "m_sprung", "m_sprung", 0);
  c26_t_u = c26_p_u.Jx_sprung;
  c26_x_y = NULL;
  sf_mex_assign(&c26_x_y, sf_mex_create("y", &c26_t_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c26_t_y, c26_x_y, "Jx_sprung", "Jx_sprung", 0);
  c26_u_u = c26_p_u.Jy_sprung;
  c26_y_y = NULL;
  sf_mex_assign(&c26_y_y, sf_mex_create("y", &c26_u_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c26_t_y, c26_y_y, "Jy_sprung", "Jy_sprung", 0);
  c26_v_u = c26_p_u.lf;
  c26_ab_y = NULL;
  sf_mex_assign(&c26_ab_y, sf_mex_create("y", &c26_v_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c26_t_y, c26_ab_y, "lf", "lf", 0);
  c26_w_u = c26_p_u.lr;
  c26_bb_y = NULL;
  sf_mex_assign(&c26_bb_y, sf_mex_create("y", &c26_w_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c26_t_y, c26_bb_y, "lr", "lr", 0);
  c26_x_u = c26_p_u.L;
  c26_cb_y = NULL;
  sf_mex_assign(&c26_cb_y, sf_mex_create("y", &c26_x_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c26_t_y, c26_cb_y, "L", "L", 0);
  c26_y_u = c26_p_u.TrackWidth;
  c26_db_y = NULL;
  sf_mex_assign(&c26_db_y, sf_mex_create("y", &c26_y_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c26_t_y, c26_db_y, "TrackWidth", "TrackWidth", 0);
  c26_ab_u = c26_p_u.h;
  c26_eb_y = NULL;
  sf_mex_assign(&c26_eb_y, sf_mex_create("y", &c26_ab_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c26_t_y, c26_eb_y, "h", "h", 0);
  c26_bb_u = c26_p_u.HalfRohACd;
  c26_fb_y = NULL;
  sf_mex_assign(&c26_fb_y, sf_mex_create("y", &c26_bb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c26_t_y, c26_fb_y, "HalfRohACd", "HalfRohACd", 0);
  for (c26_i0 = 0; c26_i0 < 4; c26_i0++) {
    c26_cb_u[c26_i0] = c26_p_u.F_z4_static[c26_i0];
  }

  c26_gb_y = NULL;
  sf_mex_assign(&c26_gb_y, sf_mex_create("y", c26_cb_u, 0, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_addfield(c26_t_y, c26_gb_y, "F_z4_static", "F_z4_static", 0);
  c26_db_u = c26_p_u.Rw;
  c26_hb_y = NULL;
  sf_mex_assign(&c26_hb_y, sf_mex_create("y", &c26_db_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c26_t_y, c26_hb_y, "Rw", "Rw", 0);
  c26_eb_u = c26_p_u.r_long;
  c26_ib_y = NULL;
  sf_mex_assign(&c26_ib_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c26_i1 = 0; c26_i1 < 3; c26_i1++) {
    c26_fb_u[c26_i1] = c26_eb_u.fl[c26_i1];
  }

  c26_jb_y = NULL;
  sf_mex_assign(&c26_jb_y, sf_mex_create("y", c26_fb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c26_ib_y, c26_jb_y, "fl", "fl", 0);
  for (c26_i2 = 0; c26_i2 < 3; c26_i2++) {
    c26_gb_u[c26_i2] = c26_eb_u.fr[c26_i2];
  }

  c26_kb_y = NULL;
  sf_mex_assign(&c26_kb_y, sf_mex_create("y", c26_gb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c26_ib_y, c26_kb_y, "fr", "fr", 0);
  for (c26_i3 = 0; c26_i3 < 3; c26_i3++) {
    c26_hb_u[c26_i3] = c26_eb_u.rl[c26_i3];
  }

  c26_lb_y = NULL;
  sf_mex_assign(&c26_lb_y, sf_mex_create("y", c26_hb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c26_ib_y, c26_lb_y, "rl", "rl", 0);
  for (c26_i4 = 0; c26_i4 < 3; c26_i4++) {
    c26_ib_u[c26_i4] = c26_eb_u.rr[c26_i4];
  }

  c26_mb_y = NULL;
  sf_mex_assign(&c26_mb_y, sf_mex_create("y", c26_ib_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c26_ib_y, c26_mb_y, "rr", "rr", 0);
  sf_mex_addfield(c26_t_y, c26_ib_y, "r_long", "r_long", 0);
  c26_eb_u = c26_p_u.r_lat;
  c26_nb_y = NULL;
  sf_mex_assign(&c26_nb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c26_i5 = 0; c26_i5 < 3; c26_i5++) {
    c26_jb_u[c26_i5] = c26_eb_u.fl[c26_i5];
  }

  c26_ob_y = NULL;
  sf_mex_assign(&c26_ob_y, sf_mex_create("y", c26_jb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c26_nb_y, c26_ob_y, "fl", "fl", 0);
  for (c26_i6 = 0; c26_i6 < 3; c26_i6++) {
    c26_kb_u[c26_i6] = c26_eb_u.fr[c26_i6];
  }

  c26_pb_y = NULL;
  sf_mex_assign(&c26_pb_y, sf_mex_create("y", c26_kb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c26_nb_y, c26_pb_y, "fr", "fr", 0);
  for (c26_i7 = 0; c26_i7 < 3; c26_i7++) {
    c26_lb_u[c26_i7] = c26_eb_u.rl[c26_i7];
  }

  c26_qb_y = NULL;
  sf_mex_assign(&c26_qb_y, sf_mex_create("y", c26_lb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c26_nb_y, c26_qb_y, "rl", "rl", 0);
  for (c26_i8 = 0; c26_i8 < 3; c26_i8++) {
    c26_mb_u[c26_i8] = c26_eb_u.rr[c26_i8];
  }

  c26_rb_y = NULL;
  sf_mex_assign(&c26_rb_y, sf_mex_create("y", c26_mb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c26_nb_y, c26_rb_y, "rr", "rr", 0);
  sf_mex_addfield(c26_t_y, c26_nb_y, "r_lat", "r_lat", 0);
  c26_eb_u = c26_p_u.r_lever;
  c26_sb_y = NULL;
  sf_mex_assign(&c26_sb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c26_i9 = 0; c26_i9 < 3; c26_i9++) {
    c26_nb_u[c26_i9] = c26_eb_u.fl[c26_i9];
  }

  c26_tb_y = NULL;
  sf_mex_assign(&c26_tb_y, sf_mex_create("y", c26_nb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c26_sb_y, c26_tb_y, "fl", "fl", 0);
  for (c26_i10 = 0; c26_i10 < 3; c26_i10++) {
    c26_ob_u[c26_i10] = c26_eb_u.fr[c26_i10];
  }

  c26_ub_y = NULL;
  sf_mex_assign(&c26_ub_y, sf_mex_create("y", c26_ob_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c26_sb_y, c26_ub_y, "fr", "fr", 0);
  for (c26_i11 = 0; c26_i11 < 3; c26_i11++) {
    c26_pb_u[c26_i11] = c26_eb_u.rl[c26_i11];
  }

  c26_vb_y = NULL;
  sf_mex_assign(&c26_vb_y, sf_mex_create("y", c26_pb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c26_sb_y, c26_vb_y, "rl", "rl", 0);
  for (c26_i12 = 0; c26_i12 < 3; c26_i12++) {
    c26_qb_u[c26_i12] = c26_eb_u.rr[c26_i12];
  }

  c26_wb_y = NULL;
  sf_mex_assign(&c26_wb_y, sf_mex_create("y", c26_qb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c26_sb_y, c26_wb_y, "rr", "rr", 0);
  sf_mex_addfield(c26_t_y, c26_sb_y, "r_lever", "r_lever", 0);
  c26_eb_u = c26_p_u.r_pivot;
  c26_xb_y = NULL;
  sf_mex_assign(&c26_xb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c26_i13 = 0; c26_i13 < 3; c26_i13++) {
    c26_rb_u[c26_i13] = c26_eb_u.fl[c26_i13];
  }

  c26_yb_y = NULL;
  sf_mex_assign(&c26_yb_y, sf_mex_create("y", c26_rb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c26_xb_y, c26_yb_y, "fl", "fl", 0);
  for (c26_i14 = 0; c26_i14 < 3; c26_i14++) {
    c26_sb_u[c26_i14] = c26_eb_u.fr[c26_i14];
  }

  c26_ac_y = NULL;
  sf_mex_assign(&c26_ac_y, sf_mex_create("y", c26_sb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c26_xb_y, c26_ac_y, "fr", "fr", 0);
  for (c26_i15 = 0; c26_i15 < 3; c26_i15++) {
    c26_tb_u[c26_i15] = c26_eb_u.rl[c26_i15];
  }

  c26_bc_y = NULL;
  sf_mex_assign(&c26_bc_y, sf_mex_create("y", c26_tb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c26_xb_y, c26_bc_y, "rl", "rl", 0);
  for (c26_i16 = 0; c26_i16 < 3; c26_i16++) {
    c26_ub_u[c26_i16] = c26_eb_u.rr[c26_i16];
  }

  c26_cc_y = NULL;
  sf_mex_assign(&c26_cc_y, sf_mex_create("y", c26_ub_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c26_xb_y, c26_cc_y, "rr", "rr", 0);
  sf_mex_addfield(c26_t_y, c26_xb_y, "r_pivot", "r_pivot", 0);
  c26_vb_u = c26_p_u.cw;
  c26_dc_y = NULL;
  sf_mex_assign(&c26_dc_y, sf_mex_create("y", &c26_vb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c26_t_y, c26_dc_y, "cw", "cw", 0);
  c26_wb_u = c26_p_u.carb_f;
  c26_ec_y = NULL;
  sf_mex_assign(&c26_ec_y, sf_mex_create("y", &c26_wb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c26_t_y, c26_ec_y, "carb_f", "carb_f", 0);
  c26_xb_u = c26_p_u.carb_r;
  c26_fc_y = NULL;
  sf_mex_assign(&c26_fc_y, sf_mex_create("y", &c26_xb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c26_t_y, c26_fc_y, "carb_r", "carb_r", 0);
  c26_yb_u = c26_p_u.dw;
  c26_gc_y = NULL;
  sf_mex_assign(&c26_gc_y, sf_mex_create("y", &c26_yb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c26_t_y, c26_gc_y, "dw", "dw", 0);
  c26_ac_u = c26_p_u.Jw;
  c26_hc_y = NULL;
  sf_mex_assign(&c26_hc_y, sf_mex_create("y", &c26_ac_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c26_t_y, c26_hc_y, "Jw", "Jw", 0);
  c26_bc_u = c26_p_u.C0;
  c26_ic_y = NULL;
  sf_mex_assign(&c26_ic_y, sf_mex_create("y", &c26_bc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c26_t_y, c26_ic_y, "C0", "C0", 0);
  c26_cc_u = c26_p_u.RelaxLength;
  c26_jc_y = NULL;
  sf_mex_assign(&c26_jc_y, sf_mex_create("y", &c26_cc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c26_t_y, c26_jc_y, "RelaxLength", "RelaxLength", 0);
  c26_dc_u = c26_p_u.RRC;
  c26_kc_y = NULL;
  sf_mex_assign(&c26_kc_y, sf_mex_create("y", &c26_dc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c26_t_y, c26_kc_y, "RRC", "RRC", 0);
  c26_ec_u = c26_p_u.Pmax;
  c26_lc_y = NULL;
  sf_mex_assign(&c26_lc_y, sf_mex_create("y", &c26_ec_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c26_t_y, c26_lc_y, "Pmax", "Pmax", 0);
  c26_fc_u = c26_p_u.PropDistrFrnt;
  c26_mc_y = NULL;
  sf_mex_assign(&c26_mc_y, sf_mex_create("y", &c26_fc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c26_t_y, c26_mc_y, "PropDistrFrnt", "PropDistrFrnt", 0);
  c26_gc_u = c26_p_u.BrkDistrFrnt;
  c26_nc_y = NULL;
  sf_mex_assign(&c26_nc_y, sf_mex_create("y", &c26_gc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c26_t_y, c26_nc_y, "BrkDistrFrnt", "BrkDistrFrnt", 0);
  c26_hc_u = c26_p_u.SteRatio;
  c26_oc_y = NULL;
  sf_mex_assign(&c26_oc_y, sf_mex_create("y", &c26_hc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c26_t_y, c26_oc_y, "SteRatio", "SteRatio", 0);
  sf_mex_addfield(c26_y, c26_t_y, "Veh", "Veh", 0);
  c26_ic_u = c26_u.Drvr;
  c26_pc_y = NULL;
  sf_mex_assign(&c26_pc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c26_jc_u = c26_ic_u.v_set;
  c26_qc_y = NULL;
  sf_mex_assign(&c26_qc_y, sf_mex_create("y", &c26_jc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c26_pc_y, c26_qc_y, "v_set", "v_set", 0);
  sf_mex_addfield(c26_y, c26_pc_y, "Drvr", "Drvr", 0);
  c26_kc_u = c26_u.Init;
  c26_rc_y = NULL;
  sf_mex_assign(&c26_rc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c26_lc_u = c26_kc_u.v_x;
  c26_sc_y = NULL;
  sf_mex_assign(&c26_sc_y, sf_mex_create("y", &c26_lc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c26_rc_y, c26_sc_y, "v_x", "v_x", 0);
  c26_mc_u = c26_kc_u.F_fz;
  c26_tc_y = NULL;
  sf_mex_assign(&c26_tc_y, sf_mex_create("y", &c26_mc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c26_rc_y, c26_tc_y, "F_fz", "F_fz", 0);
  c26_nc_u = c26_kc_u.F_rz;
  c26_uc_y = NULL;
  sf_mex_assign(&c26_uc_y, sf_mex_create("y", &c26_nc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c26_rc_y, c26_uc_y, "F_rz", "F_rz", 0);
  sf_mex_addfield(c26_y, c26_rc_y, "Init", "Init", 0);
  sf_mex_assign(&c26_mxArrayOutData, c26_y, false);
  return c26_mxArrayOutData;
}

static void c26_d_emlrt_marshallIn(SFc26_Modified2InstanceStruct *chartInstance,
  const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId,
  c26_struct_iBlsPBO3AGnt69vDoTx5zD *c26_y)
{
  emlrtMsgIdentifier c26_thisId;
  static const char * c26_fieldNames[4] = { "Env", "Veh", "Drvr", "Init" };

  c26_thisId.fParent = c26_parentId;
  sf_mex_check_struct(c26_parentId, c26_u, 4, c26_fieldNames, 0U, NULL);
  c26_thisId.fIdentifier = "Env";
  c26_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c26_u, "Env",
    "Env", 0)), &c26_thisId, &c26_y->Env);
  c26_thisId.fIdentifier = "Veh";
  c26_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c26_u, "Veh",
    "Veh", 0)), &c26_thisId, &c26_y->Veh);
  c26_thisId.fIdentifier = "Drvr";
  c26_y->Drvr = c26_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c26_u, "Drvr", "Drvr", 0)), &c26_thisId);
  c26_thisId.fIdentifier = "Init";
  c26_y->Init = c26_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c26_u, "Init", "Init", 0)), &c26_thisId);
  sf_mex_destroy(&c26_u);
}

static void c26_e_emlrt_marshallIn(SFc26_Modified2InstanceStruct *chartInstance,
  const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId,
  c26_struct_Nst2vGTExxHsg85EUOj9EH *c26_y)
{
  emlrtMsgIdentifier c26_thisId;
  static const char * c26_fieldNames[7] = { "g", "left1", "right1", "right2",
    "left2", "right3", "mu" };

  c26_thisId.fParent = c26_parentId;
  sf_mex_check_struct(c26_parentId, c26_u, 7, c26_fieldNames, 0U, NULL);
  c26_thisId.fIdentifier = "g";
  c26_y->g = c26_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c26_u, "g", "g", 0)), &c26_thisId);
  c26_thisId.fIdentifier = "left1";
  c26_y->left1 = c26_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c26_u, "left1", "left1", 0)), &c26_thisId);
  c26_thisId.fIdentifier = "right1";
  c26_y->right1 = c26_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c26_u, "right1", "right1", 0)), &c26_thisId);
  c26_thisId.fIdentifier = "right2";
  c26_y->right2 = c26_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c26_u, "right2", "right2", 0)), &c26_thisId);
  c26_thisId.fIdentifier = "left2";
  c26_y->left2 = c26_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c26_u, "left2", "left2", 0)), &c26_thisId);
  c26_thisId.fIdentifier = "right3";
  c26_y->right3 = c26_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c26_u, "right3", "right3", 0)), &c26_thisId);
  c26_thisId.fIdentifier = "mu";
  c26_y->mu = c26_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c26_u, "mu", "mu", 0)), &c26_thisId);
  sf_mex_destroy(&c26_u);
}

static c26_struct_HhckT6rntEraqECYVIDvCC c26_f_emlrt_marshallIn
  (SFc26_Modified2InstanceStruct *chartInstance, const mxArray *c26_u, const
   emlrtMsgIdentifier *c26_parentId)
{
  c26_struct_HhckT6rntEraqECYVIDvCC c26_y;
  emlrtMsgIdentifier c26_thisId;
  static const char * c26_fieldNames[2] = { "x", "y" };

  c26_thisId.fParent = c26_parentId;
  sf_mex_check_struct(c26_parentId, c26_u, 2, c26_fieldNames, 0U, NULL);
  c26_thisId.fIdentifier = "x";
  c26_y.x = c26_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c26_u, "x", "x", 0)), &c26_thisId);
  c26_thisId.fIdentifier = "y";
  c26_y.y = c26_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c26_u, "y", "y", 0)), &c26_thisId);
  sf_mex_destroy(&c26_u);
  return c26_y;
}

static void c26_g_emlrt_marshallIn(SFc26_Modified2InstanceStruct *chartInstance,
  const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId,
  c26_struct_ZCmOWPuqBDw16FSOVVD00 *c26_y)
{
  emlrtMsgIdentifier c26_thisId;
  static const char * c26_fieldNames[29] = { "m", "Jz", "m_sprung", "Jx_sprung",
    "Jy_sprung", "lf", "lr", "L", "TrackWidth", "h", "HalfRohACd", "F_z4_static",
    "Rw", "r_long", "r_lat", "r_lever", "r_pivot", "cw", "carb_f", "carb_r",
    "dw", "Jw", "C0", "RelaxLength", "RRC", "Pmax", "PropDistrFrnt",
    "BrkDistrFrnt", "SteRatio" };

  c26_thisId.fParent = c26_parentId;
  sf_mex_check_struct(c26_parentId, c26_u, 29, c26_fieldNames, 0U, NULL);
  c26_thisId.fIdentifier = "m";
  c26_y->m = c26_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c26_u, "m", "m", 0)), &c26_thisId);
  c26_thisId.fIdentifier = "Jz";
  c26_y->Jz = c26_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c26_u, "Jz", "Jz", 0)), &c26_thisId);
  c26_thisId.fIdentifier = "m_sprung";
  c26_y->m_sprung = c26_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c26_u, "m_sprung", "m_sprung", 0)), &c26_thisId);
  c26_thisId.fIdentifier = "Jx_sprung";
  c26_y->Jx_sprung = c26_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c26_u, "Jx_sprung", "Jx_sprung", 0)), &c26_thisId);
  c26_thisId.fIdentifier = "Jy_sprung";
  c26_y->Jy_sprung = c26_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c26_u, "Jy_sprung", "Jy_sprung", 0)), &c26_thisId);
  c26_thisId.fIdentifier = "lf";
  c26_y->lf = c26_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c26_u, "lf", "lf", 0)), &c26_thisId);
  c26_thisId.fIdentifier = "lr";
  c26_y->lr = c26_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c26_u, "lr", "lr", 0)), &c26_thisId);
  c26_thisId.fIdentifier = "L";
  c26_y->L = c26_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c26_u, "L", "L", 0)), &c26_thisId);
  c26_thisId.fIdentifier = "TrackWidth";
  c26_y->TrackWidth = c26_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c26_u, "TrackWidth", "TrackWidth", 0)), &c26_thisId);
  c26_thisId.fIdentifier = "h";
  c26_y->h = c26_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c26_u, "h", "h", 0)), &c26_thisId);
  c26_thisId.fIdentifier = "HalfRohACd";
  c26_y->HalfRohACd = c26_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c26_u, "HalfRohACd", "HalfRohACd", 0)), &c26_thisId);
  c26_thisId.fIdentifier = "F_z4_static";
  c26_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c26_u,
    "F_z4_static", "F_z4_static", 0)), &c26_thisId, c26_y->F_z4_static);
  c26_thisId.fIdentifier = "Rw";
  c26_y->Rw = c26_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c26_u, "Rw", "Rw", 0)), &c26_thisId);
  c26_thisId.fIdentifier = "r_long";
  c26_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c26_u,
    "r_long", "r_long", 0)), &c26_thisId, &c26_y->r_long);
  c26_thisId.fIdentifier = "r_lat";
  c26_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c26_u,
    "r_lat", "r_lat", 0)), &c26_thisId, &c26_y->r_lat);
  c26_thisId.fIdentifier = "r_lever";
  c26_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c26_u,
    "r_lever", "r_lever", 0)), &c26_thisId, &c26_y->r_lever);
  c26_thisId.fIdentifier = "r_pivot";
  c26_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c26_u,
    "r_pivot", "r_pivot", 0)), &c26_thisId, &c26_y->r_pivot);
  c26_thisId.fIdentifier = "cw";
  c26_y->cw = c26_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c26_u, "cw", "cw", 0)), &c26_thisId);
  c26_thisId.fIdentifier = "carb_f";
  c26_y->carb_f = c26_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c26_u, "carb_f", "carb_f", 0)), &c26_thisId);
  c26_thisId.fIdentifier = "carb_r";
  c26_y->carb_r = c26_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c26_u, "carb_r", "carb_r", 0)), &c26_thisId);
  c26_thisId.fIdentifier = "dw";
  c26_y->dw = c26_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c26_u, "dw", "dw", 0)), &c26_thisId);
  c26_thisId.fIdentifier = "Jw";
  c26_y->Jw = c26_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c26_u, "Jw", "Jw", 0)), &c26_thisId);
  c26_thisId.fIdentifier = "C0";
  c26_y->C0 = c26_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c26_u, "C0", "C0", 0)), &c26_thisId);
  c26_thisId.fIdentifier = "RelaxLength";
  c26_y->RelaxLength = c26_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c26_u, "RelaxLength", "RelaxLength", 0)), &c26_thisId);
  c26_thisId.fIdentifier = "RRC";
  c26_y->RRC = c26_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c26_u, "RRC", "RRC", 0)), &c26_thisId);
  c26_thisId.fIdentifier = "Pmax";
  c26_y->Pmax = c26_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c26_u, "Pmax", "Pmax", 0)), &c26_thisId);
  c26_thisId.fIdentifier = "PropDistrFrnt";
  c26_y->PropDistrFrnt = c26_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c26_u, "PropDistrFrnt", "PropDistrFrnt", 0)), &c26_thisId);
  c26_thisId.fIdentifier = "BrkDistrFrnt";
  c26_y->BrkDistrFrnt = c26_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c26_u, "BrkDistrFrnt", "BrkDistrFrnt", 0)), &c26_thisId);
  c26_thisId.fIdentifier = "SteRatio";
  c26_y->SteRatio = c26_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c26_u, "SteRatio", "SteRatio", 0)), &c26_thisId);
  sf_mex_destroy(&c26_u);
}

static void c26_h_emlrt_marshallIn(SFc26_Modified2InstanceStruct *chartInstance,
  const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId, real_T c26_y[4])
{
  real_T c26_dv0[4];
  int32_T c26_i17;
  (void)chartInstance;
  sf_mex_import(c26_parentId, sf_mex_dup(c26_u), c26_dv0, 1, 0, 0U, 1, 0U, 2, 1,
                4);
  for (c26_i17 = 0; c26_i17 < 4; c26_i17++) {
    c26_y[c26_i17] = c26_dv0[c26_i17];
  }

  sf_mex_destroy(&c26_u);
}

static void c26_i_emlrt_marshallIn(SFc26_Modified2InstanceStruct *chartInstance,
  const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId,
  c26_struct_ZKAzdrl7umDGJoC14aoVKC *c26_y)
{
  emlrtMsgIdentifier c26_thisId;
  static const char * c26_fieldNames[4] = { "fl", "fr", "rl", "rr" };

  c26_thisId.fParent = c26_parentId;
  sf_mex_check_struct(c26_parentId, c26_u, 4, c26_fieldNames, 0U, NULL);
  c26_thisId.fIdentifier = "fl";
  c26_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c26_u, "fl",
    "fl", 0)), &c26_thisId, c26_y->fl);
  c26_thisId.fIdentifier = "fr";
  c26_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c26_u, "fr",
    "fr", 0)), &c26_thisId, c26_y->fr);
  c26_thisId.fIdentifier = "rl";
  c26_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c26_u, "rl",
    "rl", 0)), &c26_thisId, c26_y->rl);
  c26_thisId.fIdentifier = "rr";
  c26_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c26_u, "rr",
    "rr", 0)), &c26_thisId, c26_y->rr);
  sf_mex_destroy(&c26_u);
}

static void c26_j_emlrt_marshallIn(SFc26_Modified2InstanceStruct *chartInstance,
  const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId, real_T c26_y[3])
{
  real_T c26_dv1[3];
  int32_T c26_i18;
  (void)chartInstance;
  sf_mex_import(c26_parentId, sf_mex_dup(c26_u), c26_dv1, 1, 0, 0U, 1, 0U, 2, 3,
                1);
  for (c26_i18 = 0; c26_i18 < 3; c26_i18++) {
    c26_y[c26_i18] = c26_dv1[c26_i18];
  }

  sf_mex_destroy(&c26_u);
}

static c26_struct_r4FNviKwHfdhB8nQjvQv9 c26_k_emlrt_marshallIn
  (SFc26_Modified2InstanceStruct *chartInstance, const mxArray *c26_u, const
   emlrtMsgIdentifier *c26_parentId)
{
  c26_struct_r4FNviKwHfdhB8nQjvQv9 c26_y;
  emlrtMsgIdentifier c26_thisId;
  static const char * c26_fieldNames[1] = { "v_set" };

  c26_thisId.fParent = c26_parentId;
  sf_mex_check_struct(c26_parentId, c26_u, 1, c26_fieldNames, 0U, NULL);
  c26_thisId.fIdentifier = "v_set";
  c26_y.v_set = c26_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c26_u, "v_set", "v_set", 0)),
    &c26_thisId);
  sf_mex_destroy(&c26_u);
  return c26_y;
}

static c26_struct_Y9F1qlBi9AhssksPwemA4G c26_l_emlrt_marshallIn
  (SFc26_Modified2InstanceStruct *chartInstance, const mxArray *c26_u, const
   emlrtMsgIdentifier *c26_parentId)
{
  c26_struct_Y9F1qlBi9AhssksPwemA4G c26_y;
  emlrtMsgIdentifier c26_thisId;
  static const char * c26_fieldNames[3] = { "v_x", "F_fz", "F_rz" };

  c26_thisId.fParent = c26_parentId;
  sf_mex_check_struct(c26_parentId, c26_u, 3, c26_fieldNames, 0U, NULL);
  c26_thisId.fIdentifier = "v_x";
  c26_y.v_x = c26_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c26_u, "v_x", "v_x", 0)), &c26_thisId);
  c26_thisId.fIdentifier = "F_fz";
  c26_y.F_fz = c26_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c26_u, "F_fz", "F_fz", 0)), &c26_thisId);
  c26_thisId.fIdentifier = "F_rz";
  c26_y.F_rz = c26_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c26_u, "F_rz", "F_rz", 0)), &c26_thisId);
  sf_mex_destroy(&c26_u);
  return c26_y;
}

static void c26_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c26_mxArrayInData, const char_T *c26_varName, void *c26_outData)
{
  const mxArray *c26_b_Par;
  const char_T *c26_identifier;
  emlrtMsgIdentifier c26_thisId;
  c26_struct_iBlsPBO3AGnt69vDoTx5zD c26_y;
  SFc26_Modified2InstanceStruct *chartInstance;
  chartInstance = (SFc26_Modified2InstanceStruct *)chartInstanceVoid;
  c26_b_Par = sf_mex_dup(c26_mxArrayInData);
  c26_identifier = c26_varName;
  c26_thisId.fIdentifier = c26_identifier;
  c26_thisId.fParent = NULL;
  c26_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c26_b_Par), &c26_thisId,
    &c26_y);
  sf_mex_destroy(&c26_b_Par);
  *(c26_struct_iBlsPBO3AGnt69vDoTx5zD *)c26_outData = c26_y;
  sf_mex_destroy(&c26_mxArrayInData);
}

static const mxArray *c26_c_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData)
{
  const mxArray *c26_mxArrayOutData = NULL;
  real_T c26_u;
  const mxArray *c26_y = NULL;
  SFc26_Modified2InstanceStruct *chartInstance;
  chartInstance = (SFc26_Modified2InstanceStruct *)chartInstanceVoid;
  c26_mxArrayOutData = NULL;
  c26_u = *(real_T *)c26_inData;
  c26_y = NULL;
  sf_mex_assign(&c26_y, sf_mex_create("y", &c26_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c26_mxArrayOutData, c26_y, false);
  return c26_mxArrayOutData;
}

static void c26_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c26_mxArrayInData, const char_T *c26_varName, void *c26_outData)
{
  const mxArray *c26_nargout;
  const char_T *c26_identifier;
  emlrtMsgIdentifier c26_thisId;
  real_T c26_y;
  SFc26_Modified2InstanceStruct *chartInstance;
  chartInstance = (SFc26_Modified2InstanceStruct *)chartInstanceVoid;
  c26_nargout = sf_mex_dup(c26_mxArrayInData);
  c26_identifier = c26_varName;
  c26_thisId.fIdentifier = c26_identifier;
  c26_thisId.fParent = NULL;
  c26_y = c26_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c26_nargout),
    &c26_thisId);
  sf_mex_destroy(&c26_nargout);
  *(real_T *)c26_outData = c26_y;
  sf_mex_destroy(&c26_mxArrayInData);
}

const mxArray *sf_c26_Modified2_get_eml_resolved_functions_info(void)
{
  const mxArray *c26_nameCaptureInfo = NULL;
  c26_nameCaptureInfo = NULL;
  sf_mex_assign(&c26_nameCaptureInfo, sf_mex_createstruct("structure", 2, 10, 1),
                false);
  c26_info_helper(&c26_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c26_nameCaptureInfo);
  return c26_nameCaptureInfo;
}

static void c26_info_helper(const mxArray **c26_info)
{
  const mxArray *c26_rhs0 = NULL;
  const mxArray *c26_lhs0 = NULL;
  const mxArray *c26_rhs1 = NULL;
  const mxArray *c26_lhs1 = NULL;
  const mxArray *c26_rhs2 = NULL;
  const mxArray *c26_lhs2 = NULL;
  const mxArray *c26_rhs3 = NULL;
  const mxArray *c26_lhs3 = NULL;
  const mxArray *c26_rhs4 = NULL;
  const mxArray *c26_lhs4 = NULL;
  const mxArray *c26_rhs5 = NULL;
  const mxArray *c26_lhs5 = NULL;
  const mxArray *c26_rhs6 = NULL;
  const mxArray *c26_lhs6 = NULL;
  const mxArray *c26_rhs7 = NULL;
  const mxArray *c26_lhs7 = NULL;
  const mxArray *c26_rhs8 = NULL;
  const mxArray *c26_lhs8 = NULL;
  const mxArray *c26_rhs9 = NULL;
  const mxArray *c26_lhs9 = NULL;
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("sign"), "name", "name", 0);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1363713856U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c26_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c26_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_scalar_sign"), "name",
                  "name", 2);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sign.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1356541494U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c26_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "context", "context", 3);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("mrdivide"), "name", "name",
                  3);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1410807648U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1370009886U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c26_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 4);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 4);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1389717774U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c26_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 5);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("rdivide"), "name", "name", 5);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1363713880U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c26_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 6);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c26_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 7);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c26_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_div"), "name", "name", 8);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1386423952U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c26_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 9);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c26_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs9), "lhs", "lhs",
                  9);
  sf_mex_destroy(&c26_rhs0);
  sf_mex_destroy(&c26_lhs0);
  sf_mex_destroy(&c26_rhs1);
  sf_mex_destroy(&c26_lhs1);
  sf_mex_destroy(&c26_rhs2);
  sf_mex_destroy(&c26_lhs2);
  sf_mex_destroy(&c26_rhs3);
  sf_mex_destroy(&c26_lhs3);
  sf_mex_destroy(&c26_rhs4);
  sf_mex_destroy(&c26_lhs4);
  sf_mex_destroy(&c26_rhs5);
  sf_mex_destroy(&c26_lhs5);
  sf_mex_destroy(&c26_rhs6);
  sf_mex_destroy(&c26_lhs6);
  sf_mex_destroy(&c26_rhs7);
  sf_mex_destroy(&c26_lhs7);
  sf_mex_destroy(&c26_rhs8);
  sf_mex_destroy(&c26_lhs8);
  sf_mex_destroy(&c26_rhs9);
  sf_mex_destroy(&c26_lhs9);
}

static const mxArray *c26_emlrt_marshallOut(const char * c26_u)
{
  const mxArray *c26_y = NULL;
  c26_y = NULL;
  sf_mex_assign(&c26_y, sf_mex_create("y", c26_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c26_u)), false);
  return c26_y;
}

static const mxArray *c26_b_emlrt_marshallOut(const uint32_T c26_u)
{
  const mxArray *c26_y = NULL;
  c26_y = NULL;
  sf_mex_assign(&c26_y, sf_mex_create("y", &c26_u, 7, 0U, 0U, 0U, 0), false);
  return c26_y;
}

static const mxArray *c26_d_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData)
{
  const mxArray *c26_mxArrayOutData = NULL;
  int32_T c26_u;
  const mxArray *c26_y = NULL;
  SFc26_Modified2InstanceStruct *chartInstance;
  chartInstance = (SFc26_Modified2InstanceStruct *)chartInstanceVoid;
  c26_mxArrayOutData = NULL;
  c26_u = *(int32_T *)c26_inData;
  c26_y = NULL;
  sf_mex_assign(&c26_y, sf_mex_create("y", &c26_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c26_mxArrayOutData, c26_y, false);
  return c26_mxArrayOutData;
}

static int32_T c26_m_emlrt_marshallIn(SFc26_Modified2InstanceStruct
  *chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId)
{
  int32_T c26_y;
  int32_T c26_i19;
  (void)chartInstance;
  sf_mex_import(c26_parentId, sf_mex_dup(c26_u), &c26_i19, 1, 6, 0U, 0, 0U, 0);
  c26_y = c26_i19;
  sf_mex_destroy(&c26_u);
  return c26_y;
}

static void c26_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c26_mxArrayInData, const char_T *c26_varName, void *c26_outData)
{
  const mxArray *c26_b_sfEvent;
  const char_T *c26_identifier;
  emlrtMsgIdentifier c26_thisId;
  int32_T c26_y;
  SFc26_Modified2InstanceStruct *chartInstance;
  chartInstance = (SFc26_Modified2InstanceStruct *)chartInstanceVoid;
  c26_b_sfEvent = sf_mex_dup(c26_mxArrayInData);
  c26_identifier = c26_varName;
  c26_thisId.fIdentifier = c26_identifier;
  c26_thisId.fParent = NULL;
  c26_y = c26_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c26_b_sfEvent),
    &c26_thisId);
  sf_mex_destroy(&c26_b_sfEvent);
  *(int32_T *)c26_outData = c26_y;
  sf_mex_destroy(&c26_mxArrayInData);
}

static const mxArray *c26_T_s4_bus_io(void *chartInstanceVoid, void *c26_pData)
{
  const mxArray *c26_mxVal = NULL;
  c26_whl_vec4 c26_tmp;
  SFc26_Modified2InstanceStruct *chartInstance;
  chartInstance = (SFc26_Modified2InstanceStruct *)chartInstanceVoid;
  c26_mxVal = NULL;
  c26_tmp.fl = *(real_T *)&((char_T *)(c26_whl_vec4 *)c26_pData)[0];
  c26_tmp.fr = *(real_T *)&((char_T *)(c26_whl_vec4 *)c26_pData)[8];
  c26_tmp.rl = *(real_T *)&((char_T *)(c26_whl_vec4 *)c26_pData)[16];
  c26_tmp.rr = *(real_T *)&((char_T *)(c26_whl_vec4 *)c26_pData)[24];
  sf_mex_assign(&c26_mxVal, c26_sf_marshallOut(chartInstance, &c26_tmp), false);
  return c26_mxVal;
}

static uint8_T c26_n_emlrt_marshallIn(SFc26_Modified2InstanceStruct
  *chartInstance, const mxArray *c26_b_is_active_c26_Modified2, const char_T
  *c26_identifier)
{
  uint8_T c26_y;
  emlrtMsgIdentifier c26_thisId;
  c26_thisId.fIdentifier = c26_identifier;
  c26_thisId.fParent = NULL;
  c26_y = c26_o_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c26_b_is_active_c26_Modified2), &c26_thisId);
  sf_mex_destroy(&c26_b_is_active_c26_Modified2);
  return c26_y;
}

static uint8_T c26_o_emlrt_marshallIn(SFc26_Modified2InstanceStruct
  *chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId)
{
  uint8_T c26_y;
  uint8_T c26_u0;
  (void)chartInstance;
  sf_mex_import(c26_parentId, sf_mex_dup(c26_u), &c26_u0, 1, 3, 0U, 0, 0U, 0);
  c26_y = c26_u0;
  sf_mex_destroy(&c26_u);
  return c26_y;
}

static void init_dsm_address_info(SFc26_Modified2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc26_Modified2InstanceStruct
  *chartInstance)
{
  chartInstance->c26_T_s4 = (c26_whl_vec4 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c26_T_us4 = (c26_whl_vec4 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c26_derw_w4 = (c26_whl_vec4 *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c26_F_xv4 = (c26_whl_vec4 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c26_F_yv4 = (c26_whl_vec4 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c26_F_z4 = (c26_whl_vec4 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c26_w_w4 = (c26_whl_vec4 *)ssGetInputPortSignal_wrapper
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

void sf_c26_Modified2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1652723854U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(230350706U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1632871624U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1815351536U);
}

mxArray* sf_c26_Modified2_get_post_codegen_info(void);
mxArray *sf_c26_Modified2_get_autoinheritance_info(void)
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
    mxArray* mxPostCodegenInfo = sf_c26_Modified2_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c26_Modified2_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c26_Modified2_jit_fallback_info(void)
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

mxArray *sf_c26_Modified2_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c26_Modified2_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c26_Modified2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[7],T\"derw_w4\",},{M[8],M[0],T\"is_active_c26_Modified2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c26_Modified2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc26_Modified2InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc26_Modified2InstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Modified2MachineNumber_,
           26,
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
        init_script_number_translation(_Modified2MachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Modified2MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Modified2MachineNumber_,
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
          (MexFcnForType)c26_T_s4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c26_T_s4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c26_T_s4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c26_T_s4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c26_T_s4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c26_T_s4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c26_T_s4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c26_b_sf_marshallOut,(MexInFcnForType)
          c26_b_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c26_T_s4);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c26_T_us4);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c26_derw_w4);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c26_F_xv4);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c26_F_yv4);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c26_F_z4);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c26_w_w4);
        _SFD_SET_DATA_VALUE_PTR(7U, &chartInstance->c26_Par);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Modified2MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "eNOzoSQLev7mB2ZCyUgDCC";
}

static void sf_opaque_initialize_c26_Modified2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc26_Modified2InstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c26_Modified2((SFc26_Modified2InstanceStruct*)
    chartInstanceVar);
  initialize_c26_Modified2((SFc26_Modified2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c26_Modified2(void *chartInstanceVar)
{
  enable_c26_Modified2((SFc26_Modified2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c26_Modified2(void *chartInstanceVar)
{
  disable_c26_Modified2((SFc26_Modified2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c26_Modified2(void *chartInstanceVar)
{
  sf_gateway_c26_Modified2((SFc26_Modified2InstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c26_Modified2(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c26_Modified2((SFc26_Modified2InstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c26_Modified2(SimStruct* S, const mxArray
  *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c26_Modified2((SFc26_Modified2InstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c26_Modified2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc26_Modified2InstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Modified2_optimization_info();
    }

    finalize_c26_Modified2((SFc26_Modified2InstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc26_Modified2((SFc26_Modified2InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c26_Modified2(SimStruct *S)
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
    initialize_params_c26_Modified2((SFc26_Modified2InstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c26_Modified2(SimStruct *S)
{
  /* Actual parameters from chart:
     Par
   */
  const char_T *rtParamNames[] = { "Par" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0],
    sf_get_param_data_type_id(S,0));
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Modified2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      26);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,26,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,26,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,26);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,26,6);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,26,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,26);
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

static void mdlRTW_c26_Modified2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c26_Modified2(SimStruct *S)
{
  SFc26_Modified2InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc26_Modified2InstanceStruct *)utMalloc(sizeof
    (SFc26_Modified2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc26_Modified2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c26_Modified2;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c26_Modified2;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c26_Modified2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c26_Modified2;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c26_Modified2;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c26_Modified2;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c26_Modified2;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c26_Modified2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c26_Modified2;
  chartInstance->chartInfo.mdlStart = mdlStart_c26_Modified2;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c26_Modified2;
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

void c26_Modified2_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c26_Modified2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c26_Modified2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c26_Modified2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c26_Modified2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
