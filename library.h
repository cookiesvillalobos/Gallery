#ifndef RAID5_LIBRARY_H
#define RAID5_LIBRARY_H

#include "Folder.h"
#include <string>
#include <vector>

using namespace std;

vector<Folder*> folders;
void write(int, string, string, string, string, string, string);

string read(int, string);

vector<string> readAllfromAF(int);

bool alreadyExist(int);

void createFailure(int);

vector<vector<string>> readAll();

int posF = -1;

#endif //RAID5_LIBRARY_H