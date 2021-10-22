#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, k;
		cin >> n >> k;
		vector<pair<long long, long long>> b(30);
		for (int i = 0; i < 30; i++) {
			b[i].first = 0;
			b[i].second = i;
		}
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			for (int j = 0; j < 30; j++) {
				if (x & (1 << j)) {
					b[j].first += (long long) (1 << j);
				}
			}
		}
		sort(b.begin(), b.end(), [](const pair<long long, long long>& x, const pair<long long, long long>& y) -> bool {
			if (x.first == y.first) {
				if (x.second < y.second) {
					return true;
				} else {
					return false;
				}
			} else if (x.first > y.first) {
				return true;
			} else {
				return false;
			}
		});
		long long ans = 0;
		for (int i = 0; i < k; i++) {
			ans += (long long) (1 << b[i].second);
		}
		cout << ans << '\n';
	}
	return 0;
}
