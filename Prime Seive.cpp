#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n = 200;

	vector<bool> p(n + 1, true);
	p[0] = p[1] = false;

	for (int i = 2; i * i <= n; i++) {
		if (p[i] == false) continue;
		cout << i << '\n';
		for (int j = i * i; j <= n; j += i) {
			p[j] = false;
		}
	}

	return 0;
}