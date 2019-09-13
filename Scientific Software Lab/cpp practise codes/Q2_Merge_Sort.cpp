#include <iostream>

using namespace std;

void merge(int *,int *,int,int,int *);
void mergesort(int[],int);
int main()
{
    int taken[] = {1,4,12,0,2,9,3,-89};
    mergesort(taken,8);
    for(int i=0;i<7;i++)
        cout << taken[i] << endl;

}

void mergesort(int arr[],int size)
{
    int arr3[size];
    int mid;
    if(size < 2)
        return;
    else
    {
        mid = size /2;
        mergesort(arr,mid);
        mergesort(arr+mid,size - mid);
        merge(arr,arr+mid,mid,size-mid,arr3);
        for(int i =0;i<size;i++)
        {
            arr[i]=arr3[i];
        }
    }
}

void merge(int* arr1,int* arr2,int first,int second,int * arr3)
{
    int k=0,i=0,j=0;
    while(i<first && j<second)
    {
        if(arr1[i]>arr2[j])
            arr3[k++]= arr2[j++];
        else
            arr3[k++]= arr1[i++];
    }
    while(i<first)
    {
        arr3[k++]= arr1[i++];
    }
    while(j<second)
    {
        arr3[k++]= arr2[j++];
    }

}





