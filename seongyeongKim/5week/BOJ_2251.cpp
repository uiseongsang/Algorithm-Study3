#include <bits/stdc++.h>
using namespace std;

int a, b, c;
bool visit[201][201][201];
queue<pair<pair<int, int>, int>> q; //a, b, c�� ���� ��
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

		//�湮 ó��
		if (visit[ca][cb][cc]) continue;
		visit[ca][cb][cc] = true;

		//���� C �� ��ü�� �����ϰ� �ִ� ���� �� �߰�
		if (ca == 0) result.push_back(cc);

		//a -> b
		//���� ��� a�� b�� ���� ���� ���� b�� ��ġ�� ��� 
		//a�� b�� �������� ���� �縸 ����� 
		//b�� ���� �� ��
		//c�� �״��
		if (ca + cb > b)
			q.push({ {ca + cb - b, b}, cc });
		//���� ��� a�� b�� ���� ���� ���� b�� ��ġġ�� �ʴ� ���
		//a�� �� �ξ��༭ 0
		//b���� ���� ��� a, b�� ���� ���� ��
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