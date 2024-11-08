// Project 2 
// Made By - Aryan Singh (ID - 300404053)
#include<iostream>
#include<cstdlib>
#include<chrono>
#include<cmath>
#include<queue>

#define Size 10000
int ar[Size];
int s = -1;
std::size_t T;

using namespace std;
using namespace
  std::chrono;

class Node{
public:
    int key;     //Node class for the binary heap
    Node* left;
    Node* right;
}obj;
void
shellsort (int ar[], int size)
{
  auto
    start = high_resolution_clock::now ();
  int
    i;
  int
    increment = 1;
  for (int gap = increment; gap > 0;
       gap = (9 * (pow (2, increment) - pow (2, (increment / 2))) + 1))
    {

      for (i = gap; i < size; i += 1)
    {
      int
        temp = ar[i];
      int
        j;
      for (j = i; j >= gap && ar[j - gap] > temp; j -= gap)
        ar[j] = ar[j - gap];

      ar[j] = temp;
    }
      increment++;
    }
  auto
    stop = high_resolution_clock::now ();
  auto
    duration = duration_cast < microseconds > (stop - start);

  cout << "Time taken by the algorithm was: ";
  cout << duration.count () << " Milliseconds" << endl;
}

int
partition (int ar[], int left, int right)    //partition function for quicksort
{
  int
    temp,
    j;
  int
    pivot = ar[right];        //making the last element the pivot
  int
    i = (left - 1);        // making i start from -1 because we need to increment a value after the condition for the right pivot is satisifed

  for (j = 0; j < right; j++)
    {
      if (ar[j] < pivot)    // if the element is less than the pivot on the right
    {
      i++;            //increment the value of i
      temp = ar[i];
      ar[i] = ar[j];    //swapping the value if the condition holds true
      ar[j] = temp;
    }
    }
  temp = ar[i];
  ar[i] = ar[j];        //swapping the pivot and placing it in its appropriate position after the loop has ended
  ar[j] = temp;
  return (i + 1);
}


void
quicksort (int ar[], int left, int right)
{
  int
    divide;
  if (left < right)
    {
      divide = partition (ar, left, right);        //dividing the array into two parts
      quicksort (ar, left, divide - 1);      //using recursion to sort the elements
      quicksort (ar, divide + 1, right);
    }
   
}

void
partiton2 (int ar[], int left, int right, int i, int j) //partition for dijkstra three way partition
{
  if (right - left <= 1)
    {
      if (ar[right] < ar[left])
    swap (ar[right], ar[left]);    //swapping if value of the element on right pivot is less than value on left pivot
      i = left;            //making i pointer equal to the left pivot
      j = right;           //making j pointer equal to the right pivot
      return;
    }
  int
    mid = left;
  int
    pivot = ar[right];
  while (mid <= right)
    {
      if (ar[mid] < pivot)
    swap (ar[left++], ar[mid++]);
      else if (ar[mid] == pivot)
    mid++;
      else if (ar[mid] > pivot)
    swap (ar[mid], ar[right--]);
    }
  i = left - 1;
  j = mid;
}

void
sort (int arr[], int left, int right)  //function to sort the elements to print the 100 smallest
{
  if (left >= right)        //1 or 0 elements
    return;
  int
    i = 0, j = 0;
  partiton2 (arr, left, right, i, j);
  quicksort (arr, left, i);
  quicksort (arr, j, right);
}
 

void printarray(int ar[], int n)    //function to print an                                         array
{
  for (int i = 0; i < 100; i++)
    {
      cout << ar[i] << endl;
    }
}

void printqueue()     //function to print the queue;
{
    for(std::size_t i{}; i < 100; ++i){
        cout<<ar[i]<<endl;
    if(T == 100)
        break;}
}

void enqeue()  //function to insert elements in the queue and where p is the elements going in the queue
{
    
    int numbers =rand () % 1000000 + 1;
    int minimum = 0;
     if(T == 0)
     {
         ar[0] = numbers;
         minimum = numbers;
     }
    else if(T !=0)
    {
        if(numbers <= minimum)
        {
            minimum = numbers;
            for (std::size_t m{ T}; m >= 0; --m)
                       {
                           ar[m + 1] = ar[m];
                       }
                       ar[0] = numbers;
        
        }
        else if(numbers< ar[T-1])
        {
            bool num= false;
            for(std::size_t j{}; !numbers; ++j)
            {
                if(numbers <= ar[j])
                {
                    num = true;
                    for(std::size_t mo{ T - 1 }; mo >= j; --mo)
                    {
                        ar[mo +1] = ar[mo];
                    }
                    ar[j] = numbers;
                }
            }
        }
        else if(numbers >= ar[T -1])
        {
            ar[T] = numbers;
        }
        
    }
    ++T;
    
}
    /*************************************************************************/

void heap(int arr[], int i)
{
    int node = i;               //to get index of parent node
    int leftnode = (2*i)+1;     //to get index of left node
    int rightnode= (2*i)+2;      //to get index of right node
    
    if (leftnode < Size && arr[leftnode] < arr[node])     //condition to make the heap satisfy its property
        node = leftnode;

    // Check if right child is smaller than smallest
    if (rightnode < Size && arr[rightnode] < arr[node])
        node = rightnode;

    // If smallest is not parent
    if (node != i) {
        swap(arr[i], arr[node]);

        // Recursively heapify the affected sub-tree
        heap(arr, node);
    }
}

// Function to build a Max-Heap from the given array
void buildHeap(int arr[])
{
    // Perform level order traversal
    // from last non-leaf node and heapify each node
    for (int i = Size; i >= 0; i--) {
        heap(arr, i);
    }
}

int height(int N)
{
    return ceil(log2(N+1))-1;   //formula to calculate the height of the heap
}
int computeleaves(int arr[], int n)
{
    int h = height(100);
    int totalnodes = ceil((n/pow(2,h+1)));   //function to calculate the total nodes in the heap then dividing it by 2
  
    return (totalnodes/2);
}
bool lookup(int ar[],int key)
{
    for(int i =0; i<100; i++){                      //function to look for an element in the heap
      if(key == ar[i])
      { cout<<"Element was found!";
          return true;}}
    
    return false;
        
}

bool samelevel(Node* current)
{
    return false;
}

bool descendant(Node* current, Node* node)
{
    
    return false;
}

bool isheap()
{
    return false;
}

    

int
main ()
{
    //size of the array
  int i;            //array to hold the million integers
  int n = Size;    //to get the length of the array

  for ( i = 0; i < Size; i++)
    {
      ar[i] = rand () % 1000000 + 1;
      //random one million integers stored in the array
    }
  cout << "Shellsort: " << endl;
  shellsort (ar, n);   // Implementing shell sort
  printarray (ar, n);  // Printing out the sorted array with execution Time
  cout << endl << endl << endl;
  cout << "Quicksort:" << endl;
  quicksort (ar, 0, n - 1); // Implementing quick sort
  printarray (ar, n);      // Printing out array with execution Time
  cout << endl << endl;
  cout << "Dijkstra three way partiton: " << endl;
  sort (ar, 0, n - 1);  // Implementing Dijkstra 3 way partiton
  printarray (ar, n); // Printing out array with execution Time
    cout<<endl;
    cout<<"Using priority queue on ordered array"<<endl;
    enqeue();  // enqeueing the random numbers in sorted order
    printqueue();  //Printing the queue out with execution Time
    cout<<endl;
    cout<<"Using Priority queue on Heap using array"<<endl;
    enqeue();   // enqeueing the random numbers in sorted order
    printqueue(); //Printing the queue out with execution Time
    cout<<endl;
    cout<<"Using binary heap"<<endl;  // Implementing binary heap along with
    buildHeap(ar);                    // given functions
    printarray(ar, n);
    cout<<endl;
    cout<<"Height of the tree is "<<height(100)<<endl;
    cout<<"No of leaves in the tree is"<<computeleaves(ar,n);
    cout<<endl;
    cout<<"Find no 10"<<computeleaves(ar, 10);
    
    return 0;
}
