//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    bool mapping(string s,string t)
    {
        unordered_map<char,char> map;
        for(int i=0;i<s.length();i++)
        {
            if(map.find(s[i])!=map.end()){
              if(map[s[i]]!=t[i]) return false;
            }
            else 
            map[s[i]]=t[i];
        }
        return true;
    }
    
    bool areIsomorphic(string str1, string str2)
    {
        
        if(str1.length()!=str2.length())
        return false;
        
        else
        return (mapping(str1,str2) &&mapping(str2,str1));
        
    
        
        
    }
       
};


//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends