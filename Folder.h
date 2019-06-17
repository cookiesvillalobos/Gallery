//
// Created by kei98 on 11/06/19.
//

#ifndef RAID5_FOLDER_H
#define RAID5_FOLDER_H

#include "Stripe.h"

#include <string>
#include <vector>

using namespace std;

class Folder {
public:
    explicit Folder(int, string, string, string, string, string, string);

    int name;
    Stripe *image;
    Stripe *imName;
    Stripe *imDescript;
    Stripe *imSize;
    Stripe *imAuthor;
    Stripe *imYear;

    string read(string);
    vector<string> readAll();
    void update(string, string);
    void delDisk(int);
    Stripe *getStripe(string);

};


#endif //RAID5_FOLDER_H
