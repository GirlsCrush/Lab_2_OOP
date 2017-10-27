#include <iostream>
#include "Long.h"
#include <fstream>
using namespace std;

int main()
{ 
	/*vector<int> a = { 6, 7, 1, 5, 1, 1, 1, 1, 1, 1, 1, 1 };
	vector<int> b = { 6, 8, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1 };*/
	/*vector<int> a = { 1, 2, 3 , 4 };
	vector<int> b = { 2, 3, 4, 1 };*/
	/*vector<int> a = { 2, 3, 4 };
	vector<int> b = { 3, 4, 1 };*/
	vector<int> a = { 5, 0, 1, 3 ,5};
	vector<int> b = { 2, 0, 0, 0 };
	/*int a = 23;*/
	Long number1(a);
	Long number2(b);

	(number2.divKuk(number1)).coutNumber();
	//Long Mul(number1.mulSheng(number2));
	///*cout << Long::isPrimeSolStrass(a, 1) << endl;*/

	//ofstream fout("res1.txt");
	//for (unsigned int i = 0; i < Mul.getNumber().size(); i++)
	//{
	//	fout << Mul.getNumber()[i];
	//}
	//fout.close();
	////vector<int> c = Long::subBinary(a, b);
	///*ofstream f1out("0.txt");
	//for (unsigned int i = 0; i < Mul.getNumber().size(); i++)
	//{
	//	f1out << Mul.getNumber()[i];
	//}
	//f1out.close();
	//*/
	//ofstream f2out("a.txt");
	//for (unsigned int i = 0; i < (number1.getNumber()).size(); i++)
	//{
	//	f2out << (number1.getNumber())[i];
	//}

	//f2out.close();
	//ofstream f3out("b.txt");
	//for (unsigned int i = 0; i < (number2.getNumber()).size(); i++)
	//{
	//	f3out << (number2.getNumber())[i];
	//}
	//f3out.close();

	system("pause");
	return 0;
}