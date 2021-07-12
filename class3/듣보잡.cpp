#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio;
	cout.tie(NULL);

	int n, m;

	cin >> n >> m;

	vector<string> people(n);
	vector<string> name;
	string a;

	for (int i = 0; i < n; i++) {
		cin >> people[i];
	}

	sort(people.begin(),people.end());

	for (int i = 0; i < m; i++) {
		cin >> a;
		if (binary_search(people.begin(), people.end(), a)) {
			name.push_back(a);
		}
	}

	sort(name.begin(), name.end());

	cout << name.size() << "\n";
	for (int i = 0; i < name.size(); i++)
		cout << name[i] << "\n";
}