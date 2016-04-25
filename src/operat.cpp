float abs(float a)
{
    if(a<=0)
        return -a;
    return a;
}
int max(int a,int b)
{
    if(a>=b)
        return a;
    return b;
}
int min(int a,int b)
{
    if(a>=b)
        return b;
    return a;
}
bool fuhao(float a,float b)
{
    if(a<=0&&b<=0)
        return true;
    if(a>=0&&b>=0)
        return true;
    return false;
}
