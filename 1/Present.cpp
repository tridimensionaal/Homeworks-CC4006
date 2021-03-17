#include <bits/stdc++.h>

using namespace std;

int probar(vector<long long> v, long long w, long long m, long long H, long long n){

    vector<long long> tt(n,0);
    long long ta = 0;
    long long r = 0;

    for (long long j = 0; j < n; j++){
        if (j-w >= 0 ){
            ta -= tt[j-w];
            if(v[j] + ta < H){
                tt[j] = H - v[j] - ta;
                ta += tt[j];
                r += tt[j];
            }
            if (r > m) {
                return 0;
            }

        }
        else{
            if(v[j] + ta < H){
                tt[j] = H - v[j] - ta;
                ta += tt[j];
                r += tt[j];
            }
            if (r > m) {
                return 0;
            }
        }

    }
    return 1;
}

int main() {
    long long n, m, w;
    cin >> n >> m >> w;

    vector<long long> v(n, 0);

    for (long long i = 0; i < n; i++) {
        cin >> v[i];
    }
    long long a = 1;
    long long b = 1000100000;
    long long mid;

    while (a < b) {
        mid = ((a + b) / 2 + 1);

        if (probar(v, w, m, mid, n)) {
            a = mid;
        } else {
            b = mid - 1;
        }
    }
    cout << a << endl;
}
