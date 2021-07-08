#include<iostream>
#include<vector>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, k, count;
	int j = 0;
	cin >> n >> k;

	vector<int> people(n);
	vector<int> answer(n);

	for (int i = 0; i < n; i++)
		people[i] = i + 1;

	for (int i = 0; i < n; i++) {
		count = 0;
		while (true) {
			if(people[j % n] != 0)
				count++;
			if (count == k) {
				answer[i] = people[(j % n)];
				people[(j % n)] = 0;
				break;
			}
			j++;
		}
		j++;
	}
	cout << "<";
	for (int i = 0; i < n; i++) {
		cout << answer[i];
		if (i < n - 1)
			cout << ", ";
	}
	cout << ">";
}