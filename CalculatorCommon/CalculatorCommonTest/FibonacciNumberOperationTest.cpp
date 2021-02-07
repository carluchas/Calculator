#include "Basic/Headers/easylogging++.h"
#include "Data/Headers/IntervalData.h"
#include "Operations/Headers/FibonacciNumberOperation.h"
#include "Operations/Headers/OperationException.h"
#include "Operations/Interfaces/IOperation.h"
#include "gtest/gtest.h"
#include <list>
#include <string>

class TestFibonacciNumberOperation : public FibonacciNumberOperation
{
public:

  static IOperationSptr NewSptr() noexcept
  {
    return std::make_shared<TestFibonacciNumberOperation>();
  };

  TestFibonacciNumberOperation() noexcept = default;

  ~TestFibonacciNumberOperation() noexcept override = default;

  void AddNextSeriesNumberSpecific(
    std::vector<unsigned long long>& ar_series)
    const noexcept(false) override
  {
    FibonacciNumberOperation::AddNextSeriesNumberSpecific(ar_series);
  }
};

TEST(FibonacciNumberOperationTestCase, FibonacciNumberOperationTest)
{
  auto sp_operation = FibonacciNumberOperation::NewSptr();

  ASSERT_TRUE(sp_operation);

  unsigned int first = 2;
  unsigned long size = 5;

  auto sp_data = IDataSptr(IntervalData::NewSptr(first, size));

  auto sp_result = sp_operation->Execute(sp_data);

  ASSERT_TRUE(sp_result);

  EXPECT_EQ(sp_operation->Present(), std::string("Fibonacci Numbers"));

  EXPECT_EQ(sp_result->Present(), std::string("1, 2, 3, 5, 8"));

  sp_data = IDataSptr(IntervalData::NewSptr(100, 5));

  EXPECT_THROW(sp_result = sp_operation->Execute(sp_data),
    OperationException);

  sp_data = IDataSptr(IntervalData::NewSptr(5, 100));

  EXPECT_THROW(sp_result = sp_operation->Execute(sp_data),
    OperationException);

  sp_operation = TestFibonacciNumberOperation::NewSptr();

  ASSERT_TRUE(sp_operation);

  auto sp_specific_operation =
    std::dynamic_pointer_cast<TestFibonacciNumberOperation>(sp_operation);

  ASSERT_TRUE(sp_specific_operation);

  EXPECT_THROW(sp_specific_operation->AddNextSeriesNumberSpecific(
    std::vector<unsigned long long>()), OperationException);
}