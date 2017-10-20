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

vector<int>& Long::mulKaracuba(vector<int> multplr) const
{
	return multplr;
}

vector<int>& Long::multiplyBinary(vector<int> numb1, vector<int> numb2) const
{
	vector<int> result;
	for (unsigned int i = 0; i < numb2.size(); ++i)
	{

	}
	return result;
}

vector<int>& Long::plusBinary(vector<int> numb1, vector<int> numb2) 
{
	vector<int> sum = (numb1.size() <= numb2.size() ? numb2 : numb1);
	vector<int> less = (numb1.size() <= numb2.size() ? numb1 : numb2);
	for (unsigned int i = 0; i < numb1.size() && i < numb2.size(); ++i)
	{
		sum[sum.size() - 1 - i] += less[numb1.size() - 1 - i];
	}
	for (int i = (numb1.size() <= numb2.size() ? numb2.size() : numb1.size()) - 1; i > 0; --i)
	{
		sum[i - 1] += sum[i] / 2;
		sum[i] %= 2;
	}
	if (sum[0] > 1)
	{
		sum[0] %= 2;
		sum.insert(sum.begin(), 1);
	}
	ofstream fout("1.txt");
	for (unsigned int i = 0; i < sum.size(); i++)
	{
		fout << sum[i];
	}
	fout.close();
	return sum;
}

void Long::decimalToBinary(vector<int> a)
{
	while (!(a.empty()))
	{
		if (a[0] == 0)
		{
			a.erase(a.begin());
		}
		else
		{
			for (unsigned int i = 0; i < (a.size() - 1); ++i)
			{
				a[i + 1] += (a[i] % 2) * 10;
				a[i] /= 2;
			}
			mNumber.insert(mNumber.begin(), a[a.size() - 1] % 2);
			a[a.size() - 1] /= 2;
		}
	}
}
