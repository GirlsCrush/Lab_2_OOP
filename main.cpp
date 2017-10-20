#include <iostream>
#include "Long.h"
#include <fstream>
using namespace std;

int main()
{
	vector<int> a = { 1,1,0,1,1,1,1,0,1,0,0,1,0,0,0,1 };
	vector<int> b = { 1,1,1,1,0,1,0,1,0,0,1,1,1,0,0,0,1 };
	Long number(a);
/*
	ofstream f1out("2.txt");
	for (unsigned int i = 0; i < a.size(); i++)
	{
		f1out << a[i];
	}
	f1out.close();

	ofstream f2out("3.txt");
	for (unsigned int i = 0; i < b.size(); i++)
	{
		f2out << b[i];
	}
	f2out.close();
*/
	system("pause");
}