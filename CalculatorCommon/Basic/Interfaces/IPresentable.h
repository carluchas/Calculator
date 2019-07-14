#pragma once

#include <string>

class IPresentable
{
public:

  virtual ~IPresentable( ) = default;

  virtual std::string Present( ) = 0;

protected:

  IPresentable( ) = default;

private:
};
