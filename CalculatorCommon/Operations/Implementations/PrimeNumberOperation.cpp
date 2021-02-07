#include "Operations/Headers/OperationException.h"
#include "Operations/Headers/PrimeNumberOperation.h"
#include <memory>

IOperationSptr PrimeNumberOperation::NewSptr() noexcept
{
  return std::make_shared<PrimeNumberOperation>(ConstructionKey());
}

PrimeNumberOperation::PrimeNumberOperation(const ConstructionKey&) noexcept
{
}

std::string PrimeNumberOperation::Present() const noexcept
{
  return std::string("Prime Numbers");
}

std::vector<unsigned long long>
PrimeNumberOperation::SeriesOrigin() const noexcept
{
  return std::vector<unsigned long long>({ 2, 3 });
}

void PrimeNumberOperation::AddNextSeriesNumberSpecific(
  std::vector<unsigned long long>& ar_series) const noexcept(false)
{
  if (ar_series.empty())
  {
    throw OperationException("Insufficient values in given germen series "
      "to calculate a new one", __func__);
  }

  if (ar_series.back() >
    (std::numeric_limits< unsigned long long >::max() - 2))
  {
    throw OperationException("Next series number cannot be represented in this"
      " platform using integer basic language types",
      __func__);
  }

  bool prime = false;

  unsigned long long to_add = ar_series.back();

  while (!prime)
  {
    to_add += 2;

    prime = true;

    for (unsigned long long i = 2;
      2 * i <= to_add + 1 && prime;
      i++)
    {
      if (to_add % i == 0)
      {
        prime = false;
      }
    }
  }

  if (prime)
  {
    ar_series.emplace_back(to_add);
  }
}