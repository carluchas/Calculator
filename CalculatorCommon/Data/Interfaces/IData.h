#pragma once

#include "Basic/Interfaces/IPresentable.h"
#include "Basic/Interfaces/IValidable.h"
#include <memory>

class IData : public IValidable, public IPresentable
{
public:

  virtual ~IData( ) = default;

protected:

  IData( ) = default;

private:
};

using IDataBaseSptr = std::shared_ptr< IData >;
