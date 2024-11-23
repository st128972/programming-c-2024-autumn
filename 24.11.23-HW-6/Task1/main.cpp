#include <iostream>
#include <ctime>

int genrandom(int start = 0, int end = 9) {
    return rand() % (end - start + 1) + start;
}

int *createArray(int size) {
    int *arr = new int[size];

    for (int i = 0; arr != nullptr && i < size; ++i) {
        arr[i] = genrandom();
    }

    return arr;
}

void outputArray(int *arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

void freeArray(int *arr) {
    if (arr != nullptr) {
        delete[] arr;
    }
}

void deleteArray(int *arr) {
    delete[] arr;
}

void printMenu(int *arr, int size) {
    system("cls");
    std::cout << "Now your array is: ";
    outputArray(arr, size);
    std::cout << "\n" << "print 0 to end";
    std::cout << "\n" << "print 1 to add element to start";
    std::cout << "\n" << "print 2 to add element to end";
    std::cout << "\n" << "print 3 to remove element from start";
    std::cout << "\n" << "print 4 to remove element from end";
    std::cout << "\n" << "print here: ";
}

void addToStart(int *&arr, int size) {
    int newElement = genrandom();
    int *newArr = new int[size + 1];

    newArr[0] = newElement;

    for (int i = 0; i < size; ++i) {
        newArr[i + 1] = arr[i];
    }

    deleteArray(arr);

    arr = newArr;
    ++size;

}

void addToEnd(int *&arr, int &size) {
    int *newArr = new int[size + 1];
    for (int i = 0; i < size; ++i) {
        newArr[i] = arr[i];
    }
    newArr[size] = genrandom();
    if (arr != nullptr) {
        delete[] arr;
    }
    arr = newArr;
    ++size;
}

void removeFromStart(int *&arr, int &size) {
    if (arr == nullptr || size == 0) {
        return;
    }

    for (int i = 0; i < size - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    --size;
    if (size == 0) {
        delete[] arr;
        arr = nullptr;
    }
}

void removeFromEnd(int *&arr, int &size) {
    --size;
}

int main(int argc, char *argv[]) {
    srand(time(0));
    int size = 0;
    std::cout << "Enter the initial size of the array: ";
    std::cin >> size;

    int *array = createArray(size);
    bool yn = true;
    while (yn) {
        int numm = 0;
        printMenu(array, size);
        std::cin >> numm;
        switch (numm) {
            case (0):
                yn = false;
                break;
            case (1):
                addToStart(array, size);
                break;
            case (2):
                addToEnd(array, size);
                break;
            case (3):
                removeFromStart(array, size);
                break;
            case (4):
                removeFromEnd(array, size);
                break;
        }
    }
    deleteArray(array);
    return 0;
}
