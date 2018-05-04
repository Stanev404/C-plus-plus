
// F82876 Иван Станев
#include <iostream>
#include <iomanip>

using namespace std;

long double func(long double x, long double a)
{
	return x*x*x*x*x - a*x*x - 76; // F82876
}


int main(){

	long double d;

	cin >> d;
	long double a = 0; // GRANICI
	long double b = 10; // GRANICI
	int MaxLoops = 1000;

	if (func(a, d)*func(b, d) >= 0) cout << "NO SOLUTION" << endl;
	else{
		long double c = a;
		int count = 0;
		while (true){
			c = (a + b) / 2;

			if (func(c, d) == 0 || count > MaxLoops)
			{
				break;
			}

			if (func(c, d) == 0 || count > MaxLoops)  break;

			else if ((func(c, d) * func(a, d) < 0)){
				b = c;

			}
			else if (func(c, d)*func(b, d) < 0){
				a = c;
			}
			else cout << "NO SOLUTION" << endl;
			count++;
		}

		cout << fixed << setprecision(19) << c << endl;
	}




	
	return 0;
}
