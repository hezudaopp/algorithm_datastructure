#include <iostream>

using namespace std;

class Solution {
private:
	int findKthMaxNumberOfArrays(int A[], int m, int B[], int n, int k) {
		if (m==0) {
			return B[k-1];
		}
		if (n==0) {
			return A[k-1];
		}
		int i = m>>1, j = n>>1;
		int *p, *q;
		if (B[j] >= A[i]) {
			p = A;
			q = B;
		} else {
			p = B;
			q = A;
			i = i ^ j;
			j = i ^ j;
			i = i ^ j;
			m = m ^ n;
			n = m ^ n;
			m = m ^ n;
		}
		int mid = i + j + 1;
		if (k <= mid) {
			return findKthMaxNumberOfArrays(p, m, q, j, k);
		} else{
			return findKthMaxNumberOfArrays(p+i+1, m-i-1, q, n, k-i-1);
		}
	}

public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
    	int mid = ((m + n)>>1)+1;
    	double result = findKthMaxNumberOfArrays(A, m, B, n, mid)*1.0;
    	if ((m+n)%2==0) {
    		result = (findKthMaxNumberOfArrays(A, m, B, n, mid)+findKthMaxNumberOfArrays(A, m, B, n, mid-1))/2.0;
    	}
    	return result;
	}
};

int main (char *argv[], int argc) {
	Solution sol;
	int A[] = {1,2,3,4,5,6,7,8,10};
	int B[] = {9};
	cout << sol.findMedianSortedArrays(A, sizeof(A)/sizeof(int), B, sizeof(B)/sizeof(int)) << endl;
	return 0;
}