class Solution {
public:
    double myPow(double x, int n) {
        if (x==0.0){
            return 0.0;
        }
        if (n==0){
            return 1.0;
        }
        // be careful with the MIN_MUM: if -MIN_MUM would lead to
        // overflow
        if (n<0){
            if (n==INT_MIN){
                return x*myPow(1.0/x,-(n+1));
            }
            return myPow(1.0/x,-n);
        }
        if (n%2==0){
            return myPow(x*x,(int)n/2);
        }
        else{
            return x*myPow(x*x,(int)n/2);
        }
    }
};
