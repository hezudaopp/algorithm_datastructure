#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
	void reverse(vector<int> &num, int start, int end) {
		while (start < end) {
			num[start] = num[start] ^ num[end];
			num[end] = num[start] ^ num[end];
			num[start] = num[start] ^ num[end];
			start++;
			end--;
		}
		return;
	}

public:
    void nextPermutation(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int end = num.size()-1, i = end, ii=0;
        while (i>=0) {
        	ii = i;
        	--i;

        	if (i>=0 && num[i] < num[ii]) {
        		int j=end;
        		while (num[j] <= num[i]) {
        			--j;
        		}
        		num[i] = num[i] ^ num[j];
        		num[j] = num[i] ^ num[j];
        		num[i] = num[i] ^ num[j];
        		break;
        	}
        }
        reverse(num, ii, end);
        return;
    }
};

int main (char *argv[], int argc) {
	int arr[]={3,2,1};
	vector<int> v(arr, arr+sizeof(arr)/sizeof(int));
	Solution sol;
	sol.nextPermutation(v);
	for (int i=0; i<v.size(); i++) {
		cout << v[i] << " ";
	}
	return 0;
}