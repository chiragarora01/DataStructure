#include <iostream>

using namespace std;

int search(int arr[], int x, int N);

int insertanywhere(int arr[], int pos, int x, int N);

int deleting(int arr[], int N, int pos);

int largest(int arr[], int N);

void print(int arr[], int N);

int secondlargest(int arr[], int N);

int movezerostoend(int arr[], int N);

int secondlargestwithoutlargest(int arr[], int N);

void leftrotatebyd_nd(int arr[], int d,int N);

void leftrotatebyd_arr(int arr[], int d,int N);

void reverse(int arr[],int low,int high);

void leftrotatebyd_best(int arr[], int d,int N);

void leaderinAnArray_n2(int arr[],int N);

void leaderinAnArray_n(int arr[],int N);

int maxdiff_n2(int arr[],int N);

int maxdiff_n(int arr[],int N);

int main() {
    int N = 7;
    int arr[] = {2, 3, 10, 6, 4, 8, 1};
//    cout << search(arr, 6, N);
//    for (int i = 0; i < N; i++)
//        cout << arr[i]<<endl;
//    cout << N;
//    print(arr,N);
    // cout << insertanywhere(arr,2,10,N)<<endl;
//    deleting(arr,N,2);
//    print(arr,N);
 //   cout << secondlargest(arr, N);
//    leftrotatebyd_best(arr,3,N);
    print(arr,N);
    //leaderinAnArray_n(arr,N);
    cout <<maxdiff_n(arr,N);
    cout <<maxdiff_n2(arr,N);
    return 0;
}

int search(int arr[], int x, int N) {
    for (int i = 0; i < N; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

int insertanywhere(int arr[], int pos, int x, int N) {
    int z = pos - 1;
    for (int i = N - 1; i >= z; i--) {
        arr[i + 1] = arr[i];
    }
    arr[z] = x;
    return N + 1;
}

void print(int arr[], int N) {
    for (int i = 0; i < N; i++)
        cout << arr[i] << "   ";
    cout << endl;
}

int deleting(int arr[], int N, int pos) {
    int z = pos - 1;
    for (int i = pos; i < N - 1; i++) {
        arr[i] = arr[i + 1];
    }
}

int largest(int arr[], int N) {
    int temp = 0;
    for (int i = 1; i < N; i++) {
        if (arr[i] > arr[temp])
            temp = i;
    }
    return temp;
}

int secondlargest(int arr[], int N) {
    int large = largest(arr, N);
    int res = -1;
    for (int i = 0; i < N; i++) {
        if (arr[i] != arr[large]) {
            if (res == -1)
                res = i;
            else if (arr[i] > arr[res])
                res = i;
        }
    }
    return res;
}

int secondlargestwithoutlargest(int arr[], int N) {
    int res = -1;
    int largest = 0;
    for (int i = 1; i < N; i++) {
        if (arr[i] > arr[largest]) {
            res = largest;
            largest = i;
        } else if (arr[i] < arr[largest]) {
            if (res == -1) {
                res = i;
            } else if (arr[i] > arr[res])
                res = i;
        }
    }
}


int movezerostoend(int arr[], int N)     //4,5,0,0,7,0,8,0
{
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] != 0) {
            swap(arr[count],arr[i]);
            count++;
        }
    }
}

void reverse(int arr[], int N) {
    int low = 0;
    int high = N - 1;
    while (low < high) {
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
        low++;
        high--;
    }
}

void Lrorate(int arr[],int N)
{
    int temp=arr[0];
    for(int i=1;i<N;i++)
    {
        arr[i-1]=arr[i];
    }
    arr[N-1]=temp;
}

void leftrotatebyd_nd(int arr[], int d,int N)
{
    for(int i=0;i<d;i++)
    {
        Lrorate(arr,N);
    }
}

void leftrotatebyd_arr(int arr[], int d,int N)
{
    int temp[d];
    for(int i=0;i<d;i++)
    {
        temp[i]=arr[i];
    }

    for(int i=d;i<N;i++)
    {
        arr[i-d]=arr[i];
    }
    for(int i=0;i<d;i++)
    {
        arr[N-d+i]=temp[i];
    }
}

void leftrotatebyd_best(int arr[], int d,int N)
{
    reverse(arr,0,d-1);
    reverse(arr,d,N-1);
    reverse(arr,0,N-1);
}

void reverse(int arr[],int low,int high)
{
    while(low<high)
    {
        swap(arr[low++],arr[high--]);
    }
}

void leaderinAnArray_n2(int arr[],int N)
{
    for(int i=0;i<N;i++)
    {
        bool flag=false;
        for(int j=i+1;j<N;j++)
        {
            if (arr[j]>=arr[i])
            {
                flag=true;
                break;
            }
        }
        if (!flag)
        {
            cout << arr[i]<<"  ";
        }
    }
}


void leaderinAnArray_n(int arr[],int N)
{
    int leader =arr[N-1];
    cout << leader<<"   ";
    for(int i=N-2;i>=0;i--)
    {
        if(arr[i]>leader)
        {
            leader = arr[i];
            cout << leader<<"   ";
        }
    }
}

int maxdiff_n2(int arr[],int N)
{
    int res=arr[1]-arr[0];
    for(int i=0;i<N;i++)
    {
        for(int j=i+1;j<N;j++)
        {
            res = max(res,arr[j]-arr[i]);
        }
    }
    return res;
}

int maxdiff_n(int arr[],int N)
{
    int res=arr[1]-arr[0];
    int minval=arr[0];

    for(int i=1;i<N;i++)
    {
        res = max(res,arr[i]-minval);
        minval=min(minval,arr[i]);
    }
    return res;
}