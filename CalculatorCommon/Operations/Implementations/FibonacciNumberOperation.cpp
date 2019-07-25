#include "Operations/Headers/FibonacciNumberOperation.h"

FibonacciNumberOperation::FibonacciNumberOperation( ) :
  SeriesNumberOperation( )
{
}

IOperationSptr FibonacciNumberOperation::NewSptr( )
{
  return IOperationSptr( new FibonacciNumberOperation( ) );
}

std::string FibonacciNumberOperation::Present( ) const
{
  return std::string( "Fibonacci Numbers" );
}

std::vector<long long unsigned int>
FibonacciNumberOperation::SeriesOrigin( ) const
{
  return std::vector<long long unsigned int>( { 1, 1 } );
}

void FibonacciNumberOperation::AddNextSeriesNumberSpecific(
  std::vector<long long unsigned int>& ar_series ) const
{
  auto elem_num = ar_series.size( );

  if( elem_num >= 2 )
  {
    ar_series.
      emplace_back( ar_series[ elem_num - 2 ] + ar_series[ elem_num - 1 ] );
  }
}