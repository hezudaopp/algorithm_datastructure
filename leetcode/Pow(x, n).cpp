#include <iostream>
#include <cfloat>

using namespace std;

class Solution {
private:
	double *arr;

	double powUnsigned (double x, unsigned n) {
		if (n==0) return 1.0;
		unsigned ex = 1;
		int count = 0;
		while (ex <= n && count < 30) {
			ex = ex << 1;
			count++;
		}
		ex = ex >> 1;
		return arr[count]*powUnsigned(x,n-ex);
	}

	bool isEqual (double m, double n) {
		if ((m - n) > -0.0000001 && (m - n) < 0.00000001) return true;
		else return false;
	}

public:
    double pow(double x, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (n == 0) return 1.0;
        bool inverse = (n < 0) ? true : false;
        unsigned e = n;
        if (n < 0) e = -n;
        int count = 1;
        unsigned ex = 1;
        int power = 1;
		while (ex <= e && count <= 31) {
			ex = ex << 1;
			count++;
		}
		arr = new double[count];
		arr[0] = 1.0;
		arr[1] = x;
		for (int i=2; i<count; i++) {
			arr[i] = arr[i-1]*arr[i-1];
			if (isEqual (arr[i], 0.0)) return 0.0;
		}
		double result = powUnsigned(x, e);
		if (inverse)
			result = 1/result;
		delete[] arr;
		return result;
    }
};

int main (char *argv[], int argc) {
	Solution sol;
	cout << sol.pow(1.00000, -2147483648) << endl;
	return 0;
}