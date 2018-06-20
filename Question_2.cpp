#include<iostream>
#include<string>
#include<stack>
using namespace std;
string decodehelper(int a,string s){
   string ans="";
   int temp=a;
   while(a!=0) {
   for(int i=0;i<s.length();i++){
       ans+=s[i]; 
   }
   a--;
   }
   return ans; 
}

//assuming all brackets are even [ [ ] ]
// no [[ ]]]
//assuming k can be greather than 10
//all char values are  in the ASCII table
void decodeString(string s){
    if(s.length()==0)
         return;
    //since assumption the brackets are even we find the next ]
    int i;
    for(i=0;i<s.length();i++)
        if(s[i]==']')
            break;
    //now we just keep going back and constructing the string using the function for help
    int s_index=i-1;
    int size=0;//size of the substring
    string ans="";
    while(i>-1){
        
        if(s[i]=='['){
            //we found our first string inside brackets
            size=s_index-i;
            s_index=i+1;
            int ten=1;
            int val;
            i--;//pointing to the next val
            //now we just need to find the number on the left side after the [
            while(s[i]>=48 && s[i]<=57){
                val=(s[i]-48)*ten;
                ten*=10;
                i--;
            }
            //when this while loop end this means we hit a letter
            //now we can feed it into our decoder helper
            string temp=s.substr(s_index ,size)+ans;
            ans=decodehelper(val,temp );
            //ans=temp+ans;
//            cout<<ans<<endl;
       
            s_index=i;
        }
        else{
        i--;}
    }
    cout<<ans<<endl; 
    return;
}



int main(){

   // string a="4[ab]";
   string b="3[hi2[b3[a]]]"; 
    decodeString(b);
   // cout<<decodehelper(4,"ab");
return 0;
}
