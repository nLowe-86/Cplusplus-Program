//Author: Nathanial Lowe
//Project: Airgead Banking
//Date: 4/02/2023

#include "Interest.h"
#include<iostream>
using namespace std;

//Input Menu
int main() {
	double initialDeposit;
	double monthlyDeposit;
	double percentInterest;
	int numberOfYears;

	cout << "********************************************" << endl;
	cout << "*************** DATA INPUT *****************" << endl;
	cout << "Initial Investment Amount: $" << endl;

	cin >> initialDeposit;

	//Error message for depositing 0 or a negatve interger
	if (initialDeposit <= 0) {
		cout << "Initial investment amount must be greater than 0." << endl;
		cout << "Initial Investment Amount: $" << endl;
		
		cin >> initialDeposit;
	}

	//Asking for Monthly deposit input
	cout << "Monthly Deposit Amount: $" << endl;
	cin >> monthlyDeposit;

	//Asking for annual interest input
	cout << "Annual Interest: %" << endl;
	cin >> percentInterest;

	//Asking for number of years input
	cout << "Number of years: " << endl;
	cin >> numberOfYears;

	cout << "Press any key to continue";
	
	system("pause");
	system("CLS");

	Interest::Interest(initialDeposit, monthlyDeposit, percentInterest, numberOfYears);

	Interest::printStaticReports();
}