#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include<array>

void fillArray(int* arr, int size, int inputMode) {
    for (int i = 0; i < size; i++) {
        switch (inputMode) {
        case 1: std::cin >> arr[i]; break;     
        case 2: arr[i] = rand() % 100 - 25;
        std::cout<<arr[i]<<" ";
        break; 
        default: std::cout<<"Неверный выбор";
        std::exit(1);
        }
    }
    std::cout<<"\n";
}

void process(int* arr, int size) {

    int minModule = abs(arr[0]);
    for(int i = 1; i < size; i++){
        if(abs(arr[i]) < minModule){
         minModule = abs(arr[i]);
        }
    }


std::cout<<"Минимальный по модулю элемент массива: "<<minModule<<"\n";


int n_zero = -1;
for(int i = size-1; i >= 0; --i)
{
if (arr[i] == 0){
    n_zero = i;
    break;
}
}
int temp=0;
int sum = 0;
if(n_zero != -1){
    temp = n_zero;
while (temp<size)
{
    sum = sum + arr[temp];
    temp++;
}
    std::cout<<"сумма элементов массива, расположенных после последнего нулевого элемента: "<<sum<<"\n";
}
else{
std::cout<<"В массиве нет нулей \n";
}

for (int i = 1; 2 * i < size; i++) {
        temp = arr[2 * i];
        for (int j = 2 * i; j > i; j--)
            arr[j] = arr[j - 1];
        arr[i] = temp;
    }
    std::cout<<"Измененный массив:\n";
for(int i = 0; i < size; i++){
    std::cout<<arr[i]<<" ";
}
}
int main() {
    srand(time(0));
    int size, inputMode, memoryMode;
    const int MAX = 100;
    std::cout << "Размер массива: "; std::cin >> size;
    std::cout << "1 - ввести вручную, 2 - случайно: "; std::cin >> inputMode;
    std::cout << "1 - статический, 2 - динамический, 3 - вектор, 4 - array: "; std::cin >> memoryMode;
 
    switch (memoryMode) {
    case 1: {
        int arr[MAX];
        if (size > MAX) size = MAX;
        fillArray(arr, size, inputMode);
        process(arr, size);
        break;
    }
    case 2: {
        int* arr = new int[size];
        fillArray(arr, size, inputMode);
        process(arr, size);
        delete[] arr;
        break;
    }
    case 3: {
        std::vector<int> arr(size);
        fillArray(arr.data(), size, inputMode);
        process(arr.data(), size);
        break;
    }
    case 4: {
        std::array<int, MAX> arr;
        fillArray(arr.data(), size, inputMode);
        process(arr.data(), size);
        break;
    }
    default:
        std::cout << "Неверный выбор" << std::endl;
    }
}
