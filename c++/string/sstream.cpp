#include <string>
#include <sstream>
#include <iostream>

using namespace std;

void main()
{
	string str = "hello!world";
	stringstream ss(str);
	string out;
	while (getline(ss, out, '!'))
	{
		cout << out << endl;
	}
}