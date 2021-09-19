#include<iostream>

using namespace std;

class node {
    public:
        node * left, * right;
    int lbit, rbit, data;
};

class tbt {
    public:
        node * root, * temp, * dummy;
    void createtbt();
    void display();
    void isttbt(node * , node * );
    tbt() {
        dummy = root = temp = NULL;
    }
};

void tbt::createtbt() {
    int val;
    char op;
    do {
        temp = new node;
        cout << "\n Insert new value: ";
        cin >> val;
        temp -> data = val;
        temp -> left = NULL;
        temp -> right = NULL;
        temp -> lbit = 0;
        temp -> rbit = 0;
        if (root == NULL) {
            dummy = new node;
            dummy -> data = 999;
            dummy -> left = temp;
            dummy -> right = dummy;
            dummy -> lbit = 1;
            dummy -> rbit = 0;
            root = temp;
            root -> left = dummy;
            root -> right = dummy;
        } else
            isttbt(root, temp);
        cout << "\n Do you want to continue?(y/n) ";
        cin >> op;
    } while (op == 'y');
}

void tbt::isttbt(node * root, node * temp) {
    if (temp -> data > root -> data) {
        if (root -> lbit == 0) {
            root -> left = temp;
            temp -> right = root;
            temp -> left = root -> left;
            root -> lbit = 1;
        } else
            isttbt(root -> left, temp);
    } else {
        if (root -> rbit == 0) {
            root -> right = temp;
            temp -> left = root;
            temp -> right = root -> right;
            root -> rbit = 1;
        } else
            isttbt(root -> right, temp);
    }
}

void tbt::display() {
    temp = root;
    while (temp -> lbit != 0) {
        temp = temp -> left;
    }
    while (temp != root) {
        cout << "\t" << temp -> data;
        temp = temp -> right;
    }
    //temp=temp->right;
    cout << "\t" << temp -> data;
    temp = temp -> right;
    while (temp -> lbit != 0) {
        temp = temp -> left;
    }
    while (temp != dummy) {
        cout << "\t" << temp -> data;
        temp = temp -> right;
    }
}

int main() {
    tbt f;
    f.createtbt();
    f.display();
    return 0;
}
