#include "Operations/Headers/OperationException.h"

OperationException::OperationException(
  char const* const a_message, char const* const a_function ) noexcept :
  exception( a_message ),
  _p_function( a_function )
{
}

char const* OperationException::where( ) const noexcept
{
  return _p_function ? _p_function : "Unknown location origin";
}