#include <iostream>
#include <vector>

using namespace std;

long long conjuntos(vector <long long> v, long long n, long long d){
    long long large = n-1;
    long long con = 0;
    long long j = 2;

    for (long long i = 0; i < large - 1 ; i++){
        long long a = v[i];

        if (j-i < 2){
            j = i + 2;
        }

        while (v[j] - a <= d){
            j++;
            if (j > large){
                break;
            }
        }
        j--;

        long long k = j - i;
        k *= (k-1);
        k /= 2;
        con += k;

        if (j < large){
            j++;
        }

        }
    
    return con;
}

int main(){
    long long n;
    long long d;
    cin >> n >> d;

    vector<long long> v(n,0);

    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    cout << conjuntos(v,n,d);

}
