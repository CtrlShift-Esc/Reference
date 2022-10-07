#include <vector>
#include <algorithm>

using namespace std;

void main()
{
	vector<int> vt = { 3, 2, 1, 5, 6 };
	//asc
	sort(vt.begin(), vt.end());
	//desc
	sort(vt.begin(), vt.end(), greater<int>());
}