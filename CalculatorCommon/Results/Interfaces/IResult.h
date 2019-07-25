#pragma once

#include "Basic/Interfaces/IPresentable.h"
#include <memory>
#include <string>

class IResult : public IPresentable
{
public:

  virtual ~IResult( ) noexcept = default;

protected:

  IResult( ) noexcept = default;

private:
};
