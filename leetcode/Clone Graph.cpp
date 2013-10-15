#include <vector>
#include <map>
#include <queue>
#include <iostream>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        UndirectedGraphNode *startNode = NULL;
        queue<UndirectedGraphNode *> q;
        map<int, UndirectedGraphNode *> createdNodesMap;
        if (node) {
        	startNode = new UndirectedGraphNode(node->label);
        	createdNodesMap[node->label] = startNode;
        	q.push(node);
        }
        while (!q.empty()) {
        	UndirectedGraphNode *curNode = q.front();
        	q.pop();
        	for (int i=0; i<curNode->neighbors.size(); i++) {
        		UndirectedGraphNode *newNode = NULL;
        		if (createdNodesMap.count(curNode->neighbors[i]->label) == 0) {
        			createdNodesMap[curNode->neighbors[i]->label] = new UndirectedGraphNode(curNode->neighbors[i]->label);
        			q.push(curNode->neighbors[i]);
        		} else {
        			newNode = createdNodesMap[curNode->neighbors[i]->label];
        		}
        		createdNodesMap[curNode->label]->neighbors.push_back(newNode);
        	}
        }
        return startNode;
    }
};

int main (char *argv[], int argc) {
	UndirectedGraphNode *node = new UndirectedGraphNode(-1);
	UndirectedGraphNode *node1 = new UndirectedGraphNode(1);
	node->neighbors.push_back(node1);
	Solution sol;
	UndirectedGraphNode *newNode = sol.cloneGraph(node);
	cout << newNode->neighbors.size() << endl;
	return 0;
}