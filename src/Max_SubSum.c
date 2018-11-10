//
// Created by LYM on 2018/11/4.
//
/**
 * 最大子列和问题
 */

#include <stdio.h>

#define MAX (100000+5)

int num[MAX];
int K;

int maxSubArraySum00(const int *num, int n);

int maxSubArraySum01(const int *num, int n);

int maxSubArraySum02(const int *num, int n);

int maxSubArraySum03(const int *num, int n);

int findMaxSubArray(const int *num, int low, int high);

int findMaxCrossSubArray(const int *num, int low, int mid, int high);

int max(int a, int b);

int main(void) {
//    int a = max(3, max(6, 9));
//    printf("%d\n", a);
    int i;
    int sum = 0;
    while (scanf("%d", &K) != EOF) {
        for (i = 0; i < K; i++) {
            scanf("%d", num + i);
        }
        sum = maxSubArraySum03(num, K);
        if (sum <= 0) {
            sum = 0;
        }
        printf("%d\n", sum);
    }

    return 0;
}

int maxSubArraySum00(const int *num, int n) {
    /**
     * O(n) = n^3
     * i: 起始值
     * j: 子列长度
     * k: 计算i->j的和
     */
    int i, j, k;
    int maxSum = 0;
    int sum = 0;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; j++) {
            sum = 0;
            for (k = i; k < j; k++) {
                sum += num[k];
            }
            if (sum > maxSum) {
                maxSum = sum;
            }
        }
    }
    return maxSum;
}

int maxSubArraySum01(const int *num, int n) {
    /**
     * O(n) = n^2
     * i: 起始值
     * j: 子列长度
     * k: 计算i->j的和
     */
    int i, j, k;
    int maxSum = 0;
    int sum = 0;
    for (i = 0; i < n; ++i) {
        sum = 0;
        for (j = i; j < n; j++) {
            sum += num[j];
            if (sum > maxSum) {
                maxSum = sum;
            }
        }
    }
    return maxSum;
}

int maxSubArraySum02(const int *num, int n) {
    return findMaxSubArray(num, 0, n - 1);
}

int findMaxSubArray(const int *num, int low, int high) {
    if (low == high) {
        return num[low];
    }
    int mid = (low + high) / 2;
    int leftSum = findMaxSubArray(num, low, mid);
    int rightSum = findMaxSubArray(num, mid + 1, high);
    int crossSum = findMaxCrossSubArray(num, low, mid, high);

    return max(leftSum, max(rightSum, crossSum));
}

int findMaxCrossSubArray(const int *num, int low, int mid, int high) {
    int i;
    int leftSum = 0;
    int leftMaxSum = 0;
    for (i = mid; i >= low; i--) {
        leftSum += num[i];
        if (leftSum > leftMaxSum) {
            leftMaxSum = leftSum;
        }
    }

    int rightSum = 0;
    int rightMaxSum = 0;
    for (i = mid + 1; i <= high; i++) {
        rightSum += num[i];
        if (rightSum > rightMaxSum) {
            rightMaxSum = rightSum;
        }
    }

    return leftMaxSum + rightMaxSum;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int maxSubArraySum03(const int *num, int n) {
    int sum = 0;
    int maxSum = 0;
    int i = 0;
    for (i=0; i<n; i++) {
        sum += num[i];
        if (sum > maxSum) {
            maxSum = sum;
        } else if (sum < 0) {
            sum = 0;
        }
    }
    return maxSum;
}