#include <bits/stdc++.h>
using namespace std;

int hammingDist(string str1, string str2){
    int i = 0, count = 0;
    while(i!=str1.length()){
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

string CSWO(vector<string>permutations, int deld,int d,int k,string s){

    if(deld<0 or k<0) return "";

    for(int i=0;i<permutations.size();i++){
        if(hammingDist(permutations[i],s)<d) return permutations[i];
    }
    string P;
    string rset = CSWO(permutations,deld,d,k-1,s);
    if(rset.length() == 0){
        /*for(int i=0;i<s.length();i++){
            if(s[i]!=permutations[i]) P[i] =s[i];
            else P[i] = 'a';
        }
        if(P!="") return P;*/
        P="aaaa";
        return  CSWO(permutations,deld-1,d,k,s);
    
    }
    return P;
}

int main() {
    string s = "abcde";
    int deld,d,k,l;
    d = 1;
    vector<string> permutations;
    string candidiate;
    
    string x;
    cin>>x;
    int n;
    
     n=x.size();
   // cin>>n;
    string c = "y";
    string z = x;
    while(n--){
        z = z+c;
    }
    cout<<z<<endl;
   // permute(s,0,s.length()-1,permutations);
   
   // for(int i=0;i<s.length();i++){
   
      //  candidiate[i] = 'a';
   // }
   
  //  deld = hammingDist(candidiate,s);
  deld = 3;
    k=3;
    string ans = CSWO(permutations,deld,d,k,s);
    cout<<ans;
    return 0;

}
