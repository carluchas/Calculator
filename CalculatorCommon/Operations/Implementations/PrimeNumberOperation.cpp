#include "Data/Headers/IntervalData.h"
#include "Operations/Headers/PrimeNumberOperation.h"
#include "Operations/Interfaces/IOperationSptr.h"
#include "Results/Headers/ListResult.h"
#include "Results/Implementations/ListResult.cpp"
#include <list>

PrimeNumberOperation::PrimeNumberOperation( ) :
  IOperation( )
{
}

IOperationSptr PrimeNumberOperation::NewSptr( )
{
  return IOperationSptr( new PrimeNumberOperation( ) );
}

std::string PrimeNumberOperation::Present( )
{
  return std::string( "Prime Numbers" );
}

IResultSptr PrimeNumberOperation::Execute( IDataSptr asp_data )
{
  auto sp_interval = std::dynamic_pointer_cast<IntervalData>( asp_data );

  if( sp_interval )
  {
    std::list< unsigned int > list_result;

    auto first_to_show = sp_interval->FirstValue( );
    auto prime_to_show = sp_interval->NumberOfValues( );

    unsigned int current_prime = 2;

    while( prime_to_show > 0 )
    {
      bool prime = true;

      for( unsigned long i = 2; i < abs( long long( current_prime / 2 ) ) + 1 && prime; ++i )
      {
        if( current_prime % i == 0 )
        {
          prime = false;
        }
      }

      if( prime )
      {
        if( first_to_show > 0 )
        {
          first_to_show--;
        }

        if( first_to_show == 0 )
        {
          list_result.emplace_back( current_prime );

          prime_to_show--;
        }
      }

      current_prime++;
    }

    auto sp_to_return = ListResult< unsigned int >::NewSptr( );

    std::dynamic_pointer_cast<ListResult< unsigned int >>( sp_to_return )->SetList( list_result );

    return IResultSptr( sp_to_return );
  }

  return IResultSptr( );
}