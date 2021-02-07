#pragma once

#include "Results//Interfaces/IResultsExplorerSptr.h"
#include "Results/Interfaces/IResultsExplorer.h"
#include <vector>

class ResultsExplorer : public IResultsExplorer
{
  class ConstructionKey {};

public:

  static IResultsExplorerSptr NewSptr() noexcept;

  explicit ResultsExplorer(const ConstructionKey&) noexcept;

  ~ResultsExplorer() noexcept override = default;

  void Present(
    const std::vector<ICalculationSptr>& ar_calculations) const noexcept override;

protected:

  ResultsExplorer() noexcept = default;

private:

  explicit ResultsExplorer(const ResultsExplorer& ar_operation)
    noexcept = delete;

  ResultsExplorer& operator = (const ResultsExplorer& ar_operation)
    noexcept = delete;
};
