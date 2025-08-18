#include<iostream>
#include<vector>
using namespace std;
void reversestring(vector<char>& s){
//Method 1 - brute force reverse the string and return and create one new more string
        // string str;
        // for(int i = s.size()-1; i >= 0; i--) str.push_back(s[i]);
        // for(int i = 0; i < str.size();i++) s[i] = str[i];

        //Method 2 - Use STL
        // reverse(s.begin(),s.end());

        //Method 3 - in place by using 
        int left = 0;
        int right = s.size()-1;

        while(left <= right)
            swap(s[left++],s[right--]);
}
int main(){
    vector<char> str;
    char c;
    cin>>c;
    while(c != '@'){
        str.push_back(c);
        cin>>c;
    }

    reversestring(str);
    
    for(auto it : str) cout<<it<<" ";

    return 0;
}