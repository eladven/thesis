#include "__cf_sldemo_mdlref_counter.h"
#include "sldemo_mdlref_counter_capi.h"
#include "sldemo_mdlref_counter.h"
#include "sldemo_mdlref_counter_private.h"
static RegMdlInfo rtMdlInfo_sldemo_mdlref_counter [ 25 ] = { { "kif1wuqbzxn"
, MDL_INFO_NAME_MDLREF_DWORK , 0 , - 1 , ( void * ) "sldemo_mdlref_counter" }
, { "kvven3wf2p" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"sldemo_mdlref_counter" } , { "ejjoxr1l3z" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT
, 0 , - 1 , ( void * ) "sldemo_mdlref_counter" } , { "m42oowqvk3" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"sldemo_mdlref_counter" } , { "mwlkec50ep" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT
, 0 , - 1 , ( void * ) "sldemo_mdlref_counter" } , { "ce0ktajikf" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"sldemo_mdlref_counter" } , { "nfs1nelvxt" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT
, 0 , - 1 , ( void * ) "sldemo_mdlref_counter" } , { "a1f5w1jqji" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"sldemo_mdlref_counter" } , { "fwliqejaja" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT
, 0 , - 1 , ( void * ) "sldemo_mdlref_counter" } , { "fh3tgpsxhi" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"sldemo_mdlref_counter" } , { "k2kslffmdl" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT
, 0 , - 1 , ( void * ) "sldemo_mdlref_counter" } , { "ayleilg2tw" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"sldemo_mdlref_counter" } , { "piz4qn4w2h" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT
, 0 , - 1 , ( void * ) "sldemo_mdlref_counter" } , { "liwoslp1uf" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"sldemo_mdlref_counter" } , { "edzd5yvevz" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT
, 0 , - 1 , ( void * ) "sldemo_mdlref_counter" } , { "dxxgfsdusg" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"sldemo_mdlref_counter" } , { "fkcxcal2e3" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT
, 0 , - 1 , ( void * ) "sldemo_mdlref_counter" } , { "agz0fugz0s" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"sldemo_mdlref_counter" } , { "sldemo_mdlref_counter" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , 0 , ( NULL ) } , { "lgatltrtnn" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"sldemo_mdlref_counter" } , { "hpker3z0vt" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT
, 0 , - 1 , ( void * ) "sldemo_mdlref_counter" } , { "npc1vd3qruq" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"sldemo_mdlref_counter" } , { "npc1vd3qru" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT
, 0 , - 1 , ( void * ) "sldemo_mdlref_counter" } , {
"sldemo_mdlref_counter.h" , MDL_INFO_MODEL_FILENAME , 0 , 0 , ( NULL ) } , {
"sldemo_mdlref_counter.c" , MDL_INFO_MODEL_FILENAME , 0 , 0 , ( NULL ) } } ;
void dxxgfsdusg ( k2kslffmdl * localDW ) { localDW -> enbaypj5ps = 0.0 ; }
void sldemo_mdlref_counter ( const real_T * gyojmgiysr , const real_T *
ehhaj0uax1 , const real_T * gwk3cowc3i , real_T * cb3yipslmm , k2kslffmdl *
localDW ) { real_T lsmrl5t5nd ; boolean_T mbk4b5vrx2 ; boolean_T oi1zkcqqng ;
lsmrl5t5nd = * ehhaj0uax1 + localDW -> enbaypj5ps ; mbk4b5vrx2 = ( *
gyojmgiysr >= lsmrl5t5nd ) ; oi1zkcqqng = ( lsmrl5t5nd >= * gwk3cowc3i ) ; if
( mbk4b5vrx2 && oi1zkcqqng ) { * cb3yipslmm = lsmrl5t5nd ; } else if (
oi1zkcqqng ) { * cb3yipslmm = * gyojmgiysr ; } else { * cb3yipslmm = *
gwk3cowc3i ; } } void edzd5yvevz ( real_T * cb3yipslmm , k2kslffmdl * localDW
) { localDW -> enbaypj5ps = * cb3yipslmm ; } void fkcxcal2e3 ( SimStruct *
_mdlRefSfcnS , int_T mdlref_TID0 , hpker3z0vt * const csoynizrov , k2kslffmdl
* localDW , void * sysRanPtr , int contextTid , rtwCAPI_ModelMappingInfo *
rt_ParentMMI , const char_T * rt_ChildPath , int_T rt_ChildMMIIdx , int_T
rt_CSTATEIdx ) { rt_InitInfAndNaN ( sizeof ( real_T ) ) ; ( void ) memset ( (
void * ) csoynizrov , 0 , sizeof ( hpker3z0vt ) ) ; csoynizrov -> Timing .
mdlref_GlobalTID [ 0 ] = mdlref_TID0 ; csoynizrov -> _mdlRefSfcnS = (
_mdlRefSfcnS ) ; ( void ) memset ( ( void * ) localDW , 0 , sizeof (
k2kslffmdl ) ) ; localDW -> enbaypj5ps = 0.0 ;
sldemo_mdlref_counter_InitializeDataMapInfo ( csoynizrov , localDW ,
sysRanPtr , contextTid ) ; if ( ( rt_ParentMMI != ( NULL ) ) && (
rt_ChildPath != ( NULL ) ) ) { rtwCAPI_SetChildMMI ( * rt_ParentMMI ,
rt_ChildMMIIdx , & ( csoynizrov -> DataMapInfo . mmi ) ) ; rtwCAPI_SetPath (
csoynizrov -> DataMapInfo . mmi , rt_ChildPath ) ;
rtwCAPI_MMISetContStateStartIndex ( csoynizrov -> DataMapInfo . mmi ,
rt_CSTATEIdx ) ; } } void mr_sldemo_mdlref_counter_MdlInfoRegFcn ( SimStruct
* mdlRefSfcnS , char_T * modelName , int_T * retVal ) { * retVal = 0 ; *
retVal = 0 ; ssRegModelRefMdlInfo ( mdlRefSfcnS , modelName ,
rtMdlInfo_sldemo_mdlref_counter , 25 ) ; * retVal = 1 ; }
