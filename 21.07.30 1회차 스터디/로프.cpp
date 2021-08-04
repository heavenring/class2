#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, weight, num;

	cin >> n;

	vector<int> lope(n);

	for (int i = 0; i < n; i++)
		cin >> lope[i];

	sort(lope.begin(),lope.end());

	weight = 0;
	for (int i = 0; i < n; i++) {
		num = lope[i] * (n - i);
		if (weight < num)
			weight = num;
	}
	cout << weight;

}