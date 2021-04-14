#include <bits/stdc++.h>
using namespace std;

int hammingDist(string str1, string str2)
{
    int i = 0, count = 0;
    while (i<str1.length())
    {
        if (str1[i] != str2[i])
            count++;
        i++;
    }
    return count;
}

void permute(string a, int l, int r,vector<string> permutations) {
    if (l == r)
        permutations.push_back(a);
    else{
        for (int i = l; i <= r; i++){
            swap(a[l], a[i]);
 
            permute(a, l+1, r, permutations);
 
            swap(a[l], a[i]);
        }
    }
}


int main() {
   string s;
   cin>>s;
   int d;
   cin>>d;
   string tsol = s;
   int b = hammingDist(s,tsol);
    vector<string> permutations;
    permute(s,0,s.length()-1,permutations);
    int maxdis = 0;
    string ans ="";
    for(int i=0;i<s.length();i++){
        tsol+="a";
    }

    //step1 
    if(d==b){
        for(int i=0;i<permutations.size();i++){
            if(hammingDist(permutations[i],s)>maxdis){
                maxdis = hammingDist(permutations[i],s);
                ans = permutations[i];
                break;
            }
        }
    }

    else {
    //arbitary missing
    //next steps

    int l = hammingDist(s,tsol)-d;
    string r = "";

    for(int i=0;i<s.length();i++){
        if(s[i]!=tsol[i]) r[i] = s[i];
    }
    
    //guessing tsol begins:
    int mini ;
    if(r.length()<b) mini = r.length();
    else mini = b;
    if(l> mini) cout<<"NULL";
    string x,y;
    //x.length() = (l+b)/2;
    //y.length() = x.length()-l;
    string z;
    for(int i=0;i<y.length();i++){
        if(s[i]!=tsol[i]) min(s[i],tsol[i])+1;
    }

    for(int i=0;i<s.length();i++){
        if(i<z.length()) tsol[i]=z[i];
        else if(i<y.length()) tsol[i]=y[i];
        else if(i<x.length()) tsol[i] = x[i];
        else if(i<r.length()) tsol[i] = r[i];
    }

   // string ans = tsol;
    int B = min(b-x.length(),x.length()-l-y.length());
    }
    cout<<tsol<<"";
    return 0;
}
