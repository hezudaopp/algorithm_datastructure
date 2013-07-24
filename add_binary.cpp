#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int a_index = a.length()-1;
        int b_index = b.length()-1;
        string result="";
        int last = 0;
        while (a_index >= 0 || b_index >= 0 ) {
        	char a_value = (a_index >= 0) ? a.at(a_index) : '0';
        	char b_value = (b_index >= 0) ? b.at(b_index) : '0';
        	int cur = last + (a_value - '0') + (b_value - '0');
        	if (cur == 3) {
        		last = 1;
        		result.insert(result.begin(), '1');
        	} else if (cur == 2) {
        		last = 1;
        		result.insert(result.begin(), '0');
        	} else if (cur == 1) {
        		last = 0;
        		result.insert(result.begin(), '1');
        	} else if (cur == 0) {
        		last = 0;
        		result.insert(result.begin(), '0');
        	}
        	--a_index;
        	--b_index;
        }
        if (last == 1) result.insert(result.begin(), '1');
        return result;
    }
};

int main (int argc, char *argv[]) {
	Solution s;
	string a = "11110001", b = "100000011111111";
  	cout << s.addBinary(a, b) << endl;
	return 0;
}