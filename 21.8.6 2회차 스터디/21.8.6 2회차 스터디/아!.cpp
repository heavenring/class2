#include<iostream>
#include<string>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string doctor, patient;

	cin >> patient >> doctor;

	if (patient <= doctor)
		cout << "go";
	else
		cout << "no";
}