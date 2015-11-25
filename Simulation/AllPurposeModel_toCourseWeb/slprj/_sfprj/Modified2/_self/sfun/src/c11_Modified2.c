/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Modified2_sfun.h"
#include "c11_Modified2.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Modified2_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c11_debug_family_names[19] = { "w1", "w2", "w3", "w4", "lf",
  "lr", "h", "T_oorpv", "F_xv4_temp", "F_yv4_temp", "F_z4_temp", "F_oorp3",
  "nargin", "nargout", "F_xv4", "F_yv4", "F_z4", "Par", "derv_oorp3" };

/* Function Declarations */
static void initialize_c11_Modified2(SFc11_Modified2InstanceStruct
  *chartInstance);
static void initialize_params_c11_Modified2(SFc11_Modified2InstanceStruct
  *chartInstance);
static void enable_c11_Modified2(SFc11_Modified2InstanceStruct *chartInstance);
static void disable_c11_Modified2(SFc11_Modified2InstanceStruct *chartInstance);
static void c11_update_debugger_state_c11_Modified2
  (SFc11_Modified2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c11_Modified2(SFc11_Modified2InstanceStruct *
  chartInstance);
static void set_sim_state_c11_Modified2(SFc11_Modified2InstanceStruct
  *chartInstance, const mxArray *c11_st);
static void finalize_c11_Modified2(SFc11_Modified2InstanceStruct *chartInstance);
static void sf_gateway_c11_Modified2(SFc11_Modified2InstanceStruct
  *chartInstance);
static void mdl_start_c11_Modified2(SFc11_Modified2InstanceStruct *chartInstance);
static void c11_chartstep_c11_Modified2(SFc11_Modified2InstanceStruct
  *chartInstance);
static void initSimStructsc11_Modified2(SFc11_Modified2InstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber, uint32_T c11_instanceNumber);
static const mxArray *c11_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static c11_oorp_vec3 c11_emlrt_marshallIn(SFc11_Modified2InstanceStruct
  *chartInstance, const mxArray *c11_b_derv_oorp3, const char_T *c11_identifier);
static c11_oorp_vec3 c11_b_emlrt_marshallIn(SFc11_Modified2InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static real_T c11_c_emlrt_marshallIn(SFc11_Modified2InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_b_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_d_emlrt_marshallIn(SFc11_Modified2InstanceStruct *chartInstance,
  const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  c11_struct_iBlsPBO3AGnt69vDoTx5zD *c11_y);
static void c11_e_emlrt_marshallIn(SFc11_Modified2InstanceStruct *chartInstance,
  const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  c11_struct_Nst2vGTExxHsg85EUOj9EH *c11_y);
static c11_struct_HhckT6rntEraqECYVIDvCC c11_f_emlrt_marshallIn
  (SFc11_Modified2InstanceStruct *chartInstance, const mxArray *c11_u, const
   emlrtMsgIdentifier *c11_parentId);
static void c11_g_emlrt_marshallIn(SFc11_Modified2InstanceStruct *chartInstance,
  const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  c11_struct_ZCmOWPuqBDw16FSOVVD00 *c11_y);
static void c11_h_emlrt_marshallIn(SFc11_Modified2InstanceStruct *chartInstance,
  const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId, real_T c11_y[4]);
static void c11_i_emlrt_marshallIn(SFc11_Modified2InstanceStruct *chartInstance,
  const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  c11_struct_ZKAzdrl7umDGJoC14aoVKC *c11_y);
static void c11_j_emlrt_marshallIn(SFc11_Modified2InstanceStruct *chartInstance,
  const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId, real_T c11_y[3]);
static c11_struct_r4FNviKwHfdhB8nQjvQv9 c11_k_emlrt_marshallIn
  (SFc11_Modified2InstanceStruct *chartInstance, const mxArray *c11_u, const
   emlrtMsgIdentifier *c11_parentId);
static c11_struct_Y9F1qlBi9AhssksPwemA4G c11_l_emlrt_marshallIn
  (SFc11_Modified2InstanceStruct *chartInstance, const mxArray *c11_u, const
   emlrtMsgIdentifier *c11_parentId);
static void c11_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_c_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static const mxArray *c11_d_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_e_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_m_emlrt_marshallIn(SFc11_Modified2InstanceStruct *chartInstance,
  const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId, real_T c11_y[3]);
static void c11_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_f_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_n_emlrt_marshallIn(SFc11_Modified2InstanceStruct *chartInstance,
  const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId, real_T c11_y[4]);
static void c11_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_g_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_o_emlrt_marshallIn(SFc11_Modified2InstanceStruct *chartInstance,
  const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId, real_T c11_y[12]);
static void c11_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static void c11_info_helper(const mxArray **c11_info);
static const mxArray *c11_emlrt_marshallOut(const char * c11_u);
static const mxArray *c11_b_emlrt_marshallOut(const uint32_T c11_u);
static void c11_eml_scalar_eg(SFc11_Modified2InstanceStruct *chartInstance);
static void c11_eml_xgemm(SFc11_Modified2InstanceStruct *chartInstance, real_T
  c11_A[12], real_T c11_B[4], real_T c11_C[3], real_T c11_b_C[3]);
static const mxArray *c11_h_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static int32_T c11_p_emlrt_marshallIn(SFc11_Modified2InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_F_xv4_bus_io(void *chartInstanceVoid, void *c11_pData);
static const mxArray *c11_derv_oorp3_bus_io(void *chartInstanceVoid, void
  *c11_pData);
static uint8_T c11_q_emlrt_marshallIn(SFc11_Modified2InstanceStruct
  *chartInstance, const mxArray *c11_b_is_active_c11_Modified2, const char_T
  *c11_identifier);
static uint8_T c11_r_emlrt_marshallIn(SFc11_Modified2InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_b_eml_xgemm(SFc11_Modified2InstanceStruct *chartInstance, real_T
  c11_A[12], real_T c11_B[4], real_T c11_C[3]);
static void init_dsm_address_info(SFc11_Modified2InstanceStruct *chartInstance);
static void init_simulink_io_address(SFc11_Modified2InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c11_Modified2(SFc11_Modified2InstanceStruct
  *chartInstance)
{
  chartInstance->c11_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c11_is_active_c11_Modified2 = 0U;
}

static void initialize_params_c11_Modified2(SFc11_Modified2InstanceStruct
  *chartInstance)
{
  const mxArray *c11_m0 = NULL;
  const mxArray *c11_mxField;
  const mxArray *c11_m1 = NULL;
  const mxArray *c11_b_mxField;
  c11_struct_iBlsPBO3AGnt69vDoTx5zD c11_r0;
  const mxArray *c11_m2 = NULL;
  const mxArray *c11_c_mxField;
  const mxArray *c11_m3 = NULL;
  const mxArray *c11_d_mxField;
  const mxArray *c11_m4 = NULL;
  const mxArray *c11_e_mxField;
  const mxArray *c11_m5 = NULL;
  const mxArray *c11_f_mxField;
  const mxArray *c11_m6 = NULL;
  const mxArray *c11_g_mxField;
  const mxArray *c11_m7 = NULL;
  const mxArray *c11_h_mxField;
  const mxArray *c11_m8 = NULL;
  const mxArray *c11_i_mxField;
  const mxArray *c11_m9 = NULL;
  const mxArray *c11_j_mxField;
  const mxArray *c11_m10 = NULL;
  const mxArray *c11_k_mxField;
  const mxArray *c11_m11 = NULL;
  const mxArray *c11_l_mxField;
  const mxArray *c11_m12 = NULL;
  const mxArray *c11_m_mxField;
  const mxArray *c11_m13 = NULL;
  const mxArray *c11_n_mxField;
  c11_m0 = sf_mex_get_sfun_param(chartInstance->S, 0, 1);
  c11_mxField = sf_mex_getfield(c11_m0, "Env", "Par", 0);
  c11_m1 = sf_mex_dup(c11_mxField);
  c11_b_mxField = sf_mex_getfield(c11_m1, "g", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_b_mxField), &c11_r0.Env.g, 1, 0, 0U,
                      0, 0U, 0);
  c11_b_mxField = sf_mex_getfield(c11_m1, "left1", "Par", 0);
  c11_m2 = sf_mex_dup(c11_b_mxField);
  c11_c_mxField = sf_mex_getfield(c11_m2, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_c_mxField), &c11_r0.Env.left1.x, 1,
                      0, 0U, 0, 0U, 0);
  c11_c_mxField = sf_mex_getfield(c11_m2, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_c_mxField), &c11_r0.Env.left1.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c11_m2);
  c11_b_mxField = sf_mex_getfield(c11_m1, "right1", "Par", 0);
  c11_m3 = sf_mex_dup(c11_b_mxField);
  c11_d_mxField = sf_mex_getfield(c11_m3, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_d_mxField), &c11_r0.Env.right1.x, 1,
                      0, 0U, 0, 0U, 0);
  c11_d_mxField = sf_mex_getfield(c11_m3, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_d_mxField), &c11_r0.Env.right1.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c11_m3);
  c11_b_mxField = sf_mex_getfield(c11_m1, "right2", "Par", 0);
  c11_m4 = sf_mex_dup(c11_b_mxField);
  c11_e_mxField = sf_mex_getfield(c11_m4, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_e_mxField), &c11_r0.Env.right2.x, 1,
                      0, 0U, 0, 0U, 0);
  c11_e_mxField = sf_mex_getfield(c11_m4, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_e_mxField), &c11_r0.Env.right2.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c11_m4);
  c11_b_mxField = sf_mex_getfield(c11_m1, "left2", "Par", 0);
  c11_m5 = sf_mex_dup(c11_b_mxField);
  c11_f_mxField = sf_mex_getfield(c11_m5, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_f_mxField), &c11_r0.Env.left2.x, 1,
                      0, 0U, 0, 0U, 0);
  c11_f_mxField = sf_mex_getfield(c11_m5, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_f_mxField), &c11_r0.Env.left2.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c11_m5);
  c11_b_mxField = sf_mex_getfield(c11_m1, "right3", "Par", 0);
  c11_m6 = sf_mex_dup(c11_b_mxField);
  c11_g_mxField = sf_mex_getfield(c11_m6, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_g_mxField), &c11_r0.Env.right3.x, 1,
                      0, 0U, 0, 0U, 0);
  c11_g_mxField = sf_mex_getfield(c11_m6, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_g_mxField), &c11_r0.Env.right3.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c11_m6);
  c11_b_mxField = sf_mex_getfield(c11_m1, "mu", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_b_mxField), &c11_r0.Env.mu, 1, 0, 0U,
                      0, 0U, 0);
  sf_mex_destroy(&c11_m1);
  c11_mxField = sf_mex_getfield(c11_m0, "Veh", "Par", 0);
  c11_m7 = sf_mex_dup(c11_mxField);
  c11_h_mxField = sf_mex_getfield(c11_m7, "m", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_h_mxField), &c11_r0.Veh.m, 1, 0, 0U,
                      0, 0U, 0);
  c11_h_mxField = sf_mex_getfield(c11_m7, "Jz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_h_mxField), &c11_r0.Veh.Jz, 1, 0, 0U,
                      0, 0U, 0);
  c11_h_mxField = sf_mex_getfield(c11_m7, "m_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_h_mxField), &c11_r0.Veh.m_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c11_h_mxField = sf_mex_getfield(c11_m7, "Jx_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_h_mxField), &c11_r0.Veh.Jx_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c11_h_mxField = sf_mex_getfield(c11_m7, "Jy_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_h_mxField), &c11_r0.Veh.Jy_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c11_h_mxField = sf_mex_getfield(c11_m7, "lf", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_h_mxField), &c11_r0.Veh.lf, 1, 0, 0U,
                      0, 0U, 0);
  c11_h_mxField = sf_mex_getfield(c11_m7, "lr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_h_mxField), &c11_r0.Veh.lr, 1, 0, 0U,
                      0, 0U, 0);
  c11_h_mxField = sf_mex_getfield(c11_m7, "L", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_h_mxField), &c11_r0.Veh.L, 1, 0, 0U,
                      0, 0U, 0);
  c11_h_mxField = sf_mex_getfield(c11_m7, "TrackWidth", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_h_mxField), &c11_r0.Veh.TrackWidth,
                      1, 0, 0U, 0, 0U, 0);
  c11_h_mxField = sf_mex_getfield(c11_m7, "h", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_h_mxField), &c11_r0.Veh.h, 1, 0, 0U,
                      0, 0U, 0);
  c11_h_mxField = sf_mex_getfield(c11_m7, "HalfRohACd", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_h_mxField), &c11_r0.Veh.HalfRohACd,
                      1, 0, 0U, 0, 0U, 0);
  c11_h_mxField = sf_mex_getfield(c11_m7, "F_z4_static", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_h_mxField), c11_r0.Veh.F_z4_static,
                      1, 0, 0U, 1, 0U, 2, 1, 4);
  c11_h_mxField = sf_mex_getfield(c11_m7, "Rw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_h_mxField), &c11_r0.Veh.Rw, 1, 0, 0U,
                      0, 0U, 0);
  c11_h_mxField = sf_mex_getfield(c11_m7, "r_long", "Par", 0);
  c11_m8 = sf_mex_dup(c11_h_mxField);
  c11_i_mxField = sf_mex_getfield(c11_m8, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_i_mxField), c11_r0.Veh.r_long.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c11_i_mxField = sf_mex_getfield(c11_m8, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_i_mxField), c11_r0.Veh.r_long.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c11_i_mxField = sf_mex_getfield(c11_m8, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_i_mxField), c11_r0.Veh.r_long.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c11_i_mxField = sf_mex_getfield(c11_m8, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_i_mxField), c11_r0.Veh.r_long.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c11_m8);
  c11_h_mxField = sf_mex_getfield(c11_m7, "r_lat", "Par", 0);
  c11_m9 = sf_mex_dup(c11_h_mxField);
  c11_j_mxField = sf_mex_getfield(c11_m9, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_j_mxField), c11_r0.Veh.r_lat.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c11_j_mxField = sf_mex_getfield(c11_m9, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_j_mxField), c11_r0.Veh.r_lat.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c11_j_mxField = sf_mex_getfield(c11_m9, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_j_mxField), c11_r0.Veh.r_lat.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c11_j_mxField = sf_mex_getfield(c11_m9, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_j_mxField), c11_r0.Veh.r_lat.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c11_m9);
  c11_h_mxField = sf_mex_getfield(c11_m7, "r_lever", "Par", 0);
  c11_m10 = sf_mex_dup(c11_h_mxField);
  c11_k_mxField = sf_mex_getfield(c11_m10, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_k_mxField), c11_r0.Veh.r_lever.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c11_k_mxField = sf_mex_getfield(c11_m10, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_k_mxField), c11_r0.Veh.r_lever.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c11_k_mxField = sf_mex_getfield(c11_m10, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_k_mxField), c11_r0.Veh.r_lever.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c11_k_mxField = sf_mex_getfield(c11_m10, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_k_mxField), c11_r0.Veh.r_lever.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c11_m10);
  c11_h_mxField = sf_mex_getfield(c11_m7, "r_pivot", "Par", 0);
  c11_m11 = sf_mex_dup(c11_h_mxField);
  c11_l_mxField = sf_mex_getfield(c11_m11, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_l_mxField), c11_r0.Veh.r_pivot.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c11_l_mxField = sf_mex_getfield(c11_m11, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_l_mxField), c11_r0.Veh.r_pivot.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c11_l_mxField = sf_mex_getfield(c11_m11, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_l_mxField), c11_r0.Veh.r_pivot.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c11_l_mxField = sf_mex_getfield(c11_m11, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_l_mxField), c11_r0.Veh.r_pivot.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c11_m11);
  c11_h_mxField = sf_mex_getfield(c11_m7, "cw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_h_mxField), &c11_r0.Veh.cw, 1, 0, 0U,
                      0, 0U, 0);
  c11_h_mxField = sf_mex_getfield(c11_m7, "carb_f", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_h_mxField), &c11_r0.Veh.carb_f, 1, 0,
                      0U, 0, 0U, 0);
  c11_h_mxField = sf_mex_getfield(c11_m7, "carb_r", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_h_mxField), &c11_r0.Veh.carb_r, 1, 0,
                      0U, 0, 0U, 0);
  c11_h_mxField = sf_mex_getfield(c11_m7, "dw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_h_mxField), &c11_r0.Veh.dw, 1, 0, 0U,
                      0, 0U, 0);
  c11_h_mxField = sf_mex_getfield(c11_m7, "Jw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_h_mxField), &c11_r0.Veh.Jw, 1, 0, 0U,
                      0, 0U, 0);
  c11_h_mxField = sf_mex_getfield(c11_m7, "C0", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_h_mxField), &c11_r0.Veh.C0, 1, 0, 0U,
                      0, 0U, 0);
  c11_h_mxField = sf_mex_getfield(c11_m7, "RelaxLength", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_h_mxField), &c11_r0.Veh.RelaxLength,
                      1, 0, 0U, 0, 0U, 0);
  c11_h_mxField = sf_mex_getfield(c11_m7, "RRC", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_h_mxField), &c11_r0.Veh.RRC, 1, 0,
                      0U, 0, 0U, 0);
  c11_h_mxField = sf_mex_getfield(c11_m7, "Pmax", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_h_mxField), &c11_r0.Veh.Pmax, 1, 0,
                      0U, 0, 0U, 0);
  c11_h_mxField = sf_mex_getfield(c11_m7, "PropDistrFrnt", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_h_mxField),
                      &c11_r0.Veh.PropDistrFrnt, 1, 0, 0U, 0, 0U, 0);
  c11_h_mxField = sf_mex_getfield(c11_m7, "BrkDistrFrnt", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_h_mxField), &c11_r0.Veh.BrkDistrFrnt,
                      1, 0, 0U, 0, 0U, 0);
  c11_h_mxField = sf_mex_getfield(c11_m7, "SteRatio", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_h_mxField), &c11_r0.Veh.SteRatio, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c11_m7);
  c11_mxField = sf_mex_getfield(c11_m0, "Drvr", "Par", 0);
  c11_m12 = sf_mex_dup(c11_mxField);
  c11_m_mxField = sf_mex_getfield(c11_m12, "v_set", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_m_mxField), &c11_r0.Drvr.v_set, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c11_m12);
  c11_mxField = sf_mex_getfield(c11_m0, "Init", "Par", 0);
  c11_m13 = sf_mex_dup(c11_mxField);
  c11_n_mxField = sf_mex_getfield(c11_m13, "v_x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_n_mxField), &c11_r0.Init.v_x, 1, 0,
                      0U, 0, 0U, 0);
  c11_n_mxField = sf_mex_getfield(c11_m13, "F_fz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_n_mxField), &c11_r0.Init.F_fz, 1, 0,
                      0U, 0, 0U, 0);
  c11_n_mxField = sf_mex_getfield(c11_m13, "F_rz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c11_n_mxField), &c11_r0.Init.F_rz, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c11_m13);
  sf_mex_destroy(&c11_m0);
  chartInstance->c11_Par = c11_r0;
}

static void enable_c11_Modified2(SFc11_Modified2InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c11_Modified2(SFc11_Modified2InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c11_update_debugger_state_c11_Modified2
  (SFc11_Modified2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c11_Modified2(SFc11_Modified2InstanceStruct *
  chartInstance)
{
  const mxArray *c11_st;
  const mxArray *c11_y = NULL;
  const mxArray *c11_b_y = NULL;
  real_T c11_u;
  const mxArray *c11_c_y = NULL;
  real_T c11_b_u;
  const mxArray *c11_d_y = NULL;
  real_T c11_c_u;
  const mxArray *c11_e_y = NULL;
  uint8_T c11_hoistedGlobal;
  uint8_T c11_d_u;
  const mxArray *c11_f_y = NULL;
  c11_st = NULL;
  c11_st = NULL;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_createcellmatrix(2, 1), false);
  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c11_u = *(real_T *)&((char_T *)chartInstance->c11_derv_oorp3)[0];
  c11_c_y = NULL;
  sf_mex_assign(&c11_c_y, sf_mex_create("y", &c11_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c11_b_y, c11_c_y, "z", "z", 0);
  c11_b_u = *(real_T *)&((char_T *)chartInstance->c11_derv_oorp3)[8];
  c11_d_y = NULL;
  sf_mex_assign(&c11_d_y, sf_mex_create("y", &c11_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c11_b_y, c11_d_y, "rotx", "rotx", 0);
  c11_c_u = *(real_T *)&((char_T *)chartInstance->c11_derv_oorp3)[16];
  c11_e_y = NULL;
  sf_mex_assign(&c11_e_y, sf_mex_create("y", &c11_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c11_b_y, c11_e_y, "roty", "roty", 0);
  sf_mex_setcell(c11_y, 0, c11_b_y);
  c11_hoistedGlobal = chartInstance->c11_is_active_c11_Modified2;
  c11_d_u = c11_hoistedGlobal;
  c11_f_y = NULL;
  sf_mex_assign(&c11_f_y, sf_mex_create("y", &c11_d_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 1, c11_f_y);
  sf_mex_assign(&c11_st, c11_y, false);
  return c11_st;
}

static void set_sim_state_c11_Modified2(SFc11_Modified2InstanceStruct
  *chartInstance, const mxArray *c11_st)
{
  const mxArray *c11_u;
  c11_oorp_vec3 c11_r1;
  chartInstance->c11_doneDoubleBufferReInit = true;
  c11_u = sf_mex_dup(c11_st);
  c11_r1 = c11_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c11_u,
    0)), "derv_oorp3");
  *(real_T *)&((char_T *)chartInstance->c11_derv_oorp3)[0] = c11_r1.z;
  *(real_T *)&((char_T *)chartInstance->c11_derv_oorp3)[8] = c11_r1.rotx;
  *(real_T *)&((char_T *)chartInstance->c11_derv_oorp3)[16] = c11_r1.roty;
  chartInstance->c11_is_active_c11_Modified2 = c11_q_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 1)),
     "is_active_c11_Modified2");
  sf_mex_destroy(&c11_u);
  c11_update_debugger_state_c11_Modified2(chartInstance);
  sf_mex_destroy(&c11_st);
}

static void finalize_c11_Modified2(SFc11_Modified2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c11_Modified2(SFc11_Modified2InstanceStruct
  *chartInstance)
{
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 8U, chartInstance->c11_sfEvent);
  chartInstance->c11_sfEvent = CALL_EVENT;
  c11_chartstep_c11_Modified2(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Modified2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c11_Modified2(SFc11_Modified2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c11_chartstep_c11_Modified2(SFc11_Modified2InstanceStruct
  *chartInstance)
{
  c11_whl_vec4 c11_b_F_xv4;
  c11_whl_vec4 c11_b_F_yv4;
  c11_whl_vec4 c11_b_F_z4;
  c11_struct_iBlsPBO3AGnt69vDoTx5zD c11_b_Par;
  uint32_T c11_debug_family_var_map[19];
  real_T c11_w1;
  real_T c11_w2;
  real_T c11_w3;
  real_T c11_w4;
  real_T c11_lf;
  real_T c11_lr;
  real_T c11_h;
  real_T c11_T_oorpv[12];
  real_T c11_F_xv4_temp[4];
  real_T c11_F_yv4_temp[4];
  real_T c11_F_z4_temp[4];
  real_T c11_F_oorp3[3];
  real_T c11_nargin = 4.0;
  real_T c11_nargout = 1.0;
  c11_oorp_vec3 c11_b_derv_oorp3;
  real_T c11_A;
  real_T c11_x;
  real_T c11_b_x;
  real_T c11_c_x;
  int32_T c11_i0;
  int32_T c11_i1;
  int32_T c11_i2;
  int32_T c11_i3;
  real_T c11_a[12];
  int32_T c11_i4;
  int32_T c11_i5;
  int32_T c11_i6;
  real_T c11_b[4];
  int32_T c11_i7;
  real_T c11_y[3];
  int32_T c11_i8;
  real_T c11_b_a[12];
  int32_T c11_i9;
  real_T c11_b_b[4];
  int32_T c11_i10;
  int32_T c11_i11;
  int32_T c11_i12;
  int32_T c11_i13;
  int32_T c11_i14;
  int32_T c11_i15;
  real_T c11_b_y[3];
  int32_T c11_i16;
  real_T c11_c_a[12];
  int32_T c11_i17;
  real_T c11_c_b[4];
  int32_T c11_i18;
  int32_T c11_i19;
  int32_T c11_i20;
  real_T c11_c_y[3];
  int32_T c11_i21;
  real_T c11_d_a[12];
  int32_T c11_i22;
  real_T c11_d_b[4];
  real_T c11_c_Par[3];
  int32_T c11_i23;
  real_T c11_b_A;
  real_T c11_B;
  real_T c11_d_x;
  real_T c11_d_y;
  real_T c11_e_x;
  real_T c11_e_y;
  real_T c11_f_x;
  real_T c11_f_y;
  real_T c11_g_y;
  real_T c11_c_A;
  real_T c11_b_B;
  real_T c11_g_x;
  real_T c11_h_y;
  real_T c11_h_x;
  real_T c11_i_y;
  real_T c11_i_x;
  real_T c11_j_y;
  real_T c11_k_y;
  real_T c11_d_A;
  real_T c11_c_B;
  real_T c11_j_x;
  real_T c11_l_y;
  real_T c11_k_x;
  real_T c11_m_y;
  real_T c11_l_x;
  real_T c11_n_y;
  real_T c11_o_y;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c11_sfEvent);
  c11_b_F_xv4.fl = *(real_T *)&((char_T *)chartInstance->c11_F_xv4)[0];
  c11_b_F_xv4.fr = *(real_T *)&((char_T *)chartInstance->c11_F_xv4)[8];
  c11_b_F_xv4.rl = *(real_T *)&((char_T *)chartInstance->c11_F_xv4)[16];
  c11_b_F_xv4.rr = *(real_T *)&((char_T *)chartInstance->c11_F_xv4)[24];
  c11_b_F_yv4.fl = *(real_T *)&((char_T *)chartInstance->c11_F_yv4)[0];
  c11_b_F_yv4.fr = *(real_T *)&((char_T *)chartInstance->c11_F_yv4)[8];
  c11_b_F_yv4.rl = *(real_T *)&((char_T *)chartInstance->c11_F_yv4)[16];
  c11_b_F_yv4.rr = *(real_T *)&((char_T *)chartInstance->c11_F_yv4)[24];
  c11_b_F_z4.fl = *(real_T *)&((char_T *)chartInstance->c11_F_z4)[0];
  c11_b_F_z4.fr = *(real_T *)&((char_T *)chartInstance->c11_F_z4)[8];
  c11_b_F_z4.rl = *(real_T *)&((char_T *)chartInstance->c11_F_z4)[16];
  c11_b_F_z4.rr = *(real_T *)&((char_T *)chartInstance->c11_F_z4)[24];
  c11_b_Par = chartInstance->c11_Par;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 19U, 19U, c11_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_w1, 0U, c11_d_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_w2, 1U, c11_d_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_w3, 2U, c11_d_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_w4, 3U, c11_d_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_lf, 4U, c11_d_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_lr, 5U, c11_d_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_h, 6U, c11_d_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_T_oorpv, 7U, c11_g_sf_marshallOut,
    c11_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_F_xv4_temp, 8U, c11_f_sf_marshallOut,
    c11_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_F_yv4_temp, 9U, c11_f_sf_marshallOut,
    c11_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_F_z4_temp, 10U, c11_f_sf_marshallOut,
    c11_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_F_oorp3, 11U, c11_e_sf_marshallOut,
    c11_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 12U, c11_d_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 13U, c11_d_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_b_F_xv4, 14U, c11_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_b_F_yv4, 15U, c11_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_b_F_z4, 16U, c11_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_Par, 17U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_derv_oorp3, 18U,
    c11_sf_marshallOut, c11_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 5);
  c11_A = c11_b_Par.Veh.TrackWidth;
  c11_x = c11_A;
  c11_b_x = c11_x;
  c11_c_x = c11_b_x;
  c11_w1 = c11_c_x / 2.0;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 6);
  c11_w2 = -c11_w1;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 7);
  c11_w3 = c11_w1;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 8);
  c11_w4 = c11_w2;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 10);
  c11_lf = c11_b_Par.Veh.lf;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 11);
  c11_lr = c11_b_Par.Veh.lr;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 13);
  c11_h = c11_b_Par.Veh.h;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 15);
  c11_i0 = 0;
  for (c11_i1 = 0; c11_i1 < 4; c11_i1++) {
    c11_T_oorpv[c11_i0] = 1.0;
    c11_i0 += 3;
  }

  c11_T_oorpv[1] = c11_w1;
  c11_T_oorpv[4] = c11_w2;
  c11_T_oorpv[7] = c11_w3;
  c11_T_oorpv[10] = c11_w4;
  c11_T_oorpv[2] = -c11_lf;
  c11_T_oorpv[5] = -c11_lf;
  c11_T_oorpv[8] = -c11_lr;
  c11_T_oorpv[11] = -c11_lr;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 19);
  c11_F_xv4_temp[0] = c11_b_F_xv4.fl;
  c11_F_xv4_temp[1] = c11_b_F_xv4.fr;
  c11_F_xv4_temp[2] = c11_b_F_xv4.rl;
  c11_F_xv4_temp[3] = c11_b_F_xv4.rr;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 20);
  c11_F_yv4_temp[0] = c11_b_F_yv4.fl;
  c11_F_yv4_temp[1] = c11_b_F_yv4.fr;
  c11_F_yv4_temp[2] = c11_b_F_yv4.rl;
  c11_F_yv4_temp[3] = c11_b_F_yv4.rr;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 21);
  c11_F_z4_temp[0] = c11_b_F_z4.fl;
  c11_F_z4_temp[1] = c11_b_F_z4.fr;
  c11_F_z4_temp[2] = c11_b_F_z4.rl;
  c11_F_z4_temp[3] = c11_b_F_z4.rr;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 24);
  c11_i2 = 0;
  for (c11_i3 = 0; c11_i3 < 4; c11_i3++) {
    c11_a[c11_i2] = 0.0;
    c11_i2 += 3;
  }

  c11_i4 = 0;
  for (c11_i5 = 0; c11_i5 < 4; c11_i5++) {
    c11_a[c11_i4 + 1] = 0.0;
    c11_i4 += 3;
  }

  c11_a[2] = -c11_h;
  c11_a[5] = -c11_h;
  c11_a[8] = -c11_h;
  c11_a[11] = -c11_h;
  for (c11_i6 = 0; c11_i6 < 4; c11_i6++) {
    c11_b[c11_i6] = c11_F_xv4_temp[c11_i6];
  }

  c11_eml_scalar_eg(chartInstance);
  c11_eml_scalar_eg(chartInstance);
  for (c11_i7 = 0; c11_i7 < 3; c11_i7++) {
    c11_y[c11_i7] = 0.0;
  }

  for (c11_i8 = 0; c11_i8 < 12; c11_i8++) {
    c11_b_a[c11_i8] = c11_a[c11_i8];
  }

  for (c11_i9 = 0; c11_i9 < 4; c11_i9++) {
    c11_b_b[c11_i9] = c11_b[c11_i9];
  }

  c11_b_eml_xgemm(chartInstance, c11_b_a, c11_b_b, c11_y);
  c11_i10 = 0;
  for (c11_i11 = 0; c11_i11 < 4; c11_i11++) {
    c11_a[c11_i10] = 0.0;
    c11_i10 += 3;
  }

  c11_a[1] = c11_h;
  c11_a[4] = c11_h;
  c11_a[7] = c11_h;
  c11_a[10] = c11_h;
  c11_i12 = 0;
  for (c11_i13 = 0; c11_i13 < 4; c11_i13++) {
    c11_a[c11_i12 + 2] = 0.0;
    c11_i12 += 3;
  }

  for (c11_i14 = 0; c11_i14 < 4; c11_i14++) {
    c11_b[c11_i14] = c11_F_yv4_temp[c11_i14];
  }

  c11_eml_scalar_eg(chartInstance);
  c11_eml_scalar_eg(chartInstance);
  for (c11_i15 = 0; c11_i15 < 3; c11_i15++) {
    c11_b_y[c11_i15] = 0.0;
  }

  for (c11_i16 = 0; c11_i16 < 12; c11_i16++) {
    c11_c_a[c11_i16] = c11_a[c11_i16];
  }

  for (c11_i17 = 0; c11_i17 < 4; c11_i17++) {
    c11_c_b[c11_i17] = c11_b[c11_i17];
  }

  c11_b_eml_xgemm(chartInstance, c11_c_a, c11_c_b, c11_b_y);
  for (c11_i18 = 0; c11_i18 < 12; c11_i18++) {
    c11_a[c11_i18] = c11_T_oorpv[c11_i18];
  }

  for (c11_i19 = 0; c11_i19 < 4; c11_i19++) {
    c11_b[c11_i19] = c11_F_z4_temp[c11_i19];
  }

  c11_eml_scalar_eg(chartInstance);
  c11_eml_scalar_eg(chartInstance);
  for (c11_i20 = 0; c11_i20 < 3; c11_i20++) {
    c11_c_y[c11_i20] = 0.0;
  }

  for (c11_i21 = 0; c11_i21 < 12; c11_i21++) {
    c11_d_a[c11_i21] = c11_a[c11_i21];
  }

  for (c11_i22 = 0; c11_i22 < 4; c11_i22++) {
    c11_d_b[c11_i22] = c11_b[c11_i22];
  }

  c11_b_eml_xgemm(chartInstance, c11_d_a, c11_d_b, c11_c_y);
  c11_c_Par[0] = -c11_b_Par.Veh.m * c11_b_Par.Env.g;
  c11_c_Par[1] = 0.0;
  c11_c_Par[2] = 0.0;
  for (c11_i23 = 0; c11_i23 < 3; c11_i23++) {
    c11_F_oorp3[c11_i23] = ((c11_y[c11_i23] + c11_b_y[c11_i23]) +
      c11_c_y[c11_i23]) + c11_c_Par[c11_i23];
  }

  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 29);
  c11_b_A = c11_F_oorp3[0];
  c11_B = c11_b_Par.Veh.m_sprung;
  c11_d_x = c11_b_A;
  c11_d_y = c11_B;
  c11_e_x = c11_d_x;
  c11_e_y = c11_d_y;
  c11_f_x = c11_e_x;
  c11_f_y = c11_e_y;
  c11_g_y = c11_f_x / c11_f_y;
  c11_b_derv_oorp3.z = c11_g_y;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 30);
  c11_c_A = c11_F_oorp3[1];
  c11_b_B = c11_b_Par.Veh.Jx_sprung;
  c11_g_x = c11_c_A;
  c11_h_y = c11_b_B;
  c11_h_x = c11_g_x;
  c11_i_y = c11_h_y;
  c11_i_x = c11_h_x;
  c11_j_y = c11_i_y;
  c11_k_y = c11_i_x / c11_j_y;
  c11_b_derv_oorp3.rotx = c11_k_y;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 31);
  c11_d_A = c11_F_oorp3[2];
  c11_c_B = c11_b_Par.Veh.Jy_sprung;
  c11_j_x = c11_d_A;
  c11_l_y = c11_c_B;
  c11_k_x = c11_j_x;
  c11_m_y = c11_l_y;
  c11_l_x = c11_k_x;
  c11_n_y = c11_m_y;
  c11_o_y = c11_l_x / c11_n_y;
  c11_b_derv_oorp3.roty = c11_o_y;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, -31);
  _SFD_SYMBOL_SCOPE_POP();
  *(real_T *)&((char_T *)chartInstance->c11_derv_oorp3)[0] = c11_b_derv_oorp3.z;
  *(real_T *)&((char_T *)chartInstance->c11_derv_oorp3)[8] =
    c11_b_derv_oorp3.rotx;
  *(real_T *)&((char_T *)chartInstance->c11_derv_oorp3)[16] =
    c11_b_derv_oorp3.roty;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c11_sfEvent);
}

static void initSimStructsc11_Modified2(SFc11_Modified2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber, uint32_T c11_instanceNumber)
{
  (void)c11_machineNumber;
  (void)c11_chartNumber;
  (void)c11_instanceNumber;
}

static const mxArray *c11_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  c11_oorp_vec3 c11_u;
  const mxArray *c11_y = NULL;
  real_T c11_b_u;
  const mxArray *c11_b_y = NULL;
  real_T c11_c_u;
  const mxArray *c11_c_y = NULL;
  real_T c11_d_u;
  const mxArray *c11_d_y = NULL;
  SFc11_Modified2InstanceStruct *chartInstance;
  chartInstance = (SFc11_Modified2InstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(c11_oorp_vec3 *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c11_b_u = c11_u.z;
  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", &c11_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c11_y, c11_b_y, "z", "z", 0);
  c11_c_u = c11_u.rotx;
  c11_c_y = NULL;
  sf_mex_assign(&c11_c_y, sf_mex_create("y", &c11_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c11_y, c11_c_y, "rotx", "rotx", 0);
  c11_d_u = c11_u.roty;
  c11_d_y = NULL;
  sf_mex_assign(&c11_d_y, sf_mex_create("y", &c11_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c11_y, c11_d_y, "roty", "roty", 0);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static c11_oorp_vec3 c11_emlrt_marshallIn(SFc11_Modified2InstanceStruct
  *chartInstance, const mxArray *c11_b_derv_oorp3, const char_T *c11_identifier)
{
  c11_oorp_vec3 c11_y;
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_derv_oorp3),
    &c11_thisId);
  sf_mex_destroy(&c11_b_derv_oorp3);
  return c11_y;
}

static c11_oorp_vec3 c11_b_emlrt_marshallIn(SFc11_Modified2InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  c11_oorp_vec3 c11_y;
  emlrtMsgIdentifier c11_thisId;
  static const char * c11_fieldNames[3] = { "z", "rotx", "roty" };

  c11_thisId.fParent = c11_parentId;
  sf_mex_check_struct(c11_parentId, c11_u, 3, c11_fieldNames, 0U, NULL);
  c11_thisId.fIdentifier = "z";
  c11_y.z = c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c11_u, "z", "z", 0)), &c11_thisId);
  c11_thisId.fIdentifier = "rotx";
  c11_y.rotx = c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c11_u, "rotx", "rotx", 0)), &c11_thisId);
  c11_thisId.fIdentifier = "roty";
  c11_y.roty = c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c11_u, "roty", "roty", 0)), &c11_thisId);
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static real_T c11_c_emlrt_marshallIn(SFc11_Modified2InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  real_T c11_y;
  real_T c11_d0;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_d0, 1, 0, 0U, 0, 0U, 0);
  c11_y = c11_d0;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_b_derv_oorp3;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  c11_oorp_vec3 c11_y;
  SFc11_Modified2InstanceStruct *chartInstance;
  chartInstance = (SFc11_Modified2InstanceStruct *)chartInstanceVoid;
  c11_b_derv_oorp3 = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_derv_oorp3),
    &c11_thisId);
  sf_mex_destroy(&c11_b_derv_oorp3);
  *(c11_oorp_vec3 *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_b_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData;
  c11_struct_iBlsPBO3AGnt69vDoTx5zD c11_u;
  const mxArray *c11_y = NULL;
  c11_struct_Nst2vGTExxHsg85EUOj9EH c11_b_u;
  const mxArray *c11_b_y = NULL;
  real_T c11_c_u;
  const mxArray *c11_c_y = NULL;
  c11_struct_HhckT6rntEraqECYVIDvCC c11_d_u;
  const mxArray *c11_d_y = NULL;
  real_T c11_e_u;
  const mxArray *c11_e_y = NULL;
  real_T c11_f_u;
  const mxArray *c11_f_y = NULL;
  const mxArray *c11_g_y = NULL;
  real_T c11_g_u;
  const mxArray *c11_h_y = NULL;
  real_T c11_h_u;
  const mxArray *c11_i_y = NULL;
  const mxArray *c11_j_y = NULL;
  real_T c11_i_u;
  const mxArray *c11_k_y = NULL;
  real_T c11_j_u;
  const mxArray *c11_l_y = NULL;
  const mxArray *c11_m_y = NULL;
  real_T c11_k_u;
  const mxArray *c11_n_y = NULL;
  real_T c11_l_u;
  const mxArray *c11_o_y = NULL;
  const mxArray *c11_p_y = NULL;
  real_T c11_m_u;
  const mxArray *c11_q_y = NULL;
  real_T c11_n_u;
  const mxArray *c11_r_y = NULL;
  real_T c11_o_u;
  const mxArray *c11_s_y = NULL;
  c11_struct_ZCmOWPuqBDw16FSOVVD00 c11_p_u;
  const mxArray *c11_t_y = NULL;
  real_T c11_q_u;
  const mxArray *c11_u_y = NULL;
  real_T c11_r_u;
  const mxArray *c11_v_y = NULL;
  real_T c11_s_u;
  const mxArray *c11_w_y = NULL;
  real_T c11_t_u;
  const mxArray *c11_x_y = NULL;
  real_T c11_u_u;
  const mxArray *c11_y_y = NULL;
  real_T c11_v_u;
  const mxArray *c11_ab_y = NULL;
  real_T c11_w_u;
  const mxArray *c11_bb_y = NULL;
  real_T c11_x_u;
  const mxArray *c11_cb_y = NULL;
  real_T c11_y_u;
  const mxArray *c11_db_y = NULL;
  real_T c11_ab_u;
  const mxArray *c11_eb_y = NULL;
  real_T c11_bb_u;
  const mxArray *c11_fb_y = NULL;
  int32_T c11_i24;
  real_T c11_cb_u[4];
  const mxArray *c11_gb_y = NULL;
  real_T c11_db_u;
  const mxArray *c11_hb_y = NULL;
  c11_struct_ZKAzdrl7umDGJoC14aoVKC c11_eb_u;
  const mxArray *c11_ib_y = NULL;
  int32_T c11_i25;
  real_T c11_fb_u[3];
  const mxArray *c11_jb_y = NULL;
  int32_T c11_i26;
  real_T c11_gb_u[3];
  const mxArray *c11_kb_y = NULL;
  int32_T c11_i27;
  real_T c11_hb_u[3];
  const mxArray *c11_lb_y = NULL;
  int32_T c11_i28;
  real_T c11_ib_u[3];
  const mxArray *c11_mb_y = NULL;
  const mxArray *c11_nb_y = NULL;
  int32_T c11_i29;
  real_T c11_jb_u[3];
  const mxArray *c11_ob_y = NULL;
  int32_T c11_i30;
  real_T c11_kb_u[3];
  const mxArray *c11_pb_y = NULL;
  int32_T c11_i31;
  real_T c11_lb_u[3];
  const mxArray *c11_qb_y = NULL;
  int32_T c11_i32;
  real_T c11_mb_u[3];
  const mxArray *c11_rb_y = NULL;
  const mxArray *c11_sb_y = NULL;
  int32_T c11_i33;
  real_T c11_nb_u[3];
  const mxArray *c11_tb_y = NULL;
  int32_T c11_i34;
  real_T c11_ob_u[3];
  const mxArray *c11_ub_y = NULL;
  int32_T c11_i35;
  real_T c11_pb_u[3];
  const mxArray *c11_vb_y = NULL;
  int32_T c11_i36;
  real_T c11_qb_u[3];
  const mxArray *c11_wb_y = NULL;
  const mxArray *c11_xb_y = NULL;
  int32_T c11_i37;
  real_T c11_rb_u[3];
  const mxArray *c11_yb_y = NULL;
  int32_T c11_i38;
  real_T c11_sb_u[3];
  const mxArray *c11_ac_y = NULL;
  int32_T c11_i39;
  real_T c11_tb_u[3];
  const mxArray *c11_bc_y = NULL;
  int32_T c11_i40;
  real_T c11_ub_u[3];
  const mxArray *c11_cc_y = NULL;
  real_T c11_vb_u;
  const mxArray *c11_dc_y = NULL;
  real_T c11_wb_u;
  const mxArray *c11_ec_y = NULL;
  real_T c11_xb_u;
  const mxArray *c11_fc_y = NULL;
  real_T c11_yb_u;
  const mxArray *c11_gc_y = NULL;
  real_T c11_ac_u;
  const mxArray *c11_hc_y = NULL;
  real_T c11_bc_u;
  const mxArray *c11_ic_y = NULL;
  real_T c11_cc_u;
  const mxArray *c11_jc_y = NULL;
  real_T c11_dc_u;
  const mxArray *c11_kc_y = NULL;
  real_T c11_ec_u;
  const mxArray *c11_lc_y = NULL;
  real_T c11_fc_u;
  const mxArray *c11_mc_y = NULL;
  real_T c11_gc_u;
  const mxArray *c11_nc_y = NULL;
  real_T c11_hc_u;
  const mxArray *c11_oc_y = NULL;
  c11_struct_r4FNviKwHfdhB8nQjvQv9 c11_ic_u;
  const mxArray *c11_pc_y = NULL;
  real_T c11_jc_u;
  const mxArray *c11_qc_y = NULL;
  c11_struct_Y9F1qlBi9AhssksPwemA4G c11_kc_u;
  const mxArray *c11_rc_y = NULL;
  real_T c11_lc_u;
  const mxArray *c11_sc_y = NULL;
  real_T c11_mc_u;
  const mxArray *c11_tc_y = NULL;
  real_T c11_nc_u;
  const mxArray *c11_uc_y = NULL;
  SFc11_Modified2InstanceStruct *chartInstance;
  chartInstance = (SFc11_Modified2InstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_mxArrayOutData = NULL;
  c11_u = *(c11_struct_iBlsPBO3AGnt69vDoTx5zD *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c11_b_u = c11_u.Env;
  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c11_c_u = c11_b_u.g;
  c11_c_y = NULL;
  sf_mex_assign(&c11_c_y, sf_mex_create("y", &c11_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c11_b_y, c11_c_y, "g", "g", 0);
  c11_d_u = c11_b_u.left1;
  c11_d_y = NULL;
  sf_mex_assign(&c11_d_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c11_e_u = c11_d_u.x;
  c11_e_y = NULL;
  sf_mex_assign(&c11_e_y, sf_mex_create("y", &c11_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c11_d_y, c11_e_y, "x", "x", 0);
  c11_f_u = c11_d_u.y;
  c11_f_y = NULL;
  sf_mex_assign(&c11_f_y, sf_mex_create("y", &c11_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c11_d_y, c11_f_y, "y", "y", 0);
  sf_mex_addfield(c11_b_y, c11_d_y, "left1", "left1", 0);
  c11_d_u = c11_b_u.right1;
  c11_g_y = NULL;
  sf_mex_assign(&c11_g_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c11_g_u = c11_d_u.x;
  c11_h_y = NULL;
  sf_mex_assign(&c11_h_y, sf_mex_create("y", &c11_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c11_g_y, c11_h_y, "x", "x", 0);
  c11_h_u = c11_d_u.y;
  c11_i_y = NULL;
  sf_mex_assign(&c11_i_y, sf_mex_create("y", &c11_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c11_g_y, c11_i_y, "y", "y", 0);
  sf_mex_addfield(c11_b_y, c11_g_y, "right1", "right1", 0);
  c11_d_u = c11_b_u.right2;
  c11_j_y = NULL;
  sf_mex_assign(&c11_j_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c11_i_u = c11_d_u.x;
  c11_k_y = NULL;
  sf_mex_assign(&c11_k_y, sf_mex_create("y", &c11_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c11_j_y, c11_k_y, "x", "x", 0);
  c11_j_u = c11_d_u.y;
  c11_l_y = NULL;
  sf_mex_assign(&c11_l_y, sf_mex_create("y", &c11_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c11_j_y, c11_l_y, "y", "y", 0);
  sf_mex_addfield(c11_b_y, c11_j_y, "right2", "right2", 0);
  c11_d_u = c11_b_u.left2;
  c11_m_y = NULL;
  sf_mex_assign(&c11_m_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c11_k_u = c11_d_u.x;
  c11_n_y = NULL;
  sf_mex_assign(&c11_n_y, sf_mex_create("y", &c11_k_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c11_m_y, c11_n_y, "x", "x", 0);
  c11_l_u = c11_d_u.y;
  c11_o_y = NULL;
  sf_mex_assign(&c11_o_y, sf_mex_create("y", &c11_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c11_m_y, c11_o_y, "y", "y", 0);
  sf_mex_addfield(c11_b_y, c11_m_y, "left2", "left2", 0);
  c11_d_u = c11_b_u.right3;
  c11_p_y = NULL;
  sf_mex_assign(&c11_p_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c11_m_u = c11_d_u.x;
  c11_q_y = NULL;
  sf_mex_assign(&c11_q_y, sf_mex_create("y", &c11_m_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c11_p_y, c11_q_y, "x", "x", 0);
  c11_n_u = c11_d_u.y;
  c11_r_y = NULL;
  sf_mex_assign(&c11_r_y, sf_mex_create("y", &c11_n_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c11_p_y, c11_r_y, "y", "y", 0);
  sf_mex_addfield(c11_b_y, c11_p_y, "right3", "right3", 0);
  c11_o_u = c11_b_u.mu;
  c11_s_y = NULL;
  sf_mex_assign(&c11_s_y, sf_mex_create("y", &c11_o_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c11_b_y, c11_s_y, "mu", "mu", 0);
  sf_mex_addfield(c11_y, c11_b_y, "Env", "Env", 0);
  c11_p_u = c11_u.Veh;
  c11_t_y = NULL;
  sf_mex_assign(&c11_t_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c11_q_u = c11_p_u.m;
  c11_u_y = NULL;
  sf_mex_assign(&c11_u_y, sf_mex_create("y", &c11_q_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c11_t_y, c11_u_y, "m", "m", 0);
  c11_r_u = c11_p_u.Jz;
  c11_v_y = NULL;
  sf_mex_assign(&c11_v_y, sf_mex_create("y", &c11_r_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c11_t_y, c11_v_y, "Jz", "Jz", 0);
  c11_s_u = c11_p_u.m_sprung;
  c11_w_y = NULL;
  sf_mex_assign(&c11_w_y, sf_mex_create("y", &c11_s_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c11_t_y, c11_w_y, "m_sprung", "m_sprung", 0);
  c11_t_u = c11_p_u.Jx_sprung;
  c11_x_y = NULL;
  sf_mex_assign(&c11_x_y, sf_mex_create("y", &c11_t_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c11_t_y, c11_x_y, "Jx_sprung", "Jx_sprung", 0);
  c11_u_u = c11_p_u.Jy_sprung;
  c11_y_y = NULL;
  sf_mex_assign(&c11_y_y, sf_mex_create("y", &c11_u_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c11_t_y, c11_y_y, "Jy_sprung", "Jy_sprung", 0);
  c11_v_u = c11_p_u.lf;
  c11_ab_y = NULL;
  sf_mex_assign(&c11_ab_y, sf_mex_create("y", &c11_v_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c11_t_y, c11_ab_y, "lf", "lf", 0);
  c11_w_u = c11_p_u.lr;
  c11_bb_y = NULL;
  sf_mex_assign(&c11_bb_y, sf_mex_create("y", &c11_w_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c11_t_y, c11_bb_y, "lr", "lr", 0);
  c11_x_u = c11_p_u.L;
  c11_cb_y = NULL;
  sf_mex_assign(&c11_cb_y, sf_mex_create("y", &c11_x_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c11_t_y, c11_cb_y, "L", "L", 0);
  c11_y_u = c11_p_u.TrackWidth;
  c11_db_y = NULL;
  sf_mex_assign(&c11_db_y, sf_mex_create("y", &c11_y_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c11_t_y, c11_db_y, "TrackWidth", "TrackWidth", 0);
  c11_ab_u = c11_p_u.h;
  c11_eb_y = NULL;
  sf_mex_assign(&c11_eb_y, sf_mex_create("y", &c11_ab_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c11_t_y, c11_eb_y, "h", "h", 0);
  c11_bb_u = c11_p_u.HalfRohACd;
  c11_fb_y = NULL;
  sf_mex_assign(&c11_fb_y, sf_mex_create("y", &c11_bb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c11_t_y, c11_fb_y, "HalfRohACd", "HalfRohACd", 0);
  for (c11_i24 = 0; c11_i24 < 4; c11_i24++) {
    c11_cb_u[c11_i24] = c11_p_u.F_z4_static[c11_i24];
  }

  c11_gb_y = NULL;
  sf_mex_assign(&c11_gb_y, sf_mex_create("y", c11_cb_u, 0, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_addfield(c11_t_y, c11_gb_y, "F_z4_static", "F_z4_static", 0);
  c11_db_u = c11_p_u.Rw;
  c11_hb_y = NULL;
  sf_mex_assign(&c11_hb_y, sf_mex_create("y", &c11_db_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c11_t_y, c11_hb_y, "Rw", "Rw", 0);
  c11_eb_u = c11_p_u.r_long;
  c11_ib_y = NULL;
  sf_mex_assign(&c11_ib_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c11_i25 = 0; c11_i25 < 3; c11_i25++) {
    c11_fb_u[c11_i25] = c11_eb_u.fl[c11_i25];
  }

  c11_jb_y = NULL;
  sf_mex_assign(&c11_jb_y, sf_mex_create("y", c11_fb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c11_ib_y, c11_jb_y, "fl", "fl", 0);
  for (c11_i26 = 0; c11_i26 < 3; c11_i26++) {
    c11_gb_u[c11_i26] = c11_eb_u.fr[c11_i26];
  }

  c11_kb_y = NULL;
  sf_mex_assign(&c11_kb_y, sf_mex_create("y", c11_gb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c11_ib_y, c11_kb_y, "fr", "fr", 0);
  for (c11_i27 = 0; c11_i27 < 3; c11_i27++) {
    c11_hb_u[c11_i27] = c11_eb_u.rl[c11_i27];
  }

  c11_lb_y = NULL;
  sf_mex_assign(&c11_lb_y, sf_mex_create("y", c11_hb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c11_ib_y, c11_lb_y, "rl", "rl", 0);
  for (c11_i28 = 0; c11_i28 < 3; c11_i28++) {
    c11_ib_u[c11_i28] = c11_eb_u.rr[c11_i28];
  }

  c11_mb_y = NULL;
  sf_mex_assign(&c11_mb_y, sf_mex_create("y", c11_ib_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c11_ib_y, c11_mb_y, "rr", "rr", 0);
  sf_mex_addfield(c11_t_y, c11_ib_y, "r_long", "r_long", 0);
  c11_eb_u = c11_p_u.r_lat;
  c11_nb_y = NULL;
  sf_mex_assign(&c11_nb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c11_i29 = 0; c11_i29 < 3; c11_i29++) {
    c11_jb_u[c11_i29] = c11_eb_u.fl[c11_i29];
  }

  c11_ob_y = NULL;
  sf_mex_assign(&c11_ob_y, sf_mex_create("y", c11_jb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c11_nb_y, c11_ob_y, "fl", "fl", 0);
  for (c11_i30 = 0; c11_i30 < 3; c11_i30++) {
    c11_kb_u[c11_i30] = c11_eb_u.fr[c11_i30];
  }

  c11_pb_y = NULL;
  sf_mex_assign(&c11_pb_y, sf_mex_create("y", c11_kb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c11_nb_y, c11_pb_y, "fr", "fr", 0);
  for (c11_i31 = 0; c11_i31 < 3; c11_i31++) {
    c11_lb_u[c11_i31] = c11_eb_u.rl[c11_i31];
  }

  c11_qb_y = NULL;
  sf_mex_assign(&c11_qb_y, sf_mex_create("y", c11_lb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c11_nb_y, c11_qb_y, "rl", "rl", 0);
  for (c11_i32 = 0; c11_i32 < 3; c11_i32++) {
    c11_mb_u[c11_i32] = c11_eb_u.rr[c11_i32];
  }

  c11_rb_y = NULL;
  sf_mex_assign(&c11_rb_y, sf_mex_create("y", c11_mb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c11_nb_y, c11_rb_y, "rr", "rr", 0);
  sf_mex_addfield(c11_t_y, c11_nb_y, "r_lat", "r_lat", 0);
  c11_eb_u = c11_p_u.r_lever;
  c11_sb_y = NULL;
  sf_mex_assign(&c11_sb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c11_i33 = 0; c11_i33 < 3; c11_i33++) {
    c11_nb_u[c11_i33] = c11_eb_u.fl[c11_i33];
  }

  c11_tb_y = NULL;
  sf_mex_assign(&c11_tb_y, sf_mex_create("y", c11_nb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c11_sb_y, c11_tb_y, "fl", "fl", 0);
  for (c11_i34 = 0; c11_i34 < 3; c11_i34++) {
    c11_ob_u[c11_i34] = c11_eb_u.fr[c11_i34];
  }

  c11_ub_y = NULL;
  sf_mex_assign(&c11_ub_y, sf_mex_create("y", c11_ob_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c11_sb_y, c11_ub_y, "fr", "fr", 0);
  for (c11_i35 = 0; c11_i35 < 3; c11_i35++) {
    c11_pb_u[c11_i35] = c11_eb_u.rl[c11_i35];
  }

  c11_vb_y = NULL;
  sf_mex_assign(&c11_vb_y, sf_mex_create("y", c11_pb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c11_sb_y, c11_vb_y, "rl", "rl", 0);
  for (c11_i36 = 0; c11_i36 < 3; c11_i36++) {
    c11_qb_u[c11_i36] = c11_eb_u.rr[c11_i36];
  }

  c11_wb_y = NULL;
  sf_mex_assign(&c11_wb_y, sf_mex_create("y", c11_qb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c11_sb_y, c11_wb_y, "rr", "rr", 0);
  sf_mex_addfield(c11_t_y, c11_sb_y, "r_lever", "r_lever", 0);
  c11_eb_u = c11_p_u.r_pivot;
  c11_xb_y = NULL;
  sf_mex_assign(&c11_xb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c11_i37 = 0; c11_i37 < 3; c11_i37++) {
    c11_rb_u[c11_i37] = c11_eb_u.fl[c11_i37];
  }

  c11_yb_y = NULL;
  sf_mex_assign(&c11_yb_y, sf_mex_create("y", c11_rb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c11_xb_y, c11_yb_y, "fl", "fl", 0);
  for (c11_i38 = 0; c11_i38 < 3; c11_i38++) {
    c11_sb_u[c11_i38] = c11_eb_u.fr[c11_i38];
  }

  c11_ac_y = NULL;
  sf_mex_assign(&c11_ac_y, sf_mex_create("y", c11_sb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c11_xb_y, c11_ac_y, "fr", "fr", 0);
  for (c11_i39 = 0; c11_i39 < 3; c11_i39++) {
    c11_tb_u[c11_i39] = c11_eb_u.rl[c11_i39];
  }

  c11_bc_y = NULL;
  sf_mex_assign(&c11_bc_y, sf_mex_create("y", c11_tb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c11_xb_y, c11_bc_y, "rl", "rl", 0);
  for (c11_i40 = 0; c11_i40 < 3; c11_i40++) {
    c11_ub_u[c11_i40] = c11_eb_u.rr[c11_i40];
  }

  c11_cc_y = NULL;
  sf_mex_assign(&c11_cc_y, sf_mex_create("y", c11_ub_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c11_xb_y, c11_cc_y, "rr", "rr", 0);
  sf_mex_addfield(c11_t_y, c11_xb_y, "r_pivot", "r_pivot", 0);
  c11_vb_u = c11_p_u.cw;
  c11_dc_y = NULL;
  sf_mex_assign(&c11_dc_y, sf_mex_create("y", &c11_vb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c11_t_y, c11_dc_y, "cw", "cw", 0);
  c11_wb_u = c11_p_u.carb_f;
  c11_ec_y = NULL;
  sf_mex_assign(&c11_ec_y, sf_mex_create("y", &c11_wb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c11_t_y, c11_ec_y, "carb_f", "carb_f", 0);
  c11_xb_u = c11_p_u.carb_r;
  c11_fc_y = NULL;
  sf_mex_assign(&c11_fc_y, sf_mex_create("y", &c11_xb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c11_t_y, c11_fc_y, "carb_r", "carb_r", 0);
  c11_yb_u = c11_p_u.dw;
  c11_gc_y = NULL;
  sf_mex_assign(&c11_gc_y, sf_mex_create("y", &c11_yb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c11_t_y, c11_gc_y, "dw", "dw", 0);
  c11_ac_u = c11_p_u.Jw;
  c11_hc_y = NULL;
  sf_mex_assign(&c11_hc_y, sf_mex_create("y", &c11_ac_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c11_t_y, c11_hc_y, "Jw", "Jw", 0);
  c11_bc_u = c11_p_u.C0;
  c11_ic_y = NULL;
  sf_mex_assign(&c11_ic_y, sf_mex_create("y", &c11_bc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c11_t_y, c11_ic_y, "C0", "C0", 0);
  c11_cc_u = c11_p_u.RelaxLength;
  c11_jc_y = NULL;
  sf_mex_assign(&c11_jc_y, sf_mex_create("y", &c11_cc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c11_t_y, c11_jc_y, "RelaxLength", "RelaxLength", 0);
  c11_dc_u = c11_p_u.RRC;
  c11_kc_y = NULL;
  sf_mex_assign(&c11_kc_y, sf_mex_create("y", &c11_dc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c11_t_y, c11_kc_y, "RRC", "RRC", 0);
  c11_ec_u = c11_p_u.Pmax;
  c11_lc_y = NULL;
  sf_mex_assign(&c11_lc_y, sf_mex_create("y", &c11_ec_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c11_t_y, c11_lc_y, "Pmax", "Pmax", 0);
  c11_fc_u = c11_p_u.PropDistrFrnt;
  c11_mc_y = NULL;
  sf_mex_assign(&c11_mc_y, sf_mex_create("y", &c11_fc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c11_t_y, c11_mc_y, "PropDistrFrnt", "PropDistrFrnt", 0);
  c11_gc_u = c11_p_u.BrkDistrFrnt;
  c11_nc_y = NULL;
  sf_mex_assign(&c11_nc_y, sf_mex_create("y", &c11_gc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c11_t_y, c11_nc_y, "BrkDistrFrnt", "BrkDistrFrnt", 0);
  c11_hc_u = c11_p_u.SteRatio;
  c11_oc_y = NULL;
  sf_mex_assign(&c11_oc_y, sf_mex_create("y", &c11_hc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c11_t_y, c11_oc_y, "SteRatio", "SteRatio", 0);
  sf_mex_addfield(c11_y, c11_t_y, "Veh", "Veh", 0);
  c11_ic_u = c11_u.Drvr;
  c11_pc_y = NULL;
  sf_mex_assign(&c11_pc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c11_jc_u = c11_ic_u.v_set;
  c11_qc_y = NULL;
  sf_mex_assign(&c11_qc_y, sf_mex_create("y", &c11_jc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c11_pc_y, c11_qc_y, "v_set", "v_set", 0);
  sf_mex_addfield(c11_y, c11_pc_y, "Drvr", "Drvr", 0);
  c11_kc_u = c11_u.Init;
  c11_rc_y = NULL;
  sf_mex_assign(&c11_rc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c11_lc_u = c11_kc_u.v_x;
  c11_sc_y = NULL;
  sf_mex_assign(&c11_sc_y, sf_mex_create("y", &c11_lc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c11_rc_y, c11_sc_y, "v_x", "v_x", 0);
  c11_mc_u = c11_kc_u.F_fz;
  c11_tc_y = NULL;
  sf_mex_assign(&c11_tc_y, sf_mex_create("y", &c11_mc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c11_rc_y, c11_tc_y, "F_fz", "F_fz", 0);
  c11_nc_u = c11_kc_u.F_rz;
  c11_uc_y = NULL;
  sf_mex_assign(&c11_uc_y, sf_mex_create("y", &c11_nc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c11_rc_y, c11_uc_y, "F_rz", "F_rz", 0);
  sf_mex_addfield(c11_y, c11_rc_y, "Init", "Init", 0);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static void c11_d_emlrt_marshallIn(SFc11_Modified2InstanceStruct *chartInstance,
  const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  c11_struct_iBlsPBO3AGnt69vDoTx5zD *c11_y)
{
  emlrtMsgIdentifier c11_thisId;
  static const char * c11_fieldNames[4] = { "Env", "Veh", "Drvr", "Init" };

  c11_thisId.fParent = c11_parentId;
  sf_mex_check_struct(c11_parentId, c11_u, 4, c11_fieldNames, 0U, NULL);
  c11_thisId.fIdentifier = "Env";
  c11_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c11_u, "Env",
    "Env", 0)), &c11_thisId, &c11_y->Env);
  c11_thisId.fIdentifier = "Veh";
  c11_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c11_u, "Veh",
    "Veh", 0)), &c11_thisId, &c11_y->Veh);
  c11_thisId.fIdentifier = "Drvr";
  c11_y->Drvr = c11_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c11_u, "Drvr", "Drvr", 0)), &c11_thisId);
  c11_thisId.fIdentifier = "Init";
  c11_y->Init = c11_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c11_u, "Init", "Init", 0)), &c11_thisId);
  sf_mex_destroy(&c11_u);
}

static void c11_e_emlrt_marshallIn(SFc11_Modified2InstanceStruct *chartInstance,
  const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  c11_struct_Nst2vGTExxHsg85EUOj9EH *c11_y)
{
  emlrtMsgIdentifier c11_thisId;
  static const char * c11_fieldNames[7] = { "g", "left1", "right1", "right2",
    "left2", "right3", "mu" };

  c11_thisId.fParent = c11_parentId;
  sf_mex_check_struct(c11_parentId, c11_u, 7, c11_fieldNames, 0U, NULL);
  c11_thisId.fIdentifier = "g";
  c11_y->g = c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c11_u, "g", "g", 0)), &c11_thisId);
  c11_thisId.fIdentifier = "left1";
  c11_y->left1 = c11_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c11_u, "left1", "left1", 0)), &c11_thisId);
  c11_thisId.fIdentifier = "right1";
  c11_y->right1 = c11_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c11_u, "right1", "right1", 0)), &c11_thisId);
  c11_thisId.fIdentifier = "right2";
  c11_y->right2 = c11_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c11_u, "right2", "right2", 0)), &c11_thisId);
  c11_thisId.fIdentifier = "left2";
  c11_y->left2 = c11_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c11_u, "left2", "left2", 0)), &c11_thisId);
  c11_thisId.fIdentifier = "right3";
  c11_y->right3 = c11_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c11_u, "right3", "right3", 0)), &c11_thisId);
  c11_thisId.fIdentifier = "mu";
  c11_y->mu = c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c11_u, "mu", "mu", 0)), &c11_thisId);
  sf_mex_destroy(&c11_u);
}

static c11_struct_HhckT6rntEraqECYVIDvCC c11_f_emlrt_marshallIn
  (SFc11_Modified2InstanceStruct *chartInstance, const mxArray *c11_u, const
   emlrtMsgIdentifier *c11_parentId)
{
  c11_struct_HhckT6rntEraqECYVIDvCC c11_y;
  emlrtMsgIdentifier c11_thisId;
  static const char * c11_fieldNames[2] = { "x", "y" };

  c11_thisId.fParent = c11_parentId;
  sf_mex_check_struct(c11_parentId, c11_u, 2, c11_fieldNames, 0U, NULL);
  c11_thisId.fIdentifier = "x";
  c11_y.x = c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c11_u, "x", "x", 0)), &c11_thisId);
  c11_thisId.fIdentifier = "y";
  c11_y.y = c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c11_u, "y", "y", 0)), &c11_thisId);
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_g_emlrt_marshallIn(SFc11_Modified2InstanceStruct *chartInstance,
  const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  c11_struct_ZCmOWPuqBDw16FSOVVD00 *c11_y)
{
  emlrtMsgIdentifier c11_thisId;
  static const char * c11_fieldNames[29] = { "m", "Jz", "m_sprung", "Jx_sprung",
    "Jy_sprung", "lf", "lr", "L", "TrackWidth", "h", "HalfRohACd", "F_z4_static",
    "Rw", "r_long", "r_lat", "r_lever", "r_pivot", "cw", "carb_f", "carb_r",
    "dw", "Jw", "C0", "RelaxLength", "RRC", "Pmax", "PropDistrFrnt",
    "BrkDistrFrnt", "SteRatio" };

  c11_thisId.fParent = c11_parentId;
  sf_mex_check_struct(c11_parentId, c11_u, 29, c11_fieldNames, 0U, NULL);
  c11_thisId.fIdentifier = "m";
  c11_y->m = c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c11_u, "m", "m", 0)), &c11_thisId);
  c11_thisId.fIdentifier = "Jz";
  c11_y->Jz = c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c11_u, "Jz", "Jz", 0)), &c11_thisId);
  c11_thisId.fIdentifier = "m_sprung";
  c11_y->m_sprung = c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c11_u, "m_sprung", "m_sprung", 0)), &c11_thisId);
  c11_thisId.fIdentifier = "Jx_sprung";
  c11_y->Jx_sprung = c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c11_u, "Jx_sprung", "Jx_sprung", 0)), &c11_thisId);
  c11_thisId.fIdentifier = "Jy_sprung";
  c11_y->Jy_sprung = c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c11_u, "Jy_sprung", "Jy_sprung", 0)), &c11_thisId);
  c11_thisId.fIdentifier = "lf";
  c11_y->lf = c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c11_u, "lf", "lf", 0)), &c11_thisId);
  c11_thisId.fIdentifier = "lr";
  c11_y->lr = c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c11_u, "lr", "lr", 0)), &c11_thisId);
  c11_thisId.fIdentifier = "L";
  c11_y->L = c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c11_u, "L", "L", 0)), &c11_thisId);
  c11_thisId.fIdentifier = "TrackWidth";
  c11_y->TrackWidth = c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c11_u, "TrackWidth", "TrackWidth", 0)), &c11_thisId);
  c11_thisId.fIdentifier = "h";
  c11_y->h = c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c11_u, "h", "h", 0)), &c11_thisId);
  c11_thisId.fIdentifier = "HalfRohACd";
  c11_y->HalfRohACd = c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c11_u, "HalfRohACd", "HalfRohACd", 0)), &c11_thisId);
  c11_thisId.fIdentifier = "F_z4_static";
  c11_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c11_u,
    "F_z4_static", "F_z4_static", 0)), &c11_thisId, c11_y->F_z4_static);
  c11_thisId.fIdentifier = "Rw";
  c11_y->Rw = c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c11_u, "Rw", "Rw", 0)), &c11_thisId);
  c11_thisId.fIdentifier = "r_long";
  c11_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c11_u,
    "r_long", "r_long", 0)), &c11_thisId, &c11_y->r_long);
  c11_thisId.fIdentifier = "r_lat";
  c11_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c11_u,
    "r_lat", "r_lat", 0)), &c11_thisId, &c11_y->r_lat);
  c11_thisId.fIdentifier = "r_lever";
  c11_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c11_u,
    "r_lever", "r_lever", 0)), &c11_thisId, &c11_y->r_lever);
  c11_thisId.fIdentifier = "r_pivot";
  c11_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c11_u,
    "r_pivot", "r_pivot", 0)), &c11_thisId, &c11_y->r_pivot);
  c11_thisId.fIdentifier = "cw";
  c11_y->cw = c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c11_u, "cw", "cw", 0)), &c11_thisId);
  c11_thisId.fIdentifier = "carb_f";
  c11_y->carb_f = c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c11_u, "carb_f", "carb_f", 0)), &c11_thisId);
  c11_thisId.fIdentifier = "carb_r";
  c11_y->carb_r = c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c11_u, "carb_r", "carb_r", 0)), &c11_thisId);
  c11_thisId.fIdentifier = "dw";
  c11_y->dw = c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c11_u, "dw", "dw", 0)), &c11_thisId);
  c11_thisId.fIdentifier = "Jw";
  c11_y->Jw = c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c11_u, "Jw", "Jw", 0)), &c11_thisId);
  c11_thisId.fIdentifier = "C0";
  c11_y->C0 = c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c11_u, "C0", "C0", 0)), &c11_thisId);
  c11_thisId.fIdentifier = "RelaxLength";
  c11_y->RelaxLength = c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c11_u, "RelaxLength", "RelaxLength", 0)), &c11_thisId);
  c11_thisId.fIdentifier = "RRC";
  c11_y->RRC = c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c11_u, "RRC", "RRC", 0)), &c11_thisId);
  c11_thisId.fIdentifier = "Pmax";
  c11_y->Pmax = c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c11_u, "Pmax", "Pmax", 0)), &c11_thisId);
  c11_thisId.fIdentifier = "PropDistrFrnt";
  c11_y->PropDistrFrnt = c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c11_u, "PropDistrFrnt", "PropDistrFrnt", 0)), &c11_thisId);
  c11_thisId.fIdentifier = "BrkDistrFrnt";
  c11_y->BrkDistrFrnt = c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c11_u, "BrkDistrFrnt", "BrkDistrFrnt", 0)), &c11_thisId);
  c11_thisId.fIdentifier = "SteRatio";
  c11_y->SteRatio = c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c11_u, "SteRatio", "SteRatio", 0)), &c11_thisId);
  sf_mex_destroy(&c11_u);
}

static void c11_h_emlrt_marshallIn(SFc11_Modified2InstanceStruct *chartInstance,
  const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId, real_T c11_y[4])
{
  real_T c11_dv0[4];
  int32_T c11_i41;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_dv0, 1, 0, 0U, 1, 0U, 2, 1,
                4);
  for (c11_i41 = 0; c11_i41 < 4; c11_i41++) {
    c11_y[c11_i41] = c11_dv0[c11_i41];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_i_emlrt_marshallIn(SFc11_Modified2InstanceStruct *chartInstance,
  const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  c11_struct_ZKAzdrl7umDGJoC14aoVKC *c11_y)
{
  emlrtMsgIdentifier c11_thisId;
  static const char * c11_fieldNames[4] = { "fl", "fr", "rl", "rr" };

  c11_thisId.fParent = c11_parentId;
  sf_mex_check_struct(c11_parentId, c11_u, 4, c11_fieldNames, 0U, NULL);
  c11_thisId.fIdentifier = "fl";
  c11_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c11_u, "fl",
    "fl", 0)), &c11_thisId, c11_y->fl);
  c11_thisId.fIdentifier = "fr";
  c11_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c11_u, "fr",
    "fr", 0)), &c11_thisId, c11_y->fr);
  c11_thisId.fIdentifier = "rl";
  c11_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c11_u, "rl",
    "rl", 0)), &c11_thisId, c11_y->rl);
  c11_thisId.fIdentifier = "rr";
  c11_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c11_u, "rr",
    "rr", 0)), &c11_thisId, c11_y->rr);
  sf_mex_destroy(&c11_u);
}

static void c11_j_emlrt_marshallIn(SFc11_Modified2InstanceStruct *chartInstance,
  const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId, real_T c11_y[3])
{
  real_T c11_dv1[3];
  int32_T c11_i42;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_dv1, 1, 0, 0U, 1, 0U, 2, 3,
                1);
  for (c11_i42 = 0; c11_i42 < 3; c11_i42++) {
    c11_y[c11_i42] = c11_dv1[c11_i42];
  }

  sf_mex_destroy(&c11_u);
}

static c11_struct_r4FNviKwHfdhB8nQjvQv9 c11_k_emlrt_marshallIn
  (SFc11_Modified2InstanceStruct *chartInstance, const mxArray *c11_u, const
   emlrtMsgIdentifier *c11_parentId)
{
  c11_struct_r4FNviKwHfdhB8nQjvQv9 c11_y;
  emlrtMsgIdentifier c11_thisId;
  static const char * c11_fieldNames[1] = { "v_set" };

  c11_thisId.fParent = c11_parentId;
  sf_mex_check_struct(c11_parentId, c11_u, 1, c11_fieldNames, 0U, NULL);
  c11_thisId.fIdentifier = "v_set";
  c11_y.v_set = c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c11_u, "v_set", "v_set", 0)),
    &c11_thisId);
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static c11_struct_Y9F1qlBi9AhssksPwemA4G c11_l_emlrt_marshallIn
  (SFc11_Modified2InstanceStruct *chartInstance, const mxArray *c11_u, const
   emlrtMsgIdentifier *c11_parentId)
{
  c11_struct_Y9F1qlBi9AhssksPwemA4G c11_y;
  emlrtMsgIdentifier c11_thisId;
  static const char * c11_fieldNames[3] = { "v_x", "F_fz", "F_rz" };

  c11_thisId.fParent = c11_parentId;
  sf_mex_check_struct(c11_parentId, c11_u, 3, c11_fieldNames, 0U, NULL);
  c11_thisId.fIdentifier = "v_x";
  c11_y.v_x = c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c11_u, "v_x", "v_x", 0)), &c11_thisId);
  c11_thisId.fIdentifier = "F_fz";
  c11_y.F_fz = c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c11_u, "F_fz", "F_fz", 0)), &c11_thisId);
  c11_thisId.fIdentifier = "F_rz";
  c11_y.F_rz = c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c11_u, "F_rz", "F_rz", 0)), &c11_thisId);
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_b_Par;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  c11_struct_iBlsPBO3AGnt69vDoTx5zD c11_y;
  SFc11_Modified2InstanceStruct *chartInstance;
  chartInstance = (SFc11_Modified2InstanceStruct *)chartInstanceVoid;
  c11_b_Par = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_Par), &c11_thisId,
    &c11_y);
  sf_mex_destroy(&c11_b_Par);
  *(c11_struct_iBlsPBO3AGnt69vDoTx5zD *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_c_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  c11_whl_vec4 c11_u;
  const mxArray *c11_y = NULL;
  real_T c11_b_u;
  const mxArray *c11_b_y = NULL;
  real_T c11_c_u;
  const mxArray *c11_c_y = NULL;
  real_T c11_d_u;
  const mxArray *c11_d_y = NULL;
  real_T c11_e_u;
  const mxArray *c11_e_y = NULL;
  SFc11_Modified2InstanceStruct *chartInstance;
  chartInstance = (SFc11_Modified2InstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(c11_whl_vec4 *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c11_b_u = c11_u.fl;
  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", &c11_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c11_y, c11_b_y, "fl", "fl", 0);
  c11_c_u = c11_u.fr;
  c11_c_y = NULL;
  sf_mex_assign(&c11_c_y, sf_mex_create("y", &c11_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c11_y, c11_c_y, "fr", "fr", 0);
  c11_d_u = c11_u.rl;
  c11_d_y = NULL;
  sf_mex_assign(&c11_d_y, sf_mex_create("y", &c11_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c11_y, c11_d_y, "rl", "rl", 0);
  c11_e_u = c11_u.rr;
  c11_e_y = NULL;
  sf_mex_assign(&c11_e_y, sf_mex_create("y", &c11_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c11_y, c11_e_y, "rr", "rr", 0);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static const mxArray *c11_d_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  real_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_Modified2InstanceStruct *chartInstance;
  chartInstance = (SFc11_Modified2InstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(real_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static void c11_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_nargout;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y;
  SFc11_Modified2InstanceStruct *chartInstance;
  chartInstance = (SFc11_Modified2InstanceStruct *)chartInstanceVoid;
  c11_nargout = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_nargout),
    &c11_thisId);
  sf_mex_destroy(&c11_nargout);
  *(real_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_e_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i43;
  real_T c11_b_inData[3];
  int32_T c11_i44;
  real_T c11_u[3];
  const mxArray *c11_y = NULL;
  SFc11_Modified2InstanceStruct *chartInstance;
  chartInstance = (SFc11_Modified2InstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i43 = 0; c11_i43 < 3; c11_i43++) {
    c11_b_inData[c11_i43] = (*(real_T (*)[3])c11_inData)[c11_i43];
  }

  for (c11_i44 = 0; c11_i44 < 3; c11_i44++) {
    c11_u[c11_i44] = c11_b_inData[c11_i44];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static void c11_m_emlrt_marshallIn(SFc11_Modified2InstanceStruct *chartInstance,
  const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId, real_T c11_y[3])
{
  real_T c11_dv2[3];
  int32_T c11_i45;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_dv2, 1, 0, 0U, 1, 0U, 1, 3);
  for (c11_i45 = 0; c11_i45 < 3; c11_i45++) {
    c11_y[c11_i45] = c11_dv2[c11_i45];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_F_oorp3;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y[3];
  int32_T c11_i46;
  SFc11_Modified2InstanceStruct *chartInstance;
  chartInstance = (SFc11_Modified2InstanceStruct *)chartInstanceVoid;
  c11_F_oorp3 = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_F_oorp3), &c11_thisId,
    c11_y);
  sf_mex_destroy(&c11_F_oorp3);
  for (c11_i46 = 0; c11_i46 < 3; c11_i46++) {
    (*(real_T (*)[3])c11_outData)[c11_i46] = c11_y[c11_i46];
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_f_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i47;
  real_T c11_b_inData[4];
  int32_T c11_i48;
  real_T c11_u[4];
  const mxArray *c11_y = NULL;
  SFc11_Modified2InstanceStruct *chartInstance;
  chartInstance = (SFc11_Modified2InstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i47 = 0; c11_i47 < 4; c11_i47++) {
    c11_b_inData[c11_i47] = (*(real_T (*)[4])c11_inData)[c11_i47];
  }

  for (c11_i48 = 0; c11_i48 < 4; c11_i48++) {
    c11_u[c11_i48] = c11_b_inData[c11_i48];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 4), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static void c11_n_emlrt_marshallIn(SFc11_Modified2InstanceStruct *chartInstance,
  const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId, real_T c11_y[4])
{
  real_T c11_dv3[4];
  int32_T c11_i49;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_dv3, 1, 0, 0U, 1, 0U, 1, 4);
  for (c11_i49 = 0; c11_i49 < 4; c11_i49++) {
    c11_y[c11_i49] = c11_dv3[c11_i49];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_F_z4_temp;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y[4];
  int32_T c11_i50;
  SFc11_Modified2InstanceStruct *chartInstance;
  chartInstance = (SFc11_Modified2InstanceStruct *)chartInstanceVoid;
  c11_F_z4_temp = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_F_z4_temp), &c11_thisId,
    c11_y);
  sf_mex_destroy(&c11_F_z4_temp);
  for (c11_i50 = 0; c11_i50 < 4; c11_i50++) {
    (*(real_T (*)[4])c11_outData)[c11_i50] = c11_y[c11_i50];
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_g_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i51;
  int32_T c11_i52;
  int32_T c11_i53;
  real_T c11_b_inData[12];
  int32_T c11_i54;
  int32_T c11_i55;
  int32_T c11_i56;
  real_T c11_u[12];
  const mxArray *c11_y = NULL;
  SFc11_Modified2InstanceStruct *chartInstance;
  chartInstance = (SFc11_Modified2InstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_i51 = 0;
  for (c11_i52 = 0; c11_i52 < 4; c11_i52++) {
    for (c11_i53 = 0; c11_i53 < 3; c11_i53++) {
      c11_b_inData[c11_i53 + c11_i51] = (*(real_T (*)[12])c11_inData)[c11_i53 +
        c11_i51];
    }

    c11_i51 += 3;
  }

  c11_i54 = 0;
  for (c11_i55 = 0; c11_i55 < 4; c11_i55++) {
    for (c11_i56 = 0; c11_i56 < 3; c11_i56++) {
      c11_u[c11_i56 + c11_i54] = c11_b_inData[c11_i56 + c11_i54];
    }

    c11_i54 += 3;
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 2, 3, 4), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static void c11_o_emlrt_marshallIn(SFc11_Modified2InstanceStruct *chartInstance,
  const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId, real_T c11_y[12])
{
  real_T c11_dv4[12];
  int32_T c11_i57;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_dv4, 1, 0, 0U, 1, 0U, 2, 3,
                4);
  for (c11_i57 = 0; c11_i57 < 12; c11_i57++) {
    c11_y[c11_i57] = c11_dv4[c11_i57];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_T_oorpv;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y[12];
  int32_T c11_i58;
  int32_T c11_i59;
  int32_T c11_i60;
  SFc11_Modified2InstanceStruct *chartInstance;
  chartInstance = (SFc11_Modified2InstanceStruct *)chartInstanceVoid;
  c11_T_oorpv = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_T_oorpv), &c11_thisId,
    c11_y);
  sf_mex_destroy(&c11_T_oorpv);
  c11_i58 = 0;
  for (c11_i59 = 0; c11_i59 < 4; c11_i59++) {
    for (c11_i60 = 0; c11_i60 < 3; c11_i60++) {
      (*(real_T (*)[12])c11_outData)[c11_i60 + c11_i58] = c11_y[c11_i60 +
        c11_i58];
    }

    c11_i58 += 3;
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

const mxArray *sf_c11_Modified2_get_eml_resolved_functions_info(void)
{
  const mxArray *c11_nameCaptureInfo = NULL;
  c11_nameCaptureInfo = NULL;
  sf_mex_assign(&c11_nameCaptureInfo, sf_mex_createstruct("structure", 2, 20, 1),
                false);
  c11_info_helper(&c11_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c11_nameCaptureInfo);
  return c11_nameCaptureInfo;
}

static void c11_info_helper(const mxArray **c11_info)
{
  const mxArray *c11_rhs0 = NULL;
  const mxArray *c11_lhs0 = NULL;
  const mxArray *c11_rhs1 = NULL;
  const mxArray *c11_lhs1 = NULL;
  const mxArray *c11_rhs2 = NULL;
  const mxArray *c11_lhs2 = NULL;
  const mxArray *c11_rhs3 = NULL;
  const mxArray *c11_lhs3 = NULL;
  const mxArray *c11_rhs4 = NULL;
  const mxArray *c11_lhs4 = NULL;
  const mxArray *c11_rhs5 = NULL;
  const mxArray *c11_lhs5 = NULL;
  const mxArray *c11_rhs6 = NULL;
  const mxArray *c11_lhs6 = NULL;
  const mxArray *c11_rhs7 = NULL;
  const mxArray *c11_lhs7 = NULL;
  const mxArray *c11_rhs8 = NULL;
  const mxArray *c11_lhs8 = NULL;
  const mxArray *c11_rhs9 = NULL;
  const mxArray *c11_lhs9 = NULL;
  const mxArray *c11_rhs10 = NULL;
  const mxArray *c11_lhs10 = NULL;
  const mxArray *c11_rhs11 = NULL;
  const mxArray *c11_lhs11 = NULL;
  const mxArray *c11_rhs12 = NULL;
  const mxArray *c11_lhs12 = NULL;
  const mxArray *c11_rhs13 = NULL;
  const mxArray *c11_lhs13 = NULL;
  const mxArray *c11_rhs14 = NULL;
  const mxArray *c11_lhs14 = NULL;
  const mxArray *c11_rhs15 = NULL;
  const mxArray *c11_lhs15 = NULL;
  const mxArray *c11_rhs16 = NULL;
  const mxArray *c11_lhs16 = NULL;
  const mxArray *c11_rhs17 = NULL;
  const mxArray *c11_lhs17 = NULL;
  const mxArray *c11_rhs18 = NULL;
  const mxArray *c11_lhs18 = NULL;
  const mxArray *c11_rhs19 = NULL;
  const mxArray *c11_lhs19 = NULL;
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("mrdivide"), "name", "name",
                  0);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1410807648U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1370009886U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c11_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1389717774U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c11_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("rdivide"), "name", "name", 2);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363713880U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c11_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c11_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 4);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c11_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_div"), "name", "name", 5);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1386423952U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c11_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 6);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c11_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "context", "context", 7);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 7);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1383877294U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c11_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 8);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 8);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c11_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 9);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c11_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 10);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 10);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c11_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 11);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c11_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 12);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  12);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1375980690U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c11_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 13);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c11_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.blas.xgemm"),
                  "name", "name", 14);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c11_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 15);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 15);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c11_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!below_threshold"),
                  "context", "context", 16);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 16);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c11_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 17);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 17);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1393330858U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c11_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 18);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 18);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c11_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 19);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "coder.internal.refblas.xgemm"), "name", "name", 19);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c11_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs19), "lhs", "lhs",
                  19);
  sf_mex_destroy(&c11_rhs0);
  sf_mex_destroy(&c11_lhs0);
  sf_mex_destroy(&c11_rhs1);
  sf_mex_destroy(&c11_lhs1);
  sf_mex_destroy(&c11_rhs2);
  sf_mex_destroy(&c11_lhs2);
  sf_mex_destroy(&c11_rhs3);
  sf_mex_destroy(&c11_lhs3);
  sf_mex_destroy(&c11_rhs4);
  sf_mex_destroy(&c11_lhs4);
  sf_mex_destroy(&c11_rhs5);
  sf_mex_destroy(&c11_lhs5);
  sf_mex_destroy(&c11_rhs6);
  sf_mex_destroy(&c11_lhs6);
  sf_mex_destroy(&c11_rhs7);
  sf_mex_destroy(&c11_lhs7);
  sf_mex_destroy(&c11_rhs8);
  sf_mex_destroy(&c11_lhs8);
  sf_mex_destroy(&c11_rhs9);
  sf_mex_destroy(&c11_lhs9);
  sf_mex_destroy(&c11_rhs10);
  sf_mex_destroy(&c11_lhs10);
  sf_mex_destroy(&c11_rhs11);
  sf_mex_destroy(&c11_lhs11);
  sf_mex_destroy(&c11_rhs12);
  sf_mex_destroy(&c11_lhs12);
  sf_mex_destroy(&c11_rhs13);
  sf_mex_destroy(&c11_lhs13);
  sf_mex_destroy(&c11_rhs14);
  sf_mex_destroy(&c11_lhs14);
  sf_mex_destroy(&c11_rhs15);
  sf_mex_destroy(&c11_lhs15);
  sf_mex_destroy(&c11_rhs16);
  sf_mex_destroy(&c11_lhs16);
  sf_mex_destroy(&c11_rhs17);
  sf_mex_destroy(&c11_lhs17);
  sf_mex_destroy(&c11_rhs18);
  sf_mex_destroy(&c11_lhs18);
  sf_mex_destroy(&c11_rhs19);
  sf_mex_destroy(&c11_lhs19);
}

static const mxArray *c11_emlrt_marshallOut(const char * c11_u)
{
  const mxArray *c11_y = NULL;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c11_u)), false);
  return c11_y;
}

static const mxArray *c11_b_emlrt_marshallOut(const uint32_T c11_u)
{
  const mxArray *c11_y = NULL;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 7, 0U, 0U, 0U, 0), false);
  return c11_y;
}

static void c11_eml_scalar_eg(SFc11_Modified2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c11_eml_xgemm(SFc11_Modified2InstanceStruct *chartInstance, real_T
  c11_A[12], real_T c11_B[4], real_T c11_C[3], real_T c11_b_C[3])
{
  int32_T c11_i61;
  int32_T c11_i62;
  real_T c11_b_A[12];
  int32_T c11_i63;
  real_T c11_b_B[4];
  for (c11_i61 = 0; c11_i61 < 3; c11_i61++) {
    c11_b_C[c11_i61] = c11_C[c11_i61];
  }

  for (c11_i62 = 0; c11_i62 < 12; c11_i62++) {
    c11_b_A[c11_i62] = c11_A[c11_i62];
  }

  for (c11_i63 = 0; c11_i63 < 4; c11_i63++) {
    c11_b_B[c11_i63] = c11_B[c11_i63];
  }

  c11_b_eml_xgemm(chartInstance, c11_b_A, c11_b_B, c11_b_C);
}

static const mxArray *c11_h_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_Modified2InstanceStruct *chartInstance;
  chartInstance = (SFc11_Modified2InstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(int32_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static int32_T c11_p_emlrt_marshallIn(SFc11_Modified2InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  int32_T c11_y;
  int32_T c11_i64;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_i64, 1, 6, 0U, 0, 0U, 0);
  c11_y = c11_i64;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_b_sfEvent;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  int32_T c11_y;
  SFc11_Modified2InstanceStruct *chartInstance;
  chartInstance = (SFc11_Modified2InstanceStruct *)chartInstanceVoid;
  c11_b_sfEvent = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_p_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_sfEvent),
    &c11_thisId);
  sf_mex_destroy(&c11_b_sfEvent);
  *(int32_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_F_xv4_bus_io(void *chartInstanceVoid, void *c11_pData)
{
  const mxArray *c11_mxVal = NULL;
  c11_whl_vec4 c11_tmp;
  SFc11_Modified2InstanceStruct *chartInstance;
  chartInstance = (SFc11_Modified2InstanceStruct *)chartInstanceVoid;
  c11_mxVal = NULL;
  c11_tmp.fl = *(real_T *)&((char_T *)(c11_whl_vec4 *)c11_pData)[0];
  c11_tmp.fr = *(real_T *)&((char_T *)(c11_whl_vec4 *)c11_pData)[8];
  c11_tmp.rl = *(real_T *)&((char_T *)(c11_whl_vec4 *)c11_pData)[16];
  c11_tmp.rr = *(real_T *)&((char_T *)(c11_whl_vec4 *)c11_pData)[24];
  sf_mex_assign(&c11_mxVal, c11_c_sf_marshallOut(chartInstance, &c11_tmp), false);
  return c11_mxVal;
}

static const mxArray *c11_derv_oorp3_bus_io(void *chartInstanceVoid, void
  *c11_pData)
{
  const mxArray *c11_mxVal = NULL;
  c11_oorp_vec3 c11_tmp;
  SFc11_Modified2InstanceStruct *chartInstance;
  chartInstance = (SFc11_Modified2InstanceStruct *)chartInstanceVoid;
  c11_mxVal = NULL;
  c11_tmp.z = *(real_T *)&((char_T *)(c11_oorp_vec3 *)c11_pData)[0];
  c11_tmp.rotx = *(real_T *)&((char_T *)(c11_oorp_vec3 *)c11_pData)[8];
  c11_tmp.roty = *(real_T *)&((char_T *)(c11_oorp_vec3 *)c11_pData)[16];
  sf_mex_assign(&c11_mxVal, c11_sf_marshallOut(chartInstance, &c11_tmp), false);
  return c11_mxVal;
}

static uint8_T c11_q_emlrt_marshallIn(SFc11_Modified2InstanceStruct
  *chartInstance, const mxArray *c11_b_is_active_c11_Modified2, const char_T
  *c11_identifier)
{
  uint8_T c11_y;
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_r_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c11_b_is_active_c11_Modified2), &c11_thisId);
  sf_mex_destroy(&c11_b_is_active_c11_Modified2);
  return c11_y;
}

static uint8_T c11_r_emlrt_marshallIn(SFc11_Modified2InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  uint8_T c11_y;
  uint8_T c11_u0;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_u0, 1, 3, 0U, 0, 0U, 0);
  c11_y = c11_u0;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_b_eml_xgemm(SFc11_Modified2InstanceStruct *chartInstance, real_T
  c11_A[12], real_T c11_B[4], real_T c11_C[3])
{
  int32_T c11_i65;
  int32_T c11_i66;
  int32_T c11_i67;
  (void)chartInstance;
  for (c11_i65 = 0; c11_i65 < 3; c11_i65++) {
    c11_C[c11_i65] = 0.0;
    c11_i66 = 0;
    for (c11_i67 = 0; c11_i67 < 4; c11_i67++) {
      c11_C[c11_i65] += c11_A[c11_i66 + c11_i65] * c11_B[c11_i67];
      c11_i66 += 3;
    }
  }
}

static void init_dsm_address_info(SFc11_Modified2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc11_Modified2InstanceStruct
  *chartInstance)
{
  chartInstance->c11_F_xv4 = (c11_whl_vec4 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c11_derv_oorp3 = (c11_oorp_vec3 *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c11_F_yv4 = (c11_whl_vec4 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c11_F_z4 = (c11_whl_vec4 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
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

void sf_c11_Modified2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1820227298U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(25443725U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2985632773U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(806101766U);
}

mxArray* sf_c11_Modified2_get_post_codegen_info(void);
mxArray *sf_c11_Modified2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("1u9pYwycNOXhEp6ajs6LnH");
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
    mxArray* mxPostCodegenInfo = sf_c11_Modified2_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c11_Modified2_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c11_Modified2_jit_fallback_info(void)
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

mxArray *sf_c11_Modified2_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c11_Modified2_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c11_Modified2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[10],T\"derv_oorp3\",},{M[8],M[0],T\"is_active_c11_Modified2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c11_Modified2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc11_Modified2InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc11_Modified2InstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Modified2MachineNumber_,
           11,
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
        init_script_number_translation(_Modified2MachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Modified2MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Modified2MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"F_xv4");
          _SFD_SET_DATA_PROPS(1,2,0,1,"derv_oorp3");
          _SFD_SET_DATA_PROPS(2,1,1,0,"F_yv4");
          _SFD_SET_DATA_PROPS(3,1,1,0,"F_z4");
          _SFD_SET_DATA_PROPS(4,10,0,0,"Par");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,881);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_F_xv4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_derv_oorp3_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_F_xv4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_F_xv4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)
          c11_b_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c11_F_xv4);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c11_derv_oorp3);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c11_F_yv4);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c11_F_z4);
        _SFD_SET_DATA_VALUE_PTR(4U, &chartInstance->c11_Par);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Modified2MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "nsuilLiT8rixZOJEK30JvD";
}

static void sf_opaque_initialize_c11_Modified2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc11_Modified2InstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c11_Modified2((SFc11_Modified2InstanceStruct*)
    chartInstanceVar);
  initialize_c11_Modified2((SFc11_Modified2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c11_Modified2(void *chartInstanceVar)
{
  enable_c11_Modified2((SFc11_Modified2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c11_Modified2(void *chartInstanceVar)
{
  disable_c11_Modified2((SFc11_Modified2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c11_Modified2(void *chartInstanceVar)
{
  sf_gateway_c11_Modified2((SFc11_Modified2InstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c11_Modified2(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c11_Modified2((SFc11_Modified2InstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c11_Modified2(SimStruct* S, const mxArray
  *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c11_Modified2((SFc11_Modified2InstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c11_Modified2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc11_Modified2InstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Modified2_optimization_info();
    }

    finalize_c11_Modified2((SFc11_Modified2InstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc11_Modified2((SFc11_Modified2InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c11_Modified2(SimStruct *S)
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
    initialize_params_c11_Modified2((SFc11_Modified2InstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c11_Modified2(SimStruct *S)
{
  /* Actual parameters from chart:
     Par
   */
  const char_T *rtParamNames[] = { "Par" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0],
    sf_get_param_data_type_id(S,0));
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Modified2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      11);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,11,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,11,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,11);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,11,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,11,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,11);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(131015953U));
  ssSetChecksum1(S,(1681997717U));
  ssSetChecksum2(S,(3356409279U));
  ssSetChecksum3(S,(1007671995U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c11_Modified2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c11_Modified2(SimStruct *S)
{
  SFc11_Modified2InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc11_Modified2InstanceStruct *)utMalloc(sizeof
    (SFc11_Modified2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc11_Modified2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c11_Modified2;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c11_Modified2;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c11_Modified2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c11_Modified2;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c11_Modified2;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c11_Modified2;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c11_Modified2;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c11_Modified2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c11_Modified2;
  chartInstance->chartInfo.mdlStart = mdlStart_c11_Modified2;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c11_Modified2;
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

void c11_Modified2_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c11_Modified2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c11_Modified2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c11_Modified2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c11_Modified2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
