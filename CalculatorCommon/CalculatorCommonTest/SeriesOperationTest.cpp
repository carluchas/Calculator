#include "Basic/Headers/easylogging++.h"
#include "Data/Headers/IntervalData.h"
#include "Operations/Headers/OperationException.h"
#include "Operations/Headers/SeriesOperation.h"
#include "Operations/Interfaces/IOperation.h"
#include "Results/Headers/ListResult.h"
#include "Results/Interfaces/IResultSptr.h"
#include "gtest/gtest.h"
#include <limits>
#include <list>
#include <string>

class TestSeriesOperation : public SeriesOperation
{
public:

  enum class Mode
  {
    StlLimitTest,
    NoElementAdded
  };

  static IOperationSptr NewSptr(const Mode& ar_test_mode) noexcept
  {
    return std::make_shared<TestSeriesOperation>(ar_test_mode);
  };

  TestSeriesOperation() noexcept = default;

  explicit TestSeriesOperation(Mode a_test_mode) noexcept :
    _mode(a_test_mode)
  {
  }

  ~TestSeriesOperation() noexcept override = default;

  void AddNextSeriesNumberSpecific(
    std::vector<unsigned long long>& ar_series)
    const noexcept(false) override
  {
    if (_mode == Mode::StlLimitTest)
    {
      auto v_size = ar_series.max_size() - 1;

      ar_series = std::vector<unsigned long long>(v_size);
    }
    else if (_mode == Mode::NoElementAdded)
    {
      return;
    }
  }

  std::string Present() const noexcept override
  {
    return "Test series";
  }

protected:

  std::vector<unsigned long long> SeriesOrigin() const noexcept override
  {
    return std::vector<unsigned long long>();
  }

private:

  Mode _mode;
};

TEST(SeriesOperationTestCase, SeriesOperationTest)
{
  auto sp_operation = TestSeriesOperation::NewSptr(
    TestSeriesOperation::Mode::StlLimitTest);

  ASSERT_TRUE(sp_operation);

  auto text = sp_operation->Present();

  EXPECT_FALSE(text.empty());

  EXPECT_THROW(auto sp_result = sp_operation->Execute(IDataSptr()),
    OperationException);

  unsigned int first = 0;
  unsigned long size = 5;

  auto sp_data = IDataSptr(IntervalData::NewSptr(first, size));

  EXPECT_THROW(auto sp_result = sp_operation->Execute(sp_data),
    OperationException);

  sp_data = IDataSptr(IntervalData::NewSptr(2, size));

  EXPECT_THROW(auto sp_result = sp_operation->Execute(sp_data), OperationException);

  sp_operation = TestSeriesOperation::NewSptr(
    TestSeriesOperation::Mode::NoElementAdded);

  sp_data = IDataSptr(IntervalData::NewSptr(2, size));

  EXPECT_THROW(auto sp_result = sp_operation->Execute(sp_data), OperationException);
}