int power(int a,int b)
{
    int pow=a;
    for(int i=1;i<b;i++)
    {
        pow*=a;
    }
    return pow;
}
