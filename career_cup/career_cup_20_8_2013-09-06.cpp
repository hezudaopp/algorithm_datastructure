#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool startsWith (string longString, string shortString) {
	if (shortString.empty()) return true;
	if (longString.empty()) return false;
	if ((longString[0]) == (shortString[0])) 
		return startsWith(longString.substr(1), shortString.substr(1));
	else
		return false;
}

int main (char *argv[], int argc) {
	string testString = "mississippi";
	const int stringSize = testString.length();
	vector<string> suffixVector(stringSize);
	for (int i=0; i<testString.length(); i++) {
		suffixVector[i] = testString.substr(i);
	}
	string strArr[] = {"is","sip", "hi", "sis"};
	int strArrSize = sizeof(strArr)/sizeof(string);
	for (int i=0; i<strArrSize; i++) {
		cout << strArr[i] << ":";
		vector<int> indexResult;
		for (int j=0; j<suffixVector.size(); j++) {
			if (startsWith(suffixVector[j], strArr[i])) {
				indexResult.push_back(j);
			}
		}
		for (int k=0; k<indexResult.size(); k++) {
			cout << indexResult[k] << " ";
		}
		cout << endl;
	}
	return 0;
}