#include "Operations/Headers/OperationException.h"
#include "gtest/gtest.h"
#include <string>

TEST( OperationExceptionTestCase, OperationExceptionTest )
{
  char const* str( "Operation Exception Test Message." );
  char const* func = __func__;

  try
  {
    throw OperationException( str, func );
  }
  catch( const OperationException& ar_e )
  {
    std::string message = ar_e.what( );

    EXPECT_TRUE( message == std::string( str ) );
    EXPECT_TRUE( ar_e.where( ) == func );
  }
}