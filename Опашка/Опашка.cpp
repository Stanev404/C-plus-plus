#include <iostream>
using namespace std;
template<typename T>
struct Node{
	Node(){};
	Node(T val) : value(val), next(nullptr){};
	Node * next;
	T value;

};
template<typename T>
class Queue{
private:
	Node<T> * head;
public:
	Queue(const Queue<T> & copied){
		head = nullptr;

		Node<T> * fakehead = new Node<T>;
		fakehead = copied.head;
		while (fakehead){
			this->push(fakehead->value);
			fakehead = fakehead->next;
			
		}
	}

	Queue() : head(nullptr){};

	void push(T val){
		Node<T> * newnode = new Node<T>(val);
		newnode->next = head;
		head = newnode;
	}
	T pop(){
		Node<T> * newnode = new Node<T>;
		Node<T> * newnode1 = new Node<T>;
		newnode1 = head;
		newnode = head;
		while (newnode1->next->next != nullptr)
			newnode1 = newnode1->next; 

		while (newnode->next != nullptr) // 3 4 5 , 3 4
			newnode = newnode->next;

		T oldvalue = newnode->value;
		newnode1->next = nullptr; // namirame predposlednia i nulirame negovia next
			delete newnode;
			return oldvalue;
	}
	friend ostream& operator<<(ostream &out, Queue<T>& queue){
		Node<T> * newnode = new Node<T>;
		newnode = queue.head;
		while (newnode){
			out << newnode->value << " ";
			newnode = newnode->next;
		}
		return out;
	}
	void printReverse(ostream & out){
		Node<T> * newnode = new Node<T>;
		newnode = head;
		int cnt = 0;
		while (newnode){
			cnt++;
			newnode = newnode->next;
		}

		for (int i = cnt; i > 0; i--){
			newnode = head;
			for (int t = 0; t < i-1; t++)
				newnode = newnode->next;
			out << newnode->value << " ";
		}
		out << endl;
	}
	~Queue(void){
		
		while (head !=nullptr){ // ne raboti 
			Node<T> * temp = new Node<T>;
			temp = head;
			head = head->next;
			delete temp;
		}
	}
};


template <typename T>
void popAndPrint(Queue<T> &queue)
{
	queue.pop();
	cout << queue << endl;
}

int main(int argc, char* argv[])
{
	Queue<int> queue;

	int x;
	while (cin >> x)
	{
		queue.push(x);
	}

	cout << queue.pop() << endl;
	cout << queue.pop() << endl;
	
	cout << queue << endl;
	
	popAndPrint(queue);

	cout << queue << endl;


	Queue<int> copy;
	copy = queue;
	copy.push(10);
	
	cout << queue << endl;
	cout << copy << endl;
	
	queue.printReverse(cout);
	
	system("pause");
	return 0;
}
