#include <iostream>
#include <windows.h>
#include <cmath>
using  namespace std;

int divs (int value) {
    static int count = 0,current = 2;
    if (value % current == 0) count++;
    current++;
    if (current < int(sqrt(value))+1) divs(value);
    else return count*2;
}

struct Node{
    int value;
    Node *next;
};

void pushFront(Node *&head, int value) {
    Node *newNode = new Node;
    newNode->value = value;
    newNode->next = head;
    head = newNode;
}
void push_back(Node*& head, int inp){
    Node *NewItem=new Node;
    NewItem->value=inp;
    NewItem->next = NULL;
    if (head == NULL) {
        head = NewItem;
    }else{
        Node *Current=head;
        for(int i=1;Current->next!=NULL; i++)
            Current=Current->next;
        Current->next = NewItem;
    }
}

void printNode(Node* head) {
    if(head == NULL) return;
    while (head != NULL) {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}


bool isEven (int value) {
    if (value % 2 == 0) return true;
    else return false;
}
void fillNode(Node* head,Node *&answer){
    if (isEven(head->value)) pushFront(answer,head->value);
    if(head->next != NULL) fillNode(head->next,answer);

}

void second(){
    Node* answer=nullptr;
    Node* head= nullptr;
    cout<<"Enter the number of elements: "<<endl;
    int n;
    cin>>n;
    cout<<"Enter the elements: \n";
    for (int i = 0; i < n; i++) {
        int value;
        cin>>value;
        push_back(head,value);
    }
    printNode(head);
    fillNode(head,answer);
    printNode(answer);


}

int main(){
    SetConsoleOutputCP(CP_UTF8);
    cout << "Вариант 20 Задание 1" << endl;
    cout << "Введите число: "<< endl;
    int n;
    cin >> n;
    cout << "Количество делителей: " << divs(n)<< endl;
    second();
    return 0;
}