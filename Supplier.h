#ifndef PROJECT_SUPPLIER_H
#define PROJECT_SUPPLIER_H

#include <iostream>
#include <string>
#include "SparePart.h"
#include "../../DataStructures/LinkedNode.h"

class SparePart;

class Supplier {
private:
    std::string supplierName;
    int supplierCode;
    std::string address;
    std::string telephone;
    std::string email;
    LinkedNode<SparePart>* suppliedPartsHead;
    Supplier* left;
    Supplier* right;

public:
    Supplier();

    void getData();
    void putData();
    void modifyData();
    void addSuppliedPart(SparePart* part);
    LinkedNode<SparePart>* getSuppliedPartsHead() const;


    Supplier* insert(Supplier* root, Supplier* newNode);
    Supplier* search(int supplierCode);

};

#endif //PROJECT_SUPPLIER_H
