#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int check(vector<vector<int>> &tomato, queue<pair<int,int>> &location, int m, int n) {

	int x, y, count = 0;;
	y = location.front().first;
	x = location.front().second;

	if (x - 1 >= 0 && tomato[y][x - 1] == 0) { //익은 토마토의 왼쪽 확인
		tomato[y][x - 1] = 1;
		location.push(make_pair(y, x - 1));
		count++;
	}

	if (y - 1 >= 0 && tomato[y - 1][x] == 0) { // 익은 토마토의 위쪽 확인
		tomato[y - 1][x] = 1;
		location.push(make_pair(y - 1, x));
		count++;
	}	

	if (x + 1 < m && tomato[y][x + 1] == 0) { // 익은 토마토의 오른쪽 확인
		tomato[y][x + 1] = 1;
		location.push(make_pair(y, x + 1));
		count++;
	}	

	if (y + 1 < n && tomato[y + 1][x] == 0) { // 익은 토마토의 아래쪽 확인
		tomato[y + 1][x] = 1;
		location.push(make_pair(y + 1, x));
		count++;
	}


	return count;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int m, n, count = 0, count1 = 0, day = 0;

	cin >> m >> n;

	vector<vector<int>> tomato(n, vector<int>(m)); // 토마토 받을 칸
	queue<pair<int, int>> location; // 토마토의 좌표를 받을 큐

	for (int i = 0; i < n; i++) // 토마토의 상태 입력
		for (int j = 0; j < m; j++) {
			cin >> tomato[i][j];
		}

	for (int i = 0; i < n; i++) // 익은 토마토의 좌표 큐에 입력
		for (int j = 0; j < m; j++)
			if (tomato[i][j] == 1) {
				location.push(make_pair(i, j));
				count++; // 하루동안 익은 토마토의 개수
			}

		while (!location.empty()) { // 더이상 익을 토마토가 없을때 까지 반복
			if (count == 0) { 
				day++; // 하루가 지났다
				count = count1; // 다음날 익을 토마토 개수 전달
				count1 = 0;
			}

			count1 += check(tomato, location, m, n); 
			location.pop();
			count--; // 하루동안 익은 토마토만큼 -1

		}

		for (int i = 0; i < n; i++) // 안익은 토마토가 있는지 확인
			for (int j = 0; j < m; j++)
				if (tomato[i][j] == 0) { // 있다면 즉시 프로그램 종료
					cout << -1;
					return 0;
				}

		cout << day;

}