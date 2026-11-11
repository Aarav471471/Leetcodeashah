class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long mn=min(need1,need2);
        long long mx=max(need1,need2);
        if(costBoth<=cost1 && costBoth<=cost2){
            return 1LL*mx*costBoth;
        }else if(costBoth<=cost1 && costBoth>=cost2){
            if(need2>=need1){
                return 1LL*(need1)*costBoth+1LL*(need2-need1)*cost2;
            }else{
                return 1LL*mx*costBoth;
            }
        }else if(costBoth<=cost2 && costBoth>=cost1){
            if(need1>=need2){
                return 1LL*(need2)*costBoth+1LL*(need1-need2)*cost1;
            }else{
                return 1LL*mx*costBoth;
            }
        }else{
           //(c1-cb)*n1+(c2)*n2>=0
           //(c1)*n1+(c2-n2)*n2>=0
           if(need1>=need2){
                return 1LL*min({1LL*costBoth*(need2)+1LL*cost1*(need1-need2),1LL*cost1*need1+1LL*cost2*need2,1LL*costBoth*need1});
           }else{
                return 1LL*min({1LL*costBoth*(1LL*need1)+1LL*cost2*(1LL*need2-1LL*need1),1LL*cost2*need2+1LL*cost1*need1,1LL*costBoth*need2});
           }
        }
        return 0;
    }
};