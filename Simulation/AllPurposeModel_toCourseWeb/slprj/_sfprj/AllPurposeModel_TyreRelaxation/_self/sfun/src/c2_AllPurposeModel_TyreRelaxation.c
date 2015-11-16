/* Include files */

#include <stddef.h>
#include "blas.h"
#include "AllPurposeModel_TyreRelaxation_sfun.h"
#include "c2_AllPurposeModel_TyreRelaxation.h"
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
static const char * c2_debug_family_names[16] = { "dist_left1rel",
  "dist_left2rel", "dist_right1rel", "dist_right2rel", "dist_right3rel",
  "dist_select_rel", "nargin", "nargout", "pos_left1rel", "pos_left2rel",
  "pos_right1rel", "pos_right2rel", "pos_right3rel", "v_x", "Par", "pos_aim_rel"
};

/* Function Declarations */
static void initialize_c2_AllPurposeModel_TyreRelaxation
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void initialize_params_c2_AllPurposeModel_TyreRelaxation
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void enable_c2_AllPurposeModel_TyreRelaxation
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void disable_c2_AllPurposeModel_TyreRelaxation
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_AllPurposeModel_TyreRelaxation
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_AllPurposeModel_TyreRelaxation
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void set_sim_state_c2_AllPurposeModel_TyreRelaxation
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c2_st);
static void finalize_c2_AllPurposeModel_TyreRelaxation
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void sf_gateway_c2_AllPurposeModel_TyreRelaxation
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void mdl_start_c2_AllPurposeModel_TyreRelaxation
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void initSimStructsc2_AllPurposeModel_TyreRelaxation
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static c2_obst_vec2 c2_emlrt_marshallIn
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c2_b_pos_aim_rel, const char_T *c2_identifier);
static c2_obst_vec2 c2_b_emlrt_marshallIn
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static real_T c2_c_emlrt_marshallIn
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_d_emlrt_marshallIn
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
   c2_struct_iBlsPBO3AGnt69vDoTx5zD *c2_y);
static void c2_e_emlrt_marshallIn
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
   c2_struct_Nst2vGTExxHsg85EUOj9EH *c2_y);
static c2_struct_HhckT6rntEraqECYVIDvCC c2_f_emlrt_marshallIn
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_g_emlrt_marshallIn
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
   c2_struct_ZCmOWPuqBDw16FSOVVD00 *c2_y);
static void c2_h_emlrt_marshallIn
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[4]);
static void c2_i_emlrt_marshallIn
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
   c2_struct_ZKAzdrl7umDGJoC14aoVKC *c2_y);
static void c2_j_emlrt_marshallIn
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[3]);
static c2_struct_r4FNviKwHfdhB8nQjvQv9 c2_k_emlrt_marshallIn
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static c2_struct_Y9F1qlBi9AhssksPwemA4G c2_l_emlrt_marshallIn
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_info_helper(const mxArray **c2_info);
static const mxArray *c2_emlrt_marshallOut(const char * c2_u);
static const mxArray *c2_b_emlrt_marshallOut(const uint32_T c2_u);
static real_T c2_mpower(SFc2_AllPurposeModel_TyreRelaxationInstanceStruct
  *chartInstance, real_T c2_a);
static void c2_eml_scalar_eg(SFc2_AllPurposeModel_TyreRelaxationInstanceStruct
  *chartInstance);
static void c2_eml_error(SFc2_AllPurposeModel_TyreRelaxationInstanceStruct
  *chartInstance);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_m_emlrt_marshallIn
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_pos_left1rel_bus_io(void *chartInstanceVoid, void
  *c2_pData);
static uint8_T c2_n_emlrt_marshallIn
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c2_b_is_active_c2_AllPurposeModel_TyreRelaxation, const char_T
   *c2_identifier);
static uint8_T c2_o_emlrt_marshallIn
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void init_simulink_io_address
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_AllPurposeModel_TyreRelaxation
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c2_is_active_c2_AllPurposeModel_TyreRelaxation = 0U;
}

static void initialize_params_c2_AllPurposeModel_TyreRelaxation
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  const mxArray *c2_m0 = NULL;
  const mxArray *c2_mxField;
  const mxArray *c2_m1 = NULL;
  const mxArray *c2_b_mxField;
  c2_struct_iBlsPBO3AGnt69vDoTx5zD c2_r0;
  const mxArray *c2_m2 = NULL;
  const mxArray *c2_c_mxField;
  const mxArray *c2_m3 = NULL;
  const mxArray *c2_d_mxField;
  const mxArray *c2_m4 = NULL;
  const mxArray *c2_e_mxField;
  const mxArray *c2_m5 = NULL;
  const mxArray *c2_f_mxField;
  const mxArray *c2_m6 = NULL;
  const mxArray *c2_g_mxField;
  const mxArray *c2_m7 = NULL;
  const mxArray *c2_h_mxField;
  const mxArray *c2_m8 = NULL;
  const mxArray *c2_i_mxField;
  const mxArray *c2_m9 = NULL;
  const mxArray *c2_j_mxField;
  const mxArray *c2_m10 = NULL;
  const mxArray *c2_k_mxField;
  const mxArray *c2_m11 = NULL;
  const mxArray *c2_l_mxField;
  const mxArray *c2_m12 = NULL;
  const mxArray *c2_m_mxField;
  const mxArray *c2_m13 = NULL;
  const mxArray *c2_n_mxField;
  c2_m0 = sf_mex_get_sfun_param(chartInstance->S, 0, 1);
  c2_mxField = sf_mex_getfield(c2_m0, "Env", "Par", 0);
  c2_m1 = sf_mex_dup(c2_mxField);
  c2_b_mxField = sf_mex_getfield(c2_m1, "g", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_b_mxField), &c2_r0.Env.g, 1, 0, 0U, 0,
                      0U, 0);
  c2_b_mxField = sf_mex_getfield(c2_m1, "left1", "Par", 0);
  c2_m2 = sf_mex_dup(c2_b_mxField);
  c2_c_mxField = sf_mex_getfield(c2_m2, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_c_mxField), &c2_r0.Env.left1.x, 1, 0,
                      0U, 0, 0U, 0);
  c2_c_mxField = sf_mex_getfield(c2_m2, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_c_mxField), &c2_r0.Env.left1.y, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c2_m2);
  c2_b_mxField = sf_mex_getfield(c2_m1, "right1", "Par", 0);
  c2_m3 = sf_mex_dup(c2_b_mxField);
  c2_d_mxField = sf_mex_getfield(c2_m3, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_d_mxField), &c2_r0.Env.right1.x, 1, 0,
                      0U, 0, 0U, 0);
  c2_d_mxField = sf_mex_getfield(c2_m3, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_d_mxField), &c2_r0.Env.right1.y, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c2_m3);
  c2_b_mxField = sf_mex_getfield(c2_m1, "right2", "Par", 0);
  c2_m4 = sf_mex_dup(c2_b_mxField);
  c2_e_mxField = sf_mex_getfield(c2_m4, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_e_mxField), &c2_r0.Env.right2.x, 1, 0,
                      0U, 0, 0U, 0);
  c2_e_mxField = sf_mex_getfield(c2_m4, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_e_mxField), &c2_r0.Env.right2.y, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c2_m4);
  c2_b_mxField = sf_mex_getfield(c2_m1, "left2", "Par", 0);
  c2_m5 = sf_mex_dup(c2_b_mxField);
  c2_f_mxField = sf_mex_getfield(c2_m5, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_f_mxField), &c2_r0.Env.left2.x, 1, 0,
                      0U, 0, 0U, 0);
  c2_f_mxField = sf_mex_getfield(c2_m5, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_f_mxField), &c2_r0.Env.left2.y, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c2_m5);
  c2_b_mxField = sf_mex_getfield(c2_m1, "right3", "Par", 0);
  c2_m6 = sf_mex_dup(c2_b_mxField);
  c2_g_mxField = sf_mex_getfield(c2_m6, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_g_mxField), &c2_r0.Env.right3.x, 1, 0,
                      0U, 0, 0U, 0);
  c2_g_mxField = sf_mex_getfield(c2_m6, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_g_mxField), &c2_r0.Env.right3.y, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c2_m6);
  c2_b_mxField = sf_mex_getfield(c2_m1, "mu", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_b_mxField), &c2_r0.Env.mu, 1, 0, 0U,
                      0, 0U, 0);
  sf_mex_destroy(&c2_m1);
  c2_mxField = sf_mex_getfield(c2_m0, "Veh", "Par", 0);
  c2_m7 = sf_mex_dup(c2_mxField);
  c2_h_mxField = sf_mex_getfield(c2_m7, "m", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_h_mxField), &c2_r0.Veh.m, 1, 0, 0U, 0,
                      0U, 0);
  c2_h_mxField = sf_mex_getfield(c2_m7, "Jz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_h_mxField), &c2_r0.Veh.Jz, 1, 0, 0U,
                      0, 0U, 0);
  c2_h_mxField = sf_mex_getfield(c2_m7, "m_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_h_mxField), &c2_r0.Veh.m_sprung, 1, 0,
                      0U, 0, 0U, 0);
  c2_h_mxField = sf_mex_getfield(c2_m7, "Jx_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_h_mxField), &c2_r0.Veh.Jx_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c2_h_mxField = sf_mex_getfield(c2_m7, "Jy_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_h_mxField), &c2_r0.Veh.Jy_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c2_h_mxField = sf_mex_getfield(c2_m7, "lf", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_h_mxField), &c2_r0.Veh.lf, 1, 0, 0U,
                      0, 0U, 0);
  c2_h_mxField = sf_mex_getfield(c2_m7, "lr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_h_mxField), &c2_r0.Veh.lr, 1, 0, 0U,
                      0, 0U, 0);
  c2_h_mxField = sf_mex_getfield(c2_m7, "L", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_h_mxField), &c2_r0.Veh.L, 1, 0, 0U, 0,
                      0U, 0);
  c2_h_mxField = sf_mex_getfield(c2_m7, "TrackWidth", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_h_mxField), &c2_r0.Veh.TrackWidth, 1,
                      0, 0U, 0, 0U, 0);
  c2_h_mxField = sf_mex_getfield(c2_m7, "h", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_h_mxField), &c2_r0.Veh.h, 1, 0, 0U, 0,
                      0U, 0);
  c2_h_mxField = sf_mex_getfield(c2_m7, "HalfRohACd", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_h_mxField), &c2_r0.Veh.HalfRohACd, 1,
                      0, 0U, 0, 0U, 0);
  c2_h_mxField = sf_mex_getfield(c2_m7, "F_z4_static", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_h_mxField), c2_r0.Veh.F_z4_static, 1,
                      0, 0U, 1, 0U, 2, 1, 4);
  c2_h_mxField = sf_mex_getfield(c2_m7, "Rw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_h_mxField), &c2_r0.Veh.Rw, 1, 0, 0U,
                      0, 0U, 0);
  c2_h_mxField = sf_mex_getfield(c2_m7, "r_long", "Par", 0);
  c2_m8 = sf_mex_dup(c2_h_mxField);
  c2_i_mxField = sf_mex_getfield(c2_m8, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_i_mxField), c2_r0.Veh.r_long.fl, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  c2_i_mxField = sf_mex_getfield(c2_m8, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_i_mxField), c2_r0.Veh.r_long.fr, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  c2_i_mxField = sf_mex_getfield(c2_m8, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_i_mxField), c2_r0.Veh.r_long.rl, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  c2_i_mxField = sf_mex_getfield(c2_m8, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_i_mxField), c2_r0.Veh.r_long.rr, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c2_m8);
  c2_h_mxField = sf_mex_getfield(c2_m7, "r_lat", "Par", 0);
  c2_m9 = sf_mex_dup(c2_h_mxField);
  c2_j_mxField = sf_mex_getfield(c2_m9, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_j_mxField), c2_r0.Veh.r_lat.fl, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  c2_j_mxField = sf_mex_getfield(c2_m9, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_j_mxField), c2_r0.Veh.r_lat.fr, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  c2_j_mxField = sf_mex_getfield(c2_m9, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_j_mxField), c2_r0.Veh.r_lat.rl, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  c2_j_mxField = sf_mex_getfield(c2_m9, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_j_mxField), c2_r0.Veh.r_lat.rr, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c2_m9);
  c2_h_mxField = sf_mex_getfield(c2_m7, "r_lever", "Par", 0);
  c2_m10 = sf_mex_dup(c2_h_mxField);
  c2_k_mxField = sf_mex_getfield(c2_m10, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_k_mxField), c2_r0.Veh.r_lever.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c2_k_mxField = sf_mex_getfield(c2_m10, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_k_mxField), c2_r0.Veh.r_lever.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c2_k_mxField = sf_mex_getfield(c2_m10, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_k_mxField), c2_r0.Veh.r_lever.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c2_k_mxField = sf_mex_getfield(c2_m10, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_k_mxField), c2_r0.Veh.r_lever.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c2_m10);
  c2_h_mxField = sf_mex_getfield(c2_m7, "r_pivot", "Par", 0);
  c2_m11 = sf_mex_dup(c2_h_mxField);
  c2_l_mxField = sf_mex_getfield(c2_m11, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_l_mxField), c2_r0.Veh.r_pivot.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c2_l_mxField = sf_mex_getfield(c2_m11, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_l_mxField), c2_r0.Veh.r_pivot.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c2_l_mxField = sf_mex_getfield(c2_m11, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_l_mxField), c2_r0.Veh.r_pivot.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c2_l_mxField = sf_mex_getfield(c2_m11, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_l_mxField), c2_r0.Veh.r_pivot.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c2_m11);
  c2_h_mxField = sf_mex_getfield(c2_m7, "cw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_h_mxField), &c2_r0.Veh.cw, 1, 0, 0U,
                      0, 0U, 0);
  c2_h_mxField = sf_mex_getfield(c2_m7, "carb_f", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_h_mxField), &c2_r0.Veh.carb_f, 1, 0,
                      0U, 0, 0U, 0);
  c2_h_mxField = sf_mex_getfield(c2_m7, "carb_r", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_h_mxField), &c2_r0.Veh.carb_r, 1, 0,
                      0U, 0, 0U, 0);
  c2_h_mxField = sf_mex_getfield(c2_m7, "dw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_h_mxField), &c2_r0.Veh.dw, 1, 0, 0U,
                      0, 0U, 0);
  c2_h_mxField = sf_mex_getfield(c2_m7, "Jw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_h_mxField), &c2_r0.Veh.Jw, 1, 0, 0U,
                      0, 0U, 0);
  c2_h_mxField = sf_mex_getfield(c2_m7, "C0", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_h_mxField), &c2_r0.Veh.C0, 1, 0, 0U,
                      0, 0U, 0);
  c2_h_mxField = sf_mex_getfield(c2_m7, "RelaxLength", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_h_mxField), &c2_r0.Veh.RelaxLength, 1,
                      0, 0U, 0, 0U, 0);
  c2_h_mxField = sf_mex_getfield(c2_m7, "RRC", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_h_mxField), &c2_r0.Veh.RRC, 1, 0, 0U,
                      0, 0U, 0);
  c2_h_mxField = sf_mex_getfield(c2_m7, "Pmax", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_h_mxField), &c2_r0.Veh.Pmax, 1, 0, 0U,
                      0, 0U, 0);
  c2_h_mxField = sf_mex_getfield(c2_m7, "PropDistrFrnt", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_h_mxField), &c2_r0.Veh.PropDistrFrnt,
                      1, 0, 0U, 0, 0U, 0);
  c2_h_mxField = sf_mex_getfield(c2_m7, "BrkDistrFrnt", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_h_mxField), &c2_r0.Veh.BrkDistrFrnt,
                      1, 0, 0U, 0, 0U, 0);
  c2_h_mxField = sf_mex_getfield(c2_m7, "SteRatio", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_h_mxField), &c2_r0.Veh.SteRatio, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c2_m7);
  c2_mxField = sf_mex_getfield(c2_m0, "Drvr", "Par", 0);
  c2_m12 = sf_mex_dup(c2_mxField);
  c2_m_mxField = sf_mex_getfield(c2_m12, "v_set", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_m_mxField), &c2_r0.Drvr.v_set, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c2_m12);
  c2_mxField = sf_mex_getfield(c2_m0, "Init", "Par", 0);
  c2_m13 = sf_mex_dup(c2_mxField);
  c2_n_mxField = sf_mex_getfield(c2_m13, "v_x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_n_mxField), &c2_r0.Init.v_x, 1, 0, 0U,
                      0, 0U, 0);
  c2_n_mxField = sf_mex_getfield(c2_m13, "F_fz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_n_mxField), &c2_r0.Init.F_fz, 1, 0,
                      0U, 0, 0U, 0);
  c2_n_mxField = sf_mex_getfield(c2_m13, "F_rz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c2_n_mxField), &c2_r0.Init.F_rz, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c2_m13);
  sf_mex_destroy(&c2_m0);
  chartInstance->c2_Par = c2_r0;
}

static void enable_c2_AllPurposeModel_TyreRelaxation
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c2_AllPurposeModel_TyreRelaxation
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c2_update_debugger_state_c2_AllPurposeModel_TyreRelaxation
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c2_AllPurposeModel_TyreRelaxation
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  const mxArray *c2_b_y = NULL;
  real_T c2_u;
  const mxArray *c2_c_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_d_y = NULL;
  uint8_T c2_hoistedGlobal;
  uint8_T c2_c_u;
  const mxArray *c2_e_y = NULL;
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellmatrix(2, 1), false);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c2_u = *(real_T *)&((char_T *)chartInstance->c2_pos_aim_rel)[0];
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_b_y, c2_c_y, "x", "x", 0);
  c2_b_u = *(real_T *)&((char_T *)chartInstance->c2_pos_aim_rel)[8];
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_b_y, c2_d_y, "y", "y", 0);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_hoistedGlobal =
    chartInstance->c2_is_active_c2_AllPurposeModel_TyreRelaxation;
  c2_c_u = c2_hoistedGlobal;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 1, c2_e_y);
  sf_mex_assign(&c2_st, c2_y, false);
  return c2_st;
}

static void set_sim_state_c2_AllPurposeModel_TyreRelaxation
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c2_st)
{
  const mxArray *c2_u;
  c2_obst_vec2 c2_r1;
  chartInstance->c2_doneDoubleBufferReInit = true;
  c2_u = sf_mex_dup(c2_st);
  c2_r1 = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)),
    "pos_aim_rel");
  *(real_T *)&((char_T *)chartInstance->c2_pos_aim_rel)[0] = c2_r1.x;
  *(real_T *)&((char_T *)chartInstance->c2_pos_aim_rel)[8] = c2_r1.y;
  chartInstance->c2_is_active_c2_AllPurposeModel_TyreRelaxation =
    c2_n_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)),
    "is_active_c2_AllPurposeModel_TyreRelaxation");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_AllPurposeModel_TyreRelaxation(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_AllPurposeModel_TyreRelaxation
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c2_AllPurposeModel_TyreRelaxation
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  real_T c2_hoistedGlobal;
  c2_obst_vec2 c2_b_pos_left1rel;
  c2_obst_vec2 c2_b_pos_left2rel;
  c2_obst_vec2 c2_b_pos_right1rel;
  c2_obst_vec2 c2_b_pos_right2rel;
  c2_obst_vec2 c2_b_pos_right3rel;
  real_T c2_b_v_x;
  c2_struct_iBlsPBO3AGnt69vDoTx5zD c2_b_Par;
  uint32_T c2_debug_family_var_map[16];
  real_T c2_dist_left1rel;
  real_T c2_dist_left2rel;
  real_T c2_dist_right1rel;
  real_T c2_dist_right2rel;
  real_T c2_dist_right3rel;
  real_T c2_dist_select_rel;
  real_T c2_nargin = 7.0;
  real_T c2_nargout = 1.0;
  c2_obst_vec2 c2_b_pos_aim_rel;
  real_T c2_x;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_g_x;
  real_T c2_h_x;
  real_T c2_i_x;
  real_T c2_j_x;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  boolean_T guard5 = false;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_v_x, 5U);
  chartInstance->c2_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *chartInstance->c2_v_x;
  c2_b_pos_left1rel.x = *(real_T *)&((char_T *)chartInstance->c2_pos_left1rel)[0];
  c2_b_pos_left1rel.y = *(real_T *)&((char_T *)chartInstance->c2_pos_left1rel)[8];
  c2_b_pos_left2rel.x = *(real_T *)&((char_T *)chartInstance->c2_pos_left2rel)[0];
  c2_b_pos_left2rel.y = *(real_T *)&((char_T *)chartInstance->c2_pos_left2rel)[8];
  c2_b_pos_right1rel.x = *(real_T *)&((char_T *)chartInstance->c2_pos_right1rel)
    [0];
  c2_b_pos_right1rel.y = *(real_T *)&((char_T *)chartInstance->c2_pos_right1rel)
    [8];
  c2_b_pos_right2rel.x = *(real_T *)&((char_T *)chartInstance->c2_pos_right2rel)
    [0];
  c2_b_pos_right2rel.y = *(real_T *)&((char_T *)chartInstance->c2_pos_right2rel)
    [8];
  c2_b_pos_right3rel.x = *(real_T *)&((char_T *)chartInstance->c2_pos_right3rel)
    [0];
  c2_b_pos_right3rel.y = *(real_T *)&((char_T *)chartInstance->c2_pos_right3rel)
    [8];
  c2_b_v_x = c2_hoistedGlobal;
  c2_b_Par = chartInstance->c2_Par;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 16U, 16U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_dist_left1rel, 0U,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_dist_left2rel, 1U,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_dist_right1rel, 2U,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_dist_right2rel, 3U,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_dist_right3rel, 4U,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_dist_select_rel, 5U,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 6U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 7U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_b_pos_left1rel, 8U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_b_pos_left2rel, 9U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_b_pos_right1rel, 10U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_b_pos_right2rel, 11U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_b_pos_right3rel, 12U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_b_v_x, 13U, c2_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_Par, 14U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_pos_aim_rel, 15U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 4);
  c2_x = c2_mpower(chartInstance, c2_b_pos_left1rel.x) + c2_mpower(chartInstance,
    c2_b_pos_left1rel.y);
  c2_dist_left1rel = c2_x;
  if (c2_dist_left1rel < 0.0) {
    c2_eml_error(chartInstance);
  }

  c2_b_x = c2_dist_left1rel;
  c2_dist_left1rel = c2_b_x;
  c2_dist_left1rel = muDoubleScalarSqrt(c2_dist_left1rel);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 5);
  c2_c_x = c2_mpower(chartInstance, c2_b_pos_left2rel.x) + c2_mpower
    (chartInstance, c2_b_pos_left2rel.y);
  c2_dist_left2rel = c2_c_x;
  if (c2_dist_left2rel < 0.0) {
    c2_eml_error(chartInstance);
  }

  c2_d_x = c2_dist_left2rel;
  c2_dist_left2rel = c2_d_x;
  c2_dist_left2rel = muDoubleScalarSqrt(c2_dist_left2rel);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 6);
  c2_e_x = c2_mpower(chartInstance, c2_b_pos_right1rel.x) + c2_mpower
    (chartInstance, c2_b_pos_right1rel.y);
  c2_dist_right1rel = c2_e_x;
  if (c2_dist_right1rel < 0.0) {
    c2_eml_error(chartInstance);
  }

  c2_f_x = c2_dist_right1rel;
  c2_dist_right1rel = c2_f_x;
  c2_dist_right1rel = muDoubleScalarSqrt(c2_dist_right1rel);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 7);
  c2_g_x = c2_mpower(chartInstance, c2_b_pos_right2rel.x) + c2_mpower
    (chartInstance, c2_b_pos_right2rel.y);
  c2_dist_right2rel = c2_g_x;
  if (c2_dist_right2rel < 0.0) {
    c2_eml_error(chartInstance);
  }

  c2_h_x = c2_dist_right2rel;
  c2_dist_right2rel = c2_h_x;
  c2_dist_right2rel = muDoubleScalarSqrt(c2_dist_right2rel);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_i_x = c2_mpower(chartInstance, c2_b_pos_right3rel.x) + c2_mpower
    (chartInstance, c2_b_pos_right3rel.y);
  c2_dist_right3rel = c2_i_x;
  if (c2_dist_right3rel < 0.0) {
    c2_eml_error(chartInstance);
  }

  c2_j_x = c2_dist_right3rel;
  c2_dist_right3rel = c2_j_x;
  c2_dist_right3rel = muDoubleScalarSqrt(c2_dist_right3rel);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 10);
  c2_dist_select_rel = rtInf;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 11);
  c2_b_pos_aim_rel.x = 100.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 12);
  c2_b_pos_aim_rel.y = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 14);
  guard5 = false;
  if (CV_EML_COND(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c2_b_pos_left1rel.x,
        c2_b_Par.Veh.lf, -1, 4U, c2_b_pos_left1rel.x > c2_b_Par.Veh.lf))) {
    if (CV_EML_COND(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 1, c2_dist_left1rel,
          c2_dist_select_rel, -1, 2U, c2_dist_left1rel < c2_dist_select_rel))) {
      CV_EML_MCDC(0, 1, 0, true);
      CV_EML_IF(0, 1, 0, true);
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 15);
      c2_b_pos_aim_rel.x = c2_b_pos_left1rel.x;
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 16);
      c2_b_pos_aim_rel.y = c2_b_pos_left1rel.y;
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 17);
      c2_dist_select_rel = c2_dist_left1rel;
    } else {
      guard5 = true;
    }
  } else {
    guard5 = true;
  }

  if (guard5 == true) {
    CV_EML_MCDC(0, 1, 0, false);
    CV_EML_IF(0, 1, 0, false);
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 20);
  guard4 = false;
  if (CV_EML_COND(0, 1, 2, CV_RELATIONAL_EVAL(4U, 0U, 2, c2_b_pos_left2rel.x,
        c2_b_Par.Veh.lf, -1, 4U, c2_b_pos_left2rel.x > c2_b_Par.Veh.lf))) {
    if (CV_EML_COND(0, 1, 3, CV_RELATIONAL_EVAL(4U, 0U, 3, c2_dist_left2rel,
          c2_dist_select_rel, -1, 2U, c2_dist_left2rel < c2_dist_select_rel))) {
      CV_EML_MCDC(0, 1, 1, true);
      CV_EML_IF(0, 1, 1, true);
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 21);
      c2_b_pos_aim_rel.x = c2_b_pos_left2rel.x;
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 22);
      c2_b_pos_aim_rel.y = c2_b_pos_left2rel.y;
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 23);
      c2_dist_select_rel = c2_dist_left2rel;
    } else {
      guard4 = true;
    }
  } else {
    guard4 = true;
  }

  if (guard4 == true) {
    CV_EML_MCDC(0, 1, 1, false);
    CV_EML_IF(0, 1, 1, false);
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 26);
  guard3 = false;
  if (CV_EML_COND(0, 1, 4, CV_RELATIONAL_EVAL(4U, 0U, 4, c2_b_pos_right1rel.x,
        c2_b_Par.Veh.lf, -1, 4U, c2_b_pos_right1rel.x > c2_b_Par.Veh.lf))) {
    if (CV_EML_COND(0, 1, 5, CV_RELATIONAL_EVAL(4U, 0U, 5, c2_dist_right1rel,
          c2_dist_select_rel, -1, 2U, c2_dist_right1rel < c2_dist_select_rel)))
    {
      CV_EML_MCDC(0, 1, 2, true);
      CV_EML_IF(0, 1, 2, true);
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 27);
      c2_b_pos_aim_rel.x = c2_b_pos_right1rel.x;
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 28);
      c2_b_pos_aim_rel.y = c2_b_pos_right1rel.y;
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 29);
      c2_dist_select_rel = c2_dist_right1rel;
    } else {
      guard3 = true;
    }
  } else {
    guard3 = true;
  }

  if (guard3 == true) {
    CV_EML_MCDC(0, 1, 2, false);
    CV_EML_IF(0, 1, 2, false);
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 32);
  guard2 = false;
  if (CV_EML_COND(0, 1, 6, CV_RELATIONAL_EVAL(4U, 0U, 6, c2_b_pos_right2rel.x,
        c2_b_Par.Veh.lf, -1, 4U, c2_b_pos_right2rel.x > c2_b_Par.Veh.lf))) {
    if (CV_EML_COND(0, 1, 7, CV_RELATIONAL_EVAL(4U, 0U, 7, c2_dist_right2rel,
          c2_dist_select_rel, -1, 2U, c2_dist_right2rel < c2_dist_select_rel)))
    {
      CV_EML_MCDC(0, 1, 3, true);
      CV_EML_IF(0, 1, 3, true);
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 33);
      c2_b_pos_aim_rel.x = c2_b_pos_right2rel.x;
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 34);
      c2_b_pos_aim_rel.y = c2_b_pos_right2rel.y;
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 35);
      c2_dist_select_rel = c2_dist_right2rel;
    } else {
      guard2 = true;
    }
  } else {
    guard2 = true;
  }

  if (guard2 == true) {
    CV_EML_MCDC(0, 1, 3, false);
    CV_EML_IF(0, 1, 3, false);
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 38);
  guard1 = false;
  if (CV_EML_COND(0, 1, 8, CV_RELATIONAL_EVAL(4U, 0U, 8, c2_b_pos_right3rel.x,
        c2_b_Par.Veh.lf, -1, 4U, c2_b_pos_right3rel.x > c2_b_Par.Veh.lf))) {
    if (CV_EML_COND(0, 1, 9, CV_RELATIONAL_EVAL(4U, 0U, 9, c2_dist_right3rel,
          c2_dist_select_rel, -1, 2U, c2_dist_right3rel < c2_dist_select_rel)))
    {
      CV_EML_MCDC(0, 1, 4, true);
      CV_EML_IF(0, 1, 4, true);
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 39);
      c2_b_pos_aim_rel.x = c2_b_pos_right3rel.x;
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 40);
      c2_b_pos_aim_rel.y = c2_b_pos_right3rel.y;
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 41);
      c2_dist_select_rel = c2_dist_right3rel;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    CV_EML_MCDC(0, 1, 4, false);
    CV_EML_IF(0, 1, 4, false);
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -41);
  _SFD_SYMBOL_SCOPE_POP();
  *(real_T *)&((char_T *)chartInstance->c2_pos_aim_rel)[0] = c2_b_pos_aim_rel.x;
  *(real_T *)&((char_T *)chartInstance->c2_pos_aim_rel)[8] = c2_b_pos_aim_rel.y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_AllPurposeModel_TyreRelaxationMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void mdl_start_c2_AllPurposeModel_TyreRelaxation
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc2_AllPurposeModel_TyreRelaxation
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber)
{
  (void)c2_machineNumber;
  (void)c2_chartNumber;
  (void)c2_instanceNumber;
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  c2_obst_vec2 c2_u;
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  real_T c2_c_u;
  const mxArray *c2_c_y = NULL;
  SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(c2_obst_vec2 *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c2_b_u = c2_u.x;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_b_y, "x", "x", 0);
  c2_c_u = c2_u.y;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_c_y, "y", "y", 0);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static c2_obst_vec2 c2_emlrt_marshallIn
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c2_b_pos_aim_rel, const char_T *c2_identifier)
{
  c2_obst_vec2 c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_pos_aim_rel),
    &c2_thisId);
  sf_mex_destroy(&c2_b_pos_aim_rel);
  return c2_y;
}

static c2_obst_vec2 c2_b_emlrt_marshallIn
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  c2_obst_vec2 c2_y;
  emlrtMsgIdentifier c2_thisId;
  static const char * c2_fieldNames[2] = { "x", "y" };

  c2_thisId.fParent = c2_parentId;
  sf_mex_check_struct(c2_parentId, c2_u, 2, c2_fieldNames, 0U, NULL);
  c2_thisId.fIdentifier = "x";
  c2_y.x = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_u,
    "x", "x", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "y";
  c2_y.y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_u,
    "y", "y", 0)), &c2_thisId);
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static real_T c2_c_emlrt_marshallIn
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_pos_aim_rel;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  c2_obst_vec2 c2_y;
  SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c2_b_pos_aim_rel = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_pos_aim_rel),
    &c2_thisId);
  sf_mex_destroy(&c2_b_pos_aim_rel);
  *(c2_obst_vec2 *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  c2_struct_iBlsPBO3AGnt69vDoTx5zD c2_u;
  const mxArray *c2_y = NULL;
  c2_struct_Nst2vGTExxHsg85EUOj9EH c2_b_u;
  const mxArray *c2_b_y = NULL;
  real_T c2_c_u;
  const mxArray *c2_c_y = NULL;
  c2_struct_HhckT6rntEraqECYVIDvCC c2_d_u;
  const mxArray *c2_d_y = NULL;
  real_T c2_e_u;
  const mxArray *c2_e_y = NULL;
  real_T c2_f_u;
  const mxArray *c2_f_y = NULL;
  const mxArray *c2_g_y = NULL;
  real_T c2_g_u;
  const mxArray *c2_h_y = NULL;
  real_T c2_h_u;
  const mxArray *c2_i_y = NULL;
  const mxArray *c2_j_y = NULL;
  real_T c2_i_u;
  const mxArray *c2_k_y = NULL;
  real_T c2_j_u;
  const mxArray *c2_l_y = NULL;
  const mxArray *c2_m_y = NULL;
  real_T c2_k_u;
  const mxArray *c2_n_y = NULL;
  real_T c2_l_u;
  const mxArray *c2_o_y = NULL;
  const mxArray *c2_p_y = NULL;
  real_T c2_m_u;
  const mxArray *c2_q_y = NULL;
  real_T c2_n_u;
  const mxArray *c2_r_y = NULL;
  real_T c2_o_u;
  const mxArray *c2_s_y = NULL;
  c2_struct_ZCmOWPuqBDw16FSOVVD00 c2_p_u;
  const mxArray *c2_t_y = NULL;
  real_T c2_q_u;
  const mxArray *c2_u_y = NULL;
  real_T c2_r_u;
  const mxArray *c2_v_y = NULL;
  real_T c2_s_u;
  const mxArray *c2_w_y = NULL;
  real_T c2_t_u;
  const mxArray *c2_x_y = NULL;
  real_T c2_u_u;
  const mxArray *c2_y_y = NULL;
  real_T c2_v_u;
  const mxArray *c2_ab_y = NULL;
  real_T c2_w_u;
  const mxArray *c2_bb_y = NULL;
  real_T c2_x_u;
  const mxArray *c2_cb_y = NULL;
  real_T c2_y_u;
  const mxArray *c2_db_y = NULL;
  real_T c2_ab_u;
  const mxArray *c2_eb_y = NULL;
  real_T c2_bb_u;
  const mxArray *c2_fb_y = NULL;
  int32_T c2_i0;
  real_T c2_cb_u[4];
  const mxArray *c2_gb_y = NULL;
  real_T c2_db_u;
  const mxArray *c2_hb_y = NULL;
  c2_struct_ZKAzdrl7umDGJoC14aoVKC c2_eb_u;
  const mxArray *c2_ib_y = NULL;
  int32_T c2_i1;
  real_T c2_fb_u[3];
  const mxArray *c2_jb_y = NULL;
  int32_T c2_i2;
  real_T c2_gb_u[3];
  const mxArray *c2_kb_y = NULL;
  int32_T c2_i3;
  real_T c2_hb_u[3];
  const mxArray *c2_lb_y = NULL;
  int32_T c2_i4;
  real_T c2_ib_u[3];
  const mxArray *c2_mb_y = NULL;
  const mxArray *c2_nb_y = NULL;
  int32_T c2_i5;
  real_T c2_jb_u[3];
  const mxArray *c2_ob_y = NULL;
  int32_T c2_i6;
  real_T c2_kb_u[3];
  const mxArray *c2_pb_y = NULL;
  int32_T c2_i7;
  real_T c2_lb_u[3];
  const mxArray *c2_qb_y = NULL;
  int32_T c2_i8;
  real_T c2_mb_u[3];
  const mxArray *c2_rb_y = NULL;
  const mxArray *c2_sb_y = NULL;
  int32_T c2_i9;
  real_T c2_nb_u[3];
  const mxArray *c2_tb_y = NULL;
  int32_T c2_i10;
  real_T c2_ob_u[3];
  const mxArray *c2_ub_y = NULL;
  int32_T c2_i11;
  real_T c2_pb_u[3];
  const mxArray *c2_vb_y = NULL;
  int32_T c2_i12;
  real_T c2_qb_u[3];
  const mxArray *c2_wb_y = NULL;
  const mxArray *c2_xb_y = NULL;
  int32_T c2_i13;
  real_T c2_rb_u[3];
  const mxArray *c2_yb_y = NULL;
  int32_T c2_i14;
  real_T c2_sb_u[3];
  const mxArray *c2_ac_y = NULL;
  int32_T c2_i15;
  real_T c2_tb_u[3];
  const mxArray *c2_bc_y = NULL;
  int32_T c2_i16;
  real_T c2_ub_u[3];
  const mxArray *c2_cc_y = NULL;
  real_T c2_vb_u;
  const mxArray *c2_dc_y = NULL;
  real_T c2_wb_u;
  const mxArray *c2_ec_y = NULL;
  real_T c2_xb_u;
  const mxArray *c2_fc_y = NULL;
  real_T c2_yb_u;
  const mxArray *c2_gc_y = NULL;
  real_T c2_ac_u;
  const mxArray *c2_hc_y = NULL;
  real_T c2_bc_u;
  const mxArray *c2_ic_y = NULL;
  real_T c2_cc_u;
  const mxArray *c2_jc_y = NULL;
  real_T c2_dc_u;
  const mxArray *c2_kc_y = NULL;
  real_T c2_ec_u;
  const mxArray *c2_lc_y = NULL;
  real_T c2_fc_u;
  const mxArray *c2_mc_y = NULL;
  real_T c2_gc_u;
  const mxArray *c2_nc_y = NULL;
  real_T c2_hc_u;
  const mxArray *c2_oc_y = NULL;
  c2_struct_r4FNviKwHfdhB8nQjvQv9 c2_ic_u;
  const mxArray *c2_pc_y = NULL;
  real_T c2_jc_u;
  const mxArray *c2_qc_y = NULL;
  c2_struct_Y9F1qlBi9AhssksPwemA4G c2_kc_u;
  const mxArray *c2_rc_y = NULL;
  real_T c2_lc_u;
  const mxArray *c2_sc_y = NULL;
  real_T c2_mc_u;
  const mxArray *c2_tc_y = NULL;
  real_T c2_nc_u;
  const mxArray *c2_uc_y = NULL;
  SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_u = *(c2_struct_iBlsPBO3AGnt69vDoTx5zD *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c2_b_u = c2_u.Env;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c2_c_u = c2_b_u.g;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_b_y, c2_c_y, "g", "g", 0);
  c2_d_u = c2_b_u.left1;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c2_e_u = c2_d_u.x;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_d_y, c2_e_y, "x", "x", 0);
  c2_f_u = c2_d_u.y;
  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_d_y, c2_f_y, "y", "y", 0);
  sf_mex_addfield(c2_b_y, c2_d_y, "left1", "left1", 0);
  c2_d_u = c2_b_u.right1;
  c2_g_y = NULL;
  sf_mex_assign(&c2_g_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c2_g_u = c2_d_u.x;
  c2_h_y = NULL;
  sf_mex_assign(&c2_h_y, sf_mex_create("y", &c2_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_g_y, c2_h_y, "x", "x", 0);
  c2_h_u = c2_d_u.y;
  c2_i_y = NULL;
  sf_mex_assign(&c2_i_y, sf_mex_create("y", &c2_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_g_y, c2_i_y, "y", "y", 0);
  sf_mex_addfield(c2_b_y, c2_g_y, "right1", "right1", 0);
  c2_d_u = c2_b_u.right2;
  c2_j_y = NULL;
  sf_mex_assign(&c2_j_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c2_i_u = c2_d_u.x;
  c2_k_y = NULL;
  sf_mex_assign(&c2_k_y, sf_mex_create("y", &c2_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_j_y, c2_k_y, "x", "x", 0);
  c2_j_u = c2_d_u.y;
  c2_l_y = NULL;
  sf_mex_assign(&c2_l_y, sf_mex_create("y", &c2_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_j_y, c2_l_y, "y", "y", 0);
  sf_mex_addfield(c2_b_y, c2_j_y, "right2", "right2", 0);
  c2_d_u = c2_b_u.left2;
  c2_m_y = NULL;
  sf_mex_assign(&c2_m_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c2_k_u = c2_d_u.x;
  c2_n_y = NULL;
  sf_mex_assign(&c2_n_y, sf_mex_create("y", &c2_k_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_m_y, c2_n_y, "x", "x", 0);
  c2_l_u = c2_d_u.y;
  c2_o_y = NULL;
  sf_mex_assign(&c2_o_y, sf_mex_create("y", &c2_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_m_y, c2_o_y, "y", "y", 0);
  sf_mex_addfield(c2_b_y, c2_m_y, "left2", "left2", 0);
  c2_d_u = c2_b_u.right3;
  c2_p_y = NULL;
  sf_mex_assign(&c2_p_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c2_m_u = c2_d_u.x;
  c2_q_y = NULL;
  sf_mex_assign(&c2_q_y, sf_mex_create("y", &c2_m_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_p_y, c2_q_y, "x", "x", 0);
  c2_n_u = c2_d_u.y;
  c2_r_y = NULL;
  sf_mex_assign(&c2_r_y, sf_mex_create("y", &c2_n_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_p_y, c2_r_y, "y", "y", 0);
  sf_mex_addfield(c2_b_y, c2_p_y, "right3", "right3", 0);
  c2_o_u = c2_b_u.mu;
  c2_s_y = NULL;
  sf_mex_assign(&c2_s_y, sf_mex_create("y", &c2_o_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_b_y, c2_s_y, "mu", "mu", 0);
  sf_mex_addfield(c2_y, c2_b_y, "Env", "Env", 0);
  c2_p_u = c2_u.Veh;
  c2_t_y = NULL;
  sf_mex_assign(&c2_t_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c2_q_u = c2_p_u.m;
  c2_u_y = NULL;
  sf_mex_assign(&c2_u_y, sf_mex_create("y", &c2_q_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_t_y, c2_u_y, "m", "m", 0);
  c2_r_u = c2_p_u.Jz;
  c2_v_y = NULL;
  sf_mex_assign(&c2_v_y, sf_mex_create("y", &c2_r_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_t_y, c2_v_y, "Jz", "Jz", 0);
  c2_s_u = c2_p_u.m_sprung;
  c2_w_y = NULL;
  sf_mex_assign(&c2_w_y, sf_mex_create("y", &c2_s_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_t_y, c2_w_y, "m_sprung", "m_sprung", 0);
  c2_t_u = c2_p_u.Jx_sprung;
  c2_x_y = NULL;
  sf_mex_assign(&c2_x_y, sf_mex_create("y", &c2_t_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_t_y, c2_x_y, "Jx_sprung", "Jx_sprung", 0);
  c2_u_u = c2_p_u.Jy_sprung;
  c2_y_y = NULL;
  sf_mex_assign(&c2_y_y, sf_mex_create("y", &c2_u_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_t_y, c2_y_y, "Jy_sprung", "Jy_sprung", 0);
  c2_v_u = c2_p_u.lf;
  c2_ab_y = NULL;
  sf_mex_assign(&c2_ab_y, sf_mex_create("y", &c2_v_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_t_y, c2_ab_y, "lf", "lf", 0);
  c2_w_u = c2_p_u.lr;
  c2_bb_y = NULL;
  sf_mex_assign(&c2_bb_y, sf_mex_create("y", &c2_w_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_t_y, c2_bb_y, "lr", "lr", 0);
  c2_x_u = c2_p_u.L;
  c2_cb_y = NULL;
  sf_mex_assign(&c2_cb_y, sf_mex_create("y", &c2_x_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_t_y, c2_cb_y, "L", "L", 0);
  c2_y_u = c2_p_u.TrackWidth;
  c2_db_y = NULL;
  sf_mex_assign(&c2_db_y, sf_mex_create("y", &c2_y_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_t_y, c2_db_y, "TrackWidth", "TrackWidth", 0);
  c2_ab_u = c2_p_u.h;
  c2_eb_y = NULL;
  sf_mex_assign(&c2_eb_y, sf_mex_create("y", &c2_ab_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_t_y, c2_eb_y, "h", "h", 0);
  c2_bb_u = c2_p_u.HalfRohACd;
  c2_fb_y = NULL;
  sf_mex_assign(&c2_fb_y, sf_mex_create("y", &c2_bb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_t_y, c2_fb_y, "HalfRohACd", "HalfRohACd", 0);
  for (c2_i0 = 0; c2_i0 < 4; c2_i0++) {
    c2_cb_u[c2_i0] = c2_p_u.F_z4_static[c2_i0];
  }

  c2_gb_y = NULL;
  sf_mex_assign(&c2_gb_y, sf_mex_create("y", c2_cb_u, 0, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_addfield(c2_t_y, c2_gb_y, "F_z4_static", "F_z4_static", 0);
  c2_db_u = c2_p_u.Rw;
  c2_hb_y = NULL;
  sf_mex_assign(&c2_hb_y, sf_mex_create("y", &c2_db_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_t_y, c2_hb_y, "Rw", "Rw", 0);
  c2_eb_u = c2_p_u.r_long;
  c2_ib_y = NULL;
  sf_mex_assign(&c2_ib_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c2_i1 = 0; c2_i1 < 3; c2_i1++) {
    c2_fb_u[c2_i1] = c2_eb_u.fl[c2_i1];
  }

  c2_jb_y = NULL;
  sf_mex_assign(&c2_jb_y, sf_mex_create("y", c2_fb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c2_ib_y, c2_jb_y, "fl", "fl", 0);
  for (c2_i2 = 0; c2_i2 < 3; c2_i2++) {
    c2_gb_u[c2_i2] = c2_eb_u.fr[c2_i2];
  }

  c2_kb_y = NULL;
  sf_mex_assign(&c2_kb_y, sf_mex_create("y", c2_gb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c2_ib_y, c2_kb_y, "fr", "fr", 0);
  for (c2_i3 = 0; c2_i3 < 3; c2_i3++) {
    c2_hb_u[c2_i3] = c2_eb_u.rl[c2_i3];
  }

  c2_lb_y = NULL;
  sf_mex_assign(&c2_lb_y, sf_mex_create("y", c2_hb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c2_ib_y, c2_lb_y, "rl", "rl", 0);
  for (c2_i4 = 0; c2_i4 < 3; c2_i4++) {
    c2_ib_u[c2_i4] = c2_eb_u.rr[c2_i4];
  }

  c2_mb_y = NULL;
  sf_mex_assign(&c2_mb_y, sf_mex_create("y", c2_ib_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c2_ib_y, c2_mb_y, "rr", "rr", 0);
  sf_mex_addfield(c2_t_y, c2_ib_y, "r_long", "r_long", 0);
  c2_eb_u = c2_p_u.r_lat;
  c2_nb_y = NULL;
  sf_mex_assign(&c2_nb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c2_i5 = 0; c2_i5 < 3; c2_i5++) {
    c2_jb_u[c2_i5] = c2_eb_u.fl[c2_i5];
  }

  c2_ob_y = NULL;
  sf_mex_assign(&c2_ob_y, sf_mex_create("y", c2_jb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c2_nb_y, c2_ob_y, "fl", "fl", 0);
  for (c2_i6 = 0; c2_i6 < 3; c2_i6++) {
    c2_kb_u[c2_i6] = c2_eb_u.fr[c2_i6];
  }

  c2_pb_y = NULL;
  sf_mex_assign(&c2_pb_y, sf_mex_create("y", c2_kb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c2_nb_y, c2_pb_y, "fr", "fr", 0);
  for (c2_i7 = 0; c2_i7 < 3; c2_i7++) {
    c2_lb_u[c2_i7] = c2_eb_u.rl[c2_i7];
  }

  c2_qb_y = NULL;
  sf_mex_assign(&c2_qb_y, sf_mex_create("y", c2_lb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c2_nb_y, c2_qb_y, "rl", "rl", 0);
  for (c2_i8 = 0; c2_i8 < 3; c2_i8++) {
    c2_mb_u[c2_i8] = c2_eb_u.rr[c2_i8];
  }

  c2_rb_y = NULL;
  sf_mex_assign(&c2_rb_y, sf_mex_create("y", c2_mb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c2_nb_y, c2_rb_y, "rr", "rr", 0);
  sf_mex_addfield(c2_t_y, c2_nb_y, "r_lat", "r_lat", 0);
  c2_eb_u = c2_p_u.r_lever;
  c2_sb_y = NULL;
  sf_mex_assign(&c2_sb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c2_i9 = 0; c2_i9 < 3; c2_i9++) {
    c2_nb_u[c2_i9] = c2_eb_u.fl[c2_i9];
  }

  c2_tb_y = NULL;
  sf_mex_assign(&c2_tb_y, sf_mex_create("y", c2_nb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c2_sb_y, c2_tb_y, "fl", "fl", 0);
  for (c2_i10 = 0; c2_i10 < 3; c2_i10++) {
    c2_ob_u[c2_i10] = c2_eb_u.fr[c2_i10];
  }

  c2_ub_y = NULL;
  sf_mex_assign(&c2_ub_y, sf_mex_create("y", c2_ob_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c2_sb_y, c2_ub_y, "fr", "fr", 0);
  for (c2_i11 = 0; c2_i11 < 3; c2_i11++) {
    c2_pb_u[c2_i11] = c2_eb_u.rl[c2_i11];
  }

  c2_vb_y = NULL;
  sf_mex_assign(&c2_vb_y, sf_mex_create("y", c2_pb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c2_sb_y, c2_vb_y, "rl", "rl", 0);
  for (c2_i12 = 0; c2_i12 < 3; c2_i12++) {
    c2_qb_u[c2_i12] = c2_eb_u.rr[c2_i12];
  }

  c2_wb_y = NULL;
  sf_mex_assign(&c2_wb_y, sf_mex_create("y", c2_qb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c2_sb_y, c2_wb_y, "rr", "rr", 0);
  sf_mex_addfield(c2_t_y, c2_sb_y, "r_lever", "r_lever", 0);
  c2_eb_u = c2_p_u.r_pivot;
  c2_xb_y = NULL;
  sf_mex_assign(&c2_xb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c2_i13 = 0; c2_i13 < 3; c2_i13++) {
    c2_rb_u[c2_i13] = c2_eb_u.fl[c2_i13];
  }

  c2_yb_y = NULL;
  sf_mex_assign(&c2_yb_y, sf_mex_create("y", c2_rb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c2_xb_y, c2_yb_y, "fl", "fl", 0);
  for (c2_i14 = 0; c2_i14 < 3; c2_i14++) {
    c2_sb_u[c2_i14] = c2_eb_u.fr[c2_i14];
  }

  c2_ac_y = NULL;
  sf_mex_assign(&c2_ac_y, sf_mex_create("y", c2_sb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c2_xb_y, c2_ac_y, "fr", "fr", 0);
  for (c2_i15 = 0; c2_i15 < 3; c2_i15++) {
    c2_tb_u[c2_i15] = c2_eb_u.rl[c2_i15];
  }

  c2_bc_y = NULL;
  sf_mex_assign(&c2_bc_y, sf_mex_create("y", c2_tb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c2_xb_y, c2_bc_y, "rl", "rl", 0);
  for (c2_i16 = 0; c2_i16 < 3; c2_i16++) {
    c2_ub_u[c2_i16] = c2_eb_u.rr[c2_i16];
  }

  c2_cc_y = NULL;
  sf_mex_assign(&c2_cc_y, sf_mex_create("y", c2_ub_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c2_xb_y, c2_cc_y, "rr", "rr", 0);
  sf_mex_addfield(c2_t_y, c2_xb_y, "r_pivot", "r_pivot", 0);
  c2_vb_u = c2_p_u.cw;
  c2_dc_y = NULL;
  sf_mex_assign(&c2_dc_y, sf_mex_create("y", &c2_vb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_t_y, c2_dc_y, "cw", "cw", 0);
  c2_wb_u = c2_p_u.carb_f;
  c2_ec_y = NULL;
  sf_mex_assign(&c2_ec_y, sf_mex_create("y", &c2_wb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_t_y, c2_ec_y, "carb_f", "carb_f", 0);
  c2_xb_u = c2_p_u.carb_r;
  c2_fc_y = NULL;
  sf_mex_assign(&c2_fc_y, sf_mex_create("y", &c2_xb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_t_y, c2_fc_y, "carb_r", "carb_r", 0);
  c2_yb_u = c2_p_u.dw;
  c2_gc_y = NULL;
  sf_mex_assign(&c2_gc_y, sf_mex_create("y", &c2_yb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_t_y, c2_gc_y, "dw", "dw", 0);
  c2_ac_u = c2_p_u.Jw;
  c2_hc_y = NULL;
  sf_mex_assign(&c2_hc_y, sf_mex_create("y", &c2_ac_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_t_y, c2_hc_y, "Jw", "Jw", 0);
  c2_bc_u = c2_p_u.C0;
  c2_ic_y = NULL;
  sf_mex_assign(&c2_ic_y, sf_mex_create("y", &c2_bc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_t_y, c2_ic_y, "C0", "C0", 0);
  c2_cc_u = c2_p_u.RelaxLength;
  c2_jc_y = NULL;
  sf_mex_assign(&c2_jc_y, sf_mex_create("y", &c2_cc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_t_y, c2_jc_y, "RelaxLength", "RelaxLength", 0);
  c2_dc_u = c2_p_u.RRC;
  c2_kc_y = NULL;
  sf_mex_assign(&c2_kc_y, sf_mex_create("y", &c2_dc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_t_y, c2_kc_y, "RRC", "RRC", 0);
  c2_ec_u = c2_p_u.Pmax;
  c2_lc_y = NULL;
  sf_mex_assign(&c2_lc_y, sf_mex_create("y", &c2_ec_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_t_y, c2_lc_y, "Pmax", "Pmax", 0);
  c2_fc_u = c2_p_u.PropDistrFrnt;
  c2_mc_y = NULL;
  sf_mex_assign(&c2_mc_y, sf_mex_create("y", &c2_fc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_t_y, c2_mc_y, "PropDistrFrnt", "PropDistrFrnt", 0);
  c2_gc_u = c2_p_u.BrkDistrFrnt;
  c2_nc_y = NULL;
  sf_mex_assign(&c2_nc_y, sf_mex_create("y", &c2_gc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_t_y, c2_nc_y, "BrkDistrFrnt", "BrkDistrFrnt", 0);
  c2_hc_u = c2_p_u.SteRatio;
  c2_oc_y = NULL;
  sf_mex_assign(&c2_oc_y, sf_mex_create("y", &c2_hc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_t_y, c2_oc_y, "SteRatio", "SteRatio", 0);
  sf_mex_addfield(c2_y, c2_t_y, "Veh", "Veh", 0);
  c2_ic_u = c2_u.Drvr;
  c2_pc_y = NULL;
  sf_mex_assign(&c2_pc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c2_jc_u = c2_ic_u.v_set;
  c2_qc_y = NULL;
  sf_mex_assign(&c2_qc_y, sf_mex_create("y", &c2_jc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_pc_y, c2_qc_y, "v_set", "v_set", 0);
  sf_mex_addfield(c2_y, c2_pc_y, "Drvr", "Drvr", 0);
  c2_kc_u = c2_u.Init;
  c2_rc_y = NULL;
  sf_mex_assign(&c2_rc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c2_lc_u = c2_kc_u.v_x;
  c2_sc_y = NULL;
  sf_mex_assign(&c2_sc_y, sf_mex_create("y", &c2_lc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_rc_y, c2_sc_y, "v_x", "v_x", 0);
  c2_mc_u = c2_kc_u.F_fz;
  c2_tc_y = NULL;
  sf_mex_assign(&c2_tc_y, sf_mex_create("y", &c2_mc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_rc_y, c2_tc_y, "F_fz", "F_fz", 0);
  c2_nc_u = c2_kc_u.F_rz;
  c2_uc_y = NULL;
  sf_mex_assign(&c2_uc_y, sf_mex_create("y", &c2_nc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_rc_y, c2_uc_y, "F_rz", "F_rz", 0);
  sf_mex_addfield(c2_y, c2_rc_y, "Init", "Init", 0);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_d_emlrt_marshallIn
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
   c2_struct_iBlsPBO3AGnt69vDoTx5zD *c2_y)
{
  emlrtMsgIdentifier c2_thisId;
  static const char * c2_fieldNames[4] = { "Env", "Veh", "Drvr", "Init" };

  c2_thisId.fParent = c2_parentId;
  sf_mex_check_struct(c2_parentId, c2_u, 4, c2_fieldNames, 0U, NULL);
  c2_thisId.fIdentifier = "Env";
  c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_u, "Env",
    "Env", 0)), &c2_thisId, &c2_y->Env);
  c2_thisId.fIdentifier = "Veh";
  c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_u, "Veh",
    "Veh", 0)), &c2_thisId, &c2_y->Veh);
  c2_thisId.fIdentifier = "Drvr";
  c2_y->Drvr = c2_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c2_u, "Drvr", "Drvr", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "Init";
  c2_y->Init = c2_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c2_u, "Init", "Init", 0)), &c2_thisId);
  sf_mex_destroy(&c2_u);
}

static void c2_e_emlrt_marshallIn
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
   c2_struct_Nst2vGTExxHsg85EUOj9EH *c2_y)
{
  emlrtMsgIdentifier c2_thisId;
  static const char * c2_fieldNames[7] = { "g", "left1", "right1", "right2",
    "left2", "right3", "mu" };

  c2_thisId.fParent = c2_parentId;
  sf_mex_check_struct(c2_parentId, c2_u, 7, c2_fieldNames, 0U, NULL);
  c2_thisId.fIdentifier = "g";
  c2_y->g = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_u,
    "g", "g", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "left1";
  c2_y->left1 = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c2_u, "left1", "left1", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "right1";
  c2_y->right1 = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c2_u, "right1", "right1", 0)),
    &c2_thisId);
  c2_thisId.fIdentifier = "right2";
  c2_y->right2 = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c2_u, "right2", "right2", 0)),
    &c2_thisId);
  c2_thisId.fIdentifier = "left2";
  c2_y->left2 = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c2_u, "left2", "left2", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "right3";
  c2_y->right3 = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c2_u, "right3", "right3", 0)),
    &c2_thisId);
  c2_thisId.fIdentifier = "mu";
  c2_y->mu = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c2_u, "mu", "mu", 0)), &c2_thisId);
  sf_mex_destroy(&c2_u);
}

static c2_struct_HhckT6rntEraqECYVIDvCC c2_f_emlrt_marshallIn
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  c2_struct_HhckT6rntEraqECYVIDvCC c2_y;
  emlrtMsgIdentifier c2_thisId;
  static const char * c2_fieldNames[2] = { "x", "y" };

  c2_thisId.fParent = c2_parentId;
  sf_mex_check_struct(c2_parentId, c2_u, 2, c2_fieldNames, 0U, NULL);
  c2_thisId.fIdentifier = "x";
  c2_y.x = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_u,
    "x", "x", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "y";
  c2_y.y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_u,
    "y", "y", 0)), &c2_thisId);
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_g_emlrt_marshallIn
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
   c2_struct_ZCmOWPuqBDw16FSOVVD00 *c2_y)
{
  emlrtMsgIdentifier c2_thisId;
  static const char * c2_fieldNames[29] = { "m", "Jz", "m_sprung", "Jx_sprung",
    "Jy_sprung", "lf", "lr", "L", "TrackWidth", "h", "HalfRohACd", "F_z4_static",
    "Rw", "r_long", "r_lat", "r_lever", "r_pivot", "cw", "carb_f", "carb_r",
    "dw", "Jw", "C0", "RelaxLength", "RRC", "Pmax", "PropDistrFrnt",
    "BrkDistrFrnt", "SteRatio" };

  c2_thisId.fParent = c2_parentId;
  sf_mex_check_struct(c2_parentId, c2_u, 29, c2_fieldNames, 0U, NULL);
  c2_thisId.fIdentifier = "m";
  c2_y->m = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_u,
    "m", "m", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "Jz";
  c2_y->Jz = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c2_u, "Jz", "Jz", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "m_sprung";
  c2_y->m_sprung = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_u, "m_sprung", "m_sprung", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "Jx_sprung";
  c2_y->Jx_sprung = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_u, "Jx_sprung", "Jx_sprung", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "Jy_sprung";
  c2_y->Jy_sprung = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_u, "Jy_sprung", "Jy_sprung", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "lf";
  c2_y->lf = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c2_u, "lf", "lf", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "lr";
  c2_y->lr = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c2_u, "lr", "lr", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "L";
  c2_y->L = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_u,
    "L", "L", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "TrackWidth";
  c2_y->TrackWidth = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_u, "TrackWidth", "TrackWidth", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "h";
  c2_y->h = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_u,
    "h", "h", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "HalfRohACd";
  c2_y->HalfRohACd = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_u, "HalfRohACd", "HalfRohACd", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "F_z4_static";
  c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_u,
    "F_z4_static", "F_z4_static", 0)), &c2_thisId, c2_y->F_z4_static);
  c2_thisId.fIdentifier = "Rw";
  c2_y->Rw = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c2_u, "Rw", "Rw", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "r_long";
  c2_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_u, "r_long",
    "r_long", 0)), &c2_thisId, &c2_y->r_long);
  c2_thisId.fIdentifier = "r_lat";
  c2_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_u, "r_lat",
    "r_lat", 0)), &c2_thisId, &c2_y->r_lat);
  c2_thisId.fIdentifier = "r_lever";
  c2_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_u,
    "r_lever", "r_lever", 0)), &c2_thisId, &c2_y->r_lever);
  c2_thisId.fIdentifier = "r_pivot";
  c2_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_u,
    "r_pivot", "r_pivot", 0)), &c2_thisId, &c2_y->r_pivot);
  c2_thisId.fIdentifier = "cw";
  c2_y->cw = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c2_u, "cw", "cw", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "carb_f";
  c2_y->carb_f = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c2_u, "carb_f", "carb_f", 0)),
    &c2_thisId);
  c2_thisId.fIdentifier = "carb_r";
  c2_y->carb_r = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c2_u, "carb_r", "carb_r", 0)),
    &c2_thisId);
  c2_thisId.fIdentifier = "dw";
  c2_y->dw = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c2_u, "dw", "dw", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "Jw";
  c2_y->Jw = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c2_u, "Jw", "Jw", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "C0";
  c2_y->C0 = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c2_u, "C0", "C0", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "RelaxLength";
  c2_y->RelaxLength = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_u, "RelaxLength", "RelaxLength", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "RRC";
  c2_y->RRC = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c2_u, "RRC", "RRC", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "Pmax";
  c2_y->Pmax = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c2_u, "Pmax", "Pmax", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "PropDistrFrnt";
  c2_y->PropDistrFrnt = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_u, "PropDistrFrnt", "PropDistrFrnt", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "BrkDistrFrnt";
  c2_y->BrkDistrFrnt = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_u, "BrkDistrFrnt", "BrkDistrFrnt", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "SteRatio";
  c2_y->SteRatio = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_u, "SteRatio", "SteRatio", 0)), &c2_thisId);
  sf_mex_destroy(&c2_u);
}

static void c2_h_emlrt_marshallIn
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[4])
{
  real_T c2_dv0[4];
  int32_T c2_i17;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv0, 1, 0, 0U, 1, 0U, 2, 1, 4);
  for (c2_i17 = 0; c2_i17 < 4; c2_i17++) {
    c2_y[c2_i17] = c2_dv0[c2_i17];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_i_emlrt_marshallIn
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
   c2_struct_ZKAzdrl7umDGJoC14aoVKC *c2_y)
{
  emlrtMsgIdentifier c2_thisId;
  static const char * c2_fieldNames[4] = { "fl", "fr", "rl", "rr" };

  c2_thisId.fParent = c2_parentId;
  sf_mex_check_struct(c2_parentId, c2_u, 4, c2_fieldNames, 0U, NULL);
  c2_thisId.fIdentifier = "fl";
  c2_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_u, "fl",
    "fl", 0)), &c2_thisId, c2_y->fl);
  c2_thisId.fIdentifier = "fr";
  c2_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_u, "fr",
    "fr", 0)), &c2_thisId, c2_y->fr);
  c2_thisId.fIdentifier = "rl";
  c2_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_u, "rl",
    "rl", 0)), &c2_thisId, c2_y->rl);
  c2_thisId.fIdentifier = "rr";
  c2_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_u, "rr",
    "rr", 0)), &c2_thisId, c2_y->rr);
  sf_mex_destroy(&c2_u);
}

static void c2_j_emlrt_marshallIn
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[3])
{
  real_T c2_dv1[3];
  int32_T c2_i18;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv1, 1, 0, 0U, 1, 0U, 2, 3, 1);
  for (c2_i18 = 0; c2_i18 < 3; c2_i18++) {
    c2_y[c2_i18] = c2_dv1[c2_i18];
  }

  sf_mex_destroy(&c2_u);
}

static c2_struct_r4FNviKwHfdhB8nQjvQv9 c2_k_emlrt_marshallIn
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  c2_struct_r4FNviKwHfdhB8nQjvQv9 c2_y;
  emlrtMsgIdentifier c2_thisId;
  static const char * c2_fieldNames[1] = { "v_set" };

  c2_thisId.fParent = c2_parentId;
  sf_mex_check_struct(c2_parentId, c2_u, 1, c2_fieldNames, 0U, NULL);
  c2_thisId.fIdentifier = "v_set";
  c2_y.v_set = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c2_u, "v_set", "v_set", 0)), &c2_thisId);
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static c2_struct_Y9F1qlBi9AhssksPwemA4G c2_l_emlrt_marshallIn
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  c2_struct_Y9F1qlBi9AhssksPwemA4G c2_y;
  emlrtMsgIdentifier c2_thisId;
  static const char * c2_fieldNames[3] = { "v_x", "F_fz", "F_rz" };

  c2_thisId.fParent = c2_parentId;
  sf_mex_check_struct(c2_parentId, c2_u, 3, c2_fieldNames, 0U, NULL);
  c2_thisId.fIdentifier = "v_x";
  c2_y.v_x = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c2_u, "v_x", "v_x", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "F_fz";
  c2_y.F_fz = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c2_u, "F_fz", "F_fz", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "F_rz";
  c2_y.F_rz = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c2_u, "F_rz", "F_rz", 0)), &c2_thisId);
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_Par;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  c2_struct_iBlsPBO3AGnt69vDoTx5zD c2_y;
  SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c2_b_Par = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_Par), &c2_thisId, &c2_y);
  sf_mex_destroy(&c2_b_Par);
  *(c2_struct_iBlsPBO3AGnt69vDoTx5zD *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_nargout;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c2_nargout = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargout), &c2_thisId);
  sf_mex_destroy(&c2_nargout);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray
  *sf_c2_AllPurposeModel_TyreRelaxation_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_createstruct("structure", 2, 16, 1),
                false);
  c2_info_helper(&c2_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(const mxArray **c2_info)
{
  const mxArray *c2_rhs0 = NULL;
  const mxArray *c2_lhs0 = NULL;
  const mxArray *c2_rhs1 = NULL;
  const mxArray *c2_lhs1 = NULL;
  const mxArray *c2_rhs2 = NULL;
  const mxArray *c2_lhs2 = NULL;
  const mxArray *c2_rhs3 = NULL;
  const mxArray *c2_lhs3 = NULL;
  const mxArray *c2_rhs4 = NULL;
  const mxArray *c2_lhs4 = NULL;
  const mxArray *c2_rhs5 = NULL;
  const mxArray *c2_lhs5 = NULL;
  const mxArray *c2_rhs6 = NULL;
  const mxArray *c2_lhs6 = NULL;
  const mxArray *c2_rhs7 = NULL;
  const mxArray *c2_lhs7 = NULL;
  const mxArray *c2_rhs8 = NULL;
  const mxArray *c2_lhs8 = NULL;
  const mxArray *c2_rhs9 = NULL;
  const mxArray *c2_lhs9 = NULL;
  const mxArray *c2_rhs10 = NULL;
  const mxArray *c2_lhs10 = NULL;
  const mxArray *c2_rhs11 = NULL;
  const mxArray *c2_lhs11 = NULL;
  const mxArray *c2_rhs12 = NULL;
  const mxArray *c2_lhs12 = NULL;
  const mxArray *c2_rhs13 = NULL;
  const mxArray *c2_lhs13 = NULL;
  const mxArray *c2_rhs14 = NULL;
  const mxArray *c2_lhs14 = NULL;
  const mxArray *c2_rhs15 = NULL;
  const mxArray *c2_lhs15 = NULL;
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("mpower"), "name", "name", 0);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c2_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c2_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("ismatrix"), "name", "name", 2);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1331304858U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c2_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("power"), "name", "name", 3);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1395328506U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c2_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 4);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c2_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 5);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 5);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c2_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 6);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c2_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 7);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 7);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c2_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 8);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 8);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c2_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 9);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("floor"), "name", "name", 9);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363713854U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c2_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 10);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c2_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 11);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286818726U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c2_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power"),
                  "context", "context", 12);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 12);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c2_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 13);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("sqrt"), "name", "name", 13);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1343830386U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c2_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_error"), "name", "name",
                  14);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 14);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1343830358U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c2_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_sqrt"), "name",
                  "name", 15);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286818738U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c2_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs15), "lhs", "lhs",
                  15);
  sf_mex_destroy(&c2_rhs0);
  sf_mex_destroy(&c2_lhs0);
  sf_mex_destroy(&c2_rhs1);
  sf_mex_destroy(&c2_lhs1);
  sf_mex_destroy(&c2_rhs2);
  sf_mex_destroy(&c2_lhs2);
  sf_mex_destroy(&c2_rhs3);
  sf_mex_destroy(&c2_lhs3);
  sf_mex_destroy(&c2_rhs4);
  sf_mex_destroy(&c2_lhs4);
  sf_mex_destroy(&c2_rhs5);
  sf_mex_destroy(&c2_lhs5);
  sf_mex_destroy(&c2_rhs6);
  sf_mex_destroy(&c2_lhs6);
  sf_mex_destroy(&c2_rhs7);
  sf_mex_destroy(&c2_lhs7);
  sf_mex_destroy(&c2_rhs8);
  sf_mex_destroy(&c2_lhs8);
  sf_mex_destroy(&c2_rhs9);
  sf_mex_destroy(&c2_lhs9);
  sf_mex_destroy(&c2_rhs10);
  sf_mex_destroy(&c2_lhs10);
  sf_mex_destroy(&c2_rhs11);
  sf_mex_destroy(&c2_lhs11);
  sf_mex_destroy(&c2_rhs12);
  sf_mex_destroy(&c2_lhs12);
  sf_mex_destroy(&c2_rhs13);
  sf_mex_destroy(&c2_lhs13);
  sf_mex_destroy(&c2_rhs14);
  sf_mex_destroy(&c2_lhs14);
  sf_mex_destroy(&c2_rhs15);
  sf_mex_destroy(&c2_lhs15);
}

static const mxArray *c2_emlrt_marshallOut(const char * c2_u)
{
  const mxArray *c2_y = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c2_u)), false);
  return c2_y;
}

static const mxArray *c2_b_emlrt_marshallOut(const uint32_T c2_u)
{
  const mxArray *c2_y = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 7, 0U, 0U, 0U, 0), false);
  return c2_y;
}

static real_T c2_mpower(SFc2_AllPurposeModel_TyreRelaxationInstanceStruct
  *chartInstance, real_T c2_a)
{
  real_T c2_b_a;
  real_T c2_c_a;
  real_T c2_ak;
  real_T c2_d_a;
  c2_b_a = c2_a;
  c2_c_a = c2_b_a;
  c2_eml_scalar_eg(chartInstance);
  c2_ak = c2_c_a;
  c2_d_a = c2_ak;
  c2_eml_scalar_eg(chartInstance);
  return c2_d_a * c2_d_a;
}

static void c2_eml_scalar_eg(SFc2_AllPurposeModel_TyreRelaxationInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c2_eml_error(SFc2_AllPurposeModel_TyreRelaxationInstanceStruct
  *chartInstance)
{
  int32_T c2_i19;
  static char_T c2_cv0[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c2_u[30];
  const mxArray *c2_y = NULL;
  int32_T c2_i20;
  static char_T c2_cv1[4] = { 's', 'q', 'r', 't' };

  char_T c2_b_u[4];
  const mxArray *c2_b_y = NULL;
  (void)chartInstance;
  for (c2_i19 = 0; c2_i19 < 30; c2_i19++) {
    c2_u[c2_i19] = c2_cv0[c2_i19];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 30), false);
  for (c2_i20 = 0; c2_i20 < 4; c2_i20++) {
    c2_b_u[c2_i20] = c2_cv1[c2_i20];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c2_y, 14, c2_b_y));
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static int32_T c2_m_emlrt_marshallIn
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i21;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i21, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i21;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_pos_left1rel_bus_io(void *chartInstanceVoid, void
  *c2_pData)
{
  const mxArray *c2_mxVal = NULL;
  c2_obst_vec2 c2_tmp;
  SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c2_mxVal = NULL;
  c2_tmp.x = *(real_T *)&((char_T *)(c2_obst_vec2 *)c2_pData)[0];
  c2_tmp.y = *(real_T *)&((char_T *)(c2_obst_vec2 *)c2_pData)[8];
  sf_mex_assign(&c2_mxVal, c2_sf_marshallOut(chartInstance, &c2_tmp), false);
  return c2_mxVal;
}

static uint8_T c2_n_emlrt_marshallIn
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c2_b_is_active_c2_AllPurposeModel_TyreRelaxation, const char_T
   *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_o_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_AllPurposeModel_TyreRelaxation), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_AllPurposeModel_TyreRelaxation);
  return c2_y;
}

static uint8_T c2_o_emlrt_marshallIn
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address
  (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  chartInstance->c2_pos_left1rel = (c2_obst_vec2 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c2_pos_left2rel = (c2_obst_vec2 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c2_pos_right1rel = (c2_obst_vec2 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c2_pos_right2rel = (c2_obst_vec2 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c2_pos_right3rel = (c2_obst_vec2 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c2_v_x = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c2_pos_aim_rel = (c2_obst_vec2 *)ssGetOutputPortSignal_wrapper
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

void sf_c2_AllPurposeModel_TyreRelaxation_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1474435698U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1830540698U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1384970299U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2384760863U);
}

mxArray* sf_c2_AllPurposeModel_TyreRelaxation_get_post_codegen_info(void);
mxArray *sf_c2_AllPurposeModel_TyreRelaxation_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("fETxr2yYqHDxjSRVG6kykD");
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
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
    mxArray* mxPostCodegenInfo =
      sf_c2_AllPurposeModel_TyreRelaxation_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c2_AllPurposeModel_TyreRelaxation_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c2_AllPurposeModel_TyreRelaxation_jit_fallback_info(void)
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

mxArray *sf_c2_AllPurposeModel_TyreRelaxation_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c2_AllPurposeModel_TyreRelaxation_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c2_AllPurposeModel_TyreRelaxation
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"pos_aim_rel\",},{M[8],M[0],T\"is_active_c2_AllPurposeModel_TyreRelaxation\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_AllPurposeModel_TyreRelaxation_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _AllPurposeModel_TyreRelaxationMachineNumber_,
           2,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"pos_left1rel");
          _SFD_SET_DATA_PROPS(1,1,1,0,"pos_left2rel");
          _SFD_SET_DATA_PROPS(2,1,1,0,"pos_right1rel");
          _SFD_SET_DATA_PROPS(3,1,1,0,"pos_right2rel");
          _SFD_SET_DATA_PROPS(4,1,1,0,"pos_right3rel");
          _SFD_SET_DATA_PROPS(5,1,1,0,"v_x");
          _SFD_SET_DATA_PROPS(6,2,0,1,"pos_aim_rel");
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
        _SFD_CV_INIT_EML(0,1,1,5,0,0,0,0,0,10,5);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1361);
        _SFD_CV_INIT_EML_IF(0,1,0,501,561,-1,668);
        _SFD_CV_INIT_EML_IF(0,1,1,670,730,-1,837);
        _SFD_CV_INIT_EML_IF(0,1,2,839,901,-1,1011);
        _SFD_CV_INIT_EML_IF(0,1,3,1013,1075,-1,1185);
        _SFD_CV_INIT_EML_IF(0,1,4,1187,1249,-1,1359);

        {
          static int condStart[] = { 504, 532 };

          static int condEnd[] = { 529, 561 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,504,561,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 673, 701 };

          static int condEnd[] = { 698, 730 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,673,730,2,2,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 842, 871 };

          static int condEnd[] = { 868, 901 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,2,842,901,2,4,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 1016, 1045 };

          static int condEnd[] = { 1042, 1075 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,3,1016,1075,2,6,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 1190, 1219 };

          static int condEnd[] = { 1216, 1249 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,4,1190,1249,2,8,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,504,529,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,532,561,-1,2);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,2,673,698,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,3,701,730,-1,2);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,4,842,868,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,5,871,901,-1,2);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,6,1016,1042,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,7,1045,1075,-1,2);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,8,1190,1216,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,9,1219,1249,-1,2);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_pos_left1rel_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_pos_left1rel_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_pos_left1rel_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_pos_left1rel_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_pos_left1rel_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_pos_left1rel_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c2_pos_left1rel);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c2_pos_left2rel);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c2_pos_right1rel);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c2_pos_right2rel);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c2_pos_right3rel);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c2_v_x);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c2_pos_aim_rel);
        _SFD_SET_DATA_VALUE_PTR(7U, &chartInstance->c2_Par);
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
  return "P1mk2yHhULXKHMIBuayfjC";
}

static void sf_opaque_initialize_c2_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_AllPurposeModel_TyreRelaxationInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_AllPurposeModel_TyreRelaxation
    ((SFc2_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
  initialize_c2_AllPurposeModel_TyreRelaxation
    ((SFc2_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  enable_c2_AllPurposeModel_TyreRelaxation
    ((SFc2_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  disable_c2_AllPurposeModel_TyreRelaxation
    ((SFc2_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  sf_gateway_c2_AllPurposeModel_TyreRelaxation
    ((SFc2_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c2_AllPurposeModel_TyreRelaxation
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c2_AllPurposeModel_TyreRelaxation
    ((SFc2_AllPurposeModel_TyreRelaxationInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c2_AllPurposeModel_TyreRelaxation(SimStruct*
  S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c2_AllPurposeModel_TyreRelaxation
    ((SFc2_AllPurposeModel_TyreRelaxationInstanceStruct*)
     chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c2_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_AllPurposeModel_TyreRelaxationInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_AllPurposeModel_TyreRelaxation_optimization_info();
    }

    finalize_c2_AllPurposeModel_TyreRelaxation
      ((SFc2_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_AllPurposeModel_TyreRelaxation
    ((SFc2_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_AllPurposeModel_TyreRelaxation(SimStruct *S)
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
    initialize_params_c2_AllPurposeModel_TyreRelaxation
      ((SFc2_AllPurposeModel_TyreRelaxationInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_AllPurposeModel_TyreRelaxation(SimStruct *S)
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
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,2,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,6);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1828511171U));
  ssSetChecksum1(S,(4277146294U));
  ssSetChecksum2(S,(2557959517U));
  ssSetChecksum3(S,(3496736079U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_AllPurposeModel_TyreRelaxation(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_AllPurposeModel_TyreRelaxation(SimStruct *S)
{
  SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct *)utMalloc
    (sizeof(SFc2_AllPurposeModel_TyreRelaxationInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc2_AllPurposeModel_TyreRelaxationInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c2_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c2_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_AllPurposeModel_TyreRelaxation;
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

void c2_AllPurposeModel_TyreRelaxation_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_AllPurposeModel_TyreRelaxation(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_AllPurposeModel_TyreRelaxation(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_AllPurposeModel_TyreRelaxation(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_AllPurposeModel_TyreRelaxation_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
