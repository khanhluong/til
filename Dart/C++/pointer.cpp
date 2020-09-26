//
//  main.cpp
//  learningcplusplus
//
//  Created by kh on 26/09/20.
//

#include <iostream>

using namespace std;

int * sum(int *i, int *j);

void pointer_ex1(){
    int i = 10;
    cout << "the value of i is " << i << endl;
    cout << "the address of i is " << &i << endl;
    cout << "the value of i with * is " << *(&i) << endl;
}

void pointer_ex2(){
    int i = 10;
    int *x = &i;
    
    int *y;
    
    y = &i;
    
    cout << "Pointer x store in memory address: " << &x << endl;
    
    cout << "Pointer x store in memory address: of i: " << x << endl;
    
    cout << "The value of i access through pointer x: " << *x << endl;
    
    *x = *x + 1;
    
    cout << "i through pointer = " << *x << "which equal i (direct access)" << i << endl;
    
    cout << "The memory allocated to the pointer x is " << sizeof(x) << "bytes" << endl;
    
}

void pointer_ex3(){
    char ch1 = 'a';
    char ch2 = 'b';
    char ch3[4] = {'c', 'd', 'e', 'f'};
    
    char *ptr[3];
    
    ptr[0] = &ch1;
    ptr[1] = &ch2;
    //base address of array ch[3] is store at ptr[2]. Equivalenty ptr[2] = &ch3[0]
//    ptr[2] = ch3;
    ptr[2] = &ch3[0];
    
    cout << "Init characters store in ptr[0] and ptr[1] " << *ptr[0] << " ptr[1] " << *ptr[1] << endl;
    
    *ptr[0] = 'y';
    *ptr[1] = 'z';
    
    cout << "Final characters store in ptr[0] and ptr[1] " << *ptr[0] << " ptr[1] " << *ptr[1] << endl;
    
}

void pointer_ex4(){
    int i = 0;
    int *ptr1 = new int;
    //new allocated memory for the unname integer. the base memory address of the variable
    //acess through the pointer
    //we can freely access throuh the pointer.
    *ptr1 = 10;
    *ptr1 = 2 + *ptr1;
    
    cout << "Dynamic memorry allocation. Value of ptr1 is: " << *ptr1 << endl;
    
    delete ptr1;
    
    ptr1 = new int[3];
    *(ptr1 + 0) = 2;
    *(ptr1 + 1) = 4;
    *(ptr1 + 2) = 6;
    
    cout << "Printing array of the pointer" << endl;
    
    for(i = 0; i < 3; i++){
        cout << "*(ptr1 + " << i << ") = " << *(ptr1 + i) << endl;
    }
    
    /**
            Note that array notation to access the pointer
     */
    
    for(i = 0; i < 3; i++){
        cout << "ptr1[" << i << "] = " << ptr1[i] << endl;
    }
    
    delete ptr1;
}

void pointer_ex5(){
//    One thing to remember is the use of dynamic memory allocation in classes. When we create a class in C++, the compiler automatically creates four member functions, even if we don't create them:
//
//    The default (no argument) constructor.
//    Hide   Copy Code
//    classname& classname ()
//    The copy constructor.

//    classname& classname (classname&)
//    The assignment (=) operator.

//    classname& operator=(classname&)
//    The destructor
    
//    ~classname ()
    
    int arr[3] = {10, 15, 20};
    int *ptr = new int[3];
    
    cout << "arr[0] using array notation " << arr[0] << endl;
    cout << "arr[0] using pointer notation " << *(arr + 0) << endl;
    cout << "Base address of array ptr point to " << ptr << endl;
    cout << "Base address of array is " << arr << endl;
    
    
}

/*
 Multi-Dimensional Pointers
 https://www.codeproject.com/KB/cpp/PointerArticle/ex6Drawing.png
 */
void pointer_ex6(){
    int **ptr2;
    int *ptr1;
    
    int i = 10;
    
    ptr1 = &i;
    ptr2 = &ptr1;
    
    cout << "Accessing i through i: " << i << endl;
    cout << "Accessing i through ptr1: " << *ptr1 << endl;
    cout << "Accessing i through ptr2: " << **ptr2 << endl;
    
    cout << "Accessing i through *ptr2: " << *ptr2 << endl;
    
    
    
}

void swap(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void pointer_ex7(){
    int p = 10;
    int q = 7;
    int *r = sum(&p, &q);
    cout << *r << endl;
    free(r);
    cout << "p,q: " << p << " "<< q << endl;
    swap(p, q);
    cout << "p,q: " << p << " "<< q << endl;
}

int * sum(int *a, int *b){
    int *result = new int;
    *result =  *a + *b;
    return result;
}

/**
 Function Pointers and typedef
 */

int sum1(int a, int b){
    return (a + b);
}

int (*ptr_sum) (int, int) = &sum1;
typedef int (*ptr_sum_type) (int, int);
void pointer_ex8(){
    int a,b;
    cout << "Enter two ints: sperated by white space: ";
    cin >> a >> b;
    
    if(ptr_sum != &sum1){
        cout << "error" << endl;
    }
    
    int result = (*ptr_sum)(a, b);
    cout << "Sum is: " << result << endl;
    
    ptr_sum_type ptr_sum1 = &sum1;
    result = (*ptr_sum1)(a,b);
    cout << "Sum typedef is: " << result << endl;
    
    
}

int main(int argc, const char * argv[]) {
    cout << "Hello, World!\n";
//    pointer_ex1();
//    pointer_ex2();
//    pointer_ex3();
//    pointer_ex4();
//    pointer_ex5();
//    pointer_ex6();
//    pointer_ex7();
    pointer_ex8();
    return 0;
}
