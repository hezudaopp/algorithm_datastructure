#include <stack>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    

        unsigned int len1 = s1.size(), len2 = s2.size(), len3 = s3.size();
        if (len3 != len1 + len2) return false;
        std::vector<std::vector<bool> > result(len1+1, std::vector<bool>(len2+1, false));
        result[0][0] = true;
        for (int i=0; i<len1; i++) {
            if (s1[i] == s3[i]) {
                result[i+1][0] = true;
            } else {
                break;
            }
        }

        for (int i=0; i<len2; i++) {
            if (s2[i] == s3[i]) {
                result[0][i+1] = true;
            } else {
                break;
            }
        }

        for (int i=1; i<=len1; i++) {
            for (int j=1; j<=len2; j++) {
                result[i][j] = (s1[i-1] == s3[i+j-1] && result[i-1][j]) 
                            || (s2[j-1] == s3[i+j-1] && result[i][j-1]);
            }
        }

        return result[len1][len2];
    }
};

/**
         * Time Limit Exceeded
         **/
        // stack<int * > s;
        // int i=0, j=0, k=0;
        // for (; k<len3; k++) {
        //     // cout << i << " " << j << " " << k << endl;
        //  if (i<len1 && j<len2 && s3[k] == s1[i] && s3[k] == s2[j]) {
        //         int *my_ints = new int(2);
        //         my_ints[0] = i, my_ints[1] = j;
        //         s.push(my_ints);
        //         // cout << my_ints << my_ints[0] << " " << my_ints[1] << " " << my_ints[2] << endl;
        //         i++;
        //     } else if (i<len1 && s3[k] == s1[i]) {
        //         i++;
        //     } else if (j<len2 && s3[k] == s2[j]) {
        //         j++;
        //     } else {
        //         if (!s.empty()) {
        //             int *v = s.top();
        //             s.pop();
        //             i = v[0], j = v[1], k = i+j;
        //             delete[] v;
        //             // cout << "stack:" << i << " " << j << " " << k << endl;
        //             j++;
        //         } else {
        //             return false;
        //         }
        //     }
        // }
        // return true;

int main (int argc, char *argv[]) {
    Solution sol;
    string s1("a"), s2(""), s3("a");
    cout << sol.isInterleave(s1, s2, s3) << endl;
}