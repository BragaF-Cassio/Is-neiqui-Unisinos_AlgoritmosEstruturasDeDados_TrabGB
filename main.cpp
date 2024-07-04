//Includes
#include <iostream>
#include <math.h>
#include <chrono>
#include <vector>
#include <algorithm>
#include <random>
#include <iterator>

using namespace std;
typedef chrono::high_resolution_clock Clock;

//Defines
#define EXEC_NUM 10
#define ITER_MULT 10

//Functions
unsigned long long timeMeasCalc();

void bubbleSort(int arr[], int n);

void insertionSort(int arr[], int n);

void selectionSort(int arr[], int n);

void heapify(int arr[], int N, int i);
void heapSort(int arr[], int N);

int shellSort(int arr[], int n);

void merge(int array[], int const left, int const mid,
           int const right);
void mergeSort(int array[], int const begin, int const end);

int partition_r(int arr[], int low, int high);
int partition(int arr[],int low,int high);
void quickSort(int arr[],int low,int high);

template <class T> void printArray(T arr[], int size);

//Arrays
unsigned long long execTime[EXEC_NUM];

//Enums
enum sortTypes {
    e_bubbleSort = 1,
    e_insertionSort,
    e_selectionSort,
    e_heapSort,
    e_shellSort,
    e_mergeSort,
    e_quickSort,

    e_first = e_bubbleSort,
    e_last = e_quickSort+1
};

//Vars

int main()
{
    sortTypes type = e_bubbleSort;
    string strType = "";

    auto start_time = Clock::now();
    auto end_time = Clock::now();

    int arrSize = 64;

    for(int z = ITER_MULT-1; z < ITER_MULT; z++) {

        arrSize = 128*pow(2, z);

        cout << "\nItera com " << arrSize << " itens:\n";

    int *arr = new int[arrSize];
    int *arrAux = new int[arrSize];

    /*//Array em ordem
    for(int i = 0; i < arrSize; i++) {
        arr[i] = i;
    }*/

    /*//Array Invertido
    for(int i = 0; i < arrSize; i++) {
        arr[i] = arrSize-i;
    }*/

    /*
    //Array random sem repetidos
    for(int i = 0; i < arrSize; i++) {
        arr[i] = i;
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    // shuffle
    std::shuffle(arr, arr + arrSize, gen);
    */

    //Array random com repeticoes
    srand(time(0)); 
    for(int i = 0; i < arrSize; i++) {
        //Garante que pelo menos 1/4 dos numeros gerados sao repetidos
        arr[i] = (arrSize/4) + rand()%(arrSize-(arrSize/4));
    }

    for(type = e_first; type < e_last; type=sortTypes(type+1)) {

    switch (type)
    {
        case e_bubbleSort:
            strType = "Bubble Sort";
            break;

        case e_insertionSort:
            strType = "Insertion Sort";
            break;

        case e_selectionSort:
            strType = "Selection Sort";
            break;

        case e_heapSort:
            strType = "Heap Sort";
            break;
        
        case e_shellSort:
            strType = "Shell Sort";
            break;

        case e_mergeSort:
            strType = "Merge Sort";
            break;

        case e_quickSort:
            strType = "Quick Sort";
            break;

        default:
            break;
    }

    for(int i = 0; i < EXEC_NUM; i++){
        start_time = Clock::now();

        // Copy first array to second array
        copy(arr, arr + arrSize, arrAux);

        //Codigo a ser medido
        switch (type)
        {
            case e_bubbleSort:
                bubbleSort(arrAux, arrSize);
                break;

            case e_insertionSort:
                insertionSort(arrAux, arrSize);
                break;

            case e_selectionSort:
                selectionSort(arrAux, arrSize);
                break;

            case e_heapSort:
                heapSort(arrAux, arrSize);
                break;
            
            case e_shellSort:
                shellSort(arrAux, arrSize);
                break;

            case e_mergeSort:
                mergeSort(arrAux, 0, arrSize-1);
                break;

            case e_quickSort:
                quickSort(arrAux, 0, arrSize-1);
                break;

            default:
                break;
        }
        

        end_time = Clock::now();

        execTime[i] = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
    }

    //printArray(arr, arrSize);
    //printArray(arrAux, arrSize);
    //printArray(execTime, EXEC_NUM);

    cout << arrSize << "->" << strType << ": " << fixed << timeMeasCalc() << " ns\n";

    }

    delete [] arr;
    delete [] arrAux;

    }

    return 0;
}

unsigned long long timeMeasCalc() {
    int j = 0;
    long double xMeas = 0;
    long double sVar = 0;
    unsigned long long meas = 0;

    for(int i = 0; i < EXEC_NUM; i++){
        xMeas += execTime[i];
    }
    xMeas /= EXEC_NUM;

    //cout << fixed << xMeas << " media\n";

    for(int i = 0; i < EXEC_NUM; i++){
        sVar += pow(((long double)execTime[i] - xMeas), 2);
    }
    sVar = sqrt(sVar/(EXEC_NUM-1));

    //cout << fixed << sVar << " desvio padrao\n";

    for(int i = 0; i < EXEC_NUM; i++){
        
        if(execTime[i] >= (xMeas - sVar) && execTime[i] <= (xMeas + sVar)) {
            //Dentro do desvio
            //cout << (i+1) << ": " << execTime[i] << "\n";
            meas += execTime[i];
            j++;
        }
    }

    if(j > 1) {
        meas /= j;
    }

    return meas;
}

// Function to print an array 
template <class T> void printArray(T arr[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        cout <<" "<< arr[i]; 

    cout << "\n";
} 

// An optimized version of Bubble Sort 
void bubbleSort(int arr[], int n) { 
    bool isUnsorted; 
    do { 
        isUnsorted = false; 
        for (int i = 0; i < (n - 1); i++) { 
            if (arr[i] > arr[i + 1]) { 
                isUnsorted = true; 
                for (; i < (n - 1); i++) { 
                    if (arr[i] > arr[i + 1]) { 
                        swap(arr[i], arr[i + 1]); 
                    } 
                } 
            } 
        } 
    } while (isUnsorted); 
} 

// Function to sort an array using
// insertion sort
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1],
        // that are greater than key, 
        // to one position ahead of their
        // current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function for Selection sort
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    // One by one move boundary of
    // unsorted subarray
    for (i = 0; i < n - 1; i++) {

        // Find the minimum element in
        // unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        // Swap the found minimum element
        // with the first element
        if (min_idx != i)
            swap(arr[min_idx], arr[i]);
    }
}

// To heapify a subtree rooted with node i
// which is an index in arr[].
// n is size of heap
void heapify(int arr[], int N, int i)
{

    // Initialize largest as root
    int largest = i;

    // left = 2*i + 1
    int l = 2 * i + 1;

    // right = 2*i + 2
    int r = 2 * i + 2;

    // If left child is larger than root
    if (l < N && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest
    // so far
    if (r < N && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected
        // sub-tree
        heapify(arr, N, largest);
    }
}

// Main function to do heap sort
void heapSort(int arr[], int N)
{

    // Build heap (rearrange array)
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);

    // One by one extract an element
    // from heap
    for (int i = N - 1; i > 0; i--) {

        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

/* function to sort arr using shellSort */
int shellSort(int arr[], int n)
{
    // Start with a big gap, then reduce the gap
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted 
        for (int i = gap; i < n; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];
 
            // shift earlier gap-sorted elements up until the correct 
            // location for a[i] is found
            int j;            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
             
            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
    return 0;
}

// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(int array[], int const left, int const mid,
           int const right)
{
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    // Create temp arrays
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

// Generates Random Pivot, swaps pivot with
// end element and calls the partition function
int partition_r(int arr[], int low, int high)
{
    // Generate a random number in between
    // low .. high
    srand(time(NULL));
    int random = low + rand() % (high - low);
 
    // Swap A[random] with A[high]
    swap(arr[random], arr[high]);
 
    return partition(arr, low, high);
}

int partition(int arr[],int low,int high)
{
  //choose the pivot
  
  int pivot=arr[high];
  //Index of smaller element and Indicate
  //the right position of pivot found so far
  int i=(low-1);
  
  for(int j=low;j<=high-1;j++)
  {
    //If current element is smaller than the pivot
    if(arr[j]<pivot)
    {
      //Increment index of smaller element
      i++;
      swap(arr[i],arr[j]);
    }
  }
  swap(arr[i+1],arr[high]);
  return (i+1);
}

// The Quicksort function Implement
           
void quickSort(int arr[],int low,int high)
{
  // when low is less than high
  if(low<high)
  {
    // pi is the partition return index of pivot
    
    int pi=partition_r(arr,low,high);
    
    //Recursion Call
    //smaller element than pivot goes left and
    //higher element goes right
    quickSort(arr,low,pi-1);
    quickSort(arr,pi+1,high);
  }
}