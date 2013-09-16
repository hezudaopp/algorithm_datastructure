#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <map>
#include <queue>

using namespace std;

#define FILENAME "A-small-practice-2.in"
#define OUTFILE "A-small-practice-2.out"
#define MAXSIZE 200

struct node {
	int color;
	vector<int> neighbours;
};

typedef struct node NODE;

bool isSplittable(int start, NODE *graph) {
	queue<int> nodesQueue;
	nodesQueue.push(start);
	graph[start].color = 0;
	while (!nodesQueue.empty()) {
		int curnode = nodesQueue.front();
		vector<int> curNeighbours = graph[curnode].neighbours;
		for (int i=0; i<curNeighbours.size(); i++) {
			int neighbourid = curNeighbours[i];
			if (graph[neighbourid].color == -1) {
				graph[neighbourid].color = 1 - graph[curnode].color;
				nodesQueue.push(neighbourid);
			} else if (graph[neighbourid].color == graph[curnode].color) {
				return false;
			}
		}
		nodesQueue.pop();
	}
	return true;
}

int main(char *argv[], int argc) {
	ifstream ifs(FILENAME);
	ofstream ofs(OUTFILE);
	int test;
	ifs >> test;
	for (int t=1; t <= test; t++) {
		int pairs;
		ifs >> pairs;
		string left, right;
		int id = 0;
		map<string, int> mymap;
		NODE graph[MAXSIZE];
		for (int i=0; i<pairs; i++) {
			ifs >> left >> right;
			int id1, id2;
			if (mymap.count(left) == 0) {
				mymap[left] = id;
				id1 = id;
				id++;
			} else {
				id1 = mymap[left];
			}
			if (mymap.count(right) == 0 ) {
				mymap[right] = id;
				id2 = id;
				id++;
			} else {
				id2 = mymap[right];
			}
			graph[id1].neighbours.push_back(id2);
			graph[id2].neighbours.push_back(id1);
		}
		for (int i=0; i<MAXSIZE; i++) {
			graph[i].color = -1;
		}
		string result("Yes");
		for (int i=0; i<MAXSIZE; i++) {
			if (graph[i].color == -1 && !isSplittable(i, graph)) {
				result = "No";
			}
		}
		ofs << "Case #" << t << ": " << result << endl;
	}
	return 0;
}