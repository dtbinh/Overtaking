/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Modified_sfun.h"
#include "c24_Modified.h"
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
static const char * c24_debug_family_names[5] = { "nargin", "nargout", "v_z4",
  "Par", "derF_s4" };

/* Function Declarations */
static void initialize_c24_Modified(SFc24_ModifiedInstanceStruct *chartInstance);
static void initialize_params_c24_Modified(SFc24_ModifiedInstanceStruct
  *chartInstance);
static void enable_c24_Modified(SFc24_ModifiedInstanceStruct *chartInstance);
static void disable_c24_Modified(SFc24_ModifiedInstanceStruct *chartInstance);
static void c24_update_debugger_state_c24_Modified(SFc24_ModifiedInstanceStruct *
  chartInstance);
static const mxArray *get_sim_state_c24_Modified(SFc24_ModifiedInstanceStruct
  *chartInstance);
static void set_sim_state_c24_Modified(SFc24_ModifiedInstanceStruct
  *chartInstance, const mxArray *c24_st);
static void finalize_c24_Modified(SFc24_ModifiedInstanceStruct *chartInstance);
static void sf_gateway_c24_Modified(SFc24_ModifiedInstanceStruct *chartInstance);
static void mdl_start_c24_Modified(SFc24_ModifiedInstanceStruct *chartInstance);
static void c24_chartstep_c24_Modified(SFc24_ModifiedInstanceStruct
  *chartInstance);
static void initSimStructsc24_Modified(SFc24_ModifiedInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c24_machineNumber, uint32_T
  c24_chartNumber, uint32_T c24_instanceNumber);
static const mxArray *c24_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData);
static c24_whl_vec4 c24_emlrt_marshallIn(SFc24_ModifiedInstanceStruct
  *chartInstance, const mxArray *c24_b_derF_s4, const char_T *c24_identifier);
static c24_whl_vec4 c24_b_emlrt_marshallIn(SFc24_ModifiedInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId);
static real_T c24_c_emlrt_marshallIn(SFc24_ModifiedInstanceStruct *chartInstance,
  const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId);
static void c24_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData);
static const mxArray *c24_b_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData);
static void c24_d_emlrt_marshallIn(SFc24_ModifiedInstanceStruct *chartInstance,
  const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId,
  c24_struct_iBlsPBO3AGnt69vDoTx5zD *c24_y);
static void c24_e_emlrt_marshallIn(SFc24_ModifiedInstanceStruct *chartInstance,
  const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId,
  c24_struct_Nst2vGTExxHsg85EUOj9EH *c24_y);
static c24_struct_HhckT6rntEraqECYVIDvCC c24_f_emlrt_marshallIn
  (SFc24_ModifiedInstanceStruct *chartInstance, const mxArray *c24_u, const
   emlrtMsgIdentifier *c24_parentId);
static void c24_g_emlrt_marshallIn(SFc24_ModifiedInstanceStruct *chartInstance,
  const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId,
  c24_struct_ZCmOWPuqBDw16FSOVVD00 *c24_y);
static void c24_h_emlrt_marshallIn(SFc24_ModifiedInstanceStruct *chartInstance,
  const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId, real_T c24_y[4]);
static void c24_i_emlrt_marshallIn(SFc24_ModifiedInstanceStruct *chartInstance,
  const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId,
  c24_struct_ZKAzdrl7umDGJoC14aoVKC *c24_y);
static void c24_j_emlrt_marshallIn(SFc24_ModifiedInstanceStruct *chartInstance,
  const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId, real_T c24_y[3]);
static c24_struct_r4FNviKwHfdhB8nQjvQv9 c24_k_emlrt_marshallIn
  (SFc24_ModifiedInstanceStruct *chartInstance, const mxArray *c24_u, const
   emlrtMsgIdentifier *c24_parentId);
static c24_struct_Y9F1qlBi9AhssksPwemA4G c24_l_emlrt_marshallIn
  (SFc24_ModifiedInstanceStruct *chartInstance, const mxArray *c24_u, const
   emlrtMsgIdentifier *c24_parentId);
static void c24_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData);
static const mxArray *c24_c_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData);
static void c24_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData);
static void c24_info_helper(const mxArray **c24_info);
static const mxArray *c24_emlrt_marshallOut(const char * c24_u);
static const mxArray *c24_b_emlrt_marshallOut(const uint32_T c24_u);
static real_T c24_eml_xdotu(SFc24_ModifiedInstanceStruct *chartInstance, real_T
  c24_x[2], real_T c24_y[2]);
static const mxArray *c24_d_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData);
static int32_T c24_m_emlrt_marshallIn(SFc24_ModifiedInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId);
static void c24_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData);
static const mxArray *c24_v_z4_bus_io(void *chartInstanceVoid, void *c24_pData);
static uint8_T c24_n_emlrt_marshallIn(SFc24_ModifiedInstanceStruct
  *chartInstance, const mxArray *c24_b_is_active_c24_Modified, const char_T
  *c24_identifier);
static uint8_T c24_o_emlrt_marshallIn(SFc24_ModifiedInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId);
static void init_dsm_address_info(SFc24_ModifiedInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc24_ModifiedInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c24_Modified(SFc24_ModifiedInstanceStruct *chartInstance)
{
  chartInstance->c24_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c24_is_active_c24_Modified = 0U;
}

static void initialize_params_c24_Modified(SFc24_ModifiedInstanceStruct
  *chartInstance)
{
  const mxArray *c24_m0 = NULL;
  const mxArray *c24_mxField;
  const mxArray *c24_m1 = NULL;
  const mxArray *c24_b_mxField;
  c24_struct_iBlsPBO3AGnt69vDoTx5zD c24_r0;
  const mxArray *c24_m2 = NULL;
  const mxArray *c24_c_mxField;
  const mxArray *c24_m3 = NULL;
  const mxArray *c24_d_mxField;
  const mxArray *c24_m4 = NULL;
  const mxArray *c24_e_mxField;
  const mxArray *c24_m5 = NULL;
  const mxArray *c24_f_mxField;
  const mxArray *c24_m6 = NULL;
  const mxArray *c24_g_mxField;
  const mxArray *c24_m7 = NULL;
  const mxArray *c24_h_mxField;
  const mxArray *c24_m8 = NULL;
  const mxArray *c24_i_mxField;
  const mxArray *c24_m9 = NULL;
  const mxArray *c24_j_mxField;
  const mxArray *c24_m10 = NULL;
  const mxArray *c24_k_mxField;
  const mxArray *c24_m11 = NULL;
  const mxArray *c24_l_mxField;
  const mxArray *c24_m12 = NULL;
  const mxArray *c24_m_mxField;
  const mxArray *c24_m13 = NULL;
  const mxArray *c24_n_mxField;
  c24_m0 = sf_mex_get_sfun_param(chartInstance->S, 0, 1);
  c24_mxField = sf_mex_getfield(c24_m0, "Env", "Par", 0);
  c24_m1 = sf_mex_dup(c24_mxField);
  c24_b_mxField = sf_mex_getfield(c24_m1, "g", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_b_mxField), &c24_r0.Env.g, 1, 0, 0U,
                      0, 0U, 0);
  c24_b_mxField = sf_mex_getfield(c24_m1, "left1", "Par", 0);
  c24_m2 = sf_mex_dup(c24_b_mxField);
  c24_c_mxField = sf_mex_getfield(c24_m2, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_c_mxField), &c24_r0.Env.left1.x, 1,
                      0, 0U, 0, 0U, 0);
  c24_c_mxField = sf_mex_getfield(c24_m2, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_c_mxField), &c24_r0.Env.left1.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c24_m2);
  c24_b_mxField = sf_mex_getfield(c24_m1, "right1", "Par", 0);
  c24_m3 = sf_mex_dup(c24_b_mxField);
  c24_d_mxField = sf_mex_getfield(c24_m3, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_d_mxField), &c24_r0.Env.right1.x, 1,
                      0, 0U, 0, 0U, 0);
  c24_d_mxField = sf_mex_getfield(c24_m3, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_d_mxField), &c24_r0.Env.right1.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c24_m3);
  c24_b_mxField = sf_mex_getfield(c24_m1, "right2", "Par", 0);
  c24_m4 = sf_mex_dup(c24_b_mxField);
  c24_e_mxField = sf_mex_getfield(c24_m4, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_e_mxField), &c24_r0.Env.right2.x, 1,
                      0, 0U, 0, 0U, 0);
  c24_e_mxField = sf_mex_getfield(c24_m4, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_e_mxField), &c24_r0.Env.right2.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c24_m4);
  c24_b_mxField = sf_mex_getfield(c24_m1, "left2", "Par", 0);
  c24_m5 = sf_mex_dup(c24_b_mxField);
  c24_f_mxField = sf_mex_getfield(c24_m5, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_f_mxField), &c24_r0.Env.left2.x, 1,
                      0, 0U, 0, 0U, 0);
  c24_f_mxField = sf_mex_getfield(c24_m5, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_f_mxField), &c24_r0.Env.left2.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c24_m5);
  c24_b_mxField = sf_mex_getfield(c24_m1, "right3", "Par", 0);
  c24_m6 = sf_mex_dup(c24_b_mxField);
  c24_g_mxField = sf_mex_getfield(c24_m6, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_g_mxField), &c24_r0.Env.right3.x, 1,
                      0, 0U, 0, 0U, 0);
  c24_g_mxField = sf_mex_getfield(c24_m6, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_g_mxField), &c24_r0.Env.right3.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c24_m6);
  c24_b_mxField = sf_mex_getfield(c24_m1, "mu", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_b_mxField), &c24_r0.Env.mu, 1, 0, 0U,
                      0, 0U, 0);
  sf_mex_destroy(&c24_m1);
  c24_mxField = sf_mex_getfield(c24_m0, "Veh", "Par", 0);
  c24_m7 = sf_mex_dup(c24_mxField);
  c24_h_mxField = sf_mex_getfield(c24_m7, "m", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_h_mxField), &c24_r0.Veh.m, 1, 0, 0U,
                      0, 0U, 0);
  c24_h_mxField = sf_mex_getfield(c24_m7, "Jz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_h_mxField), &c24_r0.Veh.Jz, 1, 0, 0U,
                      0, 0U, 0);
  c24_h_mxField = sf_mex_getfield(c24_m7, "m_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_h_mxField), &c24_r0.Veh.m_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c24_h_mxField = sf_mex_getfield(c24_m7, "Jx_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_h_mxField), &c24_r0.Veh.Jx_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c24_h_mxField = sf_mex_getfield(c24_m7, "Jy_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_h_mxField), &c24_r0.Veh.Jy_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c24_h_mxField = sf_mex_getfield(c24_m7, "lf", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_h_mxField), &c24_r0.Veh.lf, 1, 0, 0U,
                      0, 0U, 0);
  c24_h_mxField = sf_mex_getfield(c24_m7, "lr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_h_mxField), &c24_r0.Veh.lr, 1, 0, 0U,
                      0, 0U, 0);
  c24_h_mxField = sf_mex_getfield(c24_m7, "L", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_h_mxField), &c24_r0.Veh.L, 1, 0, 0U,
                      0, 0U, 0);
  c24_h_mxField = sf_mex_getfield(c24_m7, "TrackWidth", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_h_mxField), &c24_r0.Veh.TrackWidth,
                      1, 0, 0U, 0, 0U, 0);
  c24_h_mxField = sf_mex_getfield(c24_m7, "h", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_h_mxField), &c24_r0.Veh.h, 1, 0, 0U,
                      0, 0U, 0);
  c24_h_mxField = sf_mex_getfield(c24_m7, "HalfRohACd", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_h_mxField), &c24_r0.Veh.HalfRohACd,
                      1, 0, 0U, 0, 0U, 0);
  c24_h_mxField = sf_mex_getfield(c24_m7, "F_z4_static", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_h_mxField), c24_r0.Veh.F_z4_static,
                      1, 0, 0U, 1, 0U, 2, 1, 4);
  c24_h_mxField = sf_mex_getfield(c24_m7, "Rw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_h_mxField), &c24_r0.Veh.Rw, 1, 0, 0U,
                      0, 0U, 0);
  c24_h_mxField = sf_mex_getfield(c24_m7, "r_long", "Par", 0);
  c24_m8 = sf_mex_dup(c24_h_mxField);
  c24_i_mxField = sf_mex_getfield(c24_m8, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_i_mxField), c24_r0.Veh.r_long.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c24_i_mxField = sf_mex_getfield(c24_m8, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_i_mxField), c24_r0.Veh.r_long.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c24_i_mxField = sf_mex_getfield(c24_m8, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_i_mxField), c24_r0.Veh.r_long.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c24_i_mxField = sf_mex_getfield(c24_m8, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_i_mxField), c24_r0.Veh.r_long.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c24_m8);
  c24_h_mxField = sf_mex_getfield(c24_m7, "r_lat", "Par", 0);
  c24_m9 = sf_mex_dup(c24_h_mxField);
  c24_j_mxField = sf_mex_getfield(c24_m9, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_j_mxField), c24_r0.Veh.r_lat.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c24_j_mxField = sf_mex_getfield(c24_m9, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_j_mxField), c24_r0.Veh.r_lat.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c24_j_mxField = sf_mex_getfield(c24_m9, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_j_mxField), c24_r0.Veh.r_lat.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c24_j_mxField = sf_mex_getfield(c24_m9, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_j_mxField), c24_r0.Veh.r_lat.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c24_m9);
  c24_h_mxField = sf_mex_getfield(c24_m7, "r_lever", "Par", 0);
  c24_m10 = sf_mex_dup(c24_h_mxField);
  c24_k_mxField = sf_mex_getfield(c24_m10, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_k_mxField), c24_r0.Veh.r_lever.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c24_k_mxField = sf_mex_getfield(c24_m10, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_k_mxField), c24_r0.Veh.r_lever.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c24_k_mxField = sf_mex_getfield(c24_m10, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_k_mxField), c24_r0.Veh.r_lever.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c24_k_mxField = sf_mex_getfield(c24_m10, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_k_mxField), c24_r0.Veh.r_lever.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c24_m10);
  c24_h_mxField = sf_mex_getfield(c24_m7, "r_pivot", "Par", 0);
  c24_m11 = sf_mex_dup(c24_h_mxField);
  c24_l_mxField = sf_mex_getfield(c24_m11, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_l_mxField), c24_r0.Veh.r_pivot.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c24_l_mxField = sf_mex_getfield(c24_m11, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_l_mxField), c24_r0.Veh.r_pivot.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c24_l_mxField = sf_mex_getfield(c24_m11, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_l_mxField), c24_r0.Veh.r_pivot.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c24_l_mxField = sf_mex_getfield(c24_m11, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_l_mxField), c24_r0.Veh.r_pivot.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c24_m11);
  c24_h_mxField = sf_mex_getfield(c24_m7, "cw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_h_mxField), &c24_r0.Veh.cw, 1, 0, 0U,
                      0, 0U, 0);
  c24_h_mxField = sf_mex_getfield(c24_m7, "carb_f", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_h_mxField), &c24_r0.Veh.carb_f, 1, 0,
                      0U, 0, 0U, 0);
  c24_h_mxField = sf_mex_getfield(c24_m7, "carb_r", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_h_mxField), &c24_r0.Veh.carb_r, 1, 0,
                      0U, 0, 0U, 0);
  c24_h_mxField = sf_mex_getfield(c24_m7, "dw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_h_mxField), &c24_r0.Veh.dw, 1, 0, 0U,
                      0, 0U, 0);
  c24_h_mxField = sf_mex_getfield(c24_m7, "Jw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_h_mxField), &c24_r0.Veh.Jw, 1, 0, 0U,
                      0, 0U, 0);
  c24_h_mxField = sf_mex_getfield(c24_m7, "C0", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_h_mxField), &c24_r0.Veh.C0, 1, 0, 0U,
                      0, 0U, 0);
  c24_h_mxField = sf_mex_getfield(c24_m7, "RelaxLength", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_h_mxField), &c24_r0.Veh.RelaxLength,
                      1, 0, 0U, 0, 0U, 0);
  c24_h_mxField = sf_mex_getfield(c24_m7, "RRC", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_h_mxField), &c24_r0.Veh.RRC, 1, 0,
                      0U, 0, 0U, 0);
  c24_h_mxField = sf_mex_getfield(c24_m7, "Pmax", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_h_mxField), &c24_r0.Veh.Pmax, 1, 0,
                      0U, 0, 0U, 0);
  c24_h_mxField = sf_mex_getfield(c24_m7, "PropDistrFrnt", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_h_mxField),
                      &c24_r0.Veh.PropDistrFrnt, 1, 0, 0U, 0, 0U, 0);
  c24_h_mxField = sf_mex_getfield(c24_m7, "BrkDistrFrnt", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_h_mxField), &c24_r0.Veh.BrkDistrFrnt,
                      1, 0, 0U, 0, 0U, 0);
  c24_h_mxField = sf_mex_getfield(c24_m7, "SteRatio", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_h_mxField), &c24_r0.Veh.SteRatio, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c24_m7);
  c24_mxField = sf_mex_getfield(c24_m0, "Drvr", "Par", 0);
  c24_m12 = sf_mex_dup(c24_mxField);
  c24_m_mxField = sf_mex_getfield(c24_m12, "v_set", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_m_mxField), &c24_r0.Drvr.v_set, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c24_m12);
  c24_mxField = sf_mex_getfield(c24_m0, "Init", "Par", 0);
  c24_m13 = sf_mex_dup(c24_mxField);
  c24_n_mxField = sf_mex_getfield(c24_m13, "v_x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_n_mxField), &c24_r0.Init.v_x, 1, 0,
                      0U, 0, 0U, 0);
  c24_n_mxField = sf_mex_getfield(c24_m13, "F_fz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_n_mxField), &c24_r0.Init.F_fz, 1, 0,
                      0U, 0, 0U, 0);
  c24_n_mxField = sf_mex_getfield(c24_m13, "F_rz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c24_n_mxField), &c24_r0.Init.F_rz, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c24_m13);
  sf_mex_destroy(&c24_m0);
  chartInstance->c24_Par = c24_r0;
}

static void enable_c24_Modified(SFc24_ModifiedInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c24_Modified(SFc24_ModifiedInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c24_update_debugger_state_c24_Modified(SFc24_ModifiedInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c24_Modified(SFc24_ModifiedInstanceStruct
  *chartInstance)
{
  const mxArray *c24_st;
  const mxArray *c24_y = NULL;
  const mxArray *c24_b_y = NULL;
  real_T c24_u;
  const mxArray *c24_c_y = NULL;
  real_T c24_b_u;
  const mxArray *c24_d_y = NULL;
  real_T c24_c_u;
  const mxArray *c24_e_y = NULL;
  real_T c24_d_u;
  const mxArray *c24_f_y = NULL;
  uint8_T c24_hoistedGlobal;
  uint8_T c24_e_u;
  const mxArray *c24_g_y = NULL;
  c24_st = NULL;
  c24_st = NULL;
  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_createcellmatrix(2, 1), false);
  c24_b_y = NULL;
  sf_mex_assign(&c24_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c24_u = *(real_T *)&((char_T *)chartInstance->c24_derF_s4)[0];
  c24_c_y = NULL;
  sf_mex_assign(&c24_c_y, sf_mex_create("y", &c24_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c24_b_y, c24_c_y, "fl", "fl", 0);
  c24_b_u = *(real_T *)&((char_T *)chartInstance->c24_derF_s4)[8];
  c24_d_y = NULL;
  sf_mex_assign(&c24_d_y, sf_mex_create("y", &c24_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c24_b_y, c24_d_y, "fr", "fr", 0);
  c24_c_u = *(real_T *)&((char_T *)chartInstance->c24_derF_s4)[16];
  c24_e_y = NULL;
  sf_mex_assign(&c24_e_y, sf_mex_create("y", &c24_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c24_b_y, c24_e_y, "rl", "rl", 0);
  c24_d_u = *(real_T *)&((char_T *)chartInstance->c24_derF_s4)[24];
  c24_f_y = NULL;
  sf_mex_assign(&c24_f_y, sf_mex_create("y", &c24_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c24_b_y, c24_f_y, "rr", "rr", 0);
  sf_mex_setcell(c24_y, 0, c24_b_y);
  c24_hoistedGlobal = chartInstance->c24_is_active_c24_Modified;
  c24_e_u = c24_hoistedGlobal;
  c24_g_y = NULL;
  sf_mex_assign(&c24_g_y, sf_mex_create("y", &c24_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c24_y, 1, c24_g_y);
  sf_mex_assign(&c24_st, c24_y, false);
  return c24_st;
}

static void set_sim_state_c24_Modified(SFc24_ModifiedInstanceStruct
  *chartInstance, const mxArray *c24_st)
{
  const mxArray *c24_u;
  c24_whl_vec4 c24_r1;
  chartInstance->c24_doneDoubleBufferReInit = true;
  c24_u = sf_mex_dup(c24_st);
  c24_r1 = c24_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c24_u,
    0)), "derF_s4");
  *(real_T *)&((char_T *)chartInstance->c24_derF_s4)[0] = c24_r1.fl;
  *(real_T *)&((char_T *)chartInstance->c24_derF_s4)[8] = c24_r1.fr;
  *(real_T *)&((char_T *)chartInstance->c24_derF_s4)[16] = c24_r1.rl;
  *(real_T *)&((char_T *)chartInstance->c24_derF_s4)[24] = c24_r1.rr;
  chartInstance->c24_is_active_c24_Modified = c24_n_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c24_u, 1)),
     "is_active_c24_Modified");
  sf_mex_destroy(&c24_u);
  c24_update_debugger_state_c24_Modified(chartInstance);
  sf_mex_destroy(&c24_st);
}

static void finalize_c24_Modified(SFc24_ModifiedInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c24_Modified(SFc24_ModifiedInstanceStruct *chartInstance)
{
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 23U, chartInstance->c24_sfEvent);
  chartInstance->c24_sfEvent = CALL_EVENT;
  c24_chartstep_c24_Modified(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_ModifiedMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c24_Modified(SFc24_ModifiedInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c24_chartstep_c24_Modified(SFc24_ModifiedInstanceStruct
  *chartInstance)
{
  c24_whl_vec4 c24_b_v_z4;
  c24_struct_iBlsPBO3AGnt69vDoTx5zD c24_b_Par;
  uint32_T c24_debug_family_var_map[5];
  real_T c24_nargin = 2.0;
  real_T c24_nargout = 1.0;
  c24_whl_vec4 c24_b_derF_s4;
  real_T c24_a[2];
  real_T c24_b[2];
  int32_T c24_i0;
  real_T c24_b_a[2];
  int32_T c24_i1;
  real_T c24_b_b[2];
  real_T c24_y;
  int32_T c24_i2;
  real_T c24_c_a[2];
  int32_T c24_i3;
  real_T c24_c_b[2];
  real_T c24_b_y;
  int32_T c24_i4;
  real_T c24_d_a[2];
  int32_T c24_i5;
  real_T c24_d_b[2];
  real_T c24_c_y;
  int32_T c24_i6;
  real_T c24_e_a[2];
  int32_T c24_i7;
  real_T c24_e_b[2];
  real_T c24_d_y;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 23U, chartInstance->c24_sfEvent);
  c24_b_v_z4.fl = *(real_T *)&((char_T *)chartInstance->c24_v_z4)[0];
  c24_b_v_z4.fr = *(real_T *)&((char_T *)chartInstance->c24_v_z4)[8];
  c24_b_v_z4.rl = *(real_T *)&((char_T *)chartInstance->c24_v_z4)[16];
  c24_b_v_z4.rr = *(real_T *)&((char_T *)chartInstance->c24_v_z4)[24];
  c24_b_Par = chartInstance->c24_Par;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c24_debug_family_names,
    c24_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c24_nargin, 0U, c24_c_sf_marshallOut,
    c24_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c24_nargout, 1U, c24_c_sf_marshallOut,
    c24_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c24_b_v_z4, 2U, c24_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c24_b_Par, 3U, c24_b_sf_marshallOut,
    c24_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c24_b_derF_s4, 4U, c24_sf_marshallOut,
    c24_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c24_sfEvent, 5);
  c24_a[0] = c24_b_Par.Veh.cw;
  c24_a[1] = c24_b_Par.Veh.carb_f;
  c24_b[0] = -c24_b_v_z4.fl;
  c24_b[1] = -c24_b_v_z4.fr;
  for (c24_i0 = 0; c24_i0 < 2; c24_i0++) {
    c24_b_a[c24_i0] = c24_a[c24_i0];
  }

  for (c24_i1 = 0; c24_i1 < 2; c24_i1++) {
    c24_b_b[c24_i1] = c24_b[c24_i1];
  }

  c24_y = c24_eml_xdotu(chartInstance, c24_b_a, c24_b_b);
  c24_b_derF_s4.fl = c24_y;
  _SFD_EML_CALL(0U, chartInstance->c24_sfEvent, 6);
  c24_a[0] = c24_b_Par.Veh.cw;
  c24_a[1] = c24_b_Par.Veh.carb_f;
  c24_b[0] = -c24_b_v_z4.fr;
  c24_b[1] = -c24_b_v_z4.fl;
  for (c24_i2 = 0; c24_i2 < 2; c24_i2++) {
    c24_c_a[c24_i2] = c24_a[c24_i2];
  }

  for (c24_i3 = 0; c24_i3 < 2; c24_i3++) {
    c24_c_b[c24_i3] = c24_b[c24_i3];
  }

  c24_b_y = c24_eml_xdotu(chartInstance, c24_c_a, c24_c_b);
  c24_b_derF_s4.fr = c24_b_y;
  _SFD_EML_CALL(0U, chartInstance->c24_sfEvent, 7);
  c24_a[0] = c24_b_Par.Veh.cw;
  c24_a[1] = c24_b_Par.Veh.carb_r;
  c24_b[0] = -c24_b_v_z4.rl;
  c24_b[1] = -c24_b_v_z4.rr;
  for (c24_i4 = 0; c24_i4 < 2; c24_i4++) {
    c24_d_a[c24_i4] = c24_a[c24_i4];
  }

  for (c24_i5 = 0; c24_i5 < 2; c24_i5++) {
    c24_d_b[c24_i5] = c24_b[c24_i5];
  }

  c24_c_y = c24_eml_xdotu(chartInstance, c24_d_a, c24_d_b);
  c24_b_derF_s4.rl = c24_c_y;
  _SFD_EML_CALL(0U, chartInstance->c24_sfEvent, 8);
  c24_a[0] = c24_b_Par.Veh.cw;
  c24_a[1] = c24_b_Par.Veh.carb_r;
  c24_b[0] = -c24_b_v_z4.rr;
  c24_b[1] = -c24_b_v_z4.rl;
  for (c24_i6 = 0; c24_i6 < 2; c24_i6++) {
    c24_e_a[c24_i6] = c24_a[c24_i6];
  }

  for (c24_i7 = 0; c24_i7 < 2; c24_i7++) {
    c24_e_b[c24_i7] = c24_b[c24_i7];
  }

  c24_d_y = c24_eml_xdotu(chartInstance, c24_e_a, c24_e_b);
  c24_b_derF_s4.rr = c24_d_y;
  _SFD_EML_CALL(0U, chartInstance->c24_sfEvent, -8);
  _SFD_SYMBOL_SCOPE_POP();
  *(real_T *)&((char_T *)chartInstance->c24_derF_s4)[0] = c24_b_derF_s4.fl;
  *(real_T *)&((char_T *)chartInstance->c24_derF_s4)[8] = c24_b_derF_s4.fr;
  *(real_T *)&((char_T *)chartInstance->c24_derF_s4)[16] = c24_b_derF_s4.rl;
  *(real_T *)&((char_T *)chartInstance->c24_derF_s4)[24] = c24_b_derF_s4.rr;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 23U, chartInstance->c24_sfEvent);
}

static void initSimStructsc24_Modified(SFc24_ModifiedInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c24_machineNumber, uint32_T
  c24_chartNumber, uint32_T c24_instanceNumber)
{
  (void)c24_machineNumber;
  (void)c24_chartNumber;
  (void)c24_instanceNumber;
}

static const mxArray *c24_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData)
{
  const mxArray *c24_mxArrayOutData = NULL;
  c24_whl_vec4 c24_u;
  const mxArray *c24_y = NULL;
  real_T c24_b_u;
  const mxArray *c24_b_y = NULL;
  real_T c24_c_u;
  const mxArray *c24_c_y = NULL;
  real_T c24_d_u;
  const mxArray *c24_d_y = NULL;
  real_T c24_e_u;
  const mxArray *c24_e_y = NULL;
  SFc24_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc24_ModifiedInstanceStruct *)chartInstanceVoid;
  c24_mxArrayOutData = NULL;
  c24_u = *(c24_whl_vec4 *)c24_inData;
  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c24_b_u = c24_u.fl;
  c24_b_y = NULL;
  sf_mex_assign(&c24_b_y, sf_mex_create("y", &c24_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c24_y, c24_b_y, "fl", "fl", 0);
  c24_c_u = c24_u.fr;
  c24_c_y = NULL;
  sf_mex_assign(&c24_c_y, sf_mex_create("y", &c24_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c24_y, c24_c_y, "fr", "fr", 0);
  c24_d_u = c24_u.rl;
  c24_d_y = NULL;
  sf_mex_assign(&c24_d_y, sf_mex_create("y", &c24_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c24_y, c24_d_y, "rl", "rl", 0);
  c24_e_u = c24_u.rr;
  c24_e_y = NULL;
  sf_mex_assign(&c24_e_y, sf_mex_create("y", &c24_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c24_y, c24_e_y, "rr", "rr", 0);
  sf_mex_assign(&c24_mxArrayOutData, c24_y, false);
  return c24_mxArrayOutData;
}

static c24_whl_vec4 c24_emlrt_marshallIn(SFc24_ModifiedInstanceStruct
  *chartInstance, const mxArray *c24_b_derF_s4, const char_T *c24_identifier)
{
  c24_whl_vec4 c24_y;
  emlrtMsgIdentifier c24_thisId;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_y = c24_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_b_derF_s4),
    &c24_thisId);
  sf_mex_destroy(&c24_b_derF_s4);
  return c24_y;
}

static c24_whl_vec4 c24_b_emlrt_marshallIn(SFc24_ModifiedInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId)
{
  c24_whl_vec4 c24_y;
  emlrtMsgIdentifier c24_thisId;
  static const char * c24_fieldNames[4] = { "fl", "fr", "rl", "rr" };

  c24_thisId.fParent = c24_parentId;
  sf_mex_check_struct(c24_parentId, c24_u, 4, c24_fieldNames, 0U, NULL);
  c24_thisId.fIdentifier = "fl";
  c24_y.fl = c24_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c24_u, "fl", "fl", 0)), &c24_thisId);
  c24_thisId.fIdentifier = "fr";
  c24_y.fr = c24_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c24_u, "fr", "fr", 0)), &c24_thisId);
  c24_thisId.fIdentifier = "rl";
  c24_y.rl = c24_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c24_u, "rl", "rl", 0)), &c24_thisId);
  c24_thisId.fIdentifier = "rr";
  c24_y.rr = c24_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c24_u, "rr", "rr", 0)), &c24_thisId);
  sf_mex_destroy(&c24_u);
  return c24_y;
}

static real_T c24_c_emlrt_marshallIn(SFc24_ModifiedInstanceStruct *chartInstance,
  const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId)
{
  real_T c24_y;
  real_T c24_d0;
  (void)chartInstance;
  sf_mex_import(c24_parentId, sf_mex_dup(c24_u), &c24_d0, 1, 0, 0U, 0, 0U, 0);
  c24_y = c24_d0;
  sf_mex_destroy(&c24_u);
  return c24_y;
}

static void c24_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData)
{
  const mxArray *c24_b_derF_s4;
  const char_T *c24_identifier;
  emlrtMsgIdentifier c24_thisId;
  c24_whl_vec4 c24_y;
  SFc24_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc24_ModifiedInstanceStruct *)chartInstanceVoid;
  c24_b_derF_s4 = sf_mex_dup(c24_mxArrayInData);
  c24_identifier = c24_varName;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_y = c24_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_b_derF_s4),
    &c24_thisId);
  sf_mex_destroy(&c24_b_derF_s4);
  *(c24_whl_vec4 *)c24_outData = c24_y;
  sf_mex_destroy(&c24_mxArrayInData);
}

static const mxArray *c24_b_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData)
{
  const mxArray *c24_mxArrayOutData;
  c24_struct_iBlsPBO3AGnt69vDoTx5zD c24_u;
  const mxArray *c24_y = NULL;
  c24_struct_Nst2vGTExxHsg85EUOj9EH c24_b_u;
  const mxArray *c24_b_y = NULL;
  real_T c24_c_u;
  const mxArray *c24_c_y = NULL;
  c24_struct_HhckT6rntEraqECYVIDvCC c24_d_u;
  const mxArray *c24_d_y = NULL;
  real_T c24_e_u;
  const mxArray *c24_e_y = NULL;
  real_T c24_f_u;
  const mxArray *c24_f_y = NULL;
  const mxArray *c24_g_y = NULL;
  real_T c24_g_u;
  const mxArray *c24_h_y = NULL;
  real_T c24_h_u;
  const mxArray *c24_i_y = NULL;
  const mxArray *c24_j_y = NULL;
  real_T c24_i_u;
  const mxArray *c24_k_y = NULL;
  real_T c24_j_u;
  const mxArray *c24_l_y = NULL;
  const mxArray *c24_m_y = NULL;
  real_T c24_k_u;
  const mxArray *c24_n_y = NULL;
  real_T c24_l_u;
  const mxArray *c24_o_y = NULL;
  const mxArray *c24_p_y = NULL;
  real_T c24_m_u;
  const mxArray *c24_q_y = NULL;
  real_T c24_n_u;
  const mxArray *c24_r_y = NULL;
  real_T c24_o_u;
  const mxArray *c24_s_y = NULL;
  c24_struct_ZCmOWPuqBDw16FSOVVD00 c24_p_u;
  const mxArray *c24_t_y = NULL;
  real_T c24_q_u;
  const mxArray *c24_u_y = NULL;
  real_T c24_r_u;
  const mxArray *c24_v_y = NULL;
  real_T c24_s_u;
  const mxArray *c24_w_y = NULL;
  real_T c24_t_u;
  const mxArray *c24_x_y = NULL;
  real_T c24_u_u;
  const mxArray *c24_y_y = NULL;
  real_T c24_v_u;
  const mxArray *c24_ab_y = NULL;
  real_T c24_w_u;
  const mxArray *c24_bb_y = NULL;
  real_T c24_x_u;
  const mxArray *c24_cb_y = NULL;
  real_T c24_y_u;
  const mxArray *c24_db_y = NULL;
  real_T c24_ab_u;
  const mxArray *c24_eb_y = NULL;
  real_T c24_bb_u;
  const mxArray *c24_fb_y = NULL;
  int32_T c24_i8;
  real_T c24_cb_u[4];
  const mxArray *c24_gb_y = NULL;
  real_T c24_db_u;
  const mxArray *c24_hb_y = NULL;
  c24_struct_ZKAzdrl7umDGJoC14aoVKC c24_eb_u;
  const mxArray *c24_ib_y = NULL;
  int32_T c24_i9;
  real_T c24_fb_u[3];
  const mxArray *c24_jb_y = NULL;
  int32_T c24_i10;
  real_T c24_gb_u[3];
  const mxArray *c24_kb_y = NULL;
  int32_T c24_i11;
  real_T c24_hb_u[3];
  const mxArray *c24_lb_y = NULL;
  int32_T c24_i12;
  real_T c24_ib_u[3];
  const mxArray *c24_mb_y = NULL;
  const mxArray *c24_nb_y = NULL;
  int32_T c24_i13;
  real_T c24_jb_u[3];
  const mxArray *c24_ob_y = NULL;
  int32_T c24_i14;
  real_T c24_kb_u[3];
  const mxArray *c24_pb_y = NULL;
  int32_T c24_i15;
  real_T c24_lb_u[3];
  const mxArray *c24_qb_y = NULL;
  int32_T c24_i16;
  real_T c24_mb_u[3];
  const mxArray *c24_rb_y = NULL;
  const mxArray *c24_sb_y = NULL;
  int32_T c24_i17;
  real_T c24_nb_u[3];
  const mxArray *c24_tb_y = NULL;
  int32_T c24_i18;
  real_T c24_ob_u[3];
  const mxArray *c24_ub_y = NULL;
  int32_T c24_i19;
  real_T c24_pb_u[3];
  const mxArray *c24_vb_y = NULL;
  int32_T c24_i20;
  real_T c24_qb_u[3];
  const mxArray *c24_wb_y = NULL;
  const mxArray *c24_xb_y = NULL;
  int32_T c24_i21;
  real_T c24_rb_u[3];
  const mxArray *c24_yb_y = NULL;
  int32_T c24_i22;
  real_T c24_sb_u[3];
  const mxArray *c24_ac_y = NULL;
  int32_T c24_i23;
  real_T c24_tb_u[3];
  const mxArray *c24_bc_y = NULL;
  int32_T c24_i24;
  real_T c24_ub_u[3];
  const mxArray *c24_cc_y = NULL;
  real_T c24_vb_u;
  const mxArray *c24_dc_y = NULL;
  real_T c24_wb_u;
  const mxArray *c24_ec_y = NULL;
  real_T c24_xb_u;
  const mxArray *c24_fc_y = NULL;
  real_T c24_yb_u;
  const mxArray *c24_gc_y = NULL;
  real_T c24_ac_u;
  const mxArray *c24_hc_y = NULL;
  real_T c24_bc_u;
  const mxArray *c24_ic_y = NULL;
  real_T c24_cc_u;
  const mxArray *c24_jc_y = NULL;
  real_T c24_dc_u;
  const mxArray *c24_kc_y = NULL;
  real_T c24_ec_u;
  const mxArray *c24_lc_y = NULL;
  real_T c24_fc_u;
  const mxArray *c24_mc_y = NULL;
  real_T c24_gc_u;
  const mxArray *c24_nc_y = NULL;
  real_T c24_hc_u;
  const mxArray *c24_oc_y = NULL;
  c24_struct_r4FNviKwHfdhB8nQjvQv9 c24_ic_u;
  const mxArray *c24_pc_y = NULL;
  real_T c24_jc_u;
  const mxArray *c24_qc_y = NULL;
  c24_struct_Y9F1qlBi9AhssksPwemA4G c24_kc_u;
  const mxArray *c24_rc_y = NULL;
  real_T c24_lc_u;
  const mxArray *c24_sc_y = NULL;
  real_T c24_mc_u;
  const mxArray *c24_tc_y = NULL;
  real_T c24_nc_u;
  const mxArray *c24_uc_y = NULL;
  SFc24_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc24_ModifiedInstanceStruct *)chartInstanceVoid;
  c24_mxArrayOutData = NULL;
  c24_mxArrayOutData = NULL;
  c24_u = *(c24_struct_iBlsPBO3AGnt69vDoTx5zD *)c24_inData;
  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c24_b_u = c24_u.Env;
  c24_b_y = NULL;
  sf_mex_assign(&c24_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c24_c_u = c24_b_u.g;
  c24_c_y = NULL;
  sf_mex_assign(&c24_c_y, sf_mex_create("y", &c24_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c24_b_y, c24_c_y, "g", "g", 0);
  c24_d_u = c24_b_u.left1;
  c24_d_y = NULL;
  sf_mex_assign(&c24_d_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c24_e_u = c24_d_u.x;
  c24_e_y = NULL;
  sf_mex_assign(&c24_e_y, sf_mex_create("y", &c24_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c24_d_y, c24_e_y, "x", "x", 0);
  c24_f_u = c24_d_u.y;
  c24_f_y = NULL;
  sf_mex_assign(&c24_f_y, sf_mex_create("y", &c24_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c24_d_y, c24_f_y, "y", "y", 0);
  sf_mex_addfield(c24_b_y, c24_d_y, "left1", "left1", 0);
  c24_d_u = c24_b_u.right1;
  c24_g_y = NULL;
  sf_mex_assign(&c24_g_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c24_g_u = c24_d_u.x;
  c24_h_y = NULL;
  sf_mex_assign(&c24_h_y, sf_mex_create("y", &c24_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c24_g_y, c24_h_y, "x", "x", 0);
  c24_h_u = c24_d_u.y;
  c24_i_y = NULL;
  sf_mex_assign(&c24_i_y, sf_mex_create("y", &c24_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c24_g_y, c24_i_y, "y", "y", 0);
  sf_mex_addfield(c24_b_y, c24_g_y, "right1", "right1", 0);
  c24_d_u = c24_b_u.right2;
  c24_j_y = NULL;
  sf_mex_assign(&c24_j_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c24_i_u = c24_d_u.x;
  c24_k_y = NULL;
  sf_mex_assign(&c24_k_y, sf_mex_create("y", &c24_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c24_j_y, c24_k_y, "x", "x", 0);
  c24_j_u = c24_d_u.y;
  c24_l_y = NULL;
  sf_mex_assign(&c24_l_y, sf_mex_create("y", &c24_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c24_j_y, c24_l_y, "y", "y", 0);
  sf_mex_addfield(c24_b_y, c24_j_y, "right2", "right2", 0);
  c24_d_u = c24_b_u.left2;
  c24_m_y = NULL;
  sf_mex_assign(&c24_m_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c24_k_u = c24_d_u.x;
  c24_n_y = NULL;
  sf_mex_assign(&c24_n_y, sf_mex_create("y", &c24_k_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c24_m_y, c24_n_y, "x", "x", 0);
  c24_l_u = c24_d_u.y;
  c24_o_y = NULL;
  sf_mex_assign(&c24_o_y, sf_mex_create("y", &c24_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c24_m_y, c24_o_y, "y", "y", 0);
  sf_mex_addfield(c24_b_y, c24_m_y, "left2", "left2", 0);
  c24_d_u = c24_b_u.right3;
  c24_p_y = NULL;
  sf_mex_assign(&c24_p_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c24_m_u = c24_d_u.x;
  c24_q_y = NULL;
  sf_mex_assign(&c24_q_y, sf_mex_create("y", &c24_m_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c24_p_y, c24_q_y, "x", "x", 0);
  c24_n_u = c24_d_u.y;
  c24_r_y = NULL;
  sf_mex_assign(&c24_r_y, sf_mex_create("y", &c24_n_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c24_p_y, c24_r_y, "y", "y", 0);
  sf_mex_addfield(c24_b_y, c24_p_y, "right3", "right3", 0);
  c24_o_u = c24_b_u.mu;
  c24_s_y = NULL;
  sf_mex_assign(&c24_s_y, sf_mex_create("y", &c24_o_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c24_b_y, c24_s_y, "mu", "mu", 0);
  sf_mex_addfield(c24_y, c24_b_y, "Env", "Env", 0);
  c24_p_u = c24_u.Veh;
  c24_t_y = NULL;
  sf_mex_assign(&c24_t_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c24_q_u = c24_p_u.m;
  c24_u_y = NULL;
  sf_mex_assign(&c24_u_y, sf_mex_create("y", &c24_q_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c24_t_y, c24_u_y, "m", "m", 0);
  c24_r_u = c24_p_u.Jz;
  c24_v_y = NULL;
  sf_mex_assign(&c24_v_y, sf_mex_create("y", &c24_r_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c24_t_y, c24_v_y, "Jz", "Jz", 0);
  c24_s_u = c24_p_u.m_sprung;
  c24_w_y = NULL;
  sf_mex_assign(&c24_w_y, sf_mex_create("y", &c24_s_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c24_t_y, c24_w_y, "m_sprung", "m_sprung", 0);
  c24_t_u = c24_p_u.Jx_sprung;
  c24_x_y = NULL;
  sf_mex_assign(&c24_x_y, sf_mex_create("y", &c24_t_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c24_t_y, c24_x_y, "Jx_sprung", "Jx_sprung", 0);
  c24_u_u = c24_p_u.Jy_sprung;
  c24_y_y = NULL;
  sf_mex_assign(&c24_y_y, sf_mex_create("y", &c24_u_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c24_t_y, c24_y_y, "Jy_sprung", "Jy_sprung", 0);
  c24_v_u = c24_p_u.lf;
  c24_ab_y = NULL;
  sf_mex_assign(&c24_ab_y, sf_mex_create("y", &c24_v_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c24_t_y, c24_ab_y, "lf", "lf", 0);
  c24_w_u = c24_p_u.lr;
  c24_bb_y = NULL;
  sf_mex_assign(&c24_bb_y, sf_mex_create("y", &c24_w_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c24_t_y, c24_bb_y, "lr", "lr", 0);
  c24_x_u = c24_p_u.L;
  c24_cb_y = NULL;
  sf_mex_assign(&c24_cb_y, sf_mex_create("y", &c24_x_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c24_t_y, c24_cb_y, "L", "L", 0);
  c24_y_u = c24_p_u.TrackWidth;
  c24_db_y = NULL;
  sf_mex_assign(&c24_db_y, sf_mex_create("y", &c24_y_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c24_t_y, c24_db_y, "TrackWidth", "TrackWidth", 0);
  c24_ab_u = c24_p_u.h;
  c24_eb_y = NULL;
  sf_mex_assign(&c24_eb_y, sf_mex_create("y", &c24_ab_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c24_t_y, c24_eb_y, "h", "h", 0);
  c24_bb_u = c24_p_u.HalfRohACd;
  c24_fb_y = NULL;
  sf_mex_assign(&c24_fb_y, sf_mex_create("y", &c24_bb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c24_t_y, c24_fb_y, "HalfRohACd", "HalfRohACd", 0);
  for (c24_i8 = 0; c24_i8 < 4; c24_i8++) {
    c24_cb_u[c24_i8] = c24_p_u.F_z4_static[c24_i8];
  }

  c24_gb_y = NULL;
  sf_mex_assign(&c24_gb_y, sf_mex_create("y", c24_cb_u, 0, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_addfield(c24_t_y, c24_gb_y, "F_z4_static", "F_z4_static", 0);
  c24_db_u = c24_p_u.Rw;
  c24_hb_y = NULL;
  sf_mex_assign(&c24_hb_y, sf_mex_create("y", &c24_db_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c24_t_y, c24_hb_y, "Rw", "Rw", 0);
  c24_eb_u = c24_p_u.r_long;
  c24_ib_y = NULL;
  sf_mex_assign(&c24_ib_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c24_i9 = 0; c24_i9 < 3; c24_i9++) {
    c24_fb_u[c24_i9] = c24_eb_u.fl[c24_i9];
  }

  c24_jb_y = NULL;
  sf_mex_assign(&c24_jb_y, sf_mex_create("y", c24_fb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c24_ib_y, c24_jb_y, "fl", "fl", 0);
  for (c24_i10 = 0; c24_i10 < 3; c24_i10++) {
    c24_gb_u[c24_i10] = c24_eb_u.fr[c24_i10];
  }

  c24_kb_y = NULL;
  sf_mex_assign(&c24_kb_y, sf_mex_create("y", c24_gb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c24_ib_y, c24_kb_y, "fr", "fr", 0);
  for (c24_i11 = 0; c24_i11 < 3; c24_i11++) {
    c24_hb_u[c24_i11] = c24_eb_u.rl[c24_i11];
  }

  c24_lb_y = NULL;
  sf_mex_assign(&c24_lb_y, sf_mex_create("y", c24_hb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c24_ib_y, c24_lb_y, "rl", "rl", 0);
  for (c24_i12 = 0; c24_i12 < 3; c24_i12++) {
    c24_ib_u[c24_i12] = c24_eb_u.rr[c24_i12];
  }

  c24_mb_y = NULL;
  sf_mex_assign(&c24_mb_y, sf_mex_create("y", c24_ib_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c24_ib_y, c24_mb_y, "rr", "rr", 0);
  sf_mex_addfield(c24_t_y, c24_ib_y, "r_long", "r_long", 0);
  c24_eb_u = c24_p_u.r_lat;
  c24_nb_y = NULL;
  sf_mex_assign(&c24_nb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c24_i13 = 0; c24_i13 < 3; c24_i13++) {
    c24_jb_u[c24_i13] = c24_eb_u.fl[c24_i13];
  }

  c24_ob_y = NULL;
  sf_mex_assign(&c24_ob_y, sf_mex_create("y", c24_jb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c24_nb_y, c24_ob_y, "fl", "fl", 0);
  for (c24_i14 = 0; c24_i14 < 3; c24_i14++) {
    c24_kb_u[c24_i14] = c24_eb_u.fr[c24_i14];
  }

  c24_pb_y = NULL;
  sf_mex_assign(&c24_pb_y, sf_mex_create("y", c24_kb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c24_nb_y, c24_pb_y, "fr", "fr", 0);
  for (c24_i15 = 0; c24_i15 < 3; c24_i15++) {
    c24_lb_u[c24_i15] = c24_eb_u.rl[c24_i15];
  }

  c24_qb_y = NULL;
  sf_mex_assign(&c24_qb_y, sf_mex_create("y", c24_lb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c24_nb_y, c24_qb_y, "rl", "rl", 0);
  for (c24_i16 = 0; c24_i16 < 3; c24_i16++) {
    c24_mb_u[c24_i16] = c24_eb_u.rr[c24_i16];
  }

  c24_rb_y = NULL;
  sf_mex_assign(&c24_rb_y, sf_mex_create("y", c24_mb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c24_nb_y, c24_rb_y, "rr", "rr", 0);
  sf_mex_addfield(c24_t_y, c24_nb_y, "r_lat", "r_lat", 0);
  c24_eb_u = c24_p_u.r_lever;
  c24_sb_y = NULL;
  sf_mex_assign(&c24_sb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c24_i17 = 0; c24_i17 < 3; c24_i17++) {
    c24_nb_u[c24_i17] = c24_eb_u.fl[c24_i17];
  }

  c24_tb_y = NULL;
  sf_mex_assign(&c24_tb_y, sf_mex_create("y", c24_nb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c24_sb_y, c24_tb_y, "fl", "fl", 0);
  for (c24_i18 = 0; c24_i18 < 3; c24_i18++) {
    c24_ob_u[c24_i18] = c24_eb_u.fr[c24_i18];
  }

  c24_ub_y = NULL;
  sf_mex_assign(&c24_ub_y, sf_mex_create("y", c24_ob_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c24_sb_y, c24_ub_y, "fr", "fr", 0);
  for (c24_i19 = 0; c24_i19 < 3; c24_i19++) {
    c24_pb_u[c24_i19] = c24_eb_u.rl[c24_i19];
  }

  c24_vb_y = NULL;
  sf_mex_assign(&c24_vb_y, sf_mex_create("y", c24_pb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c24_sb_y, c24_vb_y, "rl", "rl", 0);
  for (c24_i20 = 0; c24_i20 < 3; c24_i20++) {
    c24_qb_u[c24_i20] = c24_eb_u.rr[c24_i20];
  }

  c24_wb_y = NULL;
  sf_mex_assign(&c24_wb_y, sf_mex_create("y", c24_qb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c24_sb_y, c24_wb_y, "rr", "rr", 0);
  sf_mex_addfield(c24_t_y, c24_sb_y, "r_lever", "r_lever", 0);
  c24_eb_u = c24_p_u.r_pivot;
  c24_xb_y = NULL;
  sf_mex_assign(&c24_xb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c24_i21 = 0; c24_i21 < 3; c24_i21++) {
    c24_rb_u[c24_i21] = c24_eb_u.fl[c24_i21];
  }

  c24_yb_y = NULL;
  sf_mex_assign(&c24_yb_y, sf_mex_create("y", c24_rb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c24_xb_y, c24_yb_y, "fl", "fl", 0);
  for (c24_i22 = 0; c24_i22 < 3; c24_i22++) {
    c24_sb_u[c24_i22] = c24_eb_u.fr[c24_i22];
  }

  c24_ac_y = NULL;
  sf_mex_assign(&c24_ac_y, sf_mex_create("y", c24_sb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c24_xb_y, c24_ac_y, "fr", "fr", 0);
  for (c24_i23 = 0; c24_i23 < 3; c24_i23++) {
    c24_tb_u[c24_i23] = c24_eb_u.rl[c24_i23];
  }

  c24_bc_y = NULL;
  sf_mex_assign(&c24_bc_y, sf_mex_create("y", c24_tb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c24_xb_y, c24_bc_y, "rl", "rl", 0);
  for (c24_i24 = 0; c24_i24 < 3; c24_i24++) {
    c24_ub_u[c24_i24] = c24_eb_u.rr[c24_i24];
  }

  c24_cc_y = NULL;
  sf_mex_assign(&c24_cc_y, sf_mex_create("y", c24_ub_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c24_xb_y, c24_cc_y, "rr", "rr", 0);
  sf_mex_addfield(c24_t_y, c24_xb_y, "r_pivot", "r_pivot", 0);
  c24_vb_u = c24_p_u.cw;
  c24_dc_y = NULL;
  sf_mex_assign(&c24_dc_y, sf_mex_create("y", &c24_vb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c24_t_y, c24_dc_y, "cw", "cw", 0);
  c24_wb_u = c24_p_u.carb_f;
  c24_ec_y = NULL;
  sf_mex_assign(&c24_ec_y, sf_mex_create("y", &c24_wb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c24_t_y, c24_ec_y, "carb_f", "carb_f", 0);
  c24_xb_u = c24_p_u.carb_r;
  c24_fc_y = NULL;
  sf_mex_assign(&c24_fc_y, sf_mex_create("y", &c24_xb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c24_t_y, c24_fc_y, "carb_r", "carb_r", 0);
  c24_yb_u = c24_p_u.dw;
  c24_gc_y = NULL;
  sf_mex_assign(&c24_gc_y, sf_mex_create("y", &c24_yb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c24_t_y, c24_gc_y, "dw", "dw", 0);
  c24_ac_u = c24_p_u.Jw;
  c24_hc_y = NULL;
  sf_mex_assign(&c24_hc_y, sf_mex_create("y", &c24_ac_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c24_t_y, c24_hc_y, "Jw", "Jw", 0);
  c24_bc_u = c24_p_u.C0;
  c24_ic_y = NULL;
  sf_mex_assign(&c24_ic_y, sf_mex_create("y", &c24_bc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c24_t_y, c24_ic_y, "C0", "C0", 0);
  c24_cc_u = c24_p_u.RelaxLength;
  c24_jc_y = NULL;
  sf_mex_assign(&c24_jc_y, sf_mex_create("y", &c24_cc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c24_t_y, c24_jc_y, "RelaxLength", "RelaxLength", 0);
  c24_dc_u = c24_p_u.RRC;
  c24_kc_y = NULL;
  sf_mex_assign(&c24_kc_y, sf_mex_create("y", &c24_dc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c24_t_y, c24_kc_y, "RRC", "RRC", 0);
  c24_ec_u = c24_p_u.Pmax;
  c24_lc_y = NULL;
  sf_mex_assign(&c24_lc_y, sf_mex_create("y", &c24_ec_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c24_t_y, c24_lc_y, "Pmax", "Pmax", 0);
  c24_fc_u = c24_p_u.PropDistrFrnt;
  c24_mc_y = NULL;
  sf_mex_assign(&c24_mc_y, sf_mex_create("y", &c24_fc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c24_t_y, c24_mc_y, "PropDistrFrnt", "PropDistrFrnt", 0);
  c24_gc_u = c24_p_u.BrkDistrFrnt;
  c24_nc_y = NULL;
  sf_mex_assign(&c24_nc_y, sf_mex_create("y", &c24_gc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c24_t_y, c24_nc_y, "BrkDistrFrnt", "BrkDistrFrnt", 0);
  c24_hc_u = c24_p_u.SteRatio;
  c24_oc_y = NULL;
  sf_mex_assign(&c24_oc_y, sf_mex_create("y", &c24_hc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c24_t_y, c24_oc_y, "SteRatio", "SteRatio", 0);
  sf_mex_addfield(c24_y, c24_t_y, "Veh", "Veh", 0);
  c24_ic_u = c24_u.Drvr;
  c24_pc_y = NULL;
  sf_mex_assign(&c24_pc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c24_jc_u = c24_ic_u.v_set;
  c24_qc_y = NULL;
  sf_mex_assign(&c24_qc_y, sf_mex_create("y", &c24_jc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c24_pc_y, c24_qc_y, "v_set", "v_set", 0);
  sf_mex_addfield(c24_y, c24_pc_y, "Drvr", "Drvr", 0);
  c24_kc_u = c24_u.Init;
  c24_rc_y = NULL;
  sf_mex_assign(&c24_rc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c24_lc_u = c24_kc_u.v_x;
  c24_sc_y = NULL;
  sf_mex_assign(&c24_sc_y, sf_mex_create("y", &c24_lc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c24_rc_y, c24_sc_y, "v_x", "v_x", 0);
  c24_mc_u = c24_kc_u.F_fz;
  c24_tc_y = NULL;
  sf_mex_assign(&c24_tc_y, sf_mex_create("y", &c24_mc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c24_rc_y, c24_tc_y, "F_fz", "F_fz", 0);
  c24_nc_u = c24_kc_u.F_rz;
  c24_uc_y = NULL;
  sf_mex_assign(&c24_uc_y, sf_mex_create("y", &c24_nc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c24_rc_y, c24_uc_y, "F_rz", "F_rz", 0);
  sf_mex_addfield(c24_y, c24_rc_y, "Init", "Init", 0);
  sf_mex_assign(&c24_mxArrayOutData, c24_y, false);
  return c24_mxArrayOutData;
}

static void c24_d_emlrt_marshallIn(SFc24_ModifiedInstanceStruct *chartInstance,
  const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId,
  c24_struct_iBlsPBO3AGnt69vDoTx5zD *c24_y)
{
  emlrtMsgIdentifier c24_thisId;
  static const char * c24_fieldNames[4] = { "Env", "Veh", "Drvr", "Init" };

  c24_thisId.fParent = c24_parentId;
  sf_mex_check_struct(c24_parentId, c24_u, 4, c24_fieldNames, 0U, NULL);
  c24_thisId.fIdentifier = "Env";
  c24_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c24_u, "Env",
    "Env", 0)), &c24_thisId, &c24_y->Env);
  c24_thisId.fIdentifier = "Veh";
  c24_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c24_u, "Veh",
    "Veh", 0)), &c24_thisId, &c24_y->Veh);
  c24_thisId.fIdentifier = "Drvr";
  c24_y->Drvr = c24_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c24_u, "Drvr", "Drvr", 0)), &c24_thisId);
  c24_thisId.fIdentifier = "Init";
  c24_y->Init = c24_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c24_u, "Init", "Init", 0)), &c24_thisId);
  sf_mex_destroy(&c24_u);
}

static void c24_e_emlrt_marshallIn(SFc24_ModifiedInstanceStruct *chartInstance,
  const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId,
  c24_struct_Nst2vGTExxHsg85EUOj9EH *c24_y)
{
  emlrtMsgIdentifier c24_thisId;
  static const char * c24_fieldNames[7] = { "g", "left1", "right1", "right2",
    "left2", "right3", "mu" };

  c24_thisId.fParent = c24_parentId;
  sf_mex_check_struct(c24_parentId, c24_u, 7, c24_fieldNames, 0U, NULL);
  c24_thisId.fIdentifier = "g";
  c24_y->g = c24_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c24_u, "g", "g", 0)), &c24_thisId);
  c24_thisId.fIdentifier = "left1";
  c24_y->left1 = c24_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c24_u, "left1", "left1", 0)), &c24_thisId);
  c24_thisId.fIdentifier = "right1";
  c24_y->right1 = c24_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c24_u, "right1", "right1", 0)), &c24_thisId);
  c24_thisId.fIdentifier = "right2";
  c24_y->right2 = c24_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c24_u, "right2", "right2", 0)), &c24_thisId);
  c24_thisId.fIdentifier = "left2";
  c24_y->left2 = c24_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c24_u, "left2", "left2", 0)), &c24_thisId);
  c24_thisId.fIdentifier = "right3";
  c24_y->right3 = c24_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c24_u, "right3", "right3", 0)), &c24_thisId);
  c24_thisId.fIdentifier = "mu";
  c24_y->mu = c24_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c24_u, "mu", "mu", 0)), &c24_thisId);
  sf_mex_destroy(&c24_u);
}

static c24_struct_HhckT6rntEraqECYVIDvCC c24_f_emlrt_marshallIn
  (SFc24_ModifiedInstanceStruct *chartInstance, const mxArray *c24_u, const
   emlrtMsgIdentifier *c24_parentId)
{
  c24_struct_HhckT6rntEraqECYVIDvCC c24_y;
  emlrtMsgIdentifier c24_thisId;
  static const char * c24_fieldNames[2] = { "x", "y" };

  c24_thisId.fParent = c24_parentId;
  sf_mex_check_struct(c24_parentId, c24_u, 2, c24_fieldNames, 0U, NULL);
  c24_thisId.fIdentifier = "x";
  c24_y.x = c24_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c24_u, "x", "x", 0)), &c24_thisId);
  c24_thisId.fIdentifier = "y";
  c24_y.y = c24_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c24_u, "y", "y", 0)), &c24_thisId);
  sf_mex_destroy(&c24_u);
  return c24_y;
}

static void c24_g_emlrt_marshallIn(SFc24_ModifiedInstanceStruct *chartInstance,
  const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId,
  c24_struct_ZCmOWPuqBDw16FSOVVD00 *c24_y)
{
  emlrtMsgIdentifier c24_thisId;
  static const char * c24_fieldNames[29] = { "m", "Jz", "m_sprung", "Jx_sprung",
    "Jy_sprung", "lf", "lr", "L", "TrackWidth", "h", "HalfRohACd", "F_z4_static",
    "Rw", "r_long", "r_lat", "r_lever", "r_pivot", "cw", "carb_f", "carb_r",
    "dw", "Jw", "C0", "RelaxLength", "RRC", "Pmax", "PropDistrFrnt",
    "BrkDistrFrnt", "SteRatio" };

  c24_thisId.fParent = c24_parentId;
  sf_mex_check_struct(c24_parentId, c24_u, 29, c24_fieldNames, 0U, NULL);
  c24_thisId.fIdentifier = "m";
  c24_y->m = c24_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c24_u, "m", "m", 0)), &c24_thisId);
  c24_thisId.fIdentifier = "Jz";
  c24_y->Jz = c24_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c24_u, "Jz", "Jz", 0)), &c24_thisId);
  c24_thisId.fIdentifier = "m_sprung";
  c24_y->m_sprung = c24_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c24_u, "m_sprung", "m_sprung", 0)), &c24_thisId);
  c24_thisId.fIdentifier = "Jx_sprung";
  c24_y->Jx_sprung = c24_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c24_u, "Jx_sprung", "Jx_sprung", 0)), &c24_thisId);
  c24_thisId.fIdentifier = "Jy_sprung";
  c24_y->Jy_sprung = c24_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c24_u, "Jy_sprung", "Jy_sprung", 0)), &c24_thisId);
  c24_thisId.fIdentifier = "lf";
  c24_y->lf = c24_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c24_u, "lf", "lf", 0)), &c24_thisId);
  c24_thisId.fIdentifier = "lr";
  c24_y->lr = c24_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c24_u, "lr", "lr", 0)), &c24_thisId);
  c24_thisId.fIdentifier = "L";
  c24_y->L = c24_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c24_u, "L", "L", 0)), &c24_thisId);
  c24_thisId.fIdentifier = "TrackWidth";
  c24_y->TrackWidth = c24_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c24_u, "TrackWidth", "TrackWidth", 0)), &c24_thisId);
  c24_thisId.fIdentifier = "h";
  c24_y->h = c24_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c24_u, "h", "h", 0)), &c24_thisId);
  c24_thisId.fIdentifier = "HalfRohACd";
  c24_y->HalfRohACd = c24_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c24_u, "HalfRohACd", "HalfRohACd", 0)), &c24_thisId);
  c24_thisId.fIdentifier = "F_z4_static";
  c24_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c24_u,
    "F_z4_static", "F_z4_static", 0)), &c24_thisId, c24_y->F_z4_static);
  c24_thisId.fIdentifier = "Rw";
  c24_y->Rw = c24_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c24_u, "Rw", "Rw", 0)), &c24_thisId);
  c24_thisId.fIdentifier = "r_long";
  c24_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c24_u,
    "r_long", "r_long", 0)), &c24_thisId, &c24_y->r_long);
  c24_thisId.fIdentifier = "r_lat";
  c24_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c24_u,
    "r_lat", "r_lat", 0)), &c24_thisId, &c24_y->r_lat);
  c24_thisId.fIdentifier = "r_lever";
  c24_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c24_u,
    "r_lever", "r_lever", 0)), &c24_thisId, &c24_y->r_lever);
  c24_thisId.fIdentifier = "r_pivot";
  c24_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c24_u,
    "r_pivot", "r_pivot", 0)), &c24_thisId, &c24_y->r_pivot);
  c24_thisId.fIdentifier = "cw";
  c24_y->cw = c24_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c24_u, "cw", "cw", 0)), &c24_thisId);
  c24_thisId.fIdentifier = "carb_f";
  c24_y->carb_f = c24_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c24_u, "carb_f", "carb_f", 0)), &c24_thisId);
  c24_thisId.fIdentifier = "carb_r";
  c24_y->carb_r = c24_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c24_u, "carb_r", "carb_r", 0)), &c24_thisId);
  c24_thisId.fIdentifier = "dw";
  c24_y->dw = c24_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c24_u, "dw", "dw", 0)), &c24_thisId);
  c24_thisId.fIdentifier = "Jw";
  c24_y->Jw = c24_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c24_u, "Jw", "Jw", 0)), &c24_thisId);
  c24_thisId.fIdentifier = "C0";
  c24_y->C0 = c24_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c24_u, "C0", "C0", 0)), &c24_thisId);
  c24_thisId.fIdentifier = "RelaxLength";
  c24_y->RelaxLength = c24_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c24_u, "RelaxLength", "RelaxLength", 0)), &c24_thisId);
  c24_thisId.fIdentifier = "RRC";
  c24_y->RRC = c24_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c24_u, "RRC", "RRC", 0)), &c24_thisId);
  c24_thisId.fIdentifier = "Pmax";
  c24_y->Pmax = c24_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c24_u, "Pmax", "Pmax", 0)), &c24_thisId);
  c24_thisId.fIdentifier = "PropDistrFrnt";
  c24_y->PropDistrFrnt = c24_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c24_u, "PropDistrFrnt", "PropDistrFrnt", 0)), &c24_thisId);
  c24_thisId.fIdentifier = "BrkDistrFrnt";
  c24_y->BrkDistrFrnt = c24_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c24_u, "BrkDistrFrnt", "BrkDistrFrnt", 0)), &c24_thisId);
  c24_thisId.fIdentifier = "SteRatio";
  c24_y->SteRatio = c24_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c24_u, "SteRatio", "SteRatio", 0)), &c24_thisId);
  sf_mex_destroy(&c24_u);
}

static void c24_h_emlrt_marshallIn(SFc24_ModifiedInstanceStruct *chartInstance,
  const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId, real_T c24_y[4])
{
  real_T c24_dv0[4];
  int32_T c24_i25;
  (void)chartInstance;
  sf_mex_import(c24_parentId, sf_mex_dup(c24_u), c24_dv0, 1, 0, 0U, 1, 0U, 2, 1,
                4);
  for (c24_i25 = 0; c24_i25 < 4; c24_i25++) {
    c24_y[c24_i25] = c24_dv0[c24_i25];
  }

  sf_mex_destroy(&c24_u);
}

static void c24_i_emlrt_marshallIn(SFc24_ModifiedInstanceStruct *chartInstance,
  const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId,
  c24_struct_ZKAzdrl7umDGJoC14aoVKC *c24_y)
{
  emlrtMsgIdentifier c24_thisId;
  static const char * c24_fieldNames[4] = { "fl", "fr", "rl", "rr" };

  c24_thisId.fParent = c24_parentId;
  sf_mex_check_struct(c24_parentId, c24_u, 4, c24_fieldNames, 0U, NULL);
  c24_thisId.fIdentifier = "fl";
  c24_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c24_u, "fl",
    "fl", 0)), &c24_thisId, c24_y->fl);
  c24_thisId.fIdentifier = "fr";
  c24_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c24_u, "fr",
    "fr", 0)), &c24_thisId, c24_y->fr);
  c24_thisId.fIdentifier = "rl";
  c24_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c24_u, "rl",
    "rl", 0)), &c24_thisId, c24_y->rl);
  c24_thisId.fIdentifier = "rr";
  c24_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c24_u, "rr",
    "rr", 0)), &c24_thisId, c24_y->rr);
  sf_mex_destroy(&c24_u);
}

static void c24_j_emlrt_marshallIn(SFc24_ModifiedInstanceStruct *chartInstance,
  const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId, real_T c24_y[3])
{
  real_T c24_dv1[3];
  int32_T c24_i26;
  (void)chartInstance;
  sf_mex_import(c24_parentId, sf_mex_dup(c24_u), c24_dv1, 1, 0, 0U, 1, 0U, 2, 3,
                1);
  for (c24_i26 = 0; c24_i26 < 3; c24_i26++) {
    c24_y[c24_i26] = c24_dv1[c24_i26];
  }

  sf_mex_destroy(&c24_u);
}

static c24_struct_r4FNviKwHfdhB8nQjvQv9 c24_k_emlrt_marshallIn
  (SFc24_ModifiedInstanceStruct *chartInstance, const mxArray *c24_u, const
   emlrtMsgIdentifier *c24_parentId)
{
  c24_struct_r4FNviKwHfdhB8nQjvQv9 c24_y;
  emlrtMsgIdentifier c24_thisId;
  static const char * c24_fieldNames[1] = { "v_set" };

  c24_thisId.fParent = c24_parentId;
  sf_mex_check_struct(c24_parentId, c24_u, 1, c24_fieldNames, 0U, NULL);
  c24_thisId.fIdentifier = "v_set";
  c24_y.v_set = c24_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c24_u, "v_set", "v_set", 0)),
    &c24_thisId);
  sf_mex_destroy(&c24_u);
  return c24_y;
}

static c24_struct_Y9F1qlBi9AhssksPwemA4G c24_l_emlrt_marshallIn
  (SFc24_ModifiedInstanceStruct *chartInstance, const mxArray *c24_u, const
   emlrtMsgIdentifier *c24_parentId)
{
  c24_struct_Y9F1qlBi9AhssksPwemA4G c24_y;
  emlrtMsgIdentifier c24_thisId;
  static const char * c24_fieldNames[3] = { "v_x", "F_fz", "F_rz" };

  c24_thisId.fParent = c24_parentId;
  sf_mex_check_struct(c24_parentId, c24_u, 3, c24_fieldNames, 0U, NULL);
  c24_thisId.fIdentifier = "v_x";
  c24_y.v_x = c24_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c24_u, "v_x", "v_x", 0)), &c24_thisId);
  c24_thisId.fIdentifier = "F_fz";
  c24_y.F_fz = c24_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c24_u, "F_fz", "F_fz", 0)), &c24_thisId);
  c24_thisId.fIdentifier = "F_rz";
  c24_y.F_rz = c24_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c24_u, "F_rz", "F_rz", 0)), &c24_thisId);
  sf_mex_destroy(&c24_u);
  return c24_y;
}

static void c24_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData)
{
  const mxArray *c24_b_Par;
  const char_T *c24_identifier;
  emlrtMsgIdentifier c24_thisId;
  c24_struct_iBlsPBO3AGnt69vDoTx5zD c24_y;
  SFc24_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc24_ModifiedInstanceStruct *)chartInstanceVoid;
  c24_b_Par = sf_mex_dup(c24_mxArrayInData);
  c24_identifier = c24_varName;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_b_Par), &c24_thisId,
    &c24_y);
  sf_mex_destroy(&c24_b_Par);
  *(c24_struct_iBlsPBO3AGnt69vDoTx5zD *)c24_outData = c24_y;
  sf_mex_destroy(&c24_mxArrayInData);
}

static const mxArray *c24_c_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData)
{
  const mxArray *c24_mxArrayOutData = NULL;
  real_T c24_u;
  const mxArray *c24_y = NULL;
  SFc24_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc24_ModifiedInstanceStruct *)chartInstanceVoid;
  c24_mxArrayOutData = NULL;
  c24_u = *(real_T *)c24_inData;
  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_create("y", &c24_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c24_mxArrayOutData, c24_y, false);
  return c24_mxArrayOutData;
}

static void c24_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData)
{
  const mxArray *c24_nargout;
  const char_T *c24_identifier;
  emlrtMsgIdentifier c24_thisId;
  real_T c24_y;
  SFc24_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc24_ModifiedInstanceStruct *)chartInstanceVoid;
  c24_nargout = sf_mex_dup(c24_mxArrayInData);
  c24_identifier = c24_varName;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_y = c24_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_nargout),
    &c24_thisId);
  sf_mex_destroy(&c24_nargout);
  *(real_T *)c24_outData = c24_y;
  sf_mex_destroy(&c24_mxArrayInData);
}

const mxArray *sf_c24_Modified_get_eml_resolved_functions_info(void)
{
  const mxArray *c24_nameCaptureInfo = NULL;
  c24_nameCaptureInfo = NULL;
  sf_mex_assign(&c24_nameCaptureInfo, sf_mex_createstruct("structure", 2, 26, 1),
                false);
  c24_info_helper(&c24_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c24_nameCaptureInfo);
  return c24_nameCaptureInfo;
}

static void c24_info_helper(const mxArray **c24_info)
{
  const mxArray *c24_rhs0 = NULL;
  const mxArray *c24_lhs0 = NULL;
  const mxArray *c24_rhs1 = NULL;
  const mxArray *c24_lhs1 = NULL;
  const mxArray *c24_rhs2 = NULL;
  const mxArray *c24_lhs2 = NULL;
  const mxArray *c24_rhs3 = NULL;
  const mxArray *c24_lhs3 = NULL;
  const mxArray *c24_rhs4 = NULL;
  const mxArray *c24_lhs4 = NULL;
  const mxArray *c24_rhs5 = NULL;
  const mxArray *c24_lhs5 = NULL;
  const mxArray *c24_rhs6 = NULL;
  const mxArray *c24_lhs6 = NULL;
  const mxArray *c24_rhs7 = NULL;
  const mxArray *c24_lhs7 = NULL;
  const mxArray *c24_rhs8 = NULL;
  const mxArray *c24_lhs8 = NULL;
  const mxArray *c24_rhs9 = NULL;
  const mxArray *c24_lhs9 = NULL;
  const mxArray *c24_rhs10 = NULL;
  const mxArray *c24_lhs10 = NULL;
  const mxArray *c24_rhs11 = NULL;
  const mxArray *c24_lhs11 = NULL;
  const mxArray *c24_rhs12 = NULL;
  const mxArray *c24_lhs12 = NULL;
  const mxArray *c24_rhs13 = NULL;
  const mxArray *c24_lhs13 = NULL;
  const mxArray *c24_rhs14 = NULL;
  const mxArray *c24_lhs14 = NULL;
  const mxArray *c24_rhs15 = NULL;
  const mxArray *c24_lhs15 = NULL;
  const mxArray *c24_rhs16 = NULL;
  const mxArray *c24_lhs16 = NULL;
  const mxArray *c24_rhs17 = NULL;
  const mxArray *c24_lhs17 = NULL;
  const mxArray *c24_rhs18 = NULL;
  const mxArray *c24_lhs18 = NULL;
  const mxArray *c24_rhs19 = NULL;
  const mxArray *c24_lhs19 = NULL;
  const mxArray *c24_rhs20 = NULL;
  const mxArray *c24_lhs20 = NULL;
  const mxArray *c24_rhs21 = NULL;
  const mxArray *c24_lhs21 = NULL;
  const mxArray *c24_rhs22 = NULL;
  const mxArray *c24_lhs22 = NULL;
  const mxArray *c24_rhs23 = NULL;
  const mxArray *c24_lhs23 = NULL;
  const mxArray *c24_rhs24 = NULL;
  const mxArray *c24_lhs24 = NULL;
  const mxArray *c24_rhs25 = NULL;
  const mxArray *c24_lhs25 = NULL;
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 0);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1383877294U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c24_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 1);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c24_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 2);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 2);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c24_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 3);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 3);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c24_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 4);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c24_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 5);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 5);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c24_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 6);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("eml_xdotu"), "name", "name",
                  6);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1375980690U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c24_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 7);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c24_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("coder.internal.blas.xdotu"),
                  "name", "name", 8);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdotu.p"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c24_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdotu.p"),
                  "context", "context", 9);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("coder.internal.blas.xdot"),
                  "name", "name", 9);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c24_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p"),
                  "context", "context", 10);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 10);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c24_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p!below_threshold"),
                  "context", "context", 11);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 11);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c24_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 12);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 12);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1393330858U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c24_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p"),
                  "context", "context", 13);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("coder.internal.refblas.xdot"),
                  "name", "name", 13);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdot.p"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c24_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdot.p"),
                  "context", "context", 14);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "coder.internal.refblas.xdotx"), "name", "name", 14);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c24_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 15);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 15);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c24_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 16);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 16);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1372583160U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c24_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 17);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 17);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 17);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1372583160U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c24_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 18);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 18);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 18);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1372583160U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c24_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 19);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 19);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1397257422U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c24_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 20);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("isfi"), "name", "name", 20);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 20);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1346510358U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c24_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("isnumerictype"), "name",
                  "name", 21);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                  "resolved", 21);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1398875598U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c24_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 22);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("intmax"), "name", "name", 22);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1362261882U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c24_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 23);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 23);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1393330858U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c24_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 24);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("intmin"), "name", "name", 24);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 24);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1362261882U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c24_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 25);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 25);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1393330858U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c24_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs25), "lhs", "lhs",
                  25);
  sf_mex_destroy(&c24_rhs0);
  sf_mex_destroy(&c24_lhs0);
  sf_mex_destroy(&c24_rhs1);
  sf_mex_destroy(&c24_lhs1);
  sf_mex_destroy(&c24_rhs2);
  sf_mex_destroy(&c24_lhs2);
  sf_mex_destroy(&c24_rhs3);
  sf_mex_destroy(&c24_lhs3);
  sf_mex_destroy(&c24_rhs4);
  sf_mex_destroy(&c24_lhs4);
  sf_mex_destroy(&c24_rhs5);
  sf_mex_destroy(&c24_lhs5);
  sf_mex_destroy(&c24_rhs6);
  sf_mex_destroy(&c24_lhs6);
  sf_mex_destroy(&c24_rhs7);
  sf_mex_destroy(&c24_lhs7);
  sf_mex_destroy(&c24_rhs8);
  sf_mex_destroy(&c24_lhs8);
  sf_mex_destroy(&c24_rhs9);
  sf_mex_destroy(&c24_lhs9);
  sf_mex_destroy(&c24_rhs10);
  sf_mex_destroy(&c24_lhs10);
  sf_mex_destroy(&c24_rhs11);
  sf_mex_destroy(&c24_lhs11);
  sf_mex_destroy(&c24_rhs12);
  sf_mex_destroy(&c24_lhs12);
  sf_mex_destroy(&c24_rhs13);
  sf_mex_destroy(&c24_lhs13);
  sf_mex_destroy(&c24_rhs14);
  sf_mex_destroy(&c24_lhs14);
  sf_mex_destroy(&c24_rhs15);
  sf_mex_destroy(&c24_lhs15);
  sf_mex_destroy(&c24_rhs16);
  sf_mex_destroy(&c24_lhs16);
  sf_mex_destroy(&c24_rhs17);
  sf_mex_destroy(&c24_lhs17);
  sf_mex_destroy(&c24_rhs18);
  sf_mex_destroy(&c24_lhs18);
  sf_mex_destroy(&c24_rhs19);
  sf_mex_destroy(&c24_lhs19);
  sf_mex_destroy(&c24_rhs20);
  sf_mex_destroy(&c24_lhs20);
  sf_mex_destroy(&c24_rhs21);
  sf_mex_destroy(&c24_lhs21);
  sf_mex_destroy(&c24_rhs22);
  sf_mex_destroy(&c24_lhs22);
  sf_mex_destroy(&c24_rhs23);
  sf_mex_destroy(&c24_lhs23);
  sf_mex_destroy(&c24_rhs24);
  sf_mex_destroy(&c24_lhs24);
  sf_mex_destroy(&c24_rhs25);
  sf_mex_destroy(&c24_lhs25);
}

static const mxArray *c24_emlrt_marshallOut(const char * c24_u)
{
  const mxArray *c24_y = NULL;
  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_create("y", c24_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c24_u)), false);
  return c24_y;
}

static const mxArray *c24_b_emlrt_marshallOut(const uint32_T c24_u)
{
  const mxArray *c24_y = NULL;
  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_create("y", &c24_u, 7, 0U, 0U, 0U, 0), false);
  return c24_y;
}

static real_T c24_eml_xdotu(SFc24_ModifiedInstanceStruct *chartInstance, real_T
  c24_x[2], real_T c24_y[2])
{
  real_T c24_d;
  int32_T c24_k;
  int32_T c24_b_k;
  (void)chartInstance;
  c24_d = 0.0;
  for (c24_k = 1; c24_k < 3; c24_k++) {
    c24_b_k = c24_k;
    c24_d += c24_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c24_b_k), 1, 2, 1, 0) - 1] * c24_y[_SFD_EML_ARRAY_BOUNDS_CHECK
      ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c24_b_k), 1, 2, 1, 0) - 1];
  }

  return c24_d;
}

static const mxArray *c24_d_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData)
{
  const mxArray *c24_mxArrayOutData = NULL;
  int32_T c24_u;
  const mxArray *c24_y = NULL;
  SFc24_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc24_ModifiedInstanceStruct *)chartInstanceVoid;
  c24_mxArrayOutData = NULL;
  c24_u = *(int32_T *)c24_inData;
  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_create("y", &c24_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c24_mxArrayOutData, c24_y, false);
  return c24_mxArrayOutData;
}

static int32_T c24_m_emlrt_marshallIn(SFc24_ModifiedInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId)
{
  int32_T c24_y;
  int32_T c24_i27;
  (void)chartInstance;
  sf_mex_import(c24_parentId, sf_mex_dup(c24_u), &c24_i27, 1, 6, 0U, 0, 0U, 0);
  c24_y = c24_i27;
  sf_mex_destroy(&c24_u);
  return c24_y;
}

static void c24_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData)
{
  const mxArray *c24_b_sfEvent;
  const char_T *c24_identifier;
  emlrtMsgIdentifier c24_thisId;
  int32_T c24_y;
  SFc24_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc24_ModifiedInstanceStruct *)chartInstanceVoid;
  c24_b_sfEvent = sf_mex_dup(c24_mxArrayInData);
  c24_identifier = c24_varName;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_y = c24_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_b_sfEvent),
    &c24_thisId);
  sf_mex_destroy(&c24_b_sfEvent);
  *(int32_T *)c24_outData = c24_y;
  sf_mex_destroy(&c24_mxArrayInData);
}

static const mxArray *c24_v_z4_bus_io(void *chartInstanceVoid, void *c24_pData)
{
  const mxArray *c24_mxVal = NULL;
  c24_whl_vec4 c24_tmp;
  SFc24_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc24_ModifiedInstanceStruct *)chartInstanceVoid;
  c24_mxVal = NULL;
  c24_tmp.fl = *(real_T *)&((char_T *)(c24_whl_vec4 *)c24_pData)[0];
  c24_tmp.fr = *(real_T *)&((char_T *)(c24_whl_vec4 *)c24_pData)[8];
  c24_tmp.rl = *(real_T *)&((char_T *)(c24_whl_vec4 *)c24_pData)[16];
  c24_tmp.rr = *(real_T *)&((char_T *)(c24_whl_vec4 *)c24_pData)[24];
  sf_mex_assign(&c24_mxVal, c24_sf_marshallOut(chartInstance, &c24_tmp), false);
  return c24_mxVal;
}

static uint8_T c24_n_emlrt_marshallIn(SFc24_ModifiedInstanceStruct
  *chartInstance, const mxArray *c24_b_is_active_c24_Modified, const char_T
  *c24_identifier)
{
  uint8_T c24_y;
  emlrtMsgIdentifier c24_thisId;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_y = c24_o_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c24_b_is_active_c24_Modified), &c24_thisId);
  sf_mex_destroy(&c24_b_is_active_c24_Modified);
  return c24_y;
}

static uint8_T c24_o_emlrt_marshallIn(SFc24_ModifiedInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId)
{
  uint8_T c24_y;
  uint8_T c24_u0;
  (void)chartInstance;
  sf_mex_import(c24_parentId, sf_mex_dup(c24_u), &c24_u0, 1, 3, 0U, 0, 0U, 0);
  c24_y = c24_u0;
  sf_mex_destroy(&c24_u);
  return c24_y;
}

static void init_dsm_address_info(SFc24_ModifiedInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc24_ModifiedInstanceStruct *chartInstance)
{
  chartInstance->c24_v_z4 = (c24_whl_vec4 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c24_derF_s4 = (c24_whl_vec4 *)ssGetOutputPortSignal_wrapper
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

void sf_c24_Modified_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4259005072U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1216813363U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1384874681U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4051693430U);
}

mxArray* sf_c24_Modified_get_post_codegen_info(void);
mxArray *sf_c24_Modified_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("XHzXl0mgVcLlXLQ5uaqgrG");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
    mxArray* mxPostCodegenInfo = sf_c24_Modified_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c24_Modified_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c24_Modified_jit_fallback_info(void)
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

mxArray *sf_c24_Modified_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c24_Modified_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c24_Modified(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[7],T\"derF_s4\",},{M[8],M[0],T\"is_active_c24_Modified\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c24_Modified_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc24_ModifiedInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc24_ModifiedInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ModifiedMachineNumber_,
           24,
           1,
           1,
           0,
           3,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"v_z4");
          _SFD_SET_DATA_PROPS(1,2,0,1,"derF_s4");
          _SFD_SET_DATA_PROPS(2,10,0,0,"Par");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,383);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c24_v_z4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c24_v_z4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c24_b_sf_marshallOut,(MexInFcnForType)
          c24_b_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c24_v_z4);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c24_derF_s4);
        _SFD_SET_DATA_VALUE_PTR(2U, &chartInstance->c24_Par);
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
  return "lBiAltMC72HqN30bOEc17E";
}

static void sf_opaque_initialize_c24_Modified(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc24_ModifiedInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c24_Modified((SFc24_ModifiedInstanceStruct*)
    chartInstanceVar);
  initialize_c24_Modified((SFc24_ModifiedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c24_Modified(void *chartInstanceVar)
{
  enable_c24_Modified((SFc24_ModifiedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c24_Modified(void *chartInstanceVar)
{
  disable_c24_Modified((SFc24_ModifiedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c24_Modified(void *chartInstanceVar)
{
  sf_gateway_c24_Modified((SFc24_ModifiedInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c24_Modified(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c24_Modified((SFc24_ModifiedInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c24_Modified(SimStruct* S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c24_Modified((SFc24_ModifiedInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c24_Modified(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc24_ModifiedInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Modified_optimization_info();
    }

    finalize_c24_Modified((SFc24_ModifiedInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc24_Modified((SFc24_ModifiedInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c24_Modified(SimStruct *S)
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
    initialize_params_c24_Modified((SFc24_ModifiedInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c24_Modified(SimStruct *S)
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
      24);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,24,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,24,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,24);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,24,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,24,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,24);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(564110241U));
  ssSetChecksum1(S,(429611429U));
  ssSetChecksum2(S,(2166877807U));
  ssSetChecksum3(S,(3876843973U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c24_Modified(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c24_Modified(SimStruct *S)
{
  SFc24_ModifiedInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc24_ModifiedInstanceStruct *)utMalloc(sizeof
    (SFc24_ModifiedInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc24_ModifiedInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c24_Modified;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c24_Modified;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c24_Modified;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c24_Modified;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c24_Modified;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c24_Modified;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c24_Modified;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c24_Modified;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c24_Modified;
  chartInstance->chartInfo.mdlStart = mdlStart_c24_Modified;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c24_Modified;
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

void c24_Modified_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c24_Modified(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c24_Modified(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c24_Modified(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c24_Modified_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
