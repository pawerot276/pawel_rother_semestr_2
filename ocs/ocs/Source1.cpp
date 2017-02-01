#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <vector>
#include <cmath>
std::string findAndReplace(std::string& a, std::vector<std::string>& v);
int main()
{
	std::string a = "2*e+4*PI+sqrt(2)+sqrt(5)+4*sin(4)";
	std::vector<std::string> v;
	v.push_back("sin(");
	v.push_back("cos(");
	v.push_back("tg(");
	v.push_back("sqrt(");
	v.push_back("ctg(");
	v.push_back("e");
	v.push_back("PI");

	std::string c2 = findAndReplace(a, v);
	std::cout << c2;

	return 0;
}
std::string findAndReplace(std::string& a, std::vector<std::string>& v)
{
	std::string copyy;
	copyy = "";
	int maxLength = 4;

	for (auto &x : v)
	{
		bool cont = true;
		while (cont)
		{
			auto it = search(a.begin(), a.end(), x.begin(), x.end());
			if (it != a.end())
			{
				if (x == "e")
				{
					float e = 23;
					a.replace(it, it + 1, "2,71");

				}
				else if (x == "PI")
				{
					a.replace(it, it + 2, "3,14");

				}
				else
				{
					auto it2 = find(it, a.end(), ')');
					while (count(it, it2 + 1, '(') != count(it, it2 + 1, ')'))
					{
						it2 = find(it2 + 1, a.end(), ')');
					}
					if (x == "sin(")
					{
						std::string temp(it + 4, it2);
						float i = stof(temp);
						std::string b = std::to_string(sin(i));

						a.replace(it, it2 + 1, b);

					}
					else if (x == "cos(")
					{
						std::string temp(it + 4, it2);
						float i = stof(temp);
						std::string b = std::to_string(cos(i));

						a.replace(it, it2 + 1, b);

					}
					else if (x == "tg(")
					{
						std::string temp(it + 3, it2);
						float i = stof(temp);
						std::string b = std::to_string(tan(i));

						a.replace(it, it2 + 1, b);

					}
					else if (x == "sqrt(")
					{
						std::string temp(it + 5, it2);
						float i = stof(temp);
						std::string b = std::to_string(sqrt(i));

						a.replace(it, it2 + 1, b);

					}
					else if (x == "ctg(")
					{
						std::string temp(it + 4, it2);
						float i = stof(temp);
						std::string b = std::to_string(1/tan(i));

						a.replace(it, it2 + 1, b);

					}
				}

			}
			else
				cont = false;
		}
	}
	return a;
}