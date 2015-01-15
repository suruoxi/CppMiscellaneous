/*************************************************************************
    > File Name: stlHeap.cpp
    > Author: Peng Zhang
    > Mail: pengzhang_live@live.com 
    > Created Time: 2015-01-15
 ************************************************************************/

// range heap example
#include <iostream>     // std::cout
#include <algorithm>    // std::make_heap, std::pop_heap, std::push_heap, std::sort_heap
#include <vector>       // std::vector

using namespace std;

int main () {
  int myints[] = {10,20,30,5,15};
  std::vector<int> v(myints,myints+5);

  std::make_heap (v.begin(),v.end());            // 默认是最大堆
  std::cout << "initial max heap   : " << v.front() << '\n';

  std::pop_heap (v.begin(),v.end());             // 这里只是将堆顶元素换到最后，剩余部分重新堆化，这个最后元素还是可以访问的
  v.pop_back();                                  // 真正删除最后一个元素，即pop前的堆顶元素了
  std::cout << "max heap after pop : " << v.front() << '\n';

  // 由于堆并不是独立的数据结构，而是在已有数据上操作，所以这里要在实际数据中push，然后才重新堆化
  v.push_back(99); 
  std::push_heap (v.begin(),v.end());
  std::cout << "max heap after push: " << v.front() << '\n';

  // 默认自然是升序排列
  std::sort_heap (v.begin(),v.end());

  std::cout << "final sorted range :";
  for (unsigned i=0; i<v.size(); i++)
    std::cout << ' ' << v[i];

  std::cout << '\n';

  return 0;
}
