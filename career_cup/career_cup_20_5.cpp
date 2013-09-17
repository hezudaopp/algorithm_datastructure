#include <iostream>
#include <fstream>

using namespace std;

int minDistanceOfTwoWords(ifstream &ifs, string &str1, string &str2) {
	string str;
	int result = -1;
	int currentDistance = 0;
	bool isStartCouting = false;
	string strToMap;
	while (ifs >> str) {
		if (str.compare(str1) == 0) {
			if (strToMap.empty()) {
				isStartCouting = true;
				strToMap = str2;
			} else if (strToMap.compare(str2) == 0) {

			} else if (strToMap.compare(str1) == 0){
				cout << currentDistance << endl;
				strToMap = str2;
				if (result == -1 || (result != -1 && currentDistance < result)) {
					result = currentDistance;
				}
			}
			currentDistance = 0;
		} else if (str.compare(str2) == 0) {
			if (strToMap.empty()) {
				isStartCouting = true;
				strToMap = str1;
			} else if (strToMap.compare(str1) == 0) {

			} else if (strToMap.compare(str2) == 0){
				cout << currentDistance << endl;
				strToMap = str1;
				if (result == -1 || (result != -1 && currentDistance < result)) {
					result = currentDistance;
				}
			}
			currentDistance = 0;
		}
		if (isStartCouting) currentDistance++;
	}
	return result;
}

int main (char *argv[], int argc) {
	ifstream ifs("career_cup_20_5.cpp");
	string str1 = "currentDistance";
	string str2 = "if";
	cout << minDistanceOfTwoWords(ifs, str1, str2) << endl;
	return 0;
}