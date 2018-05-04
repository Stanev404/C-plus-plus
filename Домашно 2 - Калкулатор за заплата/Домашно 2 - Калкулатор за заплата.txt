#include <iostream>
#include <istream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

class Deduction{
public:
	virtual double Tax(double salary) = 0;
	virtual string getName() = 0;
};
class IncomeTax : public Deduction{
private:
	double percent;
public:
	IncomeTax(double percent) : percent(percent){};
	double Tax(double salary){
		double result = 0;
		if (salary >= 0)
			result = salary * percent / 100;
		else return 0;
		return result;
	}
	string getName(){
		return "Income Tax";
	}
};
class SocialSecurityTax : public Deduction{
private:
	double balance;
	double percent;
public:
	SocialSecurityTax(double percent, double balance) : percent(percent), balance(balance){};
	string getName(){
		return "Social Security Tax";
	}
	double Tax(double salary){
		if (salary >= balance)
			return balance * percent / 100;
		else
			return salary * percent / 100;
	}

};
class Calculator{
private:
	vector<Deduction *> deduct;
public:
	Calculator(vector<Deduction *> deduct) : deduct(deduct){};
	void analyze(double salary, ostream & out){

		double money = 0;
		double balance = 0;
		double res = 0;
		static int k = 0;
		if (k == 0){
			out << "                  Gross salary" << "      " << salary << " BGN" << endl;
			out << "--------------------------------------------" << endl;
			out << "           " << deduct[0]->getName();
			money = deduct[0]->Tax(salary); //468
			balance = salary - money; // 2600 - 468
			res = money; // 468
			out << "      -" << money << " BGN" << endl;

			out << "                    " << deduct[1]->getName();
			money = deduct[1]->Tax(balance); // 213
			res += money; // 670
			out << "       -" << money << " BGN" << endl;
			out << "============================================" << endl;


			out << "                    " << "Net Salary" << "       " << salary - res << " BGN" << endl;
			k++;
		}
		else{
			out << "                  Gross salary" << "      " << salary << " BGN" << endl;
			out << "--------------------------------------------" << endl;
			for (int i = 0; i < 2; i++){
				if (deduct[i]->getName() == "Social Security Tax"){
					out << "           " << deduct[i]->getName();
					money = deduct[i]->Tax(salary); //468
					balance = salary - money; // 2600 - 468
					res = money; // 468
					out << "      -" << money << " BGN" << endl;
				}
				else{
					out << "                    " << deduct[i]->getName();
					money = deduct[i]->Tax(balance); // 213
					res += money; // 670

					if (money / 100 == 0)
						out << "-" << money << " BGN" << endl;
					else
						out << "    -" << money << " BGN" << endl;
				}
			}
			out << "============================================" << endl;


			out << "                    " << "Net Salary" << "    " <<  salary - res << " BGN" << endl;
		}
	}
};
vector<Deduction *> loadDeductions(string path){
	vector<Deduction *> result;
	string type, type1;
	double percent, percent1, balance;
	ifstream inp_data;
	inp_data.open(path);
	if (inp_data.fail()){
		cout << "Error opening file";
		return result;
	}

	getline(inp_data, type, ':');
	inp_data >> percent >> balance;
	getline(inp_data, type1, ':');
	inp_data >> percent1;

	SocialSecurityTax * social = new SocialSecurityTax(percent, balance);
	IncomeTax * income = new IncomeTax(percent1);
	result.push_back(social);
	result.push_back(income);
	inp_data.close();
	return result;

}
void prepareIniFile() {
	int configLinesCount;
	cin >> configLinesCount;
	string configLine;
	getline(cin, configLine); // trailing end of line
	ofstream fout("config.ini");
	for (int i = 0; i < configLinesCount; i++) {
		getline(cin, configLine);
		fout << configLine << endl;
	}
	fout.close();
}

int main(int argc, char *argv[]) {

	//prepareIniFile();

	vector<Deduction *> deductions = loadDeductions("config.ini");

	double salary;
	Calculator calc(deductions);
	while (cin >> salary) {
		calc.analyze(salary, cout);
		cout << endl;
	}
	
	system("pause");
	return 0;
}
