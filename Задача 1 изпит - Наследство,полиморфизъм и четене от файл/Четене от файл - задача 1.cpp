#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class Person{
protected:
	virtual ostream & doprint(ostream & out) const{
		return out << first_name << " " << last_name << endl;
	};
	string first_name;
	string last_name;
public:
	Person(){};
	Person(string first_name, string last_name) : first_name(first_name), last_name(last_name){};
	string get_first(){ //  ÷ëåí-ôóíêöèè çà äîñòúï äî äàííèòå
		return first_name;
	}
	string get_last(){ //  ÷ëåí-ôóíêöèè çà äîñòúï äî äàííèòå
		return last_name;
	}
	virtual void read(ifstream & inp_data){ // ÷ëåí-ôóíêöèÿ read çà ÷åòåíå îò ôàéë íà äàííèòå ñ ïàðàìåòúð ôàéëîâà ïðîìåíëèâà 
			inp_data >> first_name;
			inp_data >> last_name;


		inp_data.close();
		
	}
	virtual void write(ofstream & output){  // ÷ëåí-ôóíêöèÿ write çà ïèñàíå íà ôàéë íà äàííèòå ñ ïàðàìåòúð ôàéëîâà ïðîìåíëèâà 
		output << first_name << " " << last_name;
		}
	virtual void set_first(string first){
		first_name = first;
	}
	virtual void set_last(string first){
		last_name = first;
	}
	virtual string get_position(){
		return 0;
	};
	virtual int get_salary(){
		return 0;
	}; 

	friend ostream & operator <<(ostream & out, const Person & b){ // Ïðàâèì ñè åäíà âèðòóàëíà ôóíêöèÿ doprint êîÿòî êàòî ñå èçâèêà îïåðàòîðà << äà ñå èçâèêà ïðàâèëíàòà ôóíêöèÿ (òúé êàòî ïðåäåôèíèðàíèÿ îïåðàòîð << â íàñëåäíèêà íå ðàáîòè)
		return b.doprint(out);
	};
	
};
class Worker : public Person{
private:
	ostream & doprint(ostream & out) const {
		return out << first_name << " " << last_name << " " << salary << " " << position<< endl;
	}
	int salary;
	string position;
public:
	Worker(){};
	Worker(int salary, string position) : salary(salary), position(position){};
	 int get_salary(){  //  ÷ëåí-ôóíêöèè çà äîñòúï äî äàííèòå
		return salary;
	};
	void set_first(string first){
		first_name = first;
	}
	void set_last(string first){
		last_name = first;
	}
	 string get_position(){  //  ÷ëåí-ôóíêöèè çà äîñòúï äî äàííèòå
		return position;
	};


	 void read(ifstream & inp_data){ // ÷ëåí-ôóíêöèÿ read çà ÷åòåíå îò ôàéë íà äàííèòå ñ ïàðàìåòúð ôàéëîâà ïðîìåíëèâà 
		inp_data >> first_name;
		inp_data >> last_name;
		inp_data >> salary;
		inp_data >> position;


		inp_data.close();

	}
	 void write(ofstream & out){  // ÷ëåí-ôóíêöèÿ write çà ïèñàíå íà ôàéë íà äàííèòå ñ ïàðàìåòúð ôàéëîâà ïðîìåíëèâà 
		out << first_name << " " << last_name << " " << salary << " " << position;
	}
};

vector<Person *> LoadPeople(ifstream & people, ifstream & workers){
	vector<Person *> result;
	string first, last;
	while (people.good()){
		people >> first;
		people >> last;
		Person * newperson = new Person(first, last);
		result.push_back(newperson);
	}
	int balance;
	string number;
	while (workers.good()){
		workers >> first >> last >> balance >> number;
		Worker * newworker = new Worker(balance, number);
		newworker->set_first(first);
		newworker->set_last(last);
		result.push_back(newworker);
	}
	people.close();
	workers.close();
	return result;
}

void OutPut(vector<Person *> vec){
	ofstream output("output.txt");
	for (int i = 0; i < vec.size(); i++)
		output << *vec[i];
}


int main()
{
	                    // - PERSON
	string person, students, output, person_input;
	person_input = "personin.txt"; //  personin.txt ñúäúðæà - Ivan Stanev
	Person ivan;
	ifstream inp_data;
	inp_data.open(person_input.c_str());
	ivan.read(inp_data); // ÷åòåíå íà äàííè îò ôàéë ñ ïàðàìåòúð ôàéëîâà ïðîìåíëèâà(ifstream)

	cout << ivan.get_first() << " " << ivan.get_last() << endl; // ÷ëåí-ôóíêöèè çà äàííèòå

	ofstream fout("personout.txt");
	ivan.write(fout); // ïèñàíå íà äàííèòå âúâ ôàéë ñ ïàðàìåòúð ôàéëîâà ïðîìåíëèâà(ofstream)



	                  // - WORKER 
		Worker peter;
	string worker_input, worker_output;
	worker_input = "workerin.txt"; // workerin.txt ñúäúðæà - Ivan Stanev 45353 AA
	ifstream worker_inp;

	worker_inp.open(worker_input.c_str());
	peter.read(worker_inp); // ÷åòåíå íà äàííè îò ôàéë ñ ïàðàìåòúð ôàéëîâà ïðîìåíëèâà(ifstream)
	
	cout << peter.get_first() << " " << peter.get_last() << " " << peter.get_salary() << " " << peter.get_position() << endl;  // ÷ëåí-ôóíêöèè çà äàííèòå
	
	ofstream f_out("workerout.txt");
	peter.write(f_out); // ïèñàíå íà äàííèòå âúâ ôàéë ñ ïàðàìåòúð ôàéëîâà ïðîìåíëèâà(ofstream)

	                  // ×ÅÒÅÍÅ ÎÒ ÄÂÀ ÔÀÉËÀ, ÇÀÐÅÆÄÀÍÅ ÂÚÂ ÂÅÊÒÎÐ, ÑÎÐÒÈÐÀÍÅ È ÈÇÂÀÆÄÀÍÅ Â ÍÎÂ ÔÀÉË
	
	ifstream people("PEOPLE.txt"), workers("WORKERS.txt");
	vector<Person *> everyone;
	everyone = LoadPeople(people, workers); // çàðåæäàìå ïîëèìîðôíî âñè÷êè Ðàáîòíèöè è Õîðà âúâ âåêòîð ñ óêàçàòåëè êúì Person(êàêòî å óñëîâèåòî)
	cout << everyone[1]->get_first() << " " << everyone[1]->get_last() << endl; // òåñò
	cout << everyone[6]->get_first() << " " << everyone[6]->get_last() << " " << everyone[6]->get_salary() << " " << everyone[6]->get_position() << endl; // òåñò ÷å âñè÷êî ðàáîòè

	for (int i = 0; i < everyone.size(); i++){ // ÑÎÐÒÈÐÀÌÅ ÏÎ ÔÀÌÈËÈÈ
		for (int j = i + 1; j < 7; j++){
			if (everyone[i]->get_last() > everyone[j]->get_last()){
				swap(everyone[i], everyone[j]);
			}
		}
	}
	for (int i = 0; i < 7; i++)
		cout << everyone[i]->get_last() << endl; // òåñò ÷å å ñîðòèðàí âåêòîðà ïî ôàìèëèè

	OutPut(everyone);

	
	return 0;
}
