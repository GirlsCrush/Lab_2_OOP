#include "Long.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <cmath>

#define K_MAX 10
using namespace std;

vector<long long> Long::Q = { 1 };
vector<long long> Long::P = {};

vector<int> Long::numbersV[] = { { 0 }, { 1 }, { 2 }, { 3 }, { 4 }, { 5 }, { 6 }, { 7 }, { 8 }, { 9 }, { 10 }, { 11 }, { 12 }, { 13 }, { 14 }, { 15 }, { 16 } };

Long Long::numbers[] = { 
	numbersV[0], numbersV[1], numbersV[2], numbersV[3], 
	numbersV[4], numbersV[5], numbersV[6], numbersV[7], 
	numbersV[8],numbersV[9], numbersV[10], numbersV[11], 
	numbersV[12], numbersV[13], numbersV[14], numbersV[15], numbersV[16] };

vector<int> Long::numbersVB[] = { { 0 },{ 1 },{ 1, 0 },{ 1, 1 },{ 1, 0, 0 },{ 1, 0, 1 },{ 1, 1, 0 },{ 1, 1, 1 },{ 1, 0, 0, 0 },{ 1, 0, 0, 1 },{ 1, 0, 1, 0 },{ 1, 0, 1, 1 },{ 1, 1, 0, 0 },{ 1, 1, 0, 1 },{ 1, 1, 1, 0 },{ 1, 1, 1, 1 },{ 1, 0, 0, 0, 0 } };

Long::Long()
{
}

Long::Long(vector<int> &a)
{
	decimalToBinary(a);
	point = 0;
}

//Long::Long(vector<int>&a, int p)
//{
//	auto iter = a.begin();
//	advance(iter, a.size()- 1 - p);
//	vector<int>aInt(a.begin(), iter);
//	decimalToBinary(aInt);
//	point = mNumber.size();
//	decimalToBinary(a);
//}

Long::Long(Long &longNumber)
{
	mNumber = longNumber.getNumber();
	point = longNumber.getPoint();
}

Long::Long(const Long &longNumber)
{
	mNumber = longNumber.getNumber();
	point = longNumber.getPoint();
}

Long::Long(int a)
{
	decimalToBinary(a);
	point = 0;
}

Long Long::inverseKuk(int precision)
{
	vector<int> numb = this->getNumber();
	int p = numb.size() - this->getPoint();
	Long z = divDouble((Long(32) / Long(4 * numb[0] + 2 * numb[1] + numb[2])), Long(4));
	int k = 0;
	Long tmp;
	auto iter = numb.begin();
	Long V;
	do
	{
		iter = numb.begin();
		tmp = mulDouble(z, z);
		advance(iter, (numb.size() - 1 < int(pow(2, k + 1)) + 3 ? numb.size() - 1 : int(pow(2, k + 1)) + 3));
		vector<int> V_k(numb.begin(), iter);
		V.setNumber(V_k, V_k.size());
		tmp = subDouble(mulDouble(Long(2), z), mulDouble(tmp, V));
		k++;
	} while (pow(2, k) < precision);

	tmp.pushNulls_front(p - (tmp.size() - tmp.getPoint()));
	tmp.movePointLeft(p);
	return tmp;
}

void Long::coutNumber()const
{
	ofstream fout("number.txt"); 
	for (unsigned int i = 0; i < mNumber.size() - point; i++)
	{
		fout << mNumber[i];
	}
	fout << ",";
	for (unsigned int i = mNumber.size() - point; i < mNumber.size(); i++)
	{
		fout << mNumber[i];
	}
	fout.close();
}

Long Long::mulKaracuba(Long longNumber) const
{
	Long v(longNumber);	
	Long u(*this);
	if (u.size() < v.size()) v.equalDigitsAmount(u);
	if (u.size() > v.size()) u.equalDigitsAmount(v);
	Long v1;	
	Long v0;
	Long u1;
	Long u0;
	int nPartNumbers;
	v1 = v.splitNumber(1, 2);
	v0 = v.splitNumber(2, 2);
	u1 = u.splitNumber(1, 2);
	u0 = u.splitNumber(2, 2, nPartNumbers);
	
	/*ofstream fout("v1.txt");	
	for (unsigned int i = 0; i < v1.size(); i++)
	{
		fout << v1[i];
	}
	
	fout.close();
	ofstream f1out("v0.txt");
	for (unsigned int i = 0; i < v0.size(); i++)
	{
		f1out << v0[i];
	}

	f1out.close();
	ofstream f3out("u1.txt");
	for (unsigned int i = 0; i < u1.size(); i++)
	{
		f3out << u1[i];
	}
	
	f3out.close();
	ofstream f2out("u0.txt");
	for (unsigned int i = 0; i < u0.size(); i++)
	{
		f2out << u0[i];
	}
	f2out.close();
	*/

	Long product1 = v1 * u1;
	Long product2 = (u1 - u0) * (v0 - v1);
	Long product3 = v0 * u0;
	/*
	ofstream faout("product1.txt");
	for (unsigned int i = 0; i < product1.size(); i++)
	{
		faout << product1[i];
	}
	faout.close();
	ofstream fxout("product2.txt");
	for (unsigned int i = 0; i < product2.size(); i++)
	{
		fxout << product2[i];
	}
	fxout.close();
	ofstream fcout("product3.txt");
	for (unsigned int i = 0; i < product3.size(); i++)
	{
		fcout << product3[i];
	}
	fcout.close();
	*/
	product1.pushNulls_back(nPartNumbers);
	Long result = product1;
	product1.pushNulls_back(nPartNumbers);
	result = result + product1;
	product2.pushNulls_back(nPartNumbers);
	result = result + product2;
	result = result + product3;
	product3.pushNulls_back(nPartNumbers);
	result = result + product3;
	/*
	ofstream f4out("result.txt");
	for (unsigned int i = 0; i < result.size(); i++)
	{
		f4out << result[i];
	}
	f4out.close();
	*/	
	return result;
}

Long Long::mulTomKuk(Long longNumber) const
{
	Long number(*this);
	number.equalDigitsAmount(longNumber);
	Polynom pA(number);
	Polynom pB(longNumber);
	Long w0 = pA(numbers[0]) *pB(numbers[0]);
	Long w1 = pA(numbers[1]) *pB(numbers[1]);
	Long w2 = pA(numbers[2]) *pB(numbers[2]);
	Long w3 = pA(numbers[3]) *pB(numbers[3]);
	Long w4 = pA(numbers[4]) *pB(numbers[4]);
	for (int i = 1; i < 5; ++i)
	{
		if (i <= 4)
		{
			w4 = (w4 - w3) / numbers[i];
		}
		if (i <= 3)
		{
			w3 = (w3 - w2) / numbers[i];
		}
		if (i <= 2)
		{
			w2 = (w2 - w1) / numbers[i];
		}
		if (i <= 1)
		{
			w1 = (w1 - w0) / numbers[i];
		}
	}
	
	for (int i = 3; i > 0; --i)
	{
		if (i <= 1)
		{
			w1 = w1 - (numbers[i] * w2);
		}
		if (i <= 2) 
		{
			w2 = w2 - (numbers[i] * w3);
		}
		if (i <= 3) 
		{
			w3 = w3 - (numbers[i] * w4);
		}
	}
	//ofstream f1out("0.txt");
	//for (unsigned int i = 0; i < w0.getNumber().size(); i++)
	//{
	//	f1out << w0.getNumber()[i];
	//}
	//f1out.close();

	//ofstream f2out("-1.txt");
	//for (unsigned int i = 0; i < (w1.getNumber()).size(); i++)
	//{
	//	f2out << (w1.getNumber())[i];
	//}

	//f2out.close();
	//ofstream f3out("-2.txt");
	//for (unsigned int i = 0; i < (w2.getNumber()).size(); i++)
	//{
	//	f3out << (w2.getNumber())[i];
	//}
	//f3out.close();

	//ofstream f4out("-3.txt");
	//for (unsigned int i = 0; i < (w3.getNumber()).size(); i++)
	//{
	//	f4out << (w3.getNumber())[i];
	//}

	//f4out.close();
	//ofstream f5out("-4.txt");
	//for (unsigned int i = 0; i < (w4.getNumber()).size(); i++)
	//{
	//	f5out << (w4.getNumber())[i];
	//}
	//f5out.close();
	int n = pA.getDigitsAmnt();
	Long result = (((w4.pushNulls_back(n) + w3).pushNulls_back(n) + w2).pushNulls_back(n) + w1).pushNulls_back(n) + w0;
	return result;
}

Long Long::mulSheng(Long v) const
{
	initPQ();
	Long u(*this);
	int k = 0;
	while (u.size() > P[k] || v.size() > P[k])
	{
		k++;
	}

	/*u.pushNulls_front(P[k] - u.size());
	v.pushNulls_front(P[k] - v.size());*/

	vector<Long> M(6);
	M[0].pushOnes_back(6 * Q[k] - 1);
	M[1].pushOnes_back(6 * Q[k] + 1);
	M[2].pushOnes_back(6 * Q[k] + 2);
	M[3].pushOnes_back(6 * Q[k] + 3);
	M[4].pushOnes_back(6 * Q[k] + 5);
	M[5].pushOnes_back(6 * Q[k] + 7);

	vector<long long> MLL(6);
	MLL[0] = pow(2, 6 * Q[k] - 1) - 1;
	MLL[1] = pow(2, 6 * Q[k] + 1) - 1;
	MLL[2] = pow(2, 6 * Q[k] + 2) - 1;
	MLL[3] = pow(2, 6 * Q[k] + 3) - 1;
	MLL[4] = pow(2, 6 * Q[k] + 5) - 1;
	MLL[5] = pow(2, 6 * Q[k] + 7) - 1;

	/*vector<Long> M = { M[0],M[1],M[2],M[3],M[4],M[5] };*/

	vector<Long> U(6);
	for (int i = 0; i < 6; ++i)
	{
		U[i] = u % M[i];
	}

	vector<Long> V(6);
	for (int i = 0; i < 6; ++i)
	{
		V[i] = v % M[i];
	}

	vector<Long> Wv(6);
	for (int i = 0; i < 6; ++i)
	{
		Wv[i] = U[i] * V[i];
		Wv[i] = Wv[i] % M[i];
	}
	vector<vector<long long>> CLL(6, vector<long long>(6, 0));
	vector<vector<Long>> C(6, vector<Long>(6));
	
	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			CLL[i][j] = modInv(MLL[i], MLL[j]);
			C[i][j] = Long(CLL[i][j]);
		}
			for (int j = i + 1; j < 6; ++j)
			{
				CLL[i][j] = modInv(MLL[i], MLL[j]);
				C[i][j] = Long(CLL[i][j]);

			}
	}
	vector<Long> W_(6);
	for (int i = 0; i < 6; ++i)
	{
		W_[i] = Wv[i];
		/*for (int j = 0; j < i; j++)
		{
			W_[i] = (W_[i] - W_[j]) % M[i];
			W_[i] = (W_[i] * C[j][i]) % M[i];
		}*/
		for (int j = 0; j < i; j++)
		{
			W_[i] = W_[i] - W_[j];
			W_[i] = W_[i] * C[j][i];
			W_[i] = W_[i] % M[i];
		}
	}
	Long W = W_[5];
	for (int i = 0; i < 5; ++i)
	{
		W = W * M[4 - i] + W_[4 - i];
	}
	
	return W;
}

Long Long::divKuk(Long lnumb)
{
	Long tnumb(*this);
	Long result = mulDouble(tnumb, lnumb.inverseKuk(64));
	return result;
}

long long Long::modInv(long long a, long long m)
{
	long long x, y;
	long long g = gcdExt(a, m, &x, &y);
	long long res = (x % m + m) % m;
	return res;
}

long long Long::gcdExt(long long a, long long b, long long *x, long long *y)
{
	if (a == 0)
	{
		*x = 0, *y = 1;
		return b;
	}

	long long x1, y1;
	long long gcd = gcdExt(b % a, a, &x1, &y1);

	*x = y1 - (b / a) * x1;
	*y = x1;

	return gcd;
}
bool Long::isPrimeLemer(long long p, int precision) 
{
	if (p % 2 == 0) return false;
	while (precision != 0)
	{
		long long a = rand();
		
		a = a % p;
		a = powMod(a, (p - 1) / 2, p);
		if (a != 1 && a != (p - 1)) return false;
		--precision;
	}
	return true;
}

bool Long::isPrimeRabMil(long long p, int precision)
{
	if (p % 2 == 0) return false;
	int amntPow = amntPowOfTwo(p);
	long long m = (p - 1) / pow(2, amntPow);
	while (precision != 0)
	{
		int j = 0;
		long long a = rand() % p;
		long long z = mulMod(a, m, p);
		if (z == 1 || z == (p - 1));
		else
		{
			for (; j < amntPow; ++j)
			{
				z = (z * z) % p;
				if (z == 1)
					return false;
				if (z == p - 1)
					break;
			}

			if (j == amntPow && z != p - 1)
				return false;
		}
		precision--;
	}
	return true;
}

bool Long::isPrimeSolStrass(long long p, int precision)
{
	while (precision)
	{
		long long a = rand() % p;
		if (gcd(a, p) != 1) return false;
		long long j = powMod(a, (p - 1) / 2, p);
		long long J = JacobiSymbol(a, p);
		if ((j + p) % p != (J + p) % p) return false;
		--precision;
	}
	return true;
}

long long Long::powMod(long long a, long long p, long long mod)
{
	long long temp;
	if (p == 1) return (a % mod);
	if (p % 2 == 0)
	{
		temp = powMod(a, p / 2, mod);
		return (temp * temp) % mod;
	}
	else
	{
		temp = powMod(a, (p - 1) / 2, mod);
		temp = (temp * temp) % mod;
		temp = (temp * a) % mod;
		return temp;
	}
}

long long Long::mulMod(long long a , long long p , long long mod)
{
	long long temp;
	if (p == 1) return (a % mod);
	if (p % 2 == 0)
	{
		temp = powMod(a, p / 2, mod);
		return (temp + temp) % mod;
	}
	else
	{
		temp = powMod(a, (p - 1) / 2, mod);
		temp = (temp + temp) % mod;
		temp = (temp + a) % mod;
		return temp;
	}
}

int Long::amntPowOfTwo(long long p)
{
	int amnt = 0;
	while (p % 2 == 0)
	{
		p /= 2;
		++amnt;
	}
	return amnt;
}

long long Long::JacobiSymbol(long long a, long long b)
{

		if (a >= b)
			a %= b;
		if (a == 0)
			return 0;
		if (a == 1)
			return 1;

		if (a < 0)
			if ((b - 1) / 2 % 2 == 0)
				return JacobiSymbol(-a, b);
			else
				return -JacobiSymbol(-a, b);

		if (a % 2 == 0)
			if (((b * b - 1) / 8) % 2 == 0)
				return JacobiSymbol(a / 2, b);
			else
				return -JacobiSymbol(a / 2, b);

		long long g = gcd(a, b);

		if (g == a)
			return 0;
		if (g != 1)
			return JacobiSymbol(g, b) * JacobiSymbol(a / g, b);
		if (((a - 1) * (b - 1) / 4) % 2 == 0)
			return JacobiSymbol(b, a);
		else
			return -JacobiSymbol(b, a);
}

long long Long::gcd(long long a, long long b)
{
	if (a < 0) a = -a;
	if (b < 0) b = -b;

	int more = (a < b ? b : a);
	int less = (a < b ? a : b);

	while (more % less != 0)
	{
		long long tmp = more % less;
		more = less;
		less = tmp;
	}
	 return less;
}

vector<int> Long::getNumber() const
{
	return mNumber;
}

int Long::getPoint() const
{
	return point;
}

void Long::setNumber(vector<int> longNumber)
{
	mNumber = longNumber;
	point = 0;
}

void Long::movePointLeft(int p)
{
	point += p;
}

void Long::setNumber(vector<int> longNumber, int p)
{
	mNumber = longNumber;
	point = p;
}

int Long::size()const
{
	return mNumber.size();
}

void Long::initPQ()const
{
	for (int i = 0; i < K_MAX; ++i)
		Q.push_back(Q.back() * 3 - 1);
	for (int i = 0; i < Q.size(); ++i)
		P.push_back(Q[i] * 18 + 8);
}

vector<int> Long::mulBinary(vector<int> numb1, vector<int> numb2)
{
	if (isNull(numb1) || isNull(numb2)) return numbersV[0];
	clearNulls(numb1);
	clearNulls(numb2);
	vector<int> result((numb1.size() <= numb2.size() ? numb2.size() : numb1.size()), 0);
	vector<int> less = (numb1.size() <= numb2.size() ? numb1 : numb2);
	vector<int> more = (numb1.size() <= numb2.size() ? numb2 : numb1);
	
		if ( isNegative(less) && isNegative(more))
		{
			minusNumber(less);
			minusNumber(more);
		}
		else
			if (isNegative(less))minusNumber(less);
			else 
				if (isNegative(more))minusNumber(more);

		for (int i = less.size() - 1; i >= 0; --i)
		{
			if (less[i] == 1)
			{
				result = addBinary(result, more);
			}
			more.push_back(0);
		}
		clearNulls(result);
		if (isNegative(numb1) && !isNegative(numb2) || !isNegative(numb1) && isNegative(numb2)) minusNumber(result);
		/*
		ofstream fout("1.txt");
		for (unsigned int i = 0; i < result.size(); i++)
		{
			fout << result[i];
		}
		fout.close();
		*/
		return result;
}

vector<int> Long::addBinary(vector<int> numb1, vector<int> numb2) 
{
	clearNulls(numb1);
	clearNulls(numb2);
	if (isNegative(numb1) && !isNegative(numb2)) return subBinary(numb2, minusNumber(numb1));
	else
		if (!isNegative(numb1) && isNegative(numb2)) return subBinary(numb1, minusNumber(numb2));
		else
		{
			vector<int> sum = (numb1.size() <= numb2.size() ? numb2 : numb1);
			vector<int> less = (numb1.size() <= numb2.size() ? numb1 : numb2);
			if (isNegative(numb1) && isNegative(numb2))
			{
				minusNumber(less);
				minusNumber(sum);
			}

			for (unsigned int i = 0; i < sum.size() && i < less.size(); ++i)
			{
				sum[sum.size() - 1 - i] += less[less.size() - 1 - i];
			}
			for (int i = (sum.size() <= less.size() ? less.size() : sum.size()) - 1; i > 0; --i)
			{
				sum[i - 1] += sum[i] / 2;
				sum[i] %= 2;
			}
			if (sum[0] > 1)
			{
				sum[0] %= 2;
				sum.insert(sum.begin(), 1);
			}
			if (isNegative(numb1) && isNegative(numb2)) minusNumber(sum);
			/*
			ofstream fout("1.txt");
			for (unsigned int i = 0; i < sum.size(); i++)
			{
				fout << sum[i];
			}
			fout.close();
			*/
			clearNulls(sum);
			return sum;
		}
}

vector<int> Long::subBinary(vector<int> numb11, vector<int> numb22)
{
	vector<int> numb1 = numb11;
	vector<int> numb2 = numb22;
	if (isNull(numb1)) return minusNumber(numb2);
	if (isNull(numb2)) return numb1;
	clearNulls(numb1);
	clearNulls(numb2);

	if (isNegative(numb1) && !isNegative(numb2) || !isNegative(numb1) && isNegative(numb2)) return addBinary(numb1, minusNumber(numb2));
	else
	{
		vector<int> diff;
		vector<int> less;
		bool isSwaped = false;

		if (isNegative(numb1) && isNegative(numb2))
		{
			minusNumber(numb1);
			minusNumber(numb2);
		}
		if (numb1.size() != numb2.size())
		{
			if (numb1.size() < numb2.size()) isSwaped = true;
			diff = (numb1.size() <= numb2.size() ? numb2 : numb1);
			less = (numb1.size() <= numb2.size() ? numb1 : numb2);
		}
		else
		{
			int i = 0;
			for (int j = 0; i == 0 && j < numb1.size(); ++j)
			{
				i = numb1[j] - numb2[j];
			}
			if (i < 0)
			{
				isSwaped = true;
				diff = numb2;
				less = numb1;
			}
			if (i > 0)
			{
				diff = numb1;
				less = numb2;
			}
			if (i == 0)
			{
				return numbersVB[0];
			}
		}

		for (unsigned int i = 0; i < diff.size() && i < less.size(); ++i)
		{
			diff[diff.size() - 1 - i] -= less[less.size() - 1 - i];
		}
		for (int i = diff.size() - 1; i > 0; --i)
		{
			if (diff[i] < 0)
			{
				diff[i] += 2;
				diff[i - 1] -= 1;
			}
		}
		clearNulls(diff);
		/*
		ofstream fout("1.txt");
		for (unsigned int i = 0; i < diff.size(); i++)
		{
			fout << diff[i];
		}
		fout.close();
		*/
		if (isNegative(numb1) && isNegative(numb2) && !(isSwaped) || !(isNegative(numb1)) && !(isNegative(numb2)) && (isSwaped)) minusNumber(diff);
		return diff;
	}
}

vector<int> Long::divBinary(vector<int> numb1, vector<int> numb2)
{
	if (isNull(numb1)) return numb1;
	clearNulls(numb1);
	clearNulls(numb2);
	try 
	{
		if (isNull(numb2)) throw exception("\nDividing by zero.\n");
	}
	catch (const char *s) { cout << s; }

	vector<int> result;
	vector<int> less = numb2;
	vector<int> more = numb1;


	if (isNegative(less) && isNegative(more))
	{
		minusNumber(less);
		minusNumber(more);
	}
	else
		if (isNegative(less))minusNumber(less);
		else
			if (isNegative(more))minusNumber(more);

	vector<int> tmp;
	for (int i = 0; i < more.size(); ++i)
	{
		tmp.push_back(more[i]);
		if (!isNegative(subBinary(tmp,less)))
		{
			result.push_back(1);
			tmp = subBinary(tmp, less);
		}
		else result.push_back(0);
	}
		clearNulls(result);

	if (isNegative(numb1) && !isNegative(numb2) || !isNegative(numb1) && isNegative(numb2)) minusNumber(result);
	/*
	ofstream fout("1.txt");
	for (unsigned int i = 0; i < result.size(); i++)
	{
	fout << result[i];
	}
	fout.close();
	*/
	return result;
}

Long Long::mulDouble(Long lnumb1, Long lnumb2)
{
	int p = lnumb1.getPoint() + lnumb2.getPoint();
	vector<int> mul = mulBinary(lnumb1.getNumber(), lnumb2.getNumber());
	Long result;
	result.setNumber(mul, p);
	result.pushNulls_front(p - mul.size());
	return result;
}

Long Long::subDouble(Long lnumb1, Long lnumb2)
{
	int p = (lnumb1.getPoint() < lnumb2.getPoint() ? lnumb2.getPoint() : lnumb1.getPoint());
	lnumb1.pushNulls_back(p - lnumb1.getPoint());
	lnumb2.pushNulls_back(p - lnumb2.getPoint());
	vector<int> sub = subBinary(lnumb1.getNumber(), lnumb2.getNumber());
	while (sub[sub.size() - 1] == 0 && p != 0)
	{
		sub.erase(sub.end() - 1);
		p--;
	}
	Long result;
	result.setNumber(sub, p);
	return result;
}

Long Long::addDouble(Long lnumb1, Long lnumb2)
{
	int p = (lnumb1.getPoint() < lnumb2.getPoint() ? lnumb2.getPoint() : lnumb1.getPoint());
	lnumb1.pushNulls_back(p - lnumb1.getPoint());
	lnumb2.pushNulls_back(p - lnumb2.getPoint());
	vector<int> add = addBinary(lnumb1.getNumber(), lnumb2.getNumber());
	while (add[add.size() - 1] == 0 && p != 0)
	{
		add.erase(add.end() - 1);
		p--;
	}
	Long result;
	result.setNumber(add, p);
	return result;
}

Long Long::divDouble(Long lnumb1, Long lnumb2)
{
	if (isNull(lnumb1)) return lnumb1;
	int nulls = 2 * lnumb2.size();
	lnumb1.pushNulls_back(nulls);

	int p = lnumb1.getPoint() + nulls - lnumb2.getPoint();
	vector<int> div = divBinary(lnumb1.getNumber(), lnumb2.getNumber());
	while (div[div.size() - 1] == 0 && p != 0)
	{
		div.erase(div.end() - 1);
		p--;
	}
	Long result;
	result.setNumber(div, p);
	return result;
}

Long Long::operator+(Long &longNumber)
{
	Long N;
	vector<int> n(addBinary(mNumber, longNumber.getNumber()));
	N.setNumber(n);
	return N;
}

Long Long::operator-(Long &longNumber)
{
	Long N;
	vector<int> n(subBinary(mNumber, longNumber.getNumber()));
	N.setNumber(n);
	return N;
}

Long Long::operator*(Long &longNumber)
{
	Long N;
	vector<int> n(mulBinary(mNumber, longNumber.getNumber()));
	N.setNumber(n);
	return N;
}

Long Long::operator/(Long &longNumber)
{
	Long N;
	vector<int> n(divBinary(mNumber, longNumber.getNumber()));
	N.setNumber(n);
	return N;
}

Long Long::operator%(Long &number)
{
	Long thisNumber(*this);
	if(isNegative(thisNumber)) return (thisNumber - (thisNumber / number) * number) + number;
	else return thisNumber - (thisNumber / number) * number;
		
}

bool Long::operator<(Long & number)
{
	Long thisNumber(*this);
	return isNegative(thisNumber - number);
}

bool Long::operator==(Long & longNumber)
{
	return isNull((*this) - longNumber);
}

int Long::operator[](int i)
{
	return mNumber[i];
}

//Long Long::pow(Long power)
//{
//	Long thisNumber(*this);
//	power = power - numbers[1];
//	while (numbers[0] < power)
//	{
//		thisNumber = thisNumber * thisNumber;
//		power = power - numbers[1];
//	}
//	return thisNumber;
//}

Long Long::splitNumber(int part, int nParts, int &nPartNumbers)
{
	if (size() % nParts) pushNulls_front(nParts - size() % nParts);
	nPartNumbers = size() / nParts;

	auto iterPart1 = mNumber.begin();
	advance(iterPart1, (part - 1) * nPartNumbers);
	auto iterPart2 = mNumber.begin();
	advance(iterPart2, part * nPartNumbers);
	vector<int> res;
	res.insert(res.begin(), iterPart1, iterPart2);
	Long result;
	result.setNumber(res);
	return result;
}

Long Long::splitNumber(int part, int nParts)
{
	if (size() % nParts) pushNulls_front(size() % nParts);
	int nPartNumbers = size() / nParts;

	auto iterPart1 = mNumber.begin();
	advance(iterPart1, (part - 1) * nPartNumbers);
	auto iterPart2 = mNumber.begin();
	advance(iterPart2, part * nPartNumbers);
	vector<int> res;
	res.insert(res.begin(), iterPart1, iterPart2);
	Long result;
	result.setNumber(res);
	return result;
}

void Long::equalDigitsAmount(Long &longNumber)
{
	if (size() != longNumber.size())
	{
		longNumber.pushNulls_front(this->size() - longNumber.size());
	}
}

Long Long::pushNulls_back(int nNulls)
{
	if (nNulls > 0) mNumber.insert(mNumber.end(), nNulls, 0);
	return (*this);
}

Long Long::pushNulls_front(int nNulls)
{
	if(nNulls > 0) mNumber.insert(mNumber.begin(), nNulls, 0);
	return (*this);
}

Long Long::pushOnes_back(int nOnes)
{
	if (nOnes > 0) mNumber.insert(mNumber.end(), nOnes, 1);
	return (*this);
}

Long Long::pushOnes_front(int nOnes)
{
	if (nOnes > 0) mNumber.insert(mNumber.begin(), nOnes, 1);
	return (*this);
}

void Long::decimalToBinary(vector<int> aBinary)
{
	if (isNull(aBinary))
	{
		mNumber = aBinary;
		return;
	}
	while (!(aBinary.empty()))
	{
		if (aBinary[0] == 0)
		{
			aBinary.erase(aBinary.begin());
		}
		else
		{
			for (unsigned int i = 0; i < (aBinary.size() - 1); ++i)
			{
				aBinary[i + 1] += (aBinary[i] % 2) * 10;
				aBinary[i] /= 2;
			}
			mNumber.insert(mNumber.begin(), aBinary[aBinary.size() - 1] % 2);
			aBinary[aBinary.size() - 1] /= 2;
		}
	}
}

void Long::decimalToBinary(int number)
{
	while (number != 0) {
		mNumber.insert(mNumber.begin(), number % 2);
		number /= 2;
	}
}

vector<int> Long::minusNumber(vector<int> &numb)
{
	numb[0] *= -1;
	return numb;
}

bool Long::isNegative(vector<int> &numb)
{
	return (numb[0] < 0);
}

bool Long::isNegative(Long & number)
{
	return isNegative(number.getNumber());
}

bool Long::isNull(Long & number)
{
	return isNull(number.getNumber());
}

bool Long::isNull(vector<int>& number)
{
	if (number[0] == 0 && number.size() == 1) return true;
	else return false;
}

void Long::clearNulls(vector<int>& numb1)
{
	while (numb1[0] == 0 && numb1.size() != 1)
		{
			numb1.erase(numb1.begin());
		}
}

Polynom::Polynom(Long number)
{
	a = number.splitNumber(1, 3, digitsAmnt);
	b = number.splitNumber(2, 3);
	c = number.splitNumber(3, 3);
}

int Polynom::getDigitsAmnt()
{
	return digitsAmnt;
}

Long Polynom::operator()(Long x)
{
	return (a * x + b) * x + c;
}

