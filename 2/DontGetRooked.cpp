#include <iostream>
#include<vector>

using namespace std;

int maximo = 0;
int n;

int probar(vector <vector <int>> mat){

    int con = 0;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int pos = mat[i][j];

            if (pos==1){
                con++;

                for (int k = i + 1; k < n; k++){
                    if(mat[k][j] == -1){
                        break;
                    }
 
                    if(mat[k][j]==1){
                        return -1;
                    }
               }

                for (int l = j + 1; l < n; l++){

                    if(mat[i][l] == -1){
                        break;
                    }
 
                    if(mat[i][l]==1){
                        return -1;
                    }
               }
            }
        }
    }
    return con;
}


int backtracking(vector <vector <int>> mat){

    int torres = probar(mat);

    if (torres!=-1){
        if(torres > maximo){
            maximo = torres;
        }

        for(int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if(!(mat[i][j])){

                    vector <vector <int>> p = mat;
                    p[i][j]++;

                    backtracking(p);
                }
            }
        }
    }
    return 0;
}

int main(){

    while (1){

        int bol;
        cin >> bol;

        if(bol){

            maximo = 0;
            n = bol;

            vector <vector <int>> mat(bol,vector <int>(bol,0));


            for (int i = 0; i < bol; i++){
                for (int j = 0; j < bol; j++){
                    char c;

                    cin >> c;

                    if (c == '.'){
                        mat[i][j] = 0;
                    }
                    else {
                        mat[i][j] = -1;
                    }
                }
            }

            backtracking(mat);
            cout << maximo << endl;


        }

        else{
            break;
        }

    }

}

