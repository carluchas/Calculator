#pragma once

#include "Basic/Interfaces/IValidable.h"
#include "Data/Interfaces/IDataSptr.h"
#include "Operations/Interfaces/IPresentableOperationSptr.h"
#include "Results/Interfaces/IResultSptr.h"

class ICalculation : public IValidable
{
public:

  ~ICalculation() noexcept override = default;

  virtual const IDataSptr& Data() const noexcept = 0;

  virtual const IPresentableOperationSptr& Operation() const noexcept = 0;

  virtual const IResultSptr& Result() const noexcept = 0;

protected:

  ICalculation() noexcept = default;
};
