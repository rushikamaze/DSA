class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int left=0, right=0;
        for(char c:s){
            if(c=='('){
                left++;
            } else if(c==')'){
                if(left>0) left--;
                else right++;
            }
        }
        vector<string> result;
        string path;
        dfs(s,0,0,left,right,path,result);
        return result;
    }
    private:
    void dfs(const string& s, int idx, int open, int leftRem, int rightRem, string& path, vector<string>& result){
        if(open<0||leftRem<0||rightRem<0) return;

        if(idx==(int)s.size()){
            if(open==0&&leftRem==0&&rightRem==0)
            result.push_back(path);
            return;
        }
        char c=s[idx];
        if(c=='('||c==')'){
            int j=idx;
            while(j<(int)s.size()&&s[j]==c) j++;
            int cnt=j-idx;

            for(int k=0; k<=cnt; k++){
                int lr=leftRem, rr=rightRem;
                if(c=='(') lr-=k; else rr-=k;
                if(lr<0||rr<0) break;

                int keep=cnt-k;
                int newOpen=open+(c=='('?keep:-keep);
                if(newOpen<0) continue;

                size_t oldLen=path.size();
                path.append(keep, c);
                dfs(s,j,newOpen, lr,rr,path,result);
                path.resize(oldLen);
            }
        } else{
            path.push_back(c);
            dfs(s,idx+1,open,leftRem,rightRem,path,result);
            path.pop_back();
        }
    }
};