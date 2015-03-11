#include "__cf_sldemo_mdlref_counter.h"
#if !defined(S_FUNCTION_NAME)
#define S_FUNCTION_NAME sldemo_mdlref_counter_msf
#endif
#define S_FUNCTION_LEVEL 2
#if !defined(RTW_GENERATED_S_FUNCTION)
#define RTW_GENERATED_S_FUNCTION
#endif
#include <stdio.h>
#include <math.h>
#include "simstruc.h"
#include "fixedpoint.h"
#define rt_logging_h
#include "sldemo_mdlref_counter_types.h"
#include "sldemo_mdlref_counter.h"
#include "sldemo_mdlref_counter_private.h"
MdlRefChildMdlRec childModels [ 1 ] = { "sldemo_mdlref_counter" ,
"sldemo_mdlref_counter" , 0 } ; static void mdlInitializeSizes ( SimStruct *
S ) { ssSetNumSFcnParams ( S , 0 ) ; ssFxpSetU32BitRegionCompliant ( S , 1 )
; rt_InitInfAndNaN ( sizeof ( real_T ) ) ; if ( S -> mdlInfo -> genericFcn !=
( NULL ) ) { _GenericFcn fcn = S -> mdlInfo -> genericFcn ; real_T lifeSpan =
rtInf ; real_T startTime = 0.0 ; real_T stopTime = 10.0 ; int_T hwSettings [
13 ] ; int_T opSettings [ 1 ] ; boolean_T concurrTaskSupport = 0 ; boolean_T
hasDiscTs = 1 ; real_T fixedStep = 0.2 ; ( fcn ) ( S ,
GEN_FCN_CHK_MODELREF_SOLVER_TYPE_EARLY , 2 , ( NULL ) ) ; ( fcn ) ( S ,
GEN_FCN_MODELREF_RATE_GROUPED , 0 , ( NULL ) ) ; if ( ! ( fcn ) ( S ,
GEN_FCN_CHK_MODELREF_LIFE_SPAN , - 1 , & lifeSpan ) ) return ; if ( ! ( fcn )
( S , GEN_FCN_CHK_MODELREF_START_TIME , - 1 , & startTime ) ) return ; if ( !
( fcn ) ( S , GEN_FCN_CHK_MODELREF_STOP_TIME , - 1 , & stopTime ) ) return ;
hwSettings [ 0 ] = 8 ; hwSettings [ 1 ] = 16 ; hwSettings [ 2 ] = 32 ;
hwSettings [ 3 ] = 32 ; hwSettings [ 4 ] = 32 ; hwSettings [ 5 ] = 64 ;
hwSettings [ 6 ] = 32 ; hwSettings [ 7 ] = 2 ; hwSettings [ 8 ] = 0 ;
hwSettings [ 9 ] = 32 ; hwSettings [ 10 ] = 1 ; hwSettings [ 11 ] = 0 ;
hwSettings [ 12 ] = 2 ; if ( ! ( fcn ) ( S ,
GEN_FCN_CHK_MODELREF_HARDWARE_SETTINGS , 13 , hwSettings ) ) return ;
opSettings [ 0 ] = 0 ; if ( ! ( fcn ) ( S ,
GEN_FCN_CHK_MODELREF_OPTIM_SETTINGS , 1 , opSettings ) ) return ; if ( ! (
fcn ) ( S , GEN_FCN_CHK_MODELREF_CONCURRETNT_TASK_SUPPORT , ( int_T )
concurrTaskSupport , NULL ) ) return ; if ( ! ( fcn ) ( S ,
GEN_FCN_CHK_MODELREF_SOLVER_TYPE , 0 , & hasDiscTs ) ) return ; if ( ! ( fcn
) ( S , GEN_FCN_CHK_MODELREF_SOLVER_NAME , 0 , ( void * ) "FixedStepDiscrete"
) ) return ; if ( ! ( fcn ) ( S , GEN_FCN_CHK_MODELREF_SOLVER_MODE ,
SOLVER_MODE_SINGLETASKING , ( NULL ) ) ) return ; if ( ! ( fcn ) ( S ,
GEN_FCN_CHK_MODELREF_FIXED_STEP , 0 , & fixedStep ) ) return ; ( fcn ) ( S ,
GEN_FCN_CHK_MODELREF_FRAME_UPGRADE_DIAGNOSTICS , 1 , ( NULL ) ) ; }
ssSetRTWGeneratedSFcn ( S , 2 ) ; ssSetNumContStates ( S , 0 ) ;
ssSetNumDiscStates ( S , 0 ) ; if ( ! ssSetNumInputPorts ( S , 3 ) ) return ;
if ( ! ssSetInputPortVectorDimension ( S , 0 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 0 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 0 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 0 , SS_DOUBLE ) ;
} ssSetInputPortDirectFeedThrough ( S , 0 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 0 , 1 ) ; ssSetInputPortOptimOpts ( S
, 0 , SS_NOT_REUSABLE_AND_LOCAL ) ; ssSetInputPortOverWritable ( S , 0 ,
FALSE ) ; ssSetInputPortSampleTime ( S , 0 , - 1 ) ; if ( !
ssSetInputPortVectorDimension ( S , 1 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 1 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 1 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 1 , SS_DOUBLE ) ;
} ssSetInputPortDirectFeedThrough ( S , 1 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 1 , 1 ) ; ssSetInputPortOptimOpts ( S
, 1 , SS_REUSABLE_AND_LOCAL ) ; ssSetInputPortOverWritable ( S , 1 , FALSE )
; ssSetInputPortSampleTime ( S , 1 , - 1 ) ; if ( !
ssSetInputPortVectorDimension ( S , 2 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 2 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 2 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 2 , SS_DOUBLE ) ;
} ssSetInputPortDirectFeedThrough ( S , 2 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 2 , 1 ) ; ssSetInputPortOptimOpts ( S
, 2 , SS_NOT_REUSABLE_AND_LOCAL ) ; ssSetInputPortOverWritable ( S , 2 ,
FALSE ) ; ssSetInputPortSampleTime ( S , 2 , - 1 ) ; if ( !
ssSetNumOutputPorts ( S , 1 ) ) return ; if ( !
ssSetOutputPortVectorDimension ( S , 0 , 1 ) ) return ;
ssSetOutputPortDimensionsMode ( S , 0 , FIXED_DIMS_MODE ) ;
ssSetOutputPortFrameData ( S , 0 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetOutputPortDataType ( S , 0 , SS_DOUBLE )
; } ssSetOutputPortSampleTime ( S , 0 , - 1 ) ;
ssSetOutputPortDiscreteValuedOutput ( S , 0 , 0 ) ; ssSetOutputPortOkToMerge
( S , 0 , SS_NOT_OK_TO_MERGE ) ; ssSetOutputPortOptimOpts ( S , 0 ,
SS_NOT_REUSABLE_AND_GLOBAL ) ; { real_T minValue = rtMinusInf ; real_T
maxValue = rtInf ; ssSetModelRefInputSignalDesignMin ( S , 0 , & minValue ) ;
ssSetModelRefInputSignalDesignMax ( S , 0 , & maxValue ) ; } { real_T
minValue = rtMinusInf ; real_T maxValue = rtInf ;
ssSetModelRefInputSignalDesignMin ( S , 1 , & minValue ) ;
ssSetModelRefInputSignalDesignMax ( S , 1 , & maxValue ) ; } { real_T
minValue = rtMinusInf ; real_T maxValue = rtInf ;
ssSetModelRefInputSignalDesignMin ( S , 2 , & minValue ) ;
ssSetModelRefInputSignalDesignMax ( S , 2 , & maxValue ) ; } { real_T
minValue = rtMinusInf ; real_T maxValue = rtInf ;
ssSetModelRefOutputSignalDesignMin ( S , 0 , & minValue ) ;
ssSetModelRefOutputSignalDesignMax ( S , 0 , & maxValue ) ; } { static
ssRTWStorageType storageClass [ 4 ] = { SS_RTW_STORAGE_AUTO ,
SS_RTW_STORAGE_AUTO , SS_RTW_STORAGE_AUTO , SS_RTW_STORAGE_AUTO } ;
ssSetModelRefPortRTWStorageClasses ( S , storageClass ) ; }
ssSetModelRefSignalLoggingSaveFormat ( S , SS_MODEL_DATA_LOGS ) ;
ssSetNumSampleTimes ( S , PORT_BASED_SAMPLE_TIMES ) ; ssSetNumRWork ( S , 0 )
; ssSetNumIWork ( S , 0 ) ; ssSetNumPWork ( S , 0 ) ; ssSetNumModes ( S , 0 )
; { int_T zcsIdx = 0 ; } ssSetOutputPortIsNonContinuous ( S , 0 , 0 ) ;
ssSetOutputPortIsFedByBlockWithModesNoZCs ( S , 0 , 0 ) ;
ssSetInputPortIsNotDerivPort ( S , 0 , 1 ) ; ssSetInputPortIsNotDerivPort ( S
, 1 , 1 ) ; ssSetInputPortIsNotDerivPort ( S , 2 , 1 ) ;
ssSetModelReferenceSampleTimeInheritanceRule ( S ,
USE_DEFAULT_FOR_DISCRETE_INHERITANCE ) ; ssSetOptimizeModelRefInitCode ( S ,
0 ) ; ssSetAcceptsFcnCallInputs ( S ) ; ssSetModelReferenceNormalModeSupport
( S , MDL_START_AND_MDL_PROCESS_PARAMS_OK ) ; ssSupportsMultipleExecInstances
( S , false ) ; ssRegisterMsgForNotSupportingMultiExecInst ( S ,
 "<diag_root><diag id=\"Simulink:blocks:BlockDoesNotSupportMultiExecInstances\"><arguments><arg type=\"encoded\">cwBsAGQAZQBtAG8AXwBtAGQAbAByAGUAZgBfAGMAbwB1AG4AdABlAHIALwBTAGMAbwBwAGUAQQAAAA==</arg><arg type=\"encoded\">PABfAF8AaQBpAFMAUwBfAF8APgA8AC8AXwBfAGkAaQBTAFMAXwBfAD4AAAA=</arg><arg type=\"encoded\">PABfAF8AaQB0AGUAcgBCAGwAawBfAF8APgA8AC8AXwBfAGkAdABlAHIAQgBsAGsAXwBfAD4AAAA=</arg></arguments></diag>\n</diag_root>"
) ; ssHasStateInsideForEachSS ( S , false ) ; ssSetModelRefHasParforForEachSS
( S , false ) ; ssSetModelRefHasVariantModelOrSubsystem ( S , false ) ;
ssSetOptions ( S , SS_OPTION_EXCEPTION_FREE_CODE |
SS_OPTION_DISALLOW_CONSTANT_SAMPLE_TIME |
SS_OPTION_ALLOW_PORT_SAMPLE_TIME_IN_TRIGSS |
SS_OPTION_SUPPORTS_ALIAS_DATA_TYPES | SS_OPTION_WORKS_WITH_CODE_REUSE ) ; if
( S -> mdlInfo -> genericFcn != ( NULL ) ) { ssRegModelRefChildModel ( S , 1
, childModels ) ; }
#if SS_SFCN_FOR_SIM 
if ( S -> mdlInfo -> genericFcn != ( NULL ) && ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { int_T retVal = 1 ;
mr_sldemo_mdlref_counter_MdlInfoRegFcn ( S , "sldemo_mdlref_counter" , &
retVal ) ; if ( ! retVal ) return ; }
#endif
if ( ! ssSetNumDWork ( S , 1 ) ) { return ; }
#if SS_SFCN_FOR_SIM
{ int mdlrefDWTypeId ; ssRegMdlRefDWorkType ( S , & mdlrefDWTypeId ) ; if (
mdlrefDWTypeId == INVALID_DTYPE_ID ) return ; if ( ! ssSetDataTypeSize ( S ,
mdlrefDWTypeId , sizeof ( kif1wuqbzxn ) ) ) return ; ssSetDWorkDataType ( S ,
0 , mdlrefDWTypeId ) ; ssSetDWorkWidth ( S , 0 , 1 ) ; }
#endif
ssSetModelRefHasEnablePort ( S , 0 ) ; } static void mdlInitializeSampleTimes
( SimStruct * S ) { }
#define MDL_INITIALIZE_CONDITIONS
static void mdlInitializeConditions ( SimStruct * S ) { kif1wuqbzxn * dw = (
kif1wuqbzxn * ) ssGetDWork ( S , 0 ) ; dxxgfsdusg ( & ( dw -> rtdw ) ) ; }
#define MDL_SET_WORK_WIDTHS
static void mdlSetWorkWidths ( SimStruct * S ) { if ( S -> mdlInfo ->
genericFcn != ( NULL ) ) { _GenericFcn fcn = S -> mdlInfo -> genericFcn ;
ssSetSignalSizesComputeType ( S , SS_VARIABLE_SIZE_FROM_INPUT_VALUE_AND_SIZE
) ; } { static const char * toFileNames [ ] = { "" } ; static const char *
fromFileNames [ ] = { "" } ; if ( ! ssSetModelRefFromFiles ( S , 0 ,
fromFileNames ) ) return ; if ( ! ssSetModelRefToFiles ( S , 0 , toFileNames
) ) return ; } }
#define MDL_START
static void mdlStart ( SimStruct * S ) { kif1wuqbzxn * dw = ( kif1wuqbzxn * )
ssGetDWork ( S , 0 ) ; void * sysRanPtr = ( NULL ) ; int sysTid = 0 ;
ssGetContextSysRanBCPtr ( S , & sysRanPtr ) ; ssGetContextSysTid ( S , &
sysTid ) ; if ( sysTid == CONSTANT_TID ) { sysTid = 0 ; } fkcxcal2e3 ( S ,
ssGetSampleTimeTaskID ( S , 0 ) , & ( dw -> rtm ) , & ( dw -> rtdw ) ,
sysRanPtr , sysTid , ( NULL ) , ( NULL ) , 0 , - 1 ) ;
ssSetModelMappingInfoPtr ( S , & ( dw -> rtm . DataMapInfo . mmi ) ) ; if ( S
-> mdlInfo -> genericFcn != ( NULL ) ) { _GenericFcn fcn = S -> mdlInfo ->
genericFcn ; } } static void mdlOutputs ( SimStruct * S , int_T tid ) { const
real_T * InPort_0 = ( real_T * ) ssGetInputPortSignal ( S , 0 ) ; const
real_T * InPort_1 = ( real_T * ) ssGetInputPortSignal ( S , 1 ) ; const
real_T * InPort_2 = ( real_T * ) ssGetInputPortSignal ( S , 2 ) ; real_T *
OutPort_0 = ( real_T * ) ssGetOutputPortSignal ( S , 0 ) ; kif1wuqbzxn * dw =
( kif1wuqbzxn * ) ssGetDWork ( S , 0 ) ; if ( tid != CONSTANT_TID ) {
sldemo_mdlref_counter ( InPort_0 , InPort_1 , InPort_2 , OutPort_0 , & ( dw
-> rtdw ) ) ; } }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { real_T * OutPort_0 = (
real_T * ) ssGetOutputPortSignal ( S , 0 ) ; kif1wuqbzxn * dw = ( kif1wuqbzxn
* ) ssGetDWork ( S , 0 ) ; edzd5yvevz ( OutPort_0 , & ( dw -> rtdw ) ) ; }
static void mdlTerminate ( SimStruct * S ) { kif1wuqbzxn * dw = ( kif1wuqbzxn
* ) ssGetDWork ( S , 0 ) ; }
#ifdef  MATLAB_MEX_FILE    
#include "simulink.c"
#include "fixedpoint.c"
#else
#include "cg_sfun.h"
#endif
