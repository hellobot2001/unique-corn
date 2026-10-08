#include <vector>
#include <iostream>
#include <string>

using namespace std;
class uniqorn
{
private:
	static vector<string> names;
public:
	string name;
	uniqorn(string n)
	{
		auto start = names.begin();
		auto end = names.end();
		bool uniq = true;
		for (auto i = start; i != end; i++)
		{
			if (*i == n)
			{
				cout << "this uniqorn has the same name as another!! BEGONE FOUL CREATURE!!!!!!!" << endl;
				uniq = false;
				break;
			}
		}
		if (uniq)
		{
			cout << "a worthy uniqorn has been born" << endl;
			name = n;
			names.push_back(n);
		}
		else delete this;
	}

	~uniqorn()
	{
		auto start = names.cbegin();
		auto end = names.cend();
		for (auto i = start; i != end; i++)
		{
			if (*i == name)
			{
				names.erase(i);
			}
		}
	}
};

int main()
{
	uniqorn x("harry");
	uniqorn y("bob");
	uniqorn z("joe");
	uniqorn w("bob");
}