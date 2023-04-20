//Author: Nathanial Lowe
//Project: Airgead Banking
//Date: 4/02/2023

#pragma once
#ifndef INTEREST_H_
#define INTEREST_H_

using namespace std;

class Interest {
public:
	Interest();
	Interest(double, double, double, int);

	void setInitialDeposit(double);
	void setMonthlyDeposit(double);
	void setInterest(double);
	void setYears(int);
	double getInitialDeposit() const;
	double getMonthlyDeposit() const;
	double getInterest() const;
	int getYears() const;
	double initialDeposit;
	double monthlyDeposit;
	double percentInterest;
	int numberOfYears;
	void printStaticReports();

private:
	void balanceWithoutMonthlyDeposit();
	void balanceWithMonthlyDeposit();


};
#endif // !INTEREST_H_
