#include<iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio;
	cout.tie(NULL);

	int n;
	int a, b;

	cin >> n;

	for (int i = 0; i <= n; i++) {
		if (i == n) {
			cout << 0;
			break;
		}
		else {
			b = i;
			a = i;
			while (b > 0) {
				a += b % 10;
				b /= 10;
			}
			if (a == n) {
				cout << i;
				break;
			}
			a = 0;
		}
	}
}