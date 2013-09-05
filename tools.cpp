#include <cstdio>
#include <string>
#include <vector>

#include "tools.h"

Tools::void getWordFromFile(std::vector<string> &v, string filename) {
	ifstream ifs(filename.c_str());
	string str;
	char signArr[] = {',', '.'}; 
	while (ifs >> str) {
		for (int i = 0; i < sizeof(signArr); ++i)
		{
			if (signArr[i] == str[str.length()-1]) {
				str = str.substr(0, str.length()-1);
			}
		}
		for (int i = 0; i < str.length(); ++i)
		{
			str[i] = tolower(str[i]);
		}
		v.push_back(str);
	}
}