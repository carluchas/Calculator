#pragma once

#include "Data/Interfaces/IDataSptr.h"
#include "Operations/Headers/SeriesOperation.h"
#include "Operations/Interfaces/IOperationSptr.h"
#include <memory>

class PrimeNumberOperation : public virtual SeriesOperation
{
public:

  static IOperationSptr NewSptr( ) noexcept;

  virtual ~PrimeNumberOperation( ) noexcept = default;

  virtual std::string Present( ) const noexcept override;

protected:

  PrimeNumberOperation( ) noexcept;

  virtual std::vector< unsigned long long >
    SeriesOrigin( ) const noexcept override;

  virtual void AddNextSeriesNumberSpecific(
    std::vector< unsigned long long >& ar_serie )
    const noexcept( false ) override;

private:

  explicit PrimeNumberOperation( const PrimeNumberOperation& ar_operation )
    noexcept = default;

  PrimeNumberOperation& operator = ( const PrimeNumberOperation& ar_operation )
    noexcept = default;
};
