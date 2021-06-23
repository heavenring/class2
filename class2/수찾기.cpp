#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

int find(vector<int> &a, int b, int min, int max) {
	if (a[((max + min) / 2) + 1] == b)
		return 1;

	else if (a[(max + min) / 2] < b) {
		if ((max + min) / 2 == max - 1 && a[max] != b)
			return 0;
		return find(a, b, (max + min) / 2, max);
	}

	else if (a[(max + min) / 2] > b) {
		if ((max + min) / 2 == 0 && a[0] != b)
			return 0;
		return find(a, b, min, (max + min) / 2);
	}

	else
		return 1;
}

int main() {
	int n, m;

	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> m;
	vector<int> b(m);
	for (int i = 0; i < m; i++)
		cin >> b[i];

	sort(a.begin(), a.end());

	for (int i = 0; i < m; i++)
		cout << find(a, b[i], 0, n - 1) << "\n";
}