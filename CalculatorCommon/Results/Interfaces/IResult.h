#pragma once

#include "Basic/Interfaces/IPresentable.h"
#include "Basic/Interfaces/IValidable.h"
#include <memory>
#include <string>

class IResult : public IValidable, public IPresentable
{
public:

  virtual ~IResult( ) noexcept = default;

protected:

  IResult( ) noexcept = default;

private:
};
