#include<iostream>
using namespace std;

class employee{
public:
	virtual void calculateSalary() = 0;
};

class Fulltimeemployee :public employee {
private:
	double fixedsalary;
public:
	Fulltimeemployee (double fixs) {
		fixedsalary = fixs;
	}
	void calculateSalary() {
		//because the salary is fixed
		cout << "Salary of full time employee is: " << fixedsalary << endl;
	}
};

class parttimeemployee :public employee {
private:
	int hoursworked;
	int hourlyrate;
public:
	parttimeemployee(int hw, int hr) {
		hoursworked = hw;
		hourlyrate = hr;
	}
	void calculateSalary() {
		int salary = hoursworked*hourlyrate;
		cout << "Salary of part time employee is: " << salary;
	}
};
int main() {
	Fulltimeemployee obj1(12000);
	obj1.calculateSalary();

	parttimeemployee r(200, 2);
	r.calculateSalary();
	return 0;
}
