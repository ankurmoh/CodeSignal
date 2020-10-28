std::vector<int> minimumOnStack(std::vector<std::string> operations) {
stack<int>s,mins;
int i,n=operations.size(),num;
string temp="";
vector<int>res;
for(i=0;i<n;i++)
{
    if(operations[i]=="min")
        res.push_back(mins.top());
    else if(operations[i].substr(0,4) == "push")
    {
        num = stoi(operations[i].substr(5));
        s.push(num);
        if((mins.empty()) || (mins.top()>=num))
            mins.push(num);
    }
    else
    {
        if(mins.top() == s.top())
            mins.pop();
        s.pop();
    }
}
return res;
}
