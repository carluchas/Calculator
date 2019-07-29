#include "Operations/Headers/OperationException.h"
#include "Operations/Headers/EfficientPrimeNumberOperation.h"

EfficientPrimeNumberOperation::EfficientPrimeNumberOperation( ) noexcept :
  SeriesOperation( )
{
}

IOperationSptr EfficientPrimeNumberOperation::NewSptr( ) noexcept
{
  return IOperationSptr( new EfficientPrimeNumberOperation( ) );
}

std::string EfficientPrimeNumberOperation::Present( ) const noexcept
{
  return std::string( "Efficient Prime Numbers" );
}

void EfficientPrimeNumberOperation::AddNextSeriesNumberSpecific(
  std::vector<unsigned long long>& ar_series ) const noexcept( false )
{
  if( ar_series.empty( ) )
  {
    throw OperationException( "Insufficient values in given germen series "
                              "to calculate a new one", __func__ );
  }

  if( ar_series.back( ) >
    ( std::numeric_limits< unsigned long long >::max( ) - 2 ) )
  {
    throw OperationException( "Next series number cannot be represented in this"
                              " platform using integer basic language types",
                              __func__ );
  }

  bool prime = false;

  unsigned long long to_add = ar_series.back( );

  while( !prime )
  {
    to_add += 2;

    auto root = sqrtl( long double( to_add ) );

    prime = ( floor( root ) > 0 );

    for( unsigned int i = 0; ar_series[ i ] < root && prime; i++ )
    {
      if( to_add % ar_series[ i ] == 0 )
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