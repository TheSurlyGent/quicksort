// T(n) -> O(n^2) : worst time
//  O(n log n) : avg
/*    
 1) Divide & conquer algortithm
 2) Recursive
 3) in-place sorting

 position p in such a way after reposition all elements in the left side should be lesser than P (sorted or unsorted)
 all elements to to the right should be greater than P


 we do that by taking the pivot 
 we begin from start 0
iterate from start to end - 1 // because pivot is at end already
compare A[i] to pivot
while comparing 
 well see : 

 for i i < end -1 i ++
    if (A[i]<= A[P])
     {
         Swap (A[i], A[pIndex])
         pIndex = pIndex + 1
      }
      Swap(A[pIndex], A[P)])

      S                 E
     0  1  2  3  4  5  6

A = [89,45,68,90,29,34,50] i = 0
     ||i               |P
     |pIndex

    [45,89,68,90,29,34,50] i = 1
     |  |i             |P
     |pIndex
     swap
    [45,89,68,90,29,34,50] i = 2
        |   |i         |P
        |pIndex
    [45,89,68,90,29,34,50] i = 3
        |     |i       |P
        |pIndex
    [45,89,68,90,29,34,50] i = 4
        |        |i    |P
        |pIndex
        swap
        //after swap increment p index
    [45,29,34,90,89,68,50] i = 5
            |        |i|P
            |pIndex
            
            end:swap pIndex with P
    [45,29,34,50,89,68,90] i = 5
               |     |i|P
               |pIndex
     
     P = pivot

     i = 0
     compare a[i]= 89 to a[P] = 50
     A[i] !<= A[P]
     increment i
     i = 1
     compare A[i] = 45 to A[P] = 50
     (since) 45 <= 50 (is true)
     Swap (A[i] = 45 with A[pIndex])
     increment pIndex to 1
     compare A[i] = 89 <= A[P] = 50
     increment i
     i = 2
     compare A[i] = 68 to A[P] = 50
     increment i
     i = 3
     compare A[i] = 90 to A[P] = 50
     increment i
     i = 4
     compare A[i] = 29 to a[P] = 50
     29<=50 T
     Swap (A[pIndex] with A[i])
     increment pIndex to 2
     compare A[i] = 89 to A[P] = 50
     pIndex always points at element bigger than Pivot
     increment i
     i = 5
     compare A[i] = 34 to a[P] = 50
     swap (a[pIndex] = 68 with a[i] = 34)
     increment pIndex to 3
     finally 
     after loop Swap A[pIndex] and A[P]

     now P is in the new location
     after partioning [45,29,34,|50|,89,68,90]
     sorted           [29,34,45,|50|,68,89,90]

     [45,29,34,50,89,68,90]
      |      |    |      |
      ________    ________
      pI     P    ""     ""
        2 new arrays, take a pivot P for each    
        take pindex and do the whole thing for them



1) select a pivot P eg: the last element
2) rearrange the list sucth that
    a[i] <= A[P] && a[i] >= A[P]
   all the elements on the left of P are smaller than P
   all the elements on the right of P are greater than P
3) exchange the A[P] with the first element of the second sub array
                Swap(A[pIndex],A[P])
4) sort the two sub_arra recursively


pseudo -code

partition(array A, start,end)
{
int P;
int pIndex;
P = end
pIndex = start
    for(i = start i < end-1, i++)
    {
        if(A[i]<=A[P])
        {
        Swap(A[i],A[pIndex])
        pIndex = pIndex+1
        }
    }
    Swap(A[P],A[pIndex])
    return pIndex;
}
quicksort(array A,int left,int right)
{
    if(left < right)
    {
    int P = partition(A,left,right)
    quicksort(array A, left,p-1)
    quicksort(array A, p +1,right)
    }
}

                 7   
              9     6
            10   3 5   8
*/

#include <iostream>
#include "eduardoaparicio_displayVector.h"
#include "eduardoaparicio_swap.h"
#include <vector>


using namespace std;

int partition(vector<int>& A,int start,int end)
{
    int P;
    int pIndex;
    P = end;
        pIndex = start;
        for (int i = start; i < end ; i++) //i <= end - 1
        {
            if (A[i] <= A[P])
            {
                swap(A[i], A[pIndex]);
                pIndex = pIndex + 1;
            }
        }
        swap(A[pIndex], A[P]);
    return pIndex;
}

void quicksort(vector <int>& A, int left, int right)
{
    if (left < right)
    {
        int P = partition( A, left, right);
        quicksort(A, left, P - 1);
        quicksort(A, P + 1, right);
    }
}


int main()
{
    
    vector<int> list = {15,1,200,999,2,3};

    displayVector(list);

    int left = 0;
    int right = (list.size()-1);

    cout << left << endl;
    cout << right << endl;
    quicksort(list, left, right);
    displayVector(list);
    cout << right << endl;





    displayVector(list);

    return 0;

    
    
   
    
    
}


