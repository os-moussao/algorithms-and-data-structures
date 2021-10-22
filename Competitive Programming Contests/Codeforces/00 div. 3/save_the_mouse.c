#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
  
    int L[n1], R[n2];
  
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
  
    i = 0; 
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
  
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
  
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
  
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int	main(void)
{
	int	T;

	scanf("%d", &T);
	while (T-- > 0)
	{
		int	n, k;

		scanf("%d%d", &n, &k);
		int arr[k];
		for (int j = 0; j < k; j++)
			scanf("%d", &arr[j]), arr[j] = n - arr[j];

		// sort arr
		mergeSort(arr, 0, k - 1);
		/*
		for (int i = 0; i < k; i++)
		{
			int sw = 0;
			for (int j = 0; j < k - i - 1; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					int tmp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = tmp;
					sw = 1;
				}
			}
			if (!sw)
				break ;
		}
		*/
		int cnt = 0;
		int sum = 0;
		while (cnt < k && sum + arr[cnt] < n)
			sum += arr[cnt++];
		printf("%d\n", cnt);
	}
}
