#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
void HoanVi(int &a, int &b){
	int t = a; a = b; b = t;
}
void capPhatNgauNhien(int *&a, int n){
	int i = 0;
	a = (int*)malloc(n*sizeof(int));
	if (a == NULL){
		free(a);
	}
	else{
		while (i<n)
			a[i++] = rand() % (n + 1);
	}
}
void XuatMang(int *a, int n){
	for (int i = 0; i < n; i++){
		printf("%d\t", a[i]);
	}
	printf("\n");
}
void InsertionSort(int a[], int n, double &sosanh, double &gan){
	for (int i = 1; i<n; i++)
	{
		int x = a[i], pos = i - 1; gan++;
		while (pos >= 0 && a[pos] > x)
		{
			a[pos + 1] = a[pos];
			pos--;
			sosanh++;
			gan++;
		}
		a[pos + 1] = x; sosanh++; gan++;
	}
}
void BubbleSort(int a[], int n, double &sosanh, double &gan){
	for (int i = 0; i<n - 1; i++){
		for (int j = n - 1; j>i; j--){
			if (a[j] < a[j - 1]){
				HoanVi(a[j], a[j - 1]);
				gan += 3;
			}
			sosanh++;
		}
	}
}
void ShakerSort(int a[], int n, double &sosanh, double &gan){
	int l = 0, r = n - 1, k = n - 1, j;

	while (l<r)
	{
		j = r;
		while (j>l)
		{
			if (a[j] < a[j - 1])
			{
				HoanVi(a[j], a[j - 1]);
				k = j;
				gan += 3;
			}
			sosanh++;
			j--;
		}
		l = k;
		j = l;
		while (j<r)
		{
			if (a[j]>a[j + 1])
			{
				HoanVi(a[j], a[j + 1]);
				k = j;
				gan += 3;
			}
			sosanh++;
			j++;
		}
		r = k;
	}
}
void ShellSort(int* a, int n, double &sosanh, double &gan){
	int h = 1, X, i, j, c = 0;
	while (h <= n / 3)
		h = h * 3 + 1;
	while (h > 0){
		for (i = h; i < n; i++){
			X = a[i];
			j = i;
			gan++;
			while (a[j - h] > X && j > h - 1){
				a[j] = a[j - h];
				j -= h;
				gan++;
				sosanh++;
			}
			sosanh++;
			a[j] = X;
			gan++;
		}
		h = (h - 1) / 3;
		c++;
	}
}
void QuickSort(int a[], int l, int r, double &sosanh, double &gan){
	int i = l, j = r, x = a[(l + r) / 2]; gan++;
	do {
		while (a[i] < x){
			sosanh++;
			i++;
		}
		sosanh++;
		while (a[j] > x){
			sosanh++;
			j--;
		}
		sosanh++;
		if (i <= j){
			HoanVi(a[i], a[j]); gan += 3;
			i++; j--;
		}
	} while (i < j);
	if (l < j)
		QuickSort(a, l, j, sosanh, gan);
	if (i < r)
		QuickSort(a, i, r, sosanh, gan);
}
void Merge(int a[], int left, int mid, int right, double &sosanh, double &gan){
	int *temp; 
	int i = left; 
	int j = mid + 1; 
	temp = new int[right - left + 1]; 
	for (int k = 0; k <= right - left; k++){
		if (a[i] < a[j]){
			temp[k] = a[i]; gan++;
			i++;
		}
		else{
			temp[k] = a[j]; gan++;
			j++;
		}
		sosanh++;
		if (i == mid + 1){
			while (j <= right){
				k++;
				temp[k] = a[j]; gan++;
				j++;
			}
			break;
		}
		if (j == right + 1){
			while (i <= mid){
				k++;
				temp[k] = a[i]; gan++;
				i++;
			}
			break;
		}
	}
	for (int k = 0; k <= right - left; k++){
		a[left + k] = temp[k]; gan++;
	}
	delete temp;
}
void MergeSort(int a[], int left, int right, double &sosanh, double &gan){
	if (right > left){
		int mid;
		mid = (left + right) / 2;
		MergeSort(a, left, mid,sosanh,gan);
		MergeSort(a, mid + 1, right, sosanh, gan);
		Merge(a, left, mid, right, sosanh, gan);
	}
}
void heapify(int arr[], int n, int i, double &sosanh, double &gan){
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && arr[l] > arr[largest])
		largest = l;
	if (r < n && arr[r] > arr[largest])
		largest = r;
	sosanh += 2;
	if (largest != i){
		HoanVi(arr[i], arr[largest]); gan += 3;
		heapify(arr, n, largest, sosanh, gan);
	}
}
void HeapSort(int arr[], int n, double &sosanh, double &gan){
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i, sosanh, gan);
	for (int i = n - 1; i >= 0; i--){
		HoanVi(arr[0], arr[i]); gan += 3;
		heapify(arr, i, 0, sosanh, gan);
	}
}
int getMax(int arr[], int n, double &sosanh, double &gan){
	int mx = arr[0]; gan++;
	for (int i = 1; i < n; i++){
		if (arr[i] > mx){
			mx = arr[i]; gan++;
		}
		sosanh++;
	}
	return mx;
}
void countSort(int arr[], const int n, int exp, double &sosanh, double &gan){
	int * output = (int*)malloc(n*sizeof(int));
	int i, count[10] = { 0 };
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = n - 1; i >= 0; i--){
		output[count[(arr[i] / exp) % 10] - 1] = arr[i]; gan++;
		count[(arr[i] / exp) % 10]--;
	}
	for (i = 0; i < n; i++){
		arr[i] = output[i]; gan++;
	}
	free(output);
}
void RadixSort(int arr[], int n, double &sosanh, double &gan){
	int m = getMax(arr, n, sosanh, gan);
	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(arr, n, exp, sosanh, gan);
}
void CopyDuLieu(int* a, int* &b, const int n){
	b = (int*)malloc(n*sizeof(int));
	for (int i = 0; i < n; i++){
		b[i] = a[i];
	}
}

int main(){
	int *insertionsort, *bubblesort, *shakersort, *shellsort, *quicksort, *mergesort, *heapsort, *radixsort;
	int n;
	double thoigian, sosanh, gan;
	clock_t start_t, end_t;
	printf("Nhap so phan tu can cap phat ngau nhien: ");  scanf("%d", &n);
	capPhatNgauNhien(insertionsort, n); // Cấp phát DL gốc 1 lần

	sosanh = gan = 0;
	CopyDuLieu(insertionsort, bubblesort, n); //Copy Dữ liệu gốc trước khi sắp xếp
	printf("----------\tInsertionSort\t------------\n\n");
	start_t = clock();
	InsertionSort(insertionsort, n, sosanh, gan);
	//XuatMang(insertionsort, n);
	end_t = clock();
	thoigian = (float)(end_t - start_t) * 1000000 / CLOCKS_PER_SEC;
	printf("So phep so sanh:%.0lf\nSo phep gan:\t%.0lf\nThoi gian:\t%.1f microsecond\n\n", sosanh, gan, thoigian);
	free(insertionsort); //Giải phóng DL sau khi sắp xếp xong

	sosanh = gan = 0;
	CopyDuLieu(bubblesort, shakersort, n); //Copy Dữ liệu gốc trước khi sắp xếp
	printf("----------\tBubbleSort\t------------\n\n");
	start_t = clock();
	BubbleSort(bubblesort, n, sosanh, gan);
	//XuatMang(bubblesort, n);
	end_t = clock();
	thoigian = (float)(end_t - start_t) * 1000000 / CLOCKS_PER_SEC;
	printf("So phep so sanh:%.0lf\nSo phep gan:\t%.0lf\nThoi gian:\t%.1f microsecond\n\n", sosanh, gan, thoigian);
	free(bubblesort); //Giải phóng DL sau khi sắp xếp xong

	sosanh = gan = 0;
	CopyDuLieu(shakersort, shellsort, n); //Copy Dữ liệu gốc trước khi sắp xếp
	printf("----------\tShakerSort\t------------\n\n");
	start_t = clock();
	ShakerSort(shakersort, n, sosanh, gan);
	//XuatMang(shakersort, n);
	end_t = clock();
	thoigian = (float)(end_t - start_t) * 1000000 / CLOCKS_PER_SEC;
	printf("So phep so sanh:%.0lf\nSo phep gan:\t%.0lf\nThoi gian:\t%.1f microsecond\n\n", sosanh, gan, thoigian);
	free(shakersort); //Giải phóng DL sau khi sắp xếp xong

	sosanh = gan = 0;
	CopyDuLieu(shellsort, quicksort, n); //Copy Dữ liệu gốc trước khi sắp xếp
	printf("----------\tShellSort\t------------\n\n");
	start_t = clock();
	ShellSort(shellsort, n, sosanh, gan);
	//XuatMang(shellsort, n);
	end_t = clock();
	thoigian = (float)(end_t - start_t) * 1000000 / CLOCKS_PER_SEC;
	printf("So phep so sanh:%.0lf\nSo phep gan:\t%.0lf\nThoi gian:\t%.1f microsecond\n\n", sosanh, gan, thoigian);
	free(shellsort); //Giải phóng DL sau khi sắp xếp xong

	sosanh = gan = 0;
	CopyDuLieu(quicksort, mergesort, n); //Copy Dữ liệu gốc trước khi sắp xếp
	printf("----------\tQuickSort\t------------\n\n");
	start_t = clock();
	QuickSort(quicksort, 0, n-1, sosanh, gan);
	//XuatMang(quicksort, n);
	end_t = clock();
	thoigian = (float)(end_t - start_t) * 1000000 / CLOCKS_PER_SEC;
	printf("So phep so sanh:%.0lf\nSo phep gan:\t%.0lf\nThoi gian:\t%.1f microsecond\n\n", sosanh, gan, thoigian);
	free(quicksort); //Giải phóng DL sau khi sắp xếp xong
	
	sosanh = gan = 0;
	CopyDuLieu(mergesort, heapsort, n); //Copy Dữ liệu gốc trước khi sắp xếp
	printf("----------\tMergeSort\t------------\n\n");
	start_t = clock();
	MergeSort(mergesort, 0, n - 1, sosanh, gan);
	//XuatMang(mergesort, n);
	end_t = clock();
	thoigian = (float)(end_t - start_t) * 1000000 / CLOCKS_PER_SEC;
	printf("So phep so sanh:%.0lf\nSo phep gan:\t%.0lf\nThoi gian:\t%.1f microsecond\n\n", sosanh, gan, thoigian);
	free(mergesort); //Giải phóng DL sau khi sắp xếp xong
	
	sosanh = gan = 0;
	CopyDuLieu(heapsort, radixsort, n); //Copy Dữ liệu gốc trước khi sắp xếp
	printf("----------\tHeapSort\t------------\n\n");
	start_t = clock();
	HeapSort(heapsort, n, sosanh, gan);
	//XuatMang(heapsort, n);
	end_t = clock();
	thoigian = (float)(end_t - start_t) * 1000000 / CLOCKS_PER_SEC;
	printf("So phep so sanh:%.0lf\nSo phep gan:\t%.0lf\nThoi gian:\t%.1f microsecond\n\n", sosanh, gan, thoigian);
	free(heapsort); //Giải phóng DL sau khi sắp xếp xong

	sosanh = gan = 0;
	printf("----------\tRadixSort\t------------\n\n");
	start_t = clock();
	RadixSort(radixsort, n, sosanh, gan);
	//XuatMang(radixsort, n);
	end_t = clock();
	thoigian = (float)(end_t - start_t) * 1000000 / CLOCKS_PER_SEC;
	printf("So phep so sanh:%.0lf\nSo phep gan:\t%.0lf\nThoi gian:\t%.1f microsecond\n\n", sosanh, gan, thoigian);
	free(radixsort); //Giải phóng DL sau khi sắp xếp xong

	return 0;
}