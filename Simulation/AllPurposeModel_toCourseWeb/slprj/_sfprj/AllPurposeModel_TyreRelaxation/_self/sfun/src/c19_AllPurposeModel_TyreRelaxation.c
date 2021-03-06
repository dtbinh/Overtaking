/* Include files */

#include <stddef.h>
#include "blas.h"
#include "AllPurposeModel_TyreRelaxation_sfun.h"
#include "c19_AllPurposeModel_TyreRelaxation.h"
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
static const char * c19_debug_family_names[11] = { "F_xyv4_fl_temp",
  "F_xyv4_fr_temp", "F_xyv4_rl_temp", "F_xyv4_rr_temp", "nargin", "nargout",
  "F_xw4", "F_yw4", "delta_w4", "F_xv4", "F_yv4" };

/* Function Declarations */
static void initialize_c19_AllPurposeModel_TyreRelaxation
  (SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void initialize_params_c19_AllPurposeModel_TyreRelaxation
  (SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void enable_c19_AllPurposeModel_TyreRelaxation
  (SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void disable_c19_AllPurposeModel_TyreRelaxation
  (SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void c19_update_debugger_state_c19_AllPurposeModel_TyreRelaxation
  (SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c19_AllPurposeModel_TyreRelaxation
  (SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void set_sim_state_c19_AllPurposeModel_TyreRelaxation
  (SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c19_st);
static void finalize_c19_AllPurposeModel_TyreRelaxation
  (SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void sf_gateway_c19_AllPurposeModel_TyreRelaxation
  (SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void mdl_start_c19_AllPurposeModel_TyreRelaxation
  (SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void c19_chartstep_c19_AllPurposeModel_TyreRelaxation
  (SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void initSimStructsc19_AllPurposeModel_TyreRelaxation
  (SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c19_machineNumber, uint32_T
  c19_chartNumber, uint32_T c19_instanceNumber);
static const mxArray *c19_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData);
static c19_whl_vec4 c19_emlrt_marshallIn
  (SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c19_b_F_yv4, const char_T *c19_identifier);
static c19_whl_vec4 c19_b_emlrt_marshallIn
  (SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId);
static real_T c19_c_emlrt_marshallIn
  (SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId);
static void c19_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData);
static const mxArray *c19_b_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData);
static void c19_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData);
static const mxArray *c19_c_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData);
static void c19_d_emlrt_marshallIn
  (SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId, real_T c19_y[2]);
static void c19_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData);
static void c19_info_helper(const mxArray **c19_info);
static const mxArray *c19_emlrt_marshallOut(const char * c19_u);
static const mxArray *c19_b_emlrt_marshallOut(const uint32_T c19_u);
static void c19_eml_scalar_eg(SFc19_AllPurposeModel_TyreRelaxationInstanceStruct
  *chartInstance);
static void c19_eml_xgemm(SFc19_AllPurposeModel_TyreRelaxationInstanceStruct
  *chartInstance, real_T c19_A[4], real_T c19_B[2], real_T c19_C[2], real_T
  c19_b_C[2]);
static const mxArray *c19_d_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData);
static int32_T c19_e_emlrt_marshallIn
  (SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId);
static void c19_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData);
static const mxArray *c19_F_xw4_bus_io(void *chartInstanceVoid, void *c19_pData);
static uint8_T c19_f_emlrt_marshallIn
  (SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c19_b_is_active_c19_AllPurposeModel_TyreRelaxation, const char_T
   *c19_identifier);
static uint8_T c19_g_emlrt_marshallIn
  (SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId);
static void c19_b_eml_xgemm(SFc19_AllPurposeModel_TyreRelaxationInstanceStruct
  *chartInstance, real_T c19_A[4], real_T c19_B[2], real_T c19_C[2]);
static void init_dsm_address_info
  (SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);
static void init_simulink_io_address
  (SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c19_AllPurposeModel_TyreRelaxation
  (SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  chartInstance->c19_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c19_is_active_c19_AllPurposeModel_TyreRelaxation = 0U;
}

static void initialize_params_c19_AllPurposeModel_TyreRelaxation
  (SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c19_AllPurposeModel_TyreRelaxation
  (SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c19_AllPurposeModel_TyreRelaxation
  (SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c19_update_debugger_state_c19_AllPurposeModel_TyreRelaxation
  (SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c19_AllPurposeModel_TyreRelaxation
  (SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  const mxArray *c19_st;
  const mxArray *c19_y = NULL;
  const mxArray *c19_b_y = NULL;
  real_T c19_u;
  const mxArray *c19_c_y = NULL;
  real_T c19_b_u;
  const mxArray *c19_d_y = NULL;
  real_T c19_c_u;
  const mxArray *c19_e_y = NULL;
  real_T c19_d_u;
  const mxArray *c19_f_y = NULL;
  const mxArray *c19_g_y = NULL;
  real_T c19_e_u;
  const mxArray *c19_h_y = NULL;
  real_T c19_f_u;
  const mxArray *c19_i_y = NULL;
  real_T c19_g_u;
  const mxArray *c19_j_y = NULL;
  real_T c19_h_u;
  const mxArray *c19_k_y = NULL;
  uint8_T c19_hoistedGlobal;
  uint8_T c19_i_u;
  const mxArray *c19_l_y = NULL;
  c19_st = NULL;
  c19_st = NULL;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_createcellmatrix(3, 1), false);
  c19_b_y = NULL;
  sf_mex_assign(&c19_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c19_u = *(real_T *)&((char_T *)chartInstance->c19_F_xv4)[0];
  c19_c_y = NULL;
  sf_mex_assign(&c19_c_y, sf_mex_create("y", &c19_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c19_b_y, c19_c_y, "fl", "fl", 0);
  c19_b_u = *(real_T *)&((char_T *)chartInstance->c19_F_xv4)[8];
  c19_d_y = NULL;
  sf_mex_assign(&c19_d_y, sf_mex_create("y", &c19_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c19_b_y, c19_d_y, "fr", "fr", 0);
  c19_c_u = *(real_T *)&((char_T *)chartInstance->c19_F_xv4)[16];
  c19_e_y = NULL;
  sf_mex_assign(&c19_e_y, sf_mex_create("y", &c19_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c19_b_y, c19_e_y, "rl", "rl", 0);
  c19_d_u = *(real_T *)&((char_T *)chartInstance->c19_F_xv4)[24];
  c19_f_y = NULL;
  sf_mex_assign(&c19_f_y, sf_mex_create("y", &c19_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c19_b_y, c19_f_y, "rr", "rr", 0);
  sf_mex_setcell(c19_y, 0, c19_b_y);
  c19_g_y = NULL;
  sf_mex_assign(&c19_g_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c19_e_u = *(real_T *)&((char_T *)chartInstance->c19_F_yv4)[0];
  c19_h_y = NULL;
  sf_mex_assign(&c19_h_y, sf_mex_create("y", &c19_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c19_g_y, c19_h_y, "fl", "fl", 0);
  c19_f_u = *(real_T *)&((char_T *)chartInstance->c19_F_yv4)[8];
  c19_i_y = NULL;
  sf_mex_assign(&c19_i_y, sf_mex_create("y", &c19_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c19_g_y, c19_i_y, "fr", "fr", 0);
  c19_g_u = *(real_T *)&((char_T *)chartInstance->c19_F_yv4)[16];
  c19_j_y = NULL;
  sf_mex_assign(&c19_j_y, sf_mex_create("y", &c19_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c19_g_y, c19_j_y, "rl", "rl", 0);
  c19_h_u = *(real_T *)&((char_T *)chartInstance->c19_F_yv4)[24];
  c19_k_y = NULL;
  sf_mex_assign(&c19_k_y, sf_mex_create("y", &c19_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c19_g_y, c19_k_y, "rr", "rr", 0);
  sf_mex_setcell(c19_y, 1, c19_g_y);
  c19_hoistedGlobal =
    chartInstance->c19_is_active_c19_AllPurposeModel_TyreRelaxation;
  c19_i_u = c19_hoistedGlobal;
  c19_l_y = NULL;
  sf_mex_assign(&c19_l_y, sf_mex_create("y", &c19_i_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c19_y, 2, c19_l_y);
  sf_mex_assign(&c19_st, c19_y, false);
  return c19_st;
}

static void set_sim_state_c19_AllPurposeModel_TyreRelaxation
  (SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c19_st)
{
  const mxArray *c19_u;
  c19_whl_vec4 c19_r0;
  c19_whl_vec4 c19_r1;
  chartInstance->c19_doneDoubleBufferReInit = true;
  c19_u = sf_mex_dup(c19_st);
  c19_r0 = c19_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c19_u,
    0)), "F_xv4");
  *(real_T *)&((char_T *)chartInstance->c19_F_xv4)[0] = c19_r0.fl;
  *(real_T *)&((char_T *)chartInstance->c19_F_xv4)[8] = c19_r0.fr;
  *(real_T *)&((char_T *)chartInstance->c19_F_xv4)[16] = c19_r0.rl;
  *(real_T *)&((char_T *)chartInstance->c19_F_xv4)[24] = c19_r0.rr;
  c19_r1 = c19_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c19_u,
    1)), "F_yv4");
  *(real_T *)&((char_T *)chartInstance->c19_F_yv4)[0] = c19_r1.fl;
  *(real_T *)&((char_T *)chartInstance->c19_F_yv4)[8] = c19_r1.fr;
  *(real_T *)&((char_T *)chartInstance->c19_F_yv4)[16] = c19_r1.rl;
  *(real_T *)&((char_T *)chartInstance->c19_F_yv4)[24] = c19_r1.rr;
  chartInstance->c19_is_active_c19_AllPurposeModel_TyreRelaxation =
    c19_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c19_u, 2)),
    "is_active_c19_AllPurposeModel_TyreRelaxation");
  sf_mex_destroy(&c19_u);
  c19_update_debugger_state_c19_AllPurposeModel_TyreRelaxation(chartInstance);
  sf_mex_destroy(&c19_st);
}

static void finalize_c19_AllPurposeModel_TyreRelaxation
  (SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c19_AllPurposeModel_TyreRelaxation
  (SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 14U, chartInstance->c19_sfEvent);
  chartInstance->c19_sfEvent = CALL_EVENT;
  c19_chartstep_c19_AllPurposeModel_TyreRelaxation(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_AllPurposeModel_TyreRelaxationMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void mdl_start_c19_AllPurposeModel_TyreRelaxation
  (SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c19_chartstep_c19_AllPurposeModel_TyreRelaxation
  (SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  c19_whl_vec4 c19_b_F_xw4;
  c19_whl_vec4 c19_b_F_yw4;
  c19_whl_vec4 c19_b_delta_w4;
  uint32_T c19_debug_family_var_map[11];
  real_T c19_F_xyv4_fl_temp[2];
  real_T c19_F_xyv4_fr_temp[2];
  real_T c19_F_xyv4_rl_temp[2];
  real_T c19_F_xyv4_rr_temp[2];
  real_T c19_nargin = 3.0;
  real_T c19_nargout = 2.0;
  c19_whl_vec4 c19_b_F_xv4;
  c19_whl_vec4 c19_b_F_yv4;
  real_T c19_x;
  real_T c19_b_x;
  real_T c19_c_x;
  real_T c19_d_x;
  real_T c19_e_x;
  real_T c19_f_x;
  real_T c19_g_x;
  real_T c19_h_x;
  real_T c19_a[4];
  real_T c19_b[2];
  int32_T c19_i0;
  int32_T c19_i1;
  real_T c19_dv0[2];
  int32_T c19_i2;
  real_T c19_b_a[4];
  int32_T c19_i3;
  real_T c19_b_b[2];
  int32_T c19_i4;
  real_T c19_i_x;
  real_T c19_j_x;
  real_T c19_k_x;
  real_T c19_l_x;
  real_T c19_m_x;
  real_T c19_n_x;
  real_T c19_o_x;
  real_T c19_p_x;
  int32_T c19_i5;
  int32_T c19_i6;
  int32_T c19_i7;
  real_T c19_c_a[4];
  int32_T c19_i8;
  real_T c19_c_b[2];
  int32_T c19_i9;
  real_T c19_q_x;
  real_T c19_r_x;
  real_T c19_s_x;
  real_T c19_t_x;
  real_T c19_u_x;
  real_T c19_v_x;
  real_T c19_w_x;
  real_T c19_x_x;
  int32_T c19_i10;
  int32_T c19_i11;
  int32_T c19_i12;
  real_T c19_d_a[4];
  int32_T c19_i13;
  real_T c19_d_b[2];
  int32_T c19_i14;
  real_T c19_y_x;
  real_T c19_ab_x;
  real_T c19_bb_x;
  real_T c19_cb_x;
  real_T c19_db_x;
  real_T c19_eb_x;
  real_T c19_fb_x;
  real_T c19_gb_x;
  int32_T c19_i15;
  int32_T c19_i16;
  int32_T c19_i17;
  real_T c19_e_a[4];
  int32_T c19_i18;
  real_T c19_e_b[2];
  int32_T c19_i19;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 14U, chartInstance->c19_sfEvent);
  c19_b_F_xw4.fl = *(real_T *)&((char_T *)chartInstance->c19_F_xw4)[0];
  c19_b_F_xw4.fr = *(real_T *)&((char_T *)chartInstance->c19_F_xw4)[8];
  c19_b_F_xw4.rl = *(real_T *)&((char_T *)chartInstance->c19_F_xw4)[16];
  c19_b_F_xw4.rr = *(real_T *)&((char_T *)chartInstance->c19_F_xw4)[24];
  c19_b_F_yw4.fl = *(real_T *)&((char_T *)chartInstance->c19_F_yw4)[0];
  c19_b_F_yw4.fr = *(real_T *)&((char_T *)chartInstance->c19_F_yw4)[8];
  c19_b_F_yw4.rl = *(real_T *)&((char_T *)chartInstance->c19_F_yw4)[16];
  c19_b_F_yw4.rr = *(real_T *)&((char_T *)chartInstance->c19_F_yw4)[24];
  c19_b_delta_w4.fl = *(real_T *)&((char_T *)chartInstance->c19_delta_w4)[0];
  c19_b_delta_w4.fr = *(real_T *)&((char_T *)chartInstance->c19_delta_w4)[8];
  c19_b_delta_w4.rl = *(real_T *)&((char_T *)chartInstance->c19_delta_w4)[16];
  c19_b_delta_w4.rr = *(real_T *)&((char_T *)chartInstance->c19_delta_w4)[24];
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 11U, 11U, c19_debug_family_names,
    c19_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c19_F_xyv4_fl_temp, 0U,
    c19_c_sf_marshallOut, c19_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c19_F_xyv4_fr_temp, 1U,
    c19_c_sf_marshallOut, c19_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c19_F_xyv4_rl_temp, 2U,
    c19_c_sf_marshallOut, c19_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c19_F_xyv4_rr_temp, 3U,
    c19_c_sf_marshallOut, c19_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_nargin, 4U, c19_b_sf_marshallOut,
    c19_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_nargout, 5U, c19_b_sf_marshallOut,
    c19_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c19_b_F_xw4, 6U, c19_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c19_b_F_yw4, 7U, c19_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c19_b_delta_w4, 8U, c19_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_b_F_xv4, 9U, c19_sf_marshallOut,
    c19_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_b_F_yv4, 10U, c19_sf_marshallOut,
    c19_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 4);
  c19_x = c19_b_delta_w4.fl;
  c19_b_x = c19_x;
  c19_b_x = muDoubleScalarCos(c19_b_x);
  c19_c_x = c19_b_delta_w4.fl;
  c19_d_x = c19_c_x;
  c19_d_x = muDoubleScalarSin(c19_d_x);
  c19_e_x = c19_b_delta_w4.fl;
  c19_f_x = c19_e_x;
  c19_f_x = muDoubleScalarSin(c19_f_x);
  c19_g_x = c19_b_delta_w4.fl;
  c19_h_x = c19_g_x;
  c19_h_x = muDoubleScalarCos(c19_h_x);
  c19_a[0] = c19_b_x;
  c19_a[2] = -c19_d_x;
  c19_a[1] = c19_f_x;
  c19_a[3] = c19_h_x;
  c19_b[0] = c19_b_F_xw4.fl;
  c19_b[1] = c19_b_F_yw4.fl;
  c19_eml_scalar_eg(chartInstance);
  c19_eml_scalar_eg(chartInstance);
  for (c19_i0 = 0; c19_i0 < 2; c19_i0++) {
    c19_F_xyv4_fl_temp[c19_i0] = 0.0;
  }

  for (c19_i1 = 0; c19_i1 < 2; c19_i1++) {
    c19_dv0[c19_i1] = 0.0;
  }

  for (c19_i2 = 0; c19_i2 < 4; c19_i2++) {
    c19_b_a[c19_i2] = c19_a[c19_i2];
  }

  for (c19_i3 = 0; c19_i3 < 2; c19_i3++) {
    c19_b_b[c19_i3] = c19_b[c19_i3];
  }

  c19_b_eml_xgemm(chartInstance, c19_b_a, c19_b_b, c19_dv0);
  for (c19_i4 = 0; c19_i4 < 2; c19_i4++) {
    c19_F_xyv4_fl_temp[c19_i4] = c19_dv0[c19_i4];
  }

  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 5);
  c19_i_x = c19_b_delta_w4.fr;
  c19_j_x = c19_i_x;
  c19_j_x = muDoubleScalarCos(c19_j_x);
  c19_k_x = c19_b_delta_w4.fr;
  c19_l_x = c19_k_x;
  c19_l_x = muDoubleScalarSin(c19_l_x);
  c19_m_x = c19_b_delta_w4.fr;
  c19_n_x = c19_m_x;
  c19_n_x = muDoubleScalarSin(c19_n_x);
  c19_o_x = c19_b_delta_w4.fr;
  c19_p_x = c19_o_x;
  c19_p_x = muDoubleScalarCos(c19_p_x);
  c19_a[0] = c19_j_x;
  c19_a[2] = -c19_l_x;
  c19_a[1] = c19_n_x;
  c19_a[3] = c19_p_x;
  c19_b[0] = c19_b_F_xw4.fr;
  c19_b[1] = c19_b_F_yw4.fr;
  c19_eml_scalar_eg(chartInstance);
  c19_eml_scalar_eg(chartInstance);
  for (c19_i5 = 0; c19_i5 < 2; c19_i5++) {
    c19_F_xyv4_fr_temp[c19_i5] = 0.0;
  }

  for (c19_i6 = 0; c19_i6 < 2; c19_i6++) {
    c19_dv0[c19_i6] = 0.0;
  }

  for (c19_i7 = 0; c19_i7 < 4; c19_i7++) {
    c19_c_a[c19_i7] = c19_a[c19_i7];
  }

  for (c19_i8 = 0; c19_i8 < 2; c19_i8++) {
    c19_c_b[c19_i8] = c19_b[c19_i8];
  }

  c19_b_eml_xgemm(chartInstance, c19_c_a, c19_c_b, c19_dv0);
  for (c19_i9 = 0; c19_i9 < 2; c19_i9++) {
    c19_F_xyv4_fr_temp[c19_i9] = c19_dv0[c19_i9];
  }

  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 6);
  c19_q_x = c19_b_delta_w4.rl;
  c19_r_x = c19_q_x;
  c19_r_x = muDoubleScalarCos(c19_r_x);
  c19_s_x = c19_b_delta_w4.rl;
  c19_t_x = c19_s_x;
  c19_t_x = muDoubleScalarSin(c19_t_x);
  c19_u_x = c19_b_delta_w4.rl;
  c19_v_x = c19_u_x;
  c19_v_x = muDoubleScalarSin(c19_v_x);
  c19_w_x = c19_b_delta_w4.rl;
  c19_x_x = c19_w_x;
  c19_x_x = muDoubleScalarCos(c19_x_x);
  c19_a[0] = c19_r_x;
  c19_a[2] = -c19_t_x;
  c19_a[1] = c19_v_x;
  c19_a[3] = c19_x_x;
  c19_b[0] = c19_b_F_xw4.rl;
  c19_b[1] = c19_b_F_yw4.rl;
  c19_eml_scalar_eg(chartInstance);
  c19_eml_scalar_eg(chartInstance);
  for (c19_i10 = 0; c19_i10 < 2; c19_i10++) {
    c19_F_xyv4_rl_temp[c19_i10] = 0.0;
  }

  for (c19_i11 = 0; c19_i11 < 2; c19_i11++) {
    c19_dv0[c19_i11] = 0.0;
  }

  for (c19_i12 = 0; c19_i12 < 4; c19_i12++) {
    c19_d_a[c19_i12] = c19_a[c19_i12];
  }

  for (c19_i13 = 0; c19_i13 < 2; c19_i13++) {
    c19_d_b[c19_i13] = c19_b[c19_i13];
  }

  c19_b_eml_xgemm(chartInstance, c19_d_a, c19_d_b, c19_dv0);
  for (c19_i14 = 0; c19_i14 < 2; c19_i14++) {
    c19_F_xyv4_rl_temp[c19_i14] = c19_dv0[c19_i14];
  }

  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 7);
  c19_y_x = c19_b_delta_w4.rr;
  c19_ab_x = c19_y_x;
  c19_ab_x = muDoubleScalarCos(c19_ab_x);
  c19_bb_x = c19_b_delta_w4.rr;
  c19_cb_x = c19_bb_x;
  c19_cb_x = muDoubleScalarSin(c19_cb_x);
  c19_db_x = c19_b_delta_w4.rr;
  c19_eb_x = c19_db_x;
  c19_eb_x = muDoubleScalarSin(c19_eb_x);
  c19_fb_x = c19_b_delta_w4.rr;
  c19_gb_x = c19_fb_x;
  c19_gb_x = muDoubleScalarCos(c19_gb_x);
  c19_a[0] = c19_ab_x;
  c19_a[2] = -c19_cb_x;
  c19_a[1] = c19_eb_x;
  c19_a[3] = c19_gb_x;
  c19_b[0] = c19_b_F_xw4.rr;
  c19_b[1] = c19_b_F_yw4.rr;
  c19_eml_scalar_eg(chartInstance);
  c19_eml_scalar_eg(chartInstance);
  for (c19_i15 = 0; c19_i15 < 2; c19_i15++) {
    c19_F_xyv4_rr_temp[c19_i15] = 0.0;
  }

  for (c19_i16 = 0; c19_i16 < 2; c19_i16++) {
    c19_dv0[c19_i16] = 0.0;
  }

  for (c19_i17 = 0; c19_i17 < 4; c19_i17++) {
    c19_e_a[c19_i17] = c19_a[c19_i17];
  }

  for (c19_i18 = 0; c19_i18 < 2; c19_i18++) {
    c19_e_b[c19_i18] = c19_b[c19_i18];
  }

  c19_b_eml_xgemm(chartInstance, c19_e_a, c19_e_b, c19_dv0);
  for (c19_i19 = 0; c19_i19 < 2; c19_i19++) {
    c19_F_xyv4_rr_temp[c19_i19] = c19_dv0[c19_i19];
  }

  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 9);
  c19_b_F_xv4.fl = c19_F_xyv4_fl_temp[0];
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 10);
  c19_b_F_xv4.fr = c19_F_xyv4_fr_temp[0];
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 11);
  c19_b_F_xv4.rl = c19_F_xyv4_rl_temp[0];
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 12);
  c19_b_F_xv4.rr = c19_F_xyv4_rr_temp[0];
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 14);
  c19_b_F_yv4.fl = c19_F_xyv4_fl_temp[1];
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 15);
  c19_b_F_yv4.fr = c19_F_xyv4_fr_temp[1];
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 16);
  c19_b_F_yv4.rl = c19_F_xyv4_rl_temp[1];
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 17);
  c19_b_F_yv4.rr = c19_F_xyv4_rr_temp[1];
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, -17);
  _SFD_SYMBOL_SCOPE_POP();
  *(real_T *)&((char_T *)chartInstance->c19_F_xv4)[0] = c19_b_F_xv4.fl;
  *(real_T *)&((char_T *)chartInstance->c19_F_xv4)[8] = c19_b_F_xv4.fr;
  *(real_T *)&((char_T *)chartInstance->c19_F_xv4)[16] = c19_b_F_xv4.rl;
  *(real_T *)&((char_T *)chartInstance->c19_F_xv4)[24] = c19_b_F_xv4.rr;
  *(real_T *)&((char_T *)chartInstance->c19_F_yv4)[0] = c19_b_F_yv4.fl;
  *(real_T *)&((char_T *)chartInstance->c19_F_yv4)[8] = c19_b_F_yv4.fr;
  *(real_T *)&((char_T *)chartInstance->c19_F_yv4)[16] = c19_b_F_yv4.rl;
  *(real_T *)&((char_T *)chartInstance->c19_F_yv4)[24] = c19_b_F_yv4.rr;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 14U, chartInstance->c19_sfEvent);
}

static void initSimStructsc19_AllPurposeModel_TyreRelaxation
  (SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c19_machineNumber, uint32_T
  c19_chartNumber, uint32_T c19_instanceNumber)
{
  (void)c19_machineNumber;
  (void)c19_chartNumber;
  (void)c19_instanceNumber;
}

static const mxArray *c19_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData)
{
  const mxArray *c19_mxArrayOutData = NULL;
  c19_whl_vec4 c19_u;
  const mxArray *c19_y = NULL;
  real_T c19_b_u;
  const mxArray *c19_b_y = NULL;
  real_T c19_c_u;
  const mxArray *c19_c_y = NULL;
  real_T c19_d_u;
  const mxArray *c19_d_y = NULL;
  real_T c19_e_u;
  const mxArray *c19_e_y = NULL;
  SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c19_mxArrayOutData = NULL;
  c19_u = *(c19_whl_vec4 *)c19_inData;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c19_b_u = c19_u.fl;
  c19_b_y = NULL;
  sf_mex_assign(&c19_b_y, sf_mex_create("y", &c19_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c19_y, c19_b_y, "fl", "fl", 0);
  c19_c_u = c19_u.fr;
  c19_c_y = NULL;
  sf_mex_assign(&c19_c_y, sf_mex_create("y", &c19_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c19_y, c19_c_y, "fr", "fr", 0);
  c19_d_u = c19_u.rl;
  c19_d_y = NULL;
  sf_mex_assign(&c19_d_y, sf_mex_create("y", &c19_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c19_y, c19_d_y, "rl", "rl", 0);
  c19_e_u = c19_u.rr;
  c19_e_y = NULL;
  sf_mex_assign(&c19_e_y, sf_mex_create("y", &c19_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c19_y, c19_e_y, "rr", "rr", 0);
  sf_mex_assign(&c19_mxArrayOutData, c19_y, false);
  return c19_mxArrayOutData;
}

static c19_whl_vec4 c19_emlrt_marshallIn
  (SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c19_b_F_yv4, const char_T *c19_identifier)
{
  c19_whl_vec4 c19_y;
  emlrtMsgIdentifier c19_thisId;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_y = c19_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_b_F_yv4),
    &c19_thisId);
  sf_mex_destroy(&c19_b_F_yv4);
  return c19_y;
}

static c19_whl_vec4 c19_b_emlrt_marshallIn
  (SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId)
{
  c19_whl_vec4 c19_y;
  emlrtMsgIdentifier c19_thisId;
  static const char * c19_fieldNames[4] = { "fl", "fr", "rl", "rr" };

  c19_thisId.fParent = c19_parentId;
  sf_mex_check_struct(c19_parentId, c19_u, 4, c19_fieldNames, 0U, NULL);
  c19_thisId.fIdentifier = "fl";
  c19_y.fl = c19_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c19_u, "fl", "fl", 0)), &c19_thisId);
  c19_thisId.fIdentifier = "fr";
  c19_y.fr = c19_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c19_u, "fr", "fr", 0)), &c19_thisId);
  c19_thisId.fIdentifier = "rl";
  c19_y.rl = c19_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c19_u, "rl", "rl", 0)), &c19_thisId);
  c19_thisId.fIdentifier = "rr";
  c19_y.rr = c19_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c19_u, "rr", "rr", 0)), &c19_thisId);
  sf_mex_destroy(&c19_u);
  return c19_y;
}

static real_T c19_c_emlrt_marshallIn
  (SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId)
{
  real_T c19_y;
  real_T c19_d0;
  (void)chartInstance;
  sf_mex_import(c19_parentId, sf_mex_dup(c19_u), &c19_d0, 1, 0, 0U, 0, 0U, 0);
  c19_y = c19_d0;
  sf_mex_destroy(&c19_u);
  return c19_y;
}

static void c19_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData)
{
  const mxArray *c19_b_F_yv4;
  const char_T *c19_identifier;
  emlrtMsgIdentifier c19_thisId;
  c19_whl_vec4 c19_y;
  SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c19_b_F_yv4 = sf_mex_dup(c19_mxArrayInData);
  c19_identifier = c19_varName;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_y = c19_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_b_F_yv4),
    &c19_thisId);
  sf_mex_destroy(&c19_b_F_yv4);
  *(c19_whl_vec4 *)c19_outData = c19_y;
  sf_mex_destroy(&c19_mxArrayInData);
}

static const mxArray *c19_b_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData)
{
  const mxArray *c19_mxArrayOutData = NULL;
  real_T c19_u;
  const mxArray *c19_y = NULL;
  SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c19_mxArrayOutData = NULL;
  c19_u = *(real_T *)c19_inData;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", &c19_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c19_mxArrayOutData, c19_y, false);
  return c19_mxArrayOutData;
}

static void c19_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData)
{
  const mxArray *c19_nargout;
  const char_T *c19_identifier;
  emlrtMsgIdentifier c19_thisId;
  real_T c19_y;
  SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c19_nargout = sf_mex_dup(c19_mxArrayInData);
  c19_identifier = c19_varName;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_y = c19_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_nargout),
    &c19_thisId);
  sf_mex_destroy(&c19_nargout);
  *(real_T *)c19_outData = c19_y;
  sf_mex_destroy(&c19_mxArrayInData);
}

static const mxArray *c19_c_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData)
{
  const mxArray *c19_mxArrayOutData = NULL;
  int32_T c19_i20;
  real_T c19_b_inData[2];
  int32_T c19_i21;
  real_T c19_u[2];
  const mxArray *c19_y = NULL;
  SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c19_mxArrayOutData = NULL;
  for (c19_i20 = 0; c19_i20 < 2; c19_i20++) {
    c19_b_inData[c19_i20] = (*(real_T (*)[2])c19_inData)[c19_i20];
  }

  for (c19_i21 = 0; c19_i21 < 2; c19_i21++) {
    c19_u[c19_i21] = c19_b_inData[c19_i21];
  }

  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", c19_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c19_mxArrayOutData, c19_y, false);
  return c19_mxArrayOutData;
}

static void c19_d_emlrt_marshallIn
  (SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId, real_T c19_y[2])
{
  real_T c19_dv1[2];
  int32_T c19_i22;
  (void)chartInstance;
  sf_mex_import(c19_parentId, sf_mex_dup(c19_u), c19_dv1, 1, 0, 0U, 1, 0U, 1, 2);
  for (c19_i22 = 0; c19_i22 < 2; c19_i22++) {
    c19_y[c19_i22] = c19_dv1[c19_i22];
  }

  sf_mex_destroy(&c19_u);
}

static void c19_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData)
{
  const mxArray *c19_F_xyv4_rr_temp;
  const char_T *c19_identifier;
  emlrtMsgIdentifier c19_thisId;
  real_T c19_y[2];
  int32_T c19_i23;
  SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c19_F_xyv4_rr_temp = sf_mex_dup(c19_mxArrayInData);
  c19_identifier = c19_varName;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_F_xyv4_rr_temp),
    &c19_thisId, c19_y);
  sf_mex_destroy(&c19_F_xyv4_rr_temp);
  for (c19_i23 = 0; c19_i23 < 2; c19_i23++) {
    (*(real_T (*)[2])c19_outData)[c19_i23] = c19_y[c19_i23];
  }

  sf_mex_destroy(&c19_mxArrayInData);
}

const mxArray
  *sf_c19_AllPurposeModel_TyreRelaxation_get_eml_resolved_functions_info(void)
{
  const mxArray *c19_nameCaptureInfo = NULL;
  c19_nameCaptureInfo = NULL;
  sf_mex_assign(&c19_nameCaptureInfo, sf_mex_createstruct("structure", 2, 17, 1),
                false);
  c19_info_helper(&c19_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c19_nameCaptureInfo);
  return c19_nameCaptureInfo;
}

static void c19_info_helper(const mxArray **c19_info)
{
  const mxArray *c19_rhs0 = NULL;
  const mxArray *c19_lhs0 = NULL;
  const mxArray *c19_rhs1 = NULL;
  const mxArray *c19_lhs1 = NULL;
  const mxArray *c19_rhs2 = NULL;
  const mxArray *c19_lhs2 = NULL;
  const mxArray *c19_rhs3 = NULL;
  const mxArray *c19_lhs3 = NULL;
  const mxArray *c19_rhs4 = NULL;
  const mxArray *c19_lhs4 = NULL;
  const mxArray *c19_rhs5 = NULL;
  const mxArray *c19_lhs5 = NULL;
  const mxArray *c19_rhs6 = NULL;
  const mxArray *c19_lhs6 = NULL;
  const mxArray *c19_rhs7 = NULL;
  const mxArray *c19_lhs7 = NULL;
  const mxArray *c19_rhs8 = NULL;
  const mxArray *c19_lhs8 = NULL;
  const mxArray *c19_rhs9 = NULL;
  const mxArray *c19_lhs9 = NULL;
  const mxArray *c19_rhs10 = NULL;
  const mxArray *c19_lhs10 = NULL;
  const mxArray *c19_rhs11 = NULL;
  const mxArray *c19_lhs11 = NULL;
  const mxArray *c19_rhs12 = NULL;
  const mxArray *c19_lhs12 = NULL;
  const mxArray *c19_rhs13 = NULL;
  const mxArray *c19_lhs13 = NULL;
  const mxArray *c19_rhs14 = NULL;
  const mxArray *c19_lhs14 = NULL;
  const mxArray *c19_rhs15 = NULL;
  const mxArray *c19_lhs15 = NULL;
  const mxArray *c19_rhs16 = NULL;
  const mxArray *c19_lhs16 = NULL;
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("cos"), "name", "name", 0);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1395328496U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c19_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("eml_scalar_cos"), "name",
                  "name", 1);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1286818722U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c19_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(""), "context", "context", 2);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("sin"), "name", "name", 2);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1395328504U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c19_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("eml_scalar_sin"), "name",
                  "name", 3);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1286818736U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c19_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(""), "context", "context", 4);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 4);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1383877294U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c19_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 5);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 5);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c19_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 6);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 6);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c19_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 7);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 7);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c19_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 8);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c19_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  9);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1375980690U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c19_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 10);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c19_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("coder.internal.blas.xgemm"),
                  "name", "name", 11);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c19_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 12);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 12);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c19_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!below_threshold"),
                  "context", "context", 13);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 13);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c19_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 14);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 14);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1393330858U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c19_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 15);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 15);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c19_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 16);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "coder.internal.refblas.xgemm"), "name", "name", 16);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c19_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs16), "lhs", "lhs",
                  16);
  sf_mex_destroy(&c19_rhs0);
  sf_mex_destroy(&c19_lhs0);
  sf_mex_destroy(&c19_rhs1);
  sf_mex_destroy(&c19_lhs1);
  sf_mex_destroy(&c19_rhs2);
  sf_mex_destroy(&c19_lhs2);
  sf_mex_destroy(&c19_rhs3);
  sf_mex_destroy(&c19_lhs3);
  sf_mex_destroy(&c19_rhs4);
  sf_mex_destroy(&c19_lhs4);
  sf_mex_destroy(&c19_rhs5);
  sf_mex_destroy(&c19_lhs5);
  sf_mex_destroy(&c19_rhs6);
  sf_mex_destroy(&c19_lhs6);
  sf_mex_destroy(&c19_rhs7);
  sf_mex_destroy(&c19_lhs7);
  sf_mex_destroy(&c19_rhs8);
  sf_mex_destroy(&c19_lhs8);
  sf_mex_destroy(&c19_rhs9);
  sf_mex_destroy(&c19_lhs9);
  sf_mex_destroy(&c19_rhs10);
  sf_mex_destroy(&c19_lhs10);
  sf_mex_destroy(&c19_rhs11);
  sf_mex_destroy(&c19_lhs11);
  sf_mex_destroy(&c19_rhs12);
  sf_mex_destroy(&c19_lhs12);
  sf_mex_destroy(&c19_rhs13);
  sf_mex_destroy(&c19_lhs13);
  sf_mex_destroy(&c19_rhs14);
  sf_mex_destroy(&c19_lhs14);
  sf_mex_destroy(&c19_rhs15);
  sf_mex_destroy(&c19_lhs15);
  sf_mex_destroy(&c19_rhs16);
  sf_mex_destroy(&c19_lhs16);
}

static const mxArray *c19_emlrt_marshallOut(const char * c19_u)
{
  const mxArray *c19_y = NULL;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", c19_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c19_u)), false);
  return c19_y;
}

static const mxArray *c19_b_emlrt_marshallOut(const uint32_T c19_u)
{
  const mxArray *c19_y = NULL;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", &c19_u, 7, 0U, 0U, 0U, 0), false);
  return c19_y;
}

static void c19_eml_scalar_eg(SFc19_AllPurposeModel_TyreRelaxationInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c19_eml_xgemm(SFc19_AllPurposeModel_TyreRelaxationInstanceStruct
  *chartInstance, real_T c19_A[4], real_T c19_B[2], real_T c19_C[2], real_T
  c19_b_C[2])
{
  int32_T c19_i24;
  int32_T c19_i25;
  real_T c19_b_A[4];
  int32_T c19_i26;
  real_T c19_b_B[2];
  for (c19_i24 = 0; c19_i24 < 2; c19_i24++) {
    c19_b_C[c19_i24] = c19_C[c19_i24];
  }

  for (c19_i25 = 0; c19_i25 < 4; c19_i25++) {
    c19_b_A[c19_i25] = c19_A[c19_i25];
  }

  for (c19_i26 = 0; c19_i26 < 2; c19_i26++) {
    c19_b_B[c19_i26] = c19_B[c19_i26];
  }

  c19_b_eml_xgemm(chartInstance, c19_b_A, c19_b_B, c19_b_C);
}

static const mxArray *c19_d_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData)
{
  const mxArray *c19_mxArrayOutData = NULL;
  int32_T c19_u;
  const mxArray *c19_y = NULL;
  SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c19_mxArrayOutData = NULL;
  c19_u = *(int32_T *)c19_inData;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", &c19_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c19_mxArrayOutData, c19_y, false);
  return c19_mxArrayOutData;
}

static int32_T c19_e_emlrt_marshallIn
  (SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId)
{
  int32_T c19_y;
  int32_T c19_i27;
  (void)chartInstance;
  sf_mex_import(c19_parentId, sf_mex_dup(c19_u), &c19_i27, 1, 6, 0U, 0, 0U, 0);
  c19_y = c19_i27;
  sf_mex_destroy(&c19_u);
  return c19_y;
}

static void c19_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData)
{
  const mxArray *c19_b_sfEvent;
  const char_T *c19_identifier;
  emlrtMsgIdentifier c19_thisId;
  int32_T c19_y;
  SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c19_b_sfEvent = sf_mex_dup(c19_mxArrayInData);
  c19_identifier = c19_varName;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_y = c19_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_b_sfEvent),
    &c19_thisId);
  sf_mex_destroy(&c19_b_sfEvent);
  *(int32_T *)c19_outData = c19_y;
  sf_mex_destroy(&c19_mxArrayInData);
}

static const mxArray *c19_F_xw4_bus_io(void *chartInstanceVoid, void *c19_pData)
{
  const mxArray *c19_mxVal = NULL;
  c19_whl_vec4 c19_tmp;
  SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  chartInstance = (SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *)
    chartInstanceVoid;
  c19_mxVal = NULL;
  c19_tmp.fl = *(real_T *)&((char_T *)(c19_whl_vec4 *)c19_pData)[0];
  c19_tmp.fr = *(real_T *)&((char_T *)(c19_whl_vec4 *)c19_pData)[8];
  c19_tmp.rl = *(real_T *)&((char_T *)(c19_whl_vec4 *)c19_pData)[16];
  c19_tmp.rr = *(real_T *)&((char_T *)(c19_whl_vec4 *)c19_pData)[24];
  sf_mex_assign(&c19_mxVal, c19_sf_marshallOut(chartInstance, &c19_tmp), false);
  return c19_mxVal;
}

static uint8_T c19_f_emlrt_marshallIn
  (SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c19_b_is_active_c19_AllPurposeModel_TyreRelaxation, const char_T
   *c19_identifier)
{
  uint8_T c19_y;
  emlrtMsgIdentifier c19_thisId;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_y = c19_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c19_b_is_active_c19_AllPurposeModel_TyreRelaxation), &c19_thisId);
  sf_mex_destroy(&c19_b_is_active_c19_AllPurposeModel_TyreRelaxation);
  return c19_y;
}

static uint8_T c19_g_emlrt_marshallIn
  (SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance, const
   mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId)
{
  uint8_T c19_y;
  uint8_T c19_u0;
  (void)chartInstance;
  sf_mex_import(c19_parentId, sf_mex_dup(c19_u), &c19_u0, 1, 3, 0U, 0, 0U, 0);
  c19_y = c19_u0;
  sf_mex_destroy(&c19_u);
  return c19_y;
}

static void c19_b_eml_xgemm(SFc19_AllPurposeModel_TyreRelaxationInstanceStruct
  *chartInstance, real_T c19_A[4], real_T c19_B[2], real_T c19_C[2])
{
  int32_T c19_i28;
  int32_T c19_i29;
  int32_T c19_i30;
  (void)chartInstance;
  for (c19_i28 = 0; c19_i28 < 2; c19_i28++) {
    c19_C[c19_i28] = 0.0;
    c19_i29 = 0;
    for (c19_i30 = 0; c19_i30 < 2; c19_i30++) {
      c19_C[c19_i28] += c19_A[c19_i29 + c19_i28] * c19_B[c19_i30];
      c19_i29 += 2;
    }
  }
}

static void init_dsm_address_info
  (SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address
  (SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance)
{
  chartInstance->c19_F_xw4 = (c19_whl_vec4 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c19_F_yw4 = (c19_whl_vec4 *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c19_F_xv4 = (c19_whl_vec4 *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c19_F_yv4 = (c19_whl_vec4 *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c19_delta_w4 = (c19_whl_vec4 *)ssGetInputPortSignal_wrapper
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

void sf_c19_AllPurposeModel_TyreRelaxation_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3192201349U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3698539436U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1671014734U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3488508836U);
}

mxArray* sf_c19_AllPurposeModel_TyreRelaxation_get_post_codegen_info(void);
mxArray *sf_c19_AllPurposeModel_TyreRelaxation_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("F1y4LhFIX25OiKktTK2g2B");
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
    mxArray* mxPostCodegenInfo =
      sf_c19_AllPurposeModel_TyreRelaxation_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c19_AllPurposeModel_TyreRelaxation_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c19_AllPurposeModel_TyreRelaxation_jit_fallback_info(void)
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

mxArray *sf_c19_AllPurposeModel_TyreRelaxation_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c19_AllPurposeModel_TyreRelaxation_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c19_AllPurposeModel_TyreRelaxation
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"F_xv4\",},{M[1],M[7],T\"F_yv4\",},{M[8],M[0],T\"is_active_c19_AllPurposeModel_TyreRelaxation\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c19_AllPurposeModel_TyreRelaxation_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _AllPurposeModel_TyreRelaxationMachineNumber_,
           19,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"F_xw4");
          _SFD_SET_DATA_PROPS(1,1,1,0,"F_yw4");
          _SFD_SET_DATA_PROPS(2,2,0,1,"F_xv4");
          _SFD_SET_DATA_PROPS(3,2,0,1,"F_yv4");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,727);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c19_F_xw4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c19_F_xw4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c19_F_xw4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c19_F_xw4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c19_F_xw4_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c19_F_xw4);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c19_F_yw4);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c19_F_xv4);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c19_F_yv4);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c19_delta_w4);
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
  return "vfMzKFiWd9gxZLQUJsLr3D";
}

static void sf_opaque_initialize_c19_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc19_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar)->S,
     0);
  initialize_params_c19_AllPurposeModel_TyreRelaxation
    ((SFc19_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
  initialize_c19_AllPurposeModel_TyreRelaxation
    ((SFc19_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c19_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  enable_c19_AllPurposeModel_TyreRelaxation
    ((SFc19_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c19_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  disable_c19_AllPurposeModel_TyreRelaxation
    ((SFc19_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c19_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  sf_gateway_c19_AllPurposeModel_TyreRelaxation
    ((SFc19_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c19_AllPurposeModel_TyreRelaxation
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c19_AllPurposeModel_TyreRelaxation
    ((SFc19_AllPurposeModel_TyreRelaxationInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c19_AllPurposeModel_TyreRelaxation(SimStruct*
  S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c19_AllPurposeModel_TyreRelaxation
    ((SFc19_AllPurposeModel_TyreRelaxationInstanceStruct*)
     chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c19_AllPurposeModel_TyreRelaxation(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc19_AllPurposeModel_TyreRelaxationInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_AllPurposeModel_TyreRelaxation_optimization_info();
    }

    finalize_c19_AllPurposeModel_TyreRelaxation
      ((SFc19_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc19_AllPurposeModel_TyreRelaxation
    ((SFc19_AllPurposeModel_TyreRelaxationInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c19_AllPurposeModel_TyreRelaxation(SimStruct *S)
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
    initialize_params_c19_AllPurposeModel_TyreRelaxation
      ((SFc19_AllPurposeModel_TyreRelaxationInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c19_AllPurposeModel_TyreRelaxation(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_AllPurposeModel_TyreRelaxation_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      19);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,19,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,19,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,19);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,19,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,19,2);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,19);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1758676810U));
  ssSetChecksum1(S,(2636262492U));
  ssSetChecksum2(S,(1357279885U));
  ssSetChecksum3(S,(655041476U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c19_AllPurposeModel_TyreRelaxation(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c19_AllPurposeModel_TyreRelaxation(SimStruct *S)
{
  SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc19_AllPurposeModel_TyreRelaxationInstanceStruct *)utMalloc
    (sizeof(SFc19_AllPurposeModel_TyreRelaxationInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc19_AllPurposeModel_TyreRelaxationInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c19_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c19_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c19_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c19_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c19_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c19_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c19_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c19_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c19_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c19_AllPurposeModel_TyreRelaxation;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c19_AllPurposeModel_TyreRelaxation;
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

void c19_AllPurposeModel_TyreRelaxation_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c19_AllPurposeModel_TyreRelaxation(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c19_AllPurposeModel_TyreRelaxation(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c19_AllPurposeModel_TyreRelaxation(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c19_AllPurposeModel_TyreRelaxation_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
