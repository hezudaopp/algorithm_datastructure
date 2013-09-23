#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define FILENAME "A-large.in"
#define OUTFILE "A-large.out"

string readNumber(string str, int start, int count) {
	string result;
	int end = start + count;
	char lastDigit = str[start];
	int sameDigitNumber = 1;
	for (int i=start+1; i<=end; i++) {
		if (i==end || str[i] != lastDigit) {
			string tmp;
			switch (lastDigit) {
				case '0':
					tmp = "zero ";
					break;
				case '1':
					tmp = "one ";
					break;
				case '2':
					tmp = "two ";
					break;
				case '3':
					tmp = "three ";
					break;
				case '4':
					tmp = "four ";
					break;
				case '5':
					tmp = "five ";
					break;
				case '6':
					tmp = "six ";
					break;
				case '7':
					tmp = "seven ";
					break;
				case '8':
					tmp = "eight ";
					break;
				case '9':
					tmp = "nine ";
					break;
			}
			switch (sameDigitNumber) {
				case 2:
					result.append("double " + tmp);
					break;
				case 3:
					result.append("triple " + tmp);
					break;
				case 4:
					result.append("quadruple " + tmp);
					break;
				case 5:
					result.append("quintuple " + tmp);
					break;
				case 6:
					result.append("sextuple " + tmp);
					break;
				case 7:
					result.append("septuple " + tmp);
					break;
				case 8:
					result.append("octuple " + tmp);
					break;
				case 9:
					result.append("nonuple " + tmp);
					break;
				case 10:
					result.append("decuple " + tmp);
					break;
				default:
					for (int j=0; j<sameDigitNumber; j++) {
						result.append(tmp);
					}
					break;
			}
			if (i < end) {
				lastDigit = str[i];
				sameDigitNumber = 1;
			}
		} else {
			sameDigitNumber++;
		}
	}
	return result;
}

int main(char *argv[], int argc) {
	ifstream ifs(FILENAME);
	ofstream ofs(OUTFILE);
	int test;
	ifs >> test;
	for (int t=1; t <= test; t++) {
		string number;
		ifs >> number;
		char seperator[200];
		ifs >> seperator;
		char * pch;
		pch = strtok (seperator, "-");
		string result;
		int offset = 0;
		while (pch != NULL) {
			int count = atoi(pch);
			result.append(readNumber(number, offset, count));
			pch = strtok (NULL, "-");
			offset += count;
		}
		ofs << "Case #" << t << ": " << result.substr(0,result.length()-1);
		if (t!=test) ofs << endl;
	}
	return 0;
}