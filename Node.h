//
// Created by kei98 on 16/06/19.
//

#ifndef RAID5_NODE_H
#define RAID5_NODE_H

#include <vector>
using namespace std;

class Node {
public:
    explicit Node(vector<int>);

    vector<int> value;
    Node *next;

};


#endif //RAID5_NODE_H
