#include <iostream>
#include <map>
#include <fstream>
#include <string>
using namespace std;

const int ALPHABET_SIZE = 26;

class Node{
public:
	bool is_end;
	Node * child[ALPHABET_SIZE];
};

class Trie : public Node{
public:
	Node * head;

	Trie(){
		head = new Node();
		head->is_end = false; 
	}
	void insert(string word){
		Node * current = head;
		for (int i = 0; i < word.length(); i++)
		{
			int letter = (int)word[i] - (int)'a';
			if (letter < 0 || letter > 27) // tuk zashtoto nqkoi put naprimer char-a e '-' i letter stava otricatelno chislo i nqma kak da dostupim otricatelna stoinosti v child
				continue;
			else if (current->child[letter] == nullptr){
				current->child[letter] = new Node();
			}
					

			
			current = current->child[letter];
		}
		current->is_end = true;
	}

	bool search(string word){
		Node * current = head;
		for (int i = 0; i < word.length(); i++){
			int letter = (int)word[i] - (int)'a';
			if (letter < 0 || letter > 27) // tuk
				continue;
			if (current->child[letter] == nullptr)
				return 0;
			current = current->child[letter];
		}
		return current->is_end;
	}

	void load_file(string file_name){
		ifstream inp(file_name);

		if (inp.fail()) return;
		
		string word;

		while (!inp.eof()){
			inp >> word;
			insert(word);

		}


		inp.close();
	}
};


int main(){
	
	Trie ivan;
	ivan.load_file("words.txt");

	string word = "un-----come-at-able";

	if (ivan.search(word))
		cout << "Yes there is a word " << word << " in the dictionary." << endl;

	system("pause");
	return 0;
}