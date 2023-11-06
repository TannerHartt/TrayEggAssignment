#include <iostream>
#include "Big_time.h"
using namespace std;


Big_time::Big_time() : eggs(new Egg[1]), numEggs(0), capacity(1) {};
Big_time::~Big_time() { delete[] eggs; };

void Big_time::bubbleUp() {
    int index = numEggs - 1;
    Egg element = eggs[index];
    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        Egg parent = eggs[parentIndex];
        if (element < parent || element == parent) break;
        eggs[index] = parent;
        eggs[parentIndex] = element;
        index = parentIndex;
    }
};

void Big_time::bubbleDown() {
    int index = 0;
    int length = numEggs;
    Egg g = eggs[0];
    while (true) {
        int leftChildIndex = 2 * index + 1;
        int rightChildIndex = 2 * index + 2;
        Egg leftChild, rightChild;
        int swap = -1;

        if (leftChildIndex < length) {
            leftChild = eggs[leftChildIndex];
            if (g < leftChild) {
                swap = leftChildIndex;
            }
        }

        if (rightChildIndex < length) {
            rightChild = eggs[rightChildIndex];
            if ((swap == -1 && g < rightChild) || 
                (swap != -1 && leftChild < rightChild)) {
                swap = rightChildIndex;
            }
        }

        if (swap == -1) break;
        eggs[index] = eggs[swap];
        eggs[swap] = g;
        index = swap;
        g = eggs[index];
    }
};

void Big_time::give_egg(Egg g) {
    if (numEggs == capacity) {
        resize();
    }
    eggs[numEggs++] = g;
    bubbleUp();
};

bool Big_time::take_egg(Egg& g) {
    if (numEggs == 0) return false;

    Egg max = eggs[0];
    Egg end = eggs[numEggs-1];

    numEggs--; 
    if (numEggs > 0) {
        eggs[0] = end;
        bubbleDown();
    }
    g = max;
    return true;
};

void Big_time::resize() {
    Egg* carton = new Egg[capacity*=2];
    for (int i = 0; i < numEggs; i++) 
        carton[i] = eggs[i];
    delete [] eggs;
    eggs = carton;
};