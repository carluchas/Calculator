#pragma once

#include "Basic/Interfaces/IPresentable.h"
#include "Basic/Interfaces/IValidable.h"
#include <memory>

class IData : public IValidable, public IPresentable
{
public:

  virtual ~IData( ) noexcept = default;

protected:

  IData( ) noexcept = default;

private:
};