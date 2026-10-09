#include <vector>
#include <iostream>
#include <string>

using namespace std;

vector<string> names;
class uniqorn
{
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
				cout << "this uniqorn has the same name as another, " << n << "!! BEGONE FOUL CREATURE!!!!!!!" << endl;
				uniq = false;
			}
		}
		name = n;
		names.push_back(n);
		if (uniq)
			cout << "a worthy uniqorn has been born: " << name << endl;
		else throw exception("THIS UNIQORN IS UNWORTHY!");
		
	}

	~uniqorn()
	{
		cout << "goodbye, " << name << endl;
		auto start = names.begin();
		auto end = names.end();
		vector<string>::iterator found = end;
		for (auto i = start; i != end; i++)
		{
			if (*i == name)
			{
				found = i;
			}
		}
		if (found != end)
		{
			names.erase(found);
		}
	}
};

int main()
{
	uniqorn* x = new uniqorn("harry");
	uniqorn* y = new uniqorn("bob");
	uniqorn* z = new uniqorn("joe");
	delete y;
	uniqorn* a = new uniqorn("bob");
	delete x;
	uniqorn* b = new uniqorn("harry");
	uniqorn* c = new uniqorn("joe");
}