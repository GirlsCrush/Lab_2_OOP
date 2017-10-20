#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Long
{
public:
	Long(vector<int> &);
	void coutNumber();
	vector<int>& mulKaracuba(vector<int>)const;
	vector<int>& plusBinary(vector<int>, vector<int>);
private:
	vector<int>& multiplyBinary(vector<int>, vector<int>)const;
	
	void decimalToBinary(vector<int>);
	vector<int> mNumber;

};