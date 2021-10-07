//BelmanFord Algorithm

//모든 경우의 수를 보기 위해 V-1번 반복해야한다.

//만약 음의 사이클이 존재하면 V-1번 이후 V번째 반복문에서
//답이 갱신된다면 음의 사이클에 의해 갱신되기 때문에 V번 반복을 통해 음의 사이클 검사

//res[j] != INF에서 왜 INF가 아닌 부분만 업데이트 해야하는가?
//구현에 따라서 둘 다 시작점에서 도달 불가능한 정점에 대해
//dist[u] = INF, dist[v] = INF - const꼴이 나올수 있다.

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define loop(i, n) for(int i = 0; i <n;++i)
#define INF 987654321
#define MAX_V 500 + 1
using namespace std;
typedef pair<ll, ll> p;
int N, M;
vector<p> graph[MAX_V];
ll res[MAX_V];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    int a, b, c;
    for (int i = 0; i < M; ++i) {
        cin >> a >> b >> c;
        graph[a].push_back({ b, c });
    }
    for (int i = 1; i <= N; ++i)
        res[i] = INF;

    res[1] = 0;

    bool cycle = false;

    //각 노드마다 검사
    for (int i = 1; i <= N; ++i) {
        //모든 간선에 대해 검사
        for (int j = 1; j <= N; ++j) {
            for (int k = 0; k < graph[j].size(); ++k) {
                ll nextV = graph[j][k].first;
                ll nextCost = graph[j][k].second;
                if ((res[j] != INF) && res[nextV] > res[j] + nextCost) {
                    res[nextV] = res[j] + nextCost;
                    if (i == N) { cycle = true; break; }
                }
            }
        }
    }
    if (cycle) cout << -1 << endl;
    else {
        for (int i = 2; i <= N; ++i) {
            if (res[i] == INF) cout << -1 << endl;
            else cout << res[i] << endl;
        }
    }
    return 0;
}