#include "Basic/Headers/easylogging++.h"
#include "Data/Headers/IntervalData.h"
#include "gtest/gtest.h"
#include "Operations/Headers/EfficientPrimeNumberOperation.h"
#include "Operations/Interfaces/IOperation.h"
#include <list>
#include <string>

TEST( EfficientPrimeNumberOperationTestCase, EfficientPrimeNumberOperationTest )
{
  auto sp_operation = EfficientPrimeNumberOperation::NewSptr( );

  ASSERT_TRUE( sp_operation );

  unsigned int first = 2;
  unsigned long size = 5;

  LOG( INFO ) << "First prime number to show: ";
  scanf_s( "%d", &first );

  LOG( INFO ) << "Number of prime numbers to show: ";
  scanf_s( "%d", &size );

  auto sp_data = IDataSptr( IntervalData::NewSptr( first, size ) );

  auto sp_result = sp_operation->Execute( sp_data );

  ASSERT_TRUE( sp_result );

  EXPECT_EQ( sp_result->Present( ), std::string( "3, 5, 7, 11, 13" ) );
}