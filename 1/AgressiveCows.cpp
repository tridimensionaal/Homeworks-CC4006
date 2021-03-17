#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

int probar(vector<int> v,int c, int r ){
    c--;
    int i = 1;
    int ult = 0;
    int large = v.size();

    while(c > 0){
        if (large <= i ){
            return 1;
        }
        int a = v[i];
        if (a - v[ult] >= r){
            c--;
            ult = i;
        }
        i++;
    }
    return 0;
}

int main() {

    int casos;
    int n;
    int c;

    cin >> casos;

   for(int i=0; i < casos ; i++){
       cin >> n >> c;
       vector <int> v(n,0);

       for (int j = 0; j < n; j++){
           int x;
           cin >> x;
           v[j] = x;
       }
       sort(v.begin(),v.end());
       
 
       int a = 0;
       int b = v[n-1];
       int mid = 0;

       while (a < b){
           mid = ((a + b )/2)+ 1;
           if (probar(v,c,mid)){
               b = mid - 1;
                   }
           else {
               a = mid;
           }
       }

       if (!(probar(v,c,a))){
           cout << a << endl;
       }
       else {
           cout << 0 << endl;
       }
   }

    return 0;
   }

