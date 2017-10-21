#include "Long.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

Long::Long(vector<int> &a)
{
	decimalToBinary(a);
}

void Long::coutNumber()
{
	ofstream fout("1.txt"); 
	for (unsigned int i = 0; i < mNumber.size(); i++)
	{
		fout << mNumber[i];
	}
	fout.close();
}

vector<int> Long::mulKaracuba(Long longNumber) const
{
	vector<int> result;
	vector<int> v(longNumber.getNumber());	// longnumber.
	vector<int> u(getNumber());	// mNumber.
	vector<int> v1;	
	vector<int> v0;
	vector<int> u1;
	vector<int> u0;
	int middleU = u.size() / 2;
	int middleV = v.size() / 2;
	auto iterMiddleU = u.begin();
	auto iterMiddleV = v.begin();
	advance(iterMiddleU, middleU);
	advance(iterMiddleV, middleV);
	v1.insert(v1.begin(),v.begin(), iterMiddleV);
	v0.insert(v0.begin(), iterMiddleV, v.end());
	u1.insert(u1.begin(), u.begin(), iterMiddleU);
	u0.insert(u0.begin(), iterMiddleU, u.end());
	/*
	ofstream fout("v1.txt");	
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

	vector<int> product1 = mulBinary(v1, u1);
	vector<int> product2 = mulBinary(subBinary(u1, u0), subBinary(v0, v1));
	vector<int> product3 = mulBinary(v0, u0);
	ofstream faout("product1.txt");
	/*
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
	product1.insert(product1.end(), middleV + 1, 0);
	result = product1;
	product1.insert(product1.end(), middleV + 1, 0);
	result = addBinary(result, product1);
	product2.insert(product2.end(), middleV + 1, 0);
	result = addBinary(result, product2);
	result = addBinary(result, product3);
	product3.insert(product3.end(), middleV + 1, 0);
	result = addBinary(result, product3);
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

vector<int> Long::getNumber() const
{
	return mNumber;
}

vector<int> Long::mulBinary(vector<int> numb1, vector<int> numb2)
{
	if (numb1[0] == 0)
	{
		while (numb1[0] == 0 && numb1.size() != 1)
		{
			numb1.erase(numb1.begin());
		}
	}
	if (numb2[0] == 0)
	{
		while (numb2[0] == 0 && numb2.size() != 1)
		{
			numb2.erase(numb2.begin());
		}
	}
	vector<int> result((numb1.size() <= numb2.size() ? numb2.size() : numb1.size()), 0);
	vector<int> less = (numb1.size() <= numb2.size() ? numb1 : numb2);
	vector<int> more = (numb1.size() <= numb2.size() ? numb2 : numb1);
	
		if (isNegative(less) && isNegative(more))
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
	if (numb1[0] == 0)
	{
		while (numb1[0] == 0 && numb1.size() != 1)
		{
			numb1.erase(numb1.begin());
		}
	}
	if (numb2[0] == 0)
	{
		while (numb2[0] == 0 && numb2.size() != 1)
		{
			numb2.erase(numb2.begin());
		}
	}
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
			return sum;
		}
}

vector<int> Long::subBinary(vector<int> numb1, vector<int> numb2)
{
	if (numb1[0] == 0)
	{
		while (numb1[0] == 0 && numb1.size() != 1)
		{
			numb1.erase(numb1.begin());
		}
	}
	if (numb2[0] == 0)
	{
		while (numb2[0] == 0 && numb2.size() != 1)
		{
			numb2.erase(numb2.begin());
		}
	}
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
				vector<int> zero(1, 0);
				return zero;
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
		while (diff[0] == 0)
		{
			diff.erase(diff.begin());
		}
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

void Long::decimalToBinary(vector<int> &a)
{
	vector<int> aBinary(a);
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
