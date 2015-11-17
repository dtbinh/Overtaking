/* Include files */

#include <stddef.h>
#include "blas.h"
#include "AllPurposeModel_TyreRelaxation_sfun.h"
#include "c4_AllPurposeModel_TyreRelaxation.h"
#include "mwmathutil.h"
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
static const char * c4_debug_family_names[9] = { "C0", "mu", "Rw", "nargin",
  "nargout", "s_xy4", "F_z4", "Par", "F_xywSS4" };

/* Function Declarations */
static void initialize_c4_AllPurposeModel_TyreRelaxation
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void initialize_params_c4_AllPurposeModel_TyreRelaxation
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void enable_c4_AllPurposeModel_TyreRelaxation
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void disable_c4_AllPurposeModel_TyreRelaxation
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void c4_update_debugger_state_c4_AllPurposeModel_TyreRelaxation
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c4_AllPurposeModel_TyreRelaxation
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void set_sim_state_c4_AllPurposeModel_TyreRelaxation
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c4_st);
static void finalize_c4_AllPurposeModel_TyreRelaxation
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void sf_gateway_c4_AllPurposeModel_TyreRelaxation
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void mdl_start_c4_AllPurposeModel_TyreRelaxation
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void c4_chartstep_c4_AllPurposeModel_TyreRelaxation
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void initSimStructsc4_AllPurposeModel_TyreRelaxation
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static c4_whl_vec4 c4_emlrt_marshallIn
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c4_b_F_xywSS4, const char_T *c4_identifier);
static c4_whl_vec4 c4_b_emlrt_marshallIn
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static real_T c4_c_emlrt_marshallIn
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_d_emlrt_marshallIn
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
   c4_struct_iBlsPBO3AGnt69vDoTx5zD *c4_y);
static void c4_e_emlrt_marshallIn
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
   c4_struct_Nst2vGTExxHsg85EUOj9EH *c4_y);
static c4_struct_HhckT6rntEraqECYVIDvCC c4_f_emlrt_marshallIn
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_g_emlrt_marshallIn
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
   c4_struct_ZCmOWPuqBDw16FSOVVD00 *c4_y);
static void c4_h_emlrt_marshallIn
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[4]);
static void c4_i_emlrt_marshallIn
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
   c4_struct_ZKAzdrl7umDGJoC14aoVKC *c4_y);
static void c4_j_emlrt_marshallIn
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[3]);
static c4_struct_r4FNviKwHfdhB8nQjvQv9 c4_k_emlrt_marshallIn
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static c4_struct_Y9F1qlBi9AhssksPwemA4G c4_l_emlrt_marshallIn
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static void c4_info_helper(const mxArray **c4_info);
static const mxArray *c4_emlrt_marshallOut(const char * c4_u);
static const mxArray *c4_b_emlrt_marshallOut(const uint32_T c4_u);
static void c4_eml_scalar_eg(SFc4_AllPurposeModel_TyreRelaxationInstanceStruct
  *chartInstance);
static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_m_emlrt_marshallIn
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_s_xy4_bus_io(void *chartInstanceVoid, void *c4_pData);
static uint8_T c4_n_emlrt_marshallIn
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c4_b_is_active_c4_AllPurposeModel_TyreRelaxation, const char_T
   *c4_identifier);
static uint8_T c4_o_emlrt_marshallIn
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void init_dsm_address_info
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void init_simulink_io_address
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c4_AllPurposeModel_TyreRelaxation
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c4_is_active_c4_AllPurposeModel_TyreRelaxation = 0U;
}

static void initialize_params_c4_AllPurposeModel_TyreRelaxation
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  const mxArray *c4_m0 = NULL;
  const mxArray *c4_mxField;
  const mxArray *c4_m1 = NULL;
  const mxArray *c4_b_mxField;
  c4_struct_iBlsPBO3AGnt69vDoTx5zD c4_r0;
  const mxArray *c4_m2 = NULL;
  const mxArray *c4_c_mxField;
  const mxArray *c4_m3 = NULL;
  const mxArray *c4_d_mxField;
  const mxArray *c4_m4 = NULL;
  const mxArray *c4_e_mxField;
  const mxArray *c4_m5 = NULL;
  const mxArray *c4_f_mxField;
  const mxArray *c4_m6 = NULL;
  const mxArray *c4_g_mxField;
  const mxArray *c4_m7 = NULL;
  const mxArray *c4_h_mxField;
  const mxArray *c4_m8 = NULL;
  const mxArray *c4_i_mxField;
  const mxArray *c4_m9 = NULL;
  const mxArray *c4_j_mxField;
  const mxArray *c4_m10 = NULL;
  const mxArray *c4_k_mxField;
  const mxArray *c4_m11 = NULL;
  const mxArray *c4_l_mxField;
  const mxArray *c4_m12 = NULL;
  const mxArray *c4_m_mxField;
  const mxArray *c4_m13 = NULL;
  const mxArray *c4_n_mxField;
  c4_m0 = sf_mex_get_sfun_param(chartInstance->S, 0, 1);
  c4_mxField = sf_mex_getfield(c4_m0, "Env", "Par", 0);
  c4_m1 = sf_mex_dup(c4_mxField);
  c4_b_mxField = sf_mex_getfield(c4_m1, "g", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_b_mxField), &c4_r0.Env.g, 1, 0, 0U, 0,
                      0U, 0);
  c4_b_mxField = sf_mex_getfield(c4_m1, "left1", "Par", 0);
  c4_m2 = sf_mex_dup(c4_b_mxField);
  c4_c_mxField = sf_mex_getfield(c4_m2, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_c_mxField), &c4_r0.Env.left1.x, 1, 0,
                      0U, 0, 0U, 0);
  c4_c_mxField = sf_mex_getfield(c4_m2, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_c_mxField), &c4_r0.Env.left1.y, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c4_m2);
  c4_b_mxField = sf_mex_getfield(c4_m1, "right1", "Par", 0);
  c4_m3 = sf_mex_dup(c4_b_mxField);
  c4_d_mxField = sf_mex_getfield(c4_m3, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_d_mxField), &c4_r0.Env.right1.x, 1, 0,
                      0U, 0, 0U, 0);
  c4_d_mxField = sf_mex_getfield(c4_m3, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_d_mxField), &c4_r0.Env.right1.y, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c4_m3);
  c4_b_mxField = sf_mex_getfield(c4_m1, "right2", "Par", 0);
  c4_m4 = sf_mex_dup(c4_b_mxField);
  c4_e_mxField = sf_mex_getfield(c4_m4, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_e_mxField), &c4_r0.Env.right2.x, 1, 0,
                      0U, 0, 0U, 0);
  c4_e_mxField = sf_mex_getfield(c4_m4, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_e_mxField), &c4_r0.Env.right2.y, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c4_m4);
  c4_b_mxField = sf_mex_getfield(c4_m1, "left2", "Par", 0);
  c4_m5 = sf_mex_dup(c4_b_mxField);
  c4_f_mxField = sf_mex_getfield(c4_m5, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_f_mxField), &c4_r0.Env.left2.x, 1, 0,
                      0U, 0, 0U, 0);
  c4_f_mxField = sf_mex_getfield(c4_m5, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_f_mxField), &c4_r0.Env.left2.y, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c4_m5);
  c4_b_mxField = sf_mex_getfield(c4_m1, "right3", "Par", 0);
  c4_m6 = sf_mex_dup(c4_b_mxField);
  c4_g_mxField = sf_mex_getfield(c4_m6, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_g_mxField), &c4_r0.Env.right3.x, 1, 0,
                      0U, 0, 0U, 0);
  c4_g_mxField = sf_mex_getfield(c4_m6, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_g_mxField), &c4_r0.Env.right3.y, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c4_m6);
  c4_b_mxField = sf_mex_getfield(c4_m1, "mu", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_b_mxField), &c4_r0.Env.mu, 1, 0, 0U,
                      0, 0U, 0);
  sf_mex_destroy(&c4_m1);
  c4_mxField = sf_mex_getfield(c4_m0, "Veh", "Par", 0);
  c4_m7 = sf_mex_dup(c4_mxField);
  c4_h_mxField = sf_mex_getfield(c4_m7, "m", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_h_mxField), &c4_r0.Veh.m, 1, 0, 0U, 0,
                      0U, 0);
  c4_h_mxField = sf_mex_getfield(c4_m7, "Jz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_h_mxField), &c4_r0.Veh.Jz, 1, 0, 0U,
                      0, 0U, 0);
  c4_h_mxField = sf_mex_getfield(c4_m7, "m_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_h_mxField), &c4_r0.Veh.m_sprung, 1, 0,
                      0U, 0, 0U, 0);
  c4_h_mxField = sf_mex_getfield(c4_m7, "Jx_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_h_mxField), &c4_r0.Veh.Jx_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c4_h_mxField = sf_mex_getfield(c4_m7, "Jy_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_h_mxField), &c4_r0.Veh.Jy_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c4_h_mxField = sf_mex_getfield(c4_m7, "lf", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_h_mxField), &c4_r0.Veh.lf, 1, 0, 0U,
                      0, 0U, 0);
  c4_h_mxField = sf_mex_getfield(c4_m7, "lr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_h_mxField), &c4_r0.Veh.lr, 1, 0, 0U,
                      0, 0U, 0);
  c4_h_mxField = sf_mex_getfield(c4_m7, "L", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_h_mxField), &c4_r0.Veh.L, 1, 0, 0U, 0,
                      0U, 0);
  c4_h_mxField = sf_mex_getfield(c4_m7, "TrackWidth", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_h_mxField), &c4_r0.Veh.TrackWidth, 1,
                      0, 0U, 0, 0U, 0);
  c4_h_mxField = sf_mex_getfield(c4_m7, "h", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_h_mxField), &c4_r0.Veh.h, 1, 0, 0U, 0,
                      0U, 0);
  c4_h_mxField = sf_mex_getfield(c4_m7, "HalfRohACd", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_h_mxField), &c4_r0.Veh.HalfRohACd, 1,
                      0, 0U, 0, 0U, 0);
  c4_h_mxField = sf_mex_getfield(c4_m7, "F_z4_static", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_h_mxField), c4_r0.Veh.F_z4_static, 1,
                      0, 0U, 1, 0U, 2, 1, 4);
  c4_h_mxField = sf_mex_getfield(c4_m7, "Rw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_h_mxField), &c4_r0.Veh.Rw, 1, 0, 0U,
                      0, 0U, 0);
  c4_h_mxField = sf_mex_getfield(c4_m7, "r_long", "Par", 0);
  c4_m8 = sf_mex_dup(c4_h_mxField);
  c4_i_mxField = sf_mex_getfield(c4_m8, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_i_mxField), c4_r0.Veh.r_long.fl, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  c4_i_mxField = sf_mex_getfield(c4_m8, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_i_mxField), c4_r0.Veh.r_long.fr, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  c4_i_mxField = sf_mex_getfield(c4_m8, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_i_mxField), c4_r0.Veh.r_long.rl, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  c4_i_mxField = sf_mex_getfield(c4_m8, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_i_mxField), c4_r0.Veh.r_long.rr, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c4_m8);
  c4_h_mxField = sf_mex_getfield(c4_m7, "r_lat", "Par", 0);
  c4_m9 = sf_mex_dup(c4_h_mxField);
  c4_j_mxField = sf_mex_getfield(c4_m9, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_j_mxField), c4_r0.Veh.r_lat.fl, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  c4_j_mxField = sf_mex_getfield(c4_m9, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_j_mxField), c4_r0.Veh.r_lat.fr, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  c4_j_mxField = sf_mex_getfield(c4_m9, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_j_mxField), c4_r0.Veh.r_lat.rl, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  c4_j_mxField = sf_mex_getfield(c4_m9, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_j_mxField), c4_r0.Veh.r_lat.rr, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c4_m9);
  c4_h_mxField = sf_mex_getfield(c4_m7, "r_lever", "Par", 0);
  c4_m10 = sf_mex_dup(c4_h_mxField);
  c4_k_mxField = sf_mex_getfield(c4_m10, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_k_mxField), c4_r0.Veh.r_lever.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c4_k_mxField = sf_mex_getfield(c4_m10, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_k_mxField), c4_r0.Veh.r_lever.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c4_k_mxField = sf_mex_getfield(c4_m10, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_k_mxField), c4_r0.Veh.r_lever.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c4_k_mxField = sf_mex_getfield(c4_m10, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_k_mxField), c4_r0.Veh.r_lever.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c4_m10);
  c4_h_mxField = sf_mex_getfield(c4_m7, "r_pivot", "Par", 0);
  c4_m11 = sf_mex_dup(c4_h_mxField);
  c4_l_mxField = sf_mex_getfield(c4_m11, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_l_mxField), c4_r0.Veh.r_pivot.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c4_l_mxField = sf_mex_getfield(c4_m11, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_l_mxField), c4_r0.Veh.r_pivot.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c4_l_mxField = sf_mex_getfield(c4_m11, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_l_mxField), c4_r0.Veh.r_pivot.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c4_l_mxField = sf_mex_getfield(c4_m11, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_l_mxField), c4_r0.Veh.r_pivot.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c4_m11);
  c4_h_mxField = sf_mex_getfield(c4_m7, "cw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_h_mxField), &c4_r0.Veh.cw, 1, 0, 0U,
                      0, 0U, 0);
  c4_h_mxField = sf_mex_getfield(c4_m7, "carb_f", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_h_mxField), &c4_r0.Veh.carb_f, 1, 0,
                      0U, 0, 0U, 0);
  c4_h_mxField = sf_mex_getfield(c4_m7, "carb_r", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_h_mxField), &c4_r0.Veh.carb_r, 1, 0,
                      0U, 0, 0U, 0);
  c4_h_mxField = sf_mex_getfield(c4_m7, "dw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_h_mxField), &c4_r0.Veh.dw, 1, 0, 0U,
                      0, 0U, 0);
  c4_h_mxField = sf_mex_getfield(c4_m7, "Jw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_h_mxField), &c4_r0.Veh.Jw, 1, 0, 0U,
                      0, 0U, 0);
  c4_h_mxField = sf_mex_getfield(c4_m7, "C0", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_h_mxField), &c4_r0.Veh.C0, 1, 0, 0U,
                      0, 0U, 0);
  c4_h_mxField = sf_mex_getfield(c4_m7, "RelaxLength", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_h_mxField), &c4_r0.Veh.RelaxLength, 1,
                      0, 0U, 0, 0U, 0);
  c4_h_mxField = sf_mex_getfield(c4_m7, "RRC", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_h_mxField), &c4_r0.Veh.RRC, 1, 0, 0U,
                      0, 0U, 0);
  c4_h_mxField = sf_mex_getfield(c4_m7, "Pmax", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_h_mxField), &c4_r0.Veh.Pmax, 1, 0, 0U,
                      0, 0U, 0);
  c4_h_mxField = sf_mex_getfield(c4_m7, "PropDistrFrnt", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_h_mxField), &c4_r0.Veh.PropDistrFrnt,
                      1, 0, 0U, 0, 0U, 0);
  c4_h_mxField = sf_mex_getfield(c4_m7, "BrkDistrFrnt", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_h_mxField), &c4_r0.Veh.BrkDistrFrnt,
                      1, 0, 0U, 0, 0U, 0);
  c4_h_mxField = sf_mex_getfield(c4_m7, "SteRatio", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_h_mxField), &c4_r0.Veh.SteRatio, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c4_m7);
  c4_mxField = sf_mex_getfield(c4_m0, "Drvr", "Par", 0);
  c4_m12 = sf_mex_dup(c4_mxField);
  c4_m_mxField = sf_mex_getfield(c4_m12, "v_set", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_m_mxField), &c4_r0.Drvr.v_set, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c4_m12);
  c4_mxField = sf_mex_getfield(c4_m0, "Init", "Par", 0);
  c4_m13 = sf_mex_dup(c4_mxField);
  c4_n_mxField = sf_mex_getfield(c4_m13, "v_x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_n_mxField), &c4_r0.Init.v_x, 1, 0, 0U,
                      0, 0U, 0);
  c4_n_mxField = sf_mex_getfield(c4_m13, "F_fz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_n_mxField), &c4_r0.Init.F_fz, 1, 0,
                      0U, 0, 0U, 0);
  c4_n_mxField = sf_mex_getfield(c4_m13, "F_rz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c4_n_mxField), &c4_r0.Init.F_rz, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c4_m13);
  sf_mex_destroy(&c4_m0);
  chartInstance->c4_Par = c4_r0;
}

static void enable_c4_AllPurposeModel_TyreRelaxation
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c4_AllPurposeModel_TyreRelaxation
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c4_update_debugger_state_c4_AllPurposeModel_TyreRelaxation
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c4_AllPurposeModel_TyreRelaxation
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  const mxArray *c4_b_y = NULL;
  real_T c4_u;
  const mxArray *c4_c_y = NULL;
  real_T c4_b_u;
  const mxArray *c4_d_y = NULL;
  real_T c4_c_u;
  const mxArray *c4_e_y = NULL;
  real_T c4_d_u;
  const mxArray *c4_f_y = NULL;
  uint8_T c4_hoistedGlobal;
  uint8_T c4_e_u;
  const mxArray *c4_g_y = NULL;
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellmatrix(2, 1), false);
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c4_u = *(real_T *)&((char_T *)chartInstance->c4_F_xywSS4)[0];
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_b_y, c4_c_y, "fl", "fl", 0);
  c4_b_u = *(real_T *)&((char_T *)chartInstance->c4_F_xywSS4)[8];
  c4_d_y = NULL;
  sf_mex_assign(&c4_d_y, sf_mex_create("y", &c4_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_b_y, c4_d_y, "fr", "fr", 0);
  c4_c_u = *(real_T *)&((char_T *)chartInstance->c4_F_xywSS4)[16];
  c4_e_y = NULL;
  sf_mex_assign(&c4_e_y, sf_mex_create("y", &c4_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_b_y, c4_e_y, "rl", "rl", 0);
  c4_d_u = *(real_T *)&((char_T *)chartInstance->c4_F_xywSS4)[24];
  c4_f_y = NULL;
  sf_mex_assign(&c4_f_y, sf_mex_create("y", &c4_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_b_y, c4_f_y, "rr", "rr", 0);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_hoistedGlobal =
    chartInstance->c4_is_active_c4_AllPurposeModel_TyreRelaxation;
  c4_e_u = c4_hoistedGlobal;
  c4_g_y = NULL;
  sf_mex_assign(&c4_g_y, sf_mex_create("y", &c4_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 1, c4_g_y);
  sf_mex_assign(&c4_st, c4_y, false);
  return c4_st;
}

static void set_sim_state_c4_AllPurposeModel_TyreRelaxation
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c4_st)
{
  const mxArray *c4_u;
  c4_whl_vec4 c4_r1;
  chartInstance->c4_doneDoubleBufferReInit = true;
  c4_u = sf_mex_dup(c4_st);
  c4_r1 = c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 0)),
    "F_xywSS4");
  *(real_T *)&((char_T *)chartInstance->c4_F_xywSS4)[0] = c4_r1.fl;
  *(real_T *)&((char_T *)chartInstance->c4_F_xywSS4)[8] = c4_r1.fr;
  *(real_T *)&((char_T *)chartInstance->c4_F_xywSS4)[16] = c4_r1.rl;
  *(real_T *)&((char_T *)chartInstance->c4_F_xywSS4)[24] = c4_r1.rr;
  chartInstance->c4_is_active_c4_AllPurposeModel_TyreRelaxation =
    c4_n_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 1)),
    "is_active_c4_AllPurposeModel_TyreRelaxation");
  sf_mex_destroy(&c4_u);
  c4_update_debugger_state_c4_AllPurposeModel_TyreRelaxation(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_AllPurposeModel_TyreRelaxation
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c4_AllPurposeModel_TyreRelaxation
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  chartInstance->c4_sfEvent = CALL_EVENT;
  c4_chartstep_c4_AllPurposeModel_TyreRelaxation(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_AllPurposeModel_TyreRelaxationMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void mdl_start_c4_AllPurposeModel_TyreRelaxation
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c4_chartstep_c4_AllPurposeModel_TyreRelaxation
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  c4_whl_vec4 c4_b_s_xy4;
  c4_whl_vec4 c4_b_F_z4;
  c4_struct_iBlsPBO3AGnt69vDoTx5zD c4_b_Par;
  uint32_T c4_debug_family_var_map[9];
  real_T c4_C0;
  real_T c4_mu;
  real_T c4_Rw;
  real_T c4_nargin = 3.0;
  real_T c4_nargout = 1.0;
  c4_whl_vec4 c4_b_F_xywSS4;
  real_T c4_varargin_1;
  real_T c4_varargin_2;
  real_T c4_b_varargin_2;
  real_T c4_varargin_3;
  real_T c4_x;
  real_T c4_y;
  real_T c4_b_x;
  real_T c4_b_y;
  real_T c4_xk;
  real_T c4_yk;
  real_T c4_c_x;
  real_T c4_c_y;
  real_T c4_minval;
  real_T c4_b_varargin_1;
  real_T c4_c_varargin_2;
  real_T c4_d_x;
  real_T c4_e_x;
  real_T c4_b_xk;
  real_T c4_f_x;
  real_T c4_maxval;
  real_T c4_c_varargin_1;
  real_T c4_d_varargin_2;
  real_T c4_e_varargin_2;
  real_T c4_b_varargin_3;
  real_T c4_g_x;
  real_T c4_d_y;
  real_T c4_h_x;
  real_T c4_e_y;
  real_T c4_c_xk;
  real_T c4_b_yk;
  real_T c4_i_x;
  real_T c4_f_y;
  real_T c4_b_minval;
  real_T c4_d_varargin_1;
  real_T c4_f_varargin_2;
  real_T c4_j_x;
  real_T c4_k_x;
  real_T c4_d_xk;
  real_T c4_l_x;
  real_T c4_b_maxval;
  real_T c4_e_varargin_1;
  real_T c4_g_varargin_2;
  real_T c4_h_varargin_2;
  real_T c4_c_varargin_3;
  real_T c4_m_x;
  real_T c4_g_y;
  real_T c4_n_x;
  real_T c4_h_y;
  real_T c4_e_xk;
  real_T c4_c_yk;
  real_T c4_o_x;
  real_T c4_i_y;
  real_T c4_c_minval;
  real_T c4_f_varargin_1;
  real_T c4_i_varargin_2;
  real_T c4_p_x;
  real_T c4_q_x;
  real_T c4_f_xk;
  real_T c4_r_x;
  real_T c4_c_maxval;
  real_T c4_g_varargin_1;
  real_T c4_j_varargin_2;
  real_T c4_k_varargin_2;
  real_T c4_d_varargin_3;
  real_T c4_s_x;
  real_T c4_j_y;
  real_T c4_t_x;
  real_T c4_k_y;
  real_T c4_g_xk;
  real_T c4_d_yk;
  real_T c4_u_x;
  real_T c4_l_y;
  real_T c4_d_minval;
  real_T c4_h_varargin_1;
  real_T c4_l_varargin_2;
  real_T c4_v_x;
  real_T c4_w_x;
  real_T c4_h_xk;
  real_T c4_x_x;
  real_T c4_d_maxval;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  c4_b_s_xy4.fl = *(real_T *)&((char_T *)chartInstance->c4_s_xy4)[0];
  c4_b_s_xy4.fr = *(real_T *)&((char_T *)chartInstance->c4_s_xy4)[8];
  c4_b_s_xy4.rl = *(real_T *)&((char_T *)chartInstance->c4_s_xy4)[16];
  c4_b_s_xy4.rr = *(real_T *)&((char_T *)chartInstance->c4_s_xy4)[24];
  c4_b_F_z4.fl = *(real_T *)&((char_T *)chartInstance->c4_F_z4)[0];
  c4_b_F_z4.fr = *(real_T *)&((char_T *)chartInstance->c4_F_z4)[8];
  c4_b_F_z4.rl = *(real_T *)&((char_T *)chartInstance->c4_F_z4)[16];
  c4_b_F_z4.rr = *(real_T *)&((char_T *)chartInstance->c4_F_z4)[24];
  c4_b_Par = chartInstance->c4_Par;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_C0, 0U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_mu, 1U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_Rw, 2U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 3U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 4U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_b_s_xy4, 5U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_b_F_z4, 6U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_Par, 7U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_F_xywSS4, 8U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_C0 = c4_b_Par.Veh.C0;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 5);
  c4_mu = c4_b_Par.Env.mu;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 6);
  c4_Rw = c4_b_Par.Veh.Rw;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_varargin_1 = c4_C0 * c4_b_s_xy4.fl;
  c4_varargin_2 = c4_mu;
  c4_b_varargin_2 = c4_varargin_1;
  c4_varargin_3 = c4_varargin_2;
  c4_x = c4_b_varargin_2;
  c4_y = c4_varargin_3;
  c4_b_x = c4_x;
  c4_b_y = c4_y;
  c4_eml_scalar_eg(chartInstance);
  c4_xk = c4_b_x;
  c4_yk = c4_b_y;
  c4_c_x = c4_xk;
  c4_c_y = c4_yk;
  c4_eml_scalar_eg(chartInstance);
  c4_minval = muDoubleScalarMin(c4_c_x, c4_c_y);
  c4_b_varargin_1 = c4_b_F_z4.fl;
  c4_c_varargin_2 = c4_b_varargin_1;
  c4_d_x = c4_c_varargin_2;
  c4_e_x = c4_d_x;
  c4_eml_scalar_eg(chartInstance);
  c4_b_xk = c4_e_x;
  c4_f_x = c4_b_xk;
  c4_eml_scalar_eg(chartInstance);
  c4_maxval = muDoubleScalarMax(c4_f_x, 0.0);
  c4_b_F_xywSS4.fl = c4_minval * c4_maxval;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 9);
  c4_c_varargin_1 = c4_C0 * c4_b_s_xy4.fr;
  c4_d_varargin_2 = c4_mu;
  c4_e_varargin_2 = c4_c_varargin_1;
  c4_b_varargin_3 = c4_d_varargin_2;
  c4_g_x = c4_e_varargin_2;
  c4_d_y = c4_b_varargin_3;
  c4_h_x = c4_g_x;
  c4_e_y = c4_d_y;
  c4_eml_scalar_eg(chartInstance);
  c4_c_xk = c4_h_x;
  c4_b_yk = c4_e_y;
  c4_i_x = c4_c_xk;
  c4_f_y = c4_b_yk;
  c4_eml_scalar_eg(chartInstance);
  c4_b_minval = muDoubleScalarMin(c4_i_x, c4_f_y);
  c4_d_varargin_1 = c4_b_F_z4.fr;
  c4_f_varargin_2 = c4_d_varargin_1;
  c4_j_x = c4_f_varargin_2;
  c4_k_x = c4_j_x;
  c4_eml_scalar_eg(chartInstance);
  c4_d_xk = c4_k_x;
  c4_l_x = c4_d_xk;
  c4_eml_scalar_eg(chartInstance);
  c4_b_maxval = muDoubleScalarMax(c4_l_x, 0.0);
  c4_b_F_xywSS4.fr = c4_b_minval * c4_b_maxval;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 10);
  c4_e_varargin_1 = c4_C0 * c4_b_s_xy4.rl;
  c4_g_varargin_2 = c4_mu;
  c4_h_varargin_2 = c4_e_varargin_1;
  c4_c_varargin_3 = c4_g_varargin_2;
  c4_m_x = c4_h_varargin_2;
  c4_g_y = c4_c_varargin_3;
  c4_n_x = c4_m_x;
  c4_h_y = c4_g_y;
  c4_eml_scalar_eg(chartInstance);
  c4_e_xk = c4_n_x;
  c4_c_yk = c4_h_y;
  c4_o_x = c4_e_xk;
  c4_i_y = c4_c_yk;
  c4_eml_scalar_eg(chartInstance);
  c4_c_minval = muDoubleScalarMin(c4_o_x, c4_i_y);
  c4_f_varargin_1 = c4_b_F_z4.rl;
  c4_i_varargin_2 = c4_f_varargin_1;
  c4_p_x = c4_i_varargin_2;
  c4_q_x = c4_p_x;
  c4_eml_scalar_eg(chartInstance);
  c4_f_xk = c4_q_x;
  c4_r_x = c4_f_xk;
  c4_eml_scalar_eg(chartInstance);
  c4_c_maxval = muDoubleScalarMax(c4_r_x, 0.0);
  c4_b_F_xywSS4.rl = c4_c_minval * c4_c_maxval;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 11);
  c4_g_varargin_1 = c4_C0 * c4_b_s_xy4.rr;
  c4_j_varargin_2 = c4_mu;
  c4_k_varargin_2 = c4_g_varargin_1;
  c4_d_varargin_3 = c4_j_varargin_2;
  c4_s_x = c4_k_varargin_2;
  c4_j_y = c4_d_varargin_3;
  c4_t_x = c4_s_x;
  c4_k_y = c4_j_y;
  c4_eml_scalar_eg(chartInstance);
  c4_g_xk = c4_t_x;
  c4_d_yk = c4_k_y;
  c4_u_x = c4_g_xk;
  c4_l_y = c4_d_yk;
  c4_eml_scalar_eg(chartInstance);
  c4_d_minval = muDoubleScalarMin(c4_u_x, c4_l_y);
  c4_h_varargin_1 = c4_b_F_z4.rr;
  c4_l_varargin_2 = c4_h_varargin_1;
  c4_v_x = c4_l_varargin_2;
  c4_w_x = c4_v_x;
  c4_eml_scalar_eg(chartInstance);
  c4_h_xk = c4_w_x;
  c4_x_x = c4_h_xk;
  c4_eml_scalar_eg(chartInstance);
  c4_d_maxval = muDoubleScalarMax(c4_x_x, 0.0);
  c4_b_F_xywSS4.rr = c4_d_minval * c4_d_maxval;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
  *(real_T *)&((char_T *)chartInstance->c4_F_xywSS4)[0] = c4_b_F_xywSS4.fl;
  *(real_T *)&((char_T *)chartInstance->c4_F_xywSS4)[8] = c4_b_F_xywSS4.fr;
  *(real_T *)&((char_T *)chartInstance->c4_F_xywSS4)[16] = c4_b_F_xywSS4.rl;
  *(real_T *)&((char_T *)chartInstance->c4_F_xywSS4)[24] = c4_b_F_xywSS4.rr;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
}

static void initSimStructsc4_AllPurposeModel_TyreRelaxation
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber)
{
  (void)c4_machineNumber;
  (void)c4_chartNumber;
  (void)c4_instanceNumber;
}

static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  c4_whl_vec4 c4_u;
  const mxArray *c4_y = NULL;
  real_T c4_b_u;
  const mxArray *c4_b_y = NULL;
  real_T c4_c_u;
  const mxArray *c4_c_y = NULL;
  real_T c4_d_u;
  const mxArray *c4_d_y = NULL;
  real_T c4_e_u;
  const mxArray *c4_e_y = NULL;
  SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(c4_whl_vec4 *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c4_b_u = c4_u.fl;
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_y, c4_b_y, "fl", "fl", 0);
  c4_c_u = c4_u.fr;
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_y, c4_c_y, "fr", "fr", 0);
  c4_d_u = c4_u.rl;
  c4_d_y = NULL;
  sf_mex_assign(&c4_d_y, sf_mex_create("y", &c4_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_y, c4_d_y, "rl", "rl", 0);
  c4_e_u = c4_u.rr;
  c4_e_y = NULL;
  sf_mex_assign(&c4_e_y, sf_mex_create("y", &c4_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_y, c4_e_y, "rr", "rr", 0);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static c4_whl_vec4 c4_emlrt_marshallIn
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c4_b_F_xywSS4, const char_T *c4_identifier)
{
  c4_whl_vec4 c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_F_xywSS4),
    &c4_thisId);
  sf_mex_destroy(&c4_b_F_xywSS4);
  return c4_y;
}

static c4_whl_vec4 c4_b_emlrt_marshallIn
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  c4_whl_vec4 c4_y;
  emlrtMsgIdentifier c4_thisId;
  static const char * c4_fieldNames[4] = { "fl", "fr", "rl", "rr" };

  c4_thisId.fParent = c4_parentId;
  sf_mex_check_struct(c4_parentId, c4_u, 4, c4_fieldNames, 0U, NULL);
  c4_thisId.fIdentifier = "fl";
  c4_y.fl = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c4_u,
    "fl", "fl", 0)), &c4_thisId);
  c4_thisId.fIdentifier = "fr";
  c4_y.fr = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c4_u,
    "fr", "fr", 0)), &c4_thisId);
  c4_thisId.fIdentifier = "rl";
  c4_y.rl = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c4_u,
    "rl", "rl", 0)), &c4_thisId);
  c4_thisId.fIdentifier = "rr";
  c4_y.rr = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c4_u,
    "rr", "rr", 0)), &c4_thisId);
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static real_T c4_c_emlrt_marshallIn
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d0;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d0, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_F_xywSS4;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  c4_whl_vec4 c4_y;
  SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c4_b_F_xywSS4 = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_F_xywSS4),
    &c4_thisId);
  sf_mex_destroy(&c4_b_F_xywSS4);
  *(c4_whl_vec4 *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  c4_struct_iBlsPBO3AGnt69vDoTx5zD c4_u;
  const mxArray *c4_y = NULL;
  c4_struct_Nst2vGTExxHsg85EUOj9EH c4_b_u;
  const mxArray *c4_b_y = NULL;
  real_T c4_c_u;
  const mxArray *c4_c_y = NULL;
  c4_struct_HhckT6rntEraqECYVIDvCC c4_d_u;
  const mxArray *c4_d_y = NULL;
  real_T c4_e_u;
  const mxArray *c4_e_y = NULL;
  real_T c4_f_u;
  const mxArray *c4_f_y = NULL;
  const mxArray *c4_g_y = NULL;
  real_T c4_g_u;
  const mxArray *c4_h_y = NULL;
  real_T c4_h_u;
  const mxArray *c4_i_y = NULL;
  const mxArray *c4_j_y = NULL;
  real_T c4_i_u;
  const mxArray *c4_k_y = NULL;
  real_T c4_j_u;
  const mxArray *c4_l_y = NULL;
  const mxArray *c4_m_y = NULL;
  real_T c4_k_u;
  const mxArray *c4_n_y = NULL;
  real_T c4_l_u;
  const mxArray *c4_o_y = NULL;
  const mxArray *c4_p_y = NULL;
  real_T c4_m_u;
  const mxArray *c4_q_y = NULL;
  real_T c4_n_u;
  const mxArray *c4_r_y = NULL;
  real_T c4_o_u;
  const mxArray *c4_s_y = NULL;
  c4_struct_ZCmOWPuqBDw16FSOVVD00 c4_p_u;
  const mxArray *c4_t_y = NULL;
  real_T c4_q_u;
  const mxArray *c4_u_y = NULL;
  real_T c4_r_u;
  const mxArray *c4_v_y = NULL;
  real_T c4_s_u;
  const mxArray *c4_w_y = NULL;
  real_T c4_t_u;
  const mxArray *c4_x_y = NULL;
  real_T c4_u_u;
  const mxArray *c4_y_y = NULL;
  real_T c4_v_u;
  const mxArray *c4_ab_y = NULL;
  real_T c4_w_u;
  const mxArray *c4_bb_y = NULL;
  real_T c4_x_u;
  const mxArray *c4_cb_y = NULL;
  real_T c4_y_u;
  const mxArray *c4_db_y = NULL;
  real_T c4_ab_u;
  const mxArray *c4_eb_y = NULL;
  real_T c4_bb_u;
  const mxArray *c4_fb_y = NULL;
  int32_T c4_i0;
  real_T c4_cb_u[4];
  const mxArray *c4_gb_y = NULL;
  real_T c4_db_u;
  const mxArray *c4_hb_y = NULL;
  c4_struct_ZKAzdrl7umDGJoC14aoVKC c4_eb_u;
  const mxArray *c4_ib_y = NULL;
  int32_T c4_i1;
  real_T c4_fb_u[3];
  const mxArray *c4_jb_y = NULL;
  int32_T c4_i2;
  real_T c4_gb_u[3];
  const mxArray *c4_kb_y = NULL;
  int32_T c4_i3;
  real_T c4_hb_u[3];
  const mxArray *c4_lb_y = NULL;
  int32_T c4_i4;
  real_T c4_ib_u[3];
  const mxArray *c4_mb_y = NULL;
  const mxArray *c4_nb_y = NULL;
  int32_T c4_i5;
  real_T c4_jb_u[3];
  const mxArray *c4_ob_y = NULL;
  int32_T c4_i6;
  real_T c4_kb_u[3];
  const mxArray *c4_pb_y = NULL;
  int32_T c4_i7;
  real_T c4_lb_u[3];
  const mxArray *c4_qb_y = NULL;
  int32_T c4_i8;
  real_T c4_mb_u[3];
  const mxArray *c4_rb_y = NULL;
  const mxArray *c4_sb_y = NULL;
  int32_T c4_i9;
  real_T c4_nb_u[3];
  const mxArray *c4_tb_y = NULL;
  int32_T c4_i10;
  real_T c4_ob_u[3];
  const mxArray *c4_ub_y = NULL;
  int32_T c4_i11;
  real_T c4_pb_u[3];
  const mxArray *c4_vb_y = NULL;
  int32_T c4_i12;
  real_T c4_qb_u[3];
  const mxArray *c4_wb_y = NULL;
  const mxArray *c4_xb_y = NULL;
  int32_T c4_i13;
  real_T c4_rb_u[3];
  const mxArray *c4_yb_y = NULL;
  int32_T c4_i14;
  real_T c4_sb_u[3];
  const mxArray *c4_ac_y = NULL;
  int32_T c4_i15;
  real_T c4_tb_u[3];
  const mxArray *c4_bc_y = NULL;
  int32_T c4_i16;
  real_T c4_ub_u[3];
  const mxArray *c4_cc_y = NULL;
  real_T c4_vb_u;
  const mxArray *c4_dc_y = NULL;
  real_T c4_wb_u;
  const mxArray *c4_ec_y = NULL;
  real_T c4_xb_u;
  const mxArray *c4_fc_y = NULL;
  real_T c4_yb_u;
  const mxArray *c4_gc_y = NULL;
  real_T c4_ac_u;
  const mxArray *c4_hc_y = NULL;
  real_T c4_bc_u;
  const mxArray *c4_ic_y = NULL;
  real_T c4_cc_u;
  const mxArray *c4_jc_y = NULL;
  real_T c4_dc_u;
  const mxArray *c4_kc_y = NULL;
  real_T c4_ec_u;
  const mxArray *c4_lc_y = NULL;
  real_T c4_fc_u;
  const mxArray *c4_mc_y = NULL;
  real_T c4_gc_u;
  const mxArray *c4_nc_y = NULL;
  real_T c4_hc_u;
  const mxArray *c4_oc_y = NULL;
  c4_struct_r4FNviKwHfdhB8nQjvQv9 c4_ic_u;
  const mxArray *c4_pc_y = NULL;
  real_T c4_jc_u;
  const mxArray *c4_qc_y = NULL;
  c4_struct_Y9F1qlBi9AhssksPwemA4G c4_kc_u;
  const mxArray *c4_rc_y = NULL;
  real_T c4_lc_u;
  const mxArray *c4_sc_y = NULL;
  real_T c4_mc_u;
  const mxArray *c4_tc_y = NULL;
  real_T c4_nc_u;
  const mxArray *c4_uc_y = NULL;
  SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  c4_u = *(c4_struct_iBlsPBO3AGnt69vDoTx5zD *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c4_b_u = c4_u.Env;
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c4_c_u = c4_b_u.g;
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_b_y, c4_c_y, "g", "g", 0);
  c4_d_u = c4_b_u.left1;
  c4_d_y = NULL;
  sf_mex_assign(&c4_d_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c4_e_u = c4_d_u.x;
  c4_e_y = NULL;
  sf_mex_assign(&c4_e_y, sf_mex_create("y", &c4_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_d_y, c4_e_y, "x", "x", 0);
  c4_f_u = c4_d_u.y;
  c4_f_y = NULL;
  sf_mex_assign(&c4_f_y, sf_mex_create("y", &c4_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_d_y, c4_f_y, "y", "y", 0);
  sf_mex_addfield(c4_b_y, c4_d_y, "left1", "left1", 0);
  c4_d_u = c4_b_u.right1;
  c4_g_y = NULL;
  sf_mex_assign(&c4_g_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c4_g_u = c4_d_u.x;
  c4_h_y = NULL;
  sf_mex_assign(&c4_h_y, sf_mex_create("y", &c4_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_g_y, c4_h_y, "x", "x", 0);
  c4_h_u = c4_d_u.y;
  c4_i_y = NULL;
  sf_mex_assign(&c4_i_y, sf_mex_create("y", &c4_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_g_y, c4_i_y, "y", "y", 0);
  sf_mex_addfield(c4_b_y, c4_g_y, "right1", "right1", 0);
  c4_d_u = c4_b_u.right2;
  c4_j_y = NULL;
  sf_mex_assign(&c4_j_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c4_i_u = c4_d_u.x;
  c4_k_y = NULL;
  sf_mex_assign(&c4_k_y, sf_mex_create("y", &c4_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_j_y, c4_k_y, "x", "x", 0);
  c4_j_u = c4_d_u.y;
  c4_l_y = NULL;
  sf_mex_assign(&c4_l_y, sf_mex_create("y", &c4_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_j_y, c4_l_y, "y", "y", 0);
  sf_mex_addfield(c4_b_y, c4_j_y, "right2", "right2", 0);
  c4_d_u = c4_b_u.left2;
  c4_m_y = NULL;
  sf_mex_assign(&c4_m_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c4_k_u = c4_d_u.x;
  c4_n_y = NULL;
  sf_mex_assign(&c4_n_y, sf_mex_create("y", &c4_k_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_m_y, c4_n_y, "x", "x", 0);
  c4_l_u = c4_d_u.y;
  c4_o_y = NULL;
  sf_mex_assign(&c4_o_y, sf_mex_create("y", &c4_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_m_y, c4_o_y, "y", "y", 0);
  sf_mex_addfield(c4_b_y, c4_m_y, "left2", "left2", 0);
  c4_d_u = c4_b_u.right3;
  c4_p_y = NULL;
  sf_mex_assign(&c4_p_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c4_m_u = c4_d_u.x;
  c4_q_y = NULL;
  sf_mex_assign(&c4_q_y, sf_mex_create("y", &c4_m_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_p_y, c4_q_y, "x", "x", 0);
  c4_n_u = c4_d_u.y;
  c4_r_y = NULL;
  sf_mex_assign(&c4_r_y, sf_mex_create("y", &c4_n_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_p_y, c4_r_y, "y", "y", 0);
  sf_mex_addfield(c4_b_y, c4_p_y, "right3", "right3", 0);
  c4_o_u = c4_b_u.mu;
  c4_s_y = NULL;
  sf_mex_assign(&c4_s_y, sf_mex_create("y", &c4_o_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_b_y, c4_s_y, "mu", "mu", 0);
  sf_mex_addfield(c4_y, c4_b_y, "Env", "Env", 0);
  c4_p_u = c4_u.Veh;
  c4_t_y = NULL;
  sf_mex_assign(&c4_t_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c4_q_u = c4_p_u.m;
  c4_u_y = NULL;
  sf_mex_assign(&c4_u_y, sf_mex_create("y", &c4_q_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_t_y, c4_u_y, "m", "m", 0);
  c4_r_u = c4_p_u.Jz;
  c4_v_y = NULL;
  sf_mex_assign(&c4_v_y, sf_mex_create("y", &c4_r_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_t_y, c4_v_y, "Jz", "Jz", 0);
  c4_s_u = c4_p_u.m_sprung;
  c4_w_y = NULL;
  sf_mex_assign(&c4_w_y, sf_mex_create("y", &c4_s_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_t_y, c4_w_y, "m_sprung", "m_sprung", 0);
  c4_t_u = c4_p_u.Jx_sprung;
  c4_x_y = NULL;
  sf_mex_assign(&c4_x_y, sf_mex_create("y", &c4_t_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_t_y, c4_x_y, "Jx_sprung", "Jx_sprung", 0);
  c4_u_u = c4_p_u.Jy_sprung;
  c4_y_y = NULL;
  sf_mex_assign(&c4_y_y, sf_mex_create("y", &c4_u_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_t_y, c4_y_y, "Jy_sprung", "Jy_sprung", 0);
  c4_v_u = c4_p_u.lf;
  c4_ab_y = NULL;
  sf_mex_assign(&c4_ab_y, sf_mex_create("y", &c4_v_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_t_y, c4_ab_y, "lf", "lf", 0);
  c4_w_u = c4_p_u.lr;
  c4_bb_y = NULL;
  sf_mex_assign(&c4_bb_y, sf_mex_create("y", &c4_w_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_t_y, c4_bb_y, "lr", "lr", 0);
  c4_x_u = c4_p_u.L;
  c4_cb_y = NULL;
  sf_mex_assign(&c4_cb_y, sf_mex_create("y", &c4_x_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_t_y, c4_cb_y, "L", "L", 0);
  c4_y_u = c4_p_u.TrackWidth;
  c4_db_y = NULL;
  sf_mex_assign(&c4_db_y, sf_mex_create("y", &c4_y_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_t_y, c4_db_y, "TrackWidth", "TrackWidth", 0);
  c4_ab_u = c4_p_u.h;
  c4_eb_y = NULL;
  sf_mex_assign(&c4_eb_y, sf_mex_create("y", &c4_ab_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_t_y, c4_eb_y, "h", "h", 0);
  c4_bb_u = c4_p_u.HalfRohACd;
  c4_fb_y = NULL;
  sf_mex_assign(&c4_fb_y, sf_mex_create("y", &c4_bb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_t_y, c4_fb_y, "HalfRohACd", "HalfRohACd", 0);
  for (c4_i0 = 0; c4_i0 < 4; c4_i0++) {
    c4_cb_u[c4_i0] = c4_p_u.F_z4_static[c4_i0];
  }

  c4_gb_y = NULL;
  sf_mex_assign(&c4_gb_y, sf_mex_create("y", c4_cb_u, 0, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_addfield(c4_t_y, c4_gb_y, "F_z4_static", "F_z4_static", 0);
  c4_db_u = c4_p_u.Rw;
  c4_hb_y = NULL;
  sf_mex_assign(&c4_hb_y, sf_mex_create("y", &c4_db_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_t_y, c4_hb_y, "Rw", "Rw", 0);
  c4_eb_u = c4_p_u.r_long;
  c4_ib_y = NULL;
  sf_mex_assign(&c4_ib_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c4_i1 = 0; c4_i1 < 3; c4_i1++) {
    c4_fb_u[c4_i1] = c4_eb_u.fl[c4_i1];
  }

  c4_jb_y = NULL;
  sf_mex_assign(&c4_jb_y, sf_mex_create("y", c4_fb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c4_ib_y, c4_jb_y, "fl", "fl", 0);
  for (c4_i2 = 0; c4_i2 < 3; c4_i2++) {
    c4_gb_u[c4_i2] = c4_eb_u.fr[c4_i2];
  }

  c4_kb_y = NULL;
  sf_mex_assign(&c4_kb_y, sf_mex_create("y", c4_gb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c4_ib_y, c4_kb_y, "fr", "fr", 0);
  for (c4_i3 = 0; c4_i3 < 3; c4_i3++) {
    c4_hb_u[c4_i3] = c4_eb_u.rl[c4_i3];
  }

  c4_lb_y = NULL;
  sf_mex_assign(&c4_lb_y, sf_mex_create("y", c4_hb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c4_ib_y, c4_lb_y, "rl", "rl", 0);
  for (c4_i4 = 0; c4_i4 < 3; c4_i4++) {
    c4_ib_u[c4_i4] = c4_eb_u.rr[c4_i4];
  }

  c4_mb_y = NULL;
  sf_mex_assign(&c4_mb_y, sf_mex_create("y", c4_ib_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c4_ib_y, c4_mb_y, "rr", "rr", 0);
  sf_mex_addfield(c4_t_y, c4_ib_y, "r_long", "r_long", 0);
  c4_eb_u = c4_p_u.r_lat;
  c4_nb_y = NULL;
  sf_mex_assign(&c4_nb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c4_i5 = 0; c4_i5 < 3; c4_i5++) {
    c4_jb_u[c4_i5] = c4_eb_u.fl[c4_i5];
  }

  c4_ob_y = NULL;
  sf_mex_assign(&c4_ob_y, sf_mex_create("y", c4_jb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c4_nb_y, c4_ob_y, "fl", "fl", 0);
  for (c4_i6 = 0; c4_i6 < 3; c4_i6++) {
    c4_kb_u[c4_i6] = c4_eb_u.fr[c4_i6];
  }

  c4_pb_y = NULL;
  sf_mex_assign(&c4_pb_y, sf_mex_create("y", c4_kb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c4_nb_y, c4_pb_y, "fr", "fr", 0);
  for (c4_i7 = 0; c4_i7 < 3; c4_i7++) {
    c4_lb_u[c4_i7] = c4_eb_u.rl[c4_i7];
  }

  c4_qb_y = NULL;
  sf_mex_assign(&c4_qb_y, sf_mex_create("y", c4_lb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c4_nb_y, c4_qb_y, "rl", "rl", 0);
  for (c4_i8 = 0; c4_i8 < 3; c4_i8++) {
    c4_mb_u[c4_i8] = c4_eb_u.rr[c4_i8];
  }

  c4_rb_y = NULL;
  sf_mex_assign(&c4_rb_y, sf_mex_create("y", c4_mb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c4_nb_y, c4_rb_y, "rr", "rr", 0);
  sf_mex_addfield(c4_t_y, c4_nb_y, "r_lat", "r_lat", 0);
  c4_eb_u = c4_p_u.r_lever;
  c4_sb_y = NULL;
  sf_mex_assign(&c4_sb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c4_i9 = 0; c4_i9 < 3; c4_i9++) {
    c4_nb_u[c4_i9] = c4_eb_u.fl[c4_i9];
  }

  c4_tb_y = NULL;
  sf_mex_assign(&c4_tb_y, sf_mex_create("y", c4_nb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c4_sb_y, c4_tb_y, "fl", "fl", 0);
  for (c4_i10 = 0; c4_i10 < 3; c4_i10++) {
    c4_ob_u[c4_i10] = c4_eb_u.fr[c4_i10];
  }

  c4_ub_y = NULL;
  sf_mex_assign(&c4_ub_y, sf_mex_create("y", c4_ob_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c4_sb_y, c4_ub_y, "fr", "fr", 0);
  for (c4_i11 = 0; c4_i11 < 3; c4_i11++) {
    c4_pb_u[c4_i11] = c4_eb_u.rl[c4_i11];
  }

  c4_vb_y = NULL;
  sf_mex_assign(&c4_vb_y, sf_mex_create("y", c4_pb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c4_sb_y, c4_vb_y, "rl", "rl", 0);
  for (c4_i12 = 0; c4_i12 < 3; c4_i12++) {
    c4_qb_u[c4_i12] = c4_eb_u.rr[c4_i12];
  }

  c4_wb_y = NULL;
  sf_mex_assign(&c4_wb_y, sf_mex_create("y", c4_qb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c4_sb_y, c4_wb_y, "rr", "rr", 0);
  sf_mex_addfield(c4_t_y, c4_sb_y, "r_lever", "r_lever", 0);
  c4_eb_u = c4_p_u.r_pivot;
  c4_xb_y = NULL;
  sf_mex_assign(&c4_xb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c4_i13 = 0; c4_i13 < 3; c4_i13++) {
    c4_rb_u[c4_i13] = c4_eb_u.fl[c4_i13];
  }

  c4_yb_y = NULL;
  sf_mex_assign(&c4_yb_y, sf_mex_create("y", c4_rb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c4_xb_y, c4_yb_y, "fl", "fl", 0);
  for (c4_i14 = 0; c4_i14 < 3; c4_i14++) {
    c4_sb_u[c4_i14] = c4_eb_u.fr[c4_i14];
  }

  c4_ac_y = NULL;
  sf_mex_assign(&c4_ac_y, sf_mex_create("y", c4_sb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c4_xb_y, c4_ac_y, "fr", "fr", 0);
  for (c4_i15 = 0; c4_i15 < 3; c4_i15++) {
    c4_tb_u[c4_i15] = c4_eb_u.rl[c4_i15];
  }

  c4_bc_y = NULL;
  sf_mex_assign(&c4_bc_y, sf_mex_create("y", c4_tb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c4_xb_y, c4_bc_y, "rl", "rl", 0);
  for (c4_i16 = 0; c4_i16 < 3; c4_i16++) {
    c4_ub_u[c4_i16] = c4_eb_u.rr[c4_i16];
  }

  c4_cc_y = NULL;
  sf_mex_assign(&c4_cc_y, sf_mex_create("y", c4_ub_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c4_xb_y, c4_cc_y, "rr", "rr", 0);
  sf_mex_addfield(c4_t_y, c4_xb_y, "r_pivot", "r_pivot", 0);
  c4_vb_u = c4_p_u.cw;
  c4_dc_y = NULL;
  sf_mex_assign(&c4_dc_y, sf_mex_create("y", &c4_vb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_t_y, c4_dc_y, "cw", "cw", 0);
  c4_wb_u = c4_p_u.carb_f;
  c4_ec_y = NULL;
  sf_mex_assign(&c4_ec_y, sf_mex_create("y", &c4_wb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_t_y, c4_ec_y, "carb_f", "carb_f", 0);
  c4_xb_u = c4_p_u.carb_r;
  c4_fc_y = NULL;
  sf_mex_assign(&c4_fc_y, sf_mex_create("y", &c4_xb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_t_y, c4_fc_y, "carb_r", "carb_r", 0);
  c4_yb_u = c4_p_u.dw;
  c4_gc_y = NULL;
  sf_mex_assign(&c4_gc_y, sf_mex_create("y", &c4_yb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_t_y, c4_gc_y, "dw", "dw", 0);
  c4_ac_u = c4_p_u.Jw;
  c4_hc_y = NULL;
  sf_mex_assign(&c4_hc_y, sf_mex_create("y", &c4_ac_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_t_y, c4_hc_y, "Jw", "Jw", 0);
  c4_bc_u = c4_p_u.C0;
  c4_ic_y = NULL;
  sf_mex_assign(&c4_ic_y, sf_mex_create("y", &c4_bc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_t_y, c4_ic_y, "C0", "C0", 0);
  c4_cc_u = c4_p_u.RelaxLength;
  c4_jc_y = NULL;
  sf_mex_assign(&c4_jc_y, sf_mex_create("y", &c4_cc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_t_y, c4_jc_y, "RelaxLength", "RelaxLength", 0);
  c4_dc_u = c4_p_u.RRC;
  c4_kc_y = NULL;
  sf_mex_assign(&c4_kc_y, sf_mex_create("y", &c4_dc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_t_y, c4_kc_y, "RRC", "RRC", 0);
  c4_ec_u = c4_p_u.Pmax;
  c4_lc_y = NULL;
  sf_mex_assign(&c4_lc_y, sf_mex_create("y", &c4_ec_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_t_y, c4_lc_y, "Pmax", "Pmax", 0);
  c4_fc_u = c4_p_u.PropDistrFrnt;
  c4_mc_y = NULL;
  sf_mex_assign(&c4_mc_y, sf_mex_create("y", &c4_fc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_t_y, c4_mc_y, "PropDistrFrnt", "PropDistrFrnt", 0);
  c4_gc_u = c4_p_u.BrkDistrFrnt;
  c4_nc_y = NULL;
  sf_mex_assign(&c4_nc_y, sf_mex_create("y", &c4_gc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_t_y, c4_nc_y, "BrkDistrFrnt", "BrkDistrFrnt", 0);
  c4_hc_u = c4_p_u.SteRatio;
  c4_oc_y = NULL;
  sf_mex_assign(&c4_oc_y, sf_mex_create("y", &c4_hc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_t_y, c4_oc_y, "SteRatio", "SteRatio", 0);
  sf_mex_addfield(c4_y, c4_t_y, "Veh", "Veh", 0);
  c4_ic_u = c4_u.Drvr;
  c4_pc_y = NULL;
  sf_mex_assign(&c4_pc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c4_jc_u = c4_ic_u.v_set;
  c4_qc_y = NULL;
  sf_mex_assign(&c4_qc_y, sf_mex_create("y", &c4_jc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_pc_y, c4_qc_y, "v_set", "v_set", 0);
  sf_mex_addfield(c4_y, c4_pc_y, "Drvr", "Drvr", 0);
  c4_kc_u = c4_u.Init;
  c4_rc_y = NULL;
  sf_mex_assign(&c4_rc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c4_lc_u = c4_kc_u.v_x;
  c4_sc_y = NULL;
  sf_mex_assign(&c4_sc_y, sf_mex_create("y", &c4_lc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_rc_y, c4_sc_y, "v_x", "v_x", 0);
  c4_mc_u = c4_kc_u.F_fz;
  c4_tc_y = NULL;
  sf_mex_assign(&c4_tc_y, sf_mex_create("y", &c4_mc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_rc_y, c4_tc_y, "F_fz", "F_fz", 0);
  c4_nc_u = c4_kc_u.F_rz;
  c4_uc_y = NULL;
  sf_mex_assign(&c4_uc_y, sf_mex_create("y", &c4_nc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_rc_y, c4_uc_y, "F_rz", "F_rz", 0);
  sf_mex_addfield(c4_y, c4_rc_y, "Init", "Init", 0);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static void c4_d_emlrt_marshallIn
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
   c4_struct_iBlsPBO3AGnt69vDoTx5zD *c4_y)
{
  emlrtMsgIdentifier c4_thisId;
  static const char * c4_fieldNames[4] = { "Env", "Veh", "Drvr", "Init" };

  c4_thisId.fParent = c4_parentId;
  sf_mex_check_struct(c4_parentId, c4_u, 4, c4_fieldNames, 0U, NULL);
  c4_thisId.fIdentifier = "Env";
  c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c4_u, "Env",
    "Env", 0)), &c4_thisId, &c4_y->Env);
  c4_thisId.fIdentifier = "Veh";
  c4_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c4_u, "Veh",
    "Veh", 0)), &c4_thisId, &c4_y->Veh);
  c4_thisId.fIdentifier = "Drvr";
  c4_y->Drvr = c4_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c4_u, "Drvr", "Drvr", 0)), &c4_thisId);
  c4_thisId.fIdentifier = "Init";
  c4_y->Init = c4_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c4_u, "Init", "Init", 0)), &c4_thisId);
  sf_mex_destroy(&c4_u);
}

static void c4_e_emlrt_marshallIn
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
   c4_struct_Nst2vGTExxHsg85EUOj9EH *c4_y)
{
  emlrtMsgIdentifier c4_thisId;
  static const char * c4_fieldNames[7] = { "g", "left1", "right1", "right2",
    "left2", "right3", "mu" };

  c4_thisId.fParent = c4_parentId;
  sf_mex_check_struct(c4_parentId, c4_u, 7, c4_fieldNames, 0U, NULL);
  c4_thisId.fIdentifier = "g";
  c4_y->g = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c4_u,
    "g", "g", 0)), &c4_thisId);
  c4_thisId.fIdentifier = "left1";
  c4_y->left1 = c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c4_u, "left1", "left1", 0)), &c4_thisId);
  c4_thisId.fIdentifier = "right1";
  c4_y->right1 = c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c4_u, "right1", "right1", 0)),
    &c4_thisId);
  c4_thisId.fIdentifier = "right2";
  c4_y->right2 = c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c4_u, "right2", "right2", 0)),
    &c4_thisId);
  c4_thisId.fIdentifier = "left2";
  c4_y->left2 = c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c4_u, "left2", "left2", 0)), &c4_thisId);
  c4_thisId.fIdentifier = "right3";
  c4_y->right3 = c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c4_u, "right3", "right3", 0)),
    &c4_thisId);
  c4_thisId.fIdentifier = "mu";
  c4_y->mu = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c4_u, "mu", "mu", 0)), &c4_thisId);
  sf_mex_destroy(&c4_u);
}

static c4_struct_HhckT6rntEraqECYVIDvCC c4_f_emlrt_marshallIn
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  c4_struct_HhckT6rntEraqECYVIDvCC c4_y;
  emlrtMsgIdentifier c4_thisId;
  static const char * c4_fieldNames[2] = { "x", "y" };

  c4_thisId.fParent = c4_parentId;
  sf_mex_check_struct(c4_parentId, c4_u, 2, c4_fieldNames, 0U, NULL);
  c4_thisId.fIdentifier = "x";
  c4_y.x = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c4_u,
    "x", "x", 0)), &c4_thisId);
  c4_thisId.fIdentifier = "y";
  c4_y.y = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c4_u,
    "y", "y", 0)), &c4_thisId);
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_g_emlrt_marshallIn
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
   c4_struct_ZCmOWPuqBDw16FSOVVD00 *c4_y)
{
  emlrtMsgIdentifier c4_thisId;
  static const char * c4_fieldNames[29] = { "m", "Jz", "m_sprung", "Jx_sprung",
    "Jy_sprung", "lf", "lr", "L", "TrackWidth", "h", "HalfRohACd", "F_z4_static",
    "Rw", "r_long", "r_lat", "r_lever", "r_pivot", "cw", "carb_f", "carb_r",
    "dw", "Jw", "C0", "RelaxLength", "RRC", "Pmax", "PropDistrFrnt",
    "BrkDistrFrnt", "SteRatio" };

  c4_thisId.fParent = c4_parentId;
  sf_mex_check_struct(c4_parentId, c4_u, 29, c4_fieldNames, 0U, NULL);
  c4_thisId.fIdentifier = "m";
  c4_y->m = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c4_u,
    "m", "m", 0)), &c4_thisId);
  c4_thisId.fIdentifier = "Jz";
  c4_y->Jz = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c4_u, "Jz", "Jz", 0)), &c4_thisId);
  c4_thisId.fIdentifier = "m_sprung";
  c4_y->m_sprung = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c4_u, "m_sprung", "m_sprung", 0)), &c4_thisId);
  c4_thisId.fIdentifier = "Jx_sprung";
  c4_y->Jx_sprung = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c4_u, "Jx_sprung", "Jx_sprung", 0)), &c4_thisId);
  c4_thisId.fIdentifier = "Jy_sprung";
  c4_y->Jy_sprung = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c4_u, "Jy_sprung", "Jy_sprung", 0)), &c4_thisId);
  c4_thisId.fIdentifier = "lf";
  c4_y->lf = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c4_u, "lf", "lf", 0)), &c4_thisId);
  c4_thisId.fIdentifier = "lr";
  c4_y->lr = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c4_u, "lr", "lr", 0)), &c4_thisId);
  c4_thisId.fIdentifier = "L";
  c4_y->L = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c4_u,
    "L", "L", 0)), &c4_thisId);
  c4_thisId.fIdentifier = "TrackWidth";
  c4_y->TrackWidth = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c4_u, "TrackWidth", "TrackWidth", 0)), &c4_thisId);
  c4_thisId.fIdentifier = "h";
  c4_y->h = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c4_u,
    "h", "h", 0)), &c4_thisId);
  c4_thisId.fIdentifier = "HalfRohACd";
  c4_y->HalfRohACd = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c4_u, "HalfRohACd", "HalfRohACd", 0)), &c4_thisId);
  c4_thisId.fIdentifier = "F_z4_static";
  c4_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c4_u,
    "F_z4_static", "F_z4_static", 0)), &c4_thisId, c4_y->F_z4_static);
  c4_thisId.fIdentifier = "Rw";
  c4_y->Rw = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c4_u, "Rw", "Rw", 0)), &c4_thisId);
  c4_thisId.fIdentifier = "r_long";
  c4_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c4_u, "r_long",
    "r_long", 0)), &c4_thisId, &c4_y->r_long);
  c4_thisId.fIdentifier = "r_lat";
  c4_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c4_u, "r_lat",
    "r_lat", 0)), &c4_thisId, &c4_y->r_lat);
  c4_thisId.fIdentifier = "r_lever";
  c4_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c4_u,
    "r_lever", "r_lever", 0)), &c4_thisId, &c4_y->r_lever);
  c4_thisId.fIdentifier = "r_pivot";
  c4_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c4_u,
    "r_pivot", "r_pivot", 0)), &c4_thisId, &c4_y->r_pivot);
  c4_thisId.fIdentifier = "cw";
  c4_y->cw = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c4_u, "cw", "cw", 0)), &c4_thisId);
  c4_thisId.fIdentifier = "carb_f";
  c4_y->carb_f = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c4_u, "carb_f", "carb_f", 0)),
    &c4_thisId);
  c4_thisId.fIdentifier = "carb_r";
  c4_y->carb_r = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c4_u, "carb_r", "carb_r", 0)),
    &c4_thisId);
  c4_thisId.fIdentifier = "dw";
  c4_y->dw = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c4_u, "dw", "dw", 0)), &c4_thisId);
  c4_thisId.fIdentifier = "Jw";
  c4_y->Jw = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c4_u, "Jw", "Jw", 0)), &c4_thisId);
  c4_thisId.fIdentifier = "C0";
  c4_y->C0 = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c4_u, "C0", "C0", 0)), &c4_thisId);
  c4_thisId.fIdentifier = "RelaxLength";
  c4_y->RelaxLength = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c4_u, "RelaxLength", "RelaxLength", 0)), &c4_thisId);
  c4_thisId.fIdentifier = "RRC";
  c4_y->RRC = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c4_u, "RRC", "RRC", 0)), &c4_thisId);
  c4_thisId.fIdentifier = "Pmax";
  c4_y->Pmax = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c4_u, "Pmax", "Pmax", 0)), &c4_thisId);
  c4_thisId.fIdentifier = "PropDistrFrnt";
  c4_y->PropDistrFrnt = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c4_u, "PropDistrFrnt", "PropDistrFrnt", 0)), &c4_thisId);
  c4_thisId.fIdentifier = "BrkDistrFrnt";
  c4_y->BrkDistrFrnt = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c4_u, "BrkDistrFrnt", "BrkDistrFrnt", 0)), &c4_thisId);
  c4_thisId.fIdentifier = "SteRatio";
  c4_y->SteRatio = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c4_u, "SteRatio", "SteRatio", 0)), &c4_thisId);
  sf_mex_destroy(&c4_u);
}

static void c4_h_emlrt_marshallIn
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[4])
{
  real_T c4_dv0[4];
  int32_T c4_i17;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv0, 1, 0, 0U, 1, 0U, 2, 1, 4);
  for (c4_i17 = 0; c4_i17 < 4; c4_i17++) {
    c4_y[c4_i17] = c4_dv0[c4_i17];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_i_emlrt_marshallIn
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
   c4_struct_ZKAzdrl7umDGJoC14aoVKC *c4_y)
{
  emlrtMsgIdentifier c4_thisId;
  static const char * c4_fieldNames[4] = { "fl", "fr", "rl", "rr" };

  c4_thisId.fParent = c4_parentId;
  sf_mex_check_struct(c4_parentId, c4_u, 4, c4_fieldNames, 0U, NULL);
  c4_thisId.fIdentifier = "fl";
  c4_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c4_u, "fl",
    "fl", 0)), &c4_thisId, c4_y->fl);
  c4_thisId.fIdentifier = "fr";
  c4_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c4_u, "fr",
    "fr", 0)), &c4_thisId, c4_y->fr);
  c4_thisId.fIdentifier = "rl";
  c4_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c4_u, "rl",
    "rl", 0)), &c4_thisId, c4_y->rl);
  c4_thisId.fIdentifier = "rr";
  c4_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c4_u, "rr",
    "rr", 0)), &c4_thisId, c4_y->rr);
  sf_mex_destroy(&c4_u);
}

static void c4_j_emlrt_marshallIn
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[3])
{
  real_T c4_dv1[3];
  int32_T c4_i18;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv1, 1, 0, 0U, 1, 0U, 2, 3, 1);
  for (c4_i18 = 0; c4_i18 < 3; c4_i18++) {
    c4_y[c4_i18] = c4_dv1[c4_i18];
  }

  sf_mex_destroy(&c4_u);
}

static c4_struct_r4FNviKwHfdhB8nQjvQv9 c4_k_emlrt_marshallIn
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  c4_struct_r4FNviKwHfdhB8nQjvQv9 c4_y;
  emlrtMsgIdentifier c4_thisId;
  static const char * c4_fieldNames[1] = { "v_set" };

  c4_thisId.fParent = c4_parentId;
  sf_mex_check_struct(c4_parentId, c4_u, 1, c4_fieldNames, 0U, NULL);
  c4_thisId.fIdentifier = "v_set";
  c4_y.v_set = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c4_u, "v_set", "v_set", 0)), &c4_thisId);
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static c4_struct_Y9F1qlBi9AhssksPwemA4G c4_l_emlrt_marshallIn
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  c4_struct_Y9F1qlBi9AhssksPwemA4G c4_y;
  emlrtMsgIdentifier c4_thisId;
  static const char * c4_fieldNames[3] = { "v_x", "F_fz", "F_rz" };

  c4_thisId.fParent = c4_parentId;
  sf_mex_check_struct(c4_parentId, c4_u, 3, c4_fieldNames, 0U, NULL);
  c4_thisId.fIdentifier = "v_x";
  c4_y.v_x = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c4_u, "v_x", "v_x", 0)), &c4_thisId);
  c4_thisId.fIdentifier = "F_fz";
  c4_y.F_fz = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c4_u, "F_fz", "F_fz", 0)), &c4_thisId);
  c4_thisId.fIdentifier = "F_rz";
  c4_y.F_rz = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c4_u, "F_rz", "F_rz", 0)), &c4_thisId);
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_Par;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  c4_struct_iBlsPBO3AGnt69vDoTx5zD c4_y;
  SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c4_b_Par = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_Par), &c4_thisId, &c4_y);
  sf_mex_destroy(&c4_b_Par);
  *(c4_struct_iBlsPBO3AGnt69vDoTx5zD *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_nargout;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c4_nargout = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_nargout), &c4_thisId);
  sf_mex_destroy(&c4_nargout);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

const mxArray
  *sf_c4_AllPurposeModel_TyreRelaxation_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  sf_mex_assign(&c4_nameCaptureInfo, sf_mex_createstruct("structure", 2, 11, 1),
                false);
  c4_info_helper(&c4_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c4_nameCaptureInfo);
  return c4_nameCaptureInfo;
}

static void c4_info_helper(const mxArray **c4_info)
{
  const mxArray *c4_rhs0 = NULL;
  const mxArray *c4_lhs0 = NULL;
  const mxArray *c4_rhs1 = NULL;
  const mxArray *c4_lhs1 = NULL;
  const mxArray *c4_rhs2 = NULL;
  const mxArray *c4_lhs2 = NULL;
  const mxArray *c4_rhs3 = NULL;
  const mxArray *c4_lhs3 = NULL;
  const mxArray *c4_rhs4 = NULL;
  const mxArray *c4_lhs4 = NULL;
  const mxArray *c4_rhs5 = NULL;
  const mxArray *c4_lhs5 = NULL;
  const mxArray *c4_rhs6 = NULL;
  const mxArray *c4_lhs6 = NULL;
  const mxArray *c4_rhs7 = NULL;
  const mxArray *c4_lhs7 = NULL;
  const mxArray *c4_rhs8 = NULL;
  const mxArray *c4_lhs8 = NULL;
  const mxArray *c4_rhs9 = NULL;
  const mxArray *c4_lhs9 = NULL;
  const mxArray *c4_rhs10 = NULL;
  const mxArray *c4_lhs10 = NULL;
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("min"), "name", "name", 0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1311255318U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c4_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 1);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1378295984U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c4_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 2);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 2);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c4_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 3);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c4_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 4);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 4);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c4_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 5);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 5);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c4_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 6);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 6);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c4_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 7);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 7);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c4_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 8);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 8);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c4_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "context", "context", 9);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("max"), "name", "name", 9);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1311255316U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c4_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 10);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1378295984U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c4_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs10), "lhs", "lhs",
                  10);
  sf_mex_destroy(&c4_rhs0);
  sf_mex_destroy(&c4_lhs0);
  sf_mex_destroy(&c4_rhs1);
  sf_mex_destroy(&c4_lhs1);
  sf_mex_destroy(&c4_rhs2);
  sf_mex_destroy(&c4_lhs2);
  sf_mex_destroy(&c4_rhs3);
  sf_mex_destroy(&c4_lhs3);
  sf_mex_destroy(&c4_rhs4);
  sf_mex_destroy(&c4_lhs4);
  sf_mex_destroy(&c4_rhs5);
  sf_mex_destroy(&c4_lhs5);
  sf_mex_destroy(&c4_rhs6);
  sf_mex_destroy(&c4_lhs6);
  sf_mex_destroy(&c4_rhs7);
  sf_mex_destroy(&c4_lhs7);
  sf_mex_destroy(&c4_rhs8);
  sf_mex_destroy(&c4_lhs8);
  sf_mex_destroy(&c4_rhs9);
  sf_mex_destroy(&c4_lhs9);
  sf_mex_destroy(&c4_rhs10);
  sf_mex_destroy(&c4_lhs10);
}

static const mxArray *c4_emlrt_marshallOut(const char * c4_u)
{
  const mxArray *c4_y = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c4_u)), false);
  return c4_y;
}

static const mxArray *c4_b_emlrt_marshallOut(const uint32_T c4_u)
{
  const mxArray *c4_y = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 7, 0U, 0U, 0U, 0), false);
  return c4_y;
}

static void c4_eml_scalar_eg(SFc4_AllPurposeModel_TyreRelaxationInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static int32_T c4_m_emlrt_marshallIn
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_y;
  int32_T c4_i19;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i19, 1, 6, 0U, 0, 0U, 0);
  c4_y = c4_i19;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_sfEvent;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y;
  SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c4_b_sfEvent = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sfEvent),
    &c4_thisId);
  sf_mex_destroy(&c4_b_sfEvent);
  *(int32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_s_xy4_bus_io(void *chartInstanceVoid, void *c4_pData)
{
  const mxArray *c4_mxVal = NULL;
  c4_whl_vec4 c4_tmp;
  SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c4_mxVal = NULL;
  c4_tmp.fl = *(real_T *)&((char_T *)(c4_whl_vec4 *)c4_pData)[0];
  c4_tmp.fr = *(real_T *)&((char_T *)(c4_whl_vec4 *)c4_pData)[8];
  c4_tmp.rl = *(real_T *)&((char_T *)(c4_whl_vec4 *)c4_pData)[16];
  c4_tmp.rr = *(real_T *)&((char_T *)(c4_whl_vec4 *)c4_pData)[24];
  sf_mex_assign(&c4_mxVal, c4_sf_marshallOut(chartInstance, &c4_tmp), false);
  return c4_mxVal;
}

static uint8_T c4_n_emlrt_marshallIn
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c4_b_is_active_c4_AllPurposeModel_TyreRelaxation, const char_T
   *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_o_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_is_active_c4_AllPurposeModel_TyreRelaxation), &c4_thisId);
  sf_mex_destroy(&c4_b_is_active_c4_AllPurposeModel_TyreRelaxation);
  return c4_y;
}

static uint8_T c4_o_emlrt_marshallIn
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_y;
  uint8_T c4_u0;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u0, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_u0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void init_dsm_address_info
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address
  (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  chartInstance->c4_s_xy4 = (c4_whl_vec4 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c4_F_xywSS4 = (c4_whl_vec4 *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c4_F_z4 = (c4_whl_vec4 *)ssGetInputPortSignal_wrapper
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

void sf_c4_AllPurposeModel_TyreRelaxation_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2882008008U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2472374828U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3893527213U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2458161684U);
}

mxArray* sf_c4_AllPurposeModel_TyreRelaxation_get_post_codegen_info(void);
mxArray *sf_c4_AllPurposeModel_TyreRelaxation_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("Sivbt4GWkfQKGRdgCcx9IC");
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
    mxArray* mxPostCodegenInfo =
      sf_c4_AllPurposeModel_TyreRelaxation_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c4_AllPurposeModel_TyreRelaxation_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c4_AllPurposeModel_TyreRelaxation_jit_fallback_info(void)
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

mxArray *sf_c4_AllPurposeModel_TyreRelaxation_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c4_AllPurposeModel_TyreRelaxation_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c4_AllPurposeModel_TyreRelaxation
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[47],T\"F_xywSS4\",},{M[8],M[0],T\"is_active_c4_AllPurposeModel_TyreRelaxation\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_AllPurposeModel_TyreRelaxation_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _AllPurposeModel_TyreRelaxationMachineNumber_,
           4,
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
          (MexFcnForType)c4_s_xy4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_s_xy4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_s_xy4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c4_s_xy4);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c4_F_xywSS4);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c4_F_z4);
        _SFD_SET_DATA_VALUE_PTR(3U, &chartInstance->c4_Par);
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
  return "qIFokdUczmPxYta4ZCoGfE";
}

static void sf_opaque_initialize_c4_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc4_AllPurposeModel_TyreRelaxationInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c4_AllPurposeModel_TyreRelaxation
    ((SFc4_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
  initialize_c4_AllPurposeModel_TyreRelaxation
    ((SFc4_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c4_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  enable_c4_AllPurposeModel_TyreRelaxation
    ((SFc4_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c4_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  disable_c4_AllPurposeModel_TyreRelaxation
    ((SFc4_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c4_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  sf_gateway_c4_AllPurposeModel_TyreRelaxation
    ((SFc4_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c4_AllPurposeModel_TyreRelaxation
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c4_AllPurposeModel_TyreRelaxation
    ((SFc4_AllPurposeModel_TyreRelaxationInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c4_AllPurposeModel_TyreRelaxation(SimStruct*
  S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c4_AllPurposeModel_TyreRelaxation
    ((SFc4_AllPurposeModel_TyreRelaxationInstanceStruct*)
     chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c4_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_AllPurposeModel_TyreRelaxationInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_AllPurposeModel_TyreRelaxation_optimization_info();
    }

    finalize_c4_AllPurposeModel_TyreRelaxation
      ((SFc4_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc4_AllPurposeModel_TyreRelaxation
    ((SFc4_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_AllPurposeModel_TyreRelaxation(SimStruct *S)
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
    initialize_params_c4_AllPurposeModel_TyreRelaxation
      ((SFc4_AllPurposeModel_TyreRelaxationInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c4_AllPurposeModel_TyreRelaxation(SimStruct *S)
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
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,4,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,4,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,4);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,4,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,4,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3143520803U));
  ssSetChecksum1(S,(1286099038U));
  ssSetChecksum2(S,(1232644497U));
  ssSetChecksum3(S,(4106408357U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c4_AllPurposeModel_TyreRelaxation(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_AllPurposeModel_TyreRelaxation(SimStruct *S)
{
  SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct *)utMalloc
    (sizeof(SFc4_AllPurposeModel_TyreRelaxationInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc4_AllPurposeModel_TyreRelaxationInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c4_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c4_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c4_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c4_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c4_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c4_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c4_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c4_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c4_AllPurposeModel_TyreRelaxation;
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

void c4_AllPurposeModel_TyreRelaxation_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_AllPurposeModel_TyreRelaxation(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_AllPurposeModel_TyreRelaxation(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_AllPurposeModel_TyreRelaxation(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_AllPurposeModel_TyreRelaxation_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
