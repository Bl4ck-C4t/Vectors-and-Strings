#include <iostream>
#include <string>
using namespace std;

template <class T>
class Vector {
private:
	int capacity_;
	int size_;
	T *data_;

	void resize() {
		capacity_ *= 2;
		int *new_data = new T [capacity_];
		for(int i=0; i < size_; i++){
			new_data[i] = data_[i];
		}
		delete data_;
		data_ = new_data;
		
	}

	void shift_left(int index){
		for(int i=index; i < size()-1; i++){
			data_[i] = data_[i+1];
		}
	}

	void shift_right(int index){
		for(int i=size(); i != index-1; i--){
			data_[i] = data_[i-1];
		}
	}

public:
	class VectorExp {
	private:
		string message_;
	public:
		VectorExp(string mes) : message_(mes) {}
		void print_error(){
			cout << "ERR: " << message_ << endl;
		}
	};

	class VectorIter{
	private:
		int current_;
		Vector& vector_;

	public:
		VectorIter(int start, Vector& vec) :  current_(start), vector_(vec) {}

		

		VectorIter& operator++(){
			current_++;
			return *this;
		}

		VectorIter operator++(int n1){
			VectorIter it2 = *this;
			current_++;
			return it2;
		}

		T& operator*(){
			return vector_[current_];
		}

		bool operator!=(VectorIter other) {
			return current_ != other.current_ && &vector_ == &other.vector_;
		}

	};

	class VectorConstIter{
	private:
		int current_;
		const Vector& vector_;

	public:
		VectorConstIter(int start, const Vector& vec) :  current_(start), vector_(vec) {}

		

		VectorConstIter& operator++(){
			current_++;
			return *this;
		}

		VectorConstIter operator++(int n1){
			VectorConstIter it2 = *this;
			current_++;
			return it2;
		}

		T operator*(){
			return vector_[current_];
		}

		bool operator!=(VectorConstIter other) {
			return current_ != other.current_ && &vector_ == &other.vector_;
		}

	};

	class VectorRevIter{
	private:
		int current_;
		Vector& vector_;

	public:
		VectorRevIter(int start, Vector& vec) :  current_(start), vector_(vec) {}

		
		VectorRevIter& operator--(){
			current_--;
			return *this;
		}

		VectorRevIter operator--(int n1){
			VectorRevIter it2 = *this;
			current_--;
			return it2;
		}

		T& operator*(){
			return vector_[current_];
		}

		bool operator!=(VectorRevIter other) {
			return current_ != other.current_ && &vector_ == &other.vector_;
		}

	};

	class VectorConstRevIter{
	private:
		int current_;
		const Vector& vector_;

	public:
		VectorConstRevIter(int start, const Vector& vec) :  current_(start), vector_(vec) {}

		
		VectorConstRevIter& operator--(){
			current_--;
			return *this;
		}

		VectorConstRevIter operator--(int n1){
			VectorConstRevIter it2 = *this;
			current_--;
			return it2;
		}

		T operator*(){
			return vector_[current_];
		}

		bool operator!=(VectorConstRevIter other) {
			return current_ != other.current_ && &vector_ == &other.vector_;
		}

	};

	Vector() {
		capacity_ = 1;
		size_ = 0;
		data_ = new T [1];
	}
	Vector(Vector& other){
		size_ = other.size_;
		capacity_ = other.capacity_;
		int *new_data = new T [capacity_];
		for(int i=0; i < size_; i++){
			new_data[i] = other.data_[i];
		}
		data_ = new_data;
	}

	~Vector() {
		delete data_;
	}

	bool empty() const{
		return size_ == 0;
	}

	int size() const {
		return size_;
	}

	int capacity() const {
		return capacity_;
	}

	int& front() const {
		return data_[0];
	}

	int& last() const {
		return data_[size_-1];
	}

	void push(T val) {
		if(size_+1 > capacity_){
			resize();
		}
		data_[size_++] = val;
	}

	void pop_back() {
		if(empty()) {
			throw VectorExp("Cannot pop when vector is empty");
		}
		size_--;
	}

	void clear() {
		size_ = 0;
	}

	void remove(T el){
		for(int i=0; i < size()-1; i++){
			if(data_[i] == el ){
				shift_left(i);
				break;
			}
		}
		size_--;
		
	}

	void del(int index){
		shift_left(index);
		size_--;
	}

	void insert(int index, T val){
		if(size_+1 > capacity_){
			resize();
		}
		shift_right(index);
		data_[index] = val;
		size_++;
	}

	VectorIter begin(){
		return VectorIter(0, *this);
	}

	VectorRevIter rbegin(){
		return VectorRevIter(size_-1, *this);
	}

	VectorIter end() {
		return VectorIter(size_, *this);
	}

	VectorRevIter rend() {
		return VectorRevIter(-1, *this);
	}

	VectorConstIter begin() const{
		return VectorConstIter(0, *this);
	}

	VectorConstRevIter rbegin()const{
		return VectorConstRevIter(size_-1, *this);
	}

	VectorConstIter end() const{
		return VectorConstIter(size_, *this);
	}

	VectorConstRevIter rend() const{
		return VectorConstRevIter(-1, *this);
	}


	//OPERATOR OVERLOADING
	T& operator[](int index){
		if(index >= size_ || -index >= size_){
			throw VectorExp("Invalid index.");
		}
		if(index < 0) {
			return data_[size_+index];
		}
		return data_[index];
	}

	T operator[](int index) const{
		if(index >= size_ || -index >= size_){
			throw VectorExp("Invalid index.");
		}
		if(index < 0) {
			return data_[size_+index];
		}
		return data_[index];
	}

	void operator=(Vector& other){
		Vector v1(other);
		size_ = v1.size_;
		capacity_ = v1.capacity_;
		delete other.data_;
		data_ = v1.data_;
	}

	
};

int main(int argc, char const *argv[])
{
	Vector<int> v1;
	v1.push(6);
	v1.push(3);
	v1.push(7);
	v1.push(3);
	v1.push(100);
	//v1.insert(1, 69);
	//v1.insert(1, 89);
	const Vector<int> v2(v1);
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
	cout << "forward:" << endl;
	for(Vector<int>::VectorIter it = v1.begin(); it != v1.end(); ++it){

		cout << *it << endl;
	}

	cout << endl << "forward_const:" << endl;
	for(Vector<int>::VectorConstIter it = v2.begin(); it != v2.end(); ++it){

		cout << *it << endl;
	}

	cout << endl << "reversed:" << endl;
	for(Vector<int>::VectorRevIter it = v1.rbegin(); it != v1.rend(); --it){

		cout << *it << endl;
	}

	cout << endl << "reversed_const:" << endl;
	for(Vector<int>::VectorConstRevIter it = v2.rbegin(); it != v2.rend(); --it){

		cout << *it << endl;
	}
	return 0;
}