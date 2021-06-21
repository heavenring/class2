#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

int main() {
	int n;

	cin >> n;

	vector<pair<int, int>> dot(n);
	for (int i = 0; i < n; i++)
		cin >> dot[i].first >> dot[i].second;

	sort(dot.begin(),dot.end());

	for (int i = 0; i < n; i++)
		cout << dot[i].first << " " << dot[i].second << "\n";
}