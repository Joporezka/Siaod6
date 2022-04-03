#include <iostream>
#include <windows.h>
#include <cmath>
using  namespace std;


int divs (int value,int &count,int &current) {

    if (value % current == 0) count++;
    current++;
    if (current < int(sqrt(value))) divs(value,count,current);
    else{
        int result;
        if(sqrt(value)-int(sqrt(value)) == 0) return count*2+1;
        else return count*2;
    }
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
    int work = -1;
    while (work != 0) {
        cout << "Лабораторная работа №6 ИКБО-13-21 Смольников А.Б. Вариант 20" << endl << endl;
        cout<< "Рекурсивные алгоритмы и их реализация" << endl;
        cout << "Меню\n";
        cout << "Задание 1 Дано целое число. Определить количество делителей числа." << endl;
        cout << "Задание 2 Дан линейный однонаправленный список. Сформировать новый список, записав него четные числа, но в обратном порядке, по отношению к их расположению в исходном." << endl;
        cout << "0) Выход\n";
        cout << "Ваш выбор: ";
        cin >> work;
        cout << "Лабораторная работа №3 ИКБО-13-21 Смольников А.Б. Вариант 20" << endl << endl;

        switch (work) {
            case 1: {
                int count =0;
                int current = 2;
                cout << "Вариант 20 Задание 1" << endl;
                cout << "Введите число: "<< endl;
                int n;
                cin >> n;
                cout << "Количество делителей: " << divs(n,count,current)<< endl;
                break;
            }
            case 2: {
                cout << "Вариант 20 Задание 2" << endl;
                second();
                break;
            }
            default:{
                cout << "Неверный выбор" << endl;
                break;
            }
        }
    }
    return 0;
}