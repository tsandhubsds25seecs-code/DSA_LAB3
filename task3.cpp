
#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Global head pointer
Node* head = nullptr;

// ---------- 1. Insert at Head ----------
void insertAtHead(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    cout << "Inserted " << value << " at head." << endl;
}

// ---------- 2. Insert at 3rd Position ----------
void insertAtThird(int value) {
    Node* newNode = new Node(value);

    // Case: empty or single-node list
    if (head == nullptr) {
        head = newNode;
        cout << "List was empty. Inserted " << value << " at head." << endl;
        return;
    }
    if (head->next == nullptr) {
        head->next = newNode;
        cout << "List had only 1 node. Inserted " << value << " at 2nd position." << endl;
        return;
    }

    // Traverse to the 2nd node (so we can insert after it)
    Node* temp = head;
    int position = 1;
    while (temp->next != nullptr && position < 2) {
        temp = temp->next;
        position++;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    cout << "Inserted " << value << " at 3rd position." << endl;
}

// ---------- 3. Display List ----------
void displayList() {
    if (head == nullptr) {
        cout << "List is empty (NULL)." << endl;
        return;
    }
    Node* temp = head;
    cout << "List: ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// ---------- 4. Delete Last Node ----------
void deleteLast() {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }
    if (head->next == nullptr) {
        cout << "Deleted last node: " << head->data << endl;
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    cout << "Deleted last node: " << temp->next->data << endl;
    delete temp->next;
    temp->next = nullptr;
}

// ---------- 5. Count Nodes ----------
int countNodes() {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

// ---------- 6. Reverse List Iteratively ----------
void reverseList() {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;   // Save next
        current->next = prev;   // Reverse link
        prev = current;         // Move prev forward
        current = next;         // Move current forward
    }
    head = prev;
    cout << "List reversed successfully." << endl;
}

// ---------- 7. Search Value ----------
bool searchValue(int value) {
    Node* temp = head;
    int position = 1;
    while (temp != nullptr) {
        if (temp->data == value) {
            cout << "Value " << value << " found at position " << position << "." << endl;
            return true;
        }
        temp = temp->next;
        position++;
    }
    cout << "Value " << value << " NOT found in the list." << endl;
    return false;
}

// ---------- 8. Menu-Driven Main ----------
int main() {
    int choice, value;

    do {
        cout << "\n===== Singly Linked List Menu =====" << endl;
        cout << "1. Insert at Head" << endl;
        cout << "2. Insert at 3rd Position" << endl;
        cout << "3. Display List" << endl;
        cout << "4. Delete Last Node" << endl;
        cout << "5. Count Nodes" << endl;
        cout << "6. Reverse List" << endl;
        cout << "7. Search Value" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at head: ";
                cin >> value;
                insertAtHead(value);
                break;
            case 2:
                cout << "Enter value to insert at 3rd position: ";
                cin >> value;
                insertAtThird(value);
                break;
            case 3:
                displayList();
                break;
            case 4:
                deleteLast();
                displayList();
                break;
            case 5:
                cout << "Total nodes: " << countNodes() << endl;
                break;
            case 6:
                reverseList();
                displayList();
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> value;
                searchValue(value);
                break;
            case 8:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 8);

    // Clean up remaining nodes
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}