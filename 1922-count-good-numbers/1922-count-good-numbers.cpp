class Solution {
public:
const long long mod = 1e9+7;
long long pow(long long x,long  long n){
        if(n==0){
            return 1;
        }
        long long half = pow(x,n/2);
        if(n%2 == 0){
            return (half*half)%mod;
        }

        return (x*half*half)%mod;
    }
    int countGoodNumbers(long long n) {
        long long even = (n+1)/2;
        long long odd = n/2;
        long long evenways = pow(5,even);
        long long oddways = pow(4,odd);
        return (evenways*oddways)%mod;
    }
};