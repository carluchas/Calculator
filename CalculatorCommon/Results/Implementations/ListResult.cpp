#include "Results/Headers/ListResult.h"

template<class T> IResultSptr ListResult<T>::NewSptr( ) noexcept
{
  return IResultSptr( new ListResult< T >( ) );
}

template<class T> void ListResult<T>::SetList(
  const std::vector<T>& ar_list ) noexcept
{
  _list = ar_list;
}

template <class T> bool ListResult<T>::IsValid( ) const noexcept
{
  return !_list.empty( );
}

template<class T> std::string ListResult<T>::Present( ) const noexcept
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

template<class T> const std::vector<T>& ListResult<T>::List( ) const noexcept
{
  return _list;
}