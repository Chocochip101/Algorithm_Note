#include <bits/stdc++.h>
#define endl "\n"
#define MAX  32001
using namespace std;
typedef pair<int, int> p;

int n, m;
int indegree[MAX] = {0, };
vector<int> graph[MAX];
vector<int> TopologySort() {
	queue<int> q;
	vector<int> res;
	for (int i = 1; i <= n; ++i) 
		if (!indegree[i])
			q.push(i);
	
	while (!q.empty()) {
		int now = q.front(); q.pop();
		res.push_back(now);

		for (int next : graph[now]) {
			if (!(--indegree[next]))
				q.push(next);
		}
	}

	return res;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b;
		graph[a].push_back(b);
		indegree[b]++;
	}
	vector<int> ans = TopologySort();
	if(!ans.empty())
	for (int a : ans)
		cout << a << " ";
	return 0;
}