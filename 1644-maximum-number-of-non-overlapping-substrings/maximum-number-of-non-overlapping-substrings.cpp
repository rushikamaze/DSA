class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n=s.size();
        vector<int> first(26, -1), last(26, -1);

        for(int i=0; i<n; i++){
            int c=s[i]-'a';
            if(first[c]==-1) first[c]=i;
            last[c]=i;
        }
        vector<pair<int, int>> intervals;

        for(int i=0; i<n; i++){
            int c=s[i]-'a';
            if(first[c]!=i) continue;

            int start=i;
            int end=last[c];
            int j=i;
            bool valid=true;
            while(j<=end){
                int cj=s[j]-'a';
                if(first[cj]<start){
                    valid=false;
                    break;
                }
                if(last[cj]>end) end=last[cj];
                j++;
            }
            if (valid) intervals.push_back({start, end});
        }
        sort(intervals.begin(), intervals.end(), [](const pair<int,int>& a, const pair<int,int>& b){
            if(a.second!=b.second) return a.second<b.second;
            return a.first>b.first;
        });
        vector<string> result;
        int prevEnd=-1;
        for(auto& pr :intervals){
            int start=pr.first, end=pr.second;
            if(start>prevEnd){
                result.push_back(s.substr(start, end-start+1));
                prevEnd=end;
            }
        }
        return result;
    }
};