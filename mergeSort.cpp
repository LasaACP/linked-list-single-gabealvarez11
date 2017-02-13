/*template <typename T>
void merge(T* array, T* array1, T* array2)
{
	
		if(array1[i] <= array2[j])
		
}*/


#include <iostream>
using namespace std;

template <class T>
void mergeSort(T array[], int start, int stop)
{
	if(start == stop)
	{
		return;
	}
	int mid = (start + stop) / 2;
	
	mergeSort(array, start, mid);
	mergeSort(array, mid + 1, stop);
	
	int i = start;
	int j = mid + 1;
	int l = stop - start + 1;
	
	T* temp = new T[l];
	
	for(int k = 0; k < l; k++)
	{
		if (j > stop || (i <= mid && array[i] < array[j]))
		{
            temp[k] = array[i];
            i++;
        }
        
		else
		{
            temp[k] = array[j];
            j++;
        }
    }
	
    for (int k = 0, i = start ; k < l; k++, i++)
	{
        array[i]=temp[k];
    }
	
    delete temp;
}

template <class T>
void mergeSort(List* list, int start, int stop)
{
	if(start == stop)
	{
		return;
	}
	int mid = (start + stop) / 2;
	
	mergeSort(list, start, mid);
	mergeSort(list, mid + 1, stop);
	
	int i = start;
	int j = mid + 1;
	int l = stop - start + 1;
	
	List<T>* temp = new List();
	
	for(int k = 0; k < l; k++)
	{
		if (j > stop || (i <= mid && list.get(i) < list.get(j)))
		{
            temp.set(k, list.get(i));
            i++;
        }
        
		else
		{
            temp.set(k, list.get(j));
            j++;
        }
    }
	
    for (int k = 0, i = start ; k < l; k++, i++)
	{
        list.set(i, temp.get(k));
    }
	
    temp.clear();
}






int main() {
    float array[] = {1000.5,1.2,3.4,2,9,4,3,2.3,0,-5};
    int l = sizeof(array)/sizeof(array[0]);
    mergeSort(array,0,l-1);
    cout << "Result:\n";
    for (int k=0;k<l;k++){
        cout << array[k] << endl;
    }
    return 0;
}