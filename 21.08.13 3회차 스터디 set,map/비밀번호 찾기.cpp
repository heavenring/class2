#include<iostream>
#include<map>
#include<string>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, m;
	string a;
	map<string, string> site;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a;
		cin >> site[a];
	}

	for (int i = 0; i < m; i++) {
		cin >> a;
		cout << site[a] << "\n";
	}
}