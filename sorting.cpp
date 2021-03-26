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
int main()
{
    int arr[]={10,8,13,3,6,20,5,7};
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

    print(arr,N);
insertion(arr,N);
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