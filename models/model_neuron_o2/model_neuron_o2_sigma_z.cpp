
#include <include/symbolic_functions.h>
#include <string.h>
#include <include/udata.h>
#include <include/tdata.h>
#include "model_neuron_o2_w.h"

int sigma_z_model_neuron_o2(realtype t, int ie, void *user_data, TempData *tdata) {
int status = 0;
UserData *udata = (UserData*) user_data;
memset(tdata->sigmaz,0,sizeof(realtype)*5);
  tdata->sigmaz[0] = 1.0;
return(status);

}

