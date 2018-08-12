/*
 @Date    : 2018-08-12 21:24:23
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
集合类模板，由红黑树实现
 */

#ifndef SET_H
#define SET_H

#include "../Tree/BinTree/RedBlackTree.h"
#include "../Iterator/SeqIterator.h"
#include "SetIterator.h"

namespace CZ
{
    template <typename T> class Set;

    template <typename T> bool operator==(const Set<T> &lhs, const Set<T> &rhs);
    template <typename T> bool operator!=(const Set<T> &lhs, const Set<T> &rhs);
    template <typename T> Set<T> operator+(const Set<T> &lhs, const Set<T> &rhs);
    template <typename T> Set<T> operator-(const Set<T> &lhs, const Set<T> &rhs);

    template <typename T>
    class Set
    {
        friend bool operator==<T>(const Set<T> &lhs, const Set<T> &rhs);
        friend bool operator!=<T>(const Set<T> &lhs, const Set<T> &rhs);
        friend Set<T> operator+<T>(const Set<T> &lhs, const Set<T> &rhs);
        friend Set<T> operator-<T>(const Set<T> &lhs, const Set<T> &rhs);
        friend class SetIterator<T>;
    public:
        using Rank = unsigned;
        using iterator = SetIterator<T>;

        Set();
        Set(const SeqIterator<T> &begin, const SeqIterator<T> &end);
        Set(T *begin, T *end);
        Set(const std::initializer_list<T> &l);

        // 数据访问接口
        Rank size() const;
        bool empty() const;
        bool has_this_element(const T &value) const;
        iterator begin();
        iterator begin() const;
        // 注意Set没有尾后迭代器end()，取而代之的是最后一个元素的迭代器last()
        iterator last();
        iterator last() const;

        // 插入和删除，成功返回true，失败返回false或者抛出异常
        bool insert(const T &value, bool nonexcept = true);
        bool remove(const T &value, bool nonexcept = true);

        void print_info(const char *name = "") const;
    private:
        RedBlackTree<T> _T;

        template <typename It>
        void _build_set(const It &begin, const It &end);
    };
} // CZ

#include "Set_implementation.h"
#include "Set_operations.h"

#endif // SET_H
