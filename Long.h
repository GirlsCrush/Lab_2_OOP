#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Long
{
public:
	Long(vector<int> &);
	void coutNumber();
	vector<int> mulKaracuba(Long)const;
	vector<int> getNumber()const;
	static vector<int> subBinary(vector<int>, const vector<int>);
	static vector<int> mulBinary(vector<int>, vector<int>);
	static vector<int> addBinary(vector<int>, const vector<int>);
private:
	void decimalToBinary(vector<int> &);
	static vector<int> minusNumber(vector<int> &);
	static bool isNegative(vector<int> &);
	vector<int> mNumber;

};