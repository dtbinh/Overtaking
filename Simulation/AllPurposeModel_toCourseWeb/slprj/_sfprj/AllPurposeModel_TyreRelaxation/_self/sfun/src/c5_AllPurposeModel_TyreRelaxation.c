/* Include files */

#include <stddef.h>
#include "blas.h"
#include "AllPurposeModel_TyreRelaxation_sfun.h"
#include "c5_AllPurposeModel_TyreRelaxation.h"
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
static const char * c5_debug_family_names[9] = { "nargin", "nargout", "T_s4",
  "F_sd4", "F_xv4", "F_yv4", "delta_w4", "Par", "F_z4" };

/* Function Declarations */
static void initialize_c5_AllPurposeModel_TyreRelaxation
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void initialize_params_c5_AllPurposeModel_TyreRelaxation
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void enable_c5_AllPurposeModel_TyreRelaxation
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void disable_c5_AllPurposeModel_TyreRelaxation
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void c5_update_debugger_state_c5_AllPurposeModel_TyreRelaxation
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c5_AllPurposeModel_TyreRelaxation
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void set_sim_state_c5_AllPurposeModel_TyreRelaxation
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c5_st);
static void finalize_c5_AllPurposeModel_TyreRelaxation
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void sf_gateway_c5_AllPurposeModel_TyreRelaxation
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void mdl_start_c5_AllPurposeModel_TyreRelaxation
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void initSimStructsc5_AllPurposeModel_TyreRelaxation
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber, uint32_T c5_instanceNumber);
static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData);
static c5_whl_vec4 c5_emlrt_marshallIn
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c5_b_F_z4, const char_T *c5_identifier);
static c5_whl_vec4 c5_b_emlrt_marshallIn
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static real_T c5_c_emlrt_marshallIn
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_d_emlrt_marshallIn
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
   c5_struct_iBlsPBO3AGnt69vDoTx5zD *c5_y);
static void c5_e_emlrt_marshallIn
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
   c5_struct_Nst2vGTExxHsg85EUOj9EH *c5_y);
static c5_struct_HhckT6rntEraqECYVIDvCC c5_f_emlrt_marshallIn
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_g_emlrt_marshallIn
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
   c5_struct_ZCmOWPuqBDw16FSOVVD00 *c5_y);
static void c5_h_emlrt_marshallIn
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_y[4]);
static void c5_i_emlrt_marshallIn
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
   c5_struct_ZKAzdrl7umDGJoC14aoVKC *c5_y);
static void c5_j_emlrt_marshallIn
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_y[3]);
static c5_struct_r4FNviKwHfdhB8nQjvQv9 c5_k_emlrt_marshallIn
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static c5_struct_Y9F1qlBi9AhssksPwemA4G c5_l_emlrt_marshallIn
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static void c5_info_helper(const mxArray **c5_info);
static const mxArray *c5_emlrt_marshallOut(const char * c5_u);
static const mxArray *c5_b_emlrt_marshallOut(const uint32_T c5_u);
static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static int32_T c5_m_emlrt_marshallIn
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_T_s4_bus_io(void *chartInstanceVoid, void *c5_pData);
static uint8_T c5_n_emlrt_marshallIn
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c5_b_is_active_c5_AllPurposeModel_TyreRelaxation, const char_T
   *c5_identifier);
static uint8_T c5_o_emlrt_marshallIn
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void init_dsm_address_info
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void init_simulink_io_address
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c5_AllPurposeModel_TyreRelaxation
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  chartInstance->c5_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c5_is_active_c5_AllPurposeModel_TyreRelaxation = 0U;
}

static void initialize_params_c5_AllPurposeModel_TyreRelaxation
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  const mxArray *c5_m0 = NULL;
  const mxArray *c5_mxField;
  const mxArray *c5_m1 = NULL;
  const mxArray *c5_b_mxField;
  c5_struct_iBlsPBO3AGnt69vDoTx5zD c5_r0;
  const mxArray *c5_m2 = NULL;
  const mxArray *c5_c_mxField;
  const mxArray *c5_m3 = NULL;
  const mxArray *c5_d_mxField;
  const mxArray *c5_m4 = NULL;
  const mxArray *c5_e_mxField;
  const mxArray *c5_m5 = NULL;
  const mxArray *c5_f_mxField;
  const mxArray *c5_m6 = NULL;
  const mxArray *c5_g_mxField;
  const mxArray *c5_m7 = NULL;
  const mxArray *c5_h_mxField;
  const mxArray *c5_m8 = NULL;
  const mxArray *c5_i_mxField;
  const mxArray *c5_m9 = NULL;
  const mxArray *c5_j_mxField;
  const mxArray *c5_m10 = NULL;
  const mxArray *c5_k_mxField;
  const mxArray *c5_m11 = NULL;
  const mxArray *c5_l_mxField;
  const mxArray *c5_m12 = NULL;
  const mxArray *c5_m_mxField;
  const mxArray *c5_m13 = NULL;
  const mxArray *c5_n_mxField;
  c5_m0 = sf_mex_get_sfun_param(chartInstance->S, 0, 1);
  c5_mxField = sf_mex_getfield(c5_m0, "Env", "Par", 0);
  c5_m1 = sf_mex_dup(c5_mxField);
  c5_b_mxField = sf_mex_getfield(c5_m1, "g", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_b_mxField), &c5_r0.Env.g, 1, 0, 0U, 0,
                      0U, 0);
  c5_b_mxField = sf_mex_getfield(c5_m1, "left1", "Par", 0);
  c5_m2 = sf_mex_dup(c5_b_mxField);
  c5_c_mxField = sf_mex_getfield(c5_m2, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_c_mxField), &c5_r0.Env.left1.x, 1, 0,
                      0U, 0, 0U, 0);
  c5_c_mxField = sf_mex_getfield(c5_m2, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_c_mxField), &c5_r0.Env.left1.y, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c5_m2);
  c5_b_mxField = sf_mex_getfield(c5_m1, "right1", "Par", 0);
  c5_m3 = sf_mex_dup(c5_b_mxField);
  c5_d_mxField = sf_mex_getfield(c5_m3, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_d_mxField), &c5_r0.Env.right1.x, 1, 0,
                      0U, 0, 0U, 0);
  c5_d_mxField = sf_mex_getfield(c5_m3, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_d_mxField), &c5_r0.Env.right1.y, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c5_m3);
  c5_b_mxField = sf_mex_getfield(c5_m1, "right2", "Par", 0);
  c5_m4 = sf_mex_dup(c5_b_mxField);
  c5_e_mxField = sf_mex_getfield(c5_m4, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_e_mxField), &c5_r0.Env.right2.x, 1, 0,
                      0U, 0, 0U, 0);
  c5_e_mxField = sf_mex_getfield(c5_m4, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_e_mxField), &c5_r0.Env.right2.y, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c5_m4);
  c5_b_mxField = sf_mex_getfield(c5_m1, "left2", "Par", 0);
  c5_m5 = sf_mex_dup(c5_b_mxField);
  c5_f_mxField = sf_mex_getfield(c5_m5, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_f_mxField), &c5_r0.Env.left2.x, 1, 0,
                      0U, 0, 0U, 0);
  c5_f_mxField = sf_mex_getfield(c5_m5, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_f_mxField), &c5_r0.Env.left2.y, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c5_m5);
  c5_b_mxField = sf_mex_getfield(c5_m1, "right3", "Par", 0);
  c5_m6 = sf_mex_dup(c5_b_mxField);
  c5_g_mxField = sf_mex_getfield(c5_m6, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_g_mxField), &c5_r0.Env.right3.x, 1, 0,
                      0U, 0, 0U, 0);
  c5_g_mxField = sf_mex_getfield(c5_m6, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_g_mxField), &c5_r0.Env.right3.y, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c5_m6);
  c5_b_mxField = sf_mex_getfield(c5_m1, "mu", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_b_mxField), &c5_r0.Env.mu, 1, 0, 0U,
                      0, 0U, 0);
  sf_mex_destroy(&c5_m1);
  c5_mxField = sf_mex_getfield(c5_m0, "Veh", "Par", 0);
  c5_m7 = sf_mex_dup(c5_mxField);
  c5_h_mxField = sf_mex_getfield(c5_m7, "m", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_h_mxField), &c5_r0.Veh.m, 1, 0, 0U, 0,
                      0U, 0);
  c5_h_mxField = sf_mex_getfield(c5_m7, "Jz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_h_mxField), &c5_r0.Veh.Jz, 1, 0, 0U,
                      0, 0U, 0);
  c5_h_mxField = sf_mex_getfield(c5_m7, "m_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_h_mxField), &c5_r0.Veh.m_sprung, 1, 0,
                      0U, 0, 0U, 0);
  c5_h_mxField = sf_mex_getfield(c5_m7, "Jx_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_h_mxField), &c5_r0.Veh.Jx_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c5_h_mxField = sf_mex_getfield(c5_m7, "Jy_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_h_mxField), &c5_r0.Veh.Jy_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c5_h_mxField = sf_mex_getfield(c5_m7, "lf", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_h_mxField), &c5_r0.Veh.lf, 1, 0, 0U,
                      0, 0U, 0);
  c5_h_mxField = sf_mex_getfield(c5_m7, "lr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_h_mxField), &c5_r0.Veh.lr, 1, 0, 0U,
                      0, 0U, 0);
  c5_h_mxField = sf_mex_getfield(c5_m7, "L", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_h_mxField), &c5_r0.Veh.L, 1, 0, 0U, 0,
                      0U, 0);
  c5_h_mxField = sf_mex_getfield(c5_m7, "TrackWidth", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_h_mxField), &c5_r0.Veh.TrackWidth, 1,
                      0, 0U, 0, 0U, 0);
  c5_h_mxField = sf_mex_getfield(c5_m7, "h", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_h_mxField), &c5_r0.Veh.h, 1, 0, 0U, 0,
                      0U, 0);
  c5_h_mxField = sf_mex_getfield(c5_m7, "HalfRohACd", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_h_mxField), &c5_r0.Veh.HalfRohACd, 1,
                      0, 0U, 0, 0U, 0);
  c5_h_mxField = sf_mex_getfield(c5_m7, "F_z4_static", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_h_mxField), c5_r0.Veh.F_z4_static, 1,
                      0, 0U, 1, 0U, 2, 1, 4);
  c5_h_mxField = sf_mex_getfield(c5_m7, "Rw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_h_mxField), &c5_r0.Veh.Rw, 1, 0, 0U,
                      0, 0U, 0);
  c5_h_mxField = sf_mex_getfield(c5_m7, "r_long", "Par", 0);
  c5_m8 = sf_mex_dup(c5_h_mxField);
  c5_i_mxField = sf_mex_getfield(c5_m8, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_i_mxField), c5_r0.Veh.r_long.fl, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  c5_i_mxField = sf_mex_getfield(c5_m8, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_i_mxField), c5_r0.Veh.r_long.fr, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  c5_i_mxField = sf_mex_getfield(c5_m8, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_i_mxField), c5_r0.Veh.r_long.rl, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  c5_i_mxField = sf_mex_getfield(c5_m8, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_i_mxField), c5_r0.Veh.r_long.rr, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c5_m8);
  c5_h_mxField = sf_mex_getfield(c5_m7, "r_lat", "Par", 0);
  c5_m9 = sf_mex_dup(c5_h_mxField);
  c5_j_mxField = sf_mex_getfield(c5_m9, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_j_mxField), c5_r0.Veh.r_lat.fl, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  c5_j_mxField = sf_mex_getfield(c5_m9, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_j_mxField), c5_r0.Veh.r_lat.fr, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  c5_j_mxField = sf_mex_getfield(c5_m9, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_j_mxField), c5_r0.Veh.r_lat.rl, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  c5_j_mxField = sf_mex_getfield(c5_m9, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_j_mxField), c5_r0.Veh.r_lat.rr, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c5_m9);
  c5_h_mxField = sf_mex_getfield(c5_m7, "r_lever", "Par", 0);
  c5_m10 = sf_mex_dup(c5_h_mxField);
  c5_k_mxField = sf_mex_getfield(c5_m10, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_k_mxField), c5_r0.Veh.r_lever.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c5_k_mxField = sf_mex_getfield(c5_m10, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_k_mxField), c5_r0.Veh.r_lever.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c5_k_mxField = sf_mex_getfield(c5_m10, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_k_mxField), c5_r0.Veh.r_lever.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c5_k_mxField = sf_mex_getfield(c5_m10, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_k_mxField), c5_r0.Veh.r_lever.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c5_m10);
  c5_h_mxField = sf_mex_getfield(c5_m7, "r_pivot", "Par", 0);
  c5_m11 = sf_mex_dup(c5_h_mxField);
  c5_l_mxField = sf_mex_getfield(c5_m11, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_l_mxField), c5_r0.Veh.r_pivot.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c5_l_mxField = sf_mex_getfield(c5_m11, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_l_mxField), c5_r0.Veh.r_pivot.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c5_l_mxField = sf_mex_getfield(c5_m11, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_l_mxField), c5_r0.Veh.r_pivot.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c5_l_mxField = sf_mex_getfield(c5_m11, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_l_mxField), c5_r0.Veh.r_pivot.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c5_m11);
  c5_h_mxField = sf_mex_getfield(c5_m7, "cw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_h_mxField), &c5_r0.Veh.cw, 1, 0, 0U,
                      0, 0U, 0);
  c5_h_mxField = sf_mex_getfield(c5_m7, "carb_f", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_h_mxField), &c5_r0.Veh.carb_f, 1, 0,
                      0U, 0, 0U, 0);
  c5_h_mxField = sf_mex_getfield(c5_m7, "carb_r", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_h_mxField), &c5_r0.Veh.carb_r, 1, 0,
                      0U, 0, 0U, 0);
  c5_h_mxField = sf_mex_getfield(c5_m7, "dw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_h_mxField), &c5_r0.Veh.dw, 1, 0, 0U,
                      0, 0U, 0);
  c5_h_mxField = sf_mex_getfield(c5_m7, "Jw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_h_mxField), &c5_r0.Veh.Jw, 1, 0, 0U,
                      0, 0U, 0);
  c5_h_mxField = sf_mex_getfield(c5_m7, "C0", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_h_mxField), &c5_r0.Veh.C0, 1, 0, 0U,
                      0, 0U, 0);
  c5_h_mxField = sf_mex_getfield(c5_m7, "RelaxLength", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_h_mxField), &c5_r0.Veh.RelaxLength, 1,
                      0, 0U, 0, 0U, 0);
  c5_h_mxField = sf_mex_getfield(c5_m7, "RRC", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_h_mxField), &c5_r0.Veh.RRC, 1, 0, 0U,
                      0, 0U, 0);
  c5_h_mxField = sf_mex_getfield(c5_m7, "Pmax", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_h_mxField), &c5_r0.Veh.Pmax, 1, 0, 0U,
                      0, 0U, 0);
  c5_h_mxField = sf_mex_getfield(c5_m7, "PropDistrFrnt", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_h_mxField), &c5_r0.Veh.PropDistrFrnt,
                      1, 0, 0U, 0, 0U, 0);
  c5_h_mxField = sf_mex_getfield(c5_m7, "BrkDistrFrnt", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_h_mxField), &c5_r0.Veh.BrkDistrFrnt,
                      1, 0, 0U, 0, 0U, 0);
  c5_h_mxField = sf_mex_getfield(c5_m7, "SteRatio", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_h_mxField), &c5_r0.Veh.SteRatio, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c5_m7);
  c5_mxField = sf_mex_getfield(c5_m0, "Drvr", "Par", 0);
  c5_m12 = sf_mex_dup(c5_mxField);
  c5_m_mxField = sf_mex_getfield(c5_m12, "v_set", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_m_mxField), &c5_r0.Drvr.v_set, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c5_m12);
  c5_mxField = sf_mex_getfield(c5_m0, "Init", "Par", 0);
  c5_m13 = sf_mex_dup(c5_mxField);
  c5_n_mxField = sf_mex_getfield(c5_m13, "v_x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_n_mxField), &c5_r0.Init.v_x, 1, 0, 0U,
                      0, 0U, 0);
  c5_n_mxField = sf_mex_getfield(c5_m13, "F_fz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_n_mxField), &c5_r0.Init.F_fz, 1, 0,
                      0U, 0, 0U, 0);
  c5_n_mxField = sf_mex_getfield(c5_m13, "F_rz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c5_n_mxField), &c5_r0.Init.F_rz, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c5_m13);
  sf_mex_destroy(&c5_m0);
  chartInstance->c5_Par = c5_r0;
}

static void enable_c5_AllPurposeModel_TyreRelaxation
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c5_AllPurposeModel_TyreRelaxation
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c5_update_debugger_state_c5_AllPurposeModel_TyreRelaxation
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c5_AllPurposeModel_TyreRelaxation
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  const mxArray *c5_st;
  const mxArray *c5_y = NULL;
  const mxArray *c5_b_y = NULL;
  real_T c5_u;
  const mxArray *c5_c_y = NULL;
  real_T c5_b_u;
  const mxArray *c5_d_y = NULL;
  real_T c5_c_u;
  const mxArray *c5_e_y = NULL;
  real_T c5_d_u;
  const mxArray *c5_f_y = NULL;
  uint8_T c5_hoistedGlobal;
  uint8_T c5_e_u;
  const mxArray *c5_g_y = NULL;
  c5_st = NULL;
  c5_st = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createcellmatrix(2, 1), false);
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c5_u = *(real_T *)&((char_T *)chartInstance->c5_F_z4)[0];
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_b_y, c5_c_y, "fl", "fl", 0);
  c5_b_u = *(real_T *)&((char_T *)chartInstance->c5_F_z4)[8];
  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_create("y", &c5_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_b_y, c5_d_y, "fr", "fr", 0);
  c5_c_u = *(real_T *)&((char_T *)chartInstance->c5_F_z4)[16];
  c5_e_y = NULL;
  sf_mex_assign(&c5_e_y, sf_mex_create("y", &c5_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_b_y, c5_e_y, "rl", "rl", 0);
  c5_d_u = *(real_T *)&((char_T *)chartInstance->c5_F_z4)[24];
  c5_f_y = NULL;
  sf_mex_assign(&c5_f_y, sf_mex_create("y", &c5_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_b_y, c5_f_y, "rr", "rr", 0);
  sf_mex_setcell(c5_y, 0, c5_b_y);
  c5_hoistedGlobal =
    chartInstance->c5_is_active_c5_AllPurposeModel_TyreRelaxation;
  c5_e_u = c5_hoistedGlobal;
  c5_g_y = NULL;
  sf_mex_assign(&c5_g_y, sf_mex_create("y", &c5_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_y, 1, c5_g_y);
  sf_mex_assign(&c5_st, c5_y, false);
  return c5_st;
}

static void set_sim_state_c5_AllPurposeModel_TyreRelaxation
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c5_st)
{
  const mxArray *c5_u;
  c5_whl_vec4 c5_r1;
  chartInstance->c5_doneDoubleBufferReInit = true;
  c5_u = sf_mex_dup(c5_st);
  c5_r1 = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 0)),
    "F_z4");
  *(real_T *)&((char_T *)chartInstance->c5_F_z4)[0] = c5_r1.fl;
  *(real_T *)&((char_T *)chartInstance->c5_F_z4)[8] = c5_r1.fr;
  *(real_T *)&((char_T *)chartInstance->c5_F_z4)[16] = c5_r1.rl;
  *(real_T *)&((char_T *)chartInstance->c5_F_z4)[24] = c5_r1.rr;
  chartInstance->c5_is_active_c5_AllPurposeModel_TyreRelaxation =
    c5_n_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 1)),
    "is_active_c5_AllPurposeModel_TyreRelaxation");
  sf_mex_destroy(&c5_u);
  c5_update_debugger_state_c5_AllPurposeModel_TyreRelaxation(chartInstance);
  sf_mex_destroy(&c5_st);
}

static void finalize_c5_AllPurposeModel_TyreRelaxation
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c5_AllPurposeModel_TyreRelaxation
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  c5_whl_vec4 c5_b_T_s4;
  c5_whl_vec4 c5_b_F_sd4;
  c5_whl_vec4 c5_b_F_xv4;
  c5_whl_vec4 c5_b_F_yv4;
  c5_whl_vec4 c5_b_delta_w4;
  c5_struct_iBlsPBO3AGnt69vDoTx5zD c5_b_Par;
  uint32_T c5_debug_family_var_map[9];
  real_T c5_nargin = 6.0;
  real_T c5_nargout = 1.0;
  c5_whl_vec4 c5_b_F_z4;
  real_T c5_x;
  real_T c5_b_x;
  real_T c5_c_x;
  real_T c5_d_x;
  real_T c5_A;
  real_T c5_B;
  real_T c5_e_x;
  real_T c5_y;
  real_T c5_f_x;
  real_T c5_b_y;
  real_T c5_g_x;
  real_T c5_c_y;
  real_T c5_d_y;
  real_T c5_h_x;
  real_T c5_i_x;
  real_T c5_j_x;
  real_T c5_k_x;
  real_T c5_b_A;
  real_T c5_b_B;
  real_T c5_l_x;
  real_T c5_e_y;
  real_T c5_m_x;
  real_T c5_f_y;
  real_T c5_n_x;
  real_T c5_g_y;
  real_T c5_h_y;
  real_T c5_o_x;
  real_T c5_p_x;
  real_T c5_q_x;
  real_T c5_r_x;
  real_T c5_c_A;
  real_T c5_c_B;
  real_T c5_s_x;
  real_T c5_i_y;
  real_T c5_t_x;
  real_T c5_j_y;
  real_T c5_u_x;
  real_T c5_k_y;
  real_T c5_l_y;
  real_T c5_v_x;
  real_T c5_w_x;
  real_T c5_x_x;
  real_T c5_y_x;
  real_T c5_d_A;
  real_T c5_d_B;
  real_T c5_ab_x;
  real_T c5_m_y;
  real_T c5_bb_x;
  real_T c5_n_y;
  real_T c5_cb_x;
  real_T c5_o_y;
  real_T c5_p_y;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  chartInstance->c5_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  c5_b_T_s4.fl = *(real_T *)&((char_T *)chartInstance->c5_T_s4)[0];
  c5_b_T_s4.fr = *(real_T *)&((char_T *)chartInstance->c5_T_s4)[8];
  c5_b_T_s4.rl = *(real_T *)&((char_T *)chartInstance->c5_T_s4)[16];
  c5_b_T_s4.rr = *(real_T *)&((char_T *)chartInstance->c5_T_s4)[24];
  c5_b_F_sd4.fl = *(real_T *)&((char_T *)chartInstance->c5_F_sd4)[0];
  c5_b_F_sd4.fr = *(real_T *)&((char_T *)chartInstance->c5_F_sd4)[8];
  c5_b_F_sd4.rl = *(real_T *)&((char_T *)chartInstance->c5_F_sd4)[16];
  c5_b_F_sd4.rr = *(real_T *)&((char_T *)chartInstance->c5_F_sd4)[24];
  c5_b_F_xv4.fl = *(real_T *)&((char_T *)chartInstance->c5_F_xv4)[0];
  c5_b_F_xv4.fr = *(real_T *)&((char_T *)chartInstance->c5_F_xv4)[8];
  c5_b_F_xv4.rl = *(real_T *)&((char_T *)chartInstance->c5_F_xv4)[16];
  c5_b_F_xv4.rr = *(real_T *)&((char_T *)chartInstance->c5_F_xv4)[24];
  c5_b_F_yv4.fl = *(real_T *)&((char_T *)chartInstance->c5_F_yv4)[0];
  c5_b_F_yv4.fr = *(real_T *)&((char_T *)chartInstance->c5_F_yv4)[8];
  c5_b_F_yv4.rl = *(real_T *)&((char_T *)chartInstance->c5_F_yv4)[16];
  c5_b_F_yv4.rr = *(real_T *)&((char_T *)chartInstance->c5_F_yv4)[24];
  c5_b_delta_w4.fl = *(real_T *)&((char_T *)chartInstance->c5_delta_w4)[0];
  c5_b_delta_w4.fr = *(real_T *)&((char_T *)chartInstance->c5_delta_w4)[8];
  c5_b_delta_w4.rl = *(real_T *)&((char_T *)chartInstance->c5_delta_w4)[16];
  c5_b_delta_w4.rr = *(real_T *)&((char_T *)chartInstance->c5_delta_w4)[24];
  c5_b_Par = chartInstance->c5_Par;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c5_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 0U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 1U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_b_T_s4, 2U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_b_F_sd4, 3U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_b_F_xv4, 4U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_b_F_yv4, 5U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_b_delta_w4, 6U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_Par, 7U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_F_z4, 8U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_x = c5_b_delta_w4.fl;
  c5_b_x = c5_x;
  c5_b_x = muDoubleScalarCos(c5_b_x);
  c5_c_x = c5_b_delta_w4.fl;
  c5_d_x = c5_c_x;
  c5_d_x = muDoubleScalarSin(c5_d_x);
  c5_A = (c5_b_T_s4.fl * (c5_b_x * c5_b_Par.Veh.r_lever.fl[1] -
           c5_b_Par.Veh.r_lever.fl[0] * c5_d_x) - c5_b_F_xv4.fl *
          (c5_b_Par.Veh.r_lever.fl[1] * c5_b_Par.Veh.r_pivot.fl[2] +
           c5_b_Par.Veh.r_lever.fl[2] * c5_b_Par.Veh.r_pivot.fl[1])) +
    c5_b_F_yv4.fl * (c5_b_Par.Veh.r_lever.fl[0] * c5_b_Par.Veh.r_pivot.fl[2] -
                     c5_b_Par.Veh.r_lever.fl[2] * c5_b_Par.Veh.r_pivot.fl[0]);
  c5_B = c5_b_Par.Veh.r_lever.fl[0] * c5_b_Par.Veh.r_pivot.fl[1] -
    c5_b_Par.Veh.r_lever.fl[1] * c5_b_Par.Veh.r_pivot.fl[0];
  c5_e_x = c5_A;
  c5_y = c5_B;
  c5_f_x = c5_e_x;
  c5_b_y = c5_y;
  c5_g_x = c5_f_x;
  c5_c_y = c5_b_y;
  c5_d_y = c5_g_x / c5_c_y;
  c5_b_F_z4.fl = c5_b_F_sd4.fl + c5_d_y;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 8);
  c5_h_x = c5_b_delta_w4.fr;
  c5_i_x = c5_h_x;
  c5_i_x = muDoubleScalarCos(c5_i_x);
  c5_j_x = c5_b_delta_w4.fr;
  c5_k_x = c5_j_x;
  c5_k_x = muDoubleScalarSin(c5_k_x);
  c5_b_A = (c5_b_T_s4.fr * (c5_i_x * c5_b_Par.Veh.r_lever.fr[1] -
             c5_b_Par.Veh.r_lever.fr[0] * c5_k_x) - c5_b_F_xv4.fr *
            (c5_b_Par.Veh.r_lever.fr[1] * c5_b_Par.Veh.r_pivot.fr[2] +
             c5_b_Par.Veh.r_lever.fr[2] * c5_b_Par.Veh.r_pivot.fr[1])) +
    c5_b_F_yv4.fr * (c5_b_Par.Veh.r_lever.fr[0] * c5_b_Par.Veh.r_pivot.fr[2] -
                     c5_b_Par.Veh.r_lever.fr[2] * c5_b_Par.Veh.r_pivot.fr[0]);
  c5_b_B = c5_b_Par.Veh.r_lever.fr[0] * c5_b_Par.Veh.r_pivot.fr[1] -
    c5_b_Par.Veh.r_lever.fr[1] * c5_b_Par.Veh.r_pivot.fr[0];
  c5_l_x = c5_b_A;
  c5_e_y = c5_b_B;
  c5_m_x = c5_l_x;
  c5_f_y = c5_e_y;
  c5_n_x = c5_m_x;
  c5_g_y = c5_f_y;
  c5_h_y = c5_n_x / c5_g_y;
  c5_b_F_z4.fr = c5_b_F_sd4.fr + c5_h_y;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 12);
  c5_o_x = c5_b_delta_w4.rl;
  c5_p_x = c5_o_x;
  c5_p_x = muDoubleScalarCos(c5_p_x);
  c5_q_x = c5_b_delta_w4.rl;
  c5_r_x = c5_q_x;
  c5_r_x = muDoubleScalarSin(c5_r_x);
  c5_c_A = (c5_b_T_s4.rl * (c5_p_x * c5_b_Par.Veh.r_lever.rl[1] -
             c5_b_Par.Veh.r_lever.rl[0] * c5_r_x) - c5_b_F_xv4.rl *
            (c5_b_Par.Veh.r_lever.rl[1] * c5_b_Par.Veh.r_pivot.rl[2] +
             c5_b_Par.Veh.r_lever.rl[2] * c5_b_Par.Veh.r_pivot.rl[1])) +
    c5_b_F_yv4.rl * (c5_b_Par.Veh.r_lever.rl[0] * c5_b_Par.Veh.r_pivot.rl[2] -
                     c5_b_Par.Veh.r_lever.rl[2] * c5_b_Par.Veh.r_pivot.rl[0]);
  c5_c_B = c5_b_Par.Veh.r_lever.rl[0] * c5_b_Par.Veh.r_pivot.rl[1] -
    c5_b_Par.Veh.r_lever.rl[1] * c5_b_Par.Veh.r_pivot.rl[0];
  c5_s_x = c5_c_A;
  c5_i_y = c5_c_B;
  c5_t_x = c5_s_x;
  c5_j_y = c5_i_y;
  c5_u_x = c5_t_x;
  c5_k_y = c5_j_y;
  c5_l_y = c5_u_x / c5_k_y;
  c5_b_F_z4.rl = c5_b_F_sd4.rl + c5_l_y;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 16);
  c5_v_x = c5_b_delta_w4.rr;
  c5_w_x = c5_v_x;
  c5_w_x = muDoubleScalarCos(c5_w_x);
  c5_x_x = c5_b_delta_w4.rr;
  c5_y_x = c5_x_x;
  c5_y_x = muDoubleScalarSin(c5_y_x);
  c5_d_A = (c5_b_T_s4.rr * (c5_w_x * c5_b_Par.Veh.r_lever.rr[1] -
             c5_b_Par.Veh.r_lever.rr[0] * c5_y_x) - c5_b_F_xv4.rr *
            (c5_b_Par.Veh.r_lever.rr[1] * c5_b_Par.Veh.r_pivot.rr[2] +
             c5_b_Par.Veh.r_lever.rr[2] * c5_b_Par.Veh.r_pivot.rr[1])) +
    c5_b_F_yv4.rr * (c5_b_Par.Veh.r_lever.rr[0] * c5_b_Par.Veh.r_pivot.rr[2] -
                     c5_b_Par.Veh.r_lever.rr[2] * c5_b_Par.Veh.r_pivot.rr[0]);
  c5_d_B = c5_b_Par.Veh.r_lever.rr[0] * c5_b_Par.Veh.r_pivot.rr[1] -
    c5_b_Par.Veh.r_lever.rr[1] * c5_b_Par.Veh.r_pivot.rr[0];
  c5_ab_x = c5_d_A;
  c5_m_y = c5_d_B;
  c5_bb_x = c5_ab_x;
  c5_n_y = c5_m_y;
  c5_cb_x = c5_bb_x;
  c5_o_y = c5_n_y;
  c5_p_y = c5_cb_x / c5_o_y;
  c5_b_F_z4.rr = c5_b_F_sd4.rr + c5_p_y;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -16);
  _SFD_SYMBOL_SCOPE_POP();
  *(real_T *)&((char_T *)chartInstance->c5_F_z4)[0] = c5_b_F_z4.fl;
  *(real_T *)&((char_T *)chartInstance->c5_F_z4)[8] = c5_b_F_z4.fr;
  *(real_T *)&((char_T *)chartInstance->c5_F_z4)[16] = c5_b_F_z4.rl;
  *(real_T *)&((char_T *)chartInstance->c5_F_z4)[24] = c5_b_F_z4.rr;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_AllPurposeModel_TyreRelaxationMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void mdl_start_c5_AllPurposeModel_TyreRelaxation
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc5_AllPurposeModel_TyreRelaxation
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber, uint32_T c5_instanceNumber)
{
  (void)c5_machineNumber;
  (void)c5_chartNumber;
  (void)c5_instanceNumber;
}

static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  c5_whl_vec4 c5_u;
  const mxArray *c5_y = NULL;
  real_T c5_b_u;
  const mxArray *c5_b_y = NULL;
  real_T c5_c_u;
  const mxArray *c5_c_y = NULL;
  real_T c5_d_u;
  const mxArray *c5_d_y = NULL;
  real_T c5_e_u;
  const mxArray *c5_e_y = NULL;
  SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(c5_whl_vec4 *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c5_b_u = c5_u.fl;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_y, c5_b_y, "fl", "fl", 0);
  c5_c_u = c5_u.fr;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_y, c5_c_y, "fr", "fr", 0);
  c5_d_u = c5_u.rl;
  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_create("y", &c5_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_y, c5_d_y, "rl", "rl", 0);
  c5_e_u = c5_u.rr;
  c5_e_y = NULL;
  sf_mex_assign(&c5_e_y, sf_mex_create("y", &c5_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_y, c5_e_y, "rr", "rr", 0);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static c5_whl_vec4 c5_emlrt_marshallIn
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c5_b_F_z4, const char_T *c5_identifier)
{
  c5_whl_vec4 c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_F_z4), &c5_thisId);
  sf_mex_destroy(&c5_b_F_z4);
  return c5_y;
}

static c5_whl_vec4 c5_b_emlrt_marshallIn
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  c5_whl_vec4 c5_y;
  emlrtMsgIdentifier c5_thisId;
  static const char * c5_fieldNames[4] = { "fl", "fr", "rl", "rr" };

  c5_thisId.fParent = c5_parentId;
  sf_mex_check_struct(c5_parentId, c5_u, 4, c5_fieldNames, 0U, NULL);
  c5_thisId.fIdentifier = "fl";
  c5_y.fl = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_u,
    "fl", "fl", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "fr";
  c5_y.fr = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_u,
    "fr", "fr", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "rl";
  c5_y.rl = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_u,
    "rl", "rl", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "rr";
  c5_y.rr = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_u,
    "rr", "rr", 0)), &c5_thisId);
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static real_T c5_c_emlrt_marshallIn
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  real_T c5_y;
  real_T c5_d0;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_d0, 1, 0, 0U, 0, 0U, 0);
  c5_y = c5_d0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_F_z4;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  c5_whl_vec4 c5_y;
  SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c5_b_F_z4 = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_F_z4), &c5_thisId);
  sf_mex_destroy(&c5_b_F_z4);
  *(c5_whl_vec4 *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData;
  c5_struct_iBlsPBO3AGnt69vDoTx5zD c5_u;
  const mxArray *c5_y = NULL;
  c5_struct_Nst2vGTExxHsg85EUOj9EH c5_b_u;
  const mxArray *c5_b_y = NULL;
  real_T c5_c_u;
  const mxArray *c5_c_y = NULL;
  c5_struct_HhckT6rntEraqECYVIDvCC c5_d_u;
  const mxArray *c5_d_y = NULL;
  real_T c5_e_u;
  const mxArray *c5_e_y = NULL;
  real_T c5_f_u;
  const mxArray *c5_f_y = NULL;
  const mxArray *c5_g_y = NULL;
  real_T c5_g_u;
  const mxArray *c5_h_y = NULL;
  real_T c5_h_u;
  const mxArray *c5_i_y = NULL;
  const mxArray *c5_j_y = NULL;
  real_T c5_i_u;
  const mxArray *c5_k_y = NULL;
  real_T c5_j_u;
  const mxArray *c5_l_y = NULL;
  const mxArray *c5_m_y = NULL;
  real_T c5_k_u;
  const mxArray *c5_n_y = NULL;
  real_T c5_l_u;
  const mxArray *c5_o_y = NULL;
  const mxArray *c5_p_y = NULL;
  real_T c5_m_u;
  const mxArray *c5_q_y = NULL;
  real_T c5_n_u;
  const mxArray *c5_r_y = NULL;
  real_T c5_o_u;
  const mxArray *c5_s_y = NULL;
  c5_struct_ZCmOWPuqBDw16FSOVVD00 c5_p_u;
  const mxArray *c5_t_y = NULL;
  real_T c5_q_u;
  const mxArray *c5_u_y = NULL;
  real_T c5_r_u;
  const mxArray *c5_v_y = NULL;
  real_T c5_s_u;
  const mxArray *c5_w_y = NULL;
  real_T c5_t_u;
  const mxArray *c5_x_y = NULL;
  real_T c5_u_u;
  const mxArray *c5_y_y = NULL;
  real_T c5_v_u;
  const mxArray *c5_ab_y = NULL;
  real_T c5_w_u;
  const mxArray *c5_bb_y = NULL;
  real_T c5_x_u;
  const mxArray *c5_cb_y = NULL;
  real_T c5_y_u;
  const mxArray *c5_db_y = NULL;
  real_T c5_ab_u;
  const mxArray *c5_eb_y = NULL;
  real_T c5_bb_u;
  const mxArray *c5_fb_y = NULL;
  int32_T c5_i0;
  real_T c5_cb_u[4];
  const mxArray *c5_gb_y = NULL;
  real_T c5_db_u;
  const mxArray *c5_hb_y = NULL;
  c5_struct_ZKAzdrl7umDGJoC14aoVKC c5_eb_u;
  const mxArray *c5_ib_y = NULL;
  int32_T c5_i1;
  real_T c5_fb_u[3];
  const mxArray *c5_jb_y = NULL;
  int32_T c5_i2;
  real_T c5_gb_u[3];
  const mxArray *c5_kb_y = NULL;
  int32_T c5_i3;
  real_T c5_hb_u[3];
  const mxArray *c5_lb_y = NULL;
  int32_T c5_i4;
  real_T c5_ib_u[3];
  const mxArray *c5_mb_y = NULL;
  const mxArray *c5_nb_y = NULL;
  int32_T c5_i5;
  real_T c5_jb_u[3];
  const mxArray *c5_ob_y = NULL;
  int32_T c5_i6;
  real_T c5_kb_u[3];
  const mxArray *c5_pb_y = NULL;
  int32_T c5_i7;
  real_T c5_lb_u[3];
  const mxArray *c5_qb_y = NULL;
  int32_T c5_i8;
  real_T c5_mb_u[3];
  const mxArray *c5_rb_y = NULL;
  const mxArray *c5_sb_y = NULL;
  int32_T c5_i9;
  real_T c5_nb_u[3];
  const mxArray *c5_tb_y = NULL;
  int32_T c5_i10;
  real_T c5_ob_u[3];
  const mxArray *c5_ub_y = NULL;
  int32_T c5_i11;
  real_T c5_pb_u[3];
  const mxArray *c5_vb_y = NULL;
  int32_T c5_i12;
  real_T c5_qb_u[3];
  const mxArray *c5_wb_y = NULL;
  const mxArray *c5_xb_y = NULL;
  int32_T c5_i13;
  real_T c5_rb_u[3];
  const mxArray *c5_yb_y = NULL;
  int32_T c5_i14;
  real_T c5_sb_u[3];
  const mxArray *c5_ac_y = NULL;
  int32_T c5_i15;
  real_T c5_tb_u[3];
  const mxArray *c5_bc_y = NULL;
  int32_T c5_i16;
  real_T c5_ub_u[3];
  const mxArray *c5_cc_y = NULL;
  real_T c5_vb_u;
  const mxArray *c5_dc_y = NULL;
  real_T c5_wb_u;
  const mxArray *c5_ec_y = NULL;
  real_T c5_xb_u;
  const mxArray *c5_fc_y = NULL;
  real_T c5_yb_u;
  const mxArray *c5_gc_y = NULL;
  real_T c5_ac_u;
  const mxArray *c5_hc_y = NULL;
  real_T c5_bc_u;
  const mxArray *c5_ic_y = NULL;
  real_T c5_cc_u;
  const mxArray *c5_jc_y = NULL;
  real_T c5_dc_u;
  const mxArray *c5_kc_y = NULL;
  real_T c5_ec_u;
  const mxArray *c5_lc_y = NULL;
  real_T c5_fc_u;
  const mxArray *c5_mc_y = NULL;
  real_T c5_gc_u;
  const mxArray *c5_nc_y = NULL;
  real_T c5_hc_u;
  const mxArray *c5_oc_y = NULL;
  c5_struct_r4FNviKwHfdhB8nQjvQv9 c5_ic_u;
  const mxArray *c5_pc_y = NULL;
  real_T c5_jc_u;
  const mxArray *c5_qc_y = NULL;
  c5_struct_Y9F1qlBi9AhssksPwemA4G c5_kc_u;
  const mxArray *c5_rc_y = NULL;
  real_T c5_lc_u;
  const mxArray *c5_sc_y = NULL;
  real_T c5_mc_u;
  const mxArray *c5_tc_y = NULL;
  real_T c5_nc_u;
  const mxArray *c5_uc_y = NULL;
  SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_mxArrayOutData = NULL;
  c5_u = *(c5_struct_iBlsPBO3AGnt69vDoTx5zD *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c5_b_u = c5_u.Env;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c5_c_u = c5_b_u.g;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_b_y, c5_c_y, "g", "g", 0);
  c5_d_u = c5_b_u.left1;
  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c5_e_u = c5_d_u.x;
  c5_e_y = NULL;
  sf_mex_assign(&c5_e_y, sf_mex_create("y", &c5_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_d_y, c5_e_y, "x", "x", 0);
  c5_f_u = c5_d_u.y;
  c5_f_y = NULL;
  sf_mex_assign(&c5_f_y, sf_mex_create("y", &c5_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_d_y, c5_f_y, "y", "y", 0);
  sf_mex_addfield(c5_b_y, c5_d_y, "left1", "left1", 0);
  c5_d_u = c5_b_u.right1;
  c5_g_y = NULL;
  sf_mex_assign(&c5_g_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c5_g_u = c5_d_u.x;
  c5_h_y = NULL;
  sf_mex_assign(&c5_h_y, sf_mex_create("y", &c5_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_g_y, c5_h_y, "x", "x", 0);
  c5_h_u = c5_d_u.y;
  c5_i_y = NULL;
  sf_mex_assign(&c5_i_y, sf_mex_create("y", &c5_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_g_y, c5_i_y, "y", "y", 0);
  sf_mex_addfield(c5_b_y, c5_g_y, "right1", "right1", 0);
  c5_d_u = c5_b_u.right2;
  c5_j_y = NULL;
  sf_mex_assign(&c5_j_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c5_i_u = c5_d_u.x;
  c5_k_y = NULL;
  sf_mex_assign(&c5_k_y, sf_mex_create("y", &c5_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_j_y, c5_k_y, "x", "x", 0);
  c5_j_u = c5_d_u.y;
  c5_l_y = NULL;
  sf_mex_assign(&c5_l_y, sf_mex_create("y", &c5_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_j_y, c5_l_y, "y", "y", 0);
  sf_mex_addfield(c5_b_y, c5_j_y, "right2", "right2", 0);
  c5_d_u = c5_b_u.left2;
  c5_m_y = NULL;
  sf_mex_assign(&c5_m_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c5_k_u = c5_d_u.x;
  c5_n_y = NULL;
  sf_mex_assign(&c5_n_y, sf_mex_create("y", &c5_k_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_m_y, c5_n_y, "x", "x", 0);
  c5_l_u = c5_d_u.y;
  c5_o_y = NULL;
  sf_mex_assign(&c5_o_y, sf_mex_create("y", &c5_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_m_y, c5_o_y, "y", "y", 0);
  sf_mex_addfield(c5_b_y, c5_m_y, "left2", "left2", 0);
  c5_d_u = c5_b_u.right3;
  c5_p_y = NULL;
  sf_mex_assign(&c5_p_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c5_m_u = c5_d_u.x;
  c5_q_y = NULL;
  sf_mex_assign(&c5_q_y, sf_mex_create("y", &c5_m_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_p_y, c5_q_y, "x", "x", 0);
  c5_n_u = c5_d_u.y;
  c5_r_y = NULL;
  sf_mex_assign(&c5_r_y, sf_mex_create("y", &c5_n_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_p_y, c5_r_y, "y", "y", 0);
  sf_mex_addfield(c5_b_y, c5_p_y, "right3", "right3", 0);
  c5_o_u = c5_b_u.mu;
  c5_s_y = NULL;
  sf_mex_assign(&c5_s_y, sf_mex_create("y", &c5_o_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_b_y, c5_s_y, "mu", "mu", 0);
  sf_mex_addfield(c5_y, c5_b_y, "Env", "Env", 0);
  c5_p_u = c5_u.Veh;
  c5_t_y = NULL;
  sf_mex_assign(&c5_t_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c5_q_u = c5_p_u.m;
  c5_u_y = NULL;
  sf_mex_assign(&c5_u_y, sf_mex_create("y", &c5_q_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_t_y, c5_u_y, "m", "m", 0);
  c5_r_u = c5_p_u.Jz;
  c5_v_y = NULL;
  sf_mex_assign(&c5_v_y, sf_mex_create("y", &c5_r_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_t_y, c5_v_y, "Jz", "Jz", 0);
  c5_s_u = c5_p_u.m_sprung;
  c5_w_y = NULL;
  sf_mex_assign(&c5_w_y, sf_mex_create("y", &c5_s_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_t_y, c5_w_y, "m_sprung", "m_sprung", 0);
  c5_t_u = c5_p_u.Jx_sprung;
  c5_x_y = NULL;
  sf_mex_assign(&c5_x_y, sf_mex_create("y", &c5_t_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_t_y, c5_x_y, "Jx_sprung", "Jx_sprung", 0);
  c5_u_u = c5_p_u.Jy_sprung;
  c5_y_y = NULL;
  sf_mex_assign(&c5_y_y, sf_mex_create("y", &c5_u_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_t_y, c5_y_y, "Jy_sprung", "Jy_sprung", 0);
  c5_v_u = c5_p_u.lf;
  c5_ab_y = NULL;
  sf_mex_assign(&c5_ab_y, sf_mex_create("y", &c5_v_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_t_y, c5_ab_y, "lf", "lf", 0);
  c5_w_u = c5_p_u.lr;
  c5_bb_y = NULL;
  sf_mex_assign(&c5_bb_y, sf_mex_create("y", &c5_w_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_t_y, c5_bb_y, "lr", "lr", 0);
  c5_x_u = c5_p_u.L;
  c5_cb_y = NULL;
  sf_mex_assign(&c5_cb_y, sf_mex_create("y", &c5_x_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_t_y, c5_cb_y, "L", "L", 0);
  c5_y_u = c5_p_u.TrackWidth;
  c5_db_y = NULL;
  sf_mex_assign(&c5_db_y, sf_mex_create("y", &c5_y_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_t_y, c5_db_y, "TrackWidth", "TrackWidth", 0);
  c5_ab_u = c5_p_u.h;
  c5_eb_y = NULL;
  sf_mex_assign(&c5_eb_y, sf_mex_create("y", &c5_ab_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_t_y, c5_eb_y, "h", "h", 0);
  c5_bb_u = c5_p_u.HalfRohACd;
  c5_fb_y = NULL;
  sf_mex_assign(&c5_fb_y, sf_mex_create("y", &c5_bb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_t_y, c5_fb_y, "HalfRohACd", "HalfRohACd", 0);
  for (c5_i0 = 0; c5_i0 < 4; c5_i0++) {
    c5_cb_u[c5_i0] = c5_p_u.F_z4_static[c5_i0];
  }

  c5_gb_y = NULL;
  sf_mex_assign(&c5_gb_y, sf_mex_create("y", c5_cb_u, 0, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_addfield(c5_t_y, c5_gb_y, "F_z4_static", "F_z4_static", 0);
  c5_db_u = c5_p_u.Rw;
  c5_hb_y = NULL;
  sf_mex_assign(&c5_hb_y, sf_mex_create("y", &c5_db_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_t_y, c5_hb_y, "Rw", "Rw", 0);
  c5_eb_u = c5_p_u.r_long;
  c5_ib_y = NULL;
  sf_mex_assign(&c5_ib_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c5_i1 = 0; c5_i1 < 3; c5_i1++) {
    c5_fb_u[c5_i1] = c5_eb_u.fl[c5_i1];
  }

  c5_jb_y = NULL;
  sf_mex_assign(&c5_jb_y, sf_mex_create("y", c5_fb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c5_ib_y, c5_jb_y, "fl", "fl", 0);
  for (c5_i2 = 0; c5_i2 < 3; c5_i2++) {
    c5_gb_u[c5_i2] = c5_eb_u.fr[c5_i2];
  }

  c5_kb_y = NULL;
  sf_mex_assign(&c5_kb_y, sf_mex_create("y", c5_gb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c5_ib_y, c5_kb_y, "fr", "fr", 0);
  for (c5_i3 = 0; c5_i3 < 3; c5_i3++) {
    c5_hb_u[c5_i3] = c5_eb_u.rl[c5_i3];
  }

  c5_lb_y = NULL;
  sf_mex_assign(&c5_lb_y, sf_mex_create("y", c5_hb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c5_ib_y, c5_lb_y, "rl", "rl", 0);
  for (c5_i4 = 0; c5_i4 < 3; c5_i4++) {
    c5_ib_u[c5_i4] = c5_eb_u.rr[c5_i4];
  }

  c5_mb_y = NULL;
  sf_mex_assign(&c5_mb_y, sf_mex_create("y", c5_ib_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c5_ib_y, c5_mb_y, "rr", "rr", 0);
  sf_mex_addfield(c5_t_y, c5_ib_y, "r_long", "r_long", 0);
  c5_eb_u = c5_p_u.r_lat;
  c5_nb_y = NULL;
  sf_mex_assign(&c5_nb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c5_i5 = 0; c5_i5 < 3; c5_i5++) {
    c5_jb_u[c5_i5] = c5_eb_u.fl[c5_i5];
  }

  c5_ob_y = NULL;
  sf_mex_assign(&c5_ob_y, sf_mex_create("y", c5_jb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c5_nb_y, c5_ob_y, "fl", "fl", 0);
  for (c5_i6 = 0; c5_i6 < 3; c5_i6++) {
    c5_kb_u[c5_i6] = c5_eb_u.fr[c5_i6];
  }

  c5_pb_y = NULL;
  sf_mex_assign(&c5_pb_y, sf_mex_create("y", c5_kb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c5_nb_y, c5_pb_y, "fr", "fr", 0);
  for (c5_i7 = 0; c5_i7 < 3; c5_i7++) {
    c5_lb_u[c5_i7] = c5_eb_u.rl[c5_i7];
  }

  c5_qb_y = NULL;
  sf_mex_assign(&c5_qb_y, sf_mex_create("y", c5_lb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c5_nb_y, c5_qb_y, "rl", "rl", 0);
  for (c5_i8 = 0; c5_i8 < 3; c5_i8++) {
    c5_mb_u[c5_i8] = c5_eb_u.rr[c5_i8];
  }

  c5_rb_y = NULL;
  sf_mex_assign(&c5_rb_y, sf_mex_create("y", c5_mb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c5_nb_y, c5_rb_y, "rr", "rr", 0);
  sf_mex_addfield(c5_t_y, c5_nb_y, "r_lat", "r_lat", 0);
  c5_eb_u = c5_p_u.r_lever;
  c5_sb_y = NULL;
  sf_mex_assign(&c5_sb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c5_i9 = 0; c5_i9 < 3; c5_i9++) {
    c5_nb_u[c5_i9] = c5_eb_u.fl[c5_i9];
  }

  c5_tb_y = NULL;
  sf_mex_assign(&c5_tb_y, sf_mex_create("y", c5_nb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c5_sb_y, c5_tb_y, "fl", "fl", 0);
  for (c5_i10 = 0; c5_i10 < 3; c5_i10++) {
    c5_ob_u[c5_i10] = c5_eb_u.fr[c5_i10];
  }

  c5_ub_y = NULL;
  sf_mex_assign(&c5_ub_y, sf_mex_create("y", c5_ob_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c5_sb_y, c5_ub_y, "fr", "fr", 0);
  for (c5_i11 = 0; c5_i11 < 3; c5_i11++) {
    c5_pb_u[c5_i11] = c5_eb_u.rl[c5_i11];
  }

  c5_vb_y = NULL;
  sf_mex_assign(&c5_vb_y, sf_mex_create("y", c5_pb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c5_sb_y, c5_vb_y, "rl", "rl", 0);
  for (c5_i12 = 0; c5_i12 < 3; c5_i12++) {
    c5_qb_u[c5_i12] = c5_eb_u.rr[c5_i12];
  }

  c5_wb_y = NULL;
  sf_mex_assign(&c5_wb_y, sf_mex_create("y", c5_qb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c5_sb_y, c5_wb_y, "rr", "rr", 0);
  sf_mex_addfield(c5_t_y, c5_sb_y, "r_lever", "r_lever", 0);
  c5_eb_u = c5_p_u.r_pivot;
  c5_xb_y = NULL;
  sf_mex_assign(&c5_xb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c5_i13 = 0; c5_i13 < 3; c5_i13++) {
    c5_rb_u[c5_i13] = c5_eb_u.fl[c5_i13];
  }

  c5_yb_y = NULL;
  sf_mex_assign(&c5_yb_y, sf_mex_create("y", c5_rb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c5_xb_y, c5_yb_y, "fl", "fl", 0);
  for (c5_i14 = 0; c5_i14 < 3; c5_i14++) {
    c5_sb_u[c5_i14] = c5_eb_u.fr[c5_i14];
  }

  c5_ac_y = NULL;
  sf_mex_assign(&c5_ac_y, sf_mex_create("y", c5_sb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c5_xb_y, c5_ac_y, "fr", "fr", 0);
  for (c5_i15 = 0; c5_i15 < 3; c5_i15++) {
    c5_tb_u[c5_i15] = c5_eb_u.rl[c5_i15];
  }

  c5_bc_y = NULL;
  sf_mex_assign(&c5_bc_y, sf_mex_create("y", c5_tb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c5_xb_y, c5_bc_y, "rl", "rl", 0);
  for (c5_i16 = 0; c5_i16 < 3; c5_i16++) {
    c5_ub_u[c5_i16] = c5_eb_u.rr[c5_i16];
  }

  c5_cc_y = NULL;
  sf_mex_assign(&c5_cc_y, sf_mex_create("y", c5_ub_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c5_xb_y, c5_cc_y, "rr", "rr", 0);
  sf_mex_addfield(c5_t_y, c5_xb_y, "r_pivot", "r_pivot", 0);
  c5_vb_u = c5_p_u.cw;
  c5_dc_y = NULL;
  sf_mex_assign(&c5_dc_y, sf_mex_create("y", &c5_vb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_t_y, c5_dc_y, "cw", "cw", 0);
  c5_wb_u = c5_p_u.carb_f;
  c5_ec_y = NULL;
  sf_mex_assign(&c5_ec_y, sf_mex_create("y", &c5_wb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_t_y, c5_ec_y, "carb_f", "carb_f", 0);
  c5_xb_u = c5_p_u.carb_r;
  c5_fc_y = NULL;
  sf_mex_assign(&c5_fc_y, sf_mex_create("y", &c5_xb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_t_y, c5_fc_y, "carb_r", "carb_r", 0);
  c5_yb_u = c5_p_u.dw;
  c5_gc_y = NULL;
  sf_mex_assign(&c5_gc_y, sf_mex_create("y", &c5_yb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_t_y, c5_gc_y, "dw", "dw", 0);
  c5_ac_u = c5_p_u.Jw;
  c5_hc_y = NULL;
  sf_mex_assign(&c5_hc_y, sf_mex_create("y", &c5_ac_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_t_y, c5_hc_y, "Jw", "Jw", 0);
  c5_bc_u = c5_p_u.C0;
  c5_ic_y = NULL;
  sf_mex_assign(&c5_ic_y, sf_mex_create("y", &c5_bc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_t_y, c5_ic_y, "C0", "C0", 0);
  c5_cc_u = c5_p_u.RelaxLength;
  c5_jc_y = NULL;
  sf_mex_assign(&c5_jc_y, sf_mex_create("y", &c5_cc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_t_y, c5_jc_y, "RelaxLength", "RelaxLength", 0);
  c5_dc_u = c5_p_u.RRC;
  c5_kc_y = NULL;
  sf_mex_assign(&c5_kc_y, sf_mex_create("y", &c5_dc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_t_y, c5_kc_y, "RRC", "RRC", 0);
  c5_ec_u = c5_p_u.Pmax;
  c5_lc_y = NULL;
  sf_mex_assign(&c5_lc_y, sf_mex_create("y", &c5_ec_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_t_y, c5_lc_y, "Pmax", "Pmax", 0);
  c5_fc_u = c5_p_u.PropDistrFrnt;
  c5_mc_y = NULL;
  sf_mex_assign(&c5_mc_y, sf_mex_create("y", &c5_fc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_t_y, c5_mc_y, "PropDistrFrnt", "PropDistrFrnt", 0);
  c5_gc_u = c5_p_u.BrkDistrFrnt;
  c5_nc_y = NULL;
  sf_mex_assign(&c5_nc_y, sf_mex_create("y", &c5_gc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_t_y, c5_nc_y, "BrkDistrFrnt", "BrkDistrFrnt", 0);
  c5_hc_u = c5_p_u.SteRatio;
  c5_oc_y = NULL;
  sf_mex_assign(&c5_oc_y, sf_mex_create("y", &c5_hc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_t_y, c5_oc_y, "SteRatio", "SteRatio", 0);
  sf_mex_addfield(c5_y, c5_t_y, "Veh", "Veh", 0);
  c5_ic_u = c5_u.Drvr;
  c5_pc_y = NULL;
  sf_mex_assign(&c5_pc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c5_jc_u = c5_ic_u.v_set;
  c5_qc_y = NULL;
  sf_mex_assign(&c5_qc_y, sf_mex_create("y", &c5_jc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_pc_y, c5_qc_y, "v_set", "v_set", 0);
  sf_mex_addfield(c5_y, c5_pc_y, "Drvr", "Drvr", 0);
  c5_kc_u = c5_u.Init;
  c5_rc_y = NULL;
  sf_mex_assign(&c5_rc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c5_lc_u = c5_kc_u.v_x;
  c5_sc_y = NULL;
  sf_mex_assign(&c5_sc_y, sf_mex_create("y", &c5_lc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_rc_y, c5_sc_y, "v_x", "v_x", 0);
  c5_mc_u = c5_kc_u.F_fz;
  c5_tc_y = NULL;
  sf_mex_assign(&c5_tc_y, sf_mex_create("y", &c5_mc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_rc_y, c5_tc_y, "F_fz", "F_fz", 0);
  c5_nc_u = c5_kc_u.F_rz;
  c5_uc_y = NULL;
  sf_mex_assign(&c5_uc_y, sf_mex_create("y", &c5_nc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_rc_y, c5_uc_y, "F_rz", "F_rz", 0);
  sf_mex_addfield(c5_y, c5_rc_y, "Init", "Init", 0);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static void c5_d_emlrt_marshallIn
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
   c5_struct_iBlsPBO3AGnt69vDoTx5zD *c5_y)
{
  emlrtMsgIdentifier c5_thisId;
  static const char * c5_fieldNames[4] = { "Env", "Veh", "Drvr", "Init" };

  c5_thisId.fParent = c5_parentId;
  sf_mex_check_struct(c5_parentId, c5_u, 4, c5_fieldNames, 0U, NULL);
  c5_thisId.fIdentifier = "Env";
  c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_u, "Env",
    "Env", 0)), &c5_thisId, &c5_y->Env);
  c5_thisId.fIdentifier = "Veh";
  c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_u, "Veh",
    "Veh", 0)), &c5_thisId, &c5_y->Veh);
  c5_thisId.fIdentifier = "Drvr";
  c5_y->Drvr = c5_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c5_u, "Drvr", "Drvr", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "Init";
  c5_y->Init = c5_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c5_u, "Init", "Init", 0)), &c5_thisId);
  sf_mex_destroy(&c5_u);
}

static void c5_e_emlrt_marshallIn
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
   c5_struct_Nst2vGTExxHsg85EUOj9EH *c5_y)
{
  emlrtMsgIdentifier c5_thisId;
  static const char * c5_fieldNames[7] = { "g", "left1", "right1", "right2",
    "left2", "right3", "mu" };

  c5_thisId.fParent = c5_parentId;
  sf_mex_check_struct(c5_parentId, c5_u, 7, c5_fieldNames, 0U, NULL);
  c5_thisId.fIdentifier = "g";
  c5_y->g = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_u,
    "g", "g", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "left1";
  c5_y->left1 = c5_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c5_u, "left1", "left1", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "right1";
  c5_y->right1 = c5_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c5_u, "right1", "right1", 0)),
    &c5_thisId);
  c5_thisId.fIdentifier = "right2";
  c5_y->right2 = c5_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c5_u, "right2", "right2", 0)),
    &c5_thisId);
  c5_thisId.fIdentifier = "left2";
  c5_y->left2 = c5_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c5_u, "left2", "left2", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "right3";
  c5_y->right3 = c5_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c5_u, "right3", "right3", 0)),
    &c5_thisId);
  c5_thisId.fIdentifier = "mu";
  c5_y->mu = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c5_u, "mu", "mu", 0)), &c5_thisId);
  sf_mex_destroy(&c5_u);
}

static c5_struct_HhckT6rntEraqECYVIDvCC c5_f_emlrt_marshallIn
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  c5_struct_HhckT6rntEraqECYVIDvCC c5_y;
  emlrtMsgIdentifier c5_thisId;
  static const char * c5_fieldNames[2] = { "x", "y" };

  c5_thisId.fParent = c5_parentId;
  sf_mex_check_struct(c5_parentId, c5_u, 2, c5_fieldNames, 0U, NULL);
  c5_thisId.fIdentifier = "x";
  c5_y.x = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_u,
    "x", "x", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "y";
  c5_y.y = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_u,
    "y", "y", 0)), &c5_thisId);
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_g_emlrt_marshallIn
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
   c5_struct_ZCmOWPuqBDw16FSOVVD00 *c5_y)
{
  emlrtMsgIdentifier c5_thisId;
  static const char * c5_fieldNames[29] = { "m", "Jz", "m_sprung", "Jx_sprung",
    "Jy_sprung", "lf", "lr", "L", "TrackWidth", "h", "HalfRohACd", "F_z4_static",
    "Rw", "r_long", "r_lat", "r_lever", "r_pivot", "cw", "carb_f", "carb_r",
    "dw", "Jw", "C0", "RelaxLength", "RRC", "Pmax", "PropDistrFrnt",
    "BrkDistrFrnt", "SteRatio" };

  c5_thisId.fParent = c5_parentId;
  sf_mex_check_struct(c5_parentId, c5_u, 29, c5_fieldNames, 0U, NULL);
  c5_thisId.fIdentifier = "m";
  c5_y->m = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_u,
    "m", "m", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "Jz";
  c5_y->Jz = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c5_u, "Jz", "Jz", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "m_sprung";
  c5_y->m_sprung = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_u, "m_sprung", "m_sprung", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "Jx_sprung";
  c5_y->Jx_sprung = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_u, "Jx_sprung", "Jx_sprung", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "Jy_sprung";
  c5_y->Jy_sprung = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_u, "Jy_sprung", "Jy_sprung", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "lf";
  c5_y->lf = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c5_u, "lf", "lf", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "lr";
  c5_y->lr = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c5_u, "lr", "lr", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "L";
  c5_y->L = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_u,
    "L", "L", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "TrackWidth";
  c5_y->TrackWidth = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_u, "TrackWidth", "TrackWidth", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "h";
  c5_y->h = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_u,
    "h", "h", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "HalfRohACd";
  c5_y->HalfRohACd = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_u, "HalfRohACd", "HalfRohACd", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "F_z4_static";
  c5_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_u,
    "F_z4_static", "F_z4_static", 0)), &c5_thisId, c5_y->F_z4_static);
  c5_thisId.fIdentifier = "Rw";
  c5_y->Rw = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c5_u, "Rw", "Rw", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "r_long";
  c5_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_u, "r_long",
    "r_long", 0)), &c5_thisId, &c5_y->r_long);
  c5_thisId.fIdentifier = "r_lat";
  c5_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_u, "r_lat",
    "r_lat", 0)), &c5_thisId, &c5_y->r_lat);
  c5_thisId.fIdentifier = "r_lever";
  c5_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_u,
    "r_lever", "r_lever", 0)), &c5_thisId, &c5_y->r_lever);
  c5_thisId.fIdentifier = "r_pivot";
  c5_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_u,
    "r_pivot", "r_pivot", 0)), &c5_thisId, &c5_y->r_pivot);
  c5_thisId.fIdentifier = "cw";
  c5_y->cw = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c5_u, "cw", "cw", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "carb_f";
  c5_y->carb_f = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c5_u, "carb_f", "carb_f", 0)),
    &c5_thisId);
  c5_thisId.fIdentifier = "carb_r";
  c5_y->carb_r = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c5_u, "carb_r", "carb_r", 0)),
    &c5_thisId);
  c5_thisId.fIdentifier = "dw";
  c5_y->dw = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c5_u, "dw", "dw", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "Jw";
  c5_y->Jw = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c5_u, "Jw", "Jw", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "C0";
  c5_y->C0 = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c5_u, "C0", "C0", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "RelaxLength";
  c5_y->RelaxLength = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_u, "RelaxLength", "RelaxLength", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "RRC";
  c5_y->RRC = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c5_u, "RRC", "RRC", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "Pmax";
  c5_y->Pmax = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c5_u, "Pmax", "Pmax", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "PropDistrFrnt";
  c5_y->PropDistrFrnt = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_u, "PropDistrFrnt", "PropDistrFrnt", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "BrkDistrFrnt";
  c5_y->BrkDistrFrnt = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_u, "BrkDistrFrnt", "BrkDistrFrnt", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "SteRatio";
  c5_y->SteRatio = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_u, "SteRatio", "SteRatio", 0)), &c5_thisId);
  sf_mex_destroy(&c5_u);
}

static void c5_h_emlrt_marshallIn
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_y[4])
{
  real_T c5_dv0[4];
  int32_T c5_i17;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv0, 1, 0, 0U, 1, 0U, 2, 1, 4);
  for (c5_i17 = 0; c5_i17 < 4; c5_i17++) {
    c5_y[c5_i17] = c5_dv0[c5_i17];
  }

  sf_mex_destroy(&c5_u);
}

static void c5_i_emlrt_marshallIn
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
   c5_struct_ZKAzdrl7umDGJoC14aoVKC *c5_y)
{
  emlrtMsgIdentifier c5_thisId;
  static const char * c5_fieldNames[4] = { "fl", "fr", "rl", "rr" };

  c5_thisId.fParent = c5_parentId;
  sf_mex_check_struct(c5_parentId, c5_u, 4, c5_fieldNames, 0U, NULL);
  c5_thisId.fIdentifier = "fl";
  c5_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_u, "fl",
    "fl", 0)), &c5_thisId, c5_y->fl);
  c5_thisId.fIdentifier = "fr";
  c5_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_u, "fr",
    "fr", 0)), &c5_thisId, c5_y->fr);
  c5_thisId.fIdentifier = "rl";
  c5_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_u, "rl",
    "rl", 0)), &c5_thisId, c5_y->rl);
  c5_thisId.fIdentifier = "rr";
  c5_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_u, "rr",
    "rr", 0)), &c5_thisId, c5_y->rr);
  sf_mex_destroy(&c5_u);
}

static void c5_j_emlrt_marshallIn
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_y[3])
{
  real_T c5_dv1[3];
  int32_T c5_i18;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv1, 1, 0, 0U, 1, 0U, 2, 3, 1);
  for (c5_i18 = 0; c5_i18 < 3; c5_i18++) {
    c5_y[c5_i18] = c5_dv1[c5_i18];
  }

  sf_mex_destroy(&c5_u);
}

static c5_struct_r4FNviKwHfdhB8nQjvQv9 c5_k_emlrt_marshallIn
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  c5_struct_r4FNviKwHfdhB8nQjvQv9 c5_y;
  emlrtMsgIdentifier c5_thisId;
  static const char * c5_fieldNames[1] = { "v_set" };

  c5_thisId.fParent = c5_parentId;
  sf_mex_check_struct(c5_parentId, c5_u, 1, c5_fieldNames, 0U, NULL);
  c5_thisId.fIdentifier = "v_set";
  c5_y.v_set = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c5_u, "v_set", "v_set", 0)), &c5_thisId);
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static c5_struct_Y9F1qlBi9AhssksPwemA4G c5_l_emlrt_marshallIn
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  c5_struct_Y9F1qlBi9AhssksPwemA4G c5_y;
  emlrtMsgIdentifier c5_thisId;
  static const char * c5_fieldNames[3] = { "v_x", "F_fz", "F_rz" };

  c5_thisId.fParent = c5_parentId;
  sf_mex_check_struct(c5_parentId, c5_u, 3, c5_fieldNames, 0U, NULL);
  c5_thisId.fIdentifier = "v_x";
  c5_y.v_x = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c5_u, "v_x", "v_x", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "F_fz";
  c5_y.F_fz = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c5_u, "F_fz", "F_fz", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "F_rz";
  c5_y.F_rz = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c5_u, "F_rz", "F_rz", 0)), &c5_thisId);
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_Par;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  c5_struct_iBlsPBO3AGnt69vDoTx5zD c5_y;
  SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c5_b_Par = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_Par), &c5_thisId, &c5_y);
  sf_mex_destroy(&c5_b_Par);
  *(c5_struct_iBlsPBO3AGnt69vDoTx5zD *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  real_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(real_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_nargout;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y;
  SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c5_nargout = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_nargout), &c5_thisId);
  sf_mex_destroy(&c5_nargout);
  *(real_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

const mxArray
  *sf_c5_AllPurposeModel_TyreRelaxation_get_eml_resolved_functions_info(void)
{
  const mxArray *c5_nameCaptureInfo = NULL;
  c5_nameCaptureInfo = NULL;
  sf_mex_assign(&c5_nameCaptureInfo, sf_mex_createstruct("structure", 2, 11, 1),
                false);
  c5_info_helper(&c5_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c5_nameCaptureInfo);
  return c5_nameCaptureInfo;
}

static void c5_info_helper(const mxArray **c5_info)
{
  const mxArray *c5_rhs0 = NULL;
  const mxArray *c5_lhs0 = NULL;
  const mxArray *c5_rhs1 = NULL;
  const mxArray *c5_lhs1 = NULL;
  const mxArray *c5_rhs2 = NULL;
  const mxArray *c5_lhs2 = NULL;
  const mxArray *c5_rhs3 = NULL;
  const mxArray *c5_lhs3 = NULL;
  const mxArray *c5_rhs4 = NULL;
  const mxArray *c5_lhs4 = NULL;
  const mxArray *c5_rhs5 = NULL;
  const mxArray *c5_lhs5 = NULL;
  const mxArray *c5_rhs6 = NULL;
  const mxArray *c5_lhs6 = NULL;
  const mxArray *c5_rhs7 = NULL;
  const mxArray *c5_lhs7 = NULL;
  const mxArray *c5_rhs8 = NULL;
  const mxArray *c5_lhs8 = NULL;
  const mxArray *c5_rhs9 = NULL;
  const mxArray *c5_lhs9 = NULL;
  const mxArray *c5_rhs10 = NULL;
  const mxArray *c5_lhs10 = NULL;
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("cos"), "name", "name", 0);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1395328496U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c5_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_scalar_cos"), "name",
                  "name", 1);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1286818722U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c5_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "context", "context", 2);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("sin"), "name", "name", 2);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1395328504U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c5_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_scalar_sin"), "name",
                  "name", 3);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1286818736U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c5_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "context", "context", 4);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("mrdivide"), "name", "name", 4);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 4);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410807648U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1370009886U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c5_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 5);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 5);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1389717774U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c5_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 6);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("rdivide"), "name", "name", 6);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363713880U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c5_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 7);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c5_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 8);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c5_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_div"), "name", "name", 9);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1386423952U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c5_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 10);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c5_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs10), "lhs", "lhs",
                  10);
  sf_mex_destroy(&c5_rhs0);
  sf_mex_destroy(&c5_lhs0);
  sf_mex_destroy(&c5_rhs1);
  sf_mex_destroy(&c5_lhs1);
  sf_mex_destroy(&c5_rhs2);
  sf_mex_destroy(&c5_lhs2);
  sf_mex_destroy(&c5_rhs3);
  sf_mex_destroy(&c5_lhs3);
  sf_mex_destroy(&c5_rhs4);
  sf_mex_destroy(&c5_lhs4);
  sf_mex_destroy(&c5_rhs5);
  sf_mex_destroy(&c5_lhs5);
  sf_mex_destroy(&c5_rhs6);
  sf_mex_destroy(&c5_lhs6);
  sf_mex_destroy(&c5_rhs7);
  sf_mex_destroy(&c5_lhs7);
  sf_mex_destroy(&c5_rhs8);
  sf_mex_destroy(&c5_lhs8);
  sf_mex_destroy(&c5_rhs9);
  sf_mex_destroy(&c5_lhs9);
  sf_mex_destroy(&c5_rhs10);
  sf_mex_destroy(&c5_lhs10);
}

static const mxArray *c5_emlrt_marshallOut(const char * c5_u)
{
  const mxArray *c5_y = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c5_u)), false);
  return c5_y;
}

static const mxArray *c5_b_emlrt_marshallOut(const uint32_T c5_u)
{
  const mxArray *c5_y = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 7, 0U, 0U, 0U, 0), false);
  return c5_y;
}

static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(int32_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static int32_T c5_m_emlrt_marshallIn
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  int32_T c5_y;
  int32_T c5_i19;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_i19, 1, 6, 0U, 0, 0U, 0);
  c5_y = c5_i19;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_sfEvent;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  int32_T c5_y;
  SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c5_b_sfEvent = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_sfEvent),
    &c5_thisId);
  sf_mex_destroy(&c5_b_sfEvent);
  *(int32_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_T_s4_bus_io(void *chartInstanceVoid, void *c5_pData)
{
  const mxArray *c5_mxVal = NULL;
  c5_whl_vec4 c5_tmp;
  SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c5_mxVal = NULL;
  c5_tmp.fl = *(real_T *)&((char_T *)(c5_whl_vec4 *)c5_pData)[0];
  c5_tmp.fr = *(real_T *)&((char_T *)(c5_whl_vec4 *)c5_pData)[8];
  c5_tmp.rl = *(real_T *)&((char_T *)(c5_whl_vec4 *)c5_pData)[16];
  c5_tmp.rr = *(real_T *)&((char_T *)(c5_whl_vec4 *)c5_pData)[24];
  sf_mex_assign(&c5_mxVal, c5_sf_marshallOut(chartInstance, &c5_tmp), false);
  return c5_mxVal;
}

static uint8_T c5_n_emlrt_marshallIn
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c5_b_is_active_c5_AllPurposeModel_TyreRelaxation, const char_T
   *c5_identifier)
{
  uint8_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_o_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c5_b_is_active_c5_AllPurposeModel_TyreRelaxation), &c5_thisId);
  sf_mex_destroy(&c5_b_is_active_c5_AllPurposeModel_TyreRelaxation);
  return c5_y;
}

static uint8_T c5_o_emlrt_marshallIn
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  uint8_T c5_y;
  uint8_T c5_u0;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_u0, 1, 3, 0U, 0, 0U, 0);
  c5_y = c5_u0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void init_dsm_address_info
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address
  (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  chartInstance->c5_T_s4 = (c5_whl_vec4 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c5_F_sd4 = (c5_whl_vec4 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c5_F_z4 = (c5_whl_vec4 *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c5_F_xv4 = (c5_whl_vec4 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c5_F_yv4 = (c5_whl_vec4 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c5_delta_w4 = (c5_whl_vec4 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
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

void sf_c5_AllPurposeModel_TyreRelaxation_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2460042463U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2586855256U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2858596457U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2985776748U);
}

mxArray* sf_c5_AllPurposeModel_TyreRelaxation_get_post_codegen_info(void);
mxArray *sf_c5_AllPurposeModel_TyreRelaxation_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("37Gz2xXIHV5Urgd3DQEHjE");
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
      sf_c5_AllPurposeModel_TyreRelaxation_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c5_AllPurposeModel_TyreRelaxation_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c5_AllPurposeModel_TyreRelaxation_jit_fallback_info(void)
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

mxArray *sf_c5_AllPurposeModel_TyreRelaxation_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c5_AllPurposeModel_TyreRelaxation_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c5_AllPurposeModel_TyreRelaxation
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[7],T\"F_z4\",},{M[8],M[0],T\"is_active_c5_AllPurposeModel_TyreRelaxation\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_AllPurposeModel_TyreRelaxation_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _AllPurposeModel_TyreRelaxationMachineNumber_,
           5,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"T_s4");
          _SFD_SET_DATA_PROPS(1,1,1,0,"F_sd4");
          _SFD_SET_DATA_PROPS(2,2,0,1,"F_z4");
          _SFD_SET_DATA_PROPS(3,1,1,0,"F_xv4");
          _SFD_SET_DATA_PROPS(4,1,1,0,"F_yv4");
          _SFD_SET_DATA_PROPS(5,1,1,0,"delta_w4");
          _SFD_SET_DATA_PROPS(6,10,0,0,"Par");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,2192);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_T_s4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_T_s4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_T_s4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_T_s4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_T_s4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_T_s4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)c5_b_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c5_T_s4);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c5_F_sd4);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c5_F_z4);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c5_F_xv4);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c5_F_yv4);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c5_delta_w4);
        _SFD_SET_DATA_VALUE_PTR(6U, &chartInstance->c5_Par);
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
  return "NrdeWHcB9FrTELONGTIl0E";
}

static void sf_opaque_initialize_c5_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc5_AllPurposeModel_TyreRelaxationInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c5_AllPurposeModel_TyreRelaxation
    ((SFc5_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
  initialize_c5_AllPurposeModel_TyreRelaxation
    ((SFc5_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c5_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  enable_c5_AllPurposeModel_TyreRelaxation
    ((SFc5_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c5_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  disable_c5_AllPurposeModel_TyreRelaxation
    ((SFc5_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c5_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  sf_gateway_c5_AllPurposeModel_TyreRelaxation
    ((SFc5_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c5_AllPurposeModel_TyreRelaxation
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c5_AllPurposeModel_TyreRelaxation
    ((SFc5_AllPurposeModel_TyreRelaxationInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c5_AllPurposeModel_TyreRelaxation(SimStruct*
  S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c5_AllPurposeModel_TyreRelaxation
    ((SFc5_AllPurposeModel_TyreRelaxationInstanceStruct*)
     chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c5_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_AllPurposeModel_TyreRelaxationInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_AllPurposeModel_TyreRelaxation_optimization_info();
    }

    finalize_c5_AllPurposeModel_TyreRelaxation
      ((SFc5_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc5_AllPurposeModel_TyreRelaxation
    ((SFc5_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_AllPurposeModel_TyreRelaxation(SimStruct *S)
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
    initialize_params_c5_AllPurposeModel_TyreRelaxation
      ((SFc5_AllPurposeModel_TyreRelaxationInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c5_AllPurposeModel_TyreRelaxation(SimStruct *S)
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
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,5);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,5,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,5,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,5);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,5,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,5,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 5; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,5);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(655255679U));
  ssSetChecksum1(S,(113952167U));
  ssSetChecksum2(S,(154558070U));
  ssSetChecksum3(S,(1615440874U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c5_AllPurposeModel_TyreRelaxation(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c5_AllPurposeModel_TyreRelaxation(SimStruct *S)
{
  SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct *)utMalloc
    (sizeof(SFc5_AllPurposeModel_TyreRelaxationInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc5_AllPurposeModel_TyreRelaxationInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c5_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c5_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c5_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c5_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c5_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c5_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c5_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c5_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.mdlStart = mdlStart_c5_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c5_AllPurposeModel_TyreRelaxation;
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

void c5_AllPurposeModel_TyreRelaxation_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_AllPurposeModel_TyreRelaxation(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_AllPurposeModel_TyreRelaxation(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_AllPurposeModel_TyreRelaxation(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_AllPurposeModel_TyreRelaxation_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
