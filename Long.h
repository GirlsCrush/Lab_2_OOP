#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Long
{
public:
	Long();
	Long(vector<int> &);
	Long(Long &);
	Long(const Long &);
	void coutNumber()const;
	Long mulKaracuba(Long)const;
	Long mulTomKuk(Long)const;
	vector<int> getNumber()const;
	void setNumber(vector<int>);
	int size()const;
	Long polynomTomKuk(vector<int>, vector<int>)const;
	Long operator+ (Long&);
	Long operator- (Long&);
	Long operator* (Long&);
	Long operator/ (Long&);
	int operator[] (int i);
	static Long numbers[];
	static vector<int> numbersVB[];
	static vector<int> numbersV[];
	Long splitNumber(int part, int nParts, int &);
	Long splitNumber(int part, int nParts);
private:
	void equalDigitsAmount(Long &);
	Long pushNulls_back(int);
	Long pushNulls_front(int);
	void decimalToBinary(vector<int>);
	static vector<int> minusNumber(vector<int> &);
	static bool isNegative(vector<int> &);
	static bool isNull(vector<int> &);
	static void clearNulls(vector<int> &);
	static vector<int> subBinary(vector<int>, const vector<int>);
	static vector<int> mulBinary(vector<int>, vector<int>);
	static vector<int> addBinary(vector<int>, const vector<int>);
	static vector<int> divBinary(vector<int>, vector<int>);	//pre: return value must be Int.
	vector<int> mNumber;

};

class Polynom
{
public:
	Polynom(Long);
	int getDigitsAmnt();
	Long operator()(Long);
private:
	Long a;
	Long b;
	Long c;
	int digitsAmnt = 0;
};