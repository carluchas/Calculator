#include "Basic/Headers/easylogging++.h"
#include "Basic/Headers/OrdinalPresenter.h"
#include "Data/Headers/IntervalData.h"
#include "gtest/gtest.h"
#include <string>

INITIALIZE_EASYLOGGINGPP

TEST( IntervalDataTestCase, IntervalDataTest )
{
  unsigned int first = 3;
  unsigned int num = 35;

  auto sp_data = IntervalData::NewSptr( 3, 35 );

  auto sp_interval = std::dynamic_pointer_cast<IntervalData>( sp_data );

  ASSERT_TRUE( sp_interval );

  EXPECT_TRUE( sp_interval->IsValid( ) );

  EXPECT_EQ( first, sp_interval->FirstValue( ) );
  EXPECT_EQ( num, sp_interval->NumberOfValues( ) );

  EXPECT_EQ( first + num - 1, sp_interval->LastValue( ) );

  std::string to_compare( "From the " );

  OrdinalPresenter presenter;

  to_compare += presenter.ToOrdinal( first );
  to_compare += " to the ";
  to_compare += presenter.ToOrdinal( first - 1 + num );

  EXPECT_EQ( to_compare, sp_interval->Present( ) );

  sp_data = IntervalData::NewSptr( 0, 35 );

  sp_interval = std::dynamic_pointer_cast<IntervalData>( sp_data );

  ASSERT_TRUE( sp_interval );

  EXPECT_FALSE( sp_interval->IsValid( ) );

  sp_data = IntervalData::NewSptr( 5, 0 );

  sp_interval = std::dynamic_pointer_cast<IntervalData>( sp_data );

  ASSERT_TRUE( sp_interval );

  EXPECT_FALSE( sp_interval->IsValid( ) );
}