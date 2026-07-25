class Solution {
public:
    int maxProduct(int n) {
        int first = n%10;
        n = n/10;
        int second = n%10;
        n = n/10;
        if(second>first){
            swap(first,second);
        }
        while(n){
            int a = n%10;
            n = n/10;
            if(a>first){
                second = first;
                first = a;
            } else if(a>second){
                second = a;
            }
        }
        return first*second;
    }
};