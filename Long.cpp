#include "Long.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
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
}

Long::Long(Long &longNumber)
{
	mNumber = longNumber.getNumber();
}

Long::Long(const Long &longNumber)
{
	mNumber = longNumber.getNumber();
}

void Long::coutNumber()const
{
	ofstream fout("1.txt"); 
	for (unsigned int i = 0; i < mNumber.size(); i++)
	{
		fout << mNumber[i];
	}
	fout.close();
}

Long Long::mulKaracuba(Long longNumber) const
{
	Long v(longNumber);	
	Long u(*this);
	u.equalDigitsAmount(v);
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

vector<int> Long::getNumber() const
{
	return mNumber;
}

void Long::setNumber(vector<int> longNumber)
{
	mNumber = longNumber;
}

int Long::size()const
{
	return mNumber.size();
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

Long Long::polynomTomKuk(vector<int> numb, vector<int> x) const
{
	/*vector<int> numb = numbL.getNumber();
	vector<int> x = xL.getNumber();*/
	for (int i = 0; i < (numb.size() % 3); ++i) numb.insert(numb.begin(), 0);
	vector<int> a;
	vector<int> b;
	vector<int> c;
	vector<int> polynom;
	int numbThird = numb.size() / 3;
	auto iterNumbThird = numb.begin();
	advance(iterNumbThird, numbThird);
	auto iterNumbTwoThird = iterNumbThird;
	advance(iterNumbTwoThird, numbThird);
	a.insert(a.begin(), numb.begin(), iterNumbThird);
	b.insert(b.begin(), iterNumbThird, iterNumbTwoThird);
	c.insert(c.begin(), iterNumbTwoThird, numb.end());
	polynom = mulBinary(x, a);
	polynom = addBinary(polynom, b);
	polynom = mulBinary(polynom, x);
	polynom = addBinary(polynom, c);
	Long result;
	result.setNumber(polynom);
	return result;
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

int Long::operator[](int i)
{
	return mNumber[i];
}

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
		(size() < longNumber.size() ? *this: longNumber).pushNulls_front(longNumber.size() - this->size());
		(size() < longNumber.size() ? longNumber: *this).pushNulls_front(longNumber.size() - this->size());
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

vector<int> Long::minusNumber(vector<int> &numb)
{
	numb[0] *= -1;
	return numb;
}

bool Long::isNegative(vector<int> &numb)
{
	return (numb[0] < 0);
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

