class Solution {
public:
static const long long MOD=1000000007;

long long power(long long a, long long b, long long mod){
    long long res=1;
    a%=mod;
    while(b>0){
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
    int numberOfSets(int n, int k) {
        int N = n+k-1;
        vector<long long> fact(N+1), inv_fact(N+1);

        fact[0]=1;
        for(int i=1; i<=N; i++) fact[i]=fact[i-1]*i%MOD;

        inv_fact[N]=power(fact[N], MOD-2, MOD);
        for(int i=N; i>0; i--) inv_fact[i-1]=inv_fact[i]*i%MOD;

        int r=2*k;
        if(r>N) return 0;

        long long ans=fact[N]*inv_fact[r]%MOD*inv_fact[N-r]%MOD;
        return (int)ans;
    }
};