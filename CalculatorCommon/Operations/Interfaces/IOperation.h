#pragma once

#include "Data/Interfaces/IDataSptr.h"
#include "Operations/Interfaces/IPresentableOperation.h"
#include "Results/Interfaces/IResultSptr.h"
#include <memory>

class IOperation : public IPresentableOperation
{
public:

  ~IOperation() noexcept override = default;

  virtual IResultSptr Execute(IDataSptr asp_data) const noexcept(false) = 0;

protected:

  IOperation() noexcept = default;
};
