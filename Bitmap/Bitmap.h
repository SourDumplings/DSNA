/*
 @Date    : 2018-05-15 14:05:21
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
位图类
 */

#ifndef BITMAP_H
#define BITMAP_H

#include <string>

namespace CZ
{
    class Bitmap
    {
    public:
        using Rank = unsigned;
        // 构造函数
        Bitmap(Rank n_ = 8); // 按一定规模创建比特图
        Bitmap(const char *file, Rank n_ = 8); // 从指定文件中读取比特图

        // 析构函数
        ~Bitmap();

        // 访问接口函数
        void dump(const char *file); // 将位图导出☞指定的文件，以便于以后对位图的批量初始化
        std::string bits2string(Rank n_); // 将前n_位转为字符串
        bool test(Rank k); // 测试第k位是否为true（是否包含整数k），O(1)

        // 动态接口
        void set(Rank k); // 将第k为置为true（加入整数k），O(1)
        void clear(Rank k); // 将第k为置为false（删除整数k），O(1)

        // 扩容函数，若访问的Bitmap[k]已出界，则需要扩容
        void expand(Rank k);

        // 打印这个位域的信息
        void print_info(const char *name = "");

    protected:
        void init(Rank n_);
    private:
        // 比特图所在的空间_m[]，容量为_n*sizeof(char)位。
        char *_m;
        Rank _n;
    };
} // CZ

#endif // BITMAP_H


