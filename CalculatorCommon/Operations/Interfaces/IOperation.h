#pragma once

#include "Basic/Interfaces/IPresentable.h"
#include "Data/Interfaces/IDataSptr.h"
#include "Results/Interfaces/IResultSptr.h"
#include <memory>

class IOperation : public IPresentable
{
public:

  virtual ~IOperation( ) = default;

  virtual IResultSptr Execute( IDataSptr asp_data ) = 0;

protected:

  IOperation( ) = default;

private:
};
