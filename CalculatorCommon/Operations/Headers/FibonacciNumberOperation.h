#pragma once

#include "Data/Interfaces/IDataSptr.h"
#include "Operations/Headers/SeriesNumberOperation.h"
#include "Operations/Interfaces/IOperationSptr.h"
#include <memory>

class FibonacciNumberOperation : public virtual SeriesNumberOperation
{
public:

  static IOperationSptr NewSptr( );

  virtual ~FibonacciNumberOperation( ) = default;

  virtual std::string Present( ) const override;

protected:

  FibonacciNumberOperation( );

private:

  virtual std::vector< long long unsigned int >
    SeriesOrigin( ) const override;

  virtual void AddNextSeriesNumberSpecific(
    std::vector< long long unsigned int >& ar_series ) const override;
};
