#include<iostream>
#include<deque>

using namespace std;

void push_front(int odr, deque<int>& order) {
	order.push_front(odr);
}

void push_back(int odr, deque<int>& order) {
	order.push_back(odr);
}
void pop_front(deque<int>& order) {
	if (order.empty() == 1)
		cout << -1 << "\n";
	else {
		cout << order.front() << "\n";
		order.pop_front();
	}
}
void pop_back(deque<int>& order) {
	if (order.empty() == 1)
		cout << -1 << "\n";
	else {
		cout << order.back() << "\n";
		order.pop_back();
	}
}
void size(deque<int>& order) {
	cout << order.size() << "\n";
}
void empty(deque<int>& order) {
	cout << order.empty() << "\n";
}
void front(deque<int>& order) {
	if (order.empty() == 1)
		cout << -1 << "\n";
	else
		cout << order.front() << "\n";
}
void back(deque<int>& order) {
	if (order.empty() == 1)
		cout << -1 << "\n";
	else
		cout << order.back() << "\n";
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, odr2;
	string odr1;
	deque<int> order;

	cin >> n;

	for (int i = 0; i < n; i++) {

		cin >> odr1;
		if(odr1 == "push_front" || odr1 =="push_back")
		cin >> odr2;

		//명령어 목록↓↓↓↓↓↓
		if (odr1 == "push_front") 
			push_front(odr2, order);

		else if (odr1 == "push_back") 
			push_back(odr2, order);

		else if (odr1 == "pop_front") 
			pop_front(order);	

		else if (odr1 == "pop_back")
				pop_back(order);

		else if (odr1 == "size")
			size(order);

		else if (odr1 == "empty")
			empty(order);

		else if (odr1 == "front") 
			front(order);

		else //(odr1 == "back") 
			back(order);
	}
}