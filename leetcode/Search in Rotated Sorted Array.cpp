#include <iostream>

using namespace std;

class Solution {
private:
	int searchTarget(int A[], int left, int right, int target) {
		while (left <= right) {
			int mid = (left+right)/2;
			
			if (A[mid] == target) return mid;
			if (A[left] <= A[right]) {
				if (A[mid] < target) {
					left = mid+1;
				} else {
					right = mid-1;
				}
			} else {
				if (A[mid] >= A[left]) {
					if (target < A[mid]) {
						if (target < A[left]) {
							left = mid + 1;
						} else if (target > A[left]){
							right = mid - 1;
						} else {
							return left;
						}
					} else {
						left = mid + 1;
					}
				} else if (A[mid] < A[left]) {
					if (target > A[mid]) {
						if (target > A[left]) {
							right = mid -1;
						} else if (target < A[left]) {
							left = mid + 1;
						} else {
							return left;
						}
					} else {
						right = mid - 1;
					}
				}
			}
		}
		return -1;
	}

public:
    int search(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        return searchTarget(A, 0, n-1, target);
    }
};

int main (char *argv[], int argc) {
	int arr[] = {5,1,3};
	Solution sol;
	cout << sol.search(arr, sizeof(arr)/sizeof(int), 3) << endl;
	return 0;
}