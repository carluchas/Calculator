#pragma once

#include <exception>

class OperationException : public std::exception
{
public:

  explicit OperationException( char const* const a_message,
                               char const* const a_function );

  OperationException( const OperationException& ar_exception ) = default;

  OperationException& operator = ( const OperationException& ar_exception ) =
    default;

  virtual char const* where( ) const;

protected:

private:

  char const* _p_function;

  OperationException( );
};
