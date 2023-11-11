#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[50][50], B[50][50];
int result = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < M; j++) {
			A[i][j] = str[j] - '0';
		}
	}

	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < M; j++) {
			B[i][j] = str[j] - '0';
		}
	}

	int cntN = N - 2, cntM = M-2;

	

	for (int i = 0; i < cntN; i++) {
		for (int j = 0; j < cntM; j++) {
			if (A[i][j] != B[i][j]) {
				for (int k = 0; k < 3; k++) {
					for (int l = 0; l < 3; l++) {
						A[i + k][j + l] = (A[i + k][j + l] + 1) % 2;
					}
				}
				result += 1;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (A[i][j] != B[i][j]) {
				cout << -1;
				return 0;
			}
		}
	}

	cout << result;


	return 0;
}