#include "Basic/Headers/Calculation.h"
#include "Data/Interfaces/IData.h"
#include "Results/Interfaces/IResult.h"

ICalculationSptr Calculation::NewSptr(
  const IDataSptr& arsp_data,
  const IPresentableOperationSptr& arsp_operation,
  const IResultSptr& arsp_result) noexcept
{
  return std::make_shared<Calculation>(
    ConstructionKey(), arsp_data, arsp_operation, arsp_result);
}

Calculation::Calculation(
  const ConstructionKey&,
  const IDataSptr& arsp_data,
  const IPresentableOperationSptr& arsp_operation,
  const IResultSptr& arsp_result) noexcept :
  _sp_data(arsp_data),
  _sp_operation(arsp_operation),
  _sp_result(arsp_result)
{
}

bool Calculation::IsValid() const noexcept
{
  return _sp_data && _sp_operation && _sp_result &&
    _sp_data->IsValid() && _sp_result->IsValid();
}

const IDataSptr& Calculation::Data() const noexcept
{
  return _sp_data;
}

const IPresentableOperationSptr& Calculation::Operation() const noexcept
{
  return _sp_operation;
}

const IResultSptr& Calculation::Result() const noexcept
{
  return _sp_result;
}