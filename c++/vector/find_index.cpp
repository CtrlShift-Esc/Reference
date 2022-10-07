#include <vector>
#include <algorithm>

using namespace std;

void main()
{
	vector<int> vt = { 1, 2, 3, 4, 5 };
	int index = find(vt.begin(), vt.end(), 3) - vt.begin();
	// or
	index = std::distance(vt.begin(), find(vt.begin(), vt.end(), 3));
}