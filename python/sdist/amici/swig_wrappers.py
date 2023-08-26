"""Convenience wrappers for the swig interface"""
import logging
import sys
import warnings
from contextlib import contextmanager, suppress
from typing import Any, Dict, List, Optional, Sequence, Union

import amici
import amici.amici as amici_swig

from . import numpy
from .logging import get_logger

logger = get_logger(__name__, log_level=logging.DEBUG)


__all__ = [
    "runAmiciSimulation",
    "runAmiciSimulations",
    "ExpData",
    "readSolverSettingsFromHDF5",
    "writeSolverSettingsToHDF5",
    "set_model_settings",
    "get_model_settings",
    "AmiciModel",
    "AmiciSolver",
    "AmiciExpData",
    "AmiciReturnData",
    "AmiciExpDataVector",
]

AmiciModel = Union["amici.Model", "amici.ModelPtr"]
AmiciSolver = Union["amici.Solver", "amici.SolverPtr"]
AmiciExpData = Union["amici.ExpData", "amici.ExpDataPtr"]
AmiciReturnData = Union["amici.ReturnData", "amici.ReturnDataPtr"]
AmiciExpDataVector = Union["amici.ExpDataPtrVector", Sequence[AmiciExpData]]


try:
    from wurlitzer import sys_pipes
except ModuleNotFoundError:
    sys_pipes = suppress


@contextmanager
def _capture_cstdout():
    """Redirect C/C++ stdout to python stdout if python stdout is redirected,
    e.g. in ipython notebook"""
    if sys.stdout == sys.__stdout__:
        yield
    else:
        with sys_pipes():
            yield


def _get_ptr(
    obj: Union[AmiciModel, AmiciExpData, AmiciSolver, AmiciReturnData]
) -> Union[
    "amici_swig.Model",
    "amici_swig.ExpData",
    "amici_swig.Solver",
    "amici_swig.ReturnData",
]:
    """
    Convenience wrapper that returns the smart pointer pointee, if applicable

    :param obj:
        Potential smart pointer

    :returns:
        Non-smart pointer
    """
    if isinstance(
        obj,
        (
            amici_swig.ModelPtr,
            amici_swig.ExpDataPtr,
            amici_swig.SolverPtr,
            amici_swig.ReturnDataPtr,
        ),
    ):
        return obj.get()
    return obj


def runAmiciSimulation(
    model: AmiciModel, solver: AmiciSolver, edata: Optional[AmiciExpData] = None
) -> "numpy.ReturnDataView":
    """
    Convenience wrapper around :py:func:`amici.amici.runAmiciSimulation`
    (generated by swig)

    :param model:
        Model instance

    :param solver:
        Solver instance, must be generated from
        :py:meth:`amici.amici.Model.getSolver`

    :param edata:
        ExpData instance (optional)

    :returns:
        ReturnData object with simulation results
    """
    if (
        model.ne > 0
        and solver.getSensitivityMethod() == amici_swig.SensitivityMethod.adjoint
        and solver.getSensitivityOrder() == amici_swig.SensitivityOrder.first
    ):
        warnings.warn(
            "Adjoint sensitivity analysis for models with discontinuous right hand sides (events/piecewise functions) has not been thoroughly tested."
            "Sensitivities might be wrong. Tracked at https://github.com/AMICI-dev/AMICI/issues/18. "
            "Adjoint sensitivity analysis may work if the location of the discontinuity is not parameter-dependent, but we still recommend testing accuracy of gradients."
        )

    with _capture_cstdout():
        rdata = amici_swig.runAmiciSimulation(
            _get_ptr(solver), _get_ptr(edata), _get_ptr(model)
        )
    _log_simulation(rdata)
    if solver.getReturnDataReportingMode() == amici.RDataReporting.full:
        _ids_and_names_to_rdata(rdata, model)
    return numpy.ReturnDataView(rdata)


def ExpData(*args) -> "amici_swig.ExpData":
    """
    Convenience wrapper for :py:class:`amici.amici.ExpData` constructors

    :param args: arguments

    :returns: ExpData Instance
    """
    if isinstance(args[0], numpy.ReturnDataView):
        return amici_swig.ExpData(_get_ptr(args[0]["ptr"]), *args[1:])
    elif isinstance(args[0], (amici_swig.ExpData, amici_swig.ExpDataPtr)):
        # the *args[:1] should be empty, but by the time you read this,
        # the constructor signature may have changed, and you are glad this
        # wrapper did not break.
        return amici_swig.ExpData(_get_ptr(args[0]), *args[1:])
    elif isinstance(args[0], (amici_swig.Model, amici_swig.ModelPtr)):
        return amici_swig.ExpData(_get_ptr(args[0]))
    else:
        return amici_swig.ExpData(*args)


def runAmiciSimulations(
    model: AmiciModel,
    solver: AmiciSolver,
    edata_list: AmiciExpDataVector,
    failfast: bool = True,
    num_threads: int = 1,
) -> List["numpy.ReturnDataView"]:
    """
    Convenience wrapper for loops of amici.runAmiciSimulation

    :param model: Model instance
    :param solver: Solver instance, must be generated from Model.getSolver()
    :param edata_list: list of ExpData instances
    :param failfast: returns as soon as an integration failure is encountered
    :param num_threads: number of threads to use (only used if compiled
        with openmp)

    :returns: list of simulation results
    """
    if (
        model.ne > 0
        and solver.getSensitivityMethod() == amici_swig.SensitivityMethod.adjoint
        and solver.getSensitivityOrder() == amici_swig.SensitivityOrder.first
    ):
        warnings.warn(
            "Adjoint sensitivity analysis for models with discontinuous right hand sides (events/piecewise functions) has not been thoroughly tested. "
            "Sensitivities might be wrong. Tracked at https://github.com/AMICI-dev/AMICI/issues/18. "
            "Adjoint sensitivity analysis may work if the location of the discontinuity is not parameter-dependent, but we still recommend testing accuracy of gradients."
        )

    with _capture_cstdout():
        edata_ptr_vector = amici_swig.ExpDataPtrVector(edata_list)
        rdata_ptr_list = amici_swig.runAmiciSimulations(
            _get_ptr(solver),
            edata_ptr_vector,
            _get_ptr(model),
            failfast,
            num_threads,
        )
    for rdata in rdata_ptr_list:
        _log_simulation(rdata)
        if solver.getReturnDataReportingMode() == amici.RDataReporting.full:
            _ids_and_names_to_rdata(rdata, model)

    return [numpy.ReturnDataView(r) for r in rdata_ptr_list]


def readSolverSettingsFromHDF5(
    file: str, solver: AmiciSolver, location: Optional[str] = "solverSettings"
) -> None:
    """
    Convenience wrapper for :py:func:`amici.readSolverSettingsFromHDF5`

    :param file: hdf5 filename
    :param solver: Solver instance to which settings will be transferred
    :param location: location of solver settings in hdf5 file
    """
    amici_swig.readSolverSettingsFromHDF5(file, _get_ptr(solver), location)


def writeSolverSettingsToHDF5(
    solver: AmiciSolver,
    file: Union[str, object],
    location: Optional[str] = "solverSettings",
) -> None:
    """
    Convenience wrapper for :py:func:`amici.amici.writeSolverSettingsToHDF5`

    :param file: hdf5 filename, can also be an object created by
        :py:func:`amici.amici.createOrOpenForWriting`
    :param solver: Solver instance from which settings will be stored
    :param location: location of solver settings in hdf5 file
    """
    amici_swig.writeSolverSettingsToHDF5(_get_ptr(solver), file, location)


# Values are suffixes of `get[...]` and `set[...]` `amici.Model` methods.
# If either the getter or setter is not named with this pattern, then the value
# is a tuple where the first and second elements are the getter and setter
# methods, respectively.
model_instance_settings = [
    # `setParameter{List,Scale}` will clear initial state sensitivities, so
    #  `setParameter{List,Scale}` has to be called first.
    "ParameterList",
    "ParameterScale",  # getter returns a SWIG object
    "AddSigmaResiduals",
    "AlwaysCheckFinite",
    "FixedParameters",
    "InitialStates",
    ("getInitialStateSensitivities", "setUnscaledInitialStateSensitivities"),
    "MinimumSigmaResiduals",
    ("nMaxEvent", "setNMaxEvent"),
    "Parameters",
    "ReinitializationStateIdxs",
    "ReinitializeFixedParameterInitialStates",
    "StateIsNonNegative",
    "SteadyStateComputationMode",
    "SteadyStateSensitivityMode",
    ("t0", "setT0"),
    "Timepoints",
]


def get_model_settings(
    model: AmiciModel,
) -> Dict[str, Any]:
    """Get model settings that are set independently of the compiled model.

    :param model: The AMICI model instance.

    :returns: Keys are AMICI model attributes, values are attribute values.
    """
    settings = {}
    for setting in model_instance_settings:
        getter = setting[0] if isinstance(setting, tuple) else f"get{setting}"

        if getter == "getInitialStates" and not model.hasCustomInitialStates():
            settings[setting] = []
            continue
        if (
            getter == "getInitialStateSensitivities"
            and not model.hasCustomInitialStateSensitivities()
        ):
            settings[setting] = []
            continue

        settings[setting] = getattr(model, getter)()
        # TODO `amici.Model.getParameterScale` returns a SWIG object instead
        # of a Python list/tuple.
        if setting == "ParameterScale":
            settings[setting] = tuple(settings[setting])
    return settings


def set_model_settings(
    model: AmiciModel,
    settings: Dict[str, Any],
) -> None:
    """Set model settings.

    :param model: The AMICI model instance.
    :param settings: Keys are callable attributes (setters) of an AMICI model,
        values are provided to the setters.
    """
    for setting, value in settings.items():
        setter = setting[1] if isinstance(setting, tuple) else f"set{setting}"
        getattr(model, setter)(value)


def _log_simulation(rdata: amici_swig.ReturnData):
    """Extension warnings to Python logging."""
    amici_severity_to_logging = {
        amici_swig.LogSeverity_debug: logging.DEBUG,
        amici_swig.LogSeverity_warning: logging.WARNING,
        amici_swig.LogSeverity_error: logging.ERROR,
    }
    for msg in rdata.messages:
        condition = f"[{rdata.id}]" if rdata.id else ""
        logger.log(
            amici_severity_to_logging[msg.severity],
            f"{condition}[{msg.identifier}] {msg.message}",
        )


def _ids_and_names_to_rdata(rdata: amici_swig.ReturnData, model: amici_swig.Model):
    """Copy entity IDs and names from a Model to ReturnData."""
    for entity_type in (
        "State",
        "Observable",
        "Expression",
        "Parameter",
        "FixedParameter",
    ):
        for name_or_id in ("Ids", "Names"):
            names_or_ids = getattr(model, f"get{entity_type}{name_or_id}")()
            setattr(
                rdata,
                f"{entity_type.lower()}_{name_or_id.lower()}",
                names_or_ids,
            )
    rdata.state_ids_solver = model.getStateIdsSolver()
    rdata.state_names_solver = model.getStateNamesSolver()