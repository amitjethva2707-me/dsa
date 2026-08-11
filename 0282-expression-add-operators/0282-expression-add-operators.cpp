class Solution {
public:
 vector<string> ans;
 void f(string num,long long target,long long index,long long value,long long prev,string expression){
    if(index == num.size()){
        if(value == target){
            ans.push_back(expression);
        }
        return;
    }
    long long curr = 0;;
    for(int i = index;i<num.size();i++){
        if(i>index && num[index] == '0'){
            break;
        }
        curr = curr*10 +(num[i]-'0');
        string s = num.substr(index,i-index+1);
        if(index == 0){
            f(num,target,i+1,curr,curr,s);
        } else {
            f(num,target,i+1,value+curr,curr,expression + "+"+ s);
            f(num,target,i+1,value-curr,-curr,expression+"-"+s);
            f(num,target,i+1,value-prev+prev*curr,prev*curr,expression +"*"+s);
        }
    }

 }
    vector<string> addOperators(string num, int target) {
        f(num,target,0,0,0,"");
        return ans;
    }
};