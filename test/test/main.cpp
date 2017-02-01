#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
//sin cos th ctg e  PI
string findAndReplace(string& a, vector<string>& v);
int main()
{
	string a = "2+4+sqrt((12(+44)))+4*sin(44+(2sqrt3))";
	vector<string> v;
	v.push_back("sin(");
	v.push_back("cos(");
	v.push_back("tg(");
	v.push_back("sqrt(");
	v.push_back("ctg(");
	v.push_back("e");
	v.push_back("PI");

	string c2 = findAndReplace(a, v);
	cout << c2;

	return 0;
}
string findAndReplace(string& a, vector<string>& v)
{
	string copyy;
	copyy = "";
	int maxLength = 4;

	for (auto &x : v)
	{
		auto it = search(a.begin(), a.end(), x.begin(), x.end());
		if (it != a.end())
		{
			auto it2 = find(it, a.end(), ')');
			while (count(it, it2 + 1, '(') != count(it, it2 + 1, ')'))
			{
				it2 = find(it2 + 1, a.end(), ')');
			}
			a.replace(it, it2 + 1, "K");
		}
	}
	return a;
}
