#pragma once

#include "Basic/Interfaces/ICalculationSptr.h"
#include "Data/Interfaces/IDataSptr.h"
#include "Operations/Interfaces/IOperationSptr.h"
#include <vector>

class IResultsExplorer
{
public:

  virtual ~IResultsExplorer() noexcept = default;

  virtual void
    Present(const std::vector<ICalculationSptr>& ar_results) const noexcept = 0;

protected:

  IResultsExplorer() noexcept = default;

private:

  explicit IResultsExplorer(const IResultsExplorer& ar_operation)
    noexcept = delete;

  IResultsExplorer& operator = (const IResultsExplorer& ar_operation)
    noexcept = delete;
};
