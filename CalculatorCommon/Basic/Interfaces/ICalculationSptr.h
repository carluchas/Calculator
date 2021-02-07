#pragma once

#include <memory>

class ICalculation;

using ICalculationSptr = std::shared_ptr< ICalculation >;
