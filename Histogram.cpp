#include<bits/stdc++.h>
using namespace std;

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
	stack<int> St;// indexes
	int left[n], right[n];

	for (int i = 0; i < n; i++) {
		while (!St.empty() && a[St.top()] > a[i]) {
			right[St.top()] = i;
			St.pop();
		}
		St.push(i);
	}

	while (!St.empty()) {
		right[St.top()] = n;
		St.pop();
	}

	for (int i = n - 1; i >= 0; i--) {
		while (!St.empty() && a[St.top()] > a[i]) {
			left[St.top()] = i;
			St.pop();
		}
		St.push(i);
	}

	while (!St.empty()) {
		left[St.top()] = -1;
		St.pop();
	}

	// for (int i = 0; i < n; i++) {
	// 	cout << left[i] << " " << right[i] << '\n';
	// }

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, a[i] * (right[i] - left[i] - 1));
	}

	cout << ans;

	return 0;
}