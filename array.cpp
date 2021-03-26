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


int main() {
    int N = 7;
    int arr[] = {7, 1, 2, 3, 4, 5, 21};
//    cout << search(arr, 6, N);
//    for (int i = 0; i < N; i++)
//        cout << arr[i]<<endl;
//    cout << N;
//    print(arr,N);
    // cout << insertanywhere(arr,2,10,N)<<endl;
//    deleting(arr,N,2);
//    print(arr,N);
    cout << secondlargest(arr, N);
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
    int countzero;
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] != 0) {
            arr[count] = arr[i];
            if (i != 0)
                arr[i] = 0;
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