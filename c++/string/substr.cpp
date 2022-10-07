#include <string>

using namespace std;

void main()
{
	string str = "!hello!";
	str = str.substr(1, str.length() - 2);
}