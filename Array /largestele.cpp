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
int largest(vector<int>& arr){
    sort(arr.begin(),arr.end());
    return arr[arr.size()-1];
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    inputarr(arr);
    cout<<largest(arr)<<endl;
    outputarr(arr);
    return 0;
}