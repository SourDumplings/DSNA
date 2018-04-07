/*
 @Date    : 2018-04-07 13:08:13
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
容器的字典序比较算法
要求：
1.容器必须支持单向访问迭代器，具有_size属性
2.容器内元素支持比较操作符
 */

#ifndef DICT_COMPARE_CPP
#define DICT_COMPARE_CPP

namespace CZ
{
    template <typename C>
    inline bool operator==(const C &lhs, const C &rhs) noexcept
    {
        if (lhs._size != rhs._size)
        {
            return false;
        }
        for (typename C::iterator itL = lhs.begin(), itR = rhs.begin();
            itL != lhs.end(); ++itL, ++itR)
        {
            if (*itL != *itR)
            {
                return false;
            }
        }
        return true;
    }

    template <typename C>
    inline bool operator!=(const C &lhs, const C &rhs) noexcept
    {
        return !(lhs == rhs);
    }

    template <typename C>
    inline bool operator<(const C &lhs, const C &rhs) noexcept
    {
        if (lhs._size == 0)
        {
            return true;
        }
        for (typename C::iterator itL = lhs.begin(), itR = rhs.begin();
            itL != lhs.end(); ++itL, ++itR)
        {
            if (itR == rhs.end())
            {
                return false;
            }
            if (*itL < *itR)
            {
                return true;
            }
            else if (*itL > *itR)
            {
                return false;
            }
        }
        if (lhs._size < rhs._size)
        {
            return true;
        }
        else
            return false;
    }

    template <typename C>
    inline bool operator<=(const C &lhs, const C &rhs) noexcept
    {
        return lhs < rhs || lhs == rhs;
    }

    template <typename C>
    inline bool operator>(const C &lhs, const C &rhs) noexcept
    {
        return !(lhs <= rhs);
    }

    template <typename C>
    inline bool operator>=(const C &lhs, const C &rhs) noexcept
    {
        return lhs > rhs || lhs == rhs;
    }
}

#endif // DICT_COMPARE_CPP


