#include<iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int a, b, v;

	cin >> a >> b >> v;
	
	if ((v - a) % (a - b) != 0)
		cout << (v - a) / (a - b) + 2;
	else
		cout << (v - a) / (a - b) + 1;
}