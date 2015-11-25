/* Include files */

#include <stddef.h>
#include "blas.h"
#include "AllPurposeModel_TyreRelaxation_sfun.h"
#include "c27_AllPurposeModel_TyreRelaxation.h"
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
static const char * c27_debug_family_names[9] = { "nargin", "nargout",
  "pos_irp3", "Par", "pos_left1rel", "pos_left2rel", "pos_right1rel",
  "pos_right2rel", "pos_right3rel" };

/* Function Declarations */
static void initialize_c27_AllPurposeModel_TyreRelaxation
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void initialize_params_c27_AllPurposeModel_TyreRelaxation
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void enable_c27_AllPurposeModel_TyreRelaxation
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void disable_c27_AllPurposeModel_TyreRelaxation
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void c27_update_debugger_state_c27_AllPurposeModel_TyreRelaxation
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c27_AllPurposeModel_TyreRelaxation
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void set_sim_state_c27_AllPurposeModel_TyreRelaxation
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c27_st);
static void finalize_c27_AllPurposeModel_TyreRelaxation
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void sf_gateway_c27_AllPurposeModel_TyreRelaxation
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void mdl_start_c27_AllPurposeModel_TyreRelaxation
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void c27_chartstep_c27_AllPurposeModel_TyreRelaxation
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void initSimStructsc27_AllPurposeModel_TyreRelaxation
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c27_machineNumber, uint32_T
  c27_chartNumber, uint32_T c27_instanceNumber);
static const mxArray *c27_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData);
static c27_obst_vec2 c27_emlrt_marshallIn
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c27_b_pos_right3rel, const char_T *c27_identifier);
static c27_obst_vec2 c27_b_emlrt_marshallIn
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId);
static real_T c27_c_emlrt_marshallIn
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId);
static void c27_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData);
static const mxArray *c27_b_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData);
static void c27_d_emlrt_marshallIn
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId,
   c27_struct_iBlsPBO3AGnt69vDoTx5zD *c27_y);
static void c27_e_emlrt_marshallIn
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId,
   c27_struct_Nst2vGTExxHsg85EUOj9EH *c27_y);
static c27_struct_HhckT6rntEraqECYVIDvCC c27_f_emlrt_marshallIn
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId);
static void c27_g_emlrt_marshallIn
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId,
   c27_struct_ZCmOWPuqBDw16FSOVVD00 *c27_y);
static void c27_h_emlrt_marshallIn
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId, real_T c27_y[4]);
static void c27_i_emlrt_marshallIn
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId,
   c27_struct_ZKAzdrl7umDGJoC14aoVKC *c27_y);
static void c27_j_emlrt_marshallIn
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId, real_T c27_y[3]);
static c27_struct_r4FNviKwHfdhB8nQjvQv9 c27_k_emlrt_marshallIn
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId);
static c27_struct_Y9F1qlBi9AhssksPwemA4G c27_l_emlrt_marshallIn
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId);
static void c27_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData);
static const mxArray *c27_c_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData);
static const mxArray *c27_d_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData);
static void c27_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData);
static void c27_info_helper(const mxArray **c27_info);
static const mxArray *c27_emlrt_marshallOut(const char * c27_u);
static const mxArray *c27_b_emlrt_marshallOut(const uint32_T c27_u);
static real_T c27_eml_xdotu(SFc27_AllPurposeModel_TyreRelaxationInstanceStruct
  *chartInstance, real_T c27_x[2], real_T c27_y[2]);
static const mxArray *c27_e_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData);
static int32_T c27_m_emlrt_marshallIn
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId);
static void c27_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData);
static const mxArray *c27_pos_irp3_bus_io(void *chartInstanceVoid, void
  *c27_pData);
static const mxArray *c27_pos_left1rel_bus_io(void *chartInstanceVoid, void
  *c27_pData);
static uint8_T c27_n_emlrt_marshallIn
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c27_b_is_active_c27_AllPurposeModel_TyreRelaxation, const char_T
   *c27_identifier);
static uint8_T c27_o_emlrt_marshallIn
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId);
static void init_dsm_address_info
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void init_simulink_io_address
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c27_AllPurposeModel_TyreRelaxation
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  chartInstance->c27_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c27_is_active_c27_AllPurposeModel_TyreRelaxation = 0U;
}

static void initialize_params_c27_AllPurposeModel_TyreRelaxation
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  const mxArray *c27_m0 = NULL;
  const mxArray *c27_mxField;
  const mxArray *c27_m1 = NULL;
  const mxArray *c27_b_mxField;
  c27_struct_iBlsPBO3AGnt69vDoTx5zD c27_r0;
  const mxArray *c27_m2 = NULL;
  const mxArray *c27_c_mxField;
  const mxArray *c27_m3 = NULL;
  const mxArray *c27_d_mxField;
  const mxArray *c27_m4 = NULL;
  const mxArray *c27_e_mxField;
  const mxArray *c27_m5 = NULL;
  const mxArray *c27_f_mxField;
  const mxArray *c27_m6 = NULL;
  const mxArray *c27_g_mxField;
  const mxArray *c27_m7 = NULL;
  const mxArray *c27_h_mxField;
  const mxArray *c27_m8 = NULL;
  const mxArray *c27_i_mxField;
  const mxArray *c27_m9 = NULL;
  const mxArray *c27_j_mxField;
  const mxArray *c27_m10 = NULL;
  const mxArray *c27_k_mxField;
  const mxArray *c27_m11 = NULL;
  const mxArray *c27_l_mxField;
  const mxArray *c27_m12 = NULL;
  const mxArray *c27_m_mxField;
  const mxArray *c27_m13 = NULL;
  const mxArray *c27_n_mxField;
  c27_m0 = sf_mex_get_sfun_param(chartInstance->S, 0, 1);
  c27_mxField = sf_mex_getfield(c27_m0, "Env", "Par", 0);
  c27_m1 = sf_mex_dup(c27_mxField);
  c27_b_mxField = sf_mex_getfield(c27_m1, "g", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_b_mxField), &c27_r0.Env.g, 1, 0, 0U,
                      0, 0U, 0);
  c27_b_mxField = sf_mex_getfield(c27_m1, "left1", "Par", 0);
  c27_m2 = sf_mex_dup(c27_b_mxField);
  c27_c_mxField = sf_mex_getfield(c27_m2, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_c_mxField), &c27_r0.Env.left1.x, 1,
                      0, 0U, 0, 0U, 0);
  c27_c_mxField = sf_mex_getfield(c27_m2, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_c_mxField), &c27_r0.Env.left1.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c27_m2);
  c27_b_mxField = sf_mex_getfield(c27_m1, "right1", "Par", 0);
  c27_m3 = sf_mex_dup(c27_b_mxField);
  c27_d_mxField = sf_mex_getfield(c27_m3, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_d_mxField), &c27_r0.Env.right1.x, 1,
                      0, 0U, 0, 0U, 0);
  c27_d_mxField = sf_mex_getfield(c27_m3, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_d_mxField), &c27_r0.Env.right1.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c27_m3);
  c27_b_mxField = sf_mex_getfield(c27_m1, "right2", "Par", 0);
  c27_m4 = sf_mex_dup(c27_b_mxField);
  c27_e_mxField = sf_mex_getfield(c27_m4, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_e_mxField), &c27_r0.Env.right2.x, 1,
                      0, 0U, 0, 0U, 0);
  c27_e_mxField = sf_mex_getfield(c27_m4, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_e_mxField), &c27_r0.Env.right2.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c27_m4);
  c27_b_mxField = sf_mex_getfield(c27_m1, "left2", "Par", 0);
  c27_m5 = sf_mex_dup(c27_b_mxField);
  c27_f_mxField = sf_mex_getfield(c27_m5, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_f_mxField), &c27_r0.Env.left2.x, 1,
                      0, 0U, 0, 0U, 0);
  c27_f_mxField = sf_mex_getfield(c27_m5, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_f_mxField), &c27_r0.Env.left2.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c27_m5);
  c27_b_mxField = sf_mex_getfield(c27_m1, "right3", "Par", 0);
  c27_m6 = sf_mex_dup(c27_b_mxField);
  c27_g_mxField = sf_mex_getfield(c27_m6, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_g_mxField), &c27_r0.Env.right3.x, 1,
                      0, 0U, 0, 0U, 0);
  c27_g_mxField = sf_mex_getfield(c27_m6, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_g_mxField), &c27_r0.Env.right3.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c27_m6);
  c27_b_mxField = sf_mex_getfield(c27_m1, "mu", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_b_mxField), &c27_r0.Env.mu, 1, 0, 0U,
                      0, 0U, 0);
  sf_mex_destroy(&c27_m1);
  c27_mxField = sf_mex_getfield(c27_m0, "Veh", "Par", 0);
  c27_m7 = sf_mex_dup(c27_mxField);
  c27_h_mxField = sf_mex_getfield(c27_m7, "m", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_h_mxField), &c27_r0.Veh.m, 1, 0, 0U,
                      0, 0U, 0);
  c27_h_mxField = sf_mex_getfield(c27_m7, "Jz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_h_mxField), &c27_r0.Veh.Jz, 1, 0, 0U,
                      0, 0U, 0);
  c27_h_mxField = sf_mex_getfield(c27_m7, "m_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_h_mxField), &c27_r0.Veh.m_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c27_h_mxField = sf_mex_getfield(c27_m7, "Jx_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_h_mxField), &c27_r0.Veh.Jx_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c27_h_mxField = sf_mex_getfield(c27_m7, "Jy_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_h_mxField), &c27_r0.Veh.Jy_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c27_h_mxField = sf_mex_getfield(c27_m7, "lf", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_h_mxField), &c27_r0.Veh.lf, 1, 0, 0U,
                      0, 0U, 0);
  c27_h_mxField = sf_mex_getfield(c27_m7, "lr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_h_mxField), &c27_r0.Veh.lr, 1, 0, 0U,
                      0, 0U, 0);
  c27_h_mxField = sf_mex_getfield(c27_m7, "L", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_h_mxField), &c27_r0.Veh.L, 1, 0, 0U,
                      0, 0U, 0);
  c27_h_mxField = sf_mex_getfield(c27_m7, "TrackWidth", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_h_mxField), &c27_r0.Veh.TrackWidth,
                      1, 0, 0U, 0, 0U, 0);
  c27_h_mxField = sf_mex_getfield(c27_m7, "h", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_h_mxField), &c27_r0.Veh.h, 1, 0, 0U,
                      0, 0U, 0);
  c27_h_mxField = sf_mex_getfield(c27_m7, "HalfRohACd", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_h_mxField), &c27_r0.Veh.HalfRohACd,
                      1, 0, 0U, 0, 0U, 0);
  c27_h_mxField = sf_mex_getfield(c27_m7, "F_z4_static", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_h_mxField), c27_r0.Veh.F_z4_static,
                      1, 0, 0U, 1, 0U, 2, 1, 4);
  c27_h_mxField = sf_mex_getfield(c27_m7, "Rw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_h_mxField), &c27_r0.Veh.Rw, 1, 0, 0U,
                      0, 0U, 0);
  c27_h_mxField = sf_mex_getfield(c27_m7, "r_long", "Par", 0);
  c27_m8 = sf_mex_dup(c27_h_mxField);
  c27_i_mxField = sf_mex_getfield(c27_m8, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_i_mxField), c27_r0.Veh.r_long.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c27_i_mxField = sf_mex_getfield(c27_m8, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_i_mxField), c27_r0.Veh.r_long.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c27_i_mxField = sf_mex_getfield(c27_m8, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_i_mxField), c27_r0.Veh.r_long.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c27_i_mxField = sf_mex_getfield(c27_m8, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_i_mxField), c27_r0.Veh.r_long.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c27_m8);
  c27_h_mxField = sf_mex_getfield(c27_m7, "r_lat", "Par", 0);
  c27_m9 = sf_mex_dup(c27_h_mxField);
  c27_j_mxField = sf_mex_getfield(c27_m9, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_j_mxField), c27_r0.Veh.r_lat.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c27_j_mxField = sf_mex_getfield(c27_m9, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_j_mxField), c27_r0.Veh.r_lat.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c27_j_mxField = sf_mex_getfield(c27_m9, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_j_mxField), c27_r0.Veh.r_lat.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c27_j_mxField = sf_mex_getfield(c27_m9, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_j_mxField), c27_r0.Veh.r_lat.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c27_m9);
  c27_h_mxField = sf_mex_getfield(c27_m7, "r_lever", "Par", 0);
  c27_m10 = sf_mex_dup(c27_h_mxField);
  c27_k_mxField = sf_mex_getfield(c27_m10, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_k_mxField), c27_r0.Veh.r_lever.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c27_k_mxField = sf_mex_getfield(c27_m10, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_k_mxField), c27_r0.Veh.r_lever.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c27_k_mxField = sf_mex_getfield(c27_m10, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_k_mxField), c27_r0.Veh.r_lever.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c27_k_mxField = sf_mex_getfield(c27_m10, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_k_mxField), c27_r0.Veh.r_lever.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c27_m10);
  c27_h_mxField = sf_mex_getfield(c27_m7, "r_pivot", "Par", 0);
  c27_m11 = sf_mex_dup(c27_h_mxField);
  c27_l_mxField = sf_mex_getfield(c27_m11, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_l_mxField), c27_r0.Veh.r_pivot.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c27_l_mxField = sf_mex_getfield(c27_m11, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_l_mxField), c27_r0.Veh.r_pivot.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c27_l_mxField = sf_mex_getfield(c27_m11, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_l_mxField), c27_r0.Veh.r_pivot.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c27_l_mxField = sf_mex_getfield(c27_m11, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_l_mxField), c27_r0.Veh.r_pivot.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c27_m11);
  c27_h_mxField = sf_mex_getfield(c27_m7, "cw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_h_mxField), &c27_r0.Veh.cw, 1, 0, 0U,
                      0, 0U, 0);
  c27_h_mxField = sf_mex_getfield(c27_m7, "carb_f", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_h_mxField), &c27_r0.Veh.carb_f, 1, 0,
                      0U, 0, 0U, 0);
  c27_h_mxField = sf_mex_getfield(c27_m7, "carb_r", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_h_mxField), &c27_r0.Veh.carb_r, 1, 0,
                      0U, 0, 0U, 0);
  c27_h_mxField = sf_mex_getfield(c27_m7, "dw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_h_mxField), &c27_r0.Veh.dw, 1, 0, 0U,
                      0, 0U, 0);
  c27_h_mxField = sf_mex_getfield(c27_m7, "Jw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_h_mxField), &c27_r0.Veh.Jw, 1, 0, 0U,
                      0, 0U, 0);
  c27_h_mxField = sf_mex_getfield(c27_m7, "C0", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_h_mxField), &c27_r0.Veh.C0, 1, 0, 0U,
                      0, 0U, 0);
  c27_h_mxField = sf_mex_getfield(c27_m7, "RelaxLength", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_h_mxField), &c27_r0.Veh.RelaxLength,
                      1, 0, 0U, 0, 0U, 0);
  c27_h_mxField = sf_mex_getfield(c27_m7, "RRC", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_h_mxField), &c27_r0.Veh.RRC, 1, 0,
                      0U, 0, 0U, 0);
  c27_h_mxField = sf_mex_getfield(c27_m7, "Pmax", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_h_mxField), &c27_r0.Veh.Pmax, 1, 0,
                      0U, 0, 0U, 0);
  c27_h_mxField = sf_mex_getfield(c27_m7, "PropDistrFrnt", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_h_mxField),
                      &c27_r0.Veh.PropDistrFrnt, 1, 0, 0U, 0, 0U, 0);
  c27_h_mxField = sf_mex_getfield(c27_m7, "BrkDistrFrnt", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_h_mxField), &c27_r0.Veh.BrkDistrFrnt,
                      1, 0, 0U, 0, 0U, 0);
  c27_h_mxField = sf_mex_getfield(c27_m7, "SteRatio", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_h_mxField), &c27_r0.Veh.SteRatio, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c27_m7);
  c27_mxField = sf_mex_getfield(c27_m0, "Drvr", "Par", 0);
  c27_m12 = sf_mex_dup(c27_mxField);
  c27_m_mxField = sf_mex_getfield(c27_m12, "v_set", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_m_mxField), &c27_r0.Drvr.v_set, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c27_m12);
  c27_mxField = sf_mex_getfield(c27_m0, "Init", "Par", 0);
  c27_m13 = sf_mex_dup(c27_mxField);
  c27_n_mxField = sf_mex_getfield(c27_m13, "v_x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_n_mxField), &c27_r0.Init.v_x, 1, 0,
                      0U, 0, 0U, 0);
  c27_n_mxField = sf_mex_getfield(c27_m13, "F_fz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_n_mxField), &c27_r0.Init.F_fz, 1, 0,
                      0U, 0, 0U, 0);
  c27_n_mxField = sf_mex_getfield(c27_m13, "F_rz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c27_n_mxField), &c27_r0.Init.F_rz, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c27_m13);
  sf_mex_destroy(&c27_m0);
  chartInstance->c27_Par = c27_r0;
}

static void enable_c27_AllPurposeModel_TyreRelaxation
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c27_AllPurposeModel_TyreRelaxation
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c27_update_debugger_state_c27_AllPurposeModel_TyreRelaxation
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c27_AllPurposeModel_TyreRelaxation
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  const mxArray *c27_st;
  const mxArray *c27_y = NULL;
  const mxArray *c27_b_y = NULL;
  real_T c27_u;
  const mxArray *c27_c_y = NULL;
  real_T c27_b_u;
  const mxArray *c27_d_y = NULL;
  const mxArray *c27_e_y = NULL;
  real_T c27_c_u;
  const mxArray *c27_f_y = NULL;
  real_T c27_d_u;
  const mxArray *c27_g_y = NULL;
  const mxArray *c27_h_y = NULL;
  real_T c27_e_u;
  const mxArray *c27_i_y = NULL;
  real_T c27_f_u;
  const mxArray *c27_j_y = NULL;
  const mxArray *c27_k_y = NULL;
  real_T c27_g_u;
  const mxArray *c27_l_y = NULL;
  real_T c27_h_u;
  const mxArray *c27_m_y = NULL;
  const mxArray *c27_n_y = NULL;
  real_T c27_i_u;
  const mxArray *c27_o_y = NULL;
  real_T c27_j_u;
  const mxArray *c27_p_y = NULL;
  uint8_T c27_hoistedGlobal;
  uint8_T c27_k_u;
  const mxArray *c27_q_y = NULL;
  c27_st = NULL;
  c27_st = NULL;
  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_createcellmatrix(6, 1), false);
  c27_b_y = NULL;
  sf_mex_assign(&c27_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c27_u = *(real_T *)&((char_T *)chartInstance->c27_pos_left1rel)[0];
  c27_c_y = NULL;
  sf_mex_assign(&c27_c_y, sf_mex_create("y", &c27_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c27_b_y, c27_c_y, "x", "x", 0);
  c27_b_u = *(real_T *)&((char_T *)chartInstance->c27_pos_left1rel)[8];
  c27_d_y = NULL;
  sf_mex_assign(&c27_d_y, sf_mex_create("y", &c27_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c27_b_y, c27_d_y, "y", "y", 0);
  sf_mex_setcell(c27_y, 0, c27_b_y);
  c27_e_y = NULL;
  sf_mex_assign(&c27_e_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c27_c_u = *(real_T *)&((char_T *)chartInstance->c27_pos_left2rel)[0];
  c27_f_y = NULL;
  sf_mex_assign(&c27_f_y, sf_mex_create("y", &c27_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c27_e_y, c27_f_y, "x", "x", 0);
  c27_d_u = *(real_T *)&((char_T *)chartInstance->c27_pos_left2rel)[8];
  c27_g_y = NULL;
  sf_mex_assign(&c27_g_y, sf_mex_create("y", &c27_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c27_e_y, c27_g_y, "y", "y", 0);
  sf_mex_setcell(c27_y, 1, c27_e_y);
  c27_h_y = NULL;
  sf_mex_assign(&c27_h_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c27_e_u = *(real_T *)&((char_T *)chartInstance->c27_pos_right1rel)[0];
  c27_i_y = NULL;
  sf_mex_assign(&c27_i_y, sf_mex_create("y", &c27_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c27_h_y, c27_i_y, "x", "x", 0);
  c27_f_u = *(real_T *)&((char_T *)chartInstance->c27_pos_right1rel)[8];
  c27_j_y = NULL;
  sf_mex_assign(&c27_j_y, sf_mex_create("y", &c27_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c27_h_y, c27_j_y, "y", "y", 0);
  sf_mex_setcell(c27_y, 2, c27_h_y);
  c27_k_y = NULL;
  sf_mex_assign(&c27_k_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c27_g_u = *(real_T *)&((char_T *)chartInstance->c27_pos_right2rel)[0];
  c27_l_y = NULL;
  sf_mex_assign(&c27_l_y, sf_mex_create("y", &c27_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c27_k_y, c27_l_y, "x", "x", 0);
  c27_h_u = *(real_T *)&((char_T *)chartInstance->c27_pos_right2rel)[8];
  c27_m_y = NULL;
  sf_mex_assign(&c27_m_y, sf_mex_create("y", &c27_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c27_k_y, c27_m_y, "y", "y", 0);
  sf_mex_setcell(c27_y, 3, c27_k_y);
  c27_n_y = NULL;
  sf_mex_assign(&c27_n_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c27_i_u = *(real_T *)&((char_T *)chartInstance->c27_pos_right3rel)[0];
  c27_o_y = NULL;
  sf_mex_assign(&c27_o_y, sf_mex_create("y", &c27_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c27_n_y, c27_o_y, "x", "x", 0);
  c27_j_u = *(real_T *)&((char_T *)chartInstance->c27_pos_right3rel)[8];
  c27_p_y = NULL;
  sf_mex_assign(&c27_p_y, sf_mex_create("y", &c27_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c27_n_y, c27_p_y, "y", "y", 0);
  sf_mex_setcell(c27_y, 4, c27_n_y);
  c27_hoistedGlobal =
    chartInstance->c27_is_active_c27_AllPurposeModel_TyreRelaxation;
  c27_k_u = c27_hoistedGlobal;
  c27_q_y = NULL;
  sf_mex_assign(&c27_q_y, sf_mex_create("y", &c27_k_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c27_y, 5, c27_q_y);
  sf_mex_assign(&c27_st, c27_y, false);
  return c27_st;
}

static void set_sim_state_c27_AllPurposeModel_TyreRelaxation
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c27_st)
{
  const mxArray *c27_u;
  c27_obst_vec2 c27_r1;
  c27_obst_vec2 c27_r2;
  c27_obst_vec2 c27_r3;
  c27_obst_vec2 c27_r4;
  c27_obst_vec2 c27_r5;
  chartInstance->c27_doneDoubleBufferReInit = true;
  c27_u = sf_mex_dup(c27_st);
  c27_r1 = c27_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c27_u,
    0)), "pos_left1rel");
  *(real_T *)&((char_T *)chartInstance->c27_pos_left1rel)[0] = c27_r1.x;
  *(real_T *)&((char_T *)chartInstance->c27_pos_left1rel)[8] = c27_r1.y;
  c27_r2 = c27_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c27_u,
    1)), "pos_left2rel");
  *(real_T *)&((char_T *)chartInstance->c27_pos_left2rel)[0] = c27_r2.x;
  *(real_T *)&((char_T *)chartInstance->c27_pos_left2rel)[8] = c27_r2.y;
  c27_r3 = c27_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c27_u,
    2)), "pos_right1rel");
  *(real_T *)&((char_T *)chartInstance->c27_pos_right1rel)[0] = c27_r3.x;
  *(real_T *)&((char_T *)chartInstance->c27_pos_right1rel)[8] = c27_r3.y;
  c27_r4 = c27_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c27_u,
    3)), "pos_right2rel");
  *(real_T *)&((char_T *)chartInstance->c27_pos_right2rel)[0] = c27_r4.x;
  *(real_T *)&((char_T *)chartInstance->c27_pos_right2rel)[8] = c27_r4.y;
  c27_r5 = c27_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c27_u,
    4)), "pos_right3rel");
  *(real_T *)&((char_T *)chartInstance->c27_pos_right3rel)[0] = c27_r5.x;
  *(real_T *)&((char_T *)chartInstance->c27_pos_right3rel)[8] = c27_r5.y;
  chartInstance->c27_is_active_c27_AllPurposeModel_TyreRelaxation =
    c27_n_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c27_u, 5)),
    "is_active_c27_AllPurposeModel_TyreRelaxation");
  sf_mex_destroy(&c27_u);
  c27_update_debugger_state_c27_AllPurposeModel_TyreRelaxation(chartInstance);
  sf_mex_destroy(&c27_st);
}

static void finalize_c27_AllPurposeModel_TyreRelaxation
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c27_AllPurposeModel_TyreRelaxation
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 17U, chartInstance->c27_sfEvent);
  chartInstance->c27_sfEvent = CALL_EVENT;
  c27_chartstep_c27_AllPurposeModel_TyreRelaxation(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_AllPurposeModel_TyreRelaxationMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void mdl_start_c27_AllPurposeModel_TyreRelaxation
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c27_chartstep_c27_AllPurposeModel_TyreRelaxation
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  c27_irp_vec3 c27_b_pos_irp3;
  c27_struct_iBlsPBO3AGnt69vDoTx5zD c27_b_Par;
  uint32_T c27_debug_family_var_map[9];
  real_T c27_nargin = 2.0;
  real_T c27_nargout = 5.0;
  c27_obst_vec2 c27_b_pos_left1rel;
  c27_obst_vec2 c27_b_pos_left2rel;
  c27_obst_vec2 c27_b_pos_right1rel;
  c27_obst_vec2 c27_b_pos_right2rel;
  c27_obst_vec2 c27_b_pos_right3rel;
  real_T c27_x;
  real_T c27_b_x;
  real_T c27_c_x;
  real_T c27_d_x;
  real_T c27_a[2];
  real_T c27_b[2];
  int32_T c27_i0;
  real_T c27_b_a[2];
  int32_T c27_i1;
  real_T c27_b_b[2];
  real_T c27_y;
  real_T c27_e_x;
  real_T c27_f_x;
  real_T c27_g_x;
  real_T c27_h_x;
  int32_T c27_i2;
  real_T c27_c_a[2];
  int32_T c27_i3;
  real_T c27_c_b[2];
  real_T c27_b_y;
  real_T c27_i_x;
  real_T c27_j_x;
  real_T c27_k_x;
  real_T c27_l_x;
  int32_T c27_i4;
  real_T c27_d_a[2];
  int32_T c27_i5;
  real_T c27_d_b[2];
  real_T c27_c_y;
  real_T c27_m_x;
  real_T c27_n_x;
  real_T c27_o_x;
  real_T c27_p_x;
  int32_T c27_i6;
  real_T c27_e_a[2];
  int32_T c27_i7;
  real_T c27_e_b[2];
  real_T c27_d_y;
  real_T c27_q_x;
  real_T c27_r_x;
  real_T c27_s_x;
  real_T c27_t_x;
  int32_T c27_i8;
  real_T c27_f_a[2];
  int32_T c27_i9;
  real_T c27_f_b[2];
  real_T c27_e_y;
  real_T c27_u_x;
  real_T c27_v_x;
  real_T c27_w_x;
  real_T c27_x_x;
  int32_T c27_i10;
  real_T c27_g_a[2];
  int32_T c27_i11;
  real_T c27_g_b[2];
  real_T c27_f_y;
  real_T c27_y_x;
  real_T c27_ab_x;
  real_T c27_bb_x;
  real_T c27_cb_x;
  int32_T c27_i12;
  real_T c27_h_a[2];
  int32_T c27_i13;
  real_T c27_h_b[2];
  real_T c27_g_y;
  real_T c27_db_x;
  real_T c27_eb_x;
  real_T c27_fb_x;
  real_T c27_gb_x;
  int32_T c27_i14;
  real_T c27_i_a[2];
  int32_T c27_i15;
  real_T c27_i_b[2];
  real_T c27_h_y;
  real_T c27_hb_x;
  real_T c27_ib_x;
  real_T c27_jb_x;
  real_T c27_kb_x;
  int32_T c27_i16;
  real_T c27_j_a[2];
  int32_T c27_i17;
  real_T c27_j_b[2];
  real_T c27_i_y;
  real_T c27_lb_x;
  real_T c27_mb_x;
  real_T c27_nb_x;
  real_T c27_ob_x;
  int32_T c27_i18;
  real_T c27_k_a[2];
  int32_T c27_i19;
  real_T c27_k_b[2];
  real_T c27_j_y;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 17U, chartInstance->c27_sfEvent);
  c27_b_pos_irp3.x = *(real_T *)&((char_T *)chartInstance->c27_pos_irp3)[0];
  c27_b_pos_irp3.y = *(real_T *)&((char_T *)chartInstance->c27_pos_irp3)[8];
  c27_b_pos_irp3.rotz = *(real_T *)&((char_T *)chartInstance->c27_pos_irp3)[16];
  c27_b_Par = chartInstance->c27_Par;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c27_debug_family_names,
    c27_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_nargin, 0U, c27_d_sf_marshallOut,
    c27_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_nargout, 1U, c27_d_sf_marshallOut,
    c27_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c27_b_pos_irp3, 2U, c27_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_b_Par, 3U, c27_b_sf_marshallOut,
    c27_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_b_pos_left1rel, 4U,
    c27_sf_marshallOut, c27_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_b_pos_left2rel, 5U,
    c27_sf_marshallOut, c27_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_b_pos_right1rel, 6U,
    c27_sf_marshallOut, c27_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_b_pos_right2rel, 7U,
    c27_sf_marshallOut, c27_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_b_pos_right3rel, 8U,
    c27_sf_marshallOut, c27_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 8);
  c27_x = c27_b_pos_irp3.rotz;
  c27_b_x = c27_x;
  c27_b_x = muDoubleScalarCos(c27_b_x);
  c27_c_x = c27_b_pos_irp3.rotz;
  c27_d_x = c27_c_x;
  c27_d_x = muDoubleScalarSin(c27_d_x);
  c27_a[0] = c27_b_x;
  c27_a[1] = c27_d_x;
  c27_b[0] = c27_b_Par.Env.left1.x - c27_b_pos_irp3.x;
  c27_b[1] = c27_b_Par.Env.left1.y - c27_b_pos_irp3.y;
  for (c27_i0 = 0; c27_i0 < 2; c27_i0++) {
    c27_b_a[c27_i0] = c27_a[c27_i0];
  }

  for (c27_i1 = 0; c27_i1 < 2; c27_i1++) {
    c27_b_b[c27_i1] = c27_b[c27_i1];
  }

  c27_y = c27_eml_xdotu(chartInstance, c27_b_a, c27_b_b);
  c27_b_pos_left1rel.x = c27_y;
  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 9);
  c27_e_x = c27_b_pos_irp3.rotz;
  c27_f_x = c27_e_x;
  c27_f_x = muDoubleScalarSin(c27_f_x);
  c27_g_x = c27_b_pos_irp3.rotz;
  c27_h_x = c27_g_x;
  c27_h_x = muDoubleScalarCos(c27_h_x);
  c27_a[0] = -c27_f_x;
  c27_a[1] = c27_h_x;
  c27_b[0] = c27_b_Par.Env.left1.x - c27_b_pos_irp3.x;
  c27_b[1] = c27_b_Par.Env.left1.y - c27_b_pos_irp3.y;
  for (c27_i2 = 0; c27_i2 < 2; c27_i2++) {
    c27_c_a[c27_i2] = c27_a[c27_i2];
  }

  for (c27_i3 = 0; c27_i3 < 2; c27_i3++) {
    c27_c_b[c27_i3] = c27_b[c27_i3];
  }

  c27_b_y = c27_eml_xdotu(chartInstance, c27_c_a, c27_c_b);
  c27_b_pos_left1rel.y = c27_b_y;
  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 10);
  c27_i_x = c27_b_pos_irp3.rotz;
  c27_j_x = c27_i_x;
  c27_j_x = muDoubleScalarCos(c27_j_x);
  c27_k_x = c27_b_pos_irp3.rotz;
  c27_l_x = c27_k_x;
  c27_l_x = muDoubleScalarSin(c27_l_x);
  c27_a[0] = c27_j_x;
  c27_a[1] = c27_l_x;
  c27_b[0] = c27_b_Par.Env.left2.x - c27_b_pos_irp3.x;
  c27_b[1] = c27_b_Par.Env.left2.y - c27_b_pos_irp3.y;
  for (c27_i4 = 0; c27_i4 < 2; c27_i4++) {
    c27_d_a[c27_i4] = c27_a[c27_i4];
  }

  for (c27_i5 = 0; c27_i5 < 2; c27_i5++) {
    c27_d_b[c27_i5] = c27_b[c27_i5];
  }

  c27_c_y = c27_eml_xdotu(chartInstance, c27_d_a, c27_d_b);
  c27_b_pos_left2rel.x = c27_c_y;
  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 11);
  c27_m_x = c27_b_pos_irp3.rotz;
  c27_n_x = c27_m_x;
  c27_n_x = muDoubleScalarSin(c27_n_x);
  c27_o_x = c27_b_pos_irp3.rotz;
  c27_p_x = c27_o_x;
  c27_p_x = muDoubleScalarCos(c27_p_x);
  c27_a[0] = -c27_n_x;
  c27_a[1] = c27_p_x;
  c27_b[0] = c27_b_Par.Env.left2.x - c27_b_pos_irp3.x;
  c27_b[1] = c27_b_Par.Env.left2.y - c27_b_pos_irp3.y;
  for (c27_i6 = 0; c27_i6 < 2; c27_i6++) {
    c27_e_a[c27_i6] = c27_a[c27_i6];
  }

  for (c27_i7 = 0; c27_i7 < 2; c27_i7++) {
    c27_e_b[c27_i7] = c27_b[c27_i7];
  }

  c27_d_y = c27_eml_xdotu(chartInstance, c27_e_a, c27_e_b);
  c27_b_pos_left2rel.y = c27_d_y;
  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 13);
  c27_q_x = c27_b_pos_irp3.rotz;
  c27_r_x = c27_q_x;
  c27_r_x = muDoubleScalarCos(c27_r_x);
  c27_s_x = c27_b_pos_irp3.rotz;
  c27_t_x = c27_s_x;
  c27_t_x = muDoubleScalarSin(c27_t_x);
  c27_a[0] = c27_r_x;
  c27_a[1] = c27_t_x;
  c27_b[0] = c27_b_Par.Env.right1.x - c27_b_pos_irp3.x;
  c27_b[1] = c27_b_Par.Env.right1.y - c27_b_pos_irp3.y;
  for (c27_i8 = 0; c27_i8 < 2; c27_i8++) {
    c27_f_a[c27_i8] = c27_a[c27_i8];
  }

  for (c27_i9 = 0; c27_i9 < 2; c27_i9++) {
    c27_f_b[c27_i9] = c27_b[c27_i9];
  }

  c27_e_y = c27_eml_xdotu(chartInstance, c27_f_a, c27_f_b);
  c27_b_pos_right1rel.x = c27_e_y;
  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 14);
  c27_u_x = c27_b_pos_irp3.rotz;
  c27_v_x = c27_u_x;
  c27_v_x = muDoubleScalarSin(c27_v_x);
  c27_w_x = c27_b_pos_irp3.rotz;
  c27_x_x = c27_w_x;
  c27_x_x = muDoubleScalarCos(c27_x_x);
  c27_a[0] = -c27_v_x;
  c27_a[1] = c27_x_x;
  c27_b[0] = c27_b_Par.Env.right1.x - c27_b_pos_irp3.x;
  c27_b[1] = c27_b_Par.Env.right1.y - c27_b_pos_irp3.y;
  for (c27_i10 = 0; c27_i10 < 2; c27_i10++) {
    c27_g_a[c27_i10] = c27_a[c27_i10];
  }

  for (c27_i11 = 0; c27_i11 < 2; c27_i11++) {
    c27_g_b[c27_i11] = c27_b[c27_i11];
  }

  c27_f_y = c27_eml_xdotu(chartInstance, c27_g_a, c27_g_b);
  c27_b_pos_right1rel.y = c27_f_y;
  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 15);
  c27_y_x = c27_b_pos_irp3.rotz;
  c27_ab_x = c27_y_x;
  c27_ab_x = muDoubleScalarCos(c27_ab_x);
  c27_bb_x = c27_b_pos_irp3.rotz;
  c27_cb_x = c27_bb_x;
  c27_cb_x = muDoubleScalarSin(c27_cb_x);
  c27_a[0] = c27_ab_x;
  c27_a[1] = c27_cb_x;
  c27_b[0] = c27_b_Par.Env.right2.x - c27_b_pos_irp3.x;
  c27_b[1] = c27_b_Par.Env.right2.y - c27_b_pos_irp3.y;
  for (c27_i12 = 0; c27_i12 < 2; c27_i12++) {
    c27_h_a[c27_i12] = c27_a[c27_i12];
  }

  for (c27_i13 = 0; c27_i13 < 2; c27_i13++) {
    c27_h_b[c27_i13] = c27_b[c27_i13];
  }

  c27_g_y = c27_eml_xdotu(chartInstance, c27_h_a, c27_h_b);
  c27_b_pos_right2rel.x = c27_g_y;
  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 16);
  c27_db_x = c27_b_pos_irp3.rotz;
  c27_eb_x = c27_db_x;
  c27_eb_x = muDoubleScalarSin(c27_eb_x);
  c27_fb_x = c27_b_pos_irp3.rotz;
  c27_gb_x = c27_fb_x;
  c27_gb_x = muDoubleScalarCos(c27_gb_x);
  c27_a[0] = -c27_eb_x;
  c27_a[1] = c27_gb_x;
  c27_b[0] = c27_b_Par.Env.right2.x - c27_b_pos_irp3.x;
  c27_b[1] = c27_b_Par.Env.right2.y - c27_b_pos_irp3.y;
  for (c27_i14 = 0; c27_i14 < 2; c27_i14++) {
    c27_i_a[c27_i14] = c27_a[c27_i14];
  }

  for (c27_i15 = 0; c27_i15 < 2; c27_i15++) {
    c27_i_b[c27_i15] = c27_b[c27_i15];
  }

  c27_h_y = c27_eml_xdotu(chartInstance, c27_i_a, c27_i_b);
  c27_b_pos_right2rel.y = c27_h_y;
  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 17);
  c27_hb_x = c27_b_pos_irp3.rotz;
  c27_ib_x = c27_hb_x;
  c27_ib_x = muDoubleScalarCos(c27_ib_x);
  c27_jb_x = c27_b_pos_irp3.rotz;
  c27_kb_x = c27_jb_x;
  c27_kb_x = muDoubleScalarSin(c27_kb_x);
  c27_a[0] = c27_ib_x;
  c27_a[1] = c27_kb_x;
  c27_b[0] = c27_b_Par.Env.right3.x - c27_b_pos_irp3.x;
  c27_b[1] = c27_b_Par.Env.right3.y - c27_b_pos_irp3.y;
  for (c27_i16 = 0; c27_i16 < 2; c27_i16++) {
    c27_j_a[c27_i16] = c27_a[c27_i16];
  }

  for (c27_i17 = 0; c27_i17 < 2; c27_i17++) {
    c27_j_b[c27_i17] = c27_b[c27_i17];
  }

  c27_i_y = c27_eml_xdotu(chartInstance, c27_j_a, c27_j_b);
  c27_b_pos_right3rel.x = c27_i_y;
  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 18);
  c27_lb_x = c27_b_pos_irp3.rotz;
  c27_mb_x = c27_lb_x;
  c27_mb_x = muDoubleScalarSin(c27_mb_x);
  c27_nb_x = c27_b_pos_irp3.rotz;
  c27_ob_x = c27_nb_x;
  c27_ob_x = muDoubleScalarCos(c27_ob_x);
  c27_a[0] = -c27_mb_x;
  c27_a[1] = c27_ob_x;
  c27_b[0] = c27_b_Par.Env.right3.x - c27_b_pos_irp3.x;
  c27_b[1] = c27_b_Par.Env.right3.y - c27_b_pos_irp3.y;
  for (c27_i18 = 0; c27_i18 < 2; c27_i18++) {
    c27_k_a[c27_i18] = c27_a[c27_i18];
  }

  for (c27_i19 = 0; c27_i19 < 2; c27_i19++) {
    c27_k_b[c27_i19] = c27_b[c27_i19];
  }

  c27_j_y = c27_eml_xdotu(chartInstance, c27_k_a, c27_k_b);
  c27_b_pos_right3rel.y = c27_j_y;
  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, -18);
  _SFD_SYMBOL_SCOPE_POP();
  *(real_T *)&((char_T *)chartInstance->c27_pos_left1rel)[0] =
    c27_b_pos_left1rel.x;
  *(real_T *)&((char_T *)chartInstance->c27_pos_left1rel)[8] =
    c27_b_pos_left1rel.y;
  *(real_T *)&((char_T *)chartInstance->c27_pos_left2rel)[0] =
    c27_b_pos_left2rel.x;
  *(real_T *)&((char_T *)chartInstance->c27_pos_left2rel)[8] =
    c27_b_pos_left2rel.y;
  *(real_T *)&((char_T *)chartInstance->c27_pos_right1rel)[0] =
    c27_b_pos_right1rel.x;
  *(real_T *)&((char_T *)chartInstance->c27_pos_right1rel)[8] =
    c27_b_pos_right1rel.y;
  *(real_T *)&((char_T *)chartInstance->c27_pos_right2rel)[0] =
    c27_b_pos_right2rel.x;
  *(real_T *)&((char_T *)chartInstance->c27_pos_right2rel)[8] =
    c27_b_pos_right2rel.y;
  *(real_T *)&((char_T *)chartInstance->c27_pos_right3rel)[0] =
    c27_b_pos_right3rel.x;
  *(real_T *)&((char_T *)chartInstance->c27_pos_right3rel)[8] =
    c27_b_pos_right3rel.y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 17U, chartInstance->c27_sfEvent);
}

static void initSimStructsc27_AllPurposeModel_TyreRelaxation
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c27_machineNumber, uint32_T
  c27_chartNumber, uint32_T c27_instanceNumber)
{
  (void)c27_machineNumber;
  (void)c27_chartNumber;
  (void)c27_instanceNumber;
}

static const mxArray *c27_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData)
{
  const mxArray *c27_mxArrayOutData = NULL;
  c27_obst_vec2 c27_u;
  const mxArray *c27_y = NULL;
  real_T c27_b_u;
  const mxArray *c27_b_y = NULL;
  real_T c27_c_u;
  const mxArray *c27_c_y = NULL;
  SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c27_mxArrayOutData = NULL;
  c27_u = *(c27_obst_vec2 *)c27_inData;
  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c27_b_u = c27_u.x;
  c27_b_y = NULL;
  sf_mex_assign(&c27_b_y, sf_mex_create("y", &c27_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c27_y, c27_b_y, "x", "x", 0);
  c27_c_u = c27_u.y;
  c27_c_y = NULL;
  sf_mex_assign(&c27_c_y, sf_mex_create("y", &c27_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c27_y, c27_c_y, "y", "y", 0);
  sf_mex_assign(&c27_mxArrayOutData, c27_y, false);
  return c27_mxArrayOutData;
}

static c27_obst_vec2 c27_emlrt_marshallIn
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c27_b_pos_right3rel, const char_T *c27_identifier)
{
  c27_obst_vec2 c27_y;
  emlrtMsgIdentifier c27_thisId;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_y = c27_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c27_b_pos_right3rel),
    &c27_thisId);
  sf_mex_destroy(&c27_b_pos_right3rel);
  return c27_y;
}

static c27_obst_vec2 c27_b_emlrt_marshallIn
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId)
{
  c27_obst_vec2 c27_y;
  emlrtMsgIdentifier c27_thisId;
  static const char * c27_fieldNames[2] = { "x", "y" };

  c27_thisId.fParent = c27_parentId;
  sf_mex_check_struct(c27_parentId, c27_u, 2, c27_fieldNames, 0U, NULL);
  c27_thisId.fIdentifier = "x";
  c27_y.x = c27_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c27_u, "x", "x", 0)), &c27_thisId);
  c27_thisId.fIdentifier = "y";
  c27_y.y = c27_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c27_u, "y", "y", 0)), &c27_thisId);
  sf_mex_destroy(&c27_u);
  return c27_y;
}

static real_T c27_c_emlrt_marshallIn
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId)
{
  real_T c27_y;
  real_T c27_d0;
  (void)chartInstance;
  sf_mex_import(c27_parentId, sf_mex_dup(c27_u), &c27_d0, 1, 0, 0U, 0, 0U, 0);
  c27_y = c27_d0;
  sf_mex_destroy(&c27_u);
  return c27_y;
}

static void c27_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData)
{
  const mxArray *c27_b_pos_right3rel;
  const char_T *c27_identifier;
  emlrtMsgIdentifier c27_thisId;
  c27_obst_vec2 c27_y;
  SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c27_b_pos_right3rel = sf_mex_dup(c27_mxArrayInData);
  c27_identifier = c27_varName;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_y = c27_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c27_b_pos_right3rel),
    &c27_thisId);
  sf_mex_destroy(&c27_b_pos_right3rel);
  *(c27_obst_vec2 *)c27_outData = c27_y;
  sf_mex_destroy(&c27_mxArrayInData);
}

static const mxArray *c27_b_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData)
{
  const mxArray *c27_mxArrayOutData;
  c27_struct_iBlsPBO3AGnt69vDoTx5zD c27_u;
  const mxArray *c27_y = NULL;
  c27_struct_Nst2vGTExxHsg85EUOj9EH c27_b_u;
  const mxArray *c27_b_y = NULL;
  real_T c27_c_u;
  const mxArray *c27_c_y = NULL;
  c27_struct_HhckT6rntEraqECYVIDvCC c27_d_u;
  const mxArray *c27_d_y = NULL;
  real_T c27_e_u;
  const mxArray *c27_e_y = NULL;
  real_T c27_f_u;
  const mxArray *c27_f_y = NULL;
  const mxArray *c27_g_y = NULL;
  real_T c27_g_u;
  const mxArray *c27_h_y = NULL;
  real_T c27_h_u;
  const mxArray *c27_i_y = NULL;
  const mxArray *c27_j_y = NULL;
  real_T c27_i_u;
  const mxArray *c27_k_y = NULL;
  real_T c27_j_u;
  const mxArray *c27_l_y = NULL;
  const mxArray *c27_m_y = NULL;
  real_T c27_k_u;
  const mxArray *c27_n_y = NULL;
  real_T c27_l_u;
  const mxArray *c27_o_y = NULL;
  const mxArray *c27_p_y = NULL;
  real_T c27_m_u;
  const mxArray *c27_q_y = NULL;
  real_T c27_n_u;
  const mxArray *c27_r_y = NULL;
  real_T c27_o_u;
  const mxArray *c27_s_y = NULL;
  c27_struct_ZCmOWPuqBDw16FSOVVD00 c27_p_u;
  const mxArray *c27_t_y = NULL;
  real_T c27_q_u;
  const mxArray *c27_u_y = NULL;
  real_T c27_r_u;
  const mxArray *c27_v_y = NULL;
  real_T c27_s_u;
  const mxArray *c27_w_y = NULL;
  real_T c27_t_u;
  const mxArray *c27_x_y = NULL;
  real_T c27_u_u;
  const mxArray *c27_y_y = NULL;
  real_T c27_v_u;
  const mxArray *c27_ab_y = NULL;
  real_T c27_w_u;
  const mxArray *c27_bb_y = NULL;
  real_T c27_x_u;
  const mxArray *c27_cb_y = NULL;
  real_T c27_y_u;
  const mxArray *c27_db_y = NULL;
  real_T c27_ab_u;
  const mxArray *c27_eb_y = NULL;
  real_T c27_bb_u;
  const mxArray *c27_fb_y = NULL;
  int32_T c27_i20;
  real_T c27_cb_u[4];
  const mxArray *c27_gb_y = NULL;
  real_T c27_db_u;
  const mxArray *c27_hb_y = NULL;
  c27_struct_ZKAzdrl7umDGJoC14aoVKC c27_eb_u;
  const mxArray *c27_ib_y = NULL;
  int32_T c27_i21;
  real_T c27_fb_u[3];
  const mxArray *c27_jb_y = NULL;
  int32_T c27_i22;
  real_T c27_gb_u[3];
  const mxArray *c27_kb_y = NULL;
  int32_T c27_i23;
  real_T c27_hb_u[3];
  const mxArray *c27_lb_y = NULL;
  int32_T c27_i24;
  real_T c27_ib_u[3];
  const mxArray *c27_mb_y = NULL;
  const mxArray *c27_nb_y = NULL;
  int32_T c27_i25;
  real_T c27_jb_u[3];
  const mxArray *c27_ob_y = NULL;
  int32_T c27_i26;
  real_T c27_kb_u[3];
  const mxArray *c27_pb_y = NULL;
  int32_T c27_i27;
  real_T c27_lb_u[3];
  const mxArray *c27_qb_y = NULL;
  int32_T c27_i28;
  real_T c27_mb_u[3];
  const mxArray *c27_rb_y = NULL;
  const mxArray *c27_sb_y = NULL;
  int32_T c27_i29;
  real_T c27_nb_u[3];
  const mxArray *c27_tb_y = NULL;
  int32_T c27_i30;
  real_T c27_ob_u[3];
  const mxArray *c27_ub_y = NULL;
  int32_T c27_i31;
  real_T c27_pb_u[3];
  const mxArray *c27_vb_y = NULL;
  int32_T c27_i32;
  real_T c27_qb_u[3];
  const mxArray *c27_wb_y = NULL;
  const mxArray *c27_xb_y = NULL;
  int32_T c27_i33;
  real_T c27_rb_u[3];
  const mxArray *c27_yb_y = NULL;
  int32_T c27_i34;
  real_T c27_sb_u[3];
  const mxArray *c27_ac_y = NULL;
  int32_T c27_i35;
  real_T c27_tb_u[3];
  const mxArray *c27_bc_y = NULL;
  int32_T c27_i36;
  real_T c27_ub_u[3];
  const mxArray *c27_cc_y = NULL;
  real_T c27_vb_u;
  const mxArray *c27_dc_y = NULL;
  real_T c27_wb_u;
  const mxArray *c27_ec_y = NULL;
  real_T c27_xb_u;
  const mxArray *c27_fc_y = NULL;
  real_T c27_yb_u;
  const mxArray *c27_gc_y = NULL;
  real_T c27_ac_u;
  const mxArray *c27_hc_y = NULL;
  real_T c27_bc_u;
  const mxArray *c27_ic_y = NULL;
  real_T c27_cc_u;
  const mxArray *c27_jc_y = NULL;
  real_T c27_dc_u;
  const mxArray *c27_kc_y = NULL;
  real_T c27_ec_u;
  const mxArray *c27_lc_y = NULL;
  real_T c27_fc_u;
  const mxArray *c27_mc_y = NULL;
  real_T c27_gc_u;
  const mxArray *c27_nc_y = NULL;
  real_T c27_hc_u;
  const mxArray *c27_oc_y = NULL;
  c27_struct_r4FNviKwHfdhB8nQjvQv9 c27_ic_u;
  const mxArray *c27_pc_y = NULL;
  real_T c27_jc_u;
  const mxArray *c27_qc_y = NULL;
  c27_struct_Y9F1qlBi9AhssksPwemA4G c27_kc_u;
  const mxArray *c27_rc_y = NULL;
  real_T c27_lc_u;
  const mxArray *c27_sc_y = NULL;
  real_T c27_mc_u;
  const mxArray *c27_tc_y = NULL;
  real_T c27_nc_u;
  const mxArray *c27_uc_y = NULL;
  SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c27_mxArrayOutData = NULL;
  c27_mxArrayOutData = NULL;
  c27_u = *(c27_struct_iBlsPBO3AGnt69vDoTx5zD *)c27_inData;
  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c27_b_u = c27_u.Env;
  c27_b_y = NULL;
  sf_mex_assign(&c27_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c27_c_u = c27_b_u.g;
  c27_c_y = NULL;
  sf_mex_assign(&c27_c_y, sf_mex_create("y", &c27_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c27_b_y, c27_c_y, "g", "g", 0);
  c27_d_u = c27_b_u.left1;
  c27_d_y = NULL;
  sf_mex_assign(&c27_d_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c27_e_u = c27_d_u.x;
  c27_e_y = NULL;
  sf_mex_assign(&c27_e_y, sf_mex_create("y", &c27_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c27_d_y, c27_e_y, "x", "x", 0);
  c27_f_u = c27_d_u.y;
  c27_f_y = NULL;
  sf_mex_assign(&c27_f_y, sf_mex_create("y", &c27_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c27_d_y, c27_f_y, "y", "y", 0);
  sf_mex_addfield(c27_b_y, c27_d_y, "left1", "left1", 0);
  c27_d_u = c27_b_u.right1;
  c27_g_y = NULL;
  sf_mex_assign(&c27_g_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c27_g_u = c27_d_u.x;
  c27_h_y = NULL;
  sf_mex_assign(&c27_h_y, sf_mex_create("y", &c27_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c27_g_y, c27_h_y, "x", "x", 0);
  c27_h_u = c27_d_u.y;
  c27_i_y = NULL;
  sf_mex_assign(&c27_i_y, sf_mex_create("y", &c27_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c27_g_y, c27_i_y, "y", "y", 0);
  sf_mex_addfield(c27_b_y, c27_g_y, "right1", "right1", 0);
  c27_d_u = c27_b_u.right2;
  c27_j_y = NULL;
  sf_mex_assign(&c27_j_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c27_i_u = c27_d_u.x;
  c27_k_y = NULL;
  sf_mex_assign(&c27_k_y, sf_mex_create("y", &c27_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c27_j_y, c27_k_y, "x", "x", 0);
  c27_j_u = c27_d_u.y;
  c27_l_y = NULL;
  sf_mex_assign(&c27_l_y, sf_mex_create("y", &c27_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c27_j_y, c27_l_y, "y", "y", 0);
  sf_mex_addfield(c27_b_y, c27_j_y, "right2", "right2", 0);
  c27_d_u = c27_b_u.left2;
  c27_m_y = NULL;
  sf_mex_assign(&c27_m_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c27_k_u = c27_d_u.x;
  c27_n_y = NULL;
  sf_mex_assign(&c27_n_y, sf_mex_create("y", &c27_k_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c27_m_y, c27_n_y, "x", "x", 0);
  c27_l_u = c27_d_u.y;
  c27_o_y = NULL;
  sf_mex_assign(&c27_o_y, sf_mex_create("y", &c27_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c27_m_y, c27_o_y, "y", "y", 0);
  sf_mex_addfield(c27_b_y, c27_m_y, "left2", "left2", 0);
  c27_d_u = c27_b_u.right3;
  c27_p_y = NULL;
  sf_mex_assign(&c27_p_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c27_m_u = c27_d_u.x;
  c27_q_y = NULL;
  sf_mex_assign(&c27_q_y, sf_mex_create("y", &c27_m_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c27_p_y, c27_q_y, "x", "x", 0);
  c27_n_u = c27_d_u.y;
  c27_r_y = NULL;
  sf_mex_assign(&c27_r_y, sf_mex_create("y", &c27_n_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c27_p_y, c27_r_y, "y", "y", 0);
  sf_mex_addfield(c27_b_y, c27_p_y, "right3", "right3", 0);
  c27_o_u = c27_b_u.mu;
  c27_s_y = NULL;
  sf_mex_assign(&c27_s_y, sf_mex_create("y", &c27_o_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c27_b_y, c27_s_y, "mu", "mu", 0);
  sf_mex_addfield(c27_y, c27_b_y, "Env", "Env", 0);
  c27_p_u = c27_u.Veh;
  c27_t_y = NULL;
  sf_mex_assign(&c27_t_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c27_q_u = c27_p_u.m;
  c27_u_y = NULL;
  sf_mex_assign(&c27_u_y, sf_mex_create("y", &c27_q_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c27_t_y, c27_u_y, "m", "m", 0);
  c27_r_u = c27_p_u.Jz;
  c27_v_y = NULL;
  sf_mex_assign(&c27_v_y, sf_mex_create("y", &c27_r_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c27_t_y, c27_v_y, "Jz", "Jz", 0);
  c27_s_u = c27_p_u.m_sprung;
  c27_w_y = NULL;
  sf_mex_assign(&c27_w_y, sf_mex_create("y", &c27_s_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c27_t_y, c27_w_y, "m_sprung", "m_sprung", 0);
  c27_t_u = c27_p_u.Jx_sprung;
  c27_x_y = NULL;
  sf_mex_assign(&c27_x_y, sf_mex_create("y", &c27_t_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c27_t_y, c27_x_y, "Jx_sprung", "Jx_sprung", 0);
  c27_u_u = c27_p_u.Jy_sprung;
  c27_y_y = NULL;
  sf_mex_assign(&c27_y_y, sf_mex_create("y", &c27_u_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c27_t_y, c27_y_y, "Jy_sprung", "Jy_sprung", 0);
  c27_v_u = c27_p_u.lf;
  c27_ab_y = NULL;
  sf_mex_assign(&c27_ab_y, sf_mex_create("y", &c27_v_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c27_t_y, c27_ab_y, "lf", "lf", 0);
  c27_w_u = c27_p_u.lr;
  c27_bb_y = NULL;
  sf_mex_assign(&c27_bb_y, sf_mex_create("y", &c27_w_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c27_t_y, c27_bb_y, "lr", "lr", 0);
  c27_x_u = c27_p_u.L;
  c27_cb_y = NULL;
  sf_mex_assign(&c27_cb_y, sf_mex_create("y", &c27_x_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c27_t_y, c27_cb_y, "L", "L", 0);
  c27_y_u = c27_p_u.TrackWidth;
  c27_db_y = NULL;
  sf_mex_assign(&c27_db_y, sf_mex_create("y", &c27_y_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c27_t_y, c27_db_y, "TrackWidth", "TrackWidth", 0);
  c27_ab_u = c27_p_u.h;
  c27_eb_y = NULL;
  sf_mex_assign(&c27_eb_y, sf_mex_create("y", &c27_ab_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c27_t_y, c27_eb_y, "h", "h", 0);
  c27_bb_u = c27_p_u.HalfRohACd;
  c27_fb_y = NULL;
  sf_mex_assign(&c27_fb_y, sf_mex_create("y", &c27_bb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c27_t_y, c27_fb_y, "HalfRohACd", "HalfRohACd", 0);
  for (c27_i20 = 0; c27_i20 < 4; c27_i20++) {
    c27_cb_u[c27_i20] = c27_p_u.F_z4_static[c27_i20];
  }

  c27_gb_y = NULL;
  sf_mex_assign(&c27_gb_y, sf_mex_create("y", c27_cb_u, 0, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_addfield(c27_t_y, c27_gb_y, "F_z4_static", "F_z4_static", 0);
  c27_db_u = c27_p_u.Rw;
  c27_hb_y = NULL;
  sf_mex_assign(&c27_hb_y, sf_mex_create("y", &c27_db_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c27_t_y, c27_hb_y, "Rw", "Rw", 0);
  c27_eb_u = c27_p_u.r_long;
  c27_ib_y = NULL;
  sf_mex_assign(&c27_ib_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c27_i21 = 0; c27_i21 < 3; c27_i21++) {
    c27_fb_u[c27_i21] = c27_eb_u.fl[c27_i21];
  }

  c27_jb_y = NULL;
  sf_mex_assign(&c27_jb_y, sf_mex_create("y", c27_fb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c27_ib_y, c27_jb_y, "fl", "fl", 0);
  for (c27_i22 = 0; c27_i22 < 3; c27_i22++) {
    c27_gb_u[c27_i22] = c27_eb_u.fr[c27_i22];
  }

  c27_kb_y = NULL;
  sf_mex_assign(&c27_kb_y, sf_mex_create("y", c27_gb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c27_ib_y, c27_kb_y, "fr", "fr", 0);
  for (c27_i23 = 0; c27_i23 < 3; c27_i23++) {
    c27_hb_u[c27_i23] = c27_eb_u.rl[c27_i23];
  }

  c27_lb_y = NULL;
  sf_mex_assign(&c27_lb_y, sf_mex_create("y", c27_hb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c27_ib_y, c27_lb_y, "rl", "rl", 0);
  for (c27_i24 = 0; c27_i24 < 3; c27_i24++) {
    c27_ib_u[c27_i24] = c27_eb_u.rr[c27_i24];
  }

  c27_mb_y = NULL;
  sf_mex_assign(&c27_mb_y, sf_mex_create("y", c27_ib_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c27_ib_y, c27_mb_y, "rr", "rr", 0);
  sf_mex_addfield(c27_t_y, c27_ib_y, "r_long", "r_long", 0);
  c27_eb_u = c27_p_u.r_lat;
  c27_nb_y = NULL;
  sf_mex_assign(&c27_nb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c27_i25 = 0; c27_i25 < 3; c27_i25++) {
    c27_jb_u[c27_i25] = c27_eb_u.fl[c27_i25];
  }

  c27_ob_y = NULL;
  sf_mex_assign(&c27_ob_y, sf_mex_create("y", c27_jb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c27_nb_y, c27_ob_y, "fl", "fl", 0);
  for (c27_i26 = 0; c27_i26 < 3; c27_i26++) {
    c27_kb_u[c27_i26] = c27_eb_u.fr[c27_i26];
  }

  c27_pb_y = NULL;
  sf_mex_assign(&c27_pb_y, sf_mex_create("y", c27_kb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c27_nb_y, c27_pb_y, "fr", "fr", 0);
  for (c27_i27 = 0; c27_i27 < 3; c27_i27++) {
    c27_lb_u[c27_i27] = c27_eb_u.rl[c27_i27];
  }

  c27_qb_y = NULL;
  sf_mex_assign(&c27_qb_y, sf_mex_create("y", c27_lb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c27_nb_y, c27_qb_y, "rl", "rl", 0);
  for (c27_i28 = 0; c27_i28 < 3; c27_i28++) {
    c27_mb_u[c27_i28] = c27_eb_u.rr[c27_i28];
  }

  c27_rb_y = NULL;
  sf_mex_assign(&c27_rb_y, sf_mex_create("y", c27_mb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c27_nb_y, c27_rb_y, "rr", "rr", 0);
  sf_mex_addfield(c27_t_y, c27_nb_y, "r_lat", "r_lat", 0);
  c27_eb_u = c27_p_u.r_lever;
  c27_sb_y = NULL;
  sf_mex_assign(&c27_sb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c27_i29 = 0; c27_i29 < 3; c27_i29++) {
    c27_nb_u[c27_i29] = c27_eb_u.fl[c27_i29];
  }

  c27_tb_y = NULL;
  sf_mex_assign(&c27_tb_y, sf_mex_create("y", c27_nb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c27_sb_y, c27_tb_y, "fl", "fl", 0);
  for (c27_i30 = 0; c27_i30 < 3; c27_i30++) {
    c27_ob_u[c27_i30] = c27_eb_u.fr[c27_i30];
  }

  c27_ub_y = NULL;
  sf_mex_assign(&c27_ub_y, sf_mex_create("y", c27_ob_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c27_sb_y, c27_ub_y, "fr", "fr", 0);
  for (c27_i31 = 0; c27_i31 < 3; c27_i31++) {
    c27_pb_u[c27_i31] = c27_eb_u.rl[c27_i31];
  }

  c27_vb_y = NULL;
  sf_mex_assign(&c27_vb_y, sf_mex_create("y", c27_pb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c27_sb_y, c27_vb_y, "rl", "rl", 0);
  for (c27_i32 = 0; c27_i32 < 3; c27_i32++) {
    c27_qb_u[c27_i32] = c27_eb_u.rr[c27_i32];
  }

  c27_wb_y = NULL;
  sf_mex_assign(&c27_wb_y, sf_mex_create("y", c27_qb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c27_sb_y, c27_wb_y, "rr", "rr", 0);
  sf_mex_addfield(c27_t_y, c27_sb_y, "r_lever", "r_lever", 0);
  c27_eb_u = c27_p_u.r_pivot;
  c27_xb_y = NULL;
  sf_mex_assign(&c27_xb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c27_i33 = 0; c27_i33 < 3; c27_i33++) {
    c27_rb_u[c27_i33] = c27_eb_u.fl[c27_i33];
  }

  c27_yb_y = NULL;
  sf_mex_assign(&c27_yb_y, sf_mex_create("y", c27_rb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c27_xb_y, c27_yb_y, "fl", "fl", 0);
  for (c27_i34 = 0; c27_i34 < 3; c27_i34++) {
    c27_sb_u[c27_i34] = c27_eb_u.fr[c27_i34];
  }

  c27_ac_y = NULL;
  sf_mex_assign(&c27_ac_y, sf_mex_create("y", c27_sb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c27_xb_y, c27_ac_y, "fr", "fr", 0);
  for (c27_i35 = 0; c27_i35 < 3; c27_i35++) {
    c27_tb_u[c27_i35] = c27_eb_u.rl[c27_i35];
  }

  c27_bc_y = NULL;
  sf_mex_assign(&c27_bc_y, sf_mex_create("y", c27_tb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c27_xb_y, c27_bc_y, "rl", "rl", 0);
  for (c27_i36 = 0; c27_i36 < 3; c27_i36++) {
    c27_ub_u[c27_i36] = c27_eb_u.rr[c27_i36];
  }

  c27_cc_y = NULL;
  sf_mex_assign(&c27_cc_y, sf_mex_create("y", c27_ub_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c27_xb_y, c27_cc_y, "rr", "rr", 0);
  sf_mex_addfield(c27_t_y, c27_xb_y, "r_pivot", "r_pivot", 0);
  c27_vb_u = c27_p_u.cw;
  c27_dc_y = NULL;
  sf_mex_assign(&c27_dc_y, sf_mex_create("y", &c27_vb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c27_t_y, c27_dc_y, "cw", "cw", 0);
  c27_wb_u = c27_p_u.carb_f;
  c27_ec_y = NULL;
  sf_mex_assign(&c27_ec_y, sf_mex_create("y", &c27_wb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c27_t_y, c27_ec_y, "carb_f", "carb_f", 0);
  c27_xb_u = c27_p_u.carb_r;
  c27_fc_y = NULL;
  sf_mex_assign(&c27_fc_y, sf_mex_create("y", &c27_xb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c27_t_y, c27_fc_y, "carb_r", "carb_r", 0);
  c27_yb_u = c27_p_u.dw;
  c27_gc_y = NULL;
  sf_mex_assign(&c27_gc_y, sf_mex_create("y", &c27_yb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c27_t_y, c27_gc_y, "dw", "dw", 0);
  c27_ac_u = c27_p_u.Jw;
  c27_hc_y = NULL;
  sf_mex_assign(&c27_hc_y, sf_mex_create("y", &c27_ac_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c27_t_y, c27_hc_y, "Jw", "Jw", 0);
  c27_bc_u = c27_p_u.C0;
  c27_ic_y = NULL;
  sf_mex_assign(&c27_ic_y, sf_mex_create("y", &c27_bc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c27_t_y, c27_ic_y, "C0", "C0", 0);
  c27_cc_u = c27_p_u.RelaxLength;
  c27_jc_y = NULL;
  sf_mex_assign(&c27_jc_y, sf_mex_create("y", &c27_cc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c27_t_y, c27_jc_y, "RelaxLength", "RelaxLength", 0);
  c27_dc_u = c27_p_u.RRC;
  c27_kc_y = NULL;
  sf_mex_assign(&c27_kc_y, sf_mex_create("y", &c27_dc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c27_t_y, c27_kc_y, "RRC", "RRC", 0);
  c27_ec_u = c27_p_u.Pmax;
  c27_lc_y = NULL;
  sf_mex_assign(&c27_lc_y, sf_mex_create("y", &c27_ec_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c27_t_y, c27_lc_y, "Pmax", "Pmax", 0);
  c27_fc_u = c27_p_u.PropDistrFrnt;
  c27_mc_y = NULL;
  sf_mex_assign(&c27_mc_y, sf_mex_create("y", &c27_fc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c27_t_y, c27_mc_y, "PropDistrFrnt", "PropDistrFrnt", 0);
  c27_gc_u = c27_p_u.BrkDistrFrnt;
  c27_nc_y = NULL;
  sf_mex_assign(&c27_nc_y, sf_mex_create("y", &c27_gc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c27_t_y, c27_nc_y, "BrkDistrFrnt", "BrkDistrFrnt", 0);
  c27_hc_u = c27_p_u.SteRatio;
  c27_oc_y = NULL;
  sf_mex_assign(&c27_oc_y, sf_mex_create("y", &c27_hc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c27_t_y, c27_oc_y, "SteRatio", "SteRatio", 0);
  sf_mex_addfield(c27_y, c27_t_y, "Veh", "Veh", 0);
  c27_ic_u = c27_u.Drvr;
  c27_pc_y = NULL;
  sf_mex_assign(&c27_pc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c27_jc_u = c27_ic_u.v_set;
  c27_qc_y = NULL;
  sf_mex_assign(&c27_qc_y, sf_mex_create("y", &c27_jc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c27_pc_y, c27_qc_y, "v_set", "v_set", 0);
  sf_mex_addfield(c27_y, c27_pc_y, "Drvr", "Drvr", 0);
  c27_kc_u = c27_u.Init;
  c27_rc_y = NULL;
  sf_mex_assign(&c27_rc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c27_lc_u = c27_kc_u.v_x;
  c27_sc_y = NULL;
  sf_mex_assign(&c27_sc_y, sf_mex_create("y", &c27_lc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c27_rc_y, c27_sc_y, "v_x", "v_x", 0);
  c27_mc_u = c27_kc_u.F_fz;
  c27_tc_y = NULL;
  sf_mex_assign(&c27_tc_y, sf_mex_create("y", &c27_mc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c27_rc_y, c27_tc_y, "F_fz", "F_fz", 0);
  c27_nc_u = c27_kc_u.F_rz;
  c27_uc_y = NULL;
  sf_mex_assign(&c27_uc_y, sf_mex_create("y", &c27_nc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c27_rc_y, c27_uc_y, "F_rz", "F_rz", 0);
  sf_mex_addfield(c27_y, c27_rc_y, "Init", "Init", 0);
  sf_mex_assign(&c27_mxArrayOutData, c27_y, false);
  return c27_mxArrayOutData;
}

static void c27_d_emlrt_marshallIn
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId,
   c27_struct_iBlsPBO3AGnt69vDoTx5zD *c27_y)
{
  emlrtMsgIdentifier c27_thisId;
  static const char * c27_fieldNames[4] = { "Env", "Veh", "Drvr", "Init" };

  c27_thisId.fParent = c27_parentId;
  sf_mex_check_struct(c27_parentId, c27_u, 4, c27_fieldNames, 0U, NULL);
  c27_thisId.fIdentifier = "Env";
  c27_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c27_u, "Env",
    "Env", 0)), &c27_thisId, &c27_y->Env);
  c27_thisId.fIdentifier = "Veh";
  c27_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c27_u, "Veh",
    "Veh", 0)), &c27_thisId, &c27_y->Veh);
  c27_thisId.fIdentifier = "Drvr";
  c27_y->Drvr = c27_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c27_u, "Drvr", "Drvr", 0)), &c27_thisId);
  c27_thisId.fIdentifier = "Init";
  c27_y->Init = c27_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c27_u, "Init", "Init", 0)), &c27_thisId);
  sf_mex_destroy(&c27_u);
}

static void c27_e_emlrt_marshallIn
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId,
   c27_struct_Nst2vGTExxHsg85EUOj9EH *c27_y)
{
  emlrtMsgIdentifier c27_thisId;
  static const char * c27_fieldNames[7] = { "g", "left1", "right1", "right2",
    "left2", "right3", "mu" };

  c27_thisId.fParent = c27_parentId;
  sf_mex_check_struct(c27_parentId, c27_u, 7, c27_fieldNames, 0U, NULL);
  c27_thisId.fIdentifier = "g";
  c27_y->g = c27_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c27_u, "g", "g", 0)), &c27_thisId);
  c27_thisId.fIdentifier = "left1";
  c27_y->left1 = c27_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c27_u, "left1", "left1", 0)), &c27_thisId);
  c27_thisId.fIdentifier = "right1";
  c27_y->right1 = c27_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c27_u, "right1", "right1", 0)), &c27_thisId);
  c27_thisId.fIdentifier = "right2";
  c27_y->right2 = c27_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c27_u, "right2", "right2", 0)), &c27_thisId);
  c27_thisId.fIdentifier = "left2";
  c27_y->left2 = c27_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c27_u, "left2", "left2", 0)), &c27_thisId);
  c27_thisId.fIdentifier = "right3";
  c27_y->right3 = c27_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c27_u, "right3", "right3", 0)), &c27_thisId);
  c27_thisId.fIdentifier = "mu";
  c27_y->mu = c27_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c27_u, "mu", "mu", 0)), &c27_thisId);
  sf_mex_destroy(&c27_u);
}

static c27_struct_HhckT6rntEraqECYVIDvCC c27_f_emlrt_marshallIn
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId)
{
  c27_struct_HhckT6rntEraqECYVIDvCC c27_y;
  emlrtMsgIdentifier c27_thisId;
  static const char * c27_fieldNames[2] = { "x", "y" };

  c27_thisId.fParent = c27_parentId;
  sf_mex_check_struct(c27_parentId, c27_u, 2, c27_fieldNames, 0U, NULL);
  c27_thisId.fIdentifier = "x";
  c27_y.x = c27_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c27_u, "x", "x", 0)), &c27_thisId);
  c27_thisId.fIdentifier = "y";
  c27_y.y = c27_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c27_u, "y", "y", 0)), &c27_thisId);
  sf_mex_destroy(&c27_u);
  return c27_y;
}

static void c27_g_emlrt_marshallIn
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId,
   c27_struct_ZCmOWPuqBDw16FSOVVD00 *c27_y)
{
  emlrtMsgIdentifier c27_thisId;
  static const char * c27_fieldNames[29] = { "m", "Jz", "m_sprung", "Jx_sprung",
    "Jy_sprung", "lf", "lr", "L", "TrackWidth", "h", "HalfRohACd", "F_z4_static",
    "Rw", "r_long", "r_lat", "r_lever", "r_pivot", "cw", "carb_f", "carb_r",
    "dw", "Jw", "C0", "RelaxLength", "RRC", "Pmax", "PropDistrFrnt",
    "BrkDistrFrnt", "SteRatio" };

  c27_thisId.fParent = c27_parentId;
  sf_mex_check_struct(c27_parentId, c27_u, 29, c27_fieldNames, 0U, NULL);
  c27_thisId.fIdentifier = "m";
  c27_y->m = c27_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c27_u, "m", "m", 0)), &c27_thisId);
  c27_thisId.fIdentifier = "Jz";
  c27_y->Jz = c27_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c27_u, "Jz", "Jz", 0)), &c27_thisId);
  c27_thisId.fIdentifier = "m_sprung";
  c27_y->m_sprung = c27_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c27_u, "m_sprung", "m_sprung", 0)), &c27_thisId);
  c27_thisId.fIdentifier = "Jx_sprung";
  c27_y->Jx_sprung = c27_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c27_u, "Jx_sprung", "Jx_sprung", 0)), &c27_thisId);
  c27_thisId.fIdentifier = "Jy_sprung";
  c27_y->Jy_sprung = c27_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c27_u, "Jy_sprung", "Jy_sprung", 0)), &c27_thisId);
  c27_thisId.fIdentifier = "lf";
  c27_y->lf = c27_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c27_u, "lf", "lf", 0)), &c27_thisId);
  c27_thisId.fIdentifier = "lr";
  c27_y->lr = c27_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c27_u, "lr", "lr", 0)), &c27_thisId);
  c27_thisId.fIdentifier = "L";
  c27_y->L = c27_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c27_u, "L", "L", 0)), &c27_thisId);
  c27_thisId.fIdentifier = "TrackWidth";
  c27_y->TrackWidth = c27_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c27_u, "TrackWidth", "TrackWidth", 0)), &c27_thisId);
  c27_thisId.fIdentifier = "h";
  c27_y->h = c27_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c27_u, "h", "h", 0)), &c27_thisId);
  c27_thisId.fIdentifier = "HalfRohACd";
  c27_y->HalfRohACd = c27_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c27_u, "HalfRohACd", "HalfRohACd", 0)), &c27_thisId);
  c27_thisId.fIdentifier = "F_z4_static";
  c27_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c27_u,
    "F_z4_static", "F_z4_static", 0)), &c27_thisId, c27_y->F_z4_static);
  c27_thisId.fIdentifier = "Rw";
  c27_y->Rw = c27_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c27_u, "Rw", "Rw", 0)), &c27_thisId);
  c27_thisId.fIdentifier = "r_long";
  c27_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c27_u,
    "r_long", "r_long", 0)), &c27_thisId, &c27_y->r_long);
  c27_thisId.fIdentifier = "r_lat";
  c27_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c27_u,
    "r_lat", "r_lat", 0)), &c27_thisId, &c27_y->r_lat);
  c27_thisId.fIdentifier = "r_lever";
  c27_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c27_u,
    "r_lever", "r_lever", 0)), &c27_thisId, &c27_y->r_lever);
  c27_thisId.fIdentifier = "r_pivot";
  c27_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c27_u,
    "r_pivot", "r_pivot", 0)), &c27_thisId, &c27_y->r_pivot);
  c27_thisId.fIdentifier = "cw";
  c27_y->cw = c27_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c27_u, "cw", "cw", 0)), &c27_thisId);
  c27_thisId.fIdentifier = "carb_f";
  c27_y->carb_f = c27_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c27_u, "carb_f", "carb_f", 0)), &c27_thisId);
  c27_thisId.fIdentifier = "carb_r";
  c27_y->carb_r = c27_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c27_u, "carb_r", "carb_r", 0)), &c27_thisId);
  c27_thisId.fIdentifier = "dw";
  c27_y->dw = c27_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c27_u, "dw", "dw", 0)), &c27_thisId);
  c27_thisId.fIdentifier = "Jw";
  c27_y->Jw = c27_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c27_u, "Jw", "Jw", 0)), &c27_thisId);
  c27_thisId.fIdentifier = "C0";
  c27_y->C0 = c27_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c27_u, "C0", "C0", 0)), &c27_thisId);
  c27_thisId.fIdentifier = "RelaxLength";
  c27_y->RelaxLength = c27_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c27_u, "RelaxLength", "RelaxLength", 0)), &c27_thisId);
  c27_thisId.fIdentifier = "RRC";
  c27_y->RRC = c27_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c27_u, "RRC", "RRC", 0)), &c27_thisId);
  c27_thisId.fIdentifier = "Pmax";
  c27_y->Pmax = c27_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c27_u, "Pmax", "Pmax", 0)), &c27_thisId);
  c27_thisId.fIdentifier = "PropDistrFrnt";
  c27_y->PropDistrFrnt = c27_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c27_u, "PropDistrFrnt", "PropDistrFrnt", 0)), &c27_thisId);
  c27_thisId.fIdentifier = "BrkDistrFrnt";
  c27_y->BrkDistrFrnt = c27_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c27_u, "BrkDistrFrnt", "BrkDistrFrnt", 0)), &c27_thisId);
  c27_thisId.fIdentifier = "SteRatio";
  c27_y->SteRatio = c27_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c27_u, "SteRatio", "SteRatio", 0)), &c27_thisId);
  sf_mex_destroy(&c27_u);
}

static void c27_h_emlrt_marshallIn
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId, real_T c27_y[4])
{
  real_T c27_dv0[4];
  int32_T c27_i37;
  (void)chartInstance;
  sf_mex_import(c27_parentId, sf_mex_dup(c27_u), c27_dv0, 1, 0, 0U, 1, 0U, 2, 1,
                4);
  for (c27_i37 = 0; c27_i37 < 4; c27_i37++) {
    c27_y[c27_i37] = c27_dv0[c27_i37];
  }

  sf_mex_destroy(&c27_u);
}

static void c27_i_emlrt_marshallIn
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId,
   c27_struct_ZKAzdrl7umDGJoC14aoVKC *c27_y)
{
  emlrtMsgIdentifier c27_thisId;
  static const char * c27_fieldNames[4] = { "fl", "fr", "rl", "rr" };

  c27_thisId.fParent = c27_parentId;
  sf_mex_check_struct(c27_parentId, c27_u, 4, c27_fieldNames, 0U, NULL);
  c27_thisId.fIdentifier = "fl";
  c27_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c27_u, "fl",
    "fl", 0)), &c27_thisId, c27_y->fl);
  c27_thisId.fIdentifier = "fr";
  c27_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c27_u, "fr",
    "fr", 0)), &c27_thisId, c27_y->fr);
  c27_thisId.fIdentifier = "rl";
  c27_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c27_u, "rl",
    "rl", 0)), &c27_thisId, c27_y->rl);
  c27_thisId.fIdentifier = "rr";
  c27_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c27_u, "rr",
    "rr", 0)), &c27_thisId, c27_y->rr);
  sf_mex_destroy(&c27_u);
}

static void c27_j_emlrt_marshallIn
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId, real_T c27_y[3])
{
  real_T c27_dv1[3];
  int32_T c27_i38;
  (void)chartInstance;
  sf_mex_import(c27_parentId, sf_mex_dup(c27_u), c27_dv1, 1, 0, 0U, 1, 0U, 2, 3,
                1);
  for (c27_i38 = 0; c27_i38 < 3; c27_i38++) {
    c27_y[c27_i38] = c27_dv1[c27_i38];
  }

  sf_mex_destroy(&c27_u);
}

static c27_struct_r4FNviKwHfdhB8nQjvQv9 c27_k_emlrt_marshallIn
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId)
{
  c27_struct_r4FNviKwHfdhB8nQjvQv9 c27_y;
  emlrtMsgIdentifier c27_thisId;
  static const char * c27_fieldNames[1] = { "v_set" };

  c27_thisId.fParent = c27_parentId;
  sf_mex_check_struct(c27_parentId, c27_u, 1, c27_fieldNames, 0U, NULL);
  c27_thisId.fIdentifier = "v_set";
  c27_y.v_set = c27_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c27_u, "v_set", "v_set", 0)),
    &c27_thisId);
  sf_mex_destroy(&c27_u);
  return c27_y;
}

static c27_struct_Y9F1qlBi9AhssksPwemA4G c27_l_emlrt_marshallIn
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId)
{
  c27_struct_Y9F1qlBi9AhssksPwemA4G c27_y;
  emlrtMsgIdentifier c27_thisId;
  static const char * c27_fieldNames[3] = { "v_x", "F_fz", "F_rz" };

  c27_thisId.fParent = c27_parentId;
  sf_mex_check_struct(c27_parentId, c27_u, 3, c27_fieldNames, 0U, NULL);
  c27_thisId.fIdentifier = "v_x";
  c27_y.v_x = c27_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c27_u, "v_x", "v_x", 0)), &c27_thisId);
  c27_thisId.fIdentifier = "F_fz";
  c27_y.F_fz = c27_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c27_u, "F_fz", "F_fz", 0)), &c27_thisId);
  c27_thisId.fIdentifier = "F_rz";
  c27_y.F_rz = c27_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c27_u, "F_rz", "F_rz", 0)), &c27_thisId);
  sf_mex_destroy(&c27_u);
  return c27_y;
}

static void c27_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData)
{
  const mxArray *c27_b_Par;
  const char_T *c27_identifier;
  emlrtMsgIdentifier c27_thisId;
  c27_struct_iBlsPBO3AGnt69vDoTx5zD c27_y;
  SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c27_b_Par = sf_mex_dup(c27_mxArrayInData);
  c27_identifier = c27_varName;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c27_b_Par), &c27_thisId,
    &c27_y);
  sf_mex_destroy(&c27_b_Par);
  *(c27_struct_iBlsPBO3AGnt69vDoTx5zD *)c27_outData = c27_y;
  sf_mex_destroy(&c27_mxArrayInData);
}

static const mxArray *c27_c_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData)
{
  const mxArray *c27_mxArrayOutData = NULL;
  c27_irp_vec3 c27_u;
  const mxArray *c27_y = NULL;
  real_T c27_b_u;
  const mxArray *c27_b_y = NULL;
  real_T c27_c_u;
  const mxArray *c27_c_y = NULL;
  real_T c27_d_u;
  const mxArray *c27_d_y = NULL;
  SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c27_mxArrayOutData = NULL;
  c27_u = *(c27_irp_vec3 *)c27_inData;
  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c27_b_u = c27_u.x;
  c27_b_y = NULL;
  sf_mex_assign(&c27_b_y, sf_mex_create("y", &c27_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c27_y, c27_b_y, "x", "x", 0);
  c27_c_u = c27_u.y;
  c27_c_y = NULL;
  sf_mex_assign(&c27_c_y, sf_mex_create("y", &c27_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c27_y, c27_c_y, "y", "y", 0);
  c27_d_u = c27_u.rotz;
  c27_d_y = NULL;
  sf_mex_assign(&c27_d_y, sf_mex_create("y", &c27_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c27_y, c27_d_y, "rotz", "rotz", 0);
  sf_mex_assign(&c27_mxArrayOutData, c27_y, false);
  return c27_mxArrayOutData;
}

static const mxArray *c27_d_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData)
{
  const mxArray *c27_mxArrayOutData = NULL;
  real_T c27_u;
  const mxArray *c27_y = NULL;
  SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c27_mxArrayOutData = NULL;
  c27_u = *(real_T *)c27_inData;
  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", &c27_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c27_mxArrayOutData, c27_y, false);
  return c27_mxArrayOutData;
}

static void c27_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData)
{
  const mxArray *c27_nargout;
  const char_T *c27_identifier;
  emlrtMsgIdentifier c27_thisId;
  real_T c27_y;
  SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c27_nargout = sf_mex_dup(c27_mxArrayInData);
  c27_identifier = c27_varName;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_y = c27_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c27_nargout),
    &c27_thisId);
  sf_mex_destroy(&c27_nargout);
  *(real_T *)c27_outData = c27_y;
  sf_mex_destroy(&c27_mxArrayInData);
}

const mxArray
  *sf_c27_AllPurposeModel_TyreRelaxation_get_eml_resolved_functions_info(void)
{
  const mxArray *c27_nameCaptureInfo = NULL;
  c27_nameCaptureInfo = NULL;
  sf_mex_assign(&c27_nameCaptureInfo, sf_mex_createstruct("structure", 2, 30, 1),
                false);
  c27_info_helper(&c27_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c27_nameCaptureInfo);
  return c27_nameCaptureInfo;
}

static void c27_info_helper(const mxArray **c27_info)
{
  const mxArray *c27_rhs0 = NULL;
  const mxArray *c27_lhs0 = NULL;
  const mxArray *c27_rhs1 = NULL;
  const mxArray *c27_lhs1 = NULL;
  const mxArray *c27_rhs2 = NULL;
  const mxArray *c27_lhs2 = NULL;
  const mxArray *c27_rhs3 = NULL;
  const mxArray *c27_lhs3 = NULL;
  const mxArray *c27_rhs4 = NULL;
  const mxArray *c27_lhs4 = NULL;
  const mxArray *c27_rhs5 = NULL;
  const mxArray *c27_lhs5 = NULL;
  const mxArray *c27_rhs6 = NULL;
  const mxArray *c27_lhs6 = NULL;
  const mxArray *c27_rhs7 = NULL;
  const mxArray *c27_lhs7 = NULL;
  const mxArray *c27_rhs8 = NULL;
  const mxArray *c27_lhs8 = NULL;
  const mxArray *c27_rhs9 = NULL;
  const mxArray *c27_lhs9 = NULL;
  const mxArray *c27_rhs10 = NULL;
  const mxArray *c27_lhs10 = NULL;
  const mxArray *c27_rhs11 = NULL;
  const mxArray *c27_lhs11 = NULL;
  const mxArray *c27_rhs12 = NULL;
  const mxArray *c27_lhs12 = NULL;
  const mxArray *c27_rhs13 = NULL;
  const mxArray *c27_lhs13 = NULL;
  const mxArray *c27_rhs14 = NULL;
  const mxArray *c27_lhs14 = NULL;
  const mxArray *c27_rhs15 = NULL;
  const mxArray *c27_lhs15 = NULL;
  const mxArray *c27_rhs16 = NULL;
  const mxArray *c27_lhs16 = NULL;
  const mxArray *c27_rhs17 = NULL;
  const mxArray *c27_lhs17 = NULL;
  const mxArray *c27_rhs18 = NULL;
  const mxArray *c27_lhs18 = NULL;
  const mxArray *c27_rhs19 = NULL;
  const mxArray *c27_lhs19 = NULL;
  const mxArray *c27_rhs20 = NULL;
  const mxArray *c27_lhs20 = NULL;
  const mxArray *c27_rhs21 = NULL;
  const mxArray *c27_lhs21 = NULL;
  const mxArray *c27_rhs22 = NULL;
  const mxArray *c27_lhs22 = NULL;
  const mxArray *c27_rhs23 = NULL;
  const mxArray *c27_lhs23 = NULL;
  const mxArray *c27_rhs24 = NULL;
  const mxArray *c27_lhs24 = NULL;
  const mxArray *c27_rhs25 = NULL;
  const mxArray *c27_lhs25 = NULL;
  const mxArray *c27_rhs26 = NULL;
  const mxArray *c27_lhs26 = NULL;
  const mxArray *c27_rhs27 = NULL;
  const mxArray *c27_lhs27 = NULL;
  const mxArray *c27_rhs28 = NULL;
  const mxArray *c27_lhs28 = NULL;
  const mxArray *c27_rhs29 = NULL;
  const mxArray *c27_lhs29 = NULL;
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("cos"), "name", "name", 0);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1395328496U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c27_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_scalar_cos"), "name",
                  "name", 1);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1286818722U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c27_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "context", "context", 2);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("sin"), "name", "name", 2);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1395328504U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c27_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_scalar_sin"), "name",
                  "name", 3);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1286818736U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c27_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "context", "context", 4);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 4);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1383877294U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c27_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 5);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 5);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c27_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 6);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 6);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c27_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 7);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 7);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c27_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 8);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c27_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 9);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c27_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 10);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_xdotu"), "name", "name",
                  10);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1375980690U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c27_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 11);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c27_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m"), "context",
                  "context", 12);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.blas.xdotu"),
                  "name", "name", 12);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdotu.p"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c27_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdotu.p"),
                  "context", "context", 13);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.blas.xdot"),
                  "name", "name", 13);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c27_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p"),
                  "context", "context", 14);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 14);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c27_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p!below_threshold"),
                  "context", "context", 15);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 15);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c27_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 16);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 16);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1393330858U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c27_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p"),
                  "context", "context", 17);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.refblas.xdot"),
                  "name", "name", 17);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdot.p"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c27_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdot.p"),
                  "context", "context", 18);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "coder.internal.refblas.xdotx"), "name", "name", 18);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c27_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 19);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 19);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c27_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 20);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 20);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1372583160U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c27_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 21);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 21);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 21);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1372583160U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c27_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 22);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 22);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 22);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1372583160U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c27_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 23);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 23);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1397257422U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c27_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 24);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("isfi"), "name", "name", 24);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 24);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 24);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1346510358U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c27_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context",
                  "context", 25);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("isnumerictype"), "name",
                  "name", 25);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                  "resolved", 25);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1398875598U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c27_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 26);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("intmax"), "name", "name", 26);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1362261882U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c27_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 27);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 27);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1393330858U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c27_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 28);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("intmin"), "name", "name", 28);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 28);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1362261882U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c27_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 29);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 29);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1393330858U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c27_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs29), "lhs", "lhs",
                  29);
  sf_mex_destroy(&c27_rhs0);
  sf_mex_destroy(&c27_lhs0);
  sf_mex_destroy(&c27_rhs1);
  sf_mex_destroy(&c27_lhs1);
  sf_mex_destroy(&c27_rhs2);
  sf_mex_destroy(&c27_lhs2);
  sf_mex_destroy(&c27_rhs3);
  sf_mex_destroy(&c27_lhs3);
  sf_mex_destroy(&c27_rhs4);
  sf_mex_destroy(&c27_lhs4);
  sf_mex_destroy(&c27_rhs5);
  sf_mex_destroy(&c27_lhs5);
  sf_mex_destroy(&c27_rhs6);
  sf_mex_destroy(&c27_lhs6);
  sf_mex_destroy(&c27_rhs7);
  sf_mex_destroy(&c27_lhs7);
  sf_mex_destroy(&c27_rhs8);
  sf_mex_destroy(&c27_lhs8);
  sf_mex_destroy(&c27_rhs9);
  sf_mex_destroy(&c27_lhs9);
  sf_mex_destroy(&c27_rhs10);
  sf_mex_destroy(&c27_lhs10);
  sf_mex_destroy(&c27_rhs11);
  sf_mex_destroy(&c27_lhs11);
  sf_mex_destroy(&c27_rhs12);
  sf_mex_destroy(&c27_lhs12);
  sf_mex_destroy(&c27_rhs13);
  sf_mex_destroy(&c27_lhs13);
  sf_mex_destroy(&c27_rhs14);
  sf_mex_destroy(&c27_lhs14);
  sf_mex_destroy(&c27_rhs15);
  sf_mex_destroy(&c27_lhs15);
  sf_mex_destroy(&c27_rhs16);
  sf_mex_destroy(&c27_lhs16);
  sf_mex_destroy(&c27_rhs17);
  sf_mex_destroy(&c27_lhs17);
  sf_mex_destroy(&c27_rhs18);
  sf_mex_destroy(&c27_lhs18);
  sf_mex_destroy(&c27_rhs19);
  sf_mex_destroy(&c27_lhs19);
  sf_mex_destroy(&c27_rhs20);
  sf_mex_destroy(&c27_lhs20);
  sf_mex_destroy(&c27_rhs21);
  sf_mex_destroy(&c27_lhs21);
  sf_mex_destroy(&c27_rhs22);
  sf_mex_destroy(&c27_lhs22);
  sf_mex_destroy(&c27_rhs23);
  sf_mex_destroy(&c27_lhs23);
  sf_mex_destroy(&c27_rhs24);
  sf_mex_destroy(&c27_lhs24);
  sf_mex_destroy(&c27_rhs25);
  sf_mex_destroy(&c27_lhs25);
  sf_mex_destroy(&c27_rhs26);
  sf_mex_destroy(&c27_lhs26);
  sf_mex_destroy(&c27_rhs27);
  sf_mex_destroy(&c27_lhs27);
  sf_mex_destroy(&c27_rhs28);
  sf_mex_destroy(&c27_lhs28);
  sf_mex_destroy(&c27_rhs29);
  sf_mex_destroy(&c27_lhs29);
}

static const mxArray *c27_emlrt_marshallOut(const char * c27_u)
{
  const mxArray *c27_y = NULL;
  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", c27_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c27_u)), false);
  return c27_y;
}

static const mxArray *c27_b_emlrt_marshallOut(const uint32_T c27_u)
{
  const mxArray *c27_y = NULL;
  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", &c27_u, 7, 0U, 0U, 0U, 0), false);
  return c27_y;
}

static real_T c27_eml_xdotu(SFc27_AllPurposeModel_TyreRelaxationInstanceStruct
  *chartInstance, real_T c27_x[2], real_T c27_y[2])
{
  real_T c27_d;
  int32_T c27_k;
  int32_T c27_b_k;
  (void)chartInstance;
  c27_d = 0.0;
  for (c27_k = 1; c27_k < 3; c27_k++) {
    c27_b_k = c27_k;
    c27_d += c27_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c27_b_k), 1, 2, 1, 0) - 1] * c27_y[_SFD_EML_ARRAY_BOUNDS_CHECK
      ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c27_b_k), 1, 2, 1, 0) - 1];
  }

  return c27_d;
}

static const mxArray *c27_e_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData)
{
  const mxArray *c27_mxArrayOutData = NULL;
  int32_T c27_u;
  const mxArray *c27_y = NULL;
  SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c27_mxArrayOutData = NULL;
  c27_u = *(int32_T *)c27_inData;
  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", &c27_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c27_mxArrayOutData, c27_y, false);
  return c27_mxArrayOutData;
}

static int32_T c27_m_emlrt_marshallIn
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId)
{
  int32_T c27_y;
  int32_T c27_i39;
  (void)chartInstance;
  sf_mex_import(c27_parentId, sf_mex_dup(c27_u), &c27_i39, 1, 6, 0U, 0, 0U, 0);
  c27_y = c27_i39;
  sf_mex_destroy(&c27_u);
  return c27_y;
}

static void c27_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData)
{
  const mxArray *c27_b_sfEvent;
  const char_T *c27_identifier;
  emlrtMsgIdentifier c27_thisId;
  int32_T c27_y;
  SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c27_b_sfEvent = sf_mex_dup(c27_mxArrayInData);
  c27_identifier = c27_varName;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_y = c27_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c27_b_sfEvent),
    &c27_thisId);
  sf_mex_destroy(&c27_b_sfEvent);
  *(int32_T *)c27_outData = c27_y;
  sf_mex_destroy(&c27_mxArrayInData);
}

static const mxArray *c27_pos_irp3_bus_io(void *chartInstanceVoid, void
  *c27_pData)
{
  const mxArray *c27_mxVal = NULL;
  c27_irp_vec3 c27_tmp;
  SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c27_mxVal = NULL;
  c27_tmp.x = *(real_T *)&((char_T *)(c27_irp_vec3 *)c27_pData)[0];
  c27_tmp.y = *(real_T *)&((char_T *)(c27_irp_vec3 *)c27_pData)[8];
  c27_tmp.rotz = *(real_T *)&((char_T *)(c27_irp_vec3 *)c27_pData)[16];
  sf_mex_assign(&c27_mxVal, c27_c_sf_marshallOut(chartInstance, &c27_tmp), false);
  return c27_mxVal;
}

static const mxArray *c27_pos_left1rel_bus_io(void *chartInstanceVoid, void
  *c27_pData)
{
  const mxArray *c27_mxVal = NULL;
  c27_obst_vec2 c27_tmp;
  SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c27_mxVal = NULL;
  c27_tmp.x = *(real_T *)&((char_T *)(c27_obst_vec2 *)c27_pData)[0];
  c27_tmp.y = *(real_T *)&((char_T *)(c27_obst_vec2 *)c27_pData)[8];
  sf_mex_assign(&c27_mxVal, c27_sf_marshallOut(chartInstance, &c27_tmp), false);
  return c27_mxVal;
}

static uint8_T c27_n_emlrt_marshallIn
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c27_b_is_active_c27_AllPurposeModel_TyreRelaxation, const char_T
   *c27_identifier)
{
  uint8_T c27_y;
  emlrtMsgIdentifier c27_thisId;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_y = c27_o_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c27_b_is_active_c27_AllPurposeModel_TyreRelaxation), &c27_thisId);
  sf_mex_destroy(&c27_b_is_active_c27_AllPurposeModel_TyreRelaxation);
  return c27_y;
}

static uint8_T c27_o_emlrt_marshallIn
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId)
{
  uint8_T c27_y;
  uint8_T c27_u0;
  (void)chartInstance;
  sf_mex_import(c27_parentId, sf_mex_dup(c27_u), &c27_u0, 1, 3, 0U, 0, 0U, 0);
  c27_y = c27_u0;
  sf_mex_destroy(&c27_u);
  return c27_y;
}

static void init_dsm_address_info
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address
  (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  chartInstance->c27_pos_irp3 = (c27_irp_vec3 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c27_pos_left1rel = (c27_obst_vec2 *)
    ssGetOutputPortSignal_wrapper(chartInstance->S, 1);
  chartInstance->c27_pos_left2rel = (c27_obst_vec2 *)
    ssGetOutputPortSignal_wrapper(chartInstance->S, 2);
  chartInstance->c27_pos_right1rel = (c27_obst_vec2 *)
    ssGetOutputPortSignal_wrapper(chartInstance->S, 3);
  chartInstance->c27_pos_right2rel = (c27_obst_vec2 *)
    ssGetOutputPortSignal_wrapper(chartInstance->S, 4);
  chartInstance->c27_pos_right3rel = (c27_obst_vec2 *)
    ssGetOutputPortSignal_wrapper(chartInstance->S, 5);
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

void sf_c27_AllPurposeModel_TyreRelaxation_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(671489339U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2601688113U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1786044768U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4093383649U);
}

mxArray* sf_c27_AllPurposeModel_TyreRelaxation_get_post_codegen_info(void);
mxArray *sf_c27_AllPurposeModel_TyreRelaxation_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("NWADKVtcAPfsxpccQumbjE");
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo =
      sf_c27_AllPurposeModel_TyreRelaxation_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c27_AllPurposeModel_TyreRelaxation_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c27_AllPurposeModel_TyreRelaxation_jit_fallback_info(void)
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

mxArray *sf_c27_AllPurposeModel_TyreRelaxation_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c27_AllPurposeModel_TyreRelaxation_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c27_AllPurposeModel_TyreRelaxation
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x6'type','srcId','name','auxInfo'{{M[1],M[29],T\"pos_left1rel\",},{M[1],M[30],T\"pos_left2rel\",},{M[1],M[31],T\"pos_right1rel\",},{M[1],M[32],T\"pos_right2rel\",},{M[1],M[37],T\"pos_right3rel\",},{M[8],M[0],T\"is_active_c27_AllPurposeModel_TyreRelaxation\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 6, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c27_AllPurposeModel_TyreRelaxation_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _AllPurposeModel_TyreRelaxationMachineNumber_,
           27,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"pos_irp3");
          _SFD_SET_DATA_PROPS(1,10,0,0,"Par");
          _SFD_SET_DATA_PROPS(2,2,0,1,"pos_left1rel");
          _SFD_SET_DATA_PROPS(3,2,0,1,"pos_left2rel");
          _SFD_SET_DATA_PROPS(4,2,0,1,"pos_right1rel");
          _SFD_SET_DATA_PROPS(5,2,0,1,"pos_right2rel");
          _SFD_SET_DATA_PROPS(6,2,0,1,"pos_right3rel");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,2187);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c27_pos_irp3_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c27_b_sf_marshallOut,(MexInFcnForType)
          c27_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c27_pos_left1rel_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c27_pos_left1rel_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c27_pos_left1rel_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c27_pos_left1rel_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c27_pos_left1rel_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c27_pos_irp3);
        _SFD_SET_DATA_VALUE_PTR(1U, &chartInstance->c27_Par);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c27_pos_left1rel);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c27_pos_left2rel);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c27_pos_right1rel);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c27_pos_right2rel);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c27_pos_right3rel);
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
  return "sndBZnYwSYttFOwqSENboE";
}

static void sf_opaque_initialize_c27_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc27_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar)->S,
     0);
  initialize_params_c27_AllPurposeModel_TyreRelaxation
    ((SFc27_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
  initialize_c27_AllPurposeModel_TyreRelaxation
    ((SFc27_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c27_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  enable_c27_AllPurposeModel_TyreRelaxation
    ((SFc27_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c27_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  disable_c27_AllPurposeModel_TyreRelaxation
    ((SFc27_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c27_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  sf_gateway_c27_AllPurposeModel_TyreRelaxation
    ((SFc27_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c27_AllPurposeModel_TyreRelaxation
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c27_AllPurposeModel_TyreRelaxation
    ((SFc27_AllPurposeModel_TyreRelaxationInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c27_AllPurposeModel_TyreRelaxation(SimStruct*
  S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c27_AllPurposeModel_TyreRelaxation
    ((SFc27_AllPurposeModel_TyreRelaxationInstanceStruct*)
     chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c27_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc27_AllPurposeModel_TyreRelaxationInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_AllPurposeModel_TyreRelaxation_optimization_info();
    }

    finalize_c27_AllPurposeModel_TyreRelaxation
      ((SFc27_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc27_AllPurposeModel_TyreRelaxation
    ((SFc27_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c27_AllPurposeModel_TyreRelaxation(SimStruct *S)
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
    initialize_params_c27_AllPurposeModel_TyreRelaxation
      ((SFc27_AllPurposeModel_TyreRelaxationInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c27_AllPurposeModel_TyreRelaxation(SimStruct *S)
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
      27);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,27,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,27,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,27);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,27,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,27,5);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=5; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,27);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2802656826U));
  ssSetChecksum1(S,(812547209U));
  ssSetChecksum2(S,(2841232526U));
  ssSetChecksum3(S,(1790937685U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c27_AllPurposeModel_TyreRelaxation(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c27_AllPurposeModel_TyreRelaxation(SimStruct *S)
{
  SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct *)utMalloc
    (sizeof(SFc27_AllPurposeModel_TyreRelaxationInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc27_AllPurposeModel_TyreRelaxationInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c27_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c27_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c27_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c27_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c27_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c27_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c27_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c27_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c27_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c27_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c27_AllPurposeModel_TyreRelaxation;
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

void c27_AllPurposeModel_TyreRelaxation_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c27_AllPurposeModel_TyreRelaxation(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c27_AllPurposeModel_TyreRelaxation(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c27_AllPurposeModel_TyreRelaxation(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c27_AllPurposeModel_TyreRelaxation_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
