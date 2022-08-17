/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Test{
    int val;
    Test(int x) : val(x) { }
};

bool nonmem_cmp(const Test &t1, const Test &t2)
{
    if(t1.val > t2.val)
        return true;
    return false;
}

void print_res(Test t)
{
    cout << t.val << " ";
}

int main(int argc, char *argv[])
{
    vector<Test> ivec;
    ivec.push_back(Test(6));
    ivec.push_back(Test(4));
    ivec.push_back(Test(8));
    ivec.push_back(Test(2));
    ivec.push_back(Test(1));

    // 对对象按照对象值排序
    sort(ivec.begin(), ivec.end(), nonmem_cmp);
    for_each(ivec.begin(), ivec.end(), print_res);
    cout << endl;

    return 0;
}