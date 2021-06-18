#include<iostream>
using namespace std;

int main() {
	cin.tie(NULL); ios::sync_with_stdio(false); cout.tie(NULL);

	int n, k, answer;
	int i, j;
	int factorial_n = 1, factorial_k = 1, factorial_nk = 1;

	cin >> n >> k;

	for (i = 1; i <= n; i++)
		factorial_n *= i;

	for (i = 1; i <= k; i++)
		factorial_k *= i;

	for (i = 1; i <= n - k; i++)
		factorial_nk *= i;
	
	answer = factorial_n / (factorial_k * factorial_nk);

	cout << answer;
}