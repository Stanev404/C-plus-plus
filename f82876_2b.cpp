#include <iostream>
const int T = 10000;
using namespace std;
int NOD(int a, int b){
	int r;
	while (b != 0){
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int main(){
	int a, b, c, d;
	char p;

	while (cin >> a >> p >> b >> p >> c >> p >> d){
		if (a > 0 && a < T && b > 0 && b < T && c > 0 && c < T && d > 0 && d < T){ // просто число и под 10000

			if (b != d){
				int buff = b * d;
				a *= buff / b;
				c *= buff / d;
				int res = a + c;
				if (NOD(res, buff) == 1){
					cout << res << "/" << buff << endl;
				}
				else{
					int nod = NOD(a + c, buff);
					res /= nod;
					buff /= nod;
					if (res == buff) cout << 1 << endl;
					else if (buff == 1) cout << res << endl;
					else
						cout << res << "/" << buff << endl;
				}
			}
			else{
				int res = a + c;
				if (NOD(res, b) == 1)
					cout << res << "/" << b << endl;
				else
				{
					int nod = NOD(res, b);
					res /= nod;
					b /= nod;
					if (b == 1) cout << res << endl;
					else
						cout << res << "/" << b << endl;
				}
			}
		}

		else
			cout << "Bad input !" << endl;

	}




	return 0;
}
