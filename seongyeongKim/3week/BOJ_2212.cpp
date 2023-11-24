/*
���� ���� ���� �� ��ũ: https://dong-gas.tistory.com/32
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, K;
    cin >> N >> K;

    int sensor[10000];
    int dist[10000];

    for (int i = 0; i < N; i++) {
        cin >> sensor[i];
    }

    //���� ��ǥ �������� ����
    sort(sensor, sensor + N);

    //���� ��ǥ ������ �Ÿ� ����
    //ex)
    //�Է� ���� ����(sensor) : 1 6 9 3 6 7
    //������ ��(sort�� sensor) : 1 3 6 6 7 9
    //��ǥ ���� �Ÿ�(dist) : 2 3 0 1 2
    for (int i = 0; i < N - 1; i++) {
        dist[i] = sensor[i + 1] - sensor[i];
    }

    //dist �������� ����
    //�������� ���� : 3 2 2 1 0
    sort(dist, dist + N - 1, greater<>());

    int answer = 0;
    //���� ���̿� �Ÿ��� �� �� ������ �ϳ��� �������� ���Խ�Ű�� �ǹǷ�
    //�Ÿ��� ª�� �����鸸 �ٸ� �������� ���ϰ� ��
    for (int i = K; i < N; i++) {
        answer += dist[i - 1];
    }

    cout << answer;

    return 0;
}