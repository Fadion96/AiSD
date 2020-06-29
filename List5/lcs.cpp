#include <iostream>

using namespace std;
int nrComp = 0;

int longestCommonSubsequence(string a, string b){
    int n = a.length();
    int m = b.length();
    int c[n+1][m+1];
    int i,j;
    for(i = 0; i <= n; i++){
        c[i][0] = 0;
    }
    for(i = 0; i <= m; i++){
        c[0][i] = 0;
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            nrComp++;
            if(a[i - 1] == b[j - 1]){
                c[i][j] = c[i - 1][j - 1] + 1;
            } else{
                c[i][j] = max(c[i - 1][j],c[i][j - 1]);
            }
        }
    }
    return c[n][m];
}

int main() {
    string a,b;
    cout<<"Input first word"<<endl;
    cin>>a;
    cout<<"Input second word"<<endl;
    cin>>b;
    cout<<"Length of first word: "<<a.length()<<" length of second word: "<<b.length()<<endl;
    cout<<"LCS: "<<longestCommonSubsequence(a,b)<<endl;
    cout<<"Number of compares: "<<nrComp<<endl;
}