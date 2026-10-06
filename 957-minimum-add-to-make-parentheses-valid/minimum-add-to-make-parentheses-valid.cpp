class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>p,pp;
        for(auto c:s)
        {
            if(c=='(')p.push(c);
            else if(!p.empty())p.pop();
            else pp.push(c);
        }
        return p.size()+pp.size();
    }
};