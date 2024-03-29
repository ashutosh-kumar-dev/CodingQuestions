//======================= by lcs ===================

// 2nd string will be reverse of the given

class Solution {
public:

   
    int longestPalindromeSubseq(string s1) {

        string s2=s1;
        reverse(s2.begin(),s2.end());

        int m= s1.length();
        int n= s2.length();
        vector<vector<int>> t(m+1,vector<int>(n+1,0));

       
 
        for(int i=1; i<m+1; i++){
            for(int j=1; j<n+1 ; j++){
                if(s1[i-1]==s2[j-1])
                     t[i][j] = 1 + t[i-1][j-1];

                else {
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
        }
        return t[m][n];
        
    }
};