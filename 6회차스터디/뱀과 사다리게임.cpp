#include<iostream>
#include<vector>
#include<queue>

using namespace std;
/****************************************핵심 사다리와 뱀의 끝점은 방문을 확인할 필요가 없다****************************************/
/*************************사다리와 뱀의 시작점에서 방문을 확인했기 때문!! 끝점을 확인하면 오히려 다른 길에 방해가 된다******************/

void event_(vector<int> &sadari,vector<int> &bam, queue<pair<int,int>> &roll, int now, int order) {// 자주 실행되는 코드라 함수로 선언
		if (sadari[now] != 0) {
			roll.push(make_pair(sadari[now], order)); // 해당칸에 사다리가 있을경우
		}

		else if (bam[now] != 0) {
			roll.push(make_pair(bam[now], order)); // 해당 칸에 뱀이 있을경우
		}

		else {
			roll.push(make_pair(now, order)); // 해당칸에 아무것도 없을경우
		}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, m, now, order, start, end;
	vector<int> sadari(101, 0);
	vector<int> bam(101, 0);
	vector<int> visit(101, 0);
	queue<pair<int, int>> roll;

	roll.push(make_pair(1, 0));
	cin >> n >> m;

	for (int i = 0; i < n; i++) {// 사다리와 뱀의 위치를 받는 배열
		cin >> start >> end;
		sadari[start] = end;
	}
	for (int i = 0; i < m; i++) {
		cin >> start >> end;
		bam[start] = end;
	}

	event_(sadari, bam, roll, 1, 0); // 첫번째 칸에 사다리나 뱀이 있는지 확인을 위한 코드
	roll.pop();// 일반 칸이라면 같은 좌표가 한번더 들어오기에 pop()

	while (roll.front().first < 100) { // 100보다 크거나 같으면 도착하기 때문에 작을때 반복
		now = roll.front().first; // 현재의 위치
		order = roll.front().second; // 몇번째 주사위를 굴린것인지 확인

		if (now + 1 <= 100 && visit[now + 1] == 0) { // 1칸  ~ 6칸 움직일 경우
			visit[now + 1] = 1;
			event_(sadari, bam, roll, now + 1, order + 1);
		}
		if (now + 2 <= 100 && visit[now + 2] == 0) {
			visit[now + 2] = 1;
			event_(sadari, bam, roll, now + 2, order + 1);
		}
		if (now + 3 <= 100 && visit[now + 3] == 0) {
			visit[now + 3] = 1;
			event_(sadari, bam, roll, now + 3, order + 1);
		}
		if (now + 4 <= 100 && visit[now + 4] == 0) {
			visit[now + 4] = 1;
			event_(sadari, bam, roll, now + 4, order + 1);
		}
		if (now + 5 <= 100 && visit[now + 5] == 0) {
			visit[now + 5] = 1;
			event_(sadari, bam, roll, now + 5, order + 1);
		}
		if (now + 6 <= 100 && visit[now + 6] == 0) {
			visit[now + 6] = 1;
			event_(sadari, bam, roll, now + 6, order+ 1);
		}

		roll.pop(); // 메인이 되었던 칸 빼기
	}

	cout << roll.front().second;
}