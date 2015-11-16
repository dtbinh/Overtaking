/* Include files */

#include <stddef.h>
#include "blas.h"
#include "AllPurposeModel_TyreRelaxation_sfun.h"
#include "c13_AllPurposeModel_TyreRelaxation.h"
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
static const char * c13_debug_family_names[13] = { "w1", "w2", "w3", "w4", "lf",
  "lr", "v_oorp3_temp", "v_oorp4", "nargin", "nargout", "v_oorp3", "Par", "v_z4"
};

/* Function Declarations */
static void initialize_c13_AllPurposeModel_TyreRelaxation
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void initialize_params_c13_AllPurposeModel_TyreRelaxation
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void enable_c13_AllPurposeModel_TyreRelaxation
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void disable_c13_AllPurposeModel_TyreRelaxation
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void c13_update_debugger_state_c13_AllPurposeModel_TyreRelaxation
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c13_AllPurposeModel_TyreRelaxation
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void set_sim_state_c13_AllPurposeModel_TyreRelaxation
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c13_st);
static void finalize_c13_AllPurposeModel_TyreRelaxation
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void sf_gateway_c13_AllPurposeModel_TyreRelaxation
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void mdl_start_c13_AllPurposeModel_TyreRelaxation
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void initSimStructsc13_AllPurposeModel_TyreRelaxation
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c13_machineNumber, uint32_T
  c13_chartNumber, uint32_T c13_instanceNumber);
static const mxArray *c13_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static c13_whl_vec4 c13_emlrt_marshallIn
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c13_b_v_z4, const char_T *c13_identifier);
static c13_whl_vec4 c13_b_emlrt_marshallIn
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static real_T c13_c_emlrt_marshallIn
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void c13_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static const mxArray *c13_b_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static void c13_d_emlrt_marshallIn
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId,
   c13_struct_iBlsPBO3AGnt69vDoTx5zD *c13_y);
static void c13_e_emlrt_marshallIn
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId,
   c13_struct_Nst2vGTExxHsg85EUOj9EH *c13_y);
static c13_struct_HhckT6rntEraqECYVIDvCC c13_f_emlrt_marshallIn
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void c13_g_emlrt_marshallIn
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId,
   c13_struct_ZCmOWPuqBDw16FSOVVD00 *c13_y);
static void c13_h_emlrt_marshallIn
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId, real_T c13_y[4]);
static void c13_i_emlrt_marshallIn
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId,
   c13_struct_ZKAzdrl7umDGJoC14aoVKC *c13_y);
static void c13_j_emlrt_marshallIn
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId, real_T c13_y[3]);
static c13_struct_r4FNviKwHfdhB8nQjvQv9 c13_k_emlrt_marshallIn
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static c13_struct_Y9F1qlBi9AhssksPwemA4G c13_l_emlrt_marshallIn
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void c13_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static const mxArray *c13_c_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static const mxArray *c13_d_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static void c13_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static const mxArray *c13_e_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static void c13_m_emlrt_marshallIn
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId, real_T c13_y[4]);
static void c13_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static const mxArray *c13_f_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static void c13_n_emlrt_marshallIn
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId, real_T c13_y[3]);
static void c13_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static void c13_info_helper(const mxArray **c13_info);
static const mxArray *c13_emlrt_marshallOut(const char * c13_u);
static const mxArray *c13_b_emlrt_marshallOut(const uint32_T c13_u);
static void c13_eml_scalar_eg(SFc13_AllPurposeModel_TyreRelaxationInstanceStruct
  *chartInstance);
static void c13_eml_xgemm(SFc13_AllPurposeModel_TyreRelaxationInstanceStruct
  *chartInstance, real_T c13_A[12], real_T c13_B[3], real_T c13_C[4], real_T
  c13_b_C[4]);
static const mxArray *c13_g_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static int32_T c13_o_emlrt_marshallIn
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void c13_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static const mxArray *c13_v_oorp3_bus_io(void *chartInstanceVoid, void
  *c13_pData);
static const mxArray *c13_v_z4_bus_io(void *chartInstanceVoid, void *c13_pData);
static uint8_T c13_p_emlrt_marshallIn
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c13_b_is_active_c13_AllPurposeModel_TyreRelaxation, const char_T
   *c13_identifier);
static uint8_T c13_q_emlrt_marshallIn
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void c13_b_eml_xgemm(SFc13_AllPurposeModel_TyreRelaxationInstanceStruct
  *chartInstance, real_T c13_A[12], real_T c13_B[3], real_T c13_C[4]);
static void init_dsm_address_info
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void init_simulink_io_address
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c13_AllPurposeModel_TyreRelaxation
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  chartInstance->c13_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c13_is_active_c13_AllPurposeModel_TyreRelaxation = 0U;
}

static void initialize_params_c13_AllPurposeModel_TyreRelaxation
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  const mxArray *c13_m0 = NULL;
  const mxArray *c13_mxField;
  const mxArray *c13_m1 = NULL;
  const mxArray *c13_b_mxField;
  c13_struct_iBlsPBO3AGnt69vDoTx5zD c13_r0;
  const mxArray *c13_m2 = NULL;
  const mxArray *c13_c_mxField;
  const mxArray *c13_m3 = NULL;
  const mxArray *c13_d_mxField;
  const mxArray *c13_m4 = NULL;
  const mxArray *c13_e_mxField;
  const mxArray *c13_m5 = NULL;
  const mxArray *c13_f_mxField;
  const mxArray *c13_m6 = NULL;
  const mxArray *c13_g_mxField;
  const mxArray *c13_m7 = NULL;
  const mxArray *c13_h_mxField;
  const mxArray *c13_m8 = NULL;
  const mxArray *c13_i_mxField;
  const mxArray *c13_m9 = NULL;
  const mxArray *c13_j_mxField;
  const mxArray *c13_m10 = NULL;
  const mxArray *c13_k_mxField;
  const mxArray *c13_m11 = NULL;
  const mxArray *c13_l_mxField;
  const mxArray *c13_m12 = NULL;
  const mxArray *c13_m_mxField;
  const mxArray *c13_m13 = NULL;
  const mxArray *c13_n_mxField;
  c13_m0 = sf_mex_get_sfun_param(chartInstance->S, 0, 1);
  c13_mxField = sf_mex_getfield(c13_m0, "Env", "Par", 0);
  c13_m1 = sf_mex_dup(c13_mxField);
  c13_b_mxField = sf_mex_getfield(c13_m1, "g", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_b_mxField), &c13_r0.Env.g, 1, 0, 0U,
                      0, 0U, 0);
  c13_b_mxField = sf_mex_getfield(c13_m1, "left1", "Par", 0);
  c13_m2 = sf_mex_dup(c13_b_mxField);
  c13_c_mxField = sf_mex_getfield(c13_m2, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_c_mxField), &c13_r0.Env.left1.x, 1,
                      0, 0U, 0, 0U, 0);
  c13_c_mxField = sf_mex_getfield(c13_m2, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_c_mxField), &c13_r0.Env.left1.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c13_m2);
  c13_b_mxField = sf_mex_getfield(c13_m1, "right1", "Par", 0);
  c13_m3 = sf_mex_dup(c13_b_mxField);
  c13_d_mxField = sf_mex_getfield(c13_m3, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_d_mxField), &c13_r0.Env.right1.x, 1,
                      0, 0U, 0, 0U, 0);
  c13_d_mxField = sf_mex_getfield(c13_m3, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_d_mxField), &c13_r0.Env.right1.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c13_m3);
  c13_b_mxField = sf_mex_getfield(c13_m1, "right2", "Par", 0);
  c13_m4 = sf_mex_dup(c13_b_mxField);
  c13_e_mxField = sf_mex_getfield(c13_m4, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_e_mxField), &c13_r0.Env.right2.x, 1,
                      0, 0U, 0, 0U, 0);
  c13_e_mxField = sf_mex_getfield(c13_m4, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_e_mxField), &c13_r0.Env.right2.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c13_m4);
  c13_b_mxField = sf_mex_getfield(c13_m1, "left2", "Par", 0);
  c13_m5 = sf_mex_dup(c13_b_mxField);
  c13_f_mxField = sf_mex_getfield(c13_m5, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_f_mxField), &c13_r0.Env.left2.x, 1,
                      0, 0U, 0, 0U, 0);
  c13_f_mxField = sf_mex_getfield(c13_m5, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_f_mxField), &c13_r0.Env.left2.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c13_m5);
  c13_b_mxField = sf_mex_getfield(c13_m1, "right3", "Par", 0);
  c13_m6 = sf_mex_dup(c13_b_mxField);
  c13_g_mxField = sf_mex_getfield(c13_m6, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_g_mxField), &c13_r0.Env.right3.x, 1,
                      0, 0U, 0, 0U, 0);
  c13_g_mxField = sf_mex_getfield(c13_m6, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_g_mxField), &c13_r0.Env.right3.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c13_m6);
  c13_b_mxField = sf_mex_getfield(c13_m1, "mu", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_b_mxField), &c13_r0.Env.mu, 1, 0, 0U,
                      0, 0U, 0);
  sf_mex_destroy(&c13_m1);
  c13_mxField = sf_mex_getfield(c13_m0, "Veh", "Par", 0);
  c13_m7 = sf_mex_dup(c13_mxField);
  c13_h_mxField = sf_mex_getfield(c13_m7, "m", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_h_mxField), &c13_r0.Veh.m, 1, 0, 0U,
                      0, 0U, 0);
  c13_h_mxField = sf_mex_getfield(c13_m7, "Jz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_h_mxField), &c13_r0.Veh.Jz, 1, 0, 0U,
                      0, 0U, 0);
  c13_h_mxField = sf_mex_getfield(c13_m7, "m_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_h_mxField), &c13_r0.Veh.m_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c13_h_mxField = sf_mex_getfield(c13_m7, "Jx_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_h_mxField), &c13_r0.Veh.Jx_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c13_h_mxField = sf_mex_getfield(c13_m7, "Jy_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_h_mxField), &c13_r0.Veh.Jy_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c13_h_mxField = sf_mex_getfield(c13_m7, "lf", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_h_mxField), &c13_r0.Veh.lf, 1, 0, 0U,
                      0, 0U, 0);
  c13_h_mxField = sf_mex_getfield(c13_m7, "lr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_h_mxField), &c13_r0.Veh.lr, 1, 0, 0U,
                      0, 0U, 0);
  c13_h_mxField = sf_mex_getfield(c13_m7, "L", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_h_mxField), &c13_r0.Veh.L, 1, 0, 0U,
                      0, 0U, 0);
  c13_h_mxField = sf_mex_getfield(c13_m7, "TrackWidth", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_h_mxField), &c13_r0.Veh.TrackWidth,
                      1, 0, 0U, 0, 0U, 0);
  c13_h_mxField = sf_mex_getfield(c13_m7, "h", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_h_mxField), &c13_r0.Veh.h, 1, 0, 0U,
                      0, 0U, 0);
  c13_h_mxField = sf_mex_getfield(c13_m7, "HalfRohACd", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_h_mxField), &c13_r0.Veh.HalfRohACd,
                      1, 0, 0U, 0, 0U, 0);
  c13_h_mxField = sf_mex_getfield(c13_m7, "F_z4_static", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_h_mxField), c13_r0.Veh.F_z4_static,
                      1, 0, 0U, 1, 0U, 2, 1, 4);
  c13_h_mxField = sf_mex_getfield(c13_m7, "Rw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_h_mxField), &c13_r0.Veh.Rw, 1, 0, 0U,
                      0, 0U, 0);
  c13_h_mxField = sf_mex_getfield(c13_m7, "r_long", "Par", 0);
  c13_m8 = sf_mex_dup(c13_h_mxField);
  c13_i_mxField = sf_mex_getfield(c13_m8, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_i_mxField), c13_r0.Veh.r_long.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c13_i_mxField = sf_mex_getfield(c13_m8, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_i_mxField), c13_r0.Veh.r_long.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c13_i_mxField = sf_mex_getfield(c13_m8, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_i_mxField), c13_r0.Veh.r_long.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c13_i_mxField = sf_mex_getfield(c13_m8, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_i_mxField), c13_r0.Veh.r_long.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c13_m8);
  c13_h_mxField = sf_mex_getfield(c13_m7, "r_lat", "Par", 0);
  c13_m9 = sf_mex_dup(c13_h_mxField);
  c13_j_mxField = sf_mex_getfield(c13_m9, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_j_mxField), c13_r0.Veh.r_lat.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c13_j_mxField = sf_mex_getfield(c13_m9, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_j_mxField), c13_r0.Veh.r_lat.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c13_j_mxField = sf_mex_getfield(c13_m9, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_j_mxField), c13_r0.Veh.r_lat.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c13_j_mxField = sf_mex_getfield(c13_m9, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_j_mxField), c13_r0.Veh.r_lat.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c13_m9);
  c13_h_mxField = sf_mex_getfield(c13_m7, "r_lever", "Par", 0);
  c13_m10 = sf_mex_dup(c13_h_mxField);
  c13_k_mxField = sf_mex_getfield(c13_m10, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_k_mxField), c13_r0.Veh.r_lever.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c13_k_mxField = sf_mex_getfield(c13_m10, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_k_mxField), c13_r0.Veh.r_lever.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c13_k_mxField = sf_mex_getfield(c13_m10, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_k_mxField), c13_r0.Veh.r_lever.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c13_k_mxField = sf_mex_getfield(c13_m10, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_k_mxField), c13_r0.Veh.r_lever.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c13_m10);
  c13_h_mxField = sf_mex_getfield(c13_m7, "r_pivot", "Par", 0);
  c13_m11 = sf_mex_dup(c13_h_mxField);
  c13_l_mxField = sf_mex_getfield(c13_m11, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_l_mxField), c13_r0.Veh.r_pivot.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c13_l_mxField = sf_mex_getfield(c13_m11, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_l_mxField), c13_r0.Veh.r_pivot.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c13_l_mxField = sf_mex_getfield(c13_m11, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_l_mxField), c13_r0.Veh.r_pivot.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c13_l_mxField = sf_mex_getfield(c13_m11, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_l_mxField), c13_r0.Veh.r_pivot.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c13_m11);
  c13_h_mxField = sf_mex_getfield(c13_m7, "cw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_h_mxField), &c13_r0.Veh.cw, 1, 0, 0U,
                      0, 0U, 0);
  c13_h_mxField = sf_mex_getfield(c13_m7, "carb_f", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_h_mxField), &c13_r0.Veh.carb_f, 1, 0,
                      0U, 0, 0U, 0);
  c13_h_mxField = sf_mex_getfield(c13_m7, "carb_r", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_h_mxField), &c13_r0.Veh.carb_r, 1, 0,
                      0U, 0, 0U, 0);
  c13_h_mxField = sf_mex_getfield(c13_m7, "dw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_h_mxField), &c13_r0.Veh.dw, 1, 0, 0U,
                      0, 0U, 0);
  c13_h_mxField = sf_mex_getfield(c13_m7, "Jw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_h_mxField), &c13_r0.Veh.Jw, 1, 0, 0U,
                      0, 0U, 0);
  c13_h_mxField = sf_mex_getfield(c13_m7, "C0", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_h_mxField), &c13_r0.Veh.C0, 1, 0, 0U,
                      0, 0U, 0);
  c13_h_mxField = sf_mex_getfield(c13_m7, "RelaxLength", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_h_mxField), &c13_r0.Veh.RelaxLength,
                      1, 0, 0U, 0, 0U, 0);
  c13_h_mxField = sf_mex_getfield(c13_m7, "RRC", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_h_mxField), &c13_r0.Veh.RRC, 1, 0,
                      0U, 0, 0U, 0);
  c13_h_mxField = sf_mex_getfield(c13_m7, "Pmax", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_h_mxField), &c13_r0.Veh.Pmax, 1, 0,
                      0U, 0, 0U, 0);
  c13_h_mxField = sf_mex_getfield(c13_m7, "PropDistrFrnt", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_h_mxField),
                      &c13_r0.Veh.PropDistrFrnt, 1, 0, 0U, 0, 0U, 0);
  c13_h_mxField = sf_mex_getfield(c13_m7, "BrkDistrFrnt", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_h_mxField), &c13_r0.Veh.BrkDistrFrnt,
                      1, 0, 0U, 0, 0U, 0);
  c13_h_mxField = sf_mex_getfield(c13_m7, "SteRatio", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_h_mxField), &c13_r0.Veh.SteRatio, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c13_m7);
  c13_mxField = sf_mex_getfield(c13_m0, "Drvr", "Par", 0);
  c13_m12 = sf_mex_dup(c13_mxField);
  c13_m_mxField = sf_mex_getfield(c13_m12, "v_set", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_m_mxField), &c13_r0.Drvr.v_set, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c13_m12);
  c13_mxField = sf_mex_getfield(c13_m0, "Init", "Par", 0);
  c13_m13 = sf_mex_dup(c13_mxField);
  c13_n_mxField = sf_mex_getfield(c13_m13, "v_x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_n_mxField), &c13_r0.Init.v_x, 1, 0,
                      0U, 0, 0U, 0);
  c13_n_mxField = sf_mex_getfield(c13_m13, "F_fz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_n_mxField), &c13_r0.Init.F_fz, 1, 0,
                      0U, 0, 0U, 0);
  c13_n_mxField = sf_mex_getfield(c13_m13, "F_rz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c13_n_mxField), &c13_r0.Init.F_rz, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c13_m13);
  sf_mex_destroy(&c13_m0);
  chartInstance->c13_Par = c13_r0;
}

static void enable_c13_AllPurposeModel_TyreRelaxation
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c13_AllPurposeModel_TyreRelaxation
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c13_update_debugger_state_c13_AllPurposeModel_TyreRelaxation
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c13_AllPurposeModel_TyreRelaxation
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  const mxArray *c13_st;
  const mxArray *c13_y = NULL;
  const mxArray *c13_b_y = NULL;
  real_T c13_u;
  const mxArray *c13_c_y = NULL;
  real_T c13_b_u;
  const mxArray *c13_d_y = NULL;
  real_T c13_c_u;
  const mxArray *c13_e_y = NULL;
  real_T c13_d_u;
  const mxArray *c13_f_y = NULL;
  uint8_T c13_hoistedGlobal;
  uint8_T c13_e_u;
  const mxArray *c13_g_y = NULL;
  c13_st = NULL;
  c13_st = NULL;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_createcellmatrix(2, 1), false);
  c13_b_y = NULL;
  sf_mex_assign(&c13_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c13_u = *(real_T *)&((char_T *)chartInstance->c13_v_z4)[0];
  c13_c_y = NULL;
  sf_mex_assign(&c13_c_y, sf_mex_create("y", &c13_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_b_y, c13_c_y, "fl", "fl", 0);
  c13_b_u = *(real_T *)&((char_T *)chartInstance->c13_v_z4)[8];
  c13_d_y = NULL;
  sf_mex_assign(&c13_d_y, sf_mex_create("y", &c13_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_b_y, c13_d_y, "fr", "fr", 0);
  c13_c_u = *(real_T *)&((char_T *)chartInstance->c13_v_z4)[16];
  c13_e_y = NULL;
  sf_mex_assign(&c13_e_y, sf_mex_create("y", &c13_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_b_y, c13_e_y, "rl", "rl", 0);
  c13_d_u = *(real_T *)&((char_T *)chartInstance->c13_v_z4)[24];
  c13_f_y = NULL;
  sf_mex_assign(&c13_f_y, sf_mex_create("y", &c13_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_b_y, c13_f_y, "rr", "rr", 0);
  sf_mex_setcell(c13_y, 0, c13_b_y);
  c13_hoistedGlobal =
    chartInstance->c13_is_active_c13_AllPurposeModel_TyreRelaxation;
  c13_e_u = c13_hoistedGlobal;
  c13_g_y = NULL;
  sf_mex_assign(&c13_g_y, sf_mex_create("y", &c13_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c13_y, 1, c13_g_y);
  sf_mex_assign(&c13_st, c13_y, false);
  return c13_st;
}

static void set_sim_state_c13_AllPurposeModel_TyreRelaxation
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c13_st)
{
  const mxArray *c13_u;
  c13_whl_vec4 c13_r1;
  chartInstance->c13_doneDoubleBufferReInit = true;
  c13_u = sf_mex_dup(c13_st);
  c13_r1 = c13_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c13_u,
    0)), "v_z4");
  *(real_T *)&((char_T *)chartInstance->c13_v_z4)[0] = c13_r1.fl;
  *(real_T *)&((char_T *)chartInstance->c13_v_z4)[8] = c13_r1.fr;
  *(real_T *)&((char_T *)chartInstance->c13_v_z4)[16] = c13_r1.rl;
  *(real_T *)&((char_T *)chartInstance->c13_v_z4)[24] = c13_r1.rr;
  chartInstance->c13_is_active_c13_AllPurposeModel_TyreRelaxation =
    c13_p_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c13_u, 1)),
    "is_active_c13_AllPurposeModel_TyreRelaxation");
  sf_mex_destroy(&c13_u);
  c13_update_debugger_state_c13_AllPurposeModel_TyreRelaxation(chartInstance);
  sf_mex_destroy(&c13_st);
}

static void finalize_c13_AllPurposeModel_TyreRelaxation
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c13_AllPurposeModel_TyreRelaxation
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  c13_oorp_vec3 c13_b_v_oorp3;
  c13_struct_iBlsPBO3AGnt69vDoTx5zD c13_b_Par;
  uint32_T c13_debug_family_var_map[13];
  real_T c13_w1;
  real_T c13_w2;
  real_T c13_w3;
  real_T c13_w4;
  real_T c13_lf;
  real_T c13_lr;
  real_T c13_v_oorp3_temp[3];
  real_T c13_v_oorp4[4];
  real_T c13_nargin = 2.0;
  real_T c13_nargout = 1.0;
  c13_whl_vec4 c13_b_v_z4;
  real_T c13_A;
  real_T c13_x;
  real_T c13_b_x;
  real_T c13_c_x;
  real_T c13_b_w1[4];
  real_T c13_b_lf[4];
  int32_T c13_i0;
  real_T c13_a[12];
  int32_T c13_i1;
  int32_T c13_i2;
  int32_T c13_i3;
  real_T c13_b[3];
  int32_T c13_i4;
  int32_T c13_i5;
  int32_T c13_i6;
  real_T c13_b_a[12];
  int32_T c13_i7;
  real_T c13_b_b[3];
  int32_T c13_i8;
  c13_whl_vec4 c13_r2;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 12U, chartInstance->c13_sfEvent);
  chartInstance->c13_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 12U, chartInstance->c13_sfEvent);
  c13_b_v_oorp3.z = *(real_T *)&((char_T *)chartInstance->c13_v_oorp3)[0];
  c13_b_v_oorp3.rotx = *(real_T *)&((char_T *)chartInstance->c13_v_oorp3)[8];
  c13_b_v_oorp3.roty = *(real_T *)&((char_T *)chartInstance->c13_v_oorp3)[16];
  c13_b_Par = chartInstance->c13_Par;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 13U, 13U, c13_debug_family_names,
    c13_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_w1, 0U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_w2, 1U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_w3, 2U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_w4, 3U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_lf, 4U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_lr, 5U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_v_oorp3_temp, 6U,
    c13_f_sf_marshallOut, c13_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_v_oorp4, 7U, c13_e_sf_marshallOut,
    c13_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_nargin, 8U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_nargout, 9U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c13_b_v_oorp3, 10U, c13_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_b_Par, 11U, c13_b_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_b_v_z4, 12U, c13_sf_marshallOut,
    c13_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 5);
  c13_A = c13_b_Par.Veh.TrackWidth;
  c13_x = c13_A;
  c13_b_x = c13_x;
  c13_c_x = c13_b_x;
  c13_w1 = c13_c_x / 2.0;
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 6);
  c13_w2 = -c13_w1;
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 7);
  c13_w3 = c13_w1;
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 8);
  c13_w4 = c13_w2;
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 10);
  c13_lf = c13_b_Par.Veh.lf;
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 11);
  c13_lr = c13_b_Par.Veh.lr;
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 13);
  c13_v_oorp3_temp[0] = c13_b_v_oorp3.z;
  c13_v_oorp3_temp[1] = c13_b_v_oorp3.rotx;
  c13_v_oorp3_temp[2] = c13_b_v_oorp3.roty;
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 15);
  c13_b_w1[0] = c13_w1;
  c13_b_w1[1] = c13_w2;
  c13_b_w1[2] = c13_w3;
  c13_b_w1[3] = c13_w4;
  c13_b_lf[0] = -c13_lf;
  c13_b_lf[1] = -c13_lf;
  c13_b_lf[2] = -c13_lr;
  c13_b_lf[3] = -c13_lr;
  for (c13_i0 = 0; c13_i0 < 4; c13_i0++) {
    c13_a[c13_i0] = 1.0;
  }

  for (c13_i1 = 0; c13_i1 < 4; c13_i1++) {
    c13_a[c13_i1 + 4] = c13_b_w1[c13_i1];
  }

  for (c13_i2 = 0; c13_i2 < 4; c13_i2++) {
    c13_a[c13_i2 + 8] = c13_b_lf[c13_i2];
  }

  for (c13_i3 = 0; c13_i3 < 3; c13_i3++) {
    c13_b[c13_i3] = c13_v_oorp3_temp[c13_i3];
  }

  c13_eml_scalar_eg(chartInstance);
  c13_eml_scalar_eg(chartInstance);
  for (c13_i4 = 0; c13_i4 < 4; c13_i4++) {
    c13_v_oorp4[c13_i4] = 0.0;
  }

  for (c13_i5 = 0; c13_i5 < 4; c13_i5++) {
    c13_b_w1[c13_i5] = 0.0;
  }

  for (c13_i6 = 0; c13_i6 < 12; c13_i6++) {
    c13_b_a[c13_i6] = c13_a[c13_i6];
  }

  for (c13_i7 = 0; c13_i7 < 3; c13_i7++) {
    c13_b_b[c13_i7] = c13_b[c13_i7];
  }

  c13_b_eml_xgemm(chartInstance, c13_b_a, c13_b_b, c13_b_w1);
  for (c13_i8 = 0; c13_i8 < 4; c13_i8++) {
    c13_v_oorp4[c13_i8] = c13_b_w1[c13_i8];
  }

  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 17);
  c13_r2.fl = c13_v_oorp4[0];
  c13_r2.fr = c13_v_oorp4[1];
  c13_r2.rl = c13_v_oorp4[2];
  c13_r2.rr = c13_v_oorp4[3];
  c13_b_v_z4 = c13_r2;
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, -17);
  _SFD_SYMBOL_SCOPE_POP();
  *(real_T *)&((char_T *)chartInstance->c13_v_z4)[0] = c13_b_v_z4.fl;
  *(real_T *)&((char_T *)chartInstance->c13_v_z4)[8] = c13_b_v_z4.fr;
  *(real_T *)&((char_T *)chartInstance->c13_v_z4)[16] = c13_b_v_z4.rl;
  *(real_T *)&((char_T *)chartInstance->c13_v_z4)[24] = c13_b_v_z4.rr;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c13_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_AllPurposeModel_TyreRelaxationMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void mdl_start_c13_AllPurposeModel_TyreRelaxation
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc13_AllPurposeModel_TyreRelaxation
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c13_machineNumber, uint32_T
  c13_chartNumber, uint32_T c13_instanceNumber)
{
  (void)c13_machineNumber;
  (void)c13_chartNumber;
  (void)c13_instanceNumber;
}

static const mxArray *c13_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  c13_whl_vec4 c13_u;
  const mxArray *c13_y = NULL;
  real_T c13_b_u;
  const mxArray *c13_b_y = NULL;
  real_T c13_c_u;
  const mxArray *c13_c_y = NULL;
  real_T c13_d_u;
  const mxArray *c13_d_y = NULL;
  real_T c13_e_u;
  const mxArray *c13_e_y = NULL;
  SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_u = *(c13_whl_vec4 *)c13_inData;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c13_b_u = c13_u.fl;
  c13_b_y = NULL;
  sf_mex_assign(&c13_b_y, sf_mex_create("y", &c13_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_y, c13_b_y, "fl", "fl", 0);
  c13_c_u = c13_u.fr;
  c13_c_y = NULL;
  sf_mex_assign(&c13_c_y, sf_mex_create("y", &c13_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_y, c13_c_y, "fr", "fr", 0);
  c13_d_u = c13_u.rl;
  c13_d_y = NULL;
  sf_mex_assign(&c13_d_y, sf_mex_create("y", &c13_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_y, c13_d_y, "rl", "rl", 0);
  c13_e_u = c13_u.rr;
  c13_e_y = NULL;
  sf_mex_assign(&c13_e_y, sf_mex_create("y", &c13_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_y, c13_e_y, "rr", "rr", 0);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, false);
  return c13_mxArrayOutData;
}

static c13_whl_vec4 c13_emlrt_marshallIn
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c13_b_v_z4, const char_T *c13_identifier)
{
  c13_whl_vec4 c13_y;
  emlrtMsgIdentifier c13_thisId;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_b_v_z4),
    &c13_thisId);
  sf_mex_destroy(&c13_b_v_z4);
  return c13_y;
}

static c13_whl_vec4 c13_b_emlrt_marshallIn
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  c13_whl_vec4 c13_y;
  emlrtMsgIdentifier c13_thisId;
  static const char * c13_fieldNames[4] = { "fl", "fr", "rl", "rr" };

  c13_thisId.fParent = c13_parentId;
  sf_mex_check_struct(c13_parentId, c13_u, 4, c13_fieldNames, 0U, NULL);
  c13_thisId.fIdentifier = "fl";
  c13_y.fl = c13_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c13_u, "fl", "fl", 0)), &c13_thisId);
  c13_thisId.fIdentifier = "fr";
  c13_y.fr = c13_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c13_u, "fr", "fr", 0)), &c13_thisId);
  c13_thisId.fIdentifier = "rl";
  c13_y.rl = c13_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c13_u, "rl", "rl", 0)), &c13_thisId);
  c13_thisId.fIdentifier = "rr";
  c13_y.rr = c13_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c13_u, "rr", "rr", 0)), &c13_thisId);
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static real_T c13_c_emlrt_marshallIn
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  real_T c13_y;
  real_T c13_d0;
  (void)chartInstance;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_d0, 1, 0, 0U, 0, 0U, 0);
  c13_y = c13_d0;
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void c13_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_b_v_z4;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  c13_whl_vec4 c13_y;
  SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c13_b_v_z4 = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_b_v_z4),
    &c13_thisId);
  sf_mex_destroy(&c13_b_v_z4);
  *(c13_whl_vec4 *)c13_outData = c13_y;
  sf_mex_destroy(&c13_mxArrayInData);
}

static const mxArray *c13_b_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData;
  c13_struct_iBlsPBO3AGnt69vDoTx5zD c13_u;
  const mxArray *c13_y = NULL;
  c13_struct_Nst2vGTExxHsg85EUOj9EH c13_b_u;
  const mxArray *c13_b_y = NULL;
  real_T c13_c_u;
  const mxArray *c13_c_y = NULL;
  c13_struct_HhckT6rntEraqECYVIDvCC c13_d_u;
  const mxArray *c13_d_y = NULL;
  real_T c13_e_u;
  const mxArray *c13_e_y = NULL;
  real_T c13_f_u;
  const mxArray *c13_f_y = NULL;
  const mxArray *c13_g_y = NULL;
  real_T c13_g_u;
  const mxArray *c13_h_y = NULL;
  real_T c13_h_u;
  const mxArray *c13_i_y = NULL;
  const mxArray *c13_j_y = NULL;
  real_T c13_i_u;
  const mxArray *c13_k_y = NULL;
  real_T c13_j_u;
  const mxArray *c13_l_y = NULL;
  const mxArray *c13_m_y = NULL;
  real_T c13_k_u;
  const mxArray *c13_n_y = NULL;
  real_T c13_l_u;
  const mxArray *c13_o_y = NULL;
  const mxArray *c13_p_y = NULL;
  real_T c13_m_u;
  const mxArray *c13_q_y = NULL;
  real_T c13_n_u;
  const mxArray *c13_r_y = NULL;
  real_T c13_o_u;
  const mxArray *c13_s_y = NULL;
  c13_struct_ZCmOWPuqBDw16FSOVVD00 c13_p_u;
  const mxArray *c13_t_y = NULL;
  real_T c13_q_u;
  const mxArray *c13_u_y = NULL;
  real_T c13_r_u;
  const mxArray *c13_v_y = NULL;
  real_T c13_s_u;
  const mxArray *c13_w_y = NULL;
  real_T c13_t_u;
  const mxArray *c13_x_y = NULL;
  real_T c13_u_u;
  const mxArray *c13_y_y = NULL;
  real_T c13_v_u;
  const mxArray *c13_ab_y = NULL;
  real_T c13_w_u;
  const mxArray *c13_bb_y = NULL;
  real_T c13_x_u;
  const mxArray *c13_cb_y = NULL;
  real_T c13_y_u;
  const mxArray *c13_db_y = NULL;
  real_T c13_ab_u;
  const mxArray *c13_eb_y = NULL;
  real_T c13_bb_u;
  const mxArray *c13_fb_y = NULL;
  int32_T c13_i9;
  real_T c13_cb_u[4];
  const mxArray *c13_gb_y = NULL;
  real_T c13_db_u;
  const mxArray *c13_hb_y = NULL;
  c13_struct_ZKAzdrl7umDGJoC14aoVKC c13_eb_u;
  const mxArray *c13_ib_y = NULL;
  int32_T c13_i10;
  real_T c13_fb_u[3];
  const mxArray *c13_jb_y = NULL;
  int32_T c13_i11;
  real_T c13_gb_u[3];
  const mxArray *c13_kb_y = NULL;
  int32_T c13_i12;
  real_T c13_hb_u[3];
  const mxArray *c13_lb_y = NULL;
  int32_T c13_i13;
  real_T c13_ib_u[3];
  const mxArray *c13_mb_y = NULL;
  const mxArray *c13_nb_y = NULL;
  int32_T c13_i14;
  real_T c13_jb_u[3];
  const mxArray *c13_ob_y = NULL;
  int32_T c13_i15;
  real_T c13_kb_u[3];
  const mxArray *c13_pb_y = NULL;
  int32_T c13_i16;
  real_T c13_lb_u[3];
  const mxArray *c13_qb_y = NULL;
  int32_T c13_i17;
  real_T c13_mb_u[3];
  const mxArray *c13_rb_y = NULL;
  const mxArray *c13_sb_y = NULL;
  int32_T c13_i18;
  real_T c13_nb_u[3];
  const mxArray *c13_tb_y = NULL;
  int32_T c13_i19;
  real_T c13_ob_u[3];
  const mxArray *c13_ub_y = NULL;
  int32_T c13_i20;
  real_T c13_pb_u[3];
  const mxArray *c13_vb_y = NULL;
  int32_T c13_i21;
  real_T c13_qb_u[3];
  const mxArray *c13_wb_y = NULL;
  const mxArray *c13_xb_y = NULL;
  int32_T c13_i22;
  real_T c13_rb_u[3];
  const mxArray *c13_yb_y = NULL;
  int32_T c13_i23;
  real_T c13_sb_u[3];
  const mxArray *c13_ac_y = NULL;
  int32_T c13_i24;
  real_T c13_tb_u[3];
  const mxArray *c13_bc_y = NULL;
  int32_T c13_i25;
  real_T c13_ub_u[3];
  const mxArray *c13_cc_y = NULL;
  real_T c13_vb_u;
  const mxArray *c13_dc_y = NULL;
  real_T c13_wb_u;
  const mxArray *c13_ec_y = NULL;
  real_T c13_xb_u;
  const mxArray *c13_fc_y = NULL;
  real_T c13_yb_u;
  const mxArray *c13_gc_y = NULL;
  real_T c13_ac_u;
  const mxArray *c13_hc_y = NULL;
  real_T c13_bc_u;
  const mxArray *c13_ic_y = NULL;
  real_T c13_cc_u;
  const mxArray *c13_jc_y = NULL;
  real_T c13_dc_u;
  const mxArray *c13_kc_y = NULL;
  real_T c13_ec_u;
  const mxArray *c13_lc_y = NULL;
  real_T c13_fc_u;
  const mxArray *c13_mc_y = NULL;
  real_T c13_gc_u;
  const mxArray *c13_nc_y = NULL;
  real_T c13_hc_u;
  const mxArray *c13_oc_y = NULL;
  c13_struct_r4FNviKwHfdhB8nQjvQv9 c13_ic_u;
  const mxArray *c13_pc_y = NULL;
  real_T c13_jc_u;
  const mxArray *c13_qc_y = NULL;
  c13_struct_Y9F1qlBi9AhssksPwemA4G c13_kc_u;
  const mxArray *c13_rc_y = NULL;
  real_T c13_lc_u;
  const mxArray *c13_sc_y = NULL;
  real_T c13_mc_u;
  const mxArray *c13_tc_y = NULL;
  real_T c13_nc_u;
  const mxArray *c13_uc_y = NULL;
  SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_mxArrayOutData = NULL;
  c13_u = *(c13_struct_iBlsPBO3AGnt69vDoTx5zD *)c13_inData;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c13_b_u = c13_u.Env;
  c13_b_y = NULL;
  sf_mex_assign(&c13_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c13_c_u = c13_b_u.g;
  c13_c_y = NULL;
  sf_mex_assign(&c13_c_y, sf_mex_create("y", &c13_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_b_y, c13_c_y, "g", "g", 0);
  c13_d_u = c13_b_u.left1;
  c13_d_y = NULL;
  sf_mex_assign(&c13_d_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c13_e_u = c13_d_u.x;
  c13_e_y = NULL;
  sf_mex_assign(&c13_e_y, sf_mex_create("y", &c13_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_d_y, c13_e_y, "x", "x", 0);
  c13_f_u = c13_d_u.y;
  c13_f_y = NULL;
  sf_mex_assign(&c13_f_y, sf_mex_create("y", &c13_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_d_y, c13_f_y, "y", "y", 0);
  sf_mex_addfield(c13_b_y, c13_d_y, "left1", "left1", 0);
  c13_d_u = c13_b_u.right1;
  c13_g_y = NULL;
  sf_mex_assign(&c13_g_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c13_g_u = c13_d_u.x;
  c13_h_y = NULL;
  sf_mex_assign(&c13_h_y, sf_mex_create("y", &c13_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_g_y, c13_h_y, "x", "x", 0);
  c13_h_u = c13_d_u.y;
  c13_i_y = NULL;
  sf_mex_assign(&c13_i_y, sf_mex_create("y", &c13_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_g_y, c13_i_y, "y", "y", 0);
  sf_mex_addfield(c13_b_y, c13_g_y, "right1", "right1", 0);
  c13_d_u = c13_b_u.right2;
  c13_j_y = NULL;
  sf_mex_assign(&c13_j_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c13_i_u = c13_d_u.x;
  c13_k_y = NULL;
  sf_mex_assign(&c13_k_y, sf_mex_create("y", &c13_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_j_y, c13_k_y, "x", "x", 0);
  c13_j_u = c13_d_u.y;
  c13_l_y = NULL;
  sf_mex_assign(&c13_l_y, sf_mex_create("y", &c13_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_j_y, c13_l_y, "y", "y", 0);
  sf_mex_addfield(c13_b_y, c13_j_y, "right2", "right2", 0);
  c13_d_u = c13_b_u.left2;
  c13_m_y = NULL;
  sf_mex_assign(&c13_m_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c13_k_u = c13_d_u.x;
  c13_n_y = NULL;
  sf_mex_assign(&c13_n_y, sf_mex_create("y", &c13_k_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_m_y, c13_n_y, "x", "x", 0);
  c13_l_u = c13_d_u.y;
  c13_o_y = NULL;
  sf_mex_assign(&c13_o_y, sf_mex_create("y", &c13_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_m_y, c13_o_y, "y", "y", 0);
  sf_mex_addfield(c13_b_y, c13_m_y, "left2", "left2", 0);
  c13_d_u = c13_b_u.right3;
  c13_p_y = NULL;
  sf_mex_assign(&c13_p_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c13_m_u = c13_d_u.x;
  c13_q_y = NULL;
  sf_mex_assign(&c13_q_y, sf_mex_create("y", &c13_m_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_p_y, c13_q_y, "x", "x", 0);
  c13_n_u = c13_d_u.y;
  c13_r_y = NULL;
  sf_mex_assign(&c13_r_y, sf_mex_create("y", &c13_n_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_p_y, c13_r_y, "y", "y", 0);
  sf_mex_addfield(c13_b_y, c13_p_y, "right3", "right3", 0);
  c13_o_u = c13_b_u.mu;
  c13_s_y = NULL;
  sf_mex_assign(&c13_s_y, sf_mex_create("y", &c13_o_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_b_y, c13_s_y, "mu", "mu", 0);
  sf_mex_addfield(c13_y, c13_b_y, "Env", "Env", 0);
  c13_p_u = c13_u.Veh;
  c13_t_y = NULL;
  sf_mex_assign(&c13_t_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c13_q_u = c13_p_u.m;
  c13_u_y = NULL;
  sf_mex_assign(&c13_u_y, sf_mex_create("y", &c13_q_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_t_y, c13_u_y, "m", "m", 0);
  c13_r_u = c13_p_u.Jz;
  c13_v_y = NULL;
  sf_mex_assign(&c13_v_y, sf_mex_create("y", &c13_r_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_t_y, c13_v_y, "Jz", "Jz", 0);
  c13_s_u = c13_p_u.m_sprung;
  c13_w_y = NULL;
  sf_mex_assign(&c13_w_y, sf_mex_create("y", &c13_s_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_t_y, c13_w_y, "m_sprung", "m_sprung", 0);
  c13_t_u = c13_p_u.Jx_sprung;
  c13_x_y = NULL;
  sf_mex_assign(&c13_x_y, sf_mex_create("y", &c13_t_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_t_y, c13_x_y, "Jx_sprung", "Jx_sprung", 0);
  c13_u_u = c13_p_u.Jy_sprung;
  c13_y_y = NULL;
  sf_mex_assign(&c13_y_y, sf_mex_create("y", &c13_u_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_t_y, c13_y_y, "Jy_sprung", "Jy_sprung", 0);
  c13_v_u = c13_p_u.lf;
  c13_ab_y = NULL;
  sf_mex_assign(&c13_ab_y, sf_mex_create("y", &c13_v_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_t_y, c13_ab_y, "lf", "lf", 0);
  c13_w_u = c13_p_u.lr;
  c13_bb_y = NULL;
  sf_mex_assign(&c13_bb_y, sf_mex_create("y", &c13_w_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_t_y, c13_bb_y, "lr", "lr", 0);
  c13_x_u = c13_p_u.L;
  c13_cb_y = NULL;
  sf_mex_assign(&c13_cb_y, sf_mex_create("y", &c13_x_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_t_y, c13_cb_y, "L", "L", 0);
  c13_y_u = c13_p_u.TrackWidth;
  c13_db_y = NULL;
  sf_mex_assign(&c13_db_y, sf_mex_create("y", &c13_y_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_t_y, c13_db_y, "TrackWidth", "TrackWidth", 0);
  c13_ab_u = c13_p_u.h;
  c13_eb_y = NULL;
  sf_mex_assign(&c13_eb_y, sf_mex_create("y", &c13_ab_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_t_y, c13_eb_y, "h", "h", 0);
  c13_bb_u = c13_p_u.HalfRohACd;
  c13_fb_y = NULL;
  sf_mex_assign(&c13_fb_y, sf_mex_create("y", &c13_bb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_t_y, c13_fb_y, "HalfRohACd", "HalfRohACd", 0);
  for (c13_i9 = 0; c13_i9 < 4; c13_i9++) {
    c13_cb_u[c13_i9] = c13_p_u.F_z4_static[c13_i9];
  }

  c13_gb_y = NULL;
  sf_mex_assign(&c13_gb_y, sf_mex_create("y", c13_cb_u, 0, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_addfield(c13_t_y, c13_gb_y, "F_z4_static", "F_z4_static", 0);
  c13_db_u = c13_p_u.Rw;
  c13_hb_y = NULL;
  sf_mex_assign(&c13_hb_y, sf_mex_create("y", &c13_db_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_t_y, c13_hb_y, "Rw", "Rw", 0);
  c13_eb_u = c13_p_u.r_long;
  c13_ib_y = NULL;
  sf_mex_assign(&c13_ib_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c13_i10 = 0; c13_i10 < 3; c13_i10++) {
    c13_fb_u[c13_i10] = c13_eb_u.fl[c13_i10];
  }

  c13_jb_y = NULL;
  sf_mex_assign(&c13_jb_y, sf_mex_create("y", c13_fb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c13_ib_y, c13_jb_y, "fl", "fl", 0);
  for (c13_i11 = 0; c13_i11 < 3; c13_i11++) {
    c13_gb_u[c13_i11] = c13_eb_u.fr[c13_i11];
  }

  c13_kb_y = NULL;
  sf_mex_assign(&c13_kb_y, sf_mex_create("y", c13_gb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c13_ib_y, c13_kb_y, "fr", "fr", 0);
  for (c13_i12 = 0; c13_i12 < 3; c13_i12++) {
    c13_hb_u[c13_i12] = c13_eb_u.rl[c13_i12];
  }

  c13_lb_y = NULL;
  sf_mex_assign(&c13_lb_y, sf_mex_create("y", c13_hb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c13_ib_y, c13_lb_y, "rl", "rl", 0);
  for (c13_i13 = 0; c13_i13 < 3; c13_i13++) {
    c13_ib_u[c13_i13] = c13_eb_u.rr[c13_i13];
  }

  c13_mb_y = NULL;
  sf_mex_assign(&c13_mb_y, sf_mex_create("y", c13_ib_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c13_ib_y, c13_mb_y, "rr", "rr", 0);
  sf_mex_addfield(c13_t_y, c13_ib_y, "r_long", "r_long", 0);
  c13_eb_u = c13_p_u.r_lat;
  c13_nb_y = NULL;
  sf_mex_assign(&c13_nb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c13_i14 = 0; c13_i14 < 3; c13_i14++) {
    c13_jb_u[c13_i14] = c13_eb_u.fl[c13_i14];
  }

  c13_ob_y = NULL;
  sf_mex_assign(&c13_ob_y, sf_mex_create("y", c13_jb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c13_nb_y, c13_ob_y, "fl", "fl", 0);
  for (c13_i15 = 0; c13_i15 < 3; c13_i15++) {
    c13_kb_u[c13_i15] = c13_eb_u.fr[c13_i15];
  }

  c13_pb_y = NULL;
  sf_mex_assign(&c13_pb_y, sf_mex_create("y", c13_kb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c13_nb_y, c13_pb_y, "fr", "fr", 0);
  for (c13_i16 = 0; c13_i16 < 3; c13_i16++) {
    c13_lb_u[c13_i16] = c13_eb_u.rl[c13_i16];
  }

  c13_qb_y = NULL;
  sf_mex_assign(&c13_qb_y, sf_mex_create("y", c13_lb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c13_nb_y, c13_qb_y, "rl", "rl", 0);
  for (c13_i17 = 0; c13_i17 < 3; c13_i17++) {
    c13_mb_u[c13_i17] = c13_eb_u.rr[c13_i17];
  }

  c13_rb_y = NULL;
  sf_mex_assign(&c13_rb_y, sf_mex_create("y", c13_mb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c13_nb_y, c13_rb_y, "rr", "rr", 0);
  sf_mex_addfield(c13_t_y, c13_nb_y, "r_lat", "r_lat", 0);
  c13_eb_u = c13_p_u.r_lever;
  c13_sb_y = NULL;
  sf_mex_assign(&c13_sb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c13_i18 = 0; c13_i18 < 3; c13_i18++) {
    c13_nb_u[c13_i18] = c13_eb_u.fl[c13_i18];
  }

  c13_tb_y = NULL;
  sf_mex_assign(&c13_tb_y, sf_mex_create("y", c13_nb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c13_sb_y, c13_tb_y, "fl", "fl", 0);
  for (c13_i19 = 0; c13_i19 < 3; c13_i19++) {
    c13_ob_u[c13_i19] = c13_eb_u.fr[c13_i19];
  }

  c13_ub_y = NULL;
  sf_mex_assign(&c13_ub_y, sf_mex_create("y", c13_ob_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c13_sb_y, c13_ub_y, "fr", "fr", 0);
  for (c13_i20 = 0; c13_i20 < 3; c13_i20++) {
    c13_pb_u[c13_i20] = c13_eb_u.rl[c13_i20];
  }

  c13_vb_y = NULL;
  sf_mex_assign(&c13_vb_y, sf_mex_create("y", c13_pb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c13_sb_y, c13_vb_y, "rl", "rl", 0);
  for (c13_i21 = 0; c13_i21 < 3; c13_i21++) {
    c13_qb_u[c13_i21] = c13_eb_u.rr[c13_i21];
  }

  c13_wb_y = NULL;
  sf_mex_assign(&c13_wb_y, sf_mex_create("y", c13_qb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c13_sb_y, c13_wb_y, "rr", "rr", 0);
  sf_mex_addfield(c13_t_y, c13_sb_y, "r_lever", "r_lever", 0);
  c13_eb_u = c13_p_u.r_pivot;
  c13_xb_y = NULL;
  sf_mex_assign(&c13_xb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c13_i22 = 0; c13_i22 < 3; c13_i22++) {
    c13_rb_u[c13_i22] = c13_eb_u.fl[c13_i22];
  }

  c13_yb_y = NULL;
  sf_mex_assign(&c13_yb_y, sf_mex_create("y", c13_rb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c13_xb_y, c13_yb_y, "fl", "fl", 0);
  for (c13_i23 = 0; c13_i23 < 3; c13_i23++) {
    c13_sb_u[c13_i23] = c13_eb_u.fr[c13_i23];
  }

  c13_ac_y = NULL;
  sf_mex_assign(&c13_ac_y, sf_mex_create("y", c13_sb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c13_xb_y, c13_ac_y, "fr", "fr", 0);
  for (c13_i24 = 0; c13_i24 < 3; c13_i24++) {
    c13_tb_u[c13_i24] = c13_eb_u.rl[c13_i24];
  }

  c13_bc_y = NULL;
  sf_mex_assign(&c13_bc_y, sf_mex_create("y", c13_tb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c13_xb_y, c13_bc_y, "rl", "rl", 0);
  for (c13_i25 = 0; c13_i25 < 3; c13_i25++) {
    c13_ub_u[c13_i25] = c13_eb_u.rr[c13_i25];
  }

  c13_cc_y = NULL;
  sf_mex_assign(&c13_cc_y, sf_mex_create("y", c13_ub_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c13_xb_y, c13_cc_y, "rr", "rr", 0);
  sf_mex_addfield(c13_t_y, c13_xb_y, "r_pivot", "r_pivot", 0);
  c13_vb_u = c13_p_u.cw;
  c13_dc_y = NULL;
  sf_mex_assign(&c13_dc_y, sf_mex_create("y", &c13_vb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_t_y, c13_dc_y, "cw", "cw", 0);
  c13_wb_u = c13_p_u.carb_f;
  c13_ec_y = NULL;
  sf_mex_assign(&c13_ec_y, sf_mex_create("y", &c13_wb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_t_y, c13_ec_y, "carb_f", "carb_f", 0);
  c13_xb_u = c13_p_u.carb_r;
  c13_fc_y = NULL;
  sf_mex_assign(&c13_fc_y, sf_mex_create("y", &c13_xb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_t_y, c13_fc_y, "carb_r", "carb_r", 0);
  c13_yb_u = c13_p_u.dw;
  c13_gc_y = NULL;
  sf_mex_assign(&c13_gc_y, sf_mex_create("y", &c13_yb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_t_y, c13_gc_y, "dw", "dw", 0);
  c13_ac_u = c13_p_u.Jw;
  c13_hc_y = NULL;
  sf_mex_assign(&c13_hc_y, sf_mex_create("y", &c13_ac_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_t_y, c13_hc_y, "Jw", "Jw", 0);
  c13_bc_u = c13_p_u.C0;
  c13_ic_y = NULL;
  sf_mex_assign(&c13_ic_y, sf_mex_create("y", &c13_bc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_t_y, c13_ic_y, "C0", "C0", 0);
  c13_cc_u = c13_p_u.RelaxLength;
  c13_jc_y = NULL;
  sf_mex_assign(&c13_jc_y, sf_mex_create("y", &c13_cc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_t_y, c13_jc_y, "RelaxLength", "RelaxLength", 0);
  c13_dc_u = c13_p_u.RRC;
  c13_kc_y = NULL;
  sf_mex_assign(&c13_kc_y, sf_mex_create("y", &c13_dc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_t_y, c13_kc_y, "RRC", "RRC", 0);
  c13_ec_u = c13_p_u.Pmax;
  c13_lc_y = NULL;
  sf_mex_assign(&c13_lc_y, sf_mex_create("y", &c13_ec_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_t_y, c13_lc_y, "Pmax", "Pmax", 0);
  c13_fc_u = c13_p_u.PropDistrFrnt;
  c13_mc_y = NULL;
  sf_mex_assign(&c13_mc_y, sf_mex_create("y", &c13_fc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_t_y, c13_mc_y, "PropDistrFrnt", "PropDistrFrnt", 0);
  c13_gc_u = c13_p_u.BrkDistrFrnt;
  c13_nc_y = NULL;
  sf_mex_assign(&c13_nc_y, sf_mex_create("y", &c13_gc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_t_y, c13_nc_y, "BrkDistrFrnt", "BrkDistrFrnt", 0);
  c13_hc_u = c13_p_u.SteRatio;
  c13_oc_y = NULL;
  sf_mex_assign(&c13_oc_y, sf_mex_create("y", &c13_hc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_t_y, c13_oc_y, "SteRatio", "SteRatio", 0);
  sf_mex_addfield(c13_y, c13_t_y, "Veh", "Veh", 0);
  c13_ic_u = c13_u.Drvr;
  c13_pc_y = NULL;
  sf_mex_assign(&c13_pc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c13_jc_u = c13_ic_u.v_set;
  c13_qc_y = NULL;
  sf_mex_assign(&c13_qc_y, sf_mex_create("y", &c13_jc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_pc_y, c13_qc_y, "v_set", "v_set", 0);
  sf_mex_addfield(c13_y, c13_pc_y, "Drvr", "Drvr", 0);
  c13_kc_u = c13_u.Init;
  c13_rc_y = NULL;
  sf_mex_assign(&c13_rc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c13_lc_u = c13_kc_u.v_x;
  c13_sc_y = NULL;
  sf_mex_assign(&c13_sc_y, sf_mex_create("y", &c13_lc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_rc_y, c13_sc_y, "v_x", "v_x", 0);
  c13_mc_u = c13_kc_u.F_fz;
  c13_tc_y = NULL;
  sf_mex_assign(&c13_tc_y, sf_mex_create("y", &c13_mc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_rc_y, c13_tc_y, "F_fz", "F_fz", 0);
  c13_nc_u = c13_kc_u.F_rz;
  c13_uc_y = NULL;
  sf_mex_assign(&c13_uc_y, sf_mex_create("y", &c13_nc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_rc_y, c13_uc_y, "F_rz", "F_rz", 0);
  sf_mex_addfield(c13_y, c13_rc_y, "Init", "Init", 0);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, false);
  return c13_mxArrayOutData;
}

static void c13_d_emlrt_marshallIn
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId,
   c13_struct_iBlsPBO3AGnt69vDoTx5zD *c13_y)
{
  emlrtMsgIdentifier c13_thisId;
  static const char * c13_fieldNames[4] = { "Env", "Veh", "Drvr", "Init" };

  c13_thisId.fParent = c13_parentId;
  sf_mex_check_struct(c13_parentId, c13_u, 4, c13_fieldNames, 0U, NULL);
  c13_thisId.fIdentifier = "Env";
  c13_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c13_u, "Env",
    "Env", 0)), &c13_thisId, &c13_y->Env);
  c13_thisId.fIdentifier = "Veh";
  c13_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c13_u, "Veh",
    "Veh", 0)), &c13_thisId, &c13_y->Veh);
  c13_thisId.fIdentifier = "Drvr";
  c13_y->Drvr = c13_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c13_u, "Drvr", "Drvr", 0)), &c13_thisId);
  c13_thisId.fIdentifier = "Init";
  c13_y->Init = c13_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c13_u, "Init", "Init", 0)), &c13_thisId);
  sf_mex_destroy(&c13_u);
}

static void c13_e_emlrt_marshallIn
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId,
   c13_struct_Nst2vGTExxHsg85EUOj9EH *c13_y)
{
  emlrtMsgIdentifier c13_thisId;
  static const char * c13_fieldNames[7] = { "g", "left1", "right1", "right2",
    "left2", "right3", "mu" };

  c13_thisId.fParent = c13_parentId;
  sf_mex_check_struct(c13_parentId, c13_u, 7, c13_fieldNames, 0U, NULL);
  c13_thisId.fIdentifier = "g";
  c13_y->g = c13_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c13_u, "g", "g", 0)), &c13_thisId);
  c13_thisId.fIdentifier = "left1";
  c13_y->left1 = c13_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c13_u, "left1", "left1", 0)), &c13_thisId);
  c13_thisId.fIdentifier = "right1";
  c13_y->right1 = c13_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c13_u, "right1", "right1", 0)), &c13_thisId);
  c13_thisId.fIdentifier = "right2";
  c13_y->right2 = c13_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c13_u, "right2", "right2", 0)), &c13_thisId);
  c13_thisId.fIdentifier = "left2";
  c13_y->left2 = c13_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c13_u, "left2", "left2", 0)), &c13_thisId);
  c13_thisId.fIdentifier = "right3";
  c13_y->right3 = c13_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c13_u, "right3", "right3", 0)), &c13_thisId);
  c13_thisId.fIdentifier = "mu";
  c13_y->mu = c13_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c13_u, "mu", "mu", 0)), &c13_thisId);
  sf_mex_destroy(&c13_u);
}

static c13_struct_HhckT6rntEraqECYVIDvCC c13_f_emlrt_marshallIn
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  c13_struct_HhckT6rntEraqECYVIDvCC c13_y;
  emlrtMsgIdentifier c13_thisId;
  static const char * c13_fieldNames[2] = { "x", "y" };

  c13_thisId.fParent = c13_parentId;
  sf_mex_check_struct(c13_parentId, c13_u, 2, c13_fieldNames, 0U, NULL);
  c13_thisId.fIdentifier = "x";
  c13_y.x = c13_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c13_u, "x", "x", 0)), &c13_thisId);
  c13_thisId.fIdentifier = "y";
  c13_y.y = c13_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c13_u, "y", "y", 0)), &c13_thisId);
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void c13_g_emlrt_marshallIn
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId,
   c13_struct_ZCmOWPuqBDw16FSOVVD00 *c13_y)
{
  emlrtMsgIdentifier c13_thisId;
  static const char * c13_fieldNames[29] = { "m", "Jz", "m_sprung", "Jx_sprung",
    "Jy_sprung", "lf", "lr", "L", "TrackWidth", "h", "HalfRohACd", "F_z4_static",
    "Rw", "r_long", "r_lat", "r_lever", "r_pivot", "cw", "carb_f", "carb_r",
    "dw", "Jw", "C0", "RelaxLength", "RRC", "Pmax", "PropDistrFrnt",
    "BrkDistrFrnt", "SteRatio" };

  c13_thisId.fParent = c13_parentId;
  sf_mex_check_struct(c13_parentId, c13_u, 29, c13_fieldNames, 0U, NULL);
  c13_thisId.fIdentifier = "m";
  c13_y->m = c13_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c13_u, "m", "m", 0)), &c13_thisId);
  c13_thisId.fIdentifier = "Jz";
  c13_y->Jz = c13_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c13_u, "Jz", "Jz", 0)), &c13_thisId);
  c13_thisId.fIdentifier = "m_sprung";
  c13_y->m_sprung = c13_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c13_u, "m_sprung", "m_sprung", 0)), &c13_thisId);
  c13_thisId.fIdentifier = "Jx_sprung";
  c13_y->Jx_sprung = c13_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c13_u, "Jx_sprung", "Jx_sprung", 0)), &c13_thisId);
  c13_thisId.fIdentifier = "Jy_sprung";
  c13_y->Jy_sprung = c13_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c13_u, "Jy_sprung", "Jy_sprung", 0)), &c13_thisId);
  c13_thisId.fIdentifier = "lf";
  c13_y->lf = c13_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c13_u, "lf", "lf", 0)), &c13_thisId);
  c13_thisId.fIdentifier = "lr";
  c13_y->lr = c13_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c13_u, "lr", "lr", 0)), &c13_thisId);
  c13_thisId.fIdentifier = "L";
  c13_y->L = c13_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c13_u, "L", "L", 0)), &c13_thisId);
  c13_thisId.fIdentifier = "TrackWidth";
  c13_y->TrackWidth = c13_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c13_u, "TrackWidth", "TrackWidth", 0)), &c13_thisId);
  c13_thisId.fIdentifier = "h";
  c13_y->h = c13_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c13_u, "h", "h", 0)), &c13_thisId);
  c13_thisId.fIdentifier = "HalfRohACd";
  c13_y->HalfRohACd = c13_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c13_u, "HalfRohACd", "HalfRohACd", 0)), &c13_thisId);
  c13_thisId.fIdentifier = "F_z4_static";
  c13_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c13_u,
    "F_z4_static", "F_z4_static", 0)), &c13_thisId, c13_y->F_z4_static);
  c13_thisId.fIdentifier = "Rw";
  c13_y->Rw = c13_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c13_u, "Rw", "Rw", 0)), &c13_thisId);
  c13_thisId.fIdentifier = "r_long";
  c13_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c13_u,
    "r_long", "r_long", 0)), &c13_thisId, &c13_y->r_long);
  c13_thisId.fIdentifier = "r_lat";
  c13_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c13_u,
    "r_lat", "r_lat", 0)), &c13_thisId, &c13_y->r_lat);
  c13_thisId.fIdentifier = "r_lever";
  c13_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c13_u,
    "r_lever", "r_lever", 0)), &c13_thisId, &c13_y->r_lever);
  c13_thisId.fIdentifier = "r_pivot";
  c13_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c13_u,
    "r_pivot", "r_pivot", 0)), &c13_thisId, &c13_y->r_pivot);
  c13_thisId.fIdentifier = "cw";
  c13_y->cw = c13_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c13_u, "cw", "cw", 0)), &c13_thisId);
  c13_thisId.fIdentifier = "carb_f";
  c13_y->carb_f = c13_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c13_u, "carb_f", "carb_f", 0)), &c13_thisId);
  c13_thisId.fIdentifier = "carb_r";
  c13_y->carb_r = c13_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c13_u, "carb_r", "carb_r", 0)), &c13_thisId);
  c13_thisId.fIdentifier = "dw";
  c13_y->dw = c13_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c13_u, "dw", "dw", 0)), &c13_thisId);
  c13_thisId.fIdentifier = "Jw";
  c13_y->Jw = c13_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c13_u, "Jw", "Jw", 0)), &c13_thisId);
  c13_thisId.fIdentifier = "C0";
  c13_y->C0 = c13_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c13_u, "C0", "C0", 0)), &c13_thisId);
  c13_thisId.fIdentifier = "RelaxLength";
  c13_y->RelaxLength = c13_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c13_u, "RelaxLength", "RelaxLength", 0)), &c13_thisId);
  c13_thisId.fIdentifier = "RRC";
  c13_y->RRC = c13_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c13_u, "RRC", "RRC", 0)), &c13_thisId);
  c13_thisId.fIdentifier = "Pmax";
  c13_y->Pmax = c13_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c13_u, "Pmax", "Pmax", 0)), &c13_thisId);
  c13_thisId.fIdentifier = "PropDistrFrnt";
  c13_y->PropDistrFrnt = c13_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c13_u, "PropDistrFrnt", "PropDistrFrnt", 0)), &c13_thisId);
  c13_thisId.fIdentifier = "BrkDistrFrnt";
  c13_y->BrkDistrFrnt = c13_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c13_u, "BrkDistrFrnt", "BrkDistrFrnt", 0)), &c13_thisId);
  c13_thisId.fIdentifier = "SteRatio";
  c13_y->SteRatio = c13_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c13_u, "SteRatio", "SteRatio", 0)), &c13_thisId);
  sf_mex_destroy(&c13_u);
}

static void c13_h_emlrt_marshallIn
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId, real_T c13_y[4])
{
  real_T c13_dv0[4];
  int32_T c13_i26;
  (void)chartInstance;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), c13_dv0, 1, 0, 0U, 1, 0U, 2, 1,
                4);
  for (c13_i26 = 0; c13_i26 < 4; c13_i26++) {
    c13_y[c13_i26] = c13_dv0[c13_i26];
  }

  sf_mex_destroy(&c13_u);
}

static void c13_i_emlrt_marshallIn
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId,
   c13_struct_ZKAzdrl7umDGJoC14aoVKC *c13_y)
{
  emlrtMsgIdentifier c13_thisId;
  static const char * c13_fieldNames[4] = { "fl", "fr", "rl", "rr" };

  c13_thisId.fParent = c13_parentId;
  sf_mex_check_struct(c13_parentId, c13_u, 4, c13_fieldNames, 0U, NULL);
  c13_thisId.fIdentifier = "fl";
  c13_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c13_u, "fl",
    "fl", 0)), &c13_thisId, c13_y->fl);
  c13_thisId.fIdentifier = "fr";
  c13_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c13_u, "fr",
    "fr", 0)), &c13_thisId, c13_y->fr);
  c13_thisId.fIdentifier = "rl";
  c13_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c13_u, "rl",
    "rl", 0)), &c13_thisId, c13_y->rl);
  c13_thisId.fIdentifier = "rr";
  c13_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c13_u, "rr",
    "rr", 0)), &c13_thisId, c13_y->rr);
  sf_mex_destroy(&c13_u);
}

static void c13_j_emlrt_marshallIn
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId, real_T c13_y[3])
{
  real_T c13_dv1[3];
  int32_T c13_i27;
  (void)chartInstance;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), c13_dv1, 1, 0, 0U, 1, 0U, 2, 3,
                1);
  for (c13_i27 = 0; c13_i27 < 3; c13_i27++) {
    c13_y[c13_i27] = c13_dv1[c13_i27];
  }

  sf_mex_destroy(&c13_u);
}

static c13_struct_r4FNviKwHfdhB8nQjvQv9 c13_k_emlrt_marshallIn
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  c13_struct_r4FNviKwHfdhB8nQjvQv9 c13_y;
  emlrtMsgIdentifier c13_thisId;
  static const char * c13_fieldNames[1] = { "v_set" };

  c13_thisId.fParent = c13_parentId;
  sf_mex_check_struct(c13_parentId, c13_u, 1, c13_fieldNames, 0U, NULL);
  c13_thisId.fIdentifier = "v_set";
  c13_y.v_set = c13_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c13_u, "v_set", "v_set", 0)),
    &c13_thisId);
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static c13_struct_Y9F1qlBi9AhssksPwemA4G c13_l_emlrt_marshallIn
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  c13_struct_Y9F1qlBi9AhssksPwemA4G c13_y;
  emlrtMsgIdentifier c13_thisId;
  static const char * c13_fieldNames[3] = { "v_x", "F_fz", "F_rz" };

  c13_thisId.fParent = c13_parentId;
  sf_mex_check_struct(c13_parentId, c13_u, 3, c13_fieldNames, 0U, NULL);
  c13_thisId.fIdentifier = "v_x";
  c13_y.v_x = c13_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c13_u, "v_x", "v_x", 0)), &c13_thisId);
  c13_thisId.fIdentifier = "F_fz";
  c13_y.F_fz = c13_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c13_u, "F_fz", "F_fz", 0)), &c13_thisId);
  c13_thisId.fIdentifier = "F_rz";
  c13_y.F_rz = c13_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c13_u, "F_rz", "F_rz", 0)), &c13_thisId);
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void c13_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_b_Par;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  c13_struct_iBlsPBO3AGnt69vDoTx5zD c13_y;
  SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c13_b_Par = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_b_Par), &c13_thisId,
    &c13_y);
  sf_mex_destroy(&c13_b_Par);
  *(c13_struct_iBlsPBO3AGnt69vDoTx5zD *)c13_outData = c13_y;
  sf_mex_destroy(&c13_mxArrayInData);
}

static const mxArray *c13_c_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  c13_oorp_vec3 c13_u;
  const mxArray *c13_y = NULL;
  real_T c13_b_u;
  const mxArray *c13_b_y = NULL;
  real_T c13_c_u;
  const mxArray *c13_c_y = NULL;
  real_T c13_d_u;
  const mxArray *c13_d_y = NULL;
  SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_u = *(c13_oorp_vec3 *)c13_inData;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c13_b_u = c13_u.z;
  c13_b_y = NULL;
  sf_mex_assign(&c13_b_y, sf_mex_create("y", &c13_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_y, c13_b_y, "z", "z", 0);
  c13_c_u = c13_u.rotx;
  c13_c_y = NULL;
  sf_mex_assign(&c13_c_y, sf_mex_create("y", &c13_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_y, c13_c_y, "rotx", "rotx", 0);
  c13_d_u = c13_u.roty;
  c13_d_y = NULL;
  sf_mex_assign(&c13_d_y, sf_mex_create("y", &c13_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_y, c13_d_y, "roty", "roty", 0);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, false);
  return c13_mxArrayOutData;
}

static const mxArray *c13_d_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  real_T c13_u;
  const mxArray *c13_y = NULL;
  SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_u = *(real_T *)c13_inData;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, false);
  return c13_mxArrayOutData;
}

static void c13_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_nargout;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  real_T c13_y;
  SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c13_nargout = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_nargout),
    &c13_thisId);
  sf_mex_destroy(&c13_nargout);
  *(real_T *)c13_outData = c13_y;
  sf_mex_destroy(&c13_mxArrayInData);
}

static const mxArray *c13_e_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  int32_T c13_i28;
  real_T c13_b_inData[4];
  int32_T c13_i29;
  real_T c13_u[4];
  const mxArray *c13_y = NULL;
  SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  for (c13_i28 = 0; c13_i28 < 4; c13_i28++) {
    c13_b_inData[c13_i28] = (*(real_T (*)[4])c13_inData)[c13_i28];
  }

  for (c13_i29 = 0; c13_i29 < 4; c13_i29++) {
    c13_u[c13_i29] = c13_b_inData[c13_i29];
  }

  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", c13_u, 0, 0U, 1U, 0U, 1, 4), false);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, false);
  return c13_mxArrayOutData;
}

static void c13_m_emlrt_marshallIn
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId, real_T c13_y[4])
{
  real_T c13_dv2[4];
  int32_T c13_i30;
  (void)chartInstance;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), c13_dv2, 1, 0, 0U, 1, 0U, 1, 4);
  for (c13_i30 = 0; c13_i30 < 4; c13_i30++) {
    c13_y[c13_i30] = c13_dv2[c13_i30];
  }

  sf_mex_destroy(&c13_u);
}

static void c13_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_v_oorp4;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  real_T c13_y[4];
  int32_T c13_i31;
  SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c13_v_oorp4 = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_v_oorp4), &c13_thisId,
    c13_y);
  sf_mex_destroy(&c13_v_oorp4);
  for (c13_i31 = 0; c13_i31 < 4; c13_i31++) {
    (*(real_T (*)[4])c13_outData)[c13_i31] = c13_y[c13_i31];
  }

  sf_mex_destroy(&c13_mxArrayInData);
}

static const mxArray *c13_f_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  int32_T c13_i32;
  real_T c13_b_inData[3];
  int32_T c13_i33;
  real_T c13_u[3];
  const mxArray *c13_y = NULL;
  SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  for (c13_i32 = 0; c13_i32 < 3; c13_i32++) {
    c13_b_inData[c13_i32] = (*(real_T (*)[3])c13_inData)[c13_i32];
  }

  for (c13_i33 = 0; c13_i33 < 3; c13_i33++) {
    c13_u[c13_i33] = c13_b_inData[c13_i33];
  }

  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", c13_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, false);
  return c13_mxArrayOutData;
}

static void c13_n_emlrt_marshallIn
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId, real_T c13_y[3])
{
  real_T c13_dv3[3];
  int32_T c13_i34;
  (void)chartInstance;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), c13_dv3, 1, 0, 0U, 1, 0U, 1, 3);
  for (c13_i34 = 0; c13_i34 < 3; c13_i34++) {
    c13_y[c13_i34] = c13_dv3[c13_i34];
  }

  sf_mex_destroy(&c13_u);
}

static void c13_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_v_oorp3_temp;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  real_T c13_y[3];
  int32_T c13_i35;
  SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c13_v_oorp3_temp = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_v_oorp3_temp),
    &c13_thisId, c13_y);
  sf_mex_destroy(&c13_v_oorp3_temp);
  for (c13_i35 = 0; c13_i35 < 3; c13_i35++) {
    (*(real_T (*)[3])c13_outData)[c13_i35] = c13_y[c13_i35];
  }

  sf_mex_destroy(&c13_mxArrayInData);
}

const mxArray
  *sf_c13_AllPurposeModel_TyreRelaxation_get_eml_resolved_functions_info(void)
{
  const mxArray *c13_nameCaptureInfo = NULL;
  c13_nameCaptureInfo = NULL;
  sf_mex_assign(&c13_nameCaptureInfo, sf_mex_createstruct("structure", 2, 20, 1),
                false);
  c13_info_helper(&c13_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c13_nameCaptureInfo);
  return c13_nameCaptureInfo;
}

static void c13_info_helper(const mxArray **c13_info)
{
  const mxArray *c13_rhs0 = NULL;
  const mxArray *c13_lhs0 = NULL;
  const mxArray *c13_rhs1 = NULL;
  const mxArray *c13_lhs1 = NULL;
  const mxArray *c13_rhs2 = NULL;
  const mxArray *c13_lhs2 = NULL;
  const mxArray *c13_rhs3 = NULL;
  const mxArray *c13_lhs3 = NULL;
  const mxArray *c13_rhs4 = NULL;
  const mxArray *c13_lhs4 = NULL;
  const mxArray *c13_rhs5 = NULL;
  const mxArray *c13_lhs5 = NULL;
  const mxArray *c13_rhs6 = NULL;
  const mxArray *c13_lhs6 = NULL;
  const mxArray *c13_rhs7 = NULL;
  const mxArray *c13_lhs7 = NULL;
  const mxArray *c13_rhs8 = NULL;
  const mxArray *c13_lhs8 = NULL;
  const mxArray *c13_rhs9 = NULL;
  const mxArray *c13_lhs9 = NULL;
  const mxArray *c13_rhs10 = NULL;
  const mxArray *c13_lhs10 = NULL;
  const mxArray *c13_rhs11 = NULL;
  const mxArray *c13_lhs11 = NULL;
  const mxArray *c13_rhs12 = NULL;
  const mxArray *c13_lhs12 = NULL;
  const mxArray *c13_rhs13 = NULL;
  const mxArray *c13_lhs13 = NULL;
  const mxArray *c13_rhs14 = NULL;
  const mxArray *c13_lhs14 = NULL;
  const mxArray *c13_rhs15 = NULL;
  const mxArray *c13_lhs15 = NULL;
  const mxArray *c13_rhs16 = NULL;
  const mxArray *c13_lhs16 = NULL;
  const mxArray *c13_rhs17 = NULL;
  const mxArray *c13_lhs17 = NULL;
  const mxArray *c13_rhs18 = NULL;
  const mxArray *c13_lhs18 = NULL;
  const mxArray *c13_rhs19 = NULL;
  const mxArray *c13_lhs19 = NULL;
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("mrdivide"), "name", "name",
                  0);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410807648U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1370009886U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c13_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1389717774U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c13_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("rdivide"), "name", "name", 2);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1363713880U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c13_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c13_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 4);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c13_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_div"), "name", "name", 5);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1386423952U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c13_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 6);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c13_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "context", "context", 7);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 7);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1383877294U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c13_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 8);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 8);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c13_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 9);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c13_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 10);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 10);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c13_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 11);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c13_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 12);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  12);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1375980690U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c13_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 13);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c13_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.blas.xgemm"),
                  "name", "name", 14);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c13_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 15);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 15);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c13_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!below_threshold"),
                  "context", "context", 16);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 16);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c13_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 17);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 17);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1393330858U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c13_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 18);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 18);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c13_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 19);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "coder.internal.refblas.xgemm"), "name", "name", 19);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c13_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs19), "lhs", "lhs",
                  19);
  sf_mex_destroy(&c13_rhs0);
  sf_mex_destroy(&c13_lhs0);
  sf_mex_destroy(&c13_rhs1);
  sf_mex_destroy(&c13_lhs1);
  sf_mex_destroy(&c13_rhs2);
  sf_mex_destroy(&c13_lhs2);
  sf_mex_destroy(&c13_rhs3);
  sf_mex_destroy(&c13_lhs3);
  sf_mex_destroy(&c13_rhs4);
  sf_mex_destroy(&c13_lhs4);
  sf_mex_destroy(&c13_rhs5);
  sf_mex_destroy(&c13_lhs5);
  sf_mex_destroy(&c13_rhs6);
  sf_mex_destroy(&c13_lhs6);
  sf_mex_destroy(&c13_rhs7);
  sf_mex_destroy(&c13_lhs7);
  sf_mex_destroy(&c13_rhs8);
  sf_mex_destroy(&c13_lhs8);
  sf_mex_destroy(&c13_rhs9);
  sf_mex_destroy(&c13_lhs9);
  sf_mex_destroy(&c13_rhs10);
  sf_mex_destroy(&c13_lhs10);
  sf_mex_destroy(&c13_rhs11);
  sf_mex_destroy(&c13_lhs11);
  sf_mex_destroy(&c13_rhs12);
  sf_mex_destroy(&c13_lhs12);
  sf_mex_destroy(&c13_rhs13);
  sf_mex_destroy(&c13_lhs13);
  sf_mex_destroy(&c13_rhs14);
  sf_mex_destroy(&c13_lhs14);
  sf_mex_destroy(&c13_rhs15);
  sf_mex_destroy(&c13_lhs15);
  sf_mex_destroy(&c13_rhs16);
  sf_mex_destroy(&c13_lhs16);
  sf_mex_destroy(&c13_rhs17);
  sf_mex_destroy(&c13_lhs17);
  sf_mex_destroy(&c13_rhs18);
  sf_mex_destroy(&c13_lhs18);
  sf_mex_destroy(&c13_rhs19);
  sf_mex_destroy(&c13_lhs19);
}

static const mxArray *c13_emlrt_marshallOut(const char * c13_u)
{
  const mxArray *c13_y = NULL;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", c13_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c13_u)), false);
  return c13_y;
}

static const mxArray *c13_b_emlrt_marshallOut(const uint32_T c13_u)
{
  const mxArray *c13_y = NULL;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 7, 0U, 0U, 0U, 0), false);
  return c13_y;
}

static void c13_eml_scalar_eg(SFc13_AllPurposeModel_TyreRelaxationInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c13_eml_xgemm(SFc13_AllPurposeModel_TyreRelaxationInstanceStruct
  *chartInstance, real_T c13_A[12], real_T c13_B[3], real_T c13_C[4], real_T
  c13_b_C[4])
{
  int32_T c13_i36;
  int32_T c13_i37;
  real_T c13_b_A[12];
  int32_T c13_i38;
  real_T c13_b_B[3];
  for (c13_i36 = 0; c13_i36 < 4; c13_i36++) {
    c13_b_C[c13_i36] = c13_C[c13_i36];
  }

  for (c13_i37 = 0; c13_i37 < 12; c13_i37++) {
    c13_b_A[c13_i37] = c13_A[c13_i37];
  }

  for (c13_i38 = 0; c13_i38 < 3; c13_i38++) {
    c13_b_B[c13_i38] = c13_B[c13_i38];
  }

  c13_b_eml_xgemm(chartInstance, c13_b_A, c13_b_B, c13_b_C);
}

static const mxArray *c13_g_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  int32_T c13_u;
  const mxArray *c13_y = NULL;
  SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_u = *(int32_T *)c13_inData;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, false);
  return c13_mxArrayOutData;
}

static int32_T c13_o_emlrt_marshallIn
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  int32_T c13_y;
  int32_T c13_i39;
  (void)chartInstance;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_i39, 1, 6, 0U, 0, 0U, 0);
  c13_y = c13_i39;
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void c13_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_b_sfEvent;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  int32_T c13_y;
  SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c13_b_sfEvent = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_b_sfEvent),
    &c13_thisId);
  sf_mex_destroy(&c13_b_sfEvent);
  *(int32_T *)c13_outData = c13_y;
  sf_mex_destroy(&c13_mxArrayInData);
}

static const mxArray *c13_v_oorp3_bus_io(void *chartInstanceVoid, void
  *c13_pData)
{
  const mxArray *c13_mxVal = NULL;
  c13_oorp_vec3 c13_tmp;
  SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c13_mxVal = NULL;
  c13_tmp.z = *(real_T *)&((char_T *)(c13_oorp_vec3 *)c13_pData)[0];
  c13_tmp.rotx = *(real_T *)&((char_T *)(c13_oorp_vec3 *)c13_pData)[8];
  c13_tmp.roty = *(real_T *)&((char_T *)(c13_oorp_vec3 *)c13_pData)[16];
  sf_mex_assign(&c13_mxVal, c13_c_sf_marshallOut(chartInstance, &c13_tmp), false);
  return c13_mxVal;
}

static const mxArray *c13_v_z4_bus_io(void *chartInstanceVoid, void *c13_pData)
{
  const mxArray *c13_mxVal = NULL;
  c13_whl_vec4 c13_tmp;
  SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c13_mxVal = NULL;
  c13_tmp.fl = *(real_T *)&((char_T *)(c13_whl_vec4 *)c13_pData)[0];
  c13_tmp.fr = *(real_T *)&((char_T *)(c13_whl_vec4 *)c13_pData)[8];
  c13_tmp.rl = *(real_T *)&((char_T *)(c13_whl_vec4 *)c13_pData)[16];
  c13_tmp.rr = *(real_T *)&((char_T *)(c13_whl_vec4 *)c13_pData)[24];
  sf_mex_assign(&c13_mxVal, c13_sf_marshallOut(chartInstance, &c13_tmp), false);
  return c13_mxVal;
}

static uint8_T c13_p_emlrt_marshallIn
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c13_b_is_active_c13_AllPurposeModel_TyreRelaxation, const char_T
   *c13_identifier)
{
  uint8_T c13_y;
  emlrtMsgIdentifier c13_thisId;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_q_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c13_b_is_active_c13_AllPurposeModel_TyreRelaxation), &c13_thisId);
  sf_mex_destroy(&c13_b_is_active_c13_AllPurposeModel_TyreRelaxation);
  return c13_y;
}

static uint8_T c13_q_emlrt_marshallIn
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  uint8_T c13_y;
  uint8_T c13_u0;
  (void)chartInstance;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_u0, 1, 3, 0U, 0, 0U, 0);
  c13_y = c13_u0;
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void c13_b_eml_xgemm(SFc13_AllPurposeModel_TyreRelaxationInstanceStruct
  *chartInstance, real_T c13_A[12], real_T c13_B[3], real_T c13_C[4])
{
  int32_T c13_i40;
  int32_T c13_i41;
  int32_T c13_i42;
  (void)chartInstance;
  for (c13_i40 = 0; c13_i40 < 4; c13_i40++) {
    c13_C[c13_i40] = 0.0;
    c13_i41 = 0;
    for (c13_i42 = 0; c13_i42 < 3; c13_i42++) {
      c13_C[c13_i40] += c13_A[c13_i41 + c13_i40] * c13_B[c13_i42];
      c13_i41 += 4;
    }
  }
}

static void init_dsm_address_info
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address
  (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  chartInstance->c13_v_oorp3 = (c13_oorp_vec3 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c13_v_z4 = (c13_whl_vec4 *)ssGetOutputPortSignal_wrapper
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

void sf_c13_AllPurposeModel_TyreRelaxation_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3209992264U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2153147098U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3115213264U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3076855957U);
}

mxArray* sf_c13_AllPurposeModel_TyreRelaxation_get_post_codegen_info(void);
mxArray *sf_c13_AllPurposeModel_TyreRelaxation_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("0YJKEsytAPv5fA8AqKKmNE");
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
      sf_c13_AllPurposeModel_TyreRelaxation_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c13_AllPurposeModel_TyreRelaxation_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c13_AllPurposeModel_TyreRelaxation_jit_fallback_info(void)
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

mxArray *sf_c13_AllPurposeModel_TyreRelaxation_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c13_AllPurposeModel_TyreRelaxation_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c13_AllPurposeModel_TyreRelaxation
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"v_z4\",},{M[8],M[0],T\"is_active_c13_AllPurposeModel_TyreRelaxation\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c13_AllPurposeModel_TyreRelaxation_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _AllPurposeModel_TyreRelaxationMachineNumber_,
           13,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"v_oorp3");
          _SFD_SET_DATA_PROPS(1,2,0,1,"v_z4");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,384);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_v_oorp3_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_v_z4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_b_sf_marshallOut,(MexInFcnForType)
          c13_b_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c13_v_oorp3);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c13_v_z4);
        _SFD_SET_DATA_VALUE_PTR(2U, &chartInstance->c13_Par);
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
  return "3GAQyhWpcXEaZT9fye6uID";
}

static void sf_opaque_initialize_c13_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc13_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar)->S,
     0);
  initialize_params_c13_AllPurposeModel_TyreRelaxation
    ((SFc13_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
  initialize_c13_AllPurposeModel_TyreRelaxation
    ((SFc13_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c13_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  enable_c13_AllPurposeModel_TyreRelaxation
    ((SFc13_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c13_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  disable_c13_AllPurposeModel_TyreRelaxation
    ((SFc13_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c13_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  sf_gateway_c13_AllPurposeModel_TyreRelaxation
    ((SFc13_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c13_AllPurposeModel_TyreRelaxation
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c13_AllPurposeModel_TyreRelaxation
    ((SFc13_AllPurposeModel_TyreRelaxationInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c13_AllPurposeModel_TyreRelaxation(SimStruct*
  S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c13_AllPurposeModel_TyreRelaxation
    ((SFc13_AllPurposeModel_TyreRelaxationInstanceStruct*)
     chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c13_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc13_AllPurposeModel_TyreRelaxationInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_AllPurposeModel_TyreRelaxation_optimization_info();
    }

    finalize_c13_AllPurposeModel_TyreRelaxation
      ((SFc13_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc13_AllPurposeModel_TyreRelaxation
    ((SFc13_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c13_AllPurposeModel_TyreRelaxation(SimStruct *S)
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
    initialize_params_c13_AllPurposeModel_TyreRelaxation
      ((SFc13_AllPurposeModel_TyreRelaxationInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c13_AllPurposeModel_TyreRelaxation(SimStruct *S)
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
      13);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,13,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,13,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,13);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,13,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,13,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,13);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1943591764U));
  ssSetChecksum1(S,(1954040897U));
  ssSetChecksum2(S,(3035053800U));
  ssSetChecksum3(S,(581705836U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c13_AllPurposeModel_TyreRelaxation(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c13_AllPurposeModel_TyreRelaxation(SimStruct *S)
{
  SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct *)utMalloc
    (sizeof(SFc13_AllPurposeModel_TyreRelaxationInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc13_AllPurposeModel_TyreRelaxationInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c13_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c13_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c13_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c13_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c13_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c13_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c13_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c13_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c13_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c13_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c13_AllPurposeModel_TyreRelaxation;
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

void c13_AllPurposeModel_TyreRelaxation_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c13_AllPurposeModel_TyreRelaxation(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c13_AllPurposeModel_TyreRelaxation(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c13_AllPurposeModel_TyreRelaxation(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c13_AllPurposeModel_TyreRelaxation_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
