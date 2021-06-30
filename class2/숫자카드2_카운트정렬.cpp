#include<iostream>

using namespace std;

int cnt[20000001], fnd[500000];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	int num, n, m;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num;
		cnt[num + 10000000]++;
	}

	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> fnd[i];
		cout << cnt[fnd[i] + 10000000] << " ";
	}
}