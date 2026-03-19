class Solution {
public:
    string breakPalindrome(string palindrome) {
        if(palindrome.size() == 1) return "";
        int mid = palindrome.size() / 2;
        bool done = false;

        for(int i = 0; i < mid; ++i) 
            if(palindrome[i] != 'a') {
                palindrome[i] = 'a';
                done = true;
                break;
            }
        
        if(!done) palindrome[palindrome.size() - 1] = 'b';
            
        return palindrome;
    }
};