class Solution {
public:
    int reverse(int x) {
        if(x>2147483647 || x < -2147483647) return 0;
        int ret=0;
        int cnt=0;
        
        while(x!=0){
            cnt++;
            ret = ret*10 + x%10;
            x/=10;
            
            if(cnt==9 && x!=0){
                if(ret>0){
                    int cmp = 2147483647/10;
                    if(ret>cmp){
                        ret=0;
                        break;
                    }
                }else{
                    int cmp = 2147483647/10;
                    if(ret+cmp<0){
                        ret=0;
                        break;
                    }
                }
            }
        }
        return ret;
    }
};