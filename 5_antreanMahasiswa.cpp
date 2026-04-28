#include <iostream>
#include <string>
using namespace std;

struct Node {
    char mahasiswa;
    Node* next;
};

class Queue {
private:
    Node *front, *rear;

public:
    Queue() {
        front = rear = NULL;
    }

    bool isEmpty() {
        return (front == NULL);
    }

    void enqueue(char mhs) {
        Node* newNode = new Node();
        newNode->mahasiswa = mhs;
        newNode->next = NULL;

        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Mahasiswa " << mhs << " mengambil nomor antrean\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Antrean kosong\n";
            return;
        }

        Node* temp = front;
        cout << "Mahasiswa " << temp->mahasiswa << " sedang dilayani\n";

        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }

        delete temp;
    }

    void display() {
        if (isEmpty()) {
            cout << "Antrean kosong\n";
            return;
        }

        Node* temp = front;
        cout << "Antrean saat ini:" << endl;
        while (temp != NULL) {
            cout << "Mahasiswa " << temp->mahasiswa << endl;
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue('A');
    q.enqueue('B');
    q.enqueue('C');

    q.dequeue();

    q.enqueue('D');
    q.display();

    return 0;
}