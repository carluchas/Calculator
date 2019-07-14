#pragma once

#include "Basic/Interfaces/IPresentable.h"
#include <memory>

class IData : public IPresentable
{
public:

  virtual ~IData( ) = default;

protected:

  IData( ) = default;

private:
};

using IDataBaseSptr = std::shared_ptr< IData >;
