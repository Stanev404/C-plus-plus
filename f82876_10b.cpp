#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <set>
using namespace std;


int main() {
	
	string line;

	while (getline(cin, line)) {
		istringstream inp(line);
		vector<string> vec;
		string word;
		while (inp >> word) {
			vec.push_back(word);
		}
		if (vec.size() == 1) {
			cout << 1 << endl;
		}
		else {
			set<string> res;
			
			for (int i = 0; i < vec.size(); i++) {
				set<char> test;
				string curr = vec[i];
				for (int i = 0; i < curr.size(); i++)
				{
					test.insert(curr[i]);
				}
				set<char>::iterator it = test.begin();
				string final;
				while (it != test.end()) {
					final += *it;
					++it;
				}
				res.insert(final);
			}
			cout << res.size() << endl;
		}
		

	}

	return 0;

}