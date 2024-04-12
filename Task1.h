#pragma once

#include <iostream>;

using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;
};

Node* InitList(int x)
{
    Node* c = new Node;
    c->next = NULL;
    c->prev = NULL;
    c->data = x;
    return c;
}

void AddNodeAfter(Node*& ptr, int x)
{
    if (ptr == NULL) return;

    Node* c = new Node;
    c->data = x;
    c->next = ptr->next;
    c->prev = ptr;
    if (ptr->next != NULL)
        ptr->next->prev = c;
    ptr->next = c;
    ptr = c;
}

void InsertBeg(Node*& head, int x)
{
    if (head == NULL) return;
    Node* c = new Node;
    c->data = x;
    c->prev = head->prev;
    c->next = head;
    head->prev = c;
    head = c;
}

Node* DeleteNode(Node* ptr)
{
    if (ptr == NULL) return 0;
    Node* q = ptr->prev;
    if (ptr->next != NULL) // not end
    {
        ptr->next->prev = q;
        if (q) // not head
        {
            q->next = ptr->next;
            delete ptr;
            return q->next;
        }
        else // head
        {
            q = ptr->next;
            delete ptr;
            return q;
        }
    }
    else // end
    {
        if (q) // not head
        {
            q->next = NULL;
            delete ptr;
            return q;

        }
        else // and head
        {
            delete ptr;
            return NULL;
        }
    }
}

void Print_Right(Node* head)
{
    cout << "\nThe list from head to end:" << endl;
    if (head == NULL)
    {
        cout << "Empty" << endl;
        return;
    }
    Node* c = head;
    while (c != NULL)
    {
        cout << c->data << " ";
        c = c->next;
    }
    cout << endl;
}

void Print_Left(Node* end)
{
    cout << "\nThe list from end to head:" << endl;
    if (end == NULL)
    {
        cout << "Empty" << endl;
        return;
    }
    Node* c = end;
    while (c != NULL)
    {
        cout << c->data << " ";
        c = c->prev;
    }
    cout << endl;
}

void Free_Memory(Node*& head)
{
    if (head == NULL) return;
    Node* c = head;
    while (c != NULL)
    {
        head = head->next;
        delete c;
        c = head;
    }
}

void Task1()
{
    // 15 | Створити лінійний двозв'язний список з цілих чисел.
    //      Вставити в список число 25 перед кожним елементом з додатним значенням.
    //      Вилучити зі списку всі від’ємні числа

    Node* head = NULL, * end = NULL, * c;
    int x;
    cout << "Input 5 elements:" << endl;
    for (int i = 1; i <= 5; i++) // 1
    {
        cin >> x;
        if (head == NULL)
            head = end = InitList(x);
        else
            AddNodeAfter(end, x);
    }

    Print_Right(head);
    Print_Left(end);

    // Вставка числа 25 перед кожним елементом з додатним значенням
    c = head;
    while (c != NULL) // 2
    {
        if (c == head && head->data > 0)
        {
            InsertBeg(head, 25); // Вставка перед head
        }
        if (c->next != NULL && c->next->data > 0)
        {
            AddNodeAfter(c, 25);
        }
        c = c->next;
    }

    Print_Right(head);
    Print_Left(end);

    // Вилучення зі списку всіх від’ємних чисел
    c = head;
    while (c != NULL) // 3
    {
        if (c->data < 0)
        {
            if (c == head && c == end)
            {
                head = end = c = DeleteNode(c);
            }
            else if (c == head)
            {
                head = c = DeleteNode(c);
            }
            else if (c == end)
            {
                end = c = DeleteNode(c);
            }
            else
            {
                c = DeleteNode(c);
            }
        }
        else
        {
            c = c->next;
        }

    }

    Print_Right(head);
    Print_Left(end);

    Free_Memory(head);
}
