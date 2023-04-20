//Author: Nathanial Lowe
//Project: Airgead Banking
//Date: 4/02/2023

#include<iostream>
#include<iomanip>
#include<cmath>
#include "Interest.h"
using namespace std;

//Defaults the values of variables 
Interest::Interest() {
	initialDeposit = 0.00;
	monthlyDeposit = 0.00;
	percentInterest = 0.00;
	numberOfYears = 0;
}

Interest::Interest(double initialDeposit, double monthlyDeposit, double percentInterest, int numberOfYears) {
	this->initialDeposit = initialDeposit;
	this->monthlyDeposit = monthlyDeposit;
	this->percentInterest = percentInterest;
	this->numberOfYears = numberOfYears;
}

//Sets Initial Deposit
void Interest::setInitialDeposit(double initialDeposit) {
	initialDeposit = this->initialDeposit;
}

//Gets Initial deposit
double Interest::getInitialDeposit() const {
	return initialDeposit;
}

//Set monthly Deposit
void Interest::setMonthlyDeposit(double monthlyDeposit) {
	monthlyDeposit = this->monthlyDeposit;
}

//Gets monthly deposit
double Interest::getMonthlyDeposit() const {
	return monthlyDeposit;
}

//Sets Interest rate
void Interest::setInterest(double) {
	percentInterest = this->percentInterest;
}

//Gets interest rate
double Interest::getInterest() const{
	return percentInterest;
}

//Set years for interest buildup
void Interest::setYears(int numberOfYears) {
	numberOfYears = this->numberOfYears;
}

//Get years for interest buildup
int Interest::getYears() const {
	return numberOfYears;
}

//Calculate balance without the monthly deposit
void Interest::balanceWithoutMonthlyDeposit() {
	double balance = initialDeposit;
	double monthlyInterest;
	double interestRate = percentInterest / 100 / 12;
	for (int i = 0; i < numberOfYears; i++) {
		monthlyInterest = 0;
		for (int j = 0; j < 12; j++) {
			monthlyInterest += floor(balance * interestRate);
			balance += balance * interestRate;
		}
		cout << i + 1 << fixed << setprecision(2) << setw(15) << "$" 
			<< balance << setw(15) << "$" << monthlyInterest << endl;
	}
}

//Calculate balance wth monthly deposits
void Interest::balanceWithMonthlyDeposit() {
	double balance = initialDeposit;
	double monthlyInterest;
	double interestRate = percentInterest / 100 / 12;
	for (int i = 0; i < numberOfYears; i++) {
		monthlyInterest = 0;
		for (int j = 0; j < 12; j++) {
			monthlyInterest += floor(balance * interestRate);
			balance += balance * interestRate;
			balance += monthlyDeposit;
		}
		cout << i + 1 << fixed << setprecision(2) << setw(15) << "$"
			<< balance << setw(15) << "$" << monthlyInterest << endl;
	}
}

//Prints both monthly deposit and wthout monthly deposit report
void Interest::printStaticReports() {
	cout << endl;
	cout << endl;
	cout << "------------------------------------------------------------" << endl;
	cout << "Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << "============================================================" << endl;
	cout << "Year " << "Year End Balance " << "Year End Earned Interest" << endl;
	cout << "------------------------------------------------------------" << endl;
	
	Interest::balanceWithoutMonthlyDeposit();

	cout << "------------------------------------------------------------" << endl;
	cout << endl;
	cout << endl;
	cout << "------------------------------------------------------------" << endl;
	cout << "Balance and Interest With Additional Monthly Deposits" <<	endl;
	cout << "============================================================" << endl;
	cout << "Year " << "Year End Balance " << "Year End Earned Interest" << endl;
	cout << "------------------------------------------------------------" << endl;

	Interest::balanceWithMonthlyDeposit();

	cout << "------------------------------------------------------------" << endl;

}