class Solution {
public:
    int countPrimes(int n) {
        bool *prime = new bool[n];
        int i,j;
        int count = 0;
        for(i = 2; i < n; ++i){
            if(!prime[i]){
                count++;
                j = 2;
                while(i * j < n){
                    prime[i * j] = 1;
                    j++;
                }
            }
        }
        return count;
    }
};
