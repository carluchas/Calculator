#include "Basic/Headers/easylogging++.h"
#include "Data/Headers/IntervalData.h"
#include "Operations/Headers/FibonacciNumberOperation.h"
#include "Operations/Headers/OperationException.h"
#include "Operations/Interfaces/IOperation.h"
#include "gtest/gtest.h"
#include <list>
#include <string>

TEST( FibonacciNumberOperationTestCase, FibonacciNumberOperationTest )
{
  auto sp_operation = FibonacciNumberOperation::NewSptr( );

  ASSERT_TRUE( sp_operation );

  unsigned int first = 2;
  unsigned long size = 5;

  auto sp_data = IDataSptr( IntervalData::NewSptr( first, size ) );

  auto sp_result = sp_operation->Execute( sp_data );

  ASSERT_TRUE( sp_result );

  EXPECT_EQ( sp_result->Present( ), std::string( "1, 2, 3, 5, 8" ) );

  sp_data = IDataSptr( IntervalData::NewSptr( 100, 5 ) );

  EXPECT_THROW( sp_result = sp_operation->Execute( sp_data ),
                OperationException );

  sp_data = IDataSptr( IntervalData::NewSptr( 5, 100 ) );

  EXPECT_THROW( sp_result = sp_operation->Execute( sp_data ),
                OperationException );
}