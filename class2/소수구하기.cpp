#include<iostream>
#include<vector>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int m, n, count = 0;
	
	cin >> m >> n;

	vector<bool> all(n + 1, true);// true 소수 false 비 소수

	all[0] = all[1] = false;

	for (int i = 4; i <= n; i += 2)
		all[i] = false;

	for (int i = 3; i * i <= n; i += 2) // 에라토스테네스의 체 증명식 
		if (all[i])
			for (int j = i + i; j <= n; j += i) 
				all[j] = false;

	for (int i = m; i <= n; i++) 
		if (all[i]) 
			cout << i << "\n";
}