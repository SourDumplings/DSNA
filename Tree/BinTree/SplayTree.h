/*
 @Date    : 2018-06-20 20:25:34
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
伸展树模板
 */

#ifndef SPLAY_TREE_H
#define SPLAY_TREE_H

#include "SplayTreeNode.h"
#include "BST.h"

namespace CZ
{
    template <typename T>
    class SplayTree: public BST<T>
    {
    public:
        SplayTree(std::nullptr_t);
        SplayTree(SplayTreeNode<T> *root = nullptr);
        SplayTree(const SplayTree<T> &t);
        SplayTree(SplayTree<T> &&t);



    };
} // CZ

#endif // SPLAY_TREE_H
