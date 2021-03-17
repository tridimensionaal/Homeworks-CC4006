#include <iostream>
#include<vector>
#include <string>
#include <algorithm>
#include <set>
#include<iterator>

using namespace std;
int n;
set <vector <int>> mapa;

void back(vector < vector <int>> v, int i, int j, int con,vector <int> m){

    v[i][j] = 0;
    m[con-1] = (n*i + j);
 
    if (con==8){
        sort(m.begin(),m.end());
        mapa.insert(m);
        return;
    }
    //caminos a recorrer
    
    //hacia la derechaa
    if (j < n-1){
        if(v[i][j+1]){
            back(v,i,j+1,con+1,m);
        }
    }

    //hacia abajoa
    if (i < n-1){
        if(v[i+1][j]){
            back(v,i+1,j,con+1,m);
        }
    }

    //hacia la izquierdaa
    if (j){
        if(v[i][j-1]){
            back(v,i,j-1,con+1,m);
        }
    }

    //hacia arribaa
    if (i){
        if(v[i-1][j]){
            back(v,i-1,j,con+1,m);
        }
    }
    return;
}

int main(){

    int t;
    cin >> t;

    for (int i = 0; i < t; i++){
        int nn;
        cin >> nn;
        n = nn;

        set <vector <int>> mapaa;
        mapa = mapaa;

        vector< vector<int>>v(n,vector<int>(n,0));

        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                char a;
                cin >> a;
                if (a == 'X'){
                    v[j][k] = 1;
                }
            }
        }

        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                if(v[j][k]){
                    vector <int> m(8,0);
                    back(v,j,k,1,m);
                }
            }
        }
        cout << mapa.size() << endl;
    }
}
