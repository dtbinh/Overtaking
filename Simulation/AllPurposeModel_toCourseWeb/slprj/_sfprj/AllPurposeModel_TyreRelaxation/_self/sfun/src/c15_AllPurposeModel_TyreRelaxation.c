/* Include files */

#include <stddef.h>
#include "blas.h"
#include "AllPurposeModel_TyreRelaxation_sfun.h"
#include "c15_AllPurposeModel_TyreRelaxation.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "AllPurposeModel_TyreRelaxation_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c15_debug_family_names[11] = { "F_z4_temp", "nargin",
  "nargout", "s_x4", "s_y4", "s_xy4", "F_xyw4", "F_z4_prev", "Par", "F_xw4",
  "F_yw4" };

/* Function Declarations */
static void initialize_c15_AllPurposeModel_TyreRelaxation
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void initialize_params_c15_AllPurposeModel_TyreRelaxation
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void enable_c15_AllPurposeModel_TyreRelaxation
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void disable_c15_AllPurposeModel_TyreRelaxation
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void c15_update_debugger_state_c15_AllPurposeModel_TyreRelaxation
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c15_AllPurposeModel_TyreRelaxation
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void set_sim_state_c15_AllPurposeModel_TyreRelaxation
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c15_st);
static void finalize_c15_AllPurposeModel_TyreRelaxation
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void sf_gateway_c15_AllPurposeModel_TyreRelaxation
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void mdl_start_c15_AllPurposeModel_TyreRelaxation
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void c15_chartstep_c15_AllPurposeModel_TyreRelaxation
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void initSimStructsc15_AllPurposeModel_TyreRelaxation
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c15_machineNumber, uint32_T
  c15_chartNumber, uint32_T c15_instanceNumber);
static const mxArray *c15_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static c15_whl_vec4 c15_emlrt_marshallIn
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c15_b_F_yw4, const char_T *c15_identifier);
static c15_whl_vec4 c15_b_emlrt_marshallIn
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId);
static real_T c15_c_emlrt_marshallIn
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId);
static void c15_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static const mxArray *c15_b_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static void c15_d_emlrt_marshallIn
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
   c15_struct_iBlsPBO3AGnt69vDoTx5zD *c15_y);
static void c15_e_emlrt_marshallIn
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
   c15_struct_Nst2vGTExxHsg85EUOj9EH *c15_y);
static c15_struct_HhckT6rntEraqECYVIDvCC c15_f_emlrt_marshallIn
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId);
static void c15_g_emlrt_marshallIn
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
   c15_struct_ZCmOWPuqBDw16FSOVVD00 *c15_y);
static void c15_h_emlrt_marshallIn
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId, real_T c15_y[4]);
static void c15_i_emlrt_marshallIn
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
   c15_struct_ZKAzdrl7umDGJoC14aoVKC *c15_y);
static void c15_j_emlrt_marshallIn
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId, real_T c15_y[3]);
static c15_struct_r4FNviKwHfdhB8nQjvQv9 c15_k_emlrt_marshallIn
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId);
static c15_struct_Y9F1qlBi9AhssksPwemA4G c15_l_emlrt_marshallIn
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId);
static void c15_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static const mxArray *c15_c_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static void c15_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static const mxArray *c15_d_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static void c15_m_emlrt_marshallIn
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId, real_T c15_y[4]);
static void c15_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static void c15_info_helper(const mxArray **c15_info);
static const mxArray *c15_emlrt_marshallOut(const char * c15_u);
static const mxArray *c15_b_emlrt_marshallOut(const uint32_T c15_u);
static const mxArray *c15_e_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static int32_T c15_n_emlrt_marshallIn
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId);
static void c15_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static const mxArray *c15_s_x4_bus_io(void *chartInstanceVoid, void *c15_pData);
static uint8_T c15_o_emlrt_marshallIn
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c15_b_is_active_c15_AllPurposeModel_TyreRelaxation, const char_T
   *c15_identifier);
static uint8_T c15_p_emlrt_marshallIn
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId);
static void init_dsm_address_info
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void init_simulink_io_address
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c15_AllPurposeModel_TyreRelaxation
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  chartInstance->c15_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c15_is_active_c15_AllPurposeModel_TyreRelaxation = 0U;
}

static void initialize_params_c15_AllPurposeModel_TyreRelaxation
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  const mxArray *c15_m0 = NULL;
  const mxArray *c15_mxField;
  const mxArray *c15_m1 = NULL;
  const mxArray *c15_b_mxField;
  c15_struct_iBlsPBO3AGnt69vDoTx5zD c15_r0;
  const mxArray *c15_m2 = NULL;
  const mxArray *c15_c_mxField;
  const mxArray *c15_m3 = NULL;
  const mxArray *c15_d_mxField;
  const mxArray *c15_m4 = NULL;
  const mxArray *c15_e_mxField;
  const mxArray *c15_m5 = NULL;
  const mxArray *c15_f_mxField;
  const mxArray *c15_m6 = NULL;
  const mxArray *c15_g_mxField;
  const mxArray *c15_m7 = NULL;
  const mxArray *c15_h_mxField;
  const mxArray *c15_m8 = NULL;
  const mxArray *c15_i_mxField;
  const mxArray *c15_m9 = NULL;
  const mxArray *c15_j_mxField;
  const mxArray *c15_m10 = NULL;
  const mxArray *c15_k_mxField;
  const mxArray *c15_m11 = NULL;
  const mxArray *c15_l_mxField;
  const mxArray *c15_m12 = NULL;
  const mxArray *c15_m_mxField;
  const mxArray *c15_m13 = NULL;
  const mxArray *c15_n_mxField;
  c15_m0 = sf_mex_get_sfun_param(chartInstance->S, 0, 1);
  c15_mxField = sf_mex_getfield(c15_m0, "Env", "Par", 0);
  c15_m1 = sf_mex_dup(c15_mxField);
  c15_b_mxField = sf_mex_getfield(c15_m1, "g", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_b_mxField), &c15_r0.Env.g, 1, 0, 0U,
                      0, 0U, 0);
  c15_b_mxField = sf_mex_getfield(c15_m1, "left1", "Par", 0);
  c15_m2 = sf_mex_dup(c15_b_mxField);
  c15_c_mxField = sf_mex_getfield(c15_m2, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_c_mxField), &c15_r0.Env.left1.x, 1,
                      0, 0U, 0, 0U, 0);
  c15_c_mxField = sf_mex_getfield(c15_m2, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_c_mxField), &c15_r0.Env.left1.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c15_m2);
  c15_b_mxField = sf_mex_getfield(c15_m1, "right1", "Par", 0);
  c15_m3 = sf_mex_dup(c15_b_mxField);
  c15_d_mxField = sf_mex_getfield(c15_m3, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_d_mxField), &c15_r0.Env.right1.x, 1,
                      0, 0U, 0, 0U, 0);
  c15_d_mxField = sf_mex_getfield(c15_m3, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_d_mxField), &c15_r0.Env.right1.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c15_m3);
  c15_b_mxField = sf_mex_getfield(c15_m1, "right2", "Par", 0);
  c15_m4 = sf_mex_dup(c15_b_mxField);
  c15_e_mxField = sf_mex_getfield(c15_m4, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_e_mxField), &c15_r0.Env.right2.x, 1,
                      0, 0U, 0, 0U, 0);
  c15_e_mxField = sf_mex_getfield(c15_m4, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_e_mxField), &c15_r0.Env.right2.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c15_m4);
  c15_b_mxField = sf_mex_getfield(c15_m1, "left2", "Par", 0);
  c15_m5 = sf_mex_dup(c15_b_mxField);
  c15_f_mxField = sf_mex_getfield(c15_m5, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_f_mxField), &c15_r0.Env.left2.x, 1,
                      0, 0U, 0, 0U, 0);
  c15_f_mxField = sf_mex_getfield(c15_m5, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_f_mxField), &c15_r0.Env.left2.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c15_m5);
  c15_b_mxField = sf_mex_getfield(c15_m1, "right3", "Par", 0);
  c15_m6 = sf_mex_dup(c15_b_mxField);
  c15_g_mxField = sf_mex_getfield(c15_m6, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_g_mxField), &c15_r0.Env.right3.x, 1,
                      0, 0U, 0, 0U, 0);
  c15_g_mxField = sf_mex_getfield(c15_m6, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_g_mxField), &c15_r0.Env.right3.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c15_m6);
  c15_b_mxField = sf_mex_getfield(c15_m1, "mu", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_b_mxField), &c15_r0.Env.mu, 1, 0, 0U,
                      0, 0U, 0);
  sf_mex_destroy(&c15_m1);
  c15_mxField = sf_mex_getfield(c15_m0, "Veh", "Par", 0);
  c15_m7 = sf_mex_dup(c15_mxField);
  c15_h_mxField = sf_mex_getfield(c15_m7, "m", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_h_mxField), &c15_r0.Veh.m, 1, 0, 0U,
                      0, 0U, 0);
  c15_h_mxField = sf_mex_getfield(c15_m7, "Jz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_h_mxField), &c15_r0.Veh.Jz, 1, 0, 0U,
                      0, 0U, 0);
  c15_h_mxField = sf_mex_getfield(c15_m7, "m_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_h_mxField), &c15_r0.Veh.m_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c15_h_mxField = sf_mex_getfield(c15_m7, "Jx_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_h_mxField), &c15_r0.Veh.Jx_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c15_h_mxField = sf_mex_getfield(c15_m7, "Jy_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_h_mxField), &c15_r0.Veh.Jy_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c15_h_mxField = sf_mex_getfield(c15_m7, "lf", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_h_mxField), &c15_r0.Veh.lf, 1, 0, 0U,
                      0, 0U, 0);
  c15_h_mxField = sf_mex_getfield(c15_m7, "lr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_h_mxField), &c15_r0.Veh.lr, 1, 0, 0U,
                      0, 0U, 0);
  c15_h_mxField = sf_mex_getfield(c15_m7, "L", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_h_mxField), &c15_r0.Veh.L, 1, 0, 0U,
                      0, 0U, 0);
  c15_h_mxField = sf_mex_getfield(c15_m7, "TrackWidth", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_h_mxField), &c15_r0.Veh.TrackWidth,
                      1, 0, 0U, 0, 0U, 0);
  c15_h_mxField = sf_mex_getfield(c15_m7, "h", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_h_mxField), &c15_r0.Veh.h, 1, 0, 0U,
                      0, 0U, 0);
  c15_h_mxField = sf_mex_getfield(c15_m7, "HalfRohACd", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_h_mxField), &c15_r0.Veh.HalfRohACd,
                      1, 0, 0U, 0, 0U, 0);
  c15_h_mxField = sf_mex_getfield(c15_m7, "F_z4_static", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_h_mxField), c15_r0.Veh.F_z4_static,
                      1, 0, 0U, 1, 0U, 2, 1, 4);
  c15_h_mxField = sf_mex_getfield(c15_m7, "Rw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_h_mxField), &c15_r0.Veh.Rw, 1, 0, 0U,
                      0, 0U, 0);
  c15_h_mxField = sf_mex_getfield(c15_m7, "r_long", "Par", 0);
  c15_m8 = sf_mex_dup(c15_h_mxField);
  c15_i_mxField = sf_mex_getfield(c15_m8, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_i_mxField), c15_r0.Veh.r_long.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c15_i_mxField = sf_mex_getfield(c15_m8, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_i_mxField), c15_r0.Veh.r_long.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c15_i_mxField = sf_mex_getfield(c15_m8, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_i_mxField), c15_r0.Veh.r_long.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c15_i_mxField = sf_mex_getfield(c15_m8, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_i_mxField), c15_r0.Veh.r_long.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c15_m8);
  c15_h_mxField = sf_mex_getfield(c15_m7, "r_lat", "Par", 0);
  c15_m9 = sf_mex_dup(c15_h_mxField);
  c15_j_mxField = sf_mex_getfield(c15_m9, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_j_mxField), c15_r0.Veh.r_lat.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c15_j_mxField = sf_mex_getfield(c15_m9, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_j_mxField), c15_r0.Veh.r_lat.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c15_j_mxField = sf_mex_getfield(c15_m9, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_j_mxField), c15_r0.Veh.r_lat.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c15_j_mxField = sf_mex_getfield(c15_m9, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_j_mxField), c15_r0.Veh.r_lat.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c15_m9);
  c15_h_mxField = sf_mex_getfield(c15_m7, "r_lever", "Par", 0);
  c15_m10 = sf_mex_dup(c15_h_mxField);
  c15_k_mxField = sf_mex_getfield(c15_m10, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_k_mxField), c15_r0.Veh.r_lever.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c15_k_mxField = sf_mex_getfield(c15_m10, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_k_mxField), c15_r0.Veh.r_lever.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c15_k_mxField = sf_mex_getfield(c15_m10, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_k_mxField), c15_r0.Veh.r_lever.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c15_k_mxField = sf_mex_getfield(c15_m10, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_k_mxField), c15_r0.Veh.r_lever.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c15_m10);
  c15_h_mxField = sf_mex_getfield(c15_m7, "r_pivot", "Par", 0);
  c15_m11 = sf_mex_dup(c15_h_mxField);
  c15_l_mxField = sf_mex_getfield(c15_m11, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_l_mxField), c15_r0.Veh.r_pivot.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c15_l_mxField = sf_mex_getfield(c15_m11, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_l_mxField), c15_r0.Veh.r_pivot.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c15_l_mxField = sf_mex_getfield(c15_m11, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_l_mxField), c15_r0.Veh.r_pivot.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c15_l_mxField = sf_mex_getfield(c15_m11, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_l_mxField), c15_r0.Veh.r_pivot.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c15_m11);
  c15_h_mxField = sf_mex_getfield(c15_m7, "cw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_h_mxField), &c15_r0.Veh.cw, 1, 0, 0U,
                      0, 0U, 0);
  c15_h_mxField = sf_mex_getfield(c15_m7, "carb_f", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_h_mxField), &c15_r0.Veh.carb_f, 1, 0,
                      0U, 0, 0U, 0);
  c15_h_mxField = sf_mex_getfield(c15_m7, "carb_r", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_h_mxField), &c15_r0.Veh.carb_r, 1, 0,
                      0U, 0, 0U, 0);
  c15_h_mxField = sf_mex_getfield(c15_m7, "dw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_h_mxField), &c15_r0.Veh.dw, 1, 0, 0U,
                      0, 0U, 0);
  c15_h_mxField = sf_mex_getfield(c15_m7, "Jw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_h_mxField), &c15_r0.Veh.Jw, 1, 0, 0U,
                      0, 0U, 0);
  c15_h_mxField = sf_mex_getfield(c15_m7, "C0", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_h_mxField), &c15_r0.Veh.C0, 1, 0, 0U,
                      0, 0U, 0);
  c15_h_mxField = sf_mex_getfield(c15_m7, "RelaxLength", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_h_mxField), &c15_r0.Veh.RelaxLength,
                      1, 0, 0U, 0, 0U, 0);
  c15_h_mxField = sf_mex_getfield(c15_m7, "RRC", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_h_mxField), &c15_r0.Veh.RRC, 1, 0,
                      0U, 0, 0U, 0);
  c15_h_mxField = sf_mex_getfield(c15_m7, "Pmax", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_h_mxField), &c15_r0.Veh.Pmax, 1, 0,
                      0U, 0, 0U, 0);
  c15_h_mxField = sf_mex_getfield(c15_m7, "PropDistrFrnt", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_h_mxField),
                      &c15_r0.Veh.PropDistrFrnt, 1, 0, 0U, 0, 0U, 0);
  c15_h_mxField = sf_mex_getfield(c15_m7, "BrkDistrFrnt", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_h_mxField), &c15_r0.Veh.BrkDistrFrnt,
                      1, 0, 0U, 0, 0U, 0);
  c15_h_mxField = sf_mex_getfield(c15_m7, "SteRatio", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_h_mxField), &c15_r0.Veh.SteRatio, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c15_m7);
  c15_mxField = sf_mex_getfield(c15_m0, "Drvr", "Par", 0);
  c15_m12 = sf_mex_dup(c15_mxField);
  c15_m_mxField = sf_mex_getfield(c15_m12, "v_set", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_m_mxField), &c15_r0.Drvr.v_set, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c15_m12);
  c15_mxField = sf_mex_getfield(c15_m0, "Init", "Par", 0);
  c15_m13 = sf_mex_dup(c15_mxField);
  c15_n_mxField = sf_mex_getfield(c15_m13, "v_x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_n_mxField), &c15_r0.Init.v_x, 1, 0,
                      0U, 0, 0U, 0);
  c15_n_mxField = sf_mex_getfield(c15_m13, "F_fz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_n_mxField), &c15_r0.Init.F_fz, 1, 0,
                      0U, 0, 0U, 0);
  c15_n_mxField = sf_mex_getfield(c15_m13, "F_rz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c15_n_mxField), &c15_r0.Init.F_rz, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c15_m13);
  sf_mex_destroy(&c15_m0);
  chartInstance->c15_Par = c15_r0;
}

static void enable_c15_AllPurposeModel_TyreRelaxation
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c15_AllPurposeModel_TyreRelaxation
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c15_update_debugger_state_c15_AllPurposeModel_TyreRelaxation
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c15_AllPurposeModel_TyreRelaxation
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  const mxArray *c15_st;
  const mxArray *c15_y = NULL;
  const mxArray *c15_b_y = NULL;
  real_T c15_u;
  const mxArray *c15_c_y = NULL;
  real_T c15_b_u;
  const mxArray *c15_d_y = NULL;
  real_T c15_c_u;
  const mxArray *c15_e_y = NULL;
  real_T c15_d_u;
  const mxArray *c15_f_y = NULL;
  const mxArray *c15_g_y = NULL;
  real_T c15_e_u;
  const mxArray *c15_h_y = NULL;
  real_T c15_f_u;
  const mxArray *c15_i_y = NULL;
  real_T c15_g_u;
  const mxArray *c15_j_y = NULL;
  real_T c15_h_u;
  const mxArray *c15_k_y = NULL;
  uint8_T c15_hoistedGlobal;
  uint8_T c15_i_u;
  const mxArray *c15_l_y = NULL;
  c15_st = NULL;
  c15_st = NULL;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_createcellmatrix(3, 1), false);
  c15_b_y = NULL;
  sf_mex_assign(&c15_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c15_u = *(real_T *)&((char_T *)chartInstance->c15_F_xw4)[0];
  c15_c_y = NULL;
  sf_mex_assign(&c15_c_y, sf_mex_create("y", &c15_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c15_b_y, c15_c_y, "fl", "fl", 0);
  c15_b_u = *(real_T *)&((char_T *)chartInstance->c15_F_xw4)[8];
  c15_d_y = NULL;
  sf_mex_assign(&c15_d_y, sf_mex_create("y", &c15_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c15_b_y, c15_d_y, "fr", "fr", 0);
  c15_c_u = *(real_T *)&((char_T *)chartInstance->c15_F_xw4)[16];
  c15_e_y = NULL;
  sf_mex_assign(&c15_e_y, sf_mex_create("y", &c15_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c15_b_y, c15_e_y, "rl", "rl", 0);
  c15_d_u = *(real_T *)&((char_T *)chartInstance->c15_F_xw4)[24];
  c15_f_y = NULL;
  sf_mex_assign(&c15_f_y, sf_mex_create("y", &c15_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c15_b_y, c15_f_y, "rr", "rr", 0);
  sf_mex_setcell(c15_y, 0, c15_b_y);
  c15_g_y = NULL;
  sf_mex_assign(&c15_g_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c15_e_u = *(real_T *)&((char_T *)chartInstance->c15_F_yw4)[0];
  c15_h_y = NULL;
  sf_mex_assign(&c15_h_y, sf_mex_create("y", &c15_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c15_g_y, c15_h_y, "fl", "fl", 0);
  c15_f_u = *(real_T *)&((char_T *)chartInstance->c15_F_yw4)[8];
  c15_i_y = NULL;
  sf_mex_assign(&c15_i_y, sf_mex_create("y", &c15_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c15_g_y, c15_i_y, "fr", "fr", 0);
  c15_g_u = *(real_T *)&((char_T *)chartInstance->c15_F_yw4)[16];
  c15_j_y = NULL;
  sf_mex_assign(&c15_j_y, sf_mex_create("y", &c15_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c15_g_y, c15_j_y, "rl", "rl", 0);
  c15_h_u = *(real_T *)&((char_T *)chartInstance->c15_F_yw4)[24];
  c15_k_y = NULL;
  sf_mex_assign(&c15_k_y, sf_mex_create("y", &c15_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c15_g_y, c15_k_y, "rr", "rr", 0);
  sf_mex_setcell(c15_y, 1, c15_g_y);
  c15_hoistedGlobal =
    chartInstance->c15_is_active_c15_AllPurposeModel_TyreRelaxation;
  c15_i_u = c15_hoistedGlobal;
  c15_l_y = NULL;
  sf_mex_assign(&c15_l_y, sf_mex_create("y", &c15_i_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c15_y, 2, c15_l_y);
  sf_mex_assign(&c15_st, c15_y, false);
  return c15_st;
}

static void set_sim_state_c15_AllPurposeModel_TyreRelaxation
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c15_st)
{
  const mxArray *c15_u;
  c15_whl_vec4 c15_r1;
  c15_whl_vec4 c15_r2;
  chartInstance->c15_doneDoubleBufferReInit = true;
  c15_u = sf_mex_dup(c15_st);
  c15_r1 = c15_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c15_u,
    0)), "F_xw4");
  *(real_T *)&((char_T *)chartInstance->c15_F_xw4)[0] = c15_r1.fl;
  *(real_T *)&((char_T *)chartInstance->c15_F_xw4)[8] = c15_r1.fr;
  *(real_T *)&((char_T *)chartInstance->c15_F_xw4)[16] = c15_r1.rl;
  *(real_T *)&((char_T *)chartInstance->c15_F_xw4)[24] = c15_r1.rr;
  c15_r2 = c15_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c15_u,
    1)), "F_yw4");
  *(real_T *)&((char_T *)chartInstance->c15_F_yw4)[0] = c15_r2.fl;
  *(real_T *)&((char_T *)chartInstance->c15_F_yw4)[8] = c15_r2.fr;
  *(real_T *)&((char_T *)chartInstance->c15_F_yw4)[16] = c15_r2.rl;
  *(real_T *)&((char_T *)chartInstance->c15_F_yw4)[24] = c15_r2.rr;
  chartInstance->c15_is_active_c15_AllPurposeModel_TyreRelaxation =
    c15_o_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c15_u, 2)),
    "is_active_c15_AllPurposeModel_TyreRelaxation");
  sf_mex_destroy(&c15_u);
  c15_update_debugger_state_c15_AllPurposeModel_TyreRelaxation(chartInstance);
  sf_mex_destroy(&c15_st);
}

static void finalize_c15_AllPurposeModel_TyreRelaxation
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c15_AllPurposeModel_TyreRelaxation
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 13U, chartInstance->c15_sfEvent);
  chartInstance->c15_sfEvent = CALL_EVENT;
  c15_chartstep_c15_AllPurposeModel_TyreRelaxation(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_AllPurposeModel_TyreRelaxationMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void mdl_start_c15_AllPurposeModel_TyreRelaxation
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c15_chartstep_c15_AllPurposeModel_TyreRelaxation
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  c15_whl_vec4 c15_b_s_x4;
  c15_whl_vec4 c15_b_s_y4;
  c15_whl_vec4 c15_b_s_xy4;
  c15_whl_vec4 c15_b_F_xyw4;
  c15_whl_vec4 c15_b_F_z4_prev;
  c15_struct_iBlsPBO3AGnt69vDoTx5zD c15_b_Par;
  uint32_T c15_debug_family_var_map[11];
  real_T c15_F_z4_temp[4];
  real_T c15_nargin = 6.0;
  real_T c15_nargout = 2.0;
  c15_whl_vec4 c15_b_F_xw4;
  c15_whl_vec4 c15_b_F_yw4;
  real_T c15_A;
  real_T c15_B;
  real_T c15_x;
  real_T c15_y;
  real_T c15_b_x;
  real_T c15_b_y;
  real_T c15_c_x;
  real_T c15_c_y;
  real_T c15_d0;
  real_T c15_b_A;
  real_T c15_b_B;
  real_T c15_d_x;
  real_T c15_d_y;
  real_T c15_e_x;
  real_T c15_e_y;
  real_T c15_f_x;
  real_T c15_f_y;
  real_T c15_g_y;
  real_T c15_c_A;
  real_T c15_c_B;
  real_T c15_g_x;
  real_T c15_h_y;
  real_T c15_h_x;
  real_T c15_i_y;
  real_T c15_i_x;
  real_T c15_j_y;
  real_T c15_k_y;
  real_T c15_d_A;
  real_T c15_d_B;
  real_T c15_j_x;
  real_T c15_l_y;
  real_T c15_k_x;
  real_T c15_m_y;
  real_T c15_l_x;
  real_T c15_n_y;
  real_T c15_d1;
  real_T c15_e_A;
  real_T c15_e_B;
  real_T c15_m_x;
  real_T c15_o_y;
  real_T c15_n_x;
  real_T c15_p_y;
  real_T c15_o_x;
  real_T c15_q_y;
  real_T c15_r_y;
  real_T c15_f_A;
  real_T c15_f_B;
  real_T c15_p_x;
  real_T c15_s_y;
  real_T c15_q_x;
  real_T c15_t_y;
  real_T c15_r_x;
  real_T c15_u_y;
  real_T c15_v_y;
  real_T c15_g_A;
  real_T c15_g_B;
  real_T c15_s_x;
  real_T c15_w_y;
  real_T c15_t_x;
  real_T c15_x_y;
  real_T c15_u_x;
  real_T c15_y_y;
  real_T c15_d2;
  real_T c15_h_A;
  real_T c15_h_B;
  real_T c15_v_x;
  real_T c15_ab_y;
  real_T c15_w_x;
  real_T c15_bb_y;
  real_T c15_x_x;
  real_T c15_cb_y;
  real_T c15_db_y;
  real_T c15_i_A;
  real_T c15_i_B;
  real_T c15_y_x;
  real_T c15_eb_y;
  real_T c15_ab_x;
  real_T c15_fb_y;
  real_T c15_bb_x;
  real_T c15_gb_y;
  real_T c15_hb_y;
  real_T c15_j_A;
  real_T c15_j_B;
  real_T c15_cb_x;
  real_T c15_ib_y;
  real_T c15_db_x;
  real_T c15_jb_y;
  real_T c15_eb_x;
  real_T c15_kb_y;
  real_T c15_d3;
  real_T c15_k_A;
  real_T c15_k_B;
  real_T c15_fb_x;
  real_T c15_lb_y;
  real_T c15_gb_x;
  real_T c15_mb_y;
  real_T c15_hb_x;
  real_T c15_nb_y;
  real_T c15_ob_y;
  real_T c15_l_A;
  real_T c15_l_B;
  real_T c15_ib_x;
  real_T c15_pb_y;
  real_T c15_jb_x;
  real_T c15_qb_y;
  real_T c15_kb_x;
  real_T c15_rb_y;
  real_T c15_sb_y;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 13U, chartInstance->c15_sfEvent);
  c15_b_s_x4.fl = *(real_T *)&((char_T *)chartInstance->c15_s_x4)[0];
  c15_b_s_x4.fr = *(real_T *)&((char_T *)chartInstance->c15_s_x4)[8];
  c15_b_s_x4.rl = *(real_T *)&((char_T *)chartInstance->c15_s_x4)[16];
  c15_b_s_x4.rr = *(real_T *)&((char_T *)chartInstance->c15_s_x4)[24];
  c15_b_s_y4.fl = *(real_T *)&((char_T *)chartInstance->c15_s_y4)[0];
  c15_b_s_y4.fr = *(real_T *)&((char_T *)chartInstance->c15_s_y4)[8];
  c15_b_s_y4.rl = *(real_T *)&((char_T *)chartInstance->c15_s_y4)[16];
  c15_b_s_y4.rr = *(real_T *)&((char_T *)chartInstance->c15_s_y4)[24];
  c15_b_s_xy4.fl = *(real_T *)&((char_T *)chartInstance->c15_s_xy4)[0];
  c15_b_s_xy4.fr = *(real_T *)&((char_T *)chartInstance->c15_s_xy4)[8];
  c15_b_s_xy4.rl = *(real_T *)&((char_T *)chartInstance->c15_s_xy4)[16];
  c15_b_s_xy4.rr = *(real_T *)&((char_T *)chartInstance->c15_s_xy4)[24];
  c15_b_F_xyw4.fl = *(real_T *)&((char_T *)chartInstance->c15_F_xyw4)[0];
  c15_b_F_xyw4.fr = *(real_T *)&((char_T *)chartInstance->c15_F_xyw4)[8];
  c15_b_F_xyw4.rl = *(real_T *)&((char_T *)chartInstance->c15_F_xyw4)[16];
  c15_b_F_xyw4.rr = *(real_T *)&((char_T *)chartInstance->c15_F_xyw4)[24];
  c15_b_F_z4_prev.fl = *(real_T *)&((char_T *)chartInstance->c15_F_z4_prev)[0];
  c15_b_F_z4_prev.fr = *(real_T *)&((char_T *)chartInstance->c15_F_z4_prev)[8];
  c15_b_F_z4_prev.rl = *(real_T *)&((char_T *)chartInstance->c15_F_z4_prev)[16];
  c15_b_F_z4_prev.rr = *(real_T *)&((char_T *)chartInstance->c15_F_z4_prev)[24];
  c15_b_Par = chartInstance->c15_Par;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 11U, 11U, c15_debug_family_names,
    c15_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c15_F_z4_temp, 0U, c15_d_sf_marshallOut,
    c15_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_nargin, 1U, c15_c_sf_marshallOut,
    c15_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_nargout, 2U, c15_c_sf_marshallOut,
    c15_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c15_b_s_x4, 3U, c15_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c15_b_s_y4, 4U, c15_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c15_b_s_xy4, 5U, c15_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c15_b_F_xyw4, 6U, c15_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c15_b_F_z4_prev, 7U, c15_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_b_Par, 8U, c15_b_sf_marshallOut,
    c15_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_b_F_xw4, 9U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_b_F_yw4, 10U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 4);
  c15_F_z4_temp[0] = c15_b_F_z4_prev.fl;
  c15_F_z4_temp[1] = c15_b_F_z4_prev.fr;
  c15_F_z4_temp[2] = c15_b_F_z4_prev.rl;
  c15_F_z4_temp[3] = c15_b_F_z4_prev.rr;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 7);
  c15_A = c15_b_Par.Env.mu;
  c15_B = c15_b_Par.Veh.C0;
  c15_x = c15_A;
  c15_y = c15_B;
  c15_b_x = c15_x;
  c15_b_y = c15_y;
  c15_c_x = c15_b_x;
  c15_c_y = c15_b_y;
  c15_d0 = c15_c_x / c15_c_y;
  if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c15_b_s_xy4.fl, c15_d0,
        -1, 4U, c15_b_s_xy4.fl > c15_d0))) {
    _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 8);
    c15_b_A = c15_b_s_x4.fl;
    c15_b_B = c15_b_s_xy4.fl;
    c15_d_x = c15_b_A;
    c15_d_y = c15_b_B;
    c15_e_x = c15_d_x;
    c15_e_y = c15_d_y;
    c15_f_x = c15_e_x;
    c15_f_y = c15_e_y;
    c15_g_y = c15_f_x / c15_f_y;
    c15_b_F_xw4.fl = c15_b_F_xyw4.fl * c15_g_y;
    _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 9);
    c15_c_A = -c15_b_s_y4.fl;
    c15_c_B = c15_b_s_xy4.fl;
    c15_g_x = c15_c_A;
    c15_h_y = c15_c_B;
    c15_h_x = c15_g_x;
    c15_i_y = c15_h_y;
    c15_i_x = c15_h_x;
    c15_j_y = c15_i_y;
    c15_k_y = c15_i_x / c15_j_y;
    c15_b_F_yw4.fl = c15_b_F_xyw4.fl * c15_k_y;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 11);
    c15_b_F_xw4.fl = c15_F_z4_temp[0] * c15_b_Par.Veh.C0 * c15_b_s_x4.fl;
    _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 12);
    c15_b_F_yw4.fl = -c15_F_z4_temp[0] * c15_b_Par.Veh.C0 * c15_b_s_y4.fl;
  }

  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 15);
  c15_d_A = c15_b_Par.Env.mu;
  c15_d_B = c15_b_Par.Veh.C0;
  c15_j_x = c15_d_A;
  c15_l_y = c15_d_B;
  c15_k_x = c15_j_x;
  c15_m_y = c15_l_y;
  c15_l_x = c15_k_x;
  c15_n_y = c15_m_y;
  c15_d1 = c15_l_x / c15_n_y;
  if (CV_EML_IF(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 1, c15_b_s_xy4.fr, c15_d1,
        -1, 4U, c15_b_s_xy4.fr > c15_d1))) {
    _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 16);
    c15_e_A = c15_b_s_x4.fr;
    c15_e_B = c15_b_s_xy4.fr;
    c15_m_x = c15_e_A;
    c15_o_y = c15_e_B;
    c15_n_x = c15_m_x;
    c15_p_y = c15_o_y;
    c15_o_x = c15_n_x;
    c15_q_y = c15_p_y;
    c15_r_y = c15_o_x / c15_q_y;
    c15_b_F_xw4.fr = c15_b_F_xyw4.fr * c15_r_y;
    _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 17);
    c15_f_A = -c15_b_s_y4.fr;
    c15_f_B = c15_b_s_xy4.fr;
    c15_p_x = c15_f_A;
    c15_s_y = c15_f_B;
    c15_q_x = c15_p_x;
    c15_t_y = c15_s_y;
    c15_r_x = c15_q_x;
    c15_u_y = c15_t_y;
    c15_v_y = c15_r_x / c15_u_y;
    c15_b_F_yw4.fr = c15_b_F_xyw4.fr * c15_v_y;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 19);
    c15_b_F_xw4.fr = c15_F_z4_temp[1] * c15_b_Par.Veh.C0 * c15_b_s_x4.fr;
    _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 20);
    c15_b_F_yw4.fr = -c15_F_z4_temp[1] * c15_b_Par.Veh.C0 * c15_b_s_y4.fr;
  }

  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 23);
  c15_g_A = c15_b_Par.Env.mu;
  c15_g_B = c15_b_Par.Veh.C0;
  c15_s_x = c15_g_A;
  c15_w_y = c15_g_B;
  c15_t_x = c15_s_x;
  c15_x_y = c15_w_y;
  c15_u_x = c15_t_x;
  c15_y_y = c15_x_y;
  c15_d2 = c15_u_x / c15_y_y;
  if (CV_EML_IF(0, 1, 2, CV_RELATIONAL_EVAL(4U, 0U, 2, c15_b_s_xy4.rl, c15_d2,
        -1, 4U, c15_b_s_xy4.rl > c15_d2))) {
    _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 24);
    c15_h_A = c15_b_s_x4.rl;
    c15_h_B = c15_b_s_xy4.rl;
    c15_v_x = c15_h_A;
    c15_ab_y = c15_h_B;
    c15_w_x = c15_v_x;
    c15_bb_y = c15_ab_y;
    c15_x_x = c15_w_x;
    c15_cb_y = c15_bb_y;
    c15_db_y = c15_x_x / c15_cb_y;
    c15_b_F_xw4.rl = c15_b_F_xyw4.rl * c15_db_y;
    _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 25);
    c15_i_A = -c15_b_s_y4.rl;
    c15_i_B = c15_b_s_xy4.rl;
    c15_y_x = c15_i_A;
    c15_eb_y = c15_i_B;
    c15_ab_x = c15_y_x;
    c15_fb_y = c15_eb_y;
    c15_bb_x = c15_ab_x;
    c15_gb_y = c15_fb_y;
    c15_hb_y = c15_bb_x / c15_gb_y;
    c15_b_F_yw4.rl = c15_b_F_xyw4.rl * c15_hb_y;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 27);
    c15_b_F_xw4.rl = c15_F_z4_temp[2] * c15_b_Par.Veh.C0 * c15_b_s_x4.rl;
    _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 28);
    c15_b_F_yw4.rl = -c15_F_z4_temp[2] * c15_b_Par.Veh.C0 * c15_b_s_y4.rl;
  }

  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 31);
  c15_j_A = c15_b_Par.Env.mu;
  c15_j_B = c15_b_Par.Veh.C0;
  c15_cb_x = c15_j_A;
  c15_ib_y = c15_j_B;
  c15_db_x = c15_cb_x;
  c15_jb_y = c15_ib_y;
  c15_eb_x = c15_db_x;
  c15_kb_y = c15_jb_y;
  c15_d3 = c15_eb_x / c15_kb_y;
  if (CV_EML_IF(0, 1, 3, CV_RELATIONAL_EVAL(4U, 0U, 3, c15_b_s_xy4.rr, c15_d3,
        -1, 4U, c15_b_s_xy4.rr > c15_d3))) {
    _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 32);
    c15_k_A = c15_b_s_x4.rr;
    c15_k_B = c15_b_s_xy4.rr;
    c15_fb_x = c15_k_A;
    c15_lb_y = c15_k_B;
    c15_gb_x = c15_fb_x;
    c15_mb_y = c15_lb_y;
    c15_hb_x = c15_gb_x;
    c15_nb_y = c15_mb_y;
    c15_ob_y = c15_hb_x / c15_nb_y;
    c15_b_F_xw4.rr = c15_b_F_xyw4.rr * c15_ob_y;
    _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 33);
    c15_l_A = -c15_b_s_y4.rr;
    c15_l_B = c15_b_s_xy4.rr;
    c15_ib_x = c15_l_A;
    c15_pb_y = c15_l_B;
    c15_jb_x = c15_ib_x;
    c15_qb_y = c15_pb_y;
    c15_kb_x = c15_jb_x;
    c15_rb_y = c15_qb_y;
    c15_sb_y = c15_kb_x / c15_rb_y;
    c15_b_F_yw4.rr = c15_b_F_xyw4.rr * c15_sb_y;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 35);
    c15_b_F_xw4.rr = c15_F_z4_temp[3] * c15_b_Par.Veh.C0 * c15_b_s_x4.rr;
    _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 36);
    c15_b_F_yw4.rr = -c15_F_z4_temp[3] * c15_b_Par.Veh.C0 * c15_b_s_y4.rr;
  }

  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, -36);
  _SFD_SYMBOL_SCOPE_POP();
  *(real_T *)&((char_T *)chartInstance->c15_F_xw4)[0] = c15_b_F_xw4.fl;
  *(real_T *)&((char_T *)chartInstance->c15_F_xw4)[8] = c15_b_F_xw4.fr;
  *(real_T *)&((char_T *)chartInstance->c15_F_xw4)[16] = c15_b_F_xw4.rl;
  *(real_T *)&((char_T *)chartInstance->c15_F_xw4)[24] = c15_b_F_xw4.rr;
  *(real_T *)&((char_T *)chartInstance->c15_F_yw4)[0] = c15_b_F_yw4.fl;
  *(real_T *)&((char_T *)chartInstance->c15_F_yw4)[8] = c15_b_F_yw4.fr;
  *(real_T *)&((char_T *)chartInstance->c15_F_yw4)[16] = c15_b_F_yw4.rl;
  *(real_T *)&((char_T *)chartInstance->c15_F_yw4)[24] = c15_b_F_yw4.rr;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, chartInstance->c15_sfEvent);
}

static void initSimStructsc15_AllPurposeModel_TyreRelaxation
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c15_machineNumber, uint32_T
  c15_chartNumber, uint32_T c15_instanceNumber)
{
  (void)c15_machineNumber;
  (void)c15_chartNumber;
  (void)c15_instanceNumber;
}

static const mxArray *c15_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  c15_whl_vec4 c15_u;
  const mxArray *c15_y = NULL;
  real_T c15_b_u;
  const mxArray *c15_b_y = NULL;
  real_T c15_c_u;
  const mxArray *c15_c_y = NULL;
  real_T c15_d_u;
  const mxArray *c15_d_y = NULL;
  real_T c15_e_u;
  const mxArray *c15_e_y = NULL;
  SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  c15_u = *(c15_whl_vec4 *)c15_inData;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c15_b_u = c15_u.fl;
  c15_b_y = NULL;
  sf_mex_assign(&c15_b_y, sf_mex_create("y", &c15_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c15_y, c15_b_y, "fl", "fl", 0);
  c15_c_u = c15_u.fr;
  c15_c_y = NULL;
  sf_mex_assign(&c15_c_y, sf_mex_create("y", &c15_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c15_y, c15_c_y, "fr", "fr", 0);
  c15_d_u = c15_u.rl;
  c15_d_y = NULL;
  sf_mex_assign(&c15_d_y, sf_mex_create("y", &c15_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c15_y, c15_d_y, "rl", "rl", 0);
  c15_e_u = c15_u.rr;
  c15_e_y = NULL;
  sf_mex_assign(&c15_e_y, sf_mex_create("y", &c15_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c15_y, c15_e_y, "rr", "rr", 0);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, false);
  return c15_mxArrayOutData;
}

static c15_whl_vec4 c15_emlrt_marshallIn
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c15_b_F_yw4, const char_T *c15_identifier)
{
  c15_whl_vec4 c15_y;
  emlrtMsgIdentifier c15_thisId;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_y = c15_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_b_F_yw4),
    &c15_thisId);
  sf_mex_destroy(&c15_b_F_yw4);
  return c15_y;
}

static c15_whl_vec4 c15_b_emlrt_marshallIn
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId)
{
  c15_whl_vec4 c15_y;
  emlrtMsgIdentifier c15_thisId;
  static const char * c15_fieldNames[4] = { "fl", "fr", "rl", "rr" };

  c15_thisId.fParent = c15_parentId;
  sf_mex_check_struct(c15_parentId, c15_u, 4, c15_fieldNames, 0U, NULL);
  c15_thisId.fIdentifier = "fl";
  c15_y.fl = c15_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c15_u, "fl", "fl", 0)), &c15_thisId);
  c15_thisId.fIdentifier = "fr";
  c15_y.fr = c15_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c15_u, "fr", "fr", 0)), &c15_thisId);
  c15_thisId.fIdentifier = "rl";
  c15_y.rl = c15_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c15_u, "rl", "rl", 0)), &c15_thisId);
  c15_thisId.fIdentifier = "rr";
  c15_y.rr = c15_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c15_u, "rr", "rr", 0)), &c15_thisId);
  sf_mex_destroy(&c15_u);
  return c15_y;
}

static real_T c15_c_emlrt_marshallIn
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId)
{
  real_T c15_y;
  real_T c15_d4;
  (void)chartInstance;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), &c15_d4, 1, 0, 0U, 0, 0U, 0);
  c15_y = c15_d4;
  sf_mex_destroy(&c15_u);
  return c15_y;
}

static void c15_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_b_F_yw4;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  c15_whl_vec4 c15_y;
  SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c15_b_F_yw4 = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_y = c15_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_b_F_yw4),
    &c15_thisId);
  sf_mex_destroy(&c15_b_F_yw4);
  *(c15_whl_vec4 *)c15_outData = c15_y;
  sf_mex_destroy(&c15_mxArrayInData);
}

static const mxArray *c15_b_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData;
  c15_struct_iBlsPBO3AGnt69vDoTx5zD c15_u;
  const mxArray *c15_y = NULL;
  c15_struct_Nst2vGTExxHsg85EUOj9EH c15_b_u;
  const mxArray *c15_b_y = NULL;
  real_T c15_c_u;
  const mxArray *c15_c_y = NULL;
  c15_struct_HhckT6rntEraqECYVIDvCC c15_d_u;
  const mxArray *c15_d_y = NULL;
  real_T c15_e_u;
  const mxArray *c15_e_y = NULL;
  real_T c15_f_u;
  const mxArray *c15_f_y = NULL;
  const mxArray *c15_g_y = NULL;
  real_T c15_g_u;
  const mxArray *c15_h_y = NULL;
  real_T c15_h_u;
  const mxArray *c15_i_y = NULL;
  const mxArray *c15_j_y = NULL;
  real_T c15_i_u;
  const mxArray *c15_k_y = NULL;
  real_T c15_j_u;
  const mxArray *c15_l_y = NULL;
  const mxArray *c15_m_y = NULL;
  real_T c15_k_u;
  const mxArray *c15_n_y = NULL;
  real_T c15_l_u;
  const mxArray *c15_o_y = NULL;
  const mxArray *c15_p_y = NULL;
  real_T c15_m_u;
  const mxArray *c15_q_y = NULL;
  real_T c15_n_u;
  const mxArray *c15_r_y = NULL;
  real_T c15_o_u;
  const mxArray *c15_s_y = NULL;
  c15_struct_ZCmOWPuqBDw16FSOVVD00 c15_p_u;
  const mxArray *c15_t_y = NULL;
  real_T c15_q_u;
  const mxArray *c15_u_y = NULL;
  real_T c15_r_u;
  const mxArray *c15_v_y = NULL;
  real_T c15_s_u;
  const mxArray *c15_w_y = NULL;
  real_T c15_t_u;
  const mxArray *c15_x_y = NULL;
  real_T c15_u_u;
  const mxArray *c15_y_y = NULL;
  real_T c15_v_u;
  const mxArray *c15_ab_y = NULL;
  real_T c15_w_u;
  const mxArray *c15_bb_y = NULL;
  real_T c15_x_u;
  const mxArray *c15_cb_y = NULL;
  real_T c15_y_u;
  const mxArray *c15_db_y = NULL;
  real_T c15_ab_u;
  const mxArray *c15_eb_y = NULL;
  real_T c15_bb_u;
  const mxArray *c15_fb_y = NULL;
  int32_T c15_i0;
  real_T c15_cb_u[4];
  const mxArray *c15_gb_y = NULL;
  real_T c15_db_u;
  const mxArray *c15_hb_y = NULL;
  c15_struct_ZKAzdrl7umDGJoC14aoVKC c15_eb_u;
  const mxArray *c15_ib_y = NULL;
  int32_T c15_i1;
  real_T c15_fb_u[3];
  const mxArray *c15_jb_y = NULL;
  int32_T c15_i2;
  real_T c15_gb_u[3];
  const mxArray *c15_kb_y = NULL;
  int32_T c15_i3;
  real_T c15_hb_u[3];
  const mxArray *c15_lb_y = NULL;
  int32_T c15_i4;
  real_T c15_ib_u[3];
  const mxArray *c15_mb_y = NULL;
  const mxArray *c15_nb_y = NULL;
  int32_T c15_i5;
  real_T c15_jb_u[3];
  const mxArray *c15_ob_y = NULL;
  int32_T c15_i6;
  real_T c15_kb_u[3];
  const mxArray *c15_pb_y = NULL;
  int32_T c15_i7;
  real_T c15_lb_u[3];
  const mxArray *c15_qb_y = NULL;
  int32_T c15_i8;
  real_T c15_mb_u[3];
  const mxArray *c15_rb_y = NULL;
  const mxArray *c15_sb_y = NULL;
  int32_T c15_i9;
  real_T c15_nb_u[3];
  const mxArray *c15_tb_y = NULL;
  int32_T c15_i10;
  real_T c15_ob_u[3];
  const mxArray *c15_ub_y = NULL;
  int32_T c15_i11;
  real_T c15_pb_u[3];
  const mxArray *c15_vb_y = NULL;
  int32_T c15_i12;
  real_T c15_qb_u[3];
  const mxArray *c15_wb_y = NULL;
  const mxArray *c15_xb_y = NULL;
  int32_T c15_i13;
  real_T c15_rb_u[3];
  const mxArray *c15_yb_y = NULL;
  int32_T c15_i14;
  real_T c15_sb_u[3];
  const mxArray *c15_ac_y = NULL;
  int32_T c15_i15;
  real_T c15_tb_u[3];
  const mxArray *c15_bc_y = NULL;
  int32_T c15_i16;
  real_T c15_ub_u[3];
  const mxArray *c15_cc_y = NULL;
  real_T c15_vb_u;
  const mxArray *c15_dc_y = NULL;
  real_T c15_wb_u;
  const mxArray *c15_ec_y = NULL;
  real_T c15_xb_u;
  const mxArray *c15_fc_y = NULL;
  real_T c15_yb_u;
  const mxArray *c15_gc_y = NULL;
  real_T c15_ac_u;
  const mxArray *c15_hc_y = NULL;
  real_T c15_bc_u;
  const mxArray *c15_ic_y = NULL;
  real_T c15_cc_u;
  const mxArray *c15_jc_y = NULL;
  real_T c15_dc_u;
  const mxArray *c15_kc_y = NULL;
  real_T c15_ec_u;
  const mxArray *c15_lc_y = NULL;
  real_T c15_fc_u;
  const mxArray *c15_mc_y = NULL;
  real_T c15_gc_u;
  const mxArray *c15_nc_y = NULL;
  real_T c15_hc_u;
  const mxArray *c15_oc_y = NULL;
  c15_struct_r4FNviKwHfdhB8nQjvQv9 c15_ic_u;
  const mxArray *c15_pc_y = NULL;
  real_T c15_jc_u;
  const mxArray *c15_qc_y = NULL;
  c15_struct_Y9F1qlBi9AhssksPwemA4G c15_kc_u;
  const mxArray *c15_rc_y = NULL;
  real_T c15_lc_u;
  const mxArray *c15_sc_y = NULL;
  real_T c15_mc_u;
  const mxArray *c15_tc_y = NULL;
  real_T c15_nc_u;
  const mxArray *c15_uc_y = NULL;
  SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  c15_mxArrayOutData = NULL;
  c15_u = *(c15_struct_iBlsPBO3AGnt69vDoTx5zD *)c15_inData;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c15_b_u = c15_u.Env;
  c15_b_y = NULL;
  sf_mex_assign(&c15_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c15_c_u = c15_b_u.g;
  c15_c_y = NULL;
  sf_mex_assign(&c15_c_y, sf_mex_create("y", &c15_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c15_b_y, c15_c_y, "g", "g", 0);
  c15_d_u = c15_b_u.left1;
  c15_d_y = NULL;
  sf_mex_assign(&c15_d_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c15_e_u = c15_d_u.x;
  c15_e_y = NULL;
  sf_mex_assign(&c15_e_y, sf_mex_create("y", &c15_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c15_d_y, c15_e_y, "x", "x", 0);
  c15_f_u = c15_d_u.y;
  c15_f_y = NULL;
  sf_mex_assign(&c15_f_y, sf_mex_create("y", &c15_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c15_d_y, c15_f_y, "y", "y", 0);
  sf_mex_addfield(c15_b_y, c15_d_y, "left1", "left1", 0);
  c15_d_u = c15_b_u.right1;
  c15_g_y = NULL;
  sf_mex_assign(&c15_g_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c15_g_u = c15_d_u.x;
  c15_h_y = NULL;
  sf_mex_assign(&c15_h_y, sf_mex_create("y", &c15_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c15_g_y, c15_h_y, "x", "x", 0);
  c15_h_u = c15_d_u.y;
  c15_i_y = NULL;
  sf_mex_assign(&c15_i_y, sf_mex_create("y", &c15_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c15_g_y, c15_i_y, "y", "y", 0);
  sf_mex_addfield(c15_b_y, c15_g_y, "right1", "right1", 0);
  c15_d_u = c15_b_u.right2;
  c15_j_y = NULL;
  sf_mex_assign(&c15_j_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c15_i_u = c15_d_u.x;
  c15_k_y = NULL;
  sf_mex_assign(&c15_k_y, sf_mex_create("y", &c15_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c15_j_y, c15_k_y, "x", "x", 0);
  c15_j_u = c15_d_u.y;
  c15_l_y = NULL;
  sf_mex_assign(&c15_l_y, sf_mex_create("y", &c15_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c15_j_y, c15_l_y, "y", "y", 0);
  sf_mex_addfield(c15_b_y, c15_j_y, "right2", "right2", 0);
  c15_d_u = c15_b_u.left2;
  c15_m_y = NULL;
  sf_mex_assign(&c15_m_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c15_k_u = c15_d_u.x;
  c15_n_y = NULL;
  sf_mex_assign(&c15_n_y, sf_mex_create("y", &c15_k_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c15_m_y, c15_n_y, "x", "x", 0);
  c15_l_u = c15_d_u.y;
  c15_o_y = NULL;
  sf_mex_assign(&c15_o_y, sf_mex_create("y", &c15_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c15_m_y, c15_o_y, "y", "y", 0);
  sf_mex_addfield(c15_b_y, c15_m_y, "left2", "left2", 0);
  c15_d_u = c15_b_u.right3;
  c15_p_y = NULL;
  sf_mex_assign(&c15_p_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c15_m_u = c15_d_u.x;
  c15_q_y = NULL;
  sf_mex_assign(&c15_q_y, sf_mex_create("y", &c15_m_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c15_p_y, c15_q_y, "x", "x", 0);
  c15_n_u = c15_d_u.y;
  c15_r_y = NULL;
  sf_mex_assign(&c15_r_y, sf_mex_create("y", &c15_n_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c15_p_y, c15_r_y, "y", "y", 0);
  sf_mex_addfield(c15_b_y, c15_p_y, "right3", "right3", 0);
  c15_o_u = c15_b_u.mu;
  c15_s_y = NULL;
  sf_mex_assign(&c15_s_y, sf_mex_create("y", &c15_o_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c15_b_y, c15_s_y, "mu", "mu", 0);
  sf_mex_addfield(c15_y, c15_b_y, "Env", "Env", 0);
  c15_p_u = c15_u.Veh;
  c15_t_y = NULL;
  sf_mex_assign(&c15_t_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c15_q_u = c15_p_u.m;
  c15_u_y = NULL;
  sf_mex_assign(&c15_u_y, sf_mex_create("y", &c15_q_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c15_t_y, c15_u_y, "m", "m", 0);
  c15_r_u = c15_p_u.Jz;
  c15_v_y = NULL;
  sf_mex_assign(&c15_v_y, sf_mex_create("y", &c15_r_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c15_t_y, c15_v_y, "Jz", "Jz", 0);
  c15_s_u = c15_p_u.m_sprung;
  c15_w_y = NULL;
  sf_mex_assign(&c15_w_y, sf_mex_create("y", &c15_s_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c15_t_y, c15_w_y, "m_sprung", "m_sprung", 0);
  c15_t_u = c15_p_u.Jx_sprung;
  c15_x_y = NULL;
  sf_mex_assign(&c15_x_y, sf_mex_create("y", &c15_t_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c15_t_y, c15_x_y, "Jx_sprung", "Jx_sprung", 0);
  c15_u_u = c15_p_u.Jy_sprung;
  c15_y_y = NULL;
  sf_mex_assign(&c15_y_y, sf_mex_create("y", &c15_u_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c15_t_y, c15_y_y, "Jy_sprung", "Jy_sprung", 0);
  c15_v_u = c15_p_u.lf;
  c15_ab_y = NULL;
  sf_mex_assign(&c15_ab_y, sf_mex_create("y", &c15_v_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c15_t_y, c15_ab_y, "lf", "lf", 0);
  c15_w_u = c15_p_u.lr;
  c15_bb_y = NULL;
  sf_mex_assign(&c15_bb_y, sf_mex_create("y", &c15_w_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c15_t_y, c15_bb_y, "lr", "lr", 0);
  c15_x_u = c15_p_u.L;
  c15_cb_y = NULL;
  sf_mex_assign(&c15_cb_y, sf_mex_create("y", &c15_x_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c15_t_y, c15_cb_y, "L", "L", 0);
  c15_y_u = c15_p_u.TrackWidth;
  c15_db_y = NULL;
  sf_mex_assign(&c15_db_y, sf_mex_create("y", &c15_y_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c15_t_y, c15_db_y, "TrackWidth", "TrackWidth", 0);
  c15_ab_u = c15_p_u.h;
  c15_eb_y = NULL;
  sf_mex_assign(&c15_eb_y, sf_mex_create("y", &c15_ab_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c15_t_y, c15_eb_y, "h", "h", 0);
  c15_bb_u = c15_p_u.HalfRohACd;
  c15_fb_y = NULL;
  sf_mex_assign(&c15_fb_y, sf_mex_create("y", &c15_bb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c15_t_y, c15_fb_y, "HalfRohACd", "HalfRohACd", 0);
  for (c15_i0 = 0; c15_i0 < 4; c15_i0++) {
    c15_cb_u[c15_i0] = c15_p_u.F_z4_static[c15_i0];
  }

  c15_gb_y = NULL;
  sf_mex_assign(&c15_gb_y, sf_mex_create("y", c15_cb_u, 0, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_addfield(c15_t_y, c15_gb_y, "F_z4_static", "F_z4_static", 0);
  c15_db_u = c15_p_u.Rw;
  c15_hb_y = NULL;
  sf_mex_assign(&c15_hb_y, sf_mex_create("y", &c15_db_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c15_t_y, c15_hb_y, "Rw", "Rw", 0);
  c15_eb_u = c15_p_u.r_long;
  c15_ib_y = NULL;
  sf_mex_assign(&c15_ib_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c15_i1 = 0; c15_i1 < 3; c15_i1++) {
    c15_fb_u[c15_i1] = c15_eb_u.fl[c15_i1];
  }

  c15_jb_y = NULL;
  sf_mex_assign(&c15_jb_y, sf_mex_create("y", c15_fb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c15_ib_y, c15_jb_y, "fl", "fl", 0);
  for (c15_i2 = 0; c15_i2 < 3; c15_i2++) {
    c15_gb_u[c15_i2] = c15_eb_u.fr[c15_i2];
  }

  c15_kb_y = NULL;
  sf_mex_assign(&c15_kb_y, sf_mex_create("y", c15_gb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c15_ib_y, c15_kb_y, "fr", "fr", 0);
  for (c15_i3 = 0; c15_i3 < 3; c15_i3++) {
    c15_hb_u[c15_i3] = c15_eb_u.rl[c15_i3];
  }

  c15_lb_y = NULL;
  sf_mex_assign(&c15_lb_y, sf_mex_create("y", c15_hb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c15_ib_y, c15_lb_y, "rl", "rl", 0);
  for (c15_i4 = 0; c15_i4 < 3; c15_i4++) {
    c15_ib_u[c15_i4] = c15_eb_u.rr[c15_i4];
  }

  c15_mb_y = NULL;
  sf_mex_assign(&c15_mb_y, sf_mex_create("y", c15_ib_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c15_ib_y, c15_mb_y, "rr", "rr", 0);
  sf_mex_addfield(c15_t_y, c15_ib_y, "r_long", "r_long", 0);
  c15_eb_u = c15_p_u.r_lat;
  c15_nb_y = NULL;
  sf_mex_assign(&c15_nb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c15_i5 = 0; c15_i5 < 3; c15_i5++) {
    c15_jb_u[c15_i5] = c15_eb_u.fl[c15_i5];
  }

  c15_ob_y = NULL;
  sf_mex_assign(&c15_ob_y, sf_mex_create("y", c15_jb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c15_nb_y, c15_ob_y, "fl", "fl", 0);
  for (c15_i6 = 0; c15_i6 < 3; c15_i6++) {
    c15_kb_u[c15_i6] = c15_eb_u.fr[c15_i6];
  }

  c15_pb_y = NULL;
  sf_mex_assign(&c15_pb_y, sf_mex_create("y", c15_kb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c15_nb_y, c15_pb_y, "fr", "fr", 0);
  for (c15_i7 = 0; c15_i7 < 3; c15_i7++) {
    c15_lb_u[c15_i7] = c15_eb_u.rl[c15_i7];
  }

  c15_qb_y = NULL;
  sf_mex_assign(&c15_qb_y, sf_mex_create("y", c15_lb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c15_nb_y, c15_qb_y, "rl", "rl", 0);
  for (c15_i8 = 0; c15_i8 < 3; c15_i8++) {
    c15_mb_u[c15_i8] = c15_eb_u.rr[c15_i8];
  }

  c15_rb_y = NULL;
  sf_mex_assign(&c15_rb_y, sf_mex_create("y", c15_mb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c15_nb_y, c15_rb_y, "rr", "rr", 0);
  sf_mex_addfield(c15_t_y, c15_nb_y, "r_lat", "r_lat", 0);
  c15_eb_u = c15_p_u.r_lever;
  c15_sb_y = NULL;
  sf_mex_assign(&c15_sb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c15_i9 = 0; c15_i9 < 3; c15_i9++) {
    c15_nb_u[c15_i9] = c15_eb_u.fl[c15_i9];
  }

  c15_tb_y = NULL;
  sf_mex_assign(&c15_tb_y, sf_mex_create("y", c15_nb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c15_sb_y, c15_tb_y, "fl", "fl", 0);
  for (c15_i10 = 0; c15_i10 < 3; c15_i10++) {
    c15_ob_u[c15_i10] = c15_eb_u.fr[c15_i10];
  }

  c15_ub_y = NULL;
  sf_mex_assign(&c15_ub_y, sf_mex_create("y", c15_ob_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c15_sb_y, c15_ub_y, "fr", "fr", 0);
  for (c15_i11 = 0; c15_i11 < 3; c15_i11++) {
    c15_pb_u[c15_i11] = c15_eb_u.rl[c15_i11];
  }

  c15_vb_y = NULL;
  sf_mex_assign(&c15_vb_y, sf_mex_create("y", c15_pb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c15_sb_y, c15_vb_y, "rl", "rl", 0);
  for (c15_i12 = 0; c15_i12 < 3; c15_i12++) {
    c15_qb_u[c15_i12] = c15_eb_u.rr[c15_i12];
  }

  c15_wb_y = NULL;
  sf_mex_assign(&c15_wb_y, sf_mex_create("y", c15_qb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c15_sb_y, c15_wb_y, "rr", "rr", 0);
  sf_mex_addfield(c15_t_y, c15_sb_y, "r_lever", "r_lever", 0);
  c15_eb_u = c15_p_u.r_pivot;
  c15_xb_y = NULL;
  sf_mex_assign(&c15_xb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c15_i13 = 0; c15_i13 < 3; c15_i13++) {
    c15_rb_u[c15_i13] = c15_eb_u.fl[c15_i13];
  }

  c15_yb_y = NULL;
  sf_mex_assign(&c15_yb_y, sf_mex_create("y", c15_rb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c15_xb_y, c15_yb_y, "fl", "fl", 0);
  for (c15_i14 = 0; c15_i14 < 3; c15_i14++) {
    c15_sb_u[c15_i14] = c15_eb_u.fr[c15_i14];
  }

  c15_ac_y = NULL;
  sf_mex_assign(&c15_ac_y, sf_mex_create("y", c15_sb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c15_xb_y, c15_ac_y, "fr", "fr", 0);
  for (c15_i15 = 0; c15_i15 < 3; c15_i15++) {
    c15_tb_u[c15_i15] = c15_eb_u.rl[c15_i15];
  }

  c15_bc_y = NULL;
  sf_mex_assign(&c15_bc_y, sf_mex_create("y", c15_tb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c15_xb_y, c15_bc_y, "rl", "rl", 0);
  for (c15_i16 = 0; c15_i16 < 3; c15_i16++) {
    c15_ub_u[c15_i16] = c15_eb_u.rr[c15_i16];
  }

  c15_cc_y = NULL;
  sf_mex_assign(&c15_cc_y, sf_mex_create("y", c15_ub_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c15_xb_y, c15_cc_y, "rr", "rr", 0);
  sf_mex_addfield(c15_t_y, c15_xb_y, "r_pivot", "r_pivot", 0);
  c15_vb_u = c15_p_u.cw;
  c15_dc_y = NULL;
  sf_mex_assign(&c15_dc_y, sf_mex_create("y", &c15_vb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c15_t_y, c15_dc_y, "cw", "cw", 0);
  c15_wb_u = c15_p_u.carb_f;
  c15_ec_y = NULL;
  sf_mex_assign(&c15_ec_y, sf_mex_create("y", &c15_wb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c15_t_y, c15_ec_y, "carb_f", "carb_f", 0);
  c15_xb_u = c15_p_u.carb_r;
  c15_fc_y = NULL;
  sf_mex_assign(&c15_fc_y, sf_mex_create("y", &c15_xb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c15_t_y, c15_fc_y, "carb_r", "carb_r", 0);
  c15_yb_u = c15_p_u.dw;
  c15_gc_y = NULL;
  sf_mex_assign(&c15_gc_y, sf_mex_create("y", &c15_yb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c15_t_y, c15_gc_y, "dw", "dw", 0);
  c15_ac_u = c15_p_u.Jw;
  c15_hc_y = NULL;
  sf_mex_assign(&c15_hc_y, sf_mex_create("y", &c15_ac_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c15_t_y, c15_hc_y, "Jw", "Jw", 0);
  c15_bc_u = c15_p_u.C0;
  c15_ic_y = NULL;
  sf_mex_assign(&c15_ic_y, sf_mex_create("y", &c15_bc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c15_t_y, c15_ic_y, "C0", "C0", 0);
  c15_cc_u = c15_p_u.RelaxLength;
  c15_jc_y = NULL;
  sf_mex_assign(&c15_jc_y, sf_mex_create("y", &c15_cc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c15_t_y, c15_jc_y, "RelaxLength", "RelaxLength", 0);
  c15_dc_u = c15_p_u.RRC;
  c15_kc_y = NULL;
  sf_mex_assign(&c15_kc_y, sf_mex_create("y", &c15_dc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c15_t_y, c15_kc_y, "RRC", "RRC", 0);
  c15_ec_u = c15_p_u.Pmax;
  c15_lc_y = NULL;
  sf_mex_assign(&c15_lc_y, sf_mex_create("y", &c15_ec_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c15_t_y, c15_lc_y, "Pmax", "Pmax", 0);
  c15_fc_u = c15_p_u.PropDistrFrnt;
  c15_mc_y = NULL;
  sf_mex_assign(&c15_mc_y, sf_mex_create("y", &c15_fc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c15_t_y, c15_mc_y, "PropDistrFrnt", "PropDistrFrnt", 0);
  c15_gc_u = c15_p_u.BrkDistrFrnt;
  c15_nc_y = NULL;
  sf_mex_assign(&c15_nc_y, sf_mex_create("y", &c15_gc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c15_t_y, c15_nc_y, "BrkDistrFrnt", "BrkDistrFrnt", 0);
  c15_hc_u = c15_p_u.SteRatio;
  c15_oc_y = NULL;
  sf_mex_assign(&c15_oc_y, sf_mex_create("y", &c15_hc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c15_t_y, c15_oc_y, "SteRatio", "SteRatio", 0);
  sf_mex_addfield(c15_y, c15_t_y, "Veh", "Veh", 0);
  c15_ic_u = c15_u.Drvr;
  c15_pc_y = NULL;
  sf_mex_assign(&c15_pc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c15_jc_u = c15_ic_u.v_set;
  c15_qc_y = NULL;
  sf_mex_assign(&c15_qc_y, sf_mex_create("y", &c15_jc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c15_pc_y, c15_qc_y, "v_set", "v_set", 0);
  sf_mex_addfield(c15_y, c15_pc_y, "Drvr", "Drvr", 0);
  c15_kc_u = c15_u.Init;
  c15_rc_y = NULL;
  sf_mex_assign(&c15_rc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c15_lc_u = c15_kc_u.v_x;
  c15_sc_y = NULL;
  sf_mex_assign(&c15_sc_y, sf_mex_create("y", &c15_lc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c15_rc_y, c15_sc_y, "v_x", "v_x", 0);
  c15_mc_u = c15_kc_u.F_fz;
  c15_tc_y = NULL;
  sf_mex_assign(&c15_tc_y, sf_mex_create("y", &c15_mc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c15_rc_y, c15_tc_y, "F_fz", "F_fz", 0);
  c15_nc_u = c15_kc_u.F_rz;
  c15_uc_y = NULL;
  sf_mex_assign(&c15_uc_y, sf_mex_create("y", &c15_nc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c15_rc_y, c15_uc_y, "F_rz", "F_rz", 0);
  sf_mex_addfield(c15_y, c15_rc_y, "Init", "Init", 0);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, false);
  return c15_mxArrayOutData;
}

static void c15_d_emlrt_marshallIn
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
   c15_struct_iBlsPBO3AGnt69vDoTx5zD *c15_y)
{
  emlrtMsgIdentifier c15_thisId;
  static const char * c15_fieldNames[4] = { "Env", "Veh", "Drvr", "Init" };

  c15_thisId.fParent = c15_parentId;
  sf_mex_check_struct(c15_parentId, c15_u, 4, c15_fieldNames, 0U, NULL);
  c15_thisId.fIdentifier = "Env";
  c15_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c15_u, "Env",
    "Env", 0)), &c15_thisId, &c15_y->Env);
  c15_thisId.fIdentifier = "Veh";
  c15_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c15_u, "Veh",
    "Veh", 0)), &c15_thisId, &c15_y->Veh);
  c15_thisId.fIdentifier = "Drvr";
  c15_y->Drvr = c15_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c15_u, "Drvr", "Drvr", 0)), &c15_thisId);
  c15_thisId.fIdentifier = "Init";
  c15_y->Init = c15_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c15_u, "Init", "Init", 0)), &c15_thisId);
  sf_mex_destroy(&c15_u);
}

static void c15_e_emlrt_marshallIn
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
   c15_struct_Nst2vGTExxHsg85EUOj9EH *c15_y)
{
  emlrtMsgIdentifier c15_thisId;
  static const char * c15_fieldNames[7] = { "g", "left1", "right1", "right2",
    "left2", "right3", "mu" };

  c15_thisId.fParent = c15_parentId;
  sf_mex_check_struct(c15_parentId, c15_u, 7, c15_fieldNames, 0U, NULL);
  c15_thisId.fIdentifier = "g";
  c15_y->g = c15_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c15_u, "g", "g", 0)), &c15_thisId);
  c15_thisId.fIdentifier = "left1";
  c15_y->left1 = c15_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c15_u, "left1", "left1", 0)), &c15_thisId);
  c15_thisId.fIdentifier = "right1";
  c15_y->right1 = c15_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c15_u, "right1", "right1", 0)), &c15_thisId);
  c15_thisId.fIdentifier = "right2";
  c15_y->right2 = c15_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c15_u, "right2", "right2", 0)), &c15_thisId);
  c15_thisId.fIdentifier = "left2";
  c15_y->left2 = c15_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c15_u, "left2", "left2", 0)), &c15_thisId);
  c15_thisId.fIdentifier = "right3";
  c15_y->right3 = c15_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c15_u, "right3", "right3", 0)), &c15_thisId);
  c15_thisId.fIdentifier = "mu";
  c15_y->mu = c15_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c15_u, "mu", "mu", 0)), &c15_thisId);
  sf_mex_destroy(&c15_u);
}

static c15_struct_HhckT6rntEraqECYVIDvCC c15_f_emlrt_marshallIn
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId)
{
  c15_struct_HhckT6rntEraqECYVIDvCC c15_y;
  emlrtMsgIdentifier c15_thisId;
  static const char * c15_fieldNames[2] = { "x", "y" };

  c15_thisId.fParent = c15_parentId;
  sf_mex_check_struct(c15_parentId, c15_u, 2, c15_fieldNames, 0U, NULL);
  c15_thisId.fIdentifier = "x";
  c15_y.x = c15_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c15_u, "x", "x", 0)), &c15_thisId);
  c15_thisId.fIdentifier = "y";
  c15_y.y = c15_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c15_u, "y", "y", 0)), &c15_thisId);
  sf_mex_destroy(&c15_u);
  return c15_y;
}

static void c15_g_emlrt_marshallIn
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
   c15_struct_ZCmOWPuqBDw16FSOVVD00 *c15_y)
{
  emlrtMsgIdentifier c15_thisId;
  static const char * c15_fieldNames[29] = { "m", "Jz", "m_sprung", "Jx_sprung",
    "Jy_sprung", "lf", "lr", "L", "TrackWidth", "h", "HalfRohACd", "F_z4_static",
    "Rw", "r_long", "r_lat", "r_lever", "r_pivot", "cw", "carb_f", "carb_r",
    "dw", "Jw", "C0", "RelaxLength", "RRC", "Pmax", "PropDistrFrnt",
    "BrkDistrFrnt", "SteRatio" };

  c15_thisId.fParent = c15_parentId;
  sf_mex_check_struct(c15_parentId, c15_u, 29, c15_fieldNames, 0U, NULL);
  c15_thisId.fIdentifier = "m";
  c15_y->m = c15_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c15_u, "m", "m", 0)), &c15_thisId);
  c15_thisId.fIdentifier = "Jz";
  c15_y->Jz = c15_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c15_u, "Jz", "Jz", 0)), &c15_thisId);
  c15_thisId.fIdentifier = "m_sprung";
  c15_y->m_sprung = c15_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c15_u, "m_sprung", "m_sprung", 0)), &c15_thisId);
  c15_thisId.fIdentifier = "Jx_sprung";
  c15_y->Jx_sprung = c15_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c15_u, "Jx_sprung", "Jx_sprung", 0)), &c15_thisId);
  c15_thisId.fIdentifier = "Jy_sprung";
  c15_y->Jy_sprung = c15_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c15_u, "Jy_sprung", "Jy_sprung", 0)), &c15_thisId);
  c15_thisId.fIdentifier = "lf";
  c15_y->lf = c15_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c15_u, "lf", "lf", 0)), &c15_thisId);
  c15_thisId.fIdentifier = "lr";
  c15_y->lr = c15_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c15_u, "lr", "lr", 0)), &c15_thisId);
  c15_thisId.fIdentifier = "L";
  c15_y->L = c15_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c15_u, "L", "L", 0)), &c15_thisId);
  c15_thisId.fIdentifier = "TrackWidth";
  c15_y->TrackWidth = c15_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c15_u, "TrackWidth", "TrackWidth", 0)), &c15_thisId);
  c15_thisId.fIdentifier = "h";
  c15_y->h = c15_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c15_u, "h", "h", 0)), &c15_thisId);
  c15_thisId.fIdentifier = "HalfRohACd";
  c15_y->HalfRohACd = c15_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c15_u, "HalfRohACd", "HalfRohACd", 0)), &c15_thisId);
  c15_thisId.fIdentifier = "F_z4_static";
  c15_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c15_u,
    "F_z4_static", "F_z4_static", 0)), &c15_thisId, c15_y->F_z4_static);
  c15_thisId.fIdentifier = "Rw";
  c15_y->Rw = c15_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c15_u, "Rw", "Rw", 0)), &c15_thisId);
  c15_thisId.fIdentifier = "r_long";
  c15_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c15_u,
    "r_long", "r_long", 0)), &c15_thisId, &c15_y->r_long);
  c15_thisId.fIdentifier = "r_lat";
  c15_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c15_u,
    "r_lat", "r_lat", 0)), &c15_thisId, &c15_y->r_lat);
  c15_thisId.fIdentifier = "r_lever";
  c15_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c15_u,
    "r_lever", "r_lever", 0)), &c15_thisId, &c15_y->r_lever);
  c15_thisId.fIdentifier = "r_pivot";
  c15_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c15_u,
    "r_pivot", "r_pivot", 0)), &c15_thisId, &c15_y->r_pivot);
  c15_thisId.fIdentifier = "cw";
  c15_y->cw = c15_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c15_u, "cw", "cw", 0)), &c15_thisId);
  c15_thisId.fIdentifier = "carb_f";
  c15_y->carb_f = c15_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c15_u, "carb_f", "carb_f", 0)), &c15_thisId);
  c15_thisId.fIdentifier = "carb_r";
  c15_y->carb_r = c15_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c15_u, "carb_r", "carb_r", 0)), &c15_thisId);
  c15_thisId.fIdentifier = "dw";
  c15_y->dw = c15_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c15_u, "dw", "dw", 0)), &c15_thisId);
  c15_thisId.fIdentifier = "Jw";
  c15_y->Jw = c15_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c15_u, "Jw", "Jw", 0)), &c15_thisId);
  c15_thisId.fIdentifier = "C0";
  c15_y->C0 = c15_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c15_u, "C0", "C0", 0)), &c15_thisId);
  c15_thisId.fIdentifier = "RelaxLength";
  c15_y->RelaxLength = c15_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c15_u, "RelaxLength", "RelaxLength", 0)), &c15_thisId);
  c15_thisId.fIdentifier = "RRC";
  c15_y->RRC = c15_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c15_u, "RRC", "RRC", 0)), &c15_thisId);
  c15_thisId.fIdentifier = "Pmax";
  c15_y->Pmax = c15_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c15_u, "Pmax", "Pmax", 0)), &c15_thisId);
  c15_thisId.fIdentifier = "PropDistrFrnt";
  c15_y->PropDistrFrnt = c15_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c15_u, "PropDistrFrnt", "PropDistrFrnt", 0)), &c15_thisId);
  c15_thisId.fIdentifier = "BrkDistrFrnt";
  c15_y->BrkDistrFrnt = c15_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c15_u, "BrkDistrFrnt", "BrkDistrFrnt", 0)), &c15_thisId);
  c15_thisId.fIdentifier = "SteRatio";
  c15_y->SteRatio = c15_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c15_u, "SteRatio", "SteRatio", 0)), &c15_thisId);
  sf_mex_destroy(&c15_u);
}

static void c15_h_emlrt_marshallIn
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId, real_T c15_y[4])
{
  real_T c15_dv0[4];
  int32_T c15_i17;
  (void)chartInstance;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), c15_dv0, 1, 0, 0U, 1, 0U, 2, 1,
                4);
  for (c15_i17 = 0; c15_i17 < 4; c15_i17++) {
    c15_y[c15_i17] = c15_dv0[c15_i17];
  }

  sf_mex_destroy(&c15_u);
}

static void c15_i_emlrt_marshallIn
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
   c15_struct_ZKAzdrl7umDGJoC14aoVKC *c15_y)
{
  emlrtMsgIdentifier c15_thisId;
  static const char * c15_fieldNames[4] = { "fl", "fr", "rl", "rr" };

  c15_thisId.fParent = c15_parentId;
  sf_mex_check_struct(c15_parentId, c15_u, 4, c15_fieldNames, 0U, NULL);
  c15_thisId.fIdentifier = "fl";
  c15_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c15_u, "fl",
    "fl", 0)), &c15_thisId, c15_y->fl);
  c15_thisId.fIdentifier = "fr";
  c15_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c15_u, "fr",
    "fr", 0)), &c15_thisId, c15_y->fr);
  c15_thisId.fIdentifier = "rl";
  c15_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c15_u, "rl",
    "rl", 0)), &c15_thisId, c15_y->rl);
  c15_thisId.fIdentifier = "rr";
  c15_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c15_u, "rr",
    "rr", 0)), &c15_thisId, c15_y->rr);
  sf_mex_destroy(&c15_u);
}

static void c15_j_emlrt_marshallIn
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId, real_T c15_y[3])
{
  real_T c15_dv1[3];
  int32_T c15_i18;
  (void)chartInstance;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), c15_dv1, 1, 0, 0U, 1, 0U, 2, 3,
                1);
  for (c15_i18 = 0; c15_i18 < 3; c15_i18++) {
    c15_y[c15_i18] = c15_dv1[c15_i18];
  }

  sf_mex_destroy(&c15_u);
}

static c15_struct_r4FNviKwHfdhB8nQjvQv9 c15_k_emlrt_marshallIn
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId)
{
  c15_struct_r4FNviKwHfdhB8nQjvQv9 c15_y;
  emlrtMsgIdentifier c15_thisId;
  static const char * c15_fieldNames[1] = { "v_set" };

  c15_thisId.fParent = c15_parentId;
  sf_mex_check_struct(c15_parentId, c15_u, 1, c15_fieldNames, 0U, NULL);
  c15_thisId.fIdentifier = "v_set";
  c15_y.v_set = c15_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c15_u, "v_set", "v_set", 0)),
    &c15_thisId);
  sf_mex_destroy(&c15_u);
  return c15_y;
}

static c15_struct_Y9F1qlBi9AhssksPwemA4G c15_l_emlrt_marshallIn
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId)
{
  c15_struct_Y9F1qlBi9AhssksPwemA4G c15_y;
  emlrtMsgIdentifier c15_thisId;
  static const char * c15_fieldNames[3] = { "v_x", "F_fz", "F_rz" };

  c15_thisId.fParent = c15_parentId;
  sf_mex_check_struct(c15_parentId, c15_u, 3, c15_fieldNames, 0U, NULL);
  c15_thisId.fIdentifier = "v_x";
  c15_y.v_x = c15_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c15_u, "v_x", "v_x", 0)), &c15_thisId);
  c15_thisId.fIdentifier = "F_fz";
  c15_y.F_fz = c15_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c15_u, "F_fz", "F_fz", 0)), &c15_thisId);
  c15_thisId.fIdentifier = "F_rz";
  c15_y.F_rz = c15_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c15_u, "F_rz", "F_rz", 0)), &c15_thisId);
  sf_mex_destroy(&c15_u);
  return c15_y;
}

static void c15_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_b_Par;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  c15_struct_iBlsPBO3AGnt69vDoTx5zD c15_y;
  SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c15_b_Par = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_b_Par), &c15_thisId,
    &c15_y);
  sf_mex_destroy(&c15_b_Par);
  *(c15_struct_iBlsPBO3AGnt69vDoTx5zD *)c15_outData = c15_y;
  sf_mex_destroy(&c15_mxArrayInData);
}

static const mxArray *c15_c_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  real_T c15_u;
  const mxArray *c15_y = NULL;
  SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  c15_u = *(real_T *)c15_inData;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", &c15_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, false);
  return c15_mxArrayOutData;
}

static void c15_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_nargout;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  real_T c15_y;
  SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c15_nargout = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_y = c15_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_nargout),
    &c15_thisId);
  sf_mex_destroy(&c15_nargout);
  *(real_T *)c15_outData = c15_y;
  sf_mex_destroy(&c15_mxArrayInData);
}

static const mxArray *c15_d_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  int32_T c15_i19;
  real_T c15_b_inData[4];
  int32_T c15_i20;
  real_T c15_u[4];
  const mxArray *c15_y = NULL;
  SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  for (c15_i19 = 0; c15_i19 < 4; c15_i19++) {
    c15_b_inData[c15_i19] = (*(real_T (*)[4])c15_inData)[c15_i19];
  }

  for (c15_i20 = 0; c15_i20 < 4; c15_i20++) {
    c15_u[c15_i20] = c15_b_inData[c15_i20];
  }

  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", c15_u, 0, 0U, 1U, 0U, 1, 4), false);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, false);
  return c15_mxArrayOutData;
}

static void c15_m_emlrt_marshallIn
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId, real_T c15_y[4])
{
  real_T c15_dv2[4];
  int32_T c15_i21;
  (void)chartInstance;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), c15_dv2, 1, 0, 0U, 1, 0U, 1, 4);
  for (c15_i21 = 0; c15_i21 < 4; c15_i21++) {
    c15_y[c15_i21] = c15_dv2[c15_i21];
  }

  sf_mex_destroy(&c15_u);
}

static void c15_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_F_z4_temp;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  real_T c15_y[4];
  int32_T c15_i22;
  SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c15_F_z4_temp = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_F_z4_temp), &c15_thisId,
    c15_y);
  sf_mex_destroy(&c15_F_z4_temp);
  for (c15_i22 = 0; c15_i22 < 4; c15_i22++) {
    (*(real_T (*)[4])c15_outData)[c15_i22] = c15_y[c15_i22];
  }

  sf_mex_destroy(&c15_mxArrayInData);
}

const mxArray
  *sf_c15_AllPurposeModel_TyreRelaxation_get_eml_resolved_functions_info(void)
{
  const mxArray *c15_nameCaptureInfo = NULL;
  c15_nameCaptureInfo = NULL;
  sf_mex_assign(&c15_nameCaptureInfo, sf_mex_createstruct("structure", 2, 7, 1),
                false);
  c15_info_helper(&c15_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c15_nameCaptureInfo);
  return c15_nameCaptureInfo;
}

static void c15_info_helper(const mxArray **c15_info)
{
  const mxArray *c15_rhs0 = NULL;
  const mxArray *c15_lhs0 = NULL;
  const mxArray *c15_rhs1 = NULL;
  const mxArray *c15_lhs1 = NULL;
  const mxArray *c15_rhs2 = NULL;
  const mxArray *c15_lhs2 = NULL;
  const mxArray *c15_rhs3 = NULL;
  const mxArray *c15_lhs3 = NULL;
  const mxArray *c15_rhs4 = NULL;
  const mxArray *c15_lhs4 = NULL;
  const mxArray *c15_rhs5 = NULL;
  const mxArray *c15_lhs5 = NULL;
  const mxArray *c15_rhs6 = NULL;
  const mxArray *c15_lhs6 = NULL;
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("mrdivide"), "name", "name",
                  0);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1410807648U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1370009886U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c15_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1389717774U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c15_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("rdivide"), "name", "name", 2);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1363713880U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c15_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c15_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 4);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c15_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("eml_div"), "name", "name", 5);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1386423952U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c15_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 6);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c15_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs6), "lhs", "lhs",
                  6);
  sf_mex_destroy(&c15_rhs0);
  sf_mex_destroy(&c15_lhs0);
  sf_mex_destroy(&c15_rhs1);
  sf_mex_destroy(&c15_lhs1);
  sf_mex_destroy(&c15_rhs2);
  sf_mex_destroy(&c15_lhs2);
  sf_mex_destroy(&c15_rhs3);
  sf_mex_destroy(&c15_lhs3);
  sf_mex_destroy(&c15_rhs4);
  sf_mex_destroy(&c15_lhs4);
  sf_mex_destroy(&c15_rhs5);
  sf_mex_destroy(&c15_lhs5);
  sf_mex_destroy(&c15_rhs6);
  sf_mex_destroy(&c15_lhs6);
}

static const mxArray *c15_emlrt_marshallOut(const char * c15_u)
{
  const mxArray *c15_y = NULL;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", c15_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c15_u)), false);
  return c15_y;
}

static const mxArray *c15_b_emlrt_marshallOut(const uint32_T c15_u)
{
  const mxArray *c15_y = NULL;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", &c15_u, 7, 0U, 0U, 0U, 0), false);
  return c15_y;
}

static const mxArray *c15_e_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  int32_T c15_u;
  const mxArray *c15_y = NULL;
  SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  c15_u = *(int32_T *)c15_inData;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", &c15_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, false);
  return c15_mxArrayOutData;
}

static int32_T c15_n_emlrt_marshallIn
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId)
{
  int32_T c15_y;
  int32_T c15_i23;
  (void)chartInstance;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), &c15_i23, 1, 6, 0U, 0, 0U, 0);
  c15_y = c15_i23;
  sf_mex_destroy(&c15_u);
  return c15_y;
}

static void c15_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_b_sfEvent;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  int32_T c15_y;
  SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c15_b_sfEvent = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_y = c15_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_b_sfEvent),
    &c15_thisId);
  sf_mex_destroy(&c15_b_sfEvent);
  *(int32_T *)c15_outData = c15_y;
  sf_mex_destroy(&c15_mxArrayInData);
}

static const mxArray *c15_s_x4_bus_io(void *chartInstanceVoid, void *c15_pData)
{
  const mxArray *c15_mxVal = NULL;
  c15_whl_vec4 c15_tmp;
  SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c15_mxVal = NULL;
  c15_tmp.fl = *(real_T *)&((char_T *)(c15_whl_vec4 *)c15_pData)[0];
  c15_tmp.fr = *(real_T *)&((char_T *)(c15_whl_vec4 *)c15_pData)[8];
  c15_tmp.rl = *(real_T *)&((char_T *)(c15_whl_vec4 *)c15_pData)[16];
  c15_tmp.rr = *(real_T *)&((char_T *)(c15_whl_vec4 *)c15_pData)[24];
  sf_mex_assign(&c15_mxVal, c15_sf_marshallOut(chartInstance, &c15_tmp), false);
  return c15_mxVal;
}

static uint8_T c15_o_emlrt_marshallIn
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c15_b_is_active_c15_AllPurposeModel_TyreRelaxation, const char_T
   *c15_identifier)
{
  uint8_T c15_y;
  emlrtMsgIdentifier c15_thisId;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_y = c15_p_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c15_b_is_active_c15_AllPurposeModel_TyreRelaxation), &c15_thisId);
  sf_mex_destroy(&c15_b_is_active_c15_AllPurposeModel_TyreRelaxation);
  return c15_y;
}

static uint8_T c15_p_emlrt_marshallIn
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId)
{
  uint8_T c15_y;
  uint8_T c15_u0;
  (void)chartInstance;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), &c15_u0, 1, 3, 0U, 0, 0U, 0);
  c15_y = c15_u0;
  sf_mex_destroy(&c15_u);
  return c15_y;
}

static void init_dsm_address_info
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address
  (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  chartInstance->c15_s_x4 = (c15_whl_vec4 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c15_s_y4 = (c15_whl_vec4 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c15_s_xy4 = (c15_whl_vec4 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c15_F_xyw4 = (c15_whl_vec4 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c15_F_z4_prev = (c15_whl_vec4 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c15_F_xw4 = (c15_whl_vec4 *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c15_F_yw4 = (c15_whl_vec4 *)ssGetOutputPortSignal_wrapper
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

void sf_c15_AllPurposeModel_TyreRelaxation_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(859601713U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2845577817U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(972611446U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(192564767U);
}

mxArray* sf_c15_AllPurposeModel_TyreRelaxation_get_post_codegen_info(void);
mxArray *sf_c15_AllPurposeModel_TyreRelaxation_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("t8eR9VyOLo3ZobqVuKnqRB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo =
      sf_c15_AllPurposeModel_TyreRelaxation_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c15_AllPurposeModel_TyreRelaxation_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c15_AllPurposeModel_TyreRelaxation_jit_fallback_info(void)
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

mxArray *sf_c15_AllPurposeModel_TyreRelaxation_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c15_AllPurposeModel_TyreRelaxation_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c15_AllPurposeModel_TyreRelaxation
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[49],T\"F_xw4\",},{M[1],M[50],T\"F_yw4\",},{M[8],M[0],T\"is_active_c15_AllPurposeModel_TyreRelaxation\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c15_AllPurposeModel_TyreRelaxation_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _AllPurposeModel_TyreRelaxationMachineNumber_,
           15,
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
        init_script_number_translation
          (_AllPurposeModel_TyreRelaxationMachineNumber_,
           chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _AllPurposeModel_TyreRelaxationMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _AllPurposeModel_TyreRelaxationMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"s_x4");
          _SFD_SET_DATA_PROPS(1,1,1,0,"s_y4");
          _SFD_SET_DATA_PROPS(2,1,1,0,"s_xy4");
          _SFD_SET_DATA_PROPS(3,1,1,0,"F_xyw4");
          _SFD_SET_DATA_PROPS(4,1,1,0,"F_z4_prev");
          _SFD_SET_DATA_PROPS(5,2,0,1,"F_xw4");
          _SFD_SET_DATA_PROPS(6,2,0,1,"F_yw4");
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
        _SFD_CV_INIT_EML(0,1,1,4,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,2655);
        _SFD_CV_INIT_EML_IF(0,1,0,268,301,390,565);
        _SFD_CV_INIT_EML_IF(0,1,1,567,600,689,791);
        _SFD_CV_INIT_EML_IF(0,1,2,793,826,915,1017);
        _SFD_CV_INIT_EML_IF(0,1,3,1019,1052,1141,1243);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,271,301,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,570,600,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,2,796,826,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,3,1022,1052,-1,4);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_s_x4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_s_x4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_s_x4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_s_x4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_s_x4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_s_x4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_s_x4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_b_sf_marshallOut,(MexInFcnForType)
          c15_b_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c15_s_x4);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c15_s_y4);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c15_s_xy4);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c15_F_xyw4);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c15_F_z4_prev);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c15_F_xw4);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c15_F_yw4);
        _SFD_SET_DATA_VALUE_PTR(7U, &chartInstance->c15_Par);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _AllPurposeModel_TyreRelaxationMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "CdMwZd5ZINXTTrKHPqfMxC";
}

static void sf_opaque_initialize_c15_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc15_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar)->S,
     0);
  initialize_params_c15_AllPurposeModel_TyreRelaxation
    ((SFc15_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
  initialize_c15_AllPurposeModel_TyreRelaxation
    ((SFc15_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c15_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  enable_c15_AllPurposeModel_TyreRelaxation
    ((SFc15_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c15_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  disable_c15_AllPurposeModel_TyreRelaxation
    ((SFc15_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c15_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  sf_gateway_c15_AllPurposeModel_TyreRelaxation
    ((SFc15_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c15_AllPurposeModel_TyreRelaxation
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c15_AllPurposeModel_TyreRelaxation
    ((SFc15_AllPurposeModel_TyreRelaxationInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c15_AllPurposeModel_TyreRelaxation(SimStruct*
  S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c15_AllPurposeModel_TyreRelaxation
    ((SFc15_AllPurposeModel_TyreRelaxationInstanceStruct*)
     chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c15_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc15_AllPurposeModel_TyreRelaxationInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_AllPurposeModel_TyreRelaxation_optimization_info();
    }

    finalize_c15_AllPurposeModel_TyreRelaxation
      ((SFc15_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc15_AllPurposeModel_TyreRelaxation
    ((SFc15_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c15_AllPurposeModel_TyreRelaxation(SimStruct *S)
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
    initialize_params_c15_AllPurposeModel_TyreRelaxation
      ((SFc15_AllPurposeModel_TyreRelaxationInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c15_AllPurposeModel_TyreRelaxation(SimStruct *S)
{
  /* Actual parameters from chart:
     Par
   */
  const char_T *rtParamNames[] = { "Par" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0],
    sf_get_param_data_type_id(S,0));
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_AllPurposeModel_TyreRelaxation_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      15);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,15,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,15,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,15);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,15,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,15,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 5; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,15);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(769294432U));
  ssSetChecksum1(S,(958749773U));
  ssSetChecksum2(S,(4280547213U));
  ssSetChecksum3(S,(3836468109U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c15_AllPurposeModel_TyreRelaxation(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c15_AllPurposeModel_TyreRelaxation(SimStruct *S)
{
  SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct *)utMalloc
    (sizeof(SFc15_AllPurposeModel_TyreRelaxationInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc15_AllPurposeModel_TyreRelaxationInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c15_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c15_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c15_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c15_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c15_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c15_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c15_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c15_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c15_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c15_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c15_AllPurposeModel_TyreRelaxation;
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

void c15_AllPurposeModel_TyreRelaxation_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c15_AllPurposeModel_TyreRelaxation(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c15_AllPurposeModel_TyreRelaxation(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c15_AllPurposeModel_TyreRelaxation(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c15_AllPurposeModel_TyreRelaxation_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
