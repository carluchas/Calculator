#include "Operations/Headers/PrimeNumberOperation.h"

PrimeNumberOperation::PrimeNumberOperation( ) :
  SeriesNumberOperation( )
{
}

IOperationSptr PrimeNumberOperation::NewSptr( )
{
  return IOperationSptr( new PrimeNumberOperation( ) );
}

std::string PrimeNumberOperation::Present( ) const
{
  return std::string( "Prime Numbers" );
}

std::vector<long long unsigned int>
PrimeNumberOperation::SeriesOrigin( ) const
{
  return std::vector<long long unsigned int>( { 2 } );
}

void PrimeNumberOperation::AddNextSeriesNumberSpecific(
  std::vector<long long unsigned int>& ar_series ) const
{
  if( !ar_series.empty( ) )
  {
    bool prime = false;

    long long unsigned int to_add = ar_series.back( );

    while( !prime )
    {
      to_add++;

      prime = true;

      for( long long unsigned int i = 2;
           2 * i <= to_add + 1 && prime;
           i++ )
      {
        if( to_add % i == 0 )
        {
          prime = false;
        }
      }
    }

    if( prime )
    {
      ar_series.emplace_back( to_add );
    }
  }
}