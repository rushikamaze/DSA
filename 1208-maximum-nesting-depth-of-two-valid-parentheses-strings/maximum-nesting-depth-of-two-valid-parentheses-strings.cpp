class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans(seq.size());
        int depth=0;
        for(int i=0; i<(int)seq.size(); i++){
            if(seq[i]=='('){
                depth++;
                ans[i]=depth%2;
            } else{
                ans[i]=depth%2;
                depth--;
            }
        }
        return ans;
    }
};