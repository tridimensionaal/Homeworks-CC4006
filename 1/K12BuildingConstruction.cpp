#include <iostream>
#include <vector>
#define ll long long

using namespace std;

int difff(vector<int> h, vector<int> c, int n, int H){

    ll c1 = 0;
    ll c2 = 0;
    int HH = H + 1;

    for (int i = 0; i < n; i++){

        int ci = c[i];

        int d1;
        int hi = h[i];

        if (H > hi){
            d1 = H - hi;
        }
        else{

            d1 = hi - H;
        }

        c1 += 1ll*(d1*ci);

        ll d2;

        if (HH > hi){
            d2 = HH - hi;
        }

        else{

            d2 = hi - HH;
        }

        c2 += 1ll*(d2*ci);
    }

    if (c2 > c1){
        return 1;
    }
    else {
        return 0;
    }
}

int main(){

    int T;
    cin >> T;

    for (int i= 0; i < T; i++){

        int n;
        cin >> n;

        vector <int> h(n,0);
        vector <int> c(n,0);

        for (int j = 0; j < n; j++){
            cin >> h[j];
        }

        for (int k = 0; k < n; k++){
            cin >> c[k];
        }

        int a = 0;
        int b = 10000000;
        int mid;

        while (a < b){
            mid = ((a+b)/2);

            if (difff(h,c,n,mid)){
                b = mid;
            }

            else{
                a = mid + 1;
            }
        }

        ll costos1 = 0;
        ll costos2 = 0;

        for (int l = 0; l < n; l++){

            int hi = h[l];
            int ci = c[l];
            int d1;
            
            int mid2 = (mid + 1);

            if (mid > hi){
                d1 = mid - hi;
            }
            else{
                d1 = hi - mid;
            }
            costos1 += 1ll*(d1*ci);

            int d2;

            if (mid2 > hi){
                d2 = mid2 - hi;
            }
            else{
                d2 = hi - mid2;
            }
            costos2 += 1ll*(d2*ci);
        }
        
        if(costos1 < costos2){
            cout << costos1 <<endl;
        }
        else{
            cout << costos2 <<endl;
        }


        
    }
}


