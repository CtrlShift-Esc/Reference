#include <string>
#include <vector>
#include <thread>
#include <future>
#include <iostream>
#include <algorithm>
#include <map>
#include <chrono>

using namespace std;

class Loader
{
public:
	Loader() {}
	~Loader() {}

	void loadData(promise<int>& result, vector<int>* data)
	{
		for (int i = 0; i < 100000; i++)
			data->push_back(i);
		result.set_value(1);
	}
};

class Builder
{
public:
	Builder() {}
	~Builder() {}

	void loadDatas(string key, map<string, vector<int>>& datas)
	{
		if (promises.find(key) == promises.end())
			promises[key] = promise<int>();		
		promise<int>& promise = promises[key];
		if (workers.find(key) == workers.end())
			workers[key] = thread(std::bind(&Loader::loadData, &loader, std::ref(promise), &datas[key]));
	}

	int isFinished(string key)
	{
		promise<int>& r = promises[key];
		auto f = r.get_future();
		
		if (f.get())
		{
			return 1;
		}
		return 0;
	}	

private:

	map<string, thread> workers;
	map<string, promise<int>> promises;
	Loader loader;
};

int main()
{
	Builder builder;
	int works = 20;
	map<string, vector<int>> datas;

	for (int i = 0; i < works; i++)
	{
		string key = to_string(i);
		if (datas.find(key) == datas.end())
			datas[key] = vector<int>();
		builder.loadDatas(key, datas);
	}

	map<int, int> finished;
	int finishedCnt = 0;
	while (1)
	{
		for (int i = 0; i < works; i++)
		{
			if (!finished[i] && builder.isFinished(to_string(i)) == 1)
			{
				finished[i] = 1;
				finishedCnt++;
			}
		}
		if (finishedCnt == works)
			break;
	}	

	return 0;
}