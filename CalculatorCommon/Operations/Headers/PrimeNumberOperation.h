#pragma once

#include "Data/Interfaces/IDataSptr.h"
#include "Operations/Headers/SeriesOperation.h"
#include "Operations/Interfaces/IOperationSptr.h"
#include <memory>

class PrimeNumberOperation : public SeriesOperation
{
  class ConstructionKey {};

public:

  static IOperationSptr NewSptr() noexcept;

  explicit PrimeNumberOperation(const ConstructionKey&) noexcept;

  ~PrimeNumberOperation() noexcept override = default;

  std::string Present() const noexcept override;

protected:

  PrimeNumberOperation() noexcept = default;

  std::vector< unsigned long long >
    SeriesOrigin() const noexcept override;

  void AddNextSeriesNumberSpecific(
    std::vector< unsigned long long >& ar_serie)
    const noexcept(false) override;

private:

  explicit PrimeNumberOperation(const PrimeNumberOperation& ar_operation)
    noexcept = default;

  PrimeNumberOperation& operator = (const PrimeNumberOperation& ar_operation)
    noexcept = default;
};
