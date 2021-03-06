#include <iostream>

using namespace std;
template<class T>
class ArrayIterator;


template<typename T>
class Array {
private:
	int size1; // ÇÀÐÀÄÈ SIZE() âúâ print2
	T * ptr;
public:
	typedef ArrayIterator<T> iterator;
	friend class ArrayIterator<T>;
	
	Array(int n) {
		size1 = n;
		ptr = new T[size1];
		for (int i = 0; i < size1; i++)
			ptr[i] = 0;
	}
	Array(const Array<T> & copied){
		size1 = copied.size1;
		ptr = new T[copied.size1];
		for (int i = 0; i < copied.size1; i++)
			ptr[i] = copied.ptr[i];

	}
	friend ostream& operator <<(ostream& inp, Array<T> &a){
		for (int i = 0; i < a.size1; i++)
			inp << a.ptr[i] << " ";
		return inp;
	}
	T& operator[](int pos){
		return ptr[pos];
	}
	iterator begin(){ // ÒÓÊ ÂÐÚÇÂÀÌÅ ÌÀÑÈÂÀ ÊÚÌ ÈÒÅÐÀÒÎÐÀ
		T * nov = new T;
		nov = ptr;
		*nov = *nov + 1000;
		return iterator(0, nov);
	}
	iterator end(){ // äà ñå âúðòè äîêàòî íå ñòèãíå êðàÿ
		return iterator(size1, nullptr);
	}
	int size(){
		return size1;
	}
	
};
template<typename T>
class ArrayIterator{
private:
	friend class Array<T>;
	T * data;
	int pos;
public:
	ArrayIterator(){};
	ArrayIterator(int pos, T * data) : pos(pos), data(data){};
	bool operator !=(const ArrayIterator<T> & b){
		return !(pos == b.pos);
	}
	ArrayIterator<T> & operator ++(){
		pos = pos + 1;
		*data = data[pos];
		return *this;
	}
	T& operator *(){
		return data[pos];
	}

};


template<typename T>
void print2(Array<T> array) {
	for (int i = 0; i < array.size(); ++i) {
		array[i] *= array[i];
	}
	cout << "2: " << array << endl;
}

int main() {

	int n;
	cin >> n;
	Array<int> arr(n);
	
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << "arr: " << arr << endl;
	
	Array<int> copy = arr;

	
	for (Array<int>::iterator it = copy.begin(); it != copy.end(); ++it) {
		*it = *it + 1000;
	}
	
	cout << "copy: " << copy << endl;
	
	print2(arr);

	cout << "arr: " << arr << endl;
	
	system("pause");
	return 0;
}
