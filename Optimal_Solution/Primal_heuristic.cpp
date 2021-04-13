#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>

using namespace std;

int sum(vector<int> x){
    int s=0;
    for(int i=0; i<x.size(); i++){
        s += x[i];
    }
    return s;
}

vector<vector<int>> mapping(vector<string> V){
    vector<vector<int>> ans(V.size());
    for(int j=0; j<V.size(); j++){
        for(int i=0; i<V[j].size(); i++){
            // cout<<int (V[j][i])- 96;
            ans[j].push_back(int (V[j][i])- 96);
        }
    }
    return ans;
}

int CSP(vector<vector<int>> S){
    // n-> No of strings, m=length of strings
    int m=S[0].size()-1, n=S.size();
    int mx=-1, i=-1;
    for(int c=0; c<=m; c++){
        mx = -1;
        i = 1;
        for(int r=0; r<n; r++){
            if(S[r][c]>mx) {
                mx = S[r][c];
                i=r;
            }
        }
        for(int r=0; r<n; r++){
            S[r][c]=0;
        }
        S[i][c] = 1;
    }
    int d=-100;
    for(int r=0; r<n; r++){
    d = max(m - sum(S[r]), d);
    }
    return d;
}

int main(){
    // example given in Research paper
    vector<string> V {"differ", "median", "length", "medium"};
    vector<vector<int>> S;
    S = mapping(V);
    // cout<<S[0][1];
    int d=0;
    d = CSP(S);
    cout<<"Max Min Hamming Distance: "<<d;
    return 0;

}
