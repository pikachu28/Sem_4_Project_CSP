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

// int CSP(vector<vector<int>> S){
//     // n-> No of strings, m=length of strings
//     int m=S[0].size()-1, n=S.size();
//     int mx=-1, i=-1;
//     for(int c=0; c<=m; c++){
//         mx = -1;
//         i = 1;
//         for(int r=0; r<n; r++){
//             if(S[r][c]>mx) {
//                 mx = S[r][c];
//                 i=r;
//             }
//         }
//         for(int r=0; r<n; r++){
//             S[r][c]=0;
//         }
//         S[i][c] = 1;
//     }
//     int d=-100;
//     for(int r=0; r<n; r++){
//     d = max(m - sum(S[r]), d);
//     }
//     return d;
// }
// calculating Hamming Distance b/w 2 strings which mapped to integer values
int HD(vector<int> x, vector<int> y){
    // n-> No of strings, m=length of strings
    int m=x.size()-1;
    for(int c=0; c<=m; c++){
        if(x[c]>y[c]){
            y[c] = 0;
            x[c] = 1;
        }
        else{
            y[c] = 1;
            x[c] = 0;
        }
    }
    int d=-100;
    d = max(m - sum(x), m-sum(y));
    return d;
}
void CSP_2(vector<int> s, vector<vector<int>> S, int d){
    // n-> No of strings, m=length of strings
    int m = s.size();
    int mn=m, mx=-1;
    int n=S.size();
    for(int i=0; i<n; i++){
        mx=-1;
        for(int j=0; j!=i && j<n; j++){
            mx = max(mx, HD(S[i], S[j]));
        }
        if(mx!=-1 && mx<mn){
            s=S[i];
            d=mx;
            mn=mx;
        }
    }
    cout<<"Closest String is ";
    for(int i=0; i<s.size(); i++){
        cout<<s[i]<<" ";
    }
    cout<<endl<<"Hamming distance: "<<d;
}
int main(){
    // example given in Research paper
    vector<string> V {"differ", "median", "length", "medium"};
    vector<vector<int>> S;
    S = mapping(V);
    // cout<<S[0][1];
    int d=0;
    d = CSP(S);
//     cout<<"Max Hamming Distance b/w all the strings: "<<d<<endl;
    // lets say S[0] is the closet string
    // finding the optimal answer i.e closet string among all the string
    CSP_2(S[0], S, d);
    //output: closest string, max min hamming distance
    return 0;

}
