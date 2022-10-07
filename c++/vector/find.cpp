#include <vector>
#include <algorithm>

using namespace std;

void main()
{
	vector<int> vt = {1, 2, 3, 4, 5};
	auto itr = find(vt.begin(), vt.end(), 1);
	if (itr != vt.end())
	{
		// find
	}
}