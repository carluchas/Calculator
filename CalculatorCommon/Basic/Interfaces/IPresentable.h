#pragma once

#include <string>

class IPresentable
{
public:

  virtual ~IPresentable( ) noexcept = default;

  virtual std::string Present( ) const noexcept = 0;

protected:

  IPresentable( ) noexcept = default;

private:
};
