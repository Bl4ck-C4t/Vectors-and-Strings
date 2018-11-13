#include "vector_t.h"
#include <iostream>
using namespace std;


class String : public Vector<char> {
public:
	String(const char* str) : Vector(){
		//Vector();
		*this += str;
	}

	String() : Vector(){
		//Vector();
	}

	String(Vector<char> vec) {
		size_ = vec.size();
		capacity_ = vec.capacity();
		data_ = new char [vec.capacity()];
		for(int i=0; i < vec.size(); i++) {
			data_[i] = vec[i];
		}
	}

	int index_of(const char* word) const{
		bool found;
		for(int i=0; i < size(); i++){
			if(data_[i] == word[0]){
				found = true;
				for(int j=0; word[j] != '\0'; j++){
					if(word[j] != data_[i+j]){
						found = false;
						break;
					}
				}
			}
			if(found){
				return i;
			}
		}
		return -1;
	}

	bool contains(const char* word) const{
		return index_of(word) != -1;
	}

	bool contains(String& str) const{
		return index_of(str.data_) != -1; // Not working / bugged
	}

	//OPERATOR OVERLOADING
	String& operator+=(char c){
		push(c);
		return *this;
	}

	String& operator+=(const char* str){
		for(int i=0; str[i] != '\0'; i++){
			*this += str[i];
		}
		return *this;
	}

	String& operator+=(String& str){
		*this += str.data_;
		return *this;
	}

	void operator=(const char* str){ // load new literal
		size_ = 0;
		*this += str;
	}

	void operator=(Vector<char> other){ // deep copies the vector into the string 
		//copy the data from the here
		
		delete data_;
		size_ = other.size();
		capacity_ = other.capacity();
		data_ = new char [other.capacity()];
		for(int i=0; i < other.size(); i++) {
			data_[i] = other[i];
		}
		//other.~Vector();*/
	}

	void operator=(String& other){
		//Vector v1(other);
		delete data_;
		size_ = other.size();
		capacity_ = other.capacity();
		data_ = new char [other.capacity()];
		for(int i=0; i < other.size(); i++) {
			data_[i] = other[i];
		}
	}

	bool operator==(String& str1) {
		if(size_ != str1.size_){
			return false;
		}
		for(int i=0; i < size_; i++){
			if(data_[i] != str1[i]){
				return false;
			}
		}
		return true;
	}

	operator Vector<char>(){ // CAST to a char vector from string
		Vector<char> v1;
		for(int i=0; i < size_; i++){
			v1.push(data_[i]);
		}
		return v1;
	}

};

ostream& operator<<(ostream& out, const String& str){
    for(int i=0; i < str.size(); i++){
			out << str[i];
	}
	//out << endl;
    return out;
}
