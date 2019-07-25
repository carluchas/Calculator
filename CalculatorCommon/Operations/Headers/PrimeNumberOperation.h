#pragma once

#include "Data/Interfaces/IDataSptr.h"
#include "Operations/Headers/SeriesNumberOperation.h"
#include "Operations/Interfaces/IOperationSptr.h"
#include <memory>

class PrimeNumberOperation : public virtual SeriesNumberOperation
{
public:

  static IOperationSptr NewSptr( );

  virtual ~PrimeNumberOperation( ) = default;

  virtual std::string Present( ) const override;

protected:

  PrimeNumberOperation( );

private:

  virtual std::vector< long long unsigned int >
    SeriesOrigin( ) const override;

  virtual void AddNextSeriesNumberSpecific(
    std::vector< long long unsigned int >& ar_serie ) const override;
};
