//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string s)
{
    int count = 0;
    int mismatched = 0;
    for(int i =0;i<s.size();i++)
    {
        if(s[i] == '{') count++;
        else{
            if(count == 0) {
                mismatched++;
                count++;
            }
            else count-- ;
        }
    }
    if(count %2 != 0) return -1;
    mismatched += count /2; 
    return mismatched;
    
   
}
