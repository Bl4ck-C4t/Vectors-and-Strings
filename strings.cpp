#include <iostream>
#include "string.h"
using namespace std;


int main(int argc, char const *argv[])
{
	/*
	Vector<char> v1;
	v1.push('a');
	v1.push('a');
	v1.push('a');
	v1.push('a');
	for(Vector<char>::VectorIter it = v1.begin(); it != v1.end(); ++it){
		cout << *it << endl;
	}

	cout << v1[1] << endl;
	*/
	String s1("Hello");
	String s2(" World");
	Vector<char> v1 = (Vector<char>)s2;
	cout << v1;
	return 0;
	String se();
	s1 += s2;
	s1 += "!\n";
	String s3; 
	s3 = s1.reverse();
	//s1 = s1.reverse();
	//s3.del(0);
	//s1 = s3;
	//s1 = ;
	//s1.del(200);
	bool a = s3 == s1;
	//s1["::-1"];
	s2 = s1[":8"];
	cout <<  s2 << endl;
	return 0;
}
