#include <iostream>

using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int maxSum = A[0];
        int tmpSum = maxSum;
        for (int i=1; i<n; i++) {
        	tmpSum += A[i];
        	if (A[i] > tmpSum) {
        		if (A[i] > maxSum) maxSum = A[i];
        		tmpSum = A[i];
        	} else {
        		if (tmpSum > maxSum) {
        			maxSum = tmpSum;
        		}
        	}
        }
    	return maxSum;
    }
};

int main (char *argv[], int argc) {
	const int size = 2;
	int arr[size] = {-1,-2};
	Solution sol;
	cout << sol.maxSubArray(arr, size) << endl;
	return 0;
}