#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define loop(i, n) for(int i = 0; i <n;++i)
#define INF 987654321
#define MAX 20000 + 1
using namespace std;

typedef pair<int, int> p;
int v, e, k;
vector<p> adj[MAX];

vector<int> dijkstra(int src) {
	priority_queue<p> pq;
	pq.push({ 0, src });

	vector<int> dist(v + 1, INF);
	dist[src] = 0;

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (cost > dist[here]) continue;
		for (auto& n : adj[here]) {
			int there = n.first;
			int nextDist = cost + n.second;
			if (dist[there] > nextDist) {
				dist[there] = nextDist;
				pq.push({ -nextDist, there });
			}
		}
	}
	return dist;
}