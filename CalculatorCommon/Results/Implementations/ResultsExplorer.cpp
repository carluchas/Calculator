#include "Basic/Headers/easylogging++.h"
#include "Basic/Interfaces/ICalculation.h"
#include "Data/Interfaces/IData.h"
#include "Operations/Interfaces/IOperation.h"
#include "Results/Headers/ListResult.h"
#include "Results/Headers/ResultsExplorer.h"
#include "Results/Implementations/ListResult.cpp"
#include <stdexcept>
#include <vector>

IResultsExplorerSptr ResultsExplorer::NewSptr() noexcept
{
  return std::make_shared<ResultsExplorer>(ConstructionKey());
}

ResultsExplorer::ResultsExplorer(const ConstructionKey&) noexcept
{
}

void ResultsExplorer::Present(
  const std::vector<ICalculationSptr>& ar_calculations) const noexcept
{
  for (const auto& sp_calculation : ar_calculations)
  {
    if (sp_calculation && sp_calculation->IsValid())
    {
      LOG(INFO) << std::endl;
      LOG(INFO) << sp_calculation->Operation()->Present() + " " +
        sp_calculation->Data()->Present() + ": " +
        sp_calculation->Result()->Present();
      LOG(INFO) << std::endl;
    }
    else
    {
      LOG(INFO) << std::endl;
      LOG(INFO) << "Invalid calculation, it was not possible explore its result.";
      LOG(INFO) << std::endl;
    }
  }
}