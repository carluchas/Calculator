#pragma once

#include "Data/Interfaces/IDataSptr.h"
#include "Operations/Interfaces/IOperation.h"
#include "Operations/Interfaces/IOperationSptr.h"
#include "Results/Interfaces/IResult.h"
#include <memory>

class PrimeNumberOperation : public virtual IOperation
{
public:

  static IOperationSptr NewSptr( );

  virtual ~PrimeNumberOperation( ) = default;

  virtual std::string Present( ) override;

  virtual IResultSptr Execute( IDataSptr asp_data ) override;

protected:

  PrimeNumberOperation( );

private:
};
