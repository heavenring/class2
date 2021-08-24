#include<iostream>
#include<map>
#include<string>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, m;
	map<string, int> name;
	map<string, string> num;
	string a, b;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> a;
		name[a] = i;
		num[to_string(i)] = a;
	}
	b = 'A';
	for (int i = 0; i < m; i++) {
		cin >> a;

		if (a >= b)
			cout << name[a] << "\n";
		else
			cout << num[a] << "\n";
	}

}