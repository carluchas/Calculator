#include "Results/Headers/ListResult.h"

template<class T> IResultSptr ListResult<T>::NewSptr( )
{
  return IResultSptr( new ListResult< T >( ) );
}

template<class T> void ListResult<T>::SetList( const std::vector<T>& ar_list )
{
  _list = ar_list;
}

template<class T> std::string ListResult<T>::Present( ) const
{
  std::string to_return;

  for( const auto& num : _list )
  {
    if( !to_return.empty( ) )
    {
      to_return += ", ";
    }

    to_return += std::to_string( num );
  }

  return to_return;
}

template<class T> const std::vector<T>& ListResult<T>::List( ) const
{
  return _list;
}