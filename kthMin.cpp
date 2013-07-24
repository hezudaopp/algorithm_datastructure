#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
	int getKthMin(std::vector<int> v, int k) {
		return getKth(v, 0, v.size()-1, k-1);
	}
private:
	int getKth(std::vector<int> v, int left, int right, int k) {
		int result = partition(v, left, right);
		if (result == k) {
			return v[result];
		} else if (result > k) {
			return getKth(v, left, result-1, k);
		} else {
			return getKth(v, result+1, right, k);
		}
	}

	int partition(std::vector<int> &v, int left, int right) {
		int x = v[right];
		int result = left;
		for (int i=left; i<right; i++) {
			if (v[i] <= x) {
				swap(v[i], v[result]);
				result ++;
			}
		}
		swap(v[result], v[right]);
		return result;
	}

	void swap(int &a, int &b) {
		if (a != b) {
			a = a+b;
			b = a-b;
			a = a-b;
		}
	}
};

int main(int argc, char *argv[]) {
	Solution sol;
	int int_arrays[] = {2,8,7,1,3,5,6,4};
	vector<int> v(int_arrays, int_arrays+sizeof(int_arrays)/sizeof(int));
	cout << sol.getKthMin(v, 1) << endl;
	cout << sol.getKthMin(v, 5) << endl;
	cout << sol.getKthMin(v, 6) << endl;
	cout << sol.getKthMin(v, 7) << endl;
	return 0;
}