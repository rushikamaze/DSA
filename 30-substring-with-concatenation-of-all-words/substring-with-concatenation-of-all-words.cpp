class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        int n=s.size();
        int count=words.size();
        int L=words[0].size();
        int total=count*L;
        if(n<total)return result;

        unordered_map<string, int> need;
        for(auto& w:words) need[w]++;

        for(int off=0; off<L; off++){
            unordered_map<string, int> window;
            int left=off;
            int matched=0;

            for(int right=off; right+L<=n; right+=L){
                string w=s.substr(right, L);

                if(!need.count(w)){
                    window.clear();
                    matched=0;
                    left=right+L;
                    continue;
                }
                window[w]++;
                matched++;

                while(window[w]>need[w]){
                    string lw=s.substr(left, L);
                    window[lw]--;
                    matched--;
                    left+=L;
                }
                if(matched==count){
                    result.push_back(left);
                    string lw=s.substr(left, L);
                    window[lw]--;
                    matched--;
                    left+=L;
                }
            }
        }
        return result;
    }
};