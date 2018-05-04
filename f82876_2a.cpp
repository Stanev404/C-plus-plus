#include <iostream>
#include <stdlib.h> 
using namespace std;


int main(){
	int s;
	long long int N;
	int primeCount=0;
			
	// Set the boolean array
	bool checkPrime[1000];
	checkPrime[0]=false;
	for(int i=2;i<1000;i++) checkPrime[i]=true;
	int countPrime=0;
	//Maths time
	for(int i=2;i<33;i++){
		if(checkPrime[i]==true){
			for(int j=i*i;j<1000;j+=i)
				checkPrime[j]=false;
		}
	}
	while(cin>>s>>N){
		if(s>0 && s<1000 && N>0 && N<1000000000){
			srand(s);
			int resultPrimes=0;
			// Generate N random numbers
			for(int i=0;i<N;i++)
			{
				int newRandom=rand()%1000;
				//check if newRandom is prime
				if(checkPrime[newRandom-1]) {
					resultPrimes++;	
				}
			}		
			cout<<resultPrimes<<endl;
		}
		else {
			cout<<"Wrong Input"<<endl;
		}
	}		
}
