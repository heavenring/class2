#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	cin.tie(NULL); ios::sync_with_stdio(false); cout.tie(NULL);

	int n, count = 0;

	cin >> n;

	vector<int> decimal(n);

	for (int i = 0; i < n; i++)
		cin >> decimal[i];

	sort(decimal.begin(), decimal.end());

	if (decimal[0] == 1) 
		for (int i = 1; i < n; i++) {
			for (int j = 2; j <= decimal[i]; j++) {
				if (decimal[i] / j == 1) {
					count++;
					break;
				}
				else if (decimal[i] % j == 0)
					break;
			}
		}
	else 
		for (int i = 0; i < n; i++) {
			for (int j = 2; j <= decimal[i]; j++) {
				if (decimal[i] / j == 1) {
					count++;
					break;
				}
				else if (decimal[i] % j == 0)
					break;
			}
		}
	cout << count;

}