#pragma once

#include "Operations/Interfaces/IOperation.h"
#include <vector>

class ISeriesOperation : public virtual IOperation
{
public:

  virtual ~ISeriesOperation( ) = default;

protected:

  ISeriesOperation( ) = default;

  virtual std::vector< long long unsigned int > SeriesOrigin( ) const = 0;

  virtual void AddNextSeriesNumber(
    std::vector< long long unsigned int >& ar_series ) const
    noexcept( false ) = 0;

private:
};
