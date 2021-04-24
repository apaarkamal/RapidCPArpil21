#include<bits/stdc++.h>
#define int long long int
using namespace std;

struct node {
	node* nxt[26];
	int cnt = 0;
};

node* head;
int n, k;

void add(string s) {
	node* cur = head;
	for (int i = 0; i < s.size(); i++) {
		if (cur->nxt[s[i] - 'A'] == NULL) cur->nxt[s[i] - 'A'] = new node();
		cur = cur->nxt[s[i] - 'A'];
	}
	cur->cnt++;
}

int ans = 0;

void dfs(node* cur, int depth) {
	if (cur == NULL) return;
	for (int i = 0; i < 26; i++) {
		dfs(cur->nxt[i], depth + 1);
		if (cur->nxt[i] != NULL) cur->cnt += cur->nxt[i]->cnt;
	}
	ans += (cur->cnt / k) * depth;
	cur->cnt %= k;
	return;
}

void solve() {
	head = new node();
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		add(s);
	}
	ans = 0;
	dfs(head, 0);
	cout << ans;
}

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t = 1;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		solve();
		cout << '\n';
	}

	return 0;
}