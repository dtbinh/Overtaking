/* Include files */

#include "Modified_sfun.h"
#include "Modified_sfun_debug_macros.h"
#include "c3_Modified.h"
#include "c4_Modified.h"
#include "c5_Modified.h"
#include "c6_Modified.h"
#include "c7_Modified.h"
#include "c8_Modified.h"
#include "c9_Modified.h"
#include "c10_Modified.h"
#include "c11_Modified.h"
#include "c12_Modified.h"
#include "c13_Modified.h"
#include "c15_Modified.h"
#include "c19_Modified.h"
#include "c20_Modified.h"
#include "c26_Modified.h"
#include "c28_Modified.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _ModifiedMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void Modified_initializer(void)
{
}

void Modified_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_Modified_method_dispatcher(SimStruct *simstructPtr, unsigned int
  chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==3) {
    c3_Modified_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_Modified_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_Modified_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_Modified_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_Modified_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_Modified_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_Modified_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_Modified_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_Modified_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==12) {
    c12_Modified_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==13) {
    c13_Modified_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==15) {
    c15_Modified_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==19) {
    c19_Modified_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==20) {
    c20_Modified_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==26) {
    c26_Modified_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==28) {
    c28_Modified_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

extern void sf_Modified_uses_exported_functions(int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[])
{
  plhs[0] = mxCreateLogicalScalar(0);
}

unsigned int sf_Modified_process_check_sum_call( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1019030811U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1026629003U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1623511087U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3440204551U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1691970369U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(334445793U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1215074065U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2321420332U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 3:
        {
          extern void sf_c3_Modified_get_check_sum(mxArray *plhs[]);
          sf_c3_Modified_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_Modified_get_check_sum(mxArray *plhs[]);
          sf_c4_Modified_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_Modified_get_check_sum(mxArray *plhs[]);
          sf_c5_Modified_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_Modified_get_check_sum(mxArray *plhs[]);
          sf_c6_Modified_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_Modified_get_check_sum(mxArray *plhs[]);
          sf_c7_Modified_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_Modified_get_check_sum(mxArray *plhs[]);
          sf_c8_Modified_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_Modified_get_check_sum(mxArray *plhs[]);
          sf_c9_Modified_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_Modified_get_check_sum(mxArray *plhs[]);
          sf_c10_Modified_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_Modified_get_check_sum(mxArray *plhs[]);
          sf_c11_Modified_get_check_sum(plhs);
          break;
        }

       case 12:
        {
          extern void sf_c12_Modified_get_check_sum(mxArray *plhs[]);
          sf_c12_Modified_get_check_sum(plhs);
          break;
        }

       case 13:
        {
          extern void sf_c13_Modified_get_check_sum(mxArray *plhs[]);
          sf_c13_Modified_get_check_sum(plhs);
          break;
        }

       case 15:
        {
          extern void sf_c15_Modified_get_check_sum(mxArray *plhs[]);
          sf_c15_Modified_get_check_sum(plhs);
          break;
        }

       case 19:
        {
          extern void sf_c19_Modified_get_check_sum(mxArray *plhs[]);
          sf_c19_Modified_get_check_sum(plhs);
          break;
        }

       case 20:
        {
          extern void sf_c20_Modified_get_check_sum(mxArray *plhs[]);
          sf_c20_Modified_get_check_sum(plhs);
          break;
        }

       case 26:
        {
          extern void sf_c26_Modified_get_check_sum(mxArray *plhs[]);
          sf_c26_Modified_get_check_sum(plhs);
          break;
        }

       case 28:
        {
          extern void sf_c28_Modified_get_check_sum(mxArray *plhs[]);
          sf_c28_Modified_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(217978624U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(90317617U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(122204193U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(175990835U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2382311347U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(691609949U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(642588632U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2537340057U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Modified_autoinheritance_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
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
     case 3:
      {
        if (strcmp(aiChksum, "wSDJnyulOS8BTX1P0GxauC") == 0) {
          extern mxArray *sf_c3_Modified_get_autoinheritance_info(void);
          plhs[0] = sf_c3_Modified_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "02t5ILhxBbimPyrbO4goBD") == 0) {
          extern mxArray *sf_c4_Modified_get_autoinheritance_info(void);
          plhs[0] = sf_c4_Modified_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "nKz708AEfGcxK0u7dhXWNE") == 0) {
          extern mxArray *sf_c5_Modified_get_autoinheritance_info(void);
          plhs[0] = sf_c5_Modified_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "Rjl2e1nfR9I8I6RQGORYrG") == 0) {
          extern mxArray *sf_c6_Modified_get_autoinheritance_info(void);
          plhs[0] = sf_c6_Modified_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 7:
      {
        if (strcmp(aiChksum, "4KBftNIt1XbPK07dTXwFC") == 0) {
          extern mxArray *sf_c7_Modified_get_autoinheritance_info(void);
          plhs[0] = sf_c7_Modified_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "yymzPjWWJIO6bqgeXReD6") == 0) {
          extern mxArray *sf_c8_Modified_get_autoinheritance_info(void);
          plhs[0] = sf_c8_Modified_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "OcMS8rv8RU3JjKc5YauSLG") == 0) {
          extern mxArray *sf_c9_Modified_get_autoinheritance_info(void);
          plhs[0] = sf_c9_Modified_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 10:
      {
        if (strcmp(aiChksum, "XHzXl0mgVcLlXLQ5uaqgrG") == 0) {
          extern mxArray *sf_c10_Modified_get_autoinheritance_info(void);
          plhs[0] = sf_c10_Modified_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 11:
      {
        if (strcmp(aiChksum, "1u9pYwycNOXhEp6ajs6LnH") == 0) {
          extern mxArray *sf_c11_Modified_get_autoinheritance_info(void);
          plhs[0] = sf_c11_Modified_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 12:
      {
        if (strcmp(aiChksum, "iPZOHvxGs5S3V7Su2dlI9F") == 0) {
          extern mxArray *sf_c12_Modified_get_autoinheritance_info(void);
          plhs[0] = sf_c12_Modified_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 13:
      {
        if (strcmp(aiChksum, "7Gizfo0uGfrrOBsJlcLSkB") == 0) {
          extern mxArray *sf_c13_Modified_get_autoinheritance_info(void);
          plhs[0] = sf_c13_Modified_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 15:
      {
        if (strcmp(aiChksum, "aVDperqwIDDlHOIilj6ZNB") == 0) {
          extern mxArray *sf_c15_Modified_get_autoinheritance_info(void);
          plhs[0] = sf_c15_Modified_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 19:
      {
        if (strcmp(aiChksum, "RJu74AGZdeEIRjRPUAK4OC") == 0) {
          extern mxArray *sf_c19_Modified_get_autoinheritance_info(void);
          plhs[0] = sf_c19_Modified_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 20:
      {
        if (strcmp(aiChksum, "RwTBEKcRFTrNYkxp3DCTeB") == 0) {
          extern mxArray *sf_c20_Modified_get_autoinheritance_info(void);
          plhs[0] = sf_c20_Modified_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 26:
      {
        if (strcmp(aiChksum, "L4WY8Uz3OjKjg0SwXKv0zG") == 0) {
          extern mxArray *sf_c26_Modified_get_autoinheritance_info(void);
          plhs[0] = sf_c26_Modified_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 28:
      {
        if (strcmp(aiChksum, "e8XHXZMouSWuiMLKKkIuv") == 0) {
          extern mxArray *sf_c28_Modified_get_autoinheritance_info(void);
          plhs[0] = sf_c28_Modified_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Modified_get_eml_resolved_functions_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
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
     case 3:
      {
        extern const mxArray *sf_c3_Modified_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_Modified_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray *sf_c4_Modified_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_Modified_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray *sf_c5_Modified_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_Modified_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray *sf_c6_Modified_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_Modified_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray *sf_c7_Modified_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_Modified_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray *sf_c8_Modified_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_Modified_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray *sf_c9_Modified_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_Modified_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray *sf_c10_Modified_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_Modified_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray *sf_c11_Modified_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_Modified_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 12:
      {
        extern const mxArray *sf_c12_Modified_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c12_Modified_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 13:
      {
        extern const mxArray *sf_c13_Modified_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c13_Modified_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 15:
      {
        extern const mxArray *sf_c15_Modified_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c15_Modified_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 19:
      {
        extern const mxArray *sf_c19_Modified_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c19_Modified_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 20:
      {
        extern const mxArray *sf_c20_Modified_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c20_Modified_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 26:
      {
        extern const mxArray *sf_c26_Modified_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c26_Modified_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 28:
      {
        extern const mxArray *sf_c28_Modified_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c28_Modified_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Modified_third_party_uses_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
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
     case 3:
      {
        if (strcmp(tpChksum, "QtcePKxe4H9FFy5hhEFE6E") == 0) {
          extern mxArray *sf_c3_Modified_third_party_uses_info(void);
          plhs[0] = sf_c3_Modified_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "pCGJpivanLlOQcKqfmeI7D") == 0) {
          extern mxArray *sf_c4_Modified_third_party_uses_info(void);
          plhs[0] = sf_c4_Modified_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "aVcLF4aeXNV7qLRkFPcTHD") == 0) {
          extern mxArray *sf_c5_Modified_third_party_uses_info(void);
          plhs[0] = sf_c5_Modified_third_party_uses_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "8GQqFczwrdbHx0h3x8FJLG") == 0) {
          extern mxArray *sf_c6_Modified_third_party_uses_info(void);
          plhs[0] = sf_c6_Modified_third_party_uses_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "dM3QmCydJQ4zatzpUcaKaG") == 0) {
          extern mxArray *sf_c7_Modified_third_party_uses_info(void);
          plhs[0] = sf_c7_Modified_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "12uNfbaObI9kdJUMJypraD") == 0) {
          extern mxArray *sf_c8_Modified_third_party_uses_info(void);
          plhs[0] = sf_c8_Modified_third_party_uses_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "8QlPsK8YvvPlEKOLT26g0F") == 0) {
          extern mxArray *sf_c9_Modified_third_party_uses_info(void);
          plhs[0] = sf_c9_Modified_third_party_uses_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "lBiAltMC72HqN30bOEc17E") == 0) {
          extern mxArray *sf_c10_Modified_third_party_uses_info(void);
          plhs[0] = sf_c10_Modified_third_party_uses_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "nsuilLiT8rixZOJEK30JvD") == 0) {
          extern mxArray *sf_c11_Modified_third_party_uses_info(void);
          plhs[0] = sf_c11_Modified_third_party_uses_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "Lffav7JhMYenT53ThT6x3G") == 0) {
          extern mxArray *sf_c12_Modified_third_party_uses_info(void);
          plhs[0] = sf_c12_Modified_third_party_uses_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "bFcY0vA3yx0dOBkNrnUtZG") == 0) {
          extern mxArray *sf_c13_Modified_third_party_uses_info(void);
          plhs[0] = sf_c13_Modified_third_party_uses_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "CdMwZd5ZINXTTrKHPqfMxC") == 0) {
          extern mxArray *sf_c15_Modified_third_party_uses_info(void);
          plhs[0] = sf_c15_Modified_third_party_uses_info();
          break;
        }
      }

     case 19:
      {
        if (strcmp(tpChksum, "vfMzKFiWd9gxZLQUJsLr3D") == 0) {
          extern mxArray *sf_c19_Modified_third_party_uses_info(void);
          plhs[0] = sf_c19_Modified_third_party_uses_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "Ry1PGFKv4FlGo9qr0Q1IBD") == 0) {
          extern mxArray *sf_c20_Modified_third_party_uses_info(void);
          plhs[0] = sf_c20_Modified_third_party_uses_info();
          break;
        }
      }

     case 26:
      {
        if (strcmp(tpChksum, "eNOzoSQLev7mB2ZCyUgDCC") == 0) {
          extern mxArray *sf_c26_Modified_third_party_uses_info(void);
          plhs[0] = sf_c26_Modified_third_party_uses_info();
          break;
        }
      }

     case 28:
      {
        if (strcmp(tpChksum, "kn3zcNJAn7zRGpNQD8RKMC") == 0) {
          extern mxArray *sf_c28_Modified_third_party_uses_info(void);
          plhs[0] = sf_c28_Modified_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_Modified_jit_fallback_info( int nlhs, mxArray * plhs[], int nrhs,
  const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the jit_fallback_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_jit_fallback_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 3:
      {
        if (strcmp(tpChksum, "QtcePKxe4H9FFy5hhEFE6E") == 0) {
          extern mxArray *sf_c3_Modified_jit_fallback_info(void);
          plhs[0] = sf_c3_Modified_jit_fallback_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "pCGJpivanLlOQcKqfmeI7D") == 0) {
          extern mxArray *sf_c4_Modified_jit_fallback_info(void);
          plhs[0] = sf_c4_Modified_jit_fallback_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "aVcLF4aeXNV7qLRkFPcTHD") == 0) {
          extern mxArray *sf_c5_Modified_jit_fallback_info(void);
          plhs[0] = sf_c5_Modified_jit_fallback_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "8GQqFczwrdbHx0h3x8FJLG") == 0) {
          extern mxArray *sf_c6_Modified_jit_fallback_info(void);
          plhs[0] = sf_c6_Modified_jit_fallback_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "dM3QmCydJQ4zatzpUcaKaG") == 0) {
          extern mxArray *sf_c7_Modified_jit_fallback_info(void);
          plhs[0] = sf_c7_Modified_jit_fallback_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "12uNfbaObI9kdJUMJypraD") == 0) {
          extern mxArray *sf_c8_Modified_jit_fallback_info(void);
          plhs[0] = sf_c8_Modified_jit_fallback_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "8QlPsK8YvvPlEKOLT26g0F") == 0) {
          extern mxArray *sf_c9_Modified_jit_fallback_info(void);
          plhs[0] = sf_c9_Modified_jit_fallback_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "lBiAltMC72HqN30bOEc17E") == 0) {
          extern mxArray *sf_c10_Modified_jit_fallback_info(void);
          plhs[0] = sf_c10_Modified_jit_fallback_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "nsuilLiT8rixZOJEK30JvD") == 0) {
          extern mxArray *sf_c11_Modified_jit_fallback_info(void);
          plhs[0] = sf_c11_Modified_jit_fallback_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "Lffav7JhMYenT53ThT6x3G") == 0) {
          extern mxArray *sf_c12_Modified_jit_fallback_info(void);
          plhs[0] = sf_c12_Modified_jit_fallback_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "bFcY0vA3yx0dOBkNrnUtZG") == 0) {
          extern mxArray *sf_c13_Modified_jit_fallback_info(void);
          plhs[0] = sf_c13_Modified_jit_fallback_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "CdMwZd5ZINXTTrKHPqfMxC") == 0) {
          extern mxArray *sf_c15_Modified_jit_fallback_info(void);
          plhs[0] = sf_c15_Modified_jit_fallback_info();
          break;
        }
      }

     case 19:
      {
        if (strcmp(tpChksum, "vfMzKFiWd9gxZLQUJsLr3D") == 0) {
          extern mxArray *sf_c19_Modified_jit_fallback_info(void);
          plhs[0] = sf_c19_Modified_jit_fallback_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "Ry1PGFKv4FlGo9qr0Q1IBD") == 0) {
          extern mxArray *sf_c20_Modified_jit_fallback_info(void);
          plhs[0] = sf_c20_Modified_jit_fallback_info();
          break;
        }
      }

     case 26:
      {
        if (strcmp(tpChksum, "eNOzoSQLev7mB2ZCyUgDCC") == 0) {
          extern mxArray *sf_c26_Modified_jit_fallback_info(void);
          plhs[0] = sf_c26_Modified_jit_fallback_info();
          break;
        }
      }

     case 28:
      {
        if (strcmp(tpChksum, "kn3zcNJAn7zRGpNQD8RKMC") == 0) {
          extern mxArray *sf_c28_Modified_jit_fallback_info(void);
          plhs[0] = sf_c28_Modified_jit_fallback_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_Modified_updateBuildInfo_args_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the updateBuildInfo_args_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_updateBuildInfo_args_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 3:
      {
        if (strcmp(tpChksum, "QtcePKxe4H9FFy5hhEFE6E") == 0) {
          extern mxArray *sf_c3_Modified_updateBuildInfo_args_info(void);
          plhs[0] = sf_c3_Modified_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "pCGJpivanLlOQcKqfmeI7D") == 0) {
          extern mxArray *sf_c4_Modified_updateBuildInfo_args_info(void);
          plhs[0] = sf_c4_Modified_updateBuildInfo_args_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "aVcLF4aeXNV7qLRkFPcTHD") == 0) {
          extern mxArray *sf_c5_Modified_updateBuildInfo_args_info(void);
          plhs[0] = sf_c5_Modified_updateBuildInfo_args_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "8GQqFczwrdbHx0h3x8FJLG") == 0) {
          extern mxArray *sf_c6_Modified_updateBuildInfo_args_info(void);
          plhs[0] = sf_c6_Modified_updateBuildInfo_args_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "dM3QmCydJQ4zatzpUcaKaG") == 0) {
          extern mxArray *sf_c7_Modified_updateBuildInfo_args_info(void);
          plhs[0] = sf_c7_Modified_updateBuildInfo_args_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "12uNfbaObI9kdJUMJypraD") == 0) {
          extern mxArray *sf_c8_Modified_updateBuildInfo_args_info(void);
          plhs[0] = sf_c8_Modified_updateBuildInfo_args_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "8QlPsK8YvvPlEKOLT26g0F") == 0) {
          extern mxArray *sf_c9_Modified_updateBuildInfo_args_info(void);
          plhs[0] = sf_c9_Modified_updateBuildInfo_args_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "lBiAltMC72HqN30bOEc17E") == 0) {
          extern mxArray *sf_c10_Modified_updateBuildInfo_args_info(void);
          plhs[0] = sf_c10_Modified_updateBuildInfo_args_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "nsuilLiT8rixZOJEK30JvD") == 0) {
          extern mxArray *sf_c11_Modified_updateBuildInfo_args_info(void);
          plhs[0] = sf_c11_Modified_updateBuildInfo_args_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "Lffav7JhMYenT53ThT6x3G") == 0) {
          extern mxArray *sf_c12_Modified_updateBuildInfo_args_info(void);
          plhs[0] = sf_c12_Modified_updateBuildInfo_args_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "bFcY0vA3yx0dOBkNrnUtZG") == 0) {
          extern mxArray *sf_c13_Modified_updateBuildInfo_args_info(void);
          plhs[0] = sf_c13_Modified_updateBuildInfo_args_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "CdMwZd5ZINXTTrKHPqfMxC") == 0) {
          extern mxArray *sf_c15_Modified_updateBuildInfo_args_info(void);
          plhs[0] = sf_c15_Modified_updateBuildInfo_args_info();
          break;
        }
      }

     case 19:
      {
        if (strcmp(tpChksum, "vfMzKFiWd9gxZLQUJsLr3D") == 0) {
          extern mxArray *sf_c19_Modified_updateBuildInfo_args_info(void);
          plhs[0] = sf_c19_Modified_updateBuildInfo_args_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "Ry1PGFKv4FlGo9qr0Q1IBD") == 0) {
          extern mxArray *sf_c20_Modified_updateBuildInfo_args_info(void);
          plhs[0] = sf_c20_Modified_updateBuildInfo_args_info();
          break;
        }
      }

     case 26:
      {
        if (strcmp(tpChksum, "eNOzoSQLev7mB2ZCyUgDCC") == 0) {
          extern mxArray *sf_c26_Modified_updateBuildInfo_args_info(void);
          plhs[0] = sf_c26_Modified_updateBuildInfo_args_info();
          break;
        }
      }

     case 28:
      {
        if (strcmp(tpChksum, "kn3zcNJAn7zRGpNQD8RKMC") == 0) {
          extern mxArray *sf_c28_Modified_updateBuildInfo_args_info(void);
          plhs[0] = sf_c28_Modified_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void sf_Modified_get_post_codegen_info( int nlhs, mxArray * plhs[], int nrhs,
  const mxArray * prhs[] )
{
  unsigned int chartFileNumber = (unsigned int) mxGetScalar(prhs[0]);
  char tpChksum[64];
  mxGetString(prhs[1], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  switch (chartFileNumber) {
   case 3:
    {
      if (strcmp(tpChksum, "QtcePKxe4H9FFy5hhEFE6E") == 0) {
        extern mxArray *sf_c3_Modified_get_post_codegen_info(void);
        plhs[0] = sf_c3_Modified_get_post_codegen_info();
        return;
      }
    }
    break;

   case 4:
    {
      if (strcmp(tpChksum, "pCGJpivanLlOQcKqfmeI7D") == 0) {
        extern mxArray *sf_c4_Modified_get_post_codegen_info(void);
        plhs[0] = sf_c4_Modified_get_post_codegen_info();
        return;
      }
    }
    break;

   case 5:
    {
      if (strcmp(tpChksum, "aVcLF4aeXNV7qLRkFPcTHD") == 0) {
        extern mxArray *sf_c5_Modified_get_post_codegen_info(void);
        plhs[0] = sf_c5_Modified_get_post_codegen_info();
        return;
      }
    }
    break;

   case 6:
    {
      if (strcmp(tpChksum, "8GQqFczwrdbHx0h3x8FJLG") == 0) {
        extern mxArray *sf_c6_Modified_get_post_codegen_info(void);
        plhs[0] = sf_c6_Modified_get_post_codegen_info();
        return;
      }
    }
    break;

   case 7:
    {
      if (strcmp(tpChksum, "dM3QmCydJQ4zatzpUcaKaG") == 0) {
        extern mxArray *sf_c7_Modified_get_post_codegen_info(void);
        plhs[0] = sf_c7_Modified_get_post_codegen_info();
        return;
      }
    }
    break;

   case 8:
    {
      if (strcmp(tpChksum, "12uNfbaObI9kdJUMJypraD") == 0) {
        extern mxArray *sf_c8_Modified_get_post_codegen_info(void);
        plhs[0] = sf_c8_Modified_get_post_codegen_info();
        return;
      }
    }
    break;

   case 9:
    {
      if (strcmp(tpChksum, "8QlPsK8YvvPlEKOLT26g0F") == 0) {
        extern mxArray *sf_c9_Modified_get_post_codegen_info(void);
        plhs[0] = sf_c9_Modified_get_post_codegen_info();
        return;
      }
    }
    break;

   case 10:
    {
      if (strcmp(tpChksum, "lBiAltMC72HqN30bOEc17E") == 0) {
        extern mxArray *sf_c10_Modified_get_post_codegen_info(void);
        plhs[0] = sf_c10_Modified_get_post_codegen_info();
        return;
      }
    }
    break;

   case 11:
    {
      if (strcmp(tpChksum, "nsuilLiT8rixZOJEK30JvD") == 0) {
        extern mxArray *sf_c11_Modified_get_post_codegen_info(void);
        plhs[0] = sf_c11_Modified_get_post_codegen_info();
        return;
      }
    }
    break;

   case 12:
    {
      if (strcmp(tpChksum, "Lffav7JhMYenT53ThT6x3G") == 0) {
        extern mxArray *sf_c12_Modified_get_post_codegen_info(void);
        plhs[0] = sf_c12_Modified_get_post_codegen_info();
        return;
      }
    }
    break;

   case 13:
    {
      if (strcmp(tpChksum, "bFcY0vA3yx0dOBkNrnUtZG") == 0) {
        extern mxArray *sf_c13_Modified_get_post_codegen_info(void);
        plhs[0] = sf_c13_Modified_get_post_codegen_info();
        return;
      }
    }
    break;

   case 15:
    {
      if (strcmp(tpChksum, "CdMwZd5ZINXTTrKHPqfMxC") == 0) {
        extern mxArray *sf_c15_Modified_get_post_codegen_info(void);
        plhs[0] = sf_c15_Modified_get_post_codegen_info();
        return;
      }
    }
    break;

   case 19:
    {
      if (strcmp(tpChksum, "vfMzKFiWd9gxZLQUJsLr3D") == 0) {
        extern mxArray *sf_c19_Modified_get_post_codegen_info(void);
        plhs[0] = sf_c19_Modified_get_post_codegen_info();
        return;
      }
    }
    break;

   case 20:
    {
      if (strcmp(tpChksum, "Ry1PGFKv4FlGo9qr0Q1IBD") == 0) {
        extern mxArray *sf_c20_Modified_get_post_codegen_info(void);
        plhs[0] = sf_c20_Modified_get_post_codegen_info();
        return;
      }
    }
    break;

   case 26:
    {
      if (strcmp(tpChksum, "eNOzoSQLev7mB2ZCyUgDCC") == 0) {
        extern mxArray *sf_c26_Modified_get_post_codegen_info(void);
        plhs[0] = sf_c26_Modified_get_post_codegen_info();
        return;
      }
    }
    break;

   case 28:
    {
      if (strcmp(tpChksum, "kn3zcNJAn7zRGpNQD8RKMC") == 0) {
        extern mxArray *sf_c28_Modified_get_post_codegen_info(void);
        plhs[0] = sf_c28_Modified_get_post_codegen_info();
        return;
      }
    }
    break;

   default:
    break;
  }

  plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
}

void Modified_debug_initialize(struct SfDebugInstanceStruct* debugInstance)
{
  _ModifiedMachineNumber_ = sf_debug_initialize_machine(debugInstance,"Modified",
    "sfun",0,16,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,_ModifiedMachineNumber_,0,
    0);
  sf_debug_set_machine_data_thresholds(debugInstance,_ModifiedMachineNumber_,0);
}

void Modified_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_Modified_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("Modified",
      "Modified");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_Modified_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
