#pragma once

#include "Data/Interfaces/IDataSptr.h"
#include "Operations/Headers/PrimeNumberOperation.h"
#include "Operations/Interfaces/IOperationSptr.h"
#include <memory>

class EfficientPrimeNumberOperation : public virtual PrimeNumberOperation
{
public:

  static IOperationSptr NewSptr( ) noexcept;

  virtual ~EfficientPrimeNumberOperation( ) noexcept = default;

  virtual std::string Present( ) const noexcept override;

protected:

  EfficientPrimeNumberOperation( ) noexcept;

  virtual void AddNextSeriesNumberSpecific(
    std::vector< unsigned long long >& ar_serie ) const noexcept( false ) override;

private:

  explicit EfficientPrimeNumberOperation( const EfficientPrimeNumberOperation& ar_operation ) noexcept = default;

  EfficientPrimeNumberOperation& operator = ( const EfficientPrimeNumberOperation& ar_operation ) noexcept = default;
};
