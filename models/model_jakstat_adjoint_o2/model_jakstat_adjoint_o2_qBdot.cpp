
#include <include/symbolic_functions.h>
#include <string.h>
#include <include/udata.h>
#include "model_jakstat_adjoint_o2_dwdp.h"
#include "model_jakstat_adjoint_o2_w.h"

int qBdot_model_jakstat_adjoint_o2(realtype t, N_Vector x, N_Vector xB, N_Vector qBdot, void *user_data) {
int status = 0;
UserData *udata = (UserData*) user_data;
realtype *x_tmp = N_VGetArrayPointer(x);
realtype *xB_tmp = N_VGetArrayPointer(xB);
realtype *qBdot_tmp = N_VGetArrayPointer(qBdot);
int ip;
memset(qBdot_tmp,0,sizeof(realtype)*udata->nplist*udata->nJ);
status = dwdp_model_jakstat_adjoint_o2(t,x,NULL,user_data);
for(ip = 0; ip<udata->nplist; ip++) {
switch (udata->plist[ip]) {
  case 0: {
  qBdot_tmp[0] = -udata->w[0]*x_tmp[0]*xB_tmp[1]+udata->k[0]*udata->w[0]*x_tmp[0]*udata->w[2]*xB_tmp[0];
  qBdot_tmp[1] = udata->w[0]*x_tmp[9]*xB_tmp[0]-udata->w[0]*x_tmp[0]*xB_tmp[10]-udata->w[0]*x_tmp[9]*xB_tmp[1]+udata->k[0]*udata->w[0]*x_tmp[0]*udata->w[2]*xB_tmp[9];
  qBdot_tmp[2] = udata->w[0]*x_tmp[18]*xB_tmp[0]-udata->w[0]*x_tmp[0]*xB_tmp[19]-udata->w[0]*x_tmp[18]*xB_tmp[1]+udata->k[0]*udata->w[0]*x_tmp[0]*udata->w[2]*xB_tmp[18];
  qBdot_tmp[3] = udata->w[0]*x_tmp[27]*xB_tmp[0]-udata->w[0]*x_tmp[0]*xB_tmp[28]-udata->w[0]*x_tmp[27]*xB_tmp[1]+udata->k[0]*udata->w[0]*x_tmp[0]*udata->w[2]*xB_tmp[27];
  qBdot_tmp[4] = udata->w[0]*x_tmp[36]*xB_tmp[0]-udata->w[0]*x_tmp[0]*xB_tmp[37]-udata->w[0]*x_tmp[36]*xB_tmp[1]+udata->k[0]*udata->w[0]*x_tmp[0]*udata->w[2]*xB_tmp[36];
  qBdot_tmp[5] = udata->w[0]*x_tmp[45]*xB_tmp[0]-udata->w[0]*x_tmp[0]*xB_tmp[46]-udata->w[0]*x_tmp[45]*xB_tmp[1]+udata->k[0]*udata->w[0]*x_tmp[0]*udata->w[2]*xB_tmp[45];
  qBdot_tmp[6] = xB_tmp[0]*(x_tmp[0]*udata->w[5]+udata->w[0]*x_tmp[54])-xB_tmp[1]*(x_tmp[0]*udata->w[5]+udata->w[0]*x_tmp[54])-udata->w[0]*x_tmp[0]*xB_tmp[55]+udata->k[0]*udata->w[0]*x_tmp[0]*udata->w[2]*xB_tmp[54];
  qBdot_tmp[7] = xB_tmp[0]*(x_tmp[0]*udata->w[6]+udata->w[0]*x_tmp[63])-xB_tmp[1]*(x_tmp[0]*udata->w[6]+udata->w[0]*x_tmp[63])-udata->w[0]*x_tmp[0]*xB_tmp[64]+udata->k[0]*udata->w[0]*x_tmp[0]*udata->w[2]*xB_tmp[63];
  qBdot_tmp[8] = xB_tmp[0]*(x_tmp[0]*udata->w[7]+udata->w[0]*x_tmp[72])-xB_tmp[1]*(x_tmp[0]*udata->w[7]+udata->w[0]*x_tmp[72])-udata->w[0]*x_tmp[0]*xB_tmp[73]+udata->k[0]*udata->w[0]*x_tmp[0]*udata->w[2]*xB_tmp[72];
  qBdot_tmp[9] = xB_tmp[0]*(x_tmp[0]*udata->w[8]+udata->w[0]*x_tmp[81])-xB_tmp[1]*(x_tmp[0]*udata->w[8]+udata->w[0]*x_tmp[81])-udata->w[0]*x_tmp[0]*xB_tmp[82]+udata->k[0]*udata->w[0]*x_tmp[0]*udata->w[2]*xB_tmp[81];
  qBdot_tmp[10] = xB_tmp[0]*(x_tmp[0]*udata->w[9]+udata->w[0]*x_tmp[90])-xB_tmp[1]*(x_tmp[0]*udata->w[9]+udata->w[0]*x_tmp[90])-udata->w[0]*x_tmp[0]*xB_tmp[91]+udata->k[0]*udata->w[0]*x_tmp[0]*udata->w[2]*xB_tmp[90];
  qBdot_tmp[11] = udata->w[0]*xB_tmp[0]*x_tmp[99]-udata->w[0]*x_tmp[0]*xB_tmp[100]-udata->w[0]*xB_tmp[1]*x_tmp[99]+udata->k[0]*udata->w[0]*x_tmp[0]*udata->w[2]*xB_tmp[99];
  qBdot_tmp[12] = udata->w[0]*xB_tmp[0]*x_tmp[108]-udata->w[0]*x_tmp[0]*xB_tmp[109]-udata->w[0]*xB_tmp[1]*x_tmp[108]+udata->k[0]*udata->w[0]*x_tmp[0]*udata->w[2]*xB_tmp[108];
  qBdot_tmp[13] = udata->w[0]*xB_tmp[0]*x_tmp[117]-udata->w[0]*x_tmp[0]*xB_tmp[118]-udata->w[0]*xB_tmp[1]*x_tmp[117]+udata->k[0]*udata->w[0]*x_tmp[0]*udata->w[2]*xB_tmp[117];
  qBdot_tmp[14] = udata->w[0]*xB_tmp[0]*x_tmp[126]-udata->w[0]*x_tmp[0]*xB_tmp[127]-udata->w[0]*xB_tmp[1]*x_tmp[126]+udata->k[0]*udata->w[0]*x_tmp[0]*udata->w[2]*xB_tmp[126];
  qBdot_tmp[15] = udata->w[0]*xB_tmp[0]*x_tmp[135]-udata->w[0]*x_tmp[0]*xB_tmp[136]-udata->w[0]*xB_tmp[1]*x_tmp[135]+udata->k[0]*udata->w[0]*x_tmp[0]*udata->w[2]*xB_tmp[135];
  qBdot_tmp[16] = udata->w[0]*xB_tmp[0]*x_tmp[144]-udata->w[0]*x_tmp[0]*xB_tmp[145]-udata->w[0]*xB_tmp[1]*x_tmp[144]+udata->k[0]*udata->w[0]*x_tmp[0]*udata->w[2]*xB_tmp[144];
  qBdot_tmp[17] = udata->w[0]*xB_tmp[0]*x_tmp[153]-udata->w[0]*x_tmp[0]*xB_tmp[154]-udata->w[0]*xB_tmp[1]*x_tmp[153]+udata->k[0]*udata->w[0]*x_tmp[0]*udata->w[2]*xB_tmp[153];

  } break;

  case 1: {
  qBdot_tmp[0] = udata->w[1]*xB_tmp[1]*2.0-udata->w[1]*xB_tmp[2];
  qBdot_tmp[1] = udata->w[1]*xB_tmp[10]*2.0-udata->w[1]*xB_tmp[11]+x_tmp[1]*x_tmp[10]*xB_tmp[1]*4.0-x_tmp[1]*x_tmp[10]*xB_tmp[2]*2.0;
  qBdot_tmp[2] = udata->w[1]*xB_tmp[19]*2.0-udata->w[1]*xB_tmp[20]+x_tmp[1]*x_tmp[19]*xB_tmp[1]*4.0-x_tmp[1]*x_tmp[19]*xB_tmp[2]*2.0;
  qBdot_tmp[3] = udata->w[1]*xB_tmp[28]*2.0-udata->w[1]*xB_tmp[29]+x_tmp[1]*x_tmp[28]*xB_tmp[1]*4.0-x_tmp[1]*x_tmp[28]*xB_tmp[2]*2.0;
  qBdot_tmp[4] = udata->w[1]*xB_tmp[37]*2.0-udata->w[1]*xB_tmp[38]+x_tmp[1]*x_tmp[37]*xB_tmp[1]*4.0-x_tmp[1]*x_tmp[37]*xB_tmp[2]*2.0;
  qBdot_tmp[5] = udata->w[1]*xB_tmp[46]*2.0-udata->w[1]*xB_tmp[47]+x_tmp[1]*x_tmp[46]*xB_tmp[1]*4.0-x_tmp[1]*x_tmp[46]*xB_tmp[2]*2.0;
  qBdot_tmp[6] = udata->w[1]*xB_tmp[55]*2.0-udata->w[1]*xB_tmp[56]+x_tmp[1]*x_tmp[55]*xB_tmp[1]*4.0-x_tmp[1]*x_tmp[55]*xB_tmp[2]*2.0;
  qBdot_tmp[7] = udata->w[1]*xB_tmp[64]*2.0-udata->w[1]*xB_tmp[65]+x_tmp[1]*x_tmp[64]*xB_tmp[1]*4.0-x_tmp[1]*x_tmp[64]*xB_tmp[2]*2.0;
  qBdot_tmp[8] = udata->w[1]*xB_tmp[73]*2.0-udata->w[1]*xB_tmp[74]+x_tmp[1]*xB_tmp[1]*x_tmp[73]*4.0-x_tmp[1]*xB_tmp[2]*x_tmp[73]*2.0;
  qBdot_tmp[9] = udata->w[1]*xB_tmp[82]*2.0-udata->w[1]*xB_tmp[83]+x_tmp[1]*xB_tmp[1]*x_tmp[82]*4.0-x_tmp[1]*xB_tmp[2]*x_tmp[82]*2.0;
  qBdot_tmp[10] = udata->w[1]*xB_tmp[91]*2.0-udata->w[1]*xB_tmp[92]+x_tmp[1]*xB_tmp[1]*x_tmp[91]*4.0-x_tmp[1]*xB_tmp[2]*x_tmp[91]*2.0;
  qBdot_tmp[11] = udata->w[1]*xB_tmp[100]*2.0-udata->w[1]*xB_tmp[101]+x_tmp[1]*xB_tmp[1]*x_tmp[100]*4.0-x_tmp[1]*xB_tmp[2]*x_tmp[100]*2.0;
  qBdot_tmp[12] = udata->w[1]*xB_tmp[109]*2.0-udata->w[1]*xB_tmp[110]+x_tmp[1]*xB_tmp[1]*x_tmp[109]*4.0-x_tmp[1]*xB_tmp[2]*x_tmp[109]*2.0;
  qBdot_tmp[13] = udata->w[1]*xB_tmp[118]*2.0-udata->w[1]*xB_tmp[119]+x_tmp[1]*xB_tmp[1]*x_tmp[118]*4.0-x_tmp[1]*xB_tmp[2]*x_tmp[118]*2.0;
  qBdot_tmp[14] = udata->w[1]*xB_tmp[127]*2.0-udata->w[1]*xB_tmp[128]+x_tmp[1]*xB_tmp[1]*x_tmp[127]*4.0-x_tmp[1]*xB_tmp[2]*x_tmp[127]*2.0;
  qBdot_tmp[15] = udata->w[1]*xB_tmp[136]*2.0-udata->w[1]*xB_tmp[137]+x_tmp[1]*xB_tmp[1]*x_tmp[136]*4.0-x_tmp[1]*xB_tmp[2]*x_tmp[136]*2.0;
  qBdot_tmp[16] = udata->w[1]*xB_tmp[145]*2.0-udata->w[1]*xB_tmp[146]+x_tmp[1]*xB_tmp[1]*x_tmp[145]*4.0-x_tmp[1]*xB_tmp[2]*x_tmp[145]*2.0;
  qBdot_tmp[17] = udata->w[1]*xB_tmp[154]*2.0-udata->w[1]*xB_tmp[155]+x_tmp[1]*xB_tmp[1]*x_tmp[154]*4.0-x_tmp[1]*xB_tmp[2]*x_tmp[154]*2.0;

  } break;

  case 2: {
  qBdot_tmp[0] = x_tmp[2]*xB_tmp[2]-udata->k[0]*udata->w[3]*x_tmp[2]*xB_tmp[3];
  qBdot_tmp[1] = x_tmp[2]*xB_tmp[11]+x_tmp[11]*xB_tmp[2]-udata->k[0]*udata->w[3]*x_tmp[2]*xB_tmp[12]-udata->k[0]*udata->w[3]*x_tmp[11]*xB_tmp[3];
  qBdot_tmp[2] = x_tmp[2]*xB_tmp[20]+x_tmp[20]*xB_tmp[2]-udata->k[0]*udata->w[3]*x_tmp[2]*xB_tmp[21]-udata->k[0]*udata->w[3]*x_tmp[20]*xB_tmp[3];
  qBdot_tmp[3] = x_tmp[2]*xB_tmp[29]+x_tmp[29]*xB_tmp[2]-udata->k[0]*udata->w[3]*x_tmp[2]*xB_tmp[30]-udata->k[0]*udata->w[3]*x_tmp[29]*xB_tmp[3];
  qBdot_tmp[4] = x_tmp[2]*xB_tmp[38]+x_tmp[38]*xB_tmp[2]-udata->k[0]*udata->w[3]*x_tmp[2]*xB_tmp[39]-udata->k[0]*udata->w[3]*x_tmp[38]*xB_tmp[3];
  qBdot_tmp[5] = x_tmp[2]*xB_tmp[47]+x_tmp[47]*xB_tmp[2]-udata->k[0]*udata->w[3]*x_tmp[2]*xB_tmp[48]-udata->k[0]*udata->w[3]*x_tmp[47]*xB_tmp[3];
  qBdot_tmp[6] = x_tmp[2]*xB_tmp[56]+x_tmp[56]*xB_tmp[2]-udata->k[0]*udata->w[3]*x_tmp[2]*xB_tmp[57]-udata->k[0]*udata->w[3]*x_tmp[56]*xB_tmp[3];
  qBdot_tmp[7] = x_tmp[2]*xB_tmp[65]+x_tmp[65]*xB_tmp[2]-udata->k[0]*udata->w[3]*x_tmp[2]*xB_tmp[66]-udata->k[0]*udata->w[3]*x_tmp[65]*xB_tmp[3];
  qBdot_tmp[8] = x_tmp[2]*xB_tmp[74]+xB_tmp[2]*x_tmp[74]-udata->k[0]*udata->w[3]*x_tmp[2]*xB_tmp[75]-udata->k[0]*udata->w[3]*xB_tmp[3]*x_tmp[74];
  qBdot_tmp[9] = x_tmp[2]*xB_tmp[83]+xB_tmp[2]*x_tmp[83]-udata->k[0]*udata->w[3]*x_tmp[2]*xB_tmp[84]-udata->k[0]*udata->w[3]*xB_tmp[3]*x_tmp[83];
  qBdot_tmp[10] = x_tmp[2]*xB_tmp[92]+xB_tmp[2]*x_tmp[92]-udata->k[0]*udata->w[3]*x_tmp[2]*xB_tmp[93]-udata->k[0]*udata->w[3]*xB_tmp[3]*x_tmp[92];
  qBdot_tmp[11] = x_tmp[2]*xB_tmp[101]+xB_tmp[2]*x_tmp[101]-udata->k[0]*udata->w[3]*x_tmp[2]*xB_tmp[102]-udata->k[0]*udata->w[3]*xB_tmp[3]*x_tmp[101];
  qBdot_tmp[12] = x_tmp[2]*xB_tmp[110]+xB_tmp[2]*x_tmp[110]-udata->k[0]*udata->w[3]*x_tmp[2]*xB_tmp[111]-udata->k[0]*udata->w[3]*xB_tmp[3]*x_tmp[110];
  qBdot_tmp[13] = x_tmp[2]*xB_tmp[119]+xB_tmp[2]*x_tmp[119]-udata->k[0]*udata->w[3]*x_tmp[2]*xB_tmp[120]-udata->k[0]*udata->w[3]*xB_tmp[3]*x_tmp[119];
  qBdot_tmp[14] = x_tmp[2]*xB_tmp[128]+xB_tmp[2]*x_tmp[128]-udata->k[0]*udata->w[3]*x_tmp[2]*xB_tmp[129]-udata->k[0]*udata->w[3]*xB_tmp[3]*x_tmp[128];
  qBdot_tmp[15] = x_tmp[2]*xB_tmp[137]+xB_tmp[2]*x_tmp[137]-udata->k[0]*udata->w[3]*x_tmp[2]*xB_tmp[138]-udata->k[0]*udata->w[3]*xB_tmp[3]*x_tmp[137];
  qBdot_tmp[16] = x_tmp[2]*xB_tmp[146]+xB_tmp[2]*x_tmp[146]-udata->k[0]*udata->w[3]*x_tmp[2]*xB_tmp[147]-udata->k[0]*udata->w[3]*xB_tmp[3]*x_tmp[146];
  qBdot_tmp[17] = x_tmp[2]*xB_tmp[155]+xB_tmp[2]*x_tmp[155]-udata->k[0]*udata->w[3]*x_tmp[2]*xB_tmp[156]-udata->k[0]*udata->w[3]*xB_tmp[3]*x_tmp[155];

  } break;

  case 3: {
  qBdot_tmp[0] = -xB_tmp[4]*(udata->w[4]-x_tmp[4])-xB_tmp[5]*(x_tmp[4]-x_tmp[5])-xB_tmp[6]*(x_tmp[5]-x_tmp[6])-xB_tmp[7]*(x_tmp[6]-x_tmp[7])-xB_tmp[8]*(x_tmp[7]-x_tmp[8])+udata->k[1]*udata->w[3]*x_tmp[3]*xB_tmp[3]-udata->k[1]*udata->w[2]*x_tmp[8]*xB_tmp[0];
  qBdot_tmp[1] = x_tmp[12]*xB_tmp[3]-xB_tmp[13]*(udata->w[4]-x_tmp[4])-xB_tmp[14]*(x_tmp[4]-x_tmp[5])-xB_tmp[15]*(x_tmp[5]-x_tmp[6])-xB_tmp[16]*(x_tmp[6]-x_tmp[7])-xB_tmp[5]*(x_tmp[13]-x_tmp[14])-xB_tmp[17]*(x_tmp[7]-x_tmp[8])-xB_tmp[6]*(x_tmp[14]-x_tmp[15])-xB_tmp[7]*(x_tmp[15]-x_tmp[16])-xB_tmp[8]*(x_tmp[16]-x_tmp[17])-xB_tmp[4]*(x_tmp[12]*2.0-x_tmp[13])+udata->k[1]*udata->w[3]*x_tmp[3]*xB_tmp[12]-udata->k[1]*udata->w[2]*x_tmp[8]*xB_tmp[9]-udata->k[1]*udata->w[2]*x_tmp[17]*xB_tmp[0];
  qBdot_tmp[2] = x_tmp[21]*xB_tmp[3]-xB_tmp[22]*(udata->w[4]-x_tmp[4])-xB_tmp[23]*(x_tmp[4]-x_tmp[5])-xB_tmp[24]*(x_tmp[5]-x_tmp[6])-xB_tmp[25]*(x_tmp[6]-x_tmp[7])-xB_tmp[26]*(x_tmp[7]-x_tmp[8])-xB_tmp[5]*(x_tmp[22]-x_tmp[23])-xB_tmp[6]*(x_tmp[23]-x_tmp[24])-xB_tmp[7]*(x_tmp[24]-x_tmp[25])-xB_tmp[8]*(x_tmp[25]-x_tmp[26])-xB_tmp[4]*(x_tmp[21]*2.0-x_tmp[22])+udata->k[1]*udata->w[3]*x_tmp[3]*xB_tmp[21]-udata->k[1]*udata->w[2]*x_tmp[8]*xB_tmp[18]-udata->k[1]*udata->w[2]*x_tmp[26]*xB_tmp[0];
  qBdot_tmp[3] = x_tmp[30]*xB_tmp[3]-xB_tmp[31]*(udata->w[4]-x_tmp[4])-xB_tmp[32]*(x_tmp[4]-x_tmp[5])-xB_tmp[33]*(x_tmp[5]-x_tmp[6])-xB_tmp[34]*(x_tmp[6]-x_tmp[7])-xB_tmp[35]*(x_tmp[7]-x_tmp[8])-xB_tmp[5]*(x_tmp[31]-x_tmp[32])-xB_tmp[6]*(x_tmp[32]-x_tmp[33])-xB_tmp[7]*(x_tmp[33]-x_tmp[34])-xB_tmp[8]*(x_tmp[34]-x_tmp[35])-xB_tmp[4]*(x_tmp[30]*2.0-x_tmp[31])+udata->k[1]*udata->w[3]*x_tmp[3]*xB_tmp[30]-udata->k[1]*udata->w[2]*x_tmp[8]*xB_tmp[27]-udata->k[1]*udata->w[2]*x_tmp[35]*xB_tmp[0];
  qBdot_tmp[4] = x_tmp[39]*xB_tmp[3]-xB_tmp[40]*(udata->w[4]-x_tmp[4])-xB_tmp[41]*(x_tmp[4]-x_tmp[5])-xB_tmp[42]*(x_tmp[5]-x_tmp[6])-xB_tmp[43]*(x_tmp[6]-x_tmp[7])-xB_tmp[44]*(x_tmp[7]-x_tmp[8])-xB_tmp[5]*(x_tmp[40]-x_tmp[41])-xB_tmp[6]*(x_tmp[41]-x_tmp[42])-xB_tmp[7]*(x_tmp[42]-x_tmp[43])-xB_tmp[8]*(x_tmp[43]-x_tmp[44])-xB_tmp[4]*(x_tmp[39]*2.0-x_tmp[40])+udata->k[1]*udata->w[3]*x_tmp[3]*xB_tmp[39]-udata->k[1]*udata->w[2]*x_tmp[8]*xB_tmp[36]-udata->k[1]*udata->w[2]*x_tmp[44]*xB_tmp[0];
  qBdot_tmp[5] = x_tmp[48]*xB_tmp[3]-xB_tmp[49]*(udata->w[4]-x_tmp[4])-xB_tmp[50]*(x_tmp[4]-x_tmp[5])-xB_tmp[51]*(x_tmp[5]-x_tmp[6])-xB_tmp[52]*(x_tmp[6]-x_tmp[7])-xB_tmp[53]*(x_tmp[7]-x_tmp[8])-xB_tmp[5]*(x_tmp[49]-x_tmp[50])-xB_tmp[6]*(x_tmp[50]-x_tmp[51])-xB_tmp[7]*(x_tmp[51]-x_tmp[52])-xB_tmp[8]*(x_tmp[52]-x_tmp[53])-xB_tmp[4]*(x_tmp[48]*2.0-x_tmp[49])+udata->k[1]*udata->w[3]*x_tmp[3]*xB_tmp[48]-udata->k[1]*udata->w[2]*x_tmp[8]*xB_tmp[45]-udata->k[1]*udata->w[2]*x_tmp[53]*xB_tmp[0];
  qBdot_tmp[6] = x_tmp[57]*xB_tmp[3]-xB_tmp[58]*(udata->w[4]-x_tmp[4])-xB_tmp[59]*(x_tmp[4]-x_tmp[5])-xB_tmp[60]*(x_tmp[5]-x_tmp[6])-xB_tmp[61]*(x_tmp[6]-x_tmp[7])-xB_tmp[62]*(x_tmp[7]-x_tmp[8])-xB_tmp[5]*(x_tmp[58]-x_tmp[59])-xB_tmp[6]*(x_tmp[59]-x_tmp[60])-xB_tmp[7]*(x_tmp[60]-x_tmp[61])-xB_tmp[8]*(x_tmp[61]-x_tmp[62])-xB_tmp[4]*(x_tmp[57]*2.0-x_tmp[58])+udata->k[1]*udata->w[3]*x_tmp[3]*xB_tmp[57]-udata->k[1]*udata->w[2]*x_tmp[8]*xB_tmp[54]-udata->k[1]*udata->w[2]*x_tmp[62]*xB_tmp[0];
  qBdot_tmp[7] = x_tmp[66]*xB_tmp[3]-xB_tmp[67]*(udata->w[4]-x_tmp[4])-xB_tmp[68]*(x_tmp[4]-x_tmp[5])-xB_tmp[69]*(x_tmp[5]-x_tmp[6])-xB_tmp[70]*(x_tmp[6]-x_tmp[7])-xB_tmp[71]*(x_tmp[7]-x_tmp[8])-xB_tmp[5]*(x_tmp[67]-x_tmp[68])-xB_tmp[6]*(x_tmp[68]-x_tmp[69])-xB_tmp[7]*(x_tmp[69]-x_tmp[70])-xB_tmp[8]*(x_tmp[70]-x_tmp[71])-xB_tmp[4]*(x_tmp[66]*2.0-x_tmp[67])+udata->k[1]*udata->w[3]*x_tmp[3]*xB_tmp[66]-udata->k[1]*udata->w[2]*x_tmp[8]*xB_tmp[63]-udata->k[1]*udata->w[2]*xB_tmp[0]*x_tmp[71];
  qBdot_tmp[8] = xB_tmp[3]*x_tmp[75]-xB_tmp[76]*(udata->w[4]-x_tmp[4])-xB_tmp[77]*(x_tmp[4]-x_tmp[5])-xB_tmp[78]*(x_tmp[5]-x_tmp[6])-xB_tmp[79]*(x_tmp[6]-x_tmp[7])-xB_tmp[80]*(x_tmp[7]-x_tmp[8])-xB_tmp[5]*(x_tmp[76]-x_tmp[77])-xB_tmp[6]*(x_tmp[77]-x_tmp[78])-xB_tmp[7]*(x_tmp[78]-x_tmp[79])-xB_tmp[8]*(x_tmp[79]-x_tmp[80])-xB_tmp[4]*(x_tmp[75]*2.0-x_tmp[76])+udata->k[1]*udata->w[3]*x_tmp[3]*xB_tmp[75]-udata->k[1]*udata->w[2]*x_tmp[8]*xB_tmp[72]-udata->k[1]*udata->w[2]*xB_tmp[0]*x_tmp[80];
  qBdot_tmp[9] = xB_tmp[3]*x_tmp[84]-xB_tmp[85]*(udata->w[4]-x_tmp[4])-xB_tmp[86]*(x_tmp[4]-x_tmp[5])-xB_tmp[87]*(x_tmp[5]-x_tmp[6])-xB_tmp[88]*(x_tmp[6]-x_tmp[7])-xB_tmp[89]*(x_tmp[7]-x_tmp[8])-xB_tmp[5]*(x_tmp[85]-x_tmp[86])-xB_tmp[6]*(x_tmp[86]-x_tmp[87])-xB_tmp[7]*(x_tmp[87]-x_tmp[88])-xB_tmp[8]*(x_tmp[88]-x_tmp[89])-xB_tmp[4]*(x_tmp[84]*2.0-x_tmp[85])+udata->k[1]*udata->w[3]*x_tmp[3]*xB_tmp[84]-udata->k[1]*udata->w[2]*x_tmp[8]*xB_tmp[81]-udata->k[1]*udata->w[2]*xB_tmp[0]*x_tmp[89];
  qBdot_tmp[10] = xB_tmp[3]*x_tmp[93]-xB_tmp[94]*(udata->w[4]-x_tmp[4])-xB_tmp[95]*(x_tmp[4]-x_tmp[5])-xB_tmp[96]*(x_tmp[5]-x_tmp[6])-xB_tmp[97]*(x_tmp[6]-x_tmp[7])-xB_tmp[98]*(x_tmp[7]-x_tmp[8])-xB_tmp[5]*(x_tmp[94]-x_tmp[95])-xB_tmp[6]*(x_tmp[95]-x_tmp[96])-xB_tmp[7]*(x_tmp[96]-x_tmp[97])-xB_tmp[8]*(x_tmp[97]-x_tmp[98])-xB_tmp[4]*(x_tmp[93]*2.0-x_tmp[94])+udata->k[1]*udata->w[3]*x_tmp[3]*xB_tmp[93]-udata->k[1]*udata->w[2]*x_tmp[8]*xB_tmp[90]-udata->k[1]*udata->w[2]*xB_tmp[0]*x_tmp[98];
  qBdot_tmp[11] = xB_tmp[3]*x_tmp[102]-xB_tmp[103]*(udata->w[4]-x_tmp[4])-xB_tmp[104]*(x_tmp[4]-x_tmp[5])-xB_tmp[105]*(x_tmp[5]-x_tmp[6])-xB_tmp[106]*(x_tmp[6]-x_tmp[7])-xB_tmp[107]*(x_tmp[7]-x_tmp[8])-xB_tmp[5]*(x_tmp[103]-x_tmp[104])-xB_tmp[6]*(x_tmp[104]-x_tmp[105])-xB_tmp[7]*(x_tmp[105]-x_tmp[106])-xB_tmp[8]*(x_tmp[106]-x_tmp[107])-xB_tmp[4]*(x_tmp[102]*2.0-x_tmp[103])+udata->k[1]*udata->w[3]*x_tmp[3]*xB_tmp[102]-udata->k[1]*udata->w[2]*x_tmp[8]*xB_tmp[99]-udata->k[1]*udata->w[2]*xB_tmp[0]*x_tmp[107];
  qBdot_tmp[12] = xB_tmp[3]*x_tmp[111]-xB_tmp[112]*(udata->w[4]-x_tmp[4])-xB_tmp[113]*(x_tmp[4]-x_tmp[5])-xB_tmp[114]*(x_tmp[5]-x_tmp[6])-xB_tmp[115]*(x_tmp[6]-x_tmp[7])-xB_tmp[116]*(x_tmp[7]-x_tmp[8])-xB_tmp[5]*(x_tmp[112]-x_tmp[113])-xB_tmp[6]*(x_tmp[113]-x_tmp[114])-xB_tmp[7]*(x_tmp[114]-x_tmp[115])-xB_tmp[8]*(x_tmp[115]-x_tmp[116])-xB_tmp[4]*(x_tmp[111]*2.0-x_tmp[112])+udata->k[1]*udata->w[3]*x_tmp[3]*xB_tmp[111]-udata->k[1]*udata->w[2]*x_tmp[8]*xB_tmp[108]-udata->k[1]*udata->w[2]*xB_tmp[0]*x_tmp[116];
  qBdot_tmp[13] = xB_tmp[3]*x_tmp[120]-xB_tmp[121]*(udata->w[4]-x_tmp[4])-xB_tmp[122]*(x_tmp[4]-x_tmp[5])-xB_tmp[123]*(x_tmp[5]-x_tmp[6])-xB_tmp[124]*(x_tmp[6]-x_tmp[7])-xB_tmp[125]*(x_tmp[7]-x_tmp[8])-xB_tmp[5]*(x_tmp[121]-x_tmp[122])-xB_tmp[6]*(x_tmp[122]-x_tmp[123])-xB_tmp[7]*(x_tmp[123]-x_tmp[124])-xB_tmp[8]*(x_tmp[124]-x_tmp[125])-xB_tmp[4]*(x_tmp[120]*2.0-x_tmp[121])+udata->k[1]*udata->w[3]*x_tmp[3]*xB_tmp[120]-udata->k[1]*udata->w[2]*x_tmp[8]*xB_tmp[117]-udata->k[1]*udata->w[2]*xB_tmp[0]*x_tmp[125];
  qBdot_tmp[14] = xB_tmp[3]*x_tmp[129]-xB_tmp[130]*(udata->w[4]-x_tmp[4])-xB_tmp[131]*(x_tmp[4]-x_tmp[5])-xB_tmp[132]*(x_tmp[5]-x_tmp[6])-xB_tmp[133]*(x_tmp[6]-x_tmp[7])-xB_tmp[134]*(x_tmp[7]-x_tmp[8])-xB_tmp[5]*(x_tmp[130]-x_tmp[131])-xB_tmp[6]*(x_tmp[131]-x_tmp[132])-xB_tmp[7]*(x_tmp[132]-x_tmp[133])-xB_tmp[8]*(x_tmp[133]-x_tmp[134])-xB_tmp[4]*(x_tmp[129]*2.0-x_tmp[130])+udata->k[1]*udata->w[3]*x_tmp[3]*xB_tmp[129]-udata->k[1]*udata->w[2]*x_tmp[8]*xB_tmp[126]-udata->k[1]*udata->w[2]*xB_tmp[0]*x_tmp[134];
  qBdot_tmp[15] = xB_tmp[3]*x_tmp[138]-xB_tmp[139]*(udata->w[4]-x_tmp[4])-xB_tmp[140]*(x_tmp[4]-x_tmp[5])-xB_tmp[141]*(x_tmp[5]-x_tmp[6])-xB_tmp[142]*(x_tmp[6]-x_tmp[7])-xB_tmp[143]*(x_tmp[7]-x_tmp[8])-xB_tmp[5]*(x_tmp[139]-x_tmp[140])-xB_tmp[6]*(x_tmp[140]-x_tmp[141])-xB_tmp[7]*(x_tmp[141]-x_tmp[142])-xB_tmp[8]*(x_tmp[142]-x_tmp[143])-xB_tmp[4]*(x_tmp[138]*2.0-x_tmp[139])+udata->k[1]*udata->w[3]*x_tmp[3]*xB_tmp[138]-udata->k[1]*udata->w[2]*x_tmp[8]*xB_tmp[135]-udata->k[1]*udata->w[2]*xB_tmp[0]*x_tmp[143];
  qBdot_tmp[16] = xB_tmp[3]*x_tmp[147]-xB_tmp[148]*(udata->w[4]-x_tmp[4])-xB_tmp[149]*(x_tmp[4]-x_tmp[5])-xB_tmp[150]*(x_tmp[5]-x_tmp[6])-xB_tmp[151]*(x_tmp[6]-x_tmp[7])-xB_tmp[152]*(x_tmp[7]-x_tmp[8])-xB_tmp[5]*(x_tmp[148]-x_tmp[149])-xB_tmp[6]*(x_tmp[149]-x_tmp[150])-xB_tmp[7]*(x_tmp[150]-x_tmp[151])-xB_tmp[8]*(x_tmp[151]-x_tmp[152])-xB_tmp[4]*(x_tmp[147]*2.0-x_tmp[148])+udata->k[1]*udata->w[3]*x_tmp[3]*xB_tmp[147]-udata->k[1]*udata->w[2]*x_tmp[8]*xB_tmp[144]-udata->k[1]*udata->w[2]*xB_tmp[0]*x_tmp[152];
  qBdot_tmp[17] = xB_tmp[3]*x_tmp[156]-xB_tmp[157]*(udata->w[4]-x_tmp[4])-xB_tmp[158]*(x_tmp[4]-x_tmp[5])-xB_tmp[159]*(x_tmp[5]-x_tmp[6])-xB_tmp[160]*(x_tmp[6]-x_tmp[7])-xB_tmp[161]*(x_tmp[7]-x_tmp[8])-xB_tmp[5]*(x_tmp[157]-x_tmp[158])-xB_tmp[6]*(x_tmp[158]-x_tmp[159])-xB_tmp[7]*(x_tmp[159]-x_tmp[160])-xB_tmp[8]*(x_tmp[160]-x_tmp[161])-xB_tmp[4]*(x_tmp[156]*2.0-x_tmp[157])+udata->k[1]*udata->w[3]*x_tmp[3]*xB_tmp[156]-udata->k[1]*udata->w[2]*x_tmp[8]*xB_tmp[153]-udata->k[1]*udata->w[2]*xB_tmp[0]*x_tmp[161];

  } break;

  case 5: {
  qBdot_tmp[0] = -udata->p[0]*x_tmp[0]*xB_tmp[1]*udata->dwdp[0]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[0]*udata->dwdp[0];
  qBdot_tmp[1] = xB_tmp[0]*udata->dwdp[0]*(x_tmp[0]+udata->p[0]*x_tmp[9])-xB_tmp[1]*udata->dwdp[0]*(x_tmp[0]+udata->p[0]*x_tmp[9])-udata->p[0]*x_tmp[0]*xB_tmp[10]*udata->dwdp[0]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[9]*udata->dwdp[0];
  qBdot_tmp[2] = udata->p[0]*x_tmp[18]*xB_tmp[0]*udata->dwdp[0]-udata->p[0]*x_tmp[0]*xB_tmp[19]*udata->dwdp[0]-udata->p[0]*x_tmp[18]*xB_tmp[1]*udata->dwdp[0]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[18]*udata->dwdp[0];
  qBdot_tmp[3] = udata->p[0]*x_tmp[27]*xB_tmp[0]*udata->dwdp[0]-udata->p[0]*x_tmp[0]*xB_tmp[28]*udata->dwdp[0]-udata->p[0]*x_tmp[27]*xB_tmp[1]*udata->dwdp[0]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[27]*udata->dwdp[0];
  qBdot_tmp[4] = udata->p[0]*x_tmp[36]*xB_tmp[0]*udata->dwdp[0]-udata->p[0]*x_tmp[0]*xB_tmp[37]*udata->dwdp[0]-udata->p[0]*x_tmp[36]*xB_tmp[1]*udata->dwdp[0]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[36]*udata->dwdp[0];
  qBdot_tmp[5] = udata->p[0]*x_tmp[45]*xB_tmp[0]*udata->dwdp[0]-udata->p[0]*x_tmp[0]*xB_tmp[46]*udata->dwdp[0]-udata->p[0]*x_tmp[45]*xB_tmp[1]*udata->dwdp[0]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[45]*udata->dwdp[0];
  qBdot_tmp[6] = xB_tmp[0]*(udata->p[0]*x_tmp[0]*udata->dwdp[1]+udata->p[0]*x_tmp[54]*udata->dwdp[0])-xB_tmp[1]*(udata->p[0]*x_tmp[0]*udata->dwdp[1]+udata->p[0]*x_tmp[54]*udata->dwdp[0])-udata->p[0]*x_tmp[0]*xB_tmp[55]*udata->dwdp[0]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[54]*udata->dwdp[0];
  qBdot_tmp[7] = xB_tmp[0]*(udata->p[0]*x_tmp[0]*udata->dwdp[2]+udata->p[0]*x_tmp[63]*udata->dwdp[0])-xB_tmp[1]*(udata->p[0]*x_tmp[0]*udata->dwdp[2]+udata->p[0]*x_tmp[63]*udata->dwdp[0])-udata->p[0]*x_tmp[0]*xB_tmp[64]*udata->dwdp[0]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[63]*udata->dwdp[0];
  qBdot_tmp[8] = xB_tmp[0]*(udata->p[0]*x_tmp[0]*udata->dwdp[3]+udata->p[0]*x_tmp[72]*udata->dwdp[0])-xB_tmp[1]*(udata->p[0]*x_tmp[0]*udata->dwdp[3]+udata->p[0]*x_tmp[72]*udata->dwdp[0])-udata->p[0]*x_tmp[0]*xB_tmp[73]*udata->dwdp[0]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[72]*udata->dwdp[0];
  qBdot_tmp[9] = xB_tmp[0]*(udata->p[0]*x_tmp[0]*udata->dwdp[4]+udata->p[0]*x_tmp[81]*udata->dwdp[0])-xB_tmp[1]*(udata->p[0]*x_tmp[0]*udata->dwdp[4]+udata->p[0]*x_tmp[81]*udata->dwdp[0])-udata->p[0]*x_tmp[0]*xB_tmp[82]*udata->dwdp[0]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[81]*udata->dwdp[0];
  qBdot_tmp[10] = xB_tmp[0]*(udata->p[0]*x_tmp[0]*udata->dwdp[5]+udata->p[0]*x_tmp[90]*udata->dwdp[0])-xB_tmp[1]*(udata->p[0]*x_tmp[0]*udata->dwdp[5]+udata->p[0]*x_tmp[90]*udata->dwdp[0])-udata->p[0]*x_tmp[0]*xB_tmp[91]*udata->dwdp[0]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[90]*udata->dwdp[0];
  qBdot_tmp[11] = udata->p[0]*xB_tmp[0]*x_tmp[99]*udata->dwdp[0]-udata->p[0]*x_tmp[0]*xB_tmp[100]*udata->dwdp[0]-udata->p[0]*xB_tmp[1]*x_tmp[99]*udata->dwdp[0]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[99]*udata->dwdp[0];
  qBdot_tmp[12] = udata->p[0]*xB_tmp[0]*x_tmp[108]*udata->dwdp[0]-udata->p[0]*x_tmp[0]*xB_tmp[109]*udata->dwdp[0]-udata->p[0]*xB_tmp[1]*x_tmp[108]*udata->dwdp[0]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[108]*udata->dwdp[0];
  qBdot_tmp[13] = udata->p[0]*xB_tmp[0]*x_tmp[117]*udata->dwdp[0]-udata->p[0]*x_tmp[0]*xB_tmp[118]*udata->dwdp[0]-udata->p[0]*xB_tmp[1]*x_tmp[117]*udata->dwdp[0]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[117]*udata->dwdp[0];
  qBdot_tmp[14] = udata->p[0]*xB_tmp[0]*x_tmp[126]*udata->dwdp[0]-udata->p[0]*x_tmp[0]*xB_tmp[127]*udata->dwdp[0]-udata->p[0]*xB_tmp[1]*x_tmp[126]*udata->dwdp[0]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[126]*udata->dwdp[0];
  qBdot_tmp[15] = udata->p[0]*xB_tmp[0]*x_tmp[135]*udata->dwdp[0]-udata->p[0]*x_tmp[0]*xB_tmp[136]*udata->dwdp[0]-udata->p[0]*xB_tmp[1]*x_tmp[135]*udata->dwdp[0]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[135]*udata->dwdp[0];
  qBdot_tmp[16] = udata->p[0]*xB_tmp[0]*x_tmp[144]*udata->dwdp[0]-udata->p[0]*x_tmp[0]*xB_tmp[145]*udata->dwdp[0]-udata->p[0]*xB_tmp[1]*x_tmp[144]*udata->dwdp[0]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[144]*udata->dwdp[0];
  qBdot_tmp[17] = udata->p[0]*xB_tmp[0]*x_tmp[153]*udata->dwdp[0]-udata->p[0]*x_tmp[0]*xB_tmp[154]*udata->dwdp[0]-udata->p[0]*xB_tmp[1]*x_tmp[153]*udata->dwdp[0]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[153]*udata->dwdp[0];

  } break;

  case 6: {
  qBdot_tmp[0] = -udata->p[0]*x_tmp[0]*xB_tmp[1]*udata->dwdp[6]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[0]*udata->dwdp[6];
  qBdot_tmp[1] = xB_tmp[0]*udata->dwdp[6]*(x_tmp[0]+udata->p[0]*x_tmp[9])-xB_tmp[1]*udata->dwdp[6]*(x_tmp[0]+udata->p[0]*x_tmp[9])-udata->p[0]*x_tmp[0]*xB_tmp[10]*udata->dwdp[6]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[9]*udata->dwdp[6];
  qBdot_tmp[2] = udata->p[0]*x_tmp[18]*xB_tmp[0]*udata->dwdp[6]-udata->p[0]*x_tmp[0]*xB_tmp[19]*udata->dwdp[6]-udata->p[0]*x_tmp[18]*xB_tmp[1]*udata->dwdp[6]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[18]*udata->dwdp[6];
  qBdot_tmp[3] = udata->p[0]*x_tmp[27]*xB_tmp[0]*udata->dwdp[6]-udata->p[0]*x_tmp[0]*xB_tmp[28]*udata->dwdp[6]-udata->p[0]*x_tmp[27]*xB_tmp[1]*udata->dwdp[6]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[27]*udata->dwdp[6];
  qBdot_tmp[4] = udata->p[0]*x_tmp[36]*xB_tmp[0]*udata->dwdp[6]-udata->p[0]*x_tmp[0]*xB_tmp[37]*udata->dwdp[6]-udata->p[0]*x_tmp[36]*xB_tmp[1]*udata->dwdp[6]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[36]*udata->dwdp[6];
  qBdot_tmp[5] = udata->p[0]*x_tmp[45]*xB_tmp[0]*udata->dwdp[6]-udata->p[0]*x_tmp[0]*xB_tmp[46]*udata->dwdp[6]-udata->p[0]*x_tmp[45]*xB_tmp[1]*udata->dwdp[6]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[45]*udata->dwdp[6];
  qBdot_tmp[6] = xB_tmp[0]*(udata->p[0]*x_tmp[0]*udata->dwdp[7]+udata->p[0]*x_tmp[54]*udata->dwdp[6])-xB_tmp[1]*(udata->p[0]*x_tmp[0]*udata->dwdp[7]+udata->p[0]*x_tmp[54]*udata->dwdp[6])-udata->p[0]*x_tmp[0]*xB_tmp[55]*udata->dwdp[6]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[54]*udata->dwdp[6];
  qBdot_tmp[7] = xB_tmp[0]*(udata->p[0]*x_tmp[0]*udata->dwdp[8]+udata->p[0]*x_tmp[63]*udata->dwdp[6])-xB_tmp[1]*(udata->p[0]*x_tmp[0]*udata->dwdp[8]+udata->p[0]*x_tmp[63]*udata->dwdp[6])-udata->p[0]*x_tmp[0]*xB_tmp[64]*udata->dwdp[6]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[63]*udata->dwdp[6];
  qBdot_tmp[8] = xB_tmp[0]*(udata->p[0]*x_tmp[0]*udata->dwdp[9]+udata->p[0]*x_tmp[72]*udata->dwdp[6])-xB_tmp[1]*(udata->p[0]*x_tmp[0]*udata->dwdp[9]+udata->p[0]*x_tmp[72]*udata->dwdp[6])-udata->p[0]*x_tmp[0]*xB_tmp[73]*udata->dwdp[6]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[72]*udata->dwdp[6];
  qBdot_tmp[9] = xB_tmp[0]*(udata->p[0]*x_tmp[0]*udata->dwdp[10]+udata->p[0]*x_tmp[81]*udata->dwdp[6])-xB_tmp[1]*(udata->p[0]*x_tmp[0]*udata->dwdp[10]+udata->p[0]*x_tmp[81]*udata->dwdp[6])-udata->p[0]*x_tmp[0]*xB_tmp[82]*udata->dwdp[6]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[81]*udata->dwdp[6];
  qBdot_tmp[10] = xB_tmp[0]*(udata->p[0]*x_tmp[0]*udata->dwdp[11]+udata->p[0]*x_tmp[90]*udata->dwdp[6])-xB_tmp[1]*(udata->p[0]*x_tmp[0]*udata->dwdp[11]+udata->p[0]*x_tmp[90]*udata->dwdp[6])-udata->p[0]*x_tmp[0]*xB_tmp[91]*udata->dwdp[6]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[90]*udata->dwdp[6];
  qBdot_tmp[11] = udata->p[0]*xB_tmp[0]*x_tmp[99]*udata->dwdp[6]-udata->p[0]*x_tmp[0]*xB_tmp[100]*udata->dwdp[6]-udata->p[0]*xB_tmp[1]*x_tmp[99]*udata->dwdp[6]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[99]*udata->dwdp[6];
  qBdot_tmp[12] = udata->p[0]*xB_tmp[0]*x_tmp[108]*udata->dwdp[6]-udata->p[0]*x_tmp[0]*xB_tmp[109]*udata->dwdp[6]-udata->p[0]*xB_tmp[1]*x_tmp[108]*udata->dwdp[6]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[108]*udata->dwdp[6];
  qBdot_tmp[13] = udata->p[0]*xB_tmp[0]*x_tmp[117]*udata->dwdp[6]-udata->p[0]*x_tmp[0]*xB_tmp[118]*udata->dwdp[6]-udata->p[0]*xB_tmp[1]*x_tmp[117]*udata->dwdp[6]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[117]*udata->dwdp[6];
  qBdot_tmp[14] = udata->p[0]*xB_tmp[0]*x_tmp[126]*udata->dwdp[6]-udata->p[0]*x_tmp[0]*xB_tmp[127]*udata->dwdp[6]-udata->p[0]*xB_tmp[1]*x_tmp[126]*udata->dwdp[6]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[126]*udata->dwdp[6];
  qBdot_tmp[15] = udata->p[0]*xB_tmp[0]*x_tmp[135]*udata->dwdp[6]-udata->p[0]*x_tmp[0]*xB_tmp[136]*udata->dwdp[6]-udata->p[0]*xB_tmp[1]*x_tmp[135]*udata->dwdp[6]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[135]*udata->dwdp[6];
  qBdot_tmp[16] = udata->p[0]*xB_tmp[0]*x_tmp[144]*udata->dwdp[6]-udata->p[0]*x_tmp[0]*xB_tmp[145]*udata->dwdp[6]-udata->p[0]*xB_tmp[1]*x_tmp[144]*udata->dwdp[6]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[144]*udata->dwdp[6];
  qBdot_tmp[17] = udata->p[0]*xB_tmp[0]*x_tmp[153]*udata->dwdp[6]-udata->p[0]*x_tmp[0]*xB_tmp[154]*udata->dwdp[6]-udata->p[0]*xB_tmp[1]*x_tmp[153]*udata->dwdp[6]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[153]*udata->dwdp[6];

  } break;

  case 7: {
  qBdot_tmp[0] = -udata->p[0]*x_tmp[0]*xB_tmp[1]*udata->dwdp[12]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[0]*udata->dwdp[12];
  qBdot_tmp[1] = xB_tmp[0]*udata->dwdp[12]*(x_tmp[0]+udata->p[0]*x_tmp[9])-xB_tmp[1]*udata->dwdp[12]*(x_tmp[0]+udata->p[0]*x_tmp[9])-udata->p[0]*x_tmp[0]*xB_tmp[10]*udata->dwdp[12]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[9]*udata->dwdp[12];
  qBdot_tmp[2] = udata->p[0]*x_tmp[18]*xB_tmp[0]*udata->dwdp[12]-udata->p[0]*x_tmp[0]*xB_tmp[19]*udata->dwdp[12]-udata->p[0]*x_tmp[18]*xB_tmp[1]*udata->dwdp[12]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[18]*udata->dwdp[12];
  qBdot_tmp[3] = udata->p[0]*x_tmp[27]*xB_tmp[0]*udata->dwdp[12]-udata->p[0]*x_tmp[0]*xB_tmp[28]*udata->dwdp[12]-udata->p[0]*x_tmp[27]*xB_tmp[1]*udata->dwdp[12]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[27]*udata->dwdp[12];
  qBdot_tmp[4] = udata->p[0]*x_tmp[36]*xB_tmp[0]*udata->dwdp[12]-udata->p[0]*x_tmp[0]*xB_tmp[37]*udata->dwdp[12]-udata->p[0]*x_tmp[36]*xB_tmp[1]*udata->dwdp[12]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[36]*udata->dwdp[12];
  qBdot_tmp[5] = udata->p[0]*x_tmp[45]*xB_tmp[0]*udata->dwdp[12]-udata->p[0]*x_tmp[0]*xB_tmp[46]*udata->dwdp[12]-udata->p[0]*x_tmp[45]*xB_tmp[1]*udata->dwdp[12]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[45]*udata->dwdp[12];
  qBdot_tmp[6] = xB_tmp[0]*(udata->p[0]*x_tmp[0]*udata->dwdp[13]+udata->p[0]*x_tmp[54]*udata->dwdp[12])-xB_tmp[1]*(udata->p[0]*x_tmp[0]*udata->dwdp[13]+udata->p[0]*x_tmp[54]*udata->dwdp[12])-udata->p[0]*x_tmp[0]*xB_tmp[55]*udata->dwdp[12]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[54]*udata->dwdp[12];
  qBdot_tmp[7] = xB_tmp[0]*(udata->p[0]*x_tmp[0]*udata->dwdp[14]+udata->p[0]*x_tmp[63]*udata->dwdp[12])-xB_tmp[1]*(udata->p[0]*x_tmp[0]*udata->dwdp[14]+udata->p[0]*x_tmp[63]*udata->dwdp[12])-udata->p[0]*x_tmp[0]*xB_tmp[64]*udata->dwdp[12]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[63]*udata->dwdp[12];
  qBdot_tmp[8] = xB_tmp[0]*(udata->p[0]*x_tmp[0]*udata->dwdp[15]+udata->p[0]*x_tmp[72]*udata->dwdp[12])-xB_tmp[1]*(udata->p[0]*x_tmp[0]*udata->dwdp[15]+udata->p[0]*x_tmp[72]*udata->dwdp[12])-udata->p[0]*x_tmp[0]*xB_tmp[73]*udata->dwdp[12]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[72]*udata->dwdp[12];
  qBdot_tmp[9] = xB_tmp[0]*(udata->p[0]*x_tmp[0]*udata->dwdp[16]+udata->p[0]*x_tmp[81]*udata->dwdp[12])-xB_tmp[1]*(udata->p[0]*x_tmp[0]*udata->dwdp[16]+udata->p[0]*x_tmp[81]*udata->dwdp[12])-udata->p[0]*x_tmp[0]*xB_tmp[82]*udata->dwdp[12]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[81]*udata->dwdp[12];
  qBdot_tmp[10] = xB_tmp[0]*(udata->p[0]*x_tmp[0]*udata->dwdp[17]+udata->p[0]*x_tmp[90]*udata->dwdp[12])-xB_tmp[1]*(udata->p[0]*x_tmp[0]*udata->dwdp[17]+udata->p[0]*x_tmp[90]*udata->dwdp[12])-udata->p[0]*x_tmp[0]*xB_tmp[91]*udata->dwdp[12]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[90]*udata->dwdp[12];
  qBdot_tmp[11] = udata->p[0]*xB_tmp[0]*x_tmp[99]*udata->dwdp[12]-udata->p[0]*x_tmp[0]*xB_tmp[100]*udata->dwdp[12]-udata->p[0]*xB_tmp[1]*x_tmp[99]*udata->dwdp[12]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[99]*udata->dwdp[12];
  qBdot_tmp[12] = udata->p[0]*xB_tmp[0]*x_tmp[108]*udata->dwdp[12]-udata->p[0]*x_tmp[0]*xB_tmp[109]*udata->dwdp[12]-udata->p[0]*xB_tmp[1]*x_tmp[108]*udata->dwdp[12]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[108]*udata->dwdp[12];
  qBdot_tmp[13] = udata->p[0]*xB_tmp[0]*x_tmp[117]*udata->dwdp[12]-udata->p[0]*x_tmp[0]*xB_tmp[118]*udata->dwdp[12]-udata->p[0]*xB_tmp[1]*x_tmp[117]*udata->dwdp[12]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[117]*udata->dwdp[12];
  qBdot_tmp[14] = udata->p[0]*xB_tmp[0]*x_tmp[126]*udata->dwdp[12]-udata->p[0]*x_tmp[0]*xB_tmp[127]*udata->dwdp[12]-udata->p[0]*xB_tmp[1]*x_tmp[126]*udata->dwdp[12]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[126]*udata->dwdp[12];
  qBdot_tmp[15] = udata->p[0]*xB_tmp[0]*x_tmp[135]*udata->dwdp[12]-udata->p[0]*x_tmp[0]*xB_tmp[136]*udata->dwdp[12]-udata->p[0]*xB_tmp[1]*x_tmp[135]*udata->dwdp[12]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[135]*udata->dwdp[12];
  qBdot_tmp[16] = udata->p[0]*xB_tmp[0]*x_tmp[144]*udata->dwdp[12]-udata->p[0]*x_tmp[0]*xB_tmp[145]*udata->dwdp[12]-udata->p[0]*xB_tmp[1]*x_tmp[144]*udata->dwdp[12]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[144]*udata->dwdp[12];
  qBdot_tmp[17] = udata->p[0]*xB_tmp[0]*x_tmp[153]*udata->dwdp[12]-udata->p[0]*x_tmp[0]*xB_tmp[154]*udata->dwdp[12]-udata->p[0]*xB_tmp[1]*x_tmp[153]*udata->dwdp[12]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[153]*udata->dwdp[12];

  } break;

  case 8: {
  qBdot_tmp[0] = -udata->p[0]*x_tmp[0]*xB_tmp[1]*udata->dwdp[18]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[0]*udata->dwdp[18];
  qBdot_tmp[1] = xB_tmp[0]*udata->dwdp[18]*(x_tmp[0]+udata->p[0]*x_tmp[9])-xB_tmp[1]*udata->dwdp[18]*(x_tmp[0]+udata->p[0]*x_tmp[9])-udata->p[0]*x_tmp[0]*xB_tmp[10]*udata->dwdp[18]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[9]*udata->dwdp[18];
  qBdot_tmp[2] = udata->p[0]*x_tmp[18]*xB_tmp[0]*udata->dwdp[18]-udata->p[0]*x_tmp[0]*xB_tmp[19]*udata->dwdp[18]-udata->p[0]*x_tmp[18]*xB_tmp[1]*udata->dwdp[18]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[18]*udata->dwdp[18];
  qBdot_tmp[3] = udata->p[0]*x_tmp[27]*xB_tmp[0]*udata->dwdp[18]-udata->p[0]*x_tmp[0]*xB_tmp[28]*udata->dwdp[18]-udata->p[0]*x_tmp[27]*xB_tmp[1]*udata->dwdp[18]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[27]*udata->dwdp[18];
  qBdot_tmp[4] = udata->p[0]*x_tmp[36]*xB_tmp[0]*udata->dwdp[18]-udata->p[0]*x_tmp[0]*xB_tmp[37]*udata->dwdp[18]-udata->p[0]*x_tmp[36]*xB_tmp[1]*udata->dwdp[18]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[36]*udata->dwdp[18];
  qBdot_tmp[5] = udata->p[0]*x_tmp[45]*xB_tmp[0]*udata->dwdp[18]-udata->p[0]*x_tmp[0]*xB_tmp[46]*udata->dwdp[18]-udata->p[0]*x_tmp[45]*xB_tmp[1]*udata->dwdp[18]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[45]*udata->dwdp[18];
  qBdot_tmp[6] = xB_tmp[0]*(udata->p[0]*x_tmp[0]*udata->dwdp[19]+udata->p[0]*x_tmp[54]*udata->dwdp[18])-xB_tmp[1]*(udata->p[0]*x_tmp[0]*udata->dwdp[19]+udata->p[0]*x_tmp[54]*udata->dwdp[18])-udata->p[0]*x_tmp[0]*xB_tmp[55]*udata->dwdp[18]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[54]*udata->dwdp[18];
  qBdot_tmp[7] = xB_tmp[0]*(udata->p[0]*x_tmp[0]*udata->dwdp[20]+udata->p[0]*x_tmp[63]*udata->dwdp[18])-xB_tmp[1]*(udata->p[0]*x_tmp[0]*udata->dwdp[20]+udata->p[0]*x_tmp[63]*udata->dwdp[18])-udata->p[0]*x_tmp[0]*xB_tmp[64]*udata->dwdp[18]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[63]*udata->dwdp[18];
  qBdot_tmp[8] = xB_tmp[0]*(udata->p[0]*x_tmp[0]*udata->dwdp[21]+udata->p[0]*x_tmp[72]*udata->dwdp[18])-xB_tmp[1]*(udata->p[0]*x_tmp[0]*udata->dwdp[21]+udata->p[0]*x_tmp[72]*udata->dwdp[18])-udata->p[0]*x_tmp[0]*xB_tmp[73]*udata->dwdp[18]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[72]*udata->dwdp[18];
  qBdot_tmp[9] = xB_tmp[0]*(udata->p[0]*x_tmp[0]*udata->dwdp[22]+udata->p[0]*x_tmp[81]*udata->dwdp[18])-xB_tmp[1]*(udata->p[0]*x_tmp[0]*udata->dwdp[22]+udata->p[0]*x_tmp[81]*udata->dwdp[18])-udata->p[0]*x_tmp[0]*xB_tmp[82]*udata->dwdp[18]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[81]*udata->dwdp[18];
  qBdot_tmp[10] = xB_tmp[0]*(udata->p[0]*x_tmp[0]*udata->dwdp[23]+udata->p[0]*x_tmp[90]*udata->dwdp[18])-xB_tmp[1]*(udata->p[0]*x_tmp[0]*udata->dwdp[23]+udata->p[0]*x_tmp[90]*udata->dwdp[18])-udata->p[0]*x_tmp[0]*xB_tmp[91]*udata->dwdp[18]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[90]*udata->dwdp[18];
  qBdot_tmp[11] = udata->p[0]*xB_tmp[0]*x_tmp[99]*udata->dwdp[18]-udata->p[0]*x_tmp[0]*xB_tmp[100]*udata->dwdp[18]-udata->p[0]*xB_tmp[1]*x_tmp[99]*udata->dwdp[18]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[99]*udata->dwdp[18];
  qBdot_tmp[12] = udata->p[0]*xB_tmp[0]*x_tmp[108]*udata->dwdp[18]-udata->p[0]*x_tmp[0]*xB_tmp[109]*udata->dwdp[18]-udata->p[0]*xB_tmp[1]*x_tmp[108]*udata->dwdp[18]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[108]*udata->dwdp[18];
  qBdot_tmp[13] = udata->p[0]*xB_tmp[0]*x_tmp[117]*udata->dwdp[18]-udata->p[0]*x_tmp[0]*xB_tmp[118]*udata->dwdp[18]-udata->p[0]*xB_tmp[1]*x_tmp[117]*udata->dwdp[18]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[117]*udata->dwdp[18];
  qBdot_tmp[14] = udata->p[0]*xB_tmp[0]*x_tmp[126]*udata->dwdp[18]-udata->p[0]*x_tmp[0]*xB_tmp[127]*udata->dwdp[18]-udata->p[0]*xB_tmp[1]*x_tmp[126]*udata->dwdp[18]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[126]*udata->dwdp[18];
  qBdot_tmp[15] = udata->p[0]*xB_tmp[0]*x_tmp[135]*udata->dwdp[18]-udata->p[0]*x_tmp[0]*xB_tmp[136]*udata->dwdp[18]-udata->p[0]*xB_tmp[1]*x_tmp[135]*udata->dwdp[18]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[135]*udata->dwdp[18];
  qBdot_tmp[16] = udata->p[0]*xB_tmp[0]*x_tmp[144]*udata->dwdp[18]-udata->p[0]*x_tmp[0]*xB_tmp[145]*udata->dwdp[18]-udata->p[0]*xB_tmp[1]*x_tmp[144]*udata->dwdp[18]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[144]*udata->dwdp[18];
  qBdot_tmp[17] = udata->p[0]*xB_tmp[0]*x_tmp[153]*udata->dwdp[18]-udata->p[0]*x_tmp[0]*xB_tmp[154]*udata->dwdp[18]-udata->p[0]*xB_tmp[1]*x_tmp[153]*udata->dwdp[18]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[153]*udata->dwdp[18];

  } break;

  case 9: {
  qBdot_tmp[0] = -udata->p[0]*x_tmp[0]*xB_tmp[1]*udata->dwdp[24]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[0]*udata->dwdp[24];
  qBdot_tmp[1] = xB_tmp[0]*udata->dwdp[24]*(x_tmp[0]+udata->p[0]*x_tmp[9])-xB_tmp[1]*udata->dwdp[24]*(x_tmp[0]+udata->p[0]*x_tmp[9])-udata->p[0]*x_tmp[0]*xB_tmp[10]*udata->dwdp[24]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[9]*udata->dwdp[24];
  qBdot_tmp[2] = udata->p[0]*x_tmp[18]*xB_tmp[0]*udata->dwdp[24]-udata->p[0]*x_tmp[0]*xB_tmp[19]*udata->dwdp[24]-udata->p[0]*x_tmp[18]*xB_tmp[1]*udata->dwdp[24]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[18]*udata->dwdp[24];
  qBdot_tmp[3] = udata->p[0]*x_tmp[27]*xB_tmp[0]*udata->dwdp[24]-udata->p[0]*x_tmp[0]*xB_tmp[28]*udata->dwdp[24]-udata->p[0]*x_tmp[27]*xB_tmp[1]*udata->dwdp[24]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[27]*udata->dwdp[24];
  qBdot_tmp[4] = udata->p[0]*x_tmp[36]*xB_tmp[0]*udata->dwdp[24]-udata->p[0]*x_tmp[0]*xB_tmp[37]*udata->dwdp[24]-udata->p[0]*x_tmp[36]*xB_tmp[1]*udata->dwdp[24]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[36]*udata->dwdp[24];
  qBdot_tmp[5] = udata->p[0]*x_tmp[45]*xB_tmp[0]*udata->dwdp[24]-udata->p[0]*x_tmp[0]*xB_tmp[46]*udata->dwdp[24]-udata->p[0]*x_tmp[45]*xB_tmp[1]*udata->dwdp[24]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[45]*udata->dwdp[24];
  qBdot_tmp[6] = xB_tmp[0]*(udata->p[0]*x_tmp[0]*udata->dwdp[25]+udata->p[0]*x_tmp[54]*udata->dwdp[24])-xB_tmp[1]*(udata->p[0]*x_tmp[0]*udata->dwdp[25]+udata->p[0]*x_tmp[54]*udata->dwdp[24])-udata->p[0]*x_tmp[0]*xB_tmp[55]*udata->dwdp[24]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[54]*udata->dwdp[24];
  qBdot_tmp[7] = xB_tmp[0]*(udata->p[0]*x_tmp[0]*udata->dwdp[26]+udata->p[0]*x_tmp[63]*udata->dwdp[24])-xB_tmp[1]*(udata->p[0]*x_tmp[0]*udata->dwdp[26]+udata->p[0]*x_tmp[63]*udata->dwdp[24])-udata->p[0]*x_tmp[0]*xB_tmp[64]*udata->dwdp[24]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[63]*udata->dwdp[24];
  qBdot_tmp[8] = xB_tmp[0]*(udata->p[0]*x_tmp[0]*udata->dwdp[27]+udata->p[0]*x_tmp[72]*udata->dwdp[24])-xB_tmp[1]*(udata->p[0]*x_tmp[0]*udata->dwdp[27]+udata->p[0]*x_tmp[72]*udata->dwdp[24])-udata->p[0]*x_tmp[0]*xB_tmp[73]*udata->dwdp[24]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[72]*udata->dwdp[24];
  qBdot_tmp[9] = xB_tmp[0]*(udata->p[0]*x_tmp[0]*udata->dwdp[28]+udata->p[0]*x_tmp[81]*udata->dwdp[24])-xB_tmp[1]*(udata->p[0]*x_tmp[0]*udata->dwdp[28]+udata->p[0]*x_tmp[81]*udata->dwdp[24])-udata->p[0]*x_tmp[0]*xB_tmp[82]*udata->dwdp[24]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[81]*udata->dwdp[24];
  qBdot_tmp[10] = xB_tmp[0]*(udata->p[0]*x_tmp[0]*udata->dwdp[29]+udata->p[0]*x_tmp[90]*udata->dwdp[24])-xB_tmp[1]*(udata->p[0]*x_tmp[0]*udata->dwdp[29]+udata->p[0]*x_tmp[90]*udata->dwdp[24])-udata->p[0]*x_tmp[0]*xB_tmp[91]*udata->dwdp[24]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[90]*udata->dwdp[24];
  qBdot_tmp[11] = udata->p[0]*xB_tmp[0]*x_tmp[99]*udata->dwdp[24]-udata->p[0]*x_tmp[0]*xB_tmp[100]*udata->dwdp[24]-udata->p[0]*xB_tmp[1]*x_tmp[99]*udata->dwdp[24]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[99]*udata->dwdp[24];
  qBdot_tmp[12] = udata->p[0]*xB_tmp[0]*x_tmp[108]*udata->dwdp[24]-udata->p[0]*x_tmp[0]*xB_tmp[109]*udata->dwdp[24]-udata->p[0]*xB_tmp[1]*x_tmp[108]*udata->dwdp[24]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[108]*udata->dwdp[24];
  qBdot_tmp[13] = udata->p[0]*xB_tmp[0]*x_tmp[117]*udata->dwdp[24]-udata->p[0]*x_tmp[0]*xB_tmp[118]*udata->dwdp[24]-udata->p[0]*xB_tmp[1]*x_tmp[117]*udata->dwdp[24]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[117]*udata->dwdp[24];
  qBdot_tmp[14] = udata->p[0]*xB_tmp[0]*x_tmp[126]*udata->dwdp[24]-udata->p[0]*x_tmp[0]*xB_tmp[127]*udata->dwdp[24]-udata->p[0]*xB_tmp[1]*x_tmp[126]*udata->dwdp[24]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[126]*udata->dwdp[24];
  qBdot_tmp[15] = udata->p[0]*xB_tmp[0]*x_tmp[135]*udata->dwdp[24]-udata->p[0]*x_tmp[0]*xB_tmp[136]*udata->dwdp[24]-udata->p[0]*xB_tmp[1]*x_tmp[135]*udata->dwdp[24]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[135]*udata->dwdp[24];
  qBdot_tmp[16] = udata->p[0]*xB_tmp[0]*x_tmp[144]*udata->dwdp[24]-udata->p[0]*x_tmp[0]*xB_tmp[145]*udata->dwdp[24]-udata->p[0]*xB_tmp[1]*x_tmp[144]*udata->dwdp[24]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[144]*udata->dwdp[24];
  qBdot_tmp[17] = udata->p[0]*xB_tmp[0]*x_tmp[153]*udata->dwdp[24]-udata->p[0]*x_tmp[0]*xB_tmp[154]*udata->dwdp[24]-udata->p[0]*xB_tmp[1]*x_tmp[153]*udata->dwdp[24]+udata->k[0]*udata->p[0]*x_tmp[0]*udata->w[2]*xB_tmp[153]*udata->dwdp[24];

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


