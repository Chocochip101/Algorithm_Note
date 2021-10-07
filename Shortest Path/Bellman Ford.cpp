//BelmanFord Algorithm

//��� ����� ���� ���� ���� V-1�� �ݺ��ؾ��Ѵ�.

//���� ���� ����Ŭ�� �����ϸ� V-1�� ���� V��° �ݺ�������
//���� ���ŵȴٸ� ���� ����Ŭ�� ���� ���ŵǱ� ������ V�� �ݺ��� ���� ���� ����Ŭ �˻�

//res[j] != INF���� �� INF�� �ƴ� �κи� ������Ʈ �ؾ��ϴ°�?
//������ ���� �� �� ���������� ���� �Ұ����� ������ ����
//dist[u] = INF, dist[v] = INF - const���� ���ü� �ִ�.

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

    //�� ��帶�� �˻�
    for (int i = 1; i <= N; ++i) {
        //��� ������ ���� �˻�
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