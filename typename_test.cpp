#include <iostream>
//#include "string.h"
#include <string>
using namespace std;

template<class T>
class Point {
	T a_;
public:

	Point(T a){
		a_ = a;
	//sub.push(data_[end]);
	}
	void print(){
		cout << a_ << endl;
	}
};
class VectorExp {

	private:
		string message_;
	
		/*
		static VectorExp index_err{
			return VectorExp("invalid index.");
		}

		static VectorExp empty_err{
			return VectorExp("collection is empty.");
		}
		*/
	public:
		static const VectorExp index_err;
		static const VectorExp empty_err;
		VectorExp(string mes) : message_(mes) {}

		void print_error() const{
			cout << "ERR: " << message_ << endl;
		}
	};
	const VectorExp VectorExp::index_err = VectorExp("invalid index.");
	const VectorExp VectorExp::empty_err = VectorExp("collection is empty.");

int main(int argc, char const *argv[])
{
	//VectorExp err("Test error.");
	//err.print_error();
	VectorExp::index_err.print_error();
	VectorExp::empty_err.print_error();

	return 0;
}