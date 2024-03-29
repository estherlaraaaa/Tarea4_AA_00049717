//Tarea laboratorio 4
//missing number usando quicksort
//Esther Lara

#include <iostream>


#include <cstdlib>
//#include <stdc++.h>
using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; // pivote
    int i = (low - 1); // posición del primer elemento
    for (int j = low; j <= high - 1; j++)
    {
        // Si el el elemento actual es menor que el pivote
        if (arr[j] < pivot)
        {
            i++; // incrementar el index del menor elemento
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /*pi es la partición del índice, arr[p] está en el lugar correcto */
        int pi = partition(arr, low, high);
        // Ordenando separadamente los elementos antes y después de la
        // partición
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}


//funcion agregada del codigo de labo
//aca resuelvo el ejercicio
int missingNumber(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for (int i=0;i<n;i++)
            cin >> A[i];
        quickSort(A, 0, n);
        int multiplexor=2;
        for (int i=0;i<n;i++)
        {
            if (A[i]>=multiplexor)
            {
                multiplexor+=2;
            }
        }
        cout << multiplexor;
    }
    return 0;
}

int main(int argc, char** argv) {
    missingNumber();
}
