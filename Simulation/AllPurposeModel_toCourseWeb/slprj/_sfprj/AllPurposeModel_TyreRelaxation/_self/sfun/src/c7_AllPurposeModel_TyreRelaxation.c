/* Include files */

#include <stddef.h>
#include "blas.h"
#include "AllPurposeModel_TyreRelaxation_sfun.h"
#include "c7_AllPurposeModel_TyreRelaxation.h"
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
static const char * c7_debug_family_names[22] = { "v_x", "v_y", "w_z", "lf",
  "lr", "w1", "w2", "w3", "w4", "T_irpv", "F_xv4_temp", "F_yv4_temp", "F_air",
  "beta", "derv_irp3_temp", "nargin", "nargout", "F_xv4", "F_yv4", "v_irp3",
  "Par", "derv_irp3" };

/* Function Declarations */
static void initialize_c7_AllPurposeModel_TyreRelaxation
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void initialize_params_c7_AllPurposeModel_TyreRelaxation
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void enable_c7_AllPurposeModel_TyreRelaxation
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void disable_c7_AllPurposeModel_TyreRelaxation
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void c7_update_debugger_state_c7_AllPurposeModel_TyreRelaxation
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c7_AllPurposeModel_TyreRelaxation
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void set_sim_state_c7_AllPurposeModel_TyreRelaxation
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c7_st);
static void finalize_c7_AllPurposeModel_TyreRelaxation
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void sf_gateway_c7_AllPurposeModel_TyreRelaxation
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void mdl_start_c7_AllPurposeModel_TyreRelaxation
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void c7_chartstep_c7_AllPurposeModel_TyreRelaxation
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void initSimStructsc7_AllPurposeModel_TyreRelaxation
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber, uint32_T c7_instanceNumber);
static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, void *c7_inData);
static c7_irp_vec3 c7_emlrt_marshallIn
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c7_b_derv_irp3, const char_T *c7_identifier);
static c7_irp_vec3 c7_b_emlrt_marshallIn
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static real_T c7_c_emlrt_marshallIn
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_b_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static void c7_d_emlrt_marshallIn
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId,
   c7_struct_iBlsPBO3AGnt69vDoTx5zD *c7_y);
static void c7_e_emlrt_marshallIn
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId,
   c7_struct_Nst2vGTExxHsg85EUOj9EH *c7_y);
static c7_struct_HhckT6rntEraqECYVIDvCC c7_f_emlrt_marshallIn
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_g_emlrt_marshallIn
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId,
   c7_struct_ZCmOWPuqBDw16FSOVVD00 *c7_y);
static void c7_h_emlrt_marshallIn
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId, real_T c7_y[4]);
static void c7_i_emlrt_marshallIn
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId,
   c7_struct_ZKAzdrl7umDGJoC14aoVKC *c7_y);
static void c7_j_emlrt_marshallIn
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId, real_T c7_y[3]);
static c7_struct_r4FNviKwHfdhB8nQjvQv9 c7_k_emlrt_marshallIn
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static c7_struct_Y9F1qlBi9AhssksPwemA4G c7_l_emlrt_marshallIn
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_c_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_d_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static void c7_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_e_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static void c7_m_emlrt_marshallIn
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId, real_T c7_y[3]);
static void c7_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_f_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static void c7_n_emlrt_marshallIn
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId, real_T c7_y[4]);
static void c7_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_g_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static void c7_o_emlrt_marshallIn
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId, real_T c7_y[24]);
static void c7_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static void c7_info_helper(const mxArray **c7_info);
static const mxArray *c7_emlrt_marshallOut(const char * c7_u);
static const mxArray *c7_b_emlrt_marshallOut(const uint32_T c7_u);
static real_T c7_abs(SFc7_AllPurposeModel_TyreRelaxationInstanceStruct
                     *chartInstance, real_T c7_x);
static real_T c7_atan2(SFc7_AllPurposeModel_TyreRelaxationInstanceStruct
  *chartInstance, real_T c7_y, real_T c7_x);
static void c7_diag(SFc7_AllPurposeModel_TyreRelaxationInstanceStruct
                    *chartInstance, real_T c7_v[3], real_T c7_d[9]);
static void c7_eml_scalar_eg(SFc7_AllPurposeModel_TyreRelaxationInstanceStruct
  *chartInstance);
static void c7_threshold(SFc7_AllPurposeModel_TyreRelaxationInstanceStruct
  *chartInstance);
static void c7_b_eml_scalar_eg(SFc7_AllPurposeModel_TyreRelaxationInstanceStruct
  *chartInstance);
static const mxArray *c7_h_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static int32_T c7_p_emlrt_marshallIn
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_F_xv4_bus_io(void *chartInstanceVoid, void *c7_pData);
static const mxArray *c7_v_irp3_bus_io(void *chartInstanceVoid, void *c7_pData);
static uint8_T c7_q_emlrt_marshallIn
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c7_b_is_active_c7_AllPurposeModel_TyreRelaxation, const char_T
   *c7_identifier);
static uint8_T c7_r_emlrt_marshallIn
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void init_dsm_address_info
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void init_simulink_io_address
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c7_AllPurposeModel_TyreRelaxation
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  chartInstance->c7_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c7_is_active_c7_AllPurposeModel_TyreRelaxation = 0U;
}

static void initialize_params_c7_AllPurposeModel_TyreRelaxation
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  const mxArray *c7_m0 = NULL;
  const mxArray *c7_mxField;
  const mxArray *c7_m1 = NULL;
  const mxArray *c7_b_mxField;
  c7_struct_iBlsPBO3AGnt69vDoTx5zD c7_r0;
  const mxArray *c7_m2 = NULL;
  const mxArray *c7_c_mxField;
  const mxArray *c7_m3 = NULL;
  const mxArray *c7_d_mxField;
  const mxArray *c7_m4 = NULL;
  const mxArray *c7_e_mxField;
  const mxArray *c7_m5 = NULL;
  const mxArray *c7_f_mxField;
  const mxArray *c7_m6 = NULL;
  const mxArray *c7_g_mxField;
  const mxArray *c7_m7 = NULL;
  const mxArray *c7_h_mxField;
  const mxArray *c7_m8 = NULL;
  const mxArray *c7_i_mxField;
  const mxArray *c7_m9 = NULL;
  const mxArray *c7_j_mxField;
  const mxArray *c7_m10 = NULL;
  const mxArray *c7_k_mxField;
  const mxArray *c7_m11 = NULL;
  const mxArray *c7_l_mxField;
  const mxArray *c7_m12 = NULL;
  const mxArray *c7_m_mxField;
  const mxArray *c7_m13 = NULL;
  const mxArray *c7_n_mxField;
  c7_m0 = sf_mex_get_sfun_param(chartInstance->S, 0, 1);
  c7_mxField = sf_mex_getfield(c7_m0, "Env", "Par", 0);
  c7_m1 = sf_mex_dup(c7_mxField);
  c7_b_mxField = sf_mex_getfield(c7_m1, "g", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_b_mxField), &c7_r0.Env.g, 1, 0, 0U, 0,
                      0U, 0);
  c7_b_mxField = sf_mex_getfield(c7_m1, "left1", "Par", 0);
  c7_m2 = sf_mex_dup(c7_b_mxField);
  c7_c_mxField = sf_mex_getfield(c7_m2, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_c_mxField), &c7_r0.Env.left1.x, 1, 0,
                      0U, 0, 0U, 0);
  c7_c_mxField = sf_mex_getfield(c7_m2, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_c_mxField), &c7_r0.Env.left1.y, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c7_m2);
  c7_b_mxField = sf_mex_getfield(c7_m1, "right1", "Par", 0);
  c7_m3 = sf_mex_dup(c7_b_mxField);
  c7_d_mxField = sf_mex_getfield(c7_m3, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_d_mxField), &c7_r0.Env.right1.x, 1, 0,
                      0U, 0, 0U, 0);
  c7_d_mxField = sf_mex_getfield(c7_m3, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_d_mxField), &c7_r0.Env.right1.y, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c7_m3);
  c7_b_mxField = sf_mex_getfield(c7_m1, "right2", "Par", 0);
  c7_m4 = sf_mex_dup(c7_b_mxField);
  c7_e_mxField = sf_mex_getfield(c7_m4, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_e_mxField), &c7_r0.Env.right2.x, 1, 0,
                      0U, 0, 0U, 0);
  c7_e_mxField = sf_mex_getfield(c7_m4, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_e_mxField), &c7_r0.Env.right2.y, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c7_m4);
  c7_b_mxField = sf_mex_getfield(c7_m1, "left2", "Par", 0);
  c7_m5 = sf_mex_dup(c7_b_mxField);
  c7_f_mxField = sf_mex_getfield(c7_m5, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_f_mxField), &c7_r0.Env.left2.x, 1, 0,
                      0U, 0, 0U, 0);
  c7_f_mxField = sf_mex_getfield(c7_m5, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_f_mxField), &c7_r0.Env.left2.y, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c7_m5);
  c7_b_mxField = sf_mex_getfield(c7_m1, "right3", "Par", 0);
  c7_m6 = sf_mex_dup(c7_b_mxField);
  c7_g_mxField = sf_mex_getfield(c7_m6, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_g_mxField), &c7_r0.Env.right3.x, 1, 0,
                      0U, 0, 0U, 0);
  c7_g_mxField = sf_mex_getfield(c7_m6, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_g_mxField), &c7_r0.Env.right3.y, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c7_m6);
  c7_b_mxField = sf_mex_getfield(c7_m1, "mu", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_b_mxField), &c7_r0.Env.mu, 1, 0, 0U,
                      0, 0U, 0);
  sf_mex_destroy(&c7_m1);
  c7_mxField = sf_mex_getfield(c7_m0, "Veh", "Par", 0);
  c7_m7 = sf_mex_dup(c7_mxField);
  c7_h_mxField = sf_mex_getfield(c7_m7, "m", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_h_mxField), &c7_r0.Veh.m, 1, 0, 0U, 0,
                      0U, 0);
  c7_h_mxField = sf_mex_getfield(c7_m7, "Jz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_h_mxField), &c7_r0.Veh.Jz, 1, 0, 0U,
                      0, 0U, 0);
  c7_h_mxField = sf_mex_getfield(c7_m7, "m_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_h_mxField), &c7_r0.Veh.m_sprung, 1, 0,
                      0U, 0, 0U, 0);
  c7_h_mxField = sf_mex_getfield(c7_m7, "Jx_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_h_mxField), &c7_r0.Veh.Jx_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c7_h_mxField = sf_mex_getfield(c7_m7, "Jy_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_h_mxField), &c7_r0.Veh.Jy_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c7_h_mxField = sf_mex_getfield(c7_m7, "lf", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_h_mxField), &c7_r0.Veh.lf, 1, 0, 0U,
                      0, 0U, 0);
  c7_h_mxField = sf_mex_getfield(c7_m7, "lr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_h_mxField), &c7_r0.Veh.lr, 1, 0, 0U,
                      0, 0U, 0);
  c7_h_mxField = sf_mex_getfield(c7_m7, "L", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_h_mxField), &c7_r0.Veh.L, 1, 0, 0U, 0,
                      0U, 0);
  c7_h_mxField = sf_mex_getfield(c7_m7, "TrackWidth", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_h_mxField), &c7_r0.Veh.TrackWidth, 1,
                      0, 0U, 0, 0U, 0);
  c7_h_mxField = sf_mex_getfield(c7_m7, "h", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_h_mxField), &c7_r0.Veh.h, 1, 0, 0U, 0,
                      0U, 0);
  c7_h_mxField = sf_mex_getfield(c7_m7, "HalfRohACd", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_h_mxField), &c7_r0.Veh.HalfRohACd, 1,
                      0, 0U, 0, 0U, 0);
  c7_h_mxField = sf_mex_getfield(c7_m7, "F_z4_static", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_h_mxField), c7_r0.Veh.F_z4_static, 1,
                      0, 0U, 1, 0U, 2, 1, 4);
  c7_h_mxField = sf_mex_getfield(c7_m7, "Rw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_h_mxField), &c7_r0.Veh.Rw, 1, 0, 0U,
                      0, 0U, 0);
  c7_h_mxField = sf_mex_getfield(c7_m7, "r_long", "Par", 0);
  c7_m8 = sf_mex_dup(c7_h_mxField);
  c7_i_mxField = sf_mex_getfield(c7_m8, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_i_mxField), c7_r0.Veh.r_long.fl, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  c7_i_mxField = sf_mex_getfield(c7_m8, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_i_mxField), c7_r0.Veh.r_long.fr, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  c7_i_mxField = sf_mex_getfield(c7_m8, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_i_mxField), c7_r0.Veh.r_long.rl, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  c7_i_mxField = sf_mex_getfield(c7_m8, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_i_mxField), c7_r0.Veh.r_long.rr, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c7_m8);
  c7_h_mxField = sf_mex_getfield(c7_m7, "r_lat", "Par", 0);
  c7_m9 = sf_mex_dup(c7_h_mxField);
  c7_j_mxField = sf_mex_getfield(c7_m9, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_j_mxField), c7_r0.Veh.r_lat.fl, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  c7_j_mxField = sf_mex_getfield(c7_m9, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_j_mxField), c7_r0.Veh.r_lat.fr, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  c7_j_mxField = sf_mex_getfield(c7_m9, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_j_mxField), c7_r0.Veh.r_lat.rl, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  c7_j_mxField = sf_mex_getfield(c7_m9, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_j_mxField), c7_r0.Veh.r_lat.rr, 1, 0,
                      0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c7_m9);
  c7_h_mxField = sf_mex_getfield(c7_m7, "r_lever", "Par", 0);
  c7_m10 = sf_mex_dup(c7_h_mxField);
  c7_k_mxField = sf_mex_getfield(c7_m10, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_k_mxField), c7_r0.Veh.r_lever.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c7_k_mxField = sf_mex_getfield(c7_m10, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_k_mxField), c7_r0.Veh.r_lever.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c7_k_mxField = sf_mex_getfield(c7_m10, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_k_mxField), c7_r0.Veh.r_lever.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c7_k_mxField = sf_mex_getfield(c7_m10, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_k_mxField), c7_r0.Veh.r_lever.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c7_m10);
  c7_h_mxField = sf_mex_getfield(c7_m7, "r_pivot", "Par", 0);
  c7_m11 = sf_mex_dup(c7_h_mxField);
  c7_l_mxField = sf_mex_getfield(c7_m11, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_l_mxField), c7_r0.Veh.r_pivot.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c7_l_mxField = sf_mex_getfield(c7_m11, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_l_mxField), c7_r0.Veh.r_pivot.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c7_l_mxField = sf_mex_getfield(c7_m11, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_l_mxField), c7_r0.Veh.r_pivot.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c7_l_mxField = sf_mex_getfield(c7_m11, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_l_mxField), c7_r0.Veh.r_pivot.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c7_m11);
  c7_h_mxField = sf_mex_getfield(c7_m7, "cw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_h_mxField), &c7_r0.Veh.cw, 1, 0, 0U,
                      0, 0U, 0);
  c7_h_mxField = sf_mex_getfield(c7_m7, "carb_f", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_h_mxField), &c7_r0.Veh.carb_f, 1, 0,
                      0U, 0, 0U, 0);
  c7_h_mxField = sf_mex_getfield(c7_m7, "carb_r", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_h_mxField), &c7_r0.Veh.carb_r, 1, 0,
                      0U, 0, 0U, 0);
  c7_h_mxField = sf_mex_getfield(c7_m7, "dw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_h_mxField), &c7_r0.Veh.dw, 1, 0, 0U,
                      0, 0U, 0);
  c7_h_mxField = sf_mex_getfield(c7_m7, "Jw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_h_mxField), &c7_r0.Veh.Jw, 1, 0, 0U,
                      0, 0U, 0);
  c7_h_mxField = sf_mex_getfield(c7_m7, "C0", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_h_mxField), &c7_r0.Veh.C0, 1, 0, 0U,
                      0, 0U, 0);
  c7_h_mxField = sf_mex_getfield(c7_m7, "RelaxLength", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_h_mxField), &c7_r0.Veh.RelaxLength, 1,
                      0, 0U, 0, 0U, 0);
  c7_h_mxField = sf_mex_getfield(c7_m7, "RRC", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_h_mxField), &c7_r0.Veh.RRC, 1, 0, 0U,
                      0, 0U, 0);
  c7_h_mxField = sf_mex_getfield(c7_m7, "Pmax", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_h_mxField), &c7_r0.Veh.Pmax, 1, 0, 0U,
                      0, 0U, 0);
  c7_h_mxField = sf_mex_getfield(c7_m7, "PropDistrFrnt", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_h_mxField), &c7_r0.Veh.PropDistrFrnt,
                      1, 0, 0U, 0, 0U, 0);
  c7_h_mxField = sf_mex_getfield(c7_m7, "BrkDistrFrnt", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_h_mxField), &c7_r0.Veh.BrkDistrFrnt,
                      1, 0, 0U, 0, 0U, 0);
  c7_h_mxField = sf_mex_getfield(c7_m7, "SteRatio", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_h_mxField), &c7_r0.Veh.SteRatio, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c7_m7);
  c7_mxField = sf_mex_getfield(c7_m0, "Drvr", "Par", 0);
  c7_m12 = sf_mex_dup(c7_mxField);
  c7_m_mxField = sf_mex_getfield(c7_m12, "v_set", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_m_mxField), &c7_r0.Drvr.v_set, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c7_m12);
  c7_mxField = sf_mex_getfield(c7_m0, "Init", "Par", 0);
  c7_m13 = sf_mex_dup(c7_mxField);
  c7_n_mxField = sf_mex_getfield(c7_m13, "v_x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_n_mxField), &c7_r0.Init.v_x, 1, 0, 0U,
                      0, 0U, 0);
  c7_n_mxField = sf_mex_getfield(c7_m13, "F_fz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_n_mxField), &c7_r0.Init.F_fz, 1, 0,
                      0U, 0, 0U, 0);
  c7_n_mxField = sf_mex_getfield(c7_m13, "F_rz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c7_n_mxField), &c7_r0.Init.F_rz, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c7_m13);
  sf_mex_destroy(&c7_m0);
  chartInstance->c7_Par = c7_r0;
}

static void enable_c7_AllPurposeModel_TyreRelaxation
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c7_AllPurposeModel_TyreRelaxation
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c7_update_debugger_state_c7_AllPurposeModel_TyreRelaxation
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c7_AllPurposeModel_TyreRelaxation
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  const mxArray *c7_st;
  const mxArray *c7_y = NULL;
  const mxArray *c7_b_y = NULL;
  real_T c7_u;
  const mxArray *c7_c_y = NULL;
  real_T c7_b_u;
  const mxArray *c7_d_y = NULL;
  real_T c7_c_u;
  const mxArray *c7_e_y = NULL;
  uint8_T c7_hoistedGlobal;
  uint8_T c7_d_u;
  const mxArray *c7_f_y = NULL;
  c7_st = NULL;
  c7_st = NULL;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_createcellmatrix(2, 1), false);
  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c7_u = *(real_T *)&((char_T *)chartInstance->c7_derv_irp3)[0];
  c7_c_y = NULL;
  sf_mex_assign(&c7_c_y, sf_mex_create("y", &c7_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c7_b_y, c7_c_y, "x", "x", 0);
  c7_b_u = *(real_T *)&((char_T *)chartInstance->c7_derv_irp3)[8];
  c7_d_y = NULL;
  sf_mex_assign(&c7_d_y, sf_mex_create("y", &c7_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c7_b_y, c7_d_y, "y", "y", 0);
  c7_c_u = *(real_T *)&((char_T *)chartInstance->c7_derv_irp3)[16];
  c7_e_y = NULL;
  sf_mex_assign(&c7_e_y, sf_mex_create("y", &c7_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c7_b_y, c7_e_y, "rotz", "rotz", 0);
  sf_mex_setcell(c7_y, 0, c7_b_y);
  c7_hoistedGlobal =
    chartInstance->c7_is_active_c7_AllPurposeModel_TyreRelaxation;
  c7_d_u = c7_hoistedGlobal;
  c7_f_y = NULL;
  sf_mex_assign(&c7_f_y, sf_mex_create("y", &c7_d_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c7_y, 1, c7_f_y);
  sf_mex_assign(&c7_st, c7_y, false);
  return c7_st;
}

static void set_sim_state_c7_AllPurposeModel_TyreRelaxation
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c7_st)
{
  const mxArray *c7_u;
  c7_irp_vec3 c7_r1;
  chartInstance->c7_doneDoubleBufferReInit = true;
  c7_u = sf_mex_dup(c7_st);
  c7_r1 = c7_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c7_u, 0)),
    "derv_irp3");
  *(real_T *)&((char_T *)chartInstance->c7_derv_irp3)[0] = c7_r1.x;
  *(real_T *)&((char_T *)chartInstance->c7_derv_irp3)[8] = c7_r1.y;
  *(real_T *)&((char_T *)chartInstance->c7_derv_irp3)[16] = c7_r1.rotz;
  chartInstance->c7_is_active_c7_AllPurposeModel_TyreRelaxation =
    c7_q_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c7_u, 1)),
    "is_active_c7_AllPurposeModel_TyreRelaxation");
  sf_mex_destroy(&c7_u);
  c7_update_debugger_state_c7_AllPurposeModel_TyreRelaxation(chartInstance);
  sf_mex_destroy(&c7_st);
}

static void finalize_c7_AllPurposeModel_TyreRelaxation
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c7_AllPurposeModel_TyreRelaxation
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
  chartInstance->c7_sfEvent = CALL_EVENT;
  c7_chartstep_c7_AllPurposeModel_TyreRelaxation(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_AllPurposeModel_TyreRelaxationMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void mdl_start_c7_AllPurposeModel_TyreRelaxation
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c7_chartstep_c7_AllPurposeModel_TyreRelaxation
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  c7_whl_vec4 c7_b_F_xv4;
  c7_whl_vec4 c7_b_F_yv4;
  c7_irp_vec3 c7_b_v_irp3;
  c7_struct_iBlsPBO3AGnt69vDoTx5zD c7_b_Par;
  uint32_T c7_debug_family_var_map[22];
  real_T c7_v_x;
  real_T c7_v_y;
  real_T c7_w_z;
  real_T c7_lf;
  real_T c7_lr;
  real_T c7_w1;
  real_T c7_w2;
  real_T c7_w3;
  real_T c7_w4;
  real_T c7_T_irpv[24];
  real_T c7_F_xv4_temp[4];
  real_T c7_F_yv4_temp[4];
  real_T c7_F_air;
  real_T c7_beta;
  real_T c7_derv_irp3_temp[3];
  real_T c7_nargin = 4.0;
  real_T c7_nargout = 1.0;
  c7_irp_vec3 c7_b_derv_irp3;
  real_T c7_A;
  real_T c7_x;
  real_T c7_b_x;
  real_T c7_c_x;
  int32_T c7_i0;
  int32_T c7_i1;
  static real_T c7_dv0[8] = { 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0 };

  int32_T c7_i2;
  int32_T c7_i3;
  static real_T c7_dv1[8] = { 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0 };

  real_T c7_B;
  real_T c7_y;
  real_T c7_b_y;
  real_T c7_c_y;
  real_T c7_d_y;
  real_T c7_b_B;
  real_T c7_e_y;
  real_T c7_f_y;
  real_T c7_g_y;
  real_T c7_h_y;
  real_T c7_c_B;
  real_T c7_i_y;
  real_T c7_j_y;
  real_T c7_k_y;
  real_T c7_l_y;
  int32_T c7_i4;
  real_T c7_a[24];
  int32_T c7_i5;
  real_T c7_b[8];
  int32_T c7_i6;
  int32_T c7_i7;
  real_T c7_m_y[3];
  int32_T c7_i8;
  int32_T c7_i9;
  real_T c7_d_x;
  real_T c7_e_x;
  real_T c7_f_x;
  real_T c7_g_x;
  real_T c7_b_a[3];
  real_T c7_b_b;
  int32_T c7_i10;
  real_T c7_n_y[3];
  real_T c7_c_a[9];
  int32_T c7_i11;
  int32_T c7_i12;
  int32_T c7_i13;
  int32_T c7_i14;
  real_T c7_b_v_y[3];
  int32_T c7_i15;
  c7_irp_vec3 c7_r2;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
  c7_b_F_xv4.fl = *(real_T *)&((char_T *)chartInstance->c7_F_xv4)[0];
  c7_b_F_xv4.fr = *(real_T *)&((char_T *)chartInstance->c7_F_xv4)[8];
  c7_b_F_xv4.rl = *(real_T *)&((char_T *)chartInstance->c7_F_xv4)[16];
  c7_b_F_xv4.rr = *(real_T *)&((char_T *)chartInstance->c7_F_xv4)[24];
  c7_b_F_yv4.fl = *(real_T *)&((char_T *)chartInstance->c7_F_yv4)[0];
  c7_b_F_yv4.fr = *(real_T *)&((char_T *)chartInstance->c7_F_yv4)[8];
  c7_b_F_yv4.rl = *(real_T *)&((char_T *)chartInstance->c7_F_yv4)[16];
  c7_b_F_yv4.rr = *(real_T *)&((char_T *)chartInstance->c7_F_yv4)[24];
  c7_b_v_irp3.x = *(real_T *)&((char_T *)chartInstance->c7_v_irp3)[0];
  c7_b_v_irp3.y = *(real_T *)&((char_T *)chartInstance->c7_v_irp3)[8];
  c7_b_v_irp3.rotz = *(real_T *)&((char_T *)chartInstance->c7_v_irp3)[16];
  c7_b_Par = chartInstance->c7_Par;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 22U, 22U, c7_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_v_x, 0U, c7_d_sf_marshallOut,
    c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_v_y, 1U, c7_d_sf_marshallOut,
    c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_w_z, 2U, c7_d_sf_marshallOut,
    c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_lf, 3U, c7_d_sf_marshallOut,
    c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_lr, 4U, c7_d_sf_marshallOut,
    c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_w1, 5U, c7_d_sf_marshallOut,
    c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_w2, 6U, c7_d_sf_marshallOut,
    c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_w3, 7U, c7_d_sf_marshallOut,
    c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_w4, 8U, c7_d_sf_marshallOut,
    c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_T_irpv, 9U, c7_g_sf_marshallOut,
    c7_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_F_xv4_temp, 10U, c7_f_sf_marshallOut,
    c7_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_F_yv4_temp, 11U, c7_f_sf_marshallOut,
    c7_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_F_air, 12U, c7_d_sf_marshallOut,
    c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_beta, 13U, c7_d_sf_marshallOut,
    c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_derv_irp3_temp, 14U,
    c7_e_sf_marshallOut, c7_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 15U, c7_d_sf_marshallOut,
    c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 16U, c7_d_sf_marshallOut,
    c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_b_F_xv4, 17U, c7_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_b_F_yv4, 18U, c7_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_b_v_irp3, 19U, c7_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_Par, 20U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_derv_irp3, 21U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 5);
  c7_v_x = c7_b_v_irp3.x;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 6);
  c7_v_y = c7_b_v_irp3.y;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_w_z = c7_b_v_irp3.rotz;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 9);
  c7_lf = c7_b_Par.Veh.lf;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 10);
  c7_lr = c7_b_Par.Veh.lr;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 12);
  c7_A = c7_b_Par.Veh.TrackWidth;
  c7_x = c7_A;
  c7_b_x = c7_x;
  c7_c_x = c7_b_x;
  c7_w1 = c7_c_x / 2.0;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 13);
  c7_w2 = -c7_w1;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 14);
  c7_w3 = c7_w1;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 15);
  c7_w4 = -c7_w3;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 17);
  c7_i0 = 0;
  for (c7_i1 = 0; c7_i1 < 8; c7_i1++) {
    c7_T_irpv[c7_i0] = c7_dv0[c7_i1];
    c7_i0 += 3;
  }

  c7_i2 = 0;
  for (c7_i3 = 0; c7_i3 < 8; c7_i3++) {
    c7_T_irpv[c7_i2 + 1] = c7_dv1[c7_i3];
    c7_i2 += 3;
  }

  c7_T_irpv[2] = -c7_w1;
  c7_T_irpv[5] = -c7_w2;
  c7_T_irpv[8] = -c7_w3;
  c7_T_irpv[11] = -c7_w4;
  c7_T_irpv[14] = c7_lf;
  c7_T_irpv[17] = c7_lf;
  c7_T_irpv[20] = c7_lr;
  c7_T_irpv[23] = c7_lr;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 21);
  c7_F_xv4_temp[0] = c7_b_F_xv4.fl;
  c7_F_xv4_temp[1] = c7_b_F_xv4.fr;
  c7_F_xv4_temp[2] = c7_b_F_xv4.rl;
  c7_F_xv4_temp[3] = c7_b_F_xv4.rr;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 22);
  c7_F_yv4_temp[0] = c7_b_F_yv4.fl;
  c7_F_yv4_temp[1] = c7_b_F_yv4.fr;
  c7_F_yv4_temp[2] = c7_b_F_yv4.rl;
  c7_F_yv4_temp[3] = c7_b_F_yv4.rr;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 24);
  c7_F_air = c7_b_Par.Veh.HalfRohACd * c7_abs(chartInstance, c7_v_x) * c7_v_x;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 25);
  c7_beta = c7_atan2(chartInstance, c7_v_y, c7_v_x);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 27);
  c7_B = c7_b_Par.Veh.m;
  c7_y = c7_B;
  c7_b_y = c7_y;
  c7_c_y = c7_b_y;
  c7_d_y = 1.0 / c7_c_y;
  c7_b_B = c7_b_Par.Veh.m;
  c7_e_y = c7_b_B;
  c7_f_y = c7_e_y;
  c7_g_y = c7_f_y;
  c7_h_y = 1.0 / c7_g_y;
  c7_c_B = c7_b_Par.Veh.Jz;
  c7_i_y = c7_c_B;
  c7_j_y = c7_i_y;
  c7_k_y = c7_j_y;
  c7_l_y = 1.0 / c7_k_y;
  for (c7_i4 = 0; c7_i4 < 24; c7_i4++) {
    c7_a[c7_i4] = c7_T_irpv[c7_i4];
  }

  for (c7_i5 = 0; c7_i5 < 4; c7_i5++) {
    c7_b[c7_i5] = c7_F_xv4_temp[c7_i5];
  }

  for (c7_i6 = 0; c7_i6 < 4; c7_i6++) {
    c7_b[c7_i6 + 4] = c7_F_yv4_temp[c7_i6];
  }

  c7_eml_scalar_eg(chartInstance);
  c7_eml_scalar_eg(chartInstance);
  c7_threshold(chartInstance);
  for (c7_i7 = 0; c7_i7 < 3; c7_i7++) {
    c7_m_y[c7_i7] = 0.0;
    c7_i8 = 0;
    for (c7_i9 = 0; c7_i9 < 8; c7_i9++) {
      c7_m_y[c7_i7] += c7_a[c7_i8 + c7_i7] * c7_b[c7_i9];
      c7_i8 += 3;
    }
  }

  c7_d_x = c7_beta;
  c7_e_x = c7_d_x;
  c7_e_x = muDoubleScalarSin(c7_e_x);
  c7_f_x = c7_beta;
  c7_g_x = c7_f_x;
  c7_g_x = muDoubleScalarSin(c7_g_x);
  c7_b_a[0] = c7_e_x;
  c7_b_a[1] = c7_g_x;
  c7_b_a[2] = 0.0;
  c7_b_b = c7_F_air;
  for (c7_i10 = 0; c7_i10 < 3; c7_i10++) {
    c7_b_a[c7_i10] *= c7_b_b;
  }

  c7_n_y[0] = c7_d_y;
  c7_n_y[1] = c7_h_y;
  c7_n_y[2] = c7_l_y;
  c7_diag(chartInstance, c7_n_y, c7_c_a);
  for (c7_i11 = 0; c7_i11 < 3; c7_i11++) {
    c7_m_y[c7_i11] -= c7_b_a[c7_i11];
  }

  c7_b_eml_scalar_eg(chartInstance);
  c7_b_eml_scalar_eg(chartInstance);
  c7_threshold(chartInstance);
  for (c7_i12 = 0; c7_i12 < 3; c7_i12++) {
    c7_b_a[c7_i12] = 0.0;
    c7_i13 = 0;
    for (c7_i14 = 0; c7_i14 < 3; c7_i14++) {
      c7_b_a[c7_i12] += c7_c_a[c7_i13 + c7_i12] * c7_m_y[c7_i14];
      c7_i13 += 3;
    }
  }

  c7_b_v_y[0] = -c7_v_y * c7_w_z;
  c7_b_v_y[1] = c7_v_x * c7_w_z;
  c7_b_v_y[2] = 0.0;
  for (c7_i15 = 0; c7_i15 < 3; c7_i15++) {
    c7_derv_irp3_temp[c7_i15] = c7_b_a[c7_i15] - c7_b_v_y[c7_i15];
  }

  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 29);
  c7_r2.x = c7_derv_irp3_temp[0];
  c7_r2.y = c7_derv_irp3_temp[1];
  c7_r2.rotz = c7_derv_irp3_temp[2];
  c7_b_derv_irp3 = c7_r2;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, -29);
  _SFD_SYMBOL_SCOPE_POP();
  *(real_T *)&((char_T *)chartInstance->c7_derv_irp3)[0] = c7_b_derv_irp3.x;
  *(real_T *)&((char_T *)chartInstance->c7_derv_irp3)[8] = c7_b_derv_irp3.y;
  *(real_T *)&((char_T *)chartInstance->c7_derv_irp3)[16] = c7_b_derv_irp3.rotz;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
}

static void initSimStructsc7_AllPurposeModel_TyreRelaxation
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber, uint32_T c7_instanceNumber)
{
  (void)c7_machineNumber;
  (void)c7_chartNumber;
  (void)c7_instanceNumber;
}

static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, void *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  c7_irp_vec3 c7_u;
  const mxArray *c7_y = NULL;
  real_T c7_b_u;
  const mxArray *c7_b_y = NULL;
  real_T c7_c_u;
  const mxArray *c7_c_y = NULL;
  real_T c7_d_u;
  const mxArray *c7_d_y = NULL;
  SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(c7_irp_vec3 *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c7_b_u = c7_u.x;
  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", &c7_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c7_y, c7_b_y, "x", "x", 0);
  c7_c_u = c7_u.y;
  c7_c_y = NULL;
  sf_mex_assign(&c7_c_y, sf_mex_create("y", &c7_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c7_y, c7_c_y, "y", "y", 0);
  c7_d_u = c7_u.rotz;
  c7_d_y = NULL;
  sf_mex_assign(&c7_d_y, sf_mex_create("y", &c7_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c7_y, c7_d_y, "rotz", "rotz", 0);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static c7_irp_vec3 c7_emlrt_marshallIn
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c7_b_derv_irp3, const char_T *c7_identifier)
{
  c7_irp_vec3 c7_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_derv_irp3),
    &c7_thisId);
  sf_mex_destroy(&c7_b_derv_irp3);
  return c7_y;
}

static c7_irp_vec3 c7_b_emlrt_marshallIn
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  c7_irp_vec3 c7_y;
  emlrtMsgIdentifier c7_thisId;
  static const char * c7_fieldNames[3] = { "x", "y", "rotz" };

  c7_thisId.fParent = c7_parentId;
  sf_mex_check_struct(c7_parentId, c7_u, 3, c7_fieldNames, 0U, NULL);
  c7_thisId.fIdentifier = "x";
  c7_y.x = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c7_u,
    "x", "x", 0)), &c7_thisId);
  c7_thisId.fIdentifier = "y";
  c7_y.y = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c7_u,
    "y", "y", 0)), &c7_thisId);
  c7_thisId.fIdentifier = "rotz";
  c7_y.rotz = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c7_u, "rotz", "rotz", 0)), &c7_thisId);
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static real_T c7_c_emlrt_marshallIn
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  real_T c7_y;
  real_T c7_d0;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_d0, 1, 0, 0U, 0, 0U, 0);
  c7_y = c7_d0;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_b_derv_irp3;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  c7_irp_vec3 c7_y;
  SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c7_b_derv_irp3 = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_derv_irp3),
    &c7_thisId);
  sf_mex_destroy(&c7_b_derv_irp3);
  *(c7_irp_vec3 *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_b_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData;
  c7_struct_iBlsPBO3AGnt69vDoTx5zD c7_u;
  const mxArray *c7_y = NULL;
  c7_struct_Nst2vGTExxHsg85EUOj9EH c7_b_u;
  const mxArray *c7_b_y = NULL;
  real_T c7_c_u;
  const mxArray *c7_c_y = NULL;
  c7_struct_HhckT6rntEraqECYVIDvCC c7_d_u;
  const mxArray *c7_d_y = NULL;
  real_T c7_e_u;
  const mxArray *c7_e_y = NULL;
  real_T c7_f_u;
  const mxArray *c7_f_y = NULL;
  const mxArray *c7_g_y = NULL;
  real_T c7_g_u;
  const mxArray *c7_h_y = NULL;
  real_T c7_h_u;
  const mxArray *c7_i_y = NULL;
  const mxArray *c7_j_y = NULL;
  real_T c7_i_u;
  const mxArray *c7_k_y = NULL;
  real_T c7_j_u;
  const mxArray *c7_l_y = NULL;
  const mxArray *c7_m_y = NULL;
  real_T c7_k_u;
  const mxArray *c7_n_y = NULL;
  real_T c7_l_u;
  const mxArray *c7_o_y = NULL;
  const mxArray *c7_p_y = NULL;
  real_T c7_m_u;
  const mxArray *c7_q_y = NULL;
  real_T c7_n_u;
  const mxArray *c7_r_y = NULL;
  real_T c7_o_u;
  const mxArray *c7_s_y = NULL;
  c7_struct_ZCmOWPuqBDw16FSOVVD00 c7_p_u;
  const mxArray *c7_t_y = NULL;
  real_T c7_q_u;
  const mxArray *c7_u_y = NULL;
  real_T c7_r_u;
  const mxArray *c7_v_y = NULL;
  real_T c7_s_u;
  const mxArray *c7_w_y = NULL;
  real_T c7_t_u;
  const mxArray *c7_x_y = NULL;
  real_T c7_u_u;
  const mxArray *c7_y_y = NULL;
  real_T c7_v_u;
  const mxArray *c7_ab_y = NULL;
  real_T c7_w_u;
  const mxArray *c7_bb_y = NULL;
  real_T c7_x_u;
  const mxArray *c7_cb_y = NULL;
  real_T c7_y_u;
  const mxArray *c7_db_y = NULL;
  real_T c7_ab_u;
  const mxArray *c7_eb_y = NULL;
  real_T c7_bb_u;
  const mxArray *c7_fb_y = NULL;
  int32_T c7_i16;
  real_T c7_cb_u[4];
  const mxArray *c7_gb_y = NULL;
  real_T c7_db_u;
  const mxArray *c7_hb_y = NULL;
  c7_struct_ZKAzdrl7umDGJoC14aoVKC c7_eb_u;
  const mxArray *c7_ib_y = NULL;
  int32_T c7_i17;
  real_T c7_fb_u[3];
  const mxArray *c7_jb_y = NULL;
  int32_T c7_i18;
  real_T c7_gb_u[3];
  const mxArray *c7_kb_y = NULL;
  int32_T c7_i19;
  real_T c7_hb_u[3];
  const mxArray *c7_lb_y = NULL;
  int32_T c7_i20;
  real_T c7_ib_u[3];
  const mxArray *c7_mb_y = NULL;
  const mxArray *c7_nb_y = NULL;
  int32_T c7_i21;
  real_T c7_jb_u[3];
  const mxArray *c7_ob_y = NULL;
  int32_T c7_i22;
  real_T c7_kb_u[3];
  const mxArray *c7_pb_y = NULL;
  int32_T c7_i23;
  real_T c7_lb_u[3];
  const mxArray *c7_qb_y = NULL;
  int32_T c7_i24;
  real_T c7_mb_u[3];
  const mxArray *c7_rb_y = NULL;
  const mxArray *c7_sb_y = NULL;
  int32_T c7_i25;
  real_T c7_nb_u[3];
  const mxArray *c7_tb_y = NULL;
  int32_T c7_i26;
  real_T c7_ob_u[3];
  const mxArray *c7_ub_y = NULL;
  int32_T c7_i27;
  real_T c7_pb_u[3];
  const mxArray *c7_vb_y = NULL;
  int32_T c7_i28;
  real_T c7_qb_u[3];
  const mxArray *c7_wb_y = NULL;
  const mxArray *c7_xb_y = NULL;
  int32_T c7_i29;
  real_T c7_rb_u[3];
  const mxArray *c7_yb_y = NULL;
  int32_T c7_i30;
  real_T c7_sb_u[3];
  const mxArray *c7_ac_y = NULL;
  int32_T c7_i31;
  real_T c7_tb_u[3];
  const mxArray *c7_bc_y = NULL;
  int32_T c7_i32;
  real_T c7_ub_u[3];
  const mxArray *c7_cc_y = NULL;
  real_T c7_vb_u;
  const mxArray *c7_dc_y = NULL;
  real_T c7_wb_u;
  const mxArray *c7_ec_y = NULL;
  real_T c7_xb_u;
  const mxArray *c7_fc_y = NULL;
  real_T c7_yb_u;
  const mxArray *c7_gc_y = NULL;
  real_T c7_ac_u;
  const mxArray *c7_hc_y = NULL;
  real_T c7_bc_u;
  const mxArray *c7_ic_y = NULL;
  real_T c7_cc_u;
  const mxArray *c7_jc_y = NULL;
  real_T c7_dc_u;
  const mxArray *c7_kc_y = NULL;
  real_T c7_ec_u;
  const mxArray *c7_lc_y = NULL;
  real_T c7_fc_u;
  const mxArray *c7_mc_y = NULL;
  real_T c7_gc_u;
  const mxArray *c7_nc_y = NULL;
  real_T c7_hc_u;
  const mxArray *c7_oc_y = NULL;
  c7_struct_r4FNviKwHfdhB8nQjvQv9 c7_ic_u;
  const mxArray *c7_pc_y = NULL;
  real_T c7_jc_u;
  const mxArray *c7_qc_y = NULL;
  c7_struct_Y9F1qlBi9AhssksPwemA4G c7_kc_u;
  const mxArray *c7_rc_y = NULL;
  real_T c7_lc_u;
  const mxArray *c7_sc_y = NULL;
  real_T c7_mc_u;
  const mxArray *c7_tc_y = NULL;
  real_T c7_nc_u;
  const mxArray *c7_uc_y = NULL;
  SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_mxArrayOutData = NULL;
  c7_u = *(c7_struct_iBlsPBO3AGnt69vDoTx5zD *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c7_b_u = c7_u.Env;
  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c7_c_u = c7_b_u.g;
  c7_c_y = NULL;
  sf_mex_assign(&c7_c_y, sf_mex_create("y", &c7_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c7_b_y, c7_c_y, "g", "g", 0);
  c7_d_u = c7_b_u.left1;
  c7_d_y = NULL;
  sf_mex_assign(&c7_d_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c7_e_u = c7_d_u.x;
  c7_e_y = NULL;
  sf_mex_assign(&c7_e_y, sf_mex_create("y", &c7_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c7_d_y, c7_e_y, "x", "x", 0);
  c7_f_u = c7_d_u.y;
  c7_f_y = NULL;
  sf_mex_assign(&c7_f_y, sf_mex_create("y", &c7_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c7_d_y, c7_f_y, "y", "y", 0);
  sf_mex_addfield(c7_b_y, c7_d_y, "left1", "left1", 0);
  c7_d_u = c7_b_u.right1;
  c7_g_y = NULL;
  sf_mex_assign(&c7_g_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c7_g_u = c7_d_u.x;
  c7_h_y = NULL;
  sf_mex_assign(&c7_h_y, sf_mex_create("y", &c7_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c7_g_y, c7_h_y, "x", "x", 0);
  c7_h_u = c7_d_u.y;
  c7_i_y = NULL;
  sf_mex_assign(&c7_i_y, sf_mex_create("y", &c7_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c7_g_y, c7_i_y, "y", "y", 0);
  sf_mex_addfield(c7_b_y, c7_g_y, "right1", "right1", 0);
  c7_d_u = c7_b_u.right2;
  c7_j_y = NULL;
  sf_mex_assign(&c7_j_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c7_i_u = c7_d_u.x;
  c7_k_y = NULL;
  sf_mex_assign(&c7_k_y, sf_mex_create("y", &c7_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c7_j_y, c7_k_y, "x", "x", 0);
  c7_j_u = c7_d_u.y;
  c7_l_y = NULL;
  sf_mex_assign(&c7_l_y, sf_mex_create("y", &c7_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c7_j_y, c7_l_y, "y", "y", 0);
  sf_mex_addfield(c7_b_y, c7_j_y, "right2", "right2", 0);
  c7_d_u = c7_b_u.left2;
  c7_m_y = NULL;
  sf_mex_assign(&c7_m_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c7_k_u = c7_d_u.x;
  c7_n_y = NULL;
  sf_mex_assign(&c7_n_y, sf_mex_create("y", &c7_k_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c7_m_y, c7_n_y, "x", "x", 0);
  c7_l_u = c7_d_u.y;
  c7_o_y = NULL;
  sf_mex_assign(&c7_o_y, sf_mex_create("y", &c7_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c7_m_y, c7_o_y, "y", "y", 0);
  sf_mex_addfield(c7_b_y, c7_m_y, "left2", "left2", 0);
  c7_d_u = c7_b_u.right3;
  c7_p_y = NULL;
  sf_mex_assign(&c7_p_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c7_m_u = c7_d_u.x;
  c7_q_y = NULL;
  sf_mex_assign(&c7_q_y, sf_mex_create("y", &c7_m_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c7_p_y, c7_q_y, "x", "x", 0);
  c7_n_u = c7_d_u.y;
  c7_r_y = NULL;
  sf_mex_assign(&c7_r_y, sf_mex_create("y", &c7_n_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c7_p_y, c7_r_y, "y", "y", 0);
  sf_mex_addfield(c7_b_y, c7_p_y, "right3", "right3", 0);
  c7_o_u = c7_b_u.mu;
  c7_s_y = NULL;
  sf_mex_assign(&c7_s_y, sf_mex_create("y", &c7_o_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c7_b_y, c7_s_y, "mu", "mu", 0);
  sf_mex_addfield(c7_y, c7_b_y, "Env", "Env", 0);
  c7_p_u = c7_u.Veh;
  c7_t_y = NULL;
  sf_mex_assign(&c7_t_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c7_q_u = c7_p_u.m;
  c7_u_y = NULL;
  sf_mex_assign(&c7_u_y, sf_mex_create("y", &c7_q_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c7_t_y, c7_u_y, "m", "m", 0);
  c7_r_u = c7_p_u.Jz;
  c7_v_y = NULL;
  sf_mex_assign(&c7_v_y, sf_mex_create("y", &c7_r_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c7_t_y, c7_v_y, "Jz", "Jz", 0);
  c7_s_u = c7_p_u.m_sprung;
  c7_w_y = NULL;
  sf_mex_assign(&c7_w_y, sf_mex_create("y", &c7_s_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c7_t_y, c7_w_y, "m_sprung", "m_sprung", 0);
  c7_t_u = c7_p_u.Jx_sprung;
  c7_x_y = NULL;
  sf_mex_assign(&c7_x_y, sf_mex_create("y", &c7_t_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c7_t_y, c7_x_y, "Jx_sprung", "Jx_sprung", 0);
  c7_u_u = c7_p_u.Jy_sprung;
  c7_y_y = NULL;
  sf_mex_assign(&c7_y_y, sf_mex_create("y", &c7_u_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c7_t_y, c7_y_y, "Jy_sprung", "Jy_sprung", 0);
  c7_v_u = c7_p_u.lf;
  c7_ab_y = NULL;
  sf_mex_assign(&c7_ab_y, sf_mex_create("y", &c7_v_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c7_t_y, c7_ab_y, "lf", "lf", 0);
  c7_w_u = c7_p_u.lr;
  c7_bb_y = NULL;
  sf_mex_assign(&c7_bb_y, sf_mex_create("y", &c7_w_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c7_t_y, c7_bb_y, "lr", "lr", 0);
  c7_x_u = c7_p_u.L;
  c7_cb_y = NULL;
  sf_mex_assign(&c7_cb_y, sf_mex_create("y", &c7_x_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c7_t_y, c7_cb_y, "L", "L", 0);
  c7_y_u = c7_p_u.TrackWidth;
  c7_db_y = NULL;
  sf_mex_assign(&c7_db_y, sf_mex_create("y", &c7_y_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c7_t_y, c7_db_y, "TrackWidth", "TrackWidth", 0);
  c7_ab_u = c7_p_u.h;
  c7_eb_y = NULL;
  sf_mex_assign(&c7_eb_y, sf_mex_create("y", &c7_ab_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c7_t_y, c7_eb_y, "h", "h", 0);
  c7_bb_u = c7_p_u.HalfRohACd;
  c7_fb_y = NULL;
  sf_mex_assign(&c7_fb_y, sf_mex_create("y", &c7_bb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c7_t_y, c7_fb_y, "HalfRohACd", "HalfRohACd", 0);
  for (c7_i16 = 0; c7_i16 < 4; c7_i16++) {
    c7_cb_u[c7_i16] = c7_p_u.F_z4_static[c7_i16];
  }

  c7_gb_y = NULL;
  sf_mex_assign(&c7_gb_y, sf_mex_create("y", c7_cb_u, 0, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_addfield(c7_t_y, c7_gb_y, "F_z4_static", "F_z4_static", 0);
  c7_db_u = c7_p_u.Rw;
  c7_hb_y = NULL;
  sf_mex_assign(&c7_hb_y, sf_mex_create("y", &c7_db_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c7_t_y, c7_hb_y, "Rw", "Rw", 0);
  c7_eb_u = c7_p_u.r_long;
  c7_ib_y = NULL;
  sf_mex_assign(&c7_ib_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c7_i17 = 0; c7_i17 < 3; c7_i17++) {
    c7_fb_u[c7_i17] = c7_eb_u.fl[c7_i17];
  }

  c7_jb_y = NULL;
  sf_mex_assign(&c7_jb_y, sf_mex_create("y", c7_fb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c7_ib_y, c7_jb_y, "fl", "fl", 0);
  for (c7_i18 = 0; c7_i18 < 3; c7_i18++) {
    c7_gb_u[c7_i18] = c7_eb_u.fr[c7_i18];
  }

  c7_kb_y = NULL;
  sf_mex_assign(&c7_kb_y, sf_mex_create("y", c7_gb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c7_ib_y, c7_kb_y, "fr", "fr", 0);
  for (c7_i19 = 0; c7_i19 < 3; c7_i19++) {
    c7_hb_u[c7_i19] = c7_eb_u.rl[c7_i19];
  }

  c7_lb_y = NULL;
  sf_mex_assign(&c7_lb_y, sf_mex_create("y", c7_hb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c7_ib_y, c7_lb_y, "rl", "rl", 0);
  for (c7_i20 = 0; c7_i20 < 3; c7_i20++) {
    c7_ib_u[c7_i20] = c7_eb_u.rr[c7_i20];
  }

  c7_mb_y = NULL;
  sf_mex_assign(&c7_mb_y, sf_mex_create("y", c7_ib_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c7_ib_y, c7_mb_y, "rr", "rr", 0);
  sf_mex_addfield(c7_t_y, c7_ib_y, "r_long", "r_long", 0);
  c7_eb_u = c7_p_u.r_lat;
  c7_nb_y = NULL;
  sf_mex_assign(&c7_nb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c7_i21 = 0; c7_i21 < 3; c7_i21++) {
    c7_jb_u[c7_i21] = c7_eb_u.fl[c7_i21];
  }

  c7_ob_y = NULL;
  sf_mex_assign(&c7_ob_y, sf_mex_create("y", c7_jb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c7_nb_y, c7_ob_y, "fl", "fl", 0);
  for (c7_i22 = 0; c7_i22 < 3; c7_i22++) {
    c7_kb_u[c7_i22] = c7_eb_u.fr[c7_i22];
  }

  c7_pb_y = NULL;
  sf_mex_assign(&c7_pb_y, sf_mex_create("y", c7_kb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c7_nb_y, c7_pb_y, "fr", "fr", 0);
  for (c7_i23 = 0; c7_i23 < 3; c7_i23++) {
    c7_lb_u[c7_i23] = c7_eb_u.rl[c7_i23];
  }

  c7_qb_y = NULL;
  sf_mex_assign(&c7_qb_y, sf_mex_create("y", c7_lb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c7_nb_y, c7_qb_y, "rl", "rl", 0);
  for (c7_i24 = 0; c7_i24 < 3; c7_i24++) {
    c7_mb_u[c7_i24] = c7_eb_u.rr[c7_i24];
  }

  c7_rb_y = NULL;
  sf_mex_assign(&c7_rb_y, sf_mex_create("y", c7_mb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c7_nb_y, c7_rb_y, "rr", "rr", 0);
  sf_mex_addfield(c7_t_y, c7_nb_y, "r_lat", "r_lat", 0);
  c7_eb_u = c7_p_u.r_lever;
  c7_sb_y = NULL;
  sf_mex_assign(&c7_sb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c7_i25 = 0; c7_i25 < 3; c7_i25++) {
    c7_nb_u[c7_i25] = c7_eb_u.fl[c7_i25];
  }

  c7_tb_y = NULL;
  sf_mex_assign(&c7_tb_y, sf_mex_create("y", c7_nb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c7_sb_y, c7_tb_y, "fl", "fl", 0);
  for (c7_i26 = 0; c7_i26 < 3; c7_i26++) {
    c7_ob_u[c7_i26] = c7_eb_u.fr[c7_i26];
  }

  c7_ub_y = NULL;
  sf_mex_assign(&c7_ub_y, sf_mex_create("y", c7_ob_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c7_sb_y, c7_ub_y, "fr", "fr", 0);
  for (c7_i27 = 0; c7_i27 < 3; c7_i27++) {
    c7_pb_u[c7_i27] = c7_eb_u.rl[c7_i27];
  }

  c7_vb_y = NULL;
  sf_mex_assign(&c7_vb_y, sf_mex_create("y", c7_pb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c7_sb_y, c7_vb_y, "rl", "rl", 0);
  for (c7_i28 = 0; c7_i28 < 3; c7_i28++) {
    c7_qb_u[c7_i28] = c7_eb_u.rr[c7_i28];
  }

  c7_wb_y = NULL;
  sf_mex_assign(&c7_wb_y, sf_mex_create("y", c7_qb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c7_sb_y, c7_wb_y, "rr", "rr", 0);
  sf_mex_addfield(c7_t_y, c7_sb_y, "r_lever", "r_lever", 0);
  c7_eb_u = c7_p_u.r_pivot;
  c7_xb_y = NULL;
  sf_mex_assign(&c7_xb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c7_i29 = 0; c7_i29 < 3; c7_i29++) {
    c7_rb_u[c7_i29] = c7_eb_u.fl[c7_i29];
  }

  c7_yb_y = NULL;
  sf_mex_assign(&c7_yb_y, sf_mex_create("y", c7_rb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c7_xb_y, c7_yb_y, "fl", "fl", 0);
  for (c7_i30 = 0; c7_i30 < 3; c7_i30++) {
    c7_sb_u[c7_i30] = c7_eb_u.fr[c7_i30];
  }

  c7_ac_y = NULL;
  sf_mex_assign(&c7_ac_y, sf_mex_create("y", c7_sb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c7_xb_y, c7_ac_y, "fr", "fr", 0);
  for (c7_i31 = 0; c7_i31 < 3; c7_i31++) {
    c7_tb_u[c7_i31] = c7_eb_u.rl[c7_i31];
  }

  c7_bc_y = NULL;
  sf_mex_assign(&c7_bc_y, sf_mex_create("y", c7_tb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c7_xb_y, c7_bc_y, "rl", "rl", 0);
  for (c7_i32 = 0; c7_i32 < 3; c7_i32++) {
    c7_ub_u[c7_i32] = c7_eb_u.rr[c7_i32];
  }

  c7_cc_y = NULL;
  sf_mex_assign(&c7_cc_y, sf_mex_create("y", c7_ub_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c7_xb_y, c7_cc_y, "rr", "rr", 0);
  sf_mex_addfield(c7_t_y, c7_xb_y, "r_pivot", "r_pivot", 0);
  c7_vb_u = c7_p_u.cw;
  c7_dc_y = NULL;
  sf_mex_assign(&c7_dc_y, sf_mex_create("y", &c7_vb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c7_t_y, c7_dc_y, "cw", "cw", 0);
  c7_wb_u = c7_p_u.carb_f;
  c7_ec_y = NULL;
  sf_mex_assign(&c7_ec_y, sf_mex_create("y", &c7_wb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c7_t_y, c7_ec_y, "carb_f", "carb_f", 0);
  c7_xb_u = c7_p_u.carb_r;
  c7_fc_y = NULL;
  sf_mex_assign(&c7_fc_y, sf_mex_create("y", &c7_xb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c7_t_y, c7_fc_y, "carb_r", "carb_r", 0);
  c7_yb_u = c7_p_u.dw;
  c7_gc_y = NULL;
  sf_mex_assign(&c7_gc_y, sf_mex_create("y", &c7_yb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c7_t_y, c7_gc_y, "dw", "dw", 0);
  c7_ac_u = c7_p_u.Jw;
  c7_hc_y = NULL;
  sf_mex_assign(&c7_hc_y, sf_mex_create("y", &c7_ac_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c7_t_y, c7_hc_y, "Jw", "Jw", 0);
  c7_bc_u = c7_p_u.C0;
  c7_ic_y = NULL;
  sf_mex_assign(&c7_ic_y, sf_mex_create("y", &c7_bc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c7_t_y, c7_ic_y, "C0", "C0", 0);
  c7_cc_u = c7_p_u.RelaxLength;
  c7_jc_y = NULL;
  sf_mex_assign(&c7_jc_y, sf_mex_create("y", &c7_cc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c7_t_y, c7_jc_y, "RelaxLength", "RelaxLength", 0);
  c7_dc_u = c7_p_u.RRC;
  c7_kc_y = NULL;
  sf_mex_assign(&c7_kc_y, sf_mex_create("y", &c7_dc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c7_t_y, c7_kc_y, "RRC", "RRC", 0);
  c7_ec_u = c7_p_u.Pmax;
  c7_lc_y = NULL;
  sf_mex_assign(&c7_lc_y, sf_mex_create("y", &c7_ec_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c7_t_y, c7_lc_y, "Pmax", "Pmax", 0);
  c7_fc_u = c7_p_u.PropDistrFrnt;
  c7_mc_y = NULL;
  sf_mex_assign(&c7_mc_y, sf_mex_create("y", &c7_fc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c7_t_y, c7_mc_y, "PropDistrFrnt", "PropDistrFrnt", 0);
  c7_gc_u = c7_p_u.BrkDistrFrnt;
  c7_nc_y = NULL;
  sf_mex_assign(&c7_nc_y, sf_mex_create("y", &c7_gc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c7_t_y, c7_nc_y, "BrkDistrFrnt", "BrkDistrFrnt", 0);
  c7_hc_u = c7_p_u.SteRatio;
  c7_oc_y = NULL;
  sf_mex_assign(&c7_oc_y, sf_mex_create("y", &c7_hc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c7_t_y, c7_oc_y, "SteRatio", "SteRatio", 0);
  sf_mex_addfield(c7_y, c7_t_y, "Veh", "Veh", 0);
  c7_ic_u = c7_u.Drvr;
  c7_pc_y = NULL;
  sf_mex_assign(&c7_pc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c7_jc_u = c7_ic_u.v_set;
  c7_qc_y = NULL;
  sf_mex_assign(&c7_qc_y, sf_mex_create("y", &c7_jc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c7_pc_y, c7_qc_y, "v_set", "v_set", 0);
  sf_mex_addfield(c7_y, c7_pc_y, "Drvr", "Drvr", 0);
  c7_kc_u = c7_u.Init;
  c7_rc_y = NULL;
  sf_mex_assign(&c7_rc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c7_lc_u = c7_kc_u.v_x;
  c7_sc_y = NULL;
  sf_mex_assign(&c7_sc_y, sf_mex_create("y", &c7_lc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c7_rc_y, c7_sc_y, "v_x", "v_x", 0);
  c7_mc_u = c7_kc_u.F_fz;
  c7_tc_y = NULL;
  sf_mex_assign(&c7_tc_y, sf_mex_create("y", &c7_mc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c7_rc_y, c7_tc_y, "F_fz", "F_fz", 0);
  c7_nc_u = c7_kc_u.F_rz;
  c7_uc_y = NULL;
  sf_mex_assign(&c7_uc_y, sf_mex_create("y", &c7_nc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c7_rc_y, c7_uc_y, "F_rz", "F_rz", 0);
  sf_mex_addfield(c7_y, c7_rc_y, "Init", "Init", 0);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static void c7_d_emlrt_marshallIn
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId,
   c7_struct_iBlsPBO3AGnt69vDoTx5zD *c7_y)
{
  emlrtMsgIdentifier c7_thisId;
  static const char * c7_fieldNames[4] = { "Env", "Veh", "Drvr", "Init" };

  c7_thisId.fParent = c7_parentId;
  sf_mex_check_struct(c7_parentId, c7_u, 4, c7_fieldNames, 0U, NULL);
  c7_thisId.fIdentifier = "Env";
  c7_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c7_u, "Env",
    "Env", 0)), &c7_thisId, &c7_y->Env);
  c7_thisId.fIdentifier = "Veh";
  c7_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c7_u, "Veh",
    "Veh", 0)), &c7_thisId, &c7_y->Veh);
  c7_thisId.fIdentifier = "Drvr";
  c7_y->Drvr = c7_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c7_u, "Drvr", "Drvr", 0)), &c7_thisId);
  c7_thisId.fIdentifier = "Init";
  c7_y->Init = c7_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c7_u, "Init", "Init", 0)), &c7_thisId);
  sf_mex_destroy(&c7_u);
}

static void c7_e_emlrt_marshallIn
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId,
   c7_struct_Nst2vGTExxHsg85EUOj9EH *c7_y)
{
  emlrtMsgIdentifier c7_thisId;
  static const char * c7_fieldNames[7] = { "g", "left1", "right1", "right2",
    "left2", "right3", "mu" };

  c7_thisId.fParent = c7_parentId;
  sf_mex_check_struct(c7_parentId, c7_u, 7, c7_fieldNames, 0U, NULL);
  c7_thisId.fIdentifier = "g";
  c7_y->g = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c7_u,
    "g", "g", 0)), &c7_thisId);
  c7_thisId.fIdentifier = "left1";
  c7_y->left1 = c7_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c7_u, "left1", "left1", 0)), &c7_thisId);
  c7_thisId.fIdentifier = "right1";
  c7_y->right1 = c7_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c7_u, "right1", "right1", 0)),
    &c7_thisId);
  c7_thisId.fIdentifier = "right2";
  c7_y->right2 = c7_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c7_u, "right2", "right2", 0)),
    &c7_thisId);
  c7_thisId.fIdentifier = "left2";
  c7_y->left2 = c7_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c7_u, "left2", "left2", 0)), &c7_thisId);
  c7_thisId.fIdentifier = "right3";
  c7_y->right3 = c7_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c7_u, "right3", "right3", 0)),
    &c7_thisId);
  c7_thisId.fIdentifier = "mu";
  c7_y->mu = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c7_u, "mu", "mu", 0)), &c7_thisId);
  sf_mex_destroy(&c7_u);
}

static c7_struct_HhckT6rntEraqECYVIDvCC c7_f_emlrt_marshallIn
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  c7_struct_HhckT6rntEraqECYVIDvCC c7_y;
  emlrtMsgIdentifier c7_thisId;
  static const char * c7_fieldNames[2] = { "x", "y" };

  c7_thisId.fParent = c7_parentId;
  sf_mex_check_struct(c7_parentId, c7_u, 2, c7_fieldNames, 0U, NULL);
  c7_thisId.fIdentifier = "x";
  c7_y.x = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c7_u,
    "x", "x", 0)), &c7_thisId);
  c7_thisId.fIdentifier = "y";
  c7_y.y = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c7_u,
    "y", "y", 0)), &c7_thisId);
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_g_emlrt_marshallIn
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId,
   c7_struct_ZCmOWPuqBDw16FSOVVD00 *c7_y)
{
  emlrtMsgIdentifier c7_thisId;
  static const char * c7_fieldNames[29] = { "m", "Jz", "m_sprung", "Jx_sprung",
    "Jy_sprung", "lf", "lr", "L", "TrackWidth", "h", "HalfRohACd", "F_z4_static",
    "Rw", "r_long", "r_lat", "r_lever", "r_pivot", "cw", "carb_f", "carb_r",
    "dw", "Jw", "C0", "RelaxLength", "RRC", "Pmax", "PropDistrFrnt",
    "BrkDistrFrnt", "SteRatio" };

  c7_thisId.fParent = c7_parentId;
  sf_mex_check_struct(c7_parentId, c7_u, 29, c7_fieldNames, 0U, NULL);
  c7_thisId.fIdentifier = "m";
  c7_y->m = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c7_u,
    "m", "m", 0)), &c7_thisId);
  c7_thisId.fIdentifier = "Jz";
  c7_y->Jz = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c7_u, "Jz", "Jz", 0)), &c7_thisId);
  c7_thisId.fIdentifier = "m_sprung";
  c7_y->m_sprung = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c7_u, "m_sprung", "m_sprung", 0)), &c7_thisId);
  c7_thisId.fIdentifier = "Jx_sprung";
  c7_y->Jx_sprung = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c7_u, "Jx_sprung", "Jx_sprung", 0)), &c7_thisId);
  c7_thisId.fIdentifier = "Jy_sprung";
  c7_y->Jy_sprung = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c7_u, "Jy_sprung", "Jy_sprung", 0)), &c7_thisId);
  c7_thisId.fIdentifier = "lf";
  c7_y->lf = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c7_u, "lf", "lf", 0)), &c7_thisId);
  c7_thisId.fIdentifier = "lr";
  c7_y->lr = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c7_u, "lr", "lr", 0)), &c7_thisId);
  c7_thisId.fIdentifier = "L";
  c7_y->L = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c7_u,
    "L", "L", 0)), &c7_thisId);
  c7_thisId.fIdentifier = "TrackWidth";
  c7_y->TrackWidth = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c7_u, "TrackWidth", "TrackWidth", 0)), &c7_thisId);
  c7_thisId.fIdentifier = "h";
  c7_y->h = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c7_u,
    "h", "h", 0)), &c7_thisId);
  c7_thisId.fIdentifier = "HalfRohACd";
  c7_y->HalfRohACd = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c7_u, "HalfRohACd", "HalfRohACd", 0)), &c7_thisId);
  c7_thisId.fIdentifier = "F_z4_static";
  c7_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c7_u,
    "F_z4_static", "F_z4_static", 0)), &c7_thisId, c7_y->F_z4_static);
  c7_thisId.fIdentifier = "Rw";
  c7_y->Rw = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c7_u, "Rw", "Rw", 0)), &c7_thisId);
  c7_thisId.fIdentifier = "r_long";
  c7_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c7_u, "r_long",
    "r_long", 0)), &c7_thisId, &c7_y->r_long);
  c7_thisId.fIdentifier = "r_lat";
  c7_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c7_u, "r_lat",
    "r_lat", 0)), &c7_thisId, &c7_y->r_lat);
  c7_thisId.fIdentifier = "r_lever";
  c7_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c7_u,
    "r_lever", "r_lever", 0)), &c7_thisId, &c7_y->r_lever);
  c7_thisId.fIdentifier = "r_pivot";
  c7_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c7_u,
    "r_pivot", "r_pivot", 0)), &c7_thisId, &c7_y->r_pivot);
  c7_thisId.fIdentifier = "cw";
  c7_y->cw = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c7_u, "cw", "cw", 0)), &c7_thisId);
  c7_thisId.fIdentifier = "carb_f";
  c7_y->carb_f = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c7_u, "carb_f", "carb_f", 0)),
    &c7_thisId);
  c7_thisId.fIdentifier = "carb_r";
  c7_y->carb_r = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c7_u, "carb_r", "carb_r", 0)),
    &c7_thisId);
  c7_thisId.fIdentifier = "dw";
  c7_y->dw = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c7_u, "dw", "dw", 0)), &c7_thisId);
  c7_thisId.fIdentifier = "Jw";
  c7_y->Jw = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c7_u, "Jw", "Jw", 0)), &c7_thisId);
  c7_thisId.fIdentifier = "C0";
  c7_y->C0 = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c7_u, "C0", "C0", 0)), &c7_thisId);
  c7_thisId.fIdentifier = "RelaxLength";
  c7_y->RelaxLength = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c7_u, "RelaxLength", "RelaxLength", 0)), &c7_thisId);
  c7_thisId.fIdentifier = "RRC";
  c7_y->RRC = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c7_u, "RRC", "RRC", 0)), &c7_thisId);
  c7_thisId.fIdentifier = "Pmax";
  c7_y->Pmax = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c7_u, "Pmax", "Pmax", 0)), &c7_thisId);
  c7_thisId.fIdentifier = "PropDistrFrnt";
  c7_y->PropDistrFrnt = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c7_u, "PropDistrFrnt", "PropDistrFrnt", 0)), &c7_thisId);
  c7_thisId.fIdentifier = "BrkDistrFrnt";
  c7_y->BrkDistrFrnt = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c7_u, "BrkDistrFrnt", "BrkDistrFrnt", 0)), &c7_thisId);
  c7_thisId.fIdentifier = "SteRatio";
  c7_y->SteRatio = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c7_u, "SteRatio", "SteRatio", 0)), &c7_thisId);
  sf_mex_destroy(&c7_u);
}

static void c7_h_emlrt_marshallIn
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId, real_T c7_y[4])
{
  real_T c7_dv2[4];
  int32_T c7_i33;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), c7_dv2, 1, 0, 0U, 1, 0U, 2, 1, 4);
  for (c7_i33 = 0; c7_i33 < 4; c7_i33++) {
    c7_y[c7_i33] = c7_dv2[c7_i33];
  }

  sf_mex_destroy(&c7_u);
}

static void c7_i_emlrt_marshallIn
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId,
   c7_struct_ZKAzdrl7umDGJoC14aoVKC *c7_y)
{
  emlrtMsgIdentifier c7_thisId;
  static const char * c7_fieldNames[4] = { "fl", "fr", "rl", "rr" };

  c7_thisId.fParent = c7_parentId;
  sf_mex_check_struct(c7_parentId, c7_u, 4, c7_fieldNames, 0U, NULL);
  c7_thisId.fIdentifier = "fl";
  c7_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c7_u, "fl",
    "fl", 0)), &c7_thisId, c7_y->fl);
  c7_thisId.fIdentifier = "fr";
  c7_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c7_u, "fr",
    "fr", 0)), &c7_thisId, c7_y->fr);
  c7_thisId.fIdentifier = "rl";
  c7_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c7_u, "rl",
    "rl", 0)), &c7_thisId, c7_y->rl);
  c7_thisId.fIdentifier = "rr";
  c7_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c7_u, "rr",
    "rr", 0)), &c7_thisId, c7_y->rr);
  sf_mex_destroy(&c7_u);
}

static void c7_j_emlrt_marshallIn
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId, real_T c7_y[3])
{
  real_T c7_dv3[3];
  int32_T c7_i34;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), c7_dv3, 1, 0, 0U, 1, 0U, 2, 3, 1);
  for (c7_i34 = 0; c7_i34 < 3; c7_i34++) {
    c7_y[c7_i34] = c7_dv3[c7_i34];
  }

  sf_mex_destroy(&c7_u);
}

static c7_struct_r4FNviKwHfdhB8nQjvQv9 c7_k_emlrt_marshallIn
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  c7_struct_r4FNviKwHfdhB8nQjvQv9 c7_y;
  emlrtMsgIdentifier c7_thisId;
  static const char * c7_fieldNames[1] = { "v_set" };

  c7_thisId.fParent = c7_parentId;
  sf_mex_check_struct(c7_parentId, c7_u, 1, c7_fieldNames, 0U, NULL);
  c7_thisId.fIdentifier = "v_set";
  c7_y.v_set = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c7_u, "v_set", "v_set", 0)), &c7_thisId);
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static c7_struct_Y9F1qlBi9AhssksPwemA4G c7_l_emlrt_marshallIn
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  c7_struct_Y9F1qlBi9AhssksPwemA4G c7_y;
  emlrtMsgIdentifier c7_thisId;
  static const char * c7_fieldNames[3] = { "v_x", "F_fz", "F_rz" };

  c7_thisId.fParent = c7_parentId;
  sf_mex_check_struct(c7_parentId, c7_u, 3, c7_fieldNames, 0U, NULL);
  c7_thisId.fIdentifier = "v_x";
  c7_y.v_x = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c7_u, "v_x", "v_x", 0)), &c7_thisId);
  c7_thisId.fIdentifier = "F_fz";
  c7_y.F_fz = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c7_u, "F_fz", "F_fz", 0)), &c7_thisId);
  c7_thisId.fIdentifier = "F_rz";
  c7_y.F_rz = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c7_u, "F_rz", "F_rz", 0)), &c7_thisId);
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_b_Par;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  c7_struct_iBlsPBO3AGnt69vDoTx5zD c7_y;
  SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c7_b_Par = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_Par), &c7_thisId, &c7_y);
  sf_mex_destroy(&c7_b_Par);
  *(c7_struct_iBlsPBO3AGnt69vDoTx5zD *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_c_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  c7_whl_vec4 c7_u;
  const mxArray *c7_y = NULL;
  real_T c7_b_u;
  const mxArray *c7_b_y = NULL;
  real_T c7_c_u;
  const mxArray *c7_c_y = NULL;
  real_T c7_d_u;
  const mxArray *c7_d_y = NULL;
  real_T c7_e_u;
  const mxArray *c7_e_y = NULL;
  SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(c7_whl_vec4 *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c7_b_u = c7_u.fl;
  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", &c7_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c7_y, c7_b_y, "fl", "fl", 0);
  c7_c_u = c7_u.fr;
  c7_c_y = NULL;
  sf_mex_assign(&c7_c_y, sf_mex_create("y", &c7_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c7_y, c7_c_y, "fr", "fr", 0);
  c7_d_u = c7_u.rl;
  c7_d_y = NULL;
  sf_mex_assign(&c7_d_y, sf_mex_create("y", &c7_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c7_y, c7_d_y, "rl", "rl", 0);
  c7_e_u = c7_u.rr;
  c7_e_y = NULL;
  sf_mex_assign(&c7_e_y, sf_mex_create("y", &c7_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c7_y, c7_e_y, "rr", "rr", 0);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_d_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  real_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(real_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static void c7_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_nargout;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  real_T c7_y;
  SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c7_nargout = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_nargout), &c7_thisId);
  sf_mex_destroy(&c7_nargout);
  *(real_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_e_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i35;
  real_T c7_b_inData[3];
  int32_T c7_i36;
  real_T c7_u[3];
  const mxArray *c7_y = NULL;
  SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i35 = 0; c7_i35 < 3; c7_i35++) {
    c7_b_inData[c7_i35] = (*(real_T (*)[3])c7_inData)[c7_i35];
  }

  for (c7_i36 = 0; c7_i36 < 3; c7_i36++) {
    c7_u[c7_i36] = c7_b_inData[c7_i36];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static void c7_m_emlrt_marshallIn
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId, real_T c7_y[3])
{
  real_T c7_dv4[3];
  int32_T c7_i37;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), c7_dv4, 1, 0, 0U, 1, 0U, 1, 3);
  for (c7_i37 = 0; c7_i37 < 3; c7_i37++) {
    c7_y[c7_i37] = c7_dv4[c7_i37];
  }

  sf_mex_destroy(&c7_u);
}

static void c7_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_derv_irp3_temp;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  real_T c7_y[3];
  int32_T c7_i38;
  SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c7_derv_irp3_temp = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_derv_irp3_temp), &c7_thisId,
                        c7_y);
  sf_mex_destroy(&c7_derv_irp3_temp);
  for (c7_i38 = 0; c7_i38 < 3; c7_i38++) {
    (*(real_T (*)[3])c7_outData)[c7_i38] = c7_y[c7_i38];
  }

  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_f_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i39;
  real_T c7_b_inData[4];
  int32_T c7_i40;
  real_T c7_u[4];
  const mxArray *c7_y = NULL;
  SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i39 = 0; c7_i39 < 4; c7_i39++) {
    c7_b_inData[c7_i39] = (*(real_T (*)[4])c7_inData)[c7_i39];
  }

  for (c7_i40 = 0; c7_i40 < 4; c7_i40++) {
    c7_u[c7_i40] = c7_b_inData[c7_i40];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 4), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static void c7_n_emlrt_marshallIn
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId, real_T c7_y[4])
{
  real_T c7_dv5[4];
  int32_T c7_i41;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), c7_dv5, 1, 0, 0U, 1, 0U, 1, 4);
  for (c7_i41 = 0; c7_i41 < 4; c7_i41++) {
    c7_y[c7_i41] = c7_dv5[c7_i41];
  }

  sf_mex_destroy(&c7_u);
}

static void c7_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_F_yv4_temp;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  real_T c7_y[4];
  int32_T c7_i42;
  SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c7_F_yv4_temp = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_F_yv4_temp), &c7_thisId,
                        c7_y);
  sf_mex_destroy(&c7_F_yv4_temp);
  for (c7_i42 = 0; c7_i42 < 4; c7_i42++) {
    (*(real_T (*)[4])c7_outData)[c7_i42] = c7_y[c7_i42];
  }

  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_g_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i43;
  int32_T c7_i44;
  int32_T c7_i45;
  real_T c7_b_inData[24];
  int32_T c7_i46;
  int32_T c7_i47;
  int32_T c7_i48;
  real_T c7_u[24];
  const mxArray *c7_y = NULL;
  SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_i43 = 0;
  for (c7_i44 = 0; c7_i44 < 8; c7_i44++) {
    for (c7_i45 = 0; c7_i45 < 3; c7_i45++) {
      c7_b_inData[c7_i45 + c7_i43] = (*(real_T (*)[24])c7_inData)[c7_i45 +
        c7_i43];
    }

    c7_i43 += 3;
  }

  c7_i46 = 0;
  for (c7_i47 = 0; c7_i47 < 8; c7_i47++) {
    for (c7_i48 = 0; c7_i48 < 3; c7_i48++) {
      c7_u[c7_i48 + c7_i46] = c7_b_inData[c7_i48 + c7_i46];
    }

    c7_i46 += 3;
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 2, 3, 8), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static void c7_o_emlrt_marshallIn
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId, real_T c7_y[24])
{
  real_T c7_dv6[24];
  int32_T c7_i49;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), c7_dv6, 1, 0, 0U, 1, 0U, 2, 3, 8);
  for (c7_i49 = 0; c7_i49 < 24; c7_i49++) {
    c7_y[c7_i49] = c7_dv6[c7_i49];
  }

  sf_mex_destroy(&c7_u);
}

static void c7_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_T_irpv;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  real_T c7_y[24];
  int32_T c7_i50;
  int32_T c7_i51;
  int32_T c7_i52;
  SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c7_T_irpv = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_T_irpv), &c7_thisId, c7_y);
  sf_mex_destroy(&c7_T_irpv);
  c7_i50 = 0;
  for (c7_i51 = 0; c7_i51 < 8; c7_i51++) {
    for (c7_i52 = 0; c7_i52 < 3; c7_i52++) {
      (*(real_T (*)[24])c7_outData)[c7_i52 + c7_i50] = c7_y[c7_i52 + c7_i50];
    }

    c7_i50 += 3;
  }

  sf_mex_destroy(&c7_mxArrayInData);
}

const mxArray
  *sf_c7_AllPurposeModel_TyreRelaxation_get_eml_resolved_functions_info(void)
{
  const mxArray *c7_nameCaptureInfo = NULL;
  c7_nameCaptureInfo = NULL;
  sf_mex_assign(&c7_nameCaptureInfo, sf_mex_createstruct("structure", 2, 41, 1),
                false);
  c7_info_helper(&c7_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c7_nameCaptureInfo);
  return c7_nameCaptureInfo;
}

static void c7_info_helper(const mxArray **c7_info)
{
  const mxArray *c7_rhs0 = NULL;
  const mxArray *c7_lhs0 = NULL;
  const mxArray *c7_rhs1 = NULL;
  const mxArray *c7_lhs1 = NULL;
  const mxArray *c7_rhs2 = NULL;
  const mxArray *c7_lhs2 = NULL;
  const mxArray *c7_rhs3 = NULL;
  const mxArray *c7_lhs3 = NULL;
  const mxArray *c7_rhs4 = NULL;
  const mxArray *c7_lhs4 = NULL;
  const mxArray *c7_rhs5 = NULL;
  const mxArray *c7_lhs5 = NULL;
  const mxArray *c7_rhs6 = NULL;
  const mxArray *c7_lhs6 = NULL;
  const mxArray *c7_rhs7 = NULL;
  const mxArray *c7_lhs7 = NULL;
  const mxArray *c7_rhs8 = NULL;
  const mxArray *c7_lhs8 = NULL;
  const mxArray *c7_rhs9 = NULL;
  const mxArray *c7_lhs9 = NULL;
  const mxArray *c7_rhs10 = NULL;
  const mxArray *c7_lhs10 = NULL;
  const mxArray *c7_rhs11 = NULL;
  const mxArray *c7_lhs11 = NULL;
  const mxArray *c7_rhs12 = NULL;
  const mxArray *c7_lhs12 = NULL;
  const mxArray *c7_rhs13 = NULL;
  const mxArray *c7_lhs13 = NULL;
  const mxArray *c7_rhs14 = NULL;
  const mxArray *c7_lhs14 = NULL;
  const mxArray *c7_rhs15 = NULL;
  const mxArray *c7_lhs15 = NULL;
  const mxArray *c7_rhs16 = NULL;
  const mxArray *c7_lhs16 = NULL;
  const mxArray *c7_rhs17 = NULL;
  const mxArray *c7_lhs17 = NULL;
  const mxArray *c7_rhs18 = NULL;
  const mxArray *c7_lhs18 = NULL;
  const mxArray *c7_rhs19 = NULL;
  const mxArray *c7_lhs19 = NULL;
  const mxArray *c7_rhs20 = NULL;
  const mxArray *c7_lhs20 = NULL;
  const mxArray *c7_rhs21 = NULL;
  const mxArray *c7_lhs21 = NULL;
  const mxArray *c7_rhs22 = NULL;
  const mxArray *c7_lhs22 = NULL;
  const mxArray *c7_rhs23 = NULL;
  const mxArray *c7_lhs23 = NULL;
  const mxArray *c7_rhs24 = NULL;
  const mxArray *c7_lhs24 = NULL;
  const mxArray *c7_rhs25 = NULL;
  const mxArray *c7_lhs25 = NULL;
  const mxArray *c7_rhs26 = NULL;
  const mxArray *c7_lhs26 = NULL;
  const mxArray *c7_rhs27 = NULL;
  const mxArray *c7_lhs27 = NULL;
  const mxArray *c7_rhs28 = NULL;
  const mxArray *c7_lhs28 = NULL;
  const mxArray *c7_rhs29 = NULL;
  const mxArray *c7_lhs29 = NULL;
  const mxArray *c7_rhs30 = NULL;
  const mxArray *c7_lhs30 = NULL;
  const mxArray *c7_rhs31 = NULL;
  const mxArray *c7_lhs31 = NULL;
  const mxArray *c7_rhs32 = NULL;
  const mxArray *c7_lhs32 = NULL;
  const mxArray *c7_rhs33 = NULL;
  const mxArray *c7_lhs33 = NULL;
  const mxArray *c7_rhs34 = NULL;
  const mxArray *c7_lhs34 = NULL;
  const mxArray *c7_rhs35 = NULL;
  const mxArray *c7_lhs35 = NULL;
  const mxArray *c7_rhs36 = NULL;
  const mxArray *c7_lhs36 = NULL;
  const mxArray *c7_rhs37 = NULL;
  const mxArray *c7_lhs37 = NULL;
  const mxArray *c7_rhs38 = NULL;
  const mxArray *c7_lhs38 = NULL;
  const mxArray *c7_rhs39 = NULL;
  const mxArray *c7_lhs39 = NULL;
  const mxArray *c7_rhs40 = NULL;
  const mxArray *c7_lhs40 = NULL;
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("mrdivide"), "name", "name", 0);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1410807648U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1370009886U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c7_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1389717774U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c7_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("rdivide"), "name", "name", 2);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1363713880U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c7_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c7_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 4);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c7_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_div"), "name", "name", 5);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1386423952U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c7_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 6);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c7_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(""), "context", "context", 7);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("abs"), "name", "name", 7);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1363713852U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c7_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 8);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c7_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 9);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1286818712U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c7_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(""), "context", "context", 10);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("atan2"), "name", "name", 10);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1395328496U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c7_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 11);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 11);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c7_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 12);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 12);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c7_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 13);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c7_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 14);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 14);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c7_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_scalar_atan2"), "name",
                  "name", 15);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan2.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1286818720U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c7_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(""), "context", "context", 16);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("diag"), "name", "name", 16);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/diag.m"), "resolved",
                  "resolved", 16);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1363713854U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c7_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/diag.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("ismatrix"), "name", "name", 17);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1331304858U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c7_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/diag.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 18);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c7_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/diag.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 19);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c7_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/diag.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 20);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1397257422U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c7_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 21);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("isfi"), "name", "name", 21);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 21);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 21);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1346510358U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c7_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context",
                  "context", 22);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("isnumerictype"), "name",
                  "name", 22);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1398875598U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c7_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 23);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("intmax"), "name", "name", 23);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 23);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1362261882U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c7_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 24);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 24);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1393330858U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c7_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 25);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("intmin"), "name", "name", 25);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 25);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1362261882U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c7_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 26);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 26);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 26);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1393330858U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c7_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(""), "context", "context", 27);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 27);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1383877294U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c7_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 28);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 28);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c7_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 29);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 29);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c7_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 30);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 30);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 30);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c7_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 31);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  31);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1375980690U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c7_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 32);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 32);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 32);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c7_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 33);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("coder.internal.blas.xgemm"),
                  "name", "name", 33);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "resolved", "resolved", 33);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c7_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 34);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 34);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 34);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c7_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!below_threshold"),
                  "context", "context", 35);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("coder.internal.blas.threshold"),
                  "name", "name", 35);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c7_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 36);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 36);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 36);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1393330858U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c7_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 37);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 37);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c7_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 38);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("coder.internal.refblas.xgemm"),
                  "name", "name", 38);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "resolved", "resolved", 38);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c7_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(""), "context", "context", 39);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("sin"), "name", "name", 39);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "resolved",
                  "resolved", 39);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1395328504U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c7_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "context",
                  "context", 40);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_scalar_sin"), "name",
                  "name", 40);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m"),
                  "resolved", "resolved", 40);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1286818736U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c7_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs40), "lhs", "lhs",
                  40);
  sf_mex_destroy(&c7_rhs0);
  sf_mex_destroy(&c7_lhs0);
  sf_mex_destroy(&c7_rhs1);
  sf_mex_destroy(&c7_lhs1);
  sf_mex_destroy(&c7_rhs2);
  sf_mex_destroy(&c7_lhs2);
  sf_mex_destroy(&c7_rhs3);
  sf_mex_destroy(&c7_lhs3);
  sf_mex_destroy(&c7_rhs4);
  sf_mex_destroy(&c7_lhs4);
  sf_mex_destroy(&c7_rhs5);
  sf_mex_destroy(&c7_lhs5);
  sf_mex_destroy(&c7_rhs6);
  sf_mex_destroy(&c7_lhs6);
  sf_mex_destroy(&c7_rhs7);
  sf_mex_destroy(&c7_lhs7);
  sf_mex_destroy(&c7_rhs8);
  sf_mex_destroy(&c7_lhs8);
  sf_mex_destroy(&c7_rhs9);
  sf_mex_destroy(&c7_lhs9);
  sf_mex_destroy(&c7_rhs10);
  sf_mex_destroy(&c7_lhs10);
  sf_mex_destroy(&c7_rhs11);
  sf_mex_destroy(&c7_lhs11);
  sf_mex_destroy(&c7_rhs12);
  sf_mex_destroy(&c7_lhs12);
  sf_mex_destroy(&c7_rhs13);
  sf_mex_destroy(&c7_lhs13);
  sf_mex_destroy(&c7_rhs14);
  sf_mex_destroy(&c7_lhs14);
  sf_mex_destroy(&c7_rhs15);
  sf_mex_destroy(&c7_lhs15);
  sf_mex_destroy(&c7_rhs16);
  sf_mex_destroy(&c7_lhs16);
  sf_mex_destroy(&c7_rhs17);
  sf_mex_destroy(&c7_lhs17);
  sf_mex_destroy(&c7_rhs18);
  sf_mex_destroy(&c7_lhs18);
  sf_mex_destroy(&c7_rhs19);
  sf_mex_destroy(&c7_lhs19);
  sf_mex_destroy(&c7_rhs20);
  sf_mex_destroy(&c7_lhs20);
  sf_mex_destroy(&c7_rhs21);
  sf_mex_destroy(&c7_lhs21);
  sf_mex_destroy(&c7_rhs22);
  sf_mex_destroy(&c7_lhs22);
  sf_mex_destroy(&c7_rhs23);
  sf_mex_destroy(&c7_lhs23);
  sf_mex_destroy(&c7_rhs24);
  sf_mex_destroy(&c7_lhs24);
  sf_mex_destroy(&c7_rhs25);
  sf_mex_destroy(&c7_lhs25);
  sf_mex_destroy(&c7_rhs26);
  sf_mex_destroy(&c7_lhs26);
  sf_mex_destroy(&c7_rhs27);
  sf_mex_destroy(&c7_lhs27);
  sf_mex_destroy(&c7_rhs28);
  sf_mex_destroy(&c7_lhs28);
  sf_mex_destroy(&c7_rhs29);
  sf_mex_destroy(&c7_lhs29);
  sf_mex_destroy(&c7_rhs30);
  sf_mex_destroy(&c7_lhs30);
  sf_mex_destroy(&c7_rhs31);
  sf_mex_destroy(&c7_lhs31);
  sf_mex_destroy(&c7_rhs32);
  sf_mex_destroy(&c7_lhs32);
  sf_mex_destroy(&c7_rhs33);
  sf_mex_destroy(&c7_lhs33);
  sf_mex_destroy(&c7_rhs34);
  sf_mex_destroy(&c7_lhs34);
  sf_mex_destroy(&c7_rhs35);
  sf_mex_destroy(&c7_lhs35);
  sf_mex_destroy(&c7_rhs36);
  sf_mex_destroy(&c7_lhs36);
  sf_mex_destroy(&c7_rhs37);
  sf_mex_destroy(&c7_lhs37);
  sf_mex_destroy(&c7_rhs38);
  sf_mex_destroy(&c7_lhs38);
  sf_mex_destroy(&c7_rhs39);
  sf_mex_destroy(&c7_lhs39);
  sf_mex_destroy(&c7_rhs40);
  sf_mex_destroy(&c7_lhs40);
}

static const mxArray *c7_emlrt_marshallOut(const char * c7_u)
{
  const mxArray *c7_y = NULL;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c7_u)), false);
  return c7_y;
}

static const mxArray *c7_b_emlrt_marshallOut(const uint32_T c7_u)
{
  const mxArray *c7_y = NULL;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 7, 0U, 0U, 0U, 0), false);
  return c7_y;
}

static real_T c7_abs(SFc7_AllPurposeModel_TyreRelaxationInstanceStruct
                     *chartInstance, real_T c7_x)
{
  real_T c7_b_x;
  (void)chartInstance;
  c7_b_x = c7_x;
  return muDoubleScalarAbs(c7_b_x);
}

static real_T c7_atan2(SFc7_AllPurposeModel_TyreRelaxationInstanceStruct
  *chartInstance, real_T c7_y, real_T c7_x)
{
  real_T c7_b_y;
  real_T c7_b_x;
  (void)chartInstance;
  c7_b_y = c7_y;
  c7_b_x = c7_x;
  return muDoubleScalarAtan2(c7_b_y, c7_b_x);
}

static void c7_diag(SFc7_AllPurposeModel_TyreRelaxationInstanceStruct
                    *chartInstance, real_T c7_v[3], real_T c7_d[9])
{
  int32_T c7_i53;
  int32_T c7_j;
  int32_T c7_b_j;
  (void)chartInstance;
  for (c7_i53 = 0; c7_i53 < 9; c7_i53++) {
    c7_d[c7_i53] = 0.0;
  }

  for (c7_j = 1; c7_j < 4; c7_j++) {
    c7_b_j = c7_j;
    c7_d[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c7_b_j), 1, 3, 1, 0) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", (real_T)c7_b_j), 1, 3, 2, 0) - 1)) -
      1] = c7_v[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c7_b_j), 1, 3, 1, 0) - 1];
  }
}

static void c7_eml_scalar_eg(SFc7_AllPurposeModel_TyreRelaxationInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c7_threshold(SFc7_AllPurposeModel_TyreRelaxationInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c7_b_eml_scalar_eg(SFc7_AllPurposeModel_TyreRelaxationInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *c7_h_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(int32_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static int32_T c7_p_emlrt_marshallIn
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  int32_T c7_y;
  int32_T c7_i54;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_i54, 1, 6, 0U, 0, 0U, 0);
  c7_y = c7_i54;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_b_sfEvent;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  int32_T c7_y;
  SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c7_b_sfEvent = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_p_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_sfEvent),
    &c7_thisId);
  sf_mex_destroy(&c7_b_sfEvent);
  *(int32_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_F_xv4_bus_io(void *chartInstanceVoid, void *c7_pData)
{
  const mxArray *c7_mxVal = NULL;
  c7_whl_vec4 c7_tmp;
  SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c7_mxVal = NULL;
  c7_tmp.fl = *(real_T *)&((char_T *)(c7_whl_vec4 *)c7_pData)[0];
  c7_tmp.fr = *(real_T *)&((char_T *)(c7_whl_vec4 *)c7_pData)[8];
  c7_tmp.rl = *(real_T *)&((char_T *)(c7_whl_vec4 *)c7_pData)[16];
  c7_tmp.rr = *(real_T *)&((char_T *)(c7_whl_vec4 *)c7_pData)[24];
  sf_mex_assign(&c7_mxVal, c7_c_sf_marshallOut(chartInstance, &c7_tmp), false);
  return c7_mxVal;
}

static const mxArray *c7_v_irp3_bus_io(void *chartInstanceVoid, void *c7_pData)
{
  const mxArray *c7_mxVal = NULL;
  c7_irp_vec3 c7_tmp;
  SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c7_mxVal = NULL;
  c7_tmp.x = *(real_T *)&((char_T *)(c7_irp_vec3 *)c7_pData)[0];
  c7_tmp.y = *(real_T *)&((char_T *)(c7_irp_vec3 *)c7_pData)[8];
  c7_tmp.rotz = *(real_T *)&((char_T *)(c7_irp_vec3 *)c7_pData)[16];
  sf_mex_assign(&c7_mxVal, c7_sf_marshallOut(chartInstance, &c7_tmp), false);
  return c7_mxVal;
}

static uint8_T c7_q_emlrt_marshallIn
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c7_b_is_active_c7_AllPurposeModel_TyreRelaxation, const char_T
   *c7_identifier)
{
  uint8_T c7_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_r_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c7_b_is_active_c7_AllPurposeModel_TyreRelaxation), &c7_thisId);
  sf_mex_destroy(&c7_b_is_active_c7_AllPurposeModel_TyreRelaxation);
  return c7_y;
}

static uint8_T c7_r_emlrt_marshallIn
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  uint8_T c7_y;
  uint8_T c7_u0;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_u0, 1, 3, 0U, 0, 0U, 0);
  c7_y = c7_u0;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void init_dsm_address_info
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address
  (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  chartInstance->c7_F_xv4 = (c7_whl_vec4 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c7_F_yv4 = (c7_whl_vec4 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c7_v_irp3 = (c7_irp_vec3 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c7_derv_irp3 = (c7_irp_vec3 *)ssGetOutputPortSignal_wrapper
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

void sf_c7_AllPurposeModel_TyreRelaxation_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2459597298U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1928770960U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3318919776U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2563278088U);
}

mxArray* sf_c7_AllPurposeModel_TyreRelaxation_get_post_codegen_info(void);
mxArray *sf_c7_AllPurposeModel_TyreRelaxation_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("g5MYbAbGoEWCG5yf4cStDH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
      sf_c7_AllPurposeModel_TyreRelaxation_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c7_AllPurposeModel_TyreRelaxation_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c7_AllPurposeModel_TyreRelaxation_jit_fallback_info(void)
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

mxArray *sf_c7_AllPurposeModel_TyreRelaxation_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c7_AllPurposeModel_TyreRelaxation_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c7_AllPurposeModel_TyreRelaxation
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[27],T\"derv_irp3\",},{M[8],M[0],T\"is_active_c7_AllPurposeModel_TyreRelaxation\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c7_AllPurposeModel_TyreRelaxation_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _AllPurposeModel_TyreRelaxationMachineNumber_,
           7,
           1,
           1,
           0,
           5,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"F_xv4");
          _SFD_SET_DATA_PROPS(1,1,1,0,"F_yv4");
          _SFD_SET_DATA_PROPS(2,1,1,0,"v_irp3");
          _SFD_SET_DATA_PROPS(3,10,0,0,"Par");
          _SFD_SET_DATA_PROPS(4,2,0,1,"derv_irp3");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,821);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_F_xv4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_F_xv4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_v_irp3_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)c7_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_v_irp3_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c7_F_xv4);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c7_F_yv4);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c7_v_irp3);
        _SFD_SET_DATA_VALUE_PTR(3U, &chartInstance->c7_Par);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c7_derv_irp3);
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
  return "dM3QmCydJQ4zatzpUcaKaG";
}

static void sf_opaque_initialize_c7_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc7_AllPurposeModel_TyreRelaxationInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c7_AllPurposeModel_TyreRelaxation
    ((SFc7_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
  initialize_c7_AllPurposeModel_TyreRelaxation
    ((SFc7_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c7_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  enable_c7_AllPurposeModel_TyreRelaxation
    ((SFc7_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c7_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  disable_c7_AllPurposeModel_TyreRelaxation
    ((SFc7_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c7_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  sf_gateway_c7_AllPurposeModel_TyreRelaxation
    ((SFc7_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c7_AllPurposeModel_TyreRelaxation
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c7_AllPurposeModel_TyreRelaxation
    ((SFc7_AllPurposeModel_TyreRelaxationInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c7_AllPurposeModel_TyreRelaxation(SimStruct*
  S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c7_AllPurposeModel_TyreRelaxation
    ((SFc7_AllPurposeModel_TyreRelaxationInstanceStruct*)
     chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c7_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc7_AllPurposeModel_TyreRelaxationInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_AllPurposeModel_TyreRelaxation_optimization_info();
    }

    finalize_c7_AllPurposeModel_TyreRelaxation
      ((SFc7_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc7_AllPurposeModel_TyreRelaxation
    ((SFc7_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c7_AllPurposeModel_TyreRelaxation(SimStruct *S)
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
    initialize_params_c7_AllPurposeModel_TyreRelaxation
      ((SFc7_AllPurposeModel_TyreRelaxationInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c7_AllPurposeModel_TyreRelaxation(SimStruct *S)
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
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,7);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,7,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,7,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,7);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,7,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,7,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,7);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(352067768U));
  ssSetChecksum1(S,(3420251219U));
  ssSetChecksum2(S,(3392791435U));
  ssSetChecksum3(S,(1190378449U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c7_AllPurposeModel_TyreRelaxation(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c7_AllPurposeModel_TyreRelaxation(SimStruct *S)
{
  SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct *)utMalloc
    (sizeof(SFc7_AllPurposeModel_TyreRelaxationInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc7_AllPurposeModel_TyreRelaxationInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c7_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c7_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c7_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c7_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c7_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c7_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c7_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c7_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c7_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.mdlStart = mdlStart_c7_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c7_AllPurposeModel_TyreRelaxation;
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

void c7_AllPurposeModel_TyreRelaxation_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c7_AllPurposeModel_TyreRelaxation(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c7_AllPurposeModel_TyreRelaxation(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c7_AllPurposeModel_TyreRelaxation(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c7_AllPurposeModel_TyreRelaxation_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
