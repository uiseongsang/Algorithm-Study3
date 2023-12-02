#include <bits/stdc++.h>
using namespace std;

int w, h;
int _map[50][50];
int land = 0;

int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

void bfs(int ix, int iy) {
	queue<pair<int, int>> q;
	q.push({ ix, iy });
	_map[ix][iy] = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= h || ny<0 || ny>=w)
				continue;
			if (_map[nx][ny]) {
				q.push({ nx, ny });
				_map[nx][ny] = 0;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	while (true) {
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> _map[i][j];
			}
		}

		land = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (_map[i][j]) {
					bfs(i, j);
					land++;
				}
			}
		}

		cout << land << '\n';
	}

	return 0;
}