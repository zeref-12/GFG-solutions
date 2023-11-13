//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{
    private:
    void insertAtBottom(stack<int> &s,int num)
    {
        if(s.empty()) {s.push(num);return ;}
        
        int n = s.top();
        s.pop();
        
        insertAtBottom(s,num);
        s.push(n);
    }
    
    
    public:
    void clonestack(stack<int> &s, stack<int>& cloned)
    {
        if(s.empty()) return ;
        
        int num = s.top();
        s.pop();
        clonestack(s,cloned);
        insertAtBottom(s,num);
        
        while(!s.empty()){
            cloned.push(s.top());
            s.pop();
        }
        
         
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int arr[N];
        stack<int> st;
        vector<int> copy;
        for(int i = 0; i < N; i++){
            cin >> arr[i];
            st.push(arr[i]);
            copy.push_back(arr[i]);
        }
        
        reverse(copy.begin(), copy.end());
        
        Solution ob;
        stack<int> cloned;
        ob.clonestack(st,cloned);
        vector<int> check;
        while(cloned.size())
        {
            check.push_back(cloned.top());
            cloned.pop();
        }
        
        int flag = 0;
        if(check!=copy)
            flag = 1;
        
        cout<<1-flag<<endl;
    }
    return 0; 
} 

// } Driver Code Ends