#include <set>
#include <map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<std::map<char, int>, std::set<int> > m;
        map<std::map<char, int>, std::set<int> >::iterator it;
        vector<string> result;
        int size = strs.size();
        int test = 0;
        // cout << ++test << endl;
        for (int i=0; i<size; i++) {
        	string s = strs[i];
        	int len = s.length();
        	map<char, int> word_map;
        	// cout << ++test << endl;
	        for (char c='a'; c<='z'; c++) {
	        	word_map[c] = 0;
	        }
	        // cout << ++test << endl;
	        for (int j=0; j<len; j++) {
	        	word_map[s.at(j)]++;
	        }
	        // cout << ++test << endl;
	        if (m.find(word_map) == m.end()) {
	        	std::set<int> s;
	        	s.insert(s.end(), i);
	        	m[word_map] = s;
	        	// cout << "i:" << i << endl;
	        } else {
	        	std::set<int> s = m[word_map];
	        	s.insert(s.end(), i);
	        	m[word_map] = s;
	        	// cout << "i_i:" << i << endl;
	        }
	        // cout << ++test << endl;
        }

        // cout << ++test << endl;
        for (it = m.begin(); it!=m.end(); it++) {
        	std::set<int> s = (*it).second;
        	int s_size = s.size();
        	for (std::set<int>::iterator ite=s.begin(); s_size>1 && ite!=s.end(); ite++) {
        		result.push_back(strs[*ite]);
        	}
        }
        return result;
    }
};

int main (int argc, char *argv[]) {
	string s[] = {"tea","and","ace","ad","eat","dans"};
	vector<string> strs(s, s+sizeof(s)/sizeof(string));
	Solution sol;
	vector<string> result = sol.anagrams(strs);
	for (std::vector<string>::iterator it=result.begin(); it!=result.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}