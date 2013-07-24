#include <queue>
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

class Solution {
public:

    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        std::vector<string> result;
    	std::vector<string> v;
        insertIpAddresses(s, 3, result, v);
        return result;
    }

    void insertIpAddresses(string s, int num, std::vector<string> &result, std::vector<string> &v) {
    	if (num == 0 && isValidAddress(s)) {
    		string res = v[0] + "." + v[1] + "." + v[2] + "." + s;
    		cout << res << endl;
    		result.push_back(res);
    		return;
    	} else {
    		for (int i=1; i<=3; i++) {
    			int len = s.length();
    			if (len >= num+1 && len <= 3*(num+1) && len >= i) {
    				string sub = s.substr(0, i);
    				if (!isValidAddress(sub)) continue;
		    		v.push_back(sub);
		    		insertIpAddresses(s.substr(i), num-1, result, v);
		    		v.pop_back();
		    	}
    		}
    	}
    }

	bool isValidAddress(string s) {
		int len = s.length();
		if (len == 1 ) return true;
		if (len == 2 && s[0] != '0') return true;
		if (len == 3) {
			int val = atoi(s.c_str());
			if (val >=100 && val <= 255) {
				return true;
			}
		}
		return false;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	s.restoreIpAddresses("0000");
}