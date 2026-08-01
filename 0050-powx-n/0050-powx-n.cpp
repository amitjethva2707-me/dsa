class Solution {
public:
    double pow(double x,int n){
        if(n==0){
            return 1;
        }
        double half = pow(x,n/2);
        if(n%2 == 0){
            return half*half;
        }

        return x*half*half;
    }
    double myPow(double x, int n) {
        long long N = n;
        if(n<0){
            x=1/x;
          N= -N;
        }

        return pow(x,N);
    }
};