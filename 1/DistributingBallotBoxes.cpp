#include <iostream>
#include <vector>

using namespace std;

long verificar(vector<long> v, int n, int b, long resp){

    for(int i = 0; i < n; i++){

        if (b < 1){
            return 0;
        }

        long a = v[i];
        
        long rest;

        if (a%resp != 0){
            rest = a/resp + 1;
        }
        else{
            rest = a/resp;
        }

        if (rest > b){
            return 0;
        }

        else {
            b -= rest;
        }
    }

    return 1;
}

int main(){
    

    vector <long> resp;

    while (1){
        int n,b;
        cin >> n >> b;

        if((n==-1) && (b==-1)){
            break;
        }

        else{

            vector <long> v(n,0);

            for (int i = 0; i < n; i++){
                cin >> v[i];
            }
            cout << endl;

            long a = 0;
            long bb = 5000000;
            long mid;

            while (a < bb){
                mid = ((a + bb)/2);

                if(verificar(v,n,b,mid)){
                    bb = mid;
                }
                else{
                    a = mid + 1;
                }
            }
            if (verificar(v,n,b,a)){
                resp.push_back(a);
            }
            else{
                resp.push_back(bb);
            }
        }
    }
    cout << endl;

    for (unsigned long k = 0; k < resp.size(); k++){
        cout << resp[k] << endl;
    }

}










