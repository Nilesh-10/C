void quick(int a[],int n,int beg,int end,int *loc)
{

    int t;
    int left,right;
    left=beg;right=end;
    *loc=beg;
    step2:
    while(a[*loc]<=a[right]&& *loc!=right)
        right--;
    if(*loc==right)
        return;
    if(a[*loc]>a[right])
    {

        t=a[*loc];
        a[*loc]=a[right];
        a[right]=t;
        *loc=right;
    }
    step3:
    while(a[*loc]>=a[left]&&*loc!=left)
        left++;
    if(*loc==left)
        return;
    if(a[*loc]<a[left])
    {

        t=a[*loc];
        a[*loc]=a[left];
        a[left]=t;
        *loc=left;
    }
    goto step2;

}
void quick_sort(int a[],int n)
{

    int beg,end,loc,top=-1;
    int lower[20],upper[20];
    if(n>1)
    {

        top++;
        lower[top]=0;
        upper[top]=n-1;
    }
    while(top!=-1)
    {
        beg=lower[top];
        end=upper[top];
        top--;
        quick(a,n,beg,end,&loc);
        if(beg<loc-1)
        {
            top++;
            lower[top]=beg;
            upper[top]=loc-1;

        }
        if(loc+1<end)
        {
            top++;
            lower[top]=loc+1;
            upper[top]=end;
        }
    }

}
int main()
{

    int a[]={44,33,11,55,77,90,40};
    quick_sort(a,7);
    for(int i=0;i<6;i++)
    {
        printf(" %d",a[i]);
    }
    return 0;
}
