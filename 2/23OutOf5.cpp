#include <iostream>
#include<vector>
#include <algorithm> 

using namespace std;

vector <int> o = {0,0,0,0};

int phi(vector<int> v){

    int sum = 0;

    if(o[0]==0){
        sum = (v[0]+v[1]);
    }

    else if(o[0]==1){
        sum = (v[0]-v[1]);
    }

    else{
        sum = (v[0]*v[1]);
    }

    for (int i = 1; i < 4; i++){

        if(o[i]==0){
            sum += v[i+1];
        }
        else if(o[i]==1){
            sum -= v[i+1];
        }
        else{
            sum *= v[i+1];

        }
 
    }
    return sum;
}

int back2(vector <int> v){

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            for (int k = 0; k < 3; k++){
                for (int l = 0; l < 3; l++){
                    o = {i,j,k,l};
                    if (phi(v) == 23){
                        return 1;
                    }
                    
                }
            }

        }

    }
    return 0;
}

int back1(vector <int> v){
    do{
        o = {0,0,0,0,0};
        if(back2(v)){
            return 1;
        }


    }while(next_permutation(v.begin(),v.end()));

    return 0;
}

int main(){

    vector <int> r;
    int bol = 1;

    while(bol){
        int sum = 0;
        vector <int> v(5,0);

        for (int i = 0; i < 5; i++){
            int a;

            cin >> a;
            v[i] = a;
            sum += a;
        }
        if(!(sum)){
            bol = 0;
            break;
        }
        else{

            sort(v.begin(),v.end());

            int res = back1(v);

            r.push_back(res);

        }
    }
    
    int large = r.size();

    for (int i = 0; i < large; i++){
        if(r[i]){
            cout << "Possible" << endl;
        }
        else{
            cout << "Impossible" << endl;
        }
    }
}


