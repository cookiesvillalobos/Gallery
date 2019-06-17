//
// Created by kei98 on 11/06/19.
//

#include "Folder.h"

Folder::Folder(int name0, string im, string imN, string imD, string imS, string imA, string imY) {

    int name = name0;
    image = new Stripe(im, 0);
    imName = new Stripe(imN, 1);
    imDescript = new Stripe(imD, 2);
    imSize = new Stripe(imS, 3);
    imAuthor = new Stripe(imA, 4);
    imYear = new Stripe(imY, 0);

}

string Folder::read(string stripe) {
    if(stripe == "I"){
        getStripe(stripe)->recomposeBText();
    } else{
        getStripe(stripe)->read();
    }

}

void Folder::update(string stripe, string info) {
    getStripe(stripe)->update(info);
}

void Folder::delDisk(int pos) {
    image->delDisk(pos);
    imName->delDisk(pos);
    imDescript->delDisk(pos);
    imSize->delDisk(pos);
    imAuthor->delDisk(pos);
    imYear->delDisk(pos);
}

vector<string> Folder::readAll() {
    vector<string> list;
    list.push_back(image->read());
    list.push_back(imName->read());
    list.push_back(imDescript->read());
    list.push_back(imSize->read());
    list.push_back(imAuthor->read());
    list.push_back(imYear->read());
    return list;

}



/**
 * Relaciona los stripes
 * +I: para image
 * +N: para el nombre de la imagen
 * +D: para la descripción de la imagen
 * +S: para el tamaño de la imagen
 * +A: para el autor de la imagen
 * +Y: para el año de publicación de la imagen
 * @param stripe
 * @return
 */
Stripe* Folder::getStripe(string stripe) {
    if(stripe == "I"){
        return image;
    }else if(stripe == "N"){
        return imName;
    }else if(stripe == "D"){
        return imDescript;
    }else if(stripe == "S"){
        return imSize;
    }else if(stripe == "A"){
        return imAuthor;
    }else if(stripe == "Y"){
        return imYear;
    }else{
        printf("No se selccionó una stripe válida");
        return NULL;
    }
}
