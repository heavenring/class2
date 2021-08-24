#include<iostream>
#include<map>
#include<vector>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int t, w;
	string a, b;
	map<string, int> kind;

	cin >> t;
	
	for (int i = 0; i < t; i++) {
		int answer = 1, count = 0;
		cin >> w;
		vector<string> save(w);
		for (int j = 0; j < w; j++) {
			cin >> a >> b;
			if (kind.find(b) == kind.end()) {
				kind[b] = 2;
				save[count] = b;
				count++;
			}
			else
				kind[b]++;
		}
		for (int j = 0; j < count; j++) {
			answer *= kind[save[j]];
		}
		cout << answer - 1<< "\n";
		kind.clear();
	}
}