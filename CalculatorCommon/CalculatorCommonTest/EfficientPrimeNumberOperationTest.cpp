#include "Basic/Headers/easylogging++.h"
#include "Data/Headers/IntervalData.h"
#include "Operations/Headers/EfficientPrimeNumberOperation.h"
#include "Operations/Headers/OperationException.h"
#include "Operations/Interfaces/IOperation.h"
#include "gtest/gtest.h"
#include <list>
#include <string>

class TestEfficientPrimeNumberOperation : public EfficientPrimeNumberOperation
{
public:

  static IOperationSptr NewSptr() noexcept
  {
    return std::make_shared<TestEfficientPrimeNumberOperation>();
  };

  TestEfficientPrimeNumberOperation() noexcept = default;

  ~TestEfficientPrimeNumberOperation() noexcept override = default;

  void AddNextSeriesNumberSpecific(
    std::vector<unsigned long long>& ar_series)
    const noexcept(false) override
  {
    EfficientPrimeNumberOperation::AddNextSeriesNumberSpecific(ar_series);
  }
};

TEST(EfficientPrimeNumberOperationTestCase, EfficientPrimeNumberOperationTest)
{
  auto sp_operation = EfficientPrimeNumberOperation::NewSptr();

  ASSERT_TRUE(sp_operation);

  unsigned int first = 2;
  unsigned long size = 5;

  auto sp_data = IDataSptr(IntervalData::NewSptr(first, size));

  auto sp_result = sp_operation->Execute(sp_data);

  ASSERT_TRUE(sp_result);

  EXPECT_EQ(sp_operation->Present(),
    std::string("Efficient Prime Numbers"));

  EXPECT_EQ(sp_result->Present(), std::string("3, 5, 7, 11, 13"));

  sp_operation = TestEfficientPrimeNumberOperation::NewSptr();

  ASSERT_TRUE(sp_operation);

  auto sp_specific_operation =
    std::dynamic_pointer_cast<TestEfficientPrimeNumberOperation>
    (sp_operation);

  ASSERT_TRUE(sp_specific_operation);

  EXPECT_THROW(sp_specific_operation->AddNextSeriesNumberSpecific(
    std::vector<unsigned long long>()), OperationException);

  std::vector<unsigned long long> series(
    { ((std::numeric_limits< unsigned long long >::max)() - 1) });

  EXPECT_THROW(sp_specific_operation->AddNextSeriesNumberSpecific(series),
    OperationException);
}