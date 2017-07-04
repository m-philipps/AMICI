
#include <include/symbolic_functions.h>
#include <string.h>
#include <include/udata.h>
#include <include/tdata.h>
#include <include/rdata.h>
#include <include/edata.h>
#include "model_jakstat_adjoint_o2_w.h"

int Jy_model_jakstat_adjoint_o2(realtype t, int it, N_Vector x, void *user_data, TempData *tdata, const ExpData *edata, ReturnData *rdata) {
int status = 0;
UserData *udata = (UserData*) user_data;
realtype *x_tmp = N_VGetArrayPointer(x);
status = w_model_jakstat_adjoint_o2(t,x,NULL,user_data);
int iy;
if(!amiIsNaN(edata->my[0* udata->nt+it])){
    iy = 0;
  tdata->Jy[0] += amilog((tdata->sigmay[0]*tdata->sigmay[0])*3.141592653589793*2.0)*5.0E-1+1.0/(tdata->sigmay[0]*tdata->sigmay[0])*pow(edata->my[it+udata->nt*0]-rdata->y[it + udata->nt*0],2.0)*5.0E-1;
  tdata->Jy[1] += rdata->y[it + udata->nt*5];
  tdata->Jy[2] += rdata->y[it + udata->nt*5];
  tdata->Jy[3] += rdata->y[it + udata->nt*5];
  tdata->Jy[4] += rdata->y[it + udata->nt*5];
  tdata->Jy[5] += rdata->y[it + udata->nt*5];
  tdata->Jy[6] += rdata->y[it + udata->nt*5];
  tdata->Jy[7] += rdata->y[it + udata->nt*5];
  tdata->Jy[8] += rdata->y[it + udata->nt*5];
  tdata->Jy[9] += rdata->y[it + udata->nt*5];
  tdata->Jy[10] += rdata->y[it + udata->nt*5];
  tdata->Jy[11] += rdata->y[it + udata->nt*5];
  tdata->Jy[12] += rdata->y[it + udata->nt*5];
  tdata->Jy[13] += rdata->y[it + udata->nt*5];
  tdata->Jy[14] += rdata->y[it + udata->nt*5];
  tdata->Jy[15] += rdata->y[it + udata->nt*5];
  tdata->Jy[16] += rdata->y[it + udata->nt*5];
  tdata->Jy[17] += rdata->y[it + udata->nt*5];
}
if(!amiIsNaN(edata->my[1* udata->nt+it])){
    iy = 1;
  tdata->Jy[0] += amilog((tdata->sigmay[1]*tdata->sigmay[1])*3.141592653589793*2.0)*5.0E-1+1.0/(tdata->sigmay[1]*tdata->sigmay[1])*pow(edata->my[it+udata->nt*1]-rdata->y[it + udata->nt*1],2.0)*5.0E-1;
  tdata->Jy[1] += rdata->y[it + udata->nt*5];
  tdata->Jy[2] += rdata->y[it + udata->nt*5];
  tdata->Jy[3] += rdata->y[it + udata->nt*5];
  tdata->Jy[4] += rdata->y[it + udata->nt*5];
  tdata->Jy[5] += rdata->y[it + udata->nt*5];
  tdata->Jy[6] += rdata->y[it + udata->nt*5];
  tdata->Jy[7] += rdata->y[it + udata->nt*5];
  tdata->Jy[8] += rdata->y[it + udata->nt*5];
  tdata->Jy[9] += rdata->y[it + udata->nt*5];
  tdata->Jy[10] += rdata->y[it + udata->nt*5];
  tdata->Jy[11] += rdata->y[it + udata->nt*5];
  tdata->Jy[12] += rdata->y[it + udata->nt*5];
  tdata->Jy[13] += rdata->y[it + udata->nt*5];
  tdata->Jy[14] += rdata->y[it + udata->nt*5];
  tdata->Jy[15] += rdata->y[it + udata->nt*5];
  tdata->Jy[16] += rdata->y[it + udata->nt*5];
  tdata->Jy[17] += rdata->y[it + udata->nt*5];
}
if(!amiIsNaN(edata->my[2* udata->nt+it])){
    iy = 2;
  tdata->Jy[0] += amilog((tdata->sigmay[2]*tdata->sigmay[2])*3.141592653589793*2.0)*5.0E-1+1.0/(tdata->sigmay[2]*tdata->sigmay[2])*pow(edata->my[it+udata->nt*2]-rdata->y[it + udata->nt*2],2.0)*5.0E-1;
  tdata->Jy[1] += rdata->y[it + udata->nt*5];
  tdata->Jy[2] += rdata->y[it + udata->nt*5];
  tdata->Jy[3] += rdata->y[it + udata->nt*5];
  tdata->Jy[4] += rdata->y[it + udata->nt*5];
  tdata->Jy[5] += rdata->y[it + udata->nt*5];
  tdata->Jy[6] += rdata->y[it + udata->nt*5];
  tdata->Jy[7] += rdata->y[it + udata->nt*5];
  tdata->Jy[8] += rdata->y[it + udata->nt*5];
  tdata->Jy[9] += rdata->y[it + udata->nt*5];
  tdata->Jy[10] += rdata->y[it + udata->nt*5];
  tdata->Jy[11] += rdata->y[it + udata->nt*5];
  tdata->Jy[12] += rdata->y[it + udata->nt*5];
  tdata->Jy[13] += rdata->y[it + udata->nt*5];
  tdata->Jy[14] += rdata->y[it + udata->nt*5];
  tdata->Jy[15] += rdata->y[it + udata->nt*5];
  tdata->Jy[16] += rdata->y[it + udata->nt*5];
  tdata->Jy[17] += rdata->y[it + udata->nt*5];
}
return(status);

}


