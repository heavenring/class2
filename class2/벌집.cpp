#include<iostream>
#include<vector>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio;
	cout.tie(NULL);

	int n, count = 1;

	cin >> n;

	vector<int> arr(19000);

	if (n < 8) {
		if (n == 1)
			cout << count;
		else
			cout << count + 1;
	}
	else {
		arr[0] = 7;
		for (int i = 1; arr[i - 1] <= n; i++) {
			arr[i] = arr[i - 1] + 6 * (i + 1);
		}

		for (int i = 0; i <= n; i++) {
			if (arr[i] >= n) {
				cout << i + 2;
				break;
			}
		}
	}
}