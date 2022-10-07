#include <vector>
#include <algorithm>

using namespace std;

bool cmpFirstAsc(const pair<int, int>& a, const pair<int, int>& b)
{
	return a.first < b.first;
}

bool cmpFirstDesc(const pair<int, int>& a, const pair<int, int>& b)
{
	return a.first > b.first;
}

bool cmpSecondAsc(const pair<int, int>& a, const pair<int, int>& b)
{
	return a.second < b.second;
}

bool cmpSecondDesc(const pair<int, int>& a, const pair<int, int>& b)
{
	return a.second > b.second;
}

void main()
{
	vector<pair<int, int>> vt = { {1,1}, {2,2}, {3,3}, {4,4}, {5,5} };
	sort(vt.begin(), vt.end(), cmpFirstAsc);
	sort(vt.begin(), vt.end(), cmpFirstDesc);
	sort(vt.begin(), vt.end(), cmpSecondAsc);
	sort(vt.begin(), vt.end(), cmpSecondDesc);
}