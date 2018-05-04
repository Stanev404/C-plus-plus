#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class Node {
public:
	Node(string s) {
		data = s;
		yes = nullptr;
		no = nullptr;
	}
	Node() {
		yes = nullptr;
		no = nullptr;
	}
	string data;
	Node * yes;
	Node * no;
};

class Tree {
public:
	Tree() {
		root = nullptr;
	}
	Tree(string s) {
		root = new Node(s);
	}
	Node * root;

	void load(char * in_file) {
		ifstream inp;
		inp.open(in_file);
		if (inp.fail()) throw -1; // throw-a e silen tuk 

		vector<string> vec;
		string line;
		while (getline(inp, line)) {
			vec.push_back(line);
		}
		inp.close();
		load_resources(vec, root, 1, vec.size());

	}
	void load_resources(vector<string> & vec, Node *& curr, int pos, int size) {
		curr = new Node(vec[pos]); // SPORNO !!!
		
		if (pos * 2 + 2 < size) {
			load_resources(vec, curr->yes, 2 * pos, size);
			load_resources(vec, curr->no, 2 * pos + 1, size);
		}

	}

	void save(char * out_file) {
		ofstream out;
		out.open(out_file);

		if (out.fail()) return;

		vector<string> vec(2);

		save_resources(vec,root,1);

		int size = vec.size() - 4;
		for (int i = 0; i < size; i++) {
			out << vec[i] << endl;
		}
		out.close();
	}

	void save_resources(vector<string> &vec, Node * curr, int pos) {
		vec[pos] = curr->data;

		if (curr->no && curr->yes) {
			if (vec.size() < 2 * pos* + 2) {
				vec.resize(2 * pos* + 2);
			}
		
		save_resources(vec, curr->yes, 2 * pos);
		save_resources(vec, curr->no, 2 * pos + 1);
		}
	}
};


int main() {
	Tree oracle;

	try {
		oracle.load("saved_game.txt");
	}
	catch(...) {
		oracle.root = new Node("cat");
	}

	while (true) {
		string answer;
		char line[100];
		
		cout << "Are you ready to play the game ? (Y)" << endl;

		cin.getline(line, 99);
		answer = line;

			if (answer == "Y") {
				cout << "Ok, think of an animal." << endl;
			}

		Node * copy_root = oracle.root;

		while (copy_root->yes && copy_root->no) {
			cout << copy_root->data << " (Y/N) ? ";
		
			cin.getline(line, 99);
			answer = line;

			if (answer == "Y") copy_root = copy_root->yes;
			else copy_root = copy_root->no;
		}

		cout << "Is it a " << copy_root->data << " ?  (Y/N) " << endl;
		cin.getline(line, 99);
		answer = line;

		if (answer == "Y") {
			cout << "WINNER WINNER CHICKEN DINNER ! ! !";
			oracle.save("saved_game.txt");
			cout << endl;

			system("pause");
			return 0;
		}

		cout << "You Won !" << endl;
		cout << "What was your animal ?" << endl;
		cin.getline(line, 99);
		answer = line;

		copy_root->no = new Node(copy_root->data);
		copy_root->yes = new Node(answer);

		cout << "Give a qestion that has positive answer for " << copy_root->yes->data << " and negative answer for ";
		cout << copy_root->no->data << "." << endl;
		cout << "The question: ";
		cin.getline(line, 99);
		answer = line;

		copy_root->data = answer;
		cout << endl;

	}

}