#include "Basic/Headers/easylogging++.h"
#include "Data/Headers/IntervalData.h"
#include "Operations/Headers/OperationException.h"
#include "Operations/Headers/SeriesOperation.h"
#include "Operations/Interfaces/IOperation.h"
#include "gtest/gtest.h"
#include <limits>
#include <list>
#include <string>

class TestSeriesoperation : public SeriesOperation
{
public:

  enum Mode
  {
    StlLimitTest,
    NoElementAdded
  };

  static IOperationSptr NewSptr( Mode a_test_mode ) noexcept
  {
    return IOperationSptr( new TestSeriesoperation( a_test_mode ) );
  };

  TestSeriesoperation( ) noexcept = default;

  explicit TestSeriesoperation( Mode a_test_mode ) noexcept :
    _mode( a_test_mode )
  {
  }

  virtual ~TestSeriesoperation( ) noexcept = default;

  virtual void AddNextSeriesNumberSpecific(
    std::vector<unsigned long long>& ar_series )
    const noexcept( false ) override
  {
    if( _mode == StlLimitTest )
    {
      auto v_size = ar_series.max_size( ) - 1;

      std::vector<unsigned long long> v( v_size );

      ar_series = v;
    }
    else if( _mode == NoElementAdded )
    {
      ar_series = ar_series;
    }
  }

  virtual std::string Present( ) const noexcept override
  {
    return "Test series";
  }

protected:

  virtual std::vector<unsigned long long> SeriesOrigin( ) const noexcept override
  {
    return std::vector<unsigned long long>( );
  }

private:

  Mode _mode;
};

TEST( SeriesOperationTestCase, SeriesOperationTest )
{
  auto sp_operation = TestSeriesoperation::NewSptr(
    TestSeriesoperation::StlLimitTest );

  ASSERT_TRUE( sp_operation );

  EXPECT_THROW( auto sp_result = sp_operation->Execute( IDataSptr( ) ),
                OperationException );

  unsigned int first = 0;
  unsigned long size = 5;

  auto sp_data = IDataSptr( IntervalData::NewSptr( first, size ) );

  EXPECT_THROW( auto sp_result = sp_operation->Execute( sp_data ),
                OperationException );

  sp_data = IDataSptr( IntervalData::NewSptr( 2, size ) );

  EXPECT_THROW( auto sp_result = sp_operation->Execute( sp_data ), OperationException );

  sp_operation = TestSeriesoperation::NewSptr(
    TestSeriesoperation::NoElementAdded );

  sp_data = IDataSptr( IntervalData::NewSptr( 2, size ) );

  EXPECT_THROW( auto sp_result = sp_operation->Execute( sp_data ), OperationException );
}