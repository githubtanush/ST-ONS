#include<iostream>
#include<vector>
#include<set>
using namespace std;
void inputarr(vector<int>& arr){
    int n = arr.size();
    for(int i = 0; i < arr.size();i++) cin>>arr[i];
}
void outputarr(vector<int>& arr){
    int n = arr.size();
    for(int i = 0; i < arr.size();i++) cout<<arr[i]<<" ";
}
vector<int> unionn(vector<int>& a1,vector<int> a2){
    //Method 1 - We use set to store the distinct values of different arrays
    //Time complexity - O(N1 logN + N2 logN) + O(N1 + N2)
    //Space complexity - O(N1 + N2) + O(N1 + N2);
    // set<int> st;
    // for(auto i : a1) st.insert(i);
    // for(auto j : a2) st.insert(j);
    // vector<int> ans(st.begin(),st.end());
    // return ans;
    
    //Method 2 - Two pointers
    //Time complexity - O(N1 + N2)
    //Space complexity - O(N1 + N2)
    int n1 = a1.size();
    int n2 = a2.size();
    int i = 0, j = 0;
    vector<int> unionarr;
    while(i < n1 && j < n2){
        if(a1[i] <= a2[j]){
            if(unionarr.size() == 0 || unionarr.back() != a1[i]) unionarr.push_back(a1[i]);
            i++;
        }
        else {
            if(unionarr.size() == 0 || unionarr.back() != a2[j]) unionarr.push_back(a2[j]);
            j++;
        }
    }
    while(i < n1){
        if(unionarr.size() == 0 || unionarr.back() != a1[i]) unionarr.push_back(a1[i]);
        i++;
    }
    while(j < n2){
        if(unionarr.size() == 0 || unionarr.back() != a2[j]) unionarr.push_back(a2[j]);
        j++;
    }
    return unionarr;
}
int main(){
    int n1;
    cin>>n1;
    vector<int> a1(n1);
    inputarr(a1);
    int n2;
    cin>>n2;
    vector<int> a2(n2);
    inputarr(a2);
    for(int i : unionn(a1,a2)) cout<<i<<" ";
    
    return 0;
}

