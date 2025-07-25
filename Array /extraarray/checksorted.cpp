#include<iostream>
#include<vector>
using namespace std;
void inputarr(vector<int>& arr){
    int n = arr.size();
    for(int i = 0; i < arr.size();i++) cin>>arr[i];
}
void outputarr(vector<int>& arr){
    int n = arr.size();
    for(int i = 0; i < arr.size();i++) cout<<arr[i];
}
bool checksorted(vector<int>& arr){
    //we want to check that array is sorted or not and if array is sorted after 1 time rotate then it will also be OK
    //Time complexity - O(N)
    //Space complexity - O(1)
    int count = 0;
    for(int i = 0; i < arr.size();i++){
        if(arr[i] > arr[(i+1) % arr.size()]) count++;
        if(count > 1) return false;
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    inputarr(arr);
    return 0;
}
