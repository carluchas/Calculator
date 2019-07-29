#pragma once

#include "Results/Interfaces/IResult.h"
#include "Results/Interfaces/IResultSptr.h"
#include <vector>

template <class T> class ListResult : public virtual IResult
{
public:

  static IResultSptr NewSptr( ) noexcept;

  virtual ~ListResult( ) noexcept = default;

  void SetList( const std::vector<T>& ar_list ) noexcept;

  virtual bool IsValid( ) const noexcept override;

  virtual std::string Present( ) const noexcept override;

  const std::vector<T>& List( ) const noexcept;

protected:

  ListResult( ) noexcept = default;

private:

  std::vector< T > _list;

  explicit ListResult( const ListResult& ar_operation ) noexcept = default;

  ListResult& operator = ( const ListResult& ar_operation ) noexcept = default;
};
