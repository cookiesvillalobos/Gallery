//
// Created by kei98 on 11/06/19.
//

#include "Stripe.h"

Stripe::Stripe(string info, int parPos) {
    data = info;
    parityPos = parPos;
    diskD();

}

void Stripe::diskD() {
    segData = new List();

    vector<int> bytes = textToBinaryString();
    printf("String en bits:");
    printf("\n");

    for(int j = 0; j < bytes.size(); j++){
        printf("%d", bytes[j]);
    }

    printf("\n");

    if(bytes.size()%4 == 0) {
        int secLength = bytes.size() / 4;


        for (int i = 0; i < secLength; i++) {
            disk0.push_back(bytes[i]);
            disk1.push_back(bytes[i + secLength]);
            disk2.push_back(bytes[i + 2 * secLength]);
            disk3.push_back(bytes[i + 3 * secLength]);

        }
        parity();
        if (parityPos == 0) {
            segData->push_back(parityV);
            segData->push_back(disk0);
            segData->push_back(disk1);
            segData->push_back(disk2);
            segData->push_back(disk3);
        } else if (parityPos == 1) {
            segData->push_back(disk0);
            segData->push_back(parityV);
            segData->push_back(disk1);
            segData->push_back(disk2);
            segData->push_back(disk3);

        } else if (parityPos == 2) {
            segData->push_back(disk0);
            segData->push_back(disk1);
            segData->push_back(parityV);
            segData->push_back(disk2);
            segData->push_back(disk3);

        } else if (parityPos == 3) {
            segData->push_back(disk0);
            segData->push_back(disk1);
            segData->push_back(disk2);
            segData->push_back(parityV);
            segData->push_back(disk3);
        } else if (parityPos == 4) {
            segData->push_back(disk0);
            segData->push_back(disk1);
            segData->push_back(disk2);
            segData->push_back(disk3);
            segData->push_back(parityV);
        }

        printf("\n");

    } else{
        printf("error");
    }


}

void Stripe::parity() {
    for(int i = 0; i < disk0.size(); i++){
        XOR(disk0[i], disk1[i], disk2[i], disk3[i]);
    }

}

void Stripe::XOR(int d0, int d1, int d2, int d3) {
    int par = d0 + d1 + d2 + d3;
    printf("par: ");
    printf("%d",par);
    printf("\n");
    if(par%2 == 0){
        parityV.push_back(0);
    }else{
        parityV.push_back(1);
    }

}

vector<int> Stripe::textToBinaryString() {
    string binaryString = "";
    for (char& _char : data) {
        binaryString +=bitset<8>(_char).to_string();
    }


    vector<int> binary;
    for(int i = 0; i < binaryString.size(); i++){
        string b = "";
        b += binaryString[i];
        stringstream stringstream2(b);
        int b0 = 0;
        stringstream2 >> b0;
        binary.push_back(b0);
    }

    return binary;



}

void Stripe::printString() {

    printf("\n");
    printf("Vector:");
    printf("\n");
    for(int n = 0; n < disk0.size(); n++){
        printf("%d", disk0[n]);
    }
    printf("\n");
    for(int n = 0; n < disk0.size(); n++){
        printf("%d", disk1[n]);
    }
    printf("\n");
    for(int n = 0; n < disk0.size(); n++){
        printf("%d", disk2[n]);
    }
    printf("\n");
    for(int n = 0; n < disk0.size(); n++){
        printf("%d", disk3[n]);
    }
    printf("\n");
    for(int n = 0; n < disk0.size(); n++){
        printf("%d", parityV[n]);
    }
    printf("\n");

}

string Stripe::recomposeBText() {
    string recom = "";
    for(int n = 0; n < disk0.size(); n++){
        recom += to_string(disk0[n]);
    }
    for(int n = 0; n < disk0.size(); n++){
        recom += to_string(disk1[n]);
    }
    for(int n = 0; n < disk0.size(); n++){
        recom += to_string(disk2[n]);
    }
    for(int n = 0; n < disk0.size(); n++){
        recom += to_string(disk3[n]);
    }

    printf("\n");
    printf("recomposition: ");
    printf("\n");
    for(int i = 0; i < recom.size(); i++){
        printf("%c",recom[i]);
    }
    printf("\n");

    return recom;
}

string Stripe::BToText(string Bt) {
    string text = "";
    for(int k = 0; k < Bt.size()/8; k++){
        char parsed = 0;
        for (int i = 0; i < 8; i++) {
            if (Bt[i + 8*k] == '1') {
                parsed |= 1 << (7 - i);
            }
        }
        text += parsed;
    }
    /**
    printf("\n");
    printf("Texto00: ");
    printf("\n");
    for(int i = 0; i < text.size(); i++){
        printf("%c", text[i]);
    }
     **/
    return text;

}

string Stripe::read() {
    if(segData->length == 5){
        string s = BToText(recomposeBText());
        return s;
    }else{
        printf("\n");
        printf("Lost info, recovering...");
        printf("\n");
        restore();
        return "";
    }

}

void Stripe::delDisk(int pos) {
    if(segData->deleteByP(pos)){
        delPos = pos;
        if(pos == parityPos){
            parityV.clear();
        }else{
            if(parityPos == 0){
                if(pos == 1){
                    disk0.clear();
                }else if(pos == 2){
                    disk1.clear();
                }else if(pos ==3){
                    disk2.clear();
                }else if(pos == 4){
                    disk3.clear();
                }
            }else if(parityPos ==1){
                if(pos == 0){
                    disk0.clear();
                }else if(pos == 2){
                    disk1.clear();
                }else if(pos ==3){
                    disk2.clear();
                }else if(pos == 4){
                    disk3.clear();
                }

            }else if(parityPos == 2){
                if(pos == 0){
                    disk0.clear();
                }else if(pos == 1){
                    disk1.clear();
                }else if(pos ==3){
                    disk2.clear();
                }else if(pos == 4){
                    disk3.clear();
                }
            }else if(parityPos == 3){
                if(pos == 0){
                    disk0.clear();
                }else if(pos == 1){
                    disk1.clear();
                }else if(pos ==2){
                    disk2.clear();
                }else if(pos == 4){
                    disk3.clear();
                }
            }else if(parityPos == 4){
                if(pos == 0){
                    disk0.clear();
                }else if(pos == 1){
                    disk1.clear();
                }else if(pos ==2){
                    disk2.clear();
                }else if(pos == 3){
                    disk3.clear();
                }
            }
        }
    }
}

void Stripe::restore() {
    if(parityV.empty()){
        parity();
        segData->addByP(parityPos, parityV);
    }else{
        if(disk0.empty()){
            for(int i = 0; i < parityV.size(); i++){
                disk0.push_back(XORI(disk1[i], disk2[i], disk3[i], parityV[i]));
            }
            segData->addByP(delPos, disk0);
            delPos = -1;
        }else if(disk1.empty()){
            for(int i = 0; i < parityV.size(); i++){
                disk1.push_back(XORI(disk0[i], disk2[i], disk3[i], parityV[i]));
            }

            printf("\n");
            printf("delPos supuesto: ");
            printf("%d", delPos);
            printf("\n");

            segData->addByP(delPos, disk1);
            delPos = -1;
        }else if(disk2.empty()){
            for(int i = 0; i < parityV.size(); i++){
                disk2.push_back(XORI(disk0[i], disk1[i], disk3[i], parityV[i]));
            }
            segData->addByP(delPos, disk2);
            delPos = -1;
        }else if(disk3.empty()){
            for(int i = 0; i < parityV.size(); i++){
                disk3.push_back(XORI(disk0[i], disk1[i], disk2[i], parityV[i]));
            }
            segData->addByP(delPos, disk3);
            delPos = -1;
        }
    }
}

int Stripe::XORI(int d0, int d1, int d2, int parity) {
    int p = d0 + d1 + d2;
    if(p%2 == parity){
        return 0;
    }else{
        return 1;
    }

}

void Stripe::update(string info) {
    if(info != ""){
        segData->clear();
        disk0.clear();
        disk1.clear();
        disk2.clear();
        disk3.clear();
        parityV.clear();
        data = info;
        diskD();
    } else{
        printf("\n");
        printf("No hay cambios para esta fila");
        printf("\n");
    }

}


