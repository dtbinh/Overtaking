/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Modified_sfun.h"
#include "c23_Modified.h"
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
static const char * c23_debug_family_names[9] = { "d1", "d2", "d3", "d4",
  "nargin", "nargout", "v_z4", "Par", "F_d4" };

/* Function Declarations */
static void initialize_c23_Modified(SFc23_ModifiedInstanceStruct *chartInstance);
static void initialize_params_c23_Modified(SFc23_ModifiedInstanceStruct
  *chartInstance);
static void enable_c23_Modified(SFc23_ModifiedInstanceStruct *chartInstance);
static void disable_c23_Modified(SFc23_ModifiedInstanceStruct *chartInstance);
static void c23_update_debugger_state_c23_Modified(SFc23_ModifiedInstanceStruct *
  chartInstance);
static const mxArray *get_sim_state_c23_Modified(SFc23_ModifiedInstanceStruct
  *chartInstance);
static void set_sim_state_c23_Modified(SFc23_ModifiedInstanceStruct
  *chartInstance, const mxArray *c23_st);
static void finalize_c23_Modified(SFc23_ModifiedInstanceStruct *chartInstance);
static void sf_gateway_c23_Modified(SFc23_ModifiedInstanceStruct *chartInstance);
static void mdl_start_c23_Modified(SFc23_ModifiedInstanceStruct *chartInstance);
static void initSimStructsc23_Modified(SFc23_ModifiedInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c23_machineNumber, uint32_T
  c23_chartNumber, uint32_T c23_instanceNumber);
static const mxArray *c23_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static c23_whl_vec4 c23_emlrt_marshallIn(SFc23_ModifiedInstanceStruct
  *chartInstance, const mxArray *c23_b_F_d4, const char_T *c23_identifier);
static c23_whl_vec4 c23_b_emlrt_marshallIn(SFc23_ModifiedInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId);
static real_T c23_c_emlrt_marshallIn(SFc23_ModifiedInstanceStruct *chartInstance,
  const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId);
static void c23_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData);
static const mxArray *c23_b_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static void c23_d_emlrt_marshallIn(SFc23_ModifiedInstanceStruct *chartInstance,
  const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId,
  c23_struct_iBlsPBO3AGnt69vDoTx5zD *c23_y);
static void c23_e_emlrt_marshallIn(SFc23_ModifiedInstanceStruct *chartInstance,
  const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId,
  c23_struct_Nst2vGTExxHsg85EUOj9EH *c23_y);
static c23_struct_HhckT6rntEraqECYVIDvCC c23_f_emlrt_marshallIn
  (SFc23_ModifiedInstanceStruct *chartInstance, const mxArray *c23_u, const
   emlrtMsgIdentifier *c23_parentId);
static void c23_g_emlrt_marshallIn(SFc23_ModifiedInstanceStruct *chartInstance,
  const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId,
  c23_struct_ZCmOWPuqBDw16FSOVVD00 *c23_y);
static void c23_h_emlrt_marshallIn(SFc23_ModifiedInstanceStruct *chartInstance,
  const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId, real_T c23_y[4]);
static void c23_i_emlrt_marshallIn(SFc23_ModifiedInstanceStruct *chartInstance,
  const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId,
  c23_struct_ZKAzdrl7umDGJoC14aoVKC *c23_y);
static void c23_j_emlrt_marshallIn(SFc23_ModifiedInstanceStruct *chartInstance,
  const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId, real_T c23_y[3]);
static c23_struct_r4FNviKwHfdhB8nQjvQv9 c23_k_emlrt_marshallIn
  (SFc23_ModifiedInstanceStruct *chartInstance, const mxArray *c23_u, const
   emlrtMsgIdentifier *c23_parentId);
static c23_struct_Y9F1qlBi9AhssksPwemA4G c23_l_emlrt_marshallIn
  (SFc23_ModifiedInstanceStruct *chartInstance, const mxArray *c23_u, const
   emlrtMsgIdentifier *c23_parentId);
static void c23_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData);
static const mxArray *c23_c_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static void c23_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData);
static const mxArray *c23_d_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static int32_T c23_m_emlrt_marshallIn(SFc23_ModifiedInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId);
static void c23_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData);
static const mxArray *c23_v_z4_bus_io(void *chartInstanceVoid, void *c23_pData);
static uint8_T c23_n_emlrt_marshallIn(SFc23_ModifiedInstanceStruct
  *chartInstance, const mxArray *c23_b_is_active_c23_Modified, const char_T
  *c23_identifier);
static uint8_T c23_o_emlrt_marshallIn(SFc23_ModifiedInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId);
static void init_dsm_address_info(SFc23_ModifiedInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc23_ModifiedInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c23_Modified(SFc23_ModifiedInstanceStruct *chartInstance)
{
  chartInstance->c23_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c23_is_active_c23_Modified = 0U;
}

static void initialize_params_c23_Modified(SFc23_ModifiedInstanceStruct
  *chartInstance)
{
  const mxArray *c23_m0 = NULL;
  const mxArray *c23_mxField;
  const mxArray *c23_m1 = NULL;
  const mxArray *c23_b_mxField;
  c23_struct_iBlsPBO3AGnt69vDoTx5zD c23_r0;
  const mxArray *c23_m2 = NULL;
  const mxArray *c23_c_mxField;
  const mxArray *c23_m3 = NULL;
  const mxArray *c23_d_mxField;
  const mxArray *c23_m4 = NULL;
  const mxArray *c23_e_mxField;
  const mxArray *c23_m5 = NULL;
  const mxArray *c23_f_mxField;
  const mxArray *c23_m6 = NULL;
  const mxArray *c23_g_mxField;
  const mxArray *c23_m7 = NULL;
  const mxArray *c23_h_mxField;
  const mxArray *c23_m8 = NULL;
  const mxArray *c23_i_mxField;
  const mxArray *c23_m9 = NULL;
  const mxArray *c23_j_mxField;
  const mxArray *c23_m10 = NULL;
  const mxArray *c23_k_mxField;
  const mxArray *c23_m11 = NULL;
  const mxArray *c23_l_mxField;
  const mxArray *c23_m12 = NULL;
  const mxArray *c23_m_mxField;
  const mxArray *c23_m13 = NULL;
  const mxArray *c23_n_mxField;
  c23_m0 = sf_mex_get_sfun_param(chartInstance->S, 0, 1);
  c23_mxField = sf_mex_getfield(c23_m0, "Env", "Par", 0);
  c23_m1 = sf_mex_dup(c23_mxField);
  c23_b_mxField = sf_mex_getfield(c23_m1, "g", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_b_mxField), &c23_r0.Env.g, 1, 0, 0U,
                      0, 0U, 0);
  c23_b_mxField = sf_mex_getfield(c23_m1, "left1", "Par", 0);
  c23_m2 = sf_mex_dup(c23_b_mxField);
  c23_c_mxField = sf_mex_getfield(c23_m2, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_c_mxField), &c23_r0.Env.left1.x, 1,
                      0, 0U, 0, 0U, 0);
  c23_c_mxField = sf_mex_getfield(c23_m2, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_c_mxField), &c23_r0.Env.left1.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c23_m2);
  c23_b_mxField = sf_mex_getfield(c23_m1, "right1", "Par", 0);
  c23_m3 = sf_mex_dup(c23_b_mxField);
  c23_d_mxField = sf_mex_getfield(c23_m3, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_d_mxField), &c23_r0.Env.right1.x, 1,
                      0, 0U, 0, 0U, 0);
  c23_d_mxField = sf_mex_getfield(c23_m3, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_d_mxField), &c23_r0.Env.right1.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c23_m3);
  c23_b_mxField = sf_mex_getfield(c23_m1, "right2", "Par", 0);
  c23_m4 = sf_mex_dup(c23_b_mxField);
  c23_e_mxField = sf_mex_getfield(c23_m4, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_e_mxField), &c23_r0.Env.right2.x, 1,
                      0, 0U, 0, 0U, 0);
  c23_e_mxField = sf_mex_getfield(c23_m4, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_e_mxField), &c23_r0.Env.right2.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c23_m4);
  c23_b_mxField = sf_mex_getfield(c23_m1, "left2", "Par", 0);
  c23_m5 = sf_mex_dup(c23_b_mxField);
  c23_f_mxField = sf_mex_getfield(c23_m5, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_f_mxField), &c23_r0.Env.left2.x, 1,
                      0, 0U, 0, 0U, 0);
  c23_f_mxField = sf_mex_getfield(c23_m5, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_f_mxField), &c23_r0.Env.left2.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c23_m5);
  c23_b_mxField = sf_mex_getfield(c23_m1, "right3", "Par", 0);
  c23_m6 = sf_mex_dup(c23_b_mxField);
  c23_g_mxField = sf_mex_getfield(c23_m6, "x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_g_mxField), &c23_r0.Env.right3.x, 1,
                      0, 0U, 0, 0U, 0);
  c23_g_mxField = sf_mex_getfield(c23_m6, "y", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_g_mxField), &c23_r0.Env.right3.y, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c23_m6);
  c23_b_mxField = sf_mex_getfield(c23_m1, "mu", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_b_mxField), &c23_r0.Env.mu, 1, 0, 0U,
                      0, 0U, 0);
  sf_mex_destroy(&c23_m1);
  c23_mxField = sf_mex_getfield(c23_m0, "Veh", "Par", 0);
  c23_m7 = sf_mex_dup(c23_mxField);
  c23_h_mxField = sf_mex_getfield(c23_m7, "m", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_h_mxField), &c23_r0.Veh.m, 1, 0, 0U,
                      0, 0U, 0);
  c23_h_mxField = sf_mex_getfield(c23_m7, "Jz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_h_mxField), &c23_r0.Veh.Jz, 1, 0, 0U,
                      0, 0U, 0);
  c23_h_mxField = sf_mex_getfield(c23_m7, "m_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_h_mxField), &c23_r0.Veh.m_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c23_h_mxField = sf_mex_getfield(c23_m7, "Jx_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_h_mxField), &c23_r0.Veh.Jx_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c23_h_mxField = sf_mex_getfield(c23_m7, "Jy_sprung", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_h_mxField), &c23_r0.Veh.Jy_sprung, 1,
                      0, 0U, 0, 0U, 0);
  c23_h_mxField = sf_mex_getfield(c23_m7, "lf", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_h_mxField), &c23_r0.Veh.lf, 1, 0, 0U,
                      0, 0U, 0);
  c23_h_mxField = sf_mex_getfield(c23_m7, "lr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_h_mxField), &c23_r0.Veh.lr, 1, 0, 0U,
                      0, 0U, 0);
  c23_h_mxField = sf_mex_getfield(c23_m7, "L", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_h_mxField), &c23_r0.Veh.L, 1, 0, 0U,
                      0, 0U, 0);
  c23_h_mxField = sf_mex_getfield(c23_m7, "TrackWidth", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_h_mxField), &c23_r0.Veh.TrackWidth,
                      1, 0, 0U, 0, 0U, 0);
  c23_h_mxField = sf_mex_getfield(c23_m7, "h", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_h_mxField), &c23_r0.Veh.h, 1, 0, 0U,
                      0, 0U, 0);
  c23_h_mxField = sf_mex_getfield(c23_m7, "HalfRohACd", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_h_mxField), &c23_r0.Veh.HalfRohACd,
                      1, 0, 0U, 0, 0U, 0);
  c23_h_mxField = sf_mex_getfield(c23_m7, "F_z4_static", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_h_mxField), c23_r0.Veh.F_z4_static,
                      1, 0, 0U, 1, 0U, 2, 1, 4);
  c23_h_mxField = sf_mex_getfield(c23_m7, "Rw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_h_mxField), &c23_r0.Veh.Rw, 1, 0, 0U,
                      0, 0U, 0);
  c23_h_mxField = sf_mex_getfield(c23_m7, "r_long", "Par", 0);
  c23_m8 = sf_mex_dup(c23_h_mxField);
  c23_i_mxField = sf_mex_getfield(c23_m8, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_i_mxField), c23_r0.Veh.r_long.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c23_i_mxField = sf_mex_getfield(c23_m8, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_i_mxField), c23_r0.Veh.r_long.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c23_i_mxField = sf_mex_getfield(c23_m8, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_i_mxField), c23_r0.Veh.r_long.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c23_i_mxField = sf_mex_getfield(c23_m8, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_i_mxField), c23_r0.Veh.r_long.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c23_m8);
  c23_h_mxField = sf_mex_getfield(c23_m7, "r_lat", "Par", 0);
  c23_m9 = sf_mex_dup(c23_h_mxField);
  c23_j_mxField = sf_mex_getfield(c23_m9, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_j_mxField), c23_r0.Veh.r_lat.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c23_j_mxField = sf_mex_getfield(c23_m9, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_j_mxField), c23_r0.Veh.r_lat.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c23_j_mxField = sf_mex_getfield(c23_m9, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_j_mxField), c23_r0.Veh.r_lat.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c23_j_mxField = sf_mex_getfield(c23_m9, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_j_mxField), c23_r0.Veh.r_lat.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c23_m9);
  c23_h_mxField = sf_mex_getfield(c23_m7, "r_lever", "Par", 0);
  c23_m10 = sf_mex_dup(c23_h_mxField);
  c23_k_mxField = sf_mex_getfield(c23_m10, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_k_mxField), c23_r0.Veh.r_lever.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c23_k_mxField = sf_mex_getfield(c23_m10, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_k_mxField), c23_r0.Veh.r_lever.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c23_k_mxField = sf_mex_getfield(c23_m10, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_k_mxField), c23_r0.Veh.r_lever.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c23_k_mxField = sf_mex_getfield(c23_m10, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_k_mxField), c23_r0.Veh.r_lever.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c23_m10);
  c23_h_mxField = sf_mex_getfield(c23_m7, "r_pivot", "Par", 0);
  c23_m11 = sf_mex_dup(c23_h_mxField);
  c23_l_mxField = sf_mex_getfield(c23_m11, "fl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_l_mxField), c23_r0.Veh.r_pivot.fl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c23_l_mxField = sf_mex_getfield(c23_m11, "fr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_l_mxField), c23_r0.Veh.r_pivot.fr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c23_l_mxField = sf_mex_getfield(c23_m11, "rl", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_l_mxField), c23_r0.Veh.r_pivot.rl, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  c23_l_mxField = sf_mex_getfield(c23_m11, "rr", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_l_mxField), c23_r0.Veh.r_pivot.rr, 1,
                      0, 0U, 1, 0U, 2, 3, 1);
  sf_mex_destroy(&c23_m11);
  c23_h_mxField = sf_mex_getfield(c23_m7, "cw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_h_mxField), &c23_r0.Veh.cw, 1, 0, 0U,
                      0, 0U, 0);
  c23_h_mxField = sf_mex_getfield(c23_m7, "carb_f", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_h_mxField), &c23_r0.Veh.carb_f, 1, 0,
                      0U, 0, 0U, 0);
  c23_h_mxField = sf_mex_getfield(c23_m7, "carb_r", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_h_mxField), &c23_r0.Veh.carb_r, 1, 0,
                      0U, 0, 0U, 0);
  c23_h_mxField = sf_mex_getfield(c23_m7, "dw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_h_mxField), &c23_r0.Veh.dw, 1, 0, 0U,
                      0, 0U, 0);
  c23_h_mxField = sf_mex_getfield(c23_m7, "Jw", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_h_mxField), &c23_r0.Veh.Jw, 1, 0, 0U,
                      0, 0U, 0);
  c23_h_mxField = sf_mex_getfield(c23_m7, "C0", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_h_mxField), &c23_r0.Veh.C0, 1, 0, 0U,
                      0, 0U, 0);
  c23_h_mxField = sf_mex_getfield(c23_m7, "RelaxLength", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_h_mxField), &c23_r0.Veh.RelaxLength,
                      1, 0, 0U, 0, 0U, 0);
  c23_h_mxField = sf_mex_getfield(c23_m7, "RRC", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_h_mxField), &c23_r0.Veh.RRC, 1, 0,
                      0U, 0, 0U, 0);
  c23_h_mxField = sf_mex_getfield(c23_m7, "Pmax", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_h_mxField), &c23_r0.Veh.Pmax, 1, 0,
                      0U, 0, 0U, 0);
  c23_h_mxField = sf_mex_getfield(c23_m7, "PropDistrFrnt", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_h_mxField),
                      &c23_r0.Veh.PropDistrFrnt, 1, 0, 0U, 0, 0U, 0);
  c23_h_mxField = sf_mex_getfield(c23_m7, "BrkDistrFrnt", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_h_mxField), &c23_r0.Veh.BrkDistrFrnt,
                      1, 0, 0U, 0, 0U, 0);
  c23_h_mxField = sf_mex_getfield(c23_m7, "SteRatio", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_h_mxField), &c23_r0.Veh.SteRatio, 1,
                      0, 0U, 0, 0U, 0);
  sf_mex_destroy(&c23_m7);
  c23_mxField = sf_mex_getfield(c23_m0, "Drvr", "Par", 0);
  c23_m12 = sf_mex_dup(c23_mxField);
  c23_m_mxField = sf_mex_getfield(c23_m12, "v_set", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_m_mxField), &c23_r0.Drvr.v_set, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c23_m12);
  c23_mxField = sf_mex_getfield(c23_m0, "Init", "Par", 0);
  c23_m13 = sf_mex_dup(c23_mxField);
  c23_n_mxField = sf_mex_getfield(c23_m13, "v_x", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_n_mxField), &c23_r0.Init.v_x, 1, 0,
                      0U, 0, 0U, 0);
  c23_n_mxField = sf_mex_getfield(c23_m13, "F_fz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_n_mxField), &c23_r0.Init.F_fz, 1, 0,
                      0U, 0, 0U, 0);
  c23_n_mxField = sf_mex_getfield(c23_m13, "F_rz", "Par", 0);
  sf_mex_import_named("Par", sf_mex_dup(c23_n_mxField), &c23_r0.Init.F_rz, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c23_m13);
  sf_mex_destroy(&c23_m0);
  chartInstance->c23_Par = c23_r0;
}

static void enable_c23_Modified(SFc23_ModifiedInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c23_Modified(SFc23_ModifiedInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c23_update_debugger_state_c23_Modified(SFc23_ModifiedInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c23_Modified(SFc23_ModifiedInstanceStruct
  *chartInstance)
{
  const mxArray *c23_st;
  const mxArray *c23_y = NULL;
  const mxArray *c23_b_y = NULL;
  real_T c23_u;
  const mxArray *c23_c_y = NULL;
  real_T c23_b_u;
  const mxArray *c23_d_y = NULL;
  real_T c23_c_u;
  const mxArray *c23_e_y = NULL;
  real_T c23_d_u;
  const mxArray *c23_f_y = NULL;
  uint8_T c23_hoistedGlobal;
  uint8_T c23_e_u;
  const mxArray *c23_g_y = NULL;
  c23_st = NULL;
  c23_st = NULL;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_createcellmatrix(2, 1), false);
  c23_b_y = NULL;
  sf_mex_assign(&c23_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c23_u = *(real_T *)&((char_T *)chartInstance->c23_F_d4)[0];
  c23_c_y = NULL;
  sf_mex_assign(&c23_c_y, sf_mex_create("y", &c23_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c23_b_y, c23_c_y, "fl", "fl", 0);
  c23_b_u = *(real_T *)&((char_T *)chartInstance->c23_F_d4)[8];
  c23_d_y = NULL;
  sf_mex_assign(&c23_d_y, sf_mex_create("y", &c23_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c23_b_y, c23_d_y, "fr", "fr", 0);
  c23_c_u = *(real_T *)&((char_T *)chartInstance->c23_F_d4)[16];
  c23_e_y = NULL;
  sf_mex_assign(&c23_e_y, sf_mex_create("y", &c23_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c23_b_y, c23_e_y, "rl", "rl", 0);
  c23_d_u = *(real_T *)&((char_T *)chartInstance->c23_F_d4)[24];
  c23_f_y = NULL;
  sf_mex_assign(&c23_f_y, sf_mex_create("y", &c23_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c23_b_y, c23_f_y, "rr", "rr", 0);
  sf_mex_setcell(c23_y, 0, c23_b_y);
  c23_hoistedGlobal = chartInstance->c23_is_active_c23_Modified;
  c23_e_u = c23_hoistedGlobal;
  c23_g_y = NULL;
  sf_mex_assign(&c23_g_y, sf_mex_create("y", &c23_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c23_y, 1, c23_g_y);
  sf_mex_assign(&c23_st, c23_y, false);
  return c23_st;
}

static void set_sim_state_c23_Modified(SFc23_ModifiedInstanceStruct
  *chartInstance, const mxArray *c23_st)
{
  const mxArray *c23_u;
  c23_whl_vec4 c23_r1;
  chartInstance->c23_doneDoubleBufferReInit = true;
  c23_u = sf_mex_dup(c23_st);
  c23_r1 = c23_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c23_u,
    0)), "F_d4");
  *(real_T *)&((char_T *)chartInstance->c23_F_d4)[0] = c23_r1.fl;
  *(real_T *)&((char_T *)chartInstance->c23_F_d4)[8] = c23_r1.fr;
  *(real_T *)&((char_T *)chartInstance->c23_F_d4)[16] = c23_r1.rl;
  *(real_T *)&((char_T *)chartInstance->c23_F_d4)[24] = c23_r1.rr;
  chartInstance->c23_is_active_c23_Modified = c23_n_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c23_u, 1)),
     "is_active_c23_Modified");
  sf_mex_destroy(&c23_u);
  c23_update_debugger_state_c23_Modified(chartInstance);
  sf_mex_destroy(&c23_st);
}

static void finalize_c23_Modified(SFc23_ModifiedInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c23_Modified(SFc23_ModifiedInstanceStruct *chartInstance)
{
  c23_whl_vec4 c23_b_v_z4;
  c23_struct_iBlsPBO3AGnt69vDoTx5zD c23_b_Par;
  uint32_T c23_debug_family_var_map[9];
  real_T c23_d1;
  real_T c23_d2;
  real_T c23_d3;
  real_T c23_d4;
  real_T c23_nargin = 2.0;
  real_T c23_nargout = 1.0;
  c23_whl_vec4 c23_b_F_d4;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 22U, chartInstance->c23_sfEvent);
  chartInstance->c23_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 22U, chartInstance->c23_sfEvent);
  c23_b_v_z4.fl = *(real_T *)&((char_T *)chartInstance->c23_v_z4)[0];
  c23_b_v_z4.fr = *(real_T *)&((char_T *)chartInstance->c23_v_z4)[8];
  c23_b_v_z4.rl = *(real_T *)&((char_T *)chartInstance->c23_v_z4)[16];
  c23_b_v_z4.rr = *(real_T *)&((char_T *)chartInstance->c23_v_z4)[24];
  c23_b_Par = chartInstance->c23_Par;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c23_debug_family_names,
    c23_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_d1, 0U, c23_c_sf_marshallOut,
    c23_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_d2, 1U, c23_c_sf_marshallOut,
    c23_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_d3, 2U, c23_c_sf_marshallOut,
    c23_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_d4, 3U, c23_c_sf_marshallOut,
    c23_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_nargin, 4U, c23_c_sf_marshallOut,
    c23_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_nargout, 5U, c23_c_sf_marshallOut,
    c23_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c23_b_v_z4, 6U, c23_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_b_Par, 7U, c23_b_sf_marshallOut,
    c23_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_b_F_d4, 8U, c23_sf_marshallOut,
    c23_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 5);
  c23_d1 = c23_b_Par.Veh.dw;
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 6);
  c23_d2 = c23_b_Par.Veh.dw;
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 7);
  c23_d3 = c23_b_Par.Veh.dw;
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 8);
  c23_d4 = c23_b_Par.Veh.dw;
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 10);
  c23_b_F_d4.fl = -c23_d1 * c23_b_v_z4.fl;
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 11);
  c23_b_F_d4.fr = -c23_d2 * c23_b_v_z4.fr;
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 12);
  c23_b_F_d4.rl = -c23_d3 * c23_b_v_z4.rl;
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 13);
  c23_b_F_d4.rr = -c23_d4 * c23_b_v_z4.rr;
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, -13);
  _SFD_SYMBOL_SCOPE_POP();
  *(real_T *)&((char_T *)chartInstance->c23_F_d4)[0] = c23_b_F_d4.fl;
  *(real_T *)&((char_T *)chartInstance->c23_F_d4)[8] = c23_b_F_d4.fr;
  *(real_T *)&((char_T *)chartInstance->c23_F_d4)[16] = c23_b_F_d4.rl;
  *(real_T *)&((char_T *)chartInstance->c23_F_d4)[24] = c23_b_F_d4.rr;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 22U, chartInstance->c23_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_ModifiedMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c23_Modified(SFc23_ModifiedInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc23_Modified(SFc23_ModifiedInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c23_machineNumber, uint32_T
  c23_chartNumber, uint32_T c23_instanceNumber)
{
  (void)c23_machineNumber;
  (void)c23_chartNumber;
  (void)c23_instanceNumber;
}

static const mxArray *c23_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  c23_whl_vec4 c23_u;
  const mxArray *c23_y = NULL;
  real_T c23_b_u;
  const mxArray *c23_b_y = NULL;
  real_T c23_c_u;
  const mxArray *c23_c_y = NULL;
  real_T c23_d_u;
  const mxArray *c23_d_y = NULL;
  real_T c23_e_u;
  const mxArray *c23_e_y = NULL;
  SFc23_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc23_ModifiedInstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  c23_u = *(c23_whl_vec4 *)c23_inData;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c23_b_u = c23_u.fl;
  c23_b_y = NULL;
  sf_mex_assign(&c23_b_y, sf_mex_create("y", &c23_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c23_y, c23_b_y, "fl", "fl", 0);
  c23_c_u = c23_u.fr;
  c23_c_y = NULL;
  sf_mex_assign(&c23_c_y, sf_mex_create("y", &c23_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c23_y, c23_c_y, "fr", "fr", 0);
  c23_d_u = c23_u.rl;
  c23_d_y = NULL;
  sf_mex_assign(&c23_d_y, sf_mex_create("y", &c23_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c23_y, c23_d_y, "rl", "rl", 0);
  c23_e_u = c23_u.rr;
  c23_e_y = NULL;
  sf_mex_assign(&c23_e_y, sf_mex_create("y", &c23_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c23_y, c23_e_y, "rr", "rr", 0);
  sf_mex_assign(&c23_mxArrayOutData, c23_y, false);
  return c23_mxArrayOutData;
}

static c23_whl_vec4 c23_emlrt_marshallIn(SFc23_ModifiedInstanceStruct
  *chartInstance, const mxArray *c23_b_F_d4, const char_T *c23_identifier)
{
  c23_whl_vec4 c23_y;
  emlrtMsgIdentifier c23_thisId;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_b_F_d4),
    &c23_thisId);
  sf_mex_destroy(&c23_b_F_d4);
  return c23_y;
}

static c23_whl_vec4 c23_b_emlrt_marshallIn(SFc23_ModifiedInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId)
{
  c23_whl_vec4 c23_y;
  emlrtMsgIdentifier c23_thisId;
  static const char * c23_fieldNames[4] = { "fl", "fr", "rl", "rr" };

  c23_thisId.fParent = c23_parentId;
  sf_mex_check_struct(c23_parentId, c23_u, 4, c23_fieldNames, 0U, NULL);
  c23_thisId.fIdentifier = "fl";
  c23_y.fl = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c23_u, "fl", "fl", 0)), &c23_thisId);
  c23_thisId.fIdentifier = "fr";
  c23_y.fr = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c23_u, "fr", "fr", 0)), &c23_thisId);
  c23_thisId.fIdentifier = "rl";
  c23_y.rl = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c23_u, "rl", "rl", 0)), &c23_thisId);
  c23_thisId.fIdentifier = "rr";
  c23_y.rr = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c23_u, "rr", "rr", 0)), &c23_thisId);
  sf_mex_destroy(&c23_u);
  return c23_y;
}

static real_T c23_c_emlrt_marshallIn(SFc23_ModifiedInstanceStruct *chartInstance,
  const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId)
{
  real_T c23_y;
  real_T c23_d0;
  (void)chartInstance;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), &c23_d0, 1, 0, 0U, 0, 0U, 0);
  c23_y = c23_d0;
  sf_mex_destroy(&c23_u);
  return c23_y;
}

static void c23_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData)
{
  const mxArray *c23_b_F_d4;
  const char_T *c23_identifier;
  emlrtMsgIdentifier c23_thisId;
  c23_whl_vec4 c23_y;
  SFc23_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc23_ModifiedInstanceStruct *)chartInstanceVoid;
  c23_b_F_d4 = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_b_F_d4),
    &c23_thisId);
  sf_mex_destroy(&c23_b_F_d4);
  *(c23_whl_vec4 *)c23_outData = c23_y;
  sf_mex_destroy(&c23_mxArrayInData);
}

static const mxArray *c23_b_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData;
  c23_struct_iBlsPBO3AGnt69vDoTx5zD c23_u;
  const mxArray *c23_y = NULL;
  c23_struct_Nst2vGTExxHsg85EUOj9EH c23_b_u;
  const mxArray *c23_b_y = NULL;
  real_T c23_c_u;
  const mxArray *c23_c_y = NULL;
  c23_struct_HhckT6rntEraqECYVIDvCC c23_d_u;
  const mxArray *c23_d_y = NULL;
  real_T c23_e_u;
  const mxArray *c23_e_y = NULL;
  real_T c23_f_u;
  const mxArray *c23_f_y = NULL;
  const mxArray *c23_g_y = NULL;
  real_T c23_g_u;
  const mxArray *c23_h_y = NULL;
  real_T c23_h_u;
  const mxArray *c23_i_y = NULL;
  const mxArray *c23_j_y = NULL;
  real_T c23_i_u;
  const mxArray *c23_k_y = NULL;
  real_T c23_j_u;
  const mxArray *c23_l_y = NULL;
  const mxArray *c23_m_y = NULL;
  real_T c23_k_u;
  const mxArray *c23_n_y = NULL;
  real_T c23_l_u;
  const mxArray *c23_o_y = NULL;
  const mxArray *c23_p_y = NULL;
  real_T c23_m_u;
  const mxArray *c23_q_y = NULL;
  real_T c23_n_u;
  const mxArray *c23_r_y = NULL;
  real_T c23_o_u;
  const mxArray *c23_s_y = NULL;
  c23_struct_ZCmOWPuqBDw16FSOVVD00 c23_p_u;
  const mxArray *c23_t_y = NULL;
  real_T c23_q_u;
  const mxArray *c23_u_y = NULL;
  real_T c23_r_u;
  const mxArray *c23_v_y = NULL;
  real_T c23_s_u;
  const mxArray *c23_w_y = NULL;
  real_T c23_t_u;
  const mxArray *c23_x_y = NULL;
  real_T c23_u_u;
  const mxArray *c23_y_y = NULL;
  real_T c23_v_u;
  const mxArray *c23_ab_y = NULL;
  real_T c23_w_u;
  const mxArray *c23_bb_y = NULL;
  real_T c23_x_u;
  const mxArray *c23_cb_y = NULL;
  real_T c23_y_u;
  const mxArray *c23_db_y = NULL;
  real_T c23_ab_u;
  const mxArray *c23_eb_y = NULL;
  real_T c23_bb_u;
  const mxArray *c23_fb_y = NULL;
  int32_T c23_i0;
  real_T c23_cb_u[4];
  const mxArray *c23_gb_y = NULL;
  real_T c23_db_u;
  const mxArray *c23_hb_y = NULL;
  c23_struct_ZKAzdrl7umDGJoC14aoVKC c23_eb_u;
  const mxArray *c23_ib_y = NULL;
  int32_T c23_i1;
  real_T c23_fb_u[3];
  const mxArray *c23_jb_y = NULL;
  int32_T c23_i2;
  real_T c23_gb_u[3];
  const mxArray *c23_kb_y = NULL;
  int32_T c23_i3;
  real_T c23_hb_u[3];
  const mxArray *c23_lb_y = NULL;
  int32_T c23_i4;
  real_T c23_ib_u[3];
  const mxArray *c23_mb_y = NULL;
  const mxArray *c23_nb_y = NULL;
  int32_T c23_i5;
  real_T c23_jb_u[3];
  const mxArray *c23_ob_y = NULL;
  int32_T c23_i6;
  real_T c23_kb_u[3];
  const mxArray *c23_pb_y = NULL;
  int32_T c23_i7;
  real_T c23_lb_u[3];
  const mxArray *c23_qb_y = NULL;
  int32_T c23_i8;
  real_T c23_mb_u[3];
  const mxArray *c23_rb_y = NULL;
  const mxArray *c23_sb_y = NULL;
  int32_T c23_i9;
  real_T c23_nb_u[3];
  const mxArray *c23_tb_y = NULL;
  int32_T c23_i10;
  real_T c23_ob_u[3];
  const mxArray *c23_ub_y = NULL;
  int32_T c23_i11;
  real_T c23_pb_u[3];
  const mxArray *c23_vb_y = NULL;
  int32_T c23_i12;
  real_T c23_qb_u[3];
  const mxArray *c23_wb_y = NULL;
  const mxArray *c23_xb_y = NULL;
  int32_T c23_i13;
  real_T c23_rb_u[3];
  const mxArray *c23_yb_y = NULL;
  int32_T c23_i14;
  real_T c23_sb_u[3];
  const mxArray *c23_ac_y = NULL;
  int32_T c23_i15;
  real_T c23_tb_u[3];
  const mxArray *c23_bc_y = NULL;
  int32_T c23_i16;
  real_T c23_ub_u[3];
  const mxArray *c23_cc_y = NULL;
  real_T c23_vb_u;
  const mxArray *c23_dc_y = NULL;
  real_T c23_wb_u;
  const mxArray *c23_ec_y = NULL;
  real_T c23_xb_u;
  const mxArray *c23_fc_y = NULL;
  real_T c23_yb_u;
  const mxArray *c23_gc_y = NULL;
  real_T c23_ac_u;
  const mxArray *c23_hc_y = NULL;
  real_T c23_bc_u;
  const mxArray *c23_ic_y = NULL;
  real_T c23_cc_u;
  const mxArray *c23_jc_y = NULL;
  real_T c23_dc_u;
  const mxArray *c23_kc_y = NULL;
  real_T c23_ec_u;
  const mxArray *c23_lc_y = NULL;
  real_T c23_fc_u;
  const mxArray *c23_mc_y = NULL;
  real_T c23_gc_u;
  const mxArray *c23_nc_y = NULL;
  real_T c23_hc_u;
  const mxArray *c23_oc_y = NULL;
  c23_struct_r4FNviKwHfdhB8nQjvQv9 c23_ic_u;
  const mxArray *c23_pc_y = NULL;
  real_T c23_jc_u;
  const mxArray *c23_qc_y = NULL;
  c23_struct_Y9F1qlBi9AhssksPwemA4G c23_kc_u;
  const mxArray *c23_rc_y = NULL;
  real_T c23_lc_u;
  const mxArray *c23_sc_y = NULL;
  real_T c23_mc_u;
  const mxArray *c23_tc_y = NULL;
  real_T c23_nc_u;
  const mxArray *c23_uc_y = NULL;
  SFc23_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc23_ModifiedInstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  c23_mxArrayOutData = NULL;
  c23_u = *(c23_struct_iBlsPBO3AGnt69vDoTx5zD *)c23_inData;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c23_b_u = c23_u.Env;
  c23_b_y = NULL;
  sf_mex_assign(&c23_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c23_c_u = c23_b_u.g;
  c23_c_y = NULL;
  sf_mex_assign(&c23_c_y, sf_mex_create("y", &c23_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c23_b_y, c23_c_y, "g", "g", 0);
  c23_d_u = c23_b_u.left1;
  c23_d_y = NULL;
  sf_mex_assign(&c23_d_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c23_e_u = c23_d_u.x;
  c23_e_y = NULL;
  sf_mex_assign(&c23_e_y, sf_mex_create("y", &c23_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c23_d_y, c23_e_y, "x", "x", 0);
  c23_f_u = c23_d_u.y;
  c23_f_y = NULL;
  sf_mex_assign(&c23_f_y, sf_mex_create("y", &c23_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c23_d_y, c23_f_y, "y", "y", 0);
  sf_mex_addfield(c23_b_y, c23_d_y, "left1", "left1", 0);
  c23_d_u = c23_b_u.right1;
  c23_g_y = NULL;
  sf_mex_assign(&c23_g_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c23_g_u = c23_d_u.x;
  c23_h_y = NULL;
  sf_mex_assign(&c23_h_y, sf_mex_create("y", &c23_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c23_g_y, c23_h_y, "x", "x", 0);
  c23_h_u = c23_d_u.y;
  c23_i_y = NULL;
  sf_mex_assign(&c23_i_y, sf_mex_create("y", &c23_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c23_g_y, c23_i_y, "y", "y", 0);
  sf_mex_addfield(c23_b_y, c23_g_y, "right1", "right1", 0);
  c23_d_u = c23_b_u.right2;
  c23_j_y = NULL;
  sf_mex_assign(&c23_j_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c23_i_u = c23_d_u.x;
  c23_k_y = NULL;
  sf_mex_assign(&c23_k_y, sf_mex_create("y", &c23_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c23_j_y, c23_k_y, "x", "x", 0);
  c23_j_u = c23_d_u.y;
  c23_l_y = NULL;
  sf_mex_assign(&c23_l_y, sf_mex_create("y", &c23_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c23_j_y, c23_l_y, "y", "y", 0);
  sf_mex_addfield(c23_b_y, c23_j_y, "right2", "right2", 0);
  c23_d_u = c23_b_u.left2;
  c23_m_y = NULL;
  sf_mex_assign(&c23_m_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c23_k_u = c23_d_u.x;
  c23_n_y = NULL;
  sf_mex_assign(&c23_n_y, sf_mex_create("y", &c23_k_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c23_m_y, c23_n_y, "x", "x", 0);
  c23_l_u = c23_d_u.y;
  c23_o_y = NULL;
  sf_mex_assign(&c23_o_y, sf_mex_create("y", &c23_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c23_m_y, c23_o_y, "y", "y", 0);
  sf_mex_addfield(c23_b_y, c23_m_y, "left2", "left2", 0);
  c23_d_u = c23_b_u.right3;
  c23_p_y = NULL;
  sf_mex_assign(&c23_p_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c23_m_u = c23_d_u.x;
  c23_q_y = NULL;
  sf_mex_assign(&c23_q_y, sf_mex_create("y", &c23_m_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c23_p_y, c23_q_y, "x", "x", 0);
  c23_n_u = c23_d_u.y;
  c23_r_y = NULL;
  sf_mex_assign(&c23_r_y, sf_mex_create("y", &c23_n_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c23_p_y, c23_r_y, "y", "y", 0);
  sf_mex_addfield(c23_b_y, c23_p_y, "right3", "right3", 0);
  c23_o_u = c23_b_u.mu;
  c23_s_y = NULL;
  sf_mex_assign(&c23_s_y, sf_mex_create("y", &c23_o_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c23_b_y, c23_s_y, "mu", "mu", 0);
  sf_mex_addfield(c23_y, c23_b_y, "Env", "Env", 0);
  c23_p_u = c23_u.Veh;
  c23_t_y = NULL;
  sf_mex_assign(&c23_t_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c23_q_u = c23_p_u.m;
  c23_u_y = NULL;
  sf_mex_assign(&c23_u_y, sf_mex_create("y", &c23_q_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c23_t_y, c23_u_y, "m", "m", 0);
  c23_r_u = c23_p_u.Jz;
  c23_v_y = NULL;
  sf_mex_assign(&c23_v_y, sf_mex_create("y", &c23_r_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c23_t_y, c23_v_y, "Jz", "Jz", 0);
  c23_s_u = c23_p_u.m_sprung;
  c23_w_y = NULL;
  sf_mex_assign(&c23_w_y, sf_mex_create("y", &c23_s_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c23_t_y, c23_w_y, "m_sprung", "m_sprung", 0);
  c23_t_u = c23_p_u.Jx_sprung;
  c23_x_y = NULL;
  sf_mex_assign(&c23_x_y, sf_mex_create("y", &c23_t_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c23_t_y, c23_x_y, "Jx_sprung", "Jx_sprung", 0);
  c23_u_u = c23_p_u.Jy_sprung;
  c23_y_y = NULL;
  sf_mex_assign(&c23_y_y, sf_mex_create("y", &c23_u_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c23_t_y, c23_y_y, "Jy_sprung", "Jy_sprung", 0);
  c23_v_u = c23_p_u.lf;
  c23_ab_y = NULL;
  sf_mex_assign(&c23_ab_y, sf_mex_create("y", &c23_v_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c23_t_y, c23_ab_y, "lf", "lf", 0);
  c23_w_u = c23_p_u.lr;
  c23_bb_y = NULL;
  sf_mex_assign(&c23_bb_y, sf_mex_create("y", &c23_w_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c23_t_y, c23_bb_y, "lr", "lr", 0);
  c23_x_u = c23_p_u.L;
  c23_cb_y = NULL;
  sf_mex_assign(&c23_cb_y, sf_mex_create("y", &c23_x_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c23_t_y, c23_cb_y, "L", "L", 0);
  c23_y_u = c23_p_u.TrackWidth;
  c23_db_y = NULL;
  sf_mex_assign(&c23_db_y, sf_mex_create("y", &c23_y_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c23_t_y, c23_db_y, "TrackWidth", "TrackWidth", 0);
  c23_ab_u = c23_p_u.h;
  c23_eb_y = NULL;
  sf_mex_assign(&c23_eb_y, sf_mex_create("y", &c23_ab_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c23_t_y, c23_eb_y, "h", "h", 0);
  c23_bb_u = c23_p_u.HalfRohACd;
  c23_fb_y = NULL;
  sf_mex_assign(&c23_fb_y, sf_mex_create("y", &c23_bb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c23_t_y, c23_fb_y, "HalfRohACd", "HalfRohACd", 0);
  for (c23_i0 = 0; c23_i0 < 4; c23_i0++) {
    c23_cb_u[c23_i0] = c23_p_u.F_z4_static[c23_i0];
  }

  c23_gb_y = NULL;
  sf_mex_assign(&c23_gb_y, sf_mex_create("y", c23_cb_u, 0, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_addfield(c23_t_y, c23_gb_y, "F_z4_static", "F_z4_static", 0);
  c23_db_u = c23_p_u.Rw;
  c23_hb_y = NULL;
  sf_mex_assign(&c23_hb_y, sf_mex_create("y", &c23_db_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c23_t_y, c23_hb_y, "Rw", "Rw", 0);
  c23_eb_u = c23_p_u.r_long;
  c23_ib_y = NULL;
  sf_mex_assign(&c23_ib_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c23_i1 = 0; c23_i1 < 3; c23_i1++) {
    c23_fb_u[c23_i1] = c23_eb_u.fl[c23_i1];
  }

  c23_jb_y = NULL;
  sf_mex_assign(&c23_jb_y, sf_mex_create("y", c23_fb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c23_ib_y, c23_jb_y, "fl", "fl", 0);
  for (c23_i2 = 0; c23_i2 < 3; c23_i2++) {
    c23_gb_u[c23_i2] = c23_eb_u.fr[c23_i2];
  }

  c23_kb_y = NULL;
  sf_mex_assign(&c23_kb_y, sf_mex_create("y", c23_gb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c23_ib_y, c23_kb_y, "fr", "fr", 0);
  for (c23_i3 = 0; c23_i3 < 3; c23_i3++) {
    c23_hb_u[c23_i3] = c23_eb_u.rl[c23_i3];
  }

  c23_lb_y = NULL;
  sf_mex_assign(&c23_lb_y, sf_mex_create("y", c23_hb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c23_ib_y, c23_lb_y, "rl", "rl", 0);
  for (c23_i4 = 0; c23_i4 < 3; c23_i4++) {
    c23_ib_u[c23_i4] = c23_eb_u.rr[c23_i4];
  }

  c23_mb_y = NULL;
  sf_mex_assign(&c23_mb_y, sf_mex_create("y", c23_ib_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c23_ib_y, c23_mb_y, "rr", "rr", 0);
  sf_mex_addfield(c23_t_y, c23_ib_y, "r_long", "r_long", 0);
  c23_eb_u = c23_p_u.r_lat;
  c23_nb_y = NULL;
  sf_mex_assign(&c23_nb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c23_i5 = 0; c23_i5 < 3; c23_i5++) {
    c23_jb_u[c23_i5] = c23_eb_u.fl[c23_i5];
  }

  c23_ob_y = NULL;
  sf_mex_assign(&c23_ob_y, sf_mex_create("y", c23_jb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c23_nb_y, c23_ob_y, "fl", "fl", 0);
  for (c23_i6 = 0; c23_i6 < 3; c23_i6++) {
    c23_kb_u[c23_i6] = c23_eb_u.fr[c23_i6];
  }

  c23_pb_y = NULL;
  sf_mex_assign(&c23_pb_y, sf_mex_create("y", c23_kb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c23_nb_y, c23_pb_y, "fr", "fr", 0);
  for (c23_i7 = 0; c23_i7 < 3; c23_i7++) {
    c23_lb_u[c23_i7] = c23_eb_u.rl[c23_i7];
  }

  c23_qb_y = NULL;
  sf_mex_assign(&c23_qb_y, sf_mex_create("y", c23_lb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c23_nb_y, c23_qb_y, "rl", "rl", 0);
  for (c23_i8 = 0; c23_i8 < 3; c23_i8++) {
    c23_mb_u[c23_i8] = c23_eb_u.rr[c23_i8];
  }

  c23_rb_y = NULL;
  sf_mex_assign(&c23_rb_y, sf_mex_create("y", c23_mb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c23_nb_y, c23_rb_y, "rr", "rr", 0);
  sf_mex_addfield(c23_t_y, c23_nb_y, "r_lat", "r_lat", 0);
  c23_eb_u = c23_p_u.r_lever;
  c23_sb_y = NULL;
  sf_mex_assign(&c23_sb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c23_i9 = 0; c23_i9 < 3; c23_i9++) {
    c23_nb_u[c23_i9] = c23_eb_u.fl[c23_i9];
  }

  c23_tb_y = NULL;
  sf_mex_assign(&c23_tb_y, sf_mex_create("y", c23_nb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c23_sb_y, c23_tb_y, "fl", "fl", 0);
  for (c23_i10 = 0; c23_i10 < 3; c23_i10++) {
    c23_ob_u[c23_i10] = c23_eb_u.fr[c23_i10];
  }

  c23_ub_y = NULL;
  sf_mex_assign(&c23_ub_y, sf_mex_create("y", c23_ob_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c23_sb_y, c23_ub_y, "fr", "fr", 0);
  for (c23_i11 = 0; c23_i11 < 3; c23_i11++) {
    c23_pb_u[c23_i11] = c23_eb_u.rl[c23_i11];
  }

  c23_vb_y = NULL;
  sf_mex_assign(&c23_vb_y, sf_mex_create("y", c23_pb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c23_sb_y, c23_vb_y, "rl", "rl", 0);
  for (c23_i12 = 0; c23_i12 < 3; c23_i12++) {
    c23_qb_u[c23_i12] = c23_eb_u.rr[c23_i12];
  }

  c23_wb_y = NULL;
  sf_mex_assign(&c23_wb_y, sf_mex_create("y", c23_qb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c23_sb_y, c23_wb_y, "rr", "rr", 0);
  sf_mex_addfield(c23_t_y, c23_sb_y, "r_lever", "r_lever", 0);
  c23_eb_u = c23_p_u.r_pivot;
  c23_xb_y = NULL;
  sf_mex_assign(&c23_xb_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c23_i13 = 0; c23_i13 < 3; c23_i13++) {
    c23_rb_u[c23_i13] = c23_eb_u.fl[c23_i13];
  }

  c23_yb_y = NULL;
  sf_mex_assign(&c23_yb_y, sf_mex_create("y", c23_rb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c23_xb_y, c23_yb_y, "fl", "fl", 0);
  for (c23_i14 = 0; c23_i14 < 3; c23_i14++) {
    c23_sb_u[c23_i14] = c23_eb_u.fr[c23_i14];
  }

  c23_ac_y = NULL;
  sf_mex_assign(&c23_ac_y, sf_mex_create("y", c23_sb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c23_xb_y, c23_ac_y, "fr", "fr", 0);
  for (c23_i15 = 0; c23_i15 < 3; c23_i15++) {
    c23_tb_u[c23_i15] = c23_eb_u.rl[c23_i15];
  }

  c23_bc_y = NULL;
  sf_mex_assign(&c23_bc_y, sf_mex_create("y", c23_tb_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c23_xb_y, c23_bc_y, "rl", "rl", 0);
  for (c23_i16 = 0; c23_i16 < 3; c23_i16++) {
    c23_ub_u[c23_i16] = c23_eb_u.rr[c23_i16];
  }

  c23_cc_y = NULL;
  sf_mex_assign(&c23_cc_y, sf_mex_create("y", c23_ub_u, 0, 0U, 1U, 0U, 2, 3, 1),
                false);
  sf_mex_addfield(c23_xb_y, c23_cc_y, "rr", "rr", 0);
  sf_mex_addfield(c23_t_y, c23_xb_y, "r_pivot", "r_pivot", 0);
  c23_vb_u = c23_p_u.cw;
  c23_dc_y = NULL;
  sf_mex_assign(&c23_dc_y, sf_mex_create("y", &c23_vb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c23_t_y, c23_dc_y, "cw", "cw", 0);
  c23_wb_u = c23_p_u.carb_f;
  c23_ec_y = NULL;
  sf_mex_assign(&c23_ec_y, sf_mex_create("y", &c23_wb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c23_t_y, c23_ec_y, "carb_f", "carb_f", 0);
  c23_xb_u = c23_p_u.carb_r;
  c23_fc_y = NULL;
  sf_mex_assign(&c23_fc_y, sf_mex_create("y", &c23_xb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c23_t_y, c23_fc_y, "carb_r", "carb_r", 0);
  c23_yb_u = c23_p_u.dw;
  c23_gc_y = NULL;
  sf_mex_assign(&c23_gc_y, sf_mex_create("y", &c23_yb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c23_t_y, c23_gc_y, "dw", "dw", 0);
  c23_ac_u = c23_p_u.Jw;
  c23_hc_y = NULL;
  sf_mex_assign(&c23_hc_y, sf_mex_create("y", &c23_ac_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c23_t_y, c23_hc_y, "Jw", "Jw", 0);
  c23_bc_u = c23_p_u.C0;
  c23_ic_y = NULL;
  sf_mex_assign(&c23_ic_y, sf_mex_create("y", &c23_bc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c23_t_y, c23_ic_y, "C0", "C0", 0);
  c23_cc_u = c23_p_u.RelaxLength;
  c23_jc_y = NULL;
  sf_mex_assign(&c23_jc_y, sf_mex_create("y", &c23_cc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c23_t_y, c23_jc_y, "RelaxLength", "RelaxLength", 0);
  c23_dc_u = c23_p_u.RRC;
  c23_kc_y = NULL;
  sf_mex_assign(&c23_kc_y, sf_mex_create("y", &c23_dc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c23_t_y, c23_kc_y, "RRC", "RRC", 0);
  c23_ec_u = c23_p_u.Pmax;
  c23_lc_y = NULL;
  sf_mex_assign(&c23_lc_y, sf_mex_create("y", &c23_ec_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c23_t_y, c23_lc_y, "Pmax", "Pmax", 0);
  c23_fc_u = c23_p_u.PropDistrFrnt;
  c23_mc_y = NULL;
  sf_mex_assign(&c23_mc_y, sf_mex_create("y", &c23_fc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c23_t_y, c23_mc_y, "PropDistrFrnt", "PropDistrFrnt", 0);
  c23_gc_u = c23_p_u.BrkDistrFrnt;
  c23_nc_y = NULL;
  sf_mex_assign(&c23_nc_y, sf_mex_create("y", &c23_gc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c23_t_y, c23_nc_y, "BrkDistrFrnt", "BrkDistrFrnt", 0);
  c23_hc_u = c23_p_u.SteRatio;
  c23_oc_y = NULL;
  sf_mex_assign(&c23_oc_y, sf_mex_create("y", &c23_hc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c23_t_y, c23_oc_y, "SteRatio", "SteRatio", 0);
  sf_mex_addfield(c23_y, c23_t_y, "Veh", "Veh", 0);
  c23_ic_u = c23_u.Drvr;
  c23_pc_y = NULL;
  sf_mex_assign(&c23_pc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c23_jc_u = c23_ic_u.v_set;
  c23_qc_y = NULL;
  sf_mex_assign(&c23_qc_y, sf_mex_create("y", &c23_jc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c23_pc_y, c23_qc_y, "v_set", "v_set", 0);
  sf_mex_addfield(c23_y, c23_pc_y, "Drvr", "Drvr", 0);
  c23_kc_u = c23_u.Init;
  c23_rc_y = NULL;
  sf_mex_assign(&c23_rc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c23_lc_u = c23_kc_u.v_x;
  c23_sc_y = NULL;
  sf_mex_assign(&c23_sc_y, sf_mex_create("y", &c23_lc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c23_rc_y, c23_sc_y, "v_x", "v_x", 0);
  c23_mc_u = c23_kc_u.F_fz;
  c23_tc_y = NULL;
  sf_mex_assign(&c23_tc_y, sf_mex_create("y", &c23_mc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c23_rc_y, c23_tc_y, "F_fz", "F_fz", 0);
  c23_nc_u = c23_kc_u.F_rz;
  c23_uc_y = NULL;
  sf_mex_assign(&c23_uc_y, sf_mex_create("y", &c23_nc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c23_rc_y, c23_uc_y, "F_rz", "F_rz", 0);
  sf_mex_addfield(c23_y, c23_rc_y, "Init", "Init", 0);
  sf_mex_assign(&c23_mxArrayOutData, c23_y, false);
  return c23_mxArrayOutData;
}

static void c23_d_emlrt_marshallIn(SFc23_ModifiedInstanceStruct *chartInstance,
  const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId,
  c23_struct_iBlsPBO3AGnt69vDoTx5zD *c23_y)
{
  emlrtMsgIdentifier c23_thisId;
  static const char * c23_fieldNames[4] = { "Env", "Veh", "Drvr", "Init" };

  c23_thisId.fParent = c23_parentId;
  sf_mex_check_struct(c23_parentId, c23_u, 4, c23_fieldNames, 0U, NULL);
  c23_thisId.fIdentifier = "Env";
  c23_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c23_u, "Env",
    "Env", 0)), &c23_thisId, &c23_y->Env);
  c23_thisId.fIdentifier = "Veh";
  c23_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c23_u, "Veh",
    "Veh", 0)), &c23_thisId, &c23_y->Veh);
  c23_thisId.fIdentifier = "Drvr";
  c23_y->Drvr = c23_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c23_u, "Drvr", "Drvr", 0)), &c23_thisId);
  c23_thisId.fIdentifier = "Init";
  c23_y->Init = c23_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c23_u, "Init", "Init", 0)), &c23_thisId);
  sf_mex_destroy(&c23_u);
}

static void c23_e_emlrt_marshallIn(SFc23_ModifiedInstanceStruct *chartInstance,
  const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId,
  c23_struct_Nst2vGTExxHsg85EUOj9EH *c23_y)
{
  emlrtMsgIdentifier c23_thisId;
  static const char * c23_fieldNames[7] = { "g", "left1", "right1", "right2",
    "left2", "right3", "mu" };

  c23_thisId.fParent = c23_parentId;
  sf_mex_check_struct(c23_parentId, c23_u, 7, c23_fieldNames, 0U, NULL);
  c23_thisId.fIdentifier = "g";
  c23_y->g = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c23_u, "g", "g", 0)), &c23_thisId);
  c23_thisId.fIdentifier = "left1";
  c23_y->left1 = c23_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c23_u, "left1", "left1", 0)), &c23_thisId);
  c23_thisId.fIdentifier = "right1";
  c23_y->right1 = c23_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c23_u, "right1", "right1", 0)), &c23_thisId);
  c23_thisId.fIdentifier = "right2";
  c23_y->right2 = c23_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c23_u, "right2", "right2", 0)), &c23_thisId);
  c23_thisId.fIdentifier = "left2";
  c23_y->left2 = c23_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c23_u, "left2", "left2", 0)), &c23_thisId);
  c23_thisId.fIdentifier = "right3";
  c23_y->right3 = c23_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c23_u, "right3", "right3", 0)), &c23_thisId);
  c23_thisId.fIdentifier = "mu";
  c23_y->mu = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c23_u, "mu", "mu", 0)), &c23_thisId);
  sf_mex_destroy(&c23_u);
}

static c23_struct_HhckT6rntEraqECYVIDvCC c23_f_emlrt_marshallIn
  (SFc23_ModifiedInstanceStruct *chartInstance, const mxArray *c23_u, const
   emlrtMsgIdentifier *c23_parentId)
{
  c23_struct_HhckT6rntEraqECYVIDvCC c23_y;
  emlrtMsgIdentifier c23_thisId;
  static const char * c23_fieldNames[2] = { "x", "y" };

  c23_thisId.fParent = c23_parentId;
  sf_mex_check_struct(c23_parentId, c23_u, 2, c23_fieldNames, 0U, NULL);
  c23_thisId.fIdentifier = "x";
  c23_y.x = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c23_u, "x", "x", 0)), &c23_thisId);
  c23_thisId.fIdentifier = "y";
  c23_y.y = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c23_u, "y", "y", 0)), &c23_thisId);
  sf_mex_destroy(&c23_u);
  return c23_y;
}

static void c23_g_emlrt_marshallIn(SFc23_ModifiedInstanceStruct *chartInstance,
  const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId,
  c23_struct_ZCmOWPuqBDw16FSOVVD00 *c23_y)
{
  emlrtMsgIdentifier c23_thisId;
  static const char * c23_fieldNames[29] = { "m", "Jz", "m_sprung", "Jx_sprung",
    "Jy_sprung", "lf", "lr", "L", "TrackWidth", "h", "HalfRohACd", "F_z4_static",
    "Rw", "r_long", "r_lat", "r_lever", "r_pivot", "cw", "carb_f", "carb_r",
    "dw", "Jw", "C0", "RelaxLength", "RRC", "Pmax", "PropDistrFrnt",
    "BrkDistrFrnt", "SteRatio" };

  c23_thisId.fParent = c23_parentId;
  sf_mex_check_struct(c23_parentId, c23_u, 29, c23_fieldNames, 0U, NULL);
  c23_thisId.fIdentifier = "m";
  c23_y->m = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c23_u, "m", "m", 0)), &c23_thisId);
  c23_thisId.fIdentifier = "Jz";
  c23_y->Jz = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c23_u, "Jz", "Jz", 0)), &c23_thisId);
  c23_thisId.fIdentifier = "m_sprung";
  c23_y->m_sprung = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c23_u, "m_sprung", "m_sprung", 0)), &c23_thisId);
  c23_thisId.fIdentifier = "Jx_sprung";
  c23_y->Jx_sprung = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c23_u, "Jx_sprung", "Jx_sprung", 0)), &c23_thisId);
  c23_thisId.fIdentifier = "Jy_sprung";
  c23_y->Jy_sprung = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c23_u, "Jy_sprung", "Jy_sprung", 0)), &c23_thisId);
  c23_thisId.fIdentifier = "lf";
  c23_y->lf = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c23_u, "lf", "lf", 0)), &c23_thisId);
  c23_thisId.fIdentifier = "lr";
  c23_y->lr = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c23_u, "lr", "lr", 0)), &c23_thisId);
  c23_thisId.fIdentifier = "L";
  c23_y->L = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c23_u, "L", "L", 0)), &c23_thisId);
  c23_thisId.fIdentifier = "TrackWidth";
  c23_y->TrackWidth = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c23_u, "TrackWidth", "TrackWidth", 0)), &c23_thisId);
  c23_thisId.fIdentifier = "h";
  c23_y->h = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c23_u, "h", "h", 0)), &c23_thisId);
  c23_thisId.fIdentifier = "HalfRohACd";
  c23_y->HalfRohACd = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c23_u, "HalfRohACd", "HalfRohACd", 0)), &c23_thisId);
  c23_thisId.fIdentifier = "F_z4_static";
  c23_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c23_u,
    "F_z4_static", "F_z4_static", 0)), &c23_thisId, c23_y->F_z4_static);
  c23_thisId.fIdentifier = "Rw";
  c23_y->Rw = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c23_u, "Rw", "Rw", 0)), &c23_thisId);
  c23_thisId.fIdentifier = "r_long";
  c23_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c23_u,
    "r_long", "r_long", 0)), &c23_thisId, &c23_y->r_long);
  c23_thisId.fIdentifier = "r_lat";
  c23_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c23_u,
    "r_lat", "r_lat", 0)), &c23_thisId, &c23_y->r_lat);
  c23_thisId.fIdentifier = "r_lever";
  c23_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c23_u,
    "r_lever", "r_lever", 0)), &c23_thisId, &c23_y->r_lever);
  c23_thisId.fIdentifier = "r_pivot";
  c23_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c23_u,
    "r_pivot", "r_pivot", 0)), &c23_thisId, &c23_y->r_pivot);
  c23_thisId.fIdentifier = "cw";
  c23_y->cw = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c23_u, "cw", "cw", 0)), &c23_thisId);
  c23_thisId.fIdentifier = "carb_f";
  c23_y->carb_f = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c23_u, "carb_f", "carb_f", 0)), &c23_thisId);
  c23_thisId.fIdentifier = "carb_r";
  c23_y->carb_r = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c23_u, "carb_r", "carb_r", 0)), &c23_thisId);
  c23_thisId.fIdentifier = "dw";
  c23_y->dw = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c23_u, "dw", "dw", 0)), &c23_thisId);
  c23_thisId.fIdentifier = "Jw";
  c23_y->Jw = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c23_u, "Jw", "Jw", 0)), &c23_thisId);
  c23_thisId.fIdentifier = "C0";
  c23_y->C0 = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c23_u, "C0", "C0", 0)), &c23_thisId);
  c23_thisId.fIdentifier = "RelaxLength";
  c23_y->RelaxLength = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c23_u, "RelaxLength", "RelaxLength", 0)), &c23_thisId);
  c23_thisId.fIdentifier = "RRC";
  c23_y->RRC = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c23_u, "RRC", "RRC", 0)), &c23_thisId);
  c23_thisId.fIdentifier = "Pmax";
  c23_y->Pmax = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c23_u, "Pmax", "Pmax", 0)), &c23_thisId);
  c23_thisId.fIdentifier = "PropDistrFrnt";
  c23_y->PropDistrFrnt = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c23_u, "PropDistrFrnt", "PropDistrFrnt", 0)), &c23_thisId);
  c23_thisId.fIdentifier = "BrkDistrFrnt";
  c23_y->BrkDistrFrnt = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c23_u, "BrkDistrFrnt", "BrkDistrFrnt", 0)), &c23_thisId);
  c23_thisId.fIdentifier = "SteRatio";
  c23_y->SteRatio = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c23_u, "SteRatio", "SteRatio", 0)), &c23_thisId);
  sf_mex_destroy(&c23_u);
}

static void c23_h_emlrt_marshallIn(SFc23_ModifiedInstanceStruct *chartInstance,
  const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId, real_T c23_y[4])
{
  real_T c23_dv0[4];
  int32_T c23_i17;
  (void)chartInstance;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), c23_dv0, 1, 0, 0U, 1, 0U, 2, 1,
                4);
  for (c23_i17 = 0; c23_i17 < 4; c23_i17++) {
    c23_y[c23_i17] = c23_dv0[c23_i17];
  }

  sf_mex_destroy(&c23_u);
}

static void c23_i_emlrt_marshallIn(SFc23_ModifiedInstanceStruct *chartInstance,
  const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId,
  c23_struct_ZKAzdrl7umDGJoC14aoVKC *c23_y)
{
  emlrtMsgIdentifier c23_thisId;
  static const char * c23_fieldNames[4] = { "fl", "fr", "rl", "rr" };

  c23_thisId.fParent = c23_parentId;
  sf_mex_check_struct(c23_parentId, c23_u, 4, c23_fieldNames, 0U, NULL);
  c23_thisId.fIdentifier = "fl";
  c23_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c23_u, "fl",
    "fl", 0)), &c23_thisId, c23_y->fl);
  c23_thisId.fIdentifier = "fr";
  c23_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c23_u, "fr",
    "fr", 0)), &c23_thisId, c23_y->fr);
  c23_thisId.fIdentifier = "rl";
  c23_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c23_u, "rl",
    "rl", 0)), &c23_thisId, c23_y->rl);
  c23_thisId.fIdentifier = "rr";
  c23_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c23_u, "rr",
    "rr", 0)), &c23_thisId, c23_y->rr);
  sf_mex_destroy(&c23_u);
}

static void c23_j_emlrt_marshallIn(SFc23_ModifiedInstanceStruct *chartInstance,
  const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId, real_T c23_y[3])
{
  real_T c23_dv1[3];
  int32_T c23_i18;
  (void)chartInstance;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), c23_dv1, 1, 0, 0U, 1, 0U, 2, 3,
                1);
  for (c23_i18 = 0; c23_i18 < 3; c23_i18++) {
    c23_y[c23_i18] = c23_dv1[c23_i18];
  }

  sf_mex_destroy(&c23_u);
}

static c23_struct_r4FNviKwHfdhB8nQjvQv9 c23_k_emlrt_marshallIn
  (SFc23_ModifiedInstanceStruct *chartInstance, const mxArray *c23_u, const
   emlrtMsgIdentifier *c23_parentId)
{
  c23_struct_r4FNviKwHfdhB8nQjvQv9 c23_y;
  emlrtMsgIdentifier c23_thisId;
  static const char * c23_fieldNames[1] = { "v_set" };

  c23_thisId.fParent = c23_parentId;
  sf_mex_check_struct(c23_parentId, c23_u, 1, c23_fieldNames, 0U, NULL);
  c23_thisId.fIdentifier = "v_set";
  c23_y.v_set = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c23_u, "v_set", "v_set", 0)),
    &c23_thisId);
  sf_mex_destroy(&c23_u);
  return c23_y;
}

static c23_struct_Y9F1qlBi9AhssksPwemA4G c23_l_emlrt_marshallIn
  (SFc23_ModifiedInstanceStruct *chartInstance, const mxArray *c23_u, const
   emlrtMsgIdentifier *c23_parentId)
{
  c23_struct_Y9F1qlBi9AhssksPwemA4G c23_y;
  emlrtMsgIdentifier c23_thisId;
  static const char * c23_fieldNames[3] = { "v_x", "F_fz", "F_rz" };

  c23_thisId.fParent = c23_parentId;
  sf_mex_check_struct(c23_parentId, c23_u, 3, c23_fieldNames, 0U, NULL);
  c23_thisId.fIdentifier = "v_x";
  c23_y.v_x = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c23_u, "v_x", "v_x", 0)), &c23_thisId);
  c23_thisId.fIdentifier = "F_fz";
  c23_y.F_fz = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c23_u, "F_fz", "F_fz", 0)), &c23_thisId);
  c23_thisId.fIdentifier = "F_rz";
  c23_y.F_rz = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c23_u, "F_rz", "F_rz", 0)), &c23_thisId);
  sf_mex_destroy(&c23_u);
  return c23_y;
}

static void c23_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData)
{
  const mxArray *c23_b_Par;
  const char_T *c23_identifier;
  emlrtMsgIdentifier c23_thisId;
  c23_struct_iBlsPBO3AGnt69vDoTx5zD c23_y;
  SFc23_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc23_ModifiedInstanceStruct *)chartInstanceVoid;
  c23_b_Par = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_b_Par), &c23_thisId,
    &c23_y);
  sf_mex_destroy(&c23_b_Par);
  *(c23_struct_iBlsPBO3AGnt69vDoTx5zD *)c23_outData = c23_y;
  sf_mex_destroy(&c23_mxArrayInData);
}

static const mxArray *c23_c_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  real_T c23_u;
  const mxArray *c23_y = NULL;
  SFc23_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc23_ModifiedInstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  c23_u = *(real_T *)c23_inData;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", &c23_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c23_mxArrayOutData, c23_y, false);
  return c23_mxArrayOutData;
}

static void c23_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData)
{
  const mxArray *c23_nargout;
  const char_T *c23_identifier;
  emlrtMsgIdentifier c23_thisId;
  real_T c23_y;
  SFc23_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc23_ModifiedInstanceStruct *)chartInstanceVoid;
  c23_nargout = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_nargout),
    &c23_thisId);
  sf_mex_destroy(&c23_nargout);
  *(real_T *)c23_outData = c23_y;
  sf_mex_destroy(&c23_mxArrayInData);
}

const mxArray *sf_c23_Modified_get_eml_resolved_functions_info(void)
{
  const mxArray *c23_nameCaptureInfo = NULL;
  c23_nameCaptureInfo = NULL;
  sf_mex_assign(&c23_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c23_nameCaptureInfo;
}

static const mxArray *c23_d_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  int32_T c23_u;
  const mxArray *c23_y = NULL;
  SFc23_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc23_ModifiedInstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  c23_u = *(int32_T *)c23_inData;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", &c23_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c23_mxArrayOutData, c23_y, false);
  return c23_mxArrayOutData;
}

static int32_T c23_m_emlrt_marshallIn(SFc23_ModifiedInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId)
{
  int32_T c23_y;
  int32_T c23_i19;
  (void)chartInstance;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), &c23_i19, 1, 6, 0U, 0, 0U, 0);
  c23_y = c23_i19;
  sf_mex_destroy(&c23_u);
  return c23_y;
}

static void c23_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData)
{
  const mxArray *c23_b_sfEvent;
  const char_T *c23_identifier;
  emlrtMsgIdentifier c23_thisId;
  int32_T c23_y;
  SFc23_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc23_ModifiedInstanceStruct *)chartInstanceVoid;
  c23_b_sfEvent = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_b_sfEvent),
    &c23_thisId);
  sf_mex_destroy(&c23_b_sfEvent);
  *(int32_T *)c23_outData = c23_y;
  sf_mex_destroy(&c23_mxArrayInData);
}

static const mxArray *c23_v_z4_bus_io(void *chartInstanceVoid, void *c23_pData)
{
  const mxArray *c23_mxVal = NULL;
  c23_whl_vec4 c23_tmp;
  SFc23_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc23_ModifiedInstanceStruct *)chartInstanceVoid;
  c23_mxVal = NULL;
  c23_tmp.fl = *(real_T *)&((char_T *)(c23_whl_vec4 *)c23_pData)[0];
  c23_tmp.fr = *(real_T *)&((char_T *)(c23_whl_vec4 *)c23_pData)[8];
  c23_tmp.rl = *(real_T *)&((char_T *)(c23_whl_vec4 *)c23_pData)[16];
  c23_tmp.rr = *(real_T *)&((char_T *)(c23_whl_vec4 *)c23_pData)[24];
  sf_mex_assign(&c23_mxVal, c23_sf_marshallOut(chartInstance, &c23_tmp), false);
  return c23_mxVal;
}

static uint8_T c23_n_emlrt_marshallIn(SFc23_ModifiedInstanceStruct
  *chartInstance, const mxArray *c23_b_is_active_c23_Modified, const char_T
  *c23_identifier)
{
  uint8_T c23_y;
  emlrtMsgIdentifier c23_thisId;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_o_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c23_b_is_active_c23_Modified), &c23_thisId);
  sf_mex_destroy(&c23_b_is_active_c23_Modified);
  return c23_y;
}

static uint8_T c23_o_emlrt_marshallIn(SFc23_ModifiedInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId)
{
  uint8_T c23_y;
  uint8_T c23_u0;
  (void)chartInstance;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), &c23_u0, 1, 3, 0U, 0, 0U, 0);
  c23_y = c23_u0;
  sf_mex_destroy(&c23_u);
  return c23_y;
}

static void init_dsm_address_info(SFc23_ModifiedInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc23_ModifiedInstanceStruct *chartInstance)
{
  chartInstance->c23_v_z4 = (c23_whl_vec4 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c23_F_d4 = (c23_whl_vec4 *)ssGetOutputPortSignal_wrapper
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

void sf_c23_Modified_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3812684250U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(146470283U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4275654888U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2716122653U);
}

mxArray* sf_c23_Modified_get_post_codegen_info(void);
mxArray *sf_c23_Modified_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("OcMS8rv8RU3JjKc5YauSLG");
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
    mxArray* mxPostCodegenInfo = sf_c23_Modified_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c23_Modified_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c23_Modified_jit_fallback_info(void)
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

mxArray *sf_c23_Modified_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c23_Modified_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c23_Modified(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[7],T\"F_d4\",},{M[8],M[0],T\"is_active_c23_Modified\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c23_Modified_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc23_ModifiedInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc23_ModifiedInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ModifiedMachineNumber_,
           23,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"v_z4");
          _SFD_SET_DATA_PROPS(1,2,0,1,"F_d4");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,267);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c23_v_z4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c23_v_z4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c23_b_sf_marshallOut,(MexInFcnForType)
          c23_b_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c23_v_z4);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c23_F_d4);
        _SFD_SET_DATA_VALUE_PTR(2U, &chartInstance->c23_Par);
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
  return "8QlPsK8YvvPlEKOLT26g0F";
}

static void sf_opaque_initialize_c23_Modified(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc23_ModifiedInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c23_Modified((SFc23_ModifiedInstanceStruct*)
    chartInstanceVar);
  initialize_c23_Modified((SFc23_ModifiedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c23_Modified(void *chartInstanceVar)
{
  enable_c23_Modified((SFc23_ModifiedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c23_Modified(void *chartInstanceVar)
{
  disable_c23_Modified((SFc23_ModifiedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c23_Modified(void *chartInstanceVar)
{
  sf_gateway_c23_Modified((SFc23_ModifiedInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c23_Modified(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c23_Modified((SFc23_ModifiedInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c23_Modified(SimStruct* S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c23_Modified((SFc23_ModifiedInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c23_Modified(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc23_ModifiedInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Modified_optimization_info();
    }

    finalize_c23_Modified((SFc23_ModifiedInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc23_Modified((SFc23_ModifiedInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c23_Modified(SimStruct *S)
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
    initialize_params_c23_Modified((SFc23_ModifiedInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c23_Modified(SimStruct *S)
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
      23);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,23,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,23,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,23);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,23,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,23,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,23);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3947890410U));
  ssSetChecksum1(S,(733652109U));
  ssSetChecksum2(S,(2037126046U));
  ssSetChecksum3(S,(2591082517U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c23_Modified(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c23_Modified(SimStruct *S)
{
  SFc23_ModifiedInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc23_ModifiedInstanceStruct *)utMalloc(sizeof
    (SFc23_ModifiedInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc23_ModifiedInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c23_Modified;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c23_Modified;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c23_Modified;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c23_Modified;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c23_Modified;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c23_Modified;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c23_Modified;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c23_Modified;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c23_Modified;
  chartInstance->chartInfo.mdlStart = mdlStart_c23_Modified;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c23_Modified;
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

void c23_Modified_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c23_Modified(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c23_Modified(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c23_Modified(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c23_Modified_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
