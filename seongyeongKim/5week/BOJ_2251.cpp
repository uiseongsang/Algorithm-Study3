#include <bits/stdc++.h>
using namespace std;

int a, b, c;
bool visit[201][201][201];
queue<pair<pair<int, int>, int>> q; //a, b, c의 물의 양
vector<int> result;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> a >> b >> c;

	q.push({ {0,0}, c});
	while (!q.empty()) {
		int ca = q.front().first.first;
		int cb = q.front().first.second;
		int cc = q.front().second;
		q.pop();

		//방문 처리
		if (visit[ca][cb][cc]) continue;
		visit[ca][cb][cc] = true;

		//물통 C 그 자체로 보유하고 있는 물의 양 추가
		if (ca == 0) result.push_back(cc);

		//a -> b
		//지금 담긴 a와 b의 물의 양이 물통 b를 넘치는 경우 
		//a는 b가 가득차기 위한 양만 남기고 
		//b는 가득 찬 양
		//c는 그대로
		if (ca + cb > b)
			q.push({ {ca + cb - b, b}, cc });
		//지금 담긴 a와 b의 물의 양이 물통 b를 넘치치지 않는 경우
		//a는 다 부어줘서 0
		//b에는 지금 담김 a, b의 물의 양의 합
		else
			q.push({ {0, ca + cb}, cc });

		// a -> c
		if (ca + cc > c)
			q.push({ {ca + cc - c, cb}, c });
		else
			q.push({ {0, cb}, ca + cc });

		// b -> a
		if (cb + ca> a)
			q.push({ {a, cb + ca - a}, cc });
		else
			q.push({ {cb + ca, 0}, cc });
		// b -> c
		if (cb + cc> c)
			q.push({ {ca, cb + cc - c}, c });
		else
			q.push({ {ca, 0}, cb + cc });

		// c -> a
		if (cc + ca > a)
			q.push({ {a, cb}, cc + ca - a });
		else
			q.push({ {cc + ca, cb}, 0 });
		// c -> b
		if (cc + cb > b)
			q.push({ {ca, b}, cc + cb - b });
		else
			q.push({ {ca, cc + cb}, 0 });
	}

	sort(result.begin(), result.end());
	for(auto i : result){
		cout << i << ' ';
	}


	return 0;
}