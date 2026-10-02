#include<iostream>
#include<vector>
using namespace std;
 
int LCS(string &A, string &B) {
    int m=A.size(),n = B.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
 
    for(int i=1; i<=m;i++){
        for(int j=1;j<=n;j++){
            if(A[i-1]==B[j-1])
                dp[i][j]= 1 + dp[i-1][j-1];
            else 
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);     
        }
    }
    return dp[m][n];
}
 
int main() {
    string A, B;
    cout << "Enter first string: ";
    cin >> A;
    cout << "Enter second string: ";
    cin >> B;
 
    cout << "LCS length: "<<LCS(A,B)<<endl;
 
// Enter first string: ABCDE
// Enter second string: ACE
// LCS length: 3
    return 0;
}