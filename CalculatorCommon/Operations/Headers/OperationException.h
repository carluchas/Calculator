#pragma once

#include <exception>

class OperationException : public std::exception
{
public:

  explicit OperationException( char const* const a_message,
                               char const* const a_function ) noexcept;

  OperationException( const OperationException& ar_exception ) noexcept = default;

  OperationException& operator = ( const OperationException& ar_exception ) noexcept =
    default;

  virtual char const* where( ) const noexcept;

protected:

private:

  char const* _p_function;

  OperationException( );
};
