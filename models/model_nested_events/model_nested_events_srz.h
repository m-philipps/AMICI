#ifndef _am_model_nested_events_srz_h
#define _am_model_nested_events_srz_h

#include <sundials/sundials_types.h>
#include <sundials/sundials_nvector.h>
#include <sundials/sundials_sparse.h>
#include <sundials/sundials_direct.h>

class UserData;
class ReturnData;
class TempData;
class ExpData;

int srz_model_nested_events(realtype t, int ie, N_Vector x, N_Vector *sx, TempData *tdata, ReturnData *rdata);


#endif /* _am_model_nested_events_srz_h */