class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i=0, j=s.length()-1;
        while (i<=j) {
        	s[i] = tolower(s[i]);
        	if ( (s[i] > 'z' || s[i] < 'a') && (s[i] > '9' || s[i] < '0')) {
        		i++;
        		continue;
        	}
        	s[j] = tolower(s[j]);
        	if ( (s[j] > 'z' || s[j] < 'a') && (s[j] > '9' || s[j] < '0')) {
        		j--;
        		continue;
        	}
        	if (s[i] != s[j]) return false;
        	i++; j--;
        }
        return true;
    }
};

