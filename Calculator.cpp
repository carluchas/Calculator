// Calculator.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "Basic/Headers/easylogging++.h"
#include "Data/Headers/IntervalData.h"
#include "Data/Interfaces/IDataSptr.h"
#include "Operations/Headers/EfficientPrimeNumberOperation.h"
#include "Operations/Headers/FibonacciNumberOperation.h"
#include "Operations/Headers/OperationException.h"
#include "Operations/Headers/OperationsTracker.h"
#include "Operations/Headers/PrimeNumberOperation.h"
#include "Results/Headers/ResultsExplorer.h"
#include <iostream>

INITIALIZE_EASYLOGGINGPP

int main()
{
  el::Configurations defaultConf;
  defaultConf.setToDefault();

  // Values are always std::string
  defaultConf.set(el::Level::Info,
    el::ConfigurationType::Format, "%msg");

  // Default logger uses default configurations
  el::Loggers::reconfigureLogger("default", defaultConf);

  LOG(INFO) << "Hello World!\n";

  unsigned int first = 1;
  unsigned long size = 3;

  LOG(INFO) << "First series number to show: ";
  scanf_s("%d", &first);

  LOG(INFO) << "Number of series numbers to show: ";
  scanf_s("%d", &size);

  auto sp_data = IDataSptr(IntervalData::NewSptr(first, size));

  std::vector<IOperationSptr> operations{
    PrimeNumberOperation::NewSptr(),
    EfficientPrimeNumberOperation::NewSptr(),
    FibonacciNumberOperation::NewSptr() };

  ResultsExplorer::NewSptr()->
    Present(OperationsTracker::NewSptr()->Execute(operations, sp_data));
}