#include <iostream>
#include "vector_t.h"
using namespace std;


int main(int argc, char const *argv[])
{
	Vector<int> v1;
	Vector<int> e_v;
	Vector<int> v5({1,2,3,4});
	cout << v5;
	v1.push(0);
	v1.push(1);
	v1.push(2);
	v1.push(3);
	v1.push(4);
	Vector<int> v2 = v1.reverse();
	//v1 = v2;
	//v1 = v1.reverse();
	try{
		//bool a = v1 == v2;
		Vector<int> v3 = v1["1:"];
		//e_v.pop_back();
		cout << v3 << endl;

	} catch(Vector<int>::VectorExp e){
		e.print_error();
	}
	
	//v1.insert(1, 69);
	//v1.insert(1, 89);
	/*
	const Vector v2(v1);
	//v1 = v2;
	//v1.clear();
	//v1.pop_back();
	//cout << v1.last() << endl;
	/*
	try{
		cout << v1[5] << endl;
	}catch(Vector::VectorExp e){
		e.print_error();
	}*/
	//cout << v1[1] << endl;
	/*cout << "forward:" << endl;
	for(Vector::VectorIter it = v1.begin(); it != v1.end(); ++it){

		cout << *it << endl;
	}

	cout << endl << "forward_const:" << endl;
	for(Vector::VectorConstIter it = v2.begin(); it != v2.end(); ++it){

		cout << *it << endl;
	}

	cout << endl << "reversed:" << endl;
	for(Vector::VectorRevIter it = v1.rbegin(); it != v1.rend(); --it){

		cout << *it << endl;
	}

	cout << endl << "reversed_const:" << endl;
	for(Vector::VectorConstRevIter it = v2.rbegin(); it != v2.rend(); --it){

		cout << *it << endl;
	}
	*/
	return 0;
}