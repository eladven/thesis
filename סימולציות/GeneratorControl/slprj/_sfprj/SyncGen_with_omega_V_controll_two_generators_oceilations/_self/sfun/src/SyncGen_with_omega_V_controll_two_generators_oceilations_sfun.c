/* Include files */

#include "SyncGen_with_omega_V_controll_two_generators_oceilations_sfun.h"
#include "SyncGen_with_omega_V_controll_two_generators_oceilations_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _SyncGen_with_omega_V_controll_two_generators_oceilationsMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void SyncGen_with_omega_V_controll_two_generators_oceilations_initializer(void)
{
}

void SyncGen_with_omega_V_controll_two_generators_oceilations_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int
  sf_SyncGen_with_omega_V_controll_two_generators_oceilations_method_dispatcher
  (SimStruct *simstructPtr, unsigned int chartFileNumber, const char* specsCksum,
   int_T method, void *data)
{
  return 0;
}

unsigned int
  sf_SyncGen_with_omega_V_controll_two_generators_oceilations_process_check_sum_call
  ( int nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(17451192U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2525991608U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(336938595U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4058274616U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2770914432U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(68922550U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1005901515U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(181870804U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3564696471U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(678668628U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1090454852U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3896867807U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2449841776U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3855554194U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(421983590U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2375766632U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int
  sf_SyncGen_with_omega_V_controll_two_generators_oceilations_autoinheritance_info
  ( int nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int
  sf_SyncGen_with_omega_V_controll_two_generators_oceilations_get_eml_resolved_functions_info
  ( int nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int
  sf_SyncGen_with_omega_V_controll_two_generators_oceilations_third_party_uses_info
  ( int nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void SyncGen_with_omega_V_controll_two_generators_oceilations_debug_initialize(
    struct SfDebugInstanceStruct* debugInstance)
{
  _SyncGen_with_omega_V_controll_two_generators_oceilationsMachineNumber_ =
    sf_debug_initialize_machine(debugInstance,
    "SyncGen_with_omega_V_controll_two_generators_oceilations","sfun",0,0,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _SyncGen_with_omega_V_controll_two_generators_oceilationsMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _SyncGen_with_omega_V_controll_two_generators_oceilationsMachineNumber_,0);
}

void
  SyncGen_with_omega_V_controll_two_generators_oceilations_register_exported_symbols
  (SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray*
  load_SyncGen_with_omega_V_controll_two_generators_oceilations_optimization_info
  (void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "SyncGen_with_omega_V_controll_two_generators_oceilations",
      "SyncGen_with_omega_V_controll_two_generators_oceilations");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void
  unload_SyncGen_with_omega_V_controll_two_generators_oceilations_optimization_info
  (void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
