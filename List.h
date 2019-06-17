//
// Created by kei98 on 16/06/19.
//

#ifndef RAID5_LIST_H
#define RAID5_LIST_H

#include <vector>
#include "Node.h"

using namespace std;


class List {
public:
    List();
    int length;
    Node *head;
    void push_back(vector<int>);
    vector<int> getEl(int);
    bool deleteByP(int);
    void printList();
    void addByP(int, vector<int>);
    void clear();

};


#endif //RAID5_LIST_H
