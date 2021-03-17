#include <iostream>
#include <vector>

using namespace std;

long long sumamax(vector <long long> v , int n){
    int j = n - 2;
    long long sum1 = 0;
    long long sum3 = v[n-1];
    long long summax = 0;

    if (n==1){
        return 0;
    }

    for (int i = 0; i < n; i++){

        sum1 += v[i];

        while ((sum1 > sum3 )&&(j > i)){
            sum3 += v[j];
            j--;
        }
        if  (sum1 == sum3){
            summax = sum1;
        }
        if (i==j){
            return summax;
        }
        
    }
    return summax;

}

int main(){
    int n;
    cin >> n; 

    vector<long long> v(n,0);

    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    cout << sumamax(v,n);

}
