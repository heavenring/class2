#include<iostream>
#include<vector>

using namespace std;

int m, n;

void change(vector<vector<int>> &tomato, int x, int y, int count) {

	if (x + 1 < m && tomato[y][x + 1] == 0) 
		tomato[y][x + 1] = count;

	if (y + 1 < n && tomato[y + 1][x] == 0) 
		tomato[y + 1][x] = count;

	if (x - 1 >= 0 && tomato[y][x - 1] == 0) 
		tomato[y][x - 1] = count;

	if (y - 1 >= 0 && tomato[y - 1][x] == 0) 
		tomato[y - 1][x] = count;


}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int count = 1, finish = 0;
	int x = 0, y = 0;
	cin >> m >> n;

	vector<vector<int>> tomato(n, vector<int>(m));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> tomato[i][j];

	while (true) {

		for(int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				if (tomato[i][j] == count) {
					change(tomato, j, i, count + 1);
					finish = 0;
				}
				else
					finish++;
			}

		/*for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				cout << tomato[i][j] << " ";
			cout << "\n";
		}

		cout << "\n";*/

		if (finish >= m * n) {
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					if (tomato[i][j] == 0) {
						cout << -1;
						return 0;
					}
			
			cout << count - 2;
			break;
		}
		count++;
	}
}