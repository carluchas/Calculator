#pragma once

#include "Results/Interfaces/IResult.h"
#include "Results/Interfaces/IResultSptr.h"
#include <vector>

template <class T> class ListResult : public virtual IResult
{
public:

  static IResultSptr NewSptr( );

  virtual ~ListResult( ) = default;

  void SetList( const std::vector<T>& ar_list );

  virtual std::string Present( ) const override;

  const std::vector<T>& List( ) const;

protected:

  ListResult( ) = default;

private:

  std::vector< T > _list;
};
