#pragma once

#include "Basic/Interfaces/IPresentable.h"
#include "Data/Interfaces/IDataSptr.h"
#include "Results/Interfaces/IResultSptr.h"
#include <memory>

class IOperation : public IPresentable
{
public:

  virtual ~IOperation( ) noexcept = default;

  virtual IResultSptr Execute( IDataSptr asp_data ) const noexcept( false ) = 0;

protected:

  IOperation( ) noexcept = default;

private:
};
