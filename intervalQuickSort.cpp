#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

struct IntervalType

{

    int a;

    int b;

};

void Exchange(IntervalType interArry[],int i,int j)

{

    IntervalType tmpInterval=interArry[i];

    interArry[i]=interArry[j];

    interArry[j]=tmpInterval;

    return ;

}

//将区间[oBeg,oEnd]以某区间为基准，分成[oBeg,preEnd]<[preEnd+1,postBeg-1]<[postBeg,oEnd]三个区间

void Partition(IntervalType interArr[],int oBeg,int oEnd,int &preEnd,int &postBeg)

{

    IntervalType midInterval=interArr[oEnd];

    int i=oBeg-1;

    int j=oEnd+1;

    for(int k=oBeg;k<j&&k<oEnd;k++)

    {

        if(interArr[k].b<midInterval.a)//区间k比基准区间小

        {

            i++;

            Exchange(interArr,k,i);

        }

        else if(interArr[k].a>midInterval.b)//区间k比基准区间大

        {

            j--;

            Exchange(interArr,k,j);

            k--;

        }

        else//两个区间有重叠，视作相等，取它们重叠的部分作为基准区间继续划分

        {

            midInterval.a=max(midInterval.a,interArr[k].a);

            midInterval.b=min(midInterval.b,interArr[k].b);

        }

    }

    preEnd=i;

    postBeg=j;

    return;

}

void IntervalQuickSort(IntervalType interArr[],int iBeg,int iEnd)

{

    if(iBeg>=iEnd)return;

    int preEnd,postBeg;

    //将区间[iBeg,iEnd]以某区间为基准，分成[iBeg,preEnd]<[preEnd+1,postBeg-1]< [postBeg,iEnd]三个区间
    Partition(interArr,iBeg,iEnd,preEnd,postBeg);

    IntervalQuickSort(interArr,iBeg,preEnd);

    IntervalQuickSort(interArr,postBeg,iEnd);

    return ;

}

//输出存在的符合题意的排列，同时判断我们对区间的排序结果是否正确，即是否能找到这样一个满足条件的排列。

bool PrintExitCArray(IntervalType interArray[],int n)

{

    int* c=new int[n];

    cout<<interArray[0].a<<" ";

    c[0]=interArray[0].a;

    for(int i=1;i<n;i++)

    {

        c[i]=max(c[i-1],interArray[i].a);

        if(c[i]>interArray[i].b)

        {

            cout<<"error!/n";

            return false;

        }

        cout<<c[i]<<" ";

    }

    return true;

}

int main()

{

    srand((unsigned)time(0));

    IntervalType interArray[10000];

    int n=0;

    cout<<"输入区间个数n:";

    cin>>n;

    cout<<"下面随机输入"<<n<<"个区间的起点终点a,b:"<<endl;

    for(int i=0;i<n;i++)

    {

        interArray[i].a=rand()%1000;

        interArray[i].b=rand()%1000;

        while(interArray[i].a>interArray[i].b)

        {

            interArray[i].b=rand()%1000;

        }

        cout<<interArray[i].a<<" "<<interArray[i].b<<endl;

    }

    IntervalQuickSort(interArray,0,n-1);

    cout<<"模糊排序的结果如下："<<endl;

    for(int i=0;i<n;i++)

        cout<<interArray[i].a<<" "<<interArray[i].b<<endl;

    cout<<"可能存在的排列如下："<<endl;

    if(PrintExitCArray(interArray,n))

    {

        cout<<endl<<"成功找到一个满足条件的排列。"<<endl;

    }

    else

    {

        cout<<"算法失败，存在bug。"<<endl;

    }

    return 0;

}

