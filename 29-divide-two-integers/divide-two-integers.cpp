class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;
        bool negative=(dividend<0)!=(divisor<0);

        long long a=llabs((long long)dividend);
        long long b=llabs((long long)divisor);

        long long quotient=0;

        for(int shift=31; shift>=0; shift--){
            if((a>>shift)>=b){
                a-=b<<shift;
                quotient+=1LL<<shift;
            }
        }
        return negative ? -quotient:quotient;
    }
};