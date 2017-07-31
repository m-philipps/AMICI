
#include <include/symbolic_functions.h>
#include <string.h>
#include <include/udata.h>
#include "model_neuron_o2_dwdp.h"
#include "model_neuron_o2_w.h"

int qBdot_model_neuron_o2(realtype t, N_Vector x, N_Vector xB, N_Vector qBdot, void *user_data) {
int status = 0;
UserData *udata = (UserData*) user_data;
realtype *x_tmp = N_VGetArrayPointer(x);
realtype *xB_tmp = N_VGetArrayPointer(xB);
realtype *qBdot_tmp = N_VGetArrayPointer(qBdot);
int ip;
memset(qBdot_tmp,0,sizeof(realtype)*udata->nplist*udata->nJ);
status = dwdp_model_neuron_o2(t,x,NULL,user_data);
for(ip = 0; ip<udata->nplist; ip++) {
switch (udata->plist[ip]) {
  case 0: {
  qBdot_tmp[ip + udata->nplist*0] = xB_tmp[1]*(x_tmp[1]-udata->p[1]*x_tmp[0]);
  qBdot_tmp[ip + udata->nplist*1] = xB_tmp[3]*(x_tmp[1]-udata->p[1]*x_tmp[0])+xB_tmp[1]*(x_tmp[3]-udata->p[1]*x_tmp[2]);
  qBdot_tmp[ip + udata->nplist*2] = -xB_tmp[1]*(x_tmp[0]-x_tmp[5]+udata->p[1]*x_tmp[4])+xB_tmp[5]*(x_tmp[1]-udata->p[1]*x_tmp[0]);
  qBdot_tmp[ip + udata->nplist*3] = xB_tmp[7]*(x_tmp[1]-udata->p[1]*x_tmp[0])+xB_tmp[1]*(x_tmp[7]-udata->p[1]*x_tmp[6]);
  qBdot_tmp[ip + udata->nplist*4] = xB_tmp[9]*(x_tmp[1]-udata->p[1]*x_tmp[0])+xB_tmp[1]*(x_tmp[9]-udata->p[1]*x_tmp[8]);

  } break;

  case 1: {
  qBdot_tmp[ip + udata->nplist*0] = -udata->p[0]*x_tmp[0]*xB_tmp[1];
  qBdot_tmp[ip + udata->nplist*1] = -xB_tmp[1]*(x_tmp[0]+udata->p[0]*x_tmp[2])-udata->p[0]*x_tmp[0]*xB_tmp[3];
  qBdot_tmp[ip + udata->nplist*2] = -udata->p[0]*x_tmp[0]*xB_tmp[5]-udata->p[0]*x_tmp[4]*xB_tmp[1];
  qBdot_tmp[ip + udata->nplist*3] = -udata->p[0]*x_tmp[0]*xB_tmp[7]-udata->p[0]*x_tmp[6]*xB_tmp[1];
  qBdot_tmp[ip + udata->nplist*4] = -udata->p[0]*x_tmp[0]*xB_tmp[9]-udata->p[0]*x_tmp[8]*xB_tmp[1];

  } break;

}
}
for(ip = 0; ip<udata->nplist*udata->nJ; ip++) {
   if(amiIsNaN(qBdot_tmp[ip])) {
       qBdot_tmp[ip] = 0;       if(!udata->nan_qBdot) {
           warnMsgIdAndTxt("AMICI:mex:fqBdot:NaN","AMICI replaced a NaN value in xBdot and replaced it by 0.0. This will not be reported again for this simulation run.");
           udata->nan_qBdot = TRUE;
       }
   }   if(amiIsInf(qBdot_tmp[ip])) {
       warnMsgIdAndTxt("AMICI:mex:fqBdot:Inf","AMICI encountered an Inf value in xBdot! Aborting simulation ... ");
       return(-1);
   }}
return(status);

}

