#ifndef LAB0_CLASSES_H
#define LAB0_CLASSES_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

template<typename T> struct Element {
    T x;
    struct Element *next;
    struct Element *prev;
};

template<typename T> class Sequence {
public:
    virtual int GetLength() = 0;
    virtual bool GetIsEmpty() = 0;
    virtual T GetFirst() = 0;
    virtual T GetLast() = 0;
    virtual T Get(int index) = 0;
    virtual void Prepend(T item) = 0;
    virtual void Append(T item) = 0;
    virtual void InsertAt(int index, T item) = 0;
    virtual void Remove(T item) = 0;
};
template <typename T> class ArraySequence : public Sequence<T> {
public:

    T *arr;
    int N;

    ArraySequence() {
        arr = new T[0];
        N = 0;
    }

    bool GetIsEmpty() {
        if (N == 0) return true;
        else return false;
    }

    int GetLength() {
        return N;
    }

    T GetFirst() {
        return arr[0];
    }

    T GetLast() {
        return arr[N-1];
    }

    T Get(int index) {
        if ((index >= 0) && (index < N)) {
            return arr[index];
        }
        else {
            cout << "Index out of bounds! ";
        }
    }

    void Append(T item) {
        T *temp = new T[N+1];
        for(int i = 0; i < N; i++) temp[i] = arr[i];
        temp[N] = item;
        delete [] arr;
        arr = temp;
        N++;
    }

    void Prepend(T item) {
        T *temp = new T[N+1];
        temp[0] = item;
        for(int i = 0; i < N; i++) temp[i+1] = arr[i];
        delete [] arr;
        arr = temp;
        N++;
    }

    void InsertAt(int index, T item) {
        try {
            T *temp = new T[N + 1];
            for (int i = 0; i < N + 1; i++) {
                if (i < index) temp[i] = arr[i];
                if (i == index) temp[i] = item;
                if (i > index) temp[i] = arr[i - 1];
            }
            delete[] arr;
            arr = temp;
            N++;
        }
        catch(...) {
            cout << "Index out of bounds!" << endl;
        }
    }

    void Remove(T item) {
        T *temp = new T[N-1];
        bool flag = false;
        for(int i = 0; i < N; i++) {
            if ((arr[i] == item) && (flag == false)) flag = true;
            else {
                if (flag == false) temp[i] = arr[i];
                if (flag == true) temp[i-1] = arr[i];
            }
        }
        delete [] arr;
        arr = temp;
        N++;
    }

    ArraySequence<T>* GetSubsequence(int startIndex, int endIndex) {
        try {
            ArraySequence<T> *sub;
            sub = new ArraySequence<T>;
            for (int i = startIndex; i <= endIndex; i++) sub->Append(arr[i]);
            return sub;
        }
        catch(...) {
            cout << "Index out of bounds!" << endl;
        }
    }

};


template<typename T> class LinkedList : public Sequence<T> {
public:
    struct Element<T> *first, *last;
    int N;

    LinkedList() {
        first = NULL;
        last = NULL;
        N = 0;
    }

    bool GetIsEmpty() {
        if (N == 0) return true;
        else return false;
    }

    int GetLength() {
        return N;
    }

    T GetFirst() {
        return first->x;
    }

    T GetLast() {
        return last->x;
    }

    T Get(int index) {
        if ((index >= 0) && (index < N)) {
            int i = 0;
            struct Element<T> *temp;
            temp = first;
            while (i != index) {
                temp = temp->next;
                i++;
            }
            return temp->x;
        }
        else {
            cout << "Index out of bounds! ";
            return index;
        }
    }

    void Append(T item) {
        struct Element<T> *temp = new Element<T>;
        if (N == 0) {
            temp->next = NULL;
            temp->prev = NULL;
            temp->x = item;
            first = temp;
            last = temp;
        }
        else {
            temp->prev = last;
            temp->next = NULL;
            temp->x = item;
            last->next = temp;
            last = temp;
        }
        N++;
    }

    void Prepend(T item) {
        struct Element<T> *temp = new Element<T>;
        if (N == 0) {
            temp->next = NULL;
            temp->prev = NULL;
            temp->x = item;
            first = temp;
            last = temp;
        }
        else {
            temp->next = first;
            temp->prev = NULL;
            temp->x = item;
            first->prev = temp;
            first = temp;
        }
        N++;
    }

    void InsertAt(int index, T item) {
        try {
            int i = 1;
            struct Element<T> *temp;
            struct Element<T> *temp1 = new Element<T>;
            temp1->x = item;
            while (i != index) {
                if (i == index) {
                    temp->prev->next = temp1;
                    temp1->prev = temp->prev;
                    temp1->next = temp;
                    temp->prev = temp1;
                } else temp = temp->next;
                i++;
            }
            N++;
        }
        catch(...) {
            cout << "Index out of bounds!" << endl;
        }
    }

    void Remove(T item) {
        struct Element<T> *temp;
        temp = first;
        int i = 1;
        while(i != N) {
            if (temp->x == item) {
                temp = temp->prev;
                temp->next = temp->next->next;
                temp->next->prev = temp;
                break;
            }
            else temp = temp->next;
        }
    }

    LinkedList<T>* GetSubsequence(int startIndex, int endIndex) {
        try {
            LinkedList<T> *sub;
            sub = new LinkedList<T>;
            struct Element<T> *temp;
            temp = first;
            for (int i = 0; i <= endIndex; i++) {
                if (i >= startIndex) sub->Append(temp->x);
                temp = temp->next;
            }
            return sub;
        }
        catch(...) {
            cout << "Index out of bounds!" << endl;
        }
    }

};

#endif //LAB0_CLASSES_H
