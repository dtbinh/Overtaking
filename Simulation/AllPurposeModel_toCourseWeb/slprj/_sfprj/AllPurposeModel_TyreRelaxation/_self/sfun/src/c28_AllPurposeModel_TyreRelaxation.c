/* Include files */

#include <stddef.h>
#include "blas.h"
#include "AllPurposeModel_TyreRelaxation_sfun.h"
#include "c28_AllPurposeModel_TyreRelaxation.h"
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
static const char * c28_debug_family_names[17] = { "w_f_actl", "v_x_actl", "Fx",
  "T_s4_temp", "T_us4_temp", "delta_w4_temp", "nargin", "nargout", "APed",
  "BPed", "SteWhlAn", "LongDir", "w_w4_actl", "Par", "T_s4", "T_us4", "delta_w4"
};

/* Function Declarations */
static void initialize_c28_AllPurposeModel_TyreRelaxation
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void initialize_params_c28_AllPurposeModel_TyreRelaxation
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void enable_c28_AllPurposeModel_TyreRelaxation
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void disable_c28_AllPurposeModel_TyreRelaxation
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void c28_update_debugger_state_c28_AllPurposeModel_TyreRelaxation
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c28_AllPurposeModel_TyreRelaxation
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void set_sim_state_c28_AllPurposeModel_TyreRelaxation
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c28_st);
static void finalize_c28_AllPurposeModel_TyreRelaxation
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void sf_gateway_c28_AllPurposeModel_TyreRelaxation
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void mdl_start_c28_AllPurposeModel_TyreRelaxation
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void c28_chartstep_c28_AllPurposeModel_TyreRelaxation
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void initSimStructsc28_AllPurposeModel_TyreRelaxation
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c28_machineNumber, uint32_T
  c28_chartNumber, uint32_T c28_instanceNumber);
static const mxArray *c28_sf_marshallOut(void *chartInstanceVoid, void
  *c28_inData);
static c28_whl_vec4 c28_emlrt_marshallIn
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c28_b_delta_w4, const char_T *c28_identifier);
static c28_whl_vec4 c28_b_emlrt_marshallIn
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId);
static real_T c28_c_emlrt_marshallIn
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId);
static void c28_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c28_mxArrayInData, const char_T *c28_varName, void *c28_outData);
static const mxArray *c28_b_sf_marshallOut(void *chartInstanceVoid, void
  *c28_inData);
static void c28_d_emlrt_marshallIn
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId,
   c28_struct_iBlsPBO3AGnt69vDoTx5zD *c28_y);
static void c28_e_emlrt_marshallIn
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId,
   c28_struct_Nst2vGTExxHsg85EUOj9EH *c28_y);
static c28_struct_HhckT6rntEraqECYVIDvCC c28_f_emlrt_marshallIn
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId);
static void c28_g_emlrt_marshallIn
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId,
   c28_struct_ZCmOWPuqBDw16FSOVVD00 *c28_y);
static void c28_h_emlrt_marshallIn
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId, real_T c28_y[4]);
static void c28_i_emlrt_marshallIn
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId,
   c28_struct_ZKAzdrl7umDGJoC14aoVKC *c28_y);
static void c28_j_emlrt_marshallIn
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId, real_T c28_y[3]);
static c28_struct_r4FNviKwHfdhB8nQjvQv9 c28_k_emlrt_marshallIn
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId);
static c28_struct_Y9F1qlBi9AhssksPwemA4G c28_l_emlrt_marshallIn
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId);
static void c28_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c28_mxArrayInData, const char_T *c28_varName, void *c28_outData);
static const mxArray *c28_c_sf_marshallOut(void *chartInstanceVoid, void
  *c28_inData);
static void c28_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c28_mxArrayInData, const char_T *c28_varName, void *c28_outData);
static const mxArray *c28_d_sf_marshallOut(void *chartInstanceVoid, void
  *c28_inData);
static void c28_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c28_mxArrayInData, const char_T *c28_varName, void *c28_outData);
static void c28_info_helper(const mxArray **c28_info);
static const mxArray *c28_emlrt_marshallOut(const char * c28_u);
static const mxArray *c28_b_emlrt_marshallOut(const uint32_T c28_u);
static void c28_eml_switch_helper
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void c28_check_forloop_overflow_error
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, boolean_T
   c28_overflow);
static const mxArray *c28_e_sf_marshallOut(void *chartInstanceVoid, void
  *c28_inData);
static int32_T c28_m_emlrt_marshallIn
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId);
static void c28_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c28_mxArrayInData, const char_T *c28_varName, void *c28_outData);
static const mxArray *c28_T_s4_bus_io(void *chartInstanceVoid, void *c28_pData);
static uint8_T c28_n_emlrt_marshallIn
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c28_b_is_active_c28_AllPurposeModel_TyreRelaxation, const char_T
   *c28_identifier);
static uint8_T c28_o_emlrt_marshallIn
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId);
static void init_dsm_address_info
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void init_simulink_io_address
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c28_AllPurposeModel_TyreRelaxation
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  chartInstance->c28_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c28_is_active_c28_AllPurposeModel_TyreRelaxation = 0U;
}

static void initialize_params_c28_AllPurposeModel_TyreRelaxation
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  const mxArray *c28_m0 = NULL;
  const mxArray *c28_mxField;
  const mxArray *c28_m1 = NULL;
  const mxArray *c28_b_mxField;
  c28_struct_iBlsPBO3AGnt69vDoTx5zD c28_r0;
  const mxArray *c28_m2 = NULL;
  const mxArray *c28_c_mxField;
  const mxArray *c28_m3 = NULL;
  const mxArray *c28_d_mxField;
  const mxArray *c28_m4 = NULL;
  const mxArray *c28_e_mxField;
  const mxArray *c28_m5 = NULL;
  const mxArray *c28_f_mxField;
  const mxArray *c28_m6 = NULL;
  const mxArray *c28_g_mxField;
  const mxArray *c28_m7 = NULL;
  const mxArray *c28_h_mxField;
  const mxArray *c28_m8 = NULL;
  const mxArray *c28_i_mxField;
  const mxArray *c28_m9 = NULL;
  const mxArray *c28_j_mxField;
  const mxArray *c28_m10 = NULL;
  const mxArray *c28_k_mxField;
  const mxArray *c28_m11 = NULL;
  const mxArray *c28_l_mxField;
  const mxArray *c28_m12 = NULL;
  const mxArray *c28_m_mxField;
  const mxArray *c28_m13 = NULL;
  const mxArray *c28_n_mxField;
  c28_m0 = sf_mex_get_sfun_param(chartInstance->S, 0, 1);
  c28_mxField = sf_mex_getfield(c28_m0, "Env", "Par", 0);
  c28_m1 = sf_mex_dup(c28_mxField);
  c28_b_mxField = sf_mex_getfield(c28_m1, "g", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_b_mxField), &c28_r0.Env.g, 1, 0, 0U,
                      0, 0U, 0);
  c28_b_mxField = sf_mex_getfield(c28_m1, "left1", "Par", 0);
  c28_m2 = sf_mex_dup(c28_b_mxField);
  c28_c_mxField = sf_mex_getfield(c28_m2, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_c_mxField), &c28_r0.Env.left1.x, 1,
                      0, 0U, 0, 0U, 0);
  c28_c_mxField = sf_mex_getfield(c28_m2, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_c_mxField), &c28_r0.Env.left1.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c28_m2);
  c28_b_mxField = sf_mex_getfield(c28_m1, "right1", "Par", 0);
  c28_m3 = sf_mex_dup(c28_b_mxField);
  c28_d_mxField = sf_mex_getfield(c28_m3, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_d_mxField), &c28_r0.Env.right1.x, 1,
                      0, 0U, 0, 0U, 0);
  c28_d_mxField = sf_mex_getfield(c28_m3, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_d_mxField), &c28_r0.Env.right1.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c28_m3);
  c28_b_mxField = sf_mex_getfield(c28_m1, "right2", "Par", 0);
  c28_m4 = sf_mex_dup(c28_b_mxField);
  c28_e_mxField = sf_mex_getfield(c28_m4, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_e_mxField), &c28_r0.Env.right2.x, 1,
                      0, 0U, 0, 0U, 0);
  c28_e_mxField = sf_mex_getfield(c28_m4, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_e_mxField), &c28_r0.Env.right2.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c28_m4);
  c28_b_mxField = sf_mex_getfield(c28_m1, "left2", "Par", 0);
  c28_m5 = sf_mex_dup(c28_b_mxField);
  c28_f_mxField = sf_mex_getfield(c28_m5, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_f_mxField), &c28_r0.Env.left2.x, 1,
                      0, 0U, 0, 0U, 0);
  c28_f_mxField = sf_mex_getfield(c28_m5, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_f_mxField), &c28_r0.Env.left2.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c28_m5);
  c28_b_mxField = sf_mex_getfield(c28_m1, "right3", "Par", 0);
  c28_m6 = sf_mex_dup(c28_b_mxField);
  c28_g_mxField = sf_mex_getfield(c28_m6, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_g_mxField), &c28_r0.Env.right3.x, 1,
                      0, 0U, 0, 0U, 0);
  c28_g_mxField = sf_mex_getfield(c28_m6, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_g_mxField), &c28_r0.Env.right3.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c28_m6);
  c28_b_mxField = sf_mex_getfield(c28_m1, "mu", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_b_mxField), &c28_r0.Env.mu, 1, 0, 0U,
                      0, 0U, 0);
  sf_mex_destroy(&c28_m1);
  c28_mxField = sf_mex_getfield(c28_m0, "Veh", "Par", 0);
  c28_m7 = sf_mex_dup(c28_mxField);
  c28_h_mxField = sf_mex_getfield(c28_m7, "m", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_h_mxField), &c28_r0.Veh.m, 1, 0, 0U,
                      0, 0U, 0);
  c28_h_mxField = sf_mex_getfield(c28_m7, "Jz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_h_mxField), &c28_r0.Veh.Jz, 1, 0, 0U,
                      0, 0U, 0);
  c28_h_mxField = sf_mex_getfield(c28_m7, "m_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_h_mxField), &c28_r0.Veh.m_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c28_h_mxField = sf_mex_getfield(c28_m7, "Jx_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_h_mxField), &c28_r0.Veh.Jx_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c28_h_mxField = sf_mex_getfield(c28_m7, "Jy_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_h_mxField), &c28_r0.Veh.Jy_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c28_h_mxField = sf_mex_getfield(c28_m7, "lf", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_h_mxField), &c28_r0.Veh.lf, 1, 0, 0U,
                      0, 0U, 0);
  c28_h_mxField = sf_mex_getfield(c28_m7, "lr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_h_mxField), &c28_r0.Veh.lr, 1, 0, 0U,
                      0, 0U, 0);
  c28_h_mxField = sf_mex_getfield(c28_m7, "L", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_h_mxField), &c28_r0.Veh.L, 1, 0, 0U,
                      0, 0U, 0);
  c28_h_mxField = sf_mex_getfield(c28_m7, "TrackWidth", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_h_mxField), &c28_r0.Veh.TrackWidth,
                      1, 0, 0U, 0, 0U, 0);
  c28_h_mxField = sf_mex_getfield(c28_m7, "h", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_h_mxField), &c28_r0.Veh.h, 1, 0, 0U,
                      0, 0U, 0);
  c28_h_mxField = sf_mex_getfield(c28_m7, "HalfRohACd", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_h_mxField), &c28_r0.Veh.HalfRohACd,
                      1, 0, 0U, 0, 0U, 0);
  c28_h_mxField = sf_mex_getfield(c28_m7, "F_z4_static", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_h_mxField), c28_r0.Veh.F_z4_static,
                      1, 0, 0U, 1, 0U, 2, 1, 4);
  c28_h_mxField = sf_mex_getfield(c28_m7, "Rw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_h_mxField), &c28_r0.Veh.Rw, 1, 0, 0U,
                      0, 0U, 0);
  c28_h_mxField = sf_mex_getfield(c28_m7, "r_long", "Par", 0);
  c28_m8 = sf_mex_dup(c28_h_mxField);
  c28_i_mxField = sf_mex_getfield(c28_m8, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_i_mxField), c28_r0.Veh.r_long.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c28_i_mxField = sf_mex_getfield(c28_m8, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_i_mxField), c28_r0.Veh.r_long.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c28_i_mxField = sf_mex_getfield(c28_m8, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_i_mxField), c28_r0.Veh.r_long.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c28_i_mxField = sf_mex_getfield(c28_m8, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_i_mxField), c28_r0.Veh.r_long.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c28_m8);
  c28_h_mxField = sf_mex_getfield(c28_m7, "r_lat", "Par", 0);
  c28_m9 = sf_mex_dup(c28_h_mxField);
  c28_j_mxField = sf_mex_getfield(c28_m9, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_j_mxField), c28_r0.Veh.r_lat.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c28_j_mxField = sf_mex_getfield(c28_m9, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_j_mxField), c28_r0.Veh.r_lat.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c28_j_mxField = sf_mex_getfield(c28_m9, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_j_mxField), c28_r0.Veh.r_lat.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c28_j_mxField = sf_mex_getfield(c28_m9, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_j_mxField), c28_r0.Veh.r_lat.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c28_m9);
  c28_h_mxField = sf_mex_getfield(c28_m7, "r_lever", "Par", 0);
  c28_m10 = sf_mex_dup(c28_h_mxField);
  c28_k_mxField = sf_mex_getfield(c28_m10, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_k_mxField), c28_r0.Veh.r_lever.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c28_k_mxField = sf_mex_getfield(c28_m10, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_k_mxField), c28_r0.Veh.r_lever.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c28_k_mxField = sf_mex_getfield(c28_m10, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_k_mxField), c28_r0.Veh.r_lever.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c28_k_mxField = sf_mex_getfield(c28_m10, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_k_mxField), c28_r0.Veh.r_lever.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c28_m10);
  c28_h_mxField = sf_mex_getfield(c28_m7, "r_pivot", "Par", 0);
  c28_m11 = sf_mex_dup(c28_h_mxField);
  c28_l_mxField = sf_mex_getfield(c28_m11, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_l_mxField), c28_r0.Veh.r_pivot.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c28_l_mxField = sf_mex_getfield(c28_m11, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_l_mxField), c28_r0.Veh.r_pivot.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c28_l_mxField = sf_mex_getfield(c28_m11, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_l_mxField), c28_r0.Veh.r_pivot.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c28_l_mxField = sf_mex_getfield(c28_m11, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_l_mxField), c28_r0.Veh.r_pivot.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c28_m11);
  c28_h_mxField = sf_mex_getfield(c28_m7, "cw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_h_mxField), &c28_r0.Veh.cw, 1, 0, 0U,
                      0, 0U, 0);
  c28_h_mxField = sf_mex_getfield(c28_m7, "carb_f", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_h_mxField), &c28_r0.Veh.carb_f, 1, 0,
                      0U, 0, 0U, 0);
  c28_h_mxField = sf_mex_getfield(c28_m7, "carb_r", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_h_mxField), &c28_r0.Veh.carb_r, 1, 0,
                      0U, 0, 0U, 0);
  c28_h_mxField = sf_mex_getfield(c28_m7, "dw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_h_mxField), &c28_r0.Veh.dw, 1, 0, 0U,
                      0, 0U, 0);
  c28_h_mxField = sf_mex_getfield(c28_m7, "Jw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_h_mxField), &c28_r0.Veh.Jw, 1, 0, 0U,
                      0, 0U, 0);
  c28_h_mxField = sf_mex_getfield(c28_m7, "C0", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_h_mxField), &c28_r0.Veh.C0, 1, 0, 0U,
                      0, 0U, 0);
  c28_h_mxField = sf_mex_getfield(c28_m7, "RelaxLength", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_h_mxField), &c28_r0.Veh.RelaxLength,
                      1, 0, 0U, 0, 0U, 0);
  c28_h_mxField = sf_mex_getfield(c28_m7, "RRC", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_h_mxField), &c28_r0.Veh.RRC, 1, 0,
                      0U, 0, 0U, 0);
  c28_h_mxField = sf_mex_getfield(c28_m7, "Pmax", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_h_mxField), &c28_r0.Veh.Pmax, 1, 0,
                      0U, 0, 0U, 0);
  c28_h_mxField = sf_mex_getfield(c28_m7, "PropDistrFrnt", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_h_mxField),
                      &c28_r0.Veh.PropDistrFrnt, 1, 0, 0U, 0, 0U, 0);
  c28_h_mxField = sf_mex_getfield(c28_m7, "BrkDistrFrnt", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_h_mxField), &c28_r0.Veh.BrkDistrFrnt,
                      1, 0, 0U, 0, 0U, 0);
  c28_h_mxField = sf_mex_getfield(c28_m7, "SteRatio", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_h_mxField), &c28_r0.Veh.SteRatio, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c28_m7);
  c28_mxField = sf_mex_getfield(c28_m0, "Drvr", "Par", 0);
  c28_m12 = sf_mex_dup(c28_mxField);
  c28_m_mxField = sf_mex_getfield(c28_m12, "v_set", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_m_mxField), &c28_r0.Drvr.v_set, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c28_m12);
  c28_mxField = sf_mex_getfield(c28_m0, "Init", "Par", 0);
  c28_m13 = sf_mex_dup(c28_mxField);
  c28_n_mxField = sf_mex_getfield(c28_m13, "v_x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_n_mxField), &c28_r0.Init.v_x, 1, 0,
                      0U, 0, 0U, 0);
  c28_n_mxField = sf_mex_getfield(c28_m13, "F_fz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_n_mxField), &c28_r0.Init.F_fz, 1, 0,
                      0U, 0, 0U, 0);
  c28_n_mxField = sf_mex_getfield(c28_m13, "F_rz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c28_n_mxField), &c28_r0.Init.F_rz, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c28_m13);
  sf_mex_destroy(&c28_m0);
  chartInstance->c28_Par = c28_r0;
}

static void enable_c28_AllPurposeModel_TyreRelaxation
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c28_AllPurposeModel_TyreRelaxation
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c28_update_debugger_state_c28_AllPurposeModel_TyreRelaxation
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c28_AllPurposeModel_TyreRelaxation
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  const mxArray *c28_st;
  const mxArray *c28_y = NULL;
  const mxArray *c28_b_y = NULL;
  real_T c28_u;
  const mxArray *c28_c_y = NULL;
  real_T c28_b_u;
  const mxArray *c28_d_y = NULL;
  real_T c28_c_u;
  const mxArray *c28_e_y = NULL;
  real_T c28_d_u;
  const mxArray *c28_f_y = NULL;
  const mxArray *c28_g_y = NULL;
  real_T c28_e_u;
  const mxArray *c28_h_y = NULL;
  real_T c28_f_u;
  const mxArray *c28_i_y = NULL;
  real_T c28_g_u;
  const mxArray *c28_j_y = NULL;
  real_T c28_h_u;
  const mxArray *c28_k_y = NULL;
  const mxArray *c28_l_y = NULL;
  real_T c28_i_u;
  const mxArray *c28_m_y = NULL;
  real_T c28_j_u;
  const mxArray *c28_n_y = NULL;
  real_T c28_k_u;
  const mxArray *c28_o_y = NULL;
  real_T c28_l_u;
  const mxArray *c28_p_y = NULL;
  uint8_T c28_hoistedGlobal;
  uint8_T c28_m_u;
  const mxArray *c28_q_y = NULL;
  c28_st = NULL;
  c28_st = NULL;
  c28_y = NULL;
  sf_mex_assign(&c28_y, sf_mex_createcellmatrix(4, 1), false);
  c28_b_y = NULL;
  sf_mex_assign(&c28_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c28_u = *(real_T *)&((char_T *)chartInstance->c28_T_s4)[0];
  c28_c_y = NULL;
  sf_mex_assign(&c28_c_y, sf_mex_create("y", &c28_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c28_b_y, c28_c_y, "fl", "fl", 0);
  c28_b_u = *(real_T *)&((char_T *)chartInstance->c28_T_s4)[8];
  c28_d_y = NULL;
  sf_mex_assign(&c28_d_y, sf_mex_create("y", &c28_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c28_b_y, c28_d_y, "fr", "fr", 0);
  c28_c_u = *(real_T *)&((char_T *)chartInstance->c28_T_s4)[16];
  c28_e_y = NULL;
  sf_mex_assign(&c28_e_y, sf_mex_create("y", &c28_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c28_b_y, c28_e_y, "rl", "rl", 0);
  c28_d_u = *(real_T *)&((char_T *)chartInstance->c28_T_s4)[24];
  c28_f_y = NULL;
  sf_mex_assign(&c28_f_y, sf_mex_create("y", &c28_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c28_b_y, c28_f_y, "rr", "rr", 0);
  sf_mex_setcell(c28_y, 0, c28_b_y);
  c28_g_y = NULL;
  sf_mex_assign(&c28_g_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c28_e_u = *(real_T *)&((char_T *)chartInstance->c28_T_us4)[0];
  c28_h_y = NULL;
  sf_mex_assign(&c28_h_y, sf_mex_create("y", &c28_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c28_g_y, c28_h_y, "fl", "fl", 0);
  c28_f_u = *(real_T *)&((char_T *)chartInstance->c28_T_us4)[8];
  c28_i_y = NULL;
  sf_mex_assign(&c28_i_y, sf_mex_create("y", &c28_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c28_g_y, c28_i_y, "fr", "fr", 0);
  c28_g_u = *(real_T *)&((char_T *)chartInstance->c28_T_us4)[16];
  c28_j_y = NULL;
  sf_mex_assign(&c28_j_y, sf_mex_create("y", &c28_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c28_g_y, c28_j_y, "rl", "rl", 0);
  c28_h_u = *(real_T *)&((char_T *)chartInstance->c28_T_us4)[24];
  c28_k_y = NULL;
  sf_mex_assign(&c28_k_y, sf_mex_create("y", &c28_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c28_g_y, c28_k_y, "rr", "rr", 0);
  sf_mex_setcell(c28_y, 1, c28_g_y);
  c28_l_y = NULL;
  sf_mex_assign(&c28_l_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c28_i_u = *(real_T *)&((char_T *)chartInstance->c28_delta_w4)[0];
  c28_m_y = NULL;
  sf_mex_assign(&c28_m_y, sf_mex_create("y", &c28_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c28_l_y, c28_m_y, "fl", "fl", 0);
  c28_j_u = *(real_T *)&((char_T *)chartInstance->c28_delta_w4)[8];
  c28_n_y = NULL;
  sf_mex_assign(&c28_n_y, sf_mex_create("y", &c28_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c28_l_y, c28_n_y, "fr", "fr", 0);
  c28_k_u = *(real_T *)&((char_T *)chartInstance->c28_delta_w4)[16];
  c28_o_y = NULL;
  sf_mex_assign(&c28_o_y, sf_mex_create("y", &c28_k_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c28_l_y, c28_o_y, "rl", "rl", 0);
  c28_l_u = *(real_T *)&((char_T *)chartInstance->c28_delta_w4)[24];
  c28_p_y = NULL;
  sf_mex_assign(&c28_p_y, sf_mex_create("y", &c28_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c28_l_y, c28_p_y, "rr", "rr", 0);
  sf_mex_setcell(c28_y, 2, c28_l_y);
  c28_hoistedGlobal =
    chartInstance->c28_is_active_c28_AllPurposeModel_TyreRelaxation;
  c28_m_u = c28_hoistedGlobal;
  c28_q_y = NULL;
  sf_mex_assign(&c28_q_y, sf_mex_create("y", &c28_m_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c28_y, 3, c28_q_y);
  sf_mex_assign(&c28_st, c28_y, false);
  return c28_st;
}

static void set_sim_state_c28_AllPurposeModel_TyreRelaxation
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c28_st)
{
  const mxArray *c28_u;
  c28_whl_vec4 c28_r1;
  c28_whl_vec4 c28_r2;
  c28_whl_vec4 c28_r3;
  chartInstance->c28_doneDoubleBufferReInit = true;
  c28_u = sf_mex_dup(c28_st);
  c28_r1 = c28_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c28_u,
    0)), "T_s4");
  *(real_T *)&((char_T *)chartInstance->c28_T_s4)[0] = c28_r1.fl;
  *(real_T *)&((char_T *)chartInstance->c28_T_s4)[8] = c28_r1.fr;
  *(real_T *)&((char_T *)chartInstance->c28_T_s4)[16] = c28_r1.rl;
  *(real_T *)&((char_T *)chartInstance->c28_T_s4)[24] = c28_r1.rr;
  c28_r2 = c28_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c28_u,
    1)), "T_us4");
  *(real_T *)&((char_T *)chartInstance->c28_T_us4)[0] = c28_r2.fl;
  *(real_T *)&((char_T *)chartInstance->c28_T_us4)[8] = c28_r2.fr;
  *(real_T *)&((char_T *)chartInstance->c28_T_us4)[16] = c28_r2.rl;
  *(real_T *)&((char_T *)chartInstance->c28_T_us4)[24] = c28_r2.rr;
  c28_r3 = c28_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c28_u,
    2)), "delta_w4");
  *(real_T *)&((char_T *)chartInstance->c28_delta_w4)[0] = c28_r3.fl;
  *(real_T *)&((char_T *)chartInstance->c28_delta_w4)[8] = c28_r3.fr;
  *(real_T *)&((char_T *)chartInstance->c28_delta_w4)[16] = c28_r3.rl;
  *(real_T *)&((char_T *)chartInstance->c28_delta_w4)[24] = c28_r3.rr;
  chartInstance->c28_is_active_c28_AllPurposeModel_TyreRelaxation =
    c28_n_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c28_u, 3)),
    "is_active_c28_AllPurposeModel_TyreRelaxation");
  sf_mex_destroy(&c28_u);
  c28_update_debugger_state_c28_AllPurposeModel_TyreRelaxation(chartInstance);
  sf_mex_destroy(&c28_st);
}

static void finalize_c28_AllPurposeModel_TyreRelaxation
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c28_AllPurposeModel_TyreRelaxation
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 18U, chartInstance->c28_sfEvent);
  chartInstance->c28_sfEvent = CALL_EVENT;
  c28_chartstep_c28_AllPurposeModel_TyreRelaxation(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_AllPurposeModel_TyreRelaxationMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c28_APed, 2U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c28_BPed, 3U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c28_SteWhlAn, 4U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c28_LongDir, 5U);
}

static void mdl_start_c28_AllPurposeModel_TyreRelaxation
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c28_chartstep_c28_AllPurposeModel_TyreRelaxation
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  real_T c28_hoistedGlobal;
  real_T c28_b_hoistedGlobal;
  real_T c28_c_hoistedGlobal;
  real_T c28_d_hoistedGlobal;
  real_T c28_b_APed;
  real_T c28_b_BPed;
  real_T c28_b_SteWhlAn;
  real_T c28_b_LongDir;
  c28_whl_vec4 c28_b_w_w4_actl;
  c28_struct_iBlsPBO3AGnt69vDoTx5zD c28_b_Par;
  uint32_T c28_debug_family_var_map[17];
  real_T c28_w_f_actl;
  real_T c28_v_x_actl;
  real_T c28_Fx;
  real_T c28_T_s4_temp[4];
  real_T c28_T_us4_temp[4];
  real_T c28_delta_w4_temp[4];
  real_T c28_nargin = 6.0;
  real_T c28_nargout = 3.0;
  c28_whl_vec4 c28_b_T_s4;
  c28_whl_vec4 c28_b_T_us4;
  c28_whl_vec4 c28_b_delta_w4;
  real_T c28_A;
  real_T c28_x;
  real_T c28_b_x;
  real_T c28_c_x;
  real_T c28_b_A;
  real_T c28_d_x;
  real_T c28_e_x;
  real_T c28_f_x;
  real_T c28_varargin_1[2];
  int32_T c28_ixstart;
  real_T c28_mtmp;
  real_T c28_g_x;
  boolean_T c28_b;
  int32_T c28_ix;
  int32_T c28_b_ix;
  real_T c28_h_x;
  boolean_T c28_b_b;
  int32_T c28_a;
  int32_T c28_b_a;
  int32_T c28_i0;
  int32_T c28_c_a;
  int32_T c28_d_a;
  boolean_T c28_overflow;
  int32_T c28_c_ix;
  real_T c28_e_a;
  real_T c28_c_b;
  boolean_T c28_p;
  real_T c28_b_mtmp;
  real_T c28_maxval;
  real_T c28_c_A;
  real_T c28_B;
  real_T c28_i_x;
  real_T c28_y;
  real_T c28_j_x;
  real_T c28_b_y;
  real_T c28_k_x;
  real_T c28_c_y;
  real_T c28_d_A;
  real_T c28_l_x;
  real_T c28_m_x;
  real_T c28_n_x;
  real_T c28_d_y;
  real_T c28_f_a;
  int32_T c28_i1;
  real_T c28_e_A;
  real_T c28_o_x;
  real_T c28_p_x;
  real_T c28_q_x;
  real_T c28_e_y;
  real_T c28_g_a;
  int32_T c28_i2;
  real_T c28_f_y[2];
  real_T c28_h_a;
  int32_T c28_i3;
  real_T c28_d_b[4];
  int32_T c28_i4;
  int32_T c28_i5;
  real_T c28_e_b;
  int32_T c28_i6;
  int32_T c28_i7;
  int32_T c28_i8;
  real_T c28_r_x;
  real_T c28_s_x;
  real_T c28_f_A;
  real_T c28_t_x;
  real_T c28_u_x;
  real_T c28_v_x;
  real_T c28_g_y;
  real_T c28_i_a;
  int32_T c28_i9;
  real_T c28_g_A;
  real_T c28_w_x;
  real_T c28_x_x;
  real_T c28_y_x;
  real_T c28_h_y;
  real_T c28_j_a;
  int32_T c28_i10;
  real_T c28_k_a;
  int32_T c28_i11;
  int32_T c28_i12;
  int32_T c28_i13;
  real_T c28_f_b;
  int32_T c28_i14;
  real_T c28_h_A;
  real_T c28_b_B;
  real_T c28_ab_x;
  real_T c28_i_y;
  real_T c28_bb_x;
  real_T c28_j_y;
  real_T c28_cb_x;
  real_T c28_k_y;
  real_T c28_l_y;
  real_T c28_l_a;
  int32_T c28_i15;
  int32_T c28_i16;
  int32_T c28_i17;
  c28_whl_vec4 c28_r4;
  c28_whl_vec4 c28_r5;
  c28_whl_vec4 c28_r6;
  boolean_T exitg1;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 18U, chartInstance->c28_sfEvent);
  c28_hoistedGlobal = *chartInstance->c28_APed;
  c28_b_hoistedGlobal = *chartInstance->c28_BPed;
  c28_c_hoistedGlobal = *chartInstance->c28_SteWhlAn;
  c28_d_hoistedGlobal = *chartInstance->c28_LongDir;
  c28_b_APed = c28_hoistedGlobal;
  c28_b_BPed = c28_b_hoistedGlobal;
  c28_b_SteWhlAn = c28_c_hoistedGlobal;
  c28_b_LongDir = c28_d_hoistedGlobal;
  c28_b_w_w4_actl.fl = *(real_T *)&((char_T *)chartInstance->c28_w_w4_actl)[0];
  c28_b_w_w4_actl.fr = *(real_T *)&((char_T *)chartInstance->c28_w_w4_actl)[8];
  c28_b_w_w4_actl.rl = *(real_T *)&((char_T *)chartInstance->c28_w_w4_actl)[16];
  c28_b_w_w4_actl.rr = *(real_T *)&((char_T *)chartInstance->c28_w_w4_actl)[24];
  c28_b_Par = chartInstance->c28_Par;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 17U, 17U, c28_debug_family_names,
    c28_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c28_w_f_actl, 0U, c28_c_sf_marshallOut,
    c28_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c28_v_x_actl, 1U, c28_c_sf_marshallOut,
    c28_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c28_Fx, 2U, c28_c_sf_marshallOut,
    c28_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c28_T_s4_temp, 3U, c28_d_sf_marshallOut,
    c28_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c28_T_us4_temp, 4U, c28_d_sf_marshallOut,
    c28_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c28_delta_w4_temp, 5U,
    c28_d_sf_marshallOut, c28_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c28_nargin, 6U, c28_c_sf_marshallOut,
    c28_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c28_nargout, 7U, c28_c_sf_marshallOut,
    c28_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c28_b_APed, 8U, c28_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c28_b_BPed, 9U, c28_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c28_b_SteWhlAn, 10U, c28_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c28_b_LongDir, 11U, c28_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c28_b_w_w4_actl, 12U, c28_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c28_b_Par, 13U, c28_b_sf_marshallOut,
    c28_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c28_b_T_s4, 14U, c28_sf_marshallOut,
    c28_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c28_b_T_us4, 15U, c28_sf_marshallOut,
    c28_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c28_b_delta_w4, 16U, c28_sf_marshallOut,
    c28_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 4);
  c28_A = c28_b_w_w4_actl.fl + c28_b_w_w4_actl.fr;
  c28_x = c28_A;
  c28_b_x = c28_x;
  c28_c_x = c28_b_x;
  c28_w_f_actl = c28_c_x / 2.0;
  _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 5);
  c28_b_A = c28_b_w_w4_actl.rl + c28_b_w_w4_actl.rr;
  c28_d_x = c28_b_A;
  c28_e_x = c28_d_x;
  c28_f_x = c28_e_x;
  c28_v_x_actl = c28_f_x / 2.0;
  _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 7);
  if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c28_b_BPed, 0.01, -1, 2U,
        c28_b_BPed < 0.01))) {
    _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 8);
    c28_varargin_1[0] = c28_w_f_actl * c28_b_Par.Veh.Rw;
    c28_varargin_1[1] = 1.0;
    c28_ixstart = 1;
    c28_mtmp = c28_varargin_1[0];
    c28_g_x = c28_mtmp;
    c28_b = muDoubleScalarIsNaN(c28_g_x);
    if (c28_b) {
      c28_eml_switch_helper(chartInstance);
      c28_eml_switch_helper(chartInstance);
      c28_ix = 2;
      exitg1 = false;
      while ((exitg1 == false) && (c28_ix < 3)) {
        c28_b_ix = c28_ix;
        c28_ixstart = c28_b_ix;
        c28_h_x = c28_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c28_b_ix), 1, 2, 1, 0) - 1];
        c28_b_b = muDoubleScalarIsNaN(c28_h_x);
        if (!c28_b_b) {
          c28_mtmp = c28_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c28_b_ix), 1, 2, 1, 0) - 1];
          exitg1 = true;
        } else {
          c28_ix++;
        }
      }
    }

    if (c28_ixstart < 2) {
      c28_a = c28_ixstart;
      c28_b_a = c28_a + 1;
      c28_i0 = c28_b_a;
      c28_c_a = c28_i0;
      c28_d_a = c28_c_a;
      if (c28_d_a > 2) {
        c28_overflow = false;
      } else {
        c28_eml_switch_helper(chartInstance);
        c28_eml_switch_helper(chartInstance);
        c28_overflow = false;
      }

      if (c28_overflow) {
        c28_check_forloop_overflow_error(chartInstance, c28_overflow);
      }

      for (c28_c_ix = c28_i0; c28_c_ix < 3; c28_c_ix++) {
        c28_b_ix = c28_c_ix;
        c28_e_a = c28_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c28_b_ix), 1, 2, 1, 0) - 1];
        c28_c_b = c28_mtmp;
        c28_p = (c28_e_a > c28_c_b);
        if (c28_p) {
          c28_mtmp = c28_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c28_b_ix), 1, 2, 1, 0) - 1];
        }
      }
    }

    c28_b_mtmp = c28_mtmp;
    c28_maxval = c28_b_mtmp;
    c28_c_A = c28_b_LongDir * c28_b_APed * c28_b_Par.Veh.Pmax;
    c28_B = c28_maxval;
    c28_i_x = c28_c_A;
    c28_y = c28_B;
    c28_j_x = c28_i_x;
    c28_b_y = c28_y;
    c28_k_x = c28_j_x;
    c28_c_y = c28_b_y;
    c28_Fx = c28_k_x / c28_c_y;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 9);
    if (CV_EML_IF(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 1, c28_v_x_actl, 0.0, -1,
          4U, c28_v_x_actl > 0.0))) {
      _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 10);
      c28_Fx = -c28_b_BPed * c28_b_Par.Env.mu * c28_b_Par.Veh.m *
        c28_b_Par.Env.g;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 12);
      c28_Fx = -c28_v_x_actl * c28_b_BPed * 1700.0 * 9.80665;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 15);
  if (CV_EML_IF(0, 1, 2, CV_RELATIONAL_EVAL(4U, 0U, 2, c28_Fx, 0.0, -1, 4U,
        c28_Fx > 0.0))) {
    _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 16);
    c28_d_A = c28_b_Par.Veh.PropDistrFrnt;
    c28_l_x = c28_d_A;
    c28_m_x = c28_l_x;
    c28_n_x = c28_m_x;
    c28_d_y = c28_n_x / 2.0;
    c28_f_a = c28_d_y;
    for (c28_i1 = 0; c28_i1 < 2; c28_i1++) {
      c28_varargin_1[c28_i1] = c28_f_a;
    }

    c28_e_A = 1.0 - c28_b_Par.Veh.PropDistrFrnt;
    c28_o_x = c28_e_A;
    c28_p_x = c28_o_x;
    c28_q_x = c28_p_x;
    c28_e_y = c28_q_x / 2.0;
    c28_g_a = c28_e_y;
    for (c28_i2 = 0; c28_i2 < 2; c28_i2++) {
      c28_f_y[c28_i2] = c28_g_a;
    }

    c28_h_a = c28_Fx;
    for (c28_i3 = 0; c28_i3 < 2; c28_i3++) {
      c28_d_b[c28_i3] = c28_varargin_1[c28_i3];
    }

    for (c28_i4 = 0; c28_i4 < 2; c28_i4++) {
      c28_d_b[c28_i4 + 2] = c28_f_y[c28_i4];
    }

    for (c28_i5 = 0; c28_i5 < 4; c28_i5++) {
      c28_d_b[c28_i5] *= c28_h_a;
    }

    c28_e_b = c28_b_Par.Veh.Rw;
    for (c28_i6 = 0; c28_i6 < 4; c28_i6++) {
      c28_T_s4_temp[c28_i6] = c28_d_b[c28_i6] * c28_e_b;
    }

    _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 17);
    for (c28_i7 = 0; c28_i7 < 4; c28_i7++) {
      c28_T_us4_temp[c28_i7] = 0.0;
    }
  } else {
    _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 19);
    for (c28_i8 = 0; c28_i8 < 4; c28_i8++) {
      c28_T_s4_temp[c28_i8] = 0.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 20);
    c28_r_x = c28_v_x_actl;
    c28_s_x = c28_r_x;
    c28_s_x = muDoubleScalarSign(c28_s_x);
    c28_f_A = c28_b_Par.Veh.BrkDistrFrnt;
    c28_t_x = c28_f_A;
    c28_u_x = c28_t_x;
    c28_v_x = c28_u_x;
    c28_g_y = c28_v_x / 2.0;
    c28_i_a = c28_g_y;
    for (c28_i9 = 0; c28_i9 < 2; c28_i9++) {
      c28_varargin_1[c28_i9] = c28_i_a;
    }

    c28_g_A = 1.0 - c28_b_Par.Veh.BrkDistrFrnt;
    c28_w_x = c28_g_A;
    c28_x_x = c28_w_x;
    c28_y_x = c28_x_x;
    c28_h_y = c28_y_x / 2.0;
    c28_j_a = c28_h_y;
    for (c28_i10 = 0; c28_i10 < 2; c28_i10++) {
      c28_f_y[c28_i10] = c28_j_a;
    }

    c28_k_a = c28_s_x * c28_Fx;
    for (c28_i11 = 0; c28_i11 < 2; c28_i11++) {
      c28_d_b[c28_i11] = c28_varargin_1[c28_i11];
    }

    for (c28_i12 = 0; c28_i12 < 2; c28_i12++) {
      c28_d_b[c28_i12 + 2] = c28_f_y[c28_i12];
    }

    for (c28_i13 = 0; c28_i13 < 4; c28_i13++) {
      c28_d_b[c28_i13] *= c28_k_a;
    }

    c28_f_b = c28_b_Par.Veh.Rw;
    for (c28_i14 = 0; c28_i14 < 4; c28_i14++) {
      c28_T_us4_temp[c28_i14] = c28_d_b[c28_i14] * c28_f_b;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 22);
  c28_h_A = c28_b_SteWhlAn;
  c28_b_B = c28_b_Par.Veh.SteRatio;
  c28_ab_x = c28_h_A;
  c28_i_y = c28_b_B;
  c28_bb_x = c28_ab_x;
  c28_j_y = c28_i_y;
  c28_cb_x = c28_bb_x;
  c28_k_y = c28_j_y;
  c28_l_y = c28_cb_x / c28_k_y;
  c28_l_a = c28_l_y;
  for (c28_i15 = 0; c28_i15 < 2; c28_i15++) {
    c28_varargin_1[c28_i15] = c28_l_a;
  }

  for (c28_i16 = 0; c28_i16 < 2; c28_i16++) {
    c28_delta_w4_temp[c28_i16] = c28_varargin_1[c28_i16];
  }

  for (c28_i17 = 0; c28_i17 < 2; c28_i17++) {
    c28_delta_w4_temp[c28_i17 + 2] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 24);
  c28_r4.fl = c28_T_us4_temp[0];
  c28_r4.fr = c28_T_us4_temp[1];
  c28_r4.rl = c28_T_us4_temp[2];
  c28_r4.rr = c28_T_us4_temp[3];
  c28_b_T_us4 = c28_r4;
  _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 25);
  c28_r5.fl = c28_T_s4_temp[0];
  c28_r5.fr = c28_T_s4_temp[1];
  c28_r5.rl = c28_T_s4_temp[2];
  c28_r5.rr = c28_T_s4_temp[3];
  c28_b_T_s4 = c28_r5;
  _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 26);
  c28_r6.fl = c28_delta_w4_temp[0];
  c28_r6.fr = c28_delta_w4_temp[1];
  c28_r6.rl = c28_delta_w4_temp[2];
  c28_r6.rr = c28_delta_w4_temp[3];
  c28_b_delta_w4 = c28_r6;
  _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, -26);
  _SFD_SYMBOL_SCOPE_POP();
  *(real_T *)&((char_T *)chartInstance->c28_T_s4)[0] = c28_b_T_s4.fl;
  *(real_T *)&((char_T *)chartInstance->c28_T_s4)[8] = c28_b_T_s4.fr;
  *(real_T *)&((char_T *)chartInstance->c28_T_s4)[16] = c28_b_T_s4.rl;
  *(real_T *)&((char_T *)chartInstance->c28_T_s4)[24] = c28_b_T_s4.rr;
  *(real_T *)&((char_T *)chartInstance->c28_T_us4)[0] = c28_b_T_us4.fl;
  *(real_T *)&((char_T *)chartInstance->c28_T_us4)[8] = c28_b_T_us4.fr;
  *(real_T *)&((char_T *)chartInstance->c28_T_us4)[16] = c28_b_T_us4.rl;
  *(real_T *)&((char_T *)chartInstance->c28_T_us4)[24] = c28_b_T_us4.rr;
  *(real_T *)&((char_T *)chartInstance->c28_delta_w4)[0] = c28_b_delta_w4.fl;
  *(real_T *)&((char_T *)chartInstance->c28_delta_w4)[8] = c28_b_delta_w4.fr;
  *(real_T *)&((char_T *)chartInstance->c28_delta_w4)[16] = c28_b_delta_w4.rl;
  *(real_T *)&((char_T *)chartInstance->c28_delta_w4)[24] = c28_b_delta_w4.rr;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 18U, chartInstance->c28_sfEvent);
}

static void initSimStructsc28_AllPurposeModel_TyreRelaxation
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c28_machineNumber, uint32_T
  c28_chartNumber, uint32_T c28_instanceNumber)
{
  (void)c28_machineNumber;
  (void)c28_chartNumber;
  (void)c28_instanceNumber;
}

static const mxArray *c28_sf_marshallOut(void *chartInstanceVoid, void
  *c28_inData)
{
  const mxArray *c28_mxArrayOutData = NULL;
  c28_whl_vec4 c28_u;
  const mxArray *c28_y = NULL;
  real_T c28_b_u;
  const mxArray *c28_b_y = NULL;
  real_T c28_c_u;
  const mxArray *c28_c_y = NULL;
  real_T c28_d_u;
  const mxArray *c28_d_y = NULL;
  real_T c28_e_u;
  const mxArray *c28_e_y = NULL;
  SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c28_mxArrayOutData = NULL;
  c28_u = *(c28_whl_vec4 *)c28_inData;
  c28_y = NULL;
  sf_mex_assign(&c28_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c28_b_u = c28_u.fl;
  c28_b_y = NULL;
  sf_mex_assign(&c28_b_y, sf_mex_create("y", &c28_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c28_y, c28_b_y, "fl", "fl", 0);
  c28_c_u = c28_u.fr;
  c28_c_y = NULL;
  sf_mex_assign(&c28_c_y, sf_mex_create("y", &c28_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c28_y, c28_c_y, "fr", "fr", 0);
  c28_d_u = c28_u.rl;
  c28_d_y = NULL;
  sf_mex_assign(&c28_d_y, sf_mex_create("y", &c28_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c28_y, c28_d_y, "rl", "rl", 0);
  c28_e_u = c28_u.rr;
  c28_e_y = NULL;
  sf_mex_assign(&c28_e_y, sf_mex_create("y", &c28_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c28_y, c28_e_y, "rr", "rr", 0);
  sf_mex_assign(&c28_mxArrayOutData, c28_y, false);
  return c28_mxArrayOutData;
}

static c28_whl_vec4 c28_emlrt_marshallIn
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c28_b_delta_w4, const char_T *c28_identifier)
{
  c28_whl_vec4 c28_y;
  emlrtMsgIdentifier c28_thisId;
  c28_thisId.fIdentifier = c28_identifier;
  c28_thisId.fParent = NULL;
  c28_y = c28_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c28_b_delta_w4),
    &c28_thisId);
  sf_mex_destroy(&c28_b_delta_w4);
  return c28_y;
}

static c28_whl_vec4 c28_b_emlrt_marshallIn
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId)
{
  c28_whl_vec4 c28_y;
  emlrtMsgIdentifier c28_thisId;
  static const char * c28_fieldNames[4] = { "fl", "fr", "rl", "rr" };

  c28_thisId.fParent = c28_parentId;
  sf_mex_check_struct(c28_parentId, c28_u, 4, c28_fieldNames, 0U, NULL);
  c28_thisId.fIdentifier = "fl";
  c28_y.fl = c28_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c28_u, "fl", "fl", 0)), &c28_thisId);
  c28_thisId.fIdentifier = "fr";
  c28_y.fr = c28_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c28_u, "fr", "fr", 0)), &c28_thisId);
  c28_thisId.fIdentifier = "rl";
  c28_y.rl = c28_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c28_u, "rl", "rl", 0)), &c28_thisId);
  c28_thisId.fIdentifier = "rr";
  c28_y.rr = c28_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c28_u, "rr", "rr", 0)), &c28_thisId);
  sf_mex_destroy(&c28_u);
  return c28_y;
}

static real_T c28_c_emlrt_marshallIn
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId)
{
  real_T c28_y;
  real_T c28_d0;
  (void)chartInstance;
  sf_mex_import(c28_parentId, sf_mex_dup(c28_u), &c28_d0, 1, 0, 0U, 0, 0U, 0);
  c28_y = c28_d0;
  sf_mex_destroy(&c28_u);
  return c28_y;
}

static void c28_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c28_mxArrayInData, const char_T *c28_varName, void *c28_outData)
{
  const mxArray *c28_b_delta_w4;
  const char_T *c28_identifier;
  emlrtMsgIdentifier c28_thisId;
  c28_whl_vec4 c28_y;
  SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c28_b_delta_w4 = sf_mex_dup(c28_mxArrayInData);
  c28_identifier = c28_varName;
  c28_thisId.fIdentifier = c28_identifier;
  c28_thisId.fParent = NULL;
  c28_y = c28_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c28_b_delta_w4),
    &c28_thisId);
  sf_mex_destroy(&c28_b_delta_w4);
  *(c28_whl_vec4 *)c28_outData = c28_y;
  sf_mex_destroy(&c28_mxArrayInData);
}

static const mxArray *c28_b_sf_marshallOut(void *chartInstanceVoid, void
  *c28_inData)
{
  const mxArray *c28_mxArrayOutData;
  c28_struct_iBlsPBO3AGnt69vDoTx5zD c28_u;
  const mxArray *c28_y = NULL;
  c28_struct_Nst2vGTExxHsg85EUOj9EH c28_b_u;
  const mxArray *c28_b_y = NULL;
  real_T c28_c_u;
  const mxArray *c28_c_y = NULL;
  c28_struct_HhckT6rntEraqECYVIDvCC c28_d_u;
  const mxArray *c28_d_y = NULL;
  real_T c28_e_u;
  const mxArray *c28_e_y = NULL;
  real_T c28_f_u;
  const mxArray *c28_f_y = NULL;
  const mxArray *c28_g_y = NULL;
  real_T c28_g_u;
  const mxArray *c28_h_y = NULL;
  real_T c28_h_u;
  const mxArray *c28_i_y = NULL;
  const mxArray *c28_j_y = NULL;
  real_T c28_i_u;
  const mxArray *c28_k_y = NULL;
  real_T c28_j_u;
  const mxArray *c28_l_y = NULL;
  const mxArray *c28_m_y = NULL;
  real_T c28_k_u;
  const mxArray *c28_n_y = NULL;
  real_T c28_l_u;
  const mxArray *c28_o_y = NULL;
  const mxArray *c28_p_y = NULL;
  real_T c28_m_u;
  const mxArray *c28_q_y = NULL;
  real_T c28_n_u;
  const mxArray *c28_r_y = NULL;
  real_T c28_o_u;
  const mxArray *c28_s_y = NULL;
  c28_struct_ZCmOWPuqBDw16FSOVVD00 c28_p_u;
  const mxArray *c28_t_y = NULL;
  real_T c28_q_u;
  const mxArray *c28_u_y = NULL;
  real_T c28_r_u;
  const mxArray *c28_v_y = NULL;
  real_T c28_s_u;
  const mxArray *c28_w_y = NULL;
  real_T c28_t_u;
  const mxArray *c28_x_y = NULL;
  real_T c28_u_u;
  const mxArray *c28_y_y = NULL;
  real_T c28_v_u;
  const mxArray *c28_ab_y = NULL;
  real_T c28_w_u;
  const mxArray *c28_bb_y = NULL;
  real_T c28_x_u;
  const mxArray *c28_cb_y = NULL;
  real_T c28_y_u;
  const mxArray *c28_db_y = NULL;
  real_T c28_ab_u;
  const mxArray *c28_eb_y = NULL;
  real_T c28_bb_u;
  const mxArray *c28_fb_y = NULL;
  int32_T c28_i18;
  real_T c28_cb_u[4];
  const mxArray *c28_gb_y = NULL;
  real_T c28_db_u;
  const mxArray *c28_hb_y = NULL;
  c28_struct_ZKAzdrl7umDGJoC14aoVKC c28_eb_u;
  const mxArray *c28_ib_y = NULL;
  int32_T c28_i19;
  real_T c28_fb_u[3];
  const mxArray *c28_jb_y = NULL;
  int32_T c28_i20;
  real_T c28_gb_u[3];
  const mxArray *c28_kb_y = NULL;
  int32_T c28_i21;
  real_T c28_hb_u[3];
  const mxArray *c28_lb_y = NULL;
  int32_T c28_i22;
  real_T c28_ib_u[3];
  const mxArray *c28_mb_y = NULL;
  const mxArray *c28_nb_y = NULL;
  int32_T c28_i23;
  real_T c28_jb_u[3];
  const mxArray *c28_ob_y = NULL;
  int32_T c28_i24;
  real_T c28_kb_u[3];
  const mxArray *c28_pb_y = NULL;
  int32_T c28_i25;
  real_T c28_lb_u[3];
  const mxArray *c28_qb_y = NULL;
  int32_T c28_i26;
  real_T c28_mb_u[3];
  const mxArray *c28_rb_y = NULL;
  const mxArray *c28_sb_y = NULL;
  int32_T c28_i27;
  real_T c28_nb_u[3];
  const mxArray *c28_tb_y = NULL;
  int32_T c28_i28;
  real_T c28_ob_u[3];
  const mxArray *c28_ub_y = NULL;
  int32_T c28_i29;
  real_T c28_pb_u[3];
  const mxArray *c28_vb_y = NULL;
  int32_T c28_i30;
  real_T c28_qb_u[3];
  const mxArray *c28_wb_y = NULL;
  const mxArray *c28_xb_y = NULL;
  int32_T c28_i31;
  real_T c28_rb_u[3];
  const mxArray *c28_yb_y = NULL;
  int32_T c28_i32;
  real_T c28_sb_u[3];
  const mxArray *c28_ac_y = NULL;
  int32_T c28_i33;
  real_T c28_tb_u[3];
  const mxArray *c28_bc_y = NULL;
  int32_T c28_i34;
  real_T c28_ub_u[3];
  const mxArray *c28_cc_y = NULL;
  real_T c28_vb_u;
  const mxArray *c28_dc_y = NULL;
  real_T c28_wb_u;
  const mxArray *c28_ec_y = NULL;
  real_T c28_xb_u;
  const mxArray *c28_fc_y = NULL;
  real_T c28_yb_u;
  const mxArray *c28_gc_y = NULL;
  real_T c28_ac_u;
  const mxArray *c28_hc_y = NULL;
  real_T c28_bc_u;
  const mxArray *c28_ic_y = NULL;
  real_T c28_cc_u;
  const mxArray *c28_jc_y = NULL;
  real_T c28_dc_u;
  const mxArray *c28_kc_y = NULL;
  real_T c28_ec_u;
  const mxArray *c28_lc_y = NULL;
  real_T c28_fc_u;
  const mxArray *c28_mc_y = NULL;
  real_T c28_gc_u;
  const mxArray *c28_nc_y = NULL;
  real_T c28_hc_u;
  const mxArray *c28_oc_y = NULL;
  c28_struct_r4FNviKwHfdhB8nQjvQv9 c28_ic_u;
  const mxArray *c28_pc_y = NULL;
  real_T c28_jc_u;
  const mxArray *c28_qc_y = NULL;
  c28_struct_Y9F1qlBi9AhssksPwemA4G c28_kc_u;
  const mxArray *c28_rc_y = NULL;
  real_T c28_lc_u;
  const mxArray *c28_sc_y = NULL;
  real_T c28_mc_u;
  const mxArray *c28_tc_y = NULL;
  real_T c28_nc_u;
  const mxArray *c28_uc_y = NULL;
  SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c28_mxArrayOutData = NULL;
  c28_mxArrayOutData = NULL;
  c28_u = *(c28_struct_iBlsPBO3AGnt69vDoTx5zD *)c28_inData;
  c28_y = NULL;
  sf_mex_assign(&c28_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c28_b_u = c28_u.Env;
  c28_b_y = NULL;
  sf_mex_assign(&c28_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c28_c_u = c28_b_u.g;
  c28_c_y = NULL;
  sf_mex_assign(&c28_c_y, sf_mex_create("y", &c28_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c28_b_y, c28_c_y, "g", "g", 0);
  c28_d_u = c28_b_u.left1;
  c28_d_y = NULL;
  sf_mex_assign(&c28_d_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c28_e_u = c28_d_u.x;
  c28_e_y = NULL;
  sf_mex_assign(&c28_e_y, sf_mex_create("y", &c28_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c28_d_y, c28_e_y, "x", "x", 0);
  c28_f_u = c28_d_u.y;
  c28_f_y = NULL;
  sf_mex_assign(&c28_f_y, sf_mex_create("y", &c28_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c28_d_y, c28_f_y, "y", "y", 0);
  sf_mex_addfield(c28_b_y, c28_d_y, "left1", "left1", 0);
  c28_d_u = c28_b_u.right1;
  c28_g_y = NULL;
  sf_mex_assign(&c28_g_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c28_g_u = c28_d_u.x;
  c28_h_y = NULL;
  sf_mex_assign(&c28_h_y, sf_mex_create("y", &c28_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c28_g_y, c28_h_y, "x", "x", 0);
  c28_h_u = c28_d_u.y;
  c28_i_y = NULL;
  sf_mex_assign(&c28_i_y, sf_mex_create("y", &c28_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c28_g_y, c28_i_y, "y", "y", 0);
  sf_mex_addfield(c28_b_y, c28_g_y, "right1", "right1", 0);
  c28_d_u = c28_b_u.right2;
  c28_j_y = NULL;
  sf_mex_assign(&c28_j_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c28_i_u = c28_d_u.x;
  c28_k_y = NULL;
  sf_mex_assign(&c28_k_y, sf_mex_create("y", &c28_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c28_j_y, c28_k_y, "x", "x", 0);
  c28_j_u = c28_d_u.y;
  c28_l_y = NULL;
  sf_mex_assign(&c28_l_y, sf_mex_create("y", &c28_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c28_j_y, c28_l_y, "y", "y", 0);
  sf_mex_addfield(c28_b_y, c28_j_y, "right2", "right2", 0);
  c28_d_u = c28_b_u.left2;
  c28_m_y = NULL;
  sf_mex_assign(&c28_m_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c28_k_u = c28_d_u.x;
  c28_n_y = NULL;
  sf_mex_assign(&c28_n_y, sf_mex_create("y", &c28_k_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c28_m_y, c28_n_y, "x", "x", 0);
  c28_l_u = c28_d_u.y;
  c28_o_y = NULL;
  sf_mex_assign(&c28_o_y, sf_mex_create("y", &c28_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c28_m_y, c28_o_y, "y", "y", 0);
  sf_mex_addfield(c28_b_y, c28_m_y, "left2", "left2", 0);
  c28_d_u = c28_b_u.right3;
  c28_p_y = NULL;
  sf_mex_assign(&c28_p_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c28_m_u = c28_d_u.x;
  c28_q_y = NULL;
  sf_mex_assign(&c28_q_y, sf_mex_create("y", &c28_m_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c28_p_y, c28_q_y, "x", "x", 0);
  c28_n_u = c28_d_u.y;
  c28_r_y = NULL;
  sf_mex_assign(&c28_r_y, sf_mex_create("y", &c28_n_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c28_p_y, c28_r_y, "y", "y", 0);
  sf_mex_addfield(c28_b_y, c28_p_y, "right3", "right3", 0);
  c28_o_u = c28_b_u.mu;
  c28_s_y = NULL;
  sf_mex_assign(&c28_s_y, sf_mex_create("y", &c28_o_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c28_b_y, c28_s_y, "mu", "mu", 0);
  sf_mex_addfield(c28_y, c28_b_y, "Env", "Env", 0);
  c28_p_u = c28_u.Veh;
  c28_t_y = NULL;
  sf_mex_assign(&c28_t_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c28_q_u = c28_p_u.m;
  c28_u_y = NULL;
  sf_mex_assign(&c28_u_y, sf_mex_create("y", &c28_q_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c28_t_y, c28_u_y, "m", "m", 0);
  c28_r_u = c28_p_u.Jz;
  c28_v_y = NULL;
  sf_mex_assign(&c28_v_y, sf_mex_create("y", &c28_r_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c28_t_y, c28_v_y, "Jz", "Jz", 0);
  c28_s_u = c28_p_u.m_sprung;
  c28_w_y = NULL;
  sf_mex_assign(&c28_w_y, sf_mex_create("y", &c28_s_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c28_t_y, c28_w_y, "m_sprung", "m_sprung", 0);
  c28_t_u = c28_p_u.Jx_sprung;
  c28_x_y = NULL;
  sf_mex_assign(&c28_x_y, sf_mex_create("y", &c28_t_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c28_t_y, c28_x_y, "Jx_sprung", "Jx_sprung", 0);
  c28_u_u = c28_p_u.Jy_sprung;
  c28_y_y = NULL;
  sf_mex_assign(&c28_y_y, sf_mex_create("y", &c28_u_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c28_t_y, c28_y_y, "Jy_sprung", "Jy_sprung", 0);
  c28_v_u = c28_p_u.lf;
  c28_ab_y = NULL;
  sf_mex_assign(&c28_ab_y, sf_mex_create("y", &c28_v_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c28_t_y, c28_ab_y, "lf", "lf", 0);
  c28_w_u = c28_p_u.lr;
  c28_bb_y = NULL;
  sf_mex_assign(&c28_bb_y, sf_mex_create("y", &c28_w_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c28_t_y, c28_bb_y, "lr", "lr", 0);
  c28_x_u = c28_p_u.L;
  c28_cb_y = NULL;
  sf_mex_assign(&c28_cb_y, sf_mex_create("y", &c28_x_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c28_t_y, c28_cb_y, "L", "L", 0);
  c28_y_u = c28_p_u.TrackWidth;
  c28_db_y = NULL;
  sf_mex_assign(&c28_db_y, sf_mex_create("y", &c28_y_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c28_t_y, c28_db_y, "TrackWidth", "TrackWidth", 0);
  c28_ab_u = c28_p_u.h;
  c28_eb_y = NULL;
  sf_mex_assign(&c28_eb_y, sf_mex_create("y", &c28_ab_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c28_t_y, c28_eb_y, "h", "h", 0);
  c28_bb_u = c28_p_u.HalfRohACd;
  c28_fb_y = NULL;
  sf_mex_assign(&c28_fb_y, sf_mex_create("y", &c28_bb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c28_t_y, c28_fb_y, "HalfRohACd", "HalfRohACd", 0);
  for (c28_i18 = 0; c28_i18 < 4; c28_i18++) {
    c28_cb_u[c28_i18] = c28_p_u.F_z4_static[c28_i18];
  }

  c28_gb_y = NULL;
  sf_mex_assign(&c28_gb_y, sf_mex_create("y", c28_cb_u, 0, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_addfield(c28_t_y, c28_gb_y, "F_z4_static", "F_z4_static", 0);
  c28_db_u = c28_p_u.Rw;
  c28_hb_y = NULL;
  sf_mex_assign(&c28_hb_y, sf_mex_create("y", &c28_db_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c28_t_y, c28_hb_y, "Rw", "Rw", 0);
  c28_eb_u = c28_p_u.r_long;
  c28_ib_y = NULL;
  sf_mex_assign(&c28_ib_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c28_i19 = 0; c28_i19 < 3; c28_i19++) {
    c28_fb_u[c28_i19] = c28_eb_u.fl[c28_i19];
  }

  c28_jb_y = NULL;
  sf_mex_assign(&c28_jb_y, sf_mex_create("y", c28_fb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c28_ib_y, c28_jb_y, "fl", "fl", 0);
  for (c28_i20 = 0; c28_i20 < 3; c28_i20++) {
    c28_gb_u[c28_i20] = c28_eb_u.fr[c28_i20];
  }

  c28_kb_y = NULL;
  sf_mex_assign(&c28_kb_y, sf_mex_create("y", c28_gb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c28_ib_y, c28_kb_y, "fr", "fr", 0);
  for (c28_i21 = 0; c28_i21 < 3; c28_i21++) {
    c28_hb_u[c28_i21] = c28_eb_u.rl[c28_i21];
  }

  c28_lb_y = NULL;
  sf_mex_assign(&c28_lb_y, sf_mex_create("y", c28_hb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c28_ib_y, c28_lb_y, "rl", "rl", 0);
  for (c28_i22 = 0; c28_i22 < 3; c28_i22++) {
    c28_ib_u[c28_i22] = c28_eb_u.rr[c28_i22];
  }

  c28_mb_y = NULL;
  sf_mex_assign(&c28_mb_y, sf_mex_create("y", c28_ib_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c28_ib_y, c28_mb_y, "rr", "rr", 0);
  sf_mex_addfield(c28_t_y, c28_ib_y, "r_long", "r_long", 0);
  c28_eb_u = c28_p_u.r_lat;
  c28_nb_y = NULL;
  sf_mex_assign(&c28_nb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c28_i23 = 0; c28_i23 < 3; c28_i23++) {
    c28_jb_u[c28_i23] = c28_eb_u.fl[c28_i23];
  }

  c28_ob_y = NULL;
  sf_mex_assign(&c28_ob_y, sf_mex_create("y", c28_jb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c28_nb_y, c28_ob_y, "fl", "fl", 0);
  for (c28_i24 = 0; c28_i24 < 3; c28_i24++) {
    c28_kb_u[c28_i24] = c28_eb_u.fr[c28_i24];
  }

  c28_pb_y = NULL;
  sf_mex_assign(&c28_pb_y, sf_mex_create("y", c28_kb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c28_nb_y, c28_pb_y, "fr", "fr", 0);
  for (c28_i25 = 0; c28_i25 < 3; c28_i25++) {
    c28_lb_u[c28_i25] = c28_eb_u.rl[c28_i25];
  }

  c28_qb_y = NULL;
  sf_mex_assign(&c28_qb_y, sf_mex_create("y", c28_lb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c28_nb_y, c28_qb_y, "rl", "rl", 0);
  for (c28_i26 = 0; c28_i26 < 3; c28_i26++) {
    c28_mb_u[c28_i26] = c28_eb_u.rr[c28_i26];
  }

  c28_rb_y = NULL;
  sf_mex_assign(&c28_rb_y, sf_mex_create("y", c28_mb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c28_nb_y, c28_rb_y, "rr", "rr", 0);
  sf_mex_addfield(c28_t_y, c28_nb_y, "r_lat", "r_lat", 0);
  c28_eb_u = c28_p_u.r_lever;
  c28_sb_y = NULL;
  sf_mex_assign(&c28_sb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c28_i27 = 0; c28_i27 < 3; c28_i27++) {
    c28_nb_u[c28_i27] = c28_eb_u.fl[c28_i27];
  }

  c28_tb_y = NULL;
  sf_mex_assign(&c28_tb_y, sf_mex_create("y", c28_nb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c28_sb_y, c28_tb_y, "fl", "fl", 0);
  for (c28_i28 = 0; c28_i28 < 3; c28_i28++) {
    c28_ob_u[c28_i28] = c28_eb_u.fr[c28_i28];
  }

  c28_ub_y = NULL;
  sf_mex_assign(&c28_ub_y, sf_mex_create("y", c28_ob_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c28_sb_y, c28_ub_y, "fr", "fr", 0);
  for (c28_i29 = 0; c28_i29 < 3; c28_i29++) {
    c28_pb_u[c28_i29] = c28_eb_u.rl[c28_i29];
  }

  c28_vb_y = NULL;
  sf_mex_assign(&c28_vb_y, sf_mex_create("y", c28_pb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c28_sb_y, c28_vb_y, "rl", "rl", 0);
  for (c28_i30 = 0; c28_i30 < 3; c28_i30++) {
    c28_qb_u[c28_i30] = c28_eb_u.rr[c28_i30];
  }

  c28_wb_y = NULL;
  sf_mex_assign(&c28_wb_y, sf_mex_create("y", c28_qb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c28_sb_y, c28_wb_y, "rr", "rr", 0);
  sf_mex_addfield(c28_t_y, c28_sb_y, "r_lever", "r_lever", 0);
  c28_eb_u = c28_p_u.r_pivot;
  c28_xb_y = NULL;
  sf_mex_assign(&c28_xb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c28_i31 = 0; c28_i31 < 3; c28_i31++) {
    c28_rb_u[c28_i31] = c28_eb_u.fl[c28_i31];
  }

  c28_yb_y = NULL;
  sf_mex_assign(&c28_yb_y, sf_mex_create("y", c28_rb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c28_xb_y, c28_yb_y, "fl", "fl", 0);
  for (c28_i32 = 0; c28_i32 < 3; c28_i32++) {
    c28_sb_u[c28_i32] = c28_eb_u.fr[c28_i32];
  }

  c28_ac_y = NULL;
  sf_mex_assign(&c28_ac_y, sf_mex_create("y", c28_sb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c28_xb_y, c28_ac_y, "fr", "fr", 0);
  for (c28_i33 = 0; c28_i33 < 3; c28_i33++) {
    c28_tb_u[c28_i33] = c28_eb_u.rl[c28_i33];
  }

  c28_bc_y = NULL;
  sf_mex_assign(&c28_bc_y, sf_mex_create("y", c28_tb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c28_xb_y, c28_bc_y, "rl", "rl", 0);
  for (c28_i34 = 0; c28_i34 < 3; c28_i34++) {
    c28_ub_u[c28_i34] = c28_eb_u.rr[c28_i34];
  }

  c28_cc_y = NULL;
  sf_mex_assign(&c28_cc_y, sf_mex_create("y", c28_ub_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c28_xb_y, c28_cc_y, "rr", "rr", 0);
  sf_mex_addfield(c28_t_y, c28_xb_y, "r_pivot", "r_pivot", 0);
  c28_vb_u = c28_p_u.cw;
  c28_dc_y = NULL;
  sf_mex_assign(&c28_dc_y, sf_mex_create("y", &c28_vb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c28_t_y, c28_dc_y, "cw", "cw", 0);
  c28_wb_u = c28_p_u.carb_f;
  c28_ec_y = NULL;
  sf_mex_assign(&c28_ec_y, sf_mex_create("y", &c28_wb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c28_t_y, c28_ec_y, "carb_f", "carb_f", 0);
  c28_xb_u = c28_p_u.carb_r;
  c28_fc_y = NULL;
  sf_mex_assign(&c28_fc_y, sf_mex_create("y", &c28_xb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c28_t_y, c28_fc_y, "carb_r", "carb_r", 0);
  c28_yb_u = c28_p_u.dw;
  c28_gc_y = NULL;
  sf_mex_assign(&c28_gc_y, sf_mex_create("y", &c28_yb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c28_t_y, c28_gc_y, "dw", "dw", 0);
  c28_ac_u = c28_p_u.Jw;
  c28_hc_y = NULL;
  sf_mex_assign(&c28_hc_y, sf_mex_create("y", &c28_ac_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c28_t_y, c28_hc_y, "Jw", "Jw", 0);
  c28_bc_u = c28_p_u.C0;
  c28_ic_y = NULL;
  sf_mex_assign(&c28_ic_y, sf_mex_create("y", &c28_bc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c28_t_y, c28_ic_y, "C0", "C0", 0);
  c28_cc_u = c28_p_u.RelaxLength;
  c28_jc_y = NULL;
  sf_mex_assign(&c28_jc_y, sf_mex_create("y", &c28_cc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c28_t_y, c28_jc_y, "RelaxLength", "RelaxLength", 0);
  c28_dc_u = c28_p_u.RRC;
  c28_kc_y = NULL;
  sf_mex_assign(&c28_kc_y, sf_mex_create("y", &c28_dc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c28_t_y, c28_kc_y, "RRC", "RRC", 0);
  c28_ec_u = c28_p_u.Pmax;
  c28_lc_y = NULL;
  sf_mex_assign(&c28_lc_y, sf_mex_create("y", &c28_ec_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c28_t_y, c28_lc_y, "Pmax", "Pmax", 0);
  c28_fc_u = c28_p_u.PropDistrFrnt;
  c28_mc_y = NULL;
  sf_mex_assign(&c28_mc_y, sf_mex_create("y", &c28_fc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c28_t_y, c28_mc_y, "PropDistrFrnt", "PropDistrFrnt", 0);
  c28_gc_u = c28_p_u.BrkDistrFrnt;
  c28_nc_y = NULL;
  sf_mex_assign(&c28_nc_y, sf_mex_create("y", &c28_gc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c28_t_y, c28_nc_y, "BrkDistrFrnt", "BrkDistrFrnt", 0);
  c28_hc_u = c28_p_u.SteRatio;
  c28_oc_y = NULL;
  sf_mex_assign(&c28_oc_y, sf_mex_create("y", &c28_hc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c28_t_y, c28_oc_y, "SteRatio", "SteRatio", 0);
  sf_mex_addfield(c28_y, c28_t_y, "Veh", "Veh", 0);
  c28_ic_u = c28_u.Drvr;
  c28_pc_y = NULL;
  sf_mex_assign(&c28_pc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c28_jc_u = c28_ic_u.v_set;
  c28_qc_y = NULL;
  sf_mex_assign(&c28_qc_y, sf_mex_create("y", &c28_jc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c28_pc_y, c28_qc_y, "v_set", "v_set", 0);
  sf_mex_addfield(c28_y, c28_pc_y, "Drvr", "Drvr", 0);
  c28_kc_u = c28_u.Init;
  c28_rc_y = NULL;
  sf_mex_assign(&c28_rc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c28_lc_u = c28_kc_u.v_x;
  c28_sc_y = NULL;
  sf_mex_assign(&c28_sc_y, sf_mex_create("y", &c28_lc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c28_rc_y, c28_sc_y, "v_x", "v_x", 0);
  c28_mc_u = c28_kc_u.F_fz;
  c28_tc_y = NULL;
  sf_mex_assign(&c28_tc_y, sf_mex_create("y", &c28_mc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c28_rc_y, c28_tc_y, "F_fz", "F_fz", 0);
  c28_nc_u = c28_kc_u.F_rz;
  c28_uc_y = NULL;
  sf_mex_assign(&c28_uc_y, sf_mex_create("y", &c28_nc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c28_rc_y, c28_uc_y, "F_rz", "F_rz", 0);
  sf_mex_addfield(c28_y, c28_rc_y, "Init", "Init", 0);
  sf_mex_assign(&c28_mxArrayOutData, c28_y, false);
  return c28_mxArrayOutData;
}

static void c28_d_emlrt_marshallIn
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId,
   c28_struct_iBlsPBO3AGnt69vDoTx5zD *c28_y)
{
  emlrtMsgIdentifier c28_thisId;
  static const char * c28_fieldNames[4] = { "Env", "Veh", "Drvr", "Init" };

  c28_thisId.fParent = c28_parentId;
  sf_mex_check_struct(c28_parentId, c28_u, 4, c28_fieldNames, 0U, NULL);
  c28_thisId.fIdentifier = "Env";
  c28_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c28_u, "Env",
    "Env", 0)), &c28_thisId, &c28_y->Env);
  c28_thisId.fIdentifier = "Veh";
  c28_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c28_u, "Veh",
    "Veh", 0)), &c28_thisId, &c28_y->Veh);
  c28_thisId.fIdentifier = "Drvr";
  c28_y->Drvr = c28_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c28_u, "Drvr", "Drvr", 0)), &c28_thisId);
  c28_thisId.fIdentifier = "Init";
  c28_y->Init = c28_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c28_u, "Init", "Init", 0)), &c28_thisId);
  sf_mex_destroy(&c28_u);
}

static void c28_e_emlrt_marshallIn
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId,
   c28_struct_Nst2vGTExxHsg85EUOj9EH *c28_y)
{
  emlrtMsgIdentifier c28_thisId;
  static const char * c28_fieldNames[7] = { "g", "left1", "right1", "right2",
    "left2", "right3", "mu" };

  c28_thisId.fParent = c28_parentId;
  sf_mex_check_struct(c28_parentId, c28_u, 7, c28_fieldNames, 0U, NULL);
  c28_thisId.fIdentifier = "g";
  c28_y->g = c28_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c28_u, "g", "g", 0)), &c28_thisId);
  c28_thisId.fIdentifier = "left1";
  c28_y->left1 = c28_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c28_u, "left1", "left1", 0)), &c28_thisId);
  c28_thisId.fIdentifier = "right1";
  c28_y->right1 = c28_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c28_u, "right1", "right1", 0)), &c28_thisId);
  c28_thisId.fIdentifier = "right2";
  c28_y->right2 = c28_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c28_u, "right2", "right2", 0)), &c28_thisId);
  c28_thisId.fIdentifier = "left2";
  c28_y->left2 = c28_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c28_u, "left2", "left2", 0)), &c28_thisId);
  c28_thisId.fIdentifier = "right3";
  c28_y->right3 = c28_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c28_u, "right3", "right3", 0)), &c28_thisId);
  c28_thisId.fIdentifier = "mu";
  c28_y->mu = c28_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c28_u, "mu", "mu", 0)), &c28_thisId);
  sf_mex_destroy(&c28_u);
}

static c28_struct_HhckT6rntEraqECYVIDvCC c28_f_emlrt_marshallIn
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId)
{
  c28_struct_HhckT6rntEraqECYVIDvCC c28_y;
  emlrtMsgIdentifier c28_thisId;
  static const char * c28_fieldNames[2] = { "x", "y" };

  c28_thisId.fParent = c28_parentId;
  sf_mex_check_struct(c28_parentId, c28_u, 2, c28_fieldNames, 0U, NULL);
  c28_thisId.fIdentifier = "x";
  c28_y.x = c28_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c28_u, "x", "x", 0)), &c28_thisId);
  c28_thisId.fIdentifier = "y";
  c28_y.y = c28_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c28_u, "y", "y", 0)), &c28_thisId);
  sf_mex_destroy(&c28_u);
  return c28_y;
}

static void c28_g_emlrt_marshallIn
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId,
   c28_struct_ZCmOWPuqBDw16FSOVVD00 *c28_y)
{
  emlrtMsgIdentifier c28_thisId;
  static const char * c28_fieldNames[29] = { "m", "Jz", "m_sprung", "Jx_sprung",
    "Jy_sprung", "lf", "lr", "L", "TrackWidth", "h", "HalfRohACd", "F_z4_static",
    "Rw", "r_long", "r_lat", "r_lever", "r_pivot", "cw", "carb_f", "carb_r",
    "dw", "Jw", "C0", "RelaxLength", "RRC", "Pmax", "PropDistrFrnt",
    "BrkDistrFrnt", "SteRatio" };

  c28_thisId.fParent = c28_parentId;
  sf_mex_check_struct(c28_parentId, c28_u, 29, c28_fieldNames, 0U, NULL);
  c28_thisId.fIdentifier = "m";
  c28_y->m = c28_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c28_u, "m", "m", 0)), &c28_thisId);
  c28_thisId.fIdentifier = "Jz";
  c28_y->Jz = c28_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c28_u, "Jz", "Jz", 0)), &c28_thisId);
  c28_thisId.fIdentifier = "m_sprung";
  c28_y->m_sprung = c28_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c28_u, "m_sprung", "m_sprung", 0)), &c28_thisId);
  c28_thisId.fIdentifier = "Jx_sprung";
  c28_y->Jx_sprung = c28_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c28_u, "Jx_sprung", "Jx_sprung", 0)), &c28_thisId);
  c28_thisId.fIdentifier = "Jy_sprung";
  c28_y->Jy_sprung = c28_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c28_u, "Jy_sprung", "Jy_sprung", 0)), &c28_thisId);
  c28_thisId.fIdentifier = "lf";
  c28_y->lf = c28_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c28_u, "lf", "lf", 0)), &c28_thisId);
  c28_thisId.fIdentifier = "lr";
  c28_y->lr = c28_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c28_u, "lr", "lr", 0)), &c28_thisId);
  c28_thisId.fIdentifier = "L";
  c28_y->L = c28_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c28_u, "L", "L", 0)), &c28_thisId);
  c28_thisId.fIdentifier = "TrackWidth";
  c28_y->TrackWidth = c28_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c28_u, "TrackWidth", "TrackWidth", 0)), &c28_thisId);
  c28_thisId.fIdentifier = "h";
  c28_y->h = c28_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c28_u, "h", "h", 0)), &c28_thisId);
  c28_thisId.fIdentifier = "HalfRohACd";
  c28_y->HalfRohACd = c28_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c28_u, "HalfRohACd", "HalfRohACd", 0)), &c28_thisId);
  c28_thisId.fIdentifier = "F_z4_static";
  c28_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c28_u,
    "F_z4_static", "F_z4_static", 0)), &c28_thisId, c28_y->F_z4_static);
  c28_thisId.fIdentifier = "Rw";
  c28_y->Rw = c28_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c28_u, "Rw", "Rw", 0)), &c28_thisId);
  c28_thisId.fIdentifier = "r_long";
  c28_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c28_u,
    "r_long", "r_long", 0)), &c28_thisId, &c28_y->r_long);
  c28_thisId.fIdentifier = "r_lat";
  c28_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c28_u,
    "r_lat", "r_lat", 0)), &c28_thisId, &c28_y->r_lat);
  c28_thisId.fIdentifier = "r_lever";
  c28_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c28_u,
    "r_lever", "r_lever", 0)), &c28_thisId, &c28_y->r_lever);
  c28_thisId.fIdentifier = "r_pivot";
  c28_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c28_u,
    "r_pivot", "r_pivot", 0)), &c28_thisId, &c28_y->r_pivot);
  c28_thisId.fIdentifier = "cw";
  c28_y->cw = c28_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c28_u, "cw", "cw", 0)), &c28_thisId);
  c28_thisId.fIdentifier = "carb_f";
  c28_y->carb_f = c28_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c28_u, "carb_f", "carb_f", 0)), &c28_thisId);
  c28_thisId.fIdentifier = "carb_r";
  c28_y->carb_r = c28_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c28_u, "carb_r", "carb_r", 0)), &c28_thisId);
  c28_thisId.fIdentifier = "dw";
  c28_y->dw = c28_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c28_u, "dw", "dw", 0)), &c28_thisId);
  c28_thisId.fIdentifier = "Jw";
  c28_y->Jw = c28_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c28_u, "Jw", "Jw", 0)), &c28_thisId);
  c28_thisId.fIdentifier = "C0";
  c28_y->C0 = c28_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c28_u, "C0", "C0", 0)), &c28_thisId);
  c28_thisId.fIdentifier = "RelaxLength";
  c28_y->RelaxLength = c28_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c28_u, "RelaxLength", "RelaxLength", 0)), &c28_thisId);
  c28_thisId.fIdentifier = "RRC";
  c28_y->RRC = c28_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c28_u, "RRC", "RRC", 0)), &c28_thisId);
  c28_thisId.fIdentifier = "Pmax";
  c28_y->Pmax = c28_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c28_u, "Pmax", "Pmax", 0)), &c28_thisId);
  c28_thisId.fIdentifier = "PropDistrFrnt";
  c28_y->PropDistrFrnt = c28_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c28_u, "PropDistrFrnt", "PropDistrFrnt", 0)), &c28_thisId);
  c28_thisId.fIdentifier = "BrkDistrFrnt";
  c28_y->BrkDistrFrnt = c28_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c28_u, "BrkDistrFrnt", "BrkDistrFrnt", 0)), &c28_thisId);
  c28_thisId.fIdentifier = "SteRatio";
  c28_y->SteRatio = c28_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c28_u, "SteRatio", "SteRatio", 0)), &c28_thisId);
  sf_mex_destroy(&c28_u);
}

static void c28_h_emlrt_marshallIn
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId, real_T c28_y[4])
{
  real_T c28_dv0[4];
  int32_T c28_i35;
  (void)chartInstance;
  sf_mex_import(c28_parentId, sf_mex_dup(c28_u), c28_dv0, 1, 0, 0U, 1, 0U, 2, 1,
                4);
  for (c28_i35 = 0; c28_i35 < 4; c28_i35++) {
    c28_y[c28_i35] = c28_dv0[c28_i35];
  }

  sf_mex_destroy(&c28_u);
}

static void c28_i_emlrt_marshallIn
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId,
   c28_struct_ZKAzdrl7umDGJoC14aoVKC *c28_y)
{
  emlrtMsgIdentifier c28_thisId;
  static const char * c28_fieldNames[4] = { "fl", "fr", "rl", "rr" };

  c28_thisId.fParent = c28_parentId;
  sf_mex_check_struct(c28_parentId, c28_u, 4, c28_fieldNames, 0U, NULL);
  c28_thisId.fIdentifier = "fl";
  c28_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c28_u, "fl",
    "fl", 0)), &c28_thisId, c28_y->fl);
  c28_thisId.fIdentifier = "fr";
  c28_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c28_u, "fr",
    "fr", 0)), &c28_thisId, c28_y->fr);
  c28_thisId.fIdentifier = "rl";
  c28_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c28_u, "rl",
    "rl", 0)), &c28_thisId, c28_y->rl);
  c28_thisId.fIdentifier = "rr";
  c28_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c28_u, "rr",
    "rr", 0)), &c28_thisId, c28_y->rr);
  sf_mex_destroy(&c28_u);
}

static void c28_j_emlrt_marshallIn
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId, real_T c28_y[3])
{
  real_T c28_dv1[3];
  int32_T c28_i36;
  (void)chartInstance;
  sf_mex_import(c28_parentId, sf_mex_dup(c28_u), c28_dv1, 1, 0, 0U, 1, 0U, 2, 3,
                1);
  for (c28_i36 = 0; c28_i36 < 3; c28_i36++) {
    c28_y[c28_i36] = c28_dv1[c28_i36];
  }

  sf_mex_destroy(&c28_u);
}

static c28_struct_r4FNviKwHfdhB8nQjvQv9 c28_k_emlrt_marshallIn
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId)
{
  c28_struct_r4FNviKwHfdhB8nQjvQv9 c28_y;
  emlrtMsgIdentifier c28_thisId;
  static const char * c28_fieldNames[1] = { "v_set" };

  c28_thisId.fParent = c28_parentId;
  sf_mex_check_struct(c28_parentId, c28_u, 1, c28_fieldNames, 0U, NULL);
  c28_thisId.fIdentifier = "v_set";
  c28_y.v_set = c28_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c28_u, "v_set", "v_set", 0)),
    &c28_thisId);
  sf_mex_destroy(&c28_u);
  return c28_y;
}

static c28_struct_Y9F1qlBi9AhssksPwemA4G c28_l_emlrt_marshallIn
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId)
{
  c28_struct_Y9F1qlBi9AhssksPwemA4G c28_y;
  emlrtMsgIdentifier c28_thisId;
  static const char * c28_fieldNames[3] = { "v_x", "F_fz", "F_rz" };

  c28_thisId.fParent = c28_parentId;
  sf_mex_check_struct(c28_parentId, c28_u, 3, c28_fieldNames, 0U, NULL);
  c28_thisId.fIdentifier = "v_x";
  c28_y.v_x = c28_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c28_u, "v_x", "v_x", 0)), &c28_thisId);
  c28_thisId.fIdentifier = "F_fz";
  c28_y.F_fz = c28_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c28_u, "F_fz", "F_fz", 0)), &c28_thisId);
  c28_thisId.fIdentifier = "F_rz";
  c28_y.F_rz = c28_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c28_u, "F_rz", "F_rz", 0)), &c28_thisId);
  sf_mex_destroy(&c28_u);
  return c28_y;
}

static void c28_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c28_mxArrayInData, const char_T *c28_varName, void *c28_outData)
{
  const mxArray *c28_b_Par;
  const char_T *c28_identifier;
  emlrtMsgIdentifier c28_thisId;
  c28_struct_iBlsPBO3AGnt69vDoTx5zD c28_y;
  SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c28_b_Par = sf_mex_dup(c28_mxArrayInData);
  c28_identifier = c28_varName;
  c28_thisId.fIdentifier = c28_identifier;
  c28_thisId.fParent = NULL;
  c28_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c28_b_Par), &c28_thisId,
    &c28_y);
  sf_mex_destroy(&c28_b_Par);
  *(c28_struct_iBlsPBO3AGnt69vDoTx5zD *)c28_outData = c28_y;
  sf_mex_destroy(&c28_mxArrayInData);
}

static const mxArray *c28_c_sf_marshallOut(void *chartInstanceVoid, void
  *c28_inData)
{
  const mxArray *c28_mxArrayOutData = NULL;
  real_T c28_u;
  const mxArray *c28_y = NULL;
  SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c28_mxArrayOutData = NULL;
  c28_u = *(real_T *)c28_inData;
  c28_y = NULL;
  sf_mex_assign(&c28_y, sf_mex_create("y", &c28_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c28_mxArrayOutData, c28_y, false);
  return c28_mxArrayOutData;
}

static void c28_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c28_mxArrayInData, const char_T *c28_varName, void *c28_outData)
{
  const mxArray *c28_nargout;
  const char_T *c28_identifier;
  emlrtMsgIdentifier c28_thisId;
  real_T c28_y;
  SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c28_nargout = sf_mex_dup(c28_mxArrayInData);
  c28_identifier = c28_varName;
  c28_thisId.fIdentifier = c28_identifier;
  c28_thisId.fParent = NULL;
  c28_y = c28_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c28_nargout),
    &c28_thisId);
  sf_mex_destroy(&c28_nargout);
  *(real_T *)c28_outData = c28_y;
  sf_mex_destroy(&c28_mxArrayInData);
}

static const mxArray *c28_d_sf_marshallOut(void *chartInstanceVoid, void
  *c28_inData)
{
  const mxArray *c28_mxArrayOutData = NULL;
  int32_T c28_i37;
  real_T c28_b_inData[4];
  int32_T c28_i38;
  real_T c28_u[4];
  const mxArray *c28_y = NULL;
  SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c28_mxArrayOutData = NULL;
  for (c28_i37 = 0; c28_i37 < 4; c28_i37++) {
    c28_b_inData[c28_i37] = (*(real_T (*)[4])c28_inData)[c28_i37];
  }

  for (c28_i38 = 0; c28_i38 < 4; c28_i38++) {
    c28_u[c28_i38] = c28_b_inData[c28_i38];
  }

  c28_y = NULL;
  sf_mex_assign(&c28_y, sf_mex_create("y", c28_u, 0, 0U, 1U, 0U, 2, 1, 4), false);
  sf_mex_assign(&c28_mxArrayOutData, c28_y, false);
  return c28_mxArrayOutData;
}

static void c28_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c28_mxArrayInData, const char_T *c28_varName, void *c28_outData)
{
  const mxArray *c28_delta_w4_temp;
  const char_T *c28_identifier;
  emlrtMsgIdentifier c28_thisId;
  real_T c28_y[4];
  int32_T c28_i39;
  SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c28_delta_w4_temp = sf_mex_dup(c28_mxArrayInData);
  c28_identifier = c28_varName;
  c28_thisId.fIdentifier = c28_identifier;
  c28_thisId.fParent = NULL;
  c28_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c28_delta_w4_temp),
    &c28_thisId, c28_y);
  sf_mex_destroy(&c28_delta_w4_temp);
  for (c28_i39 = 0; c28_i39 < 4; c28_i39++) {
    (*(real_T (*)[4])c28_outData)[c28_i39] = c28_y[c28_i39];
  }

  sf_mex_destroy(&c28_mxArrayInData);
}

const mxArray
  *sf_c28_AllPurposeModel_TyreRelaxation_get_eml_resolved_functions_info(void)
{
  const mxArray *c28_nameCaptureInfo = NULL;
  c28_nameCaptureInfo = NULL;
  sf_mex_assign(&c28_nameCaptureInfo, sf_mex_createstruct("structure", 2, 32, 1),
                false);
  c28_info_helper(&c28_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c28_nameCaptureInfo);
  return c28_nameCaptureInfo;
}

static void c28_info_helper(const mxArray **c28_info)
{
  const mxArray *c28_rhs0 = NULL;
  const mxArray *c28_lhs0 = NULL;
  const mxArray *c28_rhs1 = NULL;
  const mxArray *c28_lhs1 = NULL;
  const mxArray *c28_rhs2 = NULL;
  const mxArray *c28_lhs2 = NULL;
  const mxArray *c28_rhs3 = NULL;
  const mxArray *c28_lhs3 = NULL;
  const mxArray *c28_rhs4 = NULL;
  const mxArray *c28_lhs4 = NULL;
  const mxArray *c28_rhs5 = NULL;
  const mxArray *c28_lhs5 = NULL;
  const mxArray *c28_rhs6 = NULL;
  const mxArray *c28_lhs6 = NULL;
  const mxArray *c28_rhs7 = NULL;
  const mxArray *c28_lhs7 = NULL;
  const mxArray *c28_rhs8 = NULL;
  const mxArray *c28_lhs8 = NULL;
  const mxArray *c28_rhs9 = NULL;
  const mxArray *c28_lhs9 = NULL;
  const mxArray *c28_rhs10 = NULL;
  const mxArray *c28_lhs10 = NULL;
  const mxArray *c28_rhs11 = NULL;
  const mxArray *c28_lhs11 = NULL;
  const mxArray *c28_rhs12 = NULL;
  const mxArray *c28_lhs12 = NULL;
  const mxArray *c28_rhs13 = NULL;
  const mxArray *c28_lhs13 = NULL;
  const mxArray *c28_rhs14 = NULL;
  const mxArray *c28_lhs14 = NULL;
  const mxArray *c28_rhs15 = NULL;
  const mxArray *c28_lhs15 = NULL;
  const mxArray *c28_rhs16 = NULL;
  const mxArray *c28_lhs16 = NULL;
  const mxArray *c28_rhs17 = NULL;
  const mxArray *c28_lhs17 = NULL;
  const mxArray *c28_rhs18 = NULL;
  const mxArray *c28_lhs18 = NULL;
  const mxArray *c28_rhs19 = NULL;
  const mxArray *c28_lhs19 = NULL;
  const mxArray *c28_rhs20 = NULL;
  const mxArray *c28_lhs20 = NULL;
  const mxArray *c28_rhs21 = NULL;
  const mxArray *c28_lhs21 = NULL;
  const mxArray *c28_rhs22 = NULL;
  const mxArray *c28_lhs22 = NULL;
  const mxArray *c28_rhs23 = NULL;
  const mxArray *c28_lhs23 = NULL;
  const mxArray *c28_rhs24 = NULL;
  const mxArray *c28_lhs24 = NULL;
  const mxArray *c28_rhs25 = NULL;
  const mxArray *c28_lhs25 = NULL;
  const mxArray *c28_rhs26 = NULL;
  const mxArray *c28_lhs26 = NULL;
  const mxArray *c28_rhs27 = NULL;
  const mxArray *c28_lhs27 = NULL;
  const mxArray *c28_rhs28 = NULL;
  const mxArray *c28_lhs28 = NULL;
  const mxArray *c28_rhs29 = NULL;
  const mxArray *c28_lhs29 = NULL;
  const mxArray *c28_rhs30 = NULL;
  const mxArray *c28_lhs30 = NULL;
  const mxArray *c28_rhs31 = NULL;
  const mxArray *c28_lhs31 = NULL;
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("mrdivide"), "name", "name",
                  0);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1410807648U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1370009886U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c28_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1389717774U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c28_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("rdivide"), "name", "name", 2);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1363713880U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c28_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c28_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 4);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c28_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("eml_div"), "name", "name", 5);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1386423952U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c28_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 6);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c28_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(""), "context", "context", 7);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("max"), "name", "name", 7);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1311255316U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c28_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 8);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1378295984U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c28_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum"),
                  "context", "context", 9);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("eml_const_nonsingleton_dim"),
                  "name", "name", 9);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1372582416U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c28_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m"),
                  "context", "context", 10);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "coder.internal.constNonSingletonDim"), "name", "name", 10);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/constNonSingletonDim.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1372583160U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c28_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum"),
                  "context", "context", 11);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 11);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 11);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c28_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 12);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 12);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c28_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum"),
                  "context", "context", 13);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 13);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c28_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 14);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 14);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c28_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 15);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("isnan"), "name", "name", 15);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1363713858U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c28_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 16);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c28_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 17);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 17);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 17);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1372582416U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c28_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 18);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 18);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1372583160U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c28_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 19);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 19);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1397257422U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c28_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 20);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("isfi"), "name", "name", 20);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 20);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1346510358U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c28_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("isnumerictype"), "name",
                  "name", 21);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                  "resolved", 21);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1398875598U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c28_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 22);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("intmax"), "name", "name", 22);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1362261882U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c28_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 23);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 23);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1393330858U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c28_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 24);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("intmin"), "name", "name", 24);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 24);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1362261882U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c28_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 25);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 25);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1393330858U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c28_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 26);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("eml_relop"), "name", "name",
                  26);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("function_handle"),
                  "dominantType", "dominantType", 26);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1342451182U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c28_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(""), "context", "context", 27);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 27);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1383877294U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c28_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 28);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 28);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c28_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(""), "context", "context", 29);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("sign"), "name", "name", 29);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m"), "resolved",
                  "resolved", 29);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1363713856U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c28_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m"), "context",
                  "context", 30);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 30);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c28_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m"), "context",
                  "context", 31);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("eml_scalar_sign"), "name",
                  "name", 31);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sign.m"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1356541494U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c28_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs31), "lhs", "lhs",
                  31);
  sf_mex_destroy(&c28_rhs0);
  sf_mex_destroy(&c28_lhs0);
  sf_mex_destroy(&c28_rhs1);
  sf_mex_destroy(&c28_lhs1);
  sf_mex_destroy(&c28_rhs2);
  sf_mex_destroy(&c28_lhs2);
  sf_mex_destroy(&c28_rhs3);
  sf_mex_destroy(&c28_lhs3);
  sf_mex_destroy(&c28_rhs4);
  sf_mex_destroy(&c28_lhs4);
  sf_mex_destroy(&c28_rhs5);
  sf_mex_destroy(&c28_lhs5);
  sf_mex_destroy(&c28_rhs6);
  sf_mex_destroy(&c28_lhs6);
  sf_mex_destroy(&c28_rhs7);
  sf_mex_destroy(&c28_lhs7);
  sf_mex_destroy(&c28_rhs8);
  sf_mex_destroy(&c28_lhs8);
  sf_mex_destroy(&c28_rhs9);
  sf_mex_destroy(&c28_lhs9);
  sf_mex_destroy(&c28_rhs10);
  sf_mex_destroy(&c28_lhs10);
  sf_mex_destroy(&c28_rhs11);
  sf_mex_destroy(&c28_lhs11);
  sf_mex_destroy(&c28_rhs12);
  sf_mex_destroy(&c28_lhs12);
  sf_mex_destroy(&c28_rhs13);
  sf_mex_destroy(&c28_lhs13);
  sf_mex_destroy(&c28_rhs14);
  sf_mex_destroy(&c28_lhs14);
  sf_mex_destroy(&c28_rhs15);
  sf_mex_destroy(&c28_lhs15);
  sf_mex_destroy(&c28_rhs16);
  sf_mex_destroy(&c28_lhs16);
  sf_mex_destroy(&c28_rhs17);
  sf_mex_destroy(&c28_lhs17);
  sf_mex_destroy(&c28_rhs18);
  sf_mex_destroy(&c28_lhs18);
  sf_mex_destroy(&c28_rhs19);
  sf_mex_destroy(&c28_lhs19);
  sf_mex_destroy(&c28_rhs20);
  sf_mex_destroy(&c28_lhs20);
  sf_mex_destroy(&c28_rhs21);
  sf_mex_destroy(&c28_lhs21);
  sf_mex_destroy(&c28_rhs22);
  sf_mex_destroy(&c28_lhs22);
  sf_mex_destroy(&c28_rhs23);
  sf_mex_destroy(&c28_lhs23);
  sf_mex_destroy(&c28_rhs24);
  sf_mex_destroy(&c28_lhs24);
  sf_mex_destroy(&c28_rhs25);
  sf_mex_destroy(&c28_lhs25);
  sf_mex_destroy(&c28_rhs26);
  sf_mex_destroy(&c28_lhs26);
  sf_mex_destroy(&c28_rhs27);
  sf_mex_destroy(&c28_lhs27);
  sf_mex_destroy(&c28_rhs28);
  sf_mex_destroy(&c28_lhs28);
  sf_mex_destroy(&c28_rhs29);
  sf_mex_destroy(&c28_lhs29);
  sf_mex_destroy(&c28_rhs30);
  sf_mex_destroy(&c28_lhs30);
  sf_mex_destroy(&c28_rhs31);
  sf_mex_destroy(&c28_lhs31);
}

static const mxArray *c28_emlrt_marshallOut(const char * c28_u)
{
  const mxArray *c28_y = NULL;
  c28_y = NULL;
  sf_mex_assign(&c28_y, sf_mex_create("y", c28_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c28_u)), false);
  return c28_y;
}

static const mxArray *c28_b_emlrt_marshallOut(const uint32_T c28_u)
{
  const mxArray *c28_y = NULL;
  c28_y = NULL;
  sf_mex_assign(&c28_y, sf_mex_create("y", &c28_u, 7, 0U, 0U, 0U, 0), false);
  return c28_y;
}

static void c28_eml_switch_helper
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c28_check_forloop_overflow_error
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, boolean_T
   c28_overflow)
{
  int32_T c28_i40;
  static char_T c28_cv0[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c28_u[34];
  const mxArray *c28_y = NULL;
  int32_T c28_i41;
  static char_T c28_cv1[5] = { 'i', 'n', 't', '3', '2' };

  char_T c28_b_u[5];
  const mxArray *c28_b_y = NULL;
  (void)chartInstance;
  if (!c28_overflow) {
  } else {
    for (c28_i40 = 0; c28_i40 < 34; c28_i40++) {
      c28_u[c28_i40] = c28_cv0[c28_i40];
    }

    c28_y = NULL;
    sf_mex_assign(&c28_y, sf_mex_create("y", c28_u, 10, 0U, 1U, 0U, 2, 1, 34),
                  false);
    for (c28_i41 = 0; c28_i41 < 5; c28_i41++) {
      c28_b_u[c28_i41] = c28_cv1[c28_i41];
    }

    c28_b_y = NULL;
    sf_mex_assign(&c28_b_y, sf_mex_create("y", c28_b_u, 10, 0U, 1U, 0U, 2, 1, 5),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 2U, 14, c28_y, 14, c28_b_y));
  }
}

static const mxArray *c28_e_sf_marshallOut(void *chartInstanceVoid, void
  *c28_inData)
{
  const mxArray *c28_mxArrayOutData = NULL;
  int32_T c28_u;
  const mxArray *c28_y = NULL;
  SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c28_mxArrayOutData = NULL;
  c28_u = *(int32_T *)c28_inData;
  c28_y = NULL;
  sf_mex_assign(&c28_y, sf_mex_create("y", &c28_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c28_mxArrayOutData, c28_y, false);
  return c28_mxArrayOutData;
}

static int32_T c28_m_emlrt_marshallIn
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId)
{
  int32_T c28_y;
  int32_T c28_i42;
  (void)chartInstance;
  sf_mex_import(c28_parentId, sf_mex_dup(c28_u), &c28_i42, 1, 6, 0U, 0, 0U, 0);
  c28_y = c28_i42;
  sf_mex_destroy(&c28_u);
  return c28_y;
}

static void c28_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c28_mxArrayInData, const char_T *c28_varName, void *c28_outData)
{
  const mxArray *c28_b_sfEvent;
  const char_T *c28_identifier;
  emlrtMsgIdentifier c28_thisId;
  int32_T c28_y;
  SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c28_b_sfEvent = sf_mex_dup(c28_mxArrayInData);
  c28_identifier = c28_varName;
  c28_thisId.fIdentifier = c28_identifier;
  c28_thisId.fParent = NULL;
  c28_y = c28_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c28_b_sfEvent),
    &c28_thisId);
  sf_mex_destroy(&c28_b_sfEvent);
  *(int32_T *)c28_outData = c28_y;
  sf_mex_destroy(&c28_mxArrayInData);
}

static const mxArray *c28_T_s4_bus_io(void *chartInstanceVoid, void *c28_pData)
{
  const mxArray *c28_mxVal = NULL;
  c28_whl_vec4 c28_tmp;
  SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c28_mxVal = NULL;
  c28_tmp.fl = *(real_T *)&((char_T *)(c28_whl_vec4 *)c28_pData)[0];
  c28_tmp.fr = *(real_T *)&((char_T *)(c28_whl_vec4 *)c28_pData)[8];
  c28_tmp.rl = *(real_T *)&((char_T *)(c28_whl_vec4 *)c28_pData)[16];
  c28_tmp.rr = *(real_T *)&((char_T *)(c28_whl_vec4 *)c28_pData)[24];
  sf_mex_assign(&c28_mxVal, c28_sf_marshallOut(chartInstance, &c28_tmp), false);
  return c28_mxVal;
}

static uint8_T c28_n_emlrt_marshallIn
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c28_b_is_active_c28_AllPurposeModel_TyreRelaxation, const char_T
   *c28_identifier)
{
  uint8_T c28_y;
  emlrtMsgIdentifier c28_thisId;
  c28_thisId.fIdentifier = c28_identifier;
  c28_thisId.fParent = NULL;
  c28_y = c28_o_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c28_b_is_active_c28_AllPurposeModel_TyreRelaxation), &c28_thisId);
  sf_mex_destroy(&c28_b_is_active_c28_AllPurposeModel_TyreRelaxation);
  return c28_y;
}

static uint8_T c28_o_emlrt_marshallIn
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId)
{
  uint8_T c28_y;
  uint8_T c28_u0;
  (void)chartInstance;
  sf_mex_import(c28_parentId, sf_mex_dup(c28_u), &c28_u0, 1, 3, 0U, 0, 0U, 0);
  c28_y = c28_u0;
  sf_mex_destroy(&c28_u);
  return c28_y;
}

static void init_dsm_address_info
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address
  (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  chartInstance->c28_T_s4 = (c28_whl_vec4 *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c28_T_us4 = (c28_whl_vec4 *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c28_APed = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c28_BPed = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c28_SteWhlAn = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c28_LongDir = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c28_w_w4_actl = (c28_whl_vec4 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c28_delta_w4 = (c28_whl_vec4 *)ssGetOutputPortSignal_wrapper
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

void sf_c28_AllPurposeModel_TyreRelaxation_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1396661111U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3631693060U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(41370495U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(748691448U);
}

mxArray* sf_c28_AllPurposeModel_TyreRelaxation_get_post_codegen_info(void);
mxArray *sf_c28_AllPurposeModel_TyreRelaxation_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("Mx3l572opQyCoKx9YqxDKH");
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
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
    mxArray* mxPostCodegenInfo =
      sf_c28_AllPurposeModel_TyreRelaxation_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c28_AllPurposeModel_TyreRelaxation_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c28_AllPurposeModel_TyreRelaxation_jit_fallback_info(void)
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

mxArray *sf_c28_AllPurposeModel_TyreRelaxation_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c28_AllPurposeModel_TyreRelaxation_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c28_AllPurposeModel_TyreRelaxation
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[8],T\"T_s4\",},{M[1],M[5],T\"T_us4\",},{M[1],M[20],T\"delta_w4\",},{M[8],M[0],T\"is_active_c28_AllPurposeModel_TyreRelaxation\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c28_AllPurposeModel_TyreRelaxation_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _AllPurposeModel_TyreRelaxationMachineNumber_,
           28,
           1,
           1,
           0,
           9,
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
          _SFD_SET_DATA_PROPS(0,2,0,1,"T_s4");
          _SFD_SET_DATA_PROPS(1,2,0,1,"T_us4");
          _SFD_SET_DATA_PROPS(2,1,1,0,"APed");
          _SFD_SET_DATA_PROPS(3,1,1,0,"BPed");
          _SFD_SET_DATA_PROPS(4,1,1,0,"SteWhlAn");
          _SFD_SET_DATA_PROPS(5,1,1,0,"LongDir");
          _SFD_SET_DATA_PROPS(6,1,1,0,"w_w4_actl");
          _SFD_SET_DATA_PROPS(7,2,0,1,"delta_w4");
          _SFD_SET_DATA_PROPS(8,10,0,0,"Par");
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
        _SFD_CV_INIT_EML(0,1,1,3,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1140);
        _SFD_CV_INIT_EML_IF(0,1,0,186,198,284,463);
        _SFD_CV_INIT_EML_IF(0,1,1,284,301,386,463);
        _SFD_CV_INIT_EML_IF(0,1,2,465,472,602,752);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,189,198,-1,2);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,291,301,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,2,468,472,-1,4);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c28_T_s4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c28_T_s4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c28_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c28_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c28_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c28_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c28_T_s4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c28_T_s4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c28_b_sf_marshallOut,(MexInFcnForType)
          c28_b_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c28_T_s4);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c28_T_us4);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c28_APed);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c28_BPed);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c28_SteWhlAn);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c28_LongDir);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c28_w_w4_actl);
        _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c28_delta_w4);
        _SFD_SET_DATA_VALUE_PTR(8U, &chartInstance->c28_Par);
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
  return "pTAlDARKEQLpBmvyvwFLwB";
}

static void sf_opaque_initialize_c28_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc28_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar)->S,
     0);
  initialize_params_c28_AllPurposeModel_TyreRelaxation
    ((SFc28_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
  initialize_c28_AllPurposeModel_TyreRelaxation
    ((SFc28_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c28_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  enable_c28_AllPurposeModel_TyreRelaxation
    ((SFc28_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c28_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  disable_c28_AllPurposeModel_TyreRelaxation
    ((SFc28_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c28_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  sf_gateway_c28_AllPurposeModel_TyreRelaxation
    ((SFc28_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c28_AllPurposeModel_TyreRelaxation
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c28_AllPurposeModel_TyreRelaxation
    ((SFc28_AllPurposeModel_TyreRelaxationInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c28_AllPurposeModel_TyreRelaxation(SimStruct*
  S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c28_AllPurposeModel_TyreRelaxation
    ((SFc28_AllPurposeModel_TyreRelaxationInstanceStruct*)
     chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c28_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc28_AllPurposeModel_TyreRelaxationInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_AllPurposeModel_TyreRelaxation_optimization_info();
    }

    finalize_c28_AllPurposeModel_TyreRelaxation
      ((SFc28_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc28_AllPurposeModel_TyreRelaxation
    ((SFc28_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c28_AllPurposeModel_TyreRelaxation(SimStruct *S)
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
    initialize_params_c28_AllPurposeModel_TyreRelaxation
      ((SFc28_AllPurposeModel_TyreRelaxationInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c28_AllPurposeModel_TyreRelaxation(SimStruct *S)
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
      28);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,28,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,28,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,28);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,28,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,28,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 5; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,28);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1402686235U));
  ssSetChecksum1(S,(1230912232U));
  ssSetChecksum2(S,(651254623U));
  ssSetChecksum3(S,(773647830U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c28_AllPurposeModel_TyreRelaxation(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c28_AllPurposeModel_TyreRelaxation(SimStruct *S)
{
  SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct *)utMalloc
    (sizeof(SFc28_AllPurposeModel_TyreRelaxationInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc28_AllPurposeModel_TyreRelaxationInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c28_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c28_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c28_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c28_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c28_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c28_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c28_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c28_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c28_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c28_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c28_AllPurposeModel_TyreRelaxation;
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

void c28_AllPurposeModel_TyreRelaxation_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c28_AllPurposeModel_TyreRelaxation(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c28_AllPurposeModel_TyreRelaxation(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c28_AllPurposeModel_TyreRelaxation(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c28_AllPurposeModel_TyreRelaxation_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
