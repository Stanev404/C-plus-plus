#include <iostream>
#include <string>

using namespace std;
class CException{
public:
	CException(){
		err = "some error";
	}
	CException(string error){
		err = error;
	}
	string get_error(){
		return err;
	}
	string err;
};
class CExceptionOverFlow : public CException{
public:
	CExceptionOverFlow() : CException("Stack Overflow exception !"){};
};


class CExceptionEmptyStack : public CException {
public:
	CExceptionEmptyStack() : CException("Stack is empty exception !"){};
};

template<typename T>
class CStack{ // abstract class, pure virtual
public:
	CStack(){};
	virtual ~CStack(){};
	virtual void push(T * pushed_one) throw (CExceptionOverFlow) = 0;
	virtual T* pop() throw (CExceptionEmptyStack) = 0;
	//virtual void resize() = 0;
};

template<typename T>
class AStack : public CStack<T>{
public:
	int sz;
	int count;
	T ** elements;
	AStack(){
		count = 0;
		sz = 10;
		elements = new T *[sz];
	}
	AStack(int num){
		if (num <= 0) sz = 2;
		else sz = num;

		count = 0;

		elements = new T*[sz];
	}
	virtual void push(T * pushed_one) throw(CExceptionOverFlow)
	{
		if (count < sz){
			elements[count] = pushed_one;
			count++;
		}
		else{
			throw CExceptionOverFlow();
		}
	}
	virtual T* pop() throw(CExceptionEmptyStack){
		if (count != 0){
			T * popped = elements[count - 1];
			delete elements[count - 1]; 
			count--;
			return popped;
			}
		else{
			throw CExceptionEmptyStack();
		}
	}
	void trace(){
		for (int i = 0; i < count; i++){
			cout << *elements[i] << " " ;
		}
		cout << endl;
		//if(count !=0) cout << endl; tva e ako pechatim v obraten red
	}
	/*virtual void resize(){

	}*/
	virtual ~AStack(){
		delete[]elements;
		cout << "Destructor" << endl;
//		system("pause");
	}


};

int main(){

	AStack<string> ivan(4);
	try{
		ivan.push(new string("kola"));
		ivan.push(new string("divan"));
		ivan.trace();
		ivan.push(new string("ochila"));
		ivan.push(new string("kotka"));
		ivan.trace();
	}
	catch (CExceptionEmptyStack e){
		cout << e.get_error() << endl;
	}
	catch (CExceptionOverFlow e){
		cout << e.get_error() << endl;
	}
	catch (...){
		cout << CException().get_error() << endl;
	}

	system("pause");
	return 0;
}