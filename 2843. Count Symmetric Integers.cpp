class Solution {
public:
    int sum_return(int n){
        long long int temp=n;
        long long int half_1=0;
        long long int half_2=0;
        string s1=to_string(n);
        long long int size=s1.size();
        for(long long int i=0;i<size/2;i++){
            half_1+=n%10;
            n/=10;
        }
        for(long long int i=0;i<size/2;i++){
            half_2+=n%10;
            n/=10;
        }
        if(half_1==half_2){
            return temp;
        }
        else{
            return -1;
        }
    }
    int countSymmetricIntegers(int low, int high) {
        vector<long long int> res;
        for(long long int i=low;i<=high;i++){
            string s1=to_string(i);
                if(s1.size()%2!=0){
                    continue;
                }
            else if(sum_return(i)==-1){
                continue;
            }
            else{
                res.push_back(i);
            }
        }
        return res.size();
    }
};
