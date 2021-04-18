#include<bits/stdc++.h>
using namespace std;

struct segment_tree {
	vector<int> st;
	int n;

	void build_helper(int a[], int start, int end, int node) {
		if (start == end) {
			st[node] = a[start];
			return ;
		}
		int mid = (start + end) / 2;
		// left build
		build_helper(a, start, mid, 2 * node + 1);
		// right build
		build_helper(a, mid + 1, end, 2 * node + 2);

		st[node] = min(st[2 * node + 1], st[2 * node + 2]);
	}

	int query_helper(int start, int end, int l, int r, int node) {
		// no overlap
		if (end < l || start > r) {
			return INT_MAX;
		}
		// complete overlap
		if (start >= l && end <= r) {
			return st[node];
		}
		// partial overlap
		int mid = (start + end) / 2;
		int q1 = query_helper(start, mid, l, r, 2 * node + 1);
		int q2 = query_helper(mid + 1, end, l, r, 2 * node + 2);
		return min(q1, q2);
	}

	void update_helper(int start, int end, int index, int val, int node) {
		if (start == end) {
			st[node] = val;
			return;
		}

		int mid = (start + end) / 2;
		if (index <= mid) {
			update_helper(start, mid, index, val, 2 * node + 1);
		}
		else {
			update_helper(mid + 1, end, index, val, 2 * node + 2);
		}

		st[node] = min(st[2 * node + 1], st[2 * node + 2]);
		return;
	}

	void build(int a[], int n) {
		st.resize(4 * n, INT_MAX);
		this->n = n;
		build_helper(a, 0, n - 1, 0);
	}

	int query(int l, int r) {
		return query_helper(0, n - 1, l, r, 0);
	}

	void update(int index, int val) {
		update_helper(0, n - 1, index, val, 0);
		return ;
	}

};

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	segment_tree tree;
	tree.build(a, n);

	// for (int i = 0; i < 4 * n; i++) {
	// 	cout << tree.st[i] << '\n';
	// }


	cout << tree.query(1, 6) << '\n';

	tree.update(2, 0);

	cout << tree.query(1, 6) << '\n';

	return 0;
}