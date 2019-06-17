//
// Created by kei98 on 11/06/19.
//

#ifndef RAID5_STRIPE_H
#define RAID5_STRIPE_H

#include "List.h"
#include <string>
#include <vector>
#include <bitset>
#include <sstream>


using namespace std;

class Stripe {
public:
    Stripe(string, int);
    List *segData;
    int parityPos;

    string read();
    void delDisk(int);
    void restore();
    void update(string);
    string recomposeBText();


private:
    string data;
    void diskD();
    void parity();
    string BToText(string);
    int delPos = -1;

    void printString();

    vector<int> disk0;
    vector<int> disk1;
    vector<int> disk2;
    vector<int> disk3;
    vector<int> parityV ;
    void XOR(int, int, int, int);
    int XORI(int, int, int, int);
    vector<int> textToBinaryString();

};


#endif //RAID5_STRIPE_H
