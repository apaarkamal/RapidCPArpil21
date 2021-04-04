#include<bits/stdc++.h>
#define int long long int
using namespace std;

const int sz = 2;
const int mod = 1e9 + 7;

struct Mat
{
	int m[sz][sz];
	Mat() {
		memset(m, 0, sizeof(m));
	}
	void identity() {
		for (int i = 0; i < sz; i++) m[i][i] = 1;
	}
	Mat operator* (Mat &a) {
		Mat res;
		for (int i = 0; i < sz; i++) {
			for (int j = 0; j < sz; j++) {
				for (int k = 0; k < sz; k++) {
					res.m[i][j] = (res.m[i][j] + m[i][k] * a.m[k][j]) % mod;
				}
			}
		}
		return res;
	}
	void print() {
		for (int i = 0; i < sz; i++) {
			for (int j = 0; j < sz; j++) {
				cout << m[i][j] << " ";
			} cout << '\n';
		}
	}
};

int giveNFib(int n) {

	Mat a, res;
	a.m[0][0] = a.m[0][1] = a.m[1][0] = 1;
	res.identity();

	while (n) {
		if (n & 1) res = res * a;
		a = a * a;
		n /= 2;
	}

	return res.m[0][0];
}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cout << giveNFib(4124124121441);

	return 0;
}