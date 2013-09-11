#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getUncoverValue (std::vector<int> faceValues) {
	sort(faceValues.begin(), faceValues.end());
	int size = faceValues.size();
	int sum = faceValues[0];
	for (int i=1; i<size; i++) {
		sum += faceValues[i];
		if ((i+1) < size && faceValues[i+1] > (sum+1) )
			return sum+1;
	}
	return sum+1;
}

int main (char *argv[], int argc) {
	int nums[] = {1,2,4,7,100};
	vector<int> faceValues;
	for (int i=0; i<sizeof(nums)/sizeof(int); i++) {
		faceValues.push_back(nums[i]);
	}
	cout << getUncoverValue(faceValues) << endl;
	return 0;
}