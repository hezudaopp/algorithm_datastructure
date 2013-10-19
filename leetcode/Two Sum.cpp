#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int *arr = new int[numbers.size()];
        for (int i=0; i<numbers.size(); i++) {
        	arr[i] = numbers[i];
        }
        sort(numbers.begin(), numbers.end());
        int i=0, j=numbers.size()-1;
        while (i<j) {
        	int sum = numbers[i]+numbers[j];
        	if (sum == target) break;
        	else if (sum > target) j--;
        	else i++;
        }
        vector<int> result;
        if (i<j) {
        	for (int k=0; k<numbers.size(); k++) {
        		if (arr[k] == numbers[i] || arr[k] == numbers[j]) {
        			result.push_back(k+1);
        		}
        		if (result.size()==2) break;
        	}
        }
        return result;
    }
};

int main (char *argv[], int argc) {
	return 0;	
}