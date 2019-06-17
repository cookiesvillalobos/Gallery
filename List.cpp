//
// Created by kei98 on 16/06/19.
//

#include <cstdio>
#include "List.h"

List::List() {
    length = 0;
    head = NULL;
}

void List::push_back(vector<int> vector) {
    if(!vector.empty()){
        if(head == NULL){
            head = new Node(vector);
            length++;
        } else{
            Node *node = new Node(vector);
            Node *temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = node;
            length++;
        }
    }


}

bool List::deleteByP(int pos) {
    if(pos == 0 && head != NULL) {
        head = head->next;
        length--;
        return true;
    }else if(pos < length && head != NULL){
        Node *temp = head;
        Node *temp2;
        while(pos != 0){
            temp2 = temp;
            temp = temp->next;
            pos--;
        }
        if(temp->next == NULL){
            temp2->next = NULL;
            length--;
            return true;
        } else{
            temp2->next = temp->next;
            length--;
            return true;
        }

    }else{
        printf("\n");
        printf("Out of range, DELETE");
        printf("\n");
        return false;
    }
}

vector<int> List::getEl(int pos) {
    if(pos < length){
        Node *temp = head;
        while(pos != 0){
            temp = temp->next;
            pos--;
        }
        return temp->value;
    } else{
        printf("Out of range, GET");
        printf("\n");
        return {};
    }
}

void List::printList() {
    printf("\n");
    printf("Lista: ");
    printf("\n");
    printf("[");
    for (int i = 0; i < length; ++i) {
        printf("[");
        for(int j = 0; j < getEl(i).size(); j++){
            printf("%d", getEl(i)[j]);
            printf(", ");

        }
        printf("], ");
    }
    printf("]");

}

void List::addByP(int pos, vector<int> vector) {
    if(!vector.empty() && pos < length){
        if(pos == 0){
            if(head == NULL){
                head = new Node(vector);
                length++;
            } else{
                Node *node = new Node(vector);
                node->next = head;
                head = node;
                length++;
            }
        }else{
            Node *node = new Node(vector);
            Node *temp = head;
            Node *temp2;
            while(pos != 0){
                temp2 = temp;
                temp = temp->next;
                pos--;
            }

            if(temp->next == NULL){
                temp->next = node;
                length++;
            } else{
                temp2->next = node;
                node->next = temp;
                length++;
            }
        }
    }else{
        printf("\n");
        printf("Out of range, ADD");
        printf("\n");
    }
}

void List::clear() {
    head = NULL;

}


