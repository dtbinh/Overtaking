/* Include files */

#include <stddef.h>
#include "blas.h"
#include "AllPurposeModel_TyreRelaxation_sfun.h"
#include "c1_AllPurposeModel_TyreRelaxation.h"
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
static const char * c1_debug_family_names[17] = { "Ped", "L", "W", "lr",
  "arg_arcsin", "d1", "d2", "d", "nargin", "nargout", "rel_aim", "v_x", "Par",
  "APed", "BPed", "SteWhlAn", "LongDir" };

/* Function Declarations */
static void initialize_c1_AllPurposeModel_TyreRelaxation
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void initialize_params_c1_AllPurposeModel_TyreRelaxation
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void enable_c1_AllPurposeModel_TyreRelaxation
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void disable_c1_AllPurposeModel_TyreRelaxation
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_AllPurposeModel_TyreRelaxation
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_AllPurposeModel_TyreRelaxation
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void set_sim_state_c1_AllPurposeModel_TyreRelaxation
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c1_st);
static void finalize_c1_AllPurposeModel_TyreRelaxation
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void sf_gateway_c1_AllPurposeModel_TyreRelaxation
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void mdl_start_c1_AllPurposeModel_TyreRelaxation
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void c1_chartstep_c1_AllPurposeModel_TyreRelaxation
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void initSimStructsc1_AllPurposeModel_TyreRelaxation
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static real_T c1_emlrt_marshallIn
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c1_b_LongDir, const char_T *c1_identifier);
static real_T c1_b_emlrt_marshallIn
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_c_emlrt_marshallIn
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
   c1_struct_iBlsPBO3AGnt69vDoTx5zD *c1_y);
static void c1_d_emlrt_marshallIn
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
   c1_struct_Nst2vGTExxHsg85EUOj9EH *c1_y);
static c1_struct_HhckT6rntEraqECYVIDvCC c1_e_emlrt_marshallIn
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_f_emlrt_marshallIn
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
   c1_struct_ZCmOWPuqBDw16FSOVVD00 *c1_y);
static void c1_g_emlrt_marshallIn
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[4]);
static void c1_h_emlrt_marshallIn
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
   c1_struct_ZKAzdrl7umDGJoC14aoVKC *c1_y);
static void c1_i_emlrt_marshallIn
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[3]);
static c1_struct_r4FNviKwHfdhB8nQjvQv9 c1_j_emlrt_marshallIn
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static c1_struct_Y9F1qlBi9AhssksPwemA4G c1_k_emlrt_marshallIn
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_info_helper(const mxArray **c1_info);
static const mxArray *c1_emlrt_marshallOut(const char * c1_u);
static const mxArray *c1_b_emlrt_marshallOut(const uint32_T c1_u);
static void c1_eml_switch_helper
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void c1_check_forloop_overflow_error
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, boolean_T
   c1_overflow);
static real_T c1_mpower(SFc1_AllPurposeModel_TyreRelaxationInstanceStruct
  *chartInstance, real_T c1_a);
static void c1_eml_scalar_eg(SFc1_AllPurposeModel_TyreRelaxationInstanceStruct
  *chartInstance);
static void c1_eml_error(SFc1_AllPurposeModel_TyreRelaxationInstanceStruct
  *chartInstance);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_l_emlrt_marshallIn
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_rel_aim_bus_io(void *chartInstanceVoid, void *c1_pData);
static uint8_T c1_m_emlrt_marshallIn
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c1_b_is_active_c1_AllPurposeModel_TyreRelaxation, const char_T
   *c1_identifier);
static uint8_T c1_n_emlrt_marshallIn
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void init_simulink_io_address
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_AllPurposeModel_TyreRelaxation
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c1_is_active_c1_AllPurposeModel_TyreRelaxation = 0U;
}

static void initialize_params_c1_AllPurposeModel_TyreRelaxation
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  const mxArray *c1_m0 = NULL;
  const mxArray *c1_mxField;
  const mxArray *c1_m1 = NULL;
  const mxArray *c1_b_mxField;
  c1_struct_iBlsPBO3AGnt69vDoTx5zD c1_r0;
  const mxArray *c1_m2 = NULL;
  const mxArray *c1_c_mxField;
  const mxArray *c1_m3 = NULL;
  const mxArray *c1_d_mxField;
  const mxArray *c1_m4 = NULL;
  const mxArray *c1_e_mxField;
  const mxArray *c1_m5 = NULL;
  const mxArray *c1_f_mxField;
  const mxArray *c1_m6 = NULL;
  const mxArray *c1_g_mxField;
  const mxArray *c1_m7 = NULL;
  const mxArray *c1_h_mxField;
  const mxArray *c1_m8 = NULL;
  const mxArray *c1_i_mxField;
  const mxArray *c1_m9 = NULL;
  const mxArray *c1_j_mxField;
  const mxArray *c1_m10 = NULL;
  const mxArray *c1_k_mxField;
  const mxArray *c1_m11 = NULL;
  const mxArray *c1_l_mxField;
  const mxArray *c1_m12 = NULL;
  const mxArray *c1_m_mxField;
  const mxArray *c1_m13 = NULL;
  const mxArray *c1_n_mxField;
  c1_m0 = sf_mex_get_sfun_param(chartInstance->S, 0, 1);
  c1_mxField = sf_mex_getfield(c1_m0, "Env", "Par", 0);
  c1_m1 = sf_mex_dup(c1_mxField);
  c1_b_mxField = sf_mex_getfield(c1_m1, "g", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_b_mxField), &c1_r0.Env.g, 1, 0, 0U, 0,
                      0U, 0);
  c1_b_mxField = sf_mex_getfield(c1_m1, "left1", "Par", 0);
  c1_m2 = sf_mex_dup(c1_b_mxField);
  c1_c_mxField = sf_mex_getfield(c1_m2, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_c_mxField), &c1_r0.Env.left1.x, 1, 0,
                      0U, 0, 0U, 0);
  c1_c_mxField = sf_mex_getfield(c1_m2, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_c_mxField), &c1_r0.Env.left1.y, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c1_m2);
  c1_b_mxField = sf_mex_getfield(c1_m1, "right1", "Par", 0);
  c1_m3 = sf_mex_dup(c1_b_mxField);
  c1_d_mxField = sf_mex_getfield(c1_m3, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_d_mxField), &c1_r0.Env.right1.x, 1, 0,
                      0U, 0, 0U, 0);
  c1_d_mxField = sf_mex_getfield(c1_m3, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_d_mxField), &c1_r0.Env.right1.y, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c1_m3);
  c1_b_mxField = sf_mex_getfield(c1_m1, "right2", "Par", 0);
  c1_m4 = sf_mex_dup(c1_b_mxField);
  c1_e_mxField = sf_mex_getfield(c1_m4, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_e_mxField), &c1_r0.Env.right2.x, 1, 0,
                      0U, 0, 0U, 0);
  c1_e_mxField = sf_mex_getfield(c1_m4, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_e_mxField), &c1_r0.Env.right2.y, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c1_m4);
  c1_b_mxField = sf_mex_getfield(c1_m1, "left2", "Par", 0);
  c1_m5 = sf_mex_dup(c1_b_mxField);
  c1_f_mxField = sf_mex_getfield(c1_m5, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_f_mxField), &c1_r0.Env.left2.x, 1, 0,
                      0U, 0, 0U, 0);
  c1_f_mxField = sf_mex_getfield(c1_m5, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_f_mxField), &c1_r0.Env.left2.y, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c1_m5);
  c1_b_mxField = sf_mex_getfield(c1_m1, "right3", "Par", 0);
  c1_m6 = sf_mex_dup(c1_b_mxField);
  c1_g_mxField = sf_mex_getfield(c1_m6, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_g_mxField), &c1_r0.Env.right3.x, 1, 0,
                      0U, 0, 0U, 0);
  c1_g_mxField = sf_mex_getfield(c1_m6, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_g_mxField), &c1_r0.Env.right3.y, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c1_m6);
  c1_b_mxField = sf_mex_getfield(c1_m1, "mu", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_b_mxField), &c1_r0.Env.mu, 1, 0, 0U,
                      0, 0U, 0);
  sf_mex_destroy(&c1_m1);
  c1_mxField = sf_mex_getfield(c1_m0, "Veh", "Par", 0);
  c1_m7 = sf_mex_dup(c1_mxField);
  c1_h_mxField = sf_mex_getfield(c1_m7, "m", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_h_mxField), &c1_r0.Veh.m, 1, 0, 0U, 0,
                      0U, 0);
  c1_h_mxField = sf_mex_getfield(c1_m7, "Jz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_h_mxField), &c1_r0.Veh.Jz, 1, 0, 0U,
                      0, 0U, 0);
  c1_h_mxField = sf_mex_getfield(c1_m7, "m_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_h_mxField), &c1_r0.Veh.m_sprung, 1, 0,
                      0U, 0, 0U, 0);
  c1_h_mxField = sf_mex_getfield(c1_m7, "Jx_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_h_mxField), &c1_r0.Veh.Jx_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c1_h_mxField = sf_mex_getfield(c1_m7, "Jy_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_h_mxField), &c1_r0.Veh.Jy_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c1_h_mxField = sf_mex_getfield(c1_m7, "lf", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_h_mxField), &c1_r0.Veh.lf, 1, 0, 0U,
                      0, 0U, 0);
  c1_h_mxField = sf_mex_getfield(c1_m7, "lr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_h_mxField), &c1_r0.Veh.lr, 1, 0, 0U,
                      0, 0U, 0);
  c1_h_mxField = sf_mex_getfield(c1_m7, "L", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_h_mxField), &c1_r0.Veh.L, 1, 0, 0U, 0,
                      0U, 0);
  c1_h_mxField = sf_mex_getfield(c1_m7, "TrackWidth", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_h_mxField), &c1_r0.Veh.TrackWidth, 1,
                      0, 0U, 0, 0U, 0);
  c1_h_mxField = sf_mex_getfield(c1_m7, "h", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_h_mxField), &c1_r0.Veh.h, 1, 0, 0U, 0,
                      0U, 0);
  c1_h_mxField = sf_mex_getfield(c1_m7, "HalfRohACd", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_h_mxField), &c1_r0.Veh.HalfRohACd, 1,
                      0, 0U, 0, 0U, 0);
  c1_h_mxField = sf_mex_getfield(c1_m7, "F_z4_static", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_h_mxField), c1_r0.Veh.F_z4_static, 1,
                      0, 0U, 1, 0U, 2, 1, 4);
  c1_h_mxField = sf_mex_getfield(c1_m7, "Rw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_h_mxField), &c1_r0.Veh.Rw, 1, 0, 0U,
                      0, 0U, 0);
  c1_h_mxField = sf_mex_getfield(c1_m7, "r_long", "Par", 0);
  c1_m8 = sf_mex_dup(c1_h_mxField);
  c1_i_mxField = sf_mex_getfield(c1_m8, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_i_mxField), c1_r0.Veh.r_long.fl, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  c1_i_mxField = sf_mex_getfield(c1_m8, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_i_mxField), c1_r0.Veh.r_long.fr, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  c1_i_mxField = sf_mex_getfield(c1_m8, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_i_mxField), c1_r0.Veh.r_long.rl, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  c1_i_mxField = sf_mex_getfield(c1_m8, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_i_mxField), c1_r0.Veh.r_long.rr, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c1_m8);
  c1_h_mxField = sf_mex_getfield(c1_m7, "r_lat", "Par", 0);
  c1_m9 = sf_mex_dup(c1_h_mxField);
  c1_j_mxField = sf_mex_getfield(c1_m9, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_j_mxField), c1_r0.Veh.r_lat.fl, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  c1_j_mxField = sf_mex_getfield(c1_m9, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_j_mxField), c1_r0.Veh.r_lat.fr, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  c1_j_mxField = sf_mex_getfield(c1_m9, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_j_mxField), c1_r0.Veh.r_lat.rl, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  c1_j_mxField = sf_mex_getfield(c1_m9, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_j_mxField), c1_r0.Veh.r_lat.rr, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c1_m9);
  c1_h_mxField = sf_mex_getfield(c1_m7, "r_lever", "Par", 0);
  c1_m10 = sf_mex_dup(c1_h_mxField);
  c1_k_mxField = sf_mex_getfield(c1_m10, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_k_mxField), c1_r0.Veh.r_lever.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c1_k_mxField = sf_mex_getfield(c1_m10, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_k_mxField), c1_r0.Veh.r_lever.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c1_k_mxField = sf_mex_getfield(c1_m10, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_k_mxField), c1_r0.Veh.r_lever.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c1_k_mxField = sf_mex_getfield(c1_m10, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_k_mxField), c1_r0.Veh.r_lever.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c1_m10);
  c1_h_mxField = sf_mex_getfield(c1_m7, "r_pivot", "Par", 0);
  c1_m11 = sf_mex_dup(c1_h_mxField);
  c1_l_mxField = sf_mex_getfield(c1_m11, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_l_mxField), c1_r0.Veh.r_pivot.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c1_l_mxField = sf_mex_getfield(c1_m11, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_l_mxField), c1_r0.Veh.r_pivot.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c1_l_mxField = sf_mex_getfield(c1_m11, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_l_mxField), c1_r0.Veh.r_pivot.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c1_l_mxField = sf_mex_getfield(c1_m11, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_l_mxField), c1_r0.Veh.r_pivot.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c1_m11);
  c1_h_mxField = sf_mex_getfield(c1_m7, "cw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_h_mxField), &c1_r0.Veh.cw, 1, 0, 0U,
                      0, 0U, 0);
  c1_h_mxField = sf_mex_getfield(c1_m7, "carb_f", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_h_mxField), &c1_r0.Veh.carb_f, 1, 0,
                      0U, 0, 0U, 0);
  c1_h_mxField = sf_mex_getfield(c1_m7, "carb_r", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_h_mxField), &c1_r0.Veh.carb_r, 1, 0,
                      0U, 0, 0U, 0);
  c1_h_mxField = sf_mex_getfield(c1_m7, "dw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_h_mxField), &c1_r0.Veh.dw, 1, 0, 0U,
                      0, 0U, 0);
  c1_h_mxField = sf_mex_getfield(c1_m7, "Jw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_h_mxField), &c1_r0.Veh.Jw, 1, 0, 0U,
                      0, 0U, 0);
  c1_h_mxField = sf_mex_getfield(c1_m7, "C0", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_h_mxField), &c1_r0.Veh.C0, 1, 0, 0U,
                      0, 0U, 0);
  c1_h_mxField = sf_mex_getfield(c1_m7, "RelaxLength", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_h_mxField), &c1_r0.Veh.RelaxLength, 1,
                      0, 0U, 0, 0U, 0);
  c1_h_mxField = sf_mex_getfield(c1_m7, "RRC", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_h_mxField), &c1_r0.Veh.RRC, 1, 0, 0U,
                      0, 0U, 0);
  c1_h_mxField = sf_mex_getfield(c1_m7, "Pmax", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_h_mxField), &c1_r0.Veh.Pmax, 1, 0, 0U,
                      0, 0U, 0);
  c1_h_mxField = sf_mex_getfield(c1_m7, "PropDistrFrnt", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_h_mxField), &c1_r0.Veh.PropDistrFrnt,
                      1, 0, 0U, 0, 0U, 0);
  c1_h_mxField = sf_mex_getfield(c1_m7, "BrkDistrFrnt", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_h_mxField), &c1_r0.Veh.BrkDistrFrnt,
                      1, 0, 0U, 0, 0U, 0);
  c1_h_mxField = sf_mex_getfield(c1_m7, "SteRatio", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_h_mxField), &c1_r0.Veh.SteRatio, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c1_m7);
  c1_mxField = sf_mex_getfield(c1_m0, "Drvr", "Par", 0);
  c1_m12 = sf_mex_dup(c1_mxField);
  c1_m_mxField = sf_mex_getfield(c1_m12, "v_set", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_m_mxField), &c1_r0.Drvr.v_set, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c1_m12);
  c1_mxField = sf_mex_getfield(c1_m0, "Init", "Par", 0);
  c1_m13 = sf_mex_dup(c1_mxField);
  c1_n_mxField = sf_mex_getfield(c1_m13, "v_x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_n_mxField), &c1_r0.Init.v_x, 1, 0, 0U,
                      0, 0U, 0);
  c1_n_mxField = sf_mex_getfield(c1_m13, "F_fz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_n_mxField), &c1_r0.Init.F_fz, 1, 0,
                      0U, 0, 0U, 0);
  c1_n_mxField = sf_mex_getfield(c1_m13, "F_rz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c1_n_mxField), &c1_r0.Init.F_rz, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c1_m13);
  sf_mex_destroy(&c1_m0);
  chartInstance->c1_Par = c1_r0;
}

static void enable_c1_AllPurposeModel_TyreRelaxation
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c1_AllPurposeModel_TyreRelaxation
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c1_update_debugger_state_c1_AllPurposeModel_TyreRelaxation
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c1_AllPurposeModel_TyreRelaxation
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  real_T c1_hoistedGlobal;
  real_T c1_u;
  const mxArray *c1_b_y = NULL;
  real_T c1_b_hoistedGlobal;
  real_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  real_T c1_c_hoistedGlobal;
  real_T c1_c_u;
  const mxArray *c1_d_y = NULL;
  real_T c1_d_hoistedGlobal;
  real_T c1_d_u;
  const mxArray *c1_e_y = NULL;
  uint8_T c1_e_hoistedGlobal;
  uint8_T c1_e_u;
  const mxArray *c1_f_y = NULL;
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellmatrix(5, 1), false);
  c1_hoistedGlobal = *chartInstance->c1_APed;
  c1_u = c1_hoistedGlobal;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_b_hoistedGlobal = *chartInstance->c1_BPed;
  c1_b_u = c1_b_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_c_hoistedGlobal = *chartInstance->c1_LongDir;
  c1_c_u = c1_c_hoistedGlobal;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  c1_d_hoistedGlobal = *chartInstance->c1_SteWhlAn;
  c1_d_u = c1_d_hoistedGlobal;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 3, c1_e_y);
  c1_e_hoistedGlobal =
    chartInstance->c1_is_active_c1_AllPurposeModel_TyreRelaxation;
  c1_e_u = c1_e_hoistedGlobal;
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 4, c1_f_y);
  sf_mex_assign(&c1_st, c1_y, false);
  return c1_st;
}

static void set_sim_state_c1_AllPurposeModel_TyreRelaxation
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c1_st)
{
  const mxArray *c1_u;
  chartInstance->c1_doneDoubleBufferReInit = true;
  c1_u = sf_mex_dup(c1_st);
  *chartInstance->c1_APed = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 0)), "APed");
  *chartInstance->c1_BPed = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 1)), "BPed");
  *chartInstance->c1_LongDir = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 2)), "LongDir");
  *chartInstance->c1_SteWhlAn = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 3)), "SteWhlAn");
  chartInstance->c1_is_active_c1_AllPurposeModel_TyreRelaxation =
    c1_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 4)),
    "is_active_c1_AllPurposeModel_TyreRelaxation");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_AllPurposeModel_TyreRelaxation(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_AllPurposeModel_TyreRelaxation
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c1_AllPurposeModel_TyreRelaxation
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  chartInstance->c1_sfEvent = CALL_EVENT;
  c1_chartstep_c1_AllPurposeModel_TyreRelaxation(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_AllPurposeModel_TyreRelaxationMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_APed, 0U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_BPed, 1U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_SteWhlAn, 2U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_v_x, 4U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_LongDir, 6U);
}

static void mdl_start_c1_AllPurposeModel_TyreRelaxation
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c1_chartstep_c1_AllPurposeModel_TyreRelaxation
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  real_T c1_hoistedGlobal;
  c1_obst_vec2 c1_b_rel_aim;
  real_T c1_b_v_x;
  c1_struct_iBlsPBO3AGnt69vDoTx5zD c1_b_Par;
  uint32_T c1_debug_family_var_map[17];
  real_T c1_Ped;
  real_T c1_L;
  real_T c1_W;
  real_T c1_lr;
  real_T c1_arg_arcsin;
  real_T c1_d1;
  real_T c1_d2;
  real_T c1_d;
  real_T c1_nargin = 3.0;
  real_T c1_nargout = 4.0;
  real_T c1_b_APed;
  real_T c1_b_BPed;
  real_T c1_b_SteWhlAn;
  real_T c1_b_LongDir;
  real_T c1_varargin_1[2];
  int32_T c1_ixstart;
  real_T c1_mtmp;
  real_T c1_x;
  boolean_T c1_b;
  int32_T c1_ix;
  int32_T c1_b_ix;
  real_T c1_b_x;
  boolean_T c1_b_b;
  int32_T c1_a;
  int32_T c1_b_a;
  int32_T c1_i0;
  int32_T c1_c_a;
  int32_T c1_d_a;
  boolean_T c1_overflow;
  int32_T c1_c_ix;
  real_T c1_e_a;
  real_T c1_c_b;
  boolean_T c1_p;
  real_T c1_b_mtmp;
  real_T c1_maxval;
  int32_T c1_b_ixstart;
  real_T c1_c_mtmp;
  real_T c1_c_x;
  boolean_T c1_d_b;
  int32_T c1_d_ix;
  int32_T c1_e_ix;
  real_T c1_d_x;
  boolean_T c1_e_b;
  int32_T c1_f_a;
  int32_T c1_g_a;
  int32_T c1_i1;
  int32_T c1_h_a;
  int32_T c1_i_a;
  boolean_T c1_b_overflow;
  int32_T c1_f_ix;
  real_T c1_j_a;
  real_T c1_f_b;
  boolean_T c1_b_p;
  real_T c1_d_mtmp;
  real_T c1_minval;
  int32_T c1_c_ixstart;
  real_T c1_e_mtmp;
  real_T c1_e_x;
  boolean_T c1_g_b;
  int32_T c1_g_ix;
  int32_T c1_h_ix;
  real_T c1_f_x;
  boolean_T c1_h_b;
  int32_T c1_k_a;
  int32_T c1_l_a;
  int32_T c1_i2;
  int32_T c1_m_a;
  int32_T c1_n_a;
  boolean_T c1_c_overflow;
  int32_T c1_i_ix;
  real_T c1_o_a;
  real_T c1_i_b;
  boolean_T c1_c_p;
  real_T c1_f_mtmp;
  real_T c1_b_minval;
  int32_T c1_d_ixstart;
  real_T c1_g_mtmp;
  real_T c1_g_x;
  boolean_T c1_j_b;
  int32_T c1_j_ix;
  int32_T c1_k_ix;
  real_T c1_h_x;
  boolean_T c1_k_b;
  int32_T c1_p_a;
  int32_T c1_q_a;
  int32_T c1_i3;
  int32_T c1_r_a;
  int32_T c1_s_a;
  boolean_T c1_d_overflow;
  int32_T c1_l_ix;
  real_T c1_t_a;
  real_T c1_l_b;
  boolean_T c1_d_p;
  real_T c1_h_mtmp;
  real_T c1_b_maxval;
  real_T c1_A;
  real_T c1_B;
  real_T c1_i_x;
  real_T c1_y;
  real_T c1_j_x;
  real_T c1_b_y;
  real_T c1_k_x;
  real_T c1_c_y;
  real_T c1_l_x;
  real_T c1_m_x;
  real_T c1_d0;
  real_T c1_n_x;
  real_T c1_o_x;
  real_T c1_p_x;
  real_T c1_q_x;
  real_T c1_b_d1;
  real_T c1_r_x;
  real_T c1_s_x;
  real_T c1_b_d2;
  real_T c1_t_x;
  real_T c1_u_x;
  real_T c1_w_x;
  real_T c1_x_x;
  real_T c1_d_y;
  real_T c1_b_varargin_1;
  real_T c1_varargin_2;
  real_T c1_y_x;
  real_T c1_ab_x;
  real_T c1_xk;
  real_T c1_bb_x;
  real_T c1_c_minval;
  boolean_T guard1 = false;
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T exitg3;
  boolean_T exitg4;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_hoistedGlobal = *chartInstance->c1_v_x;
  c1_b_rel_aim.x = *(real_T *)&((char_T *)chartInstance->c1_rel_aim)[0];
  c1_b_rel_aim.y = *(real_T *)&((char_T *)chartInstance->c1_rel_aim)[8];
  c1_b_v_x = c1_hoistedGlobal;
  c1_b_Par = chartInstance->c1_Par;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 17U, 17U, c1_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_Ped, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_L, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_W, 2U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_lr, 3U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_arg_arcsin, 4U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d1, 5U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d2, 6U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d, 7U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 8U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 9U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_b_rel_aim, 10U, c1_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_b_v_x, 11U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_Par, 12U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_APed, 13U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_BPed, 14U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_SteWhlAn, 15U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_LongDir, 16U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 5);
  c1_Ped = c1_b_Par.Drvr.v_set - c1_b_v_x;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 6);
  c1_varargin_1[0] = c1_Ped;
  c1_varargin_1[1] = 0.0;
  c1_ixstart = 1;
  c1_mtmp = c1_varargin_1[0];
  c1_x = c1_mtmp;
  c1_b = muDoubleScalarIsNaN(c1_x);
  if (c1_b) {
    c1_eml_switch_helper(chartInstance);
    c1_eml_switch_helper(chartInstance);
    c1_ix = 2;
    exitg4 = false;
    while ((exitg4 == false) && (c1_ix < 3)) {
      c1_b_ix = c1_ix;
      c1_ixstart = c1_b_ix;
      c1_b_x = c1_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c1_b_ix), 1, 2, 1, 0) - 1];
      c1_b_b = muDoubleScalarIsNaN(c1_b_x);
      if (!c1_b_b) {
        c1_mtmp = c1_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c1_b_ix), 1, 2, 1, 0) - 1];
        exitg4 = true;
      } else {
        c1_ix++;
      }
    }
  }

  if (c1_ixstart < 2) {
    c1_a = c1_ixstart;
    c1_b_a = c1_a + 1;
    c1_i0 = c1_b_a;
    c1_c_a = c1_i0;
    c1_d_a = c1_c_a;
    if (c1_d_a > 2) {
      c1_overflow = false;
    } else {
      c1_eml_switch_helper(chartInstance);
      c1_eml_switch_helper(chartInstance);
      c1_overflow = false;
    }

    if (c1_overflow) {
      c1_check_forloop_overflow_error(chartInstance, c1_overflow);
    }

    for (c1_c_ix = c1_i0; c1_c_ix < 3; c1_c_ix++) {
      c1_b_ix = c1_c_ix;
      c1_e_a = c1_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c1_b_ix), 1, 2, 1, 0) - 1];
      c1_c_b = c1_mtmp;
      c1_p = (c1_e_a > c1_c_b);
      if (c1_p) {
        c1_mtmp = c1_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c1_b_ix), 1, 2, 1, 0) - 1];
      }
    }
  }

  c1_b_mtmp = c1_mtmp;
  c1_maxval = c1_b_mtmp;
  c1_varargin_1[0] = c1_maxval;
  c1_varargin_1[1] = 1.0;
  c1_b_ixstart = 1;
  c1_c_mtmp = c1_varargin_1[0];
  c1_c_x = c1_c_mtmp;
  c1_d_b = muDoubleScalarIsNaN(c1_c_x);
  if (c1_d_b) {
    c1_eml_switch_helper(chartInstance);
    c1_eml_switch_helper(chartInstance);
    c1_d_ix = 2;
    exitg3 = false;
    while ((exitg3 == false) && (c1_d_ix < 3)) {
      c1_e_ix = c1_d_ix;
      c1_b_ixstart = c1_e_ix;
      c1_d_x = c1_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c1_e_ix), 1, 2, 1, 0) - 1];
      c1_e_b = muDoubleScalarIsNaN(c1_d_x);
      if (!c1_e_b) {
        c1_c_mtmp = c1_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c1_e_ix), 1, 2, 1, 0) - 1];
        exitg3 = true;
      } else {
        c1_d_ix++;
      }
    }
  }

  if (c1_b_ixstart < 2) {
    c1_f_a = c1_b_ixstart;
    c1_g_a = c1_f_a + 1;
    c1_i1 = c1_g_a;
    c1_h_a = c1_i1;
    c1_i_a = c1_h_a;
    if (c1_i_a > 2) {
      c1_b_overflow = false;
    } else {
      c1_eml_switch_helper(chartInstance);
      c1_eml_switch_helper(chartInstance);
      c1_b_overflow = false;
    }

    if (c1_b_overflow) {
      c1_check_forloop_overflow_error(chartInstance, c1_b_overflow);
    }

    for (c1_f_ix = c1_i1; c1_f_ix < 3; c1_f_ix++) {
      c1_e_ix = c1_f_ix;
      c1_j_a = c1_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c1_e_ix), 1, 2, 1, 0) - 1];
      c1_f_b = c1_c_mtmp;
      c1_b_p = (c1_j_a < c1_f_b);
      if (c1_b_p) {
        c1_c_mtmp = c1_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c1_e_ix), 1, 2, 1, 0) - 1];
      }
    }
  }

  c1_d_mtmp = c1_c_mtmp;
  c1_minval = c1_d_mtmp;
  c1_b_APed = c1_minval;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_varargin_1[0] = c1_Ped;
  c1_varargin_1[1] = 0.0;
  c1_c_ixstart = 1;
  c1_e_mtmp = c1_varargin_1[0];
  c1_e_x = c1_e_mtmp;
  c1_g_b = muDoubleScalarIsNaN(c1_e_x);
  if (c1_g_b) {
    c1_eml_switch_helper(chartInstance);
    c1_eml_switch_helper(chartInstance);
    c1_g_ix = 2;
    exitg2 = false;
    while ((exitg2 == false) && (c1_g_ix < 3)) {
      c1_h_ix = c1_g_ix;
      c1_c_ixstart = c1_h_ix;
      c1_f_x = c1_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c1_h_ix), 1, 2, 1, 0) - 1];
      c1_h_b = muDoubleScalarIsNaN(c1_f_x);
      if (!c1_h_b) {
        c1_e_mtmp = c1_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c1_h_ix), 1, 2, 1, 0) - 1];
        exitg2 = true;
      } else {
        c1_g_ix++;
      }
    }
  }

  if (c1_c_ixstart < 2) {
    c1_k_a = c1_c_ixstart;
    c1_l_a = c1_k_a + 1;
    c1_i2 = c1_l_a;
    c1_m_a = c1_i2;
    c1_n_a = c1_m_a;
    if (c1_n_a > 2) {
      c1_c_overflow = false;
    } else {
      c1_eml_switch_helper(chartInstance);
      c1_eml_switch_helper(chartInstance);
      c1_c_overflow = false;
    }

    if (c1_c_overflow) {
      c1_check_forloop_overflow_error(chartInstance, c1_c_overflow);
    }

    for (c1_i_ix = c1_i2; c1_i_ix < 3; c1_i_ix++) {
      c1_h_ix = c1_i_ix;
      c1_o_a = c1_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c1_h_ix), 1, 2, 1, 0) - 1];
      c1_i_b = c1_e_mtmp;
      c1_c_p = (c1_o_a < c1_i_b);
      if (c1_c_p) {
        c1_e_mtmp = c1_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c1_h_ix), 1, 2, 1, 0) - 1];
      }
    }
  }

  c1_f_mtmp = c1_e_mtmp;
  c1_b_minval = c1_f_mtmp;
  c1_varargin_1[0] = c1_b_minval;
  c1_varargin_1[1] = -1.0;
  c1_d_ixstart = 1;
  c1_g_mtmp = c1_varargin_1[0];
  c1_g_x = c1_g_mtmp;
  c1_j_b = muDoubleScalarIsNaN(c1_g_x);
  if (c1_j_b) {
    c1_eml_switch_helper(chartInstance);
    c1_eml_switch_helper(chartInstance);
    c1_j_ix = 2;
    exitg1 = false;
    while ((exitg1 == false) && (c1_j_ix < 3)) {
      c1_k_ix = c1_j_ix;
      c1_d_ixstart = c1_k_ix;
      c1_h_x = c1_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c1_k_ix), 1, 2, 1, 0) - 1];
      c1_k_b = muDoubleScalarIsNaN(c1_h_x);
      if (!c1_k_b) {
        c1_g_mtmp = c1_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c1_k_ix), 1, 2, 1, 0) - 1];
        exitg1 = true;
      } else {
        c1_j_ix++;
      }
    }
  }

  if (c1_d_ixstart < 2) {
    c1_p_a = c1_d_ixstart;
    c1_q_a = c1_p_a + 1;
    c1_i3 = c1_q_a;
    c1_r_a = c1_i3;
    c1_s_a = c1_r_a;
    if (c1_s_a > 2) {
      c1_d_overflow = false;
    } else {
      c1_eml_switch_helper(chartInstance);
      c1_eml_switch_helper(chartInstance);
      c1_d_overflow = false;
    }

    if (c1_d_overflow) {
      c1_check_forloop_overflow_error(chartInstance, c1_d_overflow);
    }

    for (c1_l_ix = c1_i3; c1_l_ix < 3; c1_l_ix++) {
      c1_k_ix = c1_l_ix;
      c1_t_a = c1_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c1_k_ix), 1, 2, 1, 0) - 1];
      c1_l_b = c1_g_mtmp;
      c1_d_p = (c1_t_a > c1_l_b);
      if (c1_d_p) {
        c1_g_mtmp = c1_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c1_k_ix), 1, 2, 1, 0) - 1];
      }
    }
  }

  c1_h_mtmp = c1_g_mtmp;
  c1_b_maxval = c1_h_mtmp;
  c1_b_BPed = -c1_b_maxval;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 9);
  c1_L = c1_b_Par.Veh.L;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 10);
  c1_W = c1_b_Par.Veh.TrackWidth;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 11);
  c1_lr = c1_b_Par.Veh.lr;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 13);
  c1_A = 2.0 * c1_L * c1_b_rel_aim.y;
  c1_B = c1_mpower(chartInstance, c1_lr - c1_b_rel_aim.x) + c1_mpower
    (chartInstance, c1_b_rel_aim.y);
  c1_i_x = c1_A;
  c1_y = c1_B;
  c1_j_x = c1_i_x;
  c1_b_y = c1_y;
  c1_k_x = c1_j_x;
  c1_c_y = c1_b_y;
  c1_arg_arcsin = c1_k_x / c1_c_y;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 14);
  c1_l_x = c1_arg_arcsin;
  c1_m_x = c1_l_x;
  c1_d0 = muDoubleScalarAbs(c1_m_x);
  if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c1_d0, 1.0, -1, 3U, c1_d0
        <= 1.0))) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 15);
    c1_n_x = c1_arg_arcsin;
    c1_d1 = c1_n_x;
    guard1 = false;
    if (c1_d1 < -1.0) {
      guard1 = true;
    } else {
      if (1.0 < c1_d1) {
        guard1 = true;
      }
    }

    if (guard1 == true) {
      c1_eml_error(chartInstance);
    }

    c1_o_x = c1_d1;
    c1_d1 = c1_o_x;
    c1_d1 = muDoubleScalarAsin(c1_d1);
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 16);
    c1_d2 = 3.1415926535897931 - c1_d1;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 17);
    c1_p_x = c1_d1;
    c1_q_x = c1_p_x;
    c1_b_d1 = muDoubleScalarAbs(c1_q_x);
    c1_r_x = c1_d2;
    c1_s_x = c1_r_x;
    c1_b_d2 = muDoubleScalarAbs(c1_s_x);
    if (CV_EML_IF(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 1, c1_b_d1, c1_b_d2, -1,
          2U, c1_b_d1 < c1_b_d2))) {
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 17);
      c1_d = c1_d1;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 17);
      c1_d = c1_d2;
    }

    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 18);
    c1_t_x = c1_d;
    c1_u_x = c1_t_x;
    c1_u_x = muDoubleScalarSign(c1_u_x);
    c1_w_x = c1_d;
    c1_x_x = c1_w_x;
    c1_d_y = muDoubleScalarAbs(c1_x_x);
    c1_b_varargin_1 = c1_d_y;
    c1_varargin_2 = c1_b_varargin_1;
    c1_y_x = c1_varargin_2;
    c1_ab_x = c1_y_x;
    c1_eml_scalar_eg(chartInstance);
    c1_xk = c1_ab_x;
    c1_bb_x = c1_xk;
    c1_eml_scalar_eg(chartInstance);
    c1_c_minval = muDoubleScalarMin(c1_bb_x, 0.78539816339744828);
    c1_b_SteWhlAn = c1_b_Par.Veh.SteRatio * c1_u_x * c1_c_minval;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 20);
    c1_b_SteWhlAn = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 23);
  c1_b_LongDir = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -23);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c1_APed = c1_b_APed;
  *chartInstance->c1_BPed = c1_b_BPed;
  *chartInstance->c1_SteWhlAn = c1_b_SteWhlAn;
  *chartInstance->c1_LongDir = c1_b_LongDir;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void initSimStructsc1_AllPurposeModel_TyreRelaxation
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber)
{
  (void)c1_machineNumber;
  (void)c1_chartNumber;
  (void)c1_instanceNumber;
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static real_T c1_emlrt_marshallIn
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c1_b_LongDir, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_LongDir),
    &c1_thisId);
  sf_mex_destroy(&c1_b_LongDir);
  return c1_y;
}

static real_T c1_b_emlrt_marshallIn
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d3;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d3, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d3;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_LongDir;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c1_b_LongDir = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_LongDir),
    &c1_thisId);
  sf_mex_destroy(&c1_b_LongDir);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  c1_struct_iBlsPBO3AGnt69vDoTx5zD c1_u;
  const mxArray *c1_y = NULL;
  c1_struct_Nst2vGTExxHsg85EUOj9EH c1_b_u;
  const mxArray *c1_b_y = NULL;
  real_T c1_c_u;
  const mxArray *c1_c_y = NULL;
  c1_struct_HhckT6rntEraqECYVIDvCC c1_d_u;
  const mxArray *c1_d_y = NULL;
  real_T c1_e_u;
  const mxArray *c1_e_y = NULL;
  real_T c1_f_u;
  const mxArray *c1_f_y = NULL;
  const mxArray *c1_g_y = NULL;
  real_T c1_g_u;
  const mxArray *c1_h_y = NULL;
  real_T c1_h_u;
  const mxArray *c1_i_y = NULL;
  const mxArray *c1_j_y = NULL;
  real_T c1_i_u;
  const mxArray *c1_k_y = NULL;
  real_T c1_j_u;
  const mxArray *c1_l_y = NULL;
  const mxArray *c1_m_y = NULL;
  real_T c1_k_u;
  const mxArray *c1_n_y = NULL;
  real_T c1_l_u;
  const mxArray *c1_o_y = NULL;
  const mxArray *c1_p_y = NULL;
  real_T c1_m_u;
  const mxArray *c1_q_y = NULL;
  real_T c1_n_u;
  const mxArray *c1_r_y = NULL;
  real_T c1_o_u;
  const mxArray *c1_s_y = NULL;
  c1_struct_ZCmOWPuqBDw16FSOVVD00 c1_p_u;
  const mxArray *c1_t_y = NULL;
  real_T c1_q_u;
  const mxArray *c1_u_y = NULL;
  real_T c1_r_u;
  const mxArray *c1_v_y = NULL;
  real_T c1_s_u;
  const mxArray *c1_w_y = NULL;
  real_T c1_t_u;
  const mxArray *c1_x_y = NULL;
  real_T c1_u_u;
  const mxArray *c1_y_y = NULL;
  real_T c1_v_u;
  const mxArray *c1_ab_y = NULL;
  real_T c1_w_u;
  const mxArray *c1_bb_y = NULL;
  real_T c1_x_u;
  const mxArray *c1_cb_y = NULL;
  real_T c1_y_u;
  const mxArray *c1_db_y = NULL;
  real_T c1_ab_u;
  const mxArray *c1_eb_y = NULL;
  real_T c1_bb_u;
  const mxArray *c1_fb_y = NULL;
  int32_T c1_i4;
  real_T c1_cb_u[4];
  const mxArray *c1_gb_y = NULL;
  real_T c1_db_u;
  const mxArray *c1_hb_y = NULL;
  c1_struct_ZKAzdrl7umDGJoC14aoVKC c1_eb_u;
  const mxArray *c1_ib_y = NULL;
  int32_T c1_i5;
  real_T c1_fb_u[3];
  const mxArray *c1_jb_y = NULL;
  int32_T c1_i6;
  real_T c1_gb_u[3];
  const mxArray *c1_kb_y = NULL;
  int32_T c1_i7;
  real_T c1_hb_u[3];
  const mxArray *c1_lb_y = NULL;
  int32_T c1_i8;
  real_T c1_ib_u[3];
  const mxArray *c1_mb_y = NULL;
  const mxArray *c1_nb_y = NULL;
  int32_T c1_i9;
  real_T c1_jb_u[3];
  const mxArray *c1_ob_y = NULL;
  int32_T c1_i10;
  real_T c1_kb_u[3];
  const mxArray *c1_pb_y = NULL;
  int32_T c1_i11;
  real_T c1_lb_u[3];
  const mxArray *c1_qb_y = NULL;
  int32_T c1_i12;
  real_T c1_mb_u[3];
  const mxArray *c1_rb_y = NULL;
  const mxArray *c1_sb_y = NULL;
  int32_T c1_i13;
  real_T c1_nb_u[3];
  const mxArray *c1_tb_y = NULL;
  int32_T c1_i14;
  real_T c1_ob_u[3];
  const mxArray *c1_ub_y = NULL;
  int32_T c1_i15;
  real_T c1_pb_u[3];
  const mxArray *c1_vb_y = NULL;
  int32_T c1_i16;
  real_T c1_qb_u[3];
  const mxArray *c1_wb_y = NULL;
  const mxArray *c1_xb_y = NULL;
  int32_T c1_i17;
  real_T c1_rb_u[3];
  const mxArray *c1_yb_y = NULL;
  int32_T c1_i18;
  real_T c1_sb_u[3];
  const mxArray *c1_ac_y = NULL;
  int32_T c1_i19;
  real_T c1_tb_u[3];
  const mxArray *c1_bc_y = NULL;
  int32_T c1_i20;
  real_T c1_ub_u[3];
  const mxArray *c1_cc_y = NULL;
  real_T c1_vb_u;
  const mxArray *c1_dc_y = NULL;
  real_T c1_wb_u;
  const mxArray *c1_ec_y = NULL;
  real_T c1_xb_u;
  const mxArray *c1_fc_y = NULL;
  real_T c1_yb_u;
  const mxArray *c1_gc_y = NULL;
  real_T c1_ac_u;
  const mxArray *c1_hc_y = NULL;
  real_T c1_bc_u;
  const mxArray *c1_ic_y = NULL;
  real_T c1_cc_u;
  const mxArray *c1_jc_y = NULL;
  real_T c1_dc_u;
  const mxArray *c1_kc_y = NULL;
  real_T c1_ec_u;
  const mxArray *c1_lc_y = NULL;
  real_T c1_fc_u;
  const mxArray *c1_mc_y = NULL;
  real_T c1_gc_u;
  const mxArray *c1_nc_y = NULL;
  real_T c1_hc_u;
  const mxArray *c1_oc_y = NULL;
  c1_struct_r4FNviKwHfdhB8nQjvQv9 c1_ic_u;
  const mxArray *c1_pc_y = NULL;
  real_T c1_jc_u;
  const mxArray *c1_qc_y = NULL;
  c1_struct_Y9F1qlBi9AhssksPwemA4G c1_kc_u;
  const mxArray *c1_rc_y = NULL;
  real_T c1_lc_u;
  const mxArray *c1_sc_y = NULL;
  real_T c1_mc_u;
  const mxArray *c1_tc_y = NULL;
  real_T c1_nc_u;
  const mxArray *c1_uc_y = NULL;
  SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_u = *(c1_struct_iBlsPBO3AGnt69vDoTx5zD *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c1_b_u = c1_u.Env;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c1_c_u = c1_b_u.g;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_b_y, c1_c_y, "g", "g", 0);
  c1_d_u = c1_b_u.left1;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c1_e_u = c1_d_u.x;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_d_y, c1_e_y, "x", "x", 0);
  c1_f_u = c1_d_u.y;
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_d_y, c1_f_y, "y", "y", 0);
  sf_mex_addfield(c1_b_y, c1_d_y, "left1", "left1", 0);
  c1_d_u = c1_b_u.right1;
  c1_g_y = NULL;
  sf_mex_assign(&c1_g_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c1_g_u = c1_d_u.x;
  c1_h_y = NULL;
  sf_mex_assign(&c1_h_y, sf_mex_create("y", &c1_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_g_y, c1_h_y, "x", "x", 0);
  c1_h_u = c1_d_u.y;
  c1_i_y = NULL;
  sf_mex_assign(&c1_i_y, sf_mex_create("y", &c1_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_g_y, c1_i_y, "y", "y", 0);
  sf_mex_addfield(c1_b_y, c1_g_y, "right1", "right1", 0);
  c1_d_u = c1_b_u.right2;
  c1_j_y = NULL;
  sf_mex_assign(&c1_j_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c1_i_u = c1_d_u.x;
  c1_k_y = NULL;
  sf_mex_assign(&c1_k_y, sf_mex_create("y", &c1_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_j_y, c1_k_y, "x", "x", 0);
  c1_j_u = c1_d_u.y;
  c1_l_y = NULL;
  sf_mex_assign(&c1_l_y, sf_mex_create("y", &c1_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_j_y, c1_l_y, "y", "y", 0);
  sf_mex_addfield(c1_b_y, c1_j_y, "right2", "right2", 0);
  c1_d_u = c1_b_u.left2;
  c1_m_y = NULL;
  sf_mex_assign(&c1_m_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c1_k_u = c1_d_u.x;
  c1_n_y = NULL;
  sf_mex_assign(&c1_n_y, sf_mex_create("y", &c1_k_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_m_y, c1_n_y, "x", "x", 0);
  c1_l_u = c1_d_u.y;
  c1_o_y = NULL;
  sf_mex_assign(&c1_o_y, sf_mex_create("y", &c1_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_m_y, c1_o_y, "y", "y", 0);
  sf_mex_addfield(c1_b_y, c1_m_y, "left2", "left2", 0);
  c1_d_u = c1_b_u.right3;
  c1_p_y = NULL;
  sf_mex_assign(&c1_p_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c1_m_u = c1_d_u.x;
  c1_q_y = NULL;
  sf_mex_assign(&c1_q_y, sf_mex_create("y", &c1_m_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_p_y, c1_q_y, "x", "x", 0);
  c1_n_u = c1_d_u.y;
  c1_r_y = NULL;
  sf_mex_assign(&c1_r_y, sf_mex_create("y", &c1_n_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_p_y, c1_r_y, "y", "y", 0);
  sf_mex_addfield(c1_b_y, c1_p_y, "right3", "right3", 0);
  c1_o_u = c1_b_u.mu;
  c1_s_y = NULL;
  sf_mex_assign(&c1_s_y, sf_mex_create("y", &c1_o_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_b_y, c1_s_y, "mu", "mu", 0);
  sf_mex_addfield(c1_y, c1_b_y, "Env", "Env", 0);
  c1_p_u = c1_u.Veh;
  c1_t_y = NULL;
  sf_mex_assign(&c1_t_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c1_q_u = c1_p_u.m;
  c1_u_y = NULL;
  sf_mex_assign(&c1_u_y, sf_mex_create("y", &c1_q_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_t_y, c1_u_y, "m", "m", 0);
  c1_r_u = c1_p_u.Jz;
  c1_v_y = NULL;
  sf_mex_assign(&c1_v_y, sf_mex_create("y", &c1_r_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_t_y, c1_v_y, "Jz", "Jz", 0);
  c1_s_u = c1_p_u.m_sprung;
  c1_w_y = NULL;
  sf_mex_assign(&c1_w_y, sf_mex_create("y", &c1_s_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_t_y, c1_w_y, "m_sprung", "m_sprung", 0);
  c1_t_u = c1_p_u.Jx_sprung;
  c1_x_y = NULL;
  sf_mex_assign(&c1_x_y, sf_mex_create("y", &c1_t_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_t_y, c1_x_y, "Jx_sprung", "Jx_sprung", 0);
  c1_u_u = c1_p_u.Jy_sprung;
  c1_y_y = NULL;
  sf_mex_assign(&c1_y_y, sf_mex_create("y", &c1_u_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_t_y, c1_y_y, "Jy_sprung", "Jy_sprung", 0);
  c1_v_u = c1_p_u.lf;
  c1_ab_y = NULL;
  sf_mex_assign(&c1_ab_y, sf_mex_create("y", &c1_v_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_t_y, c1_ab_y, "lf", "lf", 0);
  c1_w_u = c1_p_u.lr;
  c1_bb_y = NULL;
  sf_mex_assign(&c1_bb_y, sf_mex_create("y", &c1_w_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_t_y, c1_bb_y, "lr", "lr", 0);
  c1_x_u = c1_p_u.L;
  c1_cb_y = NULL;
  sf_mex_assign(&c1_cb_y, sf_mex_create("y", &c1_x_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_t_y, c1_cb_y, "L", "L", 0);
  c1_y_u = c1_p_u.TrackWidth;
  c1_db_y = NULL;
  sf_mex_assign(&c1_db_y, sf_mex_create("y", &c1_y_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_t_y, c1_db_y, "TrackWidth", "TrackWidth", 0);
  c1_ab_u = c1_p_u.h;
  c1_eb_y = NULL;
  sf_mex_assign(&c1_eb_y, sf_mex_create("y", &c1_ab_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_t_y, c1_eb_y, "h", "h", 0);
  c1_bb_u = c1_p_u.HalfRohACd;
  c1_fb_y = NULL;
  sf_mex_assign(&c1_fb_y, sf_mex_create("y", &c1_bb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_t_y, c1_fb_y, "HalfRohACd", "HalfRohACd", 0);
  for (c1_i4 = 0; c1_i4 < 4; c1_i4++) {
    c1_cb_u[c1_i4] = c1_p_u.F_z4_static[c1_i4];
  }

  c1_gb_y = NULL;
  sf_mex_assign(&c1_gb_y, sf_mex_create("y", c1_cb_u, 0, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_addfield(c1_t_y, c1_gb_y, "F_z4_static", "F_z4_static", 0);
  c1_db_u = c1_p_u.Rw;
  c1_hb_y = NULL;
  sf_mex_assign(&c1_hb_y, sf_mex_create("y", &c1_db_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_t_y, c1_hb_y, "Rw", "Rw", 0);
  c1_eb_u = c1_p_u.r_long;
  c1_ib_y = NULL;
  sf_mex_assign(&c1_ib_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c1_i5 = 0; c1_i5 < 3; c1_i5++) {
    c1_fb_u[c1_i5] = c1_eb_u.fl[c1_i5];
  }

  c1_jb_y = NULL;
  sf_mex_assign(&c1_jb_y, sf_mex_create("y", c1_fb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c1_ib_y, c1_jb_y, "fl", "fl", 0);
  for (c1_i6 = 0; c1_i6 < 3; c1_i6++) {
    c1_gb_u[c1_i6] = c1_eb_u.fr[c1_i6];
  }

  c1_kb_y = NULL;
  sf_mex_assign(&c1_kb_y, sf_mex_create("y", c1_gb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c1_ib_y, c1_kb_y, "fr", "fr", 0);
  for (c1_i7 = 0; c1_i7 < 3; c1_i7++) {
    c1_hb_u[c1_i7] = c1_eb_u.rl[c1_i7];
  }

  c1_lb_y = NULL;
  sf_mex_assign(&c1_lb_y, sf_mex_create("y", c1_hb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c1_ib_y, c1_lb_y, "rl", "rl", 0);
  for (c1_i8 = 0; c1_i8 < 3; c1_i8++) {
    c1_ib_u[c1_i8] = c1_eb_u.rr[c1_i8];
  }

  c1_mb_y = NULL;
  sf_mex_assign(&c1_mb_y, sf_mex_create("y", c1_ib_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c1_ib_y, c1_mb_y, "rr", "rr", 0);
  sf_mex_addfield(c1_t_y, c1_ib_y, "r_long", "r_long", 0);
  c1_eb_u = c1_p_u.r_lat;
  c1_nb_y = NULL;
  sf_mex_assign(&c1_nb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c1_i9 = 0; c1_i9 < 3; c1_i9++) {
    c1_jb_u[c1_i9] = c1_eb_u.fl[c1_i9];
  }

  c1_ob_y = NULL;
  sf_mex_assign(&c1_ob_y, sf_mex_create("y", c1_jb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c1_nb_y, c1_ob_y, "fl", "fl", 0);
  for (c1_i10 = 0; c1_i10 < 3; c1_i10++) {
    c1_kb_u[c1_i10] = c1_eb_u.fr[c1_i10];
  }

  c1_pb_y = NULL;
  sf_mex_assign(&c1_pb_y, sf_mex_create("y", c1_kb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c1_nb_y, c1_pb_y, "fr", "fr", 0);
  for (c1_i11 = 0; c1_i11 < 3; c1_i11++) {
    c1_lb_u[c1_i11] = c1_eb_u.rl[c1_i11];
  }

  c1_qb_y = NULL;
  sf_mex_assign(&c1_qb_y, sf_mex_create("y", c1_lb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c1_nb_y, c1_qb_y, "rl", "rl", 0);
  for (c1_i12 = 0; c1_i12 < 3; c1_i12++) {
    c1_mb_u[c1_i12] = c1_eb_u.rr[c1_i12];
  }

  c1_rb_y = NULL;
  sf_mex_assign(&c1_rb_y, sf_mex_create("y", c1_mb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c1_nb_y, c1_rb_y, "rr", "rr", 0);
  sf_mex_addfield(c1_t_y, c1_nb_y, "r_lat", "r_lat", 0);
  c1_eb_u = c1_p_u.r_lever;
  c1_sb_y = NULL;
  sf_mex_assign(&c1_sb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c1_i13 = 0; c1_i13 < 3; c1_i13++) {
    c1_nb_u[c1_i13] = c1_eb_u.fl[c1_i13];
  }

  c1_tb_y = NULL;
  sf_mex_assign(&c1_tb_y, sf_mex_create("y", c1_nb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c1_sb_y, c1_tb_y, "fl", "fl", 0);
  for (c1_i14 = 0; c1_i14 < 3; c1_i14++) {
    c1_ob_u[c1_i14] = c1_eb_u.fr[c1_i14];
  }

  c1_ub_y = NULL;
  sf_mex_assign(&c1_ub_y, sf_mex_create("y", c1_ob_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c1_sb_y, c1_ub_y, "fr", "fr", 0);
  for (c1_i15 = 0; c1_i15 < 3; c1_i15++) {
    c1_pb_u[c1_i15] = c1_eb_u.rl[c1_i15];
  }

  c1_vb_y = NULL;
  sf_mex_assign(&c1_vb_y, sf_mex_create("y", c1_pb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c1_sb_y, c1_vb_y, "rl", "rl", 0);
  for (c1_i16 = 0; c1_i16 < 3; c1_i16++) {
    c1_qb_u[c1_i16] = c1_eb_u.rr[c1_i16];
  }

  c1_wb_y = NULL;
  sf_mex_assign(&c1_wb_y, sf_mex_create("y", c1_qb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c1_sb_y, c1_wb_y, "rr", "rr", 0);
  sf_mex_addfield(c1_t_y, c1_sb_y, "r_lever", "r_lever", 0);
  c1_eb_u = c1_p_u.r_pivot;
  c1_xb_y = NULL;
  sf_mex_assign(&c1_xb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c1_i17 = 0; c1_i17 < 3; c1_i17++) {
    c1_rb_u[c1_i17] = c1_eb_u.fl[c1_i17];
  }

  c1_yb_y = NULL;
  sf_mex_assign(&c1_yb_y, sf_mex_create("y", c1_rb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c1_xb_y, c1_yb_y, "fl", "fl", 0);
  for (c1_i18 = 0; c1_i18 < 3; c1_i18++) {
    c1_sb_u[c1_i18] = c1_eb_u.fr[c1_i18];
  }

  c1_ac_y = NULL;
  sf_mex_assign(&c1_ac_y, sf_mex_create("y", c1_sb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c1_xb_y, c1_ac_y, "fr", "fr", 0);
  for (c1_i19 = 0; c1_i19 < 3; c1_i19++) {
    c1_tb_u[c1_i19] = c1_eb_u.rl[c1_i19];
  }

  c1_bc_y = NULL;
  sf_mex_assign(&c1_bc_y, sf_mex_create("y", c1_tb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c1_xb_y, c1_bc_y, "rl", "rl", 0);
  for (c1_i20 = 0; c1_i20 < 3; c1_i20++) {
    c1_ub_u[c1_i20] = c1_eb_u.rr[c1_i20];
  }

  c1_cc_y = NULL;
  sf_mex_assign(&c1_cc_y, sf_mex_create("y", c1_ub_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c1_xb_y, c1_cc_y, "rr", "rr", 0);
  sf_mex_addfield(c1_t_y, c1_xb_y, "r_pivot", "r_pivot", 0);
  c1_vb_u = c1_p_u.cw;
  c1_dc_y = NULL;
  sf_mex_assign(&c1_dc_y, sf_mex_create("y", &c1_vb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_t_y, c1_dc_y, "cw", "cw", 0);
  c1_wb_u = c1_p_u.carb_f;
  c1_ec_y = NULL;
  sf_mex_assign(&c1_ec_y, sf_mex_create("y", &c1_wb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_t_y, c1_ec_y, "carb_f", "carb_f", 0);
  c1_xb_u = c1_p_u.carb_r;
  c1_fc_y = NULL;
  sf_mex_assign(&c1_fc_y, sf_mex_create("y", &c1_xb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_t_y, c1_fc_y, "carb_r", "carb_r", 0);
  c1_yb_u = c1_p_u.dw;
  c1_gc_y = NULL;
  sf_mex_assign(&c1_gc_y, sf_mex_create("y", &c1_yb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_t_y, c1_gc_y, "dw", "dw", 0);
  c1_ac_u = c1_p_u.Jw;
  c1_hc_y = NULL;
  sf_mex_assign(&c1_hc_y, sf_mex_create("y", &c1_ac_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_t_y, c1_hc_y, "Jw", "Jw", 0);
  c1_bc_u = c1_p_u.C0;
  c1_ic_y = NULL;
  sf_mex_assign(&c1_ic_y, sf_mex_create("y", &c1_bc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_t_y, c1_ic_y, "C0", "C0", 0);
  c1_cc_u = c1_p_u.RelaxLength;
  c1_jc_y = NULL;
  sf_mex_assign(&c1_jc_y, sf_mex_create("y", &c1_cc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_t_y, c1_jc_y, "RelaxLength", "RelaxLength", 0);
  c1_dc_u = c1_p_u.RRC;
  c1_kc_y = NULL;
  sf_mex_assign(&c1_kc_y, sf_mex_create("y", &c1_dc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_t_y, c1_kc_y, "RRC", "RRC", 0);
  c1_ec_u = c1_p_u.Pmax;
  c1_lc_y = NULL;
  sf_mex_assign(&c1_lc_y, sf_mex_create("y", &c1_ec_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_t_y, c1_lc_y, "Pmax", "Pmax", 0);
  c1_fc_u = c1_p_u.PropDistrFrnt;
  c1_mc_y = NULL;
  sf_mex_assign(&c1_mc_y, sf_mex_create("y", &c1_fc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_t_y, c1_mc_y, "PropDistrFrnt", "PropDistrFrnt", 0);
  c1_gc_u = c1_p_u.BrkDistrFrnt;
  c1_nc_y = NULL;
  sf_mex_assign(&c1_nc_y, sf_mex_create("y", &c1_gc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_t_y, c1_nc_y, "BrkDistrFrnt", "BrkDistrFrnt", 0);
  c1_hc_u = c1_p_u.SteRatio;
  c1_oc_y = NULL;
  sf_mex_assign(&c1_oc_y, sf_mex_create("y", &c1_hc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_t_y, c1_oc_y, "SteRatio", "SteRatio", 0);
  sf_mex_addfield(c1_y, c1_t_y, "Veh", "Veh", 0);
  c1_ic_u = c1_u.Drvr;
  c1_pc_y = NULL;
  sf_mex_assign(&c1_pc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c1_jc_u = c1_ic_u.v_set;
  c1_qc_y = NULL;
  sf_mex_assign(&c1_qc_y, sf_mex_create("y", &c1_jc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_pc_y, c1_qc_y, "v_set", "v_set", 0);
  sf_mex_addfield(c1_y, c1_pc_y, "Drvr", "Drvr", 0);
  c1_kc_u = c1_u.Init;
  c1_rc_y = NULL;
  sf_mex_assign(&c1_rc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c1_lc_u = c1_kc_u.v_x;
  c1_sc_y = NULL;
  sf_mex_assign(&c1_sc_y, sf_mex_create("y", &c1_lc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_rc_y, c1_sc_y, "v_x", "v_x", 0);
  c1_mc_u = c1_kc_u.F_fz;
  c1_tc_y = NULL;
  sf_mex_assign(&c1_tc_y, sf_mex_create("y", &c1_mc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_rc_y, c1_tc_y, "F_fz", "F_fz", 0);
  c1_nc_u = c1_kc_u.F_rz;
  c1_uc_y = NULL;
  sf_mex_assign(&c1_uc_y, sf_mex_create("y", &c1_nc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_rc_y, c1_uc_y, "F_rz", "F_rz", 0);
  sf_mex_addfield(c1_y, c1_rc_y, "Init", "Init", 0);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_c_emlrt_marshallIn
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
   c1_struct_iBlsPBO3AGnt69vDoTx5zD *c1_y)
{
  emlrtMsgIdentifier c1_thisId;
  static const char * c1_fieldNames[4] = { "Env", "Veh", "Drvr", "Init" };

  c1_thisId.fParent = c1_parentId;
  sf_mex_check_struct(c1_parentId, c1_u, 4, c1_fieldNames, 0U, NULL);
  c1_thisId.fIdentifier = "Env";
  c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_u, "Env",
    "Env", 0)), &c1_thisId, &c1_y->Env);
  c1_thisId.fIdentifier = "Veh";
  c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_u, "Veh",
    "Veh", 0)), &c1_thisId, &c1_y->Veh);
  c1_thisId.fIdentifier = "Drvr";
  c1_y->Drvr = c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "Drvr", "Drvr", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "Init";
  c1_y->Init = c1_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "Init", "Init", 0)), &c1_thisId);
  sf_mex_destroy(&c1_u);
}

static void c1_d_emlrt_marshallIn
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
   c1_struct_Nst2vGTExxHsg85EUOj9EH *c1_y)
{
  emlrtMsgIdentifier c1_thisId;
  static const char * c1_fieldNames[7] = { "g", "left1", "right1", "right2",
    "left2", "right3", "mu" };

  c1_thisId.fParent = c1_parentId;
  sf_mex_check_struct(c1_parentId, c1_u, 7, c1_fieldNames, 0U, NULL);
  c1_thisId.fIdentifier = "g";
  c1_y->g = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_u,
    "g", "g", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "left1";
  c1_y->left1 = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "left1", "left1", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "right1";
  c1_y->right1 = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c1_u, "right1", "right1", 0)),
    &c1_thisId);
  c1_thisId.fIdentifier = "right2";
  c1_y->right2 = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c1_u, "right2", "right2", 0)),
    &c1_thisId);
  c1_thisId.fIdentifier = "left2";
  c1_y->left2 = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "left2", "left2", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "right3";
  c1_y->right3 = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c1_u, "right3", "right3", 0)),
    &c1_thisId);
  c1_thisId.fIdentifier = "mu";
  c1_y->mu = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "mu", "mu", 0)), &c1_thisId);
  sf_mex_destroy(&c1_u);
}

static c1_struct_HhckT6rntEraqECYVIDvCC c1_e_emlrt_marshallIn
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  c1_struct_HhckT6rntEraqECYVIDvCC c1_y;
  emlrtMsgIdentifier c1_thisId;
  static const char * c1_fieldNames[2] = { "x", "y" };

  c1_thisId.fParent = c1_parentId;
  sf_mex_check_struct(c1_parentId, c1_u, 2, c1_fieldNames, 0U, NULL);
  c1_thisId.fIdentifier = "x";
  c1_y.x = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_u,
    "x", "x", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "y";
  c1_y.y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_u,
    "y", "y", 0)), &c1_thisId);
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_f_emlrt_marshallIn
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
   c1_struct_ZCmOWPuqBDw16FSOVVD00 *c1_y)
{
  emlrtMsgIdentifier c1_thisId;
  static const char * c1_fieldNames[29] = { "m", "Jz", "m_sprung", "Jx_sprung",
    "Jy_sprung", "lf", "lr", "L", "TrackWidth", "h", "HalfRohACd", "F_z4_static",
    "Rw", "r_long", "r_lat", "r_lever", "r_pivot", "cw", "carb_f", "carb_r",
    "dw", "Jw", "C0", "RelaxLength", "RRC", "Pmax", "PropDistrFrnt",
    "BrkDistrFrnt", "SteRatio" };

  c1_thisId.fParent = c1_parentId;
  sf_mex_check_struct(c1_parentId, c1_u, 29, c1_fieldNames, 0U, NULL);
  c1_thisId.fIdentifier = "m";
  c1_y->m = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_u,
    "m", "m", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "Jz";
  c1_y->Jz = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "Jz", "Jz", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "m_sprung";
  c1_y->m_sprung = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_u, "m_sprung", "m_sprung", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "Jx_sprung";
  c1_y->Jx_sprung = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_u, "Jx_sprung", "Jx_sprung", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "Jy_sprung";
  c1_y->Jy_sprung = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_u, "Jy_sprung", "Jy_sprung", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "lf";
  c1_y->lf = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "lf", "lf", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "lr";
  c1_y->lr = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "lr", "lr", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "L";
  c1_y->L = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_u,
    "L", "L", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "TrackWidth";
  c1_y->TrackWidth = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_u, "TrackWidth", "TrackWidth", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "h";
  c1_y->h = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_u,
    "h", "h", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "HalfRohACd";
  c1_y->HalfRohACd = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_u, "HalfRohACd", "HalfRohACd", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "F_z4_static";
  c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_u,
    "F_z4_static", "F_z4_static", 0)), &c1_thisId, c1_y->F_z4_static);
  c1_thisId.fIdentifier = "Rw";
  c1_y->Rw = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "Rw", "Rw", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "r_long";
  c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_u, "r_long",
    "r_long", 0)), &c1_thisId, &c1_y->r_long);
  c1_thisId.fIdentifier = "r_lat";
  c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_u, "r_lat",
    "r_lat", 0)), &c1_thisId, &c1_y->r_lat);
  c1_thisId.fIdentifier = "r_lever";
  c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_u,
    "r_lever", "r_lever", 0)), &c1_thisId, &c1_y->r_lever);
  c1_thisId.fIdentifier = "r_pivot";
  c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_u,
    "r_pivot", "r_pivot", 0)), &c1_thisId, &c1_y->r_pivot);
  c1_thisId.fIdentifier = "cw";
  c1_y->cw = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "cw", "cw", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "carb_f";
  c1_y->carb_f = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c1_u, "carb_f", "carb_f", 0)),
    &c1_thisId);
  c1_thisId.fIdentifier = "carb_r";
  c1_y->carb_r = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c1_u, "carb_r", "carb_r", 0)),
    &c1_thisId);
  c1_thisId.fIdentifier = "dw";
  c1_y->dw = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "dw", "dw", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "Jw";
  c1_y->Jw = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "Jw", "Jw", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "C0";
  c1_y->C0 = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "C0", "C0", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "RelaxLength";
  c1_y->RelaxLength = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_u, "RelaxLength", "RelaxLength", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "RRC";
  c1_y->RRC = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "RRC", "RRC", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "Pmax";
  c1_y->Pmax = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "Pmax", "Pmax", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "PropDistrFrnt";
  c1_y->PropDistrFrnt = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_u, "PropDistrFrnt", "PropDistrFrnt", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "BrkDistrFrnt";
  c1_y->BrkDistrFrnt = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_u, "BrkDistrFrnt", "BrkDistrFrnt", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "SteRatio";
  c1_y->SteRatio = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_u, "SteRatio", "SteRatio", 0)), &c1_thisId);
  sf_mex_destroy(&c1_u);
}

static void c1_g_emlrt_marshallIn
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[4])
{
  real_T c1_dv0[4];
  int32_T c1_i21;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv0, 1, 0, 0U, 1, 0U, 2, 1, 4);
  for (c1_i21 = 0; c1_i21 < 4; c1_i21++) {
    c1_y[c1_i21] = c1_dv0[c1_i21];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_h_emlrt_marshallIn
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
   c1_struct_ZKAzdrl7umDGJoC14aoVKC *c1_y)
{
  emlrtMsgIdentifier c1_thisId;
  static const char * c1_fieldNames[4] = { "fl", "fr", "rl", "rr" };

  c1_thisId.fParent = c1_parentId;
  sf_mex_check_struct(c1_parentId, c1_u, 4, c1_fieldNames, 0U, NULL);
  c1_thisId.fIdentifier = "fl";
  c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_u, "fl",
    "fl", 0)), &c1_thisId, c1_y->fl);
  c1_thisId.fIdentifier = "fr";
  c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_u, "fr",
    "fr", 0)), &c1_thisId, c1_y->fr);
  c1_thisId.fIdentifier = "rl";
  c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_u, "rl",
    "rl", 0)), &c1_thisId, c1_y->rl);
  c1_thisId.fIdentifier = "rr";
  c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_u, "rr",
    "rr", 0)), &c1_thisId, c1_y->rr);
  sf_mex_destroy(&c1_u);
}

static void c1_i_emlrt_marshallIn
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[3])
{
  real_T c1_dv1[3];
  int32_T c1_i22;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv1, 1, 0, 0U, 1, 0U, 2, 3, 1);
  for (c1_i22 = 0; c1_i22 < 3; c1_i22++) {
    c1_y[c1_i22] = c1_dv1[c1_i22];
  }

  sf_mex_destroy(&c1_u);
}

static c1_struct_r4FNviKwHfdhB8nQjvQv9 c1_j_emlrt_marshallIn
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  c1_struct_r4FNviKwHfdhB8nQjvQv9 c1_y;
  emlrtMsgIdentifier c1_thisId;
  static const char * c1_fieldNames[1] = { "v_set" };

  c1_thisId.fParent = c1_parentId;
  sf_mex_check_struct(c1_parentId, c1_u, 1, c1_fieldNames, 0U, NULL);
  c1_thisId.fIdentifier = "v_set";
  c1_y.v_set = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "v_set", "v_set", 0)), &c1_thisId);
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static c1_struct_Y9F1qlBi9AhssksPwemA4G c1_k_emlrt_marshallIn
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  c1_struct_Y9F1qlBi9AhssksPwemA4G c1_y;
  emlrtMsgIdentifier c1_thisId;
  static const char * c1_fieldNames[3] = { "v_x", "F_fz", "F_rz" };

  c1_thisId.fParent = c1_parentId;
  sf_mex_check_struct(c1_parentId, c1_u, 3, c1_fieldNames, 0U, NULL);
  c1_thisId.fIdentifier = "v_x";
  c1_y.v_x = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "v_x", "v_x", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "F_fz";
  c1_y.F_fz = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "F_fz", "F_fz", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "F_rz";
  c1_y.F_rz = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "F_rz", "F_rz", 0)), &c1_thisId);
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_Par;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  c1_struct_iBlsPBO3AGnt69vDoTx5zD c1_y;
  SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c1_b_Par = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_Par), &c1_thisId, &c1_y);
  sf_mex_destroy(&c1_b_Par);
  *(c1_struct_iBlsPBO3AGnt69vDoTx5zD *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  c1_obst_vec2 c1_u;
  const mxArray *c1_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  real_T c1_c_u;
  const mxArray *c1_c_y = NULL;
  SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(c1_obst_vec2 *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c1_b_u = c1_u.x;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_y, c1_b_y, "x", "x", 0);
  c1_c_u = c1_u.y;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_y, c1_c_y, "y", "y", 0);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

const mxArray
  *sf_c1_AllPurposeModel_TyreRelaxation_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_createstruct("structure", 2, 55, 1),
                false);
  c1_info_helper(&c1_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(const mxArray **c1_info)
{
  const mxArray *c1_rhs0 = NULL;
  const mxArray *c1_lhs0 = NULL;
  const mxArray *c1_rhs1 = NULL;
  const mxArray *c1_lhs1 = NULL;
  const mxArray *c1_rhs2 = NULL;
  const mxArray *c1_lhs2 = NULL;
  const mxArray *c1_rhs3 = NULL;
  const mxArray *c1_lhs3 = NULL;
  const mxArray *c1_rhs4 = NULL;
  const mxArray *c1_lhs4 = NULL;
  const mxArray *c1_rhs5 = NULL;
  const mxArray *c1_lhs5 = NULL;
  const mxArray *c1_rhs6 = NULL;
  const mxArray *c1_lhs6 = NULL;
  const mxArray *c1_rhs7 = NULL;
  const mxArray *c1_lhs7 = NULL;
  const mxArray *c1_rhs8 = NULL;
  const mxArray *c1_lhs8 = NULL;
  const mxArray *c1_rhs9 = NULL;
  const mxArray *c1_lhs9 = NULL;
  const mxArray *c1_rhs10 = NULL;
  const mxArray *c1_lhs10 = NULL;
  const mxArray *c1_rhs11 = NULL;
  const mxArray *c1_lhs11 = NULL;
  const mxArray *c1_rhs12 = NULL;
  const mxArray *c1_lhs12 = NULL;
  const mxArray *c1_rhs13 = NULL;
  const mxArray *c1_lhs13 = NULL;
  const mxArray *c1_rhs14 = NULL;
  const mxArray *c1_lhs14 = NULL;
  const mxArray *c1_rhs15 = NULL;
  const mxArray *c1_lhs15 = NULL;
  const mxArray *c1_rhs16 = NULL;
  const mxArray *c1_lhs16 = NULL;
  const mxArray *c1_rhs17 = NULL;
  const mxArray *c1_lhs17 = NULL;
  const mxArray *c1_rhs18 = NULL;
  const mxArray *c1_lhs18 = NULL;
  const mxArray *c1_rhs19 = NULL;
  const mxArray *c1_lhs19 = NULL;
  const mxArray *c1_rhs20 = NULL;
  const mxArray *c1_lhs20 = NULL;
  const mxArray *c1_rhs21 = NULL;
  const mxArray *c1_lhs21 = NULL;
  const mxArray *c1_rhs22 = NULL;
  const mxArray *c1_lhs22 = NULL;
  const mxArray *c1_rhs23 = NULL;
  const mxArray *c1_lhs23 = NULL;
  const mxArray *c1_rhs24 = NULL;
  const mxArray *c1_lhs24 = NULL;
  const mxArray *c1_rhs25 = NULL;
  const mxArray *c1_lhs25 = NULL;
  const mxArray *c1_rhs26 = NULL;
  const mxArray *c1_lhs26 = NULL;
  const mxArray *c1_rhs27 = NULL;
  const mxArray *c1_lhs27 = NULL;
  const mxArray *c1_rhs28 = NULL;
  const mxArray *c1_lhs28 = NULL;
  const mxArray *c1_rhs29 = NULL;
  const mxArray *c1_lhs29 = NULL;
  const mxArray *c1_rhs30 = NULL;
  const mxArray *c1_lhs30 = NULL;
  const mxArray *c1_rhs31 = NULL;
  const mxArray *c1_lhs31 = NULL;
  const mxArray *c1_rhs32 = NULL;
  const mxArray *c1_lhs32 = NULL;
  const mxArray *c1_rhs33 = NULL;
  const mxArray *c1_lhs33 = NULL;
  const mxArray *c1_rhs34 = NULL;
  const mxArray *c1_lhs34 = NULL;
  const mxArray *c1_rhs35 = NULL;
  const mxArray *c1_lhs35 = NULL;
  const mxArray *c1_rhs36 = NULL;
  const mxArray *c1_lhs36 = NULL;
  const mxArray *c1_rhs37 = NULL;
  const mxArray *c1_lhs37 = NULL;
  const mxArray *c1_rhs38 = NULL;
  const mxArray *c1_lhs38 = NULL;
  const mxArray *c1_rhs39 = NULL;
  const mxArray *c1_lhs39 = NULL;
  const mxArray *c1_rhs40 = NULL;
  const mxArray *c1_lhs40 = NULL;
  const mxArray *c1_rhs41 = NULL;
  const mxArray *c1_lhs41 = NULL;
  const mxArray *c1_rhs42 = NULL;
  const mxArray *c1_lhs42 = NULL;
  const mxArray *c1_rhs43 = NULL;
  const mxArray *c1_lhs43 = NULL;
  const mxArray *c1_rhs44 = NULL;
  const mxArray *c1_lhs44 = NULL;
  const mxArray *c1_rhs45 = NULL;
  const mxArray *c1_lhs45 = NULL;
  const mxArray *c1_rhs46 = NULL;
  const mxArray *c1_lhs46 = NULL;
  const mxArray *c1_rhs47 = NULL;
  const mxArray *c1_lhs47 = NULL;
  const mxArray *c1_rhs48 = NULL;
  const mxArray *c1_lhs48 = NULL;
  const mxArray *c1_rhs49 = NULL;
  const mxArray *c1_lhs49 = NULL;
  const mxArray *c1_rhs50 = NULL;
  const mxArray *c1_lhs50 = NULL;
  const mxArray *c1_rhs51 = NULL;
  const mxArray *c1_lhs51 = NULL;
  const mxArray *c1_rhs52 = NULL;
  const mxArray *c1_lhs52 = NULL;
  const mxArray *c1_rhs53 = NULL;
  const mxArray *c1_lhs53 = NULL;
  const mxArray *c1_rhs54 = NULL;
  const mxArray *c1_lhs54 = NULL;
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("max"), "name", "name", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1311255316U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c1_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1378295984U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c1_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum"),
                  "context", "context", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_const_nonsingleton_dim"),
                  "name", "name", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1372582416U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c1_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m"),
                  "context", "context", 3);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "coder.internal.constNonSingletonDim"), "name", "name", 3);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/constNonSingletonDim.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1372583160U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c1_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum"),
                  "context", "context", 4);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 4);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 4);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c1_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 5);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c1_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum"),
                  "context", "context", 6);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 6);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c1_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 7);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 7);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c1_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 8);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("isnan"), "name", "name", 8);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363713858U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c1_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 9);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c1_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 10);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 10);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 10);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1372582416U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c1_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 11);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 11);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1372583160U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c1_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 12);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 12);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1397257422U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c1_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 13);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("isfi"), "name", "name", 13);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 13);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1346510358U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c1_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("isnumerictype"), "name",
                  "name", 14);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                  "resolved", 14);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1398875598U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c1_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 15);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("intmax"), "name", "name", 15);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1362261882U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c1_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 16);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1393330858U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c1_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 17);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("intmin"), "name", "name", 17);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1362261882U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c1_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 18);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1393330858U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c1_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 19);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_relop"), "name", "name",
                  19);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("function_handle"),
                  "dominantType", "dominantType", 19);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1342451182U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c1_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 20);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("min"), "name", "name", 20);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1311255318U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c1_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 21);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1378295984U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c1_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 22);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("mpower"), "name", "name", 22);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c1_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 23);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 23);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c1_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 24);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("ismatrix"), "name", "name", 24);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                  "resolved", 24);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1331304858U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c1_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 25);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("power"), "name", "name", 25);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "resolved",
                  "resolved", 25);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1395328506U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c1_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "context",
                  "context", 26);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 26);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 26);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c1_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 27);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 27);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 27);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c1_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 28);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 28);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c1_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 29);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 29);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c1_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 30);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("floor"), "name", "name", 30);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 30);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363713854U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c1_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 31);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 31);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c1_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 32);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 32);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 32);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1286818726U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c1_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power"),
                  "context", "context", 33);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 33);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 33);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c1_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 34);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("mrdivide"), "name", "name", 34);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 34);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1410807648U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1370009886U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c1_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 35);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 35);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1389717774U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c1_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 36);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("rdivide"), "name", "name", 36);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 36);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363713880U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c1_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 37);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 37);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c1_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 38);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 38);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 38);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c1_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 39);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_div"), "name", "name", 39);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 39);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1386423952U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c1_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 40);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 40);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 40);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c1_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 41);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("abs"), "name", "name", 41);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 41);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363713852U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c1_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 42);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 42);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 42);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c1_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 43);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 43);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 43);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1286818712U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c1_rhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 44);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("asin"), "name", "name", 44);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 44);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/asin.m"), "resolved",
                  "resolved", 44);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1395328494U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c1_rhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs44), "lhs", "lhs",
                  44);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/asin.m"), "context",
                  "context", 45);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_error"), "name", "name",
                  45);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 45);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 45);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1343830358U), "fileTimeLo",
                  "fileTimeLo", 45);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 45);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 45);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 45);
  sf_mex_assign(&c1_rhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs45), "rhs", "rhs",
                  45);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs45), "lhs", "lhs",
                  45);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/asin.m"), "context",
                  "context", 46);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalar_asin"), "name",
                  "name", 46);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 46);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_asin.m"),
                  "resolved", "resolved", 46);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1343830376U), "fileTimeLo",
                  "fileTimeLo", 46);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 46);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 46);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 46);
  sf_mex_assign(&c1_rhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs46), "rhs", "rhs",
                  46);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs46), "lhs", "lhs",
                  46);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 47);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("sign"), "name", "name", 47);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 47);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m"), "resolved",
                  "resolved", 47);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363713856U), "fileTimeLo",
                  "fileTimeLo", 47);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 47);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 47);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 47);
  sf_mex_assign(&c1_rhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs47), "rhs", "rhs",
                  47);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs47), "lhs", "lhs",
                  47);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m"), "context",
                  "context", 48);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 48);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 48);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 48);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 48);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 48);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 48);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 48);
  sf_mex_assign(&c1_rhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs48), "rhs", "rhs",
                  48);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs48), "lhs", "lhs",
                  48);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m"), "context",
                  "context", 49);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalar_sign"), "name",
                  "name", 49);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 49);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sign.m"),
                  "resolved", "resolved", 49);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1356541494U), "fileTimeLo",
                  "fileTimeLo", 49);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 49);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 49);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 49);
  sf_mex_assign(&c1_rhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs49), "rhs", "rhs",
                  49);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs49), "lhs", "lhs",
                  49);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 50);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 50);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 50);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 50);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 50);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 50);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 50);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 50);
  sf_mex_assign(&c1_rhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs50), "rhs", "rhs",
                  50);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs50), "lhs", "lhs",
                  50);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 51);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 51);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 51);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 51);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 51);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 51);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 51);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 51);
  sf_mex_assign(&c1_rhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs51), "rhs", "rhs",
                  51);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs51), "lhs", "lhs",
                  51);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 52);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 52);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 52);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 52);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 52);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 52);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 52);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 52);
  sf_mex_assign(&c1_rhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs52), "rhs", "rhs",
                  52);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs52), "lhs", "lhs",
                  52);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 53);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 53);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 53);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 53);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 53);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 53);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 53);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 53);
  sf_mex_assign(&c1_rhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs53), "rhs", "rhs",
                  53);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs53), "lhs", "lhs",
                  53);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 54);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 54);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 54);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 54);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 54);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 54);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 54);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 54);
  sf_mex_assign(&c1_rhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs54), "rhs", "rhs",
                  54);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs54), "lhs", "lhs",
                  54);
  sf_mex_destroy(&c1_rhs0);
  sf_mex_destroy(&c1_lhs0);
  sf_mex_destroy(&c1_rhs1);
  sf_mex_destroy(&c1_lhs1);
  sf_mex_destroy(&c1_rhs2);
  sf_mex_destroy(&c1_lhs2);
  sf_mex_destroy(&c1_rhs3);
  sf_mex_destroy(&c1_lhs3);
  sf_mex_destroy(&c1_rhs4);
  sf_mex_destroy(&c1_lhs4);
  sf_mex_destroy(&c1_rhs5);
  sf_mex_destroy(&c1_lhs5);
  sf_mex_destroy(&c1_rhs6);
  sf_mex_destroy(&c1_lhs6);
  sf_mex_destroy(&c1_rhs7);
  sf_mex_destroy(&c1_lhs7);
  sf_mex_destroy(&c1_rhs8);
  sf_mex_destroy(&c1_lhs8);
  sf_mex_destroy(&c1_rhs9);
  sf_mex_destroy(&c1_lhs9);
  sf_mex_destroy(&c1_rhs10);
  sf_mex_destroy(&c1_lhs10);
  sf_mex_destroy(&c1_rhs11);
  sf_mex_destroy(&c1_lhs11);
  sf_mex_destroy(&c1_rhs12);
  sf_mex_destroy(&c1_lhs12);
  sf_mex_destroy(&c1_rhs13);
  sf_mex_destroy(&c1_lhs13);
  sf_mex_destroy(&c1_rhs14);
  sf_mex_destroy(&c1_lhs14);
  sf_mex_destroy(&c1_rhs15);
  sf_mex_destroy(&c1_lhs15);
  sf_mex_destroy(&c1_rhs16);
  sf_mex_destroy(&c1_lhs16);
  sf_mex_destroy(&c1_rhs17);
  sf_mex_destroy(&c1_lhs17);
  sf_mex_destroy(&c1_rhs18);
  sf_mex_destroy(&c1_lhs18);
  sf_mex_destroy(&c1_rhs19);
  sf_mex_destroy(&c1_lhs19);
  sf_mex_destroy(&c1_rhs20);
  sf_mex_destroy(&c1_lhs20);
  sf_mex_destroy(&c1_rhs21);
  sf_mex_destroy(&c1_lhs21);
  sf_mex_destroy(&c1_rhs22);
  sf_mex_destroy(&c1_lhs22);
  sf_mex_destroy(&c1_rhs23);
  sf_mex_destroy(&c1_lhs23);
  sf_mex_destroy(&c1_rhs24);
  sf_mex_destroy(&c1_lhs24);
  sf_mex_destroy(&c1_rhs25);
  sf_mex_destroy(&c1_lhs25);
  sf_mex_destroy(&c1_rhs26);
  sf_mex_destroy(&c1_lhs26);
  sf_mex_destroy(&c1_rhs27);
  sf_mex_destroy(&c1_lhs27);
  sf_mex_destroy(&c1_rhs28);
  sf_mex_destroy(&c1_lhs28);
  sf_mex_destroy(&c1_rhs29);
  sf_mex_destroy(&c1_lhs29);
  sf_mex_destroy(&c1_rhs30);
  sf_mex_destroy(&c1_lhs30);
  sf_mex_destroy(&c1_rhs31);
  sf_mex_destroy(&c1_lhs31);
  sf_mex_destroy(&c1_rhs32);
  sf_mex_destroy(&c1_lhs32);
  sf_mex_destroy(&c1_rhs33);
  sf_mex_destroy(&c1_lhs33);
  sf_mex_destroy(&c1_rhs34);
  sf_mex_destroy(&c1_lhs34);
  sf_mex_destroy(&c1_rhs35);
  sf_mex_destroy(&c1_lhs35);
  sf_mex_destroy(&c1_rhs36);
  sf_mex_destroy(&c1_lhs36);
  sf_mex_destroy(&c1_rhs37);
  sf_mex_destroy(&c1_lhs37);
  sf_mex_destroy(&c1_rhs38);
  sf_mex_destroy(&c1_lhs38);
  sf_mex_destroy(&c1_rhs39);
  sf_mex_destroy(&c1_lhs39);
  sf_mex_destroy(&c1_rhs40);
  sf_mex_destroy(&c1_lhs40);
  sf_mex_destroy(&c1_rhs41);
  sf_mex_destroy(&c1_lhs41);
  sf_mex_destroy(&c1_rhs42);
  sf_mex_destroy(&c1_lhs42);
  sf_mex_destroy(&c1_rhs43);
  sf_mex_destroy(&c1_lhs43);
  sf_mex_destroy(&c1_rhs44);
  sf_mex_destroy(&c1_lhs44);
  sf_mex_destroy(&c1_rhs45);
  sf_mex_destroy(&c1_lhs45);
  sf_mex_destroy(&c1_rhs46);
  sf_mex_destroy(&c1_lhs46);
  sf_mex_destroy(&c1_rhs47);
  sf_mex_destroy(&c1_lhs47);
  sf_mex_destroy(&c1_rhs48);
  sf_mex_destroy(&c1_lhs48);
  sf_mex_destroy(&c1_rhs49);
  sf_mex_destroy(&c1_lhs49);
  sf_mex_destroy(&c1_rhs50);
  sf_mex_destroy(&c1_lhs50);
  sf_mex_destroy(&c1_rhs51);
  sf_mex_destroy(&c1_lhs51);
  sf_mex_destroy(&c1_rhs52);
  sf_mex_destroy(&c1_lhs52);
  sf_mex_destroy(&c1_rhs53);
  sf_mex_destroy(&c1_lhs53);
  sf_mex_destroy(&c1_rhs54);
  sf_mex_destroy(&c1_lhs54);
}

static const mxArray *c1_emlrt_marshallOut(const char * c1_u)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c1_u)), false);
  return c1_y;
}

static const mxArray *c1_b_emlrt_marshallOut(const uint32_T c1_u)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 7, 0U, 0U, 0U, 0), false);
  return c1_y;
}

static void c1_eml_switch_helper
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c1_check_forloop_overflow_error
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, boolean_T
   c1_overflow)
{
  int32_T c1_i23;
  static char_T c1_cv0[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c1_u[34];
  const mxArray *c1_y = NULL;
  int32_T c1_i24;
  static char_T c1_cv1[5] = { 'i', 'n', 't', '3', '2' };

  char_T c1_b_u[5];
  const mxArray *c1_b_y = NULL;
  (void)chartInstance;
  if (!c1_overflow) {
  } else {
    for (c1_i23 = 0; c1_i23 < 34; c1_i23++) {
      c1_u[c1_i23] = c1_cv0[c1_i23];
    }

    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 34),
                  false);
    for (c1_i24 = 0; c1_i24 < 5; c1_i24++) {
      c1_b_u[c1_i24] = c1_cv1[c1_i24];
    }

    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_u, 10, 0U, 1U, 0U, 2, 1, 5),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 2U, 14, c1_y, 14, c1_b_y));
  }
}

static real_T c1_mpower(SFc1_AllPurposeModel_TyreRelaxationInstanceStruct
  *chartInstance, real_T c1_a)
{
  real_T c1_b_a;
  real_T c1_c_a;
  real_T c1_ak;
  real_T c1_d_a;
  c1_b_a = c1_a;
  c1_c_a = c1_b_a;
  c1_eml_scalar_eg(chartInstance);
  c1_ak = c1_c_a;
  c1_d_a = c1_ak;
  c1_eml_scalar_eg(chartInstance);
  return c1_d_a * c1_d_a;
}

static void c1_eml_scalar_eg(SFc1_AllPurposeModel_TyreRelaxationInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c1_eml_error(SFc1_AllPurposeModel_TyreRelaxationInstanceStruct
  *chartInstance)
{
  int32_T c1_i25;
  static char_T c1_cv2[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c1_u[30];
  const mxArray *c1_y = NULL;
  int32_T c1_i26;
  static char_T c1_cv3[4] = { 'a', 's', 'i', 'n' };

  char_T c1_b_u[4];
  const mxArray *c1_b_y = NULL;
  (void)chartInstance;
  for (c1_i25 = 0; c1_i25 < 30; c1_i25++) {
    c1_u[c1_i25] = c1_cv2[c1_i25];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 30), false);
  for (c1_i26 = 0; c1_i26 < 4; c1_i26++) {
    c1_b_u[c1_i26] = c1_cv3[c1_i26];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c1_y, 14, c1_b_y));
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static int32_T c1_l_emlrt_marshallIn
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i27;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i27, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i27;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_rel_aim_bus_io(void *chartInstanceVoid, void *c1_pData)
{
  const mxArray *c1_mxVal = NULL;
  c1_obst_vec2 c1_tmp;
  SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c1_mxVal = NULL;
  c1_tmp.x = *(real_T *)&((char_T *)(c1_obst_vec2 *)c1_pData)[0];
  c1_tmp.y = *(real_T *)&((char_T *)(c1_obst_vec2 *)c1_pData)[8];
  sf_mex_assign(&c1_mxVal, c1_c_sf_marshallOut(chartInstance, &c1_tmp), false);
  return c1_mxVal;
}

static uint8_T c1_m_emlrt_marshallIn
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c1_b_is_active_c1_AllPurposeModel_TyreRelaxation, const char_T
   *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_n_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_AllPurposeModel_TyreRelaxation), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_AllPurposeModel_TyreRelaxation);
  return c1_y;
}

static uint8_T c1_n_emlrt_marshallIn
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address
  (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  chartInstance->c1_APed = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c1_BPed = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c1_SteWhlAn = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c1_rel_aim = (c1_obst_vec2 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c1_v_x = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c1_LongDir = (real_T *)ssGetOutputPortSignal_wrapper
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

void sf_c1_AllPurposeModel_TyreRelaxation_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1442172578U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2974735447U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3733290002U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2742515611U);
}

mxArray* sf_c1_AllPurposeModel_TyreRelaxation_get_post_codegen_info(void);
mxArray *sf_c1_AllPurposeModel_TyreRelaxation_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("Cjbz0aQDhRu5OyQ9YgvbrF");
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
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

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo =
      sf_c1_AllPurposeModel_TyreRelaxation_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_AllPurposeModel_TyreRelaxation_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c1_AllPurposeModel_TyreRelaxation_jit_fallback_info(void)
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

mxArray *sf_c1_AllPurposeModel_TyreRelaxation_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c1_AllPurposeModel_TyreRelaxation_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c1_AllPurposeModel_TyreRelaxation
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[5],T\"APed\",},{M[1],M[6],T\"BPed\",},{M[1],M[32],T\"LongDir\",},{M[1],M[26],T\"SteWhlAn\",},{M[8],M[0],T\"is_active_c1_AllPurposeModel_TyreRelaxation\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_AllPurposeModel_TyreRelaxation_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _AllPurposeModel_TyreRelaxationMachineNumber_,
           1,
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
          _SFD_SET_DATA_PROPS(0,2,0,1,"APed");
          _SFD_SET_DATA_PROPS(1,2,0,1,"BPed");
          _SFD_SET_DATA_PROPS(2,2,0,1,"SteWhlAn");
          _SFD_SET_DATA_PROPS(3,1,1,0,"rel_aim");
          _SFD_SET_DATA_PROPS(4,1,1,0,"v_x");
          _SFD_SET_DATA_PROPS(5,10,0,0,"Par");
          _SFD_SET_DATA_PROPS(6,2,0,1,"LongDir");
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
        _SFD_CV_INIT_EML(0,1,1,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,641);
        _SFD_CV_INIT_EML_IF(0,1,0,381,402,587,629);
        _SFD_CV_INIT_EML_IF(0,1,1,452,470,478,493);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,384,402,-1,3);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,455,470,-1,2);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_rel_aim_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c1_APed);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c1_BPed);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c1_SteWhlAn);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c1_rel_aim);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c1_v_x);
        _SFD_SET_DATA_VALUE_PTR(5U, &chartInstance->c1_Par);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c1_LongDir);
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
  return "gMzL3OL8lzHdHgJAHhXtKG";
}

static void sf_opaque_initialize_c1_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_AllPurposeModel_TyreRelaxationInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_AllPurposeModel_TyreRelaxation
    ((SFc1_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
  initialize_c1_AllPurposeModel_TyreRelaxation
    ((SFc1_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  enable_c1_AllPurposeModel_TyreRelaxation
    ((SFc1_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  disable_c1_AllPurposeModel_TyreRelaxation
    ((SFc1_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  sf_gateway_c1_AllPurposeModel_TyreRelaxation
    ((SFc1_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c1_AllPurposeModel_TyreRelaxation
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c1_AllPurposeModel_TyreRelaxation
    ((SFc1_AllPurposeModel_TyreRelaxationInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c1_AllPurposeModel_TyreRelaxation(SimStruct*
  S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c1_AllPurposeModel_TyreRelaxation
    ((SFc1_AllPurposeModel_TyreRelaxationInstanceStruct*)
     chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c1_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_AllPurposeModel_TyreRelaxationInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_AllPurposeModel_TyreRelaxation_optimization_info();
    }

    finalize_c1_AllPurposeModel_TyreRelaxation
      ((SFc1_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_AllPurposeModel_TyreRelaxation
    ((SFc1_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_AllPurposeModel_TyreRelaxation(SimStruct *S)
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
    initialize_params_c1_AllPurposeModel_TyreRelaxation
      ((SFc1_AllPurposeModel_TyreRelaxationInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_AllPurposeModel_TyreRelaxation(SimStruct *S)
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
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,1,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,1);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,4);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=4; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2069314464U));
  ssSetChecksum1(S,(2563799157U));
  ssSetChecksum2(S,(2214778242U));
  ssSetChecksum3(S,(529750579U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_AllPurposeModel_TyreRelaxation(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_AllPurposeModel_TyreRelaxation(SimStruct *S)
{
  SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct *)utMalloc
    (sizeof(SFc1_AllPurposeModel_TyreRelaxationInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc1_AllPurposeModel_TyreRelaxationInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c1_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_AllPurposeModel_TyreRelaxation;
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

void c1_AllPurposeModel_TyreRelaxation_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_AllPurposeModel_TyreRelaxation(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_AllPurposeModel_TyreRelaxation(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_AllPurposeModel_TyreRelaxation(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_AllPurposeModel_TyreRelaxation_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
