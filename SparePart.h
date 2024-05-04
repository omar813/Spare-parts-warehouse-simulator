#ifndef PROJECT_SPAREPART_H
#define PROJECT_SPAREPART_H

#include <iostream>
#include <string>
#include "Supplier.h"
#include "../../DataStructures/LinkedNode.h"

class Supplier;

class SparePart {
private:
    std::string partName;
    int partNumber;
    double cost;
    int existingParts;
    LinkedNode<Supplier>* supplyingSuppliersHead;
    SparePart* left;
    SparePart* right;

public:
    SparePart();
    void getData();
    void putData();
    void modifyData();
    void addSupplyingSupplier(Supplier* supplier);
    LinkedNode<Supplier>* getSupplyingSuppliersHead() const;

    SparePart* insert(SparePart* root, SparePart* newNode);
    SparePart* search(int partNumber);
};

#endif //PROJECT_SPAREPART_H
