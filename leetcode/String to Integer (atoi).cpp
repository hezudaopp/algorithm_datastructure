#include <iostream>

using namespace std;

#define INTMAX ~(1<<(sizeof(int)*8-1))
#define INTMIN -INTMAX-1

class Solution {
public:
    int atoi(const char *str) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (str == NULL) return 0;
        int sign = 1;
        while (str[0] == ' ') {
        	str++;
        }
        if (str[0] == '-' || str[0] == '+') {
        	if (str[0] == '-') sign = -1;
        	str++;
        } 


        int len = strlen(str);
        while (str[0] == '0') {
        	str++;
        }        
        long long result = 0;
        if (str[0] <= '9' && str[0] >= '0') {
        	result = str[0]-'0';
        	str++;
        } else {
        	return 0;
        }
        while (str[0] != '\0') {
        	if (str[0] <= '9' && str[0] >= '0') {
        		result = 10*result + str[0] - '0';
        		if (result > INTMAX) {
        			if (sign == -1) {
        				return INTMIN;
        			} else {
        				return INTMAX;
        			}
        		}
        		str++;
        	} else {
        		return result * sign;
        	}
        }
        return result*sign;
    }
};

int main (char *argv[], int argc) {
	Solution sol;
	cout << sol.atoi("2147483648") << endl;
}