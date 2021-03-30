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

void leftrotatebyd_nd(int arr[], int d, int N);

void leftrotatebyd_arr(int arr[], int d, int N);

void reverse(int arr[], int low, int high);

void leftrotatebyd_best(int arr[], int d, int N);

void leaderinAnArray_n2(int arr[], int N);

void leaderinAnArray_n(int arr[], int N);

int maxdiff_n2(int arr[], int N);

int maxdiff_n(int arr[], int N);

int maxProfit(int price[], int start, int end);

int even_odd_n(int arr[], int N);

int even_odd_n2(int arr[], int N);

int maxSum_n(int arr[], int N);

int maxSum_n2(int arr[], int N);

int maxConsecutive1_n2(int arr[], int N);

int getwater_n(int arr[], int N);

int getwater(int arr[], int N);

int maxProfit_n(int price[], int N);

int Majority_element(int arr[], int N);

int circularsubarray_n(int arr[], int N);

int circularsubarray_n2(int arr[], int N);

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
    print(arr, N);
    //leaderinAnArray_n(arr,N);
    cout << maxdiff_n(arr, N);
    cout << maxdiff_n2(arr, N);
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
    return 0;
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
    return res;
}


int movezerostoend(int arr[], int N)     //4,5,0,0,7,0,8,0
{
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] != 0) {
            swap(arr[count], arr[i]);
            count++;
        }
    }
    return count;
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

void Lrorate(int arr[], int N) {
    int temp = arr[0];
    for (int i = 1; i < N; i++) {
        arr[i - 1] = arr[i];
    }
    arr[N - 1] = temp;
}

void leftrotatebyd_nd(int arr[], int d, int N) {
    for (int i = 0; i < d; i++) {
        Lrorate(arr, N);
    }
}

void leftrotatebyd_arr(int arr[], int d, int N) {
    int temp[d];
    for (int i = 0; i < d; i++) {
        temp[i] = arr[i];
    }

    for (int i = d; i < N; i++) {
        arr[i - d] = arr[i];
    }
    for (int i = 0; i < d; i++) {
        arr[N - d + i] = temp[i];
    }
}

void leftrotatebyd_best(int arr[], int d, int N) {
    reverse(arr, 0, d - 1);
    reverse(arr, d, N - 1);
    reverse(arr, 0, N - 1);
}

void reverse(int arr[], int low, int high) {
    while (low < high) {
        swap(arr[low++], arr[high--]);
    }
}

void leaderinAnArray_n2(int arr[], int N) {
    for (int i = 0; i < N; i++) {
        bool flag = false;
        for (int j = i + 1; j < N; j++) {
            if (arr[j] >= arr[i]) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            cout << arr[i] << "  ";
        }
    }
}


void leaderinAnArray_n(int arr[], int N) {
    int leader = arr[N - 1];
    cout << leader << "   ";
    for (int i = N - 2; i >= 0; i--) {
        if (arr[i] > leader) {
            leader = arr[i];
            cout << leader << "   ";
        }
    }
}

int maxdiff_n2(int arr[], int N) {
    int res = arr[1] - arr[0];
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            res = max(res, arr[j] - arr[i]);
        }
    }
    return res;
}

int maxdiff_n(int arr[], int N) {
    int res = arr[1] - arr[0];
    int minval = arr[0];

    for (int i = 1; i < N; i++) {
        res = max(res, arr[i] - minval);
        minval = min(minval, arr[i]);
    }
    return res;
}

// stock buy and sell

int maxProfit(int price[], int start, int end) {
    int profit = 0;
    if (end <= start)
        return 0;
    for (int i = start; i < end; i++) {
        for (int j = i + 1; j <= end; j++) {
            if (price[j] > price[i]) {
                int curr_profit = price[j] - price[i] + maxProfit(price, start, i - 1) + maxProfit(price, j + 1, end);
                profit = max(profit, curr_profit);
            }
        }
    }
    return profit;
}

int maxProfit_n(int price[], int N) {
    int profit = 0;
    for (int i = 1; i < N; i++) {
        if (price[i] > price[i - 1]) {
            profit += price[i] - price[i - 1];
        }
    }
    return profit;
}

//trapping rain water
int getwater(int arr[], int N) {
    int res = 0;
    for (int i = 1; i < N - 2; i++) {
        int lmax = arr[i];
        for (int j = 0; j < i; j++)
            lmax = max(lmax, arr[j]);
        int rmax = arr[i];
        for (int j = i + 1; j < N; j++)
            rmax = max(rmax, arr[j]);

        res = res + (min(lmax, rmax) - arr[i]);

    }
    return res;
}

int getwater_n(int arr[], int N) {
    int res = 0;
    int lmax[N], rmax[N];
    lmax[0] = arr[0];
    for (int i = 1; i < N; i++) {
        lmax[i] = max(lmax[i - 1], arr[i]);
    }
    rmax[0] = arr[N - 1];
    for (int i = N - 2; i >= 0; i--) {
        lmax[i] = max(rmax[i + 1], arr[i]);
    }
    for (int i = 1; i < N - 1; i++) {
        res = res + (min(lmax[i], rmax[i]) - arr[i]);
    }
    return res;
}

int maxConsecutive1_n2(int arr[], int N) {
    int res = 0;
    for (int i = 0; i < N; i++) {
        int curr = 0;
        for (int j = i; j < N; j++) {
            if (arr[j] == 1)
                curr++;
            else
                break;
        }
        res = max(res, curr);
    }
    return res;
}

int maxSum_n2(int arr[], int N) {
    int res = arr[0];
    for (int i = 0; i < N; i++) {
        int curr = 0;
        for (int j = i; j < N; j++) {
            curr = curr + arr[i];
            res = max(res, curr);
        }
    }
    return res;
}

int maxSum_n(int arr[], int N) {
    int res = arr[0];
    int maxending = arr[0];
    for (int i = 0; i < N; i++) {
        maxending = max(maxending + arr[i], arr[i]);
        res = max(res, maxending);
    }
    return res;
}

int even_odd_n2(int arr[], int N) {
    int res = 1;
    for (int i = 0; i < N; i++) {
        int curr = 1;
        for (int j = i + 1; i < N; i++) {
            if (((arr[j] % 2 == 0) && (arr[j - 1] % 2 != 0)) || ((arr[j] % 2 != 0) && (arr[j - 1] % 2 == 0)))
                curr++;
            else
                break;
        }
        res = max(res, curr);
    }
    return res;
}

int even_odd_n(int arr[], int N) {
    int res = 1;
    int curr = 1;
    for (int j = 1; j < N; j++) {
        if (((arr[j] % 2 == 0) && (arr[j - 1] % 2 != 0)) || ((arr[j] % 2 != 0) && (arr[j - 1] % 2 == 0))) {
            curr++;
            res = max(res, curr);
        } else
            curr = 1;
    }
    return res;
}

int circularsubarray_n2(int arr[], int N) {
    int res = arr[0];
    for (int i = 0; i < N; i++) {
        int curr = arr[i];
        int curr_max = arr[i];
        for (int j = 1; j < N; j++) {
            int index = (i + j) % N;
            curr += arr[index];
            curr_max = max(curr_max, curr);
        }
        res = max(res, curr_max);
    }
    return res;
}

int circularsubarray_n(int arr[], int N) {
    int normal_max = maxSum_n(arr, N);
    if (normal_max < 0)
        return normal_max;
    int arr_sum = 0;
    for (int i = 0; i < N; i++) {
        arr_sum += arr[i];
        arr[i] = -arr[i];
    }
}

int Majority_element(int arr[], int N) {
    for (int i = 0; i < N; i++) {
        int curr = 0;
        for (int j = i; j < N; j++) {
            if (arr[i] == arr[j])
                curr++;
            if (curr > N / 2)
                return i;
        }
    }
    return -1;
}