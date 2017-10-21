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
	number1.mulKaracuba(number2);
	/*
	ofstream f1out("u.txt");
	for (unsigned int i = 0; i < (number1.getNumber()).size(); i++)
	{
		f1out << (number1.getNumber())[i];
	}
	f1out.close();

	ofstream f2out("v.txt");
	for (unsigned int i = 0; i < (number2.getNumber()).size(); i++)
	{
		f2out << (number2.getNumber())[i];
	}
	f2out.close();
	*/
	system("pause");
}