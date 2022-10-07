#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.second == b.second)
		a.first > b.first;
	return a.first < b.first;
}

void main()
{
	vector<pair<int, int>> vt = { {1,1}, {2,1}, {3,1}, {4,1}, {5,1} };
	sort(vt.begin(), vt.end(), cmp);
}