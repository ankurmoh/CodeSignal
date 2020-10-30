std::string amendTheSentence(std::string s) {
int i=0,len=s.length(),j;
string temp = "",res="";
while(i<len)
{
    if((s[i]>='a') && (s[i]<='z'))
    {
        temp = s[i];
        j=i+1;
        while((j<len) && (s[j]>='a') && (s[j]<='z'))
        {
            temp=temp+s[j];
            j++;
        }
        res=res+temp + " ";
        i=j;
        temp = "";
    }
    if((s[i]>='A')&&(s[i]<='Z'))
    {
        j=i+1;
        temp = s[i]+32;
        while((j<len) && (s[j]>='a') && (s[j]<='z'))
        {
            temp=temp+s[j];
            j++;
        }
        res=res+temp+" ";
        temp="";
        i=j;
    }
}
return res.substr(0,res.length() - 1);
}
