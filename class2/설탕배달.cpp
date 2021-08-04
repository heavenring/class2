#include<iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	int answer;

	cin >> n;

	answer = 2000;
	for (int i = 0; i <= n / 3; i++) {
		for (int j = 0; j <= n / 3; j++) {
			if (n == 5 * i + 3 * j && answer > i + j) {
				answer = i + j;
			}
		}
	}
	if (answer == 2000)
		cout << -1;
	else
		cout << answer;
}