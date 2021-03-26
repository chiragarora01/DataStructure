//
// Created by panda on 26-03-2021.
//

#include <iostream>
#include <algorithm>
using namespace std;
void print(int arr[],int N);
void bullble(int arr[],int N);
void selection (int arr[],int N);
void insertion(int arr[],int N);
void MergeTwoSortedArrray(int arr1[],int N1,int arr2[],int N2);

void mergesort(int arr[],int l,int r);
void merge(int arr[],int l,int m,int r);
int main()
{
    int arr[]={10,8,13,3,6,20,5,7};
    int arr1[]={10,15,20,40};
    int arr2[]={5,6,6,10,15};
    int arr3[]={10,15,20,40,8,11,15,22,25};
    int N=8;
//    for (int i=0;i<N;i++)
//    {
//        cout <<arr[i]<<"     ";
//    }
//    sort(arr,arr+N,greater<int>());
//    cout << endl;
//    for (int i=0;i<N;i++)
//    {
//        cout <<arr[i]<<"     ";
//    }

//    print(arr1,4);
//    cout<<endl;
//    print(arr2,5);
//insertion(arr,N);
//MergeTwoSortedArrray(arr1,4,arr2,5);
print(arr3,9);
mergesort(arr3,0,8);
}


void bullble(int arr[],int N)
{
    for(int i=0;i<N;i++)
    {
        for (int j=0;j<N-i-1;j++)
        {
            if (arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    print(arr,N);

}

void print(int arr[],int N)
{
    for (int i=0;i<N;i++)
    {
        cout <<arr[i]<<"     ";
    }
    cout <<endl;
}

void selection (int arr[],int N)
{
    for (int i=0;i<N;i++)
    {
        int min=i;
        for (int j=i+1;j<N;j++)
        {
            if (arr[min]>arr[j])
            {
                min=j;
            }
        }
    int temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
    }
    print(arr,N);
}

void insertion(int arr[],int N)
{
    for(int i=1;i<N;i++)
    {
        int key =arr[i]; //10
        int j=i-1; //0
        while( j>=0 && key < arr[j])    //8<10
        {
                arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    print(arr,N);
}

void MergeTwoSortedArrray(int arr1[],int N1,int arr2[],int N2)
{
    int first=0,second=0;
    int arr3[N1+N2];
    int j=0;
    while (first<N1 && second<N2)
    {
   //     cout << 1;
        if (arr1[first] > arr2[second])
        {
               arr3[j]=arr2[second];
               j++;
               second++;
        }

        else if (arr1[first] <= arr2[second])
        {
            arr3[j]=arr1[first];
            j++;
            first++;
        }
    }
    while (first <N1)
    {
        arr3[j]=arr1[first];
        first++;
        j++;
    }

    while (second <N2)
    {
        arr3[j]=arr1[second];
        second++;
        j++;
    }
    cout << endl;
    print(arr3,N1+N2);
}

void mergesort(int arr[],int l,int r)
{
    if (r>l)
    {
        int m = l+(r-l)/2;
        //int m=3;
        mergesort(arr,l,m);
        mergesort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

void merge(int arr[],int l,int m,int r)
{
    int N1=m-l+1,N2=r-l;
    int left[N1],right[N2];
    for (int i=0;i<N1;i++)
        left[i]=arr[i+l];
    for (int i=0;i<N1;i++)
        right[i]=arr[m+i+l];
    MergeTwoSortedArrray(left,N1,right,N2);
}