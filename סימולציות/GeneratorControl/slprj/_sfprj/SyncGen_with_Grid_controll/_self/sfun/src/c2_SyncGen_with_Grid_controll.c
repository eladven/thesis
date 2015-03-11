/* Include files */

#include <stddef.h>
#include "blas.h"
#include "SyncGen_with_Grid_controll_sfun.h"
#include "c2_SyncGen_with_Grid_controll.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "SyncGen_with_Grid_controll_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[8] = { "nargin", "nargout", "V_g",
  "omega", "t", "V_a", "V_b", "V_c" };

/* Function Declarations */
static void initialize_c2_SyncGen_with_Grid_controll
  (SFc2_SyncGen_with_Grid_controllInstanceStruct *chartInstance);
static void initialize_params_c2_SyncGen_with_Grid_controll
  (SFc2_SyncGen_with_Grid_controllInstanceStruct *chartInstance);
static void enable_c2_SyncGen_with_Grid_controll
  (SFc2_SyncGen_with_Grid_controllInstanceStruct *chartInstance);
static void disable_c2_SyncGen_with_Grid_controll
  (SFc2_SyncGen_with_Grid_controllInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_SyncGen_with_Grid_controll
  (SFc2_SyncGen_with_Grid_controllInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_SyncGen_with_Grid_controll
  (SFc2_SyncGen_with_Grid_controllInstanceStruct *chartInstance);
static void set_sim_state_c2_SyncGen_with_Grid_controll
  (SFc2_SyncGen_with_Grid_controllInstanceStruct *chartInstance, const mxArray
   *c2_st);
static void finalize_c2_SyncGen_with_Grid_controll
  (SFc2_SyncGen_with_Grid_controllInstanceStruct *chartInstance);
static void sf_c2_SyncGen_with_Grid_controll
  (SFc2_SyncGen_with_Grid_controllInstanceStruct *chartInstance);
static void initSimStructsc2_SyncGen_with_Grid_controll
  (SFc2_SyncGen_with_Grid_controllInstanceStruct *chartInstance);
static void registerMessagesc2_SyncGen_with_Grid_controll
  (SFc2_SyncGen_with_Grid_controllInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static real_T c2_emlrt_marshallIn(SFc2_SyncGen_with_Grid_controllInstanceStruct *
  chartInstance, const mxArray *c2_V_c, const char_T *c2_identifier);
static real_T c2_b_emlrt_marshallIn
  (SFc2_SyncGen_with_Grid_controllInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_c_emlrt_marshallIn
  (SFc2_SyncGen_with_Grid_controllInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_d_emlrt_marshallIn
  (SFc2_SyncGen_with_Grid_controllInstanceStruct *chartInstance, const mxArray
   *c2_b_is_active_c2_SyncGen_with_Grid_controll, const char_T *c2_identifier);
static uint8_T c2_e_emlrt_marshallIn
  (SFc2_SyncGen_with_Grid_controllInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_SyncGen_with_Grid_controllInstanceStruct *
  chartInstance);

/* Function Definitions */
static void initialize_c2_SyncGen_with_Grid_controll
  (SFc2_SyncGen_with_Grid_controllInstanceStruct *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_SyncGen_with_Grid_controll = 0U;
}

static void initialize_params_c2_SyncGen_with_Grid_controll
  (SFc2_SyncGen_with_Grid_controllInstanceStruct *chartInstance)
{
}

static void enable_c2_SyncGen_with_Grid_controll
  (SFc2_SyncGen_with_Grid_controllInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_SyncGen_with_Grid_controll
  (SFc2_SyncGen_with_Grid_controllInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_SyncGen_with_Grid_controll
  (SFc2_SyncGen_with_Grid_controllInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c2_SyncGen_with_Grid_controll
  (SFc2_SyncGen_with_Grid_controllInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  real_T c2_hoistedGlobal;
  real_T c2_u;
  const mxArray *c2_b_y = NULL;
  real_T c2_b_hoistedGlobal;
  real_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T c2_c_hoistedGlobal;
  real_T c2_c_u;
  const mxArray *c2_d_y = NULL;
  uint8_T c2_d_hoistedGlobal;
  uint8_T c2_d_u;
  const mxArray *c2_e_y = NULL;
  real_T *c2_V_a;
  real_T *c2_V_b;
  real_T *c2_V_c;
  c2_V_c = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_V_b = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_V_a = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(4), FALSE);
  c2_hoistedGlobal = *c2_V_a;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = *c2_V_b;
  c2_b_u = c2_b_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_c_hoistedGlobal = *c2_V_c;
  c2_c_u = c2_c_hoistedGlobal;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 2, c2_d_y);
  c2_d_hoistedGlobal = chartInstance->c2_is_active_c2_SyncGen_with_Grid_controll;
  c2_d_u = c2_d_hoistedGlobal;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 3, c2_e_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_SyncGen_with_Grid_controll
  (SFc2_SyncGen_with_Grid_controllInstanceStruct *chartInstance, const mxArray
   *c2_st)
{
  const mxArray *c2_u;
  real_T *c2_V_a;
  real_T *c2_V_b;
  real_T *c2_V_c;
  c2_V_c = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_V_b = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_V_a = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  *c2_V_a = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)),
    "V_a");
  *c2_V_b = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)),
    "V_b");
  *c2_V_c = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 2)),
    "V_c");
  chartInstance->c2_is_active_c2_SyncGen_with_Grid_controll =
    c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 3)),
    "is_active_c2_SyncGen_with_Grid_controll");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_SyncGen_with_Grid_controll(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_SyncGen_with_Grid_controll
  (SFc2_SyncGen_with_Grid_controllInstanceStruct *chartInstance)
{
}

static void sf_c2_SyncGen_with_Grid_controll
  (SFc2_SyncGen_with_Grid_controllInstanceStruct *chartInstance)
{
  real_T c2_hoistedGlobal;
  real_T c2_b_hoistedGlobal;
  real_T c2_c_hoistedGlobal;
  real_T c2_V_g;
  real_T c2_omega;
  real_T c2_t;
  uint32_T c2_debug_family_var_map[8];
  real_T c2_nargin = 3.0;
  real_T c2_nargout = 3.0;
  real_T c2_V_a;
  real_T c2_V_b;
  real_T c2_V_c;
  real_T c2_a;
  real_T c2_b;
  real_T c2_y;
  real_T c2_x;
  real_T c2_b_x;
  real_T c2_b_a;
  real_T c2_b_b;
  real_T c2_c_a;
  real_T c2_c_b;
  real_T c2_b_y;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_d_a;
  real_T c2_d_b;
  real_T c2_e_a;
  real_T c2_e_b;
  real_T c2_c_y;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_f_a;
  real_T c2_f_b;
  real_T *c2_b_V_c;
  real_T *c2_b_V_b;
  real_T *c2_b_V_a;
  real_T *c2_b_t;
  real_T *c2_b_omega;
  real_T *c2_b_V_g;
  c2_b_V_c = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_b_V_b = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_b_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_b_omega = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_V_a = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_V_g = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c2_b_V_g, 0U);
  _SFD_DATA_RANGE_CHECK(*c2_b_V_a, 1U);
  _SFD_DATA_RANGE_CHECK(*c2_b_omega, 2U);
  _SFD_DATA_RANGE_CHECK(*c2_b_t, 3U);
  _SFD_DATA_RANGE_CHECK(*c2_b_V_b, 4U);
  _SFD_DATA_RANGE_CHECK(*c2_b_V_c, 5U);
  chartInstance->c2_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *c2_b_V_g;
  c2_b_hoistedGlobal = *c2_b_omega;
  c2_c_hoistedGlobal = *c2_b_t;
  c2_V_g = c2_hoistedGlobal;
  c2_omega = c2_b_hoistedGlobal;
  c2_t = c2_c_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_V_g, 2U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_omega, 3U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_t, 4U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_V_a, 5U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_V_b, 6U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_V_c, 7U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 2);
  c2_a = c2_omega;
  c2_b = c2_t;
  c2_y = c2_a * c2_b;
  c2_x = c2_y;
  c2_b_x = c2_x;
  c2_b_x = muDoubleScalarSin(c2_b_x);
  c2_b_a = c2_V_g;
  c2_b_b = c2_b_x;
  c2_V_a = c2_b_a * c2_b_b;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 3);
  c2_c_a = c2_omega;
  c2_c_b = c2_t;
  c2_b_y = c2_c_a * c2_c_b;
  c2_c_x = c2_b_y - 2.0943951023931953;
  c2_d_x = c2_c_x;
  c2_d_x = muDoubleScalarSin(c2_d_x);
  c2_d_a = c2_V_g;
  c2_d_b = c2_d_x;
  c2_V_b = c2_d_a * c2_d_b;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 4);
  c2_e_a = c2_omega;
  c2_e_b = c2_t;
  c2_c_y = c2_e_a * c2_e_b;
  c2_e_x = c2_c_y - 4.1887902047863905;
  c2_f_x = c2_e_x;
  c2_f_x = muDoubleScalarSin(c2_f_x);
  c2_f_a = c2_V_g;
  c2_f_b = c2_f_x;
  c2_V_c = c2_f_a * c2_f_b;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -4);
  _SFD_SYMBOL_SCOPE_POP();
  *c2_b_V_a = c2_V_a;
  *c2_b_V_b = c2_V_b;
  *c2_b_V_c = c2_V_c;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_SyncGen_with_Grid_controllMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc2_SyncGen_with_Grid_controll
  (SFc2_SyncGen_with_Grid_controllInstanceStruct *chartInstance)
{
}

static void registerMessagesc2_SyncGen_with_Grid_controll
  (SFc2_SyncGen_with_Grid_controllInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_SyncGen_with_Grid_controllInstanceStruct *chartInstance;
  chartInstance = (SFc2_SyncGen_with_Grid_controllInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_emlrt_marshallIn(SFc2_SyncGen_with_Grid_controllInstanceStruct *
  chartInstance, const mxArray *c2_V_c, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_V_c), &c2_thisId);
  sf_mex_destroy(&c2_V_c);
  return c2_y;
}

static real_T c2_b_emlrt_marshallIn
  (SFc2_SyncGen_with_Grid_controllInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_V_c;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_SyncGen_with_Grid_controllInstanceStruct *chartInstance;
  chartInstance = (SFc2_SyncGen_with_Grid_controllInstanceStruct *)
    chartInstanceVoid;
  c2_V_c = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_V_c), &c2_thisId);
  sf_mex_destroy(&c2_V_c);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_SyncGen_with_Grid_controll_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[7];
  c2_ResolvedFunctionInfo (*c2_b_info)[7];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i0;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_b_info = (c2_ResolvedFunctionInfo (*)[7])c2_info;
  (*c2_b_info)[0].context = "";
  (*c2_b_info)[0].name = "mtimes";
  (*c2_b_info)[0].dominantType = "double";
  (*c2_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c2_b_info)[0].fileTimeLo = 1289516092U;
  (*c2_b_info)[0].fileTimeHi = 0U;
  (*c2_b_info)[0].mFileTimeLo = 0U;
  (*c2_b_info)[0].mFileTimeHi = 0U;
  (*c2_b_info)[1].context = "";
  (*c2_b_info)[1].name = "sin";
  (*c2_b_info)[1].dominantType = "double";
  (*c2_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c2_b_info)[1].fileTimeLo = 1343826786U;
  (*c2_b_info)[1].fileTimeHi = 0U;
  (*c2_b_info)[1].mFileTimeLo = 0U;
  (*c2_b_info)[1].mFileTimeHi = 0U;
  (*c2_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c2_b_info)[2].name = "eml_scalar_sin";
  (*c2_b_info)[2].dominantType = "double";
  (*c2_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  (*c2_b_info)[2].fileTimeLo = 1286818736U;
  (*c2_b_info)[2].fileTimeHi = 0U;
  (*c2_b_info)[2].mFileTimeLo = 0U;
  (*c2_b_info)[2].mFileTimeHi = 0U;
  (*c2_b_info)[3].context = "";
  (*c2_b_info)[3].name = "mrdivide";
  (*c2_b_info)[3].dominantType = "double";
  (*c2_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c2_b_info)[3].fileTimeLo = 1357947948U;
  (*c2_b_info)[3].fileTimeHi = 0U;
  (*c2_b_info)[3].mFileTimeLo = 1319729966U;
  (*c2_b_info)[3].mFileTimeHi = 0U;
  (*c2_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c2_b_info)[4].name = "rdivide";
  (*c2_b_info)[4].dominantType = "double";
  (*c2_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c2_b_info)[4].fileTimeLo = 1346506788U;
  (*c2_b_info)[4].fileTimeHi = 0U;
  (*c2_b_info)[4].mFileTimeLo = 0U;
  (*c2_b_info)[4].mFileTimeHi = 0U;
  (*c2_b_info)[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c2_b_info)[5].name = "eml_scalexp_compatible";
  (*c2_b_info)[5].dominantType = "double";
  (*c2_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  (*c2_b_info)[5].fileTimeLo = 1286818796U;
  (*c2_b_info)[5].fileTimeHi = 0U;
  (*c2_b_info)[5].mFileTimeLo = 0U;
  (*c2_b_info)[5].mFileTimeHi = 0U;
  (*c2_b_info)[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c2_b_info)[6].name = "eml_div";
  (*c2_b_info)[6].dominantType = "double";
  (*c2_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c2_b_info)[6].fileTimeLo = 1313344210U;
  (*c2_b_info)[6].fileTimeHi = 0U;
  (*c2_b_info)[6].mFileTimeLo = 0U;
  (*c2_b_info)[6].mFileTimeHi = 0U;
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 7), FALSE);
  for (c2_i0 = 0; c2_i0 < 7; c2_i0++) {
    c2_r0 = &c2_info[c2_i0];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i0);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_SyncGen_with_Grid_controllInstanceStruct *chartInstance;
  chartInstance = (SFc2_SyncGen_with_Grid_controllInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_c_emlrt_marshallIn
  (SFc2_SyncGen_with_Grid_controllInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i1;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i1, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i1;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_SyncGen_with_Grid_controllInstanceStruct *chartInstance;
  chartInstance = (SFc2_SyncGen_with_Grid_controllInstanceStruct *)
    chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_d_emlrt_marshallIn
  (SFc2_SyncGen_with_Grid_controllInstanceStruct *chartInstance, const mxArray
   *c2_b_is_active_c2_SyncGen_with_Grid_controll, const char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_SyncGen_with_Grid_controll), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_SyncGen_with_Grid_controll);
  return c2_y;
}

static uint8_T c2_e_emlrt_marshallIn
  (SFc2_SyncGen_with_Grid_controllInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_SyncGen_with_Grid_controllInstanceStruct *
  chartInstance)
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

void sf_c2_SyncGen_with_Grid_controll_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2237337434U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(310452484U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3953922326U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1139616453U);
}

mxArray *sf_c2_SyncGen_with_Grid_controll_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("lh87RYmIVtFDyvQ8mmEOoD");
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

mxArray *sf_c2_SyncGen_with_Grid_controll_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c2_SyncGen_with_Grid_controll(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[5],T\"V_a\",},{M[1],M[8],T\"V_b\",},{M[1],M[9],T\"V_c\",},{M[8],M[0],T\"is_active_c2_SyncGen_with_Grid_controll\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_SyncGen_with_Grid_controll_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_SyncGen_with_Grid_controllInstanceStruct *chartInstance;
    chartInstance = (SFc2_SyncGen_with_Grid_controllInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _SyncGen_with_Grid_controllMachineNumber_,
           2,
           1,
           1,
           6,
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
          init_script_number_translation
            (_SyncGen_with_Grid_controllMachineNumber_,
             chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _SyncGen_with_Grid_controllMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _SyncGen_with_Grid_controllMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"V_g");
          _SFD_SET_DATA_PROPS(1,2,0,1,"V_a");
          _SFD_SET_DATA_PROPS(2,1,1,0,"omega");
          _SFD_SET_DATA_PROPS(3,1,1,0,"t");
          _SFD_SET_DATA_PROPS(4,2,0,1,"V_b");
          _SFD_SET_DATA_PROPS(5,2,0,1,"V_c");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,131);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);

        {
          real_T *c2_V_g;
          real_T *c2_V_a;
          real_T *c2_omega;
          real_T *c2_t;
          real_T *c2_V_b;
          real_T *c2_V_c;
          c2_V_c = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c2_V_b = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c2_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c2_omega = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c2_V_a = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c2_V_g = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_V_g);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_V_a);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_omega);
          _SFD_SET_DATA_VALUE_PTR(3U, c2_t);
          _SFD_SET_DATA_VALUE_PTR(4U, c2_V_b);
          _SFD_SET_DATA_VALUE_PTR(5U, c2_V_c);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _SyncGen_with_Grid_controllMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "MecMpkyUg3ayEjJetx1sED";
}

static void sf_opaque_initialize_c2_SyncGen_with_Grid_controll(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_SyncGen_with_Grid_controllInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_SyncGen_with_Grid_controll
    ((SFc2_SyncGen_with_Grid_controllInstanceStruct*) chartInstanceVar);
  initialize_c2_SyncGen_with_Grid_controll
    ((SFc2_SyncGen_with_Grid_controllInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_SyncGen_with_Grid_controll(void
  *chartInstanceVar)
{
  enable_c2_SyncGen_with_Grid_controll
    ((SFc2_SyncGen_with_Grid_controllInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_SyncGen_with_Grid_controll(void
  *chartInstanceVar)
{
  disable_c2_SyncGen_with_Grid_controll
    ((SFc2_SyncGen_with_Grid_controllInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_SyncGen_with_Grid_controll(void
  *chartInstanceVar)
{
  sf_c2_SyncGen_with_Grid_controll
    ((SFc2_SyncGen_with_Grid_controllInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_SyncGen_with_Grid_controll
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_SyncGen_with_Grid_controll
    ((SFc2_SyncGen_with_Grid_controllInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_SyncGen_with_Grid_controll();/* state var info */
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

extern void sf_internal_set_sim_state_c2_SyncGen_with_Grid_controll(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_SyncGen_with_Grid_controll();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_SyncGen_with_Grid_controll
    ((SFc2_SyncGen_with_Grid_controllInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_SyncGen_with_Grid_controll
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c2_SyncGen_with_Grid_controll(S);
}

static void sf_opaque_set_sim_state_c2_SyncGen_with_Grid_controll(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c2_SyncGen_with_Grid_controll(S, st);
}

static void sf_opaque_terminate_c2_SyncGen_with_Grid_controll(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_SyncGen_with_Grid_controllInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_SyncGen_with_Grid_controll_optimization_info();
    }

    finalize_c2_SyncGen_with_Grid_controll
      ((SFc2_SyncGen_with_Grid_controllInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_SyncGen_with_Grid_controll
    ((SFc2_SyncGen_with_Grid_controllInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_SyncGen_with_Grid_controll(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_SyncGen_with_Grid_controll
      ((SFc2_SyncGen_with_Grid_controllInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_SyncGen_with_Grid_controll(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_SyncGen_with_Grid_controll_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,2,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4170530006U));
  ssSetChecksum1(S,(71889953U));
  ssSetChecksum2(S,(4117742789U));
  ssSetChecksum3(S,(3364064912U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_SyncGen_with_Grid_controll(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_SyncGen_with_Grid_controll(SimStruct *S)
{
  SFc2_SyncGen_with_Grid_controllInstanceStruct *chartInstance;
  chartInstance = (SFc2_SyncGen_with_Grid_controllInstanceStruct *)utMalloc
    (sizeof(SFc2_SyncGen_with_Grid_controllInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_SyncGen_with_Grid_controllInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_SyncGen_with_Grid_controll;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_SyncGen_with_Grid_controll;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_SyncGen_with_Grid_controll;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c2_SyncGen_with_Grid_controll;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c2_SyncGen_with_Grid_controll;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_SyncGen_with_Grid_controll;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_SyncGen_with_Grid_controll;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_SyncGen_with_Grid_controll;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_SyncGen_with_Grid_controll;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_SyncGen_with_Grid_controll;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_SyncGen_with_Grid_controll;
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

void c2_SyncGen_with_Grid_controll_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_SyncGen_with_Grid_controll(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_SyncGen_with_Grid_controll(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_SyncGen_with_Grid_controll(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_SyncGen_with_Grid_controll_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
