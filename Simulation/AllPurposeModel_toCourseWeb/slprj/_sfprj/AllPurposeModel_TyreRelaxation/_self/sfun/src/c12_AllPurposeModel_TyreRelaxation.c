/* Include files */

#include <stddef.h>
#include "blas.h"
#include "AllPurposeModel_TyreRelaxation_sfun.h"
#include "c12_AllPurposeModel_TyreRelaxation.h"
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
static const char * c12_debug_family_names[15] = { "lf", "lr", "w1", "w2", "w3",
  "w4", "T_irpv", "v_irp3_temp", "v_xyv8", "nargin", "nargout", "v_irp3", "Par",
  "v_xv4", "v_yv4" };

/* Function Declarations */
static void initialize_c12_AllPurposeModel_TyreRelaxation
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void initialize_params_c12_AllPurposeModel_TyreRelaxation
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void enable_c12_AllPurposeModel_TyreRelaxation
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void disable_c12_AllPurposeModel_TyreRelaxation
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void c12_update_debugger_state_c12_AllPurposeModel_TyreRelaxation
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c12_AllPurposeModel_TyreRelaxation
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void set_sim_state_c12_AllPurposeModel_TyreRelaxation
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c12_st);
static void finalize_c12_AllPurposeModel_TyreRelaxation
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void sf_gateway_c12_AllPurposeModel_TyreRelaxation
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void mdl_start_c12_AllPurposeModel_TyreRelaxation
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void initSimStructsc12_AllPurposeModel_TyreRelaxation
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c12_machineNumber, uint32_T
  c12_chartNumber, uint32_T c12_instanceNumber);
static const mxArray *c12_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static c12_whl_vec4 c12_emlrt_marshallIn
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c12_b_v_yv4, const char_T *c12_identifier);
static c12_whl_vec4 c12_b_emlrt_marshallIn
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static real_T c12_c_emlrt_marshallIn
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_b_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static void c12_d_emlrt_marshallIn
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId,
   c12_struct_iBlsPBO3AGnt69vDoTx5zD *c12_y);
static void c12_e_emlrt_marshallIn
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId,
   c12_struct_Nst2vGTExxHsg85EUOj9EH *c12_y);
static c12_struct_HhckT6rntEraqECYVIDvCC c12_f_emlrt_marshallIn
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_g_emlrt_marshallIn
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId,
   c12_struct_ZCmOWPuqBDw16FSOVVD00 *c12_y);
static void c12_h_emlrt_marshallIn
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId, real_T c12_y[4]);
static void c12_i_emlrt_marshallIn
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId,
   c12_struct_ZKAzdrl7umDGJoC14aoVKC *c12_y);
static void c12_j_emlrt_marshallIn
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId, real_T c12_y[3]);
static c12_struct_r4FNviKwHfdhB8nQjvQv9 c12_k_emlrt_marshallIn
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static c12_struct_Y9F1qlBi9AhssksPwemA4G c12_l_emlrt_marshallIn
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_c_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static const mxArray *c12_d_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static void c12_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_e_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static void c12_m_emlrt_marshallIn
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId, real_T c12_y[8]);
static void c12_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_f_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static void c12_n_emlrt_marshallIn
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId, real_T c12_y[3]);
static void c12_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_g_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static void c12_o_emlrt_marshallIn
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId, real_T c12_y[24]);
static void c12_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static void c12_info_helper(const mxArray **c12_info);
static const mxArray *c12_emlrt_marshallOut(const char * c12_u);
static const mxArray *c12_b_emlrt_marshallOut(const uint32_T c12_u);
static void c12_eml_scalar_eg(SFc12_AllPurposeModel_TyreRelaxationInstanceStruct
  *chartInstance);
static void c12_eml_xgemm(SFc12_AllPurposeModel_TyreRelaxationInstanceStruct
  *chartInstance, real_T c12_A[24], real_T c12_B[3], real_T c12_C[8], real_T
  c12_b_C[8]);
static const mxArray *c12_h_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static int32_T c12_p_emlrt_marshallIn
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_v_xv4_bus_io(void *chartInstanceVoid, void *c12_pData);
static const mxArray *c12_v_irp3_bus_io(void *chartInstanceVoid, void *c12_pData);
static uint8_T c12_q_emlrt_marshallIn
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c12_b_is_active_c12_AllPurposeModel_TyreRelaxation, const char_T
   *c12_identifier);
static uint8_T c12_r_emlrt_marshallIn
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_b_eml_xgemm(SFc12_AllPurposeModel_TyreRelaxationInstanceStruct
  *chartInstance, real_T c12_A[24], real_T c12_B[3], real_T c12_C[8]);
static void init_dsm_address_info
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void init_simulink_io_address
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c12_AllPurposeModel_TyreRelaxation
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  chartInstance->c12_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c12_is_active_c12_AllPurposeModel_TyreRelaxation = 0U;
}

static void initialize_params_c12_AllPurposeModel_TyreRelaxation
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  const mxArray *c12_m0 = NULL;
  const mxArray *c12_mxField;
  const mxArray *c12_m1 = NULL;
  const mxArray *c12_b_mxField;
  c12_struct_iBlsPBO3AGnt69vDoTx5zD c12_r0;
  const mxArray *c12_m2 = NULL;
  const mxArray *c12_c_mxField;
  const mxArray *c12_m3 = NULL;
  const mxArray *c12_d_mxField;
  const mxArray *c12_m4 = NULL;
  const mxArray *c12_e_mxField;
  const mxArray *c12_m5 = NULL;
  const mxArray *c12_f_mxField;
  const mxArray *c12_m6 = NULL;
  const mxArray *c12_g_mxField;
  const mxArray *c12_m7 = NULL;
  const mxArray *c12_h_mxField;
  const mxArray *c12_m8 = NULL;
  const mxArray *c12_i_mxField;
  const mxArray *c12_m9 = NULL;
  const mxArray *c12_j_mxField;
  const mxArray *c12_m10 = NULL;
  const mxArray *c12_k_mxField;
  const mxArray *c12_m11 = NULL;
  const mxArray *c12_l_mxField;
  const mxArray *c12_m12 = NULL;
  const mxArray *c12_m_mxField;
  const mxArray *c12_m13 = NULL;
  const mxArray *c12_n_mxField;
  c12_m0 = sf_mex_get_sfun_param(chartInstance->S, 0, 1);
  c12_mxField = sf_mex_getfield(c12_m0, "Env", "Par", 0);
  c12_m1 = sf_mex_dup(c12_mxField);
  c12_b_mxField = sf_mex_getfield(c12_m1, "g", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_b_mxField), &c12_r0.Env.g, 1, 0, 0U,
                      0, 0U, 0);
  c12_b_mxField = sf_mex_getfield(c12_m1, "left1", "Par", 0);
  c12_m2 = sf_mex_dup(c12_b_mxField);
  c12_c_mxField = sf_mex_getfield(c12_m2, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_c_mxField), &c12_r0.Env.left1.x, 1,
                      0, 0U, 0, 0U, 0);
  c12_c_mxField = sf_mex_getfield(c12_m2, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_c_mxField), &c12_r0.Env.left1.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c12_m2);
  c12_b_mxField = sf_mex_getfield(c12_m1, "right1", "Par", 0);
  c12_m3 = sf_mex_dup(c12_b_mxField);
  c12_d_mxField = sf_mex_getfield(c12_m3, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_d_mxField), &c12_r0.Env.right1.x, 1,
                      0, 0U, 0, 0U, 0);
  c12_d_mxField = sf_mex_getfield(c12_m3, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_d_mxField), &c12_r0.Env.right1.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c12_m3);
  c12_b_mxField = sf_mex_getfield(c12_m1, "right2", "Par", 0);
  c12_m4 = sf_mex_dup(c12_b_mxField);
  c12_e_mxField = sf_mex_getfield(c12_m4, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_e_mxField), &c12_r0.Env.right2.x, 1,
                      0, 0U, 0, 0U, 0);
  c12_e_mxField = sf_mex_getfield(c12_m4, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_e_mxField), &c12_r0.Env.right2.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c12_m4);
  c12_b_mxField = sf_mex_getfield(c12_m1, "left2", "Par", 0);
  c12_m5 = sf_mex_dup(c12_b_mxField);
  c12_f_mxField = sf_mex_getfield(c12_m5, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_f_mxField), &c12_r0.Env.left2.x, 1,
                      0, 0U, 0, 0U, 0);
  c12_f_mxField = sf_mex_getfield(c12_m5, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_f_mxField), &c12_r0.Env.left2.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c12_m5);
  c12_b_mxField = sf_mex_getfield(c12_m1, "right3", "Par", 0);
  c12_m6 = sf_mex_dup(c12_b_mxField);
  c12_g_mxField = sf_mex_getfield(c12_m6, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_g_mxField), &c12_r0.Env.right3.x, 1,
                      0, 0U, 0, 0U, 0);
  c12_g_mxField = sf_mex_getfield(c12_m6, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_g_mxField), &c12_r0.Env.right3.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c12_m6);
  c12_b_mxField = sf_mex_getfield(c12_m1, "mu", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_b_mxField), &c12_r0.Env.mu, 1, 0, 0U,
                      0, 0U, 0);
  sf_mex_destroy(&c12_m1);
  c12_mxField = sf_mex_getfield(c12_m0, "Veh", "Par", 0);
  c12_m7 = sf_mex_dup(c12_mxField);
  c12_h_mxField = sf_mex_getfield(c12_m7, "m", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_h_mxField), &c12_r0.Veh.m, 1, 0, 0U,
                      0, 0U, 0);
  c12_h_mxField = sf_mex_getfield(c12_m7, "Jz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_h_mxField), &c12_r0.Veh.Jz, 1, 0, 0U,
                      0, 0U, 0);
  c12_h_mxField = sf_mex_getfield(c12_m7, "m_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_h_mxField), &c12_r0.Veh.m_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c12_h_mxField = sf_mex_getfield(c12_m7, "Jx_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_h_mxField), &c12_r0.Veh.Jx_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c12_h_mxField = sf_mex_getfield(c12_m7, "Jy_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_h_mxField), &c12_r0.Veh.Jy_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c12_h_mxField = sf_mex_getfield(c12_m7, "lf", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_h_mxField), &c12_r0.Veh.lf, 1, 0, 0U,
                      0, 0U, 0);
  c12_h_mxField = sf_mex_getfield(c12_m7, "lr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_h_mxField), &c12_r0.Veh.lr, 1, 0, 0U,
                      0, 0U, 0);
  c12_h_mxField = sf_mex_getfield(c12_m7, "L", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_h_mxField), &c12_r0.Veh.L, 1, 0, 0U,
                      0, 0U, 0);
  c12_h_mxField = sf_mex_getfield(c12_m7, "TrackWidth", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_h_mxField), &c12_r0.Veh.TrackWidth,
                      1, 0, 0U, 0, 0U, 0);
  c12_h_mxField = sf_mex_getfield(c12_m7, "h", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_h_mxField), &c12_r0.Veh.h, 1, 0, 0U,
                      0, 0U, 0);
  c12_h_mxField = sf_mex_getfield(c12_m7, "HalfRohACd", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_h_mxField), &c12_r0.Veh.HalfRohACd,
                      1, 0, 0U, 0, 0U, 0);
  c12_h_mxField = sf_mex_getfield(c12_m7, "F_z4_static", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_h_mxField), c12_r0.Veh.F_z4_static,
                      1, 0, 0U, 1, 0U, 2, 1, 4);
  c12_h_mxField = sf_mex_getfield(c12_m7, "Rw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_h_mxField), &c12_r0.Veh.Rw, 1, 0, 0U,
                      0, 0U, 0);
  c12_h_mxField = sf_mex_getfield(c12_m7, "r_long", "Par", 0);
  c12_m8 = sf_mex_dup(c12_h_mxField);
  c12_i_mxField = sf_mex_getfield(c12_m8, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_i_mxField), c12_r0.Veh.r_long.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c12_i_mxField = sf_mex_getfield(c12_m8, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_i_mxField), c12_r0.Veh.r_long.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c12_i_mxField = sf_mex_getfield(c12_m8, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_i_mxField), c12_r0.Veh.r_long.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c12_i_mxField = sf_mex_getfield(c12_m8, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_i_mxField), c12_r0.Veh.r_long.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c12_m8);
  c12_h_mxField = sf_mex_getfield(c12_m7, "r_lat", "Par", 0);
  c12_m9 = sf_mex_dup(c12_h_mxField);
  c12_j_mxField = sf_mex_getfield(c12_m9, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_j_mxField), c12_r0.Veh.r_lat.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c12_j_mxField = sf_mex_getfield(c12_m9, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_j_mxField), c12_r0.Veh.r_lat.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c12_j_mxField = sf_mex_getfield(c12_m9, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_j_mxField), c12_r0.Veh.r_lat.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c12_j_mxField = sf_mex_getfield(c12_m9, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_j_mxField), c12_r0.Veh.r_lat.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c12_m9);
  c12_h_mxField = sf_mex_getfield(c12_m7, "r_lever", "Par", 0);
  c12_m10 = sf_mex_dup(c12_h_mxField);
  c12_k_mxField = sf_mex_getfield(c12_m10, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_k_mxField), c12_r0.Veh.r_lever.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c12_k_mxField = sf_mex_getfield(c12_m10, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_k_mxField), c12_r0.Veh.r_lever.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c12_k_mxField = sf_mex_getfield(c12_m10, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_k_mxField), c12_r0.Veh.r_lever.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c12_k_mxField = sf_mex_getfield(c12_m10, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_k_mxField), c12_r0.Veh.r_lever.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c12_m10);
  c12_h_mxField = sf_mex_getfield(c12_m7, "r_pivot", "Par", 0);
  c12_m11 = sf_mex_dup(c12_h_mxField);
  c12_l_mxField = sf_mex_getfield(c12_m11, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_l_mxField), c12_r0.Veh.r_pivot.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c12_l_mxField = sf_mex_getfield(c12_m11, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_l_mxField), c12_r0.Veh.r_pivot.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c12_l_mxField = sf_mex_getfield(c12_m11, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_l_mxField), c12_r0.Veh.r_pivot.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c12_l_mxField = sf_mex_getfield(c12_m11, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_l_mxField), c12_r0.Veh.r_pivot.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c12_m11);
  c12_h_mxField = sf_mex_getfield(c12_m7, "cw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_h_mxField), &c12_r0.Veh.cw, 1, 0, 0U,
                      0, 0U, 0);
  c12_h_mxField = sf_mex_getfield(c12_m7, "carb_f", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_h_mxField), &c12_r0.Veh.carb_f, 1, 0,
                      0U, 0, 0U, 0);
  c12_h_mxField = sf_mex_getfield(c12_m7, "carb_r", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_h_mxField), &c12_r0.Veh.carb_r, 1, 0,
                      0U, 0, 0U, 0);
  c12_h_mxField = sf_mex_getfield(c12_m7, "dw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_h_mxField), &c12_r0.Veh.dw, 1, 0, 0U,
                      0, 0U, 0);
  c12_h_mxField = sf_mex_getfield(c12_m7, "Jw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_h_mxField), &c12_r0.Veh.Jw, 1, 0, 0U,
                      0, 0U, 0);
  c12_h_mxField = sf_mex_getfield(c12_m7, "C0", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_h_mxField), &c12_r0.Veh.C0, 1, 0, 0U,
                      0, 0U, 0);
  c12_h_mxField = sf_mex_getfield(c12_m7, "RelaxLength", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_h_mxField), &c12_r0.Veh.RelaxLength,
                      1, 0, 0U, 0, 0U, 0);
  c12_h_mxField = sf_mex_getfield(c12_m7, "RRC", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_h_mxField), &c12_r0.Veh.RRC, 1, 0,
                      0U, 0, 0U, 0);
  c12_h_mxField = sf_mex_getfield(c12_m7, "Pmax", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_h_mxField), &c12_r0.Veh.Pmax, 1, 0,
                      0U, 0, 0U, 0);
  c12_h_mxField = sf_mex_getfield(c12_m7, "PropDistrFrnt", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_h_mxField),
                      &c12_r0.Veh.PropDistrFrnt, 1, 0, 0U, 0, 0U, 0);
  c12_h_mxField = sf_mex_getfield(c12_m7, "BrkDistrFrnt", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_h_mxField), &c12_r0.Veh.BrkDistrFrnt,
                      1, 0, 0U, 0, 0U, 0);
  c12_h_mxField = sf_mex_getfield(c12_m7, "SteRatio", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_h_mxField), &c12_r0.Veh.SteRatio, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c12_m7);
  c12_mxField = sf_mex_getfield(c12_m0, "Drvr", "Par", 0);
  c12_m12 = sf_mex_dup(c12_mxField);
  c12_m_mxField = sf_mex_getfield(c12_m12, "v_set", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_m_mxField), &c12_r0.Drvr.v_set, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c12_m12);
  c12_mxField = sf_mex_getfield(c12_m0, "Init", "Par", 0);
  c12_m13 = sf_mex_dup(c12_mxField);
  c12_n_mxField = sf_mex_getfield(c12_m13, "v_x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_n_mxField), &c12_r0.Init.v_x, 1, 0,
                      0U, 0, 0U, 0);
  c12_n_mxField = sf_mex_getfield(c12_m13, "F_fz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_n_mxField), &c12_r0.Init.F_fz, 1, 0,
                      0U, 0, 0U, 0);
  c12_n_mxField = sf_mex_getfield(c12_m13, "F_rz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c12_n_mxField), &c12_r0.Init.F_rz, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c12_m13);
  sf_mex_destroy(&c12_m0);
  chartInstance->c12_Par = c12_r0;
}

static void enable_c12_AllPurposeModel_TyreRelaxation
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c12_AllPurposeModel_TyreRelaxation
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c12_update_debugger_state_c12_AllPurposeModel_TyreRelaxation
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c12_AllPurposeModel_TyreRelaxation
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  const mxArray *c12_st;
  const mxArray *c12_y = NULL;
  const mxArray *c12_b_y = NULL;
  real_T c12_u;
  const mxArray *c12_c_y = NULL;
  real_T c12_b_u;
  const mxArray *c12_d_y = NULL;
  real_T c12_c_u;
  const mxArray *c12_e_y = NULL;
  real_T c12_d_u;
  const mxArray *c12_f_y = NULL;
  const mxArray *c12_g_y = NULL;
  real_T c12_e_u;
  const mxArray *c12_h_y = NULL;
  real_T c12_f_u;
  const mxArray *c12_i_y = NULL;
  real_T c12_g_u;
  const mxArray *c12_j_y = NULL;
  real_T c12_h_u;
  const mxArray *c12_k_y = NULL;
  uint8_T c12_hoistedGlobal;
  uint8_T c12_i_u;
  const mxArray *c12_l_y = NULL;
  c12_st = NULL;
  c12_st = NULL;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_createcellmatrix(3, 1), false);
  c12_b_y = NULL;
  sf_mex_assign(&c12_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c12_u = *(real_T *)&((char_T *)chartInstance->c12_v_xv4)[0];
  c12_c_y = NULL;
  sf_mex_assign(&c12_c_y, sf_mex_create("y", &c12_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_b_y, c12_c_y, "fl", "fl", 0);
  c12_b_u = *(real_T *)&((char_T *)chartInstance->c12_v_xv4)[8];
  c12_d_y = NULL;
  sf_mex_assign(&c12_d_y, sf_mex_create("y", &c12_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_b_y, c12_d_y, "fr", "fr", 0);
  c12_c_u = *(real_T *)&((char_T *)chartInstance->c12_v_xv4)[16];
  c12_e_y = NULL;
  sf_mex_assign(&c12_e_y, sf_mex_create("y", &c12_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_b_y, c12_e_y, "rl", "rl", 0);
  c12_d_u = *(real_T *)&((char_T *)chartInstance->c12_v_xv4)[24];
  c12_f_y = NULL;
  sf_mex_assign(&c12_f_y, sf_mex_create("y", &c12_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_b_y, c12_f_y, "rr", "rr", 0);
  sf_mex_setcell(c12_y, 0, c12_b_y);
  c12_g_y = NULL;
  sf_mex_assign(&c12_g_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c12_e_u = *(real_T *)&((char_T *)chartInstance->c12_v_yv4)[0];
  c12_h_y = NULL;
  sf_mex_assign(&c12_h_y, sf_mex_create("y", &c12_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_g_y, c12_h_y, "fl", "fl", 0);
  c12_f_u = *(real_T *)&((char_T *)chartInstance->c12_v_yv4)[8];
  c12_i_y = NULL;
  sf_mex_assign(&c12_i_y, sf_mex_create("y", &c12_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_g_y, c12_i_y, "fr", "fr", 0);
  c12_g_u = *(real_T *)&((char_T *)chartInstance->c12_v_yv4)[16];
  c12_j_y = NULL;
  sf_mex_assign(&c12_j_y, sf_mex_create("y", &c12_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_g_y, c12_j_y, "rl", "rl", 0);
  c12_h_u = *(real_T *)&((char_T *)chartInstance->c12_v_yv4)[24];
  c12_k_y = NULL;
  sf_mex_assign(&c12_k_y, sf_mex_create("y", &c12_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_g_y, c12_k_y, "rr", "rr", 0);
  sf_mex_setcell(c12_y, 1, c12_g_y);
  c12_hoistedGlobal =
    chartInstance->c12_is_active_c12_AllPurposeModel_TyreRelaxation;
  c12_i_u = c12_hoistedGlobal;
  c12_l_y = NULL;
  sf_mex_assign(&c12_l_y, sf_mex_create("y", &c12_i_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c12_y, 2, c12_l_y);
  sf_mex_assign(&c12_st, c12_y, false);
  return c12_st;
}

static void set_sim_state_c12_AllPurposeModel_TyreRelaxation
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c12_st)
{
  const mxArray *c12_u;
  c12_whl_vec4 c12_r1;
  c12_whl_vec4 c12_r2;
  chartInstance->c12_doneDoubleBufferReInit = true;
  c12_u = sf_mex_dup(c12_st);
  c12_r1 = c12_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c12_u,
    0)), "v_xv4");
  *(real_T *)&((char_T *)chartInstance->c12_v_xv4)[0] = c12_r1.fl;
  *(real_T *)&((char_T *)chartInstance->c12_v_xv4)[8] = c12_r1.fr;
  *(real_T *)&((char_T *)chartInstance->c12_v_xv4)[16] = c12_r1.rl;
  *(real_T *)&((char_T *)chartInstance->c12_v_xv4)[24] = c12_r1.rr;
  c12_r2 = c12_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c12_u,
    1)), "v_yv4");
  *(real_T *)&((char_T *)chartInstance->c12_v_yv4)[0] = c12_r2.fl;
  *(real_T *)&((char_T *)chartInstance->c12_v_yv4)[8] = c12_r2.fr;
  *(real_T *)&((char_T *)chartInstance->c12_v_yv4)[16] = c12_r2.rl;
  *(real_T *)&((char_T *)chartInstance->c12_v_yv4)[24] = c12_r2.rr;
  chartInstance->c12_is_active_c12_AllPurposeModel_TyreRelaxation =
    c12_q_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c12_u, 2)),
    "is_active_c12_AllPurposeModel_TyreRelaxation");
  sf_mex_destroy(&c12_u);
  c12_update_debugger_state_c12_AllPurposeModel_TyreRelaxation(chartInstance);
  sf_mex_destroy(&c12_st);
}

static void finalize_c12_AllPurposeModel_TyreRelaxation
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c12_AllPurposeModel_TyreRelaxation
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  c12_irp_vec3 c12_b_v_irp3;
  c12_struct_iBlsPBO3AGnt69vDoTx5zD c12_b_Par;
  uint32_T c12_debug_family_var_map[15];
  real_T c12_lf;
  real_T c12_lr;
  real_T c12_w1;
  real_T c12_w2;
  real_T c12_w3;
  real_T c12_w4;
  real_T c12_T_irpv[24];
  real_T c12_v_irp3_temp[3];
  real_T c12_v_xyv8[8];
  real_T c12_nargin = 2.0;
  real_T c12_nargout = 2.0;
  c12_whl_vec4 c12_b_v_xv4;
  c12_whl_vec4 c12_b_v_yv4;
  real_T c12_A;
  real_T c12_x;
  real_T c12_b_x;
  real_T c12_c_x;
  int32_T c12_i0;
  int32_T c12_i1;
  static real_T c12_dv0[8] = { 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0 };

  int32_T c12_i2;
  int32_T c12_i3;
  static real_T c12_dv1[8] = { 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0 };

  int32_T c12_i4;
  int32_T c12_i5;
  int32_T c12_i6;
  int32_T c12_i7;
  real_T c12_a[24];
  int32_T c12_i8;
  real_T c12_b[3];
  int32_T c12_i9;
  int32_T c12_i10;
  real_T c12_dv2[8];
  int32_T c12_i11;
  real_T c12_b_a[24];
  int32_T c12_i12;
  real_T c12_b_b[3];
  int32_T c12_i13;
  c12_whl_vec4 c12_r3;
  c12_whl_vec4 c12_r4;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 11U, chartInstance->c12_sfEvent);
  chartInstance->c12_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 11U, chartInstance->c12_sfEvent);
  c12_b_v_irp3.x = *(real_T *)&((char_T *)chartInstance->c12_v_irp3)[0];
  c12_b_v_irp3.y = *(real_T *)&((char_T *)chartInstance->c12_v_irp3)[8];
  c12_b_v_irp3.rotz = *(real_T *)&((char_T *)chartInstance->c12_v_irp3)[16];
  c12_b_Par = chartInstance->c12_Par;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 15U, 15U, c12_debug_family_names,
    c12_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_lf, 0U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_lr, 1U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_w1, 2U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_w2, 3U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_w3, 4U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_w4, 5U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c12_T_irpv, 6U, c12_g_sf_marshallOut,
    c12_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c12_v_irp3_temp, 7U, c12_f_sf_marshallOut,
    c12_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c12_v_xyv8, 8U, c12_e_sf_marshallOut,
    c12_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_nargin, 9U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_nargout, 10U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c12_b_v_irp3, 11U, c12_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_b_Par, 12U, c12_b_sf_marshallOut,
    c12_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_b_v_xv4, 13U, c12_sf_marshallOut,
    c12_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_b_v_yv4, 14U, c12_sf_marshallOut,
    c12_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 5);
  c12_lf = c12_b_Par.Veh.lf;
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 6);
  c12_lr = c12_b_Par.Veh.lr;
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 8);
  c12_A = c12_b_Par.Veh.TrackWidth;
  c12_x = c12_A;
  c12_b_x = c12_x;
  c12_c_x = c12_b_x;
  c12_w1 = c12_c_x / 2.0;
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 9);
  c12_w2 = -c12_w1;
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 10);
  c12_w3 = c12_w1;
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 11);
  c12_w4 = -c12_w3;
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 13);
  c12_i0 = 0;
  for (c12_i1 = 0; c12_i1 < 8; c12_i1++) {
    c12_T_irpv[c12_i0] = c12_dv0[c12_i1];
    c12_i0 += 3;
  }

  c12_i2 = 0;
  for (c12_i3 = 0; c12_i3 < 8; c12_i3++) {
    c12_T_irpv[c12_i2 + 1] = c12_dv1[c12_i3];
    c12_i2 += 3;
  }

  c12_T_irpv[2] = -c12_w1;
  c12_T_irpv[5] = -c12_w2;
  c12_T_irpv[8] = -c12_w3;
  c12_T_irpv[11] = -c12_w4;
  c12_T_irpv[14] = c12_lf;
  c12_T_irpv[17] = c12_lf;
  c12_T_irpv[20] = c12_lr;
  c12_T_irpv[23] = c12_lr;
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 17);
  c12_v_irp3_temp[0] = c12_b_v_irp3.x;
  c12_v_irp3_temp[1] = c12_b_v_irp3.y;
  c12_v_irp3_temp[2] = c12_b_v_irp3.rotz;
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 19);
  c12_i4 = 0;
  for (c12_i5 = 0; c12_i5 < 3; c12_i5++) {
    c12_i6 = 0;
    for (c12_i7 = 0; c12_i7 < 8; c12_i7++) {
      c12_a[c12_i7 + c12_i4] = c12_T_irpv[c12_i6 + c12_i5];
      c12_i6 += 3;
    }

    c12_i4 += 8;
  }

  for (c12_i8 = 0; c12_i8 < 3; c12_i8++) {
    c12_b[c12_i8] = c12_v_irp3_temp[c12_i8];
  }

  c12_eml_scalar_eg(chartInstance);
  c12_eml_scalar_eg(chartInstance);
  for (c12_i9 = 0; c12_i9 < 8; c12_i9++) {
    c12_v_xyv8[c12_i9] = 0.0;
  }

  for (c12_i10 = 0; c12_i10 < 8; c12_i10++) {
    c12_dv2[c12_i10] = 0.0;
  }

  for (c12_i11 = 0; c12_i11 < 24; c12_i11++) {
    c12_b_a[c12_i11] = c12_a[c12_i11];
  }

  for (c12_i12 = 0; c12_i12 < 3; c12_i12++) {
    c12_b_b[c12_i12] = c12_b[c12_i12];
  }

  c12_b_eml_xgemm(chartInstance, c12_b_a, c12_b_b, c12_dv2);
  for (c12_i13 = 0; c12_i13 < 8; c12_i13++) {
    c12_v_xyv8[c12_i13] = c12_dv2[c12_i13];
  }

  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 21);
  c12_r3.fl = c12_v_xyv8[0];
  c12_r3.fr = c12_v_xyv8[1];
  c12_r3.rl = c12_v_xyv8[2];
  c12_r3.rr = c12_v_xyv8[3];
  c12_b_v_xv4 = c12_r3;
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 22);
  c12_r4.fl = c12_v_xyv8[4];
  c12_r4.fr = c12_v_xyv8[5];
  c12_r4.rl = c12_v_xyv8[6];
  c12_r4.rr = c12_v_xyv8[7];
  c12_b_v_yv4 = c12_r4;
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, -22);
  _SFD_SYMBOL_SCOPE_POP();
  *(real_T *)&((char_T *)chartInstance->c12_v_xv4)[0] = c12_b_v_xv4.fl;
  *(real_T *)&((char_T *)chartInstance->c12_v_xv4)[8] = c12_b_v_xv4.fr;
  *(real_T *)&((char_T *)chartInstance->c12_v_xv4)[16] = c12_b_v_xv4.rl;
  *(real_T *)&((char_T *)chartInstance->c12_v_xv4)[24] = c12_b_v_xv4.rr;
  *(real_T *)&((char_T *)chartInstance->c12_v_yv4)[0] = c12_b_v_yv4.fl;
  *(real_T *)&((char_T *)chartInstance->c12_v_yv4)[8] = c12_b_v_yv4.fr;
  *(real_T *)&((char_T *)chartInstance->c12_v_yv4)[16] = c12_b_v_yv4.rl;
  *(real_T *)&((char_T *)chartInstance->c12_v_yv4)[24] = c12_b_v_yv4.rr;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c12_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_AllPurposeModel_TyreRelaxationMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void mdl_start_c12_AllPurposeModel_TyreRelaxation
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc12_AllPurposeModel_TyreRelaxation
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c12_machineNumber, uint32_T
  c12_chartNumber, uint32_T c12_instanceNumber)
{
  (void)c12_machineNumber;
  (void)c12_chartNumber;
  (void)c12_instanceNumber;
}

static const mxArray *c12_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  c12_whl_vec4 c12_u;
  const mxArray *c12_y = NULL;
  real_T c12_b_u;
  const mxArray *c12_b_y = NULL;
  real_T c12_c_u;
  const mxArray *c12_c_y = NULL;
  real_T c12_d_u;
  const mxArray *c12_d_y = NULL;
  real_T c12_e_u;
  const mxArray *c12_e_y = NULL;
  SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(c12_whl_vec4 *)c12_inData;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c12_b_u = c12_u.fl;
  c12_b_y = NULL;
  sf_mex_assign(&c12_b_y, sf_mex_create("y", &c12_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_y, c12_b_y, "fl", "fl", 0);
  c12_c_u = c12_u.fr;
  c12_c_y = NULL;
  sf_mex_assign(&c12_c_y, sf_mex_create("y", &c12_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_y, c12_c_y, "fr", "fr", 0);
  c12_d_u = c12_u.rl;
  c12_d_y = NULL;
  sf_mex_assign(&c12_d_y, sf_mex_create("y", &c12_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_y, c12_d_y, "rl", "rl", 0);
  c12_e_u = c12_u.rr;
  c12_e_y = NULL;
  sf_mex_assign(&c12_e_y, sf_mex_create("y", &c12_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_y, c12_e_y, "rr", "rr", 0);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, false);
  return c12_mxArrayOutData;
}

static c12_whl_vec4 c12_emlrt_marshallIn
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c12_b_v_yv4, const char_T *c12_identifier)
{
  c12_whl_vec4 c12_y;
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_v_yv4),
    &c12_thisId);
  sf_mex_destroy(&c12_b_v_yv4);
  return c12_y;
}

static c12_whl_vec4 c12_b_emlrt_marshallIn
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  c12_whl_vec4 c12_y;
  emlrtMsgIdentifier c12_thisId;
  static const char * c12_fieldNames[4] = { "fl", "fr", "rl", "rr" };

  c12_thisId.fParent = c12_parentId;
  sf_mex_check_struct(c12_parentId, c12_u, 4, c12_fieldNames, 0U, NULL);
  c12_thisId.fIdentifier = "fl";
  c12_y.fl = c12_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c12_u, "fl", "fl", 0)), &c12_thisId);
  c12_thisId.fIdentifier = "fr";
  c12_y.fr = c12_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c12_u, "fr", "fr", 0)), &c12_thisId);
  c12_thisId.fIdentifier = "rl";
  c12_y.rl = c12_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c12_u, "rl", "rl", 0)), &c12_thisId);
  c12_thisId.fIdentifier = "rr";
  c12_y.rr = c12_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c12_u, "rr", "rr", 0)), &c12_thisId);
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static real_T c12_c_emlrt_marshallIn
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  real_T c12_y;
  real_T c12_d0;
  (void)chartInstance;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_d0, 1, 0, 0U, 0, 0U, 0);
  c12_y = c12_d0;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_b_v_yv4;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  c12_whl_vec4 c12_y;
  SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c12_b_v_yv4 = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_v_yv4),
    &c12_thisId);
  sf_mex_destroy(&c12_b_v_yv4);
  *(c12_whl_vec4 *)c12_outData = c12_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

static const mxArray *c12_b_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData;
  c12_struct_iBlsPBO3AGnt69vDoTx5zD c12_u;
  const mxArray *c12_y = NULL;
  c12_struct_Nst2vGTExxHsg85EUOj9EH c12_b_u;
  const mxArray *c12_b_y = NULL;
  real_T c12_c_u;
  const mxArray *c12_c_y = NULL;
  c12_struct_HhckT6rntEraqECYVIDvCC c12_d_u;
  const mxArray *c12_d_y = NULL;
  real_T c12_e_u;
  const mxArray *c12_e_y = NULL;
  real_T c12_f_u;
  const mxArray *c12_f_y = NULL;
  const mxArray *c12_g_y = NULL;
  real_T c12_g_u;
  const mxArray *c12_h_y = NULL;
  real_T c12_h_u;
  const mxArray *c12_i_y = NULL;
  const mxArray *c12_j_y = NULL;
  real_T c12_i_u;
  const mxArray *c12_k_y = NULL;
  real_T c12_j_u;
  const mxArray *c12_l_y = NULL;
  const mxArray *c12_m_y = NULL;
  real_T c12_k_u;
  const mxArray *c12_n_y = NULL;
  real_T c12_l_u;
  const mxArray *c12_o_y = NULL;
  const mxArray *c12_p_y = NULL;
  real_T c12_m_u;
  const mxArray *c12_q_y = NULL;
  real_T c12_n_u;
  const mxArray *c12_r_y = NULL;
  real_T c12_o_u;
  const mxArray *c12_s_y = NULL;
  c12_struct_ZCmOWPuqBDw16FSOVVD00 c12_p_u;
  const mxArray *c12_t_y = NULL;
  real_T c12_q_u;
  const mxArray *c12_u_y = NULL;
  real_T c12_r_u;
  const mxArray *c12_v_y = NULL;
  real_T c12_s_u;
  const mxArray *c12_w_y = NULL;
  real_T c12_t_u;
  const mxArray *c12_x_y = NULL;
  real_T c12_u_u;
  const mxArray *c12_y_y = NULL;
  real_T c12_v_u;
  const mxArray *c12_ab_y = NULL;
  real_T c12_w_u;
  const mxArray *c12_bb_y = NULL;
  real_T c12_x_u;
  const mxArray *c12_cb_y = NULL;
  real_T c12_y_u;
  const mxArray *c12_db_y = NULL;
  real_T c12_ab_u;
  const mxArray *c12_eb_y = NULL;
  real_T c12_bb_u;
  const mxArray *c12_fb_y = NULL;
  int32_T c12_i14;
  real_T c12_cb_u[4];
  const mxArray *c12_gb_y = NULL;
  real_T c12_db_u;
  const mxArray *c12_hb_y = NULL;
  c12_struct_ZKAzdrl7umDGJoC14aoVKC c12_eb_u;
  const mxArray *c12_ib_y = NULL;
  int32_T c12_i15;
  real_T c12_fb_u[3];
  const mxArray *c12_jb_y = NULL;
  int32_T c12_i16;
  real_T c12_gb_u[3];
  const mxArray *c12_kb_y = NULL;
  int32_T c12_i17;
  real_T c12_hb_u[3];
  const mxArray *c12_lb_y = NULL;
  int32_T c12_i18;
  real_T c12_ib_u[3];
  const mxArray *c12_mb_y = NULL;
  const mxArray *c12_nb_y = NULL;
  int32_T c12_i19;
  real_T c12_jb_u[3];
  const mxArray *c12_ob_y = NULL;
  int32_T c12_i20;
  real_T c12_kb_u[3];
  const mxArray *c12_pb_y = NULL;
  int32_T c12_i21;
  real_T c12_lb_u[3];
  const mxArray *c12_qb_y = NULL;
  int32_T c12_i22;
  real_T c12_mb_u[3];
  const mxArray *c12_rb_y = NULL;
  const mxArray *c12_sb_y = NULL;
  int32_T c12_i23;
  real_T c12_nb_u[3];
  const mxArray *c12_tb_y = NULL;
  int32_T c12_i24;
  real_T c12_ob_u[3];
  const mxArray *c12_ub_y = NULL;
  int32_T c12_i25;
  real_T c12_pb_u[3];
  const mxArray *c12_vb_y = NULL;
  int32_T c12_i26;
  real_T c12_qb_u[3];
  const mxArray *c12_wb_y = NULL;
  const mxArray *c12_xb_y = NULL;
  int32_T c12_i27;
  real_T c12_rb_u[3];
  const mxArray *c12_yb_y = NULL;
  int32_T c12_i28;
  real_T c12_sb_u[3];
  const mxArray *c12_ac_y = NULL;
  int32_T c12_i29;
  real_T c12_tb_u[3];
  const mxArray *c12_bc_y = NULL;
  int32_T c12_i30;
  real_T c12_ub_u[3];
  const mxArray *c12_cc_y = NULL;
  real_T c12_vb_u;
  const mxArray *c12_dc_y = NULL;
  real_T c12_wb_u;
  const mxArray *c12_ec_y = NULL;
  real_T c12_xb_u;
  const mxArray *c12_fc_y = NULL;
  real_T c12_yb_u;
  const mxArray *c12_gc_y = NULL;
  real_T c12_ac_u;
  const mxArray *c12_hc_y = NULL;
  real_T c12_bc_u;
  const mxArray *c12_ic_y = NULL;
  real_T c12_cc_u;
  const mxArray *c12_jc_y = NULL;
  real_T c12_dc_u;
  const mxArray *c12_kc_y = NULL;
  real_T c12_ec_u;
  const mxArray *c12_lc_y = NULL;
  real_T c12_fc_u;
  const mxArray *c12_mc_y = NULL;
  real_T c12_gc_u;
  const mxArray *c12_nc_y = NULL;
  real_T c12_hc_u;
  const mxArray *c12_oc_y = NULL;
  c12_struct_r4FNviKwHfdhB8nQjvQv9 c12_ic_u;
  const mxArray *c12_pc_y = NULL;
  real_T c12_jc_u;
  const mxArray *c12_qc_y = NULL;
  c12_struct_Y9F1qlBi9AhssksPwemA4G c12_kc_u;
  const mxArray *c12_rc_y = NULL;
  real_T c12_lc_u;
  const mxArray *c12_sc_y = NULL;
  real_T c12_mc_u;
  const mxArray *c12_tc_y = NULL;
  real_T c12_nc_u;
  const mxArray *c12_uc_y = NULL;
  SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_mxArrayOutData = NULL;
  c12_u = *(c12_struct_iBlsPBO3AGnt69vDoTx5zD *)c12_inData;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c12_b_u = c12_u.Env;
  c12_b_y = NULL;
  sf_mex_assign(&c12_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c12_c_u = c12_b_u.g;
  c12_c_y = NULL;
  sf_mex_assign(&c12_c_y, sf_mex_create("y", &c12_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_b_y, c12_c_y, "g", "g", 0);
  c12_d_u = c12_b_u.left1;
  c12_d_y = NULL;
  sf_mex_assign(&c12_d_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c12_e_u = c12_d_u.x;
  c12_e_y = NULL;
  sf_mex_assign(&c12_e_y, sf_mex_create("y", &c12_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_d_y, c12_e_y, "x", "x", 0);
  c12_f_u = c12_d_u.y;
  c12_f_y = NULL;
  sf_mex_assign(&c12_f_y, sf_mex_create("y", &c12_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_d_y, c12_f_y, "y", "y", 0);
  sf_mex_addfield(c12_b_y, c12_d_y, "left1", "left1", 0);
  c12_d_u = c12_b_u.right1;
  c12_g_y = NULL;
  sf_mex_assign(&c12_g_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c12_g_u = c12_d_u.x;
  c12_h_y = NULL;
  sf_mex_assign(&c12_h_y, sf_mex_create("y", &c12_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_g_y, c12_h_y, "x", "x", 0);
  c12_h_u = c12_d_u.y;
  c12_i_y = NULL;
  sf_mex_assign(&c12_i_y, sf_mex_create("y", &c12_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_g_y, c12_i_y, "y", "y", 0);
  sf_mex_addfield(c12_b_y, c12_g_y, "right1", "right1", 0);
  c12_d_u = c12_b_u.right2;
  c12_j_y = NULL;
  sf_mex_assign(&c12_j_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c12_i_u = c12_d_u.x;
  c12_k_y = NULL;
  sf_mex_assign(&c12_k_y, sf_mex_create("y", &c12_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_j_y, c12_k_y, "x", "x", 0);
  c12_j_u = c12_d_u.y;
  c12_l_y = NULL;
  sf_mex_assign(&c12_l_y, sf_mex_create("y", &c12_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_j_y, c12_l_y, "y", "y", 0);
  sf_mex_addfield(c12_b_y, c12_j_y, "right2", "right2", 0);
  c12_d_u = c12_b_u.left2;
  c12_m_y = NULL;
  sf_mex_assign(&c12_m_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c12_k_u = c12_d_u.x;
  c12_n_y = NULL;
  sf_mex_assign(&c12_n_y, sf_mex_create("y", &c12_k_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_m_y, c12_n_y, "x", "x", 0);
  c12_l_u = c12_d_u.y;
  c12_o_y = NULL;
  sf_mex_assign(&c12_o_y, sf_mex_create("y", &c12_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_m_y, c12_o_y, "y", "y", 0);
  sf_mex_addfield(c12_b_y, c12_m_y, "left2", "left2", 0);
  c12_d_u = c12_b_u.right3;
  c12_p_y = NULL;
  sf_mex_assign(&c12_p_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c12_m_u = c12_d_u.x;
  c12_q_y = NULL;
  sf_mex_assign(&c12_q_y, sf_mex_create("y", &c12_m_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_p_y, c12_q_y, "x", "x", 0);
  c12_n_u = c12_d_u.y;
  c12_r_y = NULL;
  sf_mex_assign(&c12_r_y, sf_mex_create("y", &c12_n_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_p_y, c12_r_y, "y", "y", 0);
  sf_mex_addfield(c12_b_y, c12_p_y, "right3", "right3", 0);
  c12_o_u = c12_b_u.mu;
  c12_s_y = NULL;
  sf_mex_assign(&c12_s_y, sf_mex_create("y", &c12_o_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_b_y, c12_s_y, "mu", "mu", 0);
  sf_mex_addfield(c12_y, c12_b_y, "Env", "Env", 0);
  c12_p_u = c12_u.Veh;
  c12_t_y = NULL;
  sf_mex_assign(&c12_t_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c12_q_u = c12_p_u.m;
  c12_u_y = NULL;
  sf_mex_assign(&c12_u_y, sf_mex_create("y", &c12_q_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_t_y, c12_u_y, "m", "m", 0);
  c12_r_u = c12_p_u.Jz;
  c12_v_y = NULL;
  sf_mex_assign(&c12_v_y, sf_mex_create("y", &c12_r_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_t_y, c12_v_y, "Jz", "Jz", 0);
  c12_s_u = c12_p_u.m_sprung;
  c12_w_y = NULL;
  sf_mex_assign(&c12_w_y, sf_mex_create("y", &c12_s_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_t_y, c12_w_y, "m_sprung", "m_sprung", 0);
  c12_t_u = c12_p_u.Jx_sprung;
  c12_x_y = NULL;
  sf_mex_assign(&c12_x_y, sf_mex_create("y", &c12_t_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_t_y, c12_x_y, "Jx_sprung", "Jx_sprung", 0);
  c12_u_u = c12_p_u.Jy_sprung;
  c12_y_y = NULL;
  sf_mex_assign(&c12_y_y, sf_mex_create("y", &c12_u_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_t_y, c12_y_y, "Jy_sprung", "Jy_sprung", 0);
  c12_v_u = c12_p_u.lf;
  c12_ab_y = NULL;
  sf_mex_assign(&c12_ab_y, sf_mex_create("y", &c12_v_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_t_y, c12_ab_y, "lf", "lf", 0);
  c12_w_u = c12_p_u.lr;
  c12_bb_y = NULL;
  sf_mex_assign(&c12_bb_y, sf_mex_create("y", &c12_w_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_t_y, c12_bb_y, "lr", "lr", 0);
  c12_x_u = c12_p_u.L;
  c12_cb_y = NULL;
  sf_mex_assign(&c12_cb_y, sf_mex_create("y", &c12_x_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_t_y, c12_cb_y, "L", "L", 0);
  c12_y_u = c12_p_u.TrackWidth;
  c12_db_y = NULL;
  sf_mex_assign(&c12_db_y, sf_mex_create("y", &c12_y_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_t_y, c12_db_y, "TrackWidth", "TrackWidth", 0);
  c12_ab_u = c12_p_u.h;
  c12_eb_y = NULL;
  sf_mex_assign(&c12_eb_y, sf_mex_create("y", &c12_ab_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_t_y, c12_eb_y, "h", "h", 0);
  c12_bb_u = c12_p_u.HalfRohACd;
  c12_fb_y = NULL;
  sf_mex_assign(&c12_fb_y, sf_mex_create("y", &c12_bb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_t_y, c12_fb_y, "HalfRohACd", "HalfRohACd", 0);
  for (c12_i14 = 0; c12_i14 < 4; c12_i14++) {
    c12_cb_u[c12_i14] = c12_p_u.F_z4_static[c12_i14];
  }

  c12_gb_y = NULL;
  sf_mex_assign(&c12_gb_y, sf_mex_create("y", c12_cb_u, 0, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_addfield(c12_t_y, c12_gb_y, "F_z4_static", "F_z4_static", 0);
  c12_db_u = c12_p_u.Rw;
  c12_hb_y = NULL;
  sf_mex_assign(&c12_hb_y, sf_mex_create("y", &c12_db_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_t_y, c12_hb_y, "Rw", "Rw", 0);
  c12_eb_u = c12_p_u.r_long;
  c12_ib_y = NULL;
  sf_mex_assign(&c12_ib_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c12_i15 = 0; c12_i15 < 3; c12_i15++) {
    c12_fb_u[c12_i15] = c12_eb_u.fl[c12_i15];
  }

  c12_jb_y = NULL;
  sf_mex_assign(&c12_jb_y, sf_mex_create("y", c12_fb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c12_ib_y, c12_jb_y, "fl", "fl", 0);
  for (c12_i16 = 0; c12_i16 < 3; c12_i16++) {
    c12_gb_u[c12_i16] = c12_eb_u.fr[c12_i16];
  }

  c12_kb_y = NULL;
  sf_mex_assign(&c12_kb_y, sf_mex_create("y", c12_gb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c12_ib_y, c12_kb_y, "fr", "fr", 0);
  for (c12_i17 = 0; c12_i17 < 3; c12_i17++) {
    c12_hb_u[c12_i17] = c12_eb_u.rl[c12_i17];
  }

  c12_lb_y = NULL;
  sf_mex_assign(&c12_lb_y, sf_mex_create("y", c12_hb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c12_ib_y, c12_lb_y, "rl", "rl", 0);
  for (c12_i18 = 0; c12_i18 < 3; c12_i18++) {
    c12_ib_u[c12_i18] = c12_eb_u.rr[c12_i18];
  }

  c12_mb_y = NULL;
  sf_mex_assign(&c12_mb_y, sf_mex_create("y", c12_ib_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c12_ib_y, c12_mb_y, "rr", "rr", 0);
  sf_mex_addfield(c12_t_y, c12_ib_y, "r_long", "r_long", 0);
  c12_eb_u = c12_p_u.r_lat;
  c12_nb_y = NULL;
  sf_mex_assign(&c12_nb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c12_i19 = 0; c12_i19 < 3; c12_i19++) {
    c12_jb_u[c12_i19] = c12_eb_u.fl[c12_i19];
  }

  c12_ob_y = NULL;
  sf_mex_assign(&c12_ob_y, sf_mex_create("y", c12_jb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c12_nb_y, c12_ob_y, "fl", "fl", 0);
  for (c12_i20 = 0; c12_i20 < 3; c12_i20++) {
    c12_kb_u[c12_i20] = c12_eb_u.fr[c12_i20];
  }

  c12_pb_y = NULL;
  sf_mex_assign(&c12_pb_y, sf_mex_create("y", c12_kb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c12_nb_y, c12_pb_y, "fr", "fr", 0);
  for (c12_i21 = 0; c12_i21 < 3; c12_i21++) {
    c12_lb_u[c12_i21] = c12_eb_u.rl[c12_i21];
  }

  c12_qb_y = NULL;
  sf_mex_assign(&c12_qb_y, sf_mex_create("y", c12_lb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c12_nb_y, c12_qb_y, "rl", "rl", 0);
  for (c12_i22 = 0; c12_i22 < 3; c12_i22++) {
    c12_mb_u[c12_i22] = c12_eb_u.rr[c12_i22];
  }

  c12_rb_y = NULL;
  sf_mex_assign(&c12_rb_y, sf_mex_create("y", c12_mb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c12_nb_y, c12_rb_y, "rr", "rr", 0);
  sf_mex_addfield(c12_t_y, c12_nb_y, "r_lat", "r_lat", 0);
  c12_eb_u = c12_p_u.r_lever;
  c12_sb_y = NULL;
  sf_mex_assign(&c12_sb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c12_i23 = 0; c12_i23 < 3; c12_i23++) {
    c12_nb_u[c12_i23] = c12_eb_u.fl[c12_i23];
  }

  c12_tb_y = NULL;
  sf_mex_assign(&c12_tb_y, sf_mex_create("y", c12_nb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c12_sb_y, c12_tb_y, "fl", "fl", 0);
  for (c12_i24 = 0; c12_i24 < 3; c12_i24++) {
    c12_ob_u[c12_i24] = c12_eb_u.fr[c12_i24];
  }

  c12_ub_y = NULL;
  sf_mex_assign(&c12_ub_y, sf_mex_create("y", c12_ob_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c12_sb_y, c12_ub_y, "fr", "fr", 0);
  for (c12_i25 = 0; c12_i25 < 3; c12_i25++) {
    c12_pb_u[c12_i25] = c12_eb_u.rl[c12_i25];
  }

  c12_vb_y = NULL;
  sf_mex_assign(&c12_vb_y, sf_mex_create("y", c12_pb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c12_sb_y, c12_vb_y, "rl", "rl", 0);
  for (c12_i26 = 0; c12_i26 < 3; c12_i26++) {
    c12_qb_u[c12_i26] = c12_eb_u.rr[c12_i26];
  }

  c12_wb_y = NULL;
  sf_mex_assign(&c12_wb_y, sf_mex_create("y", c12_qb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c12_sb_y, c12_wb_y, "rr", "rr", 0);
  sf_mex_addfield(c12_t_y, c12_sb_y, "r_lever", "r_lever", 0);
  c12_eb_u = c12_p_u.r_pivot;
  c12_xb_y = NULL;
  sf_mex_assign(&c12_xb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c12_i27 = 0; c12_i27 < 3; c12_i27++) {
    c12_rb_u[c12_i27] = c12_eb_u.fl[c12_i27];
  }

  c12_yb_y = NULL;
  sf_mex_assign(&c12_yb_y, sf_mex_create("y", c12_rb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c12_xb_y, c12_yb_y, "fl", "fl", 0);
  for (c12_i28 = 0; c12_i28 < 3; c12_i28++) {
    c12_sb_u[c12_i28] = c12_eb_u.fr[c12_i28];
  }

  c12_ac_y = NULL;
  sf_mex_assign(&c12_ac_y, sf_mex_create("y", c12_sb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c12_xb_y, c12_ac_y, "fr", "fr", 0);
  for (c12_i29 = 0; c12_i29 < 3; c12_i29++) {
    c12_tb_u[c12_i29] = c12_eb_u.rl[c12_i29];
  }

  c12_bc_y = NULL;
  sf_mex_assign(&c12_bc_y, sf_mex_create("y", c12_tb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c12_xb_y, c12_bc_y, "rl", "rl", 0);
  for (c12_i30 = 0; c12_i30 < 3; c12_i30++) {
    c12_ub_u[c12_i30] = c12_eb_u.rr[c12_i30];
  }

  c12_cc_y = NULL;
  sf_mex_assign(&c12_cc_y, sf_mex_create("y", c12_ub_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c12_xb_y, c12_cc_y, "rr", "rr", 0);
  sf_mex_addfield(c12_t_y, c12_xb_y, "r_pivot", "r_pivot", 0);
  c12_vb_u = c12_p_u.cw;
  c12_dc_y = NULL;
  sf_mex_assign(&c12_dc_y, sf_mex_create("y", &c12_vb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_t_y, c12_dc_y, "cw", "cw", 0);
  c12_wb_u = c12_p_u.carb_f;
  c12_ec_y = NULL;
  sf_mex_assign(&c12_ec_y, sf_mex_create("y", &c12_wb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_t_y, c12_ec_y, "carb_f", "carb_f", 0);
  c12_xb_u = c12_p_u.carb_r;
  c12_fc_y = NULL;
  sf_mex_assign(&c12_fc_y, sf_mex_create("y", &c12_xb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_t_y, c12_fc_y, "carb_r", "carb_r", 0);
  c12_yb_u = c12_p_u.dw;
  c12_gc_y = NULL;
  sf_mex_assign(&c12_gc_y, sf_mex_create("y", &c12_yb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_t_y, c12_gc_y, "dw", "dw", 0);
  c12_ac_u = c12_p_u.Jw;
  c12_hc_y = NULL;
  sf_mex_assign(&c12_hc_y, sf_mex_create("y", &c12_ac_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_t_y, c12_hc_y, "Jw", "Jw", 0);
  c12_bc_u = c12_p_u.C0;
  c12_ic_y = NULL;
  sf_mex_assign(&c12_ic_y, sf_mex_create("y", &c12_bc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_t_y, c12_ic_y, "C0", "C0", 0);
  c12_cc_u = c12_p_u.RelaxLength;
  c12_jc_y = NULL;
  sf_mex_assign(&c12_jc_y, sf_mex_create("y", &c12_cc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_t_y, c12_jc_y, "RelaxLength", "RelaxLength", 0);
  c12_dc_u = c12_p_u.RRC;
  c12_kc_y = NULL;
  sf_mex_assign(&c12_kc_y, sf_mex_create("y", &c12_dc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_t_y, c12_kc_y, "RRC", "RRC", 0);
  c12_ec_u = c12_p_u.Pmax;
  c12_lc_y = NULL;
  sf_mex_assign(&c12_lc_y, sf_mex_create("y", &c12_ec_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_t_y, c12_lc_y, "Pmax", "Pmax", 0);
  c12_fc_u = c12_p_u.PropDistrFrnt;
  c12_mc_y = NULL;
  sf_mex_assign(&c12_mc_y, sf_mex_create("y", &c12_fc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_t_y, c12_mc_y, "PropDistrFrnt", "PropDistrFrnt", 0);
  c12_gc_u = c12_p_u.BrkDistrFrnt;
  c12_nc_y = NULL;
  sf_mex_assign(&c12_nc_y, sf_mex_create("y", &c12_gc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_t_y, c12_nc_y, "BrkDistrFrnt", "BrkDistrFrnt", 0);
  c12_hc_u = c12_p_u.SteRatio;
  c12_oc_y = NULL;
  sf_mex_assign(&c12_oc_y, sf_mex_create("y", &c12_hc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_t_y, c12_oc_y, "SteRatio", "SteRatio", 0);
  sf_mex_addfield(c12_y, c12_t_y, "Veh", "Veh", 0);
  c12_ic_u = c12_u.Drvr;
  c12_pc_y = NULL;
  sf_mex_assign(&c12_pc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c12_jc_u = c12_ic_u.v_set;
  c12_qc_y = NULL;
  sf_mex_assign(&c12_qc_y, sf_mex_create("y", &c12_jc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_pc_y, c12_qc_y, "v_set", "v_set", 0);
  sf_mex_addfield(c12_y, c12_pc_y, "Drvr", "Drvr", 0);
  c12_kc_u = c12_u.Init;
  c12_rc_y = NULL;
  sf_mex_assign(&c12_rc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c12_lc_u = c12_kc_u.v_x;
  c12_sc_y = NULL;
  sf_mex_assign(&c12_sc_y, sf_mex_create("y", &c12_lc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_rc_y, c12_sc_y, "v_x", "v_x", 0);
  c12_mc_u = c12_kc_u.F_fz;
  c12_tc_y = NULL;
  sf_mex_assign(&c12_tc_y, sf_mex_create("y", &c12_mc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_rc_y, c12_tc_y, "F_fz", "F_fz", 0);
  c12_nc_u = c12_kc_u.F_rz;
  c12_uc_y = NULL;
  sf_mex_assign(&c12_uc_y, sf_mex_create("y", &c12_nc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_rc_y, c12_uc_y, "F_rz", "F_rz", 0);
  sf_mex_addfield(c12_y, c12_rc_y, "Init", "Init", 0);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, false);
  return c12_mxArrayOutData;
}

static void c12_d_emlrt_marshallIn
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId,
   c12_struct_iBlsPBO3AGnt69vDoTx5zD *c12_y)
{
  emlrtMsgIdentifier c12_thisId;
  static const char * c12_fieldNames[4] = { "Env", "Veh", "Drvr", "Init" };

  c12_thisId.fParent = c12_parentId;
  sf_mex_check_struct(c12_parentId, c12_u, 4, c12_fieldNames, 0U, NULL);
  c12_thisId.fIdentifier = "Env";
  c12_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c12_u, "Env",
    "Env", 0)), &c12_thisId, &c12_y->Env);
  c12_thisId.fIdentifier = "Veh";
  c12_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c12_u, "Veh",
    "Veh", 0)), &c12_thisId, &c12_y->Veh);
  c12_thisId.fIdentifier = "Drvr";
  c12_y->Drvr = c12_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c12_u, "Drvr", "Drvr", 0)), &c12_thisId);
  c12_thisId.fIdentifier = "Init";
  c12_y->Init = c12_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c12_u, "Init", "Init", 0)), &c12_thisId);
  sf_mex_destroy(&c12_u);
}

static void c12_e_emlrt_marshallIn
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId,
   c12_struct_Nst2vGTExxHsg85EUOj9EH *c12_y)
{
  emlrtMsgIdentifier c12_thisId;
  static const char * c12_fieldNames[7] = { "g", "left1", "right1", "right2",
    "left2", "right3", "mu" };

  c12_thisId.fParent = c12_parentId;
  sf_mex_check_struct(c12_parentId, c12_u, 7, c12_fieldNames, 0U, NULL);
  c12_thisId.fIdentifier = "g";
  c12_y->g = c12_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c12_u, "g", "g", 0)), &c12_thisId);
  c12_thisId.fIdentifier = "left1";
  c12_y->left1 = c12_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c12_u, "left1", "left1", 0)), &c12_thisId);
  c12_thisId.fIdentifier = "right1";
  c12_y->right1 = c12_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c12_u, "right1", "right1", 0)), &c12_thisId);
  c12_thisId.fIdentifier = "right2";
  c12_y->right2 = c12_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c12_u, "right2", "right2", 0)), &c12_thisId);
  c12_thisId.fIdentifier = "left2";
  c12_y->left2 = c12_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c12_u, "left2", "left2", 0)), &c12_thisId);
  c12_thisId.fIdentifier = "right3";
  c12_y->right3 = c12_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c12_u, "right3", "right3", 0)), &c12_thisId);
  c12_thisId.fIdentifier = "mu";
  c12_y->mu = c12_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c12_u, "mu", "mu", 0)), &c12_thisId);
  sf_mex_destroy(&c12_u);
}

static c12_struct_HhckT6rntEraqECYVIDvCC c12_f_emlrt_marshallIn
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  c12_struct_HhckT6rntEraqECYVIDvCC c12_y;
  emlrtMsgIdentifier c12_thisId;
  static const char * c12_fieldNames[2] = { "x", "y" };

  c12_thisId.fParent = c12_parentId;
  sf_mex_check_struct(c12_parentId, c12_u, 2, c12_fieldNames, 0U, NULL);
  c12_thisId.fIdentifier = "x";
  c12_y.x = c12_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c12_u, "x", "x", 0)), &c12_thisId);
  c12_thisId.fIdentifier = "y";
  c12_y.y = c12_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c12_u, "y", "y", 0)), &c12_thisId);
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_g_emlrt_marshallIn
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId,
   c12_struct_ZCmOWPuqBDw16FSOVVD00 *c12_y)
{
  emlrtMsgIdentifier c12_thisId;
  static const char * c12_fieldNames[29] = { "m", "Jz", "m_sprung", "Jx_sprung",
    "Jy_sprung", "lf", "lr", "L", "TrackWidth", "h", "HalfRohACd", "F_z4_static",
    "Rw", "r_long", "r_lat", "r_lever", "r_pivot", "cw", "carb_f", "carb_r",
    "dw", "Jw", "C0", "RelaxLength", "RRC", "Pmax", "PropDistrFrnt",
    "BrkDistrFrnt", "SteRatio" };

  c12_thisId.fParent = c12_parentId;
  sf_mex_check_struct(c12_parentId, c12_u, 29, c12_fieldNames, 0U, NULL);
  c12_thisId.fIdentifier = "m";
  c12_y->m = c12_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c12_u, "m", "m", 0)), &c12_thisId);
  c12_thisId.fIdentifier = "Jz";
  c12_y->Jz = c12_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c12_u, "Jz", "Jz", 0)), &c12_thisId);
  c12_thisId.fIdentifier = "m_sprung";
  c12_y->m_sprung = c12_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c12_u, "m_sprung", "m_sprung", 0)), &c12_thisId);
  c12_thisId.fIdentifier = "Jx_sprung";
  c12_y->Jx_sprung = c12_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c12_u, "Jx_sprung", "Jx_sprung", 0)), &c12_thisId);
  c12_thisId.fIdentifier = "Jy_sprung";
  c12_y->Jy_sprung = c12_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c12_u, "Jy_sprung", "Jy_sprung", 0)), &c12_thisId);
  c12_thisId.fIdentifier = "lf";
  c12_y->lf = c12_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c12_u, "lf", "lf", 0)), &c12_thisId);
  c12_thisId.fIdentifier = "lr";
  c12_y->lr = c12_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c12_u, "lr", "lr", 0)), &c12_thisId);
  c12_thisId.fIdentifier = "L";
  c12_y->L = c12_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c12_u, "L", "L", 0)), &c12_thisId);
  c12_thisId.fIdentifier = "TrackWidth";
  c12_y->TrackWidth = c12_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c12_u, "TrackWidth", "TrackWidth", 0)), &c12_thisId);
  c12_thisId.fIdentifier = "h";
  c12_y->h = c12_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c12_u, "h", "h", 0)), &c12_thisId);
  c12_thisId.fIdentifier = "HalfRohACd";
  c12_y->HalfRohACd = c12_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c12_u, "HalfRohACd", "HalfRohACd", 0)), &c12_thisId);
  c12_thisId.fIdentifier = "F_z4_static";
  c12_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c12_u,
    "F_z4_static", "F_z4_static", 0)), &c12_thisId, c12_y->F_z4_static);
  c12_thisId.fIdentifier = "Rw";
  c12_y->Rw = c12_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c12_u, "Rw", "Rw", 0)), &c12_thisId);
  c12_thisId.fIdentifier = "r_long";
  c12_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c12_u,
    "r_long", "r_long", 0)), &c12_thisId, &c12_y->r_long);
  c12_thisId.fIdentifier = "r_lat";
  c12_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c12_u,
    "r_lat", "r_lat", 0)), &c12_thisId, &c12_y->r_lat);
  c12_thisId.fIdentifier = "r_lever";
  c12_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c12_u,
    "r_lever", "r_lever", 0)), &c12_thisId, &c12_y->r_lever);
  c12_thisId.fIdentifier = "r_pivot";
  c12_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c12_u,
    "r_pivot", "r_pivot", 0)), &c12_thisId, &c12_y->r_pivot);
  c12_thisId.fIdentifier = "cw";
  c12_y->cw = c12_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c12_u, "cw", "cw", 0)), &c12_thisId);
  c12_thisId.fIdentifier = "carb_f";
  c12_y->carb_f = c12_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c12_u, "carb_f", "carb_f", 0)), &c12_thisId);
  c12_thisId.fIdentifier = "carb_r";
  c12_y->carb_r = c12_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c12_u, "carb_r", "carb_r", 0)), &c12_thisId);
  c12_thisId.fIdentifier = "dw";
  c12_y->dw = c12_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c12_u, "dw", "dw", 0)), &c12_thisId);
  c12_thisId.fIdentifier = "Jw";
  c12_y->Jw = c12_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c12_u, "Jw", "Jw", 0)), &c12_thisId);
  c12_thisId.fIdentifier = "C0";
  c12_y->C0 = c12_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c12_u, "C0", "C0", 0)), &c12_thisId);
  c12_thisId.fIdentifier = "RelaxLength";
  c12_y->RelaxLength = c12_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c12_u, "RelaxLength", "RelaxLength", 0)), &c12_thisId);
  c12_thisId.fIdentifier = "RRC";
  c12_y->RRC = c12_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c12_u, "RRC", "RRC", 0)), &c12_thisId);
  c12_thisId.fIdentifier = "Pmax";
  c12_y->Pmax = c12_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c12_u, "Pmax", "Pmax", 0)), &c12_thisId);
  c12_thisId.fIdentifier = "PropDistrFrnt";
  c12_y->PropDistrFrnt = c12_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c12_u, "PropDistrFrnt", "PropDistrFrnt", 0)), &c12_thisId);
  c12_thisId.fIdentifier = "BrkDistrFrnt";
  c12_y->BrkDistrFrnt = c12_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c12_u, "BrkDistrFrnt", "BrkDistrFrnt", 0)), &c12_thisId);
  c12_thisId.fIdentifier = "SteRatio";
  c12_y->SteRatio = c12_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c12_u, "SteRatio", "SteRatio", 0)), &c12_thisId);
  sf_mex_destroy(&c12_u);
}

static void c12_h_emlrt_marshallIn
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId, real_T c12_y[4])
{
  real_T c12_dv3[4];
  int32_T c12_i31;
  (void)chartInstance;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), c12_dv3, 1, 0, 0U, 1, 0U, 2, 1,
                4);
  for (c12_i31 = 0; c12_i31 < 4; c12_i31++) {
    c12_y[c12_i31] = c12_dv3[c12_i31];
  }

  sf_mex_destroy(&c12_u);
}

static void c12_i_emlrt_marshallIn
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId,
   c12_struct_ZKAzdrl7umDGJoC14aoVKC *c12_y)
{
  emlrtMsgIdentifier c12_thisId;
  static const char * c12_fieldNames[4] = { "fl", "fr", "rl", "rr" };

  c12_thisId.fParent = c12_parentId;
  sf_mex_check_struct(c12_parentId, c12_u, 4, c12_fieldNames, 0U, NULL);
  c12_thisId.fIdentifier = "fl";
  c12_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c12_u, "fl",
    "fl", 0)), &c12_thisId, c12_y->fl);
  c12_thisId.fIdentifier = "fr";
  c12_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c12_u, "fr",
    "fr", 0)), &c12_thisId, c12_y->fr);
  c12_thisId.fIdentifier = "rl";
  c12_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c12_u, "rl",
    "rl", 0)), &c12_thisId, c12_y->rl);
  c12_thisId.fIdentifier = "rr";
  c12_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c12_u, "rr",
    "rr", 0)), &c12_thisId, c12_y->rr);
  sf_mex_destroy(&c12_u);
}

static void c12_j_emlrt_marshallIn
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId, real_T c12_y[3])
{
  real_T c12_dv4[3];
  int32_T c12_i32;
  (void)chartInstance;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), c12_dv4, 1, 0, 0U, 1, 0U, 2, 3,
                1);
  for (c12_i32 = 0; c12_i32 < 3; c12_i32++) {
    c12_y[c12_i32] = c12_dv4[c12_i32];
  }

  sf_mex_destroy(&c12_u);
}

static c12_struct_r4FNviKwHfdhB8nQjvQv9 c12_k_emlrt_marshallIn
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  c12_struct_r4FNviKwHfdhB8nQjvQv9 c12_y;
  emlrtMsgIdentifier c12_thisId;
  static const char * c12_fieldNames[1] = { "v_set" };

  c12_thisId.fParent = c12_parentId;
  sf_mex_check_struct(c12_parentId, c12_u, 1, c12_fieldNames, 0U, NULL);
  c12_thisId.fIdentifier = "v_set";
  c12_y.v_set = c12_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c12_u, "v_set", "v_set", 0)),
    &c12_thisId);
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static c12_struct_Y9F1qlBi9AhssksPwemA4G c12_l_emlrt_marshallIn
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  c12_struct_Y9F1qlBi9AhssksPwemA4G c12_y;
  emlrtMsgIdentifier c12_thisId;
  static const char * c12_fieldNames[3] = { "v_x", "F_fz", "F_rz" };

  c12_thisId.fParent = c12_parentId;
  sf_mex_check_struct(c12_parentId, c12_u, 3, c12_fieldNames, 0U, NULL);
  c12_thisId.fIdentifier = "v_x";
  c12_y.v_x = c12_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c12_u, "v_x", "v_x", 0)), &c12_thisId);
  c12_thisId.fIdentifier = "F_fz";
  c12_y.F_fz = c12_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c12_u, "F_fz", "F_fz", 0)), &c12_thisId);
  c12_thisId.fIdentifier = "F_rz";
  c12_y.F_rz = c12_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c12_u, "F_rz", "F_rz", 0)), &c12_thisId);
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_b_Par;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  c12_struct_iBlsPBO3AGnt69vDoTx5zD c12_y;
  SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c12_b_Par = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_Par), &c12_thisId,
    &c12_y);
  sf_mex_destroy(&c12_b_Par);
  *(c12_struct_iBlsPBO3AGnt69vDoTx5zD *)c12_outData = c12_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

static const mxArray *c12_c_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  c12_irp_vec3 c12_u;
  const mxArray *c12_y = NULL;
  real_T c12_b_u;
  const mxArray *c12_b_y = NULL;
  real_T c12_c_u;
  const mxArray *c12_c_y = NULL;
  real_T c12_d_u;
  const mxArray *c12_d_y = NULL;
  SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(c12_irp_vec3 *)c12_inData;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c12_b_u = c12_u.x;
  c12_b_y = NULL;
  sf_mex_assign(&c12_b_y, sf_mex_create("y", &c12_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_y, c12_b_y, "x", "x", 0);
  c12_c_u = c12_u.y;
  c12_c_y = NULL;
  sf_mex_assign(&c12_c_y, sf_mex_create("y", &c12_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_y, c12_c_y, "y", "y", 0);
  c12_d_u = c12_u.rotz;
  c12_d_y = NULL;
  sf_mex_assign(&c12_d_y, sf_mex_create("y", &c12_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_y, c12_d_y, "rotz", "rotz", 0);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, false);
  return c12_mxArrayOutData;
}

static const mxArray *c12_d_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  real_T c12_u;
  const mxArray *c12_y = NULL;
  SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(real_T *)c12_inData;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, false);
  return c12_mxArrayOutData;
}

static void c12_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_nargout;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  real_T c12_y;
  SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c12_nargout = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_nargout),
    &c12_thisId);
  sf_mex_destroy(&c12_nargout);
  *(real_T *)c12_outData = c12_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

static const mxArray *c12_e_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  int32_T c12_i33;
  real_T c12_b_inData[8];
  int32_T c12_i34;
  real_T c12_u[8];
  const mxArray *c12_y = NULL;
  SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  for (c12_i33 = 0; c12_i33 < 8; c12_i33++) {
    c12_b_inData[c12_i33] = (*(real_T (*)[8])c12_inData)[c12_i33];
  }

  for (c12_i34 = 0; c12_i34 < 8; c12_i34++) {
    c12_u[c12_i34] = c12_b_inData[c12_i34];
  }

  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", c12_u, 0, 0U, 1U, 0U, 1, 8), false);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, false);
  return c12_mxArrayOutData;
}

static void c12_m_emlrt_marshallIn
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId, real_T c12_y[8])
{
  real_T c12_dv5[8];
  int32_T c12_i35;
  (void)chartInstance;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), c12_dv5, 1, 0, 0U, 1, 0U, 1, 8);
  for (c12_i35 = 0; c12_i35 < 8; c12_i35++) {
    c12_y[c12_i35] = c12_dv5[c12_i35];
  }

  sf_mex_destroy(&c12_u);
}

static void c12_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_v_xyv8;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  real_T c12_y[8];
  int32_T c12_i36;
  SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c12_v_xyv8 = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_v_xyv8), &c12_thisId,
    c12_y);
  sf_mex_destroy(&c12_v_xyv8);
  for (c12_i36 = 0; c12_i36 < 8; c12_i36++) {
    (*(real_T (*)[8])c12_outData)[c12_i36] = c12_y[c12_i36];
  }

  sf_mex_destroy(&c12_mxArrayInData);
}

static const mxArray *c12_f_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  int32_T c12_i37;
  real_T c12_b_inData[3];
  int32_T c12_i38;
  real_T c12_u[3];
  const mxArray *c12_y = NULL;
  SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  for (c12_i37 = 0; c12_i37 < 3; c12_i37++) {
    c12_b_inData[c12_i37] = (*(real_T (*)[3])c12_inData)[c12_i37];
  }

  for (c12_i38 = 0; c12_i38 < 3; c12_i38++) {
    c12_u[c12_i38] = c12_b_inData[c12_i38];
  }

  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", c12_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, false);
  return c12_mxArrayOutData;
}

static void c12_n_emlrt_marshallIn
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId, real_T c12_y[3])
{
  real_T c12_dv6[3];
  int32_T c12_i39;
  (void)chartInstance;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), c12_dv6, 1, 0, 0U, 1, 0U, 1, 3);
  for (c12_i39 = 0; c12_i39 < 3; c12_i39++) {
    c12_y[c12_i39] = c12_dv6[c12_i39];
  }

  sf_mex_destroy(&c12_u);
}

static void c12_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_v_irp3_temp;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  real_T c12_y[3];
  int32_T c12_i40;
  SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c12_v_irp3_temp = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_v_irp3_temp), &c12_thisId,
    c12_y);
  sf_mex_destroy(&c12_v_irp3_temp);
  for (c12_i40 = 0; c12_i40 < 3; c12_i40++) {
    (*(real_T (*)[3])c12_outData)[c12_i40] = c12_y[c12_i40];
  }

  sf_mex_destroy(&c12_mxArrayInData);
}

static const mxArray *c12_g_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  int32_T c12_i41;
  int32_T c12_i42;
  int32_T c12_i43;
  real_T c12_b_inData[24];
  int32_T c12_i44;
  int32_T c12_i45;
  int32_T c12_i46;
  real_T c12_u[24];
  const mxArray *c12_y = NULL;
  SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_i41 = 0;
  for (c12_i42 = 0; c12_i42 < 8; c12_i42++) {
    for (c12_i43 = 0; c12_i43 < 3; c12_i43++) {
      c12_b_inData[c12_i43 + c12_i41] = (*(real_T (*)[24])c12_inData)[c12_i43 +
        c12_i41];
    }

    c12_i41 += 3;
  }

  c12_i44 = 0;
  for (c12_i45 = 0; c12_i45 < 8; c12_i45++) {
    for (c12_i46 = 0; c12_i46 < 3; c12_i46++) {
      c12_u[c12_i46 + c12_i44] = c12_b_inData[c12_i46 + c12_i44];
    }

    c12_i44 += 3;
  }

  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", c12_u, 0, 0U, 1U, 0U, 2, 3, 8), false);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, false);
  return c12_mxArrayOutData;
}

static void c12_o_emlrt_marshallIn
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId, real_T c12_y[24])
{
  real_T c12_dv7[24];
  int32_T c12_i47;
  (void)chartInstance;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), c12_dv7, 1, 0, 0U, 1, 0U, 2, 3,
                8);
  for (c12_i47 = 0; c12_i47 < 24; c12_i47++) {
    c12_y[c12_i47] = c12_dv7[c12_i47];
  }

  sf_mex_destroy(&c12_u);
}

static void c12_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_T_irpv;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  real_T c12_y[24];
  int32_T c12_i48;
  int32_T c12_i49;
  int32_T c12_i50;
  SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c12_T_irpv = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_T_irpv), &c12_thisId,
    c12_y);
  sf_mex_destroy(&c12_T_irpv);
  c12_i48 = 0;
  for (c12_i49 = 0; c12_i49 < 8; c12_i49++) {
    for (c12_i50 = 0; c12_i50 < 3; c12_i50++) {
      (*(real_T (*)[24])c12_outData)[c12_i50 + c12_i48] = c12_y[c12_i50 +
        c12_i48];
    }

    c12_i48 += 3;
  }

  sf_mex_destroy(&c12_mxArrayInData);
}

const mxArray
  *sf_c12_AllPurposeModel_TyreRelaxation_get_eml_resolved_functions_info(void)
{
  const mxArray *c12_nameCaptureInfo = NULL;
  c12_nameCaptureInfo = NULL;
  sf_mex_assign(&c12_nameCaptureInfo, sf_mex_createstruct("structure", 2, 20, 1),
                false);
  c12_info_helper(&c12_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c12_nameCaptureInfo);
  return c12_nameCaptureInfo;
}

static void c12_info_helper(const mxArray **c12_info)
{
  const mxArray *c12_rhs0 = NULL;
  const mxArray *c12_lhs0 = NULL;
  const mxArray *c12_rhs1 = NULL;
  const mxArray *c12_lhs1 = NULL;
  const mxArray *c12_rhs2 = NULL;
  const mxArray *c12_lhs2 = NULL;
  const mxArray *c12_rhs3 = NULL;
  const mxArray *c12_lhs3 = NULL;
  const mxArray *c12_rhs4 = NULL;
  const mxArray *c12_lhs4 = NULL;
  const mxArray *c12_rhs5 = NULL;
  const mxArray *c12_lhs5 = NULL;
  const mxArray *c12_rhs6 = NULL;
  const mxArray *c12_lhs6 = NULL;
  const mxArray *c12_rhs7 = NULL;
  const mxArray *c12_lhs7 = NULL;
  const mxArray *c12_rhs8 = NULL;
  const mxArray *c12_lhs8 = NULL;
  const mxArray *c12_rhs9 = NULL;
  const mxArray *c12_lhs9 = NULL;
  const mxArray *c12_rhs10 = NULL;
  const mxArray *c12_lhs10 = NULL;
  const mxArray *c12_rhs11 = NULL;
  const mxArray *c12_lhs11 = NULL;
  const mxArray *c12_rhs12 = NULL;
  const mxArray *c12_lhs12 = NULL;
  const mxArray *c12_rhs13 = NULL;
  const mxArray *c12_lhs13 = NULL;
  const mxArray *c12_rhs14 = NULL;
  const mxArray *c12_lhs14 = NULL;
  const mxArray *c12_rhs15 = NULL;
  const mxArray *c12_lhs15 = NULL;
  const mxArray *c12_rhs16 = NULL;
  const mxArray *c12_lhs16 = NULL;
  const mxArray *c12_rhs17 = NULL;
  const mxArray *c12_lhs17 = NULL;
  const mxArray *c12_rhs18 = NULL;
  const mxArray *c12_lhs18 = NULL;
  const mxArray *c12_rhs19 = NULL;
  const mxArray *c12_lhs19 = NULL;
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("mrdivide"), "name", "name",
                  0);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1410807648U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1370009886U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c12_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1389717774U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c12_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("rdivide"), "name", "name", 2);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1363713880U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c12_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c12_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 4);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c12_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("eml_div"), "name", "name", 5);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1386423952U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c12_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 6);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c12_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(""), "context", "context", 7);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 7);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1383877294U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c12_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 8);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 8);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c12_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 9);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c12_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 10);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 10);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c12_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 11);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c12_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 12);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  12);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1375980690U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c12_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 13);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c12_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("coder.internal.blas.xgemm"),
                  "name", "name", 14);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c12_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 15);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 15);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c12_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!below_threshold"),
                  "context", "context", 16);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 16);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c12_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 17);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 17);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1393330858U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c12_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 18);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 18);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c12_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 19);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "coder.internal.refblas.xgemm"), "name", "name", 19);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c12_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs19), "lhs", "lhs",
                  19);
  sf_mex_destroy(&c12_rhs0);
  sf_mex_destroy(&c12_lhs0);
  sf_mex_destroy(&c12_rhs1);
  sf_mex_destroy(&c12_lhs1);
  sf_mex_destroy(&c12_rhs2);
  sf_mex_destroy(&c12_lhs2);
  sf_mex_destroy(&c12_rhs3);
  sf_mex_destroy(&c12_lhs3);
  sf_mex_destroy(&c12_rhs4);
  sf_mex_destroy(&c12_lhs4);
  sf_mex_destroy(&c12_rhs5);
  sf_mex_destroy(&c12_lhs5);
  sf_mex_destroy(&c12_rhs6);
  sf_mex_destroy(&c12_lhs6);
  sf_mex_destroy(&c12_rhs7);
  sf_mex_destroy(&c12_lhs7);
  sf_mex_destroy(&c12_rhs8);
  sf_mex_destroy(&c12_lhs8);
  sf_mex_destroy(&c12_rhs9);
  sf_mex_destroy(&c12_lhs9);
  sf_mex_destroy(&c12_rhs10);
  sf_mex_destroy(&c12_lhs10);
  sf_mex_destroy(&c12_rhs11);
  sf_mex_destroy(&c12_lhs11);
  sf_mex_destroy(&c12_rhs12);
  sf_mex_destroy(&c12_lhs12);
  sf_mex_destroy(&c12_rhs13);
  sf_mex_destroy(&c12_lhs13);
  sf_mex_destroy(&c12_rhs14);
  sf_mex_destroy(&c12_lhs14);
  sf_mex_destroy(&c12_rhs15);
  sf_mex_destroy(&c12_lhs15);
  sf_mex_destroy(&c12_rhs16);
  sf_mex_destroy(&c12_lhs16);
  sf_mex_destroy(&c12_rhs17);
  sf_mex_destroy(&c12_lhs17);
  sf_mex_destroy(&c12_rhs18);
  sf_mex_destroy(&c12_lhs18);
  sf_mex_destroy(&c12_rhs19);
  sf_mex_destroy(&c12_lhs19);
}

static const mxArray *c12_emlrt_marshallOut(const char * c12_u)
{
  const mxArray *c12_y = NULL;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", c12_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c12_u)), false);
  return c12_y;
}

static const mxArray *c12_b_emlrt_marshallOut(const uint32_T c12_u)
{
  const mxArray *c12_y = NULL;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 7, 0U, 0U, 0U, 0), false);
  return c12_y;
}

static void c12_eml_scalar_eg(SFc12_AllPurposeModel_TyreRelaxationInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c12_eml_xgemm(SFc12_AllPurposeModel_TyreRelaxationInstanceStruct
  *chartInstance, real_T c12_A[24], real_T c12_B[3], real_T c12_C[8], real_T
  c12_b_C[8])
{
  int32_T c12_i51;
  int32_T c12_i52;
  real_T c12_b_A[24];
  int32_T c12_i53;
  real_T c12_b_B[3];
  for (c12_i51 = 0; c12_i51 < 8; c12_i51++) {
    c12_b_C[c12_i51] = c12_C[c12_i51];
  }

  for (c12_i52 = 0; c12_i52 < 24; c12_i52++) {
    c12_b_A[c12_i52] = c12_A[c12_i52];
  }

  for (c12_i53 = 0; c12_i53 < 3; c12_i53++) {
    c12_b_B[c12_i53] = c12_B[c12_i53];
  }

  c12_b_eml_xgemm(chartInstance, c12_b_A, c12_b_B, c12_b_C);
}

static const mxArray *c12_h_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  int32_T c12_u;
  const mxArray *c12_y = NULL;
  SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(int32_T *)c12_inData;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, false);
  return c12_mxArrayOutData;
}

static int32_T c12_p_emlrt_marshallIn
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  int32_T c12_y;
  int32_T c12_i54;
  (void)chartInstance;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_i54, 1, 6, 0U, 0, 0U, 0);
  c12_y = c12_i54;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_b_sfEvent;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  int32_T c12_y;
  SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c12_b_sfEvent = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_p_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_sfEvent),
    &c12_thisId);
  sf_mex_destroy(&c12_b_sfEvent);
  *(int32_T *)c12_outData = c12_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

static const mxArray *c12_v_xv4_bus_io(void *chartInstanceVoid, void *c12_pData)
{
  const mxArray *c12_mxVal = NULL;
  c12_whl_vec4 c12_tmp;
  SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c12_mxVal = NULL;
  c12_tmp.fl = *(real_T *)&((char_T *)(c12_whl_vec4 *)c12_pData)[0];
  c12_tmp.fr = *(real_T *)&((char_T *)(c12_whl_vec4 *)c12_pData)[8];
  c12_tmp.rl = *(real_T *)&((char_T *)(c12_whl_vec4 *)c12_pData)[16];
  c12_tmp.rr = *(real_T *)&((char_T *)(c12_whl_vec4 *)c12_pData)[24];
  sf_mex_assign(&c12_mxVal, c12_sf_marshallOut(chartInstance, &c12_tmp), false);
  return c12_mxVal;
}

static const mxArray *c12_v_irp3_bus_io(void *chartInstanceVoid, void *c12_pData)
{
  const mxArray *c12_mxVal = NULL;
  c12_irp_vec3 c12_tmp;
  SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c12_mxVal = NULL;
  c12_tmp.x = *(real_T *)&((char_T *)(c12_irp_vec3 *)c12_pData)[0];
  c12_tmp.y = *(real_T *)&((char_T *)(c12_irp_vec3 *)c12_pData)[8];
  c12_tmp.rotz = *(real_T *)&((char_T *)(c12_irp_vec3 *)c12_pData)[16];
  sf_mex_assign(&c12_mxVal, c12_c_sf_marshallOut(chartInstance, &c12_tmp), false);
  return c12_mxVal;
}

static uint8_T c12_q_emlrt_marshallIn
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c12_b_is_active_c12_AllPurposeModel_TyreRelaxation, const char_T
   *c12_identifier)
{
  uint8_T c12_y;
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_r_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c12_b_is_active_c12_AllPurposeModel_TyreRelaxation), &c12_thisId);
  sf_mex_destroy(&c12_b_is_active_c12_AllPurposeModel_TyreRelaxation);
  return c12_y;
}

static uint8_T c12_r_emlrt_marshallIn
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  uint8_T c12_y;
  uint8_T c12_u0;
  (void)chartInstance;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_u0, 1, 3, 0U, 0, 0U, 0);
  c12_y = c12_u0;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_b_eml_xgemm(SFc12_AllPurposeModel_TyreRelaxationInstanceStruct
  *chartInstance, real_T c12_A[24], real_T c12_B[3], real_T c12_C[8])
{
  int32_T c12_i55;
  int32_T c12_i56;
  int32_T c12_i57;
  (void)chartInstance;
  for (c12_i55 = 0; c12_i55 < 8; c12_i55++) {
    c12_C[c12_i55] = 0.0;
    c12_i56 = 0;
    for (c12_i57 = 0; c12_i57 < 3; c12_i57++) {
      c12_C[c12_i55] += c12_A[c12_i56 + c12_i55] * c12_B[c12_i57];
      c12_i56 += 8;
    }
  }
}

static void init_dsm_address_info
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address
  (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  chartInstance->c12_v_xv4 = (c12_whl_vec4 *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c12_v_yv4 = (c12_whl_vec4 *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c12_v_irp3 = (c12_irp_vec3 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
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

void sf_c12_AllPurposeModel_TyreRelaxation_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3552889289U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2269091618U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4205061048U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(239237436U);
}

mxArray* sf_c12_AllPurposeModel_TyreRelaxation_get_post_codegen_info(void);
mxArray *sf_c12_AllPurposeModel_TyreRelaxation_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("iPZOHvxGs5S3V7Su2dlI9F");
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
      sf_c12_AllPurposeModel_TyreRelaxation_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c12_AllPurposeModel_TyreRelaxation_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c12_AllPurposeModel_TyreRelaxation_jit_fallback_info(void)
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

mxArray *sf_c12_AllPurposeModel_TyreRelaxation_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c12_AllPurposeModel_TyreRelaxation_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c12_AllPurposeModel_TyreRelaxation
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[16],T\"v_xv4\",},{M[1],M[17],T\"v_yv4\",},{M[8],M[0],T\"is_active_c12_AllPurposeModel_TyreRelaxation\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c12_AllPurposeModel_TyreRelaxation_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _AllPurposeModel_TyreRelaxationMachineNumber_,
           12,
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
          _SFD_SET_DATA_PROPS(0,2,0,1,"v_xv4");
          _SFD_SET_DATA_PROPS(1,2,0,1,"v_yv4");
          _SFD_SET_DATA_PROPS(2,1,1,0,"v_irp3");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,584);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_v_xv4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_v_xv4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_v_irp3_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_b_sf_marshallOut,(MexInFcnForType)
          c12_b_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c12_v_xv4);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c12_v_yv4);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c12_v_irp3);
        _SFD_SET_DATA_VALUE_PTR(3U, &chartInstance->c12_Par);
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
  return "qvk51PGzWaniLgr9OK9D7B";
}

static void sf_opaque_initialize_c12_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc12_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar)->S,
     0);
  initialize_params_c12_AllPurposeModel_TyreRelaxation
    ((SFc12_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
  initialize_c12_AllPurposeModel_TyreRelaxation
    ((SFc12_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c12_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  enable_c12_AllPurposeModel_TyreRelaxation
    ((SFc12_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c12_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  disable_c12_AllPurposeModel_TyreRelaxation
    ((SFc12_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c12_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  sf_gateway_c12_AllPurposeModel_TyreRelaxation
    ((SFc12_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c12_AllPurposeModel_TyreRelaxation
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c12_AllPurposeModel_TyreRelaxation
    ((SFc12_AllPurposeModel_TyreRelaxationInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c12_AllPurposeModel_TyreRelaxation(SimStruct*
  S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c12_AllPurposeModel_TyreRelaxation
    ((SFc12_AllPurposeModel_TyreRelaxationInstanceStruct*)
     chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c12_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc12_AllPurposeModel_TyreRelaxationInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_AllPurposeModel_TyreRelaxation_optimization_info();
    }

    finalize_c12_AllPurposeModel_TyreRelaxation
      ((SFc12_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc12_AllPurposeModel_TyreRelaxation
    ((SFc12_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c12_AllPurposeModel_TyreRelaxation(SimStruct *S)
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
    initialize_params_c12_AllPurposeModel_TyreRelaxation
      ((SFc12_AllPurposeModel_TyreRelaxationInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c12_AllPurposeModel_TyreRelaxation(SimStruct *S)
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
      12);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,12,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,12,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,12);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,12,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,12,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,12);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2184303224U));
  ssSetChecksum1(S,(2644304247U));
  ssSetChecksum2(S,(2626005083U));
  ssSetChecksum3(S,(1478518900U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c12_AllPurposeModel_TyreRelaxation(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c12_AllPurposeModel_TyreRelaxation(SimStruct *S)
{
  SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct *)utMalloc
    (sizeof(SFc12_AllPurposeModel_TyreRelaxationInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc12_AllPurposeModel_TyreRelaxationInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c12_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c12_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c12_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c12_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c12_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c12_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c12_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c12_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c12_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c12_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c12_AllPurposeModel_TyreRelaxation;
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

void c12_AllPurposeModel_TyreRelaxation_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c12_AllPurposeModel_TyreRelaxation(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c12_AllPurposeModel_TyreRelaxation(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c12_AllPurposeModel_TyreRelaxation(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c12_AllPurposeModel_TyreRelaxation_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
