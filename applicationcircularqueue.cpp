
#include <bits/stdc++.h>
using namespace std;

struct customer {
    int id;
    string name;
};

class Queue {
private:
    int maxsize;
    customer *q;
    int front, rear;

public:
    Queue(int x) {
        maxsize = x;
        q = new customer[maxsize];
        front = -1;
        rear = -1;
    }

    bool isempty() {
        return (front == -1);
    }

    bool isfull() {
        return ((rear + 1) % maxsize == front);
    }

    void enqueue(int x, string nam) {
        if (isfull()) {
            cout << "The queue is full\n";
        } else {
            if (isempty()) {
                front = 0;
            }
            rear = (rear + 1) % maxsize;
            q[rear].id = x;
            q[rear].name = nam;
        }
    }

    void dequeue() {
        if (isempty()) {
            cout << "The queue is empty\n";
        } else if (front == rear) {
          
            cout << "Dequeuing customer ID: " << q[front].id << ", Name: " << q[front].name << '\n';
            front = rear = -1;  
        } else {
         
            cout << "Dequeuing customer ID: " << q[front].id << ", Name: " << q[front].name << '\n';
            front = (front + 1) % maxsize;
        }
    }

  
    void front_val() {
        if (isempty()) {
            cout << "Queue is empty\n";
        } else {
            cout << "Front customer ID: " << q[front].id << ", Name: " << q[front].name << '\n';
        }
    }

    void show() {
        if (isempty()) {
            cout << "Queue is empty, nothing to show\n";
        } else {
            int i = front;
            cout << "Customers in the queue:\n";
            while (true) {
                cout << "Customer ID: " << q[i].id << " | Customer Name: " << q[i].name << '\n';
                if (i == rear) break;
                i = (i + 1) % maxsize;
            }
        }
    }
};

int main() {
    Queue q(5);

    q.enqueue(1, "Alice");
    q.enqueue(2, "Bob");
    q.enqueue(3, "Charlie");
    q.show();

    q.enqueue(4, "Diana");
    q.enqueue(5, "Eve");

    
    q.show();

    
    q.dequeue();
    q.dequeue();

    
    q.show();

    q.enqueue(6, "Rakin");
    q.enqueue(7, "Mohit");

    q.show();

    
    q.front_val();

    return 0;
}
