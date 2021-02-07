#pragma once

#include "Data/Interfaces/IDataSptr.h"
#include "Operations/Headers/SeriesOperation.h"
#include "Operations/Interfaces/IOperationSptr.h"
#include <memory>

class FibonacciNumberOperation : public SeriesOperation
{
  class ConstructionKey {};

public:

  static IOperationSptr NewSptr() noexcept;

  explicit FibonacciNumberOperation(const ConstructionKey&) noexcept;

  ~FibonacciNumberOperation() noexcept override = default;

  std::string Present() const noexcept override;

protected:

  FibonacciNumberOperation() noexcept = default;

  std::vector< unsigned long long >
    SeriesOrigin() const noexcept override;

  void AddNextSeriesNumberSpecific(
    std::vector< unsigned long long >& ar_series) const noexcept(false) override;

private:

  explicit FibonacciNumberOperation(
    const FibonacciNumberOperation& ar_operation) noexcept = default;

  FibonacciNumberOperation& operator = (
    const FibonacciNumberOperation& ar_operation) noexcept = default;
};
