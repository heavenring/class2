#include<iostream>
#include<set>
#include<string>

using namespace std;

int main() {
	cin.tie(NULL);
	cin.tie(NULL);
	ios::sync_with_stdio;

	int n, m;
	string a;
	set<string> name;
	set<string> answer;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a;
		name.insert(a);
	}

	for (int i = 0; i < m; i++) {
		cin >> a;
		if (name.find(a) != name.end())
			answer.insert(a);
	}

	cout << answer.size() << "\n";
	for (auto iter = answer.begin(); iter != answer.end(); iter++)
		cout << *iter << "\n";
}