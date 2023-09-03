class Solution {
public:
   
    int minimumOperations(string num) {
        //string divide=longDivision(num,25);
        //string ans=multiply(divide,"25");
        vector<string> back={"00","25","50","75"};
        vector<pair<int,int>> indi;
        char take_0_1='a';
        char take_0_2='a';
        char take_25_1='a';
        char take_25_2='a';
        char take_50_1='a';
        char take_50_2='a';
        char take_75_1='a';
        char take_75_2='a';
        for(int i=0;i<num.size();i++){
            int temp1;
            int temp2;
            bool flag1=false;
            bool flag2=false;
            if(num[i]=='0'){
                temp1=i;
                flag1=true;
            }
            for(int j=i+1;j<num.size();j++){
                if(num[j]=='0'){
                    temp2=j;
                    flag2=true;
                }
            }
            if(flag1 and flag2){
                take_0_1=temp1;
                take_0_2=temp2;
            }
        }
        if(take_0_1!='a' and take_0_2!='a'){
            indi.push_back({take_0_1,take_0_2});
        }
        for(int i=0;i<num.size();i++){
            int temp1;
            int temp2;
            bool flag1=false;
            bool flag2=false;
            if(num[i]=='2'){
                temp1=i;
                flag1=true;
            }
            for(int j=i+1;j<num.size();j++){
                if(num[j]=='5'){
                    temp2=j;
                    flag2=true;
                }
            }
            if(flag1 and flag2){
                take_25_1=temp1;
                take_25_2=temp2;
            }
        }
        if(take_25_1!='a' and take_25_2!='a'){
            indi.push_back({take_25_1,take_25_2});
        }
        for(int i=0;i<num.size();i++){
            int temp1;
            int temp2;
            bool flag1=false;
            bool flag2=false;
            if(num[i]=='5'){
                temp1=i;
                flag1=true;
            }
            for(int j=i+1;j<num.size();j++){
                if(num[j]=='0'){
                    temp2=j;
                    flag2=true;
                }
            }
            if(flag1 and flag2){
                take_50_1=temp1;
                take_50_2=temp2;
            }
        }
        if(take_50_1!='a' and take_50_2!='a'){
            indi.push_back({take_50_1,take_50_2});
        }
        for(int i=0;i<num.size();i++){
            int temp1;
            int temp2;
            bool flag1=false;
            bool flag2=false;
            if(num[i]=='7'){
                temp1=i;
                flag1=true;
            }
            for(int j=i+1;j<num.size();j++){
                if(num[j]=='5'){
                    temp2=j;
                    flag2=true;
                }
            }
            if(flag1 and flag2){
                take_75_1=temp1;
                take_75_2=temp2;
            }
        }
        if(take_75_1!='a' and take_75_2!='a'){
            indi.push_back({take_75_1,take_75_2});
        }
        int ans_1=INT_MAX;
        int diff;
        //auto it:indi;
        for(auto it:indi){
            int diff=it.second-it.first-1;
            int last=num.size()-1-it.second;
            ans_1=min(ans_1,diff+last);
        }
       if(ans_1<=100){
           return ans_1;
       }
       
       else{
            int len=num.length();
           for(int i=0;i<num.length();i++){
               if(num[i]=='0'){
                   len=len-1;
               }
           }
           return len;
       }
        
    }
};
