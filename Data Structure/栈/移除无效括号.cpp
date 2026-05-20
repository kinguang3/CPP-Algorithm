#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for(auto i=0; i<s.size(); ++i)
        {
            if(s[i] != '(' && s[i] != ')')
            {
                continue;
            }
            else
            {
                if(s[i] == '(')st.push(i);
                else if(s[i] == ')')
                {
                    if(st.empty())
                    {
                        s[i] = -1;
                    }
                    else
                    {
                        st.pop();
                    }
                }
            }
        }
        while(!st.empty())
        {
            s[st.top()] = -1;
            st.pop();
        }
        string news;
        for(auto i=0; i<s.size(); ++i)
        {
            if(s[i] != -1)
            {
                news.push_back(s[i]);
            }
            else continue;
        }
        return news;
    }
};