/* Include files */

#include <stddef.h>
#include "blas.h"
#include "PartTransformation_sfun.h"
#include "c1_PartTransformation.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "PartTransformation_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[11] = { "in", "out", "nargin",
  "nargout", "a", "b", "c", "theta", "d", "q", "o" };

/* Function Declarations */
static void initialize_c1_PartTransformation
  (SFc1_PartTransformationInstanceStruct *chartInstance);
static void initialize_params_c1_PartTransformation
  (SFc1_PartTransformationInstanceStruct *chartInstance);
static void enable_c1_PartTransformation(SFc1_PartTransformationInstanceStruct
  *chartInstance);
static void disable_c1_PartTransformation(SFc1_PartTransformationInstanceStruct *
  chartInstance);
static void c1_update_debugger_state_c1_PartTransformation
  (SFc1_PartTransformationInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_PartTransformation
  (SFc1_PartTransformationInstanceStruct *chartInstance);
static void set_sim_state_c1_PartTransformation
  (SFc1_PartTransformationInstanceStruct *chartInstance, const mxArray *c1_st);
static void finalize_c1_PartTransformation(SFc1_PartTransformationInstanceStruct
  *chartInstance);
static void sf_c1_PartTransformation(SFc1_PartTransformationInstanceStruct
  *chartInstance);
static void c1_chartstep_c1_PartTransformation
  (SFc1_PartTransformationInstanceStruct *chartInstance);
static void initSimStructsc1_PartTransformation
  (SFc1_PartTransformationInstanceStruct *chartInstance);
static void registerMessagesc1_PartTransformation
  (SFc1_PartTransformationInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static real_T c1_emlrt_marshallIn(SFc1_PartTransformationInstanceStruct
  *chartInstance, const mxArray *c1_o, const char_T *c1_identifier);
static real_T c1_b_emlrt_marshallIn(SFc1_PartTransformationInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_c_emlrt_marshallIn(SFc1_PartTransformationInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[3]);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[20]);
static void c1_eml_scalar_eg(SFc1_PartTransformationInstanceStruct
  *chartInstance);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_d_emlrt_marshallIn(SFc1_PartTransformationInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_e_emlrt_marshallIn(SFc1_PartTransformationInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_PartTransformation, const
  char_T *c1_identifier);
static uint8_T c1_f_emlrt_marshallIn(SFc1_PartTransformationInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_PartTransformationInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_PartTransformation
  (SFc1_PartTransformationInstanceStruct *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_PartTransformation = 0U;
}

static void initialize_params_c1_PartTransformation
  (SFc1_PartTransformationInstanceStruct *chartInstance)
{
}

static void enable_c1_PartTransformation(SFc1_PartTransformationInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_PartTransformation(SFc1_PartTransformationInstanceStruct *
  chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_PartTransformation
  (SFc1_PartTransformationInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c1_PartTransformation
  (SFc1_PartTransformationInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  real_T c1_hoistedGlobal;
  real_T c1_u;
  const mxArray *c1_b_y = NULL;
  real_T c1_b_hoistedGlobal;
  real_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  real_T c1_c_hoistedGlobal;
  real_T c1_c_u;
  const mxArray *c1_d_y = NULL;
  uint8_T c1_d_hoistedGlobal;
  uint8_T c1_d_u;
  const mxArray *c1_e_y = NULL;
  real_T *c1_d;
  real_T *c1_o;
  real_T *c1_q;
  c1_o = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_q = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_d = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(4), FALSE);
  c1_hoistedGlobal = *c1_d;
  c1_u = c1_hoistedGlobal;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_b_hoistedGlobal = *c1_o;
  c1_b_u = c1_b_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_c_hoistedGlobal = *c1_q;
  c1_c_u = c1_c_hoistedGlobal;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  c1_d_hoistedGlobal = chartInstance->c1_is_active_c1_PartTransformation;
  c1_d_u = c1_d_hoistedGlobal;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 3, c1_e_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_PartTransformation
  (SFc1_PartTransformationInstanceStruct *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T *c1_d;
  real_T *c1_o;
  real_T *c1_q;
  c1_o = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_q = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_d = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  *c1_d = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)),
    "d");
  *c1_o = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
    "o");
  *c1_q = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 2)),
    "q");
  chartInstance->c1_is_active_c1_PartTransformation = c1_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 3)),
     "is_active_c1_PartTransformation");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_PartTransformation(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_PartTransformation(SFc1_PartTransformationInstanceStruct
  *chartInstance)
{
}

static void sf_c1_PartTransformation(SFc1_PartTransformationInstanceStruct
  *chartInstance)
{
  real_T *c1_a;
  real_T *c1_d;
  real_T *c1_b;
  real_T *c1_c;
  real_T *c1_theta;
  real_T *c1_q;
  real_T *c1_o;
  c1_o = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_q = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_theta = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c1_c = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c1_b = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_d = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_a = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c1_a, 0U);
  _SFD_DATA_RANGE_CHECK(*c1_d, 1U);
  _SFD_DATA_RANGE_CHECK(*c1_b, 2U);
  _SFD_DATA_RANGE_CHECK(*c1_c, 3U);
  _SFD_DATA_RANGE_CHECK(*c1_theta, 4U);
  _SFD_DATA_RANGE_CHECK(*c1_q, 5U);
  _SFD_DATA_RANGE_CHECK(*c1_o, 6U);
  chartInstance->c1_sfEvent = CALL_EVENT;
  c1_chartstep_c1_PartTransformation(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_PartTransformationMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c1_chartstep_c1_PartTransformation
  (SFc1_PartTransformationInstanceStruct *chartInstance)
{
  real_T c1_hoistedGlobal;
  real_T c1_b_hoistedGlobal;
  real_T c1_c_hoistedGlobal;
  real_T c1_d_hoistedGlobal;
  real_T c1_a;
  real_T c1_b;
  real_T c1_c;
  real_T c1_theta;
  uint32_T c1_debug_family_var_map[11];
  real_T c1_in[3];
  real_T c1_out[3];
  real_T c1_nargin = 4.0;
  real_T c1_nargout = 3.0;
  real_T c1_d;
  real_T c1_q;
  real_T c1_o;
  real_T c1_x;
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_d_x;
  real_T c1_e_x;
  real_T c1_f_x;
  real_T c1_g_x;
  real_T c1_h_x;
  real_T c1_i_x;
  real_T c1_j_x;
  real_T c1_k_x;
  real_T c1_l_x;
  real_T c1_b_b[9];
  int32_T c1_i0;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  real_T c1_c_b[3];
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  real_T c1_C[3];
  int32_T c1_i7;
  int32_T c1_i8;
  int32_T c1_i9;
  int32_T c1_i10;
  int32_T c1_i11;
  int32_T c1_i12;
  real_T *c1_b_a;
  real_T *c1_d_b;
  real_T *c1_b_c;
  real_T *c1_b_theta;
  real_T *c1_b_d;
  real_T *c1_b_q;
  real_T *c1_b_o;
  c1_b_o = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_b_q = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_b_theta = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c1_b_c = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c1_d_b = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_d = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_b_a = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_hoistedGlobal = *c1_b_a;
  c1_b_hoistedGlobal = *c1_d_b;
  c1_c_hoistedGlobal = *c1_b_c;
  c1_d_hoistedGlobal = *c1_b_theta;
  c1_a = c1_hoistedGlobal;
  c1_b = c1_b_hoistedGlobal;
  c1_c = c1_c_hoistedGlobal;
  c1_theta = c1_d_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 11U, 11U, c1_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_in, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_out, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 2U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 3U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_a, 4U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_b, 5U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_c, 6U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_theta, 7U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d, 8U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_q, 9U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_o, 10U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 2);
  c1_in[0] = c1_a;
  c1_in[1] = c1_b;
  c1_in[2] = c1_c;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 3);
  c1_x = c1_theta;
  c1_b_x = c1_x;
  c1_b_x = muDoubleScalarCos(c1_b_x);
  c1_c_x = c1_theta - 2.0943951023931953;
  c1_d_x = c1_c_x;
  c1_d_x = muDoubleScalarCos(c1_d_x);
  c1_e_x = c1_theta + 2.0943951023931953;
  c1_f_x = c1_e_x;
  c1_f_x = muDoubleScalarCos(c1_f_x);
  c1_g_x = c1_theta;
  c1_h_x = c1_g_x;
  c1_h_x = muDoubleScalarSin(c1_h_x);
  c1_i_x = c1_theta - 2.0943951023931953;
  c1_j_x = c1_i_x;
  c1_j_x = muDoubleScalarSin(c1_j_x);
  c1_k_x = c1_theta + 2.0943951023931953;
  c1_l_x = c1_k_x;
  c1_l_x = muDoubleScalarSin(c1_l_x);
  c1_b_b[0] = c1_b_x;
  c1_b_b[3] = c1_d_x;
  c1_b_b[6] = c1_f_x;
  c1_b_b[1] = -c1_h_x;
  c1_b_b[4] = -c1_j_x;
  c1_b_b[7] = -c1_l_x;
  c1_i0 = 0;
  for (c1_i1 = 0; c1_i1 < 3; c1_i1++) {
    c1_b_b[c1_i0 + 2] = 0.70710678118654746;
    c1_i0 += 3;
  }

  for (c1_i2 = 0; c1_i2 < 9; c1_i2++) {
    c1_b_b[c1_i2] *= 0.816496580927726;
  }

  for (c1_i3 = 0; c1_i3 < 3; c1_i3++) {
    c1_c_b[c1_i3] = c1_in[c1_i3];
  }

  c1_eml_scalar_eg(chartInstance);
  c1_eml_scalar_eg(chartInstance);
  for (c1_i4 = 0; c1_i4 < 3; c1_i4++) {
    c1_out[c1_i4] = 0.0;
  }

  for (c1_i5 = 0; c1_i5 < 3; c1_i5++) {
    c1_out[c1_i5] = 0.0;
  }

  for (c1_i6 = 0; c1_i6 < 3; c1_i6++) {
    c1_C[c1_i6] = c1_out[c1_i6];
  }

  for (c1_i7 = 0; c1_i7 < 3; c1_i7++) {
    c1_out[c1_i7] = c1_C[c1_i7];
  }

  for (c1_i8 = 0; c1_i8 < 3; c1_i8++) {
    c1_C[c1_i8] = c1_out[c1_i8];
  }

  for (c1_i9 = 0; c1_i9 < 3; c1_i9++) {
    c1_out[c1_i9] = c1_C[c1_i9];
  }

  for (c1_i10 = 0; c1_i10 < 3; c1_i10++) {
    c1_out[c1_i10] = 0.0;
    c1_i11 = 0;
    for (c1_i12 = 0; c1_i12 < 3; c1_i12++) {
      c1_out[c1_i10] += c1_b_b[c1_i11 + c1_i10] * c1_c_b[c1_i12];
      c1_i11 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_q = c1_out[0];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_d = c1_out[1];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 9);
  c1_o = c1_out[2];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -9);
  _SFD_SYMBOL_SCOPE_POP();
  *c1_b_d = c1_d;
  *c1_b_q = c1_q;
  *c1_b_o = c1_o;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void initSimStructsc1_PartTransformation
  (SFc1_PartTransformationInstanceStruct *chartInstance)
{
}

static void registerMessagesc1_PartTransformation
  (SFc1_PartTransformationInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_PartTransformationInstanceStruct *chartInstance;
  chartInstance = (SFc1_PartTransformationInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_emlrt_marshallIn(SFc1_PartTransformationInstanceStruct
  *chartInstance, const mxArray *c1_o, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_o), &c1_thisId);
  sf_mex_destroy(&c1_o);
  return c1_y;
}

static real_T c1_b_emlrt_marshallIn(SFc1_PartTransformationInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_o;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_PartTransformationInstanceStruct *chartInstance;
  chartInstance = (SFc1_PartTransformationInstanceStruct *)chartInstanceVoid;
  c1_o = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_o), &c1_thisId);
  sf_mex_destroy(&c1_o);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i13;
  real_T c1_b_inData[3];
  int32_T c1_i14;
  real_T c1_u[3];
  const mxArray *c1_y = NULL;
  SFc1_PartTransformationInstanceStruct *chartInstance;
  chartInstance = (SFc1_PartTransformationInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i13 = 0; c1_i13 < 3; c1_i13++) {
    c1_b_inData[c1_i13] = (*(real_T (*)[3])c1_inData)[c1_i13];
  }

  for (c1_i14 = 0; c1_i14 < 3; c1_i14++) {
    c1_u[c1_i14] = c1_b_inData[c1_i14];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_c_emlrt_marshallIn(SFc1_PartTransformationInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[3])
{
  real_T c1_dv0[3];
  int32_T c1_i15;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv0, 1, 0, 0U, 1, 0U, 1, 3);
  for (c1_i15 = 0; c1_i15 < 3; c1_i15++) {
    c1_y[c1_i15] = c1_dv0[c1_i15];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_out;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[3];
  int32_T c1_i16;
  SFc1_PartTransformationInstanceStruct *chartInstance;
  chartInstance = (SFc1_PartTransformationInstanceStruct *)chartInstanceVoid;
  c1_out = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_out), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_out);
  for (c1_i16 = 0; c1_i16 < 3; c1_i16++) {
    (*(real_T (*)[3])c1_outData)[c1_i16] = c1_y[c1_i16];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_PartTransformation_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[20];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i17;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_info_helper(c1_info);
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 20), FALSE);
  for (c1_i17 = 0; c1_i17 < 20; c1_i17++) {
    c1_r0 = &c1_info[c1_i17];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo",
                    c1_i17);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", c1_i17);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c1_i17);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo",
                    c1_i17);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c1_i17);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c1_i17);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c1_i17);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c1_i17);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[20])
{
  c1_info[0].context = "";
  c1_info[0].name = "mrdivide";
  c1_info[0].dominantType = "double";
  c1_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[0].fileTimeLo = 1357947948U;
  c1_info[0].fileTimeHi = 0U;
  c1_info[0].mFileTimeLo = 1319729966U;
  c1_info[0].mFileTimeHi = 0U;
  c1_info[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[1].name = "rdivide";
  c1_info[1].dominantType = "double";
  c1_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[1].fileTimeLo = 1346506788U;
  c1_info[1].fileTimeHi = 0U;
  c1_info[1].mFileTimeLo = 0U;
  c1_info[1].mFileTimeHi = 0U;
  c1_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[2].name = "eml_scalexp_compatible";
  c1_info[2].dominantType = "double";
  c1_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c1_info[2].fileTimeLo = 1286818796U;
  c1_info[2].fileTimeHi = 0U;
  c1_info[2].mFileTimeLo = 0U;
  c1_info[2].mFileTimeHi = 0U;
  c1_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[3].name = "eml_div";
  c1_info[3].dominantType = "double";
  c1_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c1_info[3].fileTimeLo = 1313344210U;
  c1_info[3].fileTimeHi = 0U;
  c1_info[3].mFileTimeLo = 0U;
  c1_info[3].mFileTimeHi = 0U;
  c1_info[4].context = "";
  c1_info[4].name = "sqrt";
  c1_info[4].dominantType = "double";
  c1_info[4].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c1_info[4].fileTimeLo = 1343826786U;
  c1_info[4].fileTimeHi = 0U;
  c1_info[4].mFileTimeLo = 0U;
  c1_info[4].mFileTimeHi = 0U;
  c1_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c1_info[5].name = "eml_error";
  c1_info[5].dominantType = "char";
  c1_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c1_info[5].fileTimeLo = 1343826758U;
  c1_info[5].fileTimeHi = 0U;
  c1_info[5].mFileTimeLo = 0U;
  c1_info[5].mFileTimeHi = 0U;
  c1_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c1_info[6].name = "eml_scalar_sqrt";
  c1_info[6].dominantType = "double";
  c1_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c1_info[6].fileTimeLo = 1286818738U;
  c1_info[6].fileTimeHi = 0U;
  c1_info[6].mFileTimeLo = 0U;
  c1_info[6].mFileTimeHi = 0U;
  c1_info[7].context = "";
  c1_info[7].name = "cos";
  c1_info[7].dominantType = "double";
  c1_info[7].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c1_info[7].fileTimeLo = 1343826772U;
  c1_info[7].fileTimeHi = 0U;
  c1_info[7].mFileTimeLo = 0U;
  c1_info[7].mFileTimeHi = 0U;
  c1_info[8].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c1_info[8].name = "eml_scalar_cos";
  c1_info[8].dominantType = "double";
  c1_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c1_info[8].fileTimeLo = 1286818722U;
  c1_info[8].fileTimeHi = 0U;
  c1_info[8].mFileTimeLo = 0U;
  c1_info[8].mFileTimeHi = 0U;
  c1_info[9].context = "";
  c1_info[9].name = "mtimes";
  c1_info[9].dominantType = "double";
  c1_info[9].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[9].fileTimeLo = 1289516092U;
  c1_info[9].fileTimeHi = 0U;
  c1_info[9].mFileTimeLo = 0U;
  c1_info[9].mFileTimeHi = 0U;
  c1_info[10].context = "";
  c1_info[10].name = "sin";
  c1_info[10].dominantType = "double";
  c1_info[10].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c1_info[10].fileTimeLo = 1343826786U;
  c1_info[10].fileTimeHi = 0U;
  c1_info[10].mFileTimeLo = 0U;
  c1_info[10].mFileTimeHi = 0U;
  c1_info[11].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c1_info[11].name = "eml_scalar_sin";
  c1_info[11].dominantType = "double";
  c1_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c1_info[11].fileTimeLo = 1286818736U;
  c1_info[11].fileTimeHi = 0U;
  c1_info[11].mFileTimeLo = 0U;
  c1_info[11].mFileTimeHi = 0U;
  c1_info[12].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[12].name = "eml_index_class";
  c1_info[12].dominantType = "";
  c1_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[12].fileTimeLo = 1323166978U;
  c1_info[12].fileTimeHi = 0U;
  c1_info[12].mFileTimeLo = 0U;
  c1_info[12].mFileTimeHi = 0U;
  c1_info[13].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[13].name = "eml_scalar_eg";
  c1_info[13].dominantType = "double";
  c1_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[13].fileTimeLo = 1286818796U;
  c1_info[13].fileTimeHi = 0U;
  c1_info[13].mFileTimeLo = 0U;
  c1_info[13].mFileTimeHi = 0U;
  c1_info[14].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[14].name = "eml_xgemm";
  c1_info[14].dominantType = "char";
  c1_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c1_info[14].fileTimeLo = 1299073172U;
  c1_info[14].fileTimeHi = 0U;
  c1_info[14].mFileTimeLo = 0U;
  c1_info[14].mFileTimeHi = 0U;
  c1_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c1_info[15].name = "eml_blas_inline";
  c1_info[15].dominantType = "";
  c1_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c1_info[15].fileTimeLo = 1299073168U;
  c1_info[15].fileTimeHi = 0U;
  c1_info[15].mFileTimeLo = 0U;
  c1_info[15].mFileTimeHi = 0U;
  c1_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c1_info[16].name = "mtimes";
  c1_info[16].dominantType = "double";
  c1_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[16].fileTimeLo = 1289516092U;
  c1_info[16].fileTimeHi = 0U;
  c1_info[16].mFileTimeLo = 0U;
  c1_info[16].mFileTimeHi = 0U;
  c1_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c1_info[17].name = "eml_index_class";
  c1_info[17].dominantType = "";
  c1_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[17].fileTimeLo = 1323166978U;
  c1_info[17].fileTimeHi = 0U;
  c1_info[17].mFileTimeLo = 0U;
  c1_info[17].mFileTimeHi = 0U;
  c1_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c1_info[18].name = "eml_scalar_eg";
  c1_info[18].dominantType = "double";
  c1_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[18].fileTimeLo = 1286818796U;
  c1_info[18].fileTimeHi = 0U;
  c1_info[18].mFileTimeLo = 0U;
  c1_info[18].mFileTimeHi = 0U;
  c1_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c1_info[19].name = "eml_refblas_xgemm";
  c1_info[19].dominantType = "char";
  c1_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c1_info[19].fileTimeLo = 1299073174U;
  c1_info[19].fileTimeHi = 0U;
  c1_info[19].mFileTimeLo = 0U;
  c1_info[19].mFileTimeHi = 0U;
}

static void c1_eml_scalar_eg(SFc1_PartTransformationInstanceStruct
  *chartInstance)
{
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_PartTransformationInstanceStruct *chartInstance;
  chartInstance = (SFc1_PartTransformationInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_d_emlrt_marshallIn(SFc1_PartTransformationInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i18;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i18, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i18;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_PartTransformationInstanceStruct *chartInstance;
  chartInstance = (SFc1_PartTransformationInstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_e_emlrt_marshallIn(SFc1_PartTransformationInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_PartTransformation, const
  char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_PartTransformation), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_PartTransformation);
  return c1_y;
}

static uint8_T c1_f_emlrt_marshallIn(SFc1_PartTransformationInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_PartTransformationInstanceStruct
  *chartInstance)
{
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

void sf_c1_PartTransformation_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1741355560U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1247356096U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1181311083U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2615631278U);
}

mxArray *sf_c1_PartTransformation_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("b8BQMNdD8Z1AWGnUI6XmoD");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_PartTransformation_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c1_PartTransformation(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[5],T\"d\",},{M[1],M[10],T\"o\",},{M[1],M[9],T\"q\",},{M[8],M[0],T\"is_active_c1_PartTransformation\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_PartTransformation_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_PartTransformationInstanceStruct *chartInstance;
    chartInstance = (SFc1_PartTransformationInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _PartTransformationMachineNumber_,
           1,
           1,
           1,
           7,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_PartTransformationMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_PartTransformationMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _PartTransformationMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"a");
          _SFD_SET_DATA_PROPS(1,2,0,1,"d");
          _SFD_SET_DATA_PROPS(2,1,1,0,"b");
          _SFD_SET_DATA_PROPS(3,1,1,0,"c");
          _SFD_SET_DATA_PROPS(4,1,1,0,"theta");
          _SFD_SET_DATA_PROPS(5,2,0,1,"q");
          _SFD_SET_DATA_PROPS(6,2,0,1,"o");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,297);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);

        {
          real_T *c1_a;
          real_T *c1_d;
          real_T *c1_b;
          real_T *c1_c;
          real_T *c1_theta;
          real_T *c1_q;
          real_T *c1_o;
          c1_o = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c1_q = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c1_theta = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c1_c = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c1_b = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c1_d = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c1_a = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_a);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_d);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_b);
          _SFD_SET_DATA_VALUE_PTR(3U, c1_c);
          _SFD_SET_DATA_VALUE_PTR(4U, c1_theta);
          _SFD_SET_DATA_VALUE_PTR(5U, c1_q);
          _SFD_SET_DATA_VALUE_PTR(6U, c1_o);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _PartTransformationMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "mryfyCUjhjARd72W6uSm9G";
}

static void sf_opaque_initialize_c1_PartTransformation(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_PartTransformationInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_PartTransformation((SFc1_PartTransformationInstanceStruct*)
    chartInstanceVar);
  initialize_c1_PartTransformation((SFc1_PartTransformationInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_PartTransformation(void *chartInstanceVar)
{
  enable_c1_PartTransformation((SFc1_PartTransformationInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_PartTransformation(void *chartInstanceVar)
{
  disable_c1_PartTransformation((SFc1_PartTransformationInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_PartTransformation(void *chartInstanceVar)
{
  sf_c1_PartTransformation((SFc1_PartTransformationInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_PartTransformation(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_PartTransformation
    ((SFc1_PartTransformationInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_PartTransformation();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c1_PartTransformation(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_PartTransformation();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_PartTransformation((SFc1_PartTransformationInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_PartTransformation(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_PartTransformation(S);
}

static void sf_opaque_set_sim_state_c1_PartTransformation(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c1_PartTransformation(S, st);
}

static void sf_opaque_terminate_c1_PartTransformation(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_PartTransformationInstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_PartTransformation_optimization_info();
    }

    finalize_c1_PartTransformation((SFc1_PartTransformationInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_PartTransformation((SFc1_PartTransformationInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_PartTransformation(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_PartTransformation
      ((SFc1_PartTransformationInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_PartTransformation(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_PartTransformation_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,1,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,1);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 4; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1166836822U));
  ssSetChecksum1(S,(3059037917U));
  ssSetChecksum2(S,(1564482846U));
  ssSetChecksum3(S,(848006948U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_PartTransformation(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_PartTransformation(SimStruct *S)
{
  SFc1_PartTransformationInstanceStruct *chartInstance;
  chartInstance = (SFc1_PartTransformationInstanceStruct *)utMalloc(sizeof
    (SFc1_PartTransformationInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_PartTransformationInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_PartTransformation;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_PartTransformation;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_PartTransformation;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_PartTransformation;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_PartTransformation;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_PartTransformation;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_PartTransformation;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_PartTransformation;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_PartTransformation;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_PartTransformation;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_PartTransformation;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c1_PartTransformation_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_PartTransformation(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_PartTransformation(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_PartTransformation(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_PartTransformation_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
