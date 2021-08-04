#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, answer;

	cin >> n;

	vector<int> time(n);

	for (int i = 0; i < n; i++)
		cin >> time[i];

	sort(time.begin(), time.end());
	answer = time[0];

	for (int i = 1; i < n; i++) {
		time[i] += time[i - 1];
		answer += time[i];
	}

	cout << answer;
}