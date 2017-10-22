#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Long
{
public:
	Long();
	Long(vector<int> &);
	void coutNumber();
	Long mulKaracuba(Long)const;
	Long mulTomKuk(Long)const;
	vector<int> getNumber()const;
	void setNumber(vector<int>);
	static vector<int>& subBinary(vector<int>, const vector<int>);
	static vector<int>& mulBinary(vector<int>, vector<int>);
	static vector<int>& addBinary(vector<int>, const vector<int>);
	Long polynomTomKuk(vector<int>, vector<int>)const;
	static Long numbers[];
	static vector<int>& divBinary(vector<int>, vector<int>);	//pre: return value must be Int.
	Long& operator+ (Long&);
	Long& operator- (Long&);
	Long& operator* (Long&);
	Long& operator/ (Long&);
	static vector<int> numbersV[];
private:
	void decimalToBinary(vector<int>);
	static vector<int> minusNumber(vector<int> &);
	static bool isNegative(vector<int> &);
	vector<int> mNumber;

};