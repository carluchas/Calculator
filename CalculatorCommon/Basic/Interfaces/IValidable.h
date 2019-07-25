#pragma once

class IValidable
{
public:

  virtual ~IValidable( ) noexcept = default;

  virtual bool IsValid( ) const noexcept = 0;

protected:

  IValidable( ) noexcept = default;

private:
};
