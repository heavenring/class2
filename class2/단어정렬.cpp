#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool length(string a, string b) {
	if (a.length() < b.length())
		return true;

	return ((a.length() == b.length()) && (a < b));
}

int main() {
	cin.tie(NULL); ios::sync_with_stdio(false); cout.tie(NULL);

	int n;

	cin >> n;

	vector<string> word(n);

	for (int i = 0; i < n; i++) {
		cin >> word[i];
	}

	sort(word.begin(), word.end(), length);

	cout << word[0];

	for (int i = 1; i < n; i++) {
		if (word[i] != word[i - 1])
			cout << "\n" << word[i];
	}		
}

/*#include<stdio.h>
#include<string.h>

int main() {

	int num, i, j;
	char word[20000][50], change[50];

	scanf("%d", &num);

	for (i = 0; i < num; i++) {
		scanf("%s", word[i]);
		for (j = i; j > 0; j--) {
			if (strlen(word[j]) < strlen(word[j - 1])) {
				strcpy(change, word[j - 1]);
				strcpy(word[j - 1], word[j]);
				strcpy(word[j], change);
			}
			else if (strlen(word[j]) == strlen(word[j - 1]))
				if (strcmp(word[j],word[j - 1]) < 0) {
					strcpy(change, word[j - 1]);
					strcpy(word[j - 1], word[j]);
					strcpy(word[j], change);
				}
		}
	}
	for (i = 0; i < num; i++) {
		if(strcmp(word[i],word[i - 1]) != 0)
			printf("%s\n", word[i]);
	}
}*/