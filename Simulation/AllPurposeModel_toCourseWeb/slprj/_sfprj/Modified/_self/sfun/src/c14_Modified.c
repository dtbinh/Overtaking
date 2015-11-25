/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Modified_sfun.h"
#include "c14_Modified.h"
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
static const char * c14_debug_family_names[13] = { "w1", "w2", "w3", "w4", "lf",
  "lr", "v_oorp3_temp", "v_oorp4", "nargin", "nargout", "v_oorp3", "Par", "v_z4"
};

/* Function Declarations */
static void initialize_c14_Modified(SFc14_ModifiedInstanceStruct *chartInstance);
static void initialize_params_c14_Modified(SFc14_ModifiedInstanceStruct
  *chartInstance);
static void enable_c14_Modified(SFc14_ModifiedInstanceStruct *chartInstance);
static void disable_c14_Modified(SFc14_ModifiedInstanceStruct *chartInstance);
static void c14_update_debugger_state_c14_Modified(SFc14_ModifiedInstanceStruct *
  chartInstance);
static const mxArray *get_sim_state_c14_Modified(SFc14_ModifiedInstanceStruct
  *chartInstance);
static void set_sim_state_c14_Modified(SFc14_ModifiedInstanceStruct
  *chartInstance, const mxArray *c14_st);
static void finalize_c14_Modified(SFc14_ModifiedInstanceStruct *chartInstance);
static void sf_gateway_c14_Modified(SFc14_ModifiedInstanceStruct *chartInstance);
static void mdl_start_c14_Modified(SFc14_ModifiedInstanceStruct *chartInstance);
static void initSimStructsc14_Modified(SFc14_ModifiedInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c14_machineNumber, uint32_T
  c14_chartNumber, uint32_T c14_instanceNumber);
static const mxArray *c14_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static c14_whl_vec4 c14_emlrt_marshallIn(SFc14_ModifiedInstanceStruct
  *chartInstance, const mxArray *c14_b_v_z4, const char_T *c14_identifier);
static c14_whl_vec4 c14_b_emlrt_marshallIn(SFc14_ModifiedInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId);
static real_T c14_c_emlrt_marshallIn(SFc14_ModifiedInstanceStruct *chartInstance,
  const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId);
static void c14_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static const mxArray *c14_b_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static void c14_d_emlrt_marshallIn(SFc14_ModifiedInstanceStruct *chartInstance,
  const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId,
  c14_struct_iBlsPBO3AGnt69vDoTx5zD *c14_y);
static void c14_e_emlrt_marshallIn(SFc14_ModifiedInstanceStruct *chartInstance,
  const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId,
  c14_struct_Nst2vGTExxHsg85EUOj9EH *c14_y);
static c14_struct_HhckT6rntEraqECYVIDvCC c14_f_emlrt_marshallIn
  (SFc14_ModifiedInstanceStruct *chartInstance, const mxArray *c14_u, const
   emlrtMsgIdentifier *c14_parentId);
static void c14_g_emlrt_marshallIn(SFc14_ModifiedInstanceStruct *chartInstance,
  const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId,
  c14_struct_ZCmOWPuqBDw16FSOVVD00 *c14_y);
static void c14_h_emlrt_marshallIn(SFc14_ModifiedInstanceStruct *chartInstance,
  const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId, real_T c14_y[4]);
static void c14_i_emlrt_marshallIn(SFc14_ModifiedInstanceStruct *chartInstance,
  const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId,
  c14_struct_ZKAzdrl7umDGJoC14aoVKC *c14_y);
static void c14_j_emlrt_marshallIn(SFc14_ModifiedInstanceStruct *chartInstance,
  const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId, real_T c14_y[3]);
static c14_struct_r4FNviKwHfdhB8nQjvQv9 c14_k_emlrt_marshallIn
  (SFc14_ModifiedInstanceStruct *chartInstance, const mxArray *c14_u, const
   emlrtMsgIdentifier *c14_parentId);
static c14_struct_Y9F1qlBi9AhssksPwemA4G c14_l_emlrt_marshallIn
  (SFc14_ModifiedInstanceStruct *chartInstance, const mxArray *c14_u, const
   emlrtMsgIdentifier *c14_parentId);
static void c14_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static const mxArray *c14_c_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static const mxArray *c14_d_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static void c14_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static const mxArray *c14_e_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static void c14_m_emlrt_marshallIn(SFc14_ModifiedInstanceStruct *chartInstance,
  const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId, real_T c14_y[4]);
static void c14_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static const mxArray *c14_f_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static void c14_n_emlrt_marshallIn(SFc14_ModifiedInstanceStruct *chartInstance,
  const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId, real_T c14_y[3]);
static void c14_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static void c14_info_helper(const mxArray **c14_info);
static const mxArray *c14_emlrt_marshallOut(const char * c14_u);
static const mxArray *c14_b_emlrt_marshallOut(const uint32_T c14_u);
static void c14_eml_scalar_eg(SFc14_ModifiedInstanceStruct *chartInstance);
static void c14_eml_xgemm(SFc14_ModifiedInstanceStruct *chartInstance, real_T
  c14_A[12], real_T c14_B[3], real_T c14_C[4], real_T c14_b_C[4]);
static const mxArray *c14_g_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static int32_T c14_o_emlrt_marshallIn(SFc14_ModifiedInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId);
static void c14_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static const mxArray *c14_v_oorp3_bus_io(void *chartInstanceVoid, void
  *c14_pData);
static const mxArray *c14_v_z4_bus_io(void *chartInstanceVoid, void *c14_pData);
static uint8_T c14_p_emlrt_marshallIn(SFc14_ModifiedInstanceStruct
  *chartInstance, const mxArray *c14_b_is_active_c14_Modified, const char_T
  *c14_identifier);
static uint8_T c14_q_emlrt_marshallIn(SFc14_ModifiedInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId);
static void c14_b_eml_xgemm(SFc14_ModifiedInstanceStruct *chartInstance, real_T
  c14_A[12], real_T c14_B[3], real_T c14_C[4]);
static void init_dsm_address_info(SFc14_ModifiedInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc14_ModifiedInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c14_Modified(SFc14_ModifiedInstanceStruct *chartInstance)
{
  chartInstance->c14_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c14_is_active_c14_Modified = 0U;
}

static void initialize_params_c14_Modified(SFc14_ModifiedInstanceStruct
  *chartInstance)
{
  const mxArray *c14_m0 = NULL;
  const mxArray *c14_mxField;
  const mxArray *c14_m1 = NULL;
  const mxArray *c14_b_mxField;
  c14_struct_iBlsPBO3AGnt69vDoTx5zD c14_r0;
  const mxArray *c14_m2 = NULL;
  const mxArray *c14_c_mxField;
  const mxArray *c14_m3 = NULL;
  const mxArray *c14_d_mxField;
  const mxArray *c14_m4 = NULL;
  const mxArray *c14_e_mxField;
  const mxArray *c14_m5 = NULL;
  const mxArray *c14_f_mxField;
  const mxArray *c14_m6 = NULL;
  const mxArray *c14_g_mxField;
  const mxArray *c14_m7 = NULL;
  const mxArray *c14_h_mxField;
  const mxArray *c14_m8 = NULL;
  const mxArray *c14_i_mxField;
  const mxArray *c14_m9 = NULL;
  const mxArray *c14_j_mxField;
  const mxArray *c14_m10 = NULL;
  const mxArray *c14_k_mxField;
  const mxArray *c14_m11 = NULL;
  const mxArray *c14_l_mxField;
  const mxArray *c14_m12 = NULL;
  const mxArray *c14_m_mxField;
  const mxArray *c14_m13 = NULL;
  const mxArray *c14_n_mxField;
  c14_m0 = sf_mex_get_sfun_param(chartInstance->S, 0, 1);
  c14_mxField = sf_mex_getfield(c14_m0, "Env", "Par", 0);
  c14_m1 = sf_mex_dup(c14_mxField);
  c14_b_mxField = sf_mex_getfield(c14_m1, "g", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_b_mxField), &c14_r0.Env.g, 1, 0, 0U,
                      0, 0U, 0);
  c14_b_mxField = sf_mex_getfield(c14_m1, "left1", "Par", 0);
  c14_m2 = sf_mex_dup(c14_b_mxField);
  c14_c_mxField = sf_mex_getfield(c14_m2, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_c_mxField), &c14_r0.Env.left1.x, 1,
                      0, 0U, 0, 0U, 0);
  c14_c_mxField = sf_mex_getfield(c14_m2, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_c_mxField), &c14_r0.Env.left1.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c14_m2);
  c14_b_mxField = sf_mex_getfield(c14_m1, "right1", "Par", 0);
  c14_m3 = sf_mex_dup(c14_b_mxField);
  c14_d_mxField = sf_mex_getfield(c14_m3, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_d_mxField), &c14_r0.Env.right1.x, 1,
                      0, 0U, 0, 0U, 0);
  c14_d_mxField = sf_mex_getfield(c14_m3, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_d_mxField), &c14_r0.Env.right1.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c14_m3);
  c14_b_mxField = sf_mex_getfield(c14_m1, "right2", "Par", 0);
  c14_m4 = sf_mex_dup(c14_b_mxField);
  c14_e_mxField = sf_mex_getfield(c14_m4, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_e_mxField), &c14_r0.Env.right2.x, 1,
                      0, 0U, 0, 0U, 0);
  c14_e_mxField = sf_mex_getfield(c14_m4, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_e_mxField), &c14_r0.Env.right2.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c14_m4);
  c14_b_mxField = sf_mex_getfield(c14_m1, "left2", "Par", 0);
  c14_m5 = sf_mex_dup(c14_b_mxField);
  c14_f_mxField = sf_mex_getfield(c14_m5, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_f_mxField), &c14_r0.Env.left2.x, 1,
                      0, 0U, 0, 0U, 0);
  c14_f_mxField = sf_mex_getfield(c14_m5, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_f_mxField), &c14_r0.Env.left2.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c14_m5);
  c14_b_mxField = sf_mex_getfield(c14_m1, "right3", "Par", 0);
  c14_m6 = sf_mex_dup(c14_b_mxField);
  c14_g_mxField = sf_mex_getfield(c14_m6, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_g_mxField), &c14_r0.Env.right3.x, 1,
                      0, 0U, 0, 0U, 0);
  c14_g_mxField = sf_mex_getfield(c14_m6, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_g_mxField), &c14_r0.Env.right3.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c14_m6);
  c14_b_mxField = sf_mex_getfield(c14_m1, "mu", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_b_mxField), &c14_r0.Env.mu, 1, 0, 0U,
                      0, 0U, 0);
  sf_mex_destroy(&c14_m1);
  c14_mxField = sf_mex_getfield(c14_m0, "Veh", "Par", 0);
  c14_m7 = sf_mex_dup(c14_mxField);
  c14_h_mxField = sf_mex_getfield(c14_m7, "m", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_h_mxField), &c14_r0.Veh.m, 1, 0, 0U,
                      0, 0U, 0);
  c14_h_mxField = sf_mex_getfield(c14_m7, "Jz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_h_mxField), &c14_r0.Veh.Jz, 1, 0, 0U,
                      0, 0U, 0);
  c14_h_mxField = sf_mex_getfield(c14_m7, "m_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_h_mxField), &c14_r0.Veh.m_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c14_h_mxField = sf_mex_getfield(c14_m7, "Jx_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_h_mxField), &c14_r0.Veh.Jx_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c14_h_mxField = sf_mex_getfield(c14_m7, "Jy_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_h_mxField), &c14_r0.Veh.Jy_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c14_h_mxField = sf_mex_getfield(c14_m7, "lf", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_h_mxField), &c14_r0.Veh.lf, 1, 0, 0U,
                      0, 0U, 0);
  c14_h_mxField = sf_mex_getfield(c14_m7, "lr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_h_mxField), &c14_r0.Veh.lr, 1, 0, 0U,
                      0, 0U, 0);
  c14_h_mxField = sf_mex_getfield(c14_m7, "L", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_h_mxField), &c14_r0.Veh.L, 1, 0, 0U,
                      0, 0U, 0);
  c14_h_mxField = sf_mex_getfield(c14_m7, "TrackWidth", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_h_mxField), &c14_r0.Veh.TrackWidth,
                      1, 0, 0U, 0, 0U, 0);
  c14_h_mxField = sf_mex_getfield(c14_m7, "h", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_h_mxField), &c14_r0.Veh.h, 1, 0, 0U,
                      0, 0U, 0);
  c14_h_mxField = sf_mex_getfield(c14_m7, "HalfRohACd", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_h_mxField), &c14_r0.Veh.HalfRohACd,
                      1, 0, 0U, 0, 0U, 0);
  c14_h_mxField = sf_mex_getfield(c14_m7, "F_z4_static", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_h_mxField), c14_r0.Veh.F_z4_static,
                      1, 0, 0U, 1, 0U, 2, 1, 4);
  c14_h_mxField = sf_mex_getfield(c14_m7, "Rw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_h_mxField), &c14_r0.Veh.Rw, 1, 0, 0U,
                      0, 0U, 0);
  c14_h_mxField = sf_mex_getfield(c14_m7, "r_long", "Par", 0);
  c14_m8 = sf_mex_dup(c14_h_mxField);
  c14_i_mxField = sf_mex_getfield(c14_m8, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_i_mxField), c14_r0.Veh.r_long.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c14_i_mxField = sf_mex_getfield(c14_m8, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_i_mxField), c14_r0.Veh.r_long.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c14_i_mxField = sf_mex_getfield(c14_m8, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_i_mxField), c14_r0.Veh.r_long.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c14_i_mxField = sf_mex_getfield(c14_m8, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_i_mxField), c14_r0.Veh.r_long.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c14_m8);
  c14_h_mxField = sf_mex_getfield(c14_m7, "r_lat", "Par", 0);
  c14_m9 = sf_mex_dup(c14_h_mxField);
  c14_j_mxField = sf_mex_getfield(c14_m9, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_j_mxField), c14_r0.Veh.r_lat.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c14_j_mxField = sf_mex_getfield(c14_m9, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_j_mxField), c14_r0.Veh.r_lat.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c14_j_mxField = sf_mex_getfield(c14_m9, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_j_mxField), c14_r0.Veh.r_lat.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c14_j_mxField = sf_mex_getfield(c14_m9, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_j_mxField), c14_r0.Veh.r_lat.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c14_m9);
  c14_h_mxField = sf_mex_getfield(c14_m7, "r_lever", "Par", 0);
  c14_m10 = sf_mex_dup(c14_h_mxField);
  c14_k_mxField = sf_mex_getfield(c14_m10, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_k_mxField), c14_r0.Veh.r_lever.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c14_k_mxField = sf_mex_getfield(c14_m10, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_k_mxField), c14_r0.Veh.r_lever.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c14_k_mxField = sf_mex_getfield(c14_m10, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_k_mxField), c14_r0.Veh.r_lever.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c14_k_mxField = sf_mex_getfield(c14_m10, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_k_mxField), c14_r0.Veh.r_lever.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c14_m10);
  c14_h_mxField = sf_mex_getfield(c14_m7, "r_pivot", "Par", 0);
  c14_m11 = sf_mex_dup(c14_h_mxField);
  c14_l_mxField = sf_mex_getfield(c14_m11, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_l_mxField), c14_r0.Veh.r_pivot.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c14_l_mxField = sf_mex_getfield(c14_m11, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_l_mxField), c14_r0.Veh.r_pivot.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c14_l_mxField = sf_mex_getfield(c14_m11, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_l_mxField), c14_r0.Veh.r_pivot.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c14_l_mxField = sf_mex_getfield(c14_m11, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_l_mxField), c14_r0.Veh.r_pivot.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c14_m11);
  c14_h_mxField = sf_mex_getfield(c14_m7, "cw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_h_mxField), &c14_r0.Veh.cw, 1, 0, 0U,
                      0, 0U, 0);
  c14_h_mxField = sf_mex_getfield(c14_m7, "carb_f", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_h_mxField), &c14_r0.Veh.carb_f, 1, 0,
                      0U, 0, 0U, 0);
  c14_h_mxField = sf_mex_getfield(c14_m7, "carb_r", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_h_mxField), &c14_r0.Veh.carb_r, 1, 0,
                      0U, 0, 0U, 0);
  c14_h_mxField = sf_mex_getfield(c14_m7, "dw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_h_mxField), &c14_r0.Veh.dw, 1, 0, 0U,
                      0, 0U, 0);
  c14_h_mxField = sf_mex_getfield(c14_m7, "Jw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_h_mxField), &c14_r0.Veh.Jw, 1, 0, 0U,
                      0, 0U, 0);
  c14_h_mxField = sf_mex_getfield(c14_m7, "C0", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_h_mxField), &c14_r0.Veh.C0, 1, 0, 0U,
                      0, 0U, 0);
  c14_h_mxField = sf_mex_getfield(c14_m7, "RelaxLength", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_h_mxField), &c14_r0.Veh.RelaxLength,
                      1, 0, 0U, 0, 0U, 0);
  c14_h_mxField = sf_mex_getfield(c14_m7, "RRC", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_h_mxField), &c14_r0.Veh.RRC, 1, 0,
                      0U, 0, 0U, 0);
  c14_h_mxField = sf_mex_getfield(c14_m7, "Pmax", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_h_mxField), &c14_r0.Veh.Pmax, 1, 0,
                      0U, 0, 0U, 0);
  c14_h_mxField = sf_mex_getfield(c14_m7, "PropDistrFrnt", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_h_mxField),
                      &c14_r0.Veh.PropDistrFrnt, 1, 0, 0U, 0, 0U, 0);
  c14_h_mxField = sf_mex_getfield(c14_m7, "BrkDistrFrnt", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_h_mxField), &c14_r0.Veh.BrkDistrFrnt,
                      1, 0, 0U, 0, 0U, 0);
  c14_h_mxField = sf_mex_getfield(c14_m7, "SteRatio", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_h_mxField), &c14_r0.Veh.SteRatio, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c14_m7);
  c14_mxField = sf_mex_getfield(c14_m0, "Drvr", "Par", 0);
  c14_m12 = sf_mex_dup(c14_mxField);
  c14_m_mxField = sf_mex_getfield(c14_m12, "v_set", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_m_mxField), &c14_r0.Drvr.v_set, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c14_m12);
  c14_mxField = sf_mex_getfield(c14_m0, "Init", "Par", 0);
  c14_m13 = sf_mex_dup(c14_mxField);
  c14_n_mxField = sf_mex_getfield(c14_m13, "v_x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_n_mxField), &c14_r0.Init.v_x, 1, 0,
                      0U, 0, 0U, 0);
  c14_n_mxField = sf_mex_getfield(c14_m13, "F_fz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_n_mxField), &c14_r0.Init.F_fz, 1, 0,
                      0U, 0, 0U, 0);
  c14_n_mxField = sf_mex_getfield(c14_m13, "F_rz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c14_n_mxField), &c14_r0.Init.F_rz, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c14_m13);
  sf_mex_destroy(&c14_m0);
  chartInstance->c14_Par = c14_r0;
}

static void enable_c14_Modified(SFc14_ModifiedInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c14_Modified(SFc14_ModifiedInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c14_update_debugger_state_c14_Modified(SFc14_ModifiedInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c14_Modified(SFc14_ModifiedInstanceStruct
  *chartInstance)
{
  const mxArray *c14_st;
  const mxArray *c14_y = NULL;
  const mxArray *c14_b_y = NULL;
  real_T c14_u;
  const mxArray *c14_c_y = NULL;
  real_T c14_b_u;
  const mxArray *c14_d_y = NULL;
  real_T c14_c_u;
  const mxArray *c14_e_y = NULL;
  real_T c14_d_u;
  const mxArray *c14_f_y = NULL;
  uint8_T c14_hoistedGlobal;
  uint8_T c14_e_u;
  const mxArray *c14_g_y = NULL;
  c14_st = NULL;
  c14_st = NULL;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_createcellmatrix(2, 1), false);
  c14_b_y = NULL;
  sf_mex_assign(&c14_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c14_u = *(real_T *)&((char_T *)chartInstance->c14_v_z4)[0];
  c14_c_y = NULL;
  sf_mex_assign(&c14_c_y, sf_mex_create("y", &c14_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c14_b_y, c14_c_y, "fl", "fl", 0);
  c14_b_u = *(real_T *)&((char_T *)chartInstance->c14_v_z4)[8];
  c14_d_y = NULL;
  sf_mex_assign(&c14_d_y, sf_mex_create("y", &c14_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c14_b_y, c14_d_y, "fr", "fr", 0);
  c14_c_u = *(real_T *)&((char_T *)chartInstance->c14_v_z4)[16];
  c14_e_y = NULL;
  sf_mex_assign(&c14_e_y, sf_mex_create("y", &c14_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c14_b_y, c14_e_y, "rl", "rl", 0);
  c14_d_u = *(real_T *)&((char_T *)chartInstance->c14_v_z4)[24];
  c14_f_y = NULL;
  sf_mex_assign(&c14_f_y, sf_mex_create("y", &c14_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c14_b_y, c14_f_y, "rr", "rr", 0);
  sf_mex_setcell(c14_y, 0, c14_b_y);
  c14_hoistedGlobal = chartInstance->c14_is_active_c14_Modified;
  c14_e_u = c14_hoistedGlobal;
  c14_g_y = NULL;
  sf_mex_assign(&c14_g_y, sf_mex_create("y", &c14_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c14_y, 1, c14_g_y);
  sf_mex_assign(&c14_st, c14_y, false);
  return c14_st;
}

static void set_sim_state_c14_Modified(SFc14_ModifiedInstanceStruct
  *chartInstance, const mxArray *c14_st)
{
  const mxArray *c14_u;
  c14_whl_vec4 c14_r1;
  chartInstance->c14_doneDoubleBufferReInit = true;
  c14_u = sf_mex_dup(c14_st);
  c14_r1 = c14_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c14_u,
    0)), "v_z4");
  *(real_T *)&((char_T *)chartInstance->c14_v_z4)[0] = c14_r1.fl;
  *(real_T *)&((char_T *)chartInstance->c14_v_z4)[8] = c14_r1.fr;
  *(real_T *)&((char_T *)chartInstance->c14_v_z4)[16] = c14_r1.rl;
  *(real_T *)&((char_T *)chartInstance->c14_v_z4)[24] = c14_r1.rr;
  chartInstance->c14_is_active_c14_Modified = c14_p_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c14_u, 1)),
     "is_active_c14_Modified");
  sf_mex_destroy(&c14_u);
  c14_update_debugger_state_c14_Modified(chartInstance);
  sf_mex_destroy(&c14_st);
}

static void finalize_c14_Modified(SFc14_ModifiedInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c14_Modified(SFc14_ModifiedInstanceStruct *chartInstance)
{
  c14_oorp_vec3 c14_b_v_oorp3;
  c14_struct_iBlsPBO3AGnt69vDoTx5zD c14_b_Par;
  uint32_T c14_debug_family_var_map[13];
  real_T c14_w1;
  real_T c14_w2;
  real_T c14_w3;
  real_T c14_w4;
  real_T c14_lf;
  real_T c14_lr;
  real_T c14_v_oorp3_temp[3];
  real_T c14_v_oorp4[4];
  real_T c14_nargin = 2.0;
  real_T c14_nargout = 1.0;
  c14_whl_vec4 c14_b_v_z4;
  real_T c14_A;
  real_T c14_x;
  real_T c14_b_x;
  real_T c14_c_x;
  real_T c14_b_w1[4];
  real_T c14_b_lf[4];
  int32_T c14_i0;
  real_T c14_a[12];
  int32_T c14_i1;
  int32_T c14_i2;
  int32_T c14_i3;
  real_T c14_b[3];
  int32_T c14_i4;
  int32_T c14_i5;
  int32_T c14_i6;
  real_T c14_b_a[12];
  int32_T c14_i7;
  real_T c14_b_b[3];
  int32_T c14_i8;
  c14_whl_vec4 c14_r2;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 13U, chartInstance->c14_sfEvent);
  chartInstance->c14_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 13U, chartInstance->c14_sfEvent);
  c14_b_v_oorp3.z = *(real_T *)&((char_T *)chartInstance->c14_v_oorp3)[0];
  c14_b_v_oorp3.rotx = *(real_T *)&((char_T *)chartInstance->c14_v_oorp3)[8];
  c14_b_v_oorp3.roty = *(real_T *)&((char_T *)chartInstance->c14_v_oorp3)[16];
  c14_b_Par = chartInstance->c14_Par;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 13U, 13U, c14_debug_family_names,
    c14_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_w1, 0U, c14_d_sf_marshallOut,
    c14_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_w2, 1U, c14_d_sf_marshallOut,
    c14_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_w3, 2U, c14_d_sf_marshallOut,
    c14_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_w4, 3U, c14_d_sf_marshallOut,
    c14_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_lf, 4U, c14_d_sf_marshallOut,
    c14_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_lr, 5U, c14_d_sf_marshallOut,
    c14_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c14_v_oorp3_temp, 6U,
    c14_f_sf_marshallOut, c14_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c14_v_oorp4, 7U, c14_e_sf_marshallOut,
    c14_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_nargin, 8U, c14_d_sf_marshallOut,
    c14_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_nargout, 9U, c14_d_sf_marshallOut,
    c14_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c14_b_v_oorp3, 10U, c14_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_b_Par, 11U, c14_b_sf_marshallOut,
    c14_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_b_v_z4, 12U, c14_sf_marshallOut,
    c14_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 5);
  c14_A = c14_b_Par.Veh.TrackWidth;
  c14_x = c14_A;
  c14_b_x = c14_x;
  c14_c_x = c14_b_x;
  c14_w1 = c14_c_x / 2.0;
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 6);
  c14_w2 = -c14_w1;
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 7);
  c14_w3 = c14_w1;
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 8);
  c14_w4 = c14_w2;
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 10);
  c14_lf = c14_b_Par.Veh.lf;
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 11);
  c14_lr = c14_b_Par.Veh.lr;
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 13);
  c14_v_oorp3_temp[0] = c14_b_v_oorp3.z;
  c14_v_oorp3_temp[1] = c14_b_v_oorp3.rotx;
  c14_v_oorp3_temp[2] = c14_b_v_oorp3.roty;
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 15);
  c14_b_w1[0] = c14_w1;
  c14_b_w1[1] = c14_w2;
  c14_b_w1[2] = c14_w3;
  c14_b_w1[3] = c14_w4;
  c14_b_lf[0] = -c14_lf;
  c14_b_lf[1] = -c14_lf;
  c14_b_lf[2] = -c14_lr;
  c14_b_lf[3] = -c14_lr;
  for (c14_i0 = 0; c14_i0 < 4; c14_i0++) {
    c14_a[c14_i0] = 1.0;
  }

  for (c14_i1 = 0; c14_i1 < 4; c14_i1++) {
    c14_a[c14_i1 + 4] = c14_b_w1[c14_i1];
  }

  for (c14_i2 = 0; c14_i2 < 4; c14_i2++) {
    c14_a[c14_i2 + 8] = c14_b_lf[c14_i2];
  }

  for (c14_i3 = 0; c14_i3 < 3; c14_i3++) {
    c14_b[c14_i3] = c14_v_oorp3_temp[c14_i3];
  }

  c14_eml_scalar_eg(chartInstance);
  c14_eml_scalar_eg(chartInstance);
  for (c14_i4 = 0; c14_i4 < 4; c14_i4++) {
    c14_v_oorp4[c14_i4] = 0.0;
  }

  for (c14_i5 = 0; c14_i5 < 4; c14_i5++) {
    c14_b_w1[c14_i5] = 0.0;
  }

  for (c14_i6 = 0; c14_i6 < 12; c14_i6++) {
    c14_b_a[c14_i6] = c14_a[c14_i6];
  }

  for (c14_i7 = 0; c14_i7 < 3; c14_i7++) {
    c14_b_b[c14_i7] = c14_b[c14_i7];
  }

  c14_b_eml_xgemm(chartInstance, c14_b_a, c14_b_b, c14_b_w1);
  for (c14_i8 = 0; c14_i8 < 4; c14_i8++) {
    c14_v_oorp4[c14_i8] = c14_b_w1[c14_i8];
  }

  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 17);
  c14_r2.fl = c14_v_oorp4[0];
  c14_r2.fr = c14_v_oorp4[1];
  c14_r2.rl = c14_v_oorp4[2];
  c14_r2.rr = c14_v_oorp4[3];
  c14_b_v_z4 = c14_r2;
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, -17);
  _SFD_SYMBOL_SCOPE_POP();
  *(real_T *)&((char_T *)chartInstance->c14_v_z4)[0] = c14_b_v_z4.fl;
  *(real_T *)&((char_T *)chartInstance->c14_v_z4)[8] = c14_b_v_z4.fr;
  *(real_T *)&((char_T *)chartInstance->c14_v_z4)[16] = c14_b_v_z4.rl;
  *(real_T *)&((char_T *)chartInstance->c14_v_z4)[24] = c14_b_v_z4.rr;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, chartInstance->c14_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_ModifiedMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c14_Modified(SFc14_ModifiedInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc14_Modified(SFc14_ModifiedInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c14_machineNumber, uint32_T
  c14_chartNumber, uint32_T c14_instanceNumber)
{
  (void)c14_machineNumber;
  (void)c14_chartNumber;
  (void)c14_instanceNumber;
}

static const mxArray *c14_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  c14_whl_vec4 c14_u;
  const mxArray *c14_y = NULL;
  real_T c14_b_u;
  const mxArray *c14_b_y = NULL;
  real_T c14_c_u;
  const mxArray *c14_c_y = NULL;
  real_T c14_d_u;
  const mxArray *c14_d_y = NULL;
  real_T c14_e_u;
  const mxArray *c14_e_y = NULL;
  SFc14_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc14_ModifiedInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  c14_u = *(c14_whl_vec4 *)c14_inData;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c14_b_u = c14_u.fl;
  c14_b_y = NULL;
  sf_mex_assign(&c14_b_y, sf_mex_create("y", &c14_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c14_y, c14_b_y, "fl", "fl", 0);
  c14_c_u = c14_u.fr;
  c14_c_y = NULL;
  sf_mex_assign(&c14_c_y, sf_mex_create("y", &c14_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c14_y, c14_c_y, "fr", "fr", 0);
  c14_d_u = c14_u.rl;
  c14_d_y = NULL;
  sf_mex_assign(&c14_d_y, sf_mex_create("y", &c14_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c14_y, c14_d_y, "rl", "rl", 0);
  c14_e_u = c14_u.rr;
  c14_e_y = NULL;
  sf_mex_assign(&c14_e_y, sf_mex_create("y", &c14_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c14_y, c14_e_y, "rr", "rr", 0);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, false);
  return c14_mxArrayOutData;
}

static c14_whl_vec4 c14_emlrt_marshallIn(SFc14_ModifiedInstanceStruct
  *chartInstance, const mxArray *c14_b_v_z4, const char_T *c14_identifier)
{
  c14_whl_vec4 c14_y;
  emlrtMsgIdentifier c14_thisId;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_b_v_z4),
    &c14_thisId);
  sf_mex_destroy(&c14_b_v_z4);
  return c14_y;
}

static c14_whl_vec4 c14_b_emlrt_marshallIn(SFc14_ModifiedInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId)
{
  c14_whl_vec4 c14_y;
  emlrtMsgIdentifier c14_thisId;
  static const char * c14_fieldNames[4] = { "fl", "fr", "rl", "rr" };

  c14_thisId.fParent = c14_parentId;
  sf_mex_check_struct(c14_parentId, c14_u, 4, c14_fieldNames, 0U, NULL);
  c14_thisId.fIdentifier = "fl";
  c14_y.fl = c14_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c14_u, "fl", "fl", 0)), &c14_thisId);
  c14_thisId.fIdentifier = "fr";
  c14_y.fr = c14_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c14_u, "fr", "fr", 0)), &c14_thisId);
  c14_thisId.fIdentifier = "rl";
  c14_y.rl = c14_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c14_u, "rl", "rl", 0)), &c14_thisId);
  c14_thisId.fIdentifier = "rr";
  c14_y.rr = c14_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c14_u, "rr", "rr", 0)), &c14_thisId);
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static real_T c14_c_emlrt_marshallIn(SFc14_ModifiedInstanceStruct *chartInstance,
  const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId)
{
  real_T c14_y;
  real_T c14_d0;
  (void)chartInstance;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), &c14_d0, 1, 0, 0U, 0, 0U, 0);
  c14_y = c14_d0;
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static void c14_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_b_v_z4;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  c14_whl_vec4 c14_y;
  SFc14_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc14_ModifiedInstanceStruct *)chartInstanceVoid;
  c14_b_v_z4 = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_b_v_z4),
    &c14_thisId);
  sf_mex_destroy(&c14_b_v_z4);
  *(c14_whl_vec4 *)c14_outData = c14_y;
  sf_mex_destroy(&c14_mxArrayInData);
}

static const mxArray *c14_b_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData;
  c14_struct_iBlsPBO3AGnt69vDoTx5zD c14_u;
  const mxArray *c14_y = NULL;
  c14_struct_Nst2vGTExxHsg85EUOj9EH c14_b_u;
  const mxArray *c14_b_y = NULL;
  real_T c14_c_u;
  const mxArray *c14_c_y = NULL;
  c14_struct_HhckT6rntEraqECYVIDvCC c14_d_u;
  const mxArray *c14_d_y = NULL;
  real_T c14_e_u;
  const mxArray *c14_e_y = NULL;
  real_T c14_f_u;
  const mxArray *c14_f_y = NULL;
  const mxArray *c14_g_y = NULL;
  real_T c14_g_u;
  const mxArray *c14_h_y = NULL;
  real_T c14_h_u;
  const mxArray *c14_i_y = NULL;
  const mxArray *c14_j_y = NULL;
  real_T c14_i_u;
  const mxArray *c14_k_y = NULL;
  real_T c14_j_u;
  const mxArray *c14_l_y = NULL;
  const mxArray *c14_m_y = NULL;
  real_T c14_k_u;
  const mxArray *c14_n_y = NULL;
  real_T c14_l_u;
  const mxArray *c14_o_y = NULL;
  const mxArray *c14_p_y = NULL;
  real_T c14_m_u;
  const mxArray *c14_q_y = NULL;
  real_T c14_n_u;
  const mxArray *c14_r_y = NULL;
  real_T c14_o_u;
  const mxArray *c14_s_y = NULL;
  c14_struct_ZCmOWPuqBDw16FSOVVD00 c14_p_u;
  const mxArray *c14_t_y = NULL;
  real_T c14_q_u;
  const mxArray *c14_u_y = NULL;
  real_T c14_r_u;
  const mxArray *c14_v_y = NULL;
  real_T c14_s_u;
  const mxArray *c14_w_y = NULL;
  real_T c14_t_u;
  const mxArray *c14_x_y = NULL;
  real_T c14_u_u;
  const mxArray *c14_y_y = NULL;
  real_T c14_v_u;
  const mxArray *c14_ab_y = NULL;
  real_T c14_w_u;
  const mxArray *c14_bb_y = NULL;
  real_T c14_x_u;
  const mxArray *c14_cb_y = NULL;
  real_T c14_y_u;
  const mxArray *c14_db_y = NULL;
  real_T c14_ab_u;
  const mxArray *c14_eb_y = NULL;
  real_T c14_bb_u;
  const mxArray *c14_fb_y = NULL;
  int32_T c14_i9;
  real_T c14_cb_u[4];
  const mxArray *c14_gb_y = NULL;
  real_T c14_db_u;
  const mxArray *c14_hb_y = NULL;
  c14_struct_ZKAzdrl7umDGJoC14aoVKC c14_eb_u;
  const mxArray *c14_ib_y = NULL;
  int32_T c14_i10;
  real_T c14_fb_u[3];
  const mxArray *c14_jb_y = NULL;
  int32_T c14_i11;
  real_T c14_gb_u[3];
  const mxArray *c14_kb_y = NULL;
  int32_T c14_i12;
  real_T c14_hb_u[3];
  const mxArray *c14_lb_y = NULL;
  int32_T c14_i13;
  real_T c14_ib_u[3];
  const mxArray *c14_mb_y = NULL;
  const mxArray *c14_nb_y = NULL;
  int32_T c14_i14;
  real_T c14_jb_u[3];
  const mxArray *c14_ob_y = NULL;
  int32_T c14_i15;
  real_T c14_kb_u[3];
  const mxArray *c14_pb_y = NULL;
  int32_T c14_i16;
  real_T c14_lb_u[3];
  const mxArray *c14_qb_y = NULL;
  int32_T c14_i17;
  real_T c14_mb_u[3];
  const mxArray *c14_rb_y = NULL;
  const mxArray *c14_sb_y = NULL;
  int32_T c14_i18;
  real_T c14_nb_u[3];
  const mxArray *c14_tb_y = NULL;
  int32_T c14_i19;
  real_T c14_ob_u[3];
  const mxArray *c14_ub_y = NULL;
  int32_T c14_i20;
  real_T c14_pb_u[3];
  const mxArray *c14_vb_y = NULL;
  int32_T c14_i21;
  real_T c14_qb_u[3];
  const mxArray *c14_wb_y = NULL;
  const mxArray *c14_xb_y = NULL;
  int32_T c14_i22;
  real_T c14_rb_u[3];
  const mxArray *c14_yb_y = NULL;
  int32_T c14_i23;
  real_T c14_sb_u[3];
  const mxArray *c14_ac_y = NULL;
  int32_T c14_i24;
  real_T c14_tb_u[3];
  const mxArray *c14_bc_y = NULL;
  int32_T c14_i25;
  real_T c14_ub_u[3];
  const mxArray *c14_cc_y = NULL;
  real_T c14_vb_u;
  const mxArray *c14_dc_y = NULL;
  real_T c14_wb_u;
  const mxArray *c14_ec_y = NULL;
  real_T c14_xb_u;
  const mxArray *c14_fc_y = NULL;
  real_T c14_yb_u;
  const mxArray *c14_gc_y = NULL;
  real_T c14_ac_u;
  const mxArray *c14_hc_y = NULL;
  real_T c14_bc_u;
  const mxArray *c14_ic_y = NULL;
  real_T c14_cc_u;
  const mxArray *c14_jc_y = NULL;
  real_T c14_dc_u;
  const mxArray *c14_kc_y = NULL;
  real_T c14_ec_u;
  const mxArray *c14_lc_y = NULL;
  real_T c14_fc_u;
  const mxArray *c14_mc_y = NULL;
  real_T c14_gc_u;
  const mxArray *c14_nc_y = NULL;
  real_T c14_hc_u;
  const mxArray *c14_oc_y = NULL;
  c14_struct_r4FNviKwHfdhB8nQjvQv9 c14_ic_u;
  const mxArray *c14_pc_y = NULL;
  real_T c14_jc_u;
  const mxArray *c14_qc_y = NULL;
  c14_struct_Y9F1qlBi9AhssksPwemA4G c14_kc_u;
  const mxArray *c14_rc_y = NULL;
  real_T c14_lc_u;
  const mxArray *c14_sc_y = NULL;
  real_T c14_mc_u;
  const mxArray *c14_tc_y = NULL;
  real_T c14_nc_u;
  const mxArray *c14_uc_y = NULL;
  SFc14_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc14_ModifiedInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  c14_mxArrayOutData = NULL;
  c14_u = *(c14_struct_iBlsPBO3AGnt69vDoTx5zD *)c14_inData;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c14_b_u = c14_u.Env;
  c14_b_y = NULL;
  sf_mex_assign(&c14_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c14_c_u = c14_b_u.g;
  c14_c_y = NULL;
  sf_mex_assign(&c14_c_y, sf_mex_create("y", &c14_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c14_b_y, c14_c_y, "g", "g", 0);
  c14_d_u = c14_b_u.left1;
  c14_d_y = NULL;
  sf_mex_assign(&c14_d_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c14_e_u = c14_d_u.x;
  c14_e_y = NULL;
  sf_mex_assign(&c14_e_y, sf_mex_create("y", &c14_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c14_d_y, c14_e_y, "x", "x", 0);
  c14_f_u = c14_d_u.y;
  c14_f_y = NULL;
  sf_mex_assign(&c14_f_y, sf_mex_create("y", &c14_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c14_d_y, c14_f_y, "y", "y", 0);
  sf_mex_addfield(c14_b_y, c14_d_y, "left1", "left1", 0);
  c14_d_u = c14_b_u.right1;
  c14_g_y = NULL;
  sf_mex_assign(&c14_g_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c14_g_u = c14_d_u.x;
  c14_h_y = NULL;
  sf_mex_assign(&c14_h_y, sf_mex_create("y", &c14_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c14_g_y, c14_h_y, "x", "x", 0);
  c14_h_u = c14_d_u.y;
  c14_i_y = NULL;
  sf_mex_assign(&c14_i_y, sf_mex_create("y", &c14_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c14_g_y, c14_i_y, "y", "y", 0);
  sf_mex_addfield(c14_b_y, c14_g_y, "right1", "right1", 0);
  c14_d_u = c14_b_u.right2;
  c14_j_y = NULL;
  sf_mex_assign(&c14_j_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c14_i_u = c14_d_u.x;
  c14_k_y = NULL;
  sf_mex_assign(&c14_k_y, sf_mex_create("y", &c14_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c14_j_y, c14_k_y, "x", "x", 0);
  c14_j_u = c14_d_u.y;
  c14_l_y = NULL;
  sf_mex_assign(&c14_l_y, sf_mex_create("y", &c14_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c14_j_y, c14_l_y, "y", "y", 0);
  sf_mex_addfield(c14_b_y, c14_j_y, "right2", "right2", 0);
  c14_d_u = c14_b_u.left2;
  c14_m_y = NULL;
  sf_mex_assign(&c14_m_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c14_k_u = c14_d_u.x;
  c14_n_y = NULL;
  sf_mex_assign(&c14_n_y, sf_mex_create("y", &c14_k_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c14_m_y, c14_n_y, "x", "x", 0);
  c14_l_u = c14_d_u.y;
  c14_o_y = NULL;
  sf_mex_assign(&c14_o_y, sf_mex_create("y", &c14_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c14_m_y, c14_o_y, "y", "y", 0);
  sf_mex_addfield(c14_b_y, c14_m_y, "left2", "left2", 0);
  c14_d_u = c14_b_u.right3;
  c14_p_y = NULL;
  sf_mex_assign(&c14_p_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c14_m_u = c14_d_u.x;
  c14_q_y = NULL;
  sf_mex_assign(&c14_q_y, sf_mex_create("y", &c14_m_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c14_p_y, c14_q_y, "x", "x", 0);
  c14_n_u = c14_d_u.y;
  c14_r_y = NULL;
  sf_mex_assign(&c14_r_y, sf_mex_create("y", &c14_n_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c14_p_y, c14_r_y, "y", "y", 0);
  sf_mex_addfield(c14_b_y, c14_p_y, "right3", "right3", 0);
  c14_o_u = c14_b_u.mu;
  c14_s_y = NULL;
  sf_mex_assign(&c14_s_y, sf_mex_create("y", &c14_o_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c14_b_y, c14_s_y, "mu", "mu", 0);
  sf_mex_addfield(c14_y, c14_b_y, "Env", "Env", 0);
  c14_p_u = c14_u.Veh;
  c14_t_y = NULL;
  sf_mex_assign(&c14_t_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c14_q_u = c14_p_u.m;
  c14_u_y = NULL;
  sf_mex_assign(&c14_u_y, sf_mex_create("y", &c14_q_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c14_t_y, c14_u_y, "m", "m", 0);
  c14_r_u = c14_p_u.Jz;
  c14_v_y = NULL;
  sf_mex_assign(&c14_v_y, sf_mex_create("y", &c14_r_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c14_t_y, c14_v_y, "Jz", "Jz", 0);
  c14_s_u = c14_p_u.m_sprung;
  c14_w_y = NULL;
  sf_mex_assign(&c14_w_y, sf_mex_create("y", &c14_s_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c14_t_y, c14_w_y, "m_sprung", "m_sprung", 0);
  c14_t_u = c14_p_u.Jx_sprung;
  c14_x_y = NULL;
  sf_mex_assign(&c14_x_y, sf_mex_create("y", &c14_t_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c14_t_y, c14_x_y, "Jx_sprung", "Jx_sprung", 0);
  c14_u_u = c14_p_u.Jy_sprung;
  c14_y_y = NULL;
  sf_mex_assign(&c14_y_y, sf_mex_create("y", &c14_u_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c14_t_y, c14_y_y, "Jy_sprung", "Jy_sprung", 0);
  c14_v_u = c14_p_u.lf;
  c14_ab_y = NULL;
  sf_mex_assign(&c14_ab_y, sf_mex_create("y", &c14_v_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c14_t_y, c14_ab_y, "lf", "lf", 0);
  c14_w_u = c14_p_u.lr;
  c14_bb_y = NULL;
  sf_mex_assign(&c14_bb_y, sf_mex_create("y", &c14_w_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c14_t_y, c14_bb_y, "lr", "lr", 0);
  c14_x_u = c14_p_u.L;
  c14_cb_y = NULL;
  sf_mex_assign(&c14_cb_y, sf_mex_create("y", &c14_x_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c14_t_y, c14_cb_y, "L", "L", 0);
  c14_y_u = c14_p_u.TrackWidth;
  c14_db_y = NULL;
  sf_mex_assign(&c14_db_y, sf_mex_create("y", &c14_y_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c14_t_y, c14_db_y, "TrackWidth", "TrackWidth", 0);
  c14_ab_u = c14_p_u.h;
  c14_eb_y = NULL;
  sf_mex_assign(&c14_eb_y, sf_mex_create("y", &c14_ab_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c14_t_y, c14_eb_y, "h", "h", 0);
  c14_bb_u = c14_p_u.HalfRohACd;
  c14_fb_y = NULL;
  sf_mex_assign(&c14_fb_y, sf_mex_create("y", &c14_bb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c14_t_y, c14_fb_y, "HalfRohACd", "HalfRohACd", 0);
  for (c14_i9 = 0; c14_i9 < 4; c14_i9++) {
    c14_cb_u[c14_i9] = c14_p_u.F_z4_static[c14_i9];
  }

  c14_gb_y = NULL;
  sf_mex_assign(&c14_gb_y, sf_mex_create("y", c14_cb_u, 0, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_addfield(c14_t_y, c14_gb_y, "F_z4_static", "F_z4_static", 0);
  c14_db_u = c14_p_u.Rw;
  c14_hb_y = NULL;
  sf_mex_assign(&c14_hb_y, sf_mex_create("y", &c14_db_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c14_t_y, c14_hb_y, "Rw", "Rw", 0);
  c14_eb_u = c14_p_u.r_long;
  c14_ib_y = NULL;
  sf_mex_assign(&c14_ib_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c14_i10 = 0; c14_i10 < 3; c14_i10++) {
    c14_fb_u[c14_i10] = c14_eb_u.fl[c14_i10];
  }

  c14_jb_y = NULL;
  sf_mex_assign(&c14_jb_y, sf_mex_create("y", c14_fb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c14_ib_y, c14_jb_y, "fl", "fl", 0);
  for (c14_i11 = 0; c14_i11 < 3; c14_i11++) {
    c14_gb_u[c14_i11] = c14_eb_u.fr[c14_i11];
  }

  c14_kb_y = NULL;
  sf_mex_assign(&c14_kb_y, sf_mex_create("y", c14_gb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c14_ib_y, c14_kb_y, "fr", "fr", 0);
  for (c14_i12 = 0; c14_i12 < 3; c14_i12++) {
    c14_hb_u[c14_i12] = c14_eb_u.rl[c14_i12];
  }

  c14_lb_y = NULL;
  sf_mex_assign(&c14_lb_y, sf_mex_create("y", c14_hb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c14_ib_y, c14_lb_y, "rl", "rl", 0);
  for (c14_i13 = 0; c14_i13 < 3; c14_i13++) {
    c14_ib_u[c14_i13] = c14_eb_u.rr[c14_i13];
  }

  c14_mb_y = NULL;
  sf_mex_assign(&c14_mb_y, sf_mex_create("y", c14_ib_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c14_ib_y, c14_mb_y, "rr", "rr", 0);
  sf_mex_addfield(c14_t_y, c14_ib_y, "r_long", "r_long", 0);
  c14_eb_u = c14_p_u.r_lat;
  c14_nb_y = NULL;
  sf_mex_assign(&c14_nb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c14_i14 = 0; c14_i14 < 3; c14_i14++) {
    c14_jb_u[c14_i14] = c14_eb_u.fl[c14_i14];
  }

  c14_ob_y = NULL;
  sf_mex_assign(&c14_ob_y, sf_mex_create("y", c14_jb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c14_nb_y, c14_ob_y, "fl", "fl", 0);
  for (c14_i15 = 0; c14_i15 < 3; c14_i15++) {
    c14_kb_u[c14_i15] = c14_eb_u.fr[c14_i15];
  }

  c14_pb_y = NULL;
  sf_mex_assign(&c14_pb_y, sf_mex_create("y", c14_kb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c14_nb_y, c14_pb_y, "fr", "fr", 0);
  for (c14_i16 = 0; c14_i16 < 3; c14_i16++) {
    c14_lb_u[c14_i16] = c14_eb_u.rl[c14_i16];
  }

  c14_qb_y = NULL;
  sf_mex_assign(&c14_qb_y, sf_mex_create("y", c14_lb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c14_nb_y, c14_qb_y, "rl", "rl", 0);
  for (c14_i17 = 0; c14_i17 < 3; c14_i17++) {
    c14_mb_u[c14_i17] = c14_eb_u.rr[c14_i17];
  }

  c14_rb_y = NULL;
  sf_mex_assign(&c14_rb_y, sf_mex_create("y", c14_mb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c14_nb_y, c14_rb_y, "rr", "rr", 0);
  sf_mex_addfield(c14_t_y, c14_nb_y, "r_lat", "r_lat", 0);
  c14_eb_u = c14_p_u.r_lever;
  c14_sb_y = NULL;
  sf_mex_assign(&c14_sb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c14_i18 = 0; c14_i18 < 3; c14_i18++) {
    c14_nb_u[c14_i18] = c14_eb_u.fl[c14_i18];
  }

  c14_tb_y = NULL;
  sf_mex_assign(&c14_tb_y, sf_mex_create("y", c14_nb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c14_sb_y, c14_tb_y, "fl", "fl", 0);
  for (c14_i19 = 0; c14_i19 < 3; c14_i19++) {
    c14_ob_u[c14_i19] = c14_eb_u.fr[c14_i19];
  }

  c14_ub_y = NULL;
  sf_mex_assign(&c14_ub_y, sf_mex_create("y", c14_ob_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c14_sb_y, c14_ub_y, "fr", "fr", 0);
  for (c14_i20 = 0; c14_i20 < 3; c14_i20++) {
    c14_pb_u[c14_i20] = c14_eb_u.rl[c14_i20];
  }

  c14_vb_y = NULL;
  sf_mex_assign(&c14_vb_y, sf_mex_create("y", c14_pb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c14_sb_y, c14_vb_y, "rl", "rl", 0);
  for (c14_i21 = 0; c14_i21 < 3; c14_i21++) {
    c14_qb_u[c14_i21] = c14_eb_u.rr[c14_i21];
  }

  c14_wb_y = NULL;
  sf_mex_assign(&c14_wb_y, sf_mex_create("y", c14_qb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c14_sb_y, c14_wb_y, "rr", "rr", 0);
  sf_mex_addfield(c14_t_y, c14_sb_y, "r_lever", "r_lever", 0);
  c14_eb_u = c14_p_u.r_pivot;
  c14_xb_y = NULL;
  sf_mex_assign(&c14_xb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c14_i22 = 0; c14_i22 < 3; c14_i22++) {
    c14_rb_u[c14_i22] = c14_eb_u.fl[c14_i22];
  }

  c14_yb_y = NULL;
  sf_mex_assign(&c14_yb_y, sf_mex_create("y", c14_rb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c14_xb_y, c14_yb_y, "fl", "fl", 0);
  for (c14_i23 = 0; c14_i23 < 3; c14_i23++) {
    c14_sb_u[c14_i23] = c14_eb_u.fr[c14_i23];
  }

  c14_ac_y = NULL;
  sf_mex_assign(&c14_ac_y, sf_mex_create("y", c14_sb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c14_xb_y, c14_ac_y, "fr", "fr", 0);
  for (c14_i24 = 0; c14_i24 < 3; c14_i24++) {
    c14_tb_u[c14_i24] = c14_eb_u.rl[c14_i24];
  }

  c14_bc_y = NULL;
  sf_mex_assign(&c14_bc_y, sf_mex_create("y", c14_tb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c14_xb_y, c14_bc_y, "rl", "rl", 0);
  for (c14_i25 = 0; c14_i25 < 3; c14_i25++) {
    c14_ub_u[c14_i25] = c14_eb_u.rr[c14_i25];
  }

  c14_cc_y = NULL;
  sf_mex_assign(&c14_cc_y, sf_mex_create("y", c14_ub_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c14_xb_y, c14_cc_y, "rr", "rr", 0);
  sf_mex_addfield(c14_t_y, c14_xb_y, "r_pivot", "r_pivot", 0);
  c14_vb_u = c14_p_u.cw;
  c14_dc_y = NULL;
  sf_mex_assign(&c14_dc_y, sf_mex_create("y", &c14_vb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c14_t_y, c14_dc_y, "cw", "cw", 0);
  c14_wb_u = c14_p_u.carb_f;
  c14_ec_y = NULL;
  sf_mex_assign(&c14_ec_y, sf_mex_create("y", &c14_wb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c14_t_y, c14_ec_y, "carb_f", "carb_f", 0);
  c14_xb_u = c14_p_u.carb_r;
  c14_fc_y = NULL;
  sf_mex_assign(&c14_fc_y, sf_mex_create("y", &c14_xb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c14_t_y, c14_fc_y, "carb_r", "carb_r", 0);
  c14_yb_u = c14_p_u.dw;
  c14_gc_y = NULL;
  sf_mex_assign(&c14_gc_y, sf_mex_create("y", &c14_yb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c14_t_y, c14_gc_y, "dw", "dw", 0);
  c14_ac_u = c14_p_u.Jw;
  c14_hc_y = NULL;
  sf_mex_assign(&c14_hc_y, sf_mex_create("y", &c14_ac_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c14_t_y, c14_hc_y, "Jw", "Jw", 0);
  c14_bc_u = c14_p_u.C0;
  c14_ic_y = NULL;
  sf_mex_assign(&c14_ic_y, sf_mex_create("y", &c14_bc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c14_t_y, c14_ic_y, "C0", "C0", 0);
  c14_cc_u = c14_p_u.RelaxLength;
  c14_jc_y = NULL;
  sf_mex_assign(&c14_jc_y, sf_mex_create("y", &c14_cc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c14_t_y, c14_jc_y, "RelaxLength", "RelaxLength", 0);
  c14_dc_u = c14_p_u.RRC;
  c14_kc_y = NULL;
  sf_mex_assign(&c14_kc_y, sf_mex_create("y", &c14_dc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c14_t_y, c14_kc_y, "RRC", "RRC", 0);
  c14_ec_u = c14_p_u.Pmax;
  c14_lc_y = NULL;
  sf_mex_assign(&c14_lc_y, sf_mex_create("y", &c14_ec_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c14_t_y, c14_lc_y, "Pmax", "Pmax", 0);
  c14_fc_u = c14_p_u.PropDistrFrnt;
  c14_mc_y = NULL;
  sf_mex_assign(&c14_mc_y, sf_mex_create("y", &c14_fc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c14_t_y, c14_mc_y, "PropDistrFrnt", "PropDistrFrnt", 0);
  c14_gc_u = c14_p_u.BrkDistrFrnt;
  c14_nc_y = NULL;
  sf_mex_assign(&c14_nc_y, sf_mex_create("y", &c14_gc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c14_t_y, c14_nc_y, "BrkDistrFrnt", "BrkDistrFrnt", 0);
  c14_hc_u = c14_p_u.SteRatio;
  c14_oc_y = NULL;
  sf_mex_assign(&c14_oc_y, sf_mex_create("y", &c14_hc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c14_t_y, c14_oc_y, "SteRatio", "SteRatio", 0);
  sf_mex_addfield(c14_y, c14_t_y, "Veh", "Veh", 0);
  c14_ic_u = c14_u.Drvr;
  c14_pc_y = NULL;
  sf_mex_assign(&c14_pc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c14_jc_u = c14_ic_u.v_set;
  c14_qc_y = NULL;
  sf_mex_assign(&c14_qc_y, sf_mex_create("y", &c14_jc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c14_pc_y, c14_qc_y, "v_set", "v_set", 0);
  sf_mex_addfield(c14_y, c14_pc_y, "Drvr", "Drvr", 0);
  c14_kc_u = c14_u.Init;
  c14_rc_y = NULL;
  sf_mex_assign(&c14_rc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c14_lc_u = c14_kc_u.v_x;
  c14_sc_y = NULL;
  sf_mex_assign(&c14_sc_y, sf_mex_create("y", &c14_lc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c14_rc_y, c14_sc_y, "v_x", "v_x", 0);
  c14_mc_u = c14_kc_u.F_fz;
  c14_tc_y = NULL;
  sf_mex_assign(&c14_tc_y, sf_mex_create("y", &c14_mc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c14_rc_y, c14_tc_y, "F_fz", "F_fz", 0);
  c14_nc_u = c14_kc_u.F_rz;
  c14_uc_y = NULL;
  sf_mex_assign(&c14_uc_y, sf_mex_create("y", &c14_nc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c14_rc_y, c14_uc_y, "F_rz", "F_rz", 0);
  sf_mex_addfield(c14_y, c14_rc_y, "Init", "Init", 0);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, false);
  return c14_mxArrayOutData;
}

static void c14_d_emlrt_marshallIn(SFc14_ModifiedInstanceStruct *chartInstance,
  const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId,
  c14_struct_iBlsPBO3AGnt69vDoTx5zD *c14_y)
{
  emlrtMsgIdentifier c14_thisId;
  static const char * c14_fieldNames[4] = { "Env", "Veh", "Drvr", "Init" };

  c14_thisId.fParent = c14_parentId;
  sf_mex_check_struct(c14_parentId, c14_u, 4, c14_fieldNames, 0U, NULL);
  c14_thisId.fIdentifier = "Env";
  c14_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c14_u, "Env",
    "Env", 0)), &c14_thisId, &c14_y->Env);
  c14_thisId.fIdentifier = "Veh";
  c14_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c14_u, "Veh",
    "Veh", 0)), &c14_thisId, &c14_y->Veh);
  c14_thisId.fIdentifier = "Drvr";
  c14_y->Drvr = c14_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c14_u, "Drvr", "Drvr", 0)), &c14_thisId);
  c14_thisId.fIdentifier = "Init";
  c14_y->Init = c14_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c14_u, "Init", "Init", 0)), &c14_thisId);
  sf_mex_destroy(&c14_u);
}

static void c14_e_emlrt_marshallIn(SFc14_ModifiedInstanceStruct *chartInstance,
  const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId,
  c14_struct_Nst2vGTExxHsg85EUOj9EH *c14_y)
{
  emlrtMsgIdentifier c14_thisId;
  static const char * c14_fieldNames[7] = { "g", "left1", "right1", "right2",
    "left2", "right3", "mu" };

  c14_thisId.fParent = c14_parentId;
  sf_mex_check_struct(c14_parentId, c14_u, 7, c14_fieldNames, 0U, NULL);
  c14_thisId.fIdentifier = "g";
  c14_y->g = c14_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c14_u, "g", "g", 0)), &c14_thisId);
  c14_thisId.fIdentifier = "left1";
  c14_y->left1 = c14_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c14_u, "left1", "left1", 0)), &c14_thisId);
  c14_thisId.fIdentifier = "right1";
  c14_y->right1 = c14_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c14_u, "right1", "right1", 0)), &c14_thisId);
  c14_thisId.fIdentifier = "right2";
  c14_y->right2 = c14_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c14_u, "right2", "right2", 0)), &c14_thisId);
  c14_thisId.fIdentifier = "left2";
  c14_y->left2 = c14_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c14_u, "left2", "left2", 0)), &c14_thisId);
  c14_thisId.fIdentifier = "right3";
  c14_y->right3 = c14_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c14_u, "right3", "right3", 0)), &c14_thisId);
  c14_thisId.fIdentifier = "mu";
  c14_y->mu = c14_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c14_u, "mu", "mu", 0)), &c14_thisId);
  sf_mex_destroy(&c14_u);
}

static c14_struct_HhckT6rntEraqECYVIDvCC c14_f_emlrt_marshallIn
  (SFc14_ModifiedInstanceStruct *chartInstance, const mxArray *c14_u, const
   emlrtMsgIdentifier *c14_parentId)
{
  c14_struct_HhckT6rntEraqECYVIDvCC c14_y;
  emlrtMsgIdentifier c14_thisId;
  static const char * c14_fieldNames[2] = { "x", "y" };

  c14_thisId.fParent = c14_parentId;
  sf_mex_check_struct(c14_parentId, c14_u, 2, c14_fieldNames, 0U, NULL);
  c14_thisId.fIdentifier = "x";
  c14_y.x = c14_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c14_u, "x", "x", 0)), &c14_thisId);
  c14_thisId.fIdentifier = "y";
  c14_y.y = c14_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c14_u, "y", "y", 0)), &c14_thisId);
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static void c14_g_emlrt_marshallIn(SFc14_ModifiedInstanceStruct *chartInstance,
  const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId,
  c14_struct_ZCmOWPuqBDw16FSOVVD00 *c14_y)
{
  emlrtMsgIdentifier c14_thisId;
  static const char * c14_fieldNames[29] = { "m", "Jz", "m_sprung", "Jx_sprung",
    "Jy_sprung", "lf", "lr", "L", "TrackWidth", "h", "HalfRohACd", "F_z4_static",
    "Rw", "r_long", "r_lat", "r_lever", "r_pivot", "cw", "carb_f", "carb_r",
    "dw", "Jw", "C0", "RelaxLength", "RRC", "Pmax", "PropDistrFrnt",
    "BrkDistrFrnt", "SteRatio" };

  c14_thisId.fParent = c14_parentId;
  sf_mex_check_struct(c14_parentId, c14_u, 29, c14_fieldNames, 0U, NULL);
  c14_thisId.fIdentifier = "m";
  c14_y->m = c14_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c14_u, "m", "m", 0)), &c14_thisId);
  c14_thisId.fIdentifier = "Jz";
  c14_y->Jz = c14_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c14_u, "Jz", "Jz", 0)), &c14_thisId);
  c14_thisId.fIdentifier = "m_sprung";
  c14_y->m_sprung = c14_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c14_u, "m_sprung", "m_sprung", 0)), &c14_thisId);
  c14_thisId.fIdentifier = "Jx_sprung";
  c14_y->Jx_sprung = c14_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c14_u, "Jx_sprung", "Jx_sprung", 0)), &c14_thisId);
  c14_thisId.fIdentifier = "Jy_sprung";
  c14_y->Jy_sprung = c14_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c14_u, "Jy_sprung", "Jy_sprung", 0)), &c14_thisId);
  c14_thisId.fIdentifier = "lf";
  c14_y->lf = c14_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c14_u, "lf", "lf", 0)), &c14_thisId);
  c14_thisId.fIdentifier = "lr";
  c14_y->lr = c14_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c14_u, "lr", "lr", 0)), &c14_thisId);
  c14_thisId.fIdentifier = "L";
  c14_y->L = c14_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c14_u, "L", "L", 0)), &c14_thisId);
  c14_thisId.fIdentifier = "TrackWidth";
  c14_y->TrackWidth = c14_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c14_u, "TrackWidth", "TrackWidth", 0)), &c14_thisId);
  c14_thisId.fIdentifier = "h";
  c14_y->h = c14_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c14_u, "h", "h", 0)), &c14_thisId);
  c14_thisId.fIdentifier = "HalfRohACd";
  c14_y->HalfRohACd = c14_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c14_u, "HalfRohACd", "HalfRohACd", 0)), &c14_thisId);
  c14_thisId.fIdentifier = "F_z4_static";
  c14_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c14_u,
    "F_z4_static", "F_z4_static", 0)), &c14_thisId, c14_y->F_z4_static);
  c14_thisId.fIdentifier = "Rw";
  c14_y->Rw = c14_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c14_u, "Rw", "Rw", 0)), &c14_thisId);
  c14_thisId.fIdentifier = "r_long";
  c14_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c14_u,
    "r_long", "r_long", 0)), &c14_thisId, &c14_y->r_long);
  c14_thisId.fIdentifier = "r_lat";
  c14_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c14_u,
    "r_lat", "r_lat", 0)), &c14_thisId, &c14_y->r_lat);
  c14_thisId.fIdentifier = "r_lever";
  c14_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c14_u,
    "r_lever", "r_lever", 0)), &c14_thisId, &c14_y->r_lever);
  c14_thisId.fIdentifier = "r_pivot";
  c14_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c14_u,
    "r_pivot", "r_pivot", 0)), &c14_thisId, &c14_y->r_pivot);
  c14_thisId.fIdentifier = "cw";
  c14_y->cw = c14_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c14_u, "cw", "cw", 0)), &c14_thisId);
  c14_thisId.fIdentifier = "carb_f";
  c14_y->carb_f = c14_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c14_u, "carb_f", "carb_f", 0)), &c14_thisId);
  c14_thisId.fIdentifier = "carb_r";
  c14_y->carb_r = c14_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c14_u, "carb_r", "carb_r", 0)), &c14_thisId);
  c14_thisId.fIdentifier = "dw";
  c14_y->dw = c14_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c14_u, "dw", "dw", 0)), &c14_thisId);
  c14_thisId.fIdentifier = "Jw";
  c14_y->Jw = c14_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c14_u, "Jw", "Jw", 0)), &c14_thisId);
  c14_thisId.fIdentifier = "C0";
  c14_y->C0 = c14_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c14_u, "C0", "C0", 0)), &c14_thisId);
  c14_thisId.fIdentifier = "RelaxLength";
  c14_y->RelaxLength = c14_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c14_u, "RelaxLength", "RelaxLength", 0)), &c14_thisId);
  c14_thisId.fIdentifier = "RRC";
  c14_y->RRC = c14_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c14_u, "RRC", "RRC", 0)), &c14_thisId);
  c14_thisId.fIdentifier = "Pmax";
  c14_y->Pmax = c14_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c14_u, "Pmax", "Pmax", 0)), &c14_thisId);
  c14_thisId.fIdentifier = "PropDistrFrnt";
  c14_y->PropDistrFrnt = c14_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c14_u, "PropDistrFrnt", "PropDistrFrnt", 0)), &c14_thisId);
  c14_thisId.fIdentifier = "BrkDistrFrnt";
  c14_y->BrkDistrFrnt = c14_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c14_u, "BrkDistrFrnt", "BrkDistrFrnt", 0)), &c14_thisId);
  c14_thisId.fIdentifier = "SteRatio";
  c14_y->SteRatio = c14_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c14_u, "SteRatio", "SteRatio", 0)), &c14_thisId);
  sf_mex_destroy(&c14_u);
}

static void c14_h_emlrt_marshallIn(SFc14_ModifiedInstanceStruct *chartInstance,
  const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId, real_T c14_y[4])
{
  real_T c14_dv0[4];
  int32_T c14_i26;
  (void)chartInstance;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), c14_dv0, 1, 0, 0U, 1, 0U, 2, 1,
                4);
  for (c14_i26 = 0; c14_i26 < 4; c14_i26++) {
    c14_y[c14_i26] = c14_dv0[c14_i26];
  }

  sf_mex_destroy(&c14_u);
}

static void c14_i_emlrt_marshallIn(SFc14_ModifiedInstanceStruct *chartInstance,
  const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId,
  c14_struct_ZKAzdrl7umDGJoC14aoVKC *c14_y)
{
  emlrtMsgIdentifier c14_thisId;
  static const char * c14_fieldNames[4] = { "fl", "fr", "rl", "rr" };

  c14_thisId.fParent = c14_parentId;
  sf_mex_check_struct(c14_parentId, c14_u, 4, c14_fieldNames, 0U, NULL);
  c14_thisId.fIdentifier = "fl";
  c14_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c14_u, "fl",
    "fl", 0)), &c14_thisId, c14_y->fl);
  c14_thisId.fIdentifier = "fr";
  c14_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c14_u, "fr",
    "fr", 0)), &c14_thisId, c14_y->fr);
  c14_thisId.fIdentifier = "rl";
  c14_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c14_u, "rl",
    "rl", 0)), &c14_thisId, c14_y->rl);
  c14_thisId.fIdentifier = "rr";
  c14_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c14_u, "rr",
    "rr", 0)), &c14_thisId, c14_y->rr);
  sf_mex_destroy(&c14_u);
}

static void c14_j_emlrt_marshallIn(SFc14_ModifiedInstanceStruct *chartInstance,
  const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId, real_T c14_y[3])
{
  real_T c14_dv1[3];
  int32_T c14_i27;
  (void)chartInstance;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), c14_dv1, 1, 0, 0U, 1, 0U, 2, 3,
                1);
  for (c14_i27 = 0; c14_i27 < 3; c14_i27++) {
    c14_y[c14_i27] = c14_dv1[c14_i27];
  }

  sf_mex_destroy(&c14_u);
}

static c14_struct_r4FNviKwHfdhB8nQjvQv9 c14_k_emlrt_marshallIn
  (SFc14_ModifiedInstanceStruct *chartInstance, const mxArray *c14_u, const
   emlrtMsgIdentifier *c14_parentId)
{
  c14_struct_r4FNviKwHfdhB8nQjvQv9 c14_y;
  emlrtMsgIdentifier c14_thisId;
  static const char * c14_fieldNames[1] = { "v_set" };

  c14_thisId.fParent = c14_parentId;
  sf_mex_check_struct(c14_parentId, c14_u, 1, c14_fieldNames, 0U, NULL);
  c14_thisId.fIdentifier = "v_set";
  c14_y.v_set = c14_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c14_u, "v_set", "v_set", 0)),
    &c14_thisId);
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static c14_struct_Y9F1qlBi9AhssksPwemA4G c14_l_emlrt_marshallIn
  (SFc14_ModifiedInstanceStruct *chartInstance, const mxArray *c14_u, const
   emlrtMsgIdentifier *c14_parentId)
{
  c14_struct_Y9F1qlBi9AhssksPwemA4G c14_y;
  emlrtMsgIdentifier c14_thisId;
  static const char * c14_fieldNames[3] = { "v_x", "F_fz", "F_rz" };

  c14_thisId.fParent = c14_parentId;
  sf_mex_check_struct(c14_parentId, c14_u, 3, c14_fieldNames, 0U, NULL);
  c14_thisId.fIdentifier = "v_x";
  c14_y.v_x = c14_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c14_u, "v_x", "v_x", 0)), &c14_thisId);
  c14_thisId.fIdentifier = "F_fz";
  c14_y.F_fz = c14_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c14_u, "F_fz", "F_fz", 0)), &c14_thisId);
  c14_thisId.fIdentifier = "F_rz";
  c14_y.F_rz = c14_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c14_u, "F_rz", "F_rz", 0)), &c14_thisId);
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static void c14_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_b_Par;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  c14_struct_iBlsPBO3AGnt69vDoTx5zD c14_y;
  SFc14_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc14_ModifiedInstanceStruct *)chartInstanceVoid;
  c14_b_Par = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_b_Par), &c14_thisId,
    &c14_y);
  sf_mex_destroy(&c14_b_Par);
  *(c14_struct_iBlsPBO3AGnt69vDoTx5zD *)c14_outData = c14_y;
  sf_mex_destroy(&c14_mxArrayInData);
}

static const mxArray *c14_c_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  c14_oorp_vec3 c14_u;
  const mxArray *c14_y = NULL;
  real_T c14_b_u;
  const mxArray *c14_b_y = NULL;
  real_T c14_c_u;
  const mxArray *c14_c_y = NULL;
  real_T c14_d_u;
  const mxArray *c14_d_y = NULL;
  SFc14_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc14_ModifiedInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  c14_u = *(c14_oorp_vec3 *)c14_inData;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c14_b_u = c14_u.z;
  c14_b_y = NULL;
  sf_mex_assign(&c14_b_y, sf_mex_create("y", &c14_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c14_y, c14_b_y, "z", "z", 0);
  c14_c_u = c14_u.rotx;
  c14_c_y = NULL;
  sf_mex_assign(&c14_c_y, sf_mex_create("y", &c14_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c14_y, c14_c_y, "rotx", "rotx", 0);
  c14_d_u = c14_u.roty;
  c14_d_y = NULL;
  sf_mex_assign(&c14_d_y, sf_mex_create("y", &c14_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c14_y, c14_d_y, "roty", "roty", 0);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, false);
  return c14_mxArrayOutData;
}

static const mxArray *c14_d_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  real_T c14_u;
  const mxArray *c14_y = NULL;
  SFc14_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc14_ModifiedInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  c14_u = *(real_T *)c14_inData;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", &c14_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, false);
  return c14_mxArrayOutData;
}

static void c14_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_nargout;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  real_T c14_y;
  SFc14_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc14_ModifiedInstanceStruct *)chartInstanceVoid;
  c14_nargout = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_nargout),
    &c14_thisId);
  sf_mex_destroy(&c14_nargout);
  *(real_T *)c14_outData = c14_y;
  sf_mex_destroy(&c14_mxArrayInData);
}

static const mxArray *c14_e_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  int32_T c14_i28;
  real_T c14_b_inData[4];
  int32_T c14_i29;
  real_T c14_u[4];
  const mxArray *c14_y = NULL;
  SFc14_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc14_ModifiedInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  for (c14_i28 = 0; c14_i28 < 4; c14_i28++) {
    c14_b_inData[c14_i28] = (*(real_T (*)[4])c14_inData)[c14_i28];
  }

  for (c14_i29 = 0; c14_i29 < 4; c14_i29++) {
    c14_u[c14_i29] = c14_b_inData[c14_i29];
  }

  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", c14_u, 0, 0U, 1U, 0U, 1, 4), false);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, false);
  return c14_mxArrayOutData;
}

static void c14_m_emlrt_marshallIn(SFc14_ModifiedInstanceStruct *chartInstance,
  const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId, real_T c14_y[4])
{
  real_T c14_dv2[4];
  int32_T c14_i30;
  (void)chartInstance;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), c14_dv2, 1, 0, 0U, 1, 0U, 1, 4);
  for (c14_i30 = 0; c14_i30 < 4; c14_i30++) {
    c14_y[c14_i30] = c14_dv2[c14_i30];
  }

  sf_mex_destroy(&c14_u);
}

static void c14_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_v_oorp4;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  real_T c14_y[4];
  int32_T c14_i31;
  SFc14_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc14_ModifiedInstanceStruct *)chartInstanceVoid;
  c14_v_oorp4 = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_v_oorp4), &c14_thisId,
    c14_y);
  sf_mex_destroy(&c14_v_oorp4);
  for (c14_i31 = 0; c14_i31 < 4; c14_i31++) {
    (*(real_T (*)[4])c14_outData)[c14_i31] = c14_y[c14_i31];
  }

  sf_mex_destroy(&c14_mxArrayInData);
}

static const mxArray *c14_f_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  int32_T c14_i32;
  real_T c14_b_inData[3];
  int32_T c14_i33;
  real_T c14_u[3];
  const mxArray *c14_y = NULL;
  SFc14_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc14_ModifiedInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  for (c14_i32 = 0; c14_i32 < 3; c14_i32++) {
    c14_b_inData[c14_i32] = (*(real_T (*)[3])c14_inData)[c14_i32];
  }

  for (c14_i33 = 0; c14_i33 < 3; c14_i33++) {
    c14_u[c14_i33] = c14_b_inData[c14_i33];
  }

  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", c14_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, false);
  return c14_mxArrayOutData;
}

static void c14_n_emlrt_marshallIn(SFc14_ModifiedInstanceStruct *chartInstance,
  const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId, real_T c14_y[3])
{
  real_T c14_dv3[3];
  int32_T c14_i34;
  (void)chartInstance;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), c14_dv3, 1, 0, 0U, 1, 0U, 1, 3);
  for (c14_i34 = 0; c14_i34 < 3; c14_i34++) {
    c14_y[c14_i34] = c14_dv3[c14_i34];
  }

  sf_mex_destroy(&c14_u);
}

static void c14_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_v_oorp3_temp;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  real_T c14_y[3];
  int32_T c14_i35;
  SFc14_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc14_ModifiedInstanceStruct *)chartInstanceVoid;
  c14_v_oorp3_temp = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_v_oorp3_temp),
    &c14_thisId, c14_y);
  sf_mex_destroy(&c14_v_oorp3_temp);
  for (c14_i35 = 0; c14_i35 < 3; c14_i35++) {
    (*(real_T (*)[3])c14_outData)[c14_i35] = c14_y[c14_i35];
  }

  sf_mex_destroy(&c14_mxArrayInData);
}

const mxArray *sf_c14_Modified_get_eml_resolved_functions_info(void)
{
  const mxArray *c14_nameCaptureInfo = NULL;
  c14_nameCaptureInfo = NULL;
  sf_mex_assign(&c14_nameCaptureInfo, sf_mex_createstruct("structure", 2, 20, 1),
                false);
  c14_info_helper(&c14_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c14_nameCaptureInfo);
  return c14_nameCaptureInfo;
}

static void c14_info_helper(const mxArray **c14_info)
{
  const mxArray *c14_rhs0 = NULL;
  const mxArray *c14_lhs0 = NULL;
  const mxArray *c14_rhs1 = NULL;
  const mxArray *c14_lhs1 = NULL;
  const mxArray *c14_rhs2 = NULL;
  const mxArray *c14_lhs2 = NULL;
  const mxArray *c14_rhs3 = NULL;
  const mxArray *c14_lhs3 = NULL;
  const mxArray *c14_rhs4 = NULL;
  const mxArray *c14_lhs4 = NULL;
  const mxArray *c14_rhs5 = NULL;
  const mxArray *c14_lhs5 = NULL;
  const mxArray *c14_rhs6 = NULL;
  const mxArray *c14_lhs6 = NULL;
  const mxArray *c14_rhs7 = NULL;
  const mxArray *c14_lhs7 = NULL;
  const mxArray *c14_rhs8 = NULL;
  const mxArray *c14_lhs8 = NULL;
  const mxArray *c14_rhs9 = NULL;
  const mxArray *c14_lhs9 = NULL;
  const mxArray *c14_rhs10 = NULL;
  const mxArray *c14_lhs10 = NULL;
  const mxArray *c14_rhs11 = NULL;
  const mxArray *c14_lhs11 = NULL;
  const mxArray *c14_rhs12 = NULL;
  const mxArray *c14_lhs12 = NULL;
  const mxArray *c14_rhs13 = NULL;
  const mxArray *c14_lhs13 = NULL;
  const mxArray *c14_rhs14 = NULL;
  const mxArray *c14_lhs14 = NULL;
  const mxArray *c14_rhs15 = NULL;
  const mxArray *c14_lhs15 = NULL;
  const mxArray *c14_rhs16 = NULL;
  const mxArray *c14_lhs16 = NULL;
  const mxArray *c14_rhs17 = NULL;
  const mxArray *c14_lhs17 = NULL;
  const mxArray *c14_rhs18 = NULL;
  const mxArray *c14_lhs18 = NULL;
  const mxArray *c14_rhs19 = NULL;
  const mxArray *c14_lhs19 = NULL;
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("mrdivide"), "name", "name",
                  0);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1410807648U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1370009886U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c14_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1389717774U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c14_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("rdivide"), "name", "name", 2);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1363713880U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c14_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c14_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 4);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c14_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("eml_div"), "name", "name", 5);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1386423952U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c14_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 6);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c14_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(""), "context", "context", 7);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 7);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1383877294U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c14_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 8);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 8);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c14_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 9);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c14_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 10);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 10);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c14_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 11);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c14_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 12);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  12);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1375980690U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c14_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 13);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c14_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("coder.internal.blas.xgemm"),
                  "name", "name", 14);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c14_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 15);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 15);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c14_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!below_threshold"),
                  "context", "context", 16);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 16);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c14_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 17);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 17);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1393330858U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c14_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 18);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 18);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c14_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 19);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "coder.internal.refblas.xgemm"), "name", "name", 19);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c14_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs19), "lhs", "lhs",
                  19);
  sf_mex_destroy(&c14_rhs0);
  sf_mex_destroy(&c14_lhs0);
  sf_mex_destroy(&c14_rhs1);
  sf_mex_destroy(&c14_lhs1);
  sf_mex_destroy(&c14_rhs2);
  sf_mex_destroy(&c14_lhs2);
  sf_mex_destroy(&c14_rhs3);
  sf_mex_destroy(&c14_lhs3);
  sf_mex_destroy(&c14_rhs4);
  sf_mex_destroy(&c14_lhs4);
  sf_mex_destroy(&c14_rhs5);
  sf_mex_destroy(&c14_lhs5);
  sf_mex_destroy(&c14_rhs6);
  sf_mex_destroy(&c14_lhs6);
  sf_mex_destroy(&c14_rhs7);
  sf_mex_destroy(&c14_lhs7);
  sf_mex_destroy(&c14_rhs8);
  sf_mex_destroy(&c14_lhs8);
  sf_mex_destroy(&c14_rhs9);
  sf_mex_destroy(&c14_lhs9);
  sf_mex_destroy(&c14_rhs10);
  sf_mex_destroy(&c14_lhs10);
  sf_mex_destroy(&c14_rhs11);
  sf_mex_destroy(&c14_lhs11);
  sf_mex_destroy(&c14_rhs12);
  sf_mex_destroy(&c14_lhs12);
  sf_mex_destroy(&c14_rhs13);
  sf_mex_destroy(&c14_lhs13);
  sf_mex_destroy(&c14_rhs14);
  sf_mex_destroy(&c14_lhs14);
  sf_mex_destroy(&c14_rhs15);
  sf_mex_destroy(&c14_lhs15);
  sf_mex_destroy(&c14_rhs16);
  sf_mex_destroy(&c14_lhs16);
  sf_mex_destroy(&c14_rhs17);
  sf_mex_destroy(&c14_lhs17);
  sf_mex_destroy(&c14_rhs18);
  sf_mex_destroy(&c14_lhs18);
  sf_mex_destroy(&c14_rhs19);
  sf_mex_destroy(&c14_lhs19);
}

static const mxArray *c14_emlrt_marshallOut(const char * c14_u)
{
  const mxArray *c14_y = NULL;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", c14_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c14_u)), false);
  return c14_y;
}

static const mxArray *c14_b_emlrt_marshallOut(const uint32_T c14_u)
{
  const mxArray *c14_y = NULL;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", &c14_u, 7, 0U, 0U, 0U, 0), false);
  return c14_y;
}

static void c14_eml_scalar_eg(SFc14_ModifiedInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c14_eml_xgemm(SFc14_ModifiedInstanceStruct *chartInstance, real_T
  c14_A[12], real_T c14_B[3], real_T c14_C[4], real_T c14_b_C[4])
{
  int32_T c14_i36;
  int32_T c14_i37;
  real_T c14_b_A[12];
  int32_T c14_i38;
  real_T c14_b_B[3];
  for (c14_i36 = 0; c14_i36 < 4; c14_i36++) {
    c14_b_C[c14_i36] = c14_C[c14_i36];
  }

  for (c14_i37 = 0; c14_i37 < 12; c14_i37++) {
    c14_b_A[c14_i37] = c14_A[c14_i37];
  }

  for (c14_i38 = 0; c14_i38 < 3; c14_i38++) {
    c14_b_B[c14_i38] = c14_B[c14_i38];
  }

  c14_b_eml_xgemm(chartInstance, c14_b_A, c14_b_B, c14_b_C);
}

static const mxArray *c14_g_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  int32_T c14_u;
  const mxArray *c14_y = NULL;
  SFc14_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc14_ModifiedInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  c14_u = *(int32_T *)c14_inData;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", &c14_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, false);
  return c14_mxArrayOutData;
}

static int32_T c14_o_emlrt_marshallIn(SFc14_ModifiedInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId)
{
  int32_T c14_y;
  int32_T c14_i39;
  (void)chartInstance;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), &c14_i39, 1, 6, 0U, 0, 0U, 0);
  c14_y = c14_i39;
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static void c14_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_b_sfEvent;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  int32_T c14_y;
  SFc14_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc14_ModifiedInstanceStruct *)chartInstanceVoid;
  c14_b_sfEvent = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_b_sfEvent),
    &c14_thisId);
  sf_mex_destroy(&c14_b_sfEvent);
  *(int32_T *)c14_outData = c14_y;
  sf_mex_destroy(&c14_mxArrayInData);
}

static const mxArray *c14_v_oorp3_bus_io(void *chartInstanceVoid, void
  *c14_pData)
{
  const mxArray *c14_mxVal = NULL;
  c14_oorp_vec3 c14_tmp;
  SFc14_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc14_ModifiedInstanceStruct *)chartInstanceVoid;
  c14_mxVal = NULL;
  c14_tmp.z = *(real_T *)&((char_T *)(c14_oorp_vec3 *)c14_pData)[0];
  c14_tmp.rotx = *(real_T *)&((char_T *)(c14_oorp_vec3 *)c14_pData)[8];
  c14_tmp.roty = *(real_T *)&((char_T *)(c14_oorp_vec3 *)c14_pData)[16];
  sf_mex_assign(&c14_mxVal, c14_c_sf_marshallOut(chartInstance, &c14_tmp), false);
  return c14_mxVal;
}

static const mxArray *c14_v_z4_bus_io(void *chartInstanceVoid, void *c14_pData)
{
  const mxArray *c14_mxVal = NULL;
  c14_whl_vec4 c14_tmp;
  SFc14_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc14_ModifiedInstanceStruct *)chartInstanceVoid;
  c14_mxVal = NULL;
  c14_tmp.fl = *(real_T *)&((char_T *)(c14_whl_vec4 *)c14_pData)[0];
  c14_tmp.fr = *(real_T *)&((char_T *)(c14_whl_vec4 *)c14_pData)[8];
  c14_tmp.rl = *(real_T *)&((char_T *)(c14_whl_vec4 *)c14_pData)[16];
  c14_tmp.rr = *(real_T *)&((char_T *)(c14_whl_vec4 *)c14_pData)[24];
  sf_mex_assign(&c14_mxVal, c14_sf_marshallOut(chartInstance, &c14_tmp), false);
  return c14_mxVal;
}

static uint8_T c14_p_emlrt_marshallIn(SFc14_ModifiedInstanceStruct
  *chartInstance, const mxArray *c14_b_is_active_c14_Modified, const char_T
  *c14_identifier)
{
  uint8_T c14_y;
  emlrtMsgIdentifier c14_thisId;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_q_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c14_b_is_active_c14_Modified), &c14_thisId);
  sf_mex_destroy(&c14_b_is_active_c14_Modified);
  return c14_y;
}

static uint8_T c14_q_emlrt_marshallIn(SFc14_ModifiedInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId)
{
  uint8_T c14_y;
  uint8_T c14_u0;
  (void)chartInstance;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), &c14_u0, 1, 3, 0U, 0, 0U, 0);
  c14_y = c14_u0;
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static void c14_b_eml_xgemm(SFc14_ModifiedInstanceStruct *chartInstance, real_T
  c14_A[12], real_T c14_B[3], real_T c14_C[4])
{
  int32_T c14_i40;
  int32_T c14_i41;
  int32_T c14_i42;
  (void)chartInstance;
  for (c14_i40 = 0; c14_i40 < 4; c14_i40++) {
    c14_C[c14_i40] = 0.0;
    c14_i41 = 0;
    for (c14_i42 = 0; c14_i42 < 3; c14_i42++) {
      c14_C[c14_i40] += c14_A[c14_i41 + c14_i40] * c14_B[c14_i42];
      c14_i41 += 4;
    }
  }
}

static void init_dsm_address_info(SFc14_ModifiedInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc14_ModifiedInstanceStruct *chartInstance)
{
  chartInstance->c14_v_oorp3 = (c14_oorp_vec3 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c14_v_z4 = (c14_whl_vec4 *)ssGetOutputPortSignal_wrapper
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

void sf_c14_Modified_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2773817902U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2099995734U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1161342682U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1634779001U);
}

mxArray* sf_c14_Modified_get_post_codegen_info(void);
mxArray *sf_c14_Modified_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("7Gizfo0uGfrrOBsJlcLSkB");
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
    mxArray* mxPostCodegenInfo = sf_c14_Modified_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c14_Modified_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c14_Modified_jit_fallback_info(void)
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

mxArray *sf_c14_Modified_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c14_Modified_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c14_Modified(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"v_z4\",},{M[8],M[0],T\"is_active_c14_Modified\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c14_Modified_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc14_ModifiedInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc14_ModifiedInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ModifiedMachineNumber_,
           14,
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
          (MexFcnForType)c14_v_oorp3_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c14_v_z4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c14_b_sf_marshallOut,(MexInFcnForType)
          c14_b_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c14_v_oorp3);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c14_v_z4);
        _SFD_SET_DATA_VALUE_PTR(2U, &chartInstance->c14_Par);
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
  return "bFcY0vA3yx0dOBkNrnUtZG";
}

static void sf_opaque_initialize_c14_Modified(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc14_ModifiedInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c14_Modified((SFc14_ModifiedInstanceStruct*)
    chartInstanceVar);
  initialize_c14_Modified((SFc14_ModifiedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c14_Modified(void *chartInstanceVar)
{
  enable_c14_Modified((SFc14_ModifiedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c14_Modified(void *chartInstanceVar)
{
  disable_c14_Modified((SFc14_ModifiedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c14_Modified(void *chartInstanceVar)
{
  sf_gateway_c14_Modified((SFc14_ModifiedInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c14_Modified(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c14_Modified((SFc14_ModifiedInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c14_Modified(SimStruct* S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c14_Modified((SFc14_ModifiedInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c14_Modified(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc14_ModifiedInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Modified_optimization_info();
    }

    finalize_c14_Modified((SFc14_ModifiedInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc14_Modified((SFc14_ModifiedInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c14_Modified(SimStruct *S)
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
    initialize_params_c14_Modified((SFc14_ModifiedInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c14_Modified(SimStruct *S)
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
      14);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,14,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,14,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,14);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,14,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,14,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,14);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4270022734U));
  ssSetChecksum1(S,(1666442209U));
  ssSetChecksum2(S,(1763450167U));
  ssSetChecksum3(S,(969503071U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c14_Modified(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c14_Modified(SimStruct *S)
{
  SFc14_ModifiedInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc14_ModifiedInstanceStruct *)utMalloc(sizeof
    (SFc14_ModifiedInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc14_ModifiedInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c14_Modified;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c14_Modified;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c14_Modified;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c14_Modified;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c14_Modified;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c14_Modified;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c14_Modified;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c14_Modified;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c14_Modified;
  chartInstance->chartInfo.mdlStart = mdlStart_c14_Modified;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c14_Modified;
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

void c14_Modified_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c14_Modified(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c14_Modified(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c14_Modified(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c14_Modified_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
