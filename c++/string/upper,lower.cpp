#include <string>
#include <algorithm>

using namespace std;

void main()
{
	string str = "hello!world";
	transform(str.begin(), str.end(), str.begin(), ::toupper);
	transform(str.begin(), str.end(), str.begin(), ::tolower);
}