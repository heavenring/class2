#include<iostream>
#include<vector>
#include<string>
#include<cmath>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	
	long long length, answer, p;
	string word;
	vector<char> alphabet(26);

	for (int i = 0; i < 26; i++) {
		alphabet[i] = i + 'a';
	}

	cin >> length >> word;
	answer = 0;

	for (int i = 0; i < length; i++) {
		for (int j = 0; j < 26; j++)
			if (word[i] == alphabet[j]){
				p = 1;
				for (int k = 0; k < i; k++)
					p = (p * 31) % 1234567891;
				answer = (answer + (j + 1) * p) % 1234567891;
				break;
			}
	}
		cout << answer;
}