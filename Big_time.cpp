#include <iostream>
#include "Big_time.h"
using namespace std;


Big_time::Big_time() : eggs(new Egg[1]), numEggs(0), capacity(1) {};

Big_time::~Big_time() { delete[] eggs; };

// void Big_time::give_egg(Egg g) adds an egg to the internal array of eggs
//     if capacity equals num_eggs, then double the capacity before adding the egg. Refer to Tray::place_back to remind yourself how to grow the capacity. But note that Tray only increases capacity by two, whereas you will double the current capacity.
//     add egg to end and increase num_eggs by 1
//     percolate upthe new egg
// void Big_time::take_egg(Egg& g) assigns the first egg to the argument g.
//     The last egg moves to the first position and num_eggs is reduced by 1
//     percolate down the egg now in the first position
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