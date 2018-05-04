/*
Äîâúðøåòå ïðîãðàìàòà, êàòî äîïúëíèòå äåêëàðèðàíèòå òðè êëàñà, çà äà ðåàëèçèðàòå áàíêîâà ëîãèêà.
Íå ìîæå äà ïðîìåíÿòå main ôóíöêèÿòà - åäèíñòâåíî òðÿáâà äà ðåàëèçèðàòå êëàñîâåòå.
class Account - ïðåäñòàâëÿâà ïîòðåáèòåëñêà ñìåòêà. Òóê òðÿáâà äà ðåàëèçèðàòå ëîãèêà ïî òåãëåíå è
äåïîçèðàíå íà ñðåäñòâà, êàòî â íèòî åäèí ìîìåíò áàëàíñúò íå ìîæå äà ñòàâà îòðèöàòåëåí.
class Transaction - ïðåäñòàâëÿâè ïðåâîä íà ñðåäñòâà îò åäíà ñìåòêà (source) äî äðóãà ñìåòêà (target).
Òðàíçàêöèÿòà ïúðâî îïèòâà äà âçåìå ïàðèòå è, åäèíñòâåíî àêî óñïåå, ãè äîáàâÿ êúì öåëåâàòà ñìåêòà.
Òðàíçàêöèÿòà ñúùî òðÿáâà äà å çàùèòåíà îò ïîâòîðíî èçïúëíåíèå.
class Bank - èçïúëíÿâà òðàíñôåðè è ïàçè èñòîðèÿ íà óñïåøíèòå òðàíçàêöèè. Ïðè èçâèêâàíå íà
÷ëåí-ôóíêöèÿòà transfer òðÿáâà äà ñå èçïîëçâà íîâ îáåêò îò òèï òðàíçàêöèÿ, à íå äà ñå äóáëèðà
ëîãèêàòà. Àêî âúïðîñíàòà ñúçäàäåíà òðàíçàêöèÿ å óñïåøíà, òîãàâà ÿ äîáàâåòå êúì ñïèñúêà ñ óñïåøíè
òðàíçàêöèè, áåç äà ïðàâèòå èçëèøíè êîïèÿ.


*/
#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>
#include <vector>
using namespace std;
class Account{
	string name;
	int balance;
public:
	Account(string name, int balance) : name(name), balance(balance){};
	string getNumber(){
		return name;
	}
	int getBalance(){
		return balance;
	}
	bool take(int sum){
		if (sum < 0) return 0;
		if (sum >= 0){
			if (balance - sum >= 0){
				balance = balance - sum;
				return 1;
			}
			else
				return 0;
		}
	}
	void add(int sum){
		if (sum >= 0)
			balance += sum;
	}
};
class Transaction{
private:
	int balance;
	Account * one;
	Account * two;
public:
	Transaction(int balance, Account * one, Account * two) : balance(balance), one(one), two(two){};
	bool execute(){
		static int b = 0;
		if (b < 1){
			if (balance > one->getBalance())
				return 0;
			else if (one->take(balance)){
				two->add(balance);
				b++;
				return 1;
			}
		}
		else
			return 0;
	}
	bool execute1(){
		if (balance >= 0 ){
			if (one->take(balance))
			{	
				two->add(balance);
				return 1;
			}
		}
		else return 0;
	}
	int getAmount(){
		return balance;
	}
	Account * getSource(){
		return one;
	}
	Account * getTarget(){
		return two;
	}
};
class Bank{
private:
	int cnt = 0;
	vector <Transaction*> transactions;
public:
	Bank(){};
	bool transfer(double balance, Account * one, Account * two){
		 Transaction* newTrans = new Transaction(balance, one, two);
		if (newTrans->execute1())
		{	
			cnt++;
			transactions.push_back(newTrans);
			return 1;
		}
		else return 0;
	}
	Transaction transactionAt(int i){
		return *transactions[i];
	}
	int transactionsCount(){
		return cnt;
	}
};

int main() {
	Account *acc1 = new Account("BB12344321", 10000);
	Account *acc2 = new Account("BB98766789", 5000);
	Account *acc3 = new Account("BB22334455", 2000);

	cout << acc1->getNumber() << ": " << acc1->getBalance() << endl; // 1
	bool success = acc1->take(1000);
	assert(success);
	
	cout << acc1->getNumber() << ": " << acc1->getBalance() << endl; // 2
		acc1->add(-1000); //shouldn't do anything
	cout << acc1->getNumber() << ": " << acc1->getBalance() << endl; // 3
	acc1->take(-1000);//shouldn't do anything
	cout << acc1->getNumber() << ": " << acc1->getBalance() << endl; // 4
	
	success = acc3->take(3000);
	assert(success == false);
	
	cout << acc3->getNumber() << ": " << acc3->getBalance() << endl;

	acc3->add(3000);
	cout << acc3->getNumber() << ": " << acc3->getBalance() << endl; // acc3 5000 acc1 9000
	

	{
		Transaction *transaction = new Transaction(2000, acc3, acc1);
		success = transaction->execute(); // acc3 3000, acc1 11000
		assert(success);
		success = transaction->execute(); // succes = false (zashtitavame ot vtoro izpolzvane)
		assert(success == false); //already executed

		delete transaction;
	}

	cout << acc1->getNumber() << ": " << acc1->getBalance() << endl;
	cout << acc3->getNumber() << ": " << acc3->getBalance() << endl;
	
	Bank *bank = new Bank();

	for (int i = 0; i < 10; i++) {
		double amount = 0;
		if (i % 2 == 0)
			amount = 1000;	
		else amount = 2000;									//double amount = i % 2 == 0 ? 1000 : 2000; // condition ? result_if_true : result_if_false // 1000,

		Account *source = acc1;
		Account *target;
		if (i % 2 == 0)
			target = acc2;
		else target = acc3;										//Account *target = i % 2 == 0 ? acc2 : acc3; // acc2
		bool success = bank->transfer(amount, source, target);
		cout << i << " (" << amount << ") " << (success ? "OK" : "FAIL") << endl;
		cout << source->getNumber() << ": " << source->getBalance() << endl;
		cout << target->getNumber() << ": " << target->getBalance() << endl;
	}
	
	//only successful transfers are recorded by the bank
	for (int i = 0; i < bank->transactionsCount(); i++) {
	cout << bank->transactionAt(i).getSource()->getNumber()
	<< " -" << bank->transactionAt(i).getAmount() << "-> "
	<< bank->transactionAt(i).getTarget()->getNumber() << endl;
	}
	
	delete bank;

	delete acc1;
	delete acc2;
	delete acc3;
	
	system("pause");
	return 0;
}
