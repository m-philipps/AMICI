#ifndef _am_model_neuron_o2_drzdp_h
#define _am_model_neuron_o2_drzdp_h

#include <sundials/sundials_types.h>
#include <sundials/sundials_nvector.h>
#include <sundials/sundials_sparse.h>
#include <sundials/sundials_direct.h>

class UserData;
class ReturnData;
class TempData;
class ExpData;

int drzdp_model_neuron_o2(realtype t, int ie, N_Vector x, void *user_data, TempData *tdata);


#endif /* _am_model_neuron_o2_drzdp_h */