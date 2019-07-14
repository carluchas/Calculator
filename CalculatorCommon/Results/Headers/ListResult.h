#pragma once

#include "Results/Interfaces/IResult.h"
#include "Results/Interfaces/IResultSptr.h"
#include <list>

template <class T> class ListResult : public virtual IResult
{
public:

  static IResultSptr NewSptr( );

  virtual ~ListResult( ) = default;

  void SetList( const std::list<T>& ar_list );

  virtual std::string Present( ) override;

  const std::list<T>& List( ) const;

protected:

  ListResult( ) = default;

private:

  std::list< T > _list;
};
