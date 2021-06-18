#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool order(pair<int,string> a, pair<int,string> b) {
	return a.first < b.first;
}

int main() {
	cin.tie(NULL); ios::sync_with_stdio(false); cout.tie(NULL);

	int n;

	cin >> n;
	
	vector<pair<int, string>> people;
	vector<int> age(n);
	vector<string> name(n);

	for (int i = 0; i < n; i++) {
		cin >> age[i] >> name[i];
		people.push_back(pair<int, string>(age[i], name[i]));
	}

	stable_sort(people.begin(), people.end(),order);

	for (int i = 0; i < people.size(); i++)
		cout << people[i].first << " " << people[i].second << "\n";
}