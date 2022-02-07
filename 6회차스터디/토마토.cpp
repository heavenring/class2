#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int check(vector<vector<int>> &tomato, queue<pair<int,int>> &location, int m, int n) {

	int x, y, count = 0;;
	y = location.front().first;
	x = location.front().second;

	if (x - 1 >= 0 && tomato[y][x - 1] == 0) { //���� �丶���� ���� Ȯ��
		tomato[y][x - 1] = 1;
		location.push(make_pair(y, x - 1));
		count++;
	}

	if (y - 1 >= 0 && tomato[y - 1][x] == 0) { // ���� �丶���� ���� Ȯ��
		tomato[y - 1][x] = 1;
		location.push(make_pair(y - 1, x));
		count++;
	}	

	if (x + 1 < m && tomato[y][x + 1] == 0) { // ���� �丶���� ������ Ȯ��
		tomato[y][x + 1] = 1;
		location.push(make_pair(y, x + 1));
		count++;
	}	

	if (y + 1 < n && tomato[y + 1][x] == 0) { // ���� �丶���� �Ʒ��� Ȯ��
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

	vector<vector<int>> tomato(n, vector<int>(m)); // �丶�� ���� ĭ
	queue<pair<int, int>> location; // �丶���� ��ǥ�� ���� ť

	for (int i = 0; i < n; i++) // �丶���� ���� �Է�
		for (int j = 0; j < m; j++) {
			cin >> tomato[i][j];
		}

	for (int i = 0; i < n; i++) // ���� �丶���� ��ǥ ť�� �Է�
		for (int j = 0; j < m; j++)
			if (tomato[i][j] == 1) {
				location.push(make_pair(i, j));
				count++; // �Ϸ絿�� ���� �丶���� ����
			}

		while (!location.empty()) { // ���̻� ���� �丶�䰡 ������ ���� �ݺ�
			if (count == 0) { 
				day++; // �Ϸ簡 ������
				count = count1; // ������ ���� �丶�� ���� ����
				count1 = 0;
			}

			count1 += check(tomato, location, m, n); 
			location.pop();
			count--; // �Ϸ絿�� ���� �丶�丸ŭ -1

		}

		for (int i = 0; i < n; i++) // ������ �丶�䰡 �ִ��� Ȯ��
			for (int j = 0; j < m; j++)
				if (tomato[i][j] == 0) { // �ִٸ� ��� ���α׷� ����
					cout << -1;
					return 0;
				}

		cout << day;

}