//Sort colors
#include<iostream>
#include<vector>
using namespace std;
void sortcolors(vector<int>& v){
    //Method 1 - The most basic method is :- sorting use - sort stl
    // sort(v.begin(),v.end());
    //Method 2 - count the number and then arrange it 
    //Take benefit of the less numbers count all the numbers
    // int zerocount = 0;
    // int onecount  = 0;
    // int twocount  = 0;

    // for(int i = 0; i < v.size();i++) if(v[i] == 0) zerocount++;
    // for(int i = 0; i < v.size();i++) if(v[i] == 1) onecount++;
    // for(int i = 0; i < v.size();i++) if(v[i] == 2) twocount++;


    // int index = 0;
    // while(zerocount--) v[index++] = 0;
    
    // while(onecount--)  v[index++] = 1;
    
    // while(twocount--)  v[index++] = 2;
    

    //Method 3 - Two pointers
    // int low = 0;
    // int mid = 0;
    // int high = v.size()-1;

    // while(mid <= high){
    //     if(v[mid] == 1) mid++;
    //     else if(v[mid] == 0) swap(v[low++],v[mid++]);
    //     else if(v[mid] == 2) swap(v[mid],v[high--]);
    // }

}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n ;i++) cin>>v[i];

    sortcolors(v);
    for(int i = 0;i < n ;i++) cout<<v[i]<<" ";

    return 0;
}