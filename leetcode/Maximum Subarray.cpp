#include <iostream>

using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n==0) return 0;
        int maxSum = A[0];
        int continueSum = maxSum;
        for (int i=1; i<n; i++) {
        	if (A[i] > (A[i]+continueSum)) {
        		continueSum = A[i];
        	} else {
        		continueSum += A[i];
        	}
        	if (continueSum > maxSum) {
        		maxSum = continueSum;
        	}
        }
        return maxSum;
    }
};

int main (char *argv[], int argc) {
	Solution sol;
	int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	cout << sol.maxSubArray(arr, sizeof(arr)/sizeof(int)) << endl;
	return 0;
}