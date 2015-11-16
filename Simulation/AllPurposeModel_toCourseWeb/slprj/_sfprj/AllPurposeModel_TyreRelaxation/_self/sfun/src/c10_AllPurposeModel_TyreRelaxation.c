/* Include files */

#include <stddef.h>
#include "blas.h"
#include "AllPurposeModel_TyreRelaxation_sfun.h"
#include "c10_AllPurposeModel_TyreRelaxation.h"
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
static const char * c10_debug_family_names[5] = { "nargin", "nargout", "v_z4",
  "Par", "derF_s4" };

/* Function Declarations */
static void initialize_c10_AllPurposeModel_TyreRelaxation
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void initialize_params_c10_AllPurposeModel_TyreRelaxation
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void enable_c10_AllPurposeModel_TyreRelaxation
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void disable_c10_AllPurposeModel_TyreRelaxation
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void c10_update_debugger_state_c10_AllPurposeModel_TyreRelaxation
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c10_AllPurposeModel_TyreRelaxation
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void set_sim_state_c10_AllPurposeModel_TyreRelaxation
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c10_st);
static void finalize_c10_AllPurposeModel_TyreRelaxation
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void sf_gateway_c10_AllPurposeModel_TyreRelaxation
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void mdl_start_c10_AllPurposeModel_TyreRelaxation
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void c10_chartstep_c10_AllPurposeModel_TyreRelaxation
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void initSimStructsc10_AllPurposeModel_TyreRelaxation
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c10_machineNumber, uint32_T
  c10_chartNumber, uint32_T c10_instanceNumber);
static const mxArray *c10_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static c10_whl_vec4 c10_emlrt_marshallIn
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c10_b_derF_s4, const char_T *c10_identifier);
static c10_whl_vec4 c10_b_emlrt_marshallIn
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static real_T c10_c_emlrt_marshallIn
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_b_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static void c10_d_emlrt_marshallIn
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
   c10_struct_iBlsPBO3AGnt69vDoTx5zD *c10_y);
static void c10_e_emlrt_marshallIn
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
   c10_struct_Nst2vGTExxHsg85EUOj9EH *c10_y);
static c10_struct_HhckT6rntEraqECYVIDvCC c10_f_emlrt_marshallIn
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_g_emlrt_marshallIn
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
   c10_struct_ZCmOWPuqBDw16FSOVVD00 *c10_y);
static void c10_h_emlrt_marshallIn
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId, real_T c10_y[4]);
static void c10_i_emlrt_marshallIn
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
   c10_struct_ZKAzdrl7umDGJoC14aoVKC *c10_y);
static void c10_j_emlrt_marshallIn
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId, real_T c10_y[3]);
static c10_struct_r4FNviKwHfdhB8nQjvQv9 c10_k_emlrt_marshallIn
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static c10_struct_Y9F1qlBi9AhssksPwemA4G c10_l_emlrt_marshallIn
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_c_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static void c10_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static void c10_info_helper(const mxArray **c10_info);
static const mxArray *c10_emlrt_marshallOut(const char * c10_u);
static const mxArray *c10_b_emlrt_marshallOut(const uint32_T c10_u);
static real_T c10_eml_xdotu(SFc10_AllPurposeModel_TyreRelaxationInstanceStruct
  *chartInstance, real_T c10_x[2], real_T c10_y[2]);
static const mxArray *c10_d_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static int32_T c10_m_emlrt_marshallIn
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_v_z4_bus_io(void *chartInstanceVoid, void *c10_pData);
static uint8_T c10_n_emlrt_marshallIn
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c10_b_is_active_c10_AllPurposeModel_TyreRelaxation, const char_T
   *c10_identifier);
static uint8_T c10_o_emlrt_marshallIn
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void init_dsm_address_info
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void init_simulink_io_address
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c10_AllPurposeModel_TyreRelaxation
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  chartInstance->c10_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c10_is_active_c10_AllPurposeModel_TyreRelaxation = 0U;
}

static void initialize_params_c10_AllPurposeModel_TyreRelaxation
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  const mxArray *c10_m0 = NULL;
  const mxArray *c10_mxField;
  const mxArray *c10_m1 = NULL;
  const mxArray *c10_b_mxField;
  c10_struct_iBlsPBO3AGnt69vDoTx5zD c10_r0;
  const mxArray *c10_m2 = NULL;
  const mxArray *c10_c_mxField;
  const mxArray *c10_m3 = NULL;
  const mxArray *c10_d_mxField;
  const mxArray *c10_m4 = NULL;
  const mxArray *c10_e_mxField;
  const mxArray *c10_m5 = NULL;
  const mxArray *c10_f_mxField;
  const mxArray *c10_m6 = NULL;
  const mxArray *c10_g_mxField;
  const mxArray *c10_m7 = NULL;
  const mxArray *c10_h_mxField;
  const mxArray *c10_m8 = NULL;
  const mxArray *c10_i_mxField;
  const mxArray *c10_m9 = NULL;
  const mxArray *c10_j_mxField;
  const mxArray *c10_m10 = NULL;
  const mxArray *c10_k_mxField;
  const mxArray *c10_m11 = NULL;
  const mxArray *c10_l_mxField;
  const mxArray *c10_m12 = NULL;
  const mxArray *c10_m_mxField;
  const mxArray *c10_m13 = NULL;
  const mxArray *c10_n_mxField;
  c10_m0 = sf_mex_get_sfun_param(chartInstance->S, 0, 1);
  c10_mxField = sf_mex_getfield(c10_m0, "Env", "Par", 0);
  c10_m1 = sf_mex_dup(c10_mxField);
  c10_b_mxField = sf_mex_getfield(c10_m1, "g", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_b_mxField), &c10_r0.Env.g, 1, 0, 0U,
                      0, 0U, 0);
  c10_b_mxField = sf_mex_getfield(c10_m1, "left1", "Par", 0);
  c10_m2 = sf_mex_dup(c10_b_mxField);
  c10_c_mxField = sf_mex_getfield(c10_m2, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_c_mxField), &c10_r0.Env.left1.x, 1,
                      0, 0U, 0, 0U, 0);
  c10_c_mxField = sf_mex_getfield(c10_m2, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_c_mxField), &c10_r0.Env.left1.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c10_m2);
  c10_b_mxField = sf_mex_getfield(c10_m1, "right1", "Par", 0);
  c10_m3 = sf_mex_dup(c10_b_mxField);
  c10_d_mxField = sf_mex_getfield(c10_m3, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_d_mxField), &c10_r0.Env.right1.x, 1,
                      0, 0U, 0, 0U, 0);
  c10_d_mxField = sf_mex_getfield(c10_m3, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_d_mxField), &c10_r0.Env.right1.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c10_m3);
  c10_b_mxField = sf_mex_getfield(c10_m1, "right2", "Par", 0);
  c10_m4 = sf_mex_dup(c10_b_mxField);
  c10_e_mxField = sf_mex_getfield(c10_m4, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_e_mxField), &c10_r0.Env.right2.x, 1,
                      0, 0U, 0, 0U, 0);
  c10_e_mxField = sf_mex_getfield(c10_m4, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_e_mxField), &c10_r0.Env.right2.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c10_m4);
  c10_b_mxField = sf_mex_getfield(c10_m1, "left2", "Par", 0);
  c10_m5 = sf_mex_dup(c10_b_mxField);
  c10_f_mxField = sf_mex_getfield(c10_m5, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_f_mxField), &c10_r0.Env.left2.x, 1,
                      0, 0U, 0, 0U, 0);
  c10_f_mxField = sf_mex_getfield(c10_m5, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_f_mxField), &c10_r0.Env.left2.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c10_m5);
  c10_b_mxField = sf_mex_getfield(c10_m1, "right3", "Par", 0);
  c10_m6 = sf_mex_dup(c10_b_mxField);
  c10_g_mxField = sf_mex_getfield(c10_m6, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_g_mxField), &c10_r0.Env.right3.x, 1,
                      0, 0U, 0, 0U, 0);
  c10_g_mxField = sf_mex_getfield(c10_m6, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_g_mxField), &c10_r0.Env.right3.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c10_m6);
  c10_b_mxField = sf_mex_getfield(c10_m1, "mu", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_b_mxField), &c10_r0.Env.mu, 1, 0, 0U,
                      0, 0U, 0);
  sf_mex_destroy(&c10_m1);
  c10_mxField = sf_mex_getfield(c10_m0, "Veh", "Par", 0);
  c10_m7 = sf_mex_dup(c10_mxField);
  c10_h_mxField = sf_mex_getfield(c10_m7, "m", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_h_mxField), &c10_r0.Veh.m, 1, 0, 0U,
                      0, 0U, 0);
  c10_h_mxField = sf_mex_getfield(c10_m7, "Jz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_h_mxField), &c10_r0.Veh.Jz, 1, 0, 0U,
                      0, 0U, 0);
  c10_h_mxField = sf_mex_getfield(c10_m7, "m_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_h_mxField), &c10_r0.Veh.m_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c10_h_mxField = sf_mex_getfield(c10_m7, "Jx_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_h_mxField), &c10_r0.Veh.Jx_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c10_h_mxField = sf_mex_getfield(c10_m7, "Jy_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_h_mxField), &c10_r0.Veh.Jy_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c10_h_mxField = sf_mex_getfield(c10_m7, "lf", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_h_mxField), &c10_r0.Veh.lf, 1, 0, 0U,
                      0, 0U, 0);
  c10_h_mxField = sf_mex_getfield(c10_m7, "lr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_h_mxField), &c10_r0.Veh.lr, 1, 0, 0U,
                      0, 0U, 0);
  c10_h_mxField = sf_mex_getfield(c10_m7, "L", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_h_mxField), &c10_r0.Veh.L, 1, 0, 0U,
                      0, 0U, 0);
  c10_h_mxField = sf_mex_getfield(c10_m7, "TrackWidth", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_h_mxField), &c10_r0.Veh.TrackWidth,
                      1, 0, 0U, 0, 0U, 0);
  c10_h_mxField = sf_mex_getfield(c10_m7, "h", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_h_mxField), &c10_r0.Veh.h, 1, 0, 0U,
                      0, 0U, 0);
  c10_h_mxField = sf_mex_getfield(c10_m7, "HalfRohACd", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_h_mxField), &c10_r0.Veh.HalfRohACd,
                      1, 0, 0U, 0, 0U, 0);
  c10_h_mxField = sf_mex_getfield(c10_m7, "F_z4_static", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_h_mxField), c10_r0.Veh.F_z4_static,
                      1, 0, 0U, 1, 0U, 2, 1, 4);
  c10_h_mxField = sf_mex_getfield(c10_m7, "Rw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_h_mxField), &c10_r0.Veh.Rw, 1, 0, 0U,
                      0, 0U, 0);
  c10_h_mxField = sf_mex_getfield(c10_m7, "r_long", "Par", 0);
  c10_m8 = sf_mex_dup(c10_h_mxField);
  c10_i_mxField = sf_mex_getfield(c10_m8, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_i_mxField), c10_r0.Veh.r_long.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c10_i_mxField = sf_mex_getfield(c10_m8, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_i_mxField), c10_r0.Veh.r_long.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c10_i_mxField = sf_mex_getfield(c10_m8, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_i_mxField), c10_r0.Veh.r_long.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c10_i_mxField = sf_mex_getfield(c10_m8, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_i_mxField), c10_r0.Veh.r_long.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c10_m8);
  c10_h_mxField = sf_mex_getfield(c10_m7, "r_lat", "Par", 0);
  c10_m9 = sf_mex_dup(c10_h_mxField);
  c10_j_mxField = sf_mex_getfield(c10_m9, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_j_mxField), c10_r0.Veh.r_lat.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c10_j_mxField = sf_mex_getfield(c10_m9, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_j_mxField), c10_r0.Veh.r_lat.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c10_j_mxField = sf_mex_getfield(c10_m9, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_j_mxField), c10_r0.Veh.r_lat.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c10_j_mxField = sf_mex_getfield(c10_m9, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_j_mxField), c10_r0.Veh.r_lat.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c10_m9);
  c10_h_mxField = sf_mex_getfield(c10_m7, "r_lever", "Par", 0);
  c10_m10 = sf_mex_dup(c10_h_mxField);
  c10_k_mxField = sf_mex_getfield(c10_m10, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_k_mxField), c10_r0.Veh.r_lever.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c10_k_mxField = sf_mex_getfield(c10_m10, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_k_mxField), c10_r0.Veh.r_lever.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c10_k_mxField = sf_mex_getfield(c10_m10, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_k_mxField), c10_r0.Veh.r_lever.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c10_k_mxField = sf_mex_getfield(c10_m10, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_k_mxField), c10_r0.Veh.r_lever.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c10_m10);
  c10_h_mxField = sf_mex_getfield(c10_m7, "r_pivot", "Par", 0);
  c10_m11 = sf_mex_dup(c10_h_mxField);
  c10_l_mxField = sf_mex_getfield(c10_m11, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_l_mxField), c10_r0.Veh.r_pivot.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c10_l_mxField = sf_mex_getfield(c10_m11, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_l_mxField), c10_r0.Veh.r_pivot.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c10_l_mxField = sf_mex_getfield(c10_m11, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_l_mxField), c10_r0.Veh.r_pivot.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c10_l_mxField = sf_mex_getfield(c10_m11, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_l_mxField), c10_r0.Veh.r_pivot.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c10_m11);
  c10_h_mxField = sf_mex_getfield(c10_m7, "cw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_h_mxField), &c10_r0.Veh.cw, 1, 0, 0U,
                      0, 0U, 0);
  c10_h_mxField = sf_mex_getfield(c10_m7, "carb_f", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_h_mxField), &c10_r0.Veh.carb_f, 1, 0,
                      0U, 0, 0U, 0);
  c10_h_mxField = sf_mex_getfield(c10_m7, "carb_r", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_h_mxField), &c10_r0.Veh.carb_r, 1, 0,
                      0U, 0, 0U, 0);
  c10_h_mxField = sf_mex_getfield(c10_m7, "dw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_h_mxField), &c10_r0.Veh.dw, 1, 0, 0U,
                      0, 0U, 0);
  c10_h_mxField = sf_mex_getfield(c10_m7, "Jw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_h_mxField), &c10_r0.Veh.Jw, 1, 0, 0U,
                      0, 0U, 0);
  c10_h_mxField = sf_mex_getfield(c10_m7, "C0", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_h_mxField), &c10_r0.Veh.C0, 1, 0, 0U,
                      0, 0U, 0);
  c10_h_mxField = sf_mex_getfield(c10_m7, "RelaxLength", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_h_mxField), &c10_r0.Veh.RelaxLength,
                      1, 0, 0U, 0, 0U, 0);
  c10_h_mxField = sf_mex_getfield(c10_m7, "RRC", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_h_mxField), &c10_r0.Veh.RRC, 1, 0,
                      0U, 0, 0U, 0);
  c10_h_mxField = sf_mex_getfield(c10_m7, "Pmax", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_h_mxField), &c10_r0.Veh.Pmax, 1, 0,
                      0U, 0, 0U, 0);
  c10_h_mxField = sf_mex_getfield(c10_m7, "PropDistrFrnt", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_h_mxField),
                      &c10_r0.Veh.PropDistrFrnt, 1, 0, 0U, 0, 0U, 0);
  c10_h_mxField = sf_mex_getfield(c10_m7, "BrkDistrFrnt", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_h_mxField), &c10_r0.Veh.BrkDistrFrnt,
                      1, 0, 0U, 0, 0U, 0);
  c10_h_mxField = sf_mex_getfield(c10_m7, "SteRatio", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_h_mxField), &c10_r0.Veh.SteRatio, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c10_m7);
  c10_mxField = sf_mex_getfield(c10_m0, "Drvr", "Par", 0);
  c10_m12 = sf_mex_dup(c10_mxField);
  c10_m_mxField = sf_mex_getfield(c10_m12, "v_set", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_m_mxField), &c10_r0.Drvr.v_set, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c10_m12);
  c10_mxField = sf_mex_getfield(c10_m0, "Init", "Par", 0);
  c10_m13 = sf_mex_dup(c10_mxField);
  c10_n_mxField = sf_mex_getfield(c10_m13, "v_x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_n_mxField), &c10_r0.Init.v_x, 1, 0,
                      0U, 0, 0U, 0);
  c10_n_mxField = sf_mex_getfield(c10_m13, "F_fz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_n_mxField), &c10_r0.Init.F_fz, 1, 0,
                      0U, 0, 0U, 0);
  c10_n_mxField = sf_mex_getfield(c10_m13, "F_rz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c10_n_mxField), &c10_r0.Init.F_rz, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c10_m13);
  sf_mex_destroy(&c10_m0);
  chartInstance->c10_Par = c10_r0;
}

static void enable_c10_AllPurposeModel_TyreRelaxation
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c10_AllPurposeModel_TyreRelaxation
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c10_update_debugger_state_c10_AllPurposeModel_TyreRelaxation
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c10_AllPurposeModel_TyreRelaxation
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  const mxArray *c10_st;
  const mxArray *c10_y = NULL;
  const mxArray *c10_b_y = NULL;
  real_T c10_u;
  const mxArray *c10_c_y = NULL;
  real_T c10_b_u;
  const mxArray *c10_d_y = NULL;
  real_T c10_c_u;
  const mxArray *c10_e_y = NULL;
  real_T c10_d_u;
  const mxArray *c10_f_y = NULL;
  uint8_T c10_hoistedGlobal;
  uint8_T c10_e_u;
  const mxArray *c10_g_y = NULL;
  c10_st = NULL;
  c10_st = NULL;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_createcellmatrix(2, 1), false);
  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c10_u = *(real_T *)&((char_T *)chartInstance->c10_derF_s4)[0];
  c10_c_y = NULL;
  sf_mex_assign(&c10_c_y, sf_mex_create("y", &c10_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c10_b_y, c10_c_y, "fl", "fl", 0);
  c10_b_u = *(real_T *)&((char_T *)chartInstance->c10_derF_s4)[8];
  c10_d_y = NULL;
  sf_mex_assign(&c10_d_y, sf_mex_create("y", &c10_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c10_b_y, c10_d_y, "fr", "fr", 0);
  c10_c_u = *(real_T *)&((char_T *)chartInstance->c10_derF_s4)[16];
  c10_e_y = NULL;
  sf_mex_assign(&c10_e_y, sf_mex_create("y", &c10_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c10_b_y, c10_e_y, "rl", "rl", 0);
  c10_d_u = *(real_T *)&((char_T *)chartInstance->c10_derF_s4)[24];
  c10_f_y = NULL;
  sf_mex_assign(&c10_f_y, sf_mex_create("y", &c10_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c10_b_y, c10_f_y, "rr", "rr", 0);
  sf_mex_setcell(c10_y, 0, c10_b_y);
  c10_hoistedGlobal =
    chartInstance->c10_is_active_c10_AllPurposeModel_TyreRelaxation;
  c10_e_u = c10_hoistedGlobal;
  c10_g_y = NULL;
  sf_mex_assign(&c10_g_y, sf_mex_create("y", &c10_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c10_y, 1, c10_g_y);
  sf_mex_assign(&c10_st, c10_y, false);
  return c10_st;
}

static void set_sim_state_c10_AllPurposeModel_TyreRelaxation
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c10_st)
{
  const mxArray *c10_u;
  c10_whl_vec4 c10_r1;
  chartInstance->c10_doneDoubleBufferReInit = true;
  c10_u = sf_mex_dup(c10_st);
  c10_r1 = c10_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c10_u,
    0)), "derF_s4");
  *(real_T *)&((char_T *)chartInstance->c10_derF_s4)[0] = c10_r1.fl;
  *(real_T *)&((char_T *)chartInstance->c10_derF_s4)[8] = c10_r1.fr;
  *(real_T *)&((char_T *)chartInstance->c10_derF_s4)[16] = c10_r1.rl;
  *(real_T *)&((char_T *)chartInstance->c10_derF_s4)[24] = c10_r1.rr;
  chartInstance->c10_is_active_c10_AllPurposeModel_TyreRelaxation =
    c10_n_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 1)),
    "is_active_c10_AllPurposeModel_TyreRelaxation");
  sf_mex_destroy(&c10_u);
  c10_update_debugger_state_c10_AllPurposeModel_TyreRelaxation(chartInstance);
  sf_mex_destroy(&c10_st);
}

static void finalize_c10_AllPurposeModel_TyreRelaxation
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c10_AllPurposeModel_TyreRelaxation
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 9U, chartInstance->c10_sfEvent);
  chartInstance->c10_sfEvent = CALL_EVENT;
  c10_chartstep_c10_AllPurposeModel_TyreRelaxation(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_AllPurposeModel_TyreRelaxationMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void mdl_start_c10_AllPurposeModel_TyreRelaxation
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c10_chartstep_c10_AllPurposeModel_TyreRelaxation
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  c10_whl_vec4 c10_b_v_z4;
  c10_struct_iBlsPBO3AGnt69vDoTx5zD c10_b_Par;
  uint32_T c10_debug_family_var_map[5];
  real_T c10_nargin = 2.0;
  real_T c10_nargout = 1.0;
  c10_whl_vec4 c10_b_derF_s4;
  real_T c10_a[2];
  real_T c10_b[2];
  int32_T c10_i0;
  real_T c10_b_a[2];
  int32_T c10_i1;
  real_T c10_b_b[2];
  real_T c10_y;
  int32_T c10_i2;
  real_T c10_c_a[2];
  int32_T c10_i3;
  real_T c10_c_b[2];
  real_T c10_b_y;
  int32_T c10_i4;
  real_T c10_d_a[2];
  int32_T c10_i5;
  real_T c10_d_b[2];
  real_T c10_c_y;
  int32_T c10_i6;
  real_T c10_e_a[2];
  int32_T c10_i7;
  real_T c10_e_b[2];
  real_T c10_d_y;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c10_sfEvent);
  c10_b_v_z4.fl = *(real_T *)&((char_T *)chartInstance->c10_v_z4)[0];
  c10_b_v_z4.fr = *(real_T *)&((char_T *)chartInstance->c10_v_z4)[8];
  c10_b_v_z4.rl = *(real_T *)&((char_T *)chartInstance->c10_v_z4)[16];
  c10_b_v_z4.rr = *(real_T *)&((char_T *)chartInstance->c10_v_z4)[24];
  c10_b_Par = chartInstance->c10_Par;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c10_debug_family_names,
    c10_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 0U, c10_c_sf_marshallOut,
    c10_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 1U, c10_c_sf_marshallOut,
    c10_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_b_v_z4, 2U, c10_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_Par, 3U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_derF_s4, 4U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 5);
  c10_a[0] = c10_b_Par.Veh.cw;
  c10_a[1] = c10_b_Par.Veh.carb_f;
  c10_b[0] = -c10_b_v_z4.fl;
  c10_b[1] = -c10_b_v_z4.fr;
  for (c10_i0 = 0; c10_i0 < 2; c10_i0++) {
    c10_b_a[c10_i0] = c10_a[c10_i0];
  }

  for (c10_i1 = 0; c10_i1 < 2; c10_i1++) {
    c10_b_b[c10_i1] = c10_b[c10_i1];
  }

  c10_y = c10_eml_xdotu(chartInstance, c10_b_a, c10_b_b);
  c10_b_derF_s4.fl = c10_y;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 6);
  c10_a[0] = c10_b_Par.Veh.cw;
  c10_a[1] = c10_b_Par.Veh.carb_f;
  c10_b[0] = -c10_b_v_z4.fr;
  c10_b[1] = -c10_b_v_z4.fl;
  for (c10_i2 = 0; c10_i2 < 2; c10_i2++) {
    c10_c_a[c10_i2] = c10_a[c10_i2];
  }

  for (c10_i3 = 0; c10_i3 < 2; c10_i3++) {
    c10_c_b[c10_i3] = c10_b[c10_i3];
  }

  c10_b_y = c10_eml_xdotu(chartInstance, c10_c_a, c10_c_b);
  c10_b_derF_s4.fr = c10_b_y;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 7);
  c10_a[0] = c10_b_Par.Veh.cw;
  c10_a[1] = c10_b_Par.Veh.carb_r;
  c10_b[0] = -c10_b_v_z4.rl;
  c10_b[1] = -c10_b_v_z4.rr;
  for (c10_i4 = 0; c10_i4 < 2; c10_i4++) {
    c10_d_a[c10_i4] = c10_a[c10_i4];
  }

  for (c10_i5 = 0; c10_i5 < 2; c10_i5++) {
    c10_d_b[c10_i5] = c10_b[c10_i5];
  }

  c10_c_y = c10_eml_xdotu(chartInstance, c10_d_a, c10_d_b);
  c10_b_derF_s4.rl = c10_c_y;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 8);
  c10_a[0] = c10_b_Par.Veh.cw;
  c10_a[1] = c10_b_Par.Veh.carb_r;
  c10_b[0] = -c10_b_v_z4.rr;
  c10_b[1] = -c10_b_v_z4.rl;
  for (c10_i6 = 0; c10_i6 < 2; c10_i6++) {
    c10_e_a[c10_i6] = c10_a[c10_i6];
  }

  for (c10_i7 = 0; c10_i7 < 2; c10_i7++) {
    c10_e_b[c10_i7] = c10_b[c10_i7];
  }

  c10_d_y = c10_eml_xdotu(chartInstance, c10_e_a, c10_e_b);
  c10_b_derF_s4.rr = c10_d_y;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, -8);
  _SFD_SYMBOL_SCOPE_POP();
  *(real_T *)&((char_T *)chartInstance->c10_derF_s4)[0] = c10_b_derF_s4.fl;
  *(real_T *)&((char_T *)chartInstance->c10_derF_s4)[8] = c10_b_derF_s4.fr;
  *(real_T *)&((char_T *)chartInstance->c10_derF_s4)[16] = c10_b_derF_s4.rl;
  *(real_T *)&((char_T *)chartInstance->c10_derF_s4)[24] = c10_b_derF_s4.rr;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c10_sfEvent);
}

static void initSimStructsc10_AllPurposeModel_TyreRelaxation
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c10_machineNumber, uint32_T
  c10_chartNumber, uint32_T c10_instanceNumber)
{
  (void)c10_machineNumber;
  (void)c10_chartNumber;
  (void)c10_instanceNumber;
}

static const mxArray *c10_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  c10_whl_vec4 c10_u;
  const mxArray *c10_y = NULL;
  real_T c10_b_u;
  const mxArray *c10_b_y = NULL;
  real_T c10_c_u;
  const mxArray *c10_c_y = NULL;
  real_T c10_d_u;
  const mxArray *c10_d_y = NULL;
  real_T c10_e_u;
  const mxArray *c10_e_y = NULL;
  SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(c10_whl_vec4 *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c10_b_u = c10_u.fl;
  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", &c10_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c10_y, c10_b_y, "fl", "fl", 0);
  c10_c_u = c10_u.fr;
  c10_c_y = NULL;
  sf_mex_assign(&c10_c_y, sf_mex_create("y", &c10_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c10_y, c10_c_y, "fr", "fr", 0);
  c10_d_u = c10_u.rl;
  c10_d_y = NULL;
  sf_mex_assign(&c10_d_y, sf_mex_create("y", &c10_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c10_y, c10_d_y, "rl", "rl", 0);
  c10_e_u = c10_u.rr;
  c10_e_y = NULL;
  sf_mex_assign(&c10_e_y, sf_mex_create("y", &c10_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c10_y, c10_e_y, "rr", "rr", 0);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static c10_whl_vec4 c10_emlrt_marshallIn
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c10_b_derF_s4, const char_T *c10_identifier)
{
  c10_whl_vec4 c10_y;
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_b_derF_s4),
    &c10_thisId);
  sf_mex_destroy(&c10_b_derF_s4);
  return c10_y;
}

static c10_whl_vec4 c10_b_emlrt_marshallIn
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  c10_whl_vec4 c10_y;
  emlrtMsgIdentifier c10_thisId;
  static const char * c10_fieldNames[4] = { "fl", "fr", "rl", "rr" };

  c10_thisId.fParent = c10_parentId;
  sf_mex_check_struct(c10_parentId, c10_u, 4, c10_fieldNames, 0U, NULL);
  c10_thisId.fIdentifier = "fl";
  c10_y.fl = c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c10_u, "fl", "fl", 0)), &c10_thisId);
  c10_thisId.fIdentifier = "fr";
  c10_y.fr = c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c10_u, "fr", "fr", 0)), &c10_thisId);
  c10_thisId.fIdentifier = "rl";
  c10_y.rl = c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c10_u, "rl", "rl", 0)), &c10_thisId);
  c10_thisId.fIdentifier = "rr";
  c10_y.rr = c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c10_u, "rr", "rr", 0)), &c10_thisId);
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static real_T c10_c_emlrt_marshallIn
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  real_T c10_y;
  real_T c10_d0;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_d0, 1, 0, 0U, 0, 0U, 0);
  c10_y = c10_d0;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_b_derF_s4;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  c10_whl_vec4 c10_y;
  SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c10_b_derF_s4 = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_b_derF_s4),
    &c10_thisId);
  sf_mex_destroy(&c10_b_derF_s4);
  *(c10_whl_vec4 *)c10_outData = c10_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

static const mxArray *c10_b_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData;
  c10_struct_iBlsPBO3AGnt69vDoTx5zD c10_u;
  const mxArray *c10_y = NULL;
  c10_struct_Nst2vGTExxHsg85EUOj9EH c10_b_u;
  const mxArray *c10_b_y = NULL;
  real_T c10_c_u;
  const mxArray *c10_c_y = NULL;
  c10_struct_HhckT6rntEraqECYVIDvCC c10_d_u;
  const mxArray *c10_d_y = NULL;
  real_T c10_e_u;
  const mxArray *c10_e_y = NULL;
  real_T c10_f_u;
  const mxArray *c10_f_y = NULL;
  const mxArray *c10_g_y = NULL;
  real_T c10_g_u;
  const mxArray *c10_h_y = NULL;
  real_T c10_h_u;
  const mxArray *c10_i_y = NULL;
  const mxArray *c10_j_y = NULL;
  real_T c10_i_u;
  const mxArray *c10_k_y = NULL;
  real_T c10_j_u;
  const mxArray *c10_l_y = NULL;
  const mxArray *c10_m_y = NULL;
  real_T c10_k_u;
  const mxArray *c10_n_y = NULL;
  real_T c10_l_u;
  const mxArray *c10_o_y = NULL;
  const mxArray *c10_p_y = NULL;
  real_T c10_m_u;
  const mxArray *c10_q_y = NULL;
  real_T c10_n_u;
  const mxArray *c10_r_y = NULL;
  real_T c10_o_u;
  const mxArray *c10_s_y = NULL;
  c10_struct_ZCmOWPuqBDw16FSOVVD00 c10_p_u;
  const mxArray *c10_t_y = NULL;
  real_T c10_q_u;
  const mxArray *c10_u_y = NULL;
  real_T c10_r_u;
  const mxArray *c10_v_y = NULL;
  real_T c10_s_u;
  const mxArray *c10_w_y = NULL;
  real_T c10_t_u;
  const mxArray *c10_x_y = NULL;
  real_T c10_u_u;
  const mxArray *c10_y_y = NULL;
  real_T c10_v_u;
  const mxArray *c10_ab_y = NULL;
  real_T c10_w_u;
  const mxArray *c10_bb_y = NULL;
  real_T c10_x_u;
  const mxArray *c10_cb_y = NULL;
  real_T c10_y_u;
  const mxArray *c10_db_y = NULL;
  real_T c10_ab_u;
  const mxArray *c10_eb_y = NULL;
  real_T c10_bb_u;
  const mxArray *c10_fb_y = NULL;
  int32_T c10_i8;
  real_T c10_cb_u[4];
  const mxArray *c10_gb_y = NULL;
  real_T c10_db_u;
  const mxArray *c10_hb_y = NULL;
  c10_struct_ZKAzdrl7umDGJoC14aoVKC c10_eb_u;
  const mxArray *c10_ib_y = NULL;
  int32_T c10_i9;
  real_T c10_fb_u[3];
  const mxArray *c10_jb_y = NULL;
  int32_T c10_i10;
  real_T c10_gb_u[3];
  const mxArray *c10_kb_y = NULL;
  int32_T c10_i11;
  real_T c10_hb_u[3];
  const mxArray *c10_lb_y = NULL;
  int32_T c10_i12;
  real_T c10_ib_u[3];
  const mxArray *c10_mb_y = NULL;
  const mxArray *c10_nb_y = NULL;
  int32_T c10_i13;
  real_T c10_jb_u[3];
  const mxArray *c10_ob_y = NULL;
  int32_T c10_i14;
  real_T c10_kb_u[3];
  const mxArray *c10_pb_y = NULL;
  int32_T c10_i15;
  real_T c10_lb_u[3];
  const mxArray *c10_qb_y = NULL;
  int32_T c10_i16;
  real_T c10_mb_u[3];
  const mxArray *c10_rb_y = NULL;
  const mxArray *c10_sb_y = NULL;
  int32_T c10_i17;
  real_T c10_nb_u[3];
  const mxArray *c10_tb_y = NULL;
  int32_T c10_i18;
  real_T c10_ob_u[3];
  const mxArray *c10_ub_y = NULL;
  int32_T c10_i19;
  real_T c10_pb_u[3];
  const mxArray *c10_vb_y = NULL;
  int32_T c10_i20;
  real_T c10_qb_u[3];
  const mxArray *c10_wb_y = NULL;
  const mxArray *c10_xb_y = NULL;
  int32_T c10_i21;
  real_T c10_rb_u[3];
  const mxArray *c10_yb_y = NULL;
  int32_T c10_i22;
  real_T c10_sb_u[3];
  const mxArray *c10_ac_y = NULL;
  int32_T c10_i23;
  real_T c10_tb_u[3];
  const mxArray *c10_bc_y = NULL;
  int32_T c10_i24;
  real_T c10_ub_u[3];
  const mxArray *c10_cc_y = NULL;
  real_T c10_vb_u;
  const mxArray *c10_dc_y = NULL;
  real_T c10_wb_u;
  const mxArray *c10_ec_y = NULL;
  real_T c10_xb_u;
  const mxArray *c10_fc_y = NULL;
  real_T c10_yb_u;
  const mxArray *c10_gc_y = NULL;
  real_T c10_ac_u;
  const mxArray *c10_hc_y = NULL;
  real_T c10_bc_u;
  const mxArray *c10_ic_y = NULL;
  real_T c10_cc_u;
  const mxArray *c10_jc_y = NULL;
  real_T c10_dc_u;
  const mxArray *c10_kc_y = NULL;
  real_T c10_ec_u;
  const mxArray *c10_lc_y = NULL;
  real_T c10_fc_u;
  const mxArray *c10_mc_y = NULL;
  real_T c10_gc_u;
  const mxArray *c10_nc_y = NULL;
  real_T c10_hc_u;
  const mxArray *c10_oc_y = NULL;
  c10_struct_r4FNviKwHfdhB8nQjvQv9 c10_ic_u;
  const mxArray *c10_pc_y = NULL;
  real_T c10_jc_u;
  const mxArray *c10_qc_y = NULL;
  c10_struct_Y9F1qlBi9AhssksPwemA4G c10_kc_u;
  const mxArray *c10_rc_y = NULL;
  real_T c10_lc_u;
  const mxArray *c10_sc_y = NULL;
  real_T c10_mc_u;
  const mxArray *c10_tc_y = NULL;
  real_T c10_nc_u;
  const mxArray *c10_uc_y = NULL;
  SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_mxArrayOutData = NULL;
  c10_u = *(c10_struct_iBlsPBO3AGnt69vDoTx5zD *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c10_b_u = c10_u.Env;
  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c10_c_u = c10_b_u.g;
  c10_c_y = NULL;
  sf_mex_assign(&c10_c_y, sf_mex_create("y", &c10_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c10_b_y, c10_c_y, "g", "g", 0);
  c10_d_u = c10_b_u.left1;
  c10_d_y = NULL;
  sf_mex_assign(&c10_d_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c10_e_u = c10_d_u.x;
  c10_e_y = NULL;
  sf_mex_assign(&c10_e_y, sf_mex_create("y", &c10_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c10_d_y, c10_e_y, "x", "x", 0);
  c10_f_u = c10_d_u.y;
  c10_f_y = NULL;
  sf_mex_assign(&c10_f_y, sf_mex_create("y", &c10_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c10_d_y, c10_f_y, "y", "y", 0);
  sf_mex_addfield(c10_b_y, c10_d_y, "left1", "left1", 0);
  c10_d_u = c10_b_u.right1;
  c10_g_y = NULL;
  sf_mex_assign(&c10_g_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c10_g_u = c10_d_u.x;
  c10_h_y = NULL;
  sf_mex_assign(&c10_h_y, sf_mex_create("y", &c10_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c10_g_y, c10_h_y, "x", "x", 0);
  c10_h_u = c10_d_u.y;
  c10_i_y = NULL;
  sf_mex_assign(&c10_i_y, sf_mex_create("y", &c10_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c10_g_y, c10_i_y, "y", "y", 0);
  sf_mex_addfield(c10_b_y, c10_g_y, "right1", "right1", 0);
  c10_d_u = c10_b_u.right2;
  c10_j_y = NULL;
  sf_mex_assign(&c10_j_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c10_i_u = c10_d_u.x;
  c10_k_y = NULL;
  sf_mex_assign(&c10_k_y, sf_mex_create("y", &c10_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c10_j_y, c10_k_y, "x", "x", 0);
  c10_j_u = c10_d_u.y;
  c10_l_y = NULL;
  sf_mex_assign(&c10_l_y, sf_mex_create("y", &c10_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c10_j_y, c10_l_y, "y", "y", 0);
  sf_mex_addfield(c10_b_y, c10_j_y, "right2", "right2", 0);
  c10_d_u = c10_b_u.left2;
  c10_m_y = NULL;
  sf_mex_assign(&c10_m_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c10_k_u = c10_d_u.x;
  c10_n_y = NULL;
  sf_mex_assign(&c10_n_y, sf_mex_create("y", &c10_k_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c10_m_y, c10_n_y, "x", "x", 0);
  c10_l_u = c10_d_u.y;
  c10_o_y = NULL;
  sf_mex_assign(&c10_o_y, sf_mex_create("y", &c10_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c10_m_y, c10_o_y, "y", "y", 0);
  sf_mex_addfield(c10_b_y, c10_m_y, "left2", "left2", 0);
  c10_d_u = c10_b_u.right3;
  c10_p_y = NULL;
  sf_mex_assign(&c10_p_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c10_m_u = c10_d_u.x;
  c10_q_y = NULL;
  sf_mex_assign(&c10_q_y, sf_mex_create("y", &c10_m_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c10_p_y, c10_q_y, "x", "x", 0);
  c10_n_u = c10_d_u.y;
  c10_r_y = NULL;
  sf_mex_assign(&c10_r_y, sf_mex_create("y", &c10_n_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c10_p_y, c10_r_y, "y", "y", 0);
  sf_mex_addfield(c10_b_y, c10_p_y, "right3", "right3", 0);
  c10_o_u = c10_b_u.mu;
  c10_s_y = NULL;
  sf_mex_assign(&c10_s_y, sf_mex_create("y", &c10_o_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c10_b_y, c10_s_y, "mu", "mu", 0);
  sf_mex_addfield(c10_y, c10_b_y, "Env", "Env", 0);
  c10_p_u = c10_u.Veh;
  c10_t_y = NULL;
  sf_mex_assign(&c10_t_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c10_q_u = c10_p_u.m;
  c10_u_y = NULL;
  sf_mex_assign(&c10_u_y, sf_mex_create("y", &c10_q_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c10_t_y, c10_u_y, "m", "m", 0);
  c10_r_u = c10_p_u.Jz;
  c10_v_y = NULL;
  sf_mex_assign(&c10_v_y, sf_mex_create("y", &c10_r_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c10_t_y, c10_v_y, "Jz", "Jz", 0);
  c10_s_u = c10_p_u.m_sprung;
  c10_w_y = NULL;
  sf_mex_assign(&c10_w_y, sf_mex_create("y", &c10_s_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c10_t_y, c10_w_y, "m_sprung", "m_sprung", 0);
  c10_t_u = c10_p_u.Jx_sprung;
  c10_x_y = NULL;
  sf_mex_assign(&c10_x_y, sf_mex_create("y", &c10_t_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c10_t_y, c10_x_y, "Jx_sprung", "Jx_sprung", 0);
  c10_u_u = c10_p_u.Jy_sprung;
  c10_y_y = NULL;
  sf_mex_assign(&c10_y_y, sf_mex_create("y", &c10_u_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c10_t_y, c10_y_y, "Jy_sprung", "Jy_sprung", 0);
  c10_v_u = c10_p_u.lf;
  c10_ab_y = NULL;
  sf_mex_assign(&c10_ab_y, sf_mex_create("y", &c10_v_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c10_t_y, c10_ab_y, "lf", "lf", 0);
  c10_w_u = c10_p_u.lr;
  c10_bb_y = NULL;
  sf_mex_assign(&c10_bb_y, sf_mex_create("y", &c10_w_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c10_t_y, c10_bb_y, "lr", "lr", 0);
  c10_x_u = c10_p_u.L;
  c10_cb_y = NULL;
  sf_mex_assign(&c10_cb_y, sf_mex_create("y", &c10_x_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c10_t_y, c10_cb_y, "L", "L", 0);
  c10_y_u = c10_p_u.TrackWidth;
  c10_db_y = NULL;
  sf_mex_assign(&c10_db_y, sf_mex_create("y", &c10_y_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c10_t_y, c10_db_y, "TrackWidth", "TrackWidth", 0);
  c10_ab_u = c10_p_u.h;
  c10_eb_y = NULL;
  sf_mex_assign(&c10_eb_y, sf_mex_create("y", &c10_ab_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c10_t_y, c10_eb_y, "h", "h", 0);
  c10_bb_u = c10_p_u.HalfRohACd;
  c10_fb_y = NULL;
  sf_mex_assign(&c10_fb_y, sf_mex_create("y", &c10_bb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c10_t_y, c10_fb_y, "HalfRohACd", "HalfRohACd", 0);
  for (c10_i8 = 0; c10_i8 < 4; c10_i8++) {
    c10_cb_u[c10_i8] = c10_p_u.F_z4_static[c10_i8];
  }

  c10_gb_y = NULL;
  sf_mex_assign(&c10_gb_y, sf_mex_create("y", c10_cb_u, 0, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_addfield(c10_t_y, c10_gb_y, "F_z4_static", "F_z4_static", 0);
  c10_db_u = c10_p_u.Rw;
  c10_hb_y = NULL;
  sf_mex_assign(&c10_hb_y, sf_mex_create("y", &c10_db_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c10_t_y, c10_hb_y, "Rw", "Rw", 0);
  c10_eb_u = c10_p_u.r_long;
  c10_ib_y = NULL;
  sf_mex_assign(&c10_ib_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c10_i9 = 0; c10_i9 < 3; c10_i9++) {
    c10_fb_u[c10_i9] = c10_eb_u.fl[c10_i9];
  }

  c10_jb_y = NULL;
  sf_mex_assign(&c10_jb_y, sf_mex_create("y", c10_fb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c10_ib_y, c10_jb_y, "fl", "fl", 0);
  for (c10_i10 = 0; c10_i10 < 3; c10_i10++) {
    c10_gb_u[c10_i10] = c10_eb_u.fr[c10_i10];
  }

  c10_kb_y = NULL;
  sf_mex_assign(&c10_kb_y, sf_mex_create("y", c10_gb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c10_ib_y, c10_kb_y, "fr", "fr", 0);
  for (c10_i11 = 0; c10_i11 < 3; c10_i11++) {
    c10_hb_u[c10_i11] = c10_eb_u.rl[c10_i11];
  }

  c10_lb_y = NULL;
  sf_mex_assign(&c10_lb_y, sf_mex_create("y", c10_hb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c10_ib_y, c10_lb_y, "rl", "rl", 0);
  for (c10_i12 = 0; c10_i12 < 3; c10_i12++) {
    c10_ib_u[c10_i12] = c10_eb_u.rr[c10_i12];
  }

  c10_mb_y = NULL;
  sf_mex_assign(&c10_mb_y, sf_mex_create("y", c10_ib_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c10_ib_y, c10_mb_y, "rr", "rr", 0);
  sf_mex_addfield(c10_t_y, c10_ib_y, "r_long", "r_long", 0);
  c10_eb_u = c10_p_u.r_lat;
  c10_nb_y = NULL;
  sf_mex_assign(&c10_nb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c10_i13 = 0; c10_i13 < 3; c10_i13++) {
    c10_jb_u[c10_i13] = c10_eb_u.fl[c10_i13];
  }

  c10_ob_y = NULL;
  sf_mex_assign(&c10_ob_y, sf_mex_create("y", c10_jb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c10_nb_y, c10_ob_y, "fl", "fl", 0);
  for (c10_i14 = 0; c10_i14 < 3; c10_i14++) {
    c10_kb_u[c10_i14] = c10_eb_u.fr[c10_i14];
  }

  c10_pb_y = NULL;
  sf_mex_assign(&c10_pb_y, sf_mex_create("y", c10_kb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c10_nb_y, c10_pb_y, "fr", "fr", 0);
  for (c10_i15 = 0; c10_i15 < 3; c10_i15++) {
    c10_lb_u[c10_i15] = c10_eb_u.rl[c10_i15];
  }

  c10_qb_y = NULL;
  sf_mex_assign(&c10_qb_y, sf_mex_create("y", c10_lb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c10_nb_y, c10_qb_y, "rl", "rl", 0);
  for (c10_i16 = 0; c10_i16 < 3; c10_i16++) {
    c10_mb_u[c10_i16] = c10_eb_u.rr[c10_i16];
  }

  c10_rb_y = NULL;
  sf_mex_assign(&c10_rb_y, sf_mex_create("y", c10_mb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c10_nb_y, c10_rb_y, "rr", "rr", 0);
  sf_mex_addfield(c10_t_y, c10_nb_y, "r_lat", "r_lat", 0);
  c10_eb_u = c10_p_u.r_lever;
  c10_sb_y = NULL;
  sf_mex_assign(&c10_sb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c10_i17 = 0; c10_i17 < 3; c10_i17++) {
    c10_nb_u[c10_i17] = c10_eb_u.fl[c10_i17];
  }

  c10_tb_y = NULL;
  sf_mex_assign(&c10_tb_y, sf_mex_create("y", c10_nb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c10_sb_y, c10_tb_y, "fl", "fl", 0);
  for (c10_i18 = 0; c10_i18 < 3; c10_i18++) {
    c10_ob_u[c10_i18] = c10_eb_u.fr[c10_i18];
  }

  c10_ub_y = NULL;
  sf_mex_assign(&c10_ub_y, sf_mex_create("y", c10_ob_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c10_sb_y, c10_ub_y, "fr", "fr", 0);
  for (c10_i19 = 0; c10_i19 < 3; c10_i19++) {
    c10_pb_u[c10_i19] = c10_eb_u.rl[c10_i19];
  }

  c10_vb_y = NULL;
  sf_mex_assign(&c10_vb_y, sf_mex_create("y", c10_pb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c10_sb_y, c10_vb_y, "rl", "rl", 0);
  for (c10_i20 = 0; c10_i20 < 3; c10_i20++) {
    c10_qb_u[c10_i20] = c10_eb_u.rr[c10_i20];
  }

  c10_wb_y = NULL;
  sf_mex_assign(&c10_wb_y, sf_mex_create("y", c10_qb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c10_sb_y, c10_wb_y, "rr", "rr", 0);
  sf_mex_addfield(c10_t_y, c10_sb_y, "r_lever", "r_lever", 0);
  c10_eb_u = c10_p_u.r_pivot;
  c10_xb_y = NULL;
  sf_mex_assign(&c10_xb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c10_i21 = 0; c10_i21 < 3; c10_i21++) {
    c10_rb_u[c10_i21] = c10_eb_u.fl[c10_i21];
  }

  c10_yb_y = NULL;
  sf_mex_assign(&c10_yb_y, sf_mex_create("y", c10_rb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c10_xb_y, c10_yb_y, "fl", "fl", 0);
  for (c10_i22 = 0; c10_i22 < 3; c10_i22++) {
    c10_sb_u[c10_i22] = c10_eb_u.fr[c10_i22];
  }

  c10_ac_y = NULL;
  sf_mex_assign(&c10_ac_y, sf_mex_create("y", c10_sb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c10_xb_y, c10_ac_y, "fr", "fr", 0);
  for (c10_i23 = 0; c10_i23 < 3; c10_i23++) {
    c10_tb_u[c10_i23] = c10_eb_u.rl[c10_i23];
  }

  c10_bc_y = NULL;
  sf_mex_assign(&c10_bc_y, sf_mex_create("y", c10_tb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c10_xb_y, c10_bc_y, "rl", "rl", 0);
  for (c10_i24 = 0; c10_i24 < 3; c10_i24++) {
    c10_ub_u[c10_i24] = c10_eb_u.rr[c10_i24];
  }

  c10_cc_y = NULL;
  sf_mex_assign(&c10_cc_y, sf_mex_create("y", c10_ub_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c10_xb_y, c10_cc_y, "rr", "rr", 0);
  sf_mex_addfield(c10_t_y, c10_xb_y, "r_pivot", "r_pivot", 0);
  c10_vb_u = c10_p_u.cw;
  c10_dc_y = NULL;
  sf_mex_assign(&c10_dc_y, sf_mex_create("y", &c10_vb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c10_t_y, c10_dc_y, "cw", "cw", 0);
  c10_wb_u = c10_p_u.carb_f;
  c10_ec_y = NULL;
  sf_mex_assign(&c10_ec_y, sf_mex_create("y", &c10_wb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c10_t_y, c10_ec_y, "carb_f", "carb_f", 0);
  c10_xb_u = c10_p_u.carb_r;
  c10_fc_y = NULL;
  sf_mex_assign(&c10_fc_y, sf_mex_create("y", &c10_xb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c10_t_y, c10_fc_y, "carb_r", "carb_r", 0);
  c10_yb_u = c10_p_u.dw;
  c10_gc_y = NULL;
  sf_mex_assign(&c10_gc_y, sf_mex_create("y", &c10_yb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c10_t_y, c10_gc_y, "dw", "dw", 0);
  c10_ac_u = c10_p_u.Jw;
  c10_hc_y = NULL;
  sf_mex_assign(&c10_hc_y, sf_mex_create("y", &c10_ac_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c10_t_y, c10_hc_y, "Jw", "Jw", 0);
  c10_bc_u = c10_p_u.C0;
  c10_ic_y = NULL;
  sf_mex_assign(&c10_ic_y, sf_mex_create("y", &c10_bc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c10_t_y, c10_ic_y, "C0", "C0", 0);
  c10_cc_u = c10_p_u.RelaxLength;
  c10_jc_y = NULL;
  sf_mex_assign(&c10_jc_y, sf_mex_create("y", &c10_cc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c10_t_y, c10_jc_y, "RelaxLength", "RelaxLength", 0);
  c10_dc_u = c10_p_u.RRC;
  c10_kc_y = NULL;
  sf_mex_assign(&c10_kc_y, sf_mex_create("y", &c10_dc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c10_t_y, c10_kc_y, "RRC", "RRC", 0);
  c10_ec_u = c10_p_u.Pmax;
  c10_lc_y = NULL;
  sf_mex_assign(&c10_lc_y, sf_mex_create("y", &c10_ec_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c10_t_y, c10_lc_y, "Pmax", "Pmax", 0);
  c10_fc_u = c10_p_u.PropDistrFrnt;
  c10_mc_y = NULL;
  sf_mex_assign(&c10_mc_y, sf_mex_create("y", &c10_fc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c10_t_y, c10_mc_y, "PropDistrFrnt", "PropDistrFrnt", 0);
  c10_gc_u = c10_p_u.BrkDistrFrnt;
  c10_nc_y = NULL;
  sf_mex_assign(&c10_nc_y, sf_mex_create("y", &c10_gc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c10_t_y, c10_nc_y, "BrkDistrFrnt", "BrkDistrFrnt", 0);
  c10_hc_u = c10_p_u.SteRatio;
  c10_oc_y = NULL;
  sf_mex_assign(&c10_oc_y, sf_mex_create("y", &c10_hc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c10_t_y, c10_oc_y, "SteRatio", "SteRatio", 0);
  sf_mex_addfield(c10_y, c10_t_y, "Veh", "Veh", 0);
  c10_ic_u = c10_u.Drvr;
  c10_pc_y = NULL;
  sf_mex_assign(&c10_pc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c10_jc_u = c10_ic_u.v_set;
  c10_qc_y = NULL;
  sf_mex_assign(&c10_qc_y, sf_mex_create("y", &c10_jc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c10_pc_y, c10_qc_y, "v_set", "v_set", 0);
  sf_mex_addfield(c10_y, c10_pc_y, "Drvr", "Drvr", 0);
  c10_kc_u = c10_u.Init;
  c10_rc_y = NULL;
  sf_mex_assign(&c10_rc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c10_lc_u = c10_kc_u.v_x;
  c10_sc_y = NULL;
  sf_mex_assign(&c10_sc_y, sf_mex_create("y", &c10_lc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c10_rc_y, c10_sc_y, "v_x", "v_x", 0);
  c10_mc_u = c10_kc_u.F_fz;
  c10_tc_y = NULL;
  sf_mex_assign(&c10_tc_y, sf_mex_create("y", &c10_mc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c10_rc_y, c10_tc_y, "F_fz", "F_fz", 0);
  c10_nc_u = c10_kc_u.F_rz;
  c10_uc_y = NULL;
  sf_mex_assign(&c10_uc_y, sf_mex_create("y", &c10_nc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c10_rc_y, c10_uc_y, "F_rz", "F_rz", 0);
  sf_mex_addfield(c10_y, c10_rc_y, "Init", "Init", 0);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static void c10_d_emlrt_marshallIn
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
   c10_struct_iBlsPBO3AGnt69vDoTx5zD *c10_y)
{
  emlrtMsgIdentifier c10_thisId;
  static const char * c10_fieldNames[4] = { "Env", "Veh", "Drvr", "Init" };

  c10_thisId.fParent = c10_parentId;
  sf_mex_check_struct(c10_parentId, c10_u, 4, c10_fieldNames, 0U, NULL);
  c10_thisId.fIdentifier = "Env";
  c10_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c10_u, "Env",
    "Env", 0)), &c10_thisId, &c10_y->Env);
  c10_thisId.fIdentifier = "Veh";
  c10_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c10_u, "Veh",
    "Veh", 0)), &c10_thisId, &c10_y->Veh);
  c10_thisId.fIdentifier = "Drvr";
  c10_y->Drvr = c10_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c10_u, "Drvr", "Drvr", 0)), &c10_thisId);
  c10_thisId.fIdentifier = "Init";
  c10_y->Init = c10_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c10_u, "Init", "Init", 0)), &c10_thisId);
  sf_mex_destroy(&c10_u);
}

static void c10_e_emlrt_marshallIn
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
   c10_struct_Nst2vGTExxHsg85EUOj9EH *c10_y)
{
  emlrtMsgIdentifier c10_thisId;
  static const char * c10_fieldNames[7] = { "g", "left1", "right1", "right2",
    "left2", "right3", "mu" };

  c10_thisId.fParent = c10_parentId;
  sf_mex_check_struct(c10_parentId, c10_u, 7, c10_fieldNames, 0U, NULL);
  c10_thisId.fIdentifier = "g";
  c10_y->g = c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c10_u, "g", "g", 0)), &c10_thisId);
  c10_thisId.fIdentifier = "left1";
  c10_y->left1 = c10_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c10_u, "left1", "left1", 0)), &c10_thisId);
  c10_thisId.fIdentifier = "right1";
  c10_y->right1 = c10_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c10_u, "right1", "right1", 0)), &c10_thisId);
  c10_thisId.fIdentifier = "right2";
  c10_y->right2 = c10_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c10_u, "right2", "right2", 0)), &c10_thisId);
  c10_thisId.fIdentifier = "left2";
  c10_y->left2 = c10_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c10_u, "left2", "left2", 0)), &c10_thisId);
  c10_thisId.fIdentifier = "right3";
  c10_y->right3 = c10_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c10_u, "right3", "right3", 0)), &c10_thisId);
  c10_thisId.fIdentifier = "mu";
  c10_y->mu = c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c10_u, "mu", "mu", 0)), &c10_thisId);
  sf_mex_destroy(&c10_u);
}

static c10_struct_HhckT6rntEraqECYVIDvCC c10_f_emlrt_marshallIn
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  c10_struct_HhckT6rntEraqECYVIDvCC c10_y;
  emlrtMsgIdentifier c10_thisId;
  static const char * c10_fieldNames[2] = { "x", "y" };

  c10_thisId.fParent = c10_parentId;
  sf_mex_check_struct(c10_parentId, c10_u, 2, c10_fieldNames, 0U, NULL);
  c10_thisId.fIdentifier = "x";
  c10_y.x = c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c10_u, "x", "x", 0)), &c10_thisId);
  c10_thisId.fIdentifier = "y";
  c10_y.y = c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c10_u, "y", "y", 0)), &c10_thisId);
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_g_emlrt_marshallIn
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
   c10_struct_ZCmOWPuqBDw16FSOVVD00 *c10_y)
{
  emlrtMsgIdentifier c10_thisId;
  static const char * c10_fieldNames[29] = { "m", "Jz", "m_sprung", "Jx_sprung",
    "Jy_sprung", "lf", "lr", "L", "TrackWidth", "h", "HalfRohACd", "F_z4_static",
    "Rw", "r_long", "r_lat", "r_lever", "r_pivot", "cw", "carb_f", "carb_r",
    "dw", "Jw", "C0", "RelaxLength", "RRC", "Pmax", "PropDistrFrnt",
    "BrkDistrFrnt", "SteRatio" };

  c10_thisId.fParent = c10_parentId;
  sf_mex_check_struct(c10_parentId, c10_u, 29, c10_fieldNames, 0U, NULL);
  c10_thisId.fIdentifier = "m";
  c10_y->m = c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c10_u, "m", "m", 0)), &c10_thisId);
  c10_thisId.fIdentifier = "Jz";
  c10_y->Jz = c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c10_u, "Jz", "Jz", 0)), &c10_thisId);
  c10_thisId.fIdentifier = "m_sprung";
  c10_y->m_sprung = c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c10_u, "m_sprung", "m_sprung", 0)), &c10_thisId);
  c10_thisId.fIdentifier = "Jx_sprung";
  c10_y->Jx_sprung = c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c10_u, "Jx_sprung", "Jx_sprung", 0)), &c10_thisId);
  c10_thisId.fIdentifier = "Jy_sprung";
  c10_y->Jy_sprung = c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c10_u, "Jy_sprung", "Jy_sprung", 0)), &c10_thisId);
  c10_thisId.fIdentifier = "lf";
  c10_y->lf = c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c10_u, "lf", "lf", 0)), &c10_thisId);
  c10_thisId.fIdentifier = "lr";
  c10_y->lr = c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c10_u, "lr", "lr", 0)), &c10_thisId);
  c10_thisId.fIdentifier = "L";
  c10_y->L = c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c10_u, "L", "L", 0)), &c10_thisId);
  c10_thisId.fIdentifier = "TrackWidth";
  c10_y->TrackWidth = c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c10_u, "TrackWidth", "TrackWidth", 0)), &c10_thisId);
  c10_thisId.fIdentifier = "h";
  c10_y->h = c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c10_u, "h", "h", 0)), &c10_thisId);
  c10_thisId.fIdentifier = "HalfRohACd";
  c10_y->HalfRohACd = c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c10_u, "HalfRohACd", "HalfRohACd", 0)), &c10_thisId);
  c10_thisId.fIdentifier = "F_z4_static";
  c10_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c10_u,
    "F_z4_static", "F_z4_static", 0)), &c10_thisId, c10_y->F_z4_static);
  c10_thisId.fIdentifier = "Rw";
  c10_y->Rw = c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c10_u, "Rw", "Rw", 0)), &c10_thisId);
  c10_thisId.fIdentifier = "r_long";
  c10_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c10_u,
    "r_long", "r_long", 0)), &c10_thisId, &c10_y->r_long);
  c10_thisId.fIdentifier = "r_lat";
  c10_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c10_u,
    "r_lat", "r_lat", 0)), &c10_thisId, &c10_y->r_lat);
  c10_thisId.fIdentifier = "r_lever";
  c10_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c10_u,
    "r_lever", "r_lever", 0)), &c10_thisId, &c10_y->r_lever);
  c10_thisId.fIdentifier = "r_pivot";
  c10_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c10_u,
    "r_pivot", "r_pivot", 0)), &c10_thisId, &c10_y->r_pivot);
  c10_thisId.fIdentifier = "cw";
  c10_y->cw = c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c10_u, "cw", "cw", 0)), &c10_thisId);
  c10_thisId.fIdentifier = "carb_f";
  c10_y->carb_f = c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c10_u, "carb_f", "carb_f", 0)), &c10_thisId);
  c10_thisId.fIdentifier = "carb_r";
  c10_y->carb_r = c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c10_u, "carb_r", "carb_r", 0)), &c10_thisId);
  c10_thisId.fIdentifier = "dw";
  c10_y->dw = c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c10_u, "dw", "dw", 0)), &c10_thisId);
  c10_thisId.fIdentifier = "Jw";
  c10_y->Jw = c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c10_u, "Jw", "Jw", 0)), &c10_thisId);
  c10_thisId.fIdentifier = "C0";
  c10_y->C0 = c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c10_u, "C0", "C0", 0)), &c10_thisId);
  c10_thisId.fIdentifier = "RelaxLength";
  c10_y->RelaxLength = c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c10_u, "RelaxLength", "RelaxLength", 0)), &c10_thisId);
  c10_thisId.fIdentifier = "RRC";
  c10_y->RRC = c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c10_u, "RRC", "RRC", 0)), &c10_thisId);
  c10_thisId.fIdentifier = "Pmax";
  c10_y->Pmax = c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c10_u, "Pmax", "Pmax", 0)), &c10_thisId);
  c10_thisId.fIdentifier = "PropDistrFrnt";
  c10_y->PropDistrFrnt = c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c10_u, "PropDistrFrnt", "PropDistrFrnt", 0)), &c10_thisId);
  c10_thisId.fIdentifier = "BrkDistrFrnt";
  c10_y->BrkDistrFrnt = c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c10_u, "BrkDistrFrnt", "BrkDistrFrnt", 0)), &c10_thisId);
  c10_thisId.fIdentifier = "SteRatio";
  c10_y->SteRatio = c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c10_u, "SteRatio", "SteRatio", 0)), &c10_thisId);
  sf_mex_destroy(&c10_u);
}

static void c10_h_emlrt_marshallIn
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId, real_T c10_y[4])
{
  real_T c10_dv0[4];
  int32_T c10_i25;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), c10_dv0, 1, 0, 0U, 1, 0U, 2, 1,
                4);
  for (c10_i25 = 0; c10_i25 < 4; c10_i25++) {
    c10_y[c10_i25] = c10_dv0[c10_i25];
  }

  sf_mex_destroy(&c10_u);
}

static void c10_i_emlrt_marshallIn
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
   c10_struct_ZKAzdrl7umDGJoC14aoVKC *c10_y)
{
  emlrtMsgIdentifier c10_thisId;
  static const char * c10_fieldNames[4] = { "fl", "fr", "rl", "rr" };

  c10_thisId.fParent = c10_parentId;
  sf_mex_check_struct(c10_parentId, c10_u, 4, c10_fieldNames, 0U, NULL);
  c10_thisId.fIdentifier = "fl";
  c10_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c10_u, "fl",
    "fl", 0)), &c10_thisId, c10_y->fl);
  c10_thisId.fIdentifier = "fr";
  c10_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c10_u, "fr",
    "fr", 0)), &c10_thisId, c10_y->fr);
  c10_thisId.fIdentifier = "rl";
  c10_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c10_u, "rl",
    "rl", 0)), &c10_thisId, c10_y->rl);
  c10_thisId.fIdentifier = "rr";
  c10_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c10_u, "rr",
    "rr", 0)), &c10_thisId, c10_y->rr);
  sf_mex_destroy(&c10_u);
}

static void c10_j_emlrt_marshallIn
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId, real_T c10_y[3])
{
  real_T c10_dv1[3];
  int32_T c10_i26;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), c10_dv1, 1, 0, 0U, 1, 0U, 2, 3,
                1);
  for (c10_i26 = 0; c10_i26 < 3; c10_i26++) {
    c10_y[c10_i26] = c10_dv1[c10_i26];
  }

  sf_mex_destroy(&c10_u);
}

static c10_struct_r4FNviKwHfdhB8nQjvQv9 c10_k_emlrt_marshallIn
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  c10_struct_r4FNviKwHfdhB8nQjvQv9 c10_y;
  emlrtMsgIdentifier c10_thisId;
  static const char * c10_fieldNames[1] = { "v_set" };

  c10_thisId.fParent = c10_parentId;
  sf_mex_check_struct(c10_parentId, c10_u, 1, c10_fieldNames, 0U, NULL);
  c10_thisId.fIdentifier = "v_set";
  c10_y.v_set = c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c10_u, "v_set", "v_set", 0)),
    &c10_thisId);
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static c10_struct_Y9F1qlBi9AhssksPwemA4G c10_l_emlrt_marshallIn
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  c10_struct_Y9F1qlBi9AhssksPwemA4G c10_y;
  emlrtMsgIdentifier c10_thisId;
  static const char * c10_fieldNames[3] = { "v_x", "F_fz", "F_rz" };

  c10_thisId.fParent = c10_parentId;
  sf_mex_check_struct(c10_parentId, c10_u, 3, c10_fieldNames, 0U, NULL);
  c10_thisId.fIdentifier = "v_x";
  c10_y.v_x = c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c10_u, "v_x", "v_x", 0)), &c10_thisId);
  c10_thisId.fIdentifier = "F_fz";
  c10_y.F_fz = c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c10_u, "F_fz", "F_fz", 0)), &c10_thisId);
  c10_thisId.fIdentifier = "F_rz";
  c10_y.F_rz = c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c10_u, "F_rz", "F_rz", 0)), &c10_thisId);
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_b_Par;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  c10_struct_iBlsPBO3AGnt69vDoTx5zD c10_y;
  SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c10_b_Par = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_b_Par), &c10_thisId,
    &c10_y);
  sf_mex_destroy(&c10_b_Par);
  *(c10_struct_iBlsPBO3AGnt69vDoTx5zD *)c10_outData = c10_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

static const mxArray *c10_c_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  real_T c10_u;
  const mxArray *c10_y = NULL;
  SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(real_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static void c10_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_nargout;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  real_T c10_y;
  SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c10_nargout = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_nargout),
    &c10_thisId);
  sf_mex_destroy(&c10_nargout);
  *(real_T *)c10_outData = c10_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

const mxArray
  *sf_c10_AllPurposeModel_TyreRelaxation_get_eml_resolved_functions_info(void)
{
  const mxArray *c10_nameCaptureInfo = NULL;
  c10_nameCaptureInfo = NULL;
  sf_mex_assign(&c10_nameCaptureInfo, sf_mex_createstruct("structure", 2, 26, 1),
                false);
  c10_info_helper(&c10_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c10_nameCaptureInfo);
  return c10_nameCaptureInfo;
}

static void c10_info_helper(const mxArray **c10_info)
{
  const mxArray *c10_rhs0 = NULL;
  const mxArray *c10_lhs0 = NULL;
  const mxArray *c10_rhs1 = NULL;
  const mxArray *c10_lhs1 = NULL;
  const mxArray *c10_rhs2 = NULL;
  const mxArray *c10_lhs2 = NULL;
  const mxArray *c10_rhs3 = NULL;
  const mxArray *c10_lhs3 = NULL;
  const mxArray *c10_rhs4 = NULL;
  const mxArray *c10_lhs4 = NULL;
  const mxArray *c10_rhs5 = NULL;
  const mxArray *c10_lhs5 = NULL;
  const mxArray *c10_rhs6 = NULL;
  const mxArray *c10_lhs6 = NULL;
  const mxArray *c10_rhs7 = NULL;
  const mxArray *c10_lhs7 = NULL;
  const mxArray *c10_rhs8 = NULL;
  const mxArray *c10_lhs8 = NULL;
  const mxArray *c10_rhs9 = NULL;
  const mxArray *c10_lhs9 = NULL;
  const mxArray *c10_rhs10 = NULL;
  const mxArray *c10_lhs10 = NULL;
  const mxArray *c10_rhs11 = NULL;
  const mxArray *c10_lhs11 = NULL;
  const mxArray *c10_rhs12 = NULL;
  const mxArray *c10_lhs12 = NULL;
  const mxArray *c10_rhs13 = NULL;
  const mxArray *c10_lhs13 = NULL;
  const mxArray *c10_rhs14 = NULL;
  const mxArray *c10_lhs14 = NULL;
  const mxArray *c10_rhs15 = NULL;
  const mxArray *c10_lhs15 = NULL;
  const mxArray *c10_rhs16 = NULL;
  const mxArray *c10_lhs16 = NULL;
  const mxArray *c10_rhs17 = NULL;
  const mxArray *c10_lhs17 = NULL;
  const mxArray *c10_rhs18 = NULL;
  const mxArray *c10_lhs18 = NULL;
  const mxArray *c10_rhs19 = NULL;
  const mxArray *c10_lhs19 = NULL;
  const mxArray *c10_rhs20 = NULL;
  const mxArray *c10_lhs20 = NULL;
  const mxArray *c10_rhs21 = NULL;
  const mxArray *c10_lhs21 = NULL;
  const mxArray *c10_rhs22 = NULL;
  const mxArray *c10_lhs22 = NULL;
  const mxArray *c10_rhs23 = NULL;
  const mxArray *c10_lhs23 = NULL;
  const mxArray *c10_rhs24 = NULL;
  const mxArray *c10_lhs24 = NULL;
  const mxArray *c10_rhs25 = NULL;
  const mxArray *c10_lhs25 = NULL;
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 0);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1383877294U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c10_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 1);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c10_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 2);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 2);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c10_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 3);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 3);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c10_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 4);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c10_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 5);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 5);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c10_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 6);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_xdotu"), "name", "name",
                  6);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1375980690U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c10_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 7);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c10_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("coder.internal.blas.xdotu"),
                  "name", "name", 8);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdotu.p"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c10_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdotu.p"),
                  "context", "context", 9);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("coder.internal.blas.xdot"),
                  "name", "name", 9);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c10_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p"),
                  "context", "context", 10);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 10);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c10_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p!below_threshold"),
                  "context", "context", 11);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 11);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c10_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 12);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 12);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1393330858U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c10_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p"),
                  "context", "context", 13);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("coder.internal.refblas.xdot"),
                  "name", "name", 13);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdot.p"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c10_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdot.p"),
                  "context", "context", 14);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "coder.internal.refblas.xdotx"), "name", "name", 14);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c10_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 15);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 15);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c10_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 16);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 16);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1372583160U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c10_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 17);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 17);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 17);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1372583160U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c10_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 18);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 18);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 18);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1372583160U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c10_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 19);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 19);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1397257422U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c10_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 20);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("isfi"), "name", "name", 20);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 20);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1346510358U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c10_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("isnumerictype"), "name",
                  "name", 21);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                  "resolved", 21);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1398875598U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c10_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 22);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("intmax"), "name", "name", 22);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1362261882U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c10_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 23);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 23);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1393330858U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c10_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 24);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("intmin"), "name", "name", 24);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 24);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1362261882U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c10_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 25);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 25);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1393330858U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c10_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs25), "lhs", "lhs",
                  25);
  sf_mex_destroy(&c10_rhs0);
  sf_mex_destroy(&c10_lhs0);
  sf_mex_destroy(&c10_rhs1);
  sf_mex_destroy(&c10_lhs1);
  sf_mex_destroy(&c10_rhs2);
  sf_mex_destroy(&c10_lhs2);
  sf_mex_destroy(&c10_rhs3);
  sf_mex_destroy(&c10_lhs3);
  sf_mex_destroy(&c10_rhs4);
  sf_mex_destroy(&c10_lhs4);
  sf_mex_destroy(&c10_rhs5);
  sf_mex_destroy(&c10_lhs5);
  sf_mex_destroy(&c10_rhs6);
  sf_mex_destroy(&c10_lhs6);
  sf_mex_destroy(&c10_rhs7);
  sf_mex_destroy(&c10_lhs7);
  sf_mex_destroy(&c10_rhs8);
  sf_mex_destroy(&c10_lhs8);
  sf_mex_destroy(&c10_rhs9);
  sf_mex_destroy(&c10_lhs9);
  sf_mex_destroy(&c10_rhs10);
  sf_mex_destroy(&c10_lhs10);
  sf_mex_destroy(&c10_rhs11);
  sf_mex_destroy(&c10_lhs11);
  sf_mex_destroy(&c10_rhs12);
  sf_mex_destroy(&c10_lhs12);
  sf_mex_destroy(&c10_rhs13);
  sf_mex_destroy(&c10_lhs13);
  sf_mex_destroy(&c10_rhs14);
  sf_mex_destroy(&c10_lhs14);
  sf_mex_destroy(&c10_rhs15);
  sf_mex_destroy(&c10_lhs15);
  sf_mex_destroy(&c10_rhs16);
  sf_mex_destroy(&c10_lhs16);
  sf_mex_destroy(&c10_rhs17);
  sf_mex_destroy(&c10_lhs17);
  sf_mex_destroy(&c10_rhs18);
  sf_mex_destroy(&c10_lhs18);
  sf_mex_destroy(&c10_rhs19);
  sf_mex_destroy(&c10_lhs19);
  sf_mex_destroy(&c10_rhs20);
  sf_mex_destroy(&c10_lhs20);
  sf_mex_destroy(&c10_rhs21);
  sf_mex_destroy(&c10_lhs21);
  sf_mex_destroy(&c10_rhs22);
  sf_mex_destroy(&c10_lhs22);
  sf_mex_destroy(&c10_rhs23);
  sf_mex_destroy(&c10_lhs23);
  sf_mex_destroy(&c10_rhs24);
  sf_mex_destroy(&c10_lhs24);
  sf_mex_destroy(&c10_rhs25);
  sf_mex_destroy(&c10_lhs25);
}

static const mxArray *c10_emlrt_marshallOut(const char * c10_u)
{
  const mxArray *c10_y = NULL;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c10_u)), false);
  return c10_y;
}

static const mxArray *c10_b_emlrt_marshallOut(const uint32_T c10_u)
{
  const mxArray *c10_y = NULL;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 7, 0U, 0U, 0U, 0), false);
  return c10_y;
}

static real_T c10_eml_xdotu(SFc10_AllPurposeModel_TyreRelaxationInstanceStruct
  *chartInstance, real_T c10_x[2], real_T c10_y[2])
{
  real_T c10_d;
  int32_T c10_k;
  int32_T c10_b_k;
  (void)chartInstance;
  c10_d = 0.0;
  for (c10_k = 1; c10_k < 3; c10_k++) {
    c10_b_k = c10_k;
    c10_d += c10_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c10_b_k), 1, 2, 1, 0) - 1] * c10_y[_SFD_EML_ARRAY_BOUNDS_CHECK
      ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c10_b_k), 1, 2, 1, 0) - 1];
  }

  return c10_d;
}

static const mxArray *c10_d_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_u;
  const mxArray *c10_y = NULL;
  SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(int32_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static int32_T c10_m_emlrt_marshallIn
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  int32_T c10_y;
  int32_T c10_i27;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_i27, 1, 6, 0U, 0, 0U, 0);
  c10_y = c10_i27;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_b_sfEvent;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  int32_T c10_y;
  SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c10_b_sfEvent = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_b_sfEvent),
    &c10_thisId);
  sf_mex_destroy(&c10_b_sfEvent);
  *(int32_T *)c10_outData = c10_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

static const mxArray *c10_v_z4_bus_io(void *chartInstanceVoid, void *c10_pData)
{
  const mxArray *c10_mxVal = NULL;
  c10_whl_vec4 c10_tmp;
  SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c10_mxVal = NULL;
  c10_tmp.fl = *(real_T *)&((char_T *)(c10_whl_vec4 *)c10_pData)[0];
  c10_tmp.fr = *(real_T *)&((char_T *)(c10_whl_vec4 *)c10_pData)[8];
  c10_tmp.rl = *(real_T *)&((char_T *)(c10_whl_vec4 *)c10_pData)[16];
  c10_tmp.rr = *(real_T *)&((char_T *)(c10_whl_vec4 *)c10_pData)[24];
  sf_mex_assign(&c10_mxVal, c10_sf_marshallOut(chartInstance, &c10_tmp), false);
  return c10_mxVal;
}

static uint8_T c10_n_emlrt_marshallIn
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c10_b_is_active_c10_AllPurposeModel_TyreRelaxation, const char_T
   *c10_identifier)
{
  uint8_T c10_y;
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_o_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c10_b_is_active_c10_AllPurposeModel_TyreRelaxation), &c10_thisId);
  sf_mex_destroy(&c10_b_is_active_c10_AllPurposeModel_TyreRelaxation);
  return c10_y;
}

static uint8_T c10_o_emlrt_marshallIn
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  uint8_T c10_y;
  uint8_T c10_u0;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_u0, 1, 3, 0U, 0, 0U, 0);
  c10_y = c10_u0;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void init_dsm_address_info
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address
  (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  chartInstance->c10_v_z4 = (c10_whl_vec4 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c10_derF_s4 = (c10_whl_vec4 *)ssGetOutputPortSignal_wrapper
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

void sf_c10_AllPurposeModel_TyreRelaxation_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3841130609U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3401720007U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(418273331U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2244263972U);
}

mxArray* sf_c10_AllPurposeModel_TyreRelaxation_get_post_codegen_info(void);
mxArray *sf_c10_AllPurposeModel_TyreRelaxation_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("ijnia3wGSrr6KZdgYe8NpH");
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
    mxArray* mxPostCodegenInfo =
      sf_c10_AllPurposeModel_TyreRelaxation_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c10_AllPurposeModel_TyreRelaxation_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c10_AllPurposeModel_TyreRelaxation_jit_fallback_info(void)
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

mxArray *sf_c10_AllPurposeModel_TyreRelaxation_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c10_AllPurposeModel_TyreRelaxation_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c10_AllPurposeModel_TyreRelaxation
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[7],T\"derF_s4\",},{M[8],M[0],T\"is_active_c10_AllPurposeModel_TyreRelaxation\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c10_AllPurposeModel_TyreRelaxation_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _AllPurposeModel_TyreRelaxationMachineNumber_,
           10,
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
          (MexFcnForType)c10_v_z4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_v_z4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_b_sf_marshallOut,(MexInFcnForType)
          c10_b_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c10_v_z4);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c10_derF_s4);
        _SFD_SET_DATA_VALUE_PTR(2U, &chartInstance->c10_Par);
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
  return "lcIk9en1LW0e1qHv8nkmzB";
}

static void sf_opaque_initialize_c10_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc10_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar)->S,
     0);
  initialize_params_c10_AllPurposeModel_TyreRelaxation
    ((SFc10_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
  initialize_c10_AllPurposeModel_TyreRelaxation
    ((SFc10_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c10_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  enable_c10_AllPurposeModel_TyreRelaxation
    ((SFc10_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c10_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  disable_c10_AllPurposeModel_TyreRelaxation
    ((SFc10_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c10_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  sf_gateway_c10_AllPurposeModel_TyreRelaxation
    ((SFc10_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c10_AllPurposeModel_TyreRelaxation
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c10_AllPurposeModel_TyreRelaxation
    ((SFc10_AllPurposeModel_TyreRelaxationInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c10_AllPurposeModel_TyreRelaxation(SimStruct*
  S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c10_AllPurposeModel_TyreRelaxation
    ((SFc10_AllPurposeModel_TyreRelaxationInstanceStruct*)
     chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c10_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc10_AllPurposeModel_TyreRelaxationInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_AllPurposeModel_TyreRelaxation_optimization_info();
    }

    finalize_c10_AllPurposeModel_TyreRelaxation
      ((SFc10_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc10_AllPurposeModel_TyreRelaxation
    ((SFc10_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c10_AllPurposeModel_TyreRelaxation(SimStruct *S)
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
    initialize_params_c10_AllPurposeModel_TyreRelaxation
      ((SFc10_AllPurposeModel_TyreRelaxationInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c10_AllPurposeModel_TyreRelaxation(SimStruct *S)
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
      10);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,10,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,10,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,10);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,10,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,10,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,10);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3153987535U));
  ssSetChecksum1(S,(2644706056U));
  ssSetChecksum2(S,(3802749903U));
  ssSetChecksum3(S,(2306637408U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c10_AllPurposeModel_TyreRelaxation(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c10_AllPurposeModel_TyreRelaxation(SimStruct *S)
{
  SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct *)utMalloc
    (sizeof(SFc10_AllPurposeModel_TyreRelaxationInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc10_AllPurposeModel_TyreRelaxationInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c10_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c10_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c10_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c10_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c10_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c10_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c10_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c10_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c10_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c10_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c10_AllPurposeModel_TyreRelaxation;
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

void c10_AllPurposeModel_TyreRelaxation_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c10_AllPurposeModel_TyreRelaxation(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c10_AllPurposeModel_TyreRelaxation(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c10_AllPurposeModel_TyreRelaxation(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c10_AllPurposeModel_TyreRelaxation_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
