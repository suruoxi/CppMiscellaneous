/*************************************************************************
    > File Name: stlUnique.cpp
    > Author: Peng Zhang
    > Mail: pengzhang_live@live.com 
    > Created Time: 2015-01-15
 ************************************************************************/

// unique用于去除连续重复元素

// unique algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::unique, std::distance
#include <vector>       // std::vector

bool myfunction (int i, int j) {
  return (i==j);
}

int main () {
  int myints[] = {10,20,20,20,30,30,20,20,10};           // 10 20 20 20 30 30 20 20 10
  std::vector<int> myvector (myints,myints+9);

  // using default comparison:
  std::vector<int>::iterator it;
  it = std::unique (myvector.begin(), myvector.end());   // 10 20 30 20 10 ?  ?  ?  ?
                                                         //                ^

  myvector.resize( std::distance(myvector.begin(),it) ); // 10 20 30 20 10 这里也可用 erase

  // print out content:
  std::cout << "myvector contains:";
  for (it=myvector.begin(); it!=myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  std::string str("hello   world  ss xx   y");
  std::string::iterator last =  std::unique(str.begin(), str.end());

  str.erase(last, str.end());

  std::cout<<str<<std::endl;

  return 0;
}
