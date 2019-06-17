#ifndef RAID5_LIBRARY_H
#define RAID5_LIBRARY_H

#include "Folder.h"
#include <string>
#include <vector>

using namespace std;

vector<Folder*> folders;
void write(int, string, string, string, string, string, string);

string read(int, string);

vector<string> readAll(int);

bool alreadyExist(int);
int posF = -1;

#endif //RAID5_LIBRARY_H