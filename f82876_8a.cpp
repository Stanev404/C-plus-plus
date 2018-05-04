//IVAN STANEV F82876
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
	int from;
	int to;
	Edge(int from, int to) {
		this->from = from;
		this->to = to;
	}
};

void BreadthFirstSearch(vector< vector<int> > adjList, int start) {
	bool * visited = new bool[adjList.size()];
	for (int i = 0; i < adjList.size(); i++) {
		visited[i] = false;
	}

	visited[start] = true;

	queue <int> toVisit;
	toVisit.push(start);


	while (!toVisit.empty()) {
		int current = toVisit.front();
		toVisit.pop();

		cout << current << " ";

		vector<int> adj = adjList[current];

		for (int i = 0; i < adj.size(); i++) {
			int nodeToEnqueue = adj[i];
			if (!visited[nodeToEnqueue]) {

				toVisit.push(adj[i]);
				visited[nodeToEnqueue] = true;

			}
		}
	}
}

int main() {
	vector < vector<int> > adjList;
	int n;
	cin >> n;

	vector <Edge> edges;
	vector <int> num;

	for (int i = 0; i < n; i++)
	{
		int from, to;
		cin >> from >> to;
		bool flag = true;
		if (i == 0) {
			num.push_back(from);
			num.push_back(to);
		}
		else {
			for (int j = 0; j < num.size(); j++) {
				if (num[j] == from) {
					flag = false;
					break;
				}
			}
			if (flag) num.push_back(from);
			flag = true;
			for (int k = 0; k < num.size(); k++) {
				if (num[k] == to) {
					flag = false;
					break;
				}

			}
			if (flag) num.push_back(to);
		}

		edges.push_back(Edge(from, to));
	}

	int size = num.size();

	for (int i = 0; i < n; i++) {
		Edge current = edges[i];
		if (adjList.size() <= current.from)
			adjList.resize(current.from + 1);

		if (adjList.size() <= current.to)
			adjList.resize(current.to + 1);

		adjList[current.from].push_back(current.to);
		adjList[current.to].push_back(current.from);

	}

	BreadthFirstSearch(adjList, 1 + 82876 % size);

	/*for (int node = 0; node < adjList.size(); node++) {
	cout << node << "Is connected with: ";
	for (int i = 0; i < adjList[node].size(); i++) {
	cout << adjList[node][i] << " ";
	}
	cout << endl;
	}*/



	return 0;
}