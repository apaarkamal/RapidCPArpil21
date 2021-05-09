#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;

vector<int> gr[N];
int vis[N], tme = 1, low[N];

vector<pair<int, int>> bridge;
set<int> art_point;

void dfs(int cur, int par) {
	vis[cur] = low[cur] = tme++;
	int child = 0;
	for (auto x : gr[cur]) {
		if (!vis[x]) {
			dfs(x, cur);
			child++;
			low[cur] = min(low[x], low[cur]);
			// bridge check
			if (low[x] > vis[cur]) {
				bridge.push_back({x, cur});
				bridge.push_back({cur, x});
			}
			// should not be an articulation point
			if (par && low[x] >= vis[cur]) {
				art_point.insert(cur);
			}
		}
		else if (x != par) {
			// backedge
			low[cur] = min(low[cur], vis[x]);
		}
	}
	// root check
	if (par == 0 && child > 1) art_point.insert(cur);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) dfs(i, 0);
	}

	return 0;
}