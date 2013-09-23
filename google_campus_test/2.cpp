#include <iostream>
#include <fstream>
#include <map>
#include <stack>

using namespace std;

#define FILENAME "B-large-practice.in"
#define OUTFILE "B-large-practice.out"

map<long long, long long> ps;
map<long long, long long> qs;

void getPQOfIndex(long long index, long long &p, long long &q) {
	long long parent = index;
	stack<long long> parents;
	while (ps.count(parent) == 0) {
		parents.push(parent);
		parent = parent>>1;
	}
	while (!parents.empty()) {
		long long path = parents.top();
		long long parent = path>>1;
		if ((path%2) == 0) {
			p = ps[parent];
			q = ps[parent] + qs[parent];
		} else {
			p = ps[parent] + qs[parent];
			q = qs[parent];
		}
		ps[path] = p;
		qs[path] = q;
		parents.pop();
	}
}

long long getIndexOfPQ(long long p, long long q) {
	if (p == q) return 1;
	if (p > q) return 2*getIndexOfPQ(p-q, q)+1;
	else return 2*getIndexOfPQ(p, q-p);
}

int main(char *argv[], int argc) {
	ps[1] = 1;
	qs[1] = 1;
	ifstream ifs(FILENAME);
	ofstream ofs(OUTFILE);
	int test;
	ifs >> test;
	for (int t=1; t <= test; t++) {
		long long problemNumber;
		ifs >> problemNumber;
		ofs << "Case #" << t << ": ";
		if (problemNumber == 1) {
			long long index;
			ifs >> index;
			cout << index << endl;
			long long p, q;
			getPQOfIndex(index, p, q);
			ofs << p << " " << q;
		} else if(problemNumber == 2) {
			long long p, q;
			ifs >> p >> q;
			ofs << getIndexOfPQ(p, q);
		}
		if (t!=test) ofs << endl;
	}
	return 0;
}