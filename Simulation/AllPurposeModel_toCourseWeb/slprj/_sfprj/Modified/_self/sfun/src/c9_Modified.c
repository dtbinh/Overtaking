/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Modified_sfun.h"
#include "c9_Modified.h"
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
static const char * c9_debug_family_names[9] = { "d1", "d2", "d3", "d4",
  "nargin", "nargout", "v_z4", "Par", "F_d4" };

/* Function Declarations */
static void initialize_c9_Modified(SFc9_ModifiedInstanceStruct *chartInstance);
static void initialize_params_c9_Modified(SFc9_ModifiedInstanceStruct
  *chartInstance);
static void enable_c9_Modified(SFc9_ModifiedInstanceStruct *chartInstance);
static void disable_c9_Modified(SFc9_ModifiedInstanceStruct *chartInstance);
static void c9_update_debugger_state_c9_Modified(SFc9_ModifiedInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c9_Modified(SFc9_ModifiedInstanceStruct
  *chartInstance);
static void set_sim_state_c9_Modified(SFc9_ModifiedInstanceStruct *chartInstance,
  const mxArray *c9_st);
static void finalize_c9_Modified(SFc9_ModifiedInstanceStruct *chartInstance);
static void sf_gateway_c9_Modified(SFc9_ModifiedInstanceStruct *chartInstance);
static void mdl_start_c9_Modified(SFc9_ModifiedInstanceStruct *chartInstance);
static void initSimStructsc9_Modified(SFc9_ModifiedInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber, uint32_T c9_instanceNumber);
static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData);
static c9_whl_vec4 c9_emlrt_marshallIn(SFc9_ModifiedInstanceStruct
  *chartInstance, const mxArray *c9_b_F_d4, const char_T *c9_identifier);
static c9_whl_vec4 c9_b_emlrt_marshallIn(SFc9_ModifiedInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static real_T c9_c_emlrt_marshallIn(SFc9_ModifiedInstanceStruct *chartInstance,
  const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_d_emlrt_marshallIn(SFc9_ModifiedInstanceStruct *chartInstance,
  const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  c9_struct_iBlsPBO3AGnt69vDoTx5zD *c9_y);
static void c9_e_emlrt_marshallIn(SFc9_ModifiedInstanceStruct *chartInstance,
  const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  c9_struct_Nst2vGTExxHsg85EUOj9EH *c9_y);
static c9_struct_HhckT6rntEraqECYVIDvCC c9_f_emlrt_marshallIn
  (SFc9_ModifiedInstanceStruct *chartInstance, const mxArray *c9_u, const
   emlrtMsgIdentifier *c9_parentId);
static void c9_g_emlrt_marshallIn(SFc9_ModifiedInstanceStruct *chartInstance,
  const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  c9_struct_ZCmOWPuqBDw16FSOVVD00 *c9_y);
static void c9_h_emlrt_marshallIn(SFc9_ModifiedInstanceStruct *chartInstance,
  const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId, real_T c9_y[4]);
static void c9_i_emlrt_marshallIn(SFc9_ModifiedInstanceStruct *chartInstance,
  const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  c9_struct_ZKAzdrl7umDGJoC14aoVKC *c9_y);
static void c9_j_emlrt_marshallIn(SFc9_ModifiedInstanceStruct *chartInstance,
  const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId, real_T c9_y[3]);
static c9_struct_r4FNviKwHfdhB8nQjvQv9 c9_k_emlrt_marshallIn
  (SFc9_ModifiedInstanceStruct *chartInstance, const mxArray *c9_u, const
   emlrtMsgIdentifier *c9_parentId);
static c9_struct_Y9F1qlBi9AhssksPwemA4G c9_l_emlrt_marshallIn
  (SFc9_ModifiedInstanceStruct *chartInstance, const mxArray *c9_u, const
   emlrtMsgIdentifier *c9_parentId);
static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_d_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static int32_T c9_m_emlrt_marshallIn(SFc9_ModifiedInstanceStruct *chartInstance,
  const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_v_z4_bus_io(void *chartInstanceVoid, void *c9_pData);
static uint8_T c9_n_emlrt_marshallIn(SFc9_ModifiedInstanceStruct *chartInstance,
  const mxArray *c9_b_is_active_c9_Modified, const char_T *c9_identifier);
static uint8_T c9_o_emlrt_marshallIn(SFc9_ModifiedInstanceStruct *chartInstance,
  const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void init_dsm_address_info(SFc9_ModifiedInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc9_ModifiedInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c9_Modified(SFc9_ModifiedInstanceStruct *chartInstance)
{
  chartInstance->c9_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c9_is_active_c9_Modified = 0U;
}

static void initialize_params_c9_Modified(SFc9_ModifiedInstanceStruct
  *chartInstance)
{
  const mxArray *c9_m0 = NULL;
  const mxArray *c9_mxField;
  const mxArray *c9_m1 = NULL;
  const mxArray *c9_b_mxField;
  c9_struct_iBlsPBO3AGnt69vDoTx5zD c9_r0;
  const mxArray *c9_m2 = NULL;
  const mxArray *c9_c_mxField;
  const mxArray *c9_m3 = NULL;
  const mxArray *c9_d_mxField;
  const mxArray *c9_m4 = NULL;
  const mxArray *c9_e_mxField;
  const mxArray *c9_m5 = NULL;
  const mxArray *c9_f_mxField;
  const mxArray *c9_m6 = NULL;
  const mxArray *c9_g_mxField;
  const mxArray *c9_m7 = NULL;
  const mxArray *c9_h_mxField;
  const mxArray *c9_m8 = NULL;
  const mxArray *c9_i_mxField;
  const mxArray *c9_m9 = NULL;
  const mxArray *c9_j_mxField;
  const mxArray *c9_m10 = NULL;
  const mxArray *c9_k_mxField;
  const mxArray *c9_m11 = NULL;
  const mxArray *c9_l_mxField;
  const mxArray *c9_m12 = NULL;
  const mxArray *c9_m_mxField;
  const mxArray *c9_m13 = NULL;
  const mxArray *c9_n_mxField;
  c9_m0 = sf_mex_get_sfun_param(chartInstance->S, 0, 1);
  c9_mxField = sf_mex_getfield(c9_m0, "Env", "Par", 0);
  c9_m1 = sf_mex_dup(c9_mxField);
  c9_b_mxField = sf_mex_getfield(c9_m1, "g", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_b_mxField), &c9_r0.Env.g, 1, 0, 0U, 0,
                      0U, 0);
  c9_b_mxField = sf_mex_getfield(c9_m1, "left1", "Par", 0);
  c9_m2 = sf_mex_dup(c9_b_mxField);
  c9_c_mxField = sf_mex_getfield(c9_m2, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_c_mxField), &c9_r0.Env.left1.x, 1, 0,
                      0U, 0, 0U, 0);
  c9_c_mxField = sf_mex_getfield(c9_m2, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_c_mxField), &c9_r0.Env.left1.y, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c9_m2);
  c9_b_mxField = sf_mex_getfield(c9_m1, "right1", "Par", 0);
  c9_m3 = sf_mex_dup(c9_b_mxField);
  c9_d_mxField = sf_mex_getfield(c9_m3, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_d_mxField), &c9_r0.Env.right1.x, 1, 0,
                      0U, 0, 0U, 0);
  c9_d_mxField = sf_mex_getfield(c9_m3, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_d_mxField), &c9_r0.Env.right1.y, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c9_m3);
  c9_b_mxField = sf_mex_getfield(c9_m1, "right2", "Par", 0);
  c9_m4 = sf_mex_dup(c9_b_mxField);
  c9_e_mxField = sf_mex_getfield(c9_m4, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_e_mxField), &c9_r0.Env.right2.x, 1, 0,
                      0U, 0, 0U, 0);
  c9_e_mxField = sf_mex_getfield(c9_m4, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_e_mxField), &c9_r0.Env.right2.y, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c9_m4);
  c9_b_mxField = sf_mex_getfield(c9_m1, "left2", "Par", 0);
  c9_m5 = sf_mex_dup(c9_b_mxField);
  c9_f_mxField = sf_mex_getfield(c9_m5, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_f_mxField), &c9_r0.Env.left2.x, 1, 0,
                      0U, 0, 0U, 0);
  c9_f_mxField = sf_mex_getfield(c9_m5, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_f_mxField), &c9_r0.Env.left2.y, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c9_m5);
  c9_b_mxField = sf_mex_getfield(c9_m1, "right3", "Par", 0);
  c9_m6 = sf_mex_dup(c9_b_mxField);
  c9_g_mxField = sf_mex_getfield(c9_m6, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_g_mxField), &c9_r0.Env.right3.x, 1, 0,
                      0U, 0, 0U, 0);
  c9_g_mxField = sf_mex_getfield(c9_m6, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_g_mxField), &c9_r0.Env.right3.y, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c9_m6);
  c9_b_mxField = sf_mex_getfield(c9_m1, "mu", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_b_mxField), &c9_r0.Env.mu, 1, 0, 0U,
                      0, 0U, 0);
  sf_mex_destroy(&c9_m1);
  c9_mxField = sf_mex_getfield(c9_m0, "Veh", "Par", 0);
  c9_m7 = sf_mex_dup(c9_mxField);
  c9_h_mxField = sf_mex_getfield(c9_m7, "m", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_h_mxField), &c9_r0.Veh.m, 1, 0, 0U, 0,
                      0U, 0);
  c9_h_mxField = sf_mex_getfield(c9_m7, "Jz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_h_mxField), &c9_r0.Veh.Jz, 1, 0, 0U,
                      0, 0U, 0);
  c9_h_mxField = sf_mex_getfield(c9_m7, "m_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_h_mxField), &c9_r0.Veh.m_sprung, 1, 0,
                      0U, 0, 0U, 0);
  c9_h_mxField = sf_mex_getfield(c9_m7, "Jx_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_h_mxField), &c9_r0.Veh.Jx_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c9_h_mxField = sf_mex_getfield(c9_m7, "Jy_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_h_mxField), &c9_r0.Veh.Jy_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c9_h_mxField = sf_mex_getfield(c9_m7, "lf", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_h_mxField), &c9_r0.Veh.lf, 1, 0, 0U,
                      0, 0U, 0);
  c9_h_mxField = sf_mex_getfield(c9_m7, "lr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_h_mxField), &c9_r0.Veh.lr, 1, 0, 0U,
                      0, 0U, 0);
  c9_h_mxField = sf_mex_getfield(c9_m7, "L", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_h_mxField), &c9_r0.Veh.L, 1, 0, 0U, 0,
                      0U, 0);
  c9_h_mxField = sf_mex_getfield(c9_m7, "TrackWidth", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_h_mxField), &c9_r0.Veh.TrackWidth, 1,
                      0, 0U, 0, 0U, 0);
  c9_h_mxField = sf_mex_getfield(c9_m7, "h", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_h_mxField), &c9_r0.Veh.h, 1, 0, 0U, 0,
                      0U, 0);
  c9_h_mxField = sf_mex_getfield(c9_m7, "HalfRohACd", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_h_mxField), &c9_r0.Veh.HalfRohACd, 1,
                      0, 0U, 0, 0U, 0);
  c9_h_mxField = sf_mex_getfield(c9_m7, "F_z4_static", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_h_mxField), c9_r0.Veh.F_z4_static, 1,
                      0, 0U, 1, 0U, 2, 1, 4);
  c9_h_mxField = sf_mex_getfield(c9_m7, "Rw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_h_mxField), &c9_r0.Veh.Rw, 1, 0, 0U,
                      0, 0U, 0);
  c9_h_mxField = sf_mex_getfield(c9_m7, "r_long", "Par", 0);
  c9_m8 = sf_mex_dup(c9_h_mxField);
  c9_i_mxField = sf_mex_getfield(c9_m8, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_i_mxField), c9_r0.Veh.r_long.fl, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  c9_i_mxField = sf_mex_getfield(c9_m8, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_i_mxField), c9_r0.Veh.r_long.fr, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  c9_i_mxField = sf_mex_getfield(c9_m8, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_i_mxField), c9_r0.Veh.r_long.rl, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  c9_i_mxField = sf_mex_getfield(c9_m8, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_i_mxField), c9_r0.Veh.r_long.rr, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c9_m8);
  c9_h_mxField = sf_mex_getfield(c9_m7, "r_lat", "Par", 0);
  c9_m9 = sf_mex_dup(c9_h_mxField);
  c9_j_mxField = sf_mex_getfield(c9_m9, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_j_mxField), c9_r0.Veh.r_lat.fl, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  c9_j_mxField = sf_mex_getfield(c9_m9, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_j_mxField), c9_r0.Veh.r_lat.fr, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  c9_j_mxField = sf_mex_getfield(c9_m9, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_j_mxField), c9_r0.Veh.r_lat.rl, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  c9_j_mxField = sf_mex_getfield(c9_m9, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_j_mxField), c9_r0.Veh.r_lat.rr, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c9_m9);
  c9_h_mxField = sf_mex_getfield(c9_m7, "r_lever", "Par", 0);
  c9_m10 = sf_mex_dup(c9_h_mxField);
  c9_k_mxField = sf_mex_getfield(c9_m10, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_k_mxField), c9_r0.Veh.r_lever.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c9_k_mxField = sf_mex_getfield(c9_m10, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_k_mxField), c9_r0.Veh.r_lever.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c9_k_mxField = sf_mex_getfield(c9_m10, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_k_mxField), c9_r0.Veh.r_lever.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c9_k_mxField = sf_mex_getfield(c9_m10, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_k_mxField), c9_r0.Veh.r_lever.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c9_m10);
  c9_h_mxField = sf_mex_getfield(c9_m7, "r_pivot", "Par", 0);
  c9_m11 = sf_mex_dup(c9_h_mxField);
  c9_l_mxField = sf_mex_getfield(c9_m11, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_l_mxField), c9_r0.Veh.r_pivot.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c9_l_mxField = sf_mex_getfield(c9_m11, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_l_mxField), c9_r0.Veh.r_pivot.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c9_l_mxField = sf_mex_getfield(c9_m11, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_l_mxField), c9_r0.Veh.r_pivot.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c9_l_mxField = sf_mex_getfield(c9_m11, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_l_mxField), c9_r0.Veh.r_pivot.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c9_m11);
  c9_h_mxField = sf_mex_getfield(c9_m7, "cw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_h_mxField), &c9_r0.Veh.cw, 1, 0, 0U,
                      0, 0U, 0);
  c9_h_mxField = sf_mex_getfield(c9_m7, "carb_f", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_h_mxField), &c9_r0.Veh.carb_f, 1, 0,
                      0U, 0, 0U, 0);
  c9_h_mxField = sf_mex_getfield(c9_m7, "carb_r", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_h_mxField), &c9_r0.Veh.carb_r, 1, 0,
                      0U, 0, 0U, 0);
  c9_h_mxField = sf_mex_getfield(c9_m7, "dw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_h_mxField), &c9_r0.Veh.dw, 1, 0, 0U,
                      0, 0U, 0);
  c9_h_mxField = sf_mex_getfield(c9_m7, "Jw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_h_mxField), &c9_r0.Veh.Jw, 1, 0, 0U,
                      0, 0U, 0);
  c9_h_mxField = sf_mex_getfield(c9_m7, "C0", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_h_mxField), &c9_r0.Veh.C0, 1, 0, 0U,
                      0, 0U, 0);
  c9_h_mxField = sf_mex_getfield(c9_m7, "RelaxLength", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_h_mxField), &c9_r0.Veh.RelaxLength, 1,
                      0, 0U, 0, 0U, 0);
  c9_h_mxField = sf_mex_getfield(c9_m7, "RRC", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_h_mxField), &c9_r0.Veh.RRC, 1, 0, 0U,
                      0, 0U, 0);
  c9_h_mxField = sf_mex_getfield(c9_m7, "Pmax", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_h_mxField), &c9_r0.Veh.Pmax, 1, 0, 0U,
                      0, 0U, 0);
  c9_h_mxField = sf_mex_getfield(c9_m7, "PropDistrFrnt", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_h_mxField), &c9_r0.Veh.PropDistrFrnt,
                      1, 0, 0U, 0, 0U, 0);
  c9_h_mxField = sf_mex_getfield(c9_m7, "BrkDistrFrnt", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_h_mxField), &c9_r0.Veh.BrkDistrFrnt,
                      1, 0, 0U, 0, 0U, 0);
  c9_h_mxField = sf_mex_getfield(c9_m7, "SteRatio", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_h_mxField), &c9_r0.Veh.SteRatio, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c9_m7);
  c9_mxField = sf_mex_getfield(c9_m0, "Drvr", "Par", 0);
  c9_m12 = sf_mex_dup(c9_mxField);
  c9_m_mxField = sf_mex_getfield(c9_m12, "v_set", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_m_mxField), &c9_r0.Drvr.v_set, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c9_m12);
  c9_mxField = sf_mex_getfield(c9_m0, "Init", "Par", 0);
  c9_m13 = sf_mex_dup(c9_mxField);
  c9_n_mxField = sf_mex_getfield(c9_m13, "v_x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_n_mxField), &c9_r0.Init.v_x, 1, 0, 0U,
                      0, 0U, 0);
  c9_n_mxField = sf_mex_getfield(c9_m13, "F_fz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_n_mxField), &c9_r0.Init.F_fz, 1, 0,
                      0U, 0, 0U, 0);
  c9_n_mxField = sf_mex_getfield(c9_m13, "F_rz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c9_n_mxField), &c9_r0.Init.F_rz, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c9_m13);
  sf_mex_destroy(&c9_m0);
  chartInstance->c9_Par = c9_r0;
}

static void enable_c9_Modified(SFc9_ModifiedInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c9_Modified(SFc9_ModifiedInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c9_update_debugger_state_c9_Modified(SFc9_ModifiedInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c9_Modified(SFc9_ModifiedInstanceStruct
  *chartInstance)
{
  const mxArray *c9_st;
  const mxArray *c9_y = NULL;
  const mxArray *c9_b_y = NULL;
  real_T c9_u;
  const mxArray *c9_c_y = NULL;
  real_T c9_b_u;
  const mxArray *c9_d_y = NULL;
  real_T c9_c_u;
  const mxArray *c9_e_y = NULL;
  real_T c9_d_u;
  const mxArray *c9_f_y = NULL;
  uint8_T c9_hoistedGlobal;
  uint8_T c9_e_u;
  const mxArray *c9_g_y = NULL;
  c9_st = NULL;
  c9_st = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_createcellmatrix(2, 1), false);
  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c9_u = *(real_T *)&((char_T *)chartInstance->c9_F_d4)[0];
  c9_c_y = NULL;
  sf_mex_assign(&c9_c_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c9_b_y, c9_c_y, "fl", "fl", 0);
  c9_b_u = *(real_T *)&((char_T *)chartInstance->c9_F_d4)[8];
  c9_d_y = NULL;
  sf_mex_assign(&c9_d_y, sf_mex_create("y", &c9_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c9_b_y, c9_d_y, "fr", "fr", 0);
  c9_c_u = *(real_T *)&((char_T *)chartInstance->c9_F_d4)[16];
  c9_e_y = NULL;
  sf_mex_assign(&c9_e_y, sf_mex_create("y", &c9_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c9_b_y, c9_e_y, "rl", "rl", 0);
  c9_d_u = *(real_T *)&((char_T *)chartInstance->c9_F_d4)[24];
  c9_f_y = NULL;
  sf_mex_assign(&c9_f_y, sf_mex_create("y", &c9_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c9_b_y, c9_f_y, "rr", "rr", 0);
  sf_mex_setcell(c9_y, 0, c9_b_y);
  c9_hoistedGlobal = chartInstance->c9_is_active_c9_Modified;
  c9_e_u = c9_hoistedGlobal;
  c9_g_y = NULL;
  sf_mex_assign(&c9_g_y, sf_mex_create("y", &c9_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 1, c9_g_y);
  sf_mex_assign(&c9_st, c9_y, false);
  return c9_st;
}

static void set_sim_state_c9_Modified(SFc9_ModifiedInstanceStruct *chartInstance,
  const mxArray *c9_st)
{
  const mxArray *c9_u;
  c9_whl_vec4 c9_r1;
  chartInstance->c9_doneDoubleBufferReInit = true;
  c9_u = sf_mex_dup(c9_st);
  c9_r1 = c9_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 0)),
    "F_d4");
  *(real_T *)&((char_T *)chartInstance->c9_F_d4)[0] = c9_r1.fl;
  *(real_T *)&((char_T *)chartInstance->c9_F_d4)[8] = c9_r1.fr;
  *(real_T *)&((char_T *)chartInstance->c9_F_d4)[16] = c9_r1.rl;
  *(real_T *)&((char_T *)chartInstance->c9_F_d4)[24] = c9_r1.rr;
  chartInstance->c9_is_active_c9_Modified = c9_n_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 1)), "is_active_c9_Modified");
  sf_mex_destroy(&c9_u);
  c9_update_debugger_state_c9_Modified(chartInstance);
  sf_mex_destroy(&c9_st);
}

static void finalize_c9_Modified(SFc9_ModifiedInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c9_Modified(SFc9_ModifiedInstanceStruct *chartInstance)
{
  c9_whl_vec4 c9_b_v_z4;
  c9_struct_iBlsPBO3AGnt69vDoTx5zD c9_b_Par;
  uint32_T c9_debug_family_var_map[9];
  real_T c9_d1;
  real_T c9_d2;
  real_T c9_d3;
  real_T c9_d4;
  real_T c9_nargin = 2.0;
  real_T c9_nargout = 1.0;
  c9_whl_vec4 c9_b_F_d4;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 6U, chartInstance->c9_sfEvent);
  chartInstance->c9_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c9_sfEvent);
  c9_b_v_z4.fl = *(real_T *)&((char_T *)chartInstance->c9_v_z4)[0];
  c9_b_v_z4.fr = *(real_T *)&((char_T *)chartInstance->c9_v_z4)[8];
  c9_b_v_z4.rl = *(real_T *)&((char_T *)chartInstance->c9_v_z4)[16];
  c9_b_v_z4.rr = *(real_T *)&((char_T *)chartInstance->c9_v_z4)[24];
  c9_b_Par = chartInstance->c9_Par;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_d1, 0U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_d2, 1U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_d3, 2U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_d4, 3U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 4U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 5U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_b_v_z4, 6U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_Par, 7U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_F_d4, 8U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 5);
  c9_d1 = c9_b_Par.Veh.dw;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 6);
  c9_d2 = c9_b_Par.Veh.dw;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_d3 = c9_b_Par.Veh.dw;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_d4 = c9_b_Par.Veh.dw;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 10);
  c9_b_F_d4.fl = -c9_d1 * c9_b_v_z4.fl;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 11);
  c9_b_F_d4.fr = -c9_d2 * c9_b_v_z4.fr;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 12);
  c9_b_F_d4.rl = -c9_d3 * c9_b_v_z4.rl;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 13);
  c9_b_F_d4.rr = -c9_d4 * c9_b_v_z4.rr;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, -13);
  _SFD_SYMBOL_SCOPE_POP();
  *(real_T *)&((char_T *)chartInstance->c9_F_d4)[0] = c9_b_F_d4.fl;
  *(real_T *)&((char_T *)chartInstance->c9_F_d4)[8] = c9_b_F_d4.fr;
  *(real_T *)&((char_T *)chartInstance->c9_F_d4)[16] = c9_b_F_d4.rl;
  *(real_T *)&((char_T *)chartInstance->c9_F_d4)[24] = c9_b_F_d4.rr;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c9_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_ModifiedMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c9_Modified(SFc9_ModifiedInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc9_Modified(SFc9_ModifiedInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber, uint32_T c9_instanceNumber)
{
  (void)c9_machineNumber;
  (void)c9_chartNumber;
  (void)c9_instanceNumber;
}

static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  c9_whl_vec4 c9_u;
  const mxArray *c9_y = NULL;
  real_T c9_b_u;
  const mxArray *c9_b_y = NULL;
  real_T c9_c_u;
  const mxArray *c9_c_y = NULL;
  real_T c9_d_u;
  const mxArray *c9_d_y = NULL;
  real_T c9_e_u;
  const mxArray *c9_e_y = NULL;
  SFc9_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc9_ModifiedInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(c9_whl_vec4 *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c9_b_u = c9_u.fl;
  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c9_y, c9_b_y, "fl", "fl", 0);
  c9_c_u = c9_u.fr;
  c9_c_y = NULL;
  sf_mex_assign(&c9_c_y, sf_mex_create("y", &c9_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c9_y, c9_c_y, "fr", "fr", 0);
  c9_d_u = c9_u.rl;
  c9_d_y = NULL;
  sf_mex_assign(&c9_d_y, sf_mex_create("y", &c9_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c9_y, c9_d_y, "rl", "rl", 0);
  c9_e_u = c9_u.rr;
  c9_e_y = NULL;
  sf_mex_assign(&c9_e_y, sf_mex_create("y", &c9_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c9_y, c9_e_y, "rr", "rr", 0);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static c9_whl_vec4 c9_emlrt_marshallIn(SFc9_ModifiedInstanceStruct
  *chartInstance, const mxArray *c9_b_F_d4, const char_T *c9_identifier)
{
  c9_whl_vec4 c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_F_d4), &c9_thisId);
  sf_mex_destroy(&c9_b_F_d4);
  return c9_y;
}

static c9_whl_vec4 c9_b_emlrt_marshallIn(SFc9_ModifiedInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  c9_whl_vec4 c9_y;
  emlrtMsgIdentifier c9_thisId;
  static const char * c9_fieldNames[4] = { "fl", "fr", "rl", "rr" };

  c9_thisId.fParent = c9_parentId;
  sf_mex_check_struct(c9_parentId, c9_u, 4, c9_fieldNames, 0U, NULL);
  c9_thisId.fIdentifier = "fl";
  c9_y.fl = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c9_u,
    "fl", "fl", 0)), &c9_thisId);
  c9_thisId.fIdentifier = "fr";
  c9_y.fr = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c9_u,
    "fr", "fr", 0)), &c9_thisId);
  c9_thisId.fIdentifier = "rl";
  c9_y.rl = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c9_u,
    "rl", "rl", 0)), &c9_thisId);
  c9_thisId.fIdentifier = "rr";
  c9_y.rr = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c9_u,
    "rr", "rr", 0)), &c9_thisId);
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static real_T c9_c_emlrt_marshallIn(SFc9_ModifiedInstanceStruct *chartInstance,
  const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  real_T c9_y;
  real_T c9_d0;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_d0, 1, 0, 0U, 0, 0U, 0);
  c9_y = c9_d0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_F_d4;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  c9_whl_vec4 c9_y;
  SFc9_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc9_ModifiedInstanceStruct *)chartInstanceVoid;
  c9_b_F_d4 = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_F_d4), &c9_thisId);
  sf_mex_destroy(&c9_b_F_d4);
  *(c9_whl_vec4 *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData;
  c9_struct_iBlsPBO3AGnt69vDoTx5zD c9_u;
  const mxArray *c9_y = NULL;
  c9_struct_Nst2vGTExxHsg85EUOj9EH c9_b_u;
  const mxArray *c9_b_y = NULL;
  real_T c9_c_u;
  const mxArray *c9_c_y = NULL;
  c9_struct_HhckT6rntEraqECYVIDvCC c9_d_u;
  const mxArray *c9_d_y = NULL;
  real_T c9_e_u;
  const mxArray *c9_e_y = NULL;
  real_T c9_f_u;
  const mxArray *c9_f_y = NULL;
  const mxArray *c9_g_y = NULL;
  real_T c9_g_u;
  const mxArray *c9_h_y = NULL;
  real_T c9_h_u;
  const mxArray *c9_i_y = NULL;
  const mxArray *c9_j_y = NULL;
  real_T c9_i_u;
  const mxArray *c9_k_y = NULL;
  real_T c9_j_u;
  const mxArray *c9_l_y = NULL;
  const mxArray *c9_m_y = NULL;
  real_T c9_k_u;
  const mxArray *c9_n_y = NULL;
  real_T c9_l_u;
  const mxArray *c9_o_y = NULL;
  const mxArray *c9_p_y = NULL;
  real_T c9_m_u;
  const mxArray *c9_q_y = NULL;
  real_T c9_n_u;
  const mxArray *c9_r_y = NULL;
  real_T c9_o_u;
  const mxArray *c9_s_y = NULL;
  c9_struct_ZCmOWPuqBDw16FSOVVD00 c9_p_u;
  const mxArray *c9_t_y = NULL;
  real_T c9_q_u;
  const mxArray *c9_u_y = NULL;
  real_T c9_r_u;
  const mxArray *c9_v_y = NULL;
  real_T c9_s_u;
  const mxArray *c9_w_y = NULL;
  real_T c9_t_u;
  const mxArray *c9_x_y = NULL;
  real_T c9_u_u;
  const mxArray *c9_y_y = NULL;
  real_T c9_v_u;
  const mxArray *c9_ab_y = NULL;
  real_T c9_w_u;
  const mxArray *c9_bb_y = NULL;
  real_T c9_x_u;
  const mxArray *c9_cb_y = NULL;
  real_T c9_y_u;
  const mxArray *c9_db_y = NULL;
  real_T c9_ab_u;
  const mxArray *c9_eb_y = NULL;
  real_T c9_bb_u;
  const mxArray *c9_fb_y = NULL;
  int32_T c9_i0;
  real_T c9_cb_u[4];
  const mxArray *c9_gb_y = NULL;
  real_T c9_db_u;
  const mxArray *c9_hb_y = NULL;
  c9_struct_ZKAzdrl7umDGJoC14aoVKC c9_eb_u;
  const mxArray *c9_ib_y = NULL;
  int32_T c9_i1;
  real_T c9_fb_u[3];
  const mxArray *c9_jb_y = NULL;
  int32_T c9_i2;
  real_T c9_gb_u[3];
  const mxArray *c9_kb_y = NULL;
  int32_T c9_i3;
  real_T c9_hb_u[3];
  const mxArray *c9_lb_y = NULL;
  int32_T c9_i4;
  real_T c9_ib_u[3];
  const mxArray *c9_mb_y = NULL;
  const mxArray *c9_nb_y = NULL;
  int32_T c9_i5;
  real_T c9_jb_u[3];
  const mxArray *c9_ob_y = NULL;
  int32_T c9_i6;
  real_T c9_kb_u[3];
  const mxArray *c9_pb_y = NULL;
  int32_T c9_i7;
  real_T c9_lb_u[3];
  const mxArray *c9_qb_y = NULL;
  int32_T c9_i8;
  real_T c9_mb_u[3];
  const mxArray *c9_rb_y = NULL;
  const mxArray *c9_sb_y = NULL;
  int32_T c9_i9;
  real_T c9_nb_u[3];
  const mxArray *c9_tb_y = NULL;
  int32_T c9_i10;
  real_T c9_ob_u[3];
  const mxArray *c9_ub_y = NULL;
  int32_T c9_i11;
  real_T c9_pb_u[3];
  const mxArray *c9_vb_y = NULL;
  int32_T c9_i12;
  real_T c9_qb_u[3];
  const mxArray *c9_wb_y = NULL;
  const mxArray *c9_xb_y = NULL;
  int32_T c9_i13;
  real_T c9_rb_u[3];
  const mxArray *c9_yb_y = NULL;
  int32_T c9_i14;
  real_T c9_sb_u[3];
  const mxArray *c9_ac_y = NULL;
  int32_T c9_i15;
  real_T c9_tb_u[3];
  const mxArray *c9_bc_y = NULL;
  int32_T c9_i16;
  real_T c9_ub_u[3];
  const mxArray *c9_cc_y = NULL;
  real_T c9_vb_u;
  const mxArray *c9_dc_y = NULL;
  real_T c9_wb_u;
  const mxArray *c9_ec_y = NULL;
  real_T c9_xb_u;
  const mxArray *c9_fc_y = NULL;
  real_T c9_yb_u;
  const mxArray *c9_gc_y = NULL;
  real_T c9_ac_u;
  const mxArray *c9_hc_y = NULL;
  real_T c9_bc_u;
  const mxArray *c9_ic_y = NULL;
  real_T c9_cc_u;
  const mxArray *c9_jc_y = NULL;
  real_T c9_dc_u;
  const mxArray *c9_kc_y = NULL;
  real_T c9_ec_u;
  const mxArray *c9_lc_y = NULL;
  real_T c9_fc_u;
  const mxArray *c9_mc_y = NULL;
  real_T c9_gc_u;
  const mxArray *c9_nc_y = NULL;
  real_T c9_hc_u;
  const mxArray *c9_oc_y = NULL;
  c9_struct_r4FNviKwHfdhB8nQjvQv9 c9_ic_u;
  const mxArray *c9_pc_y = NULL;
  real_T c9_jc_u;
  const mxArray *c9_qc_y = NULL;
  c9_struct_Y9F1qlBi9AhssksPwemA4G c9_kc_u;
  const mxArray *c9_rc_y = NULL;
  real_T c9_lc_u;
  const mxArray *c9_sc_y = NULL;
  real_T c9_mc_u;
  const mxArray *c9_tc_y = NULL;
  real_T c9_nc_u;
  const mxArray *c9_uc_y = NULL;
  SFc9_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc9_ModifiedInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_mxArrayOutData = NULL;
  c9_u = *(c9_struct_iBlsPBO3AGnt69vDoTx5zD *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c9_b_u = c9_u.Env;
  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c9_c_u = c9_b_u.g;
  c9_c_y = NULL;
  sf_mex_assign(&c9_c_y, sf_mex_create("y", &c9_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c9_b_y, c9_c_y, "g", "g", 0);
  c9_d_u = c9_b_u.left1;
  c9_d_y = NULL;
  sf_mex_assign(&c9_d_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c9_e_u = c9_d_u.x;
  c9_e_y = NULL;
  sf_mex_assign(&c9_e_y, sf_mex_create("y", &c9_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c9_d_y, c9_e_y, "x", "x", 0);
  c9_f_u = c9_d_u.y;
  c9_f_y = NULL;
  sf_mex_assign(&c9_f_y, sf_mex_create("y", &c9_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c9_d_y, c9_f_y, "y", "y", 0);
  sf_mex_addfield(c9_b_y, c9_d_y, "left1", "left1", 0);
  c9_d_u = c9_b_u.right1;
  c9_g_y = NULL;
  sf_mex_assign(&c9_g_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c9_g_u = c9_d_u.x;
  c9_h_y = NULL;
  sf_mex_assign(&c9_h_y, sf_mex_create("y", &c9_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c9_g_y, c9_h_y, "x", "x", 0);
  c9_h_u = c9_d_u.y;
  c9_i_y = NULL;
  sf_mex_assign(&c9_i_y, sf_mex_create("y", &c9_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c9_g_y, c9_i_y, "y", "y", 0);
  sf_mex_addfield(c9_b_y, c9_g_y, "right1", "right1", 0);
  c9_d_u = c9_b_u.right2;
  c9_j_y = NULL;
  sf_mex_assign(&c9_j_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c9_i_u = c9_d_u.x;
  c9_k_y = NULL;
  sf_mex_assign(&c9_k_y, sf_mex_create("y", &c9_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c9_j_y, c9_k_y, "x", "x", 0);
  c9_j_u = c9_d_u.y;
  c9_l_y = NULL;
  sf_mex_assign(&c9_l_y, sf_mex_create("y", &c9_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c9_j_y, c9_l_y, "y", "y", 0);
  sf_mex_addfield(c9_b_y, c9_j_y, "right2", "right2", 0);
  c9_d_u = c9_b_u.left2;
  c9_m_y = NULL;
  sf_mex_assign(&c9_m_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c9_k_u = c9_d_u.x;
  c9_n_y = NULL;
  sf_mex_assign(&c9_n_y, sf_mex_create("y", &c9_k_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c9_m_y, c9_n_y, "x", "x", 0);
  c9_l_u = c9_d_u.y;
  c9_o_y = NULL;
  sf_mex_assign(&c9_o_y, sf_mex_create("y", &c9_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c9_m_y, c9_o_y, "y", "y", 0);
  sf_mex_addfield(c9_b_y, c9_m_y, "left2", "left2", 0);
  c9_d_u = c9_b_u.right3;
  c9_p_y = NULL;
  sf_mex_assign(&c9_p_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c9_m_u = c9_d_u.x;
  c9_q_y = NULL;
  sf_mex_assign(&c9_q_y, sf_mex_create("y", &c9_m_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c9_p_y, c9_q_y, "x", "x", 0);
  c9_n_u = c9_d_u.y;
  c9_r_y = NULL;
  sf_mex_assign(&c9_r_y, sf_mex_create("y", &c9_n_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c9_p_y, c9_r_y, "y", "y", 0);
  sf_mex_addfield(c9_b_y, c9_p_y, "right3", "right3", 0);
  c9_o_u = c9_b_u.mu;
  c9_s_y = NULL;
  sf_mex_assign(&c9_s_y, sf_mex_create("y", &c9_o_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c9_b_y, c9_s_y, "mu", "mu", 0);
  sf_mex_addfield(c9_y, c9_b_y, "Env", "Env", 0);
  c9_p_u = c9_u.Veh;
  c9_t_y = NULL;
  sf_mex_assign(&c9_t_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c9_q_u = c9_p_u.m;
  c9_u_y = NULL;
  sf_mex_assign(&c9_u_y, sf_mex_create("y", &c9_q_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c9_t_y, c9_u_y, "m", "m", 0);
  c9_r_u = c9_p_u.Jz;
  c9_v_y = NULL;
  sf_mex_assign(&c9_v_y, sf_mex_create("y", &c9_r_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c9_t_y, c9_v_y, "Jz", "Jz", 0);
  c9_s_u = c9_p_u.m_sprung;
  c9_w_y = NULL;
  sf_mex_assign(&c9_w_y, sf_mex_create("y", &c9_s_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c9_t_y, c9_w_y, "m_sprung", "m_sprung", 0);
  c9_t_u = c9_p_u.Jx_sprung;
  c9_x_y = NULL;
  sf_mex_assign(&c9_x_y, sf_mex_create("y", &c9_t_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c9_t_y, c9_x_y, "Jx_sprung", "Jx_sprung", 0);
  c9_u_u = c9_p_u.Jy_sprung;
  c9_y_y = NULL;
  sf_mex_assign(&c9_y_y, sf_mex_create("y", &c9_u_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c9_t_y, c9_y_y, "Jy_sprung", "Jy_sprung", 0);
  c9_v_u = c9_p_u.lf;
  c9_ab_y = NULL;
  sf_mex_assign(&c9_ab_y, sf_mex_create("y", &c9_v_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c9_t_y, c9_ab_y, "lf", "lf", 0);
  c9_w_u = c9_p_u.lr;
  c9_bb_y = NULL;
  sf_mex_assign(&c9_bb_y, sf_mex_create("y", &c9_w_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c9_t_y, c9_bb_y, "lr", "lr", 0);
  c9_x_u = c9_p_u.L;
  c9_cb_y = NULL;
  sf_mex_assign(&c9_cb_y, sf_mex_create("y", &c9_x_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c9_t_y, c9_cb_y, "L", "L", 0);
  c9_y_u = c9_p_u.TrackWidth;
  c9_db_y = NULL;
  sf_mex_assign(&c9_db_y, sf_mex_create("y", &c9_y_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c9_t_y, c9_db_y, "TrackWidth", "TrackWidth", 0);
  c9_ab_u = c9_p_u.h;
  c9_eb_y = NULL;
  sf_mex_assign(&c9_eb_y, sf_mex_create("y", &c9_ab_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c9_t_y, c9_eb_y, "h", "h", 0);
  c9_bb_u = c9_p_u.HalfRohACd;
  c9_fb_y = NULL;
  sf_mex_assign(&c9_fb_y, sf_mex_create("y", &c9_bb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c9_t_y, c9_fb_y, "HalfRohACd", "HalfRohACd", 0);
  for (c9_i0 = 0; c9_i0 < 4; c9_i0++) {
    c9_cb_u[c9_i0] = c9_p_u.F_z4_static[c9_i0];
  }

  c9_gb_y = NULL;
  sf_mex_assign(&c9_gb_y, sf_mex_create("y", c9_cb_u, 0, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_addfield(c9_t_y, c9_gb_y, "F_z4_static", "F_z4_static", 0);
  c9_db_u = c9_p_u.Rw;
  c9_hb_y = NULL;
  sf_mex_assign(&c9_hb_y, sf_mex_create("y", &c9_db_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c9_t_y, c9_hb_y, "Rw", "Rw", 0);
  c9_eb_u = c9_p_u.r_long;
  c9_ib_y = NULL;
  sf_mex_assign(&c9_ib_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c9_i1 = 0; c9_i1 < 3; c9_i1++) {
    c9_fb_u[c9_i1] = c9_eb_u.fl[c9_i1];
  }

  c9_jb_y = NULL;
  sf_mex_assign(&c9_jb_y, sf_mex_create("y", c9_fb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c9_ib_y, c9_jb_y, "fl", "fl", 0);
  for (c9_i2 = 0; c9_i2 < 3; c9_i2++) {
    c9_gb_u[c9_i2] = c9_eb_u.fr[c9_i2];
  }

  c9_kb_y = NULL;
  sf_mex_assign(&c9_kb_y, sf_mex_create("y", c9_gb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c9_ib_y, c9_kb_y, "fr", "fr", 0);
  for (c9_i3 = 0; c9_i3 < 3; c9_i3++) {
    c9_hb_u[c9_i3] = c9_eb_u.rl[c9_i3];
  }

  c9_lb_y = NULL;
  sf_mex_assign(&c9_lb_y, sf_mex_create("y", c9_hb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c9_ib_y, c9_lb_y, "rl", "rl", 0);
  for (c9_i4 = 0; c9_i4 < 3; c9_i4++) {
    c9_ib_u[c9_i4] = c9_eb_u.rr[c9_i4];
  }

  c9_mb_y = NULL;
  sf_mex_assign(&c9_mb_y, sf_mex_create("y", c9_ib_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c9_ib_y, c9_mb_y, "rr", "rr", 0);
  sf_mex_addfield(c9_t_y, c9_ib_y, "r_long", "r_long", 0);
  c9_eb_u = c9_p_u.r_lat;
  c9_nb_y = NULL;
  sf_mex_assign(&c9_nb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c9_i5 = 0; c9_i5 < 3; c9_i5++) {
    c9_jb_u[c9_i5] = c9_eb_u.fl[c9_i5];
  }

  c9_ob_y = NULL;
  sf_mex_assign(&c9_ob_y, sf_mex_create("y", c9_jb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c9_nb_y, c9_ob_y, "fl", "fl", 0);
  for (c9_i6 = 0; c9_i6 < 3; c9_i6++) {
    c9_kb_u[c9_i6] = c9_eb_u.fr[c9_i6];
  }

  c9_pb_y = NULL;
  sf_mex_assign(&c9_pb_y, sf_mex_create("y", c9_kb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c9_nb_y, c9_pb_y, "fr", "fr", 0);
  for (c9_i7 = 0; c9_i7 < 3; c9_i7++) {
    c9_lb_u[c9_i7] = c9_eb_u.rl[c9_i7];
  }

  c9_qb_y = NULL;
  sf_mex_assign(&c9_qb_y, sf_mex_create("y", c9_lb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c9_nb_y, c9_qb_y, "rl", "rl", 0);
  for (c9_i8 = 0; c9_i8 < 3; c9_i8++) {
    c9_mb_u[c9_i8] = c9_eb_u.rr[c9_i8];
  }

  c9_rb_y = NULL;
  sf_mex_assign(&c9_rb_y, sf_mex_create("y", c9_mb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c9_nb_y, c9_rb_y, "rr", "rr", 0);
  sf_mex_addfield(c9_t_y, c9_nb_y, "r_lat", "r_lat", 0);
  c9_eb_u = c9_p_u.r_lever;
  c9_sb_y = NULL;
  sf_mex_assign(&c9_sb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c9_i9 = 0; c9_i9 < 3; c9_i9++) {
    c9_nb_u[c9_i9] = c9_eb_u.fl[c9_i9];
  }

  c9_tb_y = NULL;
  sf_mex_assign(&c9_tb_y, sf_mex_create("y", c9_nb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c9_sb_y, c9_tb_y, "fl", "fl", 0);
  for (c9_i10 = 0; c9_i10 < 3; c9_i10++) {
    c9_ob_u[c9_i10] = c9_eb_u.fr[c9_i10];
  }

  c9_ub_y = NULL;
  sf_mex_assign(&c9_ub_y, sf_mex_create("y", c9_ob_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c9_sb_y, c9_ub_y, "fr", "fr", 0);
  for (c9_i11 = 0; c9_i11 < 3; c9_i11++) {
    c9_pb_u[c9_i11] = c9_eb_u.rl[c9_i11];
  }

  c9_vb_y = NULL;
  sf_mex_assign(&c9_vb_y, sf_mex_create("y", c9_pb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c9_sb_y, c9_vb_y, "rl", "rl", 0);
  for (c9_i12 = 0; c9_i12 < 3; c9_i12++) {
    c9_qb_u[c9_i12] = c9_eb_u.rr[c9_i12];
  }

  c9_wb_y = NULL;
  sf_mex_assign(&c9_wb_y, sf_mex_create("y", c9_qb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c9_sb_y, c9_wb_y, "rr", "rr", 0);
  sf_mex_addfield(c9_t_y, c9_sb_y, "r_lever", "r_lever", 0);
  c9_eb_u = c9_p_u.r_pivot;
  c9_xb_y = NULL;
  sf_mex_assign(&c9_xb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c9_i13 = 0; c9_i13 < 3; c9_i13++) {
    c9_rb_u[c9_i13] = c9_eb_u.fl[c9_i13];
  }

  c9_yb_y = NULL;
  sf_mex_assign(&c9_yb_y, sf_mex_create("y", c9_rb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c9_xb_y, c9_yb_y, "fl", "fl", 0);
  for (c9_i14 = 0; c9_i14 < 3; c9_i14++) {
    c9_sb_u[c9_i14] = c9_eb_u.fr[c9_i14];
  }

  c9_ac_y = NULL;
  sf_mex_assign(&c9_ac_y, sf_mex_create("y", c9_sb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c9_xb_y, c9_ac_y, "fr", "fr", 0);
  for (c9_i15 = 0; c9_i15 < 3; c9_i15++) {
    c9_tb_u[c9_i15] = c9_eb_u.rl[c9_i15];
  }

  c9_bc_y = NULL;
  sf_mex_assign(&c9_bc_y, sf_mex_create("y", c9_tb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c9_xb_y, c9_bc_y, "rl", "rl", 0);
  for (c9_i16 = 0; c9_i16 < 3; c9_i16++) {
    c9_ub_u[c9_i16] = c9_eb_u.rr[c9_i16];
  }

  c9_cc_y = NULL;
  sf_mex_assign(&c9_cc_y, sf_mex_create("y", c9_ub_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c9_xb_y, c9_cc_y, "rr", "rr", 0);
  sf_mex_addfield(c9_t_y, c9_xb_y, "r_pivot", "r_pivot", 0);
  c9_vb_u = c9_p_u.cw;
  c9_dc_y = NULL;
  sf_mex_assign(&c9_dc_y, sf_mex_create("y", &c9_vb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c9_t_y, c9_dc_y, "cw", "cw", 0);
  c9_wb_u = c9_p_u.carb_f;
  c9_ec_y = NULL;
  sf_mex_assign(&c9_ec_y, sf_mex_create("y", &c9_wb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c9_t_y, c9_ec_y, "carb_f", "carb_f", 0);
  c9_xb_u = c9_p_u.carb_r;
  c9_fc_y = NULL;
  sf_mex_assign(&c9_fc_y, sf_mex_create("y", &c9_xb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c9_t_y, c9_fc_y, "carb_r", "carb_r", 0);
  c9_yb_u = c9_p_u.dw;
  c9_gc_y = NULL;
  sf_mex_assign(&c9_gc_y, sf_mex_create("y", &c9_yb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c9_t_y, c9_gc_y, "dw", "dw", 0);
  c9_ac_u = c9_p_u.Jw;
  c9_hc_y = NULL;
  sf_mex_assign(&c9_hc_y, sf_mex_create("y", &c9_ac_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c9_t_y, c9_hc_y, "Jw", "Jw", 0);
  c9_bc_u = c9_p_u.C0;
  c9_ic_y = NULL;
  sf_mex_assign(&c9_ic_y, sf_mex_create("y", &c9_bc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c9_t_y, c9_ic_y, "C0", "C0", 0);
  c9_cc_u = c9_p_u.RelaxLength;
  c9_jc_y = NULL;
  sf_mex_assign(&c9_jc_y, sf_mex_create("y", &c9_cc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c9_t_y, c9_jc_y, "RelaxLength", "RelaxLength", 0);
  c9_dc_u = c9_p_u.RRC;
  c9_kc_y = NULL;
  sf_mex_assign(&c9_kc_y, sf_mex_create("y", &c9_dc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c9_t_y, c9_kc_y, "RRC", "RRC", 0);
  c9_ec_u = c9_p_u.Pmax;
  c9_lc_y = NULL;
  sf_mex_assign(&c9_lc_y, sf_mex_create("y", &c9_ec_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c9_t_y, c9_lc_y, "Pmax", "Pmax", 0);
  c9_fc_u = c9_p_u.PropDistrFrnt;
  c9_mc_y = NULL;
  sf_mex_assign(&c9_mc_y, sf_mex_create("y", &c9_fc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c9_t_y, c9_mc_y, "PropDistrFrnt", "PropDistrFrnt", 0);
  c9_gc_u = c9_p_u.BrkDistrFrnt;
  c9_nc_y = NULL;
  sf_mex_assign(&c9_nc_y, sf_mex_create("y", &c9_gc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c9_t_y, c9_nc_y, "BrkDistrFrnt", "BrkDistrFrnt", 0);
  c9_hc_u = c9_p_u.SteRatio;
  c9_oc_y = NULL;
  sf_mex_assign(&c9_oc_y, sf_mex_create("y", &c9_hc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c9_t_y, c9_oc_y, "SteRatio", "SteRatio", 0);
  sf_mex_addfield(c9_y, c9_t_y, "Veh", "Veh", 0);
  c9_ic_u = c9_u.Drvr;
  c9_pc_y = NULL;
  sf_mex_assign(&c9_pc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c9_jc_u = c9_ic_u.v_set;
  c9_qc_y = NULL;
  sf_mex_assign(&c9_qc_y, sf_mex_create("y", &c9_jc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c9_pc_y, c9_qc_y, "v_set", "v_set", 0);
  sf_mex_addfield(c9_y, c9_pc_y, "Drvr", "Drvr", 0);
  c9_kc_u = c9_u.Init;
  c9_rc_y = NULL;
  sf_mex_assign(&c9_rc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c9_lc_u = c9_kc_u.v_x;
  c9_sc_y = NULL;
  sf_mex_assign(&c9_sc_y, sf_mex_create("y", &c9_lc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c9_rc_y, c9_sc_y, "v_x", "v_x", 0);
  c9_mc_u = c9_kc_u.F_fz;
  c9_tc_y = NULL;
  sf_mex_assign(&c9_tc_y, sf_mex_create("y", &c9_mc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c9_rc_y, c9_tc_y, "F_fz", "F_fz", 0);
  c9_nc_u = c9_kc_u.F_rz;
  c9_uc_y = NULL;
  sf_mex_assign(&c9_uc_y, sf_mex_create("y", &c9_nc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c9_rc_y, c9_uc_y, "F_rz", "F_rz", 0);
  sf_mex_addfield(c9_y, c9_rc_y, "Init", "Init", 0);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static void c9_d_emlrt_marshallIn(SFc9_ModifiedInstanceStruct *chartInstance,
  const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  c9_struct_iBlsPBO3AGnt69vDoTx5zD *c9_y)
{
  emlrtMsgIdentifier c9_thisId;
  static const char * c9_fieldNames[4] = { "Env", "Veh", "Drvr", "Init" };

  c9_thisId.fParent = c9_parentId;
  sf_mex_check_struct(c9_parentId, c9_u, 4, c9_fieldNames, 0U, NULL);
  c9_thisId.fIdentifier = "Env";
  c9_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c9_u, "Env",
    "Env", 0)), &c9_thisId, &c9_y->Env);
  c9_thisId.fIdentifier = "Veh";
  c9_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c9_u, "Veh",
    "Veh", 0)), &c9_thisId, &c9_y->Veh);
  c9_thisId.fIdentifier = "Drvr";
  c9_y->Drvr = c9_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c9_u, "Drvr", "Drvr", 0)), &c9_thisId);
  c9_thisId.fIdentifier = "Init";
  c9_y->Init = c9_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c9_u, "Init", "Init", 0)), &c9_thisId);
  sf_mex_destroy(&c9_u);
}

static void c9_e_emlrt_marshallIn(SFc9_ModifiedInstanceStruct *chartInstance,
  const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  c9_struct_Nst2vGTExxHsg85EUOj9EH *c9_y)
{
  emlrtMsgIdentifier c9_thisId;
  static const char * c9_fieldNames[7] = { "g", "left1", "right1", "right2",
    "left2", "right3", "mu" };

  c9_thisId.fParent = c9_parentId;
  sf_mex_check_struct(c9_parentId, c9_u, 7, c9_fieldNames, 0U, NULL);
  c9_thisId.fIdentifier = "g";
  c9_y->g = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c9_u,
    "g", "g", 0)), &c9_thisId);
  c9_thisId.fIdentifier = "left1";
  c9_y->left1 = c9_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c9_u, "left1", "left1", 0)), &c9_thisId);
  c9_thisId.fIdentifier = "right1";
  c9_y->right1 = c9_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c9_u, "right1", "right1", 0)),
    &c9_thisId);
  c9_thisId.fIdentifier = "right2";
  c9_y->right2 = c9_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c9_u, "right2", "right2", 0)),
    &c9_thisId);
  c9_thisId.fIdentifier = "left2";
  c9_y->left2 = c9_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c9_u, "left2", "left2", 0)), &c9_thisId);
  c9_thisId.fIdentifier = "right3";
  c9_y->right3 = c9_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c9_u, "right3", "right3", 0)),
    &c9_thisId);
  c9_thisId.fIdentifier = "mu";
  c9_y->mu = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c9_u, "mu", "mu", 0)), &c9_thisId);
  sf_mex_destroy(&c9_u);
}

static c9_struct_HhckT6rntEraqECYVIDvCC c9_f_emlrt_marshallIn
  (SFc9_ModifiedInstanceStruct *chartInstance, const mxArray *c9_u, const
   emlrtMsgIdentifier *c9_parentId)
{
  c9_struct_HhckT6rntEraqECYVIDvCC c9_y;
  emlrtMsgIdentifier c9_thisId;
  static const char * c9_fieldNames[2] = { "x", "y" };

  c9_thisId.fParent = c9_parentId;
  sf_mex_check_struct(c9_parentId, c9_u, 2, c9_fieldNames, 0U, NULL);
  c9_thisId.fIdentifier = "x";
  c9_y.x = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c9_u,
    "x", "x", 0)), &c9_thisId);
  c9_thisId.fIdentifier = "y";
  c9_y.y = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c9_u,
    "y", "y", 0)), &c9_thisId);
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_g_emlrt_marshallIn(SFc9_ModifiedInstanceStruct *chartInstance,
  const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  c9_struct_ZCmOWPuqBDw16FSOVVD00 *c9_y)
{
  emlrtMsgIdentifier c9_thisId;
  static const char * c9_fieldNames[29] = { "m", "Jz", "m_sprung", "Jx_sprung",
    "Jy_sprung", "lf", "lr", "L", "TrackWidth", "h", "HalfRohACd", "F_z4_static",
    "Rw", "r_long", "r_lat", "r_lever", "r_pivot", "cw", "carb_f", "carb_r",
    "dw", "Jw", "C0", "RelaxLength", "RRC", "Pmax", "PropDistrFrnt",
    "BrkDistrFrnt", "SteRatio" };

  c9_thisId.fParent = c9_parentId;
  sf_mex_check_struct(c9_parentId, c9_u, 29, c9_fieldNames, 0U, NULL);
  c9_thisId.fIdentifier = "m";
  c9_y->m = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c9_u,
    "m", "m", 0)), &c9_thisId);
  c9_thisId.fIdentifier = "Jz";
  c9_y->Jz = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c9_u, "Jz", "Jz", 0)), &c9_thisId);
  c9_thisId.fIdentifier = "m_sprung";
  c9_y->m_sprung = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c9_u, "m_sprung", "m_sprung", 0)), &c9_thisId);
  c9_thisId.fIdentifier = "Jx_sprung";
  c9_y->Jx_sprung = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c9_u, "Jx_sprung", "Jx_sprung", 0)), &c9_thisId);
  c9_thisId.fIdentifier = "Jy_sprung";
  c9_y->Jy_sprung = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c9_u, "Jy_sprung", "Jy_sprung", 0)), &c9_thisId);
  c9_thisId.fIdentifier = "lf";
  c9_y->lf = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c9_u, "lf", "lf", 0)), &c9_thisId);
  c9_thisId.fIdentifier = "lr";
  c9_y->lr = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c9_u, "lr", "lr", 0)), &c9_thisId);
  c9_thisId.fIdentifier = "L";
  c9_y->L = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c9_u,
    "L", "L", 0)), &c9_thisId);
  c9_thisId.fIdentifier = "TrackWidth";
  c9_y->TrackWidth = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c9_u, "TrackWidth", "TrackWidth", 0)), &c9_thisId);
  c9_thisId.fIdentifier = "h";
  c9_y->h = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c9_u,
    "h", "h", 0)), &c9_thisId);
  c9_thisId.fIdentifier = "HalfRohACd";
  c9_y->HalfRohACd = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c9_u, "HalfRohACd", "HalfRohACd", 0)), &c9_thisId);
  c9_thisId.fIdentifier = "F_z4_static";
  c9_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c9_u,
    "F_z4_static", "F_z4_static", 0)), &c9_thisId, c9_y->F_z4_static);
  c9_thisId.fIdentifier = "Rw";
  c9_y->Rw = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c9_u, "Rw", "Rw", 0)), &c9_thisId);
  c9_thisId.fIdentifier = "r_long";
  c9_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c9_u, "r_long",
    "r_long", 0)), &c9_thisId, &c9_y->r_long);
  c9_thisId.fIdentifier = "r_lat";
  c9_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c9_u, "r_lat",
    "r_lat", 0)), &c9_thisId, &c9_y->r_lat);
  c9_thisId.fIdentifier = "r_lever";
  c9_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c9_u,
    "r_lever", "r_lever", 0)), &c9_thisId, &c9_y->r_lever);
  c9_thisId.fIdentifier = "r_pivot";
  c9_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c9_u,
    "r_pivot", "r_pivot", 0)), &c9_thisId, &c9_y->r_pivot);
  c9_thisId.fIdentifier = "cw";
  c9_y->cw = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c9_u, "cw", "cw", 0)), &c9_thisId);
  c9_thisId.fIdentifier = "carb_f";
  c9_y->carb_f = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c9_u, "carb_f", "carb_f", 0)),
    &c9_thisId);
  c9_thisId.fIdentifier = "carb_r";
  c9_y->carb_r = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c9_u, "carb_r", "carb_r", 0)),
    &c9_thisId);
  c9_thisId.fIdentifier = "dw";
  c9_y->dw = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c9_u, "dw", "dw", 0)), &c9_thisId);
  c9_thisId.fIdentifier = "Jw";
  c9_y->Jw = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c9_u, "Jw", "Jw", 0)), &c9_thisId);
  c9_thisId.fIdentifier = "C0";
  c9_y->C0 = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c9_u, "C0", "C0", 0)), &c9_thisId);
  c9_thisId.fIdentifier = "RelaxLength";
  c9_y->RelaxLength = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c9_u, "RelaxLength", "RelaxLength", 0)), &c9_thisId);
  c9_thisId.fIdentifier = "RRC";
  c9_y->RRC = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c9_u, "RRC", "RRC", 0)), &c9_thisId);
  c9_thisId.fIdentifier = "Pmax";
  c9_y->Pmax = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c9_u, "Pmax", "Pmax", 0)), &c9_thisId);
  c9_thisId.fIdentifier = "PropDistrFrnt";
  c9_y->PropDistrFrnt = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c9_u, "PropDistrFrnt", "PropDistrFrnt", 0)), &c9_thisId);
  c9_thisId.fIdentifier = "BrkDistrFrnt";
  c9_y->BrkDistrFrnt = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c9_u, "BrkDistrFrnt", "BrkDistrFrnt", 0)), &c9_thisId);
  c9_thisId.fIdentifier = "SteRatio";
  c9_y->SteRatio = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c9_u, "SteRatio", "SteRatio", 0)), &c9_thisId);
  sf_mex_destroy(&c9_u);
}

static void c9_h_emlrt_marshallIn(SFc9_ModifiedInstanceStruct *chartInstance,
  const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId, real_T c9_y[4])
{
  real_T c9_dv0[4];
  int32_T c9_i17;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv0, 1, 0, 0U, 1, 0U, 2, 1, 4);
  for (c9_i17 = 0; c9_i17 < 4; c9_i17++) {
    c9_y[c9_i17] = c9_dv0[c9_i17];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_i_emlrt_marshallIn(SFc9_ModifiedInstanceStruct *chartInstance,
  const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  c9_struct_ZKAzdrl7umDGJoC14aoVKC *c9_y)
{
  emlrtMsgIdentifier c9_thisId;
  static const char * c9_fieldNames[4] = { "fl", "fr", "rl", "rr" };

  c9_thisId.fParent = c9_parentId;
  sf_mex_check_struct(c9_parentId, c9_u, 4, c9_fieldNames, 0U, NULL);
  c9_thisId.fIdentifier = "fl";
  c9_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c9_u, "fl",
    "fl", 0)), &c9_thisId, c9_y->fl);
  c9_thisId.fIdentifier = "fr";
  c9_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c9_u, "fr",
    "fr", 0)), &c9_thisId, c9_y->fr);
  c9_thisId.fIdentifier = "rl";
  c9_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c9_u, "rl",
    "rl", 0)), &c9_thisId, c9_y->rl);
  c9_thisId.fIdentifier = "rr";
  c9_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c9_u, "rr",
    "rr", 0)), &c9_thisId, c9_y->rr);
  sf_mex_destroy(&c9_u);
}

static void c9_j_emlrt_marshallIn(SFc9_ModifiedInstanceStruct *chartInstance,
  const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId, real_T c9_y[3])
{
  real_T c9_dv1[3];
  int32_T c9_i18;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv1, 1, 0, 0U, 1, 0U, 2, 3, 1);
  for (c9_i18 = 0; c9_i18 < 3; c9_i18++) {
    c9_y[c9_i18] = c9_dv1[c9_i18];
  }

  sf_mex_destroy(&c9_u);
}

static c9_struct_r4FNviKwHfdhB8nQjvQv9 c9_k_emlrt_marshallIn
  (SFc9_ModifiedInstanceStruct *chartInstance, const mxArray *c9_u, const
   emlrtMsgIdentifier *c9_parentId)
{
  c9_struct_r4FNviKwHfdhB8nQjvQv9 c9_y;
  emlrtMsgIdentifier c9_thisId;
  static const char * c9_fieldNames[1] = { "v_set" };

  c9_thisId.fParent = c9_parentId;
  sf_mex_check_struct(c9_parentId, c9_u, 1, c9_fieldNames, 0U, NULL);
  c9_thisId.fIdentifier = "v_set";
  c9_y.v_set = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c9_u, "v_set", "v_set", 0)), &c9_thisId);
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static c9_struct_Y9F1qlBi9AhssksPwemA4G c9_l_emlrt_marshallIn
  (SFc9_ModifiedInstanceStruct *chartInstance, const mxArray *c9_u, const
   emlrtMsgIdentifier *c9_parentId)
{
  c9_struct_Y9F1qlBi9AhssksPwemA4G c9_y;
  emlrtMsgIdentifier c9_thisId;
  static const char * c9_fieldNames[3] = { "v_x", "F_fz", "F_rz" };

  c9_thisId.fParent = c9_parentId;
  sf_mex_check_struct(c9_parentId, c9_u, 3, c9_fieldNames, 0U, NULL);
  c9_thisId.fIdentifier = "v_x";
  c9_y.v_x = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c9_u, "v_x", "v_x", 0)), &c9_thisId);
  c9_thisId.fIdentifier = "F_fz";
  c9_y.F_fz = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c9_u, "F_fz", "F_fz", 0)), &c9_thisId);
  c9_thisId.fIdentifier = "F_rz";
  c9_y.F_rz = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c9_u, "F_rz", "F_rz", 0)), &c9_thisId);
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_Par;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  c9_struct_iBlsPBO3AGnt69vDoTx5zD c9_y;
  SFc9_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc9_ModifiedInstanceStruct *)chartInstanceVoid;
  c9_b_Par = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_Par), &c9_thisId, &c9_y);
  sf_mex_destroy(&c9_b_Par);
  *(c9_struct_iBlsPBO3AGnt69vDoTx5zD *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  real_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc9_ModifiedInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(real_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static void c9_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_nargout;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y;
  SFc9_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc9_ModifiedInstanceStruct *)chartInstanceVoid;
  c9_nargout = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_nargout), &c9_thisId);
  sf_mex_destroy(&c9_nargout);
  *(real_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

const mxArray *sf_c9_Modified_get_eml_resolved_functions_info(void)
{
  const mxArray *c9_nameCaptureInfo = NULL;
  c9_nameCaptureInfo = NULL;
  sf_mex_assign(&c9_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c9_nameCaptureInfo;
}

static const mxArray *c9_d_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc9_ModifiedInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(int32_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static int32_T c9_m_emlrt_marshallIn(SFc9_ModifiedInstanceStruct *chartInstance,
  const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  int32_T c9_y;
  int32_T c9_i19;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_i19, 1, 6, 0U, 0, 0U, 0);
  c9_y = c9_i19;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_sfEvent;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  int32_T c9_y;
  SFc9_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc9_ModifiedInstanceStruct *)chartInstanceVoid;
  c9_b_sfEvent = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_sfEvent),
    &c9_thisId);
  sf_mex_destroy(&c9_b_sfEvent);
  *(int32_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_v_z4_bus_io(void *chartInstanceVoid, void *c9_pData)
{
  const mxArray *c9_mxVal = NULL;
  c9_whl_vec4 c9_tmp;
  SFc9_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc9_ModifiedInstanceStruct *)chartInstanceVoid;
  c9_mxVal = NULL;
  c9_tmp.fl = *(real_T *)&((char_T *)(c9_whl_vec4 *)c9_pData)[0];
  c9_tmp.fr = *(real_T *)&((char_T *)(c9_whl_vec4 *)c9_pData)[8];
  c9_tmp.rl = *(real_T *)&((char_T *)(c9_whl_vec4 *)c9_pData)[16];
  c9_tmp.rr = *(real_T *)&((char_T *)(c9_whl_vec4 *)c9_pData)[24];
  sf_mex_assign(&c9_mxVal, c9_sf_marshallOut(chartInstance, &c9_tmp), false);
  return c9_mxVal;
}

static uint8_T c9_n_emlrt_marshallIn(SFc9_ModifiedInstanceStruct *chartInstance,
  const mxArray *c9_b_is_active_c9_Modified, const char_T *c9_identifier)
{
  uint8_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_o_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c9_b_is_active_c9_Modified), &c9_thisId);
  sf_mex_destroy(&c9_b_is_active_c9_Modified);
  return c9_y;
}

static uint8_T c9_o_emlrt_marshallIn(SFc9_ModifiedInstanceStruct *chartInstance,
  const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  uint8_T c9_y;
  uint8_T c9_u0;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_u0, 1, 3, 0U, 0, 0U, 0);
  c9_y = c9_u0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void init_dsm_address_info(SFc9_ModifiedInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc9_ModifiedInstanceStruct *chartInstance)
{
  chartInstance->c9_v_z4 = (c9_whl_vec4 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c9_F_d4 = (c9_whl_vec4 *)ssGetOutputPortSignal_wrapper
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

void sf_c9_Modified_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3812684250U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(146470283U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4275654888U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2716122653U);
}

mxArray* sf_c9_Modified_get_post_codegen_info(void);
mxArray *sf_c9_Modified_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("OcMS8rv8RU3JjKc5YauSLG");
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
    mxArray* mxPostCodegenInfo = sf_c9_Modified_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c9_Modified_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c9_Modified_jit_fallback_info(void)
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

mxArray *sf_c9_Modified_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c9_Modified_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c9_Modified(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[7],T\"F_d4\",},{M[8],M[0],T\"is_active_c9_Modified\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c9_Modified_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc9_ModifiedInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc9_ModifiedInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ModifiedMachineNumber_,
           9,
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
          _SFD_SET_DATA_PROPS(1,2,0,1,"F_d4");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,267);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_v_z4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_v_z4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)c9_b_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c9_v_z4);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c9_F_d4);
        _SFD_SET_DATA_VALUE_PTR(2U, &chartInstance->c9_Par);
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
  return "8QlPsK8YvvPlEKOLT26g0F";
}

static void sf_opaque_initialize_c9_Modified(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc9_ModifiedInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c9_Modified((SFc9_ModifiedInstanceStruct*) chartInstanceVar);
  initialize_c9_Modified((SFc9_ModifiedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c9_Modified(void *chartInstanceVar)
{
  enable_c9_Modified((SFc9_ModifiedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c9_Modified(void *chartInstanceVar)
{
  disable_c9_Modified((SFc9_ModifiedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c9_Modified(void *chartInstanceVar)
{
  sf_gateway_c9_Modified((SFc9_ModifiedInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c9_Modified(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c9_Modified((SFc9_ModifiedInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c9_Modified(SimStruct* S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c9_Modified((SFc9_ModifiedInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c9_Modified(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc9_ModifiedInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Modified_optimization_info();
    }

    finalize_c9_Modified((SFc9_ModifiedInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc9_Modified((SFc9_ModifiedInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c9_Modified(SimStruct *S)
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
    initialize_params_c9_Modified((SFc9_ModifiedInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c9_Modified(SimStruct *S)
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
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,9);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,9,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,9,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,9);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,9,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,9,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,9);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3947890410U));
  ssSetChecksum1(S,(733652109U));
  ssSetChecksum2(S,(2037126046U));
  ssSetChecksum3(S,(2591082517U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c9_Modified(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c9_Modified(SimStruct *S)
{
  SFc9_ModifiedInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc9_ModifiedInstanceStruct *)utMalloc(sizeof
    (SFc9_ModifiedInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc9_ModifiedInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c9_Modified;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c9_Modified;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c9_Modified;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c9_Modified;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c9_Modified;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c9_Modified;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c9_Modified;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c9_Modified;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c9_Modified;
  chartInstance->chartInfo.mdlStart = mdlStart_c9_Modified;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c9_Modified;
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

void c9_Modified_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c9_Modified(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c9_Modified(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c9_Modified(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c9_Modified_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
