#pragma once

#include "Data/Interfaces/IDataSptr.h"
#include "Operations/Headers/SeriesOperation.h"
#include "Operations/Interfaces/IOperationSptr.h"
#include <memory>

class FibonacciNumberOperation : public virtual SeriesOperation
{
public:

  static IOperationSptr NewSptr( ) noexcept;

  virtual ~FibonacciNumberOperation( ) noexcept = default;

  virtual std::string Present( ) const noexcept override;

protected:

  FibonacciNumberOperation( ) noexcept;

  virtual std::vector< unsigned long long >
    SeriesOrigin( ) const noexcept override;

  virtual void AddNextSeriesNumberSpecific(
    std::vector< unsigned long long >& ar_series ) const noexcept( false ) override;

private:

  explicit FibonacciNumberOperation( const FibonacciNumberOperation& ar_operation ) noexcept = default;

  FibonacciNumberOperation& operator = ( const FibonacciNumberOperation& ar_operation ) noexcept = default;
};
