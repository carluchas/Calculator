#pragma once

#include "Basic/Interfaces/IPresentable.h"

class IPresentableOperation : public IPresentable
{
public:

  ~IPresentableOperation() noexcept override = default;

protected:

  IPresentableOperation() noexcept = default;
};
