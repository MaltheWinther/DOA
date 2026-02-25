#include <iostream>

bool contains(int *A, int x, int size)
{

    if (*A == x)
    {
        return true;
    }

    else if (size == 0)
    {
        return false;
    }

    return contains(A + 1, x, size - 1);
}

int findMax(int *array, int size){
    if (size == 1){
        return *array;
    }
    int MaxOfRest = findMax(array+1,size-1);
    return (*array > MaxOfRest) ? *array : MaxOfRest;


}

int findMin(int*array, int size){
    if (size == 1){
        return *array;
    }
    int MinOfRest = findMin(array+1,size-1);
    return (*array < MinOfRest) ? *array : MinOfRest;


}
int main()
{

    int array[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int size = sizeof(array) / sizeof(array[0]);

    std::cout << "1.A: " << std::endl;

    std::cout << contains(array, 8, size) << std::endl;  // Outputs 1
    std::cout << contains(array, 12, size) << std::endl; // Outputs 0


    std::cout << "1.B" << std::endl;

    std::cout << findMax(array,size) << std::endl;
    std::cout << findMin(array,size) << std::endl;

    return 0;
}