/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Modified_sfun.h"
#include "c22_Modified.h"
#include "mwmathutil.h"
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
static const char * c22_debug_family_names[15] = { "Tw1", "Tw2", "Tw3", "Tw4",
  "v_1xyw", "v_2xyw", "v_3xyw", "v_4xyw", "nargin", "nargout", "v_xv4", "v_yv4",
  "delta_w4", "v_xw4", "v_yw4" };

/* Function Declarations */
static void initialize_c22_Modified(SFc22_ModifiedInstanceStruct *chartInstance);
static void initialize_params_c22_Modified(SFc22_ModifiedInstanceStruct
  *chartInstance);
static void enable_c22_Modified(SFc22_ModifiedInstanceStruct *chartInstance);
static void disable_c22_Modified(SFc22_ModifiedInstanceStruct *chartInstance);
static void c22_update_debugger_state_c22_Modified(SFc22_ModifiedInstanceStruct *
  chartInstance);
static const mxArray *get_sim_state_c22_Modified(SFc22_ModifiedInstanceStruct
  *chartInstance);
static void set_sim_state_c22_Modified(SFc22_ModifiedInstanceStruct
  *chartInstance, const mxArray *c22_st);
static void finalize_c22_Modified(SFc22_ModifiedInstanceStruct *chartInstance);
static void sf_gateway_c22_Modified(SFc22_ModifiedInstanceStruct *chartInstance);
static void mdl_start_c22_Modified(SFc22_ModifiedInstanceStruct *chartInstance);
static void c22_chartstep_c22_Modified(SFc22_ModifiedInstanceStruct
  *chartInstance);
static void initSimStructsc22_Modified(SFc22_ModifiedInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c22_machineNumber, uint32_T
  c22_chartNumber, uint32_T c22_instanceNumber);
static const mxArray *c22_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData);
static c22_whl_vec4 c22_emlrt_marshallIn(SFc22_ModifiedInstanceStruct
  *chartInstance, const mxArray *c22_b_v_yw4, const char_T *c22_identifier);
static c22_whl_vec4 c22_b_emlrt_marshallIn(SFc22_ModifiedInstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId);
static real_T c22_c_emlrt_marshallIn(SFc22_ModifiedInstanceStruct *chartInstance,
  const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId);
static void c22_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData);
static const mxArray *c22_b_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData);
static void c22_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData);
static const mxArray *c22_c_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData);
static void c22_d_emlrt_marshallIn(SFc22_ModifiedInstanceStruct *chartInstance,
  const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId, real_T c22_y[2]);
static void c22_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData);
static const mxArray *c22_d_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData);
static void c22_e_emlrt_marshallIn(SFc22_ModifiedInstanceStruct *chartInstance,
  const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId, real_T c22_y[4]);
static void c22_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData);
static void c22_info_helper(const mxArray **c22_info);
static const mxArray *c22_emlrt_marshallOut(const char * c22_u);
static const mxArray *c22_b_emlrt_marshallOut(const uint32_T c22_u);
static void c22_eml_scalar_eg(SFc22_ModifiedInstanceStruct *chartInstance);
static void c22_eml_xgemm(SFc22_ModifiedInstanceStruct *chartInstance, real_T
  c22_A[4], real_T c22_B[2], real_T c22_C[2], real_T c22_b_C[2]);
static const mxArray *c22_e_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData);
static int32_T c22_f_emlrt_marshallIn(SFc22_ModifiedInstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId);
static void c22_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData);
static const mxArray *c22_v_xv4_bus_io(void *chartInstanceVoid, void *c22_pData);
static uint8_T c22_g_emlrt_marshallIn(SFc22_ModifiedInstanceStruct
  *chartInstance, const mxArray *c22_b_is_active_c22_Modified, const char_T
  *c22_identifier);
static uint8_T c22_h_emlrt_marshallIn(SFc22_ModifiedInstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId);
static void c22_b_eml_xgemm(SFc22_ModifiedInstanceStruct *chartInstance, real_T
  c22_A[4], real_T c22_B[2], real_T c22_C[2]);
static void init_dsm_address_info(SFc22_ModifiedInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc22_ModifiedInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c22_Modified(SFc22_ModifiedInstanceStruct *chartInstance)
{
  chartInstance->c22_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c22_is_active_c22_Modified = 0U;
}

static void initialize_params_c22_Modified(SFc22_ModifiedInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c22_Modified(SFc22_ModifiedInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c22_Modified(SFc22_ModifiedInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c22_update_debugger_state_c22_Modified(SFc22_ModifiedInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c22_Modified(SFc22_ModifiedInstanceStruct
  *chartInstance)
{
  const mxArray *c22_st;
  const mxArray *c22_y = NULL;
  const mxArray *c22_b_y = NULL;
  real_T c22_u;
  const mxArray *c22_c_y = NULL;
  real_T c22_b_u;
  const mxArray *c22_d_y = NULL;
  real_T c22_c_u;
  const mxArray *c22_e_y = NULL;
  real_T c22_d_u;
  const mxArray *c22_f_y = NULL;
  const mxArray *c22_g_y = NULL;
  real_T c22_e_u;
  const mxArray *c22_h_y = NULL;
  real_T c22_f_u;
  const mxArray *c22_i_y = NULL;
  real_T c22_g_u;
  const mxArray *c22_j_y = NULL;
  real_T c22_h_u;
  const mxArray *c22_k_y = NULL;
  uint8_T c22_hoistedGlobal;
  uint8_T c22_i_u;
  const mxArray *c22_l_y = NULL;
  c22_st = NULL;
  c22_st = NULL;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_createcellmatrix(3, 1), false);
  c22_b_y = NULL;
  sf_mex_assign(&c22_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c22_u = *(real_T *)&((char_T *)chartInstance->c22_v_xw4)[0];
  c22_c_y = NULL;
  sf_mex_assign(&c22_c_y, sf_mex_create("y", &c22_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c22_b_y, c22_c_y, "fl", "fl", 0);
  c22_b_u = *(real_T *)&((char_T *)chartInstance->c22_v_xw4)[8];
  c22_d_y = NULL;
  sf_mex_assign(&c22_d_y, sf_mex_create("y", &c22_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c22_b_y, c22_d_y, "fr", "fr", 0);
  c22_c_u = *(real_T *)&((char_T *)chartInstance->c22_v_xw4)[16];
  c22_e_y = NULL;
  sf_mex_assign(&c22_e_y, sf_mex_create("y", &c22_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c22_b_y, c22_e_y, "rl", "rl", 0);
  c22_d_u = *(real_T *)&((char_T *)chartInstance->c22_v_xw4)[24];
  c22_f_y = NULL;
  sf_mex_assign(&c22_f_y, sf_mex_create("y", &c22_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c22_b_y, c22_f_y, "rr", "rr", 0);
  sf_mex_setcell(c22_y, 0, c22_b_y);
  c22_g_y = NULL;
  sf_mex_assign(&c22_g_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c22_e_u = *(real_T *)&((char_T *)chartInstance->c22_v_yw4)[0];
  c22_h_y = NULL;
  sf_mex_assign(&c22_h_y, sf_mex_create("y", &c22_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c22_g_y, c22_h_y, "fl", "fl", 0);
  c22_f_u = *(real_T *)&((char_T *)chartInstance->c22_v_yw4)[8];
  c22_i_y = NULL;
  sf_mex_assign(&c22_i_y, sf_mex_create("y", &c22_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c22_g_y, c22_i_y, "fr", "fr", 0);
  c22_g_u = *(real_T *)&((char_T *)chartInstance->c22_v_yw4)[16];
  c22_j_y = NULL;
  sf_mex_assign(&c22_j_y, sf_mex_create("y", &c22_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c22_g_y, c22_j_y, "rl", "rl", 0);
  c22_h_u = *(real_T *)&((char_T *)chartInstance->c22_v_yw4)[24];
  c22_k_y = NULL;
  sf_mex_assign(&c22_k_y, sf_mex_create("y", &c22_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c22_g_y, c22_k_y, "rr", "rr", 0);
  sf_mex_setcell(c22_y, 1, c22_g_y);
  c22_hoistedGlobal = chartInstance->c22_is_active_c22_Modified;
  c22_i_u = c22_hoistedGlobal;
  c22_l_y = NULL;
  sf_mex_assign(&c22_l_y, sf_mex_create("y", &c22_i_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c22_y, 2, c22_l_y);
  sf_mex_assign(&c22_st, c22_y, false);
  return c22_st;
}

static void set_sim_state_c22_Modified(SFc22_ModifiedInstanceStruct
  *chartInstance, const mxArray *c22_st)
{
  const mxArray *c22_u;
  c22_whl_vec4 c22_r0;
  c22_whl_vec4 c22_r1;
  chartInstance->c22_doneDoubleBufferReInit = true;
  c22_u = sf_mex_dup(c22_st);
  c22_r0 = c22_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c22_u,
    0)), "v_xw4");
  *(real_T *)&((char_T *)chartInstance->c22_v_xw4)[0] = c22_r0.fl;
  *(real_T *)&((char_T *)chartInstance->c22_v_xw4)[8] = c22_r0.fr;
  *(real_T *)&((char_T *)chartInstance->c22_v_xw4)[16] = c22_r0.rl;
  *(real_T *)&((char_T *)chartInstance->c22_v_xw4)[24] = c22_r0.rr;
  c22_r1 = c22_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c22_u,
    1)), "v_yw4");
  *(real_T *)&((char_T *)chartInstance->c22_v_yw4)[0] = c22_r1.fl;
  *(real_T *)&((char_T *)chartInstance->c22_v_yw4)[8] = c22_r1.fr;
  *(real_T *)&((char_T *)chartInstance->c22_v_yw4)[16] = c22_r1.rl;
  *(real_T *)&((char_T *)chartInstance->c22_v_yw4)[24] = c22_r1.rr;
  chartInstance->c22_is_active_c22_Modified = c22_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c22_u, 2)),
     "is_active_c22_Modified");
  sf_mex_destroy(&c22_u);
  c22_update_debugger_state_c22_Modified(chartInstance);
  sf_mex_destroy(&c22_st);
}

static void finalize_c22_Modified(SFc22_ModifiedInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c22_Modified(SFc22_ModifiedInstanceStruct *chartInstance)
{
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 21U, chartInstance->c22_sfEvent);
  chartInstance->c22_sfEvent = CALL_EVENT;
  c22_chartstep_c22_Modified(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_ModifiedMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c22_Modified(SFc22_ModifiedInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c22_chartstep_c22_Modified(SFc22_ModifiedInstanceStruct
  *chartInstance)
{
  c22_whl_vec4 c22_b_v_xv4;
  c22_whl_vec4 c22_b_v_yv4;
  c22_whl_vec4 c22_b_delta_w4;
  uint32_T c22_debug_family_var_map[15];
  real_T c22_Tw1[4];
  real_T c22_Tw2[4];
  real_T c22_Tw3[4];
  real_T c22_Tw4[4];
  real_T c22_v_1xyw[2];
  real_T c22_v_2xyw[2];
  real_T c22_v_3xyw[2];
  real_T c22_v_4xyw[2];
  real_T c22_nargin = 3.0;
  real_T c22_nargout = 2.0;
  c22_whl_vec4 c22_b_v_xw4;
  c22_whl_vec4 c22_b_v_yw4;
  real_T c22_x;
  real_T c22_b_x;
  real_T c22_c_x;
  real_T c22_d_x;
  real_T c22_e_x;
  real_T c22_f_x;
  real_T c22_g_x;
  real_T c22_h_x;
  real_T c22_i_x;
  real_T c22_j_x;
  real_T c22_k_x;
  real_T c22_l_x;
  real_T c22_m_x;
  real_T c22_n_x;
  real_T c22_o_x;
  real_T c22_p_x;
  real_T c22_q_x;
  real_T c22_r_x;
  real_T c22_s_x;
  real_T c22_t_x;
  real_T c22_u_x;
  real_T c22_v_x;
  real_T c22_w_x;
  real_T c22_x_x;
  real_T c22_y_x;
  real_T c22_ab_x;
  real_T c22_bb_x;
  real_T c22_cb_x;
  real_T c22_db_x;
  real_T c22_eb_x;
  real_T c22_fb_x;
  real_T c22_gb_x;
  int32_T c22_i0;
  int32_T c22_i1;
  int32_T c22_i2;
  int32_T c22_i3;
  real_T c22_a[4];
  real_T c22_b[2];
  int32_T c22_i4;
  int32_T c22_i5;
  real_T c22_dv0[2];
  int32_T c22_i6;
  real_T c22_b_a[4];
  int32_T c22_i7;
  real_T c22_b_b[2];
  int32_T c22_i8;
  int32_T c22_i9;
  int32_T c22_i10;
  int32_T c22_i11;
  int32_T c22_i12;
  int32_T c22_i13;
  int32_T c22_i14;
  int32_T c22_i15;
  real_T c22_c_a[4];
  int32_T c22_i16;
  real_T c22_c_b[2];
  int32_T c22_i17;
  int32_T c22_i18;
  int32_T c22_i19;
  int32_T c22_i20;
  int32_T c22_i21;
  int32_T c22_i22;
  int32_T c22_i23;
  int32_T c22_i24;
  real_T c22_d_a[4];
  int32_T c22_i25;
  real_T c22_d_b[2];
  int32_T c22_i26;
  int32_T c22_i27;
  int32_T c22_i28;
  int32_T c22_i29;
  int32_T c22_i30;
  int32_T c22_i31;
  int32_T c22_i32;
  int32_T c22_i33;
  real_T c22_e_a[4];
  int32_T c22_i34;
  real_T c22_e_b[2];
  int32_T c22_i35;
  c22_whl_vec4 c22_r2;
  c22_whl_vec4 c22_r3;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 21U, chartInstance->c22_sfEvent);
  c22_b_v_xv4.fl = *(real_T *)&((char_T *)chartInstance->c22_v_xv4)[0];
  c22_b_v_xv4.fr = *(real_T *)&((char_T *)chartInstance->c22_v_xv4)[8];
  c22_b_v_xv4.rl = *(real_T *)&((char_T *)chartInstance->c22_v_xv4)[16];
  c22_b_v_xv4.rr = *(real_T *)&((char_T *)chartInstance->c22_v_xv4)[24];
  c22_b_v_yv4.fl = *(real_T *)&((char_T *)chartInstance->c22_v_yv4)[0];
  c22_b_v_yv4.fr = *(real_T *)&((char_T *)chartInstance->c22_v_yv4)[8];
  c22_b_v_yv4.rl = *(real_T *)&((char_T *)chartInstance->c22_v_yv4)[16];
  c22_b_v_yv4.rr = *(real_T *)&((char_T *)chartInstance->c22_v_yv4)[24];
  c22_b_delta_w4.fl = *(real_T *)&((char_T *)chartInstance->c22_delta_w4)[0];
  c22_b_delta_w4.fr = *(real_T *)&((char_T *)chartInstance->c22_delta_w4)[8];
  c22_b_delta_w4.rl = *(real_T *)&((char_T *)chartInstance->c22_delta_w4)[16];
  c22_b_delta_w4.rr = *(real_T *)&((char_T *)chartInstance->c22_delta_w4)[24];
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 15U, 15U, c22_debug_family_names,
    c22_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c22_Tw1, 0U, c22_d_sf_marshallOut,
    c22_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c22_Tw2, 1U, c22_d_sf_marshallOut,
    c22_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c22_Tw3, 2U, c22_d_sf_marshallOut,
    c22_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c22_Tw4, 3U, c22_d_sf_marshallOut,
    c22_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c22_v_1xyw, 4U, c22_c_sf_marshallOut,
    c22_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c22_v_2xyw, 5U, c22_c_sf_marshallOut,
    c22_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c22_v_3xyw, 6U, c22_c_sf_marshallOut,
    c22_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c22_v_4xyw, 7U, c22_c_sf_marshallOut,
    c22_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_nargin, 8U, c22_b_sf_marshallOut,
    c22_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_nargout, 9U, c22_b_sf_marshallOut,
    c22_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c22_b_v_xv4, 10U, c22_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c22_b_v_yv4, 11U, c22_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c22_b_delta_w4, 12U, c22_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_b_v_xw4, 13U, c22_sf_marshallOut,
    c22_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_b_v_yw4, 14U, c22_sf_marshallOut,
    c22_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 5);
  c22_x = c22_b_delta_w4.fl;
  c22_b_x = c22_x;
  c22_b_x = muDoubleScalarCos(c22_b_x);
  c22_c_x = c22_b_delta_w4.fl;
  c22_d_x = c22_c_x;
  c22_d_x = muDoubleScalarSin(c22_d_x);
  c22_e_x = c22_b_delta_w4.fl;
  c22_f_x = c22_e_x;
  c22_f_x = muDoubleScalarSin(c22_f_x);
  c22_g_x = c22_b_delta_w4.fl;
  c22_h_x = c22_g_x;
  c22_h_x = muDoubleScalarCos(c22_h_x);
  c22_Tw1[0] = c22_b_x;
  c22_Tw1[2] = -c22_d_x;
  c22_Tw1[1] = c22_f_x;
  c22_Tw1[3] = c22_h_x;
  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 6);
  c22_i_x = c22_b_delta_w4.fr;
  c22_j_x = c22_i_x;
  c22_j_x = muDoubleScalarCos(c22_j_x);
  c22_k_x = c22_b_delta_w4.fr;
  c22_l_x = c22_k_x;
  c22_l_x = muDoubleScalarSin(c22_l_x);
  c22_m_x = c22_b_delta_w4.fr;
  c22_n_x = c22_m_x;
  c22_n_x = muDoubleScalarSin(c22_n_x);
  c22_o_x = c22_b_delta_w4.fr;
  c22_p_x = c22_o_x;
  c22_p_x = muDoubleScalarCos(c22_p_x);
  c22_Tw2[0] = c22_j_x;
  c22_Tw2[2] = -c22_l_x;
  c22_Tw2[1] = c22_n_x;
  c22_Tw2[3] = c22_p_x;
  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 7);
  c22_q_x = c22_b_delta_w4.rl;
  c22_r_x = c22_q_x;
  c22_r_x = muDoubleScalarCos(c22_r_x);
  c22_s_x = c22_b_delta_w4.rl;
  c22_t_x = c22_s_x;
  c22_t_x = muDoubleScalarSin(c22_t_x);
  c22_u_x = c22_b_delta_w4.rl;
  c22_v_x = c22_u_x;
  c22_v_x = muDoubleScalarSin(c22_v_x);
  c22_w_x = c22_b_delta_w4.rl;
  c22_x_x = c22_w_x;
  c22_x_x = muDoubleScalarCos(c22_x_x);
  c22_Tw3[0] = c22_r_x;
  c22_Tw3[2] = -c22_t_x;
  c22_Tw3[1] = c22_v_x;
  c22_Tw3[3] = c22_x_x;
  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 8);
  c22_y_x = c22_b_delta_w4.rr;
  c22_ab_x = c22_y_x;
  c22_ab_x = muDoubleScalarCos(c22_ab_x);
  c22_bb_x = c22_b_delta_w4.rr;
  c22_cb_x = c22_bb_x;
  c22_cb_x = muDoubleScalarSin(c22_cb_x);
  c22_db_x = c22_b_delta_w4.rr;
  c22_eb_x = c22_db_x;
  c22_eb_x = muDoubleScalarSin(c22_eb_x);
  c22_fb_x = c22_b_delta_w4.rr;
  c22_gb_x = c22_fb_x;
  c22_gb_x = muDoubleScalarCos(c22_gb_x);
  c22_Tw4[0] = c22_ab_x;
  c22_Tw4[2] = -c22_cb_x;
  c22_Tw4[1] = c22_eb_x;
  c22_Tw4[3] = c22_gb_x;
  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 10);
  c22_i0 = 0;
  for (c22_i1 = 0; c22_i1 < 2; c22_i1++) {
    c22_i2 = 0;
    for (c22_i3 = 0; c22_i3 < 2; c22_i3++) {
      c22_a[c22_i3 + c22_i0] = c22_Tw1[c22_i2 + c22_i1];
      c22_i2 += 2;
    }

    c22_i0 += 2;
  }

  c22_b[0] = c22_b_v_xv4.fl;
  c22_b[1] = c22_b_v_yv4.fl;
  c22_eml_scalar_eg(chartInstance);
  c22_eml_scalar_eg(chartInstance);
  for (c22_i4 = 0; c22_i4 < 2; c22_i4++) {
    c22_v_1xyw[c22_i4] = 0.0;
  }

  for (c22_i5 = 0; c22_i5 < 2; c22_i5++) {
    c22_dv0[c22_i5] = 0.0;
  }

  for (c22_i6 = 0; c22_i6 < 4; c22_i6++) {
    c22_b_a[c22_i6] = c22_a[c22_i6];
  }

  for (c22_i7 = 0; c22_i7 < 2; c22_i7++) {
    c22_b_b[c22_i7] = c22_b[c22_i7];
  }

  c22_b_eml_xgemm(chartInstance, c22_b_a, c22_b_b, c22_dv0);
  for (c22_i8 = 0; c22_i8 < 2; c22_i8++) {
    c22_v_1xyw[c22_i8] = c22_dv0[c22_i8];
  }

  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 11);
  c22_i9 = 0;
  for (c22_i10 = 0; c22_i10 < 2; c22_i10++) {
    c22_i11 = 0;
    for (c22_i12 = 0; c22_i12 < 2; c22_i12++) {
      c22_a[c22_i12 + c22_i9] = c22_Tw2[c22_i11 + c22_i10];
      c22_i11 += 2;
    }

    c22_i9 += 2;
  }

  c22_b[0] = c22_b_v_xv4.fr;
  c22_b[1] = c22_b_v_yv4.fr;
  c22_eml_scalar_eg(chartInstance);
  c22_eml_scalar_eg(chartInstance);
  for (c22_i13 = 0; c22_i13 < 2; c22_i13++) {
    c22_v_2xyw[c22_i13] = 0.0;
  }

  for (c22_i14 = 0; c22_i14 < 2; c22_i14++) {
    c22_dv0[c22_i14] = 0.0;
  }

  for (c22_i15 = 0; c22_i15 < 4; c22_i15++) {
    c22_c_a[c22_i15] = c22_a[c22_i15];
  }

  for (c22_i16 = 0; c22_i16 < 2; c22_i16++) {
    c22_c_b[c22_i16] = c22_b[c22_i16];
  }

  c22_b_eml_xgemm(chartInstance, c22_c_a, c22_c_b, c22_dv0);
  for (c22_i17 = 0; c22_i17 < 2; c22_i17++) {
    c22_v_2xyw[c22_i17] = c22_dv0[c22_i17];
  }

  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 12);
  c22_i18 = 0;
  for (c22_i19 = 0; c22_i19 < 2; c22_i19++) {
    c22_i20 = 0;
    for (c22_i21 = 0; c22_i21 < 2; c22_i21++) {
      c22_a[c22_i21 + c22_i18] = c22_Tw3[c22_i20 + c22_i19];
      c22_i20 += 2;
    }

    c22_i18 += 2;
  }

  c22_b[0] = c22_b_v_xv4.rl;
  c22_b[1] = c22_b_v_yv4.rl;
  c22_eml_scalar_eg(chartInstance);
  c22_eml_scalar_eg(chartInstance);
  for (c22_i22 = 0; c22_i22 < 2; c22_i22++) {
    c22_v_3xyw[c22_i22] = 0.0;
  }

  for (c22_i23 = 0; c22_i23 < 2; c22_i23++) {
    c22_dv0[c22_i23] = 0.0;
  }

  for (c22_i24 = 0; c22_i24 < 4; c22_i24++) {
    c22_d_a[c22_i24] = c22_a[c22_i24];
  }

  for (c22_i25 = 0; c22_i25 < 2; c22_i25++) {
    c22_d_b[c22_i25] = c22_b[c22_i25];
  }

  c22_b_eml_xgemm(chartInstance, c22_d_a, c22_d_b, c22_dv0);
  for (c22_i26 = 0; c22_i26 < 2; c22_i26++) {
    c22_v_3xyw[c22_i26] = c22_dv0[c22_i26];
  }

  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 13);
  c22_i27 = 0;
  for (c22_i28 = 0; c22_i28 < 2; c22_i28++) {
    c22_i29 = 0;
    for (c22_i30 = 0; c22_i30 < 2; c22_i30++) {
      c22_a[c22_i30 + c22_i27] = c22_Tw4[c22_i29 + c22_i28];
      c22_i29 += 2;
    }

    c22_i27 += 2;
  }

  c22_b[0] = c22_b_v_xv4.rr;
  c22_b[1] = c22_b_v_yv4.rr;
  c22_eml_scalar_eg(chartInstance);
  c22_eml_scalar_eg(chartInstance);
  for (c22_i31 = 0; c22_i31 < 2; c22_i31++) {
    c22_v_4xyw[c22_i31] = 0.0;
  }

  for (c22_i32 = 0; c22_i32 < 2; c22_i32++) {
    c22_dv0[c22_i32] = 0.0;
  }

  for (c22_i33 = 0; c22_i33 < 4; c22_i33++) {
    c22_e_a[c22_i33] = c22_a[c22_i33];
  }

  for (c22_i34 = 0; c22_i34 < 2; c22_i34++) {
    c22_e_b[c22_i34] = c22_b[c22_i34];
  }

  c22_b_eml_xgemm(chartInstance, c22_e_a, c22_e_b, c22_dv0);
  for (c22_i35 = 0; c22_i35 < 2; c22_i35++) {
    c22_v_4xyw[c22_i35] = c22_dv0[c22_i35];
  }

  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 15);
  c22_r2.fl = c22_v_1xyw[0];
  c22_r2.fr = c22_v_2xyw[0];
  c22_r2.rl = c22_v_3xyw[0];
  c22_r2.rr = c22_v_4xyw[0];
  c22_b_v_xw4 = c22_r2;
  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 16);
  c22_r3.fl = c22_v_1xyw[1];
  c22_r3.fr = c22_v_2xyw[1];
  c22_r3.rl = c22_v_3xyw[1];
  c22_r3.rr = c22_v_4xyw[1];
  c22_b_v_yw4 = c22_r3;
  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, -16);
  _SFD_SYMBOL_SCOPE_POP();
  *(real_T *)&((char_T *)chartInstance->c22_v_xw4)[0] = c22_b_v_xw4.fl;
  *(real_T *)&((char_T *)chartInstance->c22_v_xw4)[8] = c22_b_v_xw4.fr;
  *(real_T *)&((char_T *)chartInstance->c22_v_xw4)[16] = c22_b_v_xw4.rl;
  *(real_T *)&((char_T *)chartInstance->c22_v_xw4)[24] = c22_b_v_xw4.rr;
  *(real_T *)&((char_T *)chartInstance->c22_v_yw4)[0] = c22_b_v_yw4.fl;
  *(real_T *)&((char_T *)chartInstance->c22_v_yw4)[8] = c22_b_v_yw4.fr;
  *(real_T *)&((char_T *)chartInstance->c22_v_yw4)[16] = c22_b_v_yw4.rl;
  *(real_T *)&((char_T *)chartInstance->c22_v_yw4)[24] = c22_b_v_yw4.rr;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 21U, chartInstance->c22_sfEvent);
}

static void initSimStructsc22_Modified(SFc22_ModifiedInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c22_machineNumber, uint32_T
  c22_chartNumber, uint32_T c22_instanceNumber)
{
  (void)c22_machineNumber;
  (void)c22_chartNumber;
  (void)c22_instanceNumber;
}

static const mxArray *c22_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData)
{
  const mxArray *c22_mxArrayOutData = NULL;
  c22_whl_vec4 c22_u;
  const mxArray *c22_y = NULL;
  real_T c22_b_u;
  const mxArray *c22_b_y = NULL;
  real_T c22_c_u;
  const mxArray *c22_c_y = NULL;
  real_T c22_d_u;
  const mxArray *c22_d_y = NULL;
  real_T c22_e_u;
  const mxArray *c22_e_y = NULL;
  SFc22_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc22_ModifiedInstanceStruct *)chartInstanceVoid;
  c22_mxArrayOutData = NULL;
  c22_u = *(c22_whl_vec4 *)c22_inData;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c22_b_u = c22_u.fl;
  c22_b_y = NULL;
  sf_mex_assign(&c22_b_y, sf_mex_create("y", &c22_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c22_y, c22_b_y, "fl", "fl", 0);
  c22_c_u = c22_u.fr;
  c22_c_y = NULL;
  sf_mex_assign(&c22_c_y, sf_mex_create("y", &c22_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c22_y, c22_c_y, "fr", "fr", 0);
  c22_d_u = c22_u.rl;
  c22_d_y = NULL;
  sf_mex_assign(&c22_d_y, sf_mex_create("y", &c22_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c22_y, c22_d_y, "rl", "rl", 0);
  c22_e_u = c22_u.rr;
  c22_e_y = NULL;
  sf_mex_assign(&c22_e_y, sf_mex_create("y", &c22_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c22_y, c22_e_y, "rr", "rr", 0);
  sf_mex_assign(&c22_mxArrayOutData, c22_y, false);
  return c22_mxArrayOutData;
}

static c22_whl_vec4 c22_emlrt_marshallIn(SFc22_ModifiedInstanceStruct
  *chartInstance, const mxArray *c22_b_v_yw4, const char_T *c22_identifier)
{
  c22_whl_vec4 c22_y;
  emlrtMsgIdentifier c22_thisId;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_y = c22_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c22_b_v_yw4),
    &c22_thisId);
  sf_mex_destroy(&c22_b_v_yw4);
  return c22_y;
}

static c22_whl_vec4 c22_b_emlrt_marshallIn(SFc22_ModifiedInstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId)
{
  c22_whl_vec4 c22_y;
  emlrtMsgIdentifier c22_thisId;
  static const char * c22_fieldNames[4] = { "fl", "fr", "rl", "rr" };

  c22_thisId.fParent = c22_parentId;
  sf_mex_check_struct(c22_parentId, c22_u, 4, c22_fieldNames, 0U, NULL);
  c22_thisId.fIdentifier = "fl";
  c22_y.fl = c22_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c22_u, "fl", "fl", 0)), &c22_thisId);
  c22_thisId.fIdentifier = "fr";
  c22_y.fr = c22_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c22_u, "fr", "fr", 0)), &c22_thisId);
  c22_thisId.fIdentifier = "rl";
  c22_y.rl = c22_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c22_u, "rl", "rl", 0)), &c22_thisId);
  c22_thisId.fIdentifier = "rr";
  c22_y.rr = c22_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c22_u, "rr", "rr", 0)), &c22_thisId);
  sf_mex_destroy(&c22_u);
  return c22_y;
}

static real_T c22_c_emlrt_marshallIn(SFc22_ModifiedInstanceStruct *chartInstance,
  const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId)
{
  real_T c22_y;
  real_T c22_d0;
  (void)chartInstance;
  sf_mex_import(c22_parentId, sf_mex_dup(c22_u), &c22_d0, 1, 0, 0U, 0, 0U, 0);
  c22_y = c22_d0;
  sf_mex_destroy(&c22_u);
  return c22_y;
}

static void c22_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData)
{
  const mxArray *c22_b_v_yw4;
  const char_T *c22_identifier;
  emlrtMsgIdentifier c22_thisId;
  c22_whl_vec4 c22_y;
  SFc22_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc22_ModifiedInstanceStruct *)chartInstanceVoid;
  c22_b_v_yw4 = sf_mex_dup(c22_mxArrayInData);
  c22_identifier = c22_varName;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_y = c22_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c22_b_v_yw4),
    &c22_thisId);
  sf_mex_destroy(&c22_b_v_yw4);
  *(c22_whl_vec4 *)c22_outData = c22_y;
  sf_mex_destroy(&c22_mxArrayInData);
}

static const mxArray *c22_b_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData)
{
  const mxArray *c22_mxArrayOutData = NULL;
  real_T c22_u;
  const mxArray *c22_y = NULL;
  SFc22_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc22_ModifiedInstanceStruct *)chartInstanceVoid;
  c22_mxArrayOutData = NULL;
  c22_u = *(real_T *)c22_inData;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_create("y", &c22_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c22_mxArrayOutData, c22_y, false);
  return c22_mxArrayOutData;
}

static void c22_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData)
{
  const mxArray *c22_nargout;
  const char_T *c22_identifier;
  emlrtMsgIdentifier c22_thisId;
  real_T c22_y;
  SFc22_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc22_ModifiedInstanceStruct *)chartInstanceVoid;
  c22_nargout = sf_mex_dup(c22_mxArrayInData);
  c22_identifier = c22_varName;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_y = c22_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c22_nargout),
    &c22_thisId);
  sf_mex_destroy(&c22_nargout);
  *(real_T *)c22_outData = c22_y;
  sf_mex_destroy(&c22_mxArrayInData);
}

static const mxArray *c22_c_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData)
{
  const mxArray *c22_mxArrayOutData = NULL;
  int32_T c22_i36;
  real_T c22_b_inData[2];
  int32_T c22_i37;
  real_T c22_u[2];
  const mxArray *c22_y = NULL;
  SFc22_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc22_ModifiedInstanceStruct *)chartInstanceVoid;
  c22_mxArrayOutData = NULL;
  for (c22_i36 = 0; c22_i36 < 2; c22_i36++) {
    c22_b_inData[c22_i36] = (*(real_T (*)[2])c22_inData)[c22_i36];
  }

  for (c22_i37 = 0; c22_i37 < 2; c22_i37++) {
    c22_u[c22_i37] = c22_b_inData[c22_i37];
  }

  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_create("y", c22_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c22_mxArrayOutData, c22_y, false);
  return c22_mxArrayOutData;
}

static void c22_d_emlrt_marshallIn(SFc22_ModifiedInstanceStruct *chartInstance,
  const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId, real_T c22_y[2])
{
  real_T c22_dv1[2];
  int32_T c22_i38;
  (void)chartInstance;
  sf_mex_import(c22_parentId, sf_mex_dup(c22_u), c22_dv1, 1, 0, 0U, 1, 0U, 1, 2);
  for (c22_i38 = 0; c22_i38 < 2; c22_i38++) {
    c22_y[c22_i38] = c22_dv1[c22_i38];
  }

  sf_mex_destroy(&c22_u);
}

static void c22_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData)
{
  const mxArray *c22_v_4xyw;
  const char_T *c22_identifier;
  emlrtMsgIdentifier c22_thisId;
  real_T c22_y[2];
  int32_T c22_i39;
  SFc22_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc22_ModifiedInstanceStruct *)chartInstanceVoid;
  c22_v_4xyw = sf_mex_dup(c22_mxArrayInData);
  c22_identifier = c22_varName;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c22_v_4xyw), &c22_thisId,
    c22_y);
  sf_mex_destroy(&c22_v_4xyw);
  for (c22_i39 = 0; c22_i39 < 2; c22_i39++) {
    (*(real_T (*)[2])c22_outData)[c22_i39] = c22_y[c22_i39];
  }

  sf_mex_destroy(&c22_mxArrayInData);
}

static const mxArray *c22_d_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData)
{
  const mxArray *c22_mxArrayOutData = NULL;
  int32_T c22_i40;
  int32_T c22_i41;
  int32_T c22_i42;
  real_T c22_b_inData[4];
  int32_T c22_i43;
  int32_T c22_i44;
  int32_T c22_i45;
  real_T c22_u[4];
  const mxArray *c22_y = NULL;
  SFc22_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc22_ModifiedInstanceStruct *)chartInstanceVoid;
  c22_mxArrayOutData = NULL;
  c22_i40 = 0;
  for (c22_i41 = 0; c22_i41 < 2; c22_i41++) {
    for (c22_i42 = 0; c22_i42 < 2; c22_i42++) {
      c22_b_inData[c22_i42 + c22_i40] = (*(real_T (*)[4])c22_inData)[c22_i42 +
        c22_i40];
    }

    c22_i40 += 2;
  }

  c22_i43 = 0;
  for (c22_i44 = 0; c22_i44 < 2; c22_i44++) {
    for (c22_i45 = 0; c22_i45 < 2; c22_i45++) {
      c22_u[c22_i45 + c22_i43] = c22_b_inData[c22_i45 + c22_i43];
    }

    c22_i43 += 2;
  }

  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_create("y", c22_u, 0, 0U, 1U, 0U, 2, 2, 2), false);
  sf_mex_assign(&c22_mxArrayOutData, c22_y, false);
  return c22_mxArrayOutData;
}

static void c22_e_emlrt_marshallIn(SFc22_ModifiedInstanceStruct *chartInstance,
  const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId, real_T c22_y[4])
{
  real_T c22_dv2[4];
  int32_T c22_i46;
  (void)chartInstance;
  sf_mex_import(c22_parentId, sf_mex_dup(c22_u), c22_dv2, 1, 0, 0U, 1, 0U, 2, 2,
                2);
  for (c22_i46 = 0; c22_i46 < 4; c22_i46++) {
    c22_y[c22_i46] = c22_dv2[c22_i46];
  }

  sf_mex_destroy(&c22_u);
}

static void c22_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData)
{
  const mxArray *c22_Tw4;
  const char_T *c22_identifier;
  emlrtMsgIdentifier c22_thisId;
  real_T c22_y[4];
  int32_T c22_i47;
  int32_T c22_i48;
  int32_T c22_i49;
  SFc22_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc22_ModifiedInstanceStruct *)chartInstanceVoid;
  c22_Tw4 = sf_mex_dup(c22_mxArrayInData);
  c22_identifier = c22_varName;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c22_Tw4), &c22_thisId, c22_y);
  sf_mex_destroy(&c22_Tw4);
  c22_i47 = 0;
  for (c22_i48 = 0; c22_i48 < 2; c22_i48++) {
    for (c22_i49 = 0; c22_i49 < 2; c22_i49++) {
      (*(real_T (*)[4])c22_outData)[c22_i49 + c22_i47] = c22_y[c22_i49 + c22_i47];
    }

    c22_i47 += 2;
  }

  sf_mex_destroy(&c22_mxArrayInData);
}

const mxArray *sf_c22_Modified_get_eml_resolved_functions_info(void)
{
  const mxArray *c22_nameCaptureInfo = NULL;
  c22_nameCaptureInfo = NULL;
  sf_mex_assign(&c22_nameCaptureInfo, sf_mex_createstruct("structure", 2, 17, 1),
                false);
  c22_info_helper(&c22_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c22_nameCaptureInfo);
  return c22_nameCaptureInfo;
}

static void c22_info_helper(const mxArray **c22_info)
{
  const mxArray *c22_rhs0 = NULL;
  const mxArray *c22_lhs0 = NULL;
  const mxArray *c22_rhs1 = NULL;
  const mxArray *c22_lhs1 = NULL;
  const mxArray *c22_rhs2 = NULL;
  const mxArray *c22_lhs2 = NULL;
  const mxArray *c22_rhs3 = NULL;
  const mxArray *c22_lhs3 = NULL;
  const mxArray *c22_rhs4 = NULL;
  const mxArray *c22_lhs4 = NULL;
  const mxArray *c22_rhs5 = NULL;
  const mxArray *c22_lhs5 = NULL;
  const mxArray *c22_rhs6 = NULL;
  const mxArray *c22_lhs6 = NULL;
  const mxArray *c22_rhs7 = NULL;
  const mxArray *c22_lhs7 = NULL;
  const mxArray *c22_rhs8 = NULL;
  const mxArray *c22_lhs8 = NULL;
  const mxArray *c22_rhs9 = NULL;
  const mxArray *c22_lhs9 = NULL;
  const mxArray *c22_rhs10 = NULL;
  const mxArray *c22_lhs10 = NULL;
  const mxArray *c22_rhs11 = NULL;
  const mxArray *c22_lhs11 = NULL;
  const mxArray *c22_rhs12 = NULL;
  const mxArray *c22_lhs12 = NULL;
  const mxArray *c22_rhs13 = NULL;
  const mxArray *c22_lhs13 = NULL;
  const mxArray *c22_rhs14 = NULL;
  const mxArray *c22_lhs14 = NULL;
  const mxArray *c22_rhs15 = NULL;
  const mxArray *c22_lhs15 = NULL;
  const mxArray *c22_rhs16 = NULL;
  const mxArray *c22_lhs16 = NULL;
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("cos"), "name", "name", 0);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1395328496U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c22_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c22_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("eml_scalar_cos"), "name",
                  "name", 1);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1286818722U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c22_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c22_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(""), "context", "context", 2);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("sin"), "name", "name", 2);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1395328504U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c22_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c22_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("eml_scalar_sin"), "name",
                  "name", 3);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1286818736U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c22_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c22_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(""), "context", "context", 4);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 4);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1383877294U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c22_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c22_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 5);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 5);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c22_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c22_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 6);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 6);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c22_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c22_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 7);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 7);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c22_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c22_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 8);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c22_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c22_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  9);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1375980690U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c22_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c22_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 10);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c22_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c22_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("coder.internal.blas.xgemm"),
                  "name", "name", 11);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c22_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c22_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 12);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 12);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c22_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c22_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!below_threshold"),
                  "context", "context", 13);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 13);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c22_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c22_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 14);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 14);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1393330858U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c22_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c22_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 15);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 15);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c22_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c22_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 16);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "coder.internal.refblas.xgemm"), "name", "name", 16);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c22_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c22_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs16), "lhs", "lhs",
                  16);
  sf_mex_destroy(&c22_rhs0);
  sf_mex_destroy(&c22_lhs0);
  sf_mex_destroy(&c22_rhs1);
  sf_mex_destroy(&c22_lhs1);
  sf_mex_destroy(&c22_rhs2);
  sf_mex_destroy(&c22_lhs2);
  sf_mex_destroy(&c22_rhs3);
  sf_mex_destroy(&c22_lhs3);
  sf_mex_destroy(&c22_rhs4);
  sf_mex_destroy(&c22_lhs4);
  sf_mex_destroy(&c22_rhs5);
  sf_mex_destroy(&c22_lhs5);
  sf_mex_destroy(&c22_rhs6);
  sf_mex_destroy(&c22_lhs6);
  sf_mex_destroy(&c22_rhs7);
  sf_mex_destroy(&c22_lhs7);
  sf_mex_destroy(&c22_rhs8);
  sf_mex_destroy(&c22_lhs8);
  sf_mex_destroy(&c22_rhs9);
  sf_mex_destroy(&c22_lhs9);
  sf_mex_destroy(&c22_rhs10);
  sf_mex_destroy(&c22_lhs10);
  sf_mex_destroy(&c22_rhs11);
  sf_mex_destroy(&c22_lhs11);
  sf_mex_destroy(&c22_rhs12);
  sf_mex_destroy(&c22_lhs12);
  sf_mex_destroy(&c22_rhs13);
  sf_mex_destroy(&c22_lhs13);
  sf_mex_destroy(&c22_rhs14);
  sf_mex_destroy(&c22_lhs14);
  sf_mex_destroy(&c22_rhs15);
  sf_mex_destroy(&c22_lhs15);
  sf_mex_destroy(&c22_rhs16);
  sf_mex_destroy(&c22_lhs16);
}

static const mxArray *c22_emlrt_marshallOut(const char * c22_u)
{
  const mxArray *c22_y = NULL;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_create("y", c22_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c22_u)), false);
  return c22_y;
}

static const mxArray *c22_b_emlrt_marshallOut(const uint32_T c22_u)
{
  const mxArray *c22_y = NULL;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_create("y", &c22_u, 7, 0U, 0U, 0U, 0), false);
  return c22_y;
}

static void c22_eml_scalar_eg(SFc22_ModifiedInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c22_eml_xgemm(SFc22_ModifiedInstanceStruct *chartInstance, real_T
  c22_A[4], real_T c22_B[2], real_T c22_C[2], real_T c22_b_C[2])
{
  int32_T c22_i50;
  int32_T c22_i51;
  real_T c22_b_A[4];
  int32_T c22_i52;
  real_T c22_b_B[2];
  for (c22_i50 = 0; c22_i50 < 2; c22_i50++) {
    c22_b_C[c22_i50] = c22_C[c22_i50];
  }

  for (c22_i51 = 0; c22_i51 < 4; c22_i51++) {
    c22_b_A[c22_i51] = c22_A[c22_i51];
  }

  for (c22_i52 = 0; c22_i52 < 2; c22_i52++) {
    c22_b_B[c22_i52] = c22_B[c22_i52];
  }

  c22_b_eml_xgemm(chartInstance, c22_b_A, c22_b_B, c22_b_C);
}

static const mxArray *c22_e_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData)
{
  const mxArray *c22_mxArrayOutData = NULL;
  int32_T c22_u;
  const mxArray *c22_y = NULL;
  SFc22_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc22_ModifiedInstanceStruct *)chartInstanceVoid;
  c22_mxArrayOutData = NULL;
  c22_u = *(int32_T *)c22_inData;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_create("y", &c22_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c22_mxArrayOutData, c22_y, false);
  return c22_mxArrayOutData;
}

static int32_T c22_f_emlrt_marshallIn(SFc22_ModifiedInstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId)
{
  int32_T c22_y;
  int32_T c22_i53;
  (void)chartInstance;
  sf_mex_import(c22_parentId, sf_mex_dup(c22_u), &c22_i53, 1, 6, 0U, 0, 0U, 0);
  c22_y = c22_i53;
  sf_mex_destroy(&c22_u);
  return c22_y;
}

static void c22_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData)
{
  const mxArray *c22_b_sfEvent;
  const char_T *c22_identifier;
  emlrtMsgIdentifier c22_thisId;
  int32_T c22_y;
  SFc22_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc22_ModifiedInstanceStruct *)chartInstanceVoid;
  c22_b_sfEvent = sf_mex_dup(c22_mxArrayInData);
  c22_identifier = c22_varName;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_y = c22_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c22_b_sfEvent),
    &c22_thisId);
  sf_mex_destroy(&c22_b_sfEvent);
  *(int32_T *)c22_outData = c22_y;
  sf_mex_destroy(&c22_mxArrayInData);
}

static const mxArray *c22_v_xv4_bus_io(void *chartInstanceVoid, void *c22_pData)
{
  const mxArray *c22_mxVal = NULL;
  c22_whl_vec4 c22_tmp;
  SFc22_ModifiedInstanceStruct *chartInstance;
  chartInstance = (SFc22_ModifiedInstanceStruct *)chartInstanceVoid;
  c22_mxVal = NULL;
  c22_tmp.fl = *(real_T *)&((char_T *)(c22_whl_vec4 *)c22_pData)[0];
  c22_tmp.fr = *(real_T *)&((char_T *)(c22_whl_vec4 *)c22_pData)[8];
  c22_tmp.rl = *(real_T *)&((char_T *)(c22_whl_vec4 *)c22_pData)[16];
  c22_tmp.rr = *(real_T *)&((char_T *)(c22_whl_vec4 *)c22_pData)[24];
  sf_mex_assign(&c22_mxVal, c22_sf_marshallOut(chartInstance, &c22_tmp), false);
  return c22_mxVal;
}

static uint8_T c22_g_emlrt_marshallIn(SFc22_ModifiedInstanceStruct
  *chartInstance, const mxArray *c22_b_is_active_c22_Modified, const char_T
  *c22_identifier)
{
  uint8_T c22_y;
  emlrtMsgIdentifier c22_thisId;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_y = c22_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c22_b_is_active_c22_Modified), &c22_thisId);
  sf_mex_destroy(&c22_b_is_active_c22_Modified);
  return c22_y;
}

static uint8_T c22_h_emlrt_marshallIn(SFc22_ModifiedInstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId)
{
  uint8_T c22_y;
  uint8_T c22_u0;
  (void)chartInstance;
  sf_mex_import(c22_parentId, sf_mex_dup(c22_u), &c22_u0, 1, 3, 0U, 0, 0U, 0);
  c22_y = c22_u0;
  sf_mex_destroy(&c22_u);
  return c22_y;
}

static void c22_b_eml_xgemm(SFc22_ModifiedInstanceStruct *chartInstance, real_T
  c22_A[4], real_T c22_B[2], real_T c22_C[2])
{
  int32_T c22_i54;
  int32_T c22_i55;
  int32_T c22_i56;
  (void)chartInstance;
  for (c22_i54 = 0; c22_i54 < 2; c22_i54++) {
    c22_C[c22_i54] = 0.0;
    c22_i55 = 0;
    for (c22_i56 = 0; c22_i56 < 2; c22_i56++) {
      c22_C[c22_i54] += c22_A[c22_i55 + c22_i54] * c22_B[c22_i56];
      c22_i55 += 2;
    }
  }
}

static void init_dsm_address_info(SFc22_ModifiedInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc22_ModifiedInstanceStruct *chartInstance)
{
  chartInstance->c22_v_xv4 = (c22_whl_vec4 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c22_v_xw4 = (c22_whl_vec4 *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c22_v_yw4 = (c22_whl_vec4 *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c22_v_yv4 = (c22_whl_vec4 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c22_delta_w4 = (c22_whl_vec4 *)ssGetInputPortSignal_wrapper
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

void sf_c22_Modified_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2573818043U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1667149729U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(400932572U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(981931697U);
}

mxArray* sf_c22_Modified_get_post_codegen_info(void);
mxArray *sf_c22_Modified_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("RwTBEKcRFTrNYkxp3DCTeB");
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
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
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
    mxArray* mxPostCodegenInfo = sf_c22_Modified_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c22_Modified_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c22_Modified_jit_fallback_info(void)
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

mxArray *sf_c22_Modified_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c22_Modified_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c22_Modified(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"v_xw4\",},{M[1],M[6],T\"v_yw4\",},{M[8],M[0],T\"is_active_c22_Modified\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c22_Modified_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc22_ModifiedInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc22_ModifiedInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ModifiedMachineNumber_,
           22,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"v_xv4");
          _SFD_SET_DATA_PROPS(1,2,0,1,"v_xw4");
          _SFD_SET_DATA_PROPS(2,2,0,1,"v_yw4");
          _SFD_SET_DATA_PROPS(3,1,1,0,"v_yv4");
          _SFD_SET_DATA_PROPS(4,1,1,0,"delta_w4");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,822);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c22_v_xv4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c22_v_xv4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c22_v_xv4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c22_v_xv4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c22_v_xv4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c22_v_xv4);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c22_v_xw4);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c22_v_yw4);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c22_v_yv4);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c22_delta_w4);
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
  return "Ry1PGFKv4FlGo9qr0Q1IBD";
}

static void sf_opaque_initialize_c22_Modified(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc22_ModifiedInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c22_Modified((SFc22_ModifiedInstanceStruct*)
    chartInstanceVar);
  initialize_c22_Modified((SFc22_ModifiedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c22_Modified(void *chartInstanceVar)
{
  enable_c22_Modified((SFc22_ModifiedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c22_Modified(void *chartInstanceVar)
{
  disable_c22_Modified((SFc22_ModifiedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c22_Modified(void *chartInstanceVar)
{
  sf_gateway_c22_Modified((SFc22_ModifiedInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c22_Modified(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c22_Modified((SFc22_ModifiedInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c22_Modified(SimStruct* S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c22_Modified((SFc22_ModifiedInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c22_Modified(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc22_ModifiedInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Modified_optimization_info();
    }

    finalize_c22_Modified((SFc22_ModifiedInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc22_Modified((SFc22_ModifiedInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c22_Modified(SimStruct *S)
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
    initialize_params_c22_Modified((SFc22_ModifiedInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c22_Modified(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Modified_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      22);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,22,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,22,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,22);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,22,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,22,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,22);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1322819483U));
  ssSetChecksum1(S,(1276541866U));
  ssSetChecksum2(S,(1185441415U));
  ssSetChecksum3(S,(1198932729U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c22_Modified(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c22_Modified(SimStruct *S)
{
  SFc22_ModifiedInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc22_ModifiedInstanceStruct *)utMalloc(sizeof
    (SFc22_ModifiedInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc22_ModifiedInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c22_Modified;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c22_Modified;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c22_Modified;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c22_Modified;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c22_Modified;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c22_Modified;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c22_Modified;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c22_Modified;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c22_Modified;
  chartInstance->chartInfo.mdlStart = mdlStart_c22_Modified;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c22_Modified;
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

void c22_Modified_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c22_Modified(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c22_Modified(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c22_Modified(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c22_Modified_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
