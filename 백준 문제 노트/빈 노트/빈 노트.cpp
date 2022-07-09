#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s[50];

bool comp(string s1, string s2) {
	if (s1.length() != s2.length()) return s1.length() < s2.length();
	int digitsum1 = 0, digitsum2 = 0;
	for (auto x : s1) {
		if ('0' <= x && x <= '9') digitsum1 += x - '0';
	}
	for (auto x : s2) {
		if ('0' <= x && x <= '9') digitsum2 += x - '0';
	}
	if (digitsum1 != digitsum2) return digitsum1 < digitsum2;

	return s1 < s2;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N; cin >> N;
	for (int i = 0; i < N; i++) cin >> s[i];
	sort(s, s + N, comp);

	for (int i = 0; i < N; i++) cout << s[i] << '\n';
}