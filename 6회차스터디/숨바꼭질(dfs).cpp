#include<iostream>
#include<stack>

using namespace std;

int telpo(stack<int>& save, int n, int k, int count);
int move(stack<int>& save, int n, int k, int count);
int back(stack<int>& save, int n, int k, int count);

int telpo(stack<int>& save, int n, int k, int count) {
	int a, b, c, d;
	save.push(n);

	if (save.top() < k) {

		a = telpo(save, n * 2, k, count);
		save.pop();
		b = move(save, n + 1, k, count);
		save.pop();
		c = back(save, n - 1, k, count);
		save.pop();
	}
	else if (save.top() == k) {
		if (count > save.size())
			return save.size();
		else
			return count;
	}
	else
		d = back(save, n - 1, k, count);

	return min(min(a, b), min(c, d));
}

int move(stack<int>& save, int n, int k, int count) {
	int a, b, c, d;
	save.push(n);

	if (save.top() < k) {

		a = telpo(save, n * 2, k, count);
		save.pop();
		b = move(save, n + 1, k, count);
		save.pop();
		c = back(save, n - 1, k, count);
		save.pop();
	}
	else if (save.top() == k) {
		if (count > save.size())
			return save.size();
		else
			return count;
	}
	else
		d = back(save, n - 1, k, count);

	return min(min(a, b), min(c, d));
}

int back(stack<int>& save, int n, int k, int count) {
	int a, b, c, d;
	save.push(n);

	if (save.top() < k) {

		a = telpo(save, n * 2, k, count);
		save.pop();
		b = move(save, n + 1, k, count);
		save.pop();
		c = back(save, n - 1, k, count);
		save.pop();
	}
	else if (save.top() == k) {
		if (count > save.size())
			return save.size();
		else
			return count;
	}
	else
		d = back(save, n - 1, k, count);

	return min(min(a, b), min(c, d));
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, k, count = 10000000;
	cin >> n >> k;
		
	stack<int> save;

	save.push(n);

	cout << min(telpo(save, n * 2, k, count), min(move(save, n + 1, k, count), back(save, n - 1, k, count)));

}