/*************************************************************************
    > File Name: ostream_iterator.cpp
    > Author: Peng Zhang
    > Mail: pengzhang_live@live.com 
    > Created Time: 2015-01-15
 ************************************************************************/

// ostream_iterator example
#include <iostream>     // std::cout
#include <iterator>     // std::ostream_iterator
#include <vector>       // std::vector
#include <algorithm>    // std::copy

int main () {
  std::vector<int> myvector;
  for(int i=0; i <6; ++i)
	  myvector.push_back(i);

  std::ostream_iterator<int> out_it (std::cout,",");
  std::copy ( myvector.begin(), myvector.end(), out_it );
//  std::cout<<std::endl;// 如果不输出一个换行符，就会在末尾输出一个奇怪的 %,不过这只在zsh中出现，应该是zsh的问题 
  return 0;
}
