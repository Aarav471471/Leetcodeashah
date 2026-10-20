class Solution {
public:
    int calculate(string s) {
        stack<int>nums;
        stack<char>ops;
        int num=0;
                // int mul=1;
        for(auto x:s){
            if(x=='+' || x=='-' || x=='/' ||x=='*'){
               
                    nums.push(num);
                    num=0;
                    // mul=1;
                if(x=='+'){
                    while(!ops.empty()&&(ops.top()=='*' ||ops.top()=='/' || ops.top()=='-' || ops.top()=='+')){
                        int f=nums.top();
                        nums.pop();
                        int s=nums.top();
                        nums.pop();
                        if(ops.top()=='*'){
                            nums.push(f*s);
                        }else if(ops.top()=='-'){
                            nums.push(s-f);
                        }else if(ops.top()=='+'){
                            nums.push(s+f);
                        }
                        else{
                            nums.push(s/f);
                        }
                        cout<<nums.top()<<endl;
                        ops.pop();
                    }
                    ops.push(x);
                }else if(x=='-'){
                    while(!ops.empty()&&(ops.top()=='*' ||ops.top()=='/' || ops.top()=='+' || ops.top()=='-')){
                        int f=nums.top();
                        nums.pop();
                        int s=nums.top();
                        nums.pop();
                        if(ops.top()=='*'){
                            nums.push(f*s);
                        }else if(ops.top()=='/'){
                            nums.push(s/f);
                        }else if(ops.top()=='-'){
                            nums.push(s-f);
                        }
                        else{
                            nums.push(s+f);
                        }
                        
                        ops.pop();
                    }
                    ops.push(x);
                    // cout<<ops.top();
                }
                else if(x=='/'){
                    while(!ops.empty()&&(ops.top()=='*' || ops.top()=='/')){
                        int f=nums.top();
                        nums.pop();
                        int s=nums.top();
                        nums.pop();
                        if(ops.top()=='*'){

                        nums.push(s*f);
                        }else{
                            nums.push(s/f);
                        }
                        ops.pop();
                    }
                    ops.push(x);
                }else{
                    while(!ops.empty()&&(ops.top()=='/' || ops.top()=='*')){
                        int f=nums.top();
                        nums.pop();
                        int s=nums.top();
                        nums.pop();
                        if(ops.top()=='*'){
                            nums.push(s*f);
                        }else{

                        nums.push(s/f);
                        }
                        ops.pop();
                    }
                    ops.push(x);
                
            }
        }else{
                if(isdigit(x)){
                    num=num*10+(x-'0');
                }
            }
    }
        // 11
        //-
        nums.push(num);
        while(!ops.empty()){
            int f=nums.top();
            nums.pop();
            int s=nums.top();
            nums.pop();

            if(ops.top()=='+'){
                nums.push(s+f);
            }else if(ops.top()=='-'){
                // cout<<s<<endl;
                nums.push(s-f);
            }else if(ops.top()=='*'){
                nums.push(s*f);

            }else{
                nums.push(s/f);
            }
            ops.pop();
        }
        return nums.top();
        }
    
};