/*
A Dictionary stores keywords & its meanings. Provide facility for adding new keywords,
deleting keywords, updating values of any entry. Provide facility to display whole data 
sorted in ascending/ Descending order. Also find how many maximum comparisons may require 
for finding any keyword. Use Binary Search Tree for implementation.
*/

#include <iostream>

using namespace std;

class node {
    public:
        int data;
    node * left, * right;

};

class BT {
    public:
        node * root, * temp;
    void create();
    void traverse();
    void display();
    void insert(node * , node * );
    void preorder(node * );
    void postorder(node * );
    void inorder(node * );
    BT() {
        root = temp = NULL;
    }
};

int main() {
    int ch;
    BT obj;
    do {
        cout << "\n1. Create Binary Tree\n2. Traverse Binary Tree\n3. Exit\nSelect your option:";
        cin >> ch;
        switch (ch) {
        case 1:
            cout << endl << "\t\t****Create Binary Tree****";
            obj.create();
            break;
        case 2:
            obj.display();
            break;
        default:
            cout << endl << "Invalid choice!!!";
            break;
        }
    } while (ch != 3);
    return 0;
}

void BT::display() {
    int ch1;
    do {
        cout << endl << "\t\t****Traversing a Binary Tree****";
        cout << endl << "How to Traverse?\n1.Preorder\n2.Postorder\n3.Inorder\n4.Back";
        cin >> ch1;
        switch (ch1) {
        case 1:
            preorder(temp);
            break;
        case 2:
            postorder(temp);
            break;
        case 3:
            inorder(temp);
            break;
        default:
            cout << endl << "Invalid option!!!";
            break;
        }
    } while (ch1 != 4);
}

void BT::create() {
    char op;
    int val;
    node * temp;
    do {
        cout << endl << "Enter element: ";
        cin >> val;
        temp = new node;
        temp -> data = val;
        temp -> left = NULL;
        temp -> right = NULL;
        if (root == NULL) {
            root = temp;
        } else {
            insert(root, temp);

        }
        cout << endl << "Add more elements?(Y/N)";
        cin >> op;
    } while (op == 'y' || op == 'Y');
}

void BT::insert(node * root, node * temp) {
    char op;
    cout << endl << "Current root: " << root -> data;
    cout << endl << "Where to insert element?(L/R)";
    cin >> op;
    if (op == 'L' || op == 'l') {
        if (root -> left == NULL)
            root -> left = temp;
        else
            insert(root -> left, temp);
    } else {
        if (root -> right == NULL)
            root -> right = temp;
        else
            insert(root -> right, temp);
    }
}

void BT::preorder(node * temp) {
    if (temp != NULL) {
        cout << endl << "Preorder: " << temp -> data;
        preorder(temp -> left);
        preorder(temp -> right);
    }

}

void BT::postorder(node * temp) {
    if (temp != NULL) {
        postorder(temp -> left);
        postorder(temp -> right);
        cout << endl << "Postorder: " << temp -> data;
    }

}

void BT::inorder(node * temp) {
    if (temp != NULL) {
        inorder(temp -> left);
        cout << endl << "Inorder: " << temp -> data;
        inorder(temp -> right);
    }

}
