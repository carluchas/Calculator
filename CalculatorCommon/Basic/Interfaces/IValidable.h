#pragma once

class IValidable
{
public:

  virtual ~IValidable( ) = default;

  virtual bool IsValid( ) const = 0;

protected:

  IValidable( ) = default;

private:
};
