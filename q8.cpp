#include<iostream>
using namespace std;
struct node
{
    int data;
    node* next;
};
class linklist
{
private:
public:
    void removeDuplicates(node* ptr)
    {
        node* tmp = ptr;
        node* tmp2;
        if (tmp == nullptr)
            return;
        while (tmp->next != nullptr)
        {
            if (tmp->data == tmp->next->data)
            {
                tmp2 = tmp->next->next;
                delete(tmp->next);
                tmp->next = tmp2;
            }
            else
            {
                tmp = tmp->next;
            }
        }
    }
    void addnode(node** ptr_ref, int new_data)
    {
        node* new_node = new node();
        new_node->data = new_data;
        new_node->next = (*ptr_ref);
        (*ptr_ref) = new_node;
    }
    void printList(node* node)
    {
        while (node != nullptr)
        {
            cout  << node->data << "  ";
            node = node->next;
        }
    }
};
int main()
{
    linklist a;
    node* ptr = nullptr;
    a.addnode(&ptr, 2);
    a.addnode(&ptr, 1);
    a.addnode(&ptr, 1);
    a.addnode(&ptr, 4);
    a.addnode(&ptr, 3);
    cout << "Linked list before duplicate removal "<<endl;
    a.printList(ptr);
    a.removeDuplicates(ptr);
    cout << "\nLinked list after duplicate removal " << endl;
    a.printList(ptr);

    return 0;
}