#include <string>
#include <iostream>

using namespace std;

string units[] = {"", "", "拾","佰","仟"};
string chineseNumbers[] = {"零","壹", "贰", "叁", "肆", "伍", "陆", "柒", "扒", "玖"};

bool isZeroBefore = false;

string getChineseNumberStringWithLastZero(string integer) {
	int len = integer.length();
	if (len == 0) return "";
	if (len == 1) {
		int i = integer[0]-'0';
		string result = chineseNumbers[i];
		if (!i && isZeroBefore) result = "";
		i==0 ? isZeroBefore = true : isZeroBefore = false;
		return result;
	}
	if (len >= 2 && len<=4) {
		string result(getChineseNumberStringWithLastZero(integer.substr(0,1)));
		if (integer[0] != '0')
			result += units[len];
		return result+getChineseNumberStringWithLastZero(integer.substr(1));
	}
	if (len>=5 && len<9) {
		return getChineseNumberStringWithLastZero(integer.substr(0,len-4))+"万"+getChineseNumberStringWithLastZero(integer.substr(len-4));
	}
	if (len>=9 && len<17) {
		return getChineseNumberStringWithLastZero(integer.substr(0,len-8))+"亿"+getChineseNumberStringWithLastZero(integer.substr(len-8));
	}
}

string getChineseNumberString(string integer) {
	string result = getChineseNumberStringWithLastZero(integer);
	if (integer.substr(integer.length()-1).compare("0") == 0)
		result = result.substr(0, result.length()-3);
	return result;
}

int main (char *argv[], int argc) {
	string intergers[] = {"10000", "1000", "1001", "10001", "10020", "30303"};
	for (int i=0; i<sizeof(intergers)/sizeof(string); i++) {
		cout << getChineseNumberString(intergers[i]) << endl;
	}
	return 0;
}