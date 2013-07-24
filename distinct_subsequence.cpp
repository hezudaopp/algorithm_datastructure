#include <string>
#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int s = S.size();
        int t = T.size();
        if (s < t || s == 0 || t == 0) return 0;
        // r = new int*[s];
        int value[s][t];  
        memset(value,0,sizeof(int)*s*t); 
        // for (int i=0; i<s; i++) {
        // 	r[i] = new int[t];
        // 	for (int j=0; j<t; j++) {
        // 		r[i][j] = 0;
        // 	}
        // }
        // sumDistinct(S, s-1, T, t-1);
        // print_r(s, t);
        value[0][0] = (S[0] == T[0]) ? 1 : 0;
        for (int i=1; i<s; i++) {
        	value[i][0] = (S[i] == T[0]) ? value[i-1][0] + 1 : value[i-1][0];
        }
        for (int i=1; i<s; i++) {
        	for (int j=1; j<t; j++) {
        		value[i][j] = (S[i] == T[j]) ? value[i-1][j] + value[i-1][j-1] : value[i-1][j];
        	}
        }
        return value[s-1][t-1];
    }
// private:
// 	int **r;
// 	int sumDistinct(string S, int s_end, string T, int t_end) {
// 		if (r[s_end][t_end] > 0) return r[s_end][t_end];
// 		if (s_end >= t_end) {
// 			if (s_end == t_end) {
// 				if (S.compare(0, s_end+1, T, 0, t_end+1) == 0) {
// 					r[s_end][t_end] = 1;
// 					return r[s_end][t_end];
// 				}
// 			} else if (s_end > t_end) {
// 				r[s_end][t_end] = sumDistinct(S, s_end-1, T, t_end);
// 				if (S[s_end] == T[t_end]) {
// 					if (t_end == 0) {
// 						r[s_end][t_end] += 1;
// 					}
// 					else r[s_end][t_end] += sumDistinct(S, s_end-1, T, t_end-1);
// 				}
// 			}
// 			return r[s_end][t_end];
// 		} else {
// 			return 0;
// 		}
// 	}
// 	void print_r(int row, int col) {
// 		for (int i=0; i<row; i++) {
// 			for (int j=0; j<col; j++) {
// 				cout << r[i][j] << " ";
// 			}
// 			cout << endl;
// 		}
// 	}
};

int main(int argc, char *argv[]) {
	Solution sol;
	string S("aaa");
	string T("aaa");
	cout << sol.numDistinct(S, T) << endl;
	return 0;
}