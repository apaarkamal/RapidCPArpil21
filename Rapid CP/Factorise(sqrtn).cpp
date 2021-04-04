#include<bits/stdc++.h>
#define int long long int
using namespace std;

vector<pair<int, int>> factoriseN(int n) {
	vector<pair<int, int>> res;
	int cnt = 0;
	while (n % 2 == 0) {
		cnt++;
		n /= 2;
	}
	if (cnt) res.push_back({2, cnt});
	for (int i = 3; i * i <= n; i += 2) {
		if (n % i == 0) {
			cnt = 0;
			while (n % i == 0) {
				n /= i;
				cnt++;
			}
			res.push_back({i, cnt});
		}
	}
	if (n > 1) res.push_back({n, 1});
	return res;
}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	vector<pair<int, int>> res = factoriseN(n);

	for (auto x : res) {
		cout << x.first << " " << x.second << '\n';
	}

	return 0;
}

