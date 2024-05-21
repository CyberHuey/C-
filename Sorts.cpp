#include "Sorts.h"
#include "WindowsStopWatch.h"

using namespace std;

WindowsStopwatch time1a, time1b, time1c;
WindowsStopwatch time2a, time2b, time2c;
WindowsStopwatch time3a, time3b, time3c;
WindowsStopwatch time4a, time4b, time4c;
WindowsStopwatch time5a, time5b, time5c;
WindowsStopwatch time6a, time6b, time6c;
WindowsStopwatch time7a, time7b, time7c;
WindowsStopwatch time8a, time8b, time8c;
WindowsStopwatch time9a, time9b, time9c;
WindowsStopwatch time10a, time10b, time10c;

void insertion::sort(vector<int>& asc, vector<int>& des, vector<int>& ran, int size)
{
	cout << "--- Insertion Sort ---";
	// Ascending vector
	time1a.start();
	int i = 0, key = 0, j = 0;
	for (i = 1; i < size; i++)
	{
		key = asc[i];
		j = i - 1;
		// Move elements of vector that are greater than key,
		// to one position ahead of their current position
		while (j >= 0 && asc[j] > key)
		{
			asc[j + 1] = asc[j];
			j = j - 1;
		}
		asc[j + 1] = key;
	}
	time1a.stop();

	// Descending vector
	time1b.start();
	i = 0, key = 0, j = 0;
	for (i = 1; i < size; i++)
	{
		key = des[i];
		j = i - 1;
		// Move elements of vector that are greater than key,
		// to one position ahead of their current position
		while (j >= 0 && des[j] > key)
		{
			des[j + 1] = des[j];
			j = j - 1;
		}
		des[j + 1] = key;
	}
	time1b.stop();

	// Random vector
	time1c.start();
	i = 0, key = 0, j = 0;
	for (i = 1; i < size; i++)
	{
		key = ran[i];
		j = i - 1;
		// Move elements of vector that are greater than key,
		// to one position ahead of their current position
		while (j >= 0 && ran[j] > key)
		{
			ran[j + 1] = ran[j];
			j = j - 1;
		}
		ran[j + 1] = key;
	}
	time1c.stop();
	cout << endl << "Ascending: " << time1a.getTime() << endl;
	cout << "Descending: " << time1b.getTime() << endl;
	cout << "Random: " << time1c.getTime() << endl;
}

void selection::sort(vector<int>& asc, vector<int>& des, vector<int>& ran, int size)
{
	std::cout << "--- Selection Sort ---";
	// Ascending vector
	time2a.start();
	int i, j, min_idx;
	i = 0, j = 0, min_idx = 0;
	// One by one move boundary of unsorted subarray
	for (i = 0; i < size - 1; i++)
	{
		// Find the minimum element in unsorted array  
		min_idx = i;
		for (j = i + 1; j < size; j++)
			if (asc[j] < asc[min_idx])
				min_idx = j;

		// Swap the found minimum element with the first element  
		swap(&asc[min_idx], &asc[i]);
	}
	time2a.stop();

	// Descending vector
	time2b.start();
	i = 0, j = 0, min_idx = 0;
	// One by one move boundary of unsorted subarray
	for (i = 0; i < size - 1; i++)
	{
		// Find the minimum element in unsorted array  
		min_idx = i;
		for (j = i + 1; j < size; j++)
			if (des[j] < des[min_idx])
				min_idx = j;

		// Swap the found minimum element with the first element  
		swap(&des[min_idx], &des[i]);
	}
	time2b.stop();

	// Random vector
	time2c.start();
	i = 0, j = 0, min_idx = 0;
	// One by one move boundary of unsorted subarray
	for (i = 0; i < size - 1; i++)
	{
		// Find the minimum element in unsorted array  
		min_idx = i;
		for (j = i + 1; j < size; j++)
			if (ran[j] < ran[min_idx])
				min_idx = j;

		// Swap the found minimum element with the first element  
		swap(&ran[min_idx], &ran[i]);
	}
	time2c.stop();
	cout << endl << "Ascending: " << time2a.getTime() << endl;
	cout << "Descending: " << time2b.getTime() << endl;
	cout << "Random: " << time2c.getTime() << endl;
}

void selection::swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubble::sort(vector<int>& asc, vector<int>& des, vector<int>& ran, int size)
{
	std::cout << "--- Bubble Sort ---";
	// Ascending vector
	time3a.start();
	int i, j;
	i = 0, j = 0;
	for (i = 0; i < size - 1; i++)
		// Last i elements are already in place  
		for (j = 0; j < size - i - 1; j++)
			if (asc[j] > asc[j + 1])
				swap(&asc[j], &asc[j + 1]);
	time3a.stop();

	// Descending vector
	time3b.start();
	i = 0, j = 0;
	for (i = 0; i < size - 1; i++)
		// Last i elements are already in place  
		for (j = 0; j < size - i - 1; j++)
			if (des[j] > des[j + 1])
				swap(&des[j], &des[j + 1]);
	time3b.stop();

	// Random vector 
	time3c.start();
	i = 0, j = 0;
	for (i = 0; i < size - 1; i++)
		// Last i elements are already in place  
		for (j = 0; j < size - i - 1; j++)
			if (ran[j] > ran[j + 1])
				swap(&ran[j], &ran[j + 1]);
	time3c.stop();
	cout << endl << "Ascending: " << time3a.getTime() << endl;
	cout << "Descending: " << time3b.getTime() << endl;
	cout << "Random: " << time3c.getTime() << endl;
}

void bubble::swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubbleFlag::sort(vector<int>& asc, vector<int>& des, vector<int>& ran, int size)
{
	std::cout << "--- Bubble (w/Flag) Sort ---";
	// Ascending vector
	time4a.start();
	int i, temp, comps, sorted = 0; // sorted in initially false
	i = 0, temp = 0, comps = 0;
	comps = size - 1;
	while (!sorted) // comps reduces on each pass
	{
		sorted = 1; // set true for each pass
		for (i = 0; i < comps; i++)
		{
			if (asc[i] > asc[i + 1])
			{
				temp = asc[i];
				asc[i] = asc[i + 1];
				asc[i + 1] = temp;
				sorted = 0; // not yet sorted
			}
		}
	}
	time4a.stop();

	// Descending vector
	time4b.start();
	i = 0, temp = 0, comps = 0, sorted = 0;
	comps = size - 1;
	while (!sorted) // comps reduces on each pass
	{
		sorted = 1; // set true for each pass
		for (i = 0; i < comps; i++)
		{
			if (des[i] > des[i + 1])
			{
				temp = des[i];
				des[i] = des[i + 1];
				des[i + 1] = temp;
				sorted = 0; // not yet sorted
			}
		}
	}
	time4b.stop();

	// Random vector
	time4c.start();
	i = 0, temp = 0, comps = 0, sorted = 0;
	comps = size - 1;
	while (!sorted) // comps reduces on each pass
	{
		sorted = 1; // set true for each pass
		for (i = 0; i < comps; i++)
		{
			if (ran[i] > ran[i + 1])
			{
				temp = ran[i];
				ran[i] = ran[i + 1];
				ran[i + 1] = temp;
				sorted = 0; // not yet sorted
			}
		}
	}
	time4c.stop();
	cout << endl << "Ascending: " << time4a.getTime() << endl;
	cout << "Descending: " << time4b.getTime() << endl;
	cout << "Random: " << time4c.getTime() << endl;
}


void heapsort::sort(vector<int>& asc, vector<int>& des, vector<int>& ran, int size)
{
	// Ascending
	time5a.start();
	// Build heap (rearrange array) 
	for (int i = size / 2 - 1; i >= 0; i--)
		heapify(asc, size, i);

	// One by one extract an element from heap 
	for (int i = size - 1; i > 0; i--)
	{
		// Move current root to end 
		swap(asc[0], asc[i]);

		// call max heapify on the reduced heap 
		heapify(asc, i, 0);
	}
	time5a.stop();

	// Descending
	time5b.start();
	// Build heap (rearrange array) 
	for (int i = size / 2 - 1; i >= 0; i--)
		heapify(des, size, i);

	// One by one extract an element from heap 
	for (int i = size - 1; i > 0; i--)
	{
		// Move current root to end 
		swap(des[0], des[i]);

		// call max heapify on the reduced heap 
		heapify(des, i, 0);
	}
	time5b.stop();

	// Random
	time5c.start();
	// Build heap (rearrange array) 
	for (int i = size / 2 - 1; i >= 0; i--)
		heapify(ran, size, i);

	// One by one extract an element from heap 
	for (int i = size - 1; i > 0; i--)
	{
		// Move current root to end 
		swap(ran[0], ran[i]);

		// call max heapify on the reduced heap 
		heapify(ran, i, 0);
	}
	time5c.stop();
	cout << endl << "Ascending: " << time5a.getTime() << endl;
	cout << "Descending: " << time5b.getTime() << endl;
	cout << "Random: " << time5c.getTime() << endl;
}


void heapsort::heapify(vector<int>& vec, int size, int root)
{
	int largest = root; // Initialize largest as root 
	int l = 2 * root + 1; // left = 2*i + 1 
	int r = 2 * root + 2; // right = 2*i + 2 

	// If left child is larger than root 
	if (l < size && vec[l] > vec[largest])
		largest = l;

	// If right child is larger than largest so far 
	if (r < size && vec[r] > vec[largest])
		largest = r;

	// If largest is not root 
	if (largest != root)
	{
		// Swap
		int temp;
		temp = vec[root];
		vec[root] = vec[largest];
		vec[largest] = temp;

		// Recursively heapify the affected sub-tree 
		heapify(vec, size, largest);
	}
}

void mergesort::sort(vector<int>& asc, vector<int>& des, vector<int>& ran, int size)
{
}

long mergesort::mergesort1(vector<int>& vec, int low, int high)
{
	time6a.start();
	int mid;
	if (low < high) {
		// divide the array at mid and sort independently using merge sort
		mid = (low + high) / 2;
		mergesort1(vec, low, mid);
		mergesort1(vec, mid + 1, high);
		// merge or conquer sorted arrays
		merge(vec, low, high, mid);
	}
	time6a.stop();
	return time6a.getTime();
}

long mergesort::mergesort2(vector<int>& vec, int low, int high)
{
	time6b.start();
	int mid;
	if (low < high) {
		// divide the array at mid and sort independently using merge sort
		mid = (low + high) / 2;
		mergesort2(vec, low, mid);
		mergesort2(vec, mid + 1, high);
		// merge or conquer sorted arrays
		merge(vec, low, high, mid);
	}
	time6b.stop();
	return time6b.getTime();
}

long mergesort::mergesort3(vector<int>& vec, int low, int high)
{
	time6c.start();
	int mid;
	if (low < high) {
		// divide the array at mid and sort independently using merge sort
		mid = (low + high) / 2;
		mergesort3(vec, low, mid);
		mergesort3(vec, mid + 1, high);
		// merge or conquer sorted arrays
		merge(vec, low, high, mid);
	}
	time6c.stop();
	return time6c.getTime();
}

void mergesort::merge(vector<int>& vec, int low, int high, int mid)
{
	int i, j, k, c[1000];
	i = low;
	k = low;
	j = mid + 1;
	while (i <= mid && j <= high) {
		if (vec[i] < vec[j]) {
			c[k] = vec[i];
			k++;
			i++;
		}
		else {
			c[k] = vec[j];
			k++;
			j++;
		}
	}
	while (i <= mid) {
		c[k] = vec[i];
		k++;
		i++;
	}
	while (j <= high) {
		c[k] = vec[j];
		k++;
		j++;
	}
	for (i = low; i < k; i++) {
		vec[i] = c[i];
	}
}

void quicksort::sort(vector<int>& asc, vector<int>& des, vector<int>& ran, int size)
{

}

long quicksort::quick1(vector<int>& vec, int low, int high)
{
	time7a.start();
	// Create an auxiliary stack 
	int stack[4000];

	// initialize top of stack 
	int top = -1;

	// push initial values of l and h to stack 
	stack[++top] = low;
	stack[++top] = high;

	// Keep popping from stack while is not empty 
	while (top >= 0) {
		// Pop h and l 
		high = stack[top--];
		low = stack[top--];

		// Set pivot element at its correct position 
		// in sorted array 
		int p = partition(vec, low, high);

		// If there are elements on left side of pivot, 
		// then push left side to stack 
		if (p - 1 > low) {
			stack[++top] = low;
			stack[++top] = p - 1;
		}

		// If there are elements on right side of pivot, 
		// then push right side to stack 
		if (p + 1 < high) {
			stack[++top] = p + 1;
			stack[++top] = high;
		}
	}
	time7a.stop();
	return time7a.getTime();
}

long quicksort::quick2(vector<int>& vec, int low, int high)
{
	time7b.start();
	// Create an auxiliary stack 
	int stack[4000];

	// initialize top of stack 
	int top = -1;

	// push initial values of l and h to stack 
	stack[++top] = low;
	stack[++top] = high;

	// Keep popping from stack while is not empty 
	while (top >= 0) {
		// Pop h and l 
		high = stack[top--];
		low = stack[top--];

		// Set pivot element at its correct position 
		// in sorted array 
		int p = partition(vec, low, high);

		// If there are elements on left side of pivot, 
		// then push left side to stack 
		if (p - 1 > low) {
			stack[++top] = low;
			stack[++top] = p - 1;
		}

		// If there are elements on right side of pivot, 
		// then push right side to stack 
		if (p + 1 < high) {
			stack[++top] = p + 1;
			stack[++top] = high;
		}
	}
	time7b.stop();
	return time7b.getTime();
}

long quicksort::quick3(vector<int>& vec, int low, int high)
{
	time7c.start();
	// Create an auxiliary stack 
	int stack[4000];

	// initialize top of stack 
	int top = -1;

	// push initial values of l and h to stack 
	stack[++top] = low;
	stack[++top] = high;

	// Keep popping from stack while is not empty 
	while (top >= 0) {
		// Pop h and l 
		high = stack[top--];
		low = stack[top--];

		// Set pivot element at its correct position 
		// in sorted array 
		int p = partition(vec, low, high);

		// If there are elements on left side of pivot, 
		// then push left side to stack 
		if (p - 1 > low) {
			stack[++top] = low;
			stack[++top] = p - 1;
		}

		// If there are elements on right side of pivot, 
		// then push right side to stack 
		if (p + 1 < high) {
			stack[++top] = p + 1;
			stack[++top] = high;
		}
	}
	time7c.stop();
	return time7c.getTime();
}

int quicksort::partition(vector<int>& vec, int low, int high)
{
	int pivot = vec[high]; // pivot  
	int i = (low - 1); // Index of smaller element  

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot  
		if (vec[j] < pivot)
		{
			i++; // increment index of smaller element  
			swap(&vec[i], &vec[j]);
		}
	}
	swap(&vec[i + 1], &vec[high]);
	return (i + 1);
}

void quicksort::swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void radixsort::sort(vector<int>& asc, vector<int>& des, vector<int>& ran, int size)
{

}

long radixsort::radix1(vector<int>& vec, int size)
{
	time8a.start();
	// Find the maximum number to know number of digits 
	int m = getMax(vec, size);

	// Do counting sort for every digit. Note that instead 
	// of passing digit number, exp is passed. exp is 10^i 
	// where i is current digit number 
	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(vec, size, exp);

	time8a.stop();
	return time8a.getTime();
}

long radixsort::radix2(vector<int>& vec, int size)
{
	time8b.start();
	// Find the maximum number to know number of digits 
	int m = getMax(vec, size);

	// Do counting sort for every digit. Note that instead 
	// of passing digit number, exp is passed. exp is 10^i 
	// where i is current digit number 
	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(vec, size, exp);

	time8b.stop();
	return time8b.getTime();
}

long radixsort::radix3(vector<int>& vec, int size)
{
	time8c.start();
	// Find the maximum number to know number of digits 
	int m = getMax(vec, size);

	// Do counting sort for every digit. Note that instead 
	// of passing digit number, exp is passed. exp is 10^i 
	// where i is current digit number 
	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(vec, size, exp);

	time8c.stop();
	return time8c.getTime();
}

void radixsort::countSort(vector<int>& vec, int size, int exp)
{
	int output[1000]; // output array 
	int i, count[10] = { 0 };

	// Store count of occurrences in count[] 
	for (i = 0; i < size; i++)
		count[(vec[i] / exp) % 10]++;

	// Change count[i] so that count[i] now contains actual 
	//  position of this digit in output[] 
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Build the output array 
	for (i = size - 1; i >= 0; i--) {
		output[count[(vec[i] / exp) % 10] - 1] = vec[i];
		count[(vec[i] / exp) % 10]--;
	}

	// Copy the output array to arr[], so that arr[] now 
	// contains sorted numbers according to current digit 
	for (i = 0; i < size; i++)
		vec[i] = output[i];
}

int radixsort::getMax(vector<int>& vec, int size)
{
	int mx = vec[0];
	for (int i = 1; i < size; i++)
	{
		if (vec[i] > mx)
			mx = vec[i];
	}	
	return mx;
}

void smoothsort::sort(vector<int>& asc, vector<int>& des, vector<int>& ran, int size)
{
}

void countingsort::sort(vector<int>& asc, vector<int>& des, vector<int>& ran, int size)
{
}

long countingsort::countsort1(std::vector<int>& vec)
{
	time10a.stop();
	int max = getMax(vec, vec.size());
	int min = getMin(vec, vec.size());
	int range = max - min + 1;

	vector<int> count(range), output(vec.size());
	for (int i = 0; i < vec.size(); i++)
		count[vec[i] - min]++;

	for (int i = 1; i < count.size(); i++)
		count[i] += count[i - 1];

	for (int i = vec.size() - 1; i >= 0; i--) {
		output[count[vec[i] - min] - 1] = vec[i];
		count[vec[i] - min]--;
	}

	for (int i = 0; i < vec.size(); i++)
		vec[i] = output[i];
	time10a.stop();
	return time10a.getTime();
}

long countingsort::countsort2(std::vector<int>& vec)
{
	time10b.stop();
	int max = getMax(vec, vec.size());
	int min = getMin(vec, vec.size());
	int range = max - min + 1;

	vector<int> count(range), output(vec.size());
	for (int i = 0; i < vec.size(); i++)
		count[vec[i] - min]++;

	for (int i = 1; i < count.size(); i++)
		count[i] += count[i - 1];

	for (int i = vec.size() - 1; i >= 0; i--) {
		output[count[vec[i] - min] - 1] = vec[i];
		count[vec[i] - min]--;
	}

	for (int i = 0; i < vec.size(); i++)
		vec[i] = output[i];
	time10b.stop();
	return time10b.getTime();
}

long countingsort::countsort3(std::vector<int>& vec)
{
	time10c.stop();
	int max = getMax(vec, vec.size());
	int min = getMin(vec, vec.size());
	int range = max - min + 1;

	vector<int> count(range), output(vec.size());
	for (int i = 0; i < vec.size(); i++)
		count[vec[i] - min]++;

	for (int i = 1; i < count.size(); i++)
		count[i] += count[i - 1];

	for (int i = vec.size() - 1; i >= 0; i--) {
		output[count[vec[i] - min] - 1] = vec[i];
		count[vec[i] - min]--;
	}

	for (int i = 0; i < vec.size(); i++)
		vec[i] = output[i];
	time10c.stop();
	return time10c.getTime();
}

int countingsort::getMax(vector<int>& vec, int size)
{
	int mx = vec[0];
	for (int i = 1; i < size; i++)
	{
		if (vec[i] > mx)
			mx = vec[i];
	}
	return mx;
}

int countingsort::getMin(vector<int>& vec, int size)
{
	int mx = vec[0];
	for (int i = 1; i < size; i++)
	{
		if (vec[i] < mx)
			mx = vec[i];
	}
	return mx;
}


