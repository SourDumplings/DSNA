/**  

    * @projectName DSA
    * @author SourDumplings
    * @version 1.0.0
    * @date 2021/3/4 10:31
*/

#include "Pair.h"
#include "../CZString/CZString.h"
#include <cstdio>

using namespace CZ;
using namespace std;

class K
{
public:
    int k;
};

class V
{
public:
    CZString v;
};

class KD: public K
{

};


class VD: public V
{

};

int main(int argc, char const *argv[])
{
    Pair<KD, double> p1;
    p1.key().k = 1;
    p1.value() = 2.0;
    Pair<K, int> p2(p1);
    printf("p2.key().k = %d\n", p2.key().k);
    printf("p2.value() = %d\n", p2.value());

    Pair<KD, VD> p3;
    p3.key().k = 3;
    p3.value().v = "hello";
    Pair<K, V> p4(p3);
    Pair<K, VD> p5;
    p5.key().k = 4;
    p5.value().v = "yes";
    printf("p4.key().k = %d, p4.value().v = %s\n",
           p4.key().k,
           p4.value().v.c_str());
    p4 = p3;
    printf("p4.key().k = %d, p4.value().v = %s\n",
           p4.key().k,
           p4.value().v.c_str());
    p4 = p4;
    printf("p4.key().k = %d, p4.value().v = %s\n",
           p4.key().k,
           p4.value().v.c_str());
    return 0;
}
