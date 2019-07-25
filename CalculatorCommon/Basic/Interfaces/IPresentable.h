#pragma once

#include <string>

class IPresentable
{
public:

  virtual ~IPresentable( ) = default;

  virtual std::string Present( ) const = 0;

protected:

  IPresentable( ) = default;

private:
};
