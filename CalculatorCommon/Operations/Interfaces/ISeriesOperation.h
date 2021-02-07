#pragma once

#include "Operations/Interfaces/IOperation.h"
#include <vector>

class ISeriesOperation : public IOperation
{
public:

  ~ISeriesOperation() noexcept override = default;

protected:

  ISeriesOperation() noexcept = default;

  virtual std::vector< unsigned long long > SeriesOrigin() const
    noexcept = 0;

  virtual void AddNextSeriesNumber(
    std::vector< unsigned long long >& ar_series) const
    noexcept(false) = 0;
};
