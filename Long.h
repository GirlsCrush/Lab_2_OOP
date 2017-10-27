#pragma once
#include <iostream>
#include <vector>
#define ll long long;
using namespace std;

class Long
{
public:
	Long();
	Long(vector<int> &);
	Long(Long &);
	Long(const Long &);
	Long(int);
	Long inverseKuk(int);
	Long mulKaracuba(Long)const;
	Long mulTomKuk(Long)const;
	Long mulSheng(Long)const;
	Long divKuk(Long);
	static bool isPrimeLemer(long long, int);
	static bool isPrimeRabMil(long long, int);
	static bool isPrimeSolStrass(long long, int);
	static long long powMod(long long, long long, long long);
	static long long mulMod(long long, long long, long long);
	static int amntPowOfTwo(long long);
	static long long JacobiSymbol(long long, long long);
	static long long gcd(long long, long long);
	Long operator+ (Long&);
	Long operator- (Long&);
	Long operator* (Long&);
	Long operator/ (Long&);
	Long operator% (Long&);
	bool operator< (Long&);
	bool operator==(Long&);
	int operator[] (int i);
	//Long pow(Long);	//pre: intput is positive int.
	
	Long splitNumber(int part, int nParts, int &);
	Long splitNumber(int part, int nParts);
	void coutNumber()const;
	vector<int> getNumber()const;
	int getPoint()const;
	void setNumber(vector<int>);
	void movePointLeft(int);
	void setNumber(vector<int>, int);
	int size()const;
private:
	static long long modInv(long long, long long);
	static long long gcdExt(long long, long long, long long *, long long *);
	void initPQ()const;
	static vector<long long> Q;
	static vector<long long> P;
	void equalDigitsAmount(Long &);
	Long pushNulls_back(int);
	Long pushNulls_front(int);
	Long pushOnes_back(int);
	Long pushOnes_front(int);
	void decimalToBinary(vector<int>);
	void decimalToBinary(int);
	static vector<int> minusNumber(vector<int> &);
	static bool isNegative(vector<int> &);
	static bool isNegative(Long &);
	static bool isNull(Long &);
	static bool isNull(vector<int> &);
	static void clearNulls(vector<int> &);

	static vector<int> subBinary(vector<int>, const vector<int>);
	static vector<int> mulBinary(vector<int>, vector<int>);
	static vector<int> addBinary(vector<int>, const vector<int>);
	static vector<int> divBinary(vector<int>, vector<int>);

	static Long subDouble(Long, Long);
	static Long addDouble(Long, Long);
	static Long divDouble(Long, Long);
	static Long mulDouble(Long, Long);


	static Long numbers[];
	static vector<int> numbersVB[];
	static vector<int> numbersV[];

	vector<int> mNumber;
	int point = 0;

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