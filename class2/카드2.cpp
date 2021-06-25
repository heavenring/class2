#include<iostream>
#include<queue>

using namespace std;

int main() {

	int n, pop;
	queue<int> card;
	
	cin >> n;

	for (int i = 1; i <= n; i++)
		card.push(i);

	for (int i = 1; ; i++) {
		if (card.size() == 1) {
			cout << card.front();
			break;
		}
		if (i % 2 == 1) {
			card.pop();
		}

		else if (i % 2 == 0) {
			pop = card.front();
			card.pop();
			card.push(pop);
		}
	}
}