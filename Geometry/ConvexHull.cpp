#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 200000
#define MOD 1000000000
using namespace std;

const double PI = 2 * acos(0.0);

struct vector2 {
	ll x, y;
};

vector<vector2> coord;

ll ccw(vector2 a, vector2 b, vector2 c) {
	return (a.x * b.y + b.x * c.y + c.x * a.y) - (b.x * a.y + c.x * b.y + a.x * c.y);
}

//y가 작은순으로 정렬후 같을 경우 x가 작은 순으로 정렬
bool cmp(vector2 a, vector2 b) {
	if (a.y != b.y) return a.y < b.y;
	else return a.x < b.x;
}

//반시계 정렬
bool cmp2(vector2 a, vector2 b) {
	ll Ccw = ccw(coord[0], a, b);
	if (Ccw != 0) return Ccw > 0;
	else return (a.x + a.y) < (b.x + b.y);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	stack<vector2> stk;
	int n; cin >> n;

	for (int i = 0; i < n; ++i) {
		int a, b; cin >> a >> b;
		coord.push_back({ a, b });
	}

	sort(coord.begin(), coord.begin() + n, cmp);
	sort(coord.begin() + 1, coord.begin() + n, cmp2);

	stk.push(coord[0]);
	stk.push(coord[1]);

	vector2 first, second;

	for (int i = 2; i < n; ++i) {
		while (stk.size() >= 2) {
			second = stk.top();
			stk.pop();
			first = stk.top();
			if (ccw(first, second, coord[i]) > 0) {
				stk.push(second);
				break;
			}
		}
		stk.push(coord[i]);
	}
	cout << stk.size() << endl;
	return 0;
}