#include<iostream>
#include<map>
#include<vector>

using namespace std;

int main() {
	cin.tie(NULL); ios::sync_with_stdio(false); cout.tie(NULL);
	int n, m, num;
	map<int, int> card;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num;
		card[num]++;
	}
		
	cin >> m;

	vector<int> fnd(m);

	for (int i = 0; i < m; i++)
		cin >> fnd[i];

	for (int i = 0; i < m; i++)
		cout << card[fnd[i]] << " ";

}