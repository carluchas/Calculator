#pragma once

#include "Data/Interfaces/IDataSptr.h"
#include "Operations/Headers/PrimeNumberOperation.h"
#include "Operations/Interfaces/IOperationSptr.h"
#include <memory>

class EfficientPrimeNumberOperation : public PrimeNumberOperation
{
  class ConstructionKey {};

public:

  static IOperationSptr NewSptr() noexcept;

  explicit EfficientPrimeNumberOperation(const ConstructionKey&) noexcept;

  ~EfficientPrimeNumberOperation() noexcept override = default;

  std::string Present() const noexcept override;

protected:

  EfficientPrimeNumberOperation() noexcept = default;

  void AddNextSeriesNumberSpecific(
    std::vector< unsigned long long >& ar_serie) const noexcept(false) override;

private:

  explicit EfficientPrimeNumberOperation(
    const EfficientPrimeNumberOperation& ar_operation) noexcept = default;

  EfficientPrimeNumberOperation& operator = (
    const EfficientPrimeNumberOperation& ar_operation) noexcept = default;
};
