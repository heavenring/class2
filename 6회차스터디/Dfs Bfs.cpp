#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

void dfs(vector<int> &visit, vector<vector<int>> &dfs_bfs, int v) {
	if (visit[v] == 0) {// �湮���� ���� ������ ��� ����
		cout << v << " ";// �湮�� ���� ���
		visit[v] = 1;// �湮�� ǥ��
		
		for (int i = 0; i < dfs_bfs[v].size(); i++) // ���� ������ŭ �İ��� �ݺ���
			dfs(visit, dfs_bfs, dfs_bfs[v][i]); // ����� ������ ������ ���ϰ� �ٷ� �Լ� ���� 
	}
}

void bfs(vector<int>& visit, vector<vector<int>>& dfs_bfs, queue<int> &que, int v) {

	while (!que.empty()) {
		v = que.front();
		if (visit[v] == 0) {
			cout << v << " ";
			visit[v] = 1;
			for (int i = 0; i < dfs_bfs[v].size(); i++) {
				if (visit[dfs_bfs[v][i]] == 0)// bfs�� dfs�� �޸� ���������� ������ ���� �� ������ �ֱ⿡ �������� ���� push�ϰ� ����
					que.push(dfs_bfs[v][i]);
			}
		}
		que.pop(); // ���� ������ ������ �ľ��ϱ� ���� ���� ������ ���� ����
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, m, v, a, b;

	cin >> n >> m >> v;

	vector<vector<int>> dfs_bfs(n + 1); //��
	vector<int> visit(n + 1, 0); // �ѤѤѤ� ������ ���� 1���� �����ϱ⿡ n + 1�� �Ͽ� �迭�� ũ�� ����
	queue<int> que;

	for (int i = 0; i < m; i++) {// ���� ���� 2���� �迭�� �����Ͽ� 1�� 2�� �����Ҷ� [1][0] = 2 ���Ǵ¹��
		cin >> a >> b;
		dfs_bfs[a].push_back(b);
		dfs_bfs[b].push_back(a);
	}

	for (int i = 0; i <= n; i++)// ��ü���� ������ �ƴ� �� ������ ����Ǿ� �ִ� ������ ���������� ���Բ� ���ġ �� �ڵ�
		stable_sort(dfs_bfs[i].begin(), dfs_bfs[i].end());

	dfs(visit, dfs_bfs, v);
	
	for (int i = 0; i < n + 1; i++) // dfs���� �湮�ߴ����� ���ְ� �湮���� ������ó�� �ʱ�ȭ
		visit[i] = 0;

	cout << "\n";// dfs, bfs�� ����� �����ϱ� ���� ����
	que.push(v);// ������ ������� que�� �Է�
	bfs(visit, dfs_bfs, que, v);
}