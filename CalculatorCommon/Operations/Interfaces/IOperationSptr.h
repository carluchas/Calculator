#pragma once

#include <memory>

class IOperation;

using IOperationSptr = std::shared_ptr< IOperation >;
