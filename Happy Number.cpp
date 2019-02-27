/*************************************************
        Problem: Happy Number
        Solution: Use a hash table to record numbers that have already appeared.
        Date: 2019-2-27 9:57
*************************************************/
class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int>record;
        if(n==1) return true;
        
        while(n>0){
            int sum = 0;
            // Continuously extract the lowest bit and calculate the sum of squares
            while(n){
                sum += (n % 10) * (n % 10);
                n/=10;
            }

            if(sum == 1)
                return true;
            else if(record.find(sum)!=record.end())
                return false;
            n = sum;
            record[n] = 1;
        }
    }
};
