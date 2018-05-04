
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


string move(string s, string num) {
	string res, buff, buff1;
	istringstream convert(num);
	int real;
	convert >> real;
	if (real < s.size()) {
		buff = s.substr(real, s.size());
		buff1 = s.substr(0, real);
		res = buff + buff1;
	}
	else {
		while (real > s.size()) {
			real -= s.size();
		}
		buff = s.substr(real, s.size());
		buff1 = s.substr(0, real);
		res = buff + buff1;
	}
	return res;
}




bool isNumber(string s) {
	if (s[0] < ':' && s[0] > '/') return true;
	return false;
}





int main() {
	string word, num, buff;
	while (cin >> word) {

		if (isNumber(word)) {
			string s = move(buff, word);
			cout << s << endl;
		}

		else  buff = word;
	}
	return 0;
}
