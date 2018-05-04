//IVAN STANEV F82876
#include <iostream>
#include <vector>
using namespace std;
int max(int a, int b) {
	if (a >= b) return a;
	else return b;
}

int main() {

	int n,a;
	while (cin >> n) {
		vector<int> vec;
		for (int i = 0; i < n; i++) {
			cin >> a;
			vec.push_back(a);
		}

		vector<int> T(n);
		
		for (int i = 0; i < n; i++) {
			T[i] = 1;
		}

		
		for (int j = 1; j < n; j++) {
			for (int i = 0; i < j; i++) {

				if (vec[i] <= vec[j]) {
					T[j] = max(T[j], T[i] + 1);
				}
			}
			
		}
		int maX = T[0];
		for (int i = 0; i < n-1; i++) {
			if (maX < T[i + 1]) maX = T[i + 1];
		}
		cout << maX << endl;
	}

	return 0;
}