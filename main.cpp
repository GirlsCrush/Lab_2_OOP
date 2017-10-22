#include <iostream>
#include "Long.h"
#include <fstream>
using namespace std;

int main()
{
	vector<int> a = { 6, 7, 1, 5, 0 };
	vector<int> b = { 6, 8, 0, 1, 4 };
	Long number1(a);
	Long number2(b);
	Long Mul(number1.mulTomKuk(number2));
	ofstream f1out("0.txt");
	for (unsigned int i = 0; i < Mul.getNumber().size(); i++)
	{
		f1out << Mul.getNumber()[i];
	}
	f1out.close();
	/*
	ofstream f2out("-1.txt");
	for (unsigned int i = 0; i < (number1.getNumber()).size(); i++)
	{
		f2out << (number1.getNumber())[i];
	}
	f2out.close();
	*/
	system("pause");
}