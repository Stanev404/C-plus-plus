#include <iostream>
#include <string>

using namespace std;

int ConvertPos(char curPos){
    switch (curPos){
    case '0': return 0;
    case '1': return 1;
    case '2': return 2;
    case '3': return 3;
    case '4': return 4;
    case '5': return 5;
    case '6': return 6;
    case '7': return 7;
    case '8': return 8;
    case '9': return 9;
    case 'A': return 10;
    case 'B': return 11;
    case 'C': return 12;
    case 'D': return 13;
    case 'E': return 14;
    case 'F': return 15;
    }
}


void transfer(int base, string x) {
    int sum = 0;
    for (int i = 0; i < x.size(); i++) {
        int size = x.size();
        int num = ConvertPos(x[i]);
        int final = 1;
        while (size - i > 1) {
            final *= base;
            size--;
        }
        sum += num * final;
    }
    cout << sum << endl;
}



int main() {
    int a;
    string b;

    while (cin >> a && cin >> b){
        transfer(a, b);
    }

    return 0;
}
