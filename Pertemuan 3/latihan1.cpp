#include <iostream>
#include <string>

using namespace std;

#define MAX 100

char stack[MAX];
int top = -1;

// TODO : Menambahkan karakter ke stack
void push(char value) {
    if (top < MAX - 1){
        top++;
        stack[top] = value;
    } else {
        cout << "Stack Penuh!" << endl;
    }
}

// TODO : Mengambil karakter paling atas
char pop() {
    if (top >= 0) {
        char item = stack[top];
        top--;
        return item;
    } else {
        cout << "Stack Kosong!" << endl;
        return '\0';
    }
}

int main() {

    string kata;

    cout << "Masukkan sebuah kata: ";
    cin >> kata;

    // TODO : Memasukkan setiap karakter ke stack
    for (int i = 0; i < kata.length(); i++) {
        push(kata[i]);
    }

    // TODO Mengeluarkan karakter dari stack
    cout << "Hasil Terbalik: ";
    while (top >= 0) {
        cout << pop();
    }
    
    cout << endl;

    return 0;
}