#include "__cf_sldemo_mdlref_counter.h"
#include "sldemo_mdlref_counter.h"
#include "rtw_capi.h"
#include "sldemo_mdlref_counter_private.h"
static rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) ,
0 , 0 , 0 , 0 , 0 } } ; static rtwCAPI_LoggingBusElement rtBusElements [ ] =
{ { 0 , rtwCAPI_signal } } ; static rtwCAPI_LoggingBusSignals rtBusSignals [
] = { { ( NULL ) , ( NULL ) , 0 , 0 , ( NULL ) } } ; static rtwCAPI_States
rtBlockStates [ ] = { { 0 , - 1 , "sldemo_mdlref_counter/Previous Output" ,
"" , "" , 0 , 0 , 0 , 0 , 0 , 0 } , { 0 , - 1 , ( NULL ) , ( NULL ) , ( NULL
) , 0 , 0 , 0 , 0 , 0 , 0 } } ; static void
sldemo_mdlref_counter_InitializeDataAddr ( void * dataAddr [ ] , k2kslffmdl *
localDW ) { dataAddr [ 0 ] = ( void * ) ( & localDW -> enbaypj5ps ) ; }
static void sldemo_mdlref_counter_InitializeVarDimsAddr ( int32_T *
vardimsAddr [ ] ) { vardimsAddr [ 0 ] = ( NULL ) ; } static
rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" , "real_T" , 0 , 0 ,
sizeof ( real_T ) , SS_DOUBLE , 0 , 0 } } ; static rtwCAPI_ElementMap
rtElementMap [ ] = { { ( NULL ) , 0 , 0 , 0 , 0 } , } ; static
rtwCAPI_DimensionMap rtDimensionMap [ ] = { { rtwCAPI_SCALAR , 0 , 2 , 0 } }
; static uint_T rtDimensionArray [ ] = { 1 , 1 } ; static const real_T
rtcapiStoredFloats [ ] = { 0.2 , 0.0 } ; static rtwCAPI_FixPtMap rtFixPtMap [
] = { { ( NULL ) , ( NULL ) , rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static
rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] , 0 ,
0 } } ; static int_T rtContextSystems [ 3 ] ; static rtwCAPI_LoggingMetaInfo
loggingMetaInfo [ ] = { { 0 , 0 , "" , 0 } } ; static
rtwCAPI_ModelMapLoggingStaticInfo mmiStaticInfoLogging = { 3 ,
rtContextSystems , loggingMetaInfo , 0 , rtBusSignals , { 0 , NULL , NULL } ,
0 , ( NULL ) } ; static rtwCAPI_ModelMappingStaticInfo mmiStatic = { {
rtBlockSignals , 0 , ( NULL ) , 0 , ( NULL ) , 0 } , { ( NULL ) , 0 , ( NULL
) , 0 } , { rtBlockStates , 1 } , { rtDataTypeMap , rtDimensionMap ,
rtFixPtMap , rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float" ,
& mmiStaticInfoLogging , 0 , } ; const rtwCAPI_ModelMappingStaticInfo *
sldemo_mdlref_counter_GetCAPIStaticMap ( ) { return & mmiStatic ; } static
void sldemo_mdlref_counter_InitializeSystemRan ( hpker3z0vt * const
csoynizrov , sysRanDType * systemRan [ ] , k2kslffmdl * localDW , int_T
systemTid [ ] , void * rootSysRanPtr , int rootTid ) { systemRan [ 0 ] = (
sysRanDType * ) rootSysRanPtr ; systemRan [ 1 ] = ( NULL ) ; systemRan [ 2 ]
= ( NULL ) ; systemTid [ 1 ] = rootTid ; systemTid [ 2 ] = rootTid ;
systemTid [ 0 ] = rootTid ; rtContextSystems [ 0 ] = 0 ; rtContextSystems [ 1
] = 0 ; rtContextSystems [ 2 ] = 0 ; } void
sldemo_mdlref_counter_InitializeDataMapInfo ( hpker3z0vt * const csoynizrov ,
k2kslffmdl * localDW , void * sysRanPtr , int contextTid ) {
rtwCAPI_SetVersion ( csoynizrov -> DataMapInfo . mmi , 1 ) ;
rtwCAPI_SetStaticMap ( csoynizrov -> DataMapInfo . mmi , & mmiStatic ) ;
rtwCAPI_SetLoggingStaticMap ( csoynizrov -> DataMapInfo . mmi , &
mmiStaticInfoLogging ) ; sldemo_mdlref_counter_InitializeDataAddr (
csoynizrov -> DataMapInfo . dataAddress , localDW ) ;
rtwCAPI_SetDataAddressMap ( csoynizrov -> DataMapInfo . mmi , csoynizrov ->
DataMapInfo . dataAddress ) ; sldemo_mdlref_counter_InitializeVarDimsAddr (
csoynizrov -> DataMapInfo . vardimsAddress ) ; rtwCAPI_SetVarDimsAddressMap (
csoynizrov -> DataMapInfo . mmi , csoynizrov -> DataMapInfo . vardimsAddress
) ; rtwCAPI_SetPath ( csoynizrov -> DataMapInfo . mmi , ( NULL ) ) ;
rtwCAPI_SetFullPath ( csoynizrov -> DataMapInfo . mmi , ( NULL ) ) ;
rtwCAPI_SetInstanceLoggingInfo ( csoynizrov -> DataMapInfo . mmi , &
csoynizrov -> DataMapInfo . mmiLogInstanceInfo ) ; rtwCAPI_SetChildMMIArray (
csoynizrov -> DataMapInfo . mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArrayLen (
csoynizrov -> DataMapInfo . mmi , 0 ) ;
sldemo_mdlref_counter_InitializeSystemRan ( csoynizrov , csoynizrov ->
DataMapInfo . systemRan , localDW , csoynizrov -> DataMapInfo . systemTid ,
sysRanPtr , contextTid ) ; rtwCAPI_SetSystemRan ( csoynizrov -> DataMapInfo .
mmi , csoynizrov -> DataMapInfo . systemRan ) ; rtwCAPI_SetSystemTid (
csoynizrov -> DataMapInfo . mmi , csoynizrov -> DataMapInfo . systemTid ) ;
rtwCAPI_SetGlobalTIDMap ( csoynizrov -> DataMapInfo . mmi , & csoynizrov ->
Timing . mdlref_GlobalTID [ 0 ] ) ; }
