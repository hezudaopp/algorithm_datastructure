#include <iostream>

using namespace std;

class Solution {
public:
    bool search(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        for (int i=0; i<n; i++) {
        	if (A[i] == target) return true;
        }
        return false;
    }
};

int main (char *argv[], int argc) {
	int arr[] = {1,3,1,1,1};
	Solution sol;
	cout << sol.search(arr, sizeof(arr)/sizeof(int), 3) << endl;
	return 0;
}