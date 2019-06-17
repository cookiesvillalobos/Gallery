#include "library.h"

#include <iostream>

void write(int nameFo, string im, string imN, string imD, string imS, string imA, string imY) {
    if(folders.empty()){
        Folder *folder = new Folder(nameFo, im, imN, imD, imS, imA, imY);
        folders.push_back(folder);
    }else{
        if(!alreadyExist(nameFo)){
            Folder *folder = new Folder(nameFo, im, imN, imD, imS, imA, imY);
            folders.push_back(folder);
        }else{
            folders[posF]->update("I", im);
            folders[posF]->update("N", imN);
            folders[posF]->update("D", imD);
            folders[posF]->update("S", imS);
            folders[posF]->update("A", imA);
            folders[posF]->update("Y", imY);
            posF = -1;
        }

    }
}

/**
* En inf solo se acepta:
* +I: para image
* +N: para el nombre de la imagen
* +D: para la descripción de la imagen
* +S: para el tamaño de la imagen
* +A: para el autor de la imagen
* +Y: para el año de publicación de la imagen
* @param nameFo,inf
* @return
**/
string read(int nameFo, string inf){
    if(alreadyExist(nameFo)){
        string s = folders[posF]->read(inf);
        posF = -1;
        return s;

    }else{
        printf("\n");
        printf("The Folder doesn't exist");
        printf("\n");
    }
}


bool alreadyExist(int Id) {
    for(int i = 0; i < folders.size(); i++){
        if(folders[i]->name == Id){
            posF = i;
            return true;
        }
    }
    return false;
}

vector<string> readAll(int nameFo) {
    if(alreadyExist(nameFo)){
        vector<string> vector = folders[posF]->readAll();
        posF = -1;
        return vector;
    } else{
        printf("\n");
        printf("The Folder doesn't exist");
        printf("\n");
        return {};
    }


}


