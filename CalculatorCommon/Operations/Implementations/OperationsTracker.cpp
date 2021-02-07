#include "Basic/Headers/Calculation.h"
#include "Basic/Headers/easylogging++.h"
#include "Data/Headers/IntervalData.h"
#include "Operations/Headers/OperationException.h"
#include "Operations/Headers/OperationsTracker.h"
#include "Operations/Interfaces/IOperation.h"
#include "Results/Headers/ListResult.h"
#include "Results/Implementations/ListResult.cpp"
#include <stdexcept>
#include <vector>

IOperationsTrackerSptr OperationsTracker::NewSptr() noexcept
{
  return std::make_shared<OperationsTracker>(ConstructionKey());
}

OperationsTracker::OperationsTracker(const ConstructionKey&) noexcept
{
}

std::vector<ICalculationSptr> OperationsTracker::Execute(
  const std::vector<IOperationSptr>& ar_operations, IDataSptr asp_data)
  const noexcept
{
  std::vector<ICalculationSptr> to_return;

  for (const auto& sp_operation : ar_operations)
  {
    if (sp_operation)
    {
      try
      {
        auto sp_result = sp_operation->Execute(asp_data);

        to_return.emplace_back(
          Calculation::NewSptr(asp_data, sp_operation, sp_result));
      }
      catch (const OperationException& ar_exception)
      {
        LOG(INFO) << std::endl;
        LOG(INFO) << "Error processing " + sp_operation->Present() + ": " +
          ar_exception.what() + " in " + ar_exception.where();
        LOG(INFO) << std::endl;
      }
    }
  }

  return to_return;
}