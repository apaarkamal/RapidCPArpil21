#include<bits/stdc++.h>
using namespace std;

const int N = 3e2 + 1;

int n;
int a[N];
double memo[N][N][N];
double minus_one = -1;

double dp(int zero, int one, int two, int three) {
	if (zero == n) return 0;
	if (memo[zero][one][two] != minus_one) return memo[zero][one][two];
	double ans = n;
	if (one) ans += one * dp(zero + 1, one - 1, two, three);
	if (two) ans += two * dp(zero, one + 1, two - 1, three);
	if (three) ans += three * dp(zero, one, two + 1, three - 1);
	ans /= (double)(n - zero);
	return memo[zero][one][two] = ans;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> n;
	int cnt[4];
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			for (int k = 0; k <= n; k++) {
				memo[i][j][k] = minus_one;
			}
		}
	}
	cout << setprecision(10) << fixed;
	cout << dp(cnt[0], cnt[1], cnt[2], cnt[3]);

	return 0;
}