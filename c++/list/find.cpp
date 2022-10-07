#include <list>
#include <algorithm>

using namespace std;

void main()
{
	list<int> lst = { 1, 2, 3, 4, 5 };
	list<int>::iterator itr = find(lst.begin(), lst.end(), 3);
	if (itr != lst.end())
	{
		// find
	}
}