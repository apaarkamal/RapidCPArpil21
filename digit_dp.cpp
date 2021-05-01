#include<bits/stdc++.h>
using namespace std;

string s;
int ans = 0;

int memo[9][2][81];

int fun(int i, bool last, int sum) {

	if (i == s.size()) {
		return sum;
	}

	int till = last ? (s[i] - '0') : 9;

	int ans = 0;
	for (int digits = 0; digits <= till; digits++) {
		ans += fun(i + 1, last && (digits == till), sum + digits);
	}

	return ans;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> s;
	cout << fun(0, 1, 0);



	return 0;
}