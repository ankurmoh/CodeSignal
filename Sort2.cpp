int higherVersion2(std::string ver1, std::string ver2) {
int i=0,j=0,len1 = ver1.length(), len2 = ver2.length(),k,val1,val2;
string temp1="",temp2="";
while((i<len1) && (j<len2))
{
    if((ver1[i]=='.') && (ver2[j] == '.'))
    {
        i++;
        j++;
        continue;
    }
    if((ver1[i]>='0')&&(ver1[i]<='9'))
    {
        temp1 = string(1,ver1[i]);
        k=i+1;
        while((k<len1) && (ver1[k]>='0') && (ver1[k]<='9'))
        {
            temp1=temp1+ver1[k];
            k++;
        }
        i=k;
    }
    if((ver2[j]>='0')&&(ver2[j]<='9'))
    {
        temp2 = string(1,ver2[j]);
        k=j+1;
        while((k<len2) && (ver2[k]>='0') && (ver2[k]<='9'))
        {
            temp2=temp2+ver2[k];
            k++;
        }
        j=k;
    }
    val1 = stoi(temp1);
    val2 = stoi(temp2);
    if(val1 == val2)
        continue;
    else if(val1>val2)
        return 1;
    else
        return -1;
}
return 0;
}
