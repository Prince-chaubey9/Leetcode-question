class Solution {
public:
    int reverseBits(int n) {
        long long ans=0;
        vector<int> binary(32);
        for(int i=31; i>=0;i--){
            int rem= n%2;
            binary[i]=rem;
            n/=2;
        }
        reverse(binary.begin(),binary.end());
        long long num=1;
        for(int i=31;i>=0;i--){
            ans+=num*binary[i];
            num*=2;
        }
        return ans;
    }
};