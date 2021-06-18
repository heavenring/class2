#include<iostream>
using namespace std;

int max(int a, int b) {
	int c;
	c = a % b;
	if (c == 0)
		return b;
	return max(b, c);

}

int main() {

	int n1, n2, n3;
	int answer;
	cin >> n1 >> n2;

	answer = max(n1, n2);
	cout << answer << "\n" << (n1 * n2) / answer;

}

아래꺼 이전에 풀었던것
/*#include<iostream>
using namespace std;

int max(int a, int b, int c) {

	c = a % b;
	if (a % b == 0)
		return b;
	return max(b, c, 0);
}

int main() {

	int n1, n2, n3;
	int answer;
	cin >> n1 >> n2;

	n3 = n1 % n2;

	answer = max(n1, n2, n3);
	cout << answer << "\n" << (n1 * n2) / answer;
}*/