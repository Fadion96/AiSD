#include <iostream>
#include <fstream>

using namespace std;

int editDistance(string a, string b){
    int n = a.length();
    int m = b.length();
    int c[n+1][m+1];
    int i,j;
    for(i = 0; i <= n; i++){
        c[i][0] = i;
    }
    for(i = 0; i <= m; i++){
        c[0][i] = i;
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            if(a[i - 1] == b[j - 1]){
                c[i][j] = c[i - 1][j - 1];
            }
            else if(c[i - 1][j] + 1 < c[i][j - 1] + 1){
                c[i][j] = min(c[i - 1][j] + 1, c[i - 1][j - 1] + 1);
            }
            else{
                c[i][j] = min(c[i][j - 1] + 1, c[i - 1][j - 1] + 1);
            }
        }
    }
    return c[n][m];
}

int main() {
    ifstream in("dictionary.txt");
    string a;
    string b;
    string c[3];
    int i = 0;
    cout << "Input word" << endl;
    cin >> a;
    while(!in.eof()) {
        in >> b;
        if (editDistance(a, b) == 1) {
            c[i] = b;
            i++;
            if (i == 3) {
                break;
            }
        }

    }
    cout<<"Words: "<<endl;
    for(int k = 0; k < i;k++){
        cout<<c[k]<<endl;
    }
}
