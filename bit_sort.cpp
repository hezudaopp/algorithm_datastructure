#include <iostream>
#include <cstdlib>

using namespace std;

#define BITSPERWORD 32
#define SHIFT 5
#define MASK 0x1F
#define N 10000000
int a[1+N/BITSPERWORD];
int from[N];
int to[N];
int top = 0;

// #define set(i) a[i>>SHIFT] |= (1<<(i&MASK))
// #define clr(i) a[i>>SHIFT] &= ~(1<<(i&MASK))
// #define get(i) a[i>>SHIFT] & (1<<(i&MASK))

bool get(int i) {
	if (from[i] < top && to[from[i]] == i) {
		return true;
	} else {
		return false;
	}
}

void set(int i) {
	if (!get(i)) {
		from[i] = top;
		to[from[i]] = i;
		top++;
		a[i>>SHIFT] |= (1<<(i&MASK));
	}
}

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

void bit_sort(int arr[], int len) {
	// for (int i=0; i<N; i++) {
	// 	clr(i);
	// }
	for (int i=0; i<len; i++) {
		if (arr[i] < N && arr[i] >= 0) { 
			set(arr[i]);
		}
	}
	// for (int i=0; i<N; i++) {
	// 	bool result = get(i);
	// 	if (result) 
	// 		cout << i << " ";
	// }
	qsort(to, top, sizeof(int), compare);
	for (int i=0; i<top; i++) {
		cout << to[i] << " ";
	}
}



int main (int argc, char *argv[]) {
	int arr[] = {241,6239,3435466,1233,1,4,0,3435,332,77543,2567323,1567702,92734};
	bit_sort(arr, sizeof(arr)/sizeof(int));
}