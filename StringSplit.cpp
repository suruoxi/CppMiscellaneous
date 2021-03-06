/*************************************************************************
    > File Name: StringSplit.cpp
    > Author: Peng Zhang
    > Mail: pengzhang_live@live.com 
    > Created Time: 2014-11-28
    > Source:  http://stackoverflow.com/questions/236129/split-a-string-in-c?page=1&tab=votes#tab-top
 ************************************************************************/
/*
 *	Split a string into tokens in C++
 */
#include<iostream>
#include<string>
#include<vector>
#include<stringstream>
#include<boost/algorithm/string.hpp>
#include<boost/tokenizer.hpp>
#include<boost/foreach.hpp>
using namespace std;
using namespace boost;
// everyone likes boost
vector<string> splitV4(string s){
	vector<string> res;
	boost::split( res, s, boost::is_any_of("\t ;,")); // delimiters
	return res;
}

// another boost solution
vector<string> splitV5(string s){
	char_separator<char> sep('\t');
	tokenizer<char_separator<char> > tokens(text, sep);
	BOOST_FOREACH(string t, tokens){
		cout<<t<<endl;
	}
}
// all the follow solutions work for blank delimiter
vector<string> splitV1(string s){
	istringstream iss(s);
	vector<string> res;
	do{
		string token;
		iss >> token;
		res.push_back(token);
	}while(iss);
	return res;
}

vector<string> splitV2(string s){
	istringstream iss(s);
	vector<string> res;
	copy( istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(res) );
	return res;
}

//
vector<string> splitV3(string s){
	vector<string> res{ istream_iterator<string>{iss}, istream_iterator<string>{} };
	return res;
}


