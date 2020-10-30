int euclid(int a,int b)
{
    if(b == 0)
        return a;
    return euclid(b,a%b);
}



std::vector<int> simplifyRational(int numerator, int denominator) {
int flag=0;
if((numerator<0) && (denominator<0))
    flag = 0;
else if((numerator<0) || (denominator<0))
    flag =1;
vector<int>res;
if(numerator == 0)
{
    res.push_back(numerator);
    res.push_back(1);
    return res;
}
numerator = abs(numerator);
denominator = abs(denominator);
if(numerator == denominator)
{
    if(flag == 1)
        res.push_back(-1);
    else
        res.push_back(1);
    res.push_back(1);
    return res;
}
int gcd = euclid(numerator,denominator);
if(flag == 1)
    res.push_back(-numerator/gcd);
else
    res.push_back(numerator/gcd);
res.push_back(denominator/gcd);
return res;
}
