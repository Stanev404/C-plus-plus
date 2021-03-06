#include <iostream>
using namespace std;
typedef int T;
class List;
class ListIterator;
struct Node{
	Node * next;
	T value;
	Node(T val) : value(val),next(nullptr){};
	Node(T val, Node * next) : value(val), next(next){};
	Node() : next(nullptr),value(0) {};

};
class ListIterator: public Node{
private:
	Node * current;
	friend class List;
public:
	ListIterator(){};
	ListIterator(Node * curr) : current(curr){};
	bool not_equals(ListIterator b){
		if (current != b.current)
			return true;
		else
			return false;
	}
	void next(){
		  current = current->next;
	}
	T get(){
		return current->value;
	}

};
class List :public ListIterator{
private:
	Node * head;
	Node * tail;
	T cnt;
public:
	List() : cnt(0), head(nullptr), tail(nullptr){ };
	void push(T val){
		Node * newnode = new Node(val);
		if (cnt > 0){
			newnode->next=head;
			head = newnode;
		}
		else{
			head = newnode;
			tail = newnode;
		}
		cnt++;
	}
	ListIterator begin(){
		return ListIterator(head);
	}
	ListIterator end(){
		return ListIterator(nullptr);
	}
	void insert(ListIterator insert, T val){ // 1 3 4 , 1 2 3 4
		Node * curr = new Node;
		for (ListIterator it = begin(); it.not_equals(insert); it.next())
			curr = it.current;
		
		Node * newnode = new Node(val);
		curr->next = newnode;
		newnode->next = insert.current;
	

	}
	void erase(ListIterator b){
		Node * newnode = new Node;
		for (ListIterator it = begin(); it.not_equals(b); it.next())
			newnode = it.current;
			Node * nextnode = new Node;
		nextnode = b.current->next;
		newnode->next = nextnode;
	}
};


int main() {
	List list;
	list.push(4);
	list.push(3);
	list.push(1);
	
	for (ListIterator it = list.begin(); it.not_equals(list.end()); it.next()) {
		std::cout << it.get() << " ";
	}
	std::cout << std::endl;
	
	ListIterator begin = list.begin();
	begin.next();

	list.insert(begin, 2);
	
	for (ListIterator it = list.begin(); it.not_equals(list.end()); it.next()) {
		std::cout << it.get() << " ";
	}
	std::cout << std::endl;
	

	begin = list.begin();
	begin.next();
	begin.next();
	list.erase(begin);
	
	for (ListIterator it = list.begin(); it.not_equals(list.end()); it.next()) {
		std::cout << it.get() << " ";
	}
	std::cout << std::endl;
	
	system("pause");
	return 0;
}
