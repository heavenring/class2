#include<iostream>
#include<vector>
#include<queue>

using namespace std;
/****************************************�ٽ� ��ٸ��� ���� ������ �湮�� Ȯ���� �ʿ䰡 ����****************************************/
/*************************��ٸ��� ���� ���������� �湮�� Ȯ���߱� ����!! ������ Ȯ���ϸ� ������ �ٸ� �濡 ���ذ� �ȴ�******************/

void event_(vector<int> &sadari,vector<int> &bam, queue<pair<int,int>> &roll, int now, int order) {// ���� ����Ǵ� �ڵ�� �Լ��� ����
		if (sadari[now] != 0) {
			roll.push(make_pair(sadari[now], order)); // �ش�ĭ�� ��ٸ��� �������
		}

		else if (bam[now] != 0) {
			roll.push(make_pair(bam[now], order)); // �ش� ĭ�� ���� �������
		}

		else {
			roll.push(make_pair(now, order)); // �ش�ĭ�� �ƹ��͵� �������
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

	for (int i = 0; i < n; i++) {// ��ٸ��� ���� ��ġ�� �޴� �迭
		cin >> start >> end;
		sadari[start] = end;
	}
	for (int i = 0; i < m; i++) {
		cin >> start >> end;
		bam[start] = end;
	}

	event_(sadari, bam, roll, 1, 0); // ù��° ĭ�� ��ٸ��� ���� �ִ��� Ȯ���� ���� �ڵ�
	roll.pop();// �Ϲ� ĭ�̶�� ���� ��ǥ�� �ѹ��� �����⿡ pop()

	while (roll.front().first < 100) { // 100���� ũ�ų� ������ �����ϱ� ������ ������ �ݺ�
		now = roll.front().first; // ������ ��ġ
		order = roll.front().second; // ���° �ֻ����� ���������� Ȯ��

		if (now + 1 <= 100 && visit[now + 1] == 0) { // 1ĭ  ~ 6ĭ ������ ���
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

		roll.pop(); // ������ �Ǿ��� ĭ ����
	}

	cout << roll.front().second;
}