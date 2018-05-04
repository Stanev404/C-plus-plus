#include <iostream>
#include <stdlib.h>
using namespace std;

bool prime(int num){
	int cnt = 0;
	for (int i = 1; i <= num; i++)
	{
		if (num % i == 0)
			cnt++;
	}
	if (cnt == 2)
		return true;
	return false;
}


int main() {

	int Array[10000], number;

	while (cin >> number){
		srand(number);
		int PrimeCount = 0;
		for (int i = 0; i < 10000; i++)
		{
			Array[i] = rand() % 10000;
			if (prime(Array[i]))
				PrimeCount++;
		}
		cout << PrimeCount << endl;
	}


	return 0;
}
