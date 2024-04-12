#pragma once
#include <iostream>;

using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* InitList(double x)
{
    Node* c = new Node;
    c->next = c;
    c->data = x;
    return c;
}

Node* AddNodeAfter(Node*& ptr, double x) // Getting next after added
{
    Node* c = new Node;
    c->next = c;
    c->data = x;
    if (ptr == NULL) return NULL;
    else
    {
        c->next = ptr->next;
        ptr->next = c;
        ptr = c;
        return c->next;
    }
}

void Print_List(Node* head)
{
    cout << "\nThe list:" << endl;
    Node* c = head;
    do
    {
        if (c)
        {
            cout << c->data << " ";
            c = c->next;
        }
    } while (c != head);
    cout << endl;
}

void Free_Memory(Node* head, Node* end)
{
    if (head == NULL) return;
    Node* c = head;
    end->next = NULL;
    while (c != NULL)
    {
        head = head->next;
        delete c;
        c = head;
    }
}

Node* DeleteNode(Node*& ptr, Node*& head, Node*& end) // Getting next after ptr
{
    if (ptr == NULL) return NULL;
    if (ptr == head)
    {
        if (head == end)
        {
            delete ptr;
            head = end = NULL;
            return NULL;
        }
        else
        {
            head = head->next;
            end->next = head;
            delete ptr;
            return head;
        }
    }

    Node* prev = ptr->next;
    while (prev && prev->next != ptr) // Looking for element before ptr by going through loop
    {
        prev = prev->next;
    }

    if (prev != ptr)
    {
        prev->next = ptr->next;
        if (ptr == end) end = prev;
        delete ptr;
        return prev->next;
    }
    return NULL;
}

void Task2()
{
    // 15 | Створити циклічний список цілих чисел.
    //      З кожної пари сусідніх елементів вилучити менший за модулем
    Node* head = NULL, * end = NULL, * c;  double x;
    cout << "Input 10 elements:" << endl;
    for (int i = 1; i <= 10; i++) // 1
    {
        cin >> x;
        if (head == NULL)
        {
            head = end = InitList(x);
        }
        else
        {
            head = AddNodeAfter(end, x);
        }
    }
    Print_List(head);

    c = head;
    do // 2
    {
        if (abs(c->data) < abs(c->next->data))
        {
            c = DeleteNode(c, head, end);
            c = c->next;
        }
        else if (abs(c->data) > abs(c->next->data))
        {
            c = c->next;
            c = DeleteNode(c, head, end);
            if (c == head) break;
        }
        else
        {
            c = c->next->next;
        }
    } while (c != head);

    Print_List(head);

    cout << "\nend->next->data = " << end->next->data << endl;


    Free_Memory(head, end);
}