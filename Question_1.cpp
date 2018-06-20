#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

string sortByString(string s,string t){
    unordered_map<char,int> a;
    for(int i=0;i<s.length();i++){
        if(a.find(s[i])!=a.end()){
            a[s[i]]++;
        }
        else{
            a[s[i]]=1;
        }
    }
    
    string ans;
    
    for(int i=0;i<t.length();i++){
        if(a.find(t[i])!=a.end()){
            int temp=a[t[i]];
            string stemp="";
            while(temp!=0){
            stemp+=t[i];
            temp--;
            }
            ans+=stemp;
        } 
    }

    return ans;
}




int main(){

//string s="weather";
//string t="therapyw";
string s="good";
string t="odg";

string ans=sortByString(s,t);


cout<<ans<<endl;



return 0;
}
