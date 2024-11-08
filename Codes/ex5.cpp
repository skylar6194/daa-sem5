/*Sort a given set of elements using the Quick sort method and determine the time required to sort the elements.
Repeat the experiment for different values of n, the number of elements in the list to be sorted.
The elements can be read from a file or can be generated using the random number generator.*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to swap two elements
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// Function to partition the array
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot element
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Function to implement Quick Sort
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

// Function to print the array
void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to generate random numbers
void RandomNumbers(int arr[], int size)
{
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100; // generate random numbers between 0 and 99
    }
}

int main()
{
    int n; // number of elements
    cout << "Enter the number of elements: ";
    cin >> n;

    int *arr = new int[n];

    // Ask the user whether to input numbers or generate random numbers
    cout << "Do you want to (1) input numbers or (2) generate random numbers? ";
    int choice;
    cin >> choice;

    if (choice == 1)
    {
        cout << "Enter " << n << " numbers: ";
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
    }
    else if (choice == 2)
    {
        RandomNumbers(arr, n);
    }

    // Print the original array
    cout << "Original array: ";
    printArr(arr, n);

    // Start timer
    clock_t start = clock();

    // Call Quick Sort
    quickSort(arr, 0, n - 1);

    // Stop timer
    clock_t end = clock();

    // Print the sorted array
    cout << "Sorted array: ";
    printArr(arr, n);

    // Calculate and print the time required
    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    cout << "Time taken: " << time_taken << " seconds" << endl;

    return 0;
}