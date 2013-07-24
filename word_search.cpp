#include <vector>
#include <stack>

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<int *> s;

        for (unsigned i=0; i<board.size(); i++) {
        	for (unsigned j=0; j<board[i].size(); j++) {
        		if (board[i][j] == word[0]) {
        			int x[2] = {i, j};
        			s.push(x);
        			board[i][j] = '';
        			if (sub_exist(board, word.sub_str(1), s)) return true;
        			continue;
        		}
        	}
        }
    }

    bool sub_exist(vector<vector<char> > &board, string word, stack<int *> &s) {
    	int x[] = s.top();
    	//回归的时候需要重新设置board
    	s.pop();
    	int row = x[0], col = x[1];
    	if (word.empty()) return true;

    }
};