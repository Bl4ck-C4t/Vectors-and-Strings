#include <iostream>
#include <string>
using namespace std;
//TODO finish the substring [::] operator
template <class T>
class Vector {
protected:
	int capacity_;
	int size_;
	T *data_;

	void index_check(int index) const{
		if(index > size_ || -index > size_){
			throw VectorExp::index_err;
		}
	}

	void resize() {
		capacity_ *= 2;
		T *new_data = new T [capacity_];
		for(int i=0; i < size_; i++){
			new_data[i] = data_[i];
		}
		delete data_;
		data_ = new_data;
		
	}

	void check_resize() {
		if(size_+1 > capacity_){
			resize();
		}
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
	friend class Vector;

	private:
		string message_;
		static const VectorExp index_err;
		static const VectorExp empty_err;
		/*
		static VectorExp index_err{
			return VectorExp("invalid index.");
		}

		static VectorExp empty_err{
			return VectorExp("collection is empty.");
		}
		*/
	public:

		VectorExp(string mes) : message_(mes) {}

		void print_error() const{
			cout << "ERR: " << message_ << endl;
		}
	};
	/*
	const VectorExp VectorExp::index_err = VectorExp("invalid index.");
	const VectorExp VectorExp::empty_err = VectorExp("collection is empty.");
	*/


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
	Vector(const Vector& other){
		size_ = other.size_;
		capacity_ = other.capacity_;
		T *new_data = new T [capacity_];
		for(int i=0; i < size_; i++){
			new_data[i] = other.data_[i];
		}
		data_ = new_data;
	}

	~Vector() {
		delete data_;
		data_ = nullptr;
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
		check_resize();
		data_[size_++] = val;
	}

	void pop_back() {
		if(empty()) {
			throw VectorExp::empty_err;
		}
		size_--;
	}

	void clear() {
		size_ = 0;
	}

	void del(int index){
		index_check(index);
		shift_left(index);
		size_--;
	}

	void remove(T el){
		for(int i=0; i < size()-1; i++){
			if(data_[i] == el ){
				del(i);
				break;
			}
		}
	}

	void insert(int index, T val){
		index_check(index);
		check_resize();
		shift_right(index);
		data_[index] = val;
		size_++;
	}

	Vector reverse() const{
		Vector v_cpy(*this);
		Vector v_cpy_res(*this);
		int i=0;
		for(VectorRevIter it = v_cpy.rbegin(); it != v_cpy.rend(); --it, i++){
			v_cpy_res.data_[i] = *it;
		}
		return v_cpy_res;
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

	VectorConstRevIter rbegin() const{
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
		index_check(index);
		if(index < 0) {
			return data_[size_+index];
		}
		return data_[index];
	}

	Vector<T> operator[](const char* c){ //::-1 0:3:-6
		//cout << "Running" << endl;
		Vector<T> sub;
		string sub_str;
		int start;
		int end;
		short int states = 0;
		int step = 1;
		int n=0;

		for(int i=0; c[i] != '\0'; i++){
			if(c[i] == ':'){
				if(sub_str != ""){
					int a = stoi(sub_str);
					switch(n){
					case 0:
						start = a;
						break;
					case 1:
						end = a;
						break;
					case 2:
						step = a;
					}
				}
				else{
					if(n == 0){
						states = 1;
					}
					if(n == 1){
						states += 2;
					}
				}
				sub_str = "";
				n++;
				continue;
			}
			sub_str.push_back(c[i]);
		}
		
		if(sub_str != ""){
			int a = stoi(sub_str);
			switch(n){
			case 0:
				start = a;
				break;
			case 1:
				end = a;
				break;
			case 2:
				step = a;
			}
		}
		//cout << states;
		start = start < 0 ? size_+start : start;
		end = end < 0 ? size_+end : end;
		if(states == 1){
			start = step < 0 ? size_-1 : 0;
			if(c == ":"){
				end = size_;
			} 
		}
		if(states == 2){
			end = step < 0 ? -1 : size_;
		}
		if(states == 3){
			start = step < 0 ? size_-1 : 0;
			end = step < 0 ? -1 : size_;
		}
		
		index_check(start);
		index_check(end);
		if(step < 0){
			for(int i=start; i > end; i+=step){
			    //cout << i << endl;
				sub.push(data_[i]);
			}
		}
		else{
			for(int i=start; i < end; i+=step){
				//cout << i << endl;
				sub.push(data_[i]);
			}
		}

		return sub;
		/*
		cout << start << endl;
		cout << end << endl;
		cout << step << endl;*/
	}

	T operator[](int index) const{
		index_check(index);
		if(index < 0) {
			return data_[size_+index];
		}
		return data_[index];
	}

	void operator=(Vector<T>& other){
		//Vector v1(other);
		size_ = other.size_;
		capacity_ = other.capacity_;
		//delete other.data_;
		data_ = other.data_;
		other.data_ = nullptr;
	}

	void operator=(Vector<T> other){
		//Vector v1(other);
		size_ = other.size_;
		capacity_ = other.capacity_;
		//delete other.data_;
		data_ = other.data_;
		other.data_ = nullptr;
	}

	bool operator==(Vector<T>& vec) {
		if(size_ != vec.size_){
			return false;
		}
		for(int i=0; i < size_; i++){
			if(data_[i] != vec[i]){
				return false;
			}
		}
		return true;
	}

	
};

template <class T>
const typename Vector<T>::VectorExp Vector<T>::VectorExp::index_err = Vector<T>::VectorExp("invalid index.");
template <class T>
const typename Vector<T>::VectorExp Vector<T>::VectorExp::empty_err = Vector<T>::VectorExp("collection is empty.");

//const Vector<T>::VectorExp VectorExp::empty_err = VectorExp("collection is empty.");

template <class T>
ostream& operator<<(ostream& out, Vector<T>& vec){
    for(int i=0; i < vec.size(); i++){
			out << vec[i] << endl;
	}
	//out << endl;
    return out;
}

