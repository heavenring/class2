#include<iostream>
#include<vector>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio;
	cout.tie(NULL);

	int t, tc;
	vector<int> a(41);
	vector<int> b(41);
	cin >> t;

	a[0] = 1;
	b[1] = 1;

	for (int i = 0; i < t; i++) {
		cin >> tc;
			if (a[tc] == 0 && b[tc] == 0)// �Ǻ���ġtc��° ���� �������
				for (int j = 2; j <= tc; j++) {// �Ǻ���ġ 2���� tc��° ���� ���� ���Ѵ�
					if (a[j] == 0 && b[j] == 0) {// ���� �Ǻ���ġ tc��° ���� ���� j��°�� ���� �ִٸ� �������� �Ѿ��
						a[j] = a[j - 1] + a[j - 2];
						b[j] = b[j - 1] + b[j - 2];
					}
				}
		cout << a[tc] << " " << b[tc] << "\n";
	}
}