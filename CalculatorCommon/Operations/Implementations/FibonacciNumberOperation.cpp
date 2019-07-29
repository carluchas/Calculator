#include "Operations/Headers/FibonacciNumberOperation.h"
#include "Operations/Headers/OperationException.h"

FibonacciNumberOperation::FibonacciNumberOperation( ) noexcept :
  SeriesOperation( )
{
}

IOperationSptr FibonacciNumberOperation::NewSptr( ) noexcept
{
  return IOperationSptr( new FibonacciNumberOperation( ) );
}

std::string FibonacciNumberOperation::Present( ) const noexcept
{
  return std::string( "Fibonacci Numbers" );
}

std::vector<unsigned long long>
FibonacciNumberOperation::SeriesOrigin( ) const noexcept
{
  return std::vector<unsigned long long>( { 1, 1 } );
}

void FibonacciNumberOperation::AddNextSeriesNumberSpecific(
  std::vector<unsigned long long>& ar_series ) const noexcept( false )
{
  auto elem_num = ar_series.size( );

  if( elem_num < 2 )
  {
    throw OperationException( "Insufficient values in given germen series "
                              "to calculate a new one", __func__ );
  }

  if( ar_series.back( ) >
    ( std::numeric_limits< unsigned long long >::max( ) / 2 ) )
  {
    throw OperationException( "Next series number cannot be represented in this"
                              " platform using integer basic language types",
                              __func__ );
  }

  ar_series.
    emplace_back( ar_series[ elem_num - 2 ] + ar_series.back( ) );
}