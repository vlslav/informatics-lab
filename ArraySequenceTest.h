#ifndef LAB0_ARRAYSEQUENCETEST_H
#define LAB0_ARRAYSEQUENCETEST_H

#include "Classes.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

void ArraySequenceTest() {
    cout << "=== ArraySequenceTest ===" << endl << endl;
    ArraySequence<int> *Seq;
    Seq = new ArraySequence<int>;

    cout << "Testing GetLength...";
    if (Seq->GetLength() == 0) cout << "OK" << endl;
    else cout << "FAIL" << endl;

    Seq->Append(23);

    cout << "Testing GetLength...";
    if (Seq->GetLength() == 1) cout << "OK" << endl;
    else cout << "FAIL" << endl;

    cout << "Testing GetFirst...";
    if (Seq->GetFirst() == 23) cout << "OK" << endl;
    else cout << "FAIL" << endl;

    cout << "Testing GetLast...";
    if (Seq->GetLast() == 23) cout << "OK" << endl;
    else cout << "FAIL" << endl;

    cout << "Testing Get...";
    if (Seq->Get(0) == 23) cout << "OK" << endl;
    else cout << "FAIL" << endl;
    if (Seq->Get(-1) == -1) cout << "OK" << endl;
    else cout << "FAIL" << endl;
    if (Seq->Get(1) == 1) cout << "OK" << endl;
    else cout << "FAIL" << endl;

    Seq->Append(43);

    cout << "Testing GetLength...";
    if (Seq->GetLength() == 2) cout << "OK" << endl;
    else cout << "FAIL" << endl;

    cout << "Testing GetFirst...";
    if (Seq->GetFirst() == 23) cout << "OK" << endl;
    else cout << "FAIL" << endl;

    cout << "Testing GetLast...";
    if (Seq->GetLast() == 43) cout << "OK" << endl;
    else cout << "FAIL" << endl;

    cout << "Testing Get...";
    if (Seq->Get(0) == 23) cout << "OK...";
    else cout << "FAIL...";
    if (Seq->Get(1) == 43) cout << "OK" << endl;
    else cout << "FAIL" << endl;
    if (Seq->Get(-1) == -1) cout << "OK" << endl;
    else cout << "FAIL" << endl;
    if (Seq->Get(2) == 2) cout << "OK" << endl;
    else cout << "FAIL" << endl;

    Seq->Prepend(53);

    cout << "Testing GetLength...";
    if (Seq->GetLength() == 3) cout << "OK" << endl;
    else cout << "FAIL" << endl;

    cout << "Testing GetFirst...";
    if (Seq->GetFirst() == 53) cout << "OK" << endl;
    else cout << "FAIL" << endl;

    cout << "Testing GetLast...";
    if (Seq->GetLast() == 43) cout << "OK" << endl;
    else cout << "FAIL" << endl;

    cout << "Testing Get...";
    if (Seq->Get(0) == 53) cout << "OK...";
    else cout << "FAIL...";
    if (Seq->Get(1) == 23) cout << "OK" << endl;
    else cout << "FAIL" << endl;
    if (Seq->Get(-1) == -1) cout << "OK" << endl;
    else cout << "FAIL" << endl;
    if (Seq->Get(3) == 3) cout << "OK" << endl;
    else cout << "FAIL" << endl;

    cout << "Testing GetSubsequence...";
    if (Seq->GetSubsequence(1, 1)->GetLength() == 1) cout << "OK...";
    else cout << "FAIL...";
    if (Seq->GetSubsequence(1, 1)->GetFirst() == 23) cout << "OK...";
    else cout << "FAIL...";
    if (Seq->GetSubsequence(1, 1)->GetLast() == 23) cout << "OK";
    else cout << "FAIL";

    cout << endl << endl;
}

#endif //LAB0_ARRAYSEQUENCETEST_H
