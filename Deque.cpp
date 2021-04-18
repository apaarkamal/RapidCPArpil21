#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	deque<int> Q;

	for (int i = 0; i < k; i++) {
		while (!Q.empty() && a[Q.back()] <= a[i]) {
			Q.pop_back();
		}
		Q.push_back(i);
	}
	cout << a[Q.front()] << '\n';

	for (int i = k; i < n; i++) {
		if (Q.front() == i - k) Q.pop_front();
		while (!Q.empty() && a[Q.back()] <= a[i]) {
			Q.pop_back();
		}
		Q.push_back(i);
		cout << a[Q.front()] << '\n';
	}

	return 0;
}