/*************************************************************************
    > File Name: stlHeapArray.cpp
    > Author: Peng Zhang
    > Mail: pengzhang_live@live.com 
    > Created Time: 2015-01-15
 ************************************************************************/

#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int myints[] = {
		10,20,30,5,15
	};
	make_heap (myints, myints+5);
	cout<<"initial max heap "<<myints[0]<<endl;

	sort_heap(myints, myints+5);
	for(int i=0; i < 5; i++)
		cout<<myints[i]<<'\t';
	cout<<endl;

	return 0;
}
