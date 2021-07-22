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
			if (a[tc] == 0 && b[tc] == 0)// 피보나치tc번째 값이 없을경우
				for (int j = 2; j <= tc; j++) {// 피보나치 2부터 tc번째 까지 값을 구한다
					if (a[j] == 0 && b[j] == 0) {// 만약 피보나치 tc번째 보다 낮은 j번째에 값이 있다면 다음으로 넘어간다
						a[j] = a[j - 1] + a[j - 2];
						b[j] = b[j - 1] + b[j - 2];
					}
				}
		cout << a[tc] << " " << b[tc] << "\n";
	}
}