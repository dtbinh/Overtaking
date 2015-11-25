/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Modified_sfun.h"
#include "c16_Modified.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Modified_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c16_debug_family_names[19] = { "w1", "w2", "w3", "w4", "lf",
  "lr", "h", "T_oorpv", "F_xv4_temp", "F_yv4_temp", "F_z4_temp", "F_oorp3",
  "nargin", "nargout", "F_xv4", "F_yv4", "F_z4", "Par", "derv_oorp3" };

/* Function Declarations */
static void initialize_c16_Modified(SFc16_ModifiedInstanceStruct *chartInstance);
static void initialize_params_c16_Modified(SFc16_ModifiedInstanceStruct
  *chartInstance);
static void enable_c16_Modified(SFc16_ModifiedInstanceStruct *chartInstance);
static void disable_c16_Modified(SFc16_ModifiedInstanceStruct *chartInstance);
static void c16_update_debugger_state_c16_Modified(SFc16_ModifiedInstanceStruct *
  chartInstance);
static const mxArray *get_sim_state_c16_Modified(SFc16_ModifiedInstanceStruct
  *chartInstance);
static void set_sim_state_c16_Modified(SFc16_ModifiedInstanceStruct
  *chartInstance, const mxArray *c16_st);
static void finalize_c16_Modified(SFc16_ModifiedInstanceStruct *chartInstance);
static void sf_gateway_c16_Modified(SFc16_ModifiedInstanceStruct *chartInstance);
static void mdl_start_c16_Modified(SFc16_ModifiedInstanceStruct *chartInstance);
static void c16_chartstep_c16_Modified(SFc16_ModifiedInstanceStruct
  *chartInstance);
static void initSimStructsc16_Modified(SFc16_ModifiedInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c16_machineNumber, uint32_T
  c16_chartNumber, uint32_T c16_instanceNumber);
static const mxArray *c16_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static c16_oorp_vec3 c16_emlrt_marshallIn(SFc16_ModifiedInstanceStruct
  *chartInstance, const mxArray *c16_b_derv_oorp3, const char_T *c16_identifier);
static c16_oorp_vec3 c16_b_emlrt_marshallIn(SFc16_ModifiedInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId);
static real_T c16_c_emlrt_marshallIn(SFc16_ModifiedInstanceStruct *chartInstance,
  const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId);
static void c16_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData);
static const mxArray *c16_b_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static void c16_d_emlrt_marshallIn(SFc16_ModifiedInstanceStruct *chartInstance,
  const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId,
  c16_struct_iBlsPBO3AGnt69vDoTx5zD *c16_y);
static void c16_e_emlrt_marshallIn(SFc16_ModifiedInstanceStruct *chartInstance,
  const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId,
  c16_struct_Nst2vGTExxHsg85EUOj9EH *c16_y);
static c16_struct_HhckT6rntEraqECYVIDvCC c16_f_emlrt_marshallIn
  (SFc16_ModifiedInstanceStruct *chartInstance, const mxArray *c16_u, const
   emlrtMsgIdentifier *c16_parentId);
static void c16_g_emlrt_marshallIn(SFc16_ModifiedInstanceStruct *chartInstance,
  const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId,
  c16_struct_ZCmOWPuqBDw16FSOVVD00 *c16_y);
static void c16_h_emlrt_marshallIn(SFc16_ModifiedInstanceStruct *chartInstance,
  const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId, real_T c16_y[4]);
static void c16_i_emlrt_marshallIn(SFc16_ModifiedInstanceStruct *chartInstance,
  const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId,
  c16_struct_ZKAzdrl7umDGJoC14aoVKC *c16_y);
static void c16_j_emlrt_marshallIn(SFc16_ModifiedInstanceStruct *chartInstance,
  const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId, real_T c16_y[3]);
static c16_struct_r4FNviKwHfdhB8nQjvQv9 c16_k_emlrt_marshallIn
  (SFc16_ModifiedInstanceStruct *chartInstance, const mxArray *c16_u, const
   emlrtMsgIdentifier *c16_parentId);
static c16_struct_Y9F1qlBi9AhssksPwemA4G c16_l_emlrt_marshallIn
  (SFc16_ModifiedInstanceStruct *chartInstance, const mxArray *c16_u, const
   emlrtMsgIdentifier *c16_parentId);
static void c16_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData);
static const mxArray *c16_c_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static const mxArray *c16_d_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static void c16_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData);
static const mxArray *c16_e_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static void c16_m_emlrt_marshallIn(SFc16_ModifiedInstanceStruct *chartInstance,
  const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId, real_T c16_y[3]);
static void c16_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData);
static const mxArray *c16_f_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static void c16_n_emlrt_marshallIn(SFc16_ModifiedInstanceStruct *chartInstance,
  const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId, real_T c16_y[4]);
static void c16_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData);
static const mxArray *c16_g_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static void c16_o_emlrt_marshallIn(SFc16_ModifiedInstanceStruct *chartInstance,
  const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId, real_T c16_y[12]);
static void c16_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData);
static void c16_info_helper(const mxArray **c16_info);
static const mxArray *c16_emlrt_marshallOut(const char * c16_u);
static const mxArray *c16_b_emlrt_marshallOut(const uint32_T c16_u);
static void c16_eml_scalar_eg(SFc16_ModifiedInstanceStruct *chartInstance);
static void c16_eml_xgemm(SFc16_ModifiedInstanceStruct *chartInstance, real_T
  c16_A[12], real_T c16_B[4], real_T c16_C[3], real_T c16_b_C[3]);
static const mxArray *c16_h_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static int32_T c16_p_emlrt_marshallIn(SFc16_ModifiedInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId);
static void c16_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData);
static const mxArray *c16_F_xv4_bus_io(void *chartInstanceVoid, void *c16_pData);
static const mxArray *c16_derv_oorp3_bus_io(void *chartInstanceVoid, void
  *c16_pData);
static uint8_T c16_q_emlrt_marshallIn(SFc16_ModifiedInstanceStruct
  *chartInstance, const mxArray *c16_b_is_active_c16_Modified, const char_T
  *c16_identifier);
static uint8_T c16_r_emlrt_marshallIn(SFc16_ModifiedInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId);
static void c16_b_eml_xgemm(SFc16_ModifiedInstanceStruct *chartInstance, real_T
  c16_A[12], real_T c16_B[4], real_T c16_C[3]);
static void init_dsm_address_info(SFc16_ModifiedInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc16_ModifiedInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c16_Modified(SFc16_ModifiedInstanceStruct *chartInstance)
{
  chartInstance->c16_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c16_is_active_c16_Modified = 0U;
}

static void initialize_params_c16_Modified(SFc16_ModifiedInstanceStruct
  *chartInstance)
{
  const mxArray *c16_m0 = NULL;
  const mxArray *c16_mxField;
  const mxArray *c16_m1 = NULL;
  const mxArray *c16_b_mxField;
  c16_struct_iBlsPBO3AGnt69vDoTx5zD c16_r0;
  const mxArray *c16_m2 = NULL;
  const mxArray *c16_c_mxField;
  const mxArray *c16_m3 = NULL;
  const mxArray *c16_d_mxField;
  const mxArray *c16_m4 = NULL;
  const mxArray *c16_e_mxField;
  const mxArray *c16_m5 = NULL;
  const mxArray *c16_f_mxField;
  const mxArray *c16_m6 = NULL;
  const mxArray *c16_g_mxField;
  const mxArray *c16_m7 = NULL;
  const mxArray *c16_h_mxField;
  const mxArray *c16_m8 = NULL;
  const mxArray *c16_i_mxField;
  const mxArray *c16_m9 = NULL;
  const mxArray *c16_j_mxField;
  const mxArray *c16_m10 = NULL;
  const mxArray *c16_k_mxField;
  const mxArray *c16_m11 = NULL;
  const mxArray *c16_l_mxField;
  const mxArray *c16_m12 = NULL;
  const mxArray *c16_m_mxField;
  const mxArray *c16_m13 = NULL;
  const mxArray *c16_n_mxField;
  c16_m0 = sf_mex_get_sfun_param(chartInstance->S, 0, 1);
  c16_mxField = sf_mex_getfield(c16_m0, "Env", "Par", 0);
  c16_m1 = sf_mex_dup(c16_mxField);
  c16_b_mxField = sf_mex_getfield(c16_m1, "g", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_b_mxField), &c16_r0.Env.g, 1, 0, 0U,
                      0, 0U, 0);
  c16_b_mxField = sf_mex_getfield(c16_m1, "left1", "Par", 0);
  c16_m2 = sf_mex_dup(c16_b_mxField);
  c16_c_mxField = sf_mex_getfield(c16_m2, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_c_mxField), &c16_r0.Env.left1.x, 1,
                      0, 0U, 0, 0U, 0);
  c16_c_mxField = sf_mex_getfield(c16_m2, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_c_mxField), &c16_r0.Env.left1.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c16_m2);
  c16_b_mxField = sf_mex_getfield(c16_m1, "right1", "Par", 0);
  c16_m3 = sf_mex_dup(c16_b_mxField);
  c16_d_mxField = sf_mex_getfield(c16_m3, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_d_mxField), &c16_r0.Env.right1.x, 1,
                      0, 0U, 0, 0U, 0);
  c16_d_mxField = sf_mex_getfield(c16_m3, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_d_mxField), &c16_r0.Env.right1.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c16_m3);
  c16_b_mxField = sf_mex_getfield(c16_m1, "right2", "Par", 0);
  c16_m4 = sf_mex_dup(c16_b_mxField);
  c16_e_mxField = sf_mex_getfield(c16_m4, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_e_mxField), &c16_r0.Env.right2.x, 1,
                      0, 0U, 0, 0U, 0);
  c16_e_mxField = sf_mex_getfield(c16_m4, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_e_mxField), &c16_r0.Env.right2.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c16_m4);
  c16_b_mxField = sf_mex_getfield(c16_m1, "left2", "Par", 0);
  c16_m5 = sf_mex_dup(c16_b_mxField);
  c16_f_mxField = sf_mex_getfield(c16_m5, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_f_mxField), &c16_r0.Env.left2.x, 1,
                      0, 0U, 0, 0U, 0);
  c16_f_mxField = sf_mex_getfield(c16_m5, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_f_mxField), &c16_r0.Env.left2.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c16_m5);
  c16_b_mxField = sf_mex_getfield(c16_m1, "right3", "Par", 0);
  c16_m6 = sf_mex_dup(c16_b_mxField);
  c16_g_mxField = sf_mex_getfield(c16_m6, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_g_mxField), &c16_r0.Env.right3.x, 1,
                      0, 0U, 0, 0U, 0);
  c16_g_mxField = sf_mex_getfield(c16_m6, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_g_mxField), &c16_r0.Env.right3.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c16_m6);
  c16_b_mxField = sf_mex_getfield(c16_m1, "mu", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_b_mxField), &c16_r0.Env.mu, 1, 0, 0U,
                      0, 0U, 0);
  sf_mex_destroy(&c16_m1);
  c16_mxField = sf_mex_getfield(c16_m0, "Veh", "Par", 0);
  c16_m7 = sf_mex_dup(c16_mxField);
  c16_h_mxField = sf_mex_getfield(c16_m7, "m", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_h_mxField), &c16_r0.Veh.m, 1, 0, 0U,
                      0, 0U, 0);
  c16_h_mxField = sf_mex_getfield(c16_m7, "Jz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_h_mxField), &c16_r0.Veh.Jz, 1, 0, 0U,
                      0, 0U, 0);
  c16_h_mxField = sf_mex_getfield(c16_m7, "m_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_h_mxField), &c16_r0.Veh.m_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c16_h_mxField = sf_mex_getfield(c16_m7, "Jx_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_h_mxField), &c16_r0.Veh.Jx_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c16_h_mxField = sf_mex_getfield(c16_m7, "Jy_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_h_mxField), &c16_r0.Veh.Jy_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c16_h_mxField = sf_mex_getfield(c16_m7, "lf", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_h_mxField), &c16_r0.Veh.lf, 1, 0, 0U,
                      0, 0U, 0);
  c16_h_mxField = sf_mex_getfield(c16_m7, "lr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_h_mxField), &c16_r0.Veh.lr, 1, 0, 0U,
                      0, 0U, 0);
  c16_h_mxField = sf_mex_getfield(c16_m7, "L", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_h_mxField), &c16_r0.Veh.L, 1, 0, 0U,
                      0, 0U, 0);
  c16_h_mxField = sf_mex_getfield(c16_m7, "TrackWidth", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_h_mxField), &c16_r0.Veh.TrackWidth,
                      1, 0, 0U, 0, 0U, 0);
  c16_h_mxField = sf_mex_getfield(c16_m7, "h", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_h_mxField), &c16_r0.Veh.h, 1, 0, 0U,
                      0, 0U, 0);
  c16_h_mxField = sf_mex_getfield(c16_m7, "HalfRohACd", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_h_mxField), &c16_r0.Veh.HalfRohACd,
                      1, 0, 0U, 0, 0U, 0);
  c16_h_mxField = sf_mex_getfield(c16_m7, "F_z4_static", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_h_mxField), c16_r0.Veh.F_z4_static,
                      1, 0, 0U, 1, 0U, 2, 1, 4);
  c16_h_mxField = sf_mex_getfield(c16_m7, "Rw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_h_mxField), &c16_r0.Veh.Rw, 1, 0, 0U,
                      0, 0U, 0);
  c16_h_mxField = sf_mex_getfield(c16_m7, "r_long", "Par", 0);
  c16_m8 = sf_mex_dup(c16_h_mxField);
  c16_i_mxField = sf_mex_getfield(c16_m8, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_i_mxField), c16_r0.Veh.r_long.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c16_i_mxField = sf_mex_getfield(c16_m8, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_i_mxField), c16_r0.Veh.r_long.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c16_i_mxField = sf_mex_getfield(c16_m8, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_i_mxField), c16_r0.Veh.r_long.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c16_i_mxField = sf_mex_getfield(c16_m8, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_i_mxField), c16_r0.Veh.r_long.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c16_m8);
  c16_h_mxField = sf_mex_getfield(c16_m7, "r_lat", "Par", 0);
  c16_m9 = sf_mex_dup(c16_h_mxField);
  c16_j_mxField = sf_mex_getfield(c16_m9, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_j_mxField), c16_r0.Veh.r_lat.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c16_j_mxField = sf_mex_getfield(c16_m9, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_j_mxField), c16_r0.Veh.r_lat.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c16_j_mxField = sf_mex_getfield(c16_m9, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_j_mxField), c16_r0.Veh.r_lat.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c16_j_mxField = sf_mex_getfield(c16_m9, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_j_mxField), c16_r0.Veh.r_lat.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c16_m9);
  c16_h_mxField = sf_mex_getfield(c16_m7, "r_lever", "Par", 0);
  c16_m10 = sf_mex_dup(c16_h_mxField);
  c16_k_mxField = sf_mex_getfield(c16_m10, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_k_mxField), c16_r0.Veh.r_lever.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c16_k_mxField = sf_mex_getfield(c16_m10, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_k_mxField), c16_r0.Veh.r_lever.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c16_k_mxField = sf_mex_getfield(c16_m10, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_k_mxField), c16_r0.Veh.r_lever.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c16_k_mxField = sf_mex_getfield(c16_m10, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_k_mxField), c16_r0.Veh.r_lever.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c16_m10);
  c16_h_mxField = sf_mex_getfield(c16_m7, "r_pivot", "Par", 0);
  c16_m11 = sf_mex_dup(c16_h_mxField);
  c16_l_mxField = sf_mex_getfield(c16_m11, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_l_mxField), c16_r0.Veh.r_pivot.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c16_l_mxField = sf_mex_getfield(c16_m11, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_l_mxField), c16_r0.Veh.r_pivot.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c16_l_mxField = sf_mex_getfield(c16_m11, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_l_mxField), c16_r0.Veh.r_pivot.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c16_l_mxField = sf_mex_getfield(c16_m11, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_l_mxField), c16_r0.Veh.r_pivot.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c16_m11);
  c16_h_mxField = sf_mex_getfield(c16_m7, "cw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_h_mxField), &c16_r0.Veh.cw, 1, 0, 0U,
                      0, 0U, 0);
  c16_h_mxField = sf_mex_getfield(c16_m7, "carb_f", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_h_mxField), &c16_r0.Veh.carb_f, 1, 0,
                      0U, 0, 0U, 0);
  c16_h_mxField = sf_mex_getfield(c16_m7, "carb_r", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_h_mxField), &c16_r0.Veh.carb_r, 1, 0,
                      0U, 0, 0U, 0);
  c16_h_mxField = sf_mex_getfield(c16_m7, "dw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_h_mxField), &c16_r0.Veh.dw, 1, 0, 0U,
                      0, 0U, 0);
  c16_h_mxField = sf_mex_getfield(c16_m7, "Jw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_h_mxField), &c16_r0.Veh.Jw, 1, 0, 0U,
                      0, 0U, 0);
  c16_h_mxField = sf_mex_getfield(c16_m7, "C0", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_h_mxField), &c16_r0.Veh.C0, 1, 0, 0U,
                      0, 0U, 0);
  c16_h_mxField = sf_mex_getfield(c16_m7, "RelaxLength", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_h_mxField), &c16_r0.Veh.RelaxLength,
                      1, 0, 0U, 0, 0U, 0);
  c16_h_mxField = sf_mex_getfield(c16_m7, "RRC", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_h_mxField), &c16_r0.Veh.RRC, 1, 0,
                      0U, 0, 0U, 0);
  c16_h_mxField = sf_mex_getfield(c16_m7, "Pmax", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_h_mxField), &c16_r0.Veh.Pmax, 1, 0,
                      0U, 0, 0U, 0);
  c16_h_mxField = sf_mex_getfield(c16_m7, "PropDistrFrnt", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_h_mxField),
                      &c16_r0.Veh.PropDistrFrnt, 1, 0, 0U, 0, 0U, 0);
  c16_h_mxField = sf_mex_getfield(c16_m7, "BrkDistrFrnt", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_h_mxField), &c16_r0.Veh.BrkDistrFrnt,
                      1, 0, 0U, 0, 0U, 0);
  c16_h_mxField = sf_mex_getfield(c16_m7, "SteRatio", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_h_mxField), &c16_r0.Veh.SteRatio, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c16_m7);
  c16_mxField = sf_mex_getfield(c16_m0, "Drvr", "Par", 0);
  c16_m12 = sf_mex_dup(c16_mxField);
  c16_m_mxField = sf_mex_getfield(c16_m12, "v_set", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_m_mxField), &c16_r0.Drvr.v_set, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c16_m12);
  c16_mxField = sf_mex_getfield(c16_m0, "Init", "Par", 0);
  c16_m13 = sf_mex_dup(c16_mxField);
  c16_n_mxField = sf_mex_getfield(c16_m13, "v_x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_n_mxField), &c16_r0.Init.v_x, 1, 0,
                      0U, 0, 0U, 0);
  c16_n_mxField = sf_mex_getfield(c16_m13, "F_fz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_n_mxField), &c16_r0.Init.F_fz, 1, 0,
                      0U, 0, 0U, 0);
  c16_n_mxField = sf_mex_getfield(c16_m13, "F_rz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c16_n_mxField), &c16_r0.Init.F_rz, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c16_m13);
  sf_mex_destroy(&c16_m0);
  chartInstance->c16_Par = c16_r0;
}

static void enable_c16_Modified(SFc16_ModifiedInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c16_Modified(SFc16_ModifiedInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c16_update_debugger_state_c16_Modified(SFc16_ModifiedInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c16_Modified(SFc16_ModifiedInstanceStruct
  *chartInstance)
{
  const mxArray *c16_st;
  const mxArray *c16_y = NULL;
  const mxArray *c16_b_y = NULL;
  real_T c16_u;
  const mxArray *c16_c_y = NULL;
  real_T c16_b_u;
  const mxArray *c16_d_y = NULL;
  real_T c16_c_u;
  const mxArray *c16_e_y = NULL;
  uint8_T c16_hoistedGlobal;
  uint8_T c16_d_u;
  const mxArray *c16_f_y = NULL;
  c16_st = NULL;
  c16_st = NULL;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_createcellmatrix(2, 1), false);
  c16_b_y = NULL;
  sf_mex_assign(&c16_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c16_u = *(real_T *)&((char_T *)chartInstance->c16_derv_oorp3)[0];
  c16_c_y = NULL;
  sf_mex_assign(&c16_c_y, sf_mex_create("y", &c16_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c16_b_y, c16_c_y, "z", "z", 0);
  c16_b_u = *(real_T *)&((char_T *)chartInstance->c16_derv_oorp3)[8];
  c16_d_y = NULL;
  sf_mex_assign(&c16_d_y, sf_mex_create("y", &c16_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c16_b_y, c16_d_y, "rotx", "rotx", 0);
  c16_c_u = *(real_T *)&((char_T *)chartInstance->c16_derv_oorp3)[16];
  c16_e_y = NULL;
  sf_mex_assign(&c16_e_y, sf_mex_create("y", &c16_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c16_b_y, c16_e_y, "roty", "roty", 0);
  sf_mex_setcell(c16_y, 0, c16_b_y);
  c16_hoistedGlobal = chartInstance->c16_is_active_c16_Modified;
  c16_d_u = c16_hoistedGlobal;
  c16_f_y = NULL;
  sf_mex_assign(&c16_f_y, sf_mex_create("y", &c16_d_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c16_y, 1, c16_f_y);
  sf_mex_assign(&c16_st, c16_y, false);
  return c16_st;
}

static void set_sim_state_c16_Modified(SFc16_ModifiedInstanceStruct
  *chartInstance, const mxArray *c16_st)
{
  const mxArray *c16_u;
  c16_oorp_vec3 c16_r1;
  chartInstance->c16_doneDoubleBufferReInit = true;
  c16_u = sf_mex_dup(c16_st);
  c16_r1 = c16_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c16_u,
    0)), "derv_oorp3");
  *(real_T *)&((char_T *)chartInstance->c16_derv_oorp3)[0] = c16_r1.z;
  *(real_T *)&((char_T *)chartInstance->c16_derv_oorp3)[8] = c16_r1.rotx;
  *(real_T *)&((char_T *)chartInstance->c16_derv_oorp3)[16] = c16_r1.roty;
  chartInstance->c16_is_active_c16_Modified = c16_q_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c16_u, 1)),
     "is_active_c16_Modified");
  sf_mex_destroy(&c16_u);
  c16_update_debugger_state_c16_Modified(chartInstance);
  sf_mex_destroy(&c16_st);
}

static void finalize_c16_Modified(SFc16_ModifiedInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c16_Modified(SFc16_ModifiedInstanceStruct *chartInstance)
{
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 15U, chartInstance->c16_sfEvent);
  chartInstance->c16_sfEvent = CALL_EVENT;
  c16_chartstep_c16_Modified(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_ModifiedMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c16_Modified(SFc16_ModifiedInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c16_chartstep_c16_Modified(SFc16_ModifiedInstanceStruct
  *chartInstance)
{
  c16_whl_vec4 c16_b_F_xv4;
  c16_whl_vec4 c16_b_F_yv4;
  c16_whl_vec4 c16_b_F_z4;
  c16_struct_iBlsPBO3AGnt69vDoTx5zD c16_b_Par;
  uint32_T c16_debug_family_var_map[19];
  real_T c16_w1;
  real_T c16_w2;
  real_T c16_w3;
  real_T c16_w4;
  real_T c16_lf;
  real_T c16_lr;
  real_T c16_h;
  real_T c16_T_oorpv[12];
  real_T c16_F_xv4_temp[4];
  real_T c16_F_yv4_temp[4];
  real_T c16_F_z4_temp[4];
  real_T c16_F_oorp3[3];
  real_T c16_nargin = 4.0;
  real_T c16_nargout = 1.0;
  c16_oorp_vec3 c16_b_derv_oorp3;
  real_T c16_A;
  real_T c16_x;
  real_T c16_b_x;
  real_T c16_c_x;
  int32_T c16_i0;
  int32_T c16_i1;
  int32_T c16_i2;
  int32_T c16_i3;
  real_T c16_a[12];
  int32_T c16_i4;
  int32_T c16_i5;
  int32_T c16_i6;
  real_T c16_b[4];
  int32_T c16_i7;
  real_T c16_y[3];
  int32_T c16_i8;
  real_T c16_b_a[12];
  int32_T c16_i9;
  real_T c16_b_b[4];
  int32_T c16_i10;
  int32_T c16_i11;
  int32_T c16_i12;
  int32_T c16_i13;
  int32_T c16_i14;
  int32_T c16_i15;
  real_T c16_b_y[3];
  int32_T c16_i16;
  real_T c16_c_a[12];
  int32_T c16_i17;
  real_T c16_c_b[4];
  int32_T c16_i18;
  int32_T c16_i19;
  int32_T c16_i20;
  real_T c16_c_y[3];
  int32_T c16_i21;
  real_T c16_d_a[12];
  int32_T c16_i22;
  real_T c16_d_b[4];
  real_T c16_c_Par[3];
  int32_T c16_i23;
  real_T c16_b_A;
  real_T c16_B;
  real_T c16_d_x;
  real_T c16_d_y;
  real_T c16_e_x;
  real_T c16_e_y;
  real_T c16_f_x;
  real_T c16_f_y;
  real_T c16_g_y;
  real_T c16_c_A;
  real_T c16_b_B;
  real_T c16_g_x;
  real_T c16_h_y;
  real_T c16_h_x;
  real_T c16_i_y;
  real_T c16_i_x;
  real_T c16_j_y;
  real_T c16_k_y;
  real_T c16_d_A;
  real_T c16_c_B;
  real_T c16_j_x;
  real_T c16_l_y;
  real_T c16_k_x;
  real_T c16_m_y;
  real_T c16_l_x;
  real_T c16_n_y;
  real_T c16_o_y;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 15U, chartInstance->c16_sfEvent);
  c16_b_F_xv4.fl = *(real_T *)&((char_T *)chartInstance->c16_F_xv4)[0];
  c16_b_F_xv4.fr = *(real_T *)&((char_T *)chartInstance->c16_F_xv4)[8];
  c16_b_F_xv4.rl = *(real_T *)&((char_T *)chartInstance->c16_F_xv4)[16];
  c16_b_F_xv4.rr = *(real_T *)&((char_T *)chartInstance->c16_F_xv4)[24];
  c16_b_F_yv4.fl = *(real_T *)&((char_T *)chartInstance->c16_F_yv4)[0];
  c16_b_F_yv4.fr = *(real_T *)&((char_T *)chartInstance->c16_F_yv4)[8];
  c16_b_F_yv4.rl = *(real_T *)&((char_T *)chartInstance->c16_F_yv4)[16];
  c16_b_F_yv4.rr = *(real_T *)&((char_T *)chartInstance->c16_F_yv4)[24];
  c16_b_F_z4.fl = *(real_T *)&((char_T *)chartInstance->c16_F_z4)[0];
  c16_b_F_z4.fr = *(real_T *)&((char_T *)chartInstance->c16_F_z4)[8];
  c16_b_F_z4.rl = *(real_T *)&((char_T *)chartInstance->c16_F_z4)[16];
  c16_b_F_z4.rr = *(real_T *)&((char_T *)chartInstance->c16_F_z4)[24];
  c16_b_Par = chartInstance->c16_Par;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 19U, 19U, c16_debug_family_names,
    c16_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_w1, 0U, c16_d_sf_marshallOut,
    c16_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_w2, 1U, c16_d_sf_marshallOut,
    c16_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_w3, 2U, c16_d_sf_marshallOut,
    c16_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_w4, 3U, c16_d_sf_marshallOut,
    c16_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_lf, 4U, c16_d_sf_marshallOut,
    c16_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_lr, 5U, c16_d_sf_marshallOut,
    c16_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_h, 6U, c16_d_sf_marshallOut,
    c16_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c16_T_oorpv, 7U, c16_g_sf_marshallOut,
    c16_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c16_F_xv4_temp, 8U, c16_f_sf_marshallOut,
    c16_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c16_F_yv4_temp, 9U, c16_f_sf_marshallOut,
    c16_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c16_F_z4_temp, 10U, c16_f_sf_marshallOut,
    c16_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c16_F_oorp3, 11U, c16_e_sf_marshallOut,
    c16_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_nargin, 12U, c16_d_sf_marshallOut,
    c16_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_nargout, 13U, c16_d_sf_marshallOut,
    c16_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c16_b_F_xv4, 14U, c16_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c16_b_F_yv4, 15U, c16_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c16_b_F_z4, 16U, c16_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_b_Par, 17U, c16_b_sf_marshallOut,
    c16_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_b_derv_oorp3, 18U,
    c16_sf_marshallOut, c16_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 5);
  c16_A = c16_b_Par.Veh.TrackWidth;
  c16_x = c16_A;
  c16_b_x = c16_x;
  c16_c_x = c16_b_x;
  c16_w1 = c16_c_x / 2.0;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 6);
  c16_w2 = -c16_w1;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 7);
  c16_w3 = c16_w1;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 8);
  c16_w4 = c16_w2;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 10);
  c16_lf = c16_b_Par.Veh.lf;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 11);
  c16_lr = c16_b_Par.Veh.lr;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 13);
  c16_h = c16_b_Par.Veh.h;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 15);
  c16_i0 = 0;
  for (c16_i1 = 0; c16_i1 < 4; c16_i1++) {
    c16_T_oorpv[c16_i0] = 1.0;
    c16_i0 += 3;
  }

  c16_T_oorpv[1] = c16_w1;
  c16_T_oorpv[4] = c16_w2;
  c16_T_oorpv[7] = c16_w3;
  c16_T_oorpv[10] = c16_w4;
  c16_T_oorpv[2] = -c16_lf;
  c16_T_oorpv[5] = -c16_lf;
  c16_T_oorpv[8] = -c16_lr;
  c16_T_oorpv[11] = -c16_lr;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 19);
  c16_F_xv4_temp[0] = c16_b_F_xv4.fl;
  c16_F_xv4_temp[1] = c16_b_F_xv4.fr;
  c16_F_xv4_temp[2] = c16_b_F_xv4.rl;
  c16_F_xv4_temp[3] = c16_b_F_xv4.rr;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 20);
  c16_F_yv4_temp[0] = c16_b_F_yv4.fl;
  c16_F_yv4_temp[1] = c16_b_F_yv4.fr;
  c16_F_yv4_temp[2] = c16_b_F_yv4.rl;
  c16_F_yv4_temp[3] = c16_b_F_yv4.rr;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 21);
  c16_F_z4_temp[0] = c16_b_F_z4.fl;
  c16_F_z4_temp[1] = c16_b_F_z4.fr;
  c16_F_z4_temp[2] = c16_b_F_z4.rl;
  c16_F_z4_temp[3] = c16_b_F_z4.rr;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 24);
  c16_i2 = 0;
  for (c16_i3 = 0; c16_i3 < 4; c16_i3++) {
    c16_a[c16_i2] = 0.0;
    c16_i2 += 3;
  }

  c16_i4 = 0;
  for (c16_i5 = 0; c16_i5 < 4; c16_i5++) {
    c16_a[c16_i4 + 1] = 0.0;
    c16_i4 += 3;
  }

  c16_a[2] = -c16_h;
  c16_a[5] = -c16_h;
  c16_a[8] = -c16_h;
  c16_a[11] = -c16_h;
  for (c16_i6 = 0; c16_i6 < 4; c16_i6++) {
    c16_b[c16_i6] = c16_F_xv4_temp[c16_i6];
  }

  c16_eml_scalar_eg(chartInstance);
  c16_eml_scalar_eg(chartInstance);
  for (c16_i7 = 0; c16_i7 < 3; c16_i7++) {
    c16_y[c16_i7] = 0.0;
  }

  for (c16_i8 = 0; c16_i8 < 12; c16_i8++) {
    c16_b_a[c16_i8] = c16_a[c16_i8];
  }

  for (c16_i9 = 0; c16_i9 < 4; c16_i9++) {
    c16_b_b[c16_i9] = c16_b[c16_i9];
  }

  c16_b_eml_xgemm(chartInstance, c16_b_a, c16_b_b, c16_y);
  c16_i10 = 0;
  for (c16_i11 = 0; c16_i11 < 4; c16_i11++) {
    c16_a[c16_i10] = 0.0;
    c16_i10 += 3;
  }

  c16_a[1] = c16_h;
  c16_a[4] = c16_h;
  c16_a[7] = c16_h;
  c16_a[10] = c16_h;
  c16_i12 = 0;
  for (c16_i13 = 0; c16_i13 < 4; c16_i13++) {
    c16_a[c16_i12 + 2] = 0.0;
    c16_i12 += 3;
  }

  for (c16_i14 = 0; c16_i14 < 4; c16_i14++) {
    c16_b[c16_i14] = c16_F_yv4_temp[c16_i14];
  }

  c16_eml_scalar_eg(chartInstance);
  c16_eml_scalar_eg(chartInstance);
  for (c16_i15 = 0; c16_i15 < 3; c16_i15++) {
    c16_b_y[c16_i15] = 0.0;
  }

  for (c16_i16 = 0; c16_i16 < 12; c16_i16++) {
    c16_c_a[c16_i16] = c16_a[c16_i16];
  }

  for (c16_i17 = 0; c16_i17 < 4; c16_i17++) {
    c16_c_b[c16_i17] = c16_b[c16_i17];
  }

  c16_b_eml_xgemm(chartInstance, c16_c_a, c16_c_b, c16_b_y);
  for (c16_i18 = 0; c16_i18 < 12; c16_i18++) {
    c16_a[c16_i18] = c16_T_oorpv[c16_i18];
  }

  for (c16_i19 = 0; c16_i19 < 4; c16_i19++) {
    c16_b[c16_i19] = c16_F_z4_temp[c16_i19];
  }

  c16_eml_scalar_eg(chartInstance);
  c16_eml_scalar_eg(chartInstance);
  for (c16_i20 = 0; c16_i20 < 3; c16_i20++) {
    c16_c_y[c16_i20] = 0.0;
  }

  for (c16_i21 = 0; c16_i21 < 12; c16_i21++) {
    c16_d_a[c16_i21] = c16_a[c16_i21];
  }

  for (c16_i22 = 0; c16_i22 < 4; c16_i22++) {
    c16_d_b[c16_i22] = c16_b[c16_i22];
  }

  c16_b_eml_xgemm(chartInstance, c16_d_a, c16_d_b, c16_c_y);
  c16_c_Par[0] = -c16_b_Par.Veh.m * c16_b_Par.Env.g;
  c16_c_Par[1] = 0.0;
  c16_c_Par[2] = 0.0;
  for (c16_i23 = 0; c16_i23 < 3; c16_i23++) {
    c16_F_oorp3[c16_i23] = ((c16_y[c16_i23] + c16_b_y[c16_i23]) +
      c16_c_y[c16_i23]) + c16_c_Par[c16_i23];
  }

  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 29);
  c16_b_A = c16_F_oorp3[0];
  c16_B = c16_b_Par.Veh.m_sprung;
  c16_d_x = c16_b_A;
  c16_d_y = c16_B;
  c16_e_x = c16_d_x;
  c16_e_y = c16_d_y;
  c16_f_x = c16_e_x;
  c16_f_y = c16_e_y;
  c16_g_y = c16_f_x / c16_f_y;
  c16_b_derv_oorp3.z = c16_g_y;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 30);
  c16_c_A = c16_F_oorp3[1];
  c16_b_B = c16_b_Par.Veh.Jx_sprung;
  c16_g_x = c16_c_A;
  c16_h_y = c16_b_B;
  c16_h_x = c16_g_x;
  c16_i_y = c16_h_y;
  c16_i_x = c16_h_x;
  c16_j_y = c16_i_y;
  c16_k_y = c16_i_x / c16_j_y;
  c16_b_derv_oorp3.rotx = c16_k_y;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 31);
  c16_d_A = c16_F_oorp3[2];
  c16_c_B = c16_b_Par.Veh.Jy_sprung;
  c16_j_x = c16_d_A;
  c16_l_y = c16_c_B;
  c16_k_x = c16_j_x;
  c16_m_y = c16_l_y;
  c16_l_x = c16_k_x;
  c16_n_y = c16_m_y;
  c16_o_y = c16_l_x / c16_n_y;
  c16_b_derv_oorp3.roty = c16_o_y;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, -31);
  _SFD_SYMBOL_SCOPE_POP();
  *(real_T *)&((char_T *)chartInstance->c16_derv_oorp3)[0] = c16_b_derv_oorp3.z;
  *(real_T *)&((char_T *)chartInstance->c16_derv_oorp3)[8] =
    c16_b_derv_oorp3.rotx;
  *(real_T *)&((char_T *)chartInstance->c16_derv_oorp3)[16] =
    c16_b_derv_oorp3.roty;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 15U, chartInstance->c16_sfEvent);
}

static void initSimStructsc16_Modified(SFc16_ModifiedInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c16_machineNumber, uint32_T
  c16_chartNumber, uint32_T c16_instanceNumber)
{
  (void)c16_machineNumber;
  (void)c16_chartNumber;
  (void)c16_instanceNumber;
}

static const mxArray *c16_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  c16_oorp_vec3 c16_u;
  const mxArray *c16_y = NULL;
  real_T c16_b_u;
  const mxArray *c16_b_y = NULL;
  real_T c16_c_u;
  const mxArray *c16_c_y = NULL;
  real_T c16_d_u;
  const mxArray *c16_d_y = NULL;
  SFc16_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc16_ModifiedInstanceStruct *)chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  c16_u = *(c16_oorp_vec3 *)c16_inData;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c16_b_u = c16_u.z;
  c16_b_y = NULL;
  sf_mex_assign(&c16_b_y, sf_mex_create("y", &c16_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c16_y, c16_b_y, "z", "z", 0);
  c16_c_u = c16_u.rotx;
  c16_c_y = NULL;
  sf_mex_assign(&c16_c_y, sf_mex_create("y", &c16_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c16_y, c16_c_y, "rotx", "rotx", 0);
  c16_d_u = c16_u.roty;
  c16_d_y = NULL;
  sf_mex_assign(&c16_d_y, sf_mex_create("y", &c16_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c16_y, c16_d_y, "roty", "roty", 0);
  sf_mex_assign(&c16_mxArrayOutData, c16_y, false);
  return c16_mxArrayOutData;
}

static c16_oorp_vec3 c16_emlrt_marshallIn(SFc16_ModifiedInstanceStruct
  *chartInstance, const mxArray *c16_b_derv_oorp3, const char_T *c16_identifier)
{
  c16_oorp_vec3 c16_y;
  emlrtMsgIdentifier c16_thisId;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_b_derv_oorp3),
    &c16_thisId);
  sf_mex_destroy(&c16_b_derv_oorp3);
  return c16_y;
}

static c16_oorp_vec3 c16_b_emlrt_marshallIn(SFc16_ModifiedInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId)
{
  c16_oorp_vec3 c16_y;
  emlrtMsgIdentifier c16_thisId;
  static const char * c16_fieldNames[3] = { "z", "rotx", "roty" };

  c16_thisId.fParent = c16_parentId;
  sf_mex_check_struct(c16_parentId, c16_u, 3, c16_fieldNames, 0U, NULL);
  c16_thisId.fIdentifier = "z";
  c16_y.z = c16_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c16_u, "z", "z", 0)), &c16_thisId);
  c16_thisId.fIdentifier = "rotx";
  c16_y.rotx = c16_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c16_u, "rotx", "rotx", 0)), &c16_thisId);
  c16_thisId.fIdentifier = "roty";
  c16_y.roty = c16_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c16_u, "roty", "roty", 0)), &c16_thisId);
  sf_mex_destroy(&c16_u);
  return c16_y;
}

static real_T c16_c_emlrt_marshallIn(SFc16_ModifiedInstanceStruct *chartInstance,
  const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId)
{
  real_T c16_y;
  real_T c16_d0;
  (void)chartInstance;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), &c16_d0, 1, 0, 0U, 0, 0U, 0);
  c16_y = c16_d0;
  sf_mex_destroy(&c16_u);
  return c16_y;
}

static void c16_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData)
{
  const mxArray *c16_b_derv_oorp3;
  const char_T *c16_identifier;
  emlrtMsgIdentifier c16_thisId;
  c16_oorp_vec3 c16_y;
  SFc16_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc16_ModifiedInstanceStruct *)chartInstanceVoid;
  c16_b_derv_oorp3 = sf_mex_dup(c16_mxArrayInData);
  c16_identifier = c16_varName;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_b_derv_oorp3),
    &c16_thisId);
  sf_mex_destroy(&c16_b_derv_oorp3);
  *(c16_oorp_vec3 *)c16_outData = c16_y;
  sf_mex_destroy(&c16_mxArrayInData);
}

static const mxArray *c16_b_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData;
  c16_struct_iBlsPBO3AGnt69vDoTx5zD c16_u;
  const mxArray *c16_y = NULL;
  c16_struct_Nst2vGTExxHsg85EUOj9EH c16_b_u;
  const mxArray *c16_b_y = NULL;
  real_T c16_c_u;
  const mxArray *c16_c_y = NULL;
  c16_struct_HhckT6rntEraqECYVIDvCC c16_d_u;
  const mxArray *c16_d_y = NULL;
  real_T c16_e_u;
  const mxArray *c16_e_y = NULL;
  real_T c16_f_u;
  const mxArray *c16_f_y = NULL;
  const mxArray *c16_g_y = NULL;
  real_T c16_g_u;
  const mxArray *c16_h_y = NULL;
  real_T c16_h_u;
  const mxArray *c16_i_y = NULL;
  const mxArray *c16_j_y = NULL;
  real_T c16_i_u;
  const mxArray *c16_k_y = NULL;
  real_T c16_j_u;
  const mxArray *c16_l_y = NULL;
  const mxArray *c16_m_y = NULL;
  real_T c16_k_u;
  const mxArray *c16_n_y = NULL;
  real_T c16_l_u;
  const mxArray *c16_o_y = NULL;
  const mxArray *c16_p_y = NULL;
  real_T c16_m_u;
  const mxArray *c16_q_y = NULL;
  real_T c16_n_u;
  const mxArray *c16_r_y = NULL;
  real_T c16_o_u;
  const mxArray *c16_s_y = NULL;
  c16_struct_ZCmOWPuqBDw16FSOVVD00 c16_p_u;
  const mxArray *c16_t_y = NULL;
  real_T c16_q_u;
  const mxArray *c16_u_y = NULL;
  real_T c16_r_u;
  const mxArray *c16_v_y = NULL;
  real_T c16_s_u;
  const mxArray *c16_w_y = NULL;
  real_T c16_t_u;
  const mxArray *c16_x_y = NULL;
  real_T c16_u_u;
  const mxArray *c16_y_y = NULL;
  real_T c16_v_u;
  const mxArray *c16_ab_y = NULL;
  real_T c16_w_u;
  const mxArray *c16_bb_y = NULL;
  real_T c16_x_u;
  const mxArray *c16_cb_y = NULL;
  real_T c16_y_u;
  const mxArray *c16_db_y = NULL;
  real_T c16_ab_u;
  const mxArray *c16_eb_y = NULL;
  real_T c16_bb_u;
  const mxArray *c16_fb_y = NULL;
  int32_T c16_i24;
  real_T c16_cb_u[4];
  const mxArray *c16_gb_y = NULL;
  real_T c16_db_u;
  const mxArray *c16_hb_y = NULL;
  c16_struct_ZKAzdrl7umDGJoC14aoVKC c16_eb_u;
  const mxArray *c16_ib_y = NULL;
  int32_T c16_i25;
  real_T c16_fb_u[3];
  const mxArray *c16_jb_y = NULL;
  int32_T c16_i26;
  real_T c16_gb_u[3];
  const mxArray *c16_kb_y = NULL;
  int32_T c16_i27;
  real_T c16_hb_u[3];
  const mxArray *c16_lb_y = NULL;
  int32_T c16_i28;
  real_T c16_ib_u[3];
  const mxArray *c16_mb_y = NULL;
  const mxArray *c16_nb_y = NULL;
  int32_T c16_i29;
  real_T c16_jb_u[3];
  const mxArray *c16_ob_y = NULL;
  int32_T c16_i30;
  real_T c16_kb_u[3];
  const mxArray *c16_pb_y = NULL;
  int32_T c16_i31;
  real_T c16_lb_u[3];
  const mxArray *c16_qb_y = NULL;
  int32_T c16_i32;
  real_T c16_mb_u[3];
  const mxArray *c16_rb_y = NULL;
  const mxArray *c16_sb_y = NULL;
  int32_T c16_i33;
  real_T c16_nb_u[3];
  const mxArray *c16_tb_y = NULL;
  int32_T c16_i34;
  real_T c16_ob_u[3];
  const mxArray *c16_ub_y = NULL;
  int32_T c16_i35;
  real_T c16_pb_u[3];
  const mxArray *c16_vb_y = NULL;
  int32_T c16_i36;
  real_T c16_qb_u[3];
  const mxArray *c16_wb_y = NULL;
  const mxArray *c16_xb_y = NULL;
  int32_T c16_i37;
  real_T c16_rb_u[3];
  const mxArray *c16_yb_y = NULL;
  int32_T c16_i38;
  real_T c16_sb_u[3];
  const mxArray *c16_ac_y = NULL;
  int32_T c16_i39;
  real_T c16_tb_u[3];
  const mxArray *c16_bc_y = NULL;
  int32_T c16_i40;
  real_T c16_ub_u[3];
  const mxArray *c16_cc_y = NULL;
  real_T c16_vb_u;
  const mxArray *c16_dc_y = NULL;
  real_T c16_wb_u;
  const mxArray *c16_ec_y = NULL;
  real_T c16_xb_u;
  const mxArray *c16_fc_y = NULL;
  real_T c16_yb_u;
  const mxArray *c16_gc_y = NULL;
  real_T c16_ac_u;
  const mxArray *c16_hc_y = NULL;
  real_T c16_bc_u;
  const mxArray *c16_ic_y = NULL;
  real_T c16_cc_u;
  const mxArray *c16_jc_y = NULL;
  real_T c16_dc_u;
  const mxArray *c16_kc_y = NULL;
  real_T c16_ec_u;
  const mxArray *c16_lc_y = NULL;
  real_T c16_fc_u;
  const mxArray *c16_mc_y = NULL;
  real_T c16_gc_u;
  const mxArray *c16_nc_y = NULL;
  real_T c16_hc_u;
  const mxArray *c16_oc_y = NULL;
  c16_struct_r4FNviKwHfdhB8nQjvQv9 c16_ic_u;
  const mxArray *c16_pc_y = NULL;
  real_T c16_jc_u;
  const mxArray *c16_qc_y = NULL;
  c16_struct_Y9F1qlBi9AhssksPwemA4G c16_kc_u;
  const mxArray *c16_rc_y = NULL;
  real_T c16_lc_u;
  const mxArray *c16_sc_y = NULL;
  real_T c16_mc_u;
  const mxArray *c16_tc_y = NULL;
  real_T c16_nc_u;
  const mxArray *c16_uc_y = NULL;
  SFc16_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc16_ModifiedInstanceStruct *)chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  c16_mxArrayOutData = NULL;
  c16_u = *(c16_struct_iBlsPBO3AGnt69vDoTx5zD *)c16_inData;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c16_b_u = c16_u.Env;
  c16_b_y = NULL;
  sf_mex_assign(&c16_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c16_c_u = c16_b_u.g;
  c16_c_y = NULL;
  sf_mex_assign(&c16_c_y, sf_mex_create("y", &c16_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c16_b_y, c16_c_y, "g", "g", 0);
  c16_d_u = c16_b_u.left1;
  c16_d_y = NULL;
  sf_mex_assign(&c16_d_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c16_e_u = c16_d_u.x;
  c16_e_y = NULL;
  sf_mex_assign(&c16_e_y, sf_mex_create("y", &c16_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c16_d_y, c16_e_y, "x", "x", 0);
  c16_f_u = c16_d_u.y;
  c16_f_y = NULL;
  sf_mex_assign(&c16_f_y, sf_mex_create("y", &c16_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c16_d_y, c16_f_y, "y", "y", 0);
  sf_mex_addfield(c16_b_y, c16_d_y, "left1", "left1", 0);
  c16_d_u = c16_b_u.right1;
  c16_g_y = NULL;
  sf_mex_assign(&c16_g_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c16_g_u = c16_d_u.x;
  c16_h_y = NULL;
  sf_mex_assign(&c16_h_y, sf_mex_create("y", &c16_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c16_g_y, c16_h_y, "x", "x", 0);
  c16_h_u = c16_d_u.y;
  c16_i_y = NULL;
  sf_mex_assign(&c16_i_y, sf_mex_create("y", &c16_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c16_g_y, c16_i_y, "y", "y", 0);
  sf_mex_addfield(c16_b_y, c16_g_y, "right1", "right1", 0);
  c16_d_u = c16_b_u.right2;
  c16_j_y = NULL;
  sf_mex_assign(&c16_j_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c16_i_u = c16_d_u.x;
  c16_k_y = NULL;
  sf_mex_assign(&c16_k_y, sf_mex_create("y", &c16_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c16_j_y, c16_k_y, "x", "x", 0);
  c16_j_u = c16_d_u.y;
  c16_l_y = NULL;
  sf_mex_assign(&c16_l_y, sf_mex_create("y", &c16_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c16_j_y, c16_l_y, "y", "y", 0);
  sf_mex_addfield(c16_b_y, c16_j_y, "right2", "right2", 0);
  c16_d_u = c16_b_u.left2;
  c16_m_y = NULL;
  sf_mex_assign(&c16_m_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c16_k_u = c16_d_u.x;
  c16_n_y = NULL;
  sf_mex_assign(&c16_n_y, sf_mex_create("y", &c16_k_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c16_m_y, c16_n_y, "x", "x", 0);
  c16_l_u = c16_d_u.y;
  c16_o_y = NULL;
  sf_mex_assign(&c16_o_y, sf_mex_create("y", &c16_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c16_m_y, c16_o_y, "y", "y", 0);
  sf_mex_addfield(c16_b_y, c16_m_y, "left2", "left2", 0);
  c16_d_u = c16_b_u.right3;
  c16_p_y = NULL;
  sf_mex_assign(&c16_p_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c16_m_u = c16_d_u.x;
  c16_q_y = NULL;
  sf_mex_assign(&c16_q_y, sf_mex_create("y", &c16_m_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c16_p_y, c16_q_y, "x", "x", 0);
  c16_n_u = c16_d_u.y;
  c16_r_y = NULL;
  sf_mex_assign(&c16_r_y, sf_mex_create("y", &c16_n_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c16_p_y, c16_r_y, "y", "y", 0);
  sf_mex_addfield(c16_b_y, c16_p_y, "right3", "right3", 0);
  c16_o_u = c16_b_u.mu;
  c16_s_y = NULL;
  sf_mex_assign(&c16_s_y, sf_mex_create("y", &c16_o_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c16_b_y, c16_s_y, "mu", "mu", 0);
  sf_mex_addfield(c16_y, c16_b_y, "Env", "Env", 0);
  c16_p_u = c16_u.Veh;
  c16_t_y = NULL;
  sf_mex_assign(&c16_t_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c16_q_u = c16_p_u.m;
  c16_u_y = NULL;
  sf_mex_assign(&c16_u_y, sf_mex_create("y", &c16_q_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c16_t_y, c16_u_y, "m", "m", 0);
  c16_r_u = c16_p_u.Jz;
  c16_v_y = NULL;
  sf_mex_assign(&c16_v_y, sf_mex_create("y", &c16_r_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c16_t_y, c16_v_y, "Jz", "Jz", 0);
  c16_s_u = c16_p_u.m_sprung;
  c16_w_y = NULL;
  sf_mex_assign(&c16_w_y, sf_mex_create("y", &c16_s_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c16_t_y, c16_w_y, "m_sprung", "m_sprung", 0);
  c16_t_u = c16_p_u.Jx_sprung;
  c16_x_y = NULL;
  sf_mex_assign(&c16_x_y, sf_mex_create("y", &c16_t_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c16_t_y, c16_x_y, "Jx_sprung", "Jx_sprung", 0);
  c16_u_u = c16_p_u.Jy_sprung;
  c16_y_y = NULL;
  sf_mex_assign(&c16_y_y, sf_mex_create("y", &c16_u_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c16_t_y, c16_y_y, "Jy_sprung", "Jy_sprung", 0);
  c16_v_u = c16_p_u.lf;
  c16_ab_y = NULL;
  sf_mex_assign(&c16_ab_y, sf_mex_create("y", &c16_v_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c16_t_y, c16_ab_y, "lf", "lf", 0);
  c16_w_u = c16_p_u.lr;
  c16_bb_y = NULL;
  sf_mex_assign(&c16_bb_y, sf_mex_create("y", &c16_w_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c16_t_y, c16_bb_y, "lr", "lr", 0);
  c16_x_u = c16_p_u.L;
  c16_cb_y = NULL;
  sf_mex_assign(&c16_cb_y, sf_mex_create("y", &c16_x_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c16_t_y, c16_cb_y, "L", "L", 0);
  c16_y_u = c16_p_u.TrackWidth;
  c16_db_y = NULL;
  sf_mex_assign(&c16_db_y, sf_mex_create("y", &c16_y_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c16_t_y, c16_db_y, "TrackWidth", "TrackWidth", 0);
  c16_ab_u = c16_p_u.h;
  c16_eb_y = NULL;
  sf_mex_assign(&c16_eb_y, sf_mex_create("y", &c16_ab_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c16_t_y, c16_eb_y, "h", "h", 0);
  c16_bb_u = c16_p_u.HalfRohACd;
  c16_fb_y = NULL;
  sf_mex_assign(&c16_fb_y, sf_mex_create("y", &c16_bb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c16_t_y, c16_fb_y, "HalfRohACd", "HalfRohACd", 0);
  for (c16_i24 = 0; c16_i24 < 4; c16_i24++) {
    c16_cb_u[c16_i24] = c16_p_u.F_z4_static[c16_i24];
  }

  c16_gb_y = NULL;
  sf_mex_assign(&c16_gb_y, sf_mex_create("y", c16_cb_u, 0, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_addfield(c16_t_y, c16_gb_y, "F_z4_static", "F_z4_static", 0);
  c16_db_u = c16_p_u.Rw;
  c16_hb_y = NULL;
  sf_mex_assign(&c16_hb_y, sf_mex_create("y", &c16_db_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c16_t_y, c16_hb_y, "Rw", "Rw", 0);
  c16_eb_u = c16_p_u.r_long;
  c16_ib_y = NULL;
  sf_mex_assign(&c16_ib_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c16_i25 = 0; c16_i25 < 3; c16_i25++) {
    c16_fb_u[c16_i25] = c16_eb_u.fl[c16_i25];
  }

  c16_jb_y = NULL;
  sf_mex_assign(&c16_jb_y, sf_mex_create("y", c16_fb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c16_ib_y, c16_jb_y, "fl", "fl", 0);
  for (c16_i26 = 0; c16_i26 < 3; c16_i26++) {
    c16_gb_u[c16_i26] = c16_eb_u.fr[c16_i26];
  }

  c16_kb_y = NULL;
  sf_mex_assign(&c16_kb_y, sf_mex_create("y", c16_gb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c16_ib_y, c16_kb_y, "fr", "fr", 0);
  for (c16_i27 = 0; c16_i27 < 3; c16_i27++) {
    c16_hb_u[c16_i27] = c16_eb_u.rl[c16_i27];
  }

  c16_lb_y = NULL;
  sf_mex_assign(&c16_lb_y, sf_mex_create("y", c16_hb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c16_ib_y, c16_lb_y, "rl", "rl", 0);
  for (c16_i28 = 0; c16_i28 < 3; c16_i28++) {
    c16_ib_u[c16_i28] = c16_eb_u.rr[c16_i28];
  }

  c16_mb_y = NULL;
  sf_mex_assign(&c16_mb_y, sf_mex_create("y", c16_ib_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c16_ib_y, c16_mb_y, "rr", "rr", 0);
  sf_mex_addfield(c16_t_y, c16_ib_y, "r_long", "r_long", 0);
  c16_eb_u = c16_p_u.r_lat;
  c16_nb_y = NULL;
  sf_mex_assign(&c16_nb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c16_i29 = 0; c16_i29 < 3; c16_i29++) {
    c16_jb_u[c16_i29] = c16_eb_u.fl[c16_i29];
  }

  c16_ob_y = NULL;
  sf_mex_assign(&c16_ob_y, sf_mex_create("y", c16_jb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c16_nb_y, c16_ob_y, "fl", "fl", 0);
  for (c16_i30 = 0; c16_i30 < 3; c16_i30++) {
    c16_kb_u[c16_i30] = c16_eb_u.fr[c16_i30];
  }

  c16_pb_y = NULL;
  sf_mex_assign(&c16_pb_y, sf_mex_create("y", c16_kb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c16_nb_y, c16_pb_y, "fr", "fr", 0);
  for (c16_i31 = 0; c16_i31 < 3; c16_i31++) {
    c16_lb_u[c16_i31] = c16_eb_u.rl[c16_i31];
  }

  c16_qb_y = NULL;
  sf_mex_assign(&c16_qb_y, sf_mex_create("y", c16_lb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c16_nb_y, c16_qb_y, "rl", "rl", 0);
  for (c16_i32 = 0; c16_i32 < 3; c16_i32++) {
    c16_mb_u[c16_i32] = c16_eb_u.rr[c16_i32];
  }

  c16_rb_y = NULL;
  sf_mex_assign(&c16_rb_y, sf_mex_create("y", c16_mb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c16_nb_y, c16_rb_y, "rr", "rr", 0);
  sf_mex_addfield(c16_t_y, c16_nb_y, "r_lat", "r_lat", 0);
  c16_eb_u = c16_p_u.r_lever;
  c16_sb_y = NULL;
  sf_mex_assign(&c16_sb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c16_i33 = 0; c16_i33 < 3; c16_i33++) {
    c16_nb_u[c16_i33] = c16_eb_u.fl[c16_i33];
  }

  c16_tb_y = NULL;
  sf_mex_assign(&c16_tb_y, sf_mex_create("y", c16_nb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c16_sb_y, c16_tb_y, "fl", "fl", 0);
  for (c16_i34 = 0; c16_i34 < 3; c16_i34++) {
    c16_ob_u[c16_i34] = c16_eb_u.fr[c16_i34];
  }

  c16_ub_y = NULL;
  sf_mex_assign(&c16_ub_y, sf_mex_create("y", c16_ob_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c16_sb_y, c16_ub_y, "fr", "fr", 0);
  for (c16_i35 = 0; c16_i35 < 3; c16_i35++) {
    c16_pb_u[c16_i35] = c16_eb_u.rl[c16_i35];
  }

  c16_vb_y = NULL;
  sf_mex_assign(&c16_vb_y, sf_mex_create("y", c16_pb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c16_sb_y, c16_vb_y, "rl", "rl", 0);
  for (c16_i36 = 0; c16_i36 < 3; c16_i36++) {
    c16_qb_u[c16_i36] = c16_eb_u.rr[c16_i36];
  }

  c16_wb_y = NULL;
  sf_mex_assign(&c16_wb_y, sf_mex_create("y", c16_qb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c16_sb_y, c16_wb_y, "rr", "rr", 0);
  sf_mex_addfield(c16_t_y, c16_sb_y, "r_lever", "r_lever", 0);
  c16_eb_u = c16_p_u.r_pivot;
  c16_xb_y = NULL;
  sf_mex_assign(&c16_xb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c16_i37 = 0; c16_i37 < 3; c16_i37++) {
    c16_rb_u[c16_i37] = c16_eb_u.fl[c16_i37];
  }

  c16_yb_y = NULL;
  sf_mex_assign(&c16_yb_y, sf_mex_create("y", c16_rb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c16_xb_y, c16_yb_y, "fl", "fl", 0);
  for (c16_i38 = 0; c16_i38 < 3; c16_i38++) {
    c16_sb_u[c16_i38] = c16_eb_u.fr[c16_i38];
  }

  c16_ac_y = NULL;
  sf_mex_assign(&c16_ac_y, sf_mex_create("y", c16_sb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c16_xb_y, c16_ac_y, "fr", "fr", 0);
  for (c16_i39 = 0; c16_i39 < 3; c16_i39++) {
    c16_tb_u[c16_i39] = c16_eb_u.rl[c16_i39];
  }

  c16_bc_y = NULL;
  sf_mex_assign(&c16_bc_y, sf_mex_create("y", c16_tb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c16_xb_y, c16_bc_y, "rl", "rl", 0);
  for (c16_i40 = 0; c16_i40 < 3; c16_i40++) {
    c16_ub_u[c16_i40] = c16_eb_u.rr[c16_i40];
  }

  c16_cc_y = NULL;
  sf_mex_assign(&c16_cc_y, sf_mex_create("y", c16_ub_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c16_xb_y, c16_cc_y, "rr", "rr", 0);
  sf_mex_addfield(c16_t_y, c16_xb_y, "r_pivot", "r_pivot", 0);
  c16_vb_u = c16_p_u.cw;
  c16_dc_y = NULL;
  sf_mex_assign(&c16_dc_y, sf_mex_create("y", &c16_vb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c16_t_y, c16_dc_y, "cw", "cw", 0);
  c16_wb_u = c16_p_u.carb_f;
  c16_ec_y = NULL;
  sf_mex_assign(&c16_ec_y, sf_mex_create("y", &c16_wb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c16_t_y, c16_ec_y, "carb_f", "carb_f", 0);
  c16_xb_u = c16_p_u.carb_r;
  c16_fc_y = NULL;
  sf_mex_assign(&c16_fc_y, sf_mex_create("y", &c16_xb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c16_t_y, c16_fc_y, "carb_r", "carb_r", 0);
  c16_yb_u = c16_p_u.dw;
  c16_gc_y = NULL;
  sf_mex_assign(&c16_gc_y, sf_mex_create("y", &c16_yb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c16_t_y, c16_gc_y, "dw", "dw", 0);
  c16_ac_u = c16_p_u.Jw;
  c16_hc_y = NULL;
  sf_mex_assign(&c16_hc_y, sf_mex_create("y", &c16_ac_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c16_t_y, c16_hc_y, "Jw", "Jw", 0);
  c16_bc_u = c16_p_u.C0;
  c16_ic_y = NULL;
  sf_mex_assign(&c16_ic_y, sf_mex_create("y", &c16_bc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c16_t_y, c16_ic_y, "C0", "C0", 0);
  c16_cc_u = c16_p_u.RelaxLength;
  c16_jc_y = NULL;
  sf_mex_assign(&c16_jc_y, sf_mex_create("y", &c16_cc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c16_t_y, c16_jc_y, "RelaxLength", "RelaxLength", 0);
  c16_dc_u = c16_p_u.RRC;
  c16_kc_y = NULL;
  sf_mex_assign(&c16_kc_y, sf_mex_create("y", &c16_dc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c16_t_y, c16_kc_y, "RRC", "RRC", 0);
  c16_ec_u = c16_p_u.Pmax;
  c16_lc_y = NULL;
  sf_mex_assign(&c16_lc_y, sf_mex_create("y", &c16_ec_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c16_t_y, c16_lc_y, "Pmax", "Pmax", 0);
  c16_fc_u = c16_p_u.PropDistrFrnt;
  c16_mc_y = NULL;
  sf_mex_assign(&c16_mc_y, sf_mex_create("y", &c16_fc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c16_t_y, c16_mc_y, "PropDistrFrnt", "PropDistrFrnt", 0);
  c16_gc_u = c16_p_u.BrkDistrFrnt;
  c16_nc_y = NULL;
  sf_mex_assign(&c16_nc_y, sf_mex_create("y", &c16_gc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c16_t_y, c16_nc_y, "BrkDistrFrnt", "BrkDistrFrnt", 0);
  c16_hc_u = c16_p_u.SteRatio;
  c16_oc_y = NULL;
  sf_mex_assign(&c16_oc_y, sf_mex_create("y", &c16_hc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c16_t_y, c16_oc_y, "SteRatio", "SteRatio", 0);
  sf_mex_addfield(c16_y, c16_t_y, "Veh", "Veh", 0);
  c16_ic_u = c16_u.Drvr;
  c16_pc_y = NULL;
  sf_mex_assign(&c16_pc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c16_jc_u = c16_ic_u.v_set;
  c16_qc_y = NULL;
  sf_mex_assign(&c16_qc_y, sf_mex_create("y", &c16_jc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c16_pc_y, c16_qc_y, "v_set", "v_set", 0);
  sf_mex_addfield(c16_y, c16_pc_y, "Drvr", "Drvr", 0);
  c16_kc_u = c16_u.Init;
  c16_rc_y = NULL;
  sf_mex_assign(&c16_rc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c16_lc_u = c16_kc_u.v_x;
  c16_sc_y = NULL;
  sf_mex_assign(&c16_sc_y, sf_mex_create("y", &c16_lc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c16_rc_y, c16_sc_y, "v_x", "v_x", 0);
  c16_mc_u = c16_kc_u.F_fz;
  c16_tc_y = NULL;
  sf_mex_assign(&c16_tc_y, sf_mex_create("y", &c16_mc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c16_rc_y, c16_tc_y, "F_fz", "F_fz", 0);
  c16_nc_u = c16_kc_u.F_rz;
  c16_uc_y = NULL;
  sf_mex_assign(&c16_uc_y, sf_mex_create("y", &c16_nc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c16_rc_y, c16_uc_y, "F_rz", "F_rz", 0);
  sf_mex_addfield(c16_y, c16_rc_y, "Init", "Init", 0);
  sf_mex_assign(&c16_mxArrayOutData, c16_y, false);
  return c16_mxArrayOutData;
}

static void c16_d_emlrt_marshallIn(SFc16_ModifiedInstanceStruct *chartInstance,
  const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId,
  c16_struct_iBlsPBO3AGnt69vDoTx5zD *c16_y)
{
  emlrtMsgIdentifier c16_thisId;
  static const char * c16_fieldNames[4] = { "Env", "Veh", "Drvr", "Init" };

  c16_thisId.fParent = c16_parentId;
  sf_mex_check_struct(c16_parentId, c16_u, 4, c16_fieldNames, 0U, NULL);
  c16_thisId.fIdentifier = "Env";
  c16_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c16_u, "Env",
    "Env", 0)), &c16_thisId, &c16_y->Env);
  c16_thisId.fIdentifier = "Veh";
  c16_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c16_u, "Veh",
    "Veh", 0)), &c16_thisId, &c16_y->Veh);
  c16_thisId.fIdentifier = "Drvr";
  c16_y->Drvr = c16_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c16_u, "Drvr", "Drvr", 0)), &c16_thisId);
  c16_thisId.fIdentifier = "Init";
  c16_y->Init = c16_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c16_u, "Init", "Init", 0)), &c16_thisId);
  sf_mex_destroy(&c16_u);
}

static void c16_e_emlrt_marshallIn(SFc16_ModifiedInstanceStruct *chartInstance,
  const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId,
  c16_struct_Nst2vGTExxHsg85EUOj9EH *c16_y)
{
  emlrtMsgIdentifier c16_thisId;
  static const char * c16_fieldNames[7] = { "g", "left1", "right1", "right2",
    "left2", "right3", "mu" };

  c16_thisId.fParent = c16_parentId;
  sf_mex_check_struct(c16_parentId, c16_u, 7, c16_fieldNames, 0U, NULL);
  c16_thisId.fIdentifier = "g";
  c16_y->g = c16_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c16_u, "g", "g", 0)), &c16_thisId);
  c16_thisId.fIdentifier = "left1";
  c16_y->left1 = c16_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c16_u, "left1", "left1", 0)), &c16_thisId);
  c16_thisId.fIdentifier = "right1";
  c16_y->right1 = c16_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c16_u, "right1", "right1", 0)), &c16_thisId);
  c16_thisId.fIdentifier = "right2";
  c16_y->right2 = c16_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c16_u, "right2", "right2", 0)), &c16_thisId);
  c16_thisId.fIdentifier = "left2";
  c16_y->left2 = c16_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c16_u, "left2", "left2", 0)), &c16_thisId);
  c16_thisId.fIdentifier = "right3";
  c16_y->right3 = c16_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c16_u, "right3", "right3", 0)), &c16_thisId);
  c16_thisId.fIdentifier = "mu";
  c16_y->mu = c16_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c16_u, "mu", "mu", 0)), &c16_thisId);
  sf_mex_destroy(&c16_u);
}

static c16_struct_HhckT6rntEraqECYVIDvCC c16_f_emlrt_marshallIn
  (SFc16_ModifiedInstanceStruct *chartInstance, const mxArray *c16_u, const
   emlrtMsgIdentifier *c16_parentId)
{
  c16_struct_HhckT6rntEraqECYVIDvCC c16_y;
  emlrtMsgIdentifier c16_thisId;
  static const char * c16_fieldNames[2] = { "x", "y" };

  c16_thisId.fParent = c16_parentId;
  sf_mex_check_struct(c16_parentId, c16_u, 2, c16_fieldNames, 0U, NULL);
  c16_thisId.fIdentifier = "x";
  c16_y.x = c16_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c16_u, "x", "x", 0)), &c16_thisId);
  c16_thisId.fIdentifier = "y";
  c16_y.y = c16_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c16_u, "y", "y", 0)), &c16_thisId);
  sf_mex_destroy(&c16_u);
  return c16_y;
}

static void c16_g_emlrt_marshallIn(SFc16_ModifiedInstanceStruct *chartInstance,
  const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId,
  c16_struct_ZCmOWPuqBDw16FSOVVD00 *c16_y)
{
  emlrtMsgIdentifier c16_thisId;
  static const char * c16_fieldNames[29] = { "m", "Jz", "m_sprung", "Jx_sprung",
    "Jy_sprung", "lf", "lr", "L", "TrackWidth", "h", "HalfRohACd", "F_z4_static",
    "Rw", "r_long", "r_lat", "r_lever", "r_pivot", "cw", "carb_f", "carb_r",
    "dw", "Jw", "C0", "RelaxLength", "RRC", "Pmax", "PropDistrFrnt",
    "BrkDistrFrnt", "SteRatio" };

  c16_thisId.fParent = c16_parentId;
  sf_mex_check_struct(c16_parentId, c16_u, 29, c16_fieldNames, 0U, NULL);
  c16_thisId.fIdentifier = "m";
  c16_y->m = c16_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c16_u, "m", "m", 0)), &c16_thisId);
  c16_thisId.fIdentifier = "Jz";
  c16_y->Jz = c16_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c16_u, "Jz", "Jz", 0)), &c16_thisId);
  c16_thisId.fIdentifier = "m_sprung";
  c16_y->m_sprung = c16_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c16_u, "m_sprung", "m_sprung", 0)), &c16_thisId);
  c16_thisId.fIdentifier = "Jx_sprung";
  c16_y->Jx_sprung = c16_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c16_u, "Jx_sprung", "Jx_sprung", 0)), &c16_thisId);
  c16_thisId.fIdentifier = "Jy_sprung";
  c16_y->Jy_sprung = c16_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c16_u, "Jy_sprung", "Jy_sprung", 0)), &c16_thisId);
  c16_thisId.fIdentifier = "lf";
  c16_y->lf = c16_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c16_u, "lf", "lf", 0)), &c16_thisId);
  c16_thisId.fIdentifier = "lr";
  c16_y->lr = c16_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c16_u, "lr", "lr", 0)), &c16_thisId);
  c16_thisId.fIdentifier = "L";
  c16_y->L = c16_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c16_u, "L", "L", 0)), &c16_thisId);
  c16_thisId.fIdentifier = "TrackWidth";
  c16_y->TrackWidth = c16_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c16_u, "TrackWidth", "TrackWidth", 0)), &c16_thisId);
  c16_thisId.fIdentifier = "h";
  c16_y->h = c16_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c16_u, "h", "h", 0)), &c16_thisId);
  c16_thisId.fIdentifier = "HalfRohACd";
  c16_y->HalfRohACd = c16_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c16_u, "HalfRohACd", "HalfRohACd", 0)), &c16_thisId);
  c16_thisId.fIdentifier = "F_z4_static";
  c16_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c16_u,
    "F_z4_static", "F_z4_static", 0)), &c16_thisId, c16_y->F_z4_static);
  c16_thisId.fIdentifier = "Rw";
  c16_y->Rw = c16_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c16_u, "Rw", "Rw", 0)), &c16_thisId);
  c16_thisId.fIdentifier = "r_long";
  c16_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c16_u,
    "r_long", "r_long", 0)), &c16_thisId, &c16_y->r_long);
  c16_thisId.fIdentifier = "r_lat";
  c16_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c16_u,
    "r_lat", "r_lat", 0)), &c16_thisId, &c16_y->r_lat);
  c16_thisId.fIdentifier = "r_lever";
  c16_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c16_u,
    "r_lever", "r_lever", 0)), &c16_thisId, &c16_y->r_lever);
  c16_thisId.fIdentifier = "r_pivot";
  c16_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c16_u,
    "r_pivot", "r_pivot", 0)), &c16_thisId, &c16_y->r_pivot);
  c16_thisId.fIdentifier = "cw";
  c16_y->cw = c16_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c16_u, "cw", "cw", 0)), &c16_thisId);
  c16_thisId.fIdentifier = "carb_f";
  c16_y->carb_f = c16_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c16_u, "carb_f", "carb_f", 0)), &c16_thisId);
  c16_thisId.fIdentifier = "carb_r";
  c16_y->carb_r = c16_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c16_u, "carb_r", "carb_r", 0)), &c16_thisId);
  c16_thisId.fIdentifier = "dw";
  c16_y->dw = c16_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c16_u, "dw", "dw", 0)), &c16_thisId);
  c16_thisId.fIdentifier = "Jw";
  c16_y->Jw = c16_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c16_u, "Jw", "Jw", 0)), &c16_thisId);
  c16_thisId.fIdentifier = "C0";
  c16_y->C0 = c16_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c16_u, "C0", "C0", 0)), &c16_thisId);
  c16_thisId.fIdentifier = "RelaxLength";
  c16_y->RelaxLength = c16_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c16_u, "RelaxLength", "RelaxLength", 0)), &c16_thisId);
  c16_thisId.fIdentifier = "RRC";
  c16_y->RRC = c16_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c16_u, "RRC", "RRC", 0)), &c16_thisId);
  c16_thisId.fIdentifier = "Pmax";
  c16_y->Pmax = c16_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c16_u, "Pmax", "Pmax", 0)), &c16_thisId);
  c16_thisId.fIdentifier = "PropDistrFrnt";
  c16_y->PropDistrFrnt = c16_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c16_u, "PropDistrFrnt", "PropDistrFrnt", 0)), &c16_thisId);
  c16_thisId.fIdentifier = "BrkDistrFrnt";
  c16_y->BrkDistrFrnt = c16_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c16_u, "BrkDistrFrnt", "BrkDistrFrnt", 0)), &c16_thisId);
  c16_thisId.fIdentifier = "SteRatio";
  c16_y->SteRatio = c16_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c16_u, "SteRatio", "SteRatio", 0)), &c16_thisId);
  sf_mex_destroy(&c16_u);
}

static void c16_h_emlrt_marshallIn(SFc16_ModifiedInstanceStruct *chartInstance,
  const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId, real_T c16_y[4])
{
  real_T c16_dv0[4];
  int32_T c16_i41;
  (void)chartInstance;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), c16_dv0, 1, 0, 0U, 1, 0U, 2, 1,
                4);
  for (c16_i41 = 0; c16_i41 < 4; c16_i41++) {
    c16_y[c16_i41] = c16_dv0[c16_i41];
  }

  sf_mex_destroy(&c16_u);
}

static void c16_i_emlrt_marshallIn(SFc16_ModifiedInstanceStruct *chartInstance,
  const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId,
  c16_struct_ZKAzdrl7umDGJoC14aoVKC *c16_y)
{
  emlrtMsgIdentifier c16_thisId;
  static const char * c16_fieldNames[4] = { "fl", "fr", "rl", "rr" };

  c16_thisId.fParent = c16_parentId;
  sf_mex_check_struct(c16_parentId, c16_u, 4, c16_fieldNames, 0U, NULL);
  c16_thisId.fIdentifier = "fl";
  c16_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c16_u, "fl",
    "fl", 0)), &c16_thisId, c16_y->fl);
  c16_thisId.fIdentifier = "fr";
  c16_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c16_u, "fr",
    "fr", 0)), &c16_thisId, c16_y->fr);
  c16_thisId.fIdentifier = "rl";
  c16_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c16_u, "rl",
    "rl", 0)), &c16_thisId, c16_y->rl);
  c16_thisId.fIdentifier = "rr";
  c16_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c16_u, "rr",
    "rr", 0)), &c16_thisId, c16_y->rr);
  sf_mex_destroy(&c16_u);
}

static void c16_j_emlrt_marshallIn(SFc16_ModifiedInstanceStruct *chartInstance,
  const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId, real_T c16_y[3])
{
  real_T c16_dv1[3];
  int32_T c16_i42;
  (void)chartInstance;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), c16_dv1, 1, 0, 0U, 1, 0U, 2, 3,
                1);
  for (c16_i42 = 0; c16_i42 < 3; c16_i42++) {
    c16_y[c16_i42] = c16_dv1[c16_i42];
  }

  sf_mex_destroy(&c16_u);
}

static c16_struct_r4FNviKwHfdhB8nQjvQv9 c16_k_emlrt_marshallIn
  (SFc16_ModifiedInstanceStruct *chartInstance, const mxArray *c16_u, const
   emlrtMsgIdentifier *c16_parentId)
{
  c16_struct_r4FNviKwHfdhB8nQjvQv9 c16_y;
  emlrtMsgIdentifier c16_thisId;
  static const char * c16_fieldNames[1] = { "v_set" };

  c16_thisId.fParent = c16_parentId;
  sf_mex_check_struct(c16_parentId, c16_u, 1, c16_fieldNames, 0U, NULL);
  c16_thisId.fIdentifier = "v_set";
  c16_y.v_set = c16_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c16_u, "v_set", "v_set", 0)),
    &c16_thisId);
  sf_mex_destroy(&c16_u);
  return c16_y;
}

static c16_struct_Y9F1qlBi9AhssksPwemA4G c16_l_emlrt_marshallIn
  (SFc16_ModifiedInstanceStruct *chartInstance, const mxArray *c16_u, const
   emlrtMsgIdentifier *c16_parentId)
{
  c16_struct_Y9F1qlBi9AhssksPwemA4G c16_y;
  emlrtMsgIdentifier c16_thisId;
  static const char * c16_fieldNames[3] = { "v_x", "F_fz", "F_rz" };

  c16_thisId.fParent = c16_parentId;
  sf_mex_check_struct(c16_parentId, c16_u, 3, c16_fieldNames, 0U, NULL);
  c16_thisId.fIdentifier = "v_x";
  c16_y.v_x = c16_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c16_u, "v_x", "v_x", 0)), &c16_thisId);
  c16_thisId.fIdentifier = "F_fz";
  c16_y.F_fz = c16_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c16_u, "F_fz", "F_fz", 0)), &c16_thisId);
  c16_thisId.fIdentifier = "F_rz";
  c16_y.F_rz = c16_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c16_u, "F_rz", "F_rz", 0)), &c16_thisId);
  sf_mex_destroy(&c16_u);
  return c16_y;
}

static void c16_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData)
{
  const mxArray *c16_b_Par;
  const char_T *c16_identifier;
  emlrtMsgIdentifier c16_thisId;
  c16_struct_iBlsPBO3AGnt69vDoTx5zD c16_y;
  SFc16_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc16_ModifiedInstanceStruct *)chartInstanceVoid;
  c16_b_Par = sf_mex_dup(c16_mxArrayInData);
  c16_identifier = c16_varName;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_b_Par), &c16_thisId,
    &c16_y);
  sf_mex_destroy(&c16_b_Par);
  *(c16_struct_iBlsPBO3AGnt69vDoTx5zD *)c16_outData = c16_y;
  sf_mex_destroy(&c16_mxArrayInData);
}

static const mxArray *c16_c_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  c16_whl_vec4 c16_u;
  const mxArray *c16_y = NULL;
  real_T c16_b_u;
  const mxArray *c16_b_y = NULL;
  real_T c16_c_u;
  const mxArray *c16_c_y = NULL;
  real_T c16_d_u;
  const mxArray *c16_d_y = NULL;
  real_T c16_e_u;
  const mxArray *c16_e_y = NULL;
  SFc16_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc16_ModifiedInstanceStruct *)chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  c16_u = *(c16_whl_vec4 *)c16_inData;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c16_b_u = c16_u.fl;
  c16_b_y = NULL;
  sf_mex_assign(&c16_b_y, sf_mex_create("y", &c16_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c16_y, c16_b_y, "fl", "fl", 0);
  c16_c_u = c16_u.fr;
  c16_c_y = NULL;
  sf_mex_assign(&c16_c_y, sf_mex_create("y", &c16_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c16_y, c16_c_y, "fr", "fr", 0);
  c16_d_u = c16_u.rl;
  c16_d_y = NULL;
  sf_mex_assign(&c16_d_y, sf_mex_create("y", &c16_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c16_y, c16_d_y, "rl", "rl", 0);
  c16_e_u = c16_u.rr;
  c16_e_y = NULL;
  sf_mex_assign(&c16_e_y, sf_mex_create("y", &c16_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c16_y, c16_e_y, "rr", "rr", 0);
  sf_mex_assign(&c16_mxArrayOutData, c16_y, false);
  return c16_mxArrayOutData;
}

static const mxArray *c16_d_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  real_T c16_u;
  const mxArray *c16_y = NULL;
  SFc16_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc16_ModifiedInstanceStruct *)chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  c16_u = *(real_T *)c16_inData;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", &c16_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c16_mxArrayOutData, c16_y, false);
  return c16_mxArrayOutData;
}

static void c16_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData)
{
  const mxArray *c16_nargout;
  const char_T *c16_identifier;
  emlrtMsgIdentifier c16_thisId;
  real_T c16_y;
  SFc16_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc16_ModifiedInstanceStruct *)chartInstanceVoid;
  c16_nargout = sf_mex_dup(c16_mxArrayInData);
  c16_identifier = c16_varName;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_nargout),
    &c16_thisId);
  sf_mex_destroy(&c16_nargout);
  *(real_T *)c16_outData = c16_y;
  sf_mex_destroy(&c16_mxArrayInData);
}

static const mxArray *c16_e_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  int32_T c16_i43;
  real_T c16_b_inData[3];
  int32_T c16_i44;
  real_T c16_u[3];
  const mxArray *c16_y = NULL;
  SFc16_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc16_ModifiedInstanceStruct *)chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  for (c16_i43 = 0; c16_i43 < 3; c16_i43++) {
    c16_b_inData[c16_i43] = (*(real_T (*)[3])c16_inData)[c16_i43];
  }

  for (c16_i44 = 0; c16_i44 < 3; c16_i44++) {
    c16_u[c16_i44] = c16_b_inData[c16_i44];
  }

  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", c16_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c16_mxArrayOutData, c16_y, false);
  return c16_mxArrayOutData;
}

static void c16_m_emlrt_marshallIn(SFc16_ModifiedInstanceStruct *chartInstance,
  const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId, real_T c16_y[3])
{
  real_T c16_dv2[3];
  int32_T c16_i45;
  (void)chartInstance;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), c16_dv2, 1, 0, 0U, 1, 0U, 1, 3);
  for (c16_i45 = 0; c16_i45 < 3; c16_i45++) {
    c16_y[c16_i45] = c16_dv2[c16_i45];
  }

  sf_mex_destroy(&c16_u);
}

static void c16_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData)
{
  const mxArray *c16_F_oorp3;
  const char_T *c16_identifier;
  emlrtMsgIdentifier c16_thisId;
  real_T c16_y[3];
  int32_T c16_i46;
  SFc16_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc16_ModifiedInstanceStruct *)chartInstanceVoid;
  c16_F_oorp3 = sf_mex_dup(c16_mxArrayInData);
  c16_identifier = c16_varName;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_F_oorp3), &c16_thisId,
    c16_y);
  sf_mex_destroy(&c16_F_oorp3);
  for (c16_i46 = 0; c16_i46 < 3; c16_i46++) {
    (*(real_T (*)[3])c16_outData)[c16_i46] = c16_y[c16_i46];
  }

  sf_mex_destroy(&c16_mxArrayInData);
}

static const mxArray *c16_f_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  int32_T c16_i47;
  real_T c16_b_inData[4];
  int32_T c16_i48;
  real_T c16_u[4];
  const mxArray *c16_y = NULL;
  SFc16_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc16_ModifiedInstanceStruct *)chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  for (c16_i47 = 0; c16_i47 < 4; c16_i47++) {
    c16_b_inData[c16_i47] = (*(real_T (*)[4])c16_inData)[c16_i47];
  }

  for (c16_i48 = 0; c16_i48 < 4; c16_i48++) {
    c16_u[c16_i48] = c16_b_inData[c16_i48];
  }

  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", c16_u, 0, 0U, 1U, 0U, 1, 4), false);
  sf_mex_assign(&c16_mxArrayOutData, c16_y, false);
  return c16_mxArrayOutData;
}

static void c16_n_emlrt_marshallIn(SFc16_ModifiedInstanceStruct *chartInstance,
  const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId, real_T c16_y[4])
{
  real_T c16_dv3[4];
  int32_T c16_i49;
  (void)chartInstance;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), c16_dv3, 1, 0, 0U, 1, 0U, 1, 4);
  for (c16_i49 = 0; c16_i49 < 4; c16_i49++) {
    c16_y[c16_i49] = c16_dv3[c16_i49];
  }

  sf_mex_destroy(&c16_u);
}

static void c16_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData)
{
  const mxArray *c16_F_z4_temp;
  const char_T *c16_identifier;
  emlrtMsgIdentifier c16_thisId;
  real_T c16_y[4];
  int32_T c16_i50;
  SFc16_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc16_ModifiedInstanceStruct *)chartInstanceVoid;
  c16_F_z4_temp = sf_mex_dup(c16_mxArrayInData);
  c16_identifier = c16_varName;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_F_z4_temp), &c16_thisId,
    c16_y);
  sf_mex_destroy(&c16_F_z4_temp);
  for (c16_i50 = 0; c16_i50 < 4; c16_i50++) {
    (*(real_T (*)[4])c16_outData)[c16_i50] = c16_y[c16_i50];
  }

  sf_mex_destroy(&c16_mxArrayInData);
}

static const mxArray *c16_g_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  int32_T c16_i51;
  int32_T c16_i52;
  int32_T c16_i53;
  real_T c16_b_inData[12];
  int32_T c16_i54;
  int32_T c16_i55;
  int32_T c16_i56;
  real_T c16_u[12];
  const mxArray *c16_y = NULL;
  SFc16_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc16_ModifiedInstanceStruct *)chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  c16_i51 = 0;
  for (c16_i52 = 0; c16_i52 < 4; c16_i52++) {
    for (c16_i53 = 0; c16_i53 < 3; c16_i53++) {
      c16_b_inData[c16_i53 + c16_i51] = (*(real_T (*)[12])c16_inData)[c16_i53 +
        c16_i51];
    }

    c16_i51 += 3;
  }

  c16_i54 = 0;
  for (c16_i55 = 0; c16_i55 < 4; c16_i55++) {
    for (c16_i56 = 0; c16_i56 < 3; c16_i56++) {
      c16_u[c16_i56 + c16_i54] = c16_b_inData[c16_i56 + c16_i54];
    }

    c16_i54 += 3;
  }

  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", c16_u, 0, 0U, 1U, 0U, 2, 3, 4), false);
  sf_mex_assign(&c16_mxArrayOutData, c16_y, false);
  return c16_mxArrayOutData;
}

static void c16_o_emlrt_marshallIn(SFc16_ModifiedInstanceStruct *chartInstance,
  const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId, real_T c16_y[12])
{
  real_T c16_dv4[12];
  int32_T c16_i57;
  (void)chartInstance;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), c16_dv4, 1, 0, 0U, 1, 0U, 2, 3,
                4);
  for (c16_i57 = 0; c16_i57 < 12; c16_i57++) {
    c16_y[c16_i57] = c16_dv4[c16_i57];
  }

  sf_mex_destroy(&c16_u);
}

static void c16_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData)
{
  const mxArray *c16_T_oorpv;
  const char_T *c16_identifier;
  emlrtMsgIdentifier c16_thisId;
  real_T c16_y[12];
  int32_T c16_i58;
  int32_T c16_i59;
  int32_T c16_i60;
  SFc16_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc16_ModifiedInstanceStruct *)chartInstanceVoid;
  c16_T_oorpv = sf_mex_dup(c16_mxArrayInData);
  c16_identifier = c16_varName;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_T_oorpv), &c16_thisId,
    c16_y);
  sf_mex_destroy(&c16_T_oorpv);
  c16_i58 = 0;
  for (c16_i59 = 0; c16_i59 < 4; c16_i59++) {
    for (c16_i60 = 0; c16_i60 < 3; c16_i60++) {
      (*(real_T (*)[12])c16_outData)[c16_i60 + c16_i58] = c16_y[c16_i60 +
        c16_i58];
    }

    c16_i58 += 3;
  }

  sf_mex_destroy(&c16_mxArrayInData);
}

const mxArray *sf_c16_Modified_get_eml_resolved_functions_info(void)
{
  const mxArray *c16_nameCaptureInfo = NULL;
  c16_nameCaptureInfo = NULL;
  sf_mex_assign(&c16_nameCaptureInfo, sf_mex_createstruct("structure", 2, 20, 1),
                false);
  c16_info_helper(&c16_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c16_nameCaptureInfo);
  return c16_nameCaptureInfo;
}

static void c16_info_helper(const mxArray **c16_info)
{
  const mxArray *c16_rhs0 = NULL;
  const mxArray *c16_lhs0 = NULL;
  const mxArray *c16_rhs1 = NULL;
  const mxArray *c16_lhs1 = NULL;
  const mxArray *c16_rhs2 = NULL;
  const mxArray *c16_lhs2 = NULL;
  const mxArray *c16_rhs3 = NULL;
  const mxArray *c16_lhs3 = NULL;
  const mxArray *c16_rhs4 = NULL;
  const mxArray *c16_lhs4 = NULL;
  const mxArray *c16_rhs5 = NULL;
  const mxArray *c16_lhs5 = NULL;
  const mxArray *c16_rhs6 = NULL;
  const mxArray *c16_lhs6 = NULL;
  const mxArray *c16_rhs7 = NULL;
  const mxArray *c16_lhs7 = NULL;
  const mxArray *c16_rhs8 = NULL;
  const mxArray *c16_lhs8 = NULL;
  const mxArray *c16_rhs9 = NULL;
  const mxArray *c16_lhs9 = NULL;
  const mxArray *c16_rhs10 = NULL;
  const mxArray *c16_lhs10 = NULL;
  const mxArray *c16_rhs11 = NULL;
  const mxArray *c16_lhs11 = NULL;
  const mxArray *c16_rhs12 = NULL;
  const mxArray *c16_lhs12 = NULL;
  const mxArray *c16_rhs13 = NULL;
  const mxArray *c16_lhs13 = NULL;
  const mxArray *c16_rhs14 = NULL;
  const mxArray *c16_lhs14 = NULL;
  const mxArray *c16_rhs15 = NULL;
  const mxArray *c16_lhs15 = NULL;
  const mxArray *c16_rhs16 = NULL;
  const mxArray *c16_lhs16 = NULL;
  const mxArray *c16_rhs17 = NULL;
  const mxArray *c16_lhs17 = NULL;
  const mxArray *c16_rhs18 = NULL;
  const mxArray *c16_lhs18 = NULL;
  const mxArray *c16_rhs19 = NULL;
  const mxArray *c16_lhs19 = NULL;
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("mrdivide"), "name", "name",
                  0);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1410807648U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1370009886U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c16_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1389717774U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c16_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("rdivide"), "name", "name", 2);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1363713880U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c16_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c16_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 4);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c16_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("eml_div"), "name", "name", 5);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1386423952U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c16_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 6);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c16_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(""), "context", "context", 7);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 7);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1383877294U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c16_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 8);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 8);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c16_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 9);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c16_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 10);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 10);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c16_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 11);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c16_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 12);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  12);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1375980690U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c16_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 13);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c16_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("coder.internal.blas.xgemm"),
                  "name", "name", 14);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c16_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 15);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 15);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c16_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!below_threshold"),
                  "context", "context", 16);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 16);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c16_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 17);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 17);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1393330858U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c16_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 18);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 18);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c16_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 19);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "coder.internal.refblas.xgemm"), "name", "name", 19);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c16_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs19), "lhs", "lhs",
                  19);
  sf_mex_destroy(&c16_rhs0);
  sf_mex_destroy(&c16_lhs0);
  sf_mex_destroy(&c16_rhs1);
  sf_mex_destroy(&c16_lhs1);
  sf_mex_destroy(&c16_rhs2);
  sf_mex_destroy(&c16_lhs2);
  sf_mex_destroy(&c16_rhs3);
  sf_mex_destroy(&c16_lhs3);
  sf_mex_destroy(&c16_rhs4);
  sf_mex_destroy(&c16_lhs4);
  sf_mex_destroy(&c16_rhs5);
  sf_mex_destroy(&c16_lhs5);
  sf_mex_destroy(&c16_rhs6);
  sf_mex_destroy(&c16_lhs6);
  sf_mex_destroy(&c16_rhs7);
  sf_mex_destroy(&c16_lhs7);
  sf_mex_destroy(&c16_rhs8);
  sf_mex_destroy(&c16_lhs8);
  sf_mex_destroy(&c16_rhs9);
  sf_mex_destroy(&c16_lhs9);
  sf_mex_destroy(&c16_rhs10);
  sf_mex_destroy(&c16_lhs10);
  sf_mex_destroy(&c16_rhs11);
  sf_mex_destroy(&c16_lhs11);
  sf_mex_destroy(&c16_rhs12);
  sf_mex_destroy(&c16_lhs12);
  sf_mex_destroy(&c16_rhs13);
  sf_mex_destroy(&c16_lhs13);
  sf_mex_destroy(&c16_rhs14);
  sf_mex_destroy(&c16_lhs14);
  sf_mex_destroy(&c16_rhs15);
  sf_mex_destroy(&c16_lhs15);
  sf_mex_destroy(&c16_rhs16);
  sf_mex_destroy(&c16_lhs16);
  sf_mex_destroy(&c16_rhs17);
  sf_mex_destroy(&c16_lhs17);
  sf_mex_destroy(&c16_rhs18);
  sf_mex_destroy(&c16_lhs18);
  sf_mex_destroy(&c16_rhs19);
  sf_mex_destroy(&c16_lhs19);
}

static const mxArray *c16_emlrt_marshallOut(const char * c16_u)
{
  const mxArray *c16_y = NULL;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", c16_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c16_u)), false);
  return c16_y;
}

static const mxArray *c16_b_emlrt_marshallOut(const uint32_T c16_u)
{
  const mxArray *c16_y = NULL;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", &c16_u, 7, 0U, 0U, 0U, 0), false);
  return c16_y;
}

static void c16_eml_scalar_eg(SFc16_ModifiedInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c16_eml_xgemm(SFc16_ModifiedInstanceStruct *chartInstance, real_T
  c16_A[12], real_T c16_B[4], real_T c16_C[3], real_T c16_b_C[3])
{
  int32_T c16_i61;
  int32_T c16_i62;
  real_T c16_b_A[12];
  int32_T c16_i63;
  real_T c16_b_B[4];
  for (c16_i61 = 0; c16_i61 < 3; c16_i61++) {
    c16_b_C[c16_i61] = c16_C[c16_i61];
  }

  for (c16_i62 = 0; c16_i62 < 12; c16_i62++) {
    c16_b_A[c16_i62] = c16_A[c16_i62];
  }

  for (c16_i63 = 0; c16_i63 < 4; c16_i63++) {
    c16_b_B[c16_i63] = c16_B[c16_i63];
  }

  c16_b_eml_xgemm(chartInstance, c16_b_A, c16_b_B, c16_b_C);
}

static const mxArray *c16_h_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  int32_T c16_u;
  const mxArray *c16_y = NULL;
  SFc16_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc16_ModifiedInstanceStruct *)chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  c16_u = *(int32_T *)c16_inData;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", &c16_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c16_mxArrayOutData, c16_y, false);
  return c16_mxArrayOutData;
}

static int32_T c16_p_emlrt_marshallIn(SFc16_ModifiedInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId)
{
  int32_T c16_y;
  int32_T c16_i64;
  (void)chartInstance;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), &c16_i64, 1, 6, 0U, 0, 0U, 0);
  c16_y = c16_i64;
  sf_mex_destroy(&c16_u);
  return c16_y;
}

static void c16_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData)
{
  const mxArray *c16_b_sfEvent;
  const char_T *c16_identifier;
  emlrtMsgIdentifier c16_thisId;
  int32_T c16_y;
  SFc16_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc16_ModifiedInstanceStruct *)chartInstanceVoid;
  c16_b_sfEvent = sf_mex_dup(c16_mxArrayInData);
  c16_identifier = c16_varName;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_p_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_b_sfEvent),
    &c16_thisId);
  sf_mex_destroy(&c16_b_sfEvent);
  *(int32_T *)c16_outData = c16_y;
  sf_mex_destroy(&c16_mxArrayInData);
}

static const mxArray *c16_F_xv4_bus_io(void *chartInstanceVoid, void *c16_pData)
{
  const mxArray *c16_mxVal = NULL;
  c16_whl_vec4 c16_tmp;
  SFc16_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc16_ModifiedInstanceStruct *)chartInstanceVoid;
  c16_mxVal = NULL;
  c16_tmp.fl = *(real_T *)&((char_T *)(c16_whl_vec4 *)c16_pData)[0];
  c16_tmp.fr = *(real_T *)&((char_T *)(c16_whl_vec4 *)c16_pData)[8];
  c16_tmp.rl = *(real_T *)&((char_T *)(c16_whl_vec4 *)c16_pData)[16];
  c16_tmp.rr = *(real_T *)&((char_T *)(c16_whl_vec4 *)c16_pData)[24];
  sf_mex_assign(&c16_mxVal, c16_c_sf_marshallOut(chartInstance, &c16_tmp), false);
  return c16_mxVal;
}

static const mxArray *c16_derv_oorp3_bus_io(void *chartInstanceVoid, void
  *c16_pData)
{
  const mxArray *c16_mxVal = NULL;
  c16_oorp_vec3 c16_tmp;
  SFc16_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc16_ModifiedInstanceStruct *)chartInstanceVoid;
  c16_mxVal = NULL;
  c16_tmp.z = *(real_T *)&((char_T *)(c16_oorp_vec3 *)c16_pData)[0];
  c16_tmp.rotx = *(real_T *)&((char_T *)(c16_oorp_vec3 *)c16_pData)[8];
  c16_tmp.roty = *(real_T *)&((char_T *)(c16_oorp_vec3 *)c16_pData)[16];
  sf_mex_assign(&c16_mxVal, c16_sf_marshallOut(chartInstance, &c16_tmp), false);
  return c16_mxVal;
}

static uint8_T c16_q_emlrt_marshallIn(SFc16_ModifiedInstanceStruct
  *chartInstance, const mxArray *c16_b_is_active_c16_Modified, const char_T
  *c16_identifier)
{
  uint8_T c16_y;
  emlrtMsgIdentifier c16_thisId;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_r_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c16_b_is_active_c16_Modified), &c16_thisId);
  sf_mex_destroy(&c16_b_is_active_c16_Modified);
  return c16_y;
}

static uint8_T c16_r_emlrt_marshallIn(SFc16_ModifiedInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId)
{
  uint8_T c16_y;
  uint8_T c16_u0;
  (void)chartInstance;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), &c16_u0, 1, 3, 0U, 0, 0U, 0);
  c16_y = c16_u0;
  sf_mex_destroy(&c16_u);
  return c16_y;
}

static void c16_b_eml_xgemm(SFc16_ModifiedInstanceStruct *chartInstance, real_T
  c16_A[12], real_T c16_B[4], real_T c16_C[3])
{
  int32_T c16_i65;
  int32_T c16_i66;
  int32_T c16_i67;
  (void)chartInstance;
  for (c16_i65 = 0; c16_i65 < 3; c16_i65++) {
    c16_C[c16_i65] = 0.0;
    c16_i66 = 0;
    for (c16_i67 = 0; c16_i67 < 4; c16_i67++) {
      c16_C[c16_i65] += c16_A[c16_i66 + c16_i65] * c16_B[c16_i67];
      c16_i66 += 3;
    }
  }
}

static void init_dsm_address_info(SFc16_ModifiedInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc16_ModifiedInstanceStruct *chartInstance)
{
  chartInstance->c16_F_xv4 = (c16_whl_vec4 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c16_derv_oorp3 = (c16_oorp_vec3 *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c16_F_yv4 = (c16_whl_vec4 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c16_F_z4 = (c16_whl_vec4 *)ssGetInputPortSignal_wrapper
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

void sf_c16_Modified_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1820227298U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(25443725U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2985632773U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(806101766U);
}

mxArray* sf_c16_Modified_get_post_codegen_info(void);
mxArray *sf_c16_Modified_get_autoinheritance_info(void)
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
    mxArray* mxPostCodegenInfo = sf_c16_Modified_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c16_Modified_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c16_Modified_jit_fallback_info(void)
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

mxArray *sf_c16_Modified_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c16_Modified_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c16_Modified(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[10],T\"derv_oorp3\",},{M[8],M[0],T\"is_active_c16_Modified\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c16_Modified_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc16_ModifiedInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc16_ModifiedInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ModifiedMachineNumber_,
           16,
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
        init_script_number_translation(_ModifiedMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_ModifiedMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _ModifiedMachineNumber_,
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
          (MexFcnForType)c16_F_xv4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_derv_oorp3_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_F_xv4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_F_xv4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_b_sf_marshallOut,(MexInFcnForType)
          c16_b_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c16_F_xv4);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c16_derv_oorp3);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c16_F_yv4);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c16_F_z4);
        _SFD_SET_DATA_VALUE_PTR(4U, &chartInstance->c16_Par);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _ModifiedMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "nsuilLiT8rixZOJEK30JvD";
}

static void sf_opaque_initialize_c16_Modified(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc16_ModifiedInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c16_Modified((SFc16_ModifiedInstanceStruct*)
    chartInstanceVar);
  initialize_c16_Modified((SFc16_ModifiedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c16_Modified(void *chartInstanceVar)
{
  enable_c16_Modified((SFc16_ModifiedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c16_Modified(void *chartInstanceVar)
{
  disable_c16_Modified((SFc16_ModifiedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c16_Modified(void *chartInstanceVar)
{
  sf_gateway_c16_Modified((SFc16_ModifiedInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c16_Modified(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c16_Modified((SFc16_ModifiedInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c16_Modified(SimStruct* S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c16_Modified((SFc16_ModifiedInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c16_Modified(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc16_ModifiedInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Modified_optimization_info();
    }

    finalize_c16_Modified((SFc16_ModifiedInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc16_Modified((SFc16_ModifiedInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c16_Modified(SimStruct *S)
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
    initialize_params_c16_Modified((SFc16_ModifiedInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c16_Modified(SimStruct *S)
{
  /* Actual parameters from chart:
     Par
   */
  const char_T *rtParamNames[] = { "Par" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0],
    sf_get_param_data_type_id(S,0));
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Modified_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      16);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,16,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,16,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,16);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,16,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,16,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,16);
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

static void mdlRTW_c16_Modified(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c16_Modified(SimStruct *S)
{
  SFc16_ModifiedInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc16_ModifiedInstanceStruct *)utMalloc(sizeof
    (SFc16_ModifiedInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc16_ModifiedInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c16_Modified;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c16_Modified;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c16_Modified;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c16_Modified;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c16_Modified;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c16_Modified;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c16_Modified;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c16_Modified;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c16_Modified;
  chartInstance->chartInfo.mdlStart = mdlStart_c16_Modified;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c16_Modified;
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

void c16_Modified_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c16_Modified(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c16_Modified(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c16_Modified(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c16_Modified_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
