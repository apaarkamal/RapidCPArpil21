class Solution {
public:
	string s, t;
	int n, m;
	vector<vector<int>> memo;
	bool dp(int i, int j) {
		if (i == n && j == m) return true;
		if (j == m) return false;
		if (memo[i][j] != -1) return memo[i][j];
		bool ans = false;
		if (i < n && s[i] == t[j]) {
			ans |= dp(i + 1, j + 1);
		}
		else {
			if (i < n && t[j] == '?') {
				ans |= dp(i + 1, j + 1);
			}
			else if (t[j] == '*') {
				// no element is matched
				ans |= dp(i, j + 1);
				// matched one will match more
				if (i < n) ans |= dp(i + 1, j);
			}
		}
		return memo[i][j] = ans;
	}
	bool isMatch(string s, string p) {
		this->s = s;
		this->t = p;
		this->n = s.size();
		this->m = t.size();
		memo.resize(n + 1, vector<int>(m + 1, -1));
		return dp(0, 0);
	}
};