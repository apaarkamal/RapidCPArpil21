#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;

int n, k;
int a[N];

// O(n)
int k_required(int diff) {
	int ans = 0;
	for (int i = 1; i < n; i++) {
		ans += (a[i] - a[i - 1] - 1) / diff;
	}
	return ans;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		// for (int i = 1; i <= 10000; i++) {
		// 	cout << i << " " << k_required(i) << '\n';
		// }

		int lf = 1, rt = a[n - 1] - a[0];

		while (lf < rt) {
			int mid = (lf + rt) / 2;
			if (k_required(mid) <= k) {
				rt = mid;
			}
			else {
				lf = mid + 1;
			}
		}

		cout << lf << '\n';

	}

	return 0;
}