/* Include files */

#include "AllPurposeModel_TyreRelaxation_sfun.h"
#include "AllPurposeModel_TyreRelaxation_sfun_debug_macros.h"
#include "c1_AllPurposeModel_TyreRelaxation.h"
#include "c2_AllPurposeModel_TyreRelaxation.h"
#include "c3_AllPurposeModel_TyreRelaxation.h"
#include "c4_AllPurposeModel_TyreRelaxation.h"
#include "c5_AllPurposeModel_TyreRelaxation.h"
#include "c6_AllPurposeModel_TyreRelaxation.h"
#include "c7_AllPurposeModel_TyreRelaxation.h"
#include "c8_AllPurposeModel_TyreRelaxation.h"
#include "c9_AllPurposeModel_TyreRelaxation.h"
#include "c10_AllPurposeModel_TyreRelaxation.h"
#include "c11_AllPurposeModel_TyreRelaxation.h"
#include "c12_AllPurposeModel_TyreRelaxation.h"
#include "c13_AllPurposeModel_TyreRelaxation.h"
#include "c15_AllPurposeModel_TyreRelaxation.h"
#include "c19_AllPurposeModel_TyreRelaxation.h"
#include "c20_AllPurposeModel_TyreRelaxation.h"
#include "c26_AllPurposeModel_TyreRelaxation.h"
#include "c27_AllPurposeModel_TyreRelaxation.h"
#include "c28_AllPurposeModel_TyreRelaxation.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _AllPurposeModel_TyreRelaxationMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void AllPurposeModel_TyreRelaxation_initializer(void)
{
}

void AllPurposeModel_TyreRelaxation_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_AllPurposeModel_TyreRelaxation_method_dispatcher(SimStruct
  *simstructPtr, unsigned int chartFileNumber, const char* specsCksum, int_T
  method, void *data)
{
  if (chartFileNumber==1) {
    c1_AllPurposeModel_TyreRelaxation_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_AllPurposeModel_TyreRelaxation_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_AllPurposeModel_TyreRelaxation_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_AllPurposeModel_TyreRelaxation_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_AllPurposeModel_TyreRelaxation_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_AllPurposeModel_TyreRelaxation_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_AllPurposeModel_TyreRelaxation_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_AllPurposeModel_TyreRelaxation_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_AllPurposeModel_TyreRelaxation_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_AllPurposeModel_TyreRelaxation_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_AllPurposeModel_TyreRelaxation_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==12) {
    c12_AllPurposeModel_TyreRelaxation_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==13) {
    c13_AllPurposeModel_TyreRelaxation_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==15) {
    c15_AllPurposeModel_TyreRelaxation_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==19) {
    c19_AllPurposeModel_TyreRelaxation_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==20) {
    c20_AllPurposeModel_TyreRelaxation_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==26) {
    c26_AllPurposeModel_TyreRelaxation_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==27) {
    c27_AllPurposeModel_TyreRelaxation_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==28) {
    c28_AllPurposeModel_TyreRelaxation_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  return 0;
}

extern void sf_AllPurposeModel_TyreRelaxation_uses_exported_functions(int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[])
{
  plhs[0] = mxCreateLogicalScalar(0);
}

unsigned int sf_AllPurposeModel_TyreRelaxation_process_check_sum_call( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3020022189U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2346538426U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(107979818U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(669203463U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2153834600U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2839484659U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2058843585U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3943045028U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_AllPurposeModel_TyreRelaxation_get_check_sum(mxArray
            *plhs[]);
          sf_c1_AllPurposeModel_TyreRelaxation_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_AllPurposeModel_TyreRelaxation_get_check_sum(mxArray
            *plhs[]);
          sf_c2_AllPurposeModel_TyreRelaxation_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_AllPurposeModel_TyreRelaxation_get_check_sum(mxArray
            *plhs[]);
          sf_c3_AllPurposeModel_TyreRelaxation_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_AllPurposeModel_TyreRelaxation_get_check_sum(mxArray
            *plhs[]);
          sf_c4_AllPurposeModel_TyreRelaxation_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_AllPurposeModel_TyreRelaxation_get_check_sum(mxArray
            *plhs[]);
          sf_c5_AllPurposeModel_TyreRelaxation_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_AllPurposeModel_TyreRelaxation_get_check_sum(mxArray
            *plhs[]);
          sf_c6_AllPurposeModel_TyreRelaxation_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_AllPurposeModel_TyreRelaxation_get_check_sum(mxArray
            *plhs[]);
          sf_c7_AllPurposeModel_TyreRelaxation_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_AllPurposeModel_TyreRelaxation_get_check_sum(mxArray
            *plhs[]);
          sf_c8_AllPurposeModel_TyreRelaxation_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_AllPurposeModel_TyreRelaxation_get_check_sum(mxArray
            *plhs[]);
          sf_c9_AllPurposeModel_TyreRelaxation_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_AllPurposeModel_TyreRelaxation_get_check_sum
            (mxArray *plhs[]);
          sf_c10_AllPurposeModel_TyreRelaxation_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_AllPurposeModel_TyreRelaxation_get_check_sum
            (mxArray *plhs[]);
          sf_c11_AllPurposeModel_TyreRelaxation_get_check_sum(plhs);
          break;
        }

       case 12:
        {
          extern void sf_c12_AllPurposeModel_TyreRelaxation_get_check_sum
            (mxArray *plhs[]);
          sf_c12_AllPurposeModel_TyreRelaxation_get_check_sum(plhs);
          break;
        }

       case 13:
        {
          extern void sf_c13_AllPurposeModel_TyreRelaxation_get_check_sum
            (mxArray *plhs[]);
          sf_c13_AllPurposeModel_TyreRelaxation_get_check_sum(plhs);
          break;
        }

       case 15:
        {
          extern void sf_c15_AllPurposeModel_TyreRelaxation_get_check_sum
            (mxArray *plhs[]);
          sf_c15_AllPurposeModel_TyreRelaxation_get_check_sum(plhs);
          break;
        }

       case 19:
        {
          extern void sf_c19_AllPurposeModel_TyreRelaxation_get_check_sum
            (mxArray *plhs[]);
          sf_c19_AllPurposeModel_TyreRelaxation_get_check_sum(plhs);
          break;
        }

       case 20:
        {
          extern void sf_c20_AllPurposeModel_TyreRelaxation_get_check_sum
            (mxArray *plhs[]);
          sf_c20_AllPurposeModel_TyreRelaxation_get_check_sum(plhs);
          break;
        }

       case 26:
        {
          extern void sf_c26_AllPurposeModel_TyreRelaxation_get_check_sum
            (mxArray *plhs[]);
          sf_c26_AllPurposeModel_TyreRelaxation_get_check_sum(plhs);
          break;
        }

       case 27:
        {
          extern void sf_c27_AllPurposeModel_TyreRelaxation_get_check_sum
            (mxArray *plhs[]);
          sf_c27_AllPurposeModel_TyreRelaxation_get_check_sum(plhs);
          break;
        }

       case 28:
        {
          extern void sf_c28_AllPurposeModel_TyreRelaxation_get_check_sum
            (mxArray *plhs[]);
          sf_c28_AllPurposeModel_TyreRelaxation_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(610380107U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(359872906U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1689847851U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(736621885U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_AllPurposeModel_TyreRelaxation_autoinheritance_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
     case 1:
      {
        if (strcmp(aiChksum, "Cjbz0aQDhRu5OyQ9YgvbrF") == 0) {
          extern mxArray
            *sf_c1_AllPurposeModel_TyreRelaxation_get_autoinheritance_info(void);
          plhs[0] =
            sf_c1_AllPurposeModel_TyreRelaxation_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "fETxr2yYqHDxjSRVG6kykD") == 0) {
          extern mxArray
            *sf_c2_AllPurposeModel_TyreRelaxation_get_autoinheritance_info(void);
          plhs[0] =
            sf_c2_AllPurposeModel_TyreRelaxation_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "NVAjIFf7Fqte52QAhV4sMF") == 0) {
          extern mxArray
            *sf_c3_AllPurposeModel_TyreRelaxation_get_autoinheritance_info(void);
          plhs[0] =
            sf_c3_AllPurposeModel_TyreRelaxation_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "Sivbt4GWkfQKGRdgCcx9IC") == 0) {
          extern mxArray
            *sf_c4_AllPurposeModel_TyreRelaxation_get_autoinheritance_info(void);
          plhs[0] =
            sf_c4_AllPurposeModel_TyreRelaxation_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "37Gz2xXIHV5Urgd3DQEHjE") == 0) {
          extern mxArray
            *sf_c5_AllPurposeModel_TyreRelaxation_get_autoinheritance_info(void);
          plhs[0] =
            sf_c5_AllPurposeModel_TyreRelaxation_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "w63AfJG06UiMZ4lE09H6MF") == 0) {
          extern mxArray
            *sf_c6_AllPurposeModel_TyreRelaxation_get_autoinheritance_info(void);
          plhs[0] =
            sf_c6_AllPurposeModel_TyreRelaxation_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 7:
      {
        if (strcmp(aiChksum, "g5MYbAbGoEWCG5yf4cStDH") == 0) {
          extern mxArray
            *sf_c7_AllPurposeModel_TyreRelaxation_get_autoinheritance_info(void);
          plhs[0] =
            sf_c7_AllPurposeModel_TyreRelaxation_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "yymzPjWWJIO6bqgeXReD6") == 0) {
          extern mxArray
            *sf_c8_AllPurposeModel_TyreRelaxation_get_autoinheritance_info(void);
          plhs[0] =
            sf_c8_AllPurposeModel_TyreRelaxation_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "Fpakne37Zae9d1ZNmzdUq") == 0) {
          extern mxArray
            *sf_c9_AllPurposeModel_TyreRelaxation_get_autoinheritance_info(void);
          plhs[0] =
            sf_c9_AllPurposeModel_TyreRelaxation_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 10:
      {
        if (strcmp(aiChksum, "ijnia3wGSrr6KZdgYe8NpH") == 0) {
          extern mxArray
            *sf_c10_AllPurposeModel_TyreRelaxation_get_autoinheritance_info(void);
          plhs[0] =
            sf_c10_AllPurposeModel_TyreRelaxation_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 11:
      {
        if (strcmp(aiChksum, "uboajGdeBAgIsRE5Rim3x") == 0) {
          extern mxArray
            *sf_c11_AllPurposeModel_TyreRelaxation_get_autoinheritance_info(void);
          plhs[0] =
            sf_c11_AllPurposeModel_TyreRelaxation_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 12:
      {
        if (strcmp(aiChksum, "iPZOHvxGs5S3V7Su2dlI9F") == 0) {
          extern mxArray
            *sf_c12_AllPurposeModel_TyreRelaxation_get_autoinheritance_info(void);
          plhs[0] =
            sf_c12_AllPurposeModel_TyreRelaxation_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 13:
      {
        if (strcmp(aiChksum, "0YJKEsytAPv5fA8AqKKmNE") == 0) {
          extern mxArray
            *sf_c13_AllPurposeModel_TyreRelaxation_get_autoinheritance_info(void);
          plhs[0] =
            sf_c13_AllPurposeModel_TyreRelaxation_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 15:
      {
        if (strcmp(aiChksum, "t8eR9VyOLo3ZobqVuKnqRB") == 0) {
          extern mxArray
            *sf_c15_AllPurposeModel_TyreRelaxation_get_autoinheritance_info(void);
          plhs[0] =
            sf_c15_AllPurposeModel_TyreRelaxation_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 19:
      {
        if (strcmp(aiChksum, "F1y4LhFIX25OiKktTK2g2B") == 0) {
          extern mxArray
            *sf_c19_AllPurposeModel_TyreRelaxation_get_autoinheritance_info(void);
          plhs[0] =
            sf_c19_AllPurposeModel_TyreRelaxation_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 20:
      {
        if (strcmp(aiChksum, "ymqjqyS9kPDPtiXOCIVYIB") == 0) {
          extern mxArray
            *sf_c20_AllPurposeModel_TyreRelaxation_get_autoinheritance_info(void);
          plhs[0] =
            sf_c20_AllPurposeModel_TyreRelaxation_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 26:
      {
        if (strcmp(aiChksum, "nbC4us9jFfnNchMW1pAJoB") == 0) {
          extern mxArray
            *sf_c26_AllPurposeModel_TyreRelaxation_get_autoinheritance_info(void);
          plhs[0] =
            sf_c26_AllPurposeModel_TyreRelaxation_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 27:
      {
        if (strcmp(aiChksum, "NWADKVtcAPfsxpccQumbjE") == 0) {
          extern mxArray
            *sf_c27_AllPurposeModel_TyreRelaxation_get_autoinheritance_info(void);
          plhs[0] =
            sf_c27_AllPurposeModel_TyreRelaxation_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 28:
      {
        if (strcmp(aiChksum, "Mx3l572opQyCoKx9YqxDKH") == 0) {
          extern mxArray
            *sf_c28_AllPurposeModel_TyreRelaxation_get_autoinheritance_info(void);
          plhs[0] =
            sf_c28_AllPurposeModel_TyreRelaxation_get_autoinheritance_info();
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

unsigned int sf_AllPurposeModel_TyreRelaxation_get_eml_resolved_functions_info
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
     case 1:
      {
        extern const mxArray
          *sf_c1_AllPurposeModel_TyreRelaxation_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_AllPurposeModel_TyreRelaxation_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_AllPurposeModel_TyreRelaxation_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_AllPurposeModel_TyreRelaxation_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_AllPurposeModel_TyreRelaxation_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_AllPurposeModel_TyreRelaxation_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_AllPurposeModel_TyreRelaxation_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_AllPurposeModel_TyreRelaxation_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_AllPurposeModel_TyreRelaxation_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_AllPurposeModel_TyreRelaxation_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray
          *sf_c6_AllPurposeModel_TyreRelaxation_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_AllPurposeModel_TyreRelaxation_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray
          *sf_c7_AllPurposeModel_TyreRelaxation_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_AllPurposeModel_TyreRelaxation_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray
          *sf_c8_AllPurposeModel_TyreRelaxation_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_AllPurposeModel_TyreRelaxation_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray
          *sf_c9_AllPurposeModel_TyreRelaxation_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_AllPurposeModel_TyreRelaxation_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray
          *sf_c10_AllPurposeModel_TyreRelaxation_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_AllPurposeModel_TyreRelaxation_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray
          *sf_c11_AllPurposeModel_TyreRelaxation_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_AllPurposeModel_TyreRelaxation_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 12:
      {
        extern const mxArray
          *sf_c12_AllPurposeModel_TyreRelaxation_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c12_AllPurposeModel_TyreRelaxation_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 13:
      {
        extern const mxArray
          *sf_c13_AllPurposeModel_TyreRelaxation_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c13_AllPurposeModel_TyreRelaxation_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 15:
      {
        extern const mxArray
          *sf_c15_AllPurposeModel_TyreRelaxation_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c15_AllPurposeModel_TyreRelaxation_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 19:
      {
        extern const mxArray
          *sf_c19_AllPurposeModel_TyreRelaxation_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c19_AllPurposeModel_TyreRelaxation_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 20:
      {
        extern const mxArray
          *sf_c20_AllPurposeModel_TyreRelaxation_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c20_AllPurposeModel_TyreRelaxation_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 26:
      {
        extern const mxArray
          *sf_c26_AllPurposeModel_TyreRelaxation_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c26_AllPurposeModel_TyreRelaxation_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 27:
      {
        extern const mxArray
          *sf_c27_AllPurposeModel_TyreRelaxation_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c27_AllPurposeModel_TyreRelaxation_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 28:
      {
        extern const mxArray
          *sf_c28_AllPurposeModel_TyreRelaxation_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c28_AllPurposeModel_TyreRelaxation_get_eml_resolved_functions_info();
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

unsigned int sf_AllPurposeModel_TyreRelaxation_third_party_uses_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
     case 1:
      {
        if (strcmp(tpChksum, "gMzL3OL8lzHdHgJAHhXtKG") == 0) {
          extern mxArray
            *sf_c1_AllPurposeModel_TyreRelaxation_third_party_uses_info(void);
          plhs[0] = sf_c1_AllPurposeModel_TyreRelaxation_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "ppfRxc5CHzQz5QA9hiYqDF") == 0) {
          extern mxArray
            *sf_c2_AllPurposeModel_TyreRelaxation_third_party_uses_info(void);
          plhs[0] = sf_c2_AllPurposeModel_TyreRelaxation_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "QtcePKxe4H9FFy5hhEFE6E") == 0) {
          extern mxArray
            *sf_c3_AllPurposeModel_TyreRelaxation_third_party_uses_info(void);
          plhs[0] = sf_c3_AllPurposeModel_TyreRelaxation_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "pCGJpivanLlOQcKqfmeI7D") == 0) {
          extern mxArray
            *sf_c4_AllPurposeModel_TyreRelaxation_third_party_uses_info(void);
          plhs[0] = sf_c4_AllPurposeModel_TyreRelaxation_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "aVcLF4aeXNV7qLRkFPcTHD") == 0) {
          extern mxArray
            *sf_c5_AllPurposeModel_TyreRelaxation_third_party_uses_info(void);
          plhs[0] = sf_c5_AllPurposeModel_TyreRelaxation_third_party_uses_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "8GQqFczwrdbHx0h3x8FJLG") == 0) {
          extern mxArray
            *sf_c6_AllPurposeModel_TyreRelaxation_third_party_uses_info(void);
          plhs[0] = sf_c6_AllPurposeModel_TyreRelaxation_third_party_uses_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "dM3QmCydJQ4zatzpUcaKaG") == 0) {
          extern mxArray
            *sf_c7_AllPurposeModel_TyreRelaxation_third_party_uses_info(void);
          plhs[0] = sf_c7_AllPurposeModel_TyreRelaxation_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "12uNfbaObI9kdJUMJypraD") == 0) {
          extern mxArray
            *sf_c8_AllPurposeModel_TyreRelaxation_third_party_uses_info(void);
          plhs[0] = sf_c8_AllPurposeModel_TyreRelaxation_third_party_uses_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "8QlPsK8YvvPlEKOLT26g0F") == 0) {
          extern mxArray
            *sf_c9_AllPurposeModel_TyreRelaxation_third_party_uses_info(void);
          plhs[0] = sf_c9_AllPurposeModel_TyreRelaxation_third_party_uses_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "lBiAltMC72HqN30bOEc17E") == 0) {
          extern mxArray
            *sf_c10_AllPurposeModel_TyreRelaxation_third_party_uses_info(void);
          plhs[0] = sf_c10_AllPurposeModel_TyreRelaxation_third_party_uses_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "nsuilLiT8rixZOJEK30JvD") == 0) {
          extern mxArray
            *sf_c11_AllPurposeModel_TyreRelaxation_third_party_uses_info(void);
          plhs[0] = sf_c11_AllPurposeModel_TyreRelaxation_third_party_uses_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "Lffav7JhMYenT53ThT6x3G") == 0) {
          extern mxArray
            *sf_c12_AllPurposeModel_TyreRelaxation_third_party_uses_info(void);
          plhs[0] = sf_c12_AllPurposeModel_TyreRelaxation_third_party_uses_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "bFcY0vA3yx0dOBkNrnUtZG") == 0) {
          extern mxArray
            *sf_c13_AllPurposeModel_TyreRelaxation_third_party_uses_info(void);
          plhs[0] = sf_c13_AllPurposeModel_TyreRelaxation_third_party_uses_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "CdMwZd5ZINXTTrKHPqfMxC") == 0) {
          extern mxArray
            *sf_c15_AllPurposeModel_TyreRelaxation_third_party_uses_info(void);
          plhs[0] = sf_c15_AllPurposeModel_TyreRelaxation_third_party_uses_info();
          break;
        }
      }

     case 19:
      {
        if (strcmp(tpChksum, "vfMzKFiWd9gxZLQUJsLr3D") == 0) {
          extern mxArray
            *sf_c19_AllPurposeModel_TyreRelaxation_third_party_uses_info(void);
          plhs[0] = sf_c19_AllPurposeModel_TyreRelaxation_third_party_uses_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "Ry1PGFKv4FlGo9qr0Q1IBD") == 0) {
          extern mxArray
            *sf_c20_AllPurposeModel_TyreRelaxation_third_party_uses_info(void);
          plhs[0] = sf_c20_AllPurposeModel_TyreRelaxation_third_party_uses_info();
          break;
        }
      }

     case 26:
      {
        if (strcmp(tpChksum, "eNOzoSQLev7mB2ZCyUgDCC") == 0) {
          extern mxArray
            *sf_c26_AllPurposeModel_TyreRelaxation_third_party_uses_info(void);
          plhs[0] = sf_c26_AllPurposeModel_TyreRelaxation_third_party_uses_info();
          break;
        }
      }

     case 27:
      {
        if (strcmp(tpChksum, "sndBZnYwSYttFOwqSENboE") == 0) {
          extern mxArray
            *sf_c27_AllPurposeModel_TyreRelaxation_third_party_uses_info(void);
          plhs[0] = sf_c27_AllPurposeModel_TyreRelaxation_third_party_uses_info();
          break;
        }
      }

     case 28:
      {
        if (strcmp(tpChksum, "kn3zcNJAn7zRGpNQD8RKMC") == 0) {
          extern mxArray
            *sf_c28_AllPurposeModel_TyreRelaxation_third_party_uses_info(void);
          plhs[0] = sf_c28_AllPurposeModel_TyreRelaxation_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_AllPurposeModel_TyreRelaxation_jit_fallback_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
     case 1:
      {
        if (strcmp(tpChksum, "gMzL3OL8lzHdHgJAHhXtKG") == 0) {
          extern mxArray *sf_c1_AllPurposeModel_TyreRelaxation_jit_fallback_info
            (void);
          plhs[0] = sf_c1_AllPurposeModel_TyreRelaxation_jit_fallback_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "ppfRxc5CHzQz5QA9hiYqDF") == 0) {
          extern mxArray *sf_c2_AllPurposeModel_TyreRelaxation_jit_fallback_info
            (void);
          plhs[0] = sf_c2_AllPurposeModel_TyreRelaxation_jit_fallback_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "QtcePKxe4H9FFy5hhEFE6E") == 0) {
          extern mxArray *sf_c3_AllPurposeModel_TyreRelaxation_jit_fallback_info
            (void);
          plhs[0] = sf_c3_AllPurposeModel_TyreRelaxation_jit_fallback_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "pCGJpivanLlOQcKqfmeI7D") == 0) {
          extern mxArray *sf_c4_AllPurposeModel_TyreRelaxation_jit_fallback_info
            (void);
          plhs[0] = sf_c4_AllPurposeModel_TyreRelaxation_jit_fallback_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "aVcLF4aeXNV7qLRkFPcTHD") == 0) {
          extern mxArray *sf_c5_AllPurposeModel_TyreRelaxation_jit_fallback_info
            (void);
          plhs[0] = sf_c5_AllPurposeModel_TyreRelaxation_jit_fallback_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "8GQqFczwrdbHx0h3x8FJLG") == 0) {
          extern mxArray *sf_c6_AllPurposeModel_TyreRelaxation_jit_fallback_info
            (void);
          plhs[0] = sf_c6_AllPurposeModel_TyreRelaxation_jit_fallback_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "dM3QmCydJQ4zatzpUcaKaG") == 0) {
          extern mxArray *sf_c7_AllPurposeModel_TyreRelaxation_jit_fallback_info
            (void);
          plhs[0] = sf_c7_AllPurposeModel_TyreRelaxation_jit_fallback_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "12uNfbaObI9kdJUMJypraD") == 0) {
          extern mxArray *sf_c8_AllPurposeModel_TyreRelaxation_jit_fallback_info
            (void);
          plhs[0] = sf_c8_AllPurposeModel_TyreRelaxation_jit_fallback_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "8QlPsK8YvvPlEKOLT26g0F") == 0) {
          extern mxArray *sf_c9_AllPurposeModel_TyreRelaxation_jit_fallback_info
            (void);
          plhs[0] = sf_c9_AllPurposeModel_TyreRelaxation_jit_fallback_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "lBiAltMC72HqN30bOEc17E") == 0) {
          extern mxArray
            *sf_c10_AllPurposeModel_TyreRelaxation_jit_fallback_info(void);
          plhs[0] = sf_c10_AllPurposeModel_TyreRelaxation_jit_fallback_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "nsuilLiT8rixZOJEK30JvD") == 0) {
          extern mxArray
            *sf_c11_AllPurposeModel_TyreRelaxation_jit_fallback_info(void);
          plhs[0] = sf_c11_AllPurposeModel_TyreRelaxation_jit_fallback_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "Lffav7JhMYenT53ThT6x3G") == 0) {
          extern mxArray
            *sf_c12_AllPurposeModel_TyreRelaxation_jit_fallback_info(void);
          plhs[0] = sf_c12_AllPurposeModel_TyreRelaxation_jit_fallback_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "bFcY0vA3yx0dOBkNrnUtZG") == 0) {
          extern mxArray
            *sf_c13_AllPurposeModel_TyreRelaxation_jit_fallback_info(void);
          plhs[0] = sf_c13_AllPurposeModel_TyreRelaxation_jit_fallback_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "CdMwZd5ZINXTTrKHPqfMxC") == 0) {
          extern mxArray
            *sf_c15_AllPurposeModel_TyreRelaxation_jit_fallback_info(void);
          plhs[0] = sf_c15_AllPurposeModel_TyreRelaxation_jit_fallback_info();
          break;
        }
      }

     case 19:
      {
        if (strcmp(tpChksum, "vfMzKFiWd9gxZLQUJsLr3D") == 0) {
          extern mxArray
            *sf_c19_AllPurposeModel_TyreRelaxation_jit_fallback_info(void);
          plhs[0] = sf_c19_AllPurposeModel_TyreRelaxation_jit_fallback_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "Ry1PGFKv4FlGo9qr0Q1IBD") == 0) {
          extern mxArray
            *sf_c20_AllPurposeModel_TyreRelaxation_jit_fallback_info(void);
          plhs[0] = sf_c20_AllPurposeModel_TyreRelaxation_jit_fallback_info();
          break;
        }
      }

     case 26:
      {
        if (strcmp(tpChksum, "eNOzoSQLev7mB2ZCyUgDCC") == 0) {
          extern mxArray
            *sf_c26_AllPurposeModel_TyreRelaxation_jit_fallback_info(void);
          plhs[0] = sf_c26_AllPurposeModel_TyreRelaxation_jit_fallback_info();
          break;
        }
      }

     case 27:
      {
        if (strcmp(tpChksum, "sndBZnYwSYttFOwqSENboE") == 0) {
          extern mxArray
            *sf_c27_AllPurposeModel_TyreRelaxation_jit_fallback_info(void);
          plhs[0] = sf_c27_AllPurposeModel_TyreRelaxation_jit_fallback_info();
          break;
        }
      }

     case 28:
      {
        if (strcmp(tpChksum, "kn3zcNJAn7zRGpNQD8RKMC") == 0) {
          extern mxArray
            *sf_c28_AllPurposeModel_TyreRelaxation_jit_fallback_info(void);
          plhs[0] = sf_c28_AllPurposeModel_TyreRelaxation_jit_fallback_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_AllPurposeModel_TyreRelaxation_updateBuildInfo_args_info( int
  nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
     case 1:
      {
        if (strcmp(tpChksum, "gMzL3OL8lzHdHgJAHhXtKG") == 0) {
          extern mxArray
            *sf_c1_AllPurposeModel_TyreRelaxation_updateBuildInfo_args_info(void);
          plhs[0] =
            sf_c1_AllPurposeModel_TyreRelaxation_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "ppfRxc5CHzQz5QA9hiYqDF") == 0) {
          extern mxArray
            *sf_c2_AllPurposeModel_TyreRelaxation_updateBuildInfo_args_info(void);
          plhs[0] =
            sf_c2_AllPurposeModel_TyreRelaxation_updateBuildInfo_args_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "QtcePKxe4H9FFy5hhEFE6E") == 0) {
          extern mxArray
            *sf_c3_AllPurposeModel_TyreRelaxation_updateBuildInfo_args_info(void);
          plhs[0] =
            sf_c3_AllPurposeModel_TyreRelaxation_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "pCGJpivanLlOQcKqfmeI7D") == 0) {
          extern mxArray
            *sf_c4_AllPurposeModel_TyreRelaxation_updateBuildInfo_args_info(void);
          plhs[0] =
            sf_c4_AllPurposeModel_TyreRelaxation_updateBuildInfo_args_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "aVcLF4aeXNV7qLRkFPcTHD") == 0) {
          extern mxArray
            *sf_c5_AllPurposeModel_TyreRelaxation_updateBuildInfo_args_info(void);
          plhs[0] =
            sf_c5_AllPurposeModel_TyreRelaxation_updateBuildInfo_args_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "8GQqFczwrdbHx0h3x8FJLG") == 0) {
          extern mxArray
            *sf_c6_AllPurposeModel_TyreRelaxation_updateBuildInfo_args_info(void);
          plhs[0] =
            sf_c6_AllPurposeModel_TyreRelaxation_updateBuildInfo_args_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "dM3QmCydJQ4zatzpUcaKaG") == 0) {
          extern mxArray
            *sf_c7_AllPurposeModel_TyreRelaxation_updateBuildInfo_args_info(void);
          plhs[0] =
            sf_c7_AllPurposeModel_TyreRelaxation_updateBuildInfo_args_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "12uNfbaObI9kdJUMJypraD") == 0) {
          extern mxArray
            *sf_c8_AllPurposeModel_TyreRelaxation_updateBuildInfo_args_info(void);
          plhs[0] =
            sf_c8_AllPurposeModel_TyreRelaxation_updateBuildInfo_args_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "8QlPsK8YvvPlEKOLT26g0F") == 0) {
          extern mxArray
            *sf_c9_AllPurposeModel_TyreRelaxation_updateBuildInfo_args_info(void);
          plhs[0] =
            sf_c9_AllPurposeModel_TyreRelaxation_updateBuildInfo_args_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "lBiAltMC72HqN30bOEc17E") == 0) {
          extern mxArray
            *sf_c10_AllPurposeModel_TyreRelaxation_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c10_AllPurposeModel_TyreRelaxation_updateBuildInfo_args_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "nsuilLiT8rixZOJEK30JvD") == 0) {
          extern mxArray
            *sf_c11_AllPurposeModel_TyreRelaxation_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c11_AllPurposeModel_TyreRelaxation_updateBuildInfo_args_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "Lffav7JhMYenT53ThT6x3G") == 0) {
          extern mxArray
            *sf_c12_AllPurposeModel_TyreRelaxation_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c12_AllPurposeModel_TyreRelaxation_updateBuildInfo_args_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "bFcY0vA3yx0dOBkNrnUtZG") == 0) {
          extern mxArray
            *sf_c13_AllPurposeModel_TyreRelaxation_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c13_AllPurposeModel_TyreRelaxation_updateBuildInfo_args_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "CdMwZd5ZINXTTrKHPqfMxC") == 0) {
          extern mxArray
            *sf_c15_AllPurposeModel_TyreRelaxation_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c15_AllPurposeModel_TyreRelaxation_updateBuildInfo_args_info();
          break;
        }
      }

     case 19:
      {
        if (strcmp(tpChksum, "vfMzKFiWd9gxZLQUJsLr3D") == 0) {
          extern mxArray
            *sf_c19_AllPurposeModel_TyreRelaxation_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c19_AllPurposeModel_TyreRelaxation_updateBuildInfo_args_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "Ry1PGFKv4FlGo9qr0Q1IBD") == 0) {
          extern mxArray
            *sf_c20_AllPurposeModel_TyreRelaxation_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c20_AllPurposeModel_TyreRelaxation_updateBuildInfo_args_info();
          break;
        }
      }

     case 26:
      {
        if (strcmp(tpChksum, "eNOzoSQLev7mB2ZCyUgDCC") == 0) {
          extern mxArray
            *sf_c26_AllPurposeModel_TyreRelaxation_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c26_AllPurposeModel_TyreRelaxation_updateBuildInfo_args_info();
          break;
        }
      }

     case 27:
      {
        if (strcmp(tpChksum, "sndBZnYwSYttFOwqSENboE") == 0) {
          extern mxArray
            *sf_c27_AllPurposeModel_TyreRelaxation_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c27_AllPurposeModel_TyreRelaxation_updateBuildInfo_args_info();
          break;
        }
      }

     case 28:
      {
        if (strcmp(tpChksum, "kn3zcNJAn7zRGpNQD8RKMC") == 0) {
          extern mxArray
            *sf_c28_AllPurposeModel_TyreRelaxation_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c28_AllPurposeModel_TyreRelaxation_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void sf_AllPurposeModel_TyreRelaxation_get_post_codegen_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{
  unsigned int chartFileNumber = (unsigned int) mxGetScalar(prhs[0]);
  char tpChksum[64];
  mxGetString(prhs[1], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  switch (chartFileNumber) {
   case 1:
    {
      if (strcmp(tpChksum, "gMzL3OL8lzHdHgJAHhXtKG") == 0) {
        extern mxArray
          *sf_c1_AllPurposeModel_TyreRelaxation_get_post_codegen_info(void);
        plhs[0] = sf_c1_AllPurposeModel_TyreRelaxation_get_post_codegen_info();
        return;
      }
    }
    break;

   case 2:
    {
      if (strcmp(tpChksum, "ppfRxc5CHzQz5QA9hiYqDF") == 0) {
        extern mxArray
          *sf_c2_AllPurposeModel_TyreRelaxation_get_post_codegen_info(void);
        plhs[0] = sf_c2_AllPurposeModel_TyreRelaxation_get_post_codegen_info();
        return;
      }
    }
    break;

   case 3:
    {
      if (strcmp(tpChksum, "QtcePKxe4H9FFy5hhEFE6E") == 0) {
        extern mxArray
          *sf_c3_AllPurposeModel_TyreRelaxation_get_post_codegen_info(void);
        plhs[0] = sf_c3_AllPurposeModel_TyreRelaxation_get_post_codegen_info();
        return;
      }
    }
    break;

   case 4:
    {
      if (strcmp(tpChksum, "pCGJpivanLlOQcKqfmeI7D") == 0) {
        extern mxArray
          *sf_c4_AllPurposeModel_TyreRelaxation_get_post_codegen_info(void);
        plhs[0] = sf_c4_AllPurposeModel_TyreRelaxation_get_post_codegen_info();
        return;
      }
    }
    break;

   case 5:
    {
      if (strcmp(tpChksum, "aVcLF4aeXNV7qLRkFPcTHD") == 0) {
        extern mxArray
          *sf_c5_AllPurposeModel_TyreRelaxation_get_post_codegen_info(void);
        plhs[0] = sf_c5_AllPurposeModel_TyreRelaxation_get_post_codegen_info();
        return;
      }
    }
    break;

   case 6:
    {
      if (strcmp(tpChksum, "8GQqFczwrdbHx0h3x8FJLG") == 0) {
        extern mxArray
          *sf_c6_AllPurposeModel_TyreRelaxation_get_post_codegen_info(void);
        plhs[0] = sf_c6_AllPurposeModel_TyreRelaxation_get_post_codegen_info();
        return;
      }
    }
    break;

   case 7:
    {
      if (strcmp(tpChksum, "dM3QmCydJQ4zatzpUcaKaG") == 0) {
        extern mxArray
          *sf_c7_AllPurposeModel_TyreRelaxation_get_post_codegen_info(void);
        plhs[0] = sf_c7_AllPurposeModel_TyreRelaxation_get_post_codegen_info();
        return;
      }
    }
    break;

   case 8:
    {
      if (strcmp(tpChksum, "12uNfbaObI9kdJUMJypraD") == 0) {
        extern mxArray
          *sf_c8_AllPurposeModel_TyreRelaxation_get_post_codegen_info(void);
        plhs[0] = sf_c8_AllPurposeModel_TyreRelaxation_get_post_codegen_info();
        return;
      }
    }
    break;

   case 9:
    {
      if (strcmp(tpChksum, "8QlPsK8YvvPlEKOLT26g0F") == 0) {
        extern mxArray
          *sf_c9_AllPurposeModel_TyreRelaxation_get_post_codegen_info(void);
        plhs[0] = sf_c9_AllPurposeModel_TyreRelaxation_get_post_codegen_info();
        return;
      }
    }
    break;

   case 10:
    {
      if (strcmp(tpChksum, "lBiAltMC72HqN30bOEc17E") == 0) {
        extern mxArray
          *sf_c10_AllPurposeModel_TyreRelaxation_get_post_codegen_info(void);
        plhs[0] = sf_c10_AllPurposeModel_TyreRelaxation_get_post_codegen_info();
        return;
      }
    }
    break;

   case 11:
    {
      if (strcmp(tpChksum, "nsuilLiT8rixZOJEK30JvD") == 0) {
        extern mxArray
          *sf_c11_AllPurposeModel_TyreRelaxation_get_post_codegen_info(void);
        plhs[0] = sf_c11_AllPurposeModel_TyreRelaxation_get_post_codegen_info();
        return;
      }
    }
    break;

   case 12:
    {
      if (strcmp(tpChksum, "Lffav7JhMYenT53ThT6x3G") == 0) {
        extern mxArray
          *sf_c12_AllPurposeModel_TyreRelaxation_get_post_codegen_info(void);
        plhs[0] = sf_c12_AllPurposeModel_TyreRelaxation_get_post_codegen_info();
        return;
      }
    }
    break;

   case 13:
    {
      if (strcmp(tpChksum, "bFcY0vA3yx0dOBkNrnUtZG") == 0) {
        extern mxArray
          *sf_c13_AllPurposeModel_TyreRelaxation_get_post_codegen_info(void);
        plhs[0] = sf_c13_AllPurposeModel_TyreRelaxation_get_post_codegen_info();
        return;
      }
    }
    break;

   case 15:
    {
      if (strcmp(tpChksum, "CdMwZd5ZINXTTrKHPqfMxC") == 0) {
        extern mxArray
          *sf_c15_AllPurposeModel_TyreRelaxation_get_post_codegen_info(void);
        plhs[0] = sf_c15_AllPurposeModel_TyreRelaxation_get_post_codegen_info();
        return;
      }
    }
    break;

   case 19:
    {
      if (strcmp(tpChksum, "vfMzKFiWd9gxZLQUJsLr3D") == 0) {
        extern mxArray
          *sf_c19_AllPurposeModel_TyreRelaxation_get_post_codegen_info(void);
        plhs[0] = sf_c19_AllPurposeModel_TyreRelaxation_get_post_codegen_info();
        return;
      }
    }
    break;

   case 20:
    {
      if (strcmp(tpChksum, "Ry1PGFKv4FlGo9qr0Q1IBD") == 0) {
        extern mxArray
          *sf_c20_AllPurposeModel_TyreRelaxation_get_post_codegen_info(void);
        plhs[0] = sf_c20_AllPurposeModel_TyreRelaxation_get_post_codegen_info();
        return;
      }
    }
    break;

   case 26:
    {
      if (strcmp(tpChksum, "eNOzoSQLev7mB2ZCyUgDCC") == 0) {
        extern mxArray
          *sf_c26_AllPurposeModel_TyreRelaxation_get_post_codegen_info(void);
        plhs[0] = sf_c26_AllPurposeModel_TyreRelaxation_get_post_codegen_info();
        return;
      }
    }
    break;

   case 27:
    {
      if (strcmp(tpChksum, "sndBZnYwSYttFOwqSENboE") == 0) {
        extern mxArray
          *sf_c27_AllPurposeModel_TyreRelaxation_get_post_codegen_info(void);
        plhs[0] = sf_c27_AllPurposeModel_TyreRelaxation_get_post_codegen_info();
        return;
      }
    }
    break;

   case 28:
    {
      if (strcmp(tpChksum, "kn3zcNJAn7zRGpNQD8RKMC") == 0) {
        extern mxArray
          *sf_c28_AllPurposeModel_TyreRelaxation_get_post_codegen_info(void);
        plhs[0] = sf_c28_AllPurposeModel_TyreRelaxation_get_post_codegen_info();
        return;
      }
    }
    break;

   default:
    break;
  }

  plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
}

void AllPurposeModel_TyreRelaxation_debug_initialize(struct
  SfDebugInstanceStruct* debugInstance)
{
  _AllPurposeModel_TyreRelaxationMachineNumber_ = sf_debug_initialize_machine
    (debugInstance,"AllPurposeModel_TyreRelaxation","sfun",0,19,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _AllPurposeModel_TyreRelaxationMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _AllPurposeModel_TyreRelaxationMachineNumber_,0);
}

void AllPurposeModel_TyreRelaxation_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_AllPurposeModel_TyreRelaxation_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "AllPurposeModel_TyreRelaxation", "AllPurposeModel_TyreRelaxation");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_AllPurposeModel_TyreRelaxation_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
