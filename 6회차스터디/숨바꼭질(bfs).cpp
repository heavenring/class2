#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, k;
	int location, time;

	queue<pair<int, int>> que;
	vector<int> visit(1000000);
	cin >> n >> k;

	que.push(make_pair(n, 0));
	visit[n] = 1;

	if (n > k) {
		cout << n - k;
		return 0;
	}

	while (!que.empty()) {
		location = que.front().first;
		time = que.front().second;

		if (que.front().first == k) {
			cout << que.front().second;
			break;
		}

		if (que.front().first * 2 < 100001 && visit[que.front().first * 2] == 0) {
			que.push(make_pair(location * 2,time + 1));
			visit[que.front().first * 2] = 1;
		}

		if (que.front().first + 1 < 100001 && visit[que.front().first + 1] == 0) {
			que.push(make_pair(location + 1, time + 1));
			visit[que.front().first + 1] = 1;
		}

		if (que.front().first - 1 >= 0 && visit[que.front().first - 1] == 0) {
			que.push(make_pair(location - 1, time + 1));
			visit[que.front().first - 1] = 1;
		}

		que.pop();
	}
}