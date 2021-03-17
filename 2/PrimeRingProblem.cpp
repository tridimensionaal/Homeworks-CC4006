#include <bits/stdc++.h>

using namespace std;

int cont = 0;

bool esPrimo(int a) {
    if(a < 2){
        return 0;
    }

    int large = int(sqrt(a)) + 1;

    for(int i = 2; i <= large; i++) {
        if (a % i == 0) {
            return 0;
        }
    }
    return 1;
}

bool search(vector <int> v,int j){
    int large= v.size();
    for(int k = 0; k < large; k++){
        if (v[k] == j){
            return 1;
        }
    }
    return 0;
}

void Back(int n,vector <int> v){
    int large = v.size();
    if (large == n) {
        int f = v[n-1];
        if(esPrimo(1+f) && esPrimo(f+v[n-2])){
            for(int i= 0; i<n; i++ ){
                cout << v[i];
                if (i != n-1){
                    cout << " ";
                }
            }
            cout << endl;
        }

    }
    else if ((v.size()>=2) &&(!(esPrimo(v[v.size()-1] + v[v.size()-2])))){
        return;
    }
    else{
        for(int j = 2; j <= n; j++) {
            if (!(search(v,j))) {
                vector<int> vp;
                vp = v;
                vp.push_back(j);
                Back(n, vp);
            }
        }


    }

}

int main() {
    int n;
    while(cin >> n){
        if(cont){
            cout << endl;
        }
        cont++;
        vector<int> v;
        v.push_back(1);
        cout << "Case " << cont << ":" << endl;
        Back(n,v);
    }
}
