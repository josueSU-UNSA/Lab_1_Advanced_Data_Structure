#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;
// Bubble sort      OK
// Heap sort        OK
// Insertion sort   OK
// Selection sort   OK(revisar)  
// Shell sort       OK(revisar)
// Merge sort       OK
// Quick sort       OK


//------------------------------------------------------------------------
//--------------------INSTRUCTION TO COMPUTE THE TIME---------------------
//unsigned t0, t1;
//t0=clock();//Inicio del cronometro
//t1 = clock();//Final del cronometro
//double time = (double(t1-t0)/CLOCKS_PER_SEC);//calculo del tiempo en sec
//------------------------------------------------------------------------



//Bubble Sort
//-----------------------------------------------------
void bubble_sort(int * arr_num,int size){
    
    for(int i=0;i<size-1;i++){
        for (int j=0;j<size-i-1;j++){
            if(arr_num[j]>arr_num[j+1]){
                swap(arr_num[j],arr_num[j+1]);
            }
        }
    }
}
//-----------------------------------------------------

//Heap Sort
//-----------------------------------------------------
void heapify(int arr[], int N, int i){
    int largest = i;
 

    int l = 2 * i + 1;

    int r = 2 * i + 2;
 
    if (l < N && arr[l] > arr[largest])
        largest = l;

    if (r < N && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, N, largest);
    }
}

void heapSort(int arr[], int N){

    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);

    for (int i = N - 1; i > 0; i--) {

        swap(arr[0], arr[i]);
        
        heapify(arr, i, 0);
    }
}
//-----------------------------------------------------

//Insertion Sort
//-----------------------------------------------------
void insertionSort(int *arr, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++){//ESTE BUCLE NOS PERMITIRA SEGUIR EL PASO 
                            //AL INDICE EN EL QUE SE QUEDA LA ITERACION
                            //DE ESA MANERA NO ESTE AFECTADA POR LOS CAMBIOS
                            //PROPIOS DEL INSERTION SORT
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key)//CONDICION PARA HACER LOS CAMBIOS
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
//-----------------------------------------------------

//Selection Sort
//-----------------------------------------------------
void selectionSort(int arr_num[], int size){
    int min;
 
    
    for (int i = 0; i < size-1; i++){    
        min = i;
        for (int j = i+1; j < size; j++){
            if (arr_num[j] < arr_num[min]) min = j;
        }
    
        if(min!=i)swap(arr_num[min], arr_num[i]);
    }
}
//-----------------------------------------------------

//Shell sort
//-----------------------------------------------------
void shellSort(int * arr, int n){
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i];
            int j;       
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
              
            
            arr[j] = temp;
        }
    }
    
}
//-----------------------------------------------------

//Merge Sort
//-----------------------------------------------------
void merge(int array[], int cota_izq, int punto_medio, int cota_dcha)
{
    int subArray_Izq = punto_medio - cota_izq + 1;
    int subArray_Dcha = cota_dcha - punto_medio;
  
    // Let L[1....n(1)+1]  and R[1....n(2)+1] be new arrays
    int *IzqArray,*DchaArray; 
    IzqArray = new int[subArray_Izq];
    DchaArray = new int[subArray_Dcha];
  
    
    for (int i = 0; i < subArray_Izq; i++)
        IzqArray[i] = array[cota_izq + i];//+1 sobre  el pseudo
    for (int j = 0; j < subArray_Dcha; j++)
        DchaArray[j] = array[punto_medio + j+1];//+1 sobre  el pseudo
  
    int indexArraySorted = cota_izq; // Indice inicial del array unido
    int indexOfSubArray_Izq;//Indicie inicial de la primera partición
    int indexOfSubArray_Dcha; // Indicie inicial de la segunda partición
    indexOfSubArray_Izq = 0;//i=1
    indexOfSubArray_Dcha = 0;//j=1
    

    
    while (indexOfSubArray_Izq < subArray_Izq && indexOfSubArray_Dcha < subArray_Dcha) {
        if (IzqArray[indexOfSubArray_Izq] <= DchaArray[indexOfSubArray_Dcha]) {
            array[indexArraySorted] = IzqArray[indexOfSubArray_Izq];
            indexOfSubArray_Izq++;
        }
        else {
            array[indexArraySorted] = DchaArray[indexOfSubArray_Dcha];
            indexOfSubArray_Dcha++;
        }
        indexArraySorted++;
    }
    
    while (indexOfSubArray_Izq < subArray_Izq) {
        array[indexArraySorted] = IzqArray[indexOfSubArray_Izq];
        indexOfSubArray_Izq++;
        indexArraySorted++;
    }
    
    while (indexOfSubArray_Dcha < subArray_Dcha) {
        array[indexArraySorted] = DchaArray[indexOfSubArray_Dcha];
        indexOfSubArray_Dcha++;
        indexArraySorted++;
    }

}
  

void mergeSort(int array[], int begin, int  end)
{
    if(begin<end){
        int mid = (begin + end )/ 2;
        mergeSort(array, begin, mid);
        mergeSort(array, mid + 1, end);
        merge(array, begin, mid, end);
    }
    
}
void mergeSort(int* arr,int arr_size)
{
    mergeSort(arr, 0, arr_size-1);

    
}
//-----------------------------------------------------
//Quicksort
//-----------------------------------------------------
int Partition(int *A ,long int p,long int r){

    long int x=A[r];
    long int i=p-1;
    for(int j=p;j<r;j++){
        if(A[j]<=x){
            i++;
            swap(A[i],A[j]);
  
        }
        
    }
   
    swap(A[i+1],A[r]);
    
    return i+1;
}
void only_Quicksort(int *&A,int p,int r){
    if(p<r){
        int q=Partition(A,p,r);
        
        only_Quicksort(A,p,q-1);
        only_Quicksort(A,q+1,r);
    }
    
}

void Quicskort(int* A, int size){
    only_Quicksort(A,0,size-1);
}
//-----------------------------------------------------



void print_arr(int arr[],int size){
    //int size=sizeof(arr)/sizeof(arr[0]);
    for (int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}
//-------------TEST_SORT------------------------------
//----------------------------------------------------
// Bubble sort      OK
// Heap sort        OK  -
// Insertion sort   OK
// Selection sort   OK(revisar)  
// Shell sort       OK(revisar)
// Merge sort       OK
// Quick sort       OK




void change_val_arr(int *arr_to_sort,int size){
    for(int i=0;i<size;i++)arr_to_sort[i]=1;
    for(int i=0;i<size;i++)cout<<arr_to_sort[i]<<" ";
    cout<<endl;


}

void fill_arr(int *arr_input,int size){
    ifstream file_to_read;
    file_to_read.open("inputs_random.txt");

    for (int i=0;i<size;i++)file_to_read>>arr_input[i];

    file_to_read.close();
}


//----------------------------------------------------
int main_2(){
    int size=100;
    int *arr_input=new int[size];
    ifstream file_to_read;
    file_to_read.open("inputs_random.txt");
    
    for (int i=0;i<size;i++){
        
        file_to_read>>arr_input[i];
     

    }
    file_to_read.close();

    print_arr(arr_input,size);

    
     
    return 0;
}
int main(){
    

    ofstream file_excel;
    file_excel.open("Complexities_graph");

    
    int size=10000;
    int *arr_sort;
    

    

    //Getting the data from the file:
    for(;size<=1000000;size+=10000){ 
        
        arr_sort=new int[size];
        
        // Bubble sort      OK
        fill_arr(arr_sort,size);
        bubble_sort(arr_sort,size);
        
        // Heap sort        OK
        fill_arr(arr_sort,size);
        heapSort(arr_sort,size);
        
        // Insertion sort   OK
        fill_arr(arr_sort,size);
        insertionSort(arr_sort,size);
        
        // Selection sort   OK(revisar)
        fill_arr(arr_sort,size);
        selectionSort(arr_sort,size);
          
        // Shell sort       OK(revisar)
        fill_arr(arr_sort,size);
        shellSort(arr_sort,size);
        
        // Merge sort       OK
        fill_arr(arr_sort,size);
        mergeSort(arr_sort,size);
        
        // Quick sort       OK
        fill_arr(arr_sort,size);
        Quicskort(arr_sort,size);
        delete [] arr_sort;
                
    }


    


    return 0;
}