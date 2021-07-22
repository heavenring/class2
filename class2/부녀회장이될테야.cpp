#include<iostream>
#include<vector>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int k, n, t, mem;

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> k >> n;

		vector<vector<int>> floor(k + 1,vector<int>(n));

		for (int j = 0; j < n; j++) 
			floor[0][j] = j + 1;

		for (int j = 1; j <= k; j++) {
			mem = floor[j][0] = 1;
			for (int l = 1; l < n; l++) {
				mem += floor[j - 1][l];
				floor[j][l] = mem;
			}
		}
		cout << floor[k][n - 1] << "\n";
	}
}