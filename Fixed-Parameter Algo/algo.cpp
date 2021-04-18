#include<bits/stdc++.h>

using namespace std;
static int d=4;
vector<string> S={"harryisawiz",
                  "harryisaboy",
                  "harryhasowl",
                  "harrypotter",
                  "harryisgood",
                  "ronnyisawiz"};
int L=S[0].size();
int k=S.size();

void mapping(vector<vector<int>> &s,vector<string> &str){
   int i,j;
   for(i=0;i<k;i++){
      for(j=0;j<L;j++){
         s[i][j]= str[i][j]-96;
      }
   }
}

int dirtyCol(vector<vector<int>> &s){
   unsigned int r,c,count=0;
   set <int> temp;
   for(c=0;c<s[0].size();c++){
      for(r=0;r<s.size();r++){
         temp.insert(s[r][c]);
      }
      if(temp.size()>3)
         count++;
      temp.clear();
   }
   return count;
}

int hD(string str1, string str2)
{
    unsigned int i = 0, count = 0;
    while (i<str1.length())
    {
        if (str1[i] != str2[i])
            count++;
        i++;
    }
    return count;
}

//we assume this is invoked with a minimal distance parameter d
string CSd(string s,int deld)
{
   int i,j,dist,flag=1;
   vector<int> P;
   if(deld<0)
      return "";
   for(i=0;i<k;i++){
      dist=hD(s,S[i]);
      if(dist>deld+d)
         return "";
      else if(dist>d){
         j=i;
         flag=0;
         break;
      }
   }
   if(flag==1)
      return s;
   for(i=0;i<L;i++){
      if (s[i] != S[j][i])
         P.push_back(i);
   }
   string s_dash=s;
   string s_ret;
   for(i=0;i<=d;i++){
      s_dash[P[i]]=S[j][P[i]];
      s_ret=CSd(s_dash,deld-1);
      if(!s_ret.empty())
         return s_ret;
   }
   return "";

}

void ClosestString(vector<vector<int>> &mat){
   int deld=d;
   string ans;
   ans=CSd(S[0],deld);
   if(ans.empty())
      cout<<"No Such string exists!!"<<endl;
   else{
      cout<<ans<<endl;
      cout<<"For d="<<d<<endl;
   }

}

int main()
{
    int dirty;
    vector<vector<int>> mat(k,vector<int> (L,0));
    mapping(mat,S);
    dirty=dirtyCol(mat);
    if(dirty>=k*d)
       cout<<"No Closest String found!!"<<endl;
    else{
       ClosestString(mat);
    }
    return 0;
}
