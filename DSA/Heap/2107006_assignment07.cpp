#include <bits/stdc++.h>
using namespace std;

template <typename T>
class PriorityQueueVector
{
private:
    vector<T> data;
    bool ascending;

public:
    PriorityQueueVector(bool asc = true) : ascending(asc) {}

    void push(const T &val)
    {
        data.push_back(val);
        if (ascending)
            sort(data.begin(), data.end());
        else
            sort(data.begin(), data.end(), greater<T>());
    }

    void pop()
    {
        if (!empty())
            data.pop_back();
    }

    T top() const
    {
        if (!empty())
            return data.back();
        throw out_of_range("Priority queue is empty");
    }

    bool empty() const
    {
        return data.empty();
    }

    size_t size() const
    {
        return data.size();
    }
};

template <typename T>
class Node
{
public:
    T value;
    Node<T> *next;
    Node<T> *prev;

    Node(const T &val) : value(val), next(nullptr), prev(nullptr) {}
};

template <typename T>
class PriorityQueueLinkedList
{
private:
    Node<T> *head;
    Node<T> *tail;
    bool ascending;

public:
    PriorityQueueLinkedList(bool asc = true) : head(nullptr), tail(nullptr), ascending(asc) {}

    void push(const T &val)
    {
        Node<T> *newNode = new Node<T>(val);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            Node<T> *current = head;
            while (current && (ascending ? val > current->value : val < current->value))
            {
                current = current->next;
            }
            if (!current)
            { 
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            else
            {
                if (current->prev)
                {
                    current->prev->next = newNode;
                    newNode->prev = current->prev;
                }
                else
                {
                    head = newNode;
                }
                newNode->next = current;
                current->prev = newNode;
            }
        }
    }

    void pop()
    {
        if (!empty())
        {
            Node<T> *temp = head;
            head = head->next;
            if (head)
                head->prev = nullptr;
            delete temp;
        }
    }

    T top() const
    {
        if (!empty())
            return head->value;
        throw out_of_range("Priority queue is empty");
    }

    bool empty() const
    {
        return head == nullptr;
    }

    size_t size() const
    {
        size_t count = 0;
        Node<T> *current = head;
        while (current)
        {
            count++;
            current = current->next;
        }
        return count;
    }
};

int main()
{
    PriorityQueueVector<int> pqVec(true);
    pqVec.push(20);
    pqVec.push(10);
    pqVec.push(50);
    cout << "PQVector size: " << pqVec.size() << endl;
    cout << "Top element in PQVector: " << pqVec.top() << endl;
    pqVec.pop();
    cout << "Top element in PQVector after pop operation: " << pqVec.top() << endl;

    PriorityQueueLinkedList<int> pqList(false);
    pqList.push(20);
    pqList.push(10);
    pqList.push(50);
    cout << "\nPQLinkedList size: " << pqList.size() << endl;
    cout << "Top element in PQLinkedList: " << pqList.top() << endl;
    pqList.pop();
    cout << "Top element in PQLinkedList after pop operation: " << pqList.top() << endl;

    return 0;
}
