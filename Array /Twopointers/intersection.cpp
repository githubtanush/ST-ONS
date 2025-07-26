#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
void inputarr(vector<int>& arr){
    int n = arr.size();
    for(int i = 0; i < arr.size();i++) cin>>arr[i];
}
void outputarr(vector<int>& arr){
    int n = arr.size();
    for(int i = 0; i < arr.size();i++) cout<<arr[i]<<" ";
}
vector<int> intersection(vector<int>& a1,vector<int> a2){
    //brute force - make one visited array in which i check who is visited or who is not 
    // and then for also the duplicate elements we say it as a visited
    //Time complexity - O(N1 * N2)
    //Space complexity - O(N2)
    //if there is no duplicae in it
    int n1 = a1.size();
    int n2 = a2.size();
    vector<bool> vis(n2,0);//visited
    vector<int> ans;
    for(int i = 0; i < n1; i++){
        for(int j = 0;j < n2 ; j++){
            if(a1[i] == a2[j] && vis[j] == 0){
                ans.push_back(a1[i]);
                vis[j] = 1;
                break;
            }
            if(a2[j] > a1[i]) break;
        }
    }
    return ans;

    //Better force - we can crete 2 unordered set in which set we insert the elements of the array from begin to end
    // Time complexity - O(n1 * n2)
    // Space complexity - O(Min(N1,N2))

    // unordered_set<int> st1(a1.begin(),a1.end());
    // unordered_set<int> st2(a2.begin(),a2.end());
    // vector<int> res;
    // for(const auto& num : st1){
    //     if(st2.find(num) != st2.end()) res.push_back(num);
    // }
    // return res;
    
    
    //Method 2 - Two pointers
    //Time complexity - O(N1 + N2)
    //Space complexity - O(N1 + N2)
    // int n1 = a1.size();
    // int n2 = a2.size();
    // int i = 0, j = 0;
    // vector<int> unionarr;
    // while(i < n1 && j < n2){
    //     if(a1[i] == a2[j]){
    //         if(unionarr.size() == 0 || unionarr.back() != a1[i]) unionarr.push_back(a1[i]);
    //         i++;
    //         j++;
    //     }
    //     else if(a1[i] < a2[j]) i++;
    //     else j++;
    // }
    // return unionarr;
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
    for(int i : intersection(a1,a2)) cout<<i<<" ";
    
    return 0;
}

