/*
 @Date    : 2018-05-17 19:15:13
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
List类模板的动态操作
 */

#ifndef LIST_MODIFICATIONS_H
#define LIST_MODIFICATIONS_H

#include "List.h"
#include <stdexcept>
#include <utility>
#include "..\Algorithms\Swap.h"

namespace CZ
{
    template <typename T>
    inline void List<T>::clear()
    {
        for (ListNode<T> *node = _head->next(); node != _tail;)
        {
            ListNode<T> *temp = node;
            node->next()->prev() = nullptr;
            node = node->next();
            delete temp;
        }
        _size = 0;
        _head->next() = _tail;
        _tail->prev() = _head;
        _back = nullptr;
        return;
    }

    template <typename T>
    inline typename List<T>::iterator List<T>::insert(typename List<T>::iterator pos, const T &data)
    {
        ListNode<T> *newNode = pos.get()->insert_as_prev(data);
        pos.get()->prev()->next() = newNode;
        pos.get()->prev() = newNode;
        ++_size;
        _back = _tail->prev();
        return ListIterator<T>(newNode);
    }

    template <typename T>
    inline typename List<T>::iterator List<T>::insert(typename List<T>::iterator pos, T &&data)
    {
        ListNode<T> *posGet = pos.get();
        ListNode<T> *newNode = posGet->insert_as_prev(std::move(data));
        posGet->prev()->next() = newNode;
        posGet->prev() = newNode;
        ++_size;
        _back = _tail->prev();
        return ListIterator<T>(newNode);
    }

    template <typename T>
    inline typename List<T>::iterator List<T>::insert(typename List<T>::iterator pos,
        typename List<T>::iterator b, typename List<T>::iterator e)
    {
        ListNode<T> *posGet = pos.get();
        ListNode<T> *hNode = posGet->prev();
        while (b != e)
        {
            ListNode<T> *newNode = posGet->insert_as_prev(*b++);
            posGet->prev()->next() = newNode;
            posGet->prev() = newNode;
            ++_size;
        }
        _back = _tail->prev();
        return ListIterator<T>(hNode->next());
    }

    template <typename T>
    inline typename List<T>::iterator List<T>::erase(typename List<T>::iterator pos)
    {
        try
        {
            ListNode<T> *posGet = pos.get();
            if (!posGet->prev() || !posGet->next())
            {
                throw "head or tail can not be erased!";
            }
            posGet->next()->prev() = posGet->prev();
            posGet->prev()->next() = posGet->next();
            posGet = posGet->next();
            delete pos.get();
            --_size;
            if (!empty())
                _back = _tail->prev();
            else _back = nullptr;
            return ListIterator<T>(posGet);
        }
        catch (const char *errMsg)
        {
            printf("Error: %s\n", errMsg);
            throw std::exception();
        }
        return pos;
    }

    template <typename T>
    inline typename List<T>::iterator List<T>::erase(typename List<T>::iterator b,
        typename List<T>::iterator e)
    {
        try
        {
            while (b != e)
            {
                ListNode<T> *posGet = b++.get();
                if (!posGet->prev() || !posGet->next())
                {
                    throw "head or tail can not be erased!";
                }
                posGet->next()->prev() = posGet->prev();
                posGet->prev()->next() = posGet->next();
                delete posGet;
                --_size;
            }
        }
        catch (const char *errMsg)
        {
            printf("Error: %s\n", errMsg);
            throw std::exception();
        }
        if (!empty())
            _back = _tail->prev();
        else _back = nullptr;
        return e;
    }

    template <typename T>
    inline void List<T>::push_back(const T &data)
    {
        insert(end(), data);
        return;
    }

    template <typename T>
    inline void List<T>::push_back(T &&data)
    {
        insert(end(), std::move(data));
        return;
    }

    template <typename T>
    inline void List<T>::push_front(const T &data)
    {
        insert(_head->next(), data);
        return;
    }

    template <typename T>
    inline void List<T>::push_front(T &&data)
    {
        insert(_head->next(), std::move(data));
        return;
    }

    template <typename T>
    inline void List<T>::pop_front()
    {
        erase(_head->next());
        return;
    }

    template <typename T>
    inline void List<T>::pop_back()
    {
        erase(_back);
        return;
    }

    template <typename T>
    inline void List<T>::merge(const List<T> &l)
    {
        insert(end(), l.begin(), l.end());
        return;
    }

    template <typename T>
    inline void List<T>::merge(List<T> &&l)
    {
        _back->next() = l._head->next();
        _tail->prev() = l._back;
        _back = l._back;
        _tail = l._tail;
        _size += l._size;

        l.init();
        l._back = nullptr;
        l._size = 0;
        return;
    }

    template <typename T>
    inline void List<T>::swap(iterator pos1, iterator pos2)
    {
        Swap(*pos1, *pos2);
        return;
    }

    template <typename T>
    template <typename Cmp>
    inline void List<T>::sort(const Cmp &cmp)
    {
        bool isSorted = false;
        unsigned unSortedNum = _size, checkedNum;
        while (!isSorted)
        {
            isSorted = true;
            checkedNum = 0;
            for (iterator it = begin(); checkedNum != unSortedNum - 1 && it != end(); ++checkedNum)
            {
                T &thisData = *it;
                T &nextData = *++it;
                if (cmp(nextData, thisData))
                {
                    Swap(thisData, nextData);
                    isSorted = false;
                }
            }
            --unSortedNum;
        }
        return;
    }

    template <typename T>
    template <typename Cmp>
    inline void List<T>::unique(const Cmp &cmp)
    {
        for (iterator firstRepeat = begin(); firstRepeat != end();)
        {
            iterator lastRepeat = firstRepeat;
            for (; cmp(*lastRepeat, *firstRepeat) && lastRepeat != end(); ++lastRepeat);
            firstRepeat = erase(++iterator(firstRepeat), lastRepeat);
        }
        return;
    }

    template <typename T>
    inline void List<T>::reverse()
    {
        ListNode<T> *e = _tail;
        _back = _head->next();
        for (unsigned count = 0; count != _size; ++count)
        {
            ListNode<T> *temp = _head->next();
            _head->next() = temp->next();
            temp->next()->prev() = _head;

            e->prev()->next() = temp;
            e->insert_as_prev(temp);
            e->prev() = temp;
            e = temp;
        }
        return;
    }

} // CZ

#endif // LIST_MODIFICATIONS_H

