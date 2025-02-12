
#include "amici/symbolic_functions.h"
#include "amici/defines.h" //realtype definition
typedef amici::realtype realtype;
#include <cmath> 

using namespace amici;

namespace amici {

namespace model_model_jakstat_adjoint_o2{

void dwdx_model_jakstat_adjoint_o2(realtype *dwdx, const realtype t, const realtype *x, const realtype *p, const realtype *k, const realtype *h, const realtype *w, const realtype *tcl, const realtype *spl) {
  dwdx[0] = x[1]*2.0;
  dwdx[1] = 2.0;
}

} // namespace model_model_jakstat_adjoint_o2

} // namespace amici

