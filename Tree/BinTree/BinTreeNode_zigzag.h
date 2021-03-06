/*
 @Date    : 2018-06-03 14:02:31
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
二叉树结点类模板的旋转操作实现，返回旋转后的原来位置的结点指针
该方法将会完成结点父子关系的调整和高度的更新

zig:
      |                |
      A                B
     / \              / \
    B   C    ->      D   A
   / \                  / \
  D   E                E   C

zag:
      |                |
      A                C
     / \              / \
    B   C     ->     A   E
       / \          / \
      D   E        B   D
 */

#ifndef BIN_TREE_NODE_ZIGZAG_H
#define BIN_TREE_NODE_ZIGZAG_H

#include "BinTreeNode.h"

namespace CZ
{
    template <typename T>
    BinTreeNode<T>* BinTreeNode<T>::zig()
    {
        BinTreeNode<T> *lChild = left_child();
        try
        {
            if (!lChild)
            {
                throw "this node doesn't have left child, cannot zig";
            }
        }
        catch (const char *errMsg)
        {
            printf("%s\n", errMsg);
            throw std::exception();
        }

        lChild->father() = this->father();
        BinTreeNode<T> *&f = (BinTreeNode<T>*&)(this->father());
        if (f)
        {
            ((this == f->left_child()) ?
                f->left_child() : f->right_child()) = lChild;
        }
        left_child() = lChild->right_child();
        if (left_child())
        {
            left_child()->father() = this;
        }
        lChild->right_child() = this;
        this->father() = lChild;

        // 更新这个结点的高度
        Rank lH = left_child() ? left_child()->height() : 0;
        Rank rH = right_child() ? right_child()->height() : 0;
        this->height() = Max(lH, rH) + 1;
        // 更新结点B的高度
        lH = lChild->left_child() ? lChild->left_child()->height() : 0;
        rH = lChild->right_child() ? lChild->right_child()->height() : 0;
        lChild->height() = Max(lH, rH) + 1;
        lChild->update_height_above(0); // 结点B的高度只可能增加
        return lChild;
    }

    template <typename T>
    BinTreeNode<T>* BinTreeNode<T>::zag()
    {
        BinTreeNode<T> *rChild = right_child();
        try
        {
            if (!rChild)
            {
                throw "this node doesn't have right child, cannot zag";
            }
        }
        catch (const char *errMsg)
        {
            printf("%s\n", errMsg);
            throw std::exception();
        }

        rChild->father() = this->father();
        BinTreeNode<T> *&f = (BinTreeNode<T>*&)(this->father());
        if (f)
        {
            ((this == f->right_child()) ?
                f->right_child() : f->left_child()) = rChild;
        }
        right_child() = rChild->left_child();
        if (right_child())
        {
            right_child()->father() = this;
        }
        rChild->left_child() = this;
        this->father() = rChild;

        // 更新这个结点的高度
        Rank lH = left_child() ? left_child()->height() : 0;
        Rank rH = right_child() ? right_child()->height() : 0;
        this->height() = Max(lH, rH) + 1;
        // 更新结点C的高度
        lH = rChild->left_child() ? rChild->left_child()->height() : 0;
        rH = rChild->right_child() ? rChild->right_child()->height() : 0;
        rChild->height() = Max(lH, rH) + 1;
        rChild->update_height_above(0); // 结点C的高度只可能增加
        return rChild;
    }
} // CZ

#endif // BIN_TREE_NODE_ZIGZAG_H


