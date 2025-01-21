#include <iostream>
#include <vector>

// Function to perform insertion sort on a vector from index left to right
void	insertionSort(std::vector<int>& arr, int left, int right)
{
	for (int i = left + 1; i <= right; ++i)
	{
		int key = arr[i];
		int j = i - 1;
		while (j >= left && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = key;
	}
}
// Function to perform Merge Insertion Sort
void	merge(std::vector<int>& arr, int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;

	std::vector<int> L(n1);
	std::vector<int> R(n2);

	for (int i = 0; i < n1; ++i)
		L[i] = arr[left + i];
	for (int i = 0; i < n2; ++i)
		R[i] = arr[mid + 1 + i];

	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
			arr[k++] = L[i++];
		else
			arr[k++] = R[j++];
	}

	while (i < n1)
		arr[k++] = L[i++];

	while (j < n2)
		arr[k++] = R[j++];
}

// Function to merge two sorted subarrays into a single sorted array
void	mergeInsertionSort(std::vector<int>& arr, int left, int right)
{
	if (left < right)
	{
		if (right - left + 1 <= 10) // Umbral para usar Insertion Sort
			insertionSort(arr, left, right);
		else {
			int mid = left + (right - left) / 2;
			mergeInsertionSort(arr, left, mid);
			mergeInsertionSort(arr, mid + 1, right);
			merge(arr, left, mid, right);
		}
	}
}

int	main(int ac, char **av)
{
	std::vector<int> arr = {112, 11, 0, 13, 5, 6, 7, 30, 1, 29, 14, 10, 18, 9, 4};

	std::cout << "Given array is:\n";
	for (int num : arr)
		std::cout << num << " ";

	std::cout << std::endl;

	mergeInsertionSort(arr, 0, arr.size() - 1);

	std::cout << "Sorted array is:\n";
	for (int num : arr)
		std::cout << num << " ";
	std::cout << std::endl;

	return 0;
}