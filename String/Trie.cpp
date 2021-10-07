#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define loop(i, n) for(int i = 0; i <n;++i)
#define INF 987654321
#define MAX 26
using namespace std;
typedef pair<int, int> p;

int ans;
struct TrieNode {
	TrieNode* children[MAX];
	bool terminal, isRoot;
	int cnt;

	TrieNode(bool par) :terminal(false) {
		isRoot = par;
		//�ڽ� �� ���
		cnt = 0;
		memset(children, 0, sizeof(children));
	}

	~TrieNode() {
		for (int i = 0; i < MAX; ++i)
			if (children[i])
				delete children[i];
	}

	int toNum(char ch) {
		return ch - 'a';
	}

	void insert(const char* key) {
		if (*key == '\0')
			terminal = true;
		else {
			int next = toNum(*key);
			if (!children[next]) {
				children[next] = new TrieNode(false);
				cnt++;
			}
			return children[next]->insert(key + 1);
		}
	}

	void find(const char* key) {
		if (*key == '\0') return;
		int next = toNum(*key);
		//ù ���ڴ� ������ �Է�
		if (isRoot)ans++;
		else {
			//������ ������ ��� �Է�
			if (cnt > 1) ans++;
			// ���ڿ� ���� ��� �Է�
			else if (terminal)ans++;
		}
		children[next]->find(key + 1);
	}
};