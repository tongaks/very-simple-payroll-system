#include <bits/stdc++.h>

using namespace std;

class PayrollSystem {
	map<string, int> positions = {
		{"Manager", 2000},
		{"Supervisor", 1500},
		{"Secretary", 800},
		{"Clerk", 570},
		{"Janitor", 500}
	};

	map<string, float> Taxes {
		{"PAGIBIG", 200},
		{"PHILHEALTH", 300},
		{"Tax", 0.062},
		{"SSS", 0.06},
	};

	string position;
	int salary, days, overtime, holiday, vale, loan;
	long netpayment, grosspayment;

public:
	void MainMenu() {}

	void Payroll() {
		system("clear");
		cout << "-----------PAYROLL SYSTEM-----------" << endl;		
		for (const auto& p : positions) {
			cout << "[+]" << p.first << "\tRate: $" << p.second << '\n';
		}

		cout << "\nEnter position: "; cin >> position;

		for (auto i = positions.begin(); i != positions.end(); i++) {
			if (position == i->first) {
				salary =  i->second;
			}
		}

		cout << "Number of days present: "; cin >> days;
		cout << "Holiday: "; cin >> holiday;
		cout << "Overtime: "; cin >> overtime;
		cout << "VALE: "; cin >> vale;
		cout << "Loan: "; cin >> loan;

		GetGrosspayment(positions[position], days, holiday, overtime);

		system("clear");
		cout << "-----------Final-----------\n";
		for (const auto& p : Taxes) {
			cout << "[+]Tax: " << p.first;
			if (p.second == Taxes["SSS"] || p.second == Taxes["Tax"]) {
				cout << " Rate: " << p.second << "% = $" << grosspayment * p.second << endl;
			} else {
				cout << " Rate: $" << p.second << endl;
			}
		}

		cout << "Grosspayment: $" << grosspayment;
		cout << "\nNetPayment: $" << NetPayment(vale, loan);
		cout << "\n-----------Final-----------\n";
	}

	int GetGrosspayment(int rate, int day, int holiday, int overtime) {
		return grosspayment = (rate * day) + holiday * (rate - 125) + overtime * ((rate / 8) * 0.5 + (rate / 8));
	}

	int NetPayment(int Vale, int loan) {
		if (days > 0) {
			netpayment = static_cast<long>(grosspayment) - ((Taxes["PHILHEALTH"] + Taxes["PAGIBIG"]) + (Taxes["Tax"] * grosspayment) + (Taxes["SSS"] * grosspayment));
		}


		return netpayment;
	}
};

int main() {
	PayrollSystem pl;
	pl.Payroll();
	return 0;
}