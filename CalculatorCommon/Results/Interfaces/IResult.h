#pragma once

#include "Basic/Interfaces/IPresentable.h"
#include <memory>
#include <string>

class IResult : public IPresentable
{
public:

  virtual ~IResult( ) = default;

protected:

  IResult( ) = default;

private:
};
