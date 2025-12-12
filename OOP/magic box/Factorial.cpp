int factorial(int num)
{
    int factorial=1;
    for(int i=num;i>0;i--)
    {
        factorial*=i;
    }
    return factorial;
}
