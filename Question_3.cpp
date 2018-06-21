#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;


void amount(int total,vector<int> vals){
    vector<int> ans;
    int temp;
    ans.push_back(1);
    ans.insert(ans.begin()+1,total,0);
    for(int i=0;i<vals.size();i++){
        for(int j=0;j<=total;j++){
            if(j>=vals[i]) {
                temp=ans[j-vals[i]];
                ans[j]+=temp;
            }
        }
    
    }

    cout<<ans[total]<<endl;   
    
    return;
}



int main() {
    
vector<int> a;
a.push_back(1);
a.push_back(2);
a.push_back(3);

amount(7,a);
   
return 0;
}
