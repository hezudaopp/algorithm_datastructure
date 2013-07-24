/*Problem Statement
    
The product value of a string is the product of all the digits ('0'-'9') in the string. 
For example, the product value of "123" is 1 * 2 * 3 = 6. 
A string is called colorful if it contains only digits and the product value of each of its nonempty contiguous substrings is distinct. 
For example, the string "263" has six substrings: "2", "6", "3", "26", "63" and "263". 
The product values of these substrings are: 2, 6, 3, 2 * 6 = 12, 6 * 3 = 18 and 2 * 6 * 3 = 36, respectively. 
Since all six product values are distinct, "263" is colorful. 
On the other hand, "236" is not colorful because two of its substrings, "6" and "23", have the same product value (6 = 2 * 3). 
Return the k-th (1-based) lexicographically smallest colorful string of length n. 
If there are less than k colorful strings of length n, return an empty string instead.
Definition
    
Class:
ColorfulStrings
Method:
getKth
Parameters:
int, int
Returns:
string
Method signature:
string getKth(int n, int k)
(be sure your method is public)
    

Notes
-
The lexicographically smaller of two strings is the one that has the smaller character ('0' < '1' < ... < '9') at the first position where they differ.
Constraints
-
n will be between 1 and 50, inclusive.
-
k will be between 1 and 1,000,000,000, inclusive.
Examples
0)

    
3
4
Returns: "238"
The first four smallest colorful strings of length 3 are "234", "235", "237" and "238".
1)

    
4
2000
Returns: ""
The number of colorful strings of length 4 is less than 2000.
2)

    
5
1
Returns: "23457"

3)

    
2
22
Returns: "52"

4)

    
6
464
Returns: "257936"

This problem statement is the exclusive and proprietary property of TopCoder, Inc. 
Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. 
(c)2003, TopCoder, Inc. All rights reserved.
 */

/*
string int_to_string (int i) {
	return '0' + i;
}

void reverseString(string &theWord) {       // Reverse the string contained in theWord.
    int i;
    char temp;
    
    for (i=0; i<theWord.length()/2; i++)
    {
    	temp = theWord[i];
    	theWord[i] = theWord[theWord.length()-i-1];
    	theWord[theWord.length()-i-1] = temp;
    }
} 
*/
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <set>

#define SIZE 8
#define FOR(i, a, b) for(int i = (a); i < (b); i++)

using namespace std;

class ColorfulStrings {
	public:
	string getKth(int n, int k) {
		string result = "";
		if (n < 1 || n > 8) return result;
		if (n == 1 && k <= 10) {
			result += '0' + k-1;
			return result;
		}
		int index = 0, count = 0;
		int perm[SIZE];
		FOR(i, 2, 2+SIZE) perm[index++] = i;
		do {
			count += isColorful (perm, n);
			if (count == k) {
				FOR(i, 0, n) result += '0' + perm[i];
				break;
			}
			reverse(perm+n, perm+SIZE);
		} while (next_permutation(perm, perm+SIZE));
		return result;
	}

	private:
		std::vector<int> colors;

		int isColorful(int perm[], unsigned int len) {
			// cout << str << " " << len;
			std::set<int> s;
			for (int i = 0; i < len; i++) {
				int product = 1;
				for (int j = i; j < len; j++) {
					product *= perm[j];
					if (!s.insert(product).second) {
						return 0;
					}
				}
			}
			return 1;
		}
};

int main (int argc, char **argv) {
	ColorfulStrings cs;
	cout << cs.getKth(1, 1) << endl;
	return 0;
}