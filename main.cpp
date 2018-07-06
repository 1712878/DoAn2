#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define MAX 5
template <class T>
void HoanVi(T &a, T &b){
	T t = a; a = b; b = t;
}
template <class T>
void capPhatNgauNhien(T *&a, T n){
	T i = 0;
	a = (T*)malloc(n*sizeof(T));
	if (a == NULL){
		free(a);
	}
	else{
		while (i<n)
			a[i++] = rand() % (n + 1);
	}
}
template <class T>
void XuatMang(T *a, T n){
	for (T i = 0; i < n; i++){
		printf("%ld\t", a[i]);
	}
	printf("\n");
}
template <class T>
void InsertionSort(T a[], T n, T &sosanh, T &gan){
	for (T i = 1; i<n; i++) 
	{
		T x = a[i], pos = i - 1; gan++;
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
template <class T>
void BubbleSort(T *a, T n, T &sosanh, T &gan){
	for (T i = 0; i<n - 1; i++){
		for (T j = n - 1; j>i; j--){
			if (a[j] < a[j - 1]){
				HoanVi(a[j], a[j - 1]);
				gan += 3;
			}
			sosanh++;
		}
	}
}
template <class T>
void ShakerSort(T *a, T n, T &sosanh, T &gan){
	int l = 0, r = n - 1, k = n - 1, j;
	
	while (l<r)
	{
		j = r; 
		while (j>l)
		{
			if (a[j]<a[j - 1])
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
template <class T>
void ShellSort(T a[], T n, T h[], T k){     
	for (T i = 0; i < k; i++) 		             
	for (T j = h[i]; j < n; j++) 
	{
		T   x = a[j];                     
		T   l = j - h[i];
		while (l >= 0 && x < a[k])                                
		{    
			a[l + h[i]] = a[l];
			l = l - h[i];
		}
		a[l + h[i]] = x;
	}
}
template <class T>
void QuickSort(T a[], T l, T r)
{
	T i = l, j = r, x = a[(l + r) / 2];
	do {
		while (a[i] < x) i++;
		while (a[j] > x) j--;
		if (i <= j){
			HoanVi(a[i], a[j]);
			i++; j--;
		}
	} while (i < j);
	if (l < j)
		QuickSort(a, l, j);
	if (i < r)
		QuickSort(a, i, r);
}
template <class T>
void merge(T* array, T left, T mid, T right)	{

	T temp1[mid - left + 1];
	T temp2[right - mid];
	T index_array = left;

	for (T i = 0; i < mid - left + 1; i++)
		temp1[i] = array[index_array++];

	for (T i = 0; i < right - mid; i++)
		temp2[i] = array[index_array++];

	T index_temp1 = 0, index_temp2 = 0;
	index_array = left;

	while (index_temp1 <= mid - left && index_temp2 < right - mid)	{

		if (temp1[index_temp1] < temp2[index_temp2]) 	{

			array[index_array] = temp1[index_temp1];
			index_temp1++;
		}
		else	{

			array[index_array] = temp2[index_temp2];
			index_temp2++;
		}
		index_array++;
	}

	while (index_temp1 <= mid - left)	{

		array[index_array] = temp1[index_temp1];
		index_array++;
		index_temp1++;
	}

	while (index_temp2 < right - mid)	{

		array[index_array] = temp2[index_temp2];
		index_array++;
		index_temp2++;
	}
}
template <class T>
void merge_sort(T* array, T left, T right)	{

	T mid = (right + left) / 2;
	if (left < right) 	{

		merge_sort(array, left, mid);
		merge_sort(array, mid + 1, right);
		merge(array, left, mid, right);
	}
}
template <class T>
void Shift(T a[], T l, T r){
	T   x, i, j;
	i = l;   j = 2 * l;
	x = a[i - 1];
	while (j <= r)
	{
		if (j  <  r)
		if (a[j - 1]   <   a[j])       j = j + 1;
		if (a[j - 1]  <  x)	return;
		else
		{
			a[i - 1] = a[j - 1];
			a[j - 1] = x;
			i = j;
			j = 2 * i;
		}
	}
}
template <class T>
void TaoHeap(T a[], T N)
{
	T   l;
	l = N / 2;
	while (l  > 0)
	{
		Shift(a, l, N);
		l = l - 1;
	}
}
template <class T>
void HeapSort(T a[], T N)
{
	T   r;
	TaoHeap(a, N);
	r = N - 1; //gia tri thuc cua n
	while (r > 0)
	{
		HoanVi(a[0], a[r]);
		r = r - 1;
		Shift(a, 1, r + 1);
	}
}
template <class T>
void RadixSort(T *a, T n)
{
	T i, b[MAX], m = a[0], exp = 1;
	for (i = 0; i < n; i++)
	{
		if (a[i] > m)
			m = a[i];
	}
	while (m / exp > 0)
	{
		T bucket[10] = { 0 };
		for (i = 0; i < n; i++)
			bucket[a[i] / exp % 10]++;
		for (i = 1; i < 10; i++)
			bucket[i] += bucket[i - 1];
		for (i = n - 1; i >= 0; i--)
			b[--bucket[a[i] / exp % 10]] = a[i];
		for (i = 0; i < n; i++)
			a[i] = b[i];
		exp *= 10;
	}
}
template <class T>
void CopyDuLieu(T* a, T* &b, const int n){
	b = (T*)malloc(n*sizeof(T));
	for (T i = 0; i < n; i++){
		b[i] = a[i];
	}
}
int main(){
	long *insertionsort, *bubblesort, *shakersort, *shellsort, *quicksort, *mergesort, *heapsort, *radixsort;
	long n, sosanh, gan;
	float thoigian;
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
	thoigian = (float)(end_t - start_t) * 1000 / CLOCKS_PER_SEC;
	printf("So phep so sanh:%d\nSo phep gan:\t%d\nThoi gian:\t%.3f ms\n\n", sosanh, gan, thoigian);
	free(insertionsort); //Giải phóng DL sau khi sắp xếp xong

	sosanh = gan = 0;
	CopyDuLieu(bubblesort, shakersort, n); //Copy Dữ liệu gốc trước khi sắp xếp
	printf("----------\tBubbleSort\t------------\n\n");
	start_t = clock();
	BubbleSort(bubblesort, n, sosanh, gan);
	//XuatMang(bubblesort, n);
	end_t = clock();
	thoigian = (float)(end_t - start_t) * 1000 / CLOCKS_PER_SEC;
	printf("So phep so sanh:%d\nSo phep gan:\t%d\nThoi gian:\t%.3f ms\n\n", sosanh, gan, thoigian);
	free(bubblesort); //Giải phóng DL sau khi sắp xếp xong

	sosanh = gan = 0;
	//CopyDuLieu(shakersort, shellsort, n); //Copy Dữ liệu gốc trước khi sắp xếp
	printf("----------\tShakerSort\t------------\n\n");
	start_t = clock();
	ShakerSort(shakersort, n, sosanh, gan);
	//XuatMang(shakersort, n);
	end_t = clock();
	thoigian = (float)(end_t - start_t) * 1000 / CLOCKS_PER_SEC;
	printf("So phep so sanh:%d\nSo phep gan:\t%d\nThoi gian:\t%.3f ms\n\n", sosanh, gan, thoigian);
	free(shakersort); //Giải phóng DL sau khi sắp xếp xong

	return 0;
}