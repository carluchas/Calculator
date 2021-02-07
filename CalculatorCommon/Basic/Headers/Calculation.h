#pragma once

#include "Basic/Interfaces/ICalculation.h"
#include "Basic/Interfaces/ICalculationSptr.h"
#include <string>

class Calculation : public ICalculation
{
  class ConstructionKey {};

public:

  static ICalculationSptr NewSptr(
    const IDataSptr& arsp_data,
    const IPresentableOperationSptr& arsp_operation,
    const IResultSptr& arsp_result) noexcept;

  explicit Calculation(const ConstructionKey&,
    const IDataSptr& arsp_data,
    const IPresentableOperationSptr& arsp_operation,
    const IResultSptr& arsp_result) noexcept;

  ~Calculation() noexcept override = default;

  bool IsValid() const noexcept override;

  const IDataSptr& Data() const noexcept override;

  const IPresentableOperationSptr& Operation() const noexcept override;

  const IResultSptr& Result() const noexcept override;

private:

  IDataSptr _sp_data;

  IPresentableOperationSptr _sp_operation;

  IResultSptr _sp_result;

  Calculation() noexcept = delete;

  explicit Calculation(const Calculation& ar_presenter) noexcept = default;

  Calculation& operator = (const Calculation& ar_presenter) noexcept = default;
};
