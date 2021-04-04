#include<bits/stdc++.h>
using namespace std;

vector<int> primes;
const int N = 1e5;

void seive() {
	vector<bool> p(N, true);
	p[0] = p[1] = false;
	for (int i = 2; i * i < N; i++) {
		if (p[i] == false) continue;
		primes.push_back(i);
		for (int j = i * i; j < N; j += i) {
			p[j] = false;
		}
	}
}

void solve() {
	int l, r;
	cin >> l >> r;
	int range = r - l + 1;
	vector<bool> p(range, true);

	for (auto prime : primes) {
		if (prime * prime > r) break;
		// cancel multiples of prime
		int start;

		if (prime >= l) start = prime * 2;
		else start = (l / prime) * prime;

		if (start < l) start += prime;

		for (int i = start; i <= r; i += prime) {
			p[i - l] = false;
		}

	}

	for (int i = l; i <= r; i++) {
		if (p[i - l] && i != 1) cout << i << '\n';
	}
	cout << '\n';
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	seive();

	int t;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}