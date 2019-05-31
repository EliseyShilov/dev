#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>

using namespace std;

template <typename T>
class Stack
{
private:
    T *stck;
    int top;
    unsigned int size;
    void increase();

public:
    Stack(int size);
    ~Stack();
    void push(const T value);
    void pop();
    void print() const;
    T pop_value;

};

template <typename T>
Stack<T>::Stack(int size){
    stck = new T[size];
    top = -1;
}

template <typename T>
Stack<T>::~Stack(){
    delete[] stck;
    top = 0;
    size = 0;
}

template <typename T>
void Stack<T>::increase(){
    T *bufStack = new T[size];
    for (unsigned int i = 0; i < top; i++)
        bufStack[i] = stck[i];
    size+=5;
    stck = new T[size];
    for (unsigned int i = 0; i < top; i++)
        stck[i] = bufStack[i];
}

template <class T>
void Stack<T>::push(const T value){
    if (size == top + 1)
        increase();
    top++;
    stck[top] = value;
}

template <class T>
void Stack<T>::pop(){
    if (top < 0)
        cout << "Stack is empty!" << endl;
    else{
        pop_value = stck[top];
        top--;
    }
}

template <typename T>
void Stack<T>::print()const {
    cout << "\nStack:" << endl;
    for (unsigned int i = 0; i <= top; i++)
        cout << stck[i] << " ";
}

int main()
{
    bool flag = true;
    int num;
    int test;
    string key;
    string elem;
    Stack <int> stck(5);
    cout << "Welcome to Stack's tester!" << endl;
    cout << "\n-To add element use command 'push x' (x - your's element)" << endl;
    cout << "-To remove element from stack use command 'pop'" << endl;
    cout << "-To display the stack on the screen use command 'print'" << endl;
    cout << "-To stop working use command 'stop'" << endl;
    cin >> key;
    if (key == "stop")
        flag = false;

    while(flag){

        if (key == "print")
            stck.print();

        else if (key == "pop"){
            stck.pop();
            test = stck.pop_value;
        }

        else if (key == "push"){
            cin >> elem;
            stck.push(atoi(elem.c_str()));
        }

        else cout << "Incorrect command!" << endl;

        cin >> key;
        if (key == "stop")
            flag = false;
    }
    return 0;
}

