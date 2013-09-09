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

    int maxSubArrayWithDivideAndConquer (int A[], int left, int right) {
    	if (left > right) return 0;
    	if (left == right) return A[left];
    	int mid = left + ((right-left) >> 1);
    	// calculate left side max sum
    	int leftSum = 0, leftBorderSum = A[mid];
    	for (int i=mid; i>=left; i--) {
    		leftSum += A[i];
    		leftBorderSum = max(leftBorderSum, leftSum);
    	}
    	int rightSum = 0, rightBorderSum = A[mid];
    	for (int i=mid+1; i<=right; i++) {
    		rightSum += A[i];
    		rightBorderSum = max(rightSum, rightBorderSum);
    	}
    	int leftMaxSum = maxSubArrayWithDivideAndConquer(A, left, mid);
    	int rightMaxSum = maxSubArrayWithDivideAndConquer(A, mid+1, right);
    	return max(max(leftMaxSum, rightMaxSum), leftBorderSum+rightBorderSum);
    }
};

int main (char *argv[], int argc) {
	const int size = 10;
	int arr[size] = {-1,-2,-3,5,7,-4,8,2,-7,10};
	Solution sol;
	cout << sol.maxSubArray(arr, size) << endl;
	cout << sol.maxSubArrayWithDivideAndConquer(arr, 0, size-1) << endl;
	return 0;
}