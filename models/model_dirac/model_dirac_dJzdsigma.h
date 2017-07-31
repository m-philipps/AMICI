#ifndef _am_model_dirac_dJzdsigma_h
#define _am_model_dirac_dJzdsigma_h

#include <sundials/sundials_types.h>
#include <sundials/sundials_nvector.h>
#include <sundials/sundials_sparse.h>
#include <sundials/sundials_direct.h>

class UserData;
class ReturnData;
class TempData;
class ExpData;

int dJzdsigma_model_dirac(realtype t, int ie, N_Vector x, void *user_data, TempData *tdata, const ExpData *edata, ReturnData *rdata);


#endif /* _am_model_dirac_dJzdsigma_h */