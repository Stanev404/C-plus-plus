#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

#define sz 1000
#define max_value 10000
#define no_parent -1
#define val 100000


int array[sz][sz];
int parent[sz];
int weight[sz];
int vertex[sz];



void Dijkstra(int s, vector<int>input,int& n,int &max){
	
	for(int i=0;i<max;i++){
		weight[i]=val;
	}
	for (int i = 0; i < max; i++){ 
		for (int j = 0; j < max; j++){
			array[i][j] = 0;
		}
	}
	
	for (int i = 0; i+1 < input.size(); i=i+3){ //input
		array[input[i]-1][input[i+1]-1] = input[i+2];
	}
	
	for(int i=0;i<max;i++){
		if(0==array[s][i]){
			weight[i]=max_value;
			parent[i]=no_parent;
		}
		else{
			weight[i]=array[s][i];
			parent[i]=s;
		}
		vertex[i]=1;
	}
	vertex[s]=0;
	parent[s]=no_parent;
	while(true){
		int j=no_parent;
		int sw=max_value;
		for(int i=0;i<max;i++){
			if(vertex[i]&&weight[i]<sw){
				sw=weight[i];
				j=i;
			}
		}
		if(no_parent==j)break;
		vertex[j]=0;
		
		for(int i=0;i<max;i++){
			if(vertex[i]&&array[j][i]!=0){
				if(weight[i]>weight[j]+array[j][i]){
					weight[i]=weight[j]+array[j][i];
					parent[i]=j;
				}
			}
		}
	}
}

void print(int& s,int& max){
	weight[s]=0;
	for(int i=0;i<max;i++){
		if(weight[i]==max_value){
			weight[i]=-1;
		}
		if(weight[i]!=val){
			cout<<weight[i]<<" ";
		}
	}
	cout<<endl;
}
int main(){
	int links;
	int num;
	vector<int>vec;
	while(cin >> links){
	int max=1;
	int cnt=0;
	for(int i=0;i<links*3 ;i++){
		cin>>num;
		if(cnt==3)cnt=0;
		if(cnt!=2){
			if(num>max) max=num;
	
		}
			vec.push_back(num);
		cnt++;
	}
	vector<int>count;
	int counter=0;

	for(int i=0;i<vec.size();i++){
			bool flag=true;
		for(int j=0;j<count.size();j++){
			if(vec[i]==count[j]){
				flag=false;
				break;
			}
		}
		if(flag==true){
			count.push_back(vec[i]);
			counter++;
		}
		
	}
	for(int i=0;i<max;i++){
	Dijkstra(i,vec,counter,max);
	print(i,max);	
}
cout<<endl;
vec.clear();
}
	return 0;
}
