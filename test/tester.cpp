#include "tester.h"

void Tester::execute() {
    Mocker mocker;

    for (int j = 0; j < NUMBER_OF_TESTS; ++j) {
        unsigned int size = mocker.generateRandomInt(10);
        List<Integer> integers;
        List<Float> floats;
        for (int i = 0; i < size; ++i) {
            integers.insert(2 * i + 1);
            floats.insert(20.f / (i + 1.f) + 2.f);
        }

        ASSERT(isSorted(integers), "The integers list has problems");
        ASSERT(isSorted(floats), "The floats list has problems");

        for (int i = 0; i < 5; ++i) {
            integers.remove(2 * i + 1);
            floats.remove(20.f / (i + 1.f) + 2.f);
        }

        int newSize = size - 5;
        ASSERT(integers.size() == newSize, "The size function has problems");
        ASSERT(floats.size() == newSize, "The size function has problems");
        ASSERT(isSorted(integers), "The integers list has problems");
        ASSERT(isSorted(floats), "The floats list has problems");
        //Prueba Operator
        /*
        cout << "------------------------------\n";
        cout << "Integers: \n";
        cout << "\n------------------------------\n";
        integers.print();
        cout << "\n------------------------------\n";
        cout << "integers[0]: "<<integers[0]<<"  |  integers[nodes-1]:"<<integers[integers.size()-1];
        cout << "\n------------------------------\n";
        cout << "Floats: \n";
        floats.print();
        cout << "\n------------------------------\n";
        cout << "\nfloats[0]: "<<floats[0]<<"  |  floats[nodes-1]:"<<floats[floats.size()-1];
        */

    }
}

template <typename T>
bool Tester::isSorted(List<T> &list) {
    for (int i = 1; i < list.size(); ++i) {
        if ((is_same<T, Integer>::value) && list[i - 1] > list[i]) {
            return false;
        } else if ((is_same<T, Float>::value) && list[i - 1] < list[i]) {
            return false;
        }
    }

    return true;
}