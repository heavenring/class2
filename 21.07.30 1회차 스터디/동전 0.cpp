#include<iostream>
#include<vector>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, k, money;

	cin >> n >> k;

	vector<int> kind(n);

	for (int i = 0; i < n; i++)
		cin >> kind[i];

	money = 0;
	for (int i = n - 1; i >= 0; i--) {
		money += k / kind[i];
		k -= (k / kind[i]) * kind[i];
		if (k == 0)
			break;
	}

	cout << money;

}