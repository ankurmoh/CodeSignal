std::vector<std::string> pressingButtons(std::string buttons) {
        vector<string>res;
        string key;
        int i,len=buttons.length(),sz,sz1,j,k,dig;
        if(len==0)
            return res;
        res.push_back("");
        vector<string>mp = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        for(i=0;i<len;i++)
        {
            dig=buttons[i]-'0';
            key=mp[dig];
            if(key=="")
                continue;
            vector<string>temp;
            sz=key.length();
            sz1=res.size();
            for(j=0;j<sz;j++)
            {
                for(k=0;k<sz1;k++)
                    temp.push_back(res[k]+key[j]);
            }
            sort(temp.begin(),temp.end());
            res=temp;
        }
        //sort(res.begin(),res.end());
        return res;
}
