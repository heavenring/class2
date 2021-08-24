#include<iostream>
#include<string>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m, count;
	int location;
	cin >> n >> m;

	string find;
	string target;
	cin >> target;

	find += "I";

	for (int i = 0; i < n; i++) {
		find += "OI";
	}
	count = 0;
	for (int i = target.find(find); i < m - (1 + 2 * n); i++) {
		if (target[i] == find[0]) {
			location = 0;
			for (int j = 0; j < n; j++) {
				if (target[i + 1 + 2 * j] == find[1] && target[i + 2 + 2 * j] == find[0]) {
					location++;
					if (location == n) {
						count++;
						while (i < m - (1 + 2 * n) && target[i + 1 + 2 * n] == find[1] && target[i + 2 + 2 * n] == find[0]) {
							count++;
							i += 2;
							if (i >= m - (1 + 2 * n))
								break;
						}
					}
				}
				else
					break;
			}
			i += location;
		}
	}
	cout << count;
}