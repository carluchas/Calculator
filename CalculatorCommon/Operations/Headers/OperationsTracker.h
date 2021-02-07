#pragma once

#include "Data/Interfaces/IDataSptr.h"
#include "Operations//Interfaces/IOperationsTrackerSptr.h"
#include "Operations/Interfaces/IOperationSptr.h"
#include "Operations/Interfaces/IOperationsTracker.h"
#include "Results/Interfaces/IResultSptr.h"
#include <vector>

class OperationsTracker : public IOperationsTracker
{
  class ConstructionKey {};

public:

  static IOperationsTrackerSptr NewSptr() noexcept;

  explicit OperationsTracker(const ConstructionKey&) noexcept;

  ~OperationsTracker() noexcept override = default;

  std::vector<ICalculationSptr>
    Execute(const std::vector<IOperationSptr>& ar_operations,
      IDataSptr asp_data) const noexcept final;

protected:

  OperationsTracker() noexcept = default;

private:

  explicit OperationsTracker(const OperationsTracker& ar_operation)
    noexcept = delete;

  OperationsTracker& operator = (const OperationsTracker& ar_operation)
    noexcept = delete;
};
