#ifndef _am_model_jakstat_adjoint_dJrzdsigma_h
#define _am_model_jakstat_adjoint_dJrzdsigma_h

#include <sundials/sundials_types.h>
#include <sundials/sundials_nvector.h>
#include <sundials/sundials_sparse.h>
#include <sundials/sundials_direct.h>

class UserData;
class ReturnData;
class TempData;
class ExpData;

int dJrzdsigma_model_jakstat_adjoint(realtype t, int ie, N_Vector x, void *user_data, TempData *tdata, const ExpData *edata, ReturnData *rdata);


#endif /* _am_model_jakstat_adjoint_dJrzdsigma_h */