#include "../Headers/SparePart.h"


SparePart::SparePart() : supplyingSuppliersHead(nullptr), left(nullptr), right(nullptr) {}


void SparePart::getData() {
    std::cout << "Part Name: " << partName << std::endl;
    std::cout << "Part Number: " << partNumber << std::endl;
    std::cout << "Cost: " << cost << std::endl;
    std::cout << "Existing Parts: " << existingParts << std::endl;
}


void SparePart::putData() {
    std::cout << "Enter part name: ";
    std::cin >> partName;

    std::cout << "Enter part number: ";
    std::cin >> partNumber;

    std::cout << "Enter cost: ";
    std::cin >> cost;

    std::cout << "Enter existing parts: ";
    std::cin >> existingParts;
}

void SparePart::modifyData() {
    std::cout << "Enter new part name: ";
    std::cin >> partName;

    std::cout << "Enter new part number: ";
    std::cin >> partNumber;

    std::cout << "Enter new cost: ";
    std::cin >> cost;

    std::cout << "Enter new existing parts: ";
    std::cin >> existingParts;
}


void SparePart::addSupplyingSupplier(Supplier* supplier) {
    LinkedNode<Supplier>* newNode = new LinkedNode<Supplier>(*supplier);
    newNode->next = supplyingSuppliersHead;
    supplyingSuppliersHead = newNode;
}

LinkedNode<Supplier>* SparePart::getSupplyingSuppliersHead() const {
    return supplyingSuppliersHead;
}

SparePart* SparePart::insert(SparePart* root, SparePart* newNode) {
    if (root == nullptr) {
        return newNode;
    }

    if (newNode->partNumber < root->partNumber) {
        root->left = insert(root->left, newNode);
    } else if (newNode->partNumber > root->partNumber) {
        root->right = insert(root->right, newNode);
    }

    return root;
}

SparePart* SparePart::search(int partNumber) {
    if (this == nullptr || this->partNumber == partNumber) {
        return this;
    }

    if (partNumber < this->partNumber) {
        return left == nullptr ? nullptr : left->search(partNumber);
    } else {
        return right == nullptr ? nullptr : right->search(partNumber);
    }
}
