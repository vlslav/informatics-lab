#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include "Classes.h"
#include "TreeSort.h"
//#include "BinaryInsertionSort.h"
//#include "QuickSort.h"

using namespace std;

int main() {
    int a, b, x, y;
    cout << "To use ArraySequence enter 1, for LinkedList enter 2 ";
    cin >> a;
    cout << "For TreeSort enter 1, for BinaryInsertionSort enter 2, for QuickSort enter 3 ";
    cin >> b;
    cout << "Enter number of elements: ";
    cin >> x;
    if (a == 1) {
        ArraySequence<int> *Seq;
        Seq = new ArraySequence<int>;
        for (int i = 0; i < x; i++) {
            cout << "Enter element " << i << ": ";
            cin >> y;
            Seq->Append(y);
        }

        if (b == 1) ArraySequenceTreeSort(*Seq);
        //if (b == 2)
        //if (b == 3)
    }

    if (a == 2) {
        LinkedList<int> *Seq;
        Seq = new LinkedList<int>;
        for (int i = 0; i < x; i++) {
            cout << "Enter element " << i << ": ";
            cin >> y;
            Seq->Append(y);
        }

        if (b == 1) LinkedListTreeSort(*Seq);
        //if (b == 2)
        //if (b == 3)
}
    
	return 0;
}