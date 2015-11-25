/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Modified_sfun.h"
#include "c27_Modified.h"
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
static const char * c27_debug_family_names[11] = { "F_z4_temp", "nargin",
  "nargout", "s_x4", "s_y4", "s_xy4", "F_xyw4", "F_z4_prev", "Par", "F_xw4",
  "F_yw4" };

/* Function Declarations */
static void initialize_c27_Modified(SFc27_ModifiedInstanceStruct *chartInstance);
static void initialize_params_c27_Modified(SFc27_ModifiedInstanceStruct
  *chartInstance);
static void enable_c27_Modified(SFc27_ModifiedInstanceStruct *chartInstance);
static void disable_c27_Modified(SFc27_ModifiedInstanceStruct *chartInstance);
static void c27_update_debugger_state_c27_Modified(SFc27_ModifiedInstanceStruct *
  chartInstance);
static const mxArray *get_sim_state_c27_Modified(SFc27_ModifiedInstanceStruct
  *chartInstance);
static void set_sim_state_c27_Modified(SFc27_ModifiedInstanceStruct
  *chartInstance, const mxArray *c27_st);
static void finalize_c27_Modified(SFc27_ModifiedInstanceStruct *chartInstance);
static void sf_gateway_c27_Modified(SFc27_ModifiedInstanceStruct *chartInstance);
static void mdl_start_c27_Modified(SFc27_ModifiedInstanceStruct *chartInstance);
static void c27_chartstep_c27_Modified(SFc27_ModifiedInstanceStruct
  *chartInstance);
static void initSimStructsc27_Modified(SFc27_ModifiedInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c27_machineNumber, uint32_T
  c27_chartNumber, uint32_T c27_instanceNumber);
static const mxArray *c27_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData);
static c27_whl_vec4 c27_emlrt_marshallIn(SFc27_ModifiedInstanceStruct
  *chartInstance, const mxArray *c27_b_F_yw4, const char_T *c27_identifier);
static c27_whl_vec4 c27_b_emlrt_marshallIn(SFc27_ModifiedInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId);
static real_T c27_c_emlrt_marshallIn(SFc27_ModifiedInstanceStruct *chartInstance,
  const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId);
static void c27_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData);
static const mxArray *c27_b_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData);
static void c27_d_emlrt_marshallIn(SFc27_ModifiedInstanceStruct *chartInstance,
  const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId,
  c27_struct_iBlsPBO3AGnt69vDoTx5zD *c27_y);
static void c27_e_emlrt_marshallIn(SFc27_ModifiedInstanceStruct *chartInstance,
  const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId,
  c27_struct_Nst2vGTExxHsg85EUOj9EH *c27_y);
static c27_struct_HhckT6rntEraqECYVIDvCC c27_f_emlrt_marshallIn
  (SFc27_ModifiedInstanceStruct *chartInstance, const mxArray *c27_u, const
   emlrtMsgIdentifier *c27_parentId);
static void c27_g_emlrt_marshallIn(SFc27_ModifiedInstanceStruct *chartInstance,
  const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId,
  c27_struct_ZCmOWPuqBDw16FSOVVD00 *c27_y);
static void c27_h_emlrt_marshallIn(SFc27_ModifiedInstanceStruct *chartInstance,
  const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId, real_T c27_y[4]);
static void c27_i_emlrt_marshallIn(SFc27_ModifiedInstanceStruct *chartInstance,
  const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId,
  c27_struct_ZKAzdrl7umDGJoC14aoVKC *c27_y);
static void c27_j_emlrt_marshallIn(SFc27_ModifiedInstanceStruct *chartInstance,
  const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId, real_T c27_y[3]);
static c27_struct_r4FNviKwHfdhB8nQjvQv9 c27_k_emlrt_marshallIn
  (SFc27_ModifiedInstanceStruct *chartInstance, const mxArray *c27_u, const
   emlrtMsgIdentifier *c27_parentId);
static c27_struct_Y9F1qlBi9AhssksPwemA4G c27_l_emlrt_marshallIn
  (SFc27_ModifiedInstanceStruct *chartInstance, const mxArray *c27_u, const
   emlrtMsgIdentifier *c27_parentId);
static void c27_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData);
static const mxArray *c27_c_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData);
static void c27_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData);
static const mxArray *c27_d_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData);
static void c27_m_emlrt_marshallIn(SFc27_ModifiedInstanceStruct *chartInstance,
  const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId, real_T c27_y[4]);
static void c27_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData);
static void c27_info_helper(const mxArray **c27_info);
static const mxArray *c27_emlrt_marshallOut(const char * c27_u);
static const mxArray *c27_b_emlrt_marshallOut(const uint32_T c27_u);
static const mxArray *c27_e_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData);
static int32_T c27_n_emlrt_marshallIn(SFc27_ModifiedInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId);
static void c27_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData);
static const mxArray *c27_s_x4_bus_io(void *chartInstanceVoid, void *c27_pData);
static uint8_T c27_o_emlrt_marshallIn(SFc27_ModifiedInstanceStruct
  *chartInstance, const mxArray *c27_b_is_active_c27_Modified, const char_T
  *c27_identifier);
static uint8_T c27_p_emlrt_marshallIn(SFc27_ModifiedInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId);
static void init_dsm_address_info(SFc27_ModifiedInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc27_ModifiedInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c27_Modified(SFc27_ModifiedInstanceStruct *chartInstance)
{
  chartInstance->c27_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c27_is_active_c27_Modified = 0U;
}

static void initialize_params_c27_Modified(SFc27_ModifiedInstanceStruct
  *chartInstance)
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

static void enable_c27_Modified(SFc27_ModifiedInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c27_Modified(SFc27_ModifiedInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c27_update_debugger_state_c27_Modified(SFc27_ModifiedInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c27_Modified(SFc27_ModifiedInstanceStruct
  *chartInstance)
{
  const mxArray *c27_st;
  const mxArray *c27_y = NULL;
  const mxArray *c27_b_y = NULL;
  real_T c27_u;
  const mxArray *c27_c_y = NULL;
  real_T c27_b_u;
  const mxArray *c27_d_y = NULL;
  real_T c27_c_u;
  const mxArray *c27_e_y = NULL;
  real_T c27_d_u;
  const mxArray *c27_f_y = NULL;
  const mxArray *c27_g_y = NULL;
  real_T c27_e_u;
  const mxArray *c27_h_y = NULL;
  real_T c27_f_u;
  const mxArray *c27_i_y = NULL;
  real_T c27_g_u;
  const mxArray *c27_j_y = NULL;
  real_T c27_h_u;
  const mxArray *c27_k_y = NULL;
  uint8_T c27_hoistedGlobal;
  uint8_T c27_i_u;
  const mxArray *c27_l_y = NULL;
  c27_st = NULL;
  c27_st = NULL;
  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_createcellmatrix(3, 1), false);
  c27_b_y = NULL;
  sf_mex_assign(&c27_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c27_u = *(real_T *)&((char_T *)chartInstance->c27_F_xw4)[0];
  c27_c_y = NULL;
  sf_mex_assign(&c27_c_y, sf_mex_create("y", &c27_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c27_b_y, c27_c_y, "fl", "fl", 0);
  c27_b_u = *(real_T *)&((char_T *)chartInstance->c27_F_xw4)[8];
  c27_d_y = NULL;
  sf_mex_assign(&c27_d_y, sf_mex_create("y", &c27_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c27_b_y, c27_d_y, "fr", "fr", 0);
  c27_c_u = *(real_T *)&((char_T *)chartInstance->c27_F_xw4)[16];
  c27_e_y = NULL;
  sf_mex_assign(&c27_e_y, sf_mex_create("y", &c27_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c27_b_y, c27_e_y, "rl", "rl", 0);
  c27_d_u = *(real_T *)&((char_T *)chartInstance->c27_F_xw4)[24];
  c27_f_y = NULL;
  sf_mex_assign(&c27_f_y, sf_mex_create("y", &c27_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c27_b_y, c27_f_y, "rr", "rr", 0);
  sf_mex_setcell(c27_y, 0, c27_b_y);
  c27_g_y = NULL;
  sf_mex_assign(&c27_g_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c27_e_u = *(real_T *)&((char_T *)chartInstance->c27_F_yw4)[0];
  c27_h_y = NULL;
  sf_mex_assign(&c27_h_y, sf_mex_create("y", &c27_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c27_g_y, c27_h_y, "fl", "fl", 0);
  c27_f_u = *(real_T *)&((char_T *)chartInstance->c27_F_yw4)[8];
  c27_i_y = NULL;
  sf_mex_assign(&c27_i_y, sf_mex_create("y", &c27_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c27_g_y, c27_i_y, "fr", "fr", 0);
  c27_g_u = *(real_T *)&((char_T *)chartInstance->c27_F_yw4)[16];
  c27_j_y = NULL;
  sf_mex_assign(&c27_j_y, sf_mex_create("y", &c27_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c27_g_y, c27_j_y, "rl", "rl", 0);
  c27_h_u = *(real_T *)&((char_T *)chartInstance->c27_F_yw4)[24];
  c27_k_y = NULL;
  sf_mex_assign(&c27_k_y, sf_mex_create("y", &c27_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c27_g_y, c27_k_y, "rr", "rr", 0);
  sf_mex_setcell(c27_y, 1, c27_g_y);
  c27_hoistedGlobal = chartInstance->c27_is_active_c27_Modified;
  c27_i_u = c27_hoistedGlobal;
  c27_l_y = NULL;
  sf_mex_assign(&c27_l_y, sf_mex_create("y", &c27_i_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c27_y, 2, c27_l_y);
  sf_mex_assign(&c27_st, c27_y, false);
  return c27_st;
}

static void set_sim_state_c27_Modified(SFc27_ModifiedInstanceStruct
  *chartInstance, const mxArray *c27_st)
{
  const mxArray *c27_u;
  c27_whl_vec4 c27_r1;
  c27_whl_vec4 c27_r2;
  chartInstance->c27_doneDoubleBufferReInit = true;
  c27_u = sf_mex_dup(c27_st);
  c27_r1 = c27_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c27_u,
    0)), "F_xw4");
  *(real_T *)&((char_T *)chartInstance->c27_F_xw4)[0] = c27_r1.fl;
  *(real_T *)&((char_T *)chartInstance->c27_F_xw4)[8] = c27_r1.fr;
  *(real_T *)&((char_T *)chartInstance->c27_F_xw4)[16] = c27_r1.rl;
  *(real_T *)&((char_T *)chartInstance->c27_F_xw4)[24] = c27_r1.rr;
  c27_r2 = c27_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c27_u,
    1)), "F_yw4");
  *(real_T *)&((char_T *)chartInstance->c27_F_yw4)[0] = c27_r2.fl;
  *(real_T *)&((char_T *)chartInstance->c27_F_yw4)[8] = c27_r2.fr;
  *(real_T *)&((char_T *)chartInstance->c27_F_yw4)[16] = c27_r2.rl;
  *(real_T *)&((char_T *)chartInstance->c27_F_yw4)[24] = c27_r2.rr;
  chartInstance->c27_is_active_c27_Modified = c27_o_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c27_u, 2)),
     "is_active_c27_Modified");
  sf_mex_destroy(&c27_u);
  c27_update_debugger_state_c27_Modified(chartInstance);
  sf_mex_destroy(&c27_st);
}

static void finalize_c27_Modified(SFc27_ModifiedInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c27_Modified(SFc27_ModifiedInstanceStruct *chartInstance)
{
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 26U, chartInstance->c27_sfEvent);
  chartInstance->c27_sfEvent = CALL_EVENT;
  c27_chartstep_c27_Modified(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_ModifiedMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c27_Modified(SFc27_ModifiedInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c27_chartstep_c27_Modified(SFc27_ModifiedInstanceStruct
  *chartInstance)
{
  c27_whl_vec4 c27_b_s_x4;
  c27_whl_vec4 c27_b_s_y4;
  c27_whl_vec4 c27_b_s_xy4;
  c27_whl_vec4 c27_b_F_xyw4;
  c27_whl_vec4 c27_b_F_z4_prev;
  c27_struct_iBlsPBO3AGnt69vDoTx5zD c27_b_Par;
  uint32_T c27_debug_family_var_map[11];
  real_T c27_F_z4_temp[4];
  real_T c27_nargin = 6.0;
  real_T c27_nargout = 2.0;
  c27_whl_vec4 c27_b_F_xw4;
  c27_whl_vec4 c27_b_F_yw4;
  real_T c27_A;
  real_T c27_B;
  real_T c27_x;
  real_T c27_y;
  real_T c27_b_x;
  real_T c27_b_y;
  real_T c27_c_x;
  real_T c27_c_y;
  real_T c27_d0;
  real_T c27_b_A;
  real_T c27_b_B;
  real_T c27_d_x;
  real_T c27_d_y;
  real_T c27_e_x;
  real_T c27_e_y;
  real_T c27_f_x;
  real_T c27_f_y;
  real_T c27_g_y;
  real_T c27_c_A;
  real_T c27_c_B;
  real_T c27_g_x;
  real_T c27_h_y;
  real_T c27_h_x;
  real_T c27_i_y;
  real_T c27_i_x;
  real_T c27_j_y;
  real_T c27_k_y;
  real_T c27_d_A;
  real_T c27_d_B;
  real_T c27_j_x;
  real_T c27_l_y;
  real_T c27_k_x;
  real_T c27_m_y;
  real_T c27_l_x;
  real_T c27_n_y;
  real_T c27_d1;
  real_T c27_e_A;
  real_T c27_e_B;
  real_T c27_m_x;
  real_T c27_o_y;
  real_T c27_n_x;
  real_T c27_p_y;
  real_T c27_o_x;
  real_T c27_q_y;
  real_T c27_r_y;
  real_T c27_f_A;
  real_T c27_f_B;
  real_T c27_p_x;
  real_T c27_s_y;
  real_T c27_q_x;
  real_T c27_t_y;
  real_T c27_r_x;
  real_T c27_u_y;
  real_T c27_v_y;
  real_T c27_g_A;
  real_T c27_g_B;
  real_T c27_s_x;
  real_T c27_w_y;
  real_T c27_t_x;
  real_T c27_x_y;
  real_T c27_u_x;
  real_T c27_y_y;
  real_T c27_d2;
  real_T c27_h_A;
  real_T c27_h_B;
  real_T c27_v_x;
  real_T c27_ab_y;
  real_T c27_w_x;
  real_T c27_bb_y;
  real_T c27_x_x;
  real_T c27_cb_y;
  real_T c27_db_y;
  real_T c27_i_A;
  real_T c27_i_B;
  real_T c27_y_x;
  real_T c27_eb_y;
  real_T c27_ab_x;
  real_T c27_fb_y;
  real_T c27_bb_x;
  real_T c27_gb_y;
  real_T c27_hb_y;
  real_T c27_j_A;
  real_T c27_j_B;
  real_T c27_cb_x;
  real_T c27_ib_y;
  real_T c27_db_x;
  real_T c27_jb_y;
  real_T c27_eb_x;
  real_T c27_kb_y;
  real_T c27_d3;
  real_T c27_k_A;
  real_T c27_k_B;
  real_T c27_fb_x;
  real_T c27_lb_y;
  real_T c27_gb_x;
  real_T c27_mb_y;
  real_T c27_hb_x;
  real_T c27_nb_y;
  real_T c27_ob_y;
  real_T c27_l_A;
  real_T c27_l_B;
  real_T c27_ib_x;
  real_T c27_pb_y;
  real_T c27_jb_x;
  real_T c27_qb_y;
  real_T c27_kb_x;
  real_T c27_rb_y;
  real_T c27_sb_y;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 26U, chartInstance->c27_sfEvent);
  c27_b_s_x4.fl = *(real_T *)&((char_T *)chartInstance->c27_s_x4)[0];
  c27_b_s_x4.fr = *(real_T *)&((char_T *)chartInstance->c27_s_x4)[8];
  c27_b_s_x4.rl = *(real_T *)&((char_T *)chartInstance->c27_s_x4)[16];
  c27_b_s_x4.rr = *(real_T *)&((char_T *)chartInstance->c27_s_x4)[24];
  c27_b_s_y4.fl = *(real_T *)&((char_T *)chartInstance->c27_s_y4)[0];
  c27_b_s_y4.fr = *(real_T *)&((char_T *)chartInstance->c27_s_y4)[8];
  c27_b_s_y4.rl = *(real_T *)&((char_T *)chartInstance->c27_s_y4)[16];
  c27_b_s_y4.rr = *(real_T *)&((char_T *)chartInstance->c27_s_y4)[24];
  c27_b_s_xy4.fl = *(real_T *)&((char_T *)chartInstance->c27_s_xy4)[0];
  c27_b_s_xy4.fr = *(real_T *)&((char_T *)chartInstance->c27_s_xy4)[8];
  c27_b_s_xy4.rl = *(real_T *)&((char_T *)chartInstance->c27_s_xy4)[16];
  c27_b_s_xy4.rr = *(real_T *)&((char_T *)chartInstance->c27_s_xy4)[24];
  c27_b_F_xyw4.fl = *(real_T *)&((char_T *)chartInstance->c27_F_xyw4)[0];
  c27_b_F_xyw4.fr = *(real_T *)&((char_T *)chartInstance->c27_F_xyw4)[8];
  c27_b_F_xyw4.rl = *(real_T *)&((char_T *)chartInstance->c27_F_xyw4)[16];
  c27_b_F_xyw4.rr = *(real_T *)&((char_T *)chartInstance->c27_F_xyw4)[24];
  c27_b_F_z4_prev.fl = *(real_T *)&((char_T *)chartInstance->c27_F_z4_prev)[0];
  c27_b_F_z4_prev.fr = *(real_T *)&((char_T *)chartInstance->c27_F_z4_prev)[8];
  c27_b_F_z4_prev.rl = *(real_T *)&((char_T *)chartInstance->c27_F_z4_prev)[16];
  c27_b_F_z4_prev.rr = *(real_T *)&((char_T *)chartInstance->c27_F_z4_prev)[24];
  c27_b_Par = chartInstance->c27_Par;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 11U, 11U, c27_debug_family_names,
    c27_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c27_F_z4_temp, 0U, c27_d_sf_marshallOut,
    c27_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_nargin, 1U, c27_c_sf_marshallOut,
    c27_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_nargout, 2U, c27_c_sf_marshallOut,
    c27_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c27_b_s_x4, 3U, c27_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c27_b_s_y4, 4U, c27_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c27_b_s_xy4, 5U, c27_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c27_b_F_xyw4, 6U, c27_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c27_b_F_z4_prev, 7U, c27_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_b_Par, 8U, c27_b_sf_marshallOut,
    c27_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_b_F_xw4, 9U, c27_sf_marshallOut,
    c27_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_b_F_yw4, 10U, c27_sf_marshallOut,
    c27_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 4);
  c27_F_z4_temp[0] = c27_b_F_z4_prev.fl;
  c27_F_z4_temp[1] = c27_b_F_z4_prev.fr;
  c27_F_z4_temp[2] = c27_b_F_z4_prev.rl;
  c27_F_z4_temp[3] = c27_b_F_z4_prev.rr;
  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 7);
  c27_A = c27_b_Par.Env.mu;
  c27_B = c27_b_Par.Veh.C0;
  c27_x = c27_A;
  c27_y = c27_B;
  c27_b_x = c27_x;
  c27_b_y = c27_y;
  c27_c_x = c27_b_x;
  c27_c_y = c27_b_y;
  c27_d0 = c27_c_x / c27_c_y;
  if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c27_b_s_xy4.fl, c27_d0,
        -1, 4U, c27_b_s_xy4.fl > c27_d0))) {
    _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 8);
    c27_b_A = c27_b_s_x4.fl;
    c27_b_B = c27_b_s_xy4.fl;
    c27_d_x = c27_b_A;
    c27_d_y = c27_b_B;
    c27_e_x = c27_d_x;
    c27_e_y = c27_d_y;
    c27_f_x = c27_e_x;
    c27_f_y = c27_e_y;
    c27_g_y = c27_f_x / c27_f_y;
    c27_b_F_xw4.fl = c27_b_F_xyw4.fl * c27_g_y;
    _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 9);
    c27_c_A = -c27_b_s_y4.fl;
    c27_c_B = c27_b_s_xy4.fl;
    c27_g_x = c27_c_A;
    c27_h_y = c27_c_B;
    c27_h_x = c27_g_x;
    c27_i_y = c27_h_y;
    c27_i_x = c27_h_x;
    c27_j_y = c27_i_y;
    c27_k_y = c27_i_x / c27_j_y;
    c27_b_F_yw4.fl = c27_b_F_xyw4.fl * c27_k_y;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 11);
    c27_b_F_xw4.fl = c27_F_z4_temp[0] * c27_b_Par.Veh.C0 * c27_b_s_x4.fl;
    _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 12);
    c27_b_F_yw4.fl = -c27_F_z4_temp[0] * c27_b_Par.Veh.C0 * c27_b_s_y4.fl;
  }

  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 15);
  c27_d_A = c27_b_Par.Env.mu;
  c27_d_B = c27_b_Par.Veh.C0;
  c27_j_x = c27_d_A;
  c27_l_y = c27_d_B;
  c27_k_x = c27_j_x;
  c27_m_y = c27_l_y;
  c27_l_x = c27_k_x;
  c27_n_y = c27_m_y;
  c27_d1 = c27_l_x / c27_n_y;
  if (CV_EML_IF(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 1, c27_b_s_xy4.fr, c27_d1,
        -1, 4U, c27_b_s_xy4.fr > c27_d1))) {
    _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 16);
    c27_e_A = c27_b_s_x4.fr;
    c27_e_B = c27_b_s_xy4.fr;
    c27_m_x = c27_e_A;
    c27_o_y = c27_e_B;
    c27_n_x = c27_m_x;
    c27_p_y = c27_o_y;
    c27_o_x = c27_n_x;
    c27_q_y = c27_p_y;
    c27_r_y = c27_o_x / c27_q_y;
    c27_b_F_xw4.fr = c27_b_F_xyw4.fr * c27_r_y;
    _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 17);
    c27_f_A = -c27_b_s_y4.fr;
    c27_f_B = c27_b_s_xy4.fr;
    c27_p_x = c27_f_A;
    c27_s_y = c27_f_B;
    c27_q_x = c27_p_x;
    c27_t_y = c27_s_y;
    c27_r_x = c27_q_x;
    c27_u_y = c27_t_y;
    c27_v_y = c27_r_x / c27_u_y;
    c27_b_F_yw4.fr = c27_b_F_xyw4.fr * c27_v_y;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 19);
    c27_b_F_xw4.fr = c27_F_z4_temp[1] * c27_b_Par.Veh.C0 * c27_b_s_x4.fr;
    _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 20);
    c27_b_F_yw4.fr = -c27_F_z4_temp[1] * c27_b_Par.Veh.C0 * c27_b_s_y4.fr;
  }

  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 23);
  c27_g_A = c27_b_Par.Env.mu;
  c27_g_B = c27_b_Par.Veh.C0;
  c27_s_x = c27_g_A;
  c27_w_y = c27_g_B;
  c27_t_x = c27_s_x;
  c27_x_y = c27_w_y;
  c27_u_x = c27_t_x;
  c27_y_y = c27_x_y;
  c27_d2 = c27_u_x / c27_y_y;
  if (CV_EML_IF(0, 1, 2, CV_RELATIONAL_EVAL(4U, 0U, 2, c27_b_s_xy4.rl, c27_d2,
        -1, 4U, c27_b_s_xy4.rl > c27_d2))) {
    _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 24);
    c27_h_A = c27_b_s_x4.rl;
    c27_h_B = c27_b_s_xy4.rl;
    c27_v_x = c27_h_A;
    c27_ab_y = c27_h_B;
    c27_w_x = c27_v_x;
    c27_bb_y = c27_ab_y;
    c27_x_x = c27_w_x;
    c27_cb_y = c27_bb_y;
    c27_db_y = c27_x_x / c27_cb_y;
    c27_b_F_xw4.rl = c27_b_F_xyw4.rl * c27_db_y;
    _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 25);
    c27_i_A = -c27_b_s_y4.rl;
    c27_i_B = c27_b_s_xy4.rl;
    c27_y_x = c27_i_A;
    c27_eb_y = c27_i_B;
    c27_ab_x = c27_y_x;
    c27_fb_y = c27_eb_y;
    c27_bb_x = c27_ab_x;
    c27_gb_y = c27_fb_y;
    c27_hb_y = c27_bb_x / c27_gb_y;
    c27_b_F_yw4.rl = c27_b_F_xyw4.rl * c27_hb_y;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 27);
    c27_b_F_xw4.rl = c27_F_z4_temp[2] * c27_b_Par.Veh.C0 * c27_b_s_x4.rl;
    _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 28);
    c27_b_F_yw4.rl = -c27_F_z4_temp[2] * c27_b_Par.Veh.C0 * c27_b_s_y4.rl;
  }

  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 31);
  c27_j_A = c27_b_Par.Env.mu;
  c27_j_B = c27_b_Par.Veh.C0;
  c27_cb_x = c27_j_A;
  c27_ib_y = c27_j_B;
  c27_db_x = c27_cb_x;
  c27_jb_y = c27_ib_y;
  c27_eb_x = c27_db_x;
  c27_kb_y = c27_jb_y;
  c27_d3 = c27_eb_x / c27_kb_y;
  if (CV_EML_IF(0, 1, 3, CV_RELATIONAL_EVAL(4U, 0U, 3, c27_b_s_xy4.rr, c27_d3,
        -1, 4U, c27_b_s_xy4.rr > c27_d3))) {
    _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 32);
    c27_k_A = c27_b_s_x4.rr;
    c27_k_B = c27_b_s_xy4.rr;
    c27_fb_x = c27_k_A;
    c27_lb_y = c27_k_B;
    c27_gb_x = c27_fb_x;
    c27_mb_y = c27_lb_y;
    c27_hb_x = c27_gb_x;
    c27_nb_y = c27_mb_y;
    c27_ob_y = c27_hb_x / c27_nb_y;
    c27_b_F_xw4.rr = c27_b_F_xyw4.rr * c27_ob_y;
    _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 33);
    c27_l_A = -c27_b_s_y4.rr;
    c27_l_B = c27_b_s_xy4.rr;
    c27_ib_x = c27_l_A;
    c27_pb_y = c27_l_B;
    c27_jb_x = c27_ib_x;
    c27_qb_y = c27_pb_y;
    c27_kb_x = c27_jb_x;
    c27_rb_y = c27_qb_y;
    c27_sb_y = c27_kb_x / c27_rb_y;
    c27_b_F_yw4.rr = c27_b_F_xyw4.rr * c27_sb_y;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 35);
    c27_b_F_xw4.rr = c27_F_z4_temp[3] * c27_b_Par.Veh.C0 * c27_b_s_x4.rr;
    _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 36);
    c27_b_F_yw4.rr = -c27_F_z4_temp[3] * c27_b_Par.Veh.C0 * c27_b_s_y4.rr;
  }

  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, -36);
  _SFD_SYMBOL_SCOPE_POP();
  *(real_T *)&((char_T *)chartInstance->c27_F_xw4)[0] = c27_b_F_xw4.fl;
  *(real_T *)&((char_T *)chartInstance->c27_F_xw4)[8] = c27_b_F_xw4.fr;
  *(real_T *)&((char_T *)chartInstance->c27_F_xw4)[16] = c27_b_F_xw4.rl;
  *(real_T *)&((char_T *)chartInstance->c27_F_xw4)[24] = c27_b_F_xw4.rr;
  *(real_T *)&((char_T *)chartInstance->c27_F_yw4)[0] = c27_b_F_yw4.fl;
  *(real_T *)&((char_T *)chartInstance->c27_F_yw4)[8] = c27_b_F_yw4.fr;
  *(real_T *)&((char_T *)chartInstance->c27_F_yw4)[16] = c27_b_F_yw4.rl;
  *(real_T *)&((char_T *)chartInstance->c27_F_yw4)[24] = c27_b_F_yw4.rr;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 26U, chartInstance->c27_sfEvent);
}

static void initSimStructsc27_Modified(SFc27_ModifiedInstanceStruct
  *chartInstance)
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
  c27_whl_vec4 c27_u;
  const mxArray *c27_y = NULL;
  real_T c27_b_u;
  const mxArray *c27_b_y = NULL;
  real_T c27_c_u;
  const mxArray *c27_c_y = NULL;
  real_T c27_d_u;
  const mxArray *c27_d_y = NULL;
  real_T c27_e_u;
  const mxArray *c27_e_y = NULL;
  SFc27_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc27_ModifiedInstanceStruct *)chartInstanceVoid;
  c27_mxArrayOutData = NULL;
  c27_u = *(c27_whl_vec4 *)c27_inData;
  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c27_b_u = c27_u.fl;
  c27_b_y = NULL;
  sf_mex_assign(&c27_b_y, sf_mex_create("y", &c27_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c27_y, c27_b_y, "fl", "fl", 0);
  c27_c_u = c27_u.fr;
  c27_c_y = NULL;
  sf_mex_assign(&c27_c_y, sf_mex_create("y", &c27_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c27_y, c27_c_y, "fr", "fr", 0);
  c27_d_u = c27_u.rl;
  c27_d_y = NULL;
  sf_mex_assign(&c27_d_y, sf_mex_create("y", &c27_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c27_y, c27_d_y, "rl", "rl", 0);
  c27_e_u = c27_u.rr;
  c27_e_y = NULL;
  sf_mex_assign(&c27_e_y, sf_mex_create("y", &c27_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c27_y, c27_e_y, "rr", "rr", 0);
  sf_mex_assign(&c27_mxArrayOutData, c27_y, false);
  return c27_mxArrayOutData;
}

static c27_whl_vec4 c27_emlrt_marshallIn(SFc27_ModifiedInstanceStruct
  *chartInstance, const mxArray *c27_b_F_yw4, const char_T *c27_identifier)
{
  c27_whl_vec4 c27_y;
  emlrtMsgIdentifier c27_thisId;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_y = c27_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c27_b_F_yw4),
    &c27_thisId);
  sf_mex_destroy(&c27_b_F_yw4);
  return c27_y;
}

static c27_whl_vec4 c27_b_emlrt_marshallIn(SFc27_ModifiedInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId)
{
  c27_whl_vec4 c27_y;
  emlrtMsgIdentifier c27_thisId;
  static const char * c27_fieldNames[4] = { "fl", "fr", "rl", "rr" };

  c27_thisId.fParent = c27_parentId;
  sf_mex_check_struct(c27_parentId, c27_u, 4, c27_fieldNames, 0U, NULL);
  c27_thisId.fIdentifier = "fl";
  c27_y.fl = c27_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c27_u, "fl", "fl", 0)), &c27_thisId);
  c27_thisId.fIdentifier = "fr";
  c27_y.fr = c27_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c27_u, "fr", "fr", 0)), &c27_thisId);
  c27_thisId.fIdentifier = "rl";
  c27_y.rl = c27_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c27_u, "rl", "rl", 0)), &c27_thisId);
  c27_thisId.fIdentifier = "rr";
  c27_y.rr = c27_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c27_u, "rr", "rr", 0)), &c27_thisId);
  sf_mex_destroy(&c27_u);
  return c27_y;
}

static real_T c27_c_emlrt_marshallIn(SFc27_ModifiedInstanceStruct *chartInstance,
  const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId)
{
  real_T c27_y;
  real_T c27_d4;
  (void)chartInstance;
  sf_mex_import(c27_parentId, sf_mex_dup(c27_u), &c27_d4, 1, 0, 0U, 0, 0U, 0);
  c27_y = c27_d4;
  sf_mex_destroy(&c27_u);
  return c27_y;
}

static void c27_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData)
{
  const mxArray *c27_b_F_yw4;
  const char_T *c27_identifier;
  emlrtMsgIdentifier c27_thisId;
  c27_whl_vec4 c27_y;
  SFc27_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc27_ModifiedInstanceStruct *)chartInstanceVoid;
  c27_b_F_yw4 = sf_mex_dup(c27_mxArrayInData);
  c27_identifier = c27_varName;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_y = c27_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c27_b_F_yw4),
    &c27_thisId);
  sf_mex_destroy(&c27_b_F_yw4);
  *(c27_whl_vec4 *)c27_outData = c27_y;
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
  int32_T c27_i0;
  real_T c27_cb_u[4];
  const mxArray *c27_gb_y = NULL;
  real_T c27_db_u;
  const mxArray *c27_hb_y = NULL;
  c27_struct_ZKAzdrl7umDGJoC14aoVKC c27_eb_u;
  const mxArray *c27_ib_y = NULL;
  int32_T c27_i1;
  real_T c27_fb_u[3];
  const mxArray *c27_jb_y = NULL;
  int32_T c27_i2;
  real_T c27_gb_u[3];
  const mxArray *c27_kb_y = NULL;
  int32_T c27_i3;
  real_T c27_hb_u[3];
  const mxArray *c27_lb_y = NULL;
  int32_T c27_i4;
  real_T c27_ib_u[3];
  const mxArray *c27_mb_y = NULL;
  const mxArray *c27_nb_y = NULL;
  int32_T c27_i5;
  real_T c27_jb_u[3];
  const mxArray *c27_ob_y = NULL;
  int32_T c27_i6;
  real_T c27_kb_u[3];
  const mxArray *c27_pb_y = NULL;
  int32_T c27_i7;
  real_T c27_lb_u[3];
  const mxArray *c27_qb_y = NULL;
  int32_T c27_i8;
  real_T c27_mb_u[3];
  const mxArray *c27_rb_y = NULL;
  const mxArray *c27_sb_y = NULL;
  int32_T c27_i9;
  real_T c27_nb_u[3];
  const mxArray *c27_tb_y = NULL;
  int32_T c27_i10;
  real_T c27_ob_u[3];
  const mxArray *c27_ub_y = NULL;
  int32_T c27_i11;
  real_T c27_pb_u[3];
  const mxArray *c27_vb_y = NULL;
  int32_T c27_i12;
  real_T c27_qb_u[3];
  const mxArray *c27_wb_y = NULL;
  const mxArray *c27_xb_y = NULL;
  int32_T c27_i13;
  real_T c27_rb_u[3];
  const mxArray *c27_yb_y = NULL;
  int32_T c27_i14;
  real_T c27_sb_u[3];
  const mxArray *c27_ac_y = NULL;
  int32_T c27_i15;
  real_T c27_tb_u[3];
  const mxArray *c27_bc_y = NULL;
  int32_T c27_i16;
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
  SFc27_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc27_ModifiedInstanceStruct *)chartInstanceVoid;
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
  for (c27_i0 = 0; c27_i0 < 4; c27_i0++) {
    c27_cb_u[c27_i0] = c27_p_u.F_z4_static[c27_i0];
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
  for (c27_i1 = 0; c27_i1 < 3; c27_i1++) {
    c27_fb_u[c27_i1] = c27_eb_u.fl[c27_i1];
  }

  c27_jb_y = NULL;
  sf_mex_assign(&c27_jb_y, sf_mex_create("y", c27_fb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c27_ib_y, c27_jb_y, "fl", "fl", 0);
  for (c27_i2 = 0; c27_i2 < 3; c27_i2++) {
    c27_gb_u[c27_i2] = c27_eb_u.fr[c27_i2];
  }

  c27_kb_y = NULL;
  sf_mex_assign(&c27_kb_y, sf_mex_create("y", c27_gb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c27_ib_y, c27_kb_y, "fr", "fr", 0);
  for (c27_i3 = 0; c27_i3 < 3; c27_i3++) {
    c27_hb_u[c27_i3] = c27_eb_u.rl[c27_i3];
  }

  c27_lb_y = NULL;
  sf_mex_assign(&c27_lb_y, sf_mex_create("y", c27_hb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c27_ib_y, c27_lb_y, "rl", "rl", 0);
  for (c27_i4 = 0; c27_i4 < 3; c27_i4++) {
    c27_ib_u[c27_i4] = c27_eb_u.rr[c27_i4];
  }

  c27_mb_y = NULL;
  sf_mex_assign(&c27_mb_y, sf_mex_create("y", c27_ib_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c27_ib_y, c27_mb_y, "rr", "rr", 0);
  sf_mex_addfield(c27_t_y, c27_ib_y, "r_long", "r_long", 0);
  c27_eb_u = c27_p_u.r_lat;
  c27_nb_y = NULL;
  sf_mex_assign(&c27_nb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c27_i5 = 0; c27_i5 < 3; c27_i5++) {
    c27_jb_u[c27_i5] = c27_eb_u.fl[c27_i5];
  }

  c27_ob_y = NULL;
  sf_mex_assign(&c27_ob_y, sf_mex_create("y", c27_jb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c27_nb_y, c27_ob_y, "fl", "fl", 0);
  for (c27_i6 = 0; c27_i6 < 3; c27_i6++) {
    c27_kb_u[c27_i6] = c27_eb_u.fr[c27_i6];
  }

  c27_pb_y = NULL;
  sf_mex_assign(&c27_pb_y, sf_mex_create("y", c27_kb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c27_nb_y, c27_pb_y, "fr", "fr", 0);
  for (c27_i7 = 0; c27_i7 < 3; c27_i7++) {
    c27_lb_u[c27_i7] = c27_eb_u.rl[c27_i7];
  }

  c27_qb_y = NULL;
  sf_mex_assign(&c27_qb_y, sf_mex_create("y", c27_lb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c27_nb_y, c27_qb_y, "rl", "rl", 0);
  for (c27_i8 = 0; c27_i8 < 3; c27_i8++) {
    c27_mb_u[c27_i8] = c27_eb_u.rr[c27_i8];
  }

  c27_rb_y = NULL;
  sf_mex_assign(&c27_rb_y, sf_mex_create("y", c27_mb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c27_nb_y, c27_rb_y, "rr", "rr", 0);
  sf_mex_addfield(c27_t_y, c27_nb_y, "r_lat", "r_lat", 0);
  c27_eb_u = c27_p_u.r_lever;
  c27_sb_y = NULL;
  sf_mex_assign(&c27_sb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c27_i9 = 0; c27_i9 < 3; c27_i9++) {
    c27_nb_u[c27_i9] = c27_eb_u.fl[c27_i9];
  }

  c27_tb_y = NULL;
  sf_mex_assign(&c27_tb_y, sf_mex_create("y", c27_nb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c27_sb_y, c27_tb_y, "fl", "fl", 0);
  for (c27_i10 = 0; c27_i10 < 3; c27_i10++) {
    c27_ob_u[c27_i10] = c27_eb_u.fr[c27_i10];
  }

  c27_ub_y = NULL;
  sf_mex_assign(&c27_ub_y, sf_mex_create("y", c27_ob_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c27_sb_y, c27_ub_y, "fr", "fr", 0);
  for (c27_i11 = 0; c27_i11 < 3; c27_i11++) {
    c27_pb_u[c27_i11] = c27_eb_u.rl[c27_i11];
  }

  c27_vb_y = NULL;
  sf_mex_assign(&c27_vb_y, sf_mex_create("y", c27_pb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c27_sb_y, c27_vb_y, "rl", "rl", 0);
  for (c27_i12 = 0; c27_i12 < 3; c27_i12++) {
    c27_qb_u[c27_i12] = c27_eb_u.rr[c27_i12];
  }

  c27_wb_y = NULL;
  sf_mex_assign(&c27_wb_y, sf_mex_create("y", c27_qb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c27_sb_y, c27_wb_y, "rr", "rr", 0);
  sf_mex_addfield(c27_t_y, c27_sb_y, "r_lever", "r_lever", 0);
  c27_eb_u = c27_p_u.r_pivot;
  c27_xb_y = NULL;
  sf_mex_assign(&c27_xb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c27_i13 = 0; c27_i13 < 3; c27_i13++) {
    c27_rb_u[c27_i13] = c27_eb_u.fl[c27_i13];
  }

  c27_yb_y = NULL;
  sf_mex_assign(&c27_yb_y, sf_mex_create("y", c27_rb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c27_xb_y, c27_yb_y, "fl", "fl", 0);
  for (c27_i14 = 0; c27_i14 < 3; c27_i14++) {
    c27_sb_u[c27_i14] = c27_eb_u.fr[c27_i14];
  }

  c27_ac_y = NULL;
  sf_mex_assign(&c27_ac_y, sf_mex_create("y", c27_sb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c27_xb_y, c27_ac_y, "fr", "fr", 0);
  for (c27_i15 = 0; c27_i15 < 3; c27_i15++) {
    c27_tb_u[c27_i15] = c27_eb_u.rl[c27_i15];
  }

  c27_bc_y = NULL;
  sf_mex_assign(&c27_bc_y, sf_mex_create("y", c27_tb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c27_xb_y, c27_bc_y, "rl", "rl", 0);
  for (c27_i16 = 0; c27_i16 < 3; c27_i16++) {
    c27_ub_u[c27_i16] = c27_eb_u.rr[c27_i16];
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

static void c27_d_emlrt_marshallIn(SFc27_ModifiedInstanceStruct *chartInstance,
  const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId,
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

static void c27_e_emlrt_marshallIn(SFc27_ModifiedInstanceStruct *chartInstance,
  const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId,
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
  (SFc27_ModifiedInstanceStruct *chartInstance, const mxArray *c27_u, const
   emlrtMsgIdentifier *c27_parentId)
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

static void c27_g_emlrt_marshallIn(SFc27_ModifiedInstanceStruct *chartInstance,
  const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId,
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

static void c27_h_emlrt_marshallIn(SFc27_ModifiedInstanceStruct *chartInstance,
  const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId, real_T c27_y[4])
{
  real_T c27_dv0[4];
  int32_T c27_i17;
  (void)chartInstance;
  sf_mex_import(c27_parentId, sf_mex_dup(c27_u), c27_dv0, 1, 0, 0U, 1, 0U, 2, 1,
                4);
  for (c27_i17 = 0; c27_i17 < 4; c27_i17++) {
    c27_y[c27_i17] = c27_dv0[c27_i17];
  }

  sf_mex_destroy(&c27_u);
}

static void c27_i_emlrt_marshallIn(SFc27_ModifiedInstanceStruct *chartInstance,
  const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId,
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

static void c27_j_emlrt_marshallIn(SFc27_ModifiedInstanceStruct *chartInstance,
  const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId, real_T c27_y[3])
{
  real_T c27_dv1[3];
  int32_T c27_i18;
  (void)chartInstance;
  sf_mex_import(c27_parentId, sf_mex_dup(c27_u), c27_dv1, 1, 0, 0U, 1, 0U, 2, 3,
                1);
  for (c27_i18 = 0; c27_i18 < 3; c27_i18++) {
    c27_y[c27_i18] = c27_dv1[c27_i18];
  }

  sf_mex_destroy(&c27_u);
}

static c27_struct_r4FNviKwHfdhB8nQjvQv9 c27_k_emlrt_marshallIn
  (SFc27_ModifiedInstanceStruct *chartInstance, const mxArray *c27_u, const
   emlrtMsgIdentifier *c27_parentId)
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
  (SFc27_ModifiedInstanceStruct *chartInstance, const mxArray *c27_u, const
   emlrtMsgIdentifier *c27_parentId)
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
  SFc27_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc27_ModifiedInstanceStruct *)chartInstanceVoid;
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
  real_T c27_u;
  const mxArray *c27_y = NULL;
  SFc27_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc27_ModifiedInstanceStruct *)chartInstanceVoid;
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
  SFc27_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc27_ModifiedInstanceStruct *)chartInstanceVoid;
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

static const mxArray *c27_d_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData)
{
  const mxArray *c27_mxArrayOutData = NULL;
  int32_T c27_i19;
  real_T c27_b_inData[4];
  int32_T c27_i20;
  real_T c27_u[4];
  const mxArray *c27_y = NULL;
  SFc27_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc27_ModifiedInstanceStruct *)chartInstanceVoid;
  c27_mxArrayOutData = NULL;
  for (c27_i19 = 0; c27_i19 < 4; c27_i19++) {
    c27_b_inData[c27_i19] = (*(real_T (*)[4])c27_inData)[c27_i19];
  }

  for (c27_i20 = 0; c27_i20 < 4; c27_i20++) {
    c27_u[c27_i20] = c27_b_inData[c27_i20];
  }

  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", c27_u, 0, 0U, 1U, 0U, 1, 4), false);
  sf_mex_assign(&c27_mxArrayOutData, c27_y, false);
  return c27_mxArrayOutData;
}

static void c27_m_emlrt_marshallIn(SFc27_ModifiedInstanceStruct *chartInstance,
  const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId, real_T c27_y[4])
{
  real_T c27_dv2[4];
  int32_T c27_i21;
  (void)chartInstance;
  sf_mex_import(c27_parentId, sf_mex_dup(c27_u), c27_dv2, 1, 0, 0U, 1, 0U, 1, 4);
  for (c27_i21 = 0; c27_i21 < 4; c27_i21++) {
    c27_y[c27_i21] = c27_dv2[c27_i21];
  }

  sf_mex_destroy(&c27_u);
}

static void c27_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData)
{
  const mxArray *c27_F_z4_temp;
  const char_T *c27_identifier;
  emlrtMsgIdentifier c27_thisId;
  real_T c27_y[4];
  int32_T c27_i22;
  SFc27_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc27_ModifiedInstanceStruct *)chartInstanceVoid;
  c27_F_z4_temp = sf_mex_dup(c27_mxArrayInData);
  c27_identifier = c27_varName;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c27_F_z4_temp), &c27_thisId,
    c27_y);
  sf_mex_destroy(&c27_F_z4_temp);
  for (c27_i22 = 0; c27_i22 < 4; c27_i22++) {
    (*(real_T (*)[4])c27_outData)[c27_i22] = c27_y[c27_i22];
  }

  sf_mex_destroy(&c27_mxArrayInData);
}

const mxArray *sf_c27_Modified_get_eml_resolved_functions_info(void)
{
  const mxArray *c27_nameCaptureInfo = NULL;
  c27_nameCaptureInfo = NULL;
  sf_mex_assign(&c27_nameCaptureInfo, sf_mex_createstruct("structure", 2, 7, 1),
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
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("mrdivide"), "name", "name",
                  0);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410807648U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1370009886U), "mFileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1389717774U), "fileTimeLo",
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
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("rdivide"), "name", "name", 2);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1363713880U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
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
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 4);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_div"), "name", "name", 5);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1386423952U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 6);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
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

static const mxArray *c27_e_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData)
{
  const mxArray *c27_mxArrayOutData = NULL;
  int32_T c27_u;
  const mxArray *c27_y = NULL;
  SFc27_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc27_ModifiedInstanceStruct *)chartInstanceVoid;
  c27_mxArrayOutData = NULL;
  c27_u = *(int32_T *)c27_inData;
  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", &c27_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c27_mxArrayOutData, c27_y, false);
  return c27_mxArrayOutData;
}

static int32_T c27_n_emlrt_marshallIn(SFc27_ModifiedInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId)
{
  int32_T c27_y;
  int32_T c27_i23;
  (void)chartInstance;
  sf_mex_import(c27_parentId, sf_mex_dup(c27_u), &c27_i23, 1, 6, 0U, 0, 0U, 0);
  c27_y = c27_i23;
  sf_mex_destroy(&c27_u);
  return c27_y;
}

static void c27_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData)
{
  const mxArray *c27_b_sfEvent;
  const char_T *c27_identifier;
  emlrtMsgIdentifier c27_thisId;
  int32_T c27_y;
  SFc27_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc27_ModifiedInstanceStruct *)chartInstanceVoid;
  c27_b_sfEvent = sf_mex_dup(c27_mxArrayInData);
  c27_identifier = c27_varName;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_y = c27_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c27_b_sfEvent),
    &c27_thisId);
  sf_mex_destroy(&c27_b_sfEvent);
  *(int32_T *)c27_outData = c27_y;
  sf_mex_destroy(&c27_mxArrayInData);
}

static const mxArray *c27_s_x4_bus_io(void *chartInstanceVoid, void *c27_pData)
{
  const mxArray *c27_mxVal = NULL;
  c27_whl_vec4 c27_tmp;
  SFc27_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc27_ModifiedInstanceStruct *)chartInstanceVoid;
  c27_mxVal = NULL;
  c27_tmp.fl = *(real_T *)&((char_T *)(c27_whl_vec4 *)c27_pData)[0];
  c27_tmp.fr = *(real_T *)&((char_T *)(c27_whl_vec4 *)c27_pData)[8];
  c27_tmp.rl = *(real_T *)&((char_T *)(c27_whl_vec4 *)c27_pData)[16];
  c27_tmp.rr = *(real_T *)&((char_T *)(c27_whl_vec4 *)c27_pData)[24];
  sf_mex_assign(&c27_mxVal, c27_sf_marshallOut(chartInstance, &c27_tmp), false);
  return c27_mxVal;
}

static uint8_T c27_o_emlrt_marshallIn(SFc27_ModifiedInstanceStruct
  *chartInstance, const mxArray *c27_b_is_active_c27_Modified, const char_T
  *c27_identifier)
{
  uint8_T c27_y;
  emlrtMsgIdentifier c27_thisId;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_y = c27_p_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c27_b_is_active_c27_Modified), &c27_thisId);
  sf_mex_destroy(&c27_b_is_active_c27_Modified);
  return c27_y;
}

static uint8_T c27_p_emlrt_marshallIn(SFc27_ModifiedInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId)
{
  uint8_T c27_y;
  uint8_T c27_u0;
  (void)chartInstance;
  sf_mex_import(c27_parentId, sf_mex_dup(c27_u), &c27_u0, 1, 3, 0U, 0, 0U, 0);
  c27_y = c27_u0;
  sf_mex_destroy(&c27_u);
  return c27_y;
}

static void init_dsm_address_info(SFc27_ModifiedInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc27_ModifiedInstanceStruct *chartInstance)
{
  chartInstance->c27_s_x4 = (c27_whl_vec4 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c27_s_y4 = (c27_whl_vec4 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c27_s_xy4 = (c27_whl_vec4 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c27_F_xyw4 = (c27_whl_vec4 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c27_F_z4_prev = (c27_whl_vec4 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c27_F_xw4 = (c27_whl_vec4 *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c27_F_yw4 = (c27_whl_vec4 *)ssGetOutputPortSignal_wrapper
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

void sf_c27_Modified_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(859601713U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2845577817U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(972611446U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(192564767U);
}

mxArray* sf_c27_Modified_get_post_codegen_info(void);
mxArray *sf_c27_Modified_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("aVDperqwIDDlHOIilj6ZNB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
    mxArray* mxPostCodegenInfo = sf_c27_Modified_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c27_Modified_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c27_Modified_jit_fallback_info(void)
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

mxArray *sf_c27_Modified_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c27_Modified_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c27_Modified(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[49],T\"F_xw4\",},{M[1],M[50],T\"F_yw4\",},{M[8],M[0],T\"is_active_c27_Modified\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c27_Modified_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc27_ModifiedInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc27_ModifiedInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ModifiedMachineNumber_,
           27,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"s_x4");
          _SFD_SET_DATA_PROPS(1,1,1,0,"s_y4");
          _SFD_SET_DATA_PROPS(2,1,1,0,"s_xy4");
          _SFD_SET_DATA_PROPS(3,1,1,0,"F_xyw4");
          _SFD_SET_DATA_PROPS(4,1,1,0,"F_z4_prev");
          _SFD_SET_DATA_PROPS(5,2,0,1,"F_xw4");
          _SFD_SET_DATA_PROPS(6,2,0,1,"F_yw4");
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
        _SFD_CV_INIT_EML(0,1,1,4,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,2655);
        _SFD_CV_INIT_EML_IF(0,1,0,268,301,390,565);
        _SFD_CV_INIT_EML_IF(0,1,1,567,600,689,791);
        _SFD_CV_INIT_EML_IF(0,1,2,793,826,915,1017);
        _SFD_CV_INIT_EML_IF(0,1,3,1019,1052,1141,1243);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,271,301,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,570,600,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,2,796,826,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,3,1022,1052,-1,4);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c27_s_x4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c27_s_x4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c27_s_x4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c27_s_x4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c27_s_x4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c27_s_x4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c27_s_x4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c27_b_sf_marshallOut,(MexInFcnForType)
          c27_b_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c27_s_x4);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c27_s_y4);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c27_s_xy4);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c27_F_xyw4);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c27_F_z4_prev);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c27_F_xw4);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c27_F_yw4);
        _SFD_SET_DATA_VALUE_PTR(7U, &chartInstance->c27_Par);
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
  return "CdMwZd5ZINXTTrKHPqfMxC";
}

static void sf_opaque_initialize_c27_Modified(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc27_ModifiedInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c27_Modified((SFc27_ModifiedInstanceStruct*)
    chartInstanceVar);
  initialize_c27_Modified((SFc27_ModifiedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c27_Modified(void *chartInstanceVar)
{
  enable_c27_Modified((SFc27_ModifiedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c27_Modified(void *chartInstanceVar)
{
  disable_c27_Modified((SFc27_ModifiedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c27_Modified(void *chartInstanceVar)
{
  sf_gateway_c27_Modified((SFc27_ModifiedInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c27_Modified(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c27_Modified((SFc27_ModifiedInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c27_Modified(SimStruct* S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c27_Modified((SFc27_ModifiedInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c27_Modified(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc27_ModifiedInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Modified_optimization_info();
    }

    finalize_c27_Modified((SFc27_ModifiedInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc27_Modified((SFc27_ModifiedInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c27_Modified(SimStruct *S)
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
    initialize_params_c27_Modified((SFc27_ModifiedInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c27_Modified(SimStruct *S)
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
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,27,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,27,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 5; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,27);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(769294432U));
  ssSetChecksum1(S,(958749773U));
  ssSetChecksum2(S,(4280547213U));
  ssSetChecksum3(S,(3836468109U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c27_Modified(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c27_Modified(SimStruct *S)
{
  SFc27_ModifiedInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc27_ModifiedInstanceStruct *)utMalloc(sizeof
    (SFc27_ModifiedInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc27_ModifiedInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c27_Modified;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c27_Modified;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c27_Modified;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c27_Modified;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c27_Modified;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c27_Modified;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c27_Modified;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c27_Modified;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c27_Modified;
  chartInstance->chartInfo.mdlStart = mdlStart_c27_Modified;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c27_Modified;
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

void c27_Modified_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c27_Modified(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c27_Modified(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c27_Modified(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c27_Modified_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
