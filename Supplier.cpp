#include "../Headers/Supplier.h"

Supplier::Supplier() : suppliedPartsHead(nullptr), left(nullptr), right(nullptr) {}

void Supplier::putData() {
    std::cout << "Enter supplier name: ";
    std::cin >> supplierName;

    std::cout << "Enter supplier code: ";
    std::cin >> supplierCode;

    std::cout << "Enter address: ";
    std::cin.ignore();
    std::getline(std::cin, address);

    std::cout << "Enter telephone: ";
    std::cin >> telephone;

    std::cout << "Enter email: ";
    std::cin >> email;
}

void Supplier::getData() {
    std::cout << "Supplier Name: " << supplierName << std::endl;
    std::cout << "Supplier Code: " << supplierCode << std::endl;
    std::cout << "Address: " << address << std::endl;
    std::cout << "Telephone: " << telephone << std::endl;
    std::cout << "Email: " << email << std::endl;
}

void Supplier::modifyData() {
    std::cout << "Enter new supplier name: ";
    std::cin >> supplierName;

    std::cout << "Enter new supplier code: ";
    std::cin >> supplierCode;

    std::cout << "Enter new address: ";
    std::cin.ignore();
    std::getline(std::cin, address);

    std::cout << "Enter new telephone: ";
    std::cin >> telephone;

    std::cout << "Enter new email: ";
    std::cin >> email;
}

void Supplier::addSuppliedPart(SparePart* part) {
    LinkedNode<SparePart>* newNode = new LinkedNode<SparePart>(*part);
    newNode->next = suppliedPartsHead;
    suppliedPartsHead = newNode;
}

LinkedNode<SparePart>* Supplier::getSuppliedPartsHead() const {
    return suppliedPartsHead;
}

Supplier* Supplier::insert(Supplier* root, Supplier* newNode) {
    if (root == nullptr) {
        return newNode;
    }

    if (newNode->supplierCode < root->supplierCode) {
        root->left = insert(root->left, newNode);
    } else if (newNode->supplierCode > root->supplierCode) {
        root->right = insert(root->right, newNode);
    }

    return root;
}

Supplier* Supplier::search(int supplierCode) {
    if (this == nullptr || this->supplierCode == supplierCode) {
        return this;
    }

    if (supplierCode < this->supplierCode) {
        return left == nullptr ? nullptr : left->search(supplierCode);
    } else {
        return right == nullptr ? nullptr : right->search(supplierCode);
    }
}
