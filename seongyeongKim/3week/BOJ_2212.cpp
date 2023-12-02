/*
문제 이해 도움 준 링크: https://dong-gas.tistory.com/32
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

    //센서 좌표 오름차순 정렬
    sort(sensor, sensor + N);

    //센서 좌표 사이의 거리 추출
    //ex)
    //입력 받은 센서(sensor) : 1 6 9 3 6 7
    //정렬한 값(sort된 sensor) : 1 3 6 6 7 9
    //좌표 사이 거리(dist) : 2 3 0 1 2
    for (int i = 0; i < N - 1; i++) {
        dist[i] = sensor[i + 1] - sensor[i];
    }

    //dist 내림차순 정렬
    //내림차순 정렬 : 3 2 2 1 0
    sort(dist, dist + N - 1, greater<>());

    int answer = 0;
    //센서 사이에 거리가 먼 두 센서는 하나의 기지국에 포함시키면 되므로
    //거리가 짧은 센서들만 다른 기지국에 속하게 함
    for (int i = K; i < N; i++) {
        answer += dist[i - 1];
    }

    cout << answer;

    return 0;
}