/*
 @Date    : 2018-05-17 19:47:33
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
List类模板的访问接口函数
 */

#ifndef LIST_INTERFACES_H
#define LIST_INTERFACES_H

#include "List.h"

namespace CZ
{
    template <typename T>
    inline typename List<T>::iterator List<T>::begin()
    {
        return ListIterator<T>(_head->next());
    }
    template <typename T>
    inline typename List<T>::iterator List<T>::begin() const
    {
        return ListIterator<T>(_head->next());
    }

    template <typename T>
    inline typename List<T>::iterator List<T>::end()
    {
        return ListIterator<T>(_tail);
    }
    template <typename T>
    inline typename List<T>::iterator List<T>::end() const
    {
        return ListIterator<T>(_tail);
    }

    template <typename T>
    inline typename List<T>::Rank List<T>::size()
    {
        return _size;
    }
    template <typename T>
    inline typename List<T>::Rank List<T>::size() const
    {
        return _size;
    }

    template <typename T>
    inline bool List<T>::empty()
    {
        return _size == 0;
    }
    template <typename T>
    inline bool List<T>::empty() const
    {
        return _size == 0;
    }

    template <typename T>
    inline ListNode<T>& List<T>::head()
    {
        return *_head;
    }

    template <typename T>
    inline const ListNode<T>& List<T>::head() const
    {
        return *_head;
    }

    template <typename T>
    inline ListNode<T>& List<T>::tail()
    {
        return *_tail;
    }

    template <typename T>
    inline const ListNode<T>& List<T>::tail() const
    {
        return *_tail;
    }

    template <typename T>
    inline T& List<T>::front()
    {
        return _head->next()->data();
    }

    template <typename T>
    inline const T& List<T>::front() const
    {
        return _head->next()->data();
    }

    template <typename T>
    inline T& List<T>::back()
    {
        return _back->data();
    }

    template <typename T>
    inline const T& List<T>::back() const
    {
        return _back->data();
    }

} // CZ

#endif // LIST_INTERFACES_H

