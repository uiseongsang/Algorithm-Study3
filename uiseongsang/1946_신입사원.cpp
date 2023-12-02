#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    for(int i = 0; i < T; i++) {
        int n;
        cin >> n;

        vector<pair<int,int>> v;

        for(int j = 0; j < n; j++) {
            int a,b;
            cin >> a >> b;
            v.push_back({a,b});
        }
        
        sort(v.begin(), v.end());

        int _start = 0;
        int ret = 1;

        for(int i = 1; i < n; i++){
            if(v[_start].second > v[i].second) {
                ret++;
                _start = i;
            }
        }
        cout << ret << "\n";
    }
    return 0;
}
