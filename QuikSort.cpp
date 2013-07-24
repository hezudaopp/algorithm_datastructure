#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	std::vector<int> sort(std::vector<int> v) {
		std::vector<int> result(v);
		quickSort(result, 0, result.size()-1);
		return result;
	}

private:
	void quickSort(std::vector<int> &v, int left, int right) {
		if (left < right) {
			int p = partition(v, left, right);
			quickSort(v, left, p-1);
			quickSort(v, p+1, right);
		}
	}

	int partition(std::vector<int> &v, int left, int right) {
		int pivot = v[right];
		int result = left;
		for (int i=left; i<right; i++) {
			if (v[i] <= pivot) {
				swap(v[result], v[i]);
				result++;
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
	std::vector<int> result = sol.sort(v);
	for(int i=0; i<result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << endl;
}