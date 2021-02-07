#pragma once

#include "Basic/Interfaces/ICalculationSptr.h"
#include "Data/Interfaces/IDataSptr.h"
#include "Operations/Interfaces/IOperationSptr.h"
#include <vector>

class IOperationsTracker
{
public:

  virtual ~IOperationsTracker() noexcept = default;

  virtual std::vector<ICalculationSptr>
    Execute(const std::vector<IOperationSptr>& ar_operations,
      IDataSptr asp_data) const noexcept = 0;

protected:

  IOperationsTracker() noexcept = default;

private:

  explicit IOperationsTracker(const IOperationsTracker& ar_operation)
    noexcept = delete;

  IOperationsTracker& operator = (const IOperationsTracker& ar_operation)
    noexcept = delete;
};
