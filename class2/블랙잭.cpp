#include<iostream>
#include<vector>
using namespace std;

int main() {
	cin.tie(NULL); ios::sync_with_stdio(false); cout.tie(NULL);

	int n, m, i, num, answer = 0;
	int a, b, c;
	vector<int> card(100);

	cin >> n >> m;

	for (i = 0; i < n; i++)
		cin >> card[i];

	for(a = 0; a < n - 2; a++)
		for(b = (a + 1); b < n - 1; b++)
			for (c = (b + 1); c < n; c++) {
				num = m - (card[a] + card[b] + card[c]);
				if (num >= 0 && (m - answer) > num)
					answer = m - num;
			}
	cout << answer;
}