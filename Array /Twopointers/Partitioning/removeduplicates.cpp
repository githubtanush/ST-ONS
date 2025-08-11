#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;
int removeDuplicates(vector<int>& v){
    //Method1 - The brute force make the new array and the number which enter can't insert it again
//    set<int> st;
//    vector<int> ans;
//    for(int i : v) st.insert(i);
//    for(auto s : st) ans.push_back(s);
//    v = ans;
//    return ans.size();

//Method 2 - Using hashmap
// vector<int> temp;
// map<int,int> mpp;
// for(int i = 0; i < v.size();i++) if(mpp[v[i]] == 0) mpp[v[i]]++;
// for(auto i : mpp) temp.push_back(i.first);
//  v = temp;
//  return temp.size();

    //Method 3 - Using Two pointers
    int left = 0;
    int right = 1;
    while(right < v.size()){
        if(v[left] == v[right]) right++;
        else{
            left++;
            v[left] = v[right];
            right++;
        }
    }
    return left+1;
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n ;i++) cin>>v[i];
    cout<<removeDuplicates(v)<<endl;;
    for(int i = 0; i < n ;i++) cout<<v[i]<<" ";
    return 0;
}