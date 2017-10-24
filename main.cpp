#include <iostream>
#include "Long.h"
#include <fstream>
using namespace std;

int main()
{
	vector<int> a = { 6, 7, 1, 5 };
	vector<int> b = { 6, 8, 0, 1, 4 };
	/*vector<int> a = { 1, 2, 3 , 4 };
	vector<int> b = { 2, 3, 4, 1 };*/
	/*vector<int> a = { 2, 3, 4 };
	vector<int> b = { 3, 4, 1 };*/
	//vector<int> a = { 5, 0 };
	//vector<int> b = { 1, 6, 0, 0 };
	Long number1(a);
	Long number2(b);

	Long Mul(number1.mulTomKuk(number2));

	ofstream fout("res1.txt");
	for (unsigned int i = 0; i < Mul.getNumber().size(); i++)
	{
		fout << Mul.getNumber()[i];
	}
	fout.close();
	//vector<int> c = Long::subBinary(a, b);
	/*ofstream f1out("0.txt");
	for (unsigned int i = 0; i < Mul.getNumber().size(); i++)
	{
		f1out << Mul.getNumber()[i];
	}
	f1out.close();
	*/
	ofstream f2out("a.txt");
	for (unsigned int i = 0; i < (number1.getNumber()).size(); i++)
	{
		f2out << (number1.getNumber())[i];
	}

	f2out.close();
	ofstream f3out("b.txt");
	for (unsigned int i = 0; i < (number2.getNumber()).size(); i++)
	{
		f3out << (number2.getNumber())[i];
	}
	f3out.close();

	system("pause");
}