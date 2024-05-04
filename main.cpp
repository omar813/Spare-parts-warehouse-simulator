#include <iostream>
#include "src/Classes/Headers/SparePart.h"
#include "src/Classes/Headers/Supplier.h"
#include "src/DataStructures/Stack.h"
#include "src/DataStructures/Queue.h"

using namespace std;

const int MAX_SPARE_PARTS = 100;
const int MAX_SUPPLIERS = 20;

void displayMenu() {
    cout << "Menu:\n";
    cout << "1. Add Spare Part\n";
    cout << "2. Add Supplier\n";
    cout << "3. Search Spare Part\n";
    cout << "4. Search Supplier\n";
    cout << "5. Display Spare Parts\n";
    cout << "6. Display Suppliers\n";
    cout << "7. Link Spare Part to Supplier\n";
    cout << "0. Exit\n";
}

int main() {
    SparePart spareParts[MAX_SPARE_PARTS];
    Supplier suppliers[MAX_SUPPLIERS];

    int sparePartCount = 0;
    int supplierCount = 0;

    Stack<string> interactionStack;

    Queue<string> sparePartProcessingQueue;
    Queue<string> supplierProcessingQueue;

    int choice;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                if (sparePartCount < MAX_SPARE_PARTS) {
                    spareParts[sparePartCount].putData();
                    sparePartProcessingQueue.enqueue("Spare Part " + to_string(sparePartCount + 1) + " data processing in progress.");
                    spareParts[0].insert(&spareParts[0], &spareParts[sparePartCount]);
                    sparePartCount++;
                } else {
                    cout << "Maximum spare parts limit reached.\n";
                }
                break;
            }
            case 2: {
                if (supplierCount < MAX_SUPPLIERS) {
                    suppliers[supplierCount].putData();
                    supplierProcessingQueue.enqueue("Supplier " + to_string(supplierCount + 1) + " data processing in progress.");
                    suppliers[0].insert(&suppliers[0], &suppliers[supplierCount]);
                    supplierCount++;
                } else {
                    cout << "Maximum suppliers limit reached.\n";
                }
                break;
            }
            case 3: {
                int partNumber;
                cout << "Enter spare part number to search: ";
                cin >> partNumber;

                SparePart* foundSparePart = spareParts[0].search(partNumber);

                if (foundSparePart != nullptr) {
                    foundSparePart->getData();
                    LinkedNode<Supplier>* supplierNode = foundSparePart->getSupplyingSuppliersHead();
                    while (supplierNode != nullptr) {
                        supplierNode->data.getData();
                        supplierNode = supplierNode->next;
                    }
                } else {
                    cout << "Spare part not found.\n";
                }
                break;
            }
            case 4: {
                int supplierCode;
                cout << "Enter supplier code to search: ";
                cin >> supplierCode;

                Supplier* foundSupplier = suppliers[0].search(supplierCode);

                if (foundSupplier != nullptr) {
                    foundSupplier->getData();
                    LinkedNode<SparePart>* sparePartNode = foundSupplier->getSuppliedPartsHead();
                    while (sparePartNode != nullptr) {
                        sparePartNode->data.getData();
                        sparePartNode = sparePartNode->next;
                    }
                } else {
                    cout << "Supplier not found.\n";
                }
                break;
            }
            case 5: {
                for (int i = 0; i < sparePartCount; ++i) {
                    spareParts[i].getData();
                    LinkedNode<Supplier>* supplierNode = spareParts[i].getSupplyingSuppliersHead();
                    while (supplierNode != nullptr) {
                        cout << endl;
                        supplierNode->data.getData();
                        supplierNode = supplierNode->next;
                    }
                    cout << endl;
                }
                break;
            }
            case 6: {
                for (int i = 0; i < supplierCount; ++i) {
                    suppliers[i].getData();
                    LinkedNode<SparePart>* sparePartNode = suppliers[i].getSuppliedPartsHead();
                    while (sparePartNode != nullptr) {
                        cout << endl;
                        sparePartNode->data.getData();
                        sparePartNode = sparePartNode->next;
                    }
                    cout << endl;
                }
                break;
            }
            case 7: {
                int sparePartIndex, supplierIndex;
                cout << "Enter the index of the spare part: ";
                cin >> sparePartIndex;

                cout << "Enter the index of the supplier: ";
                cin >> supplierIndex;

                SparePart* foundSparePart = spareParts[0].search(sparePartIndex);
                Supplier* foundSupplier = suppliers[0].search(supplierIndex);

                if (foundSparePart != nullptr && foundSupplier != nullptr) {
                    foundSparePart->addSupplyingSupplier(foundSupplier);
                    foundSupplier->addSuppliedPart(foundSparePart);
                    cout << "Spare part linked to supplier.\n";
                } else {
                    cout << "Spare part or supplier not found.\n";
                }
                break;
            }
            case 0: {
                cout << "Exiting...\n";
                break;
            }
            default:
                cout << "Invalid choice. Please try again.\n";
        }

        interactionStack.push("User performed operation: " + to_string(choice));

        if (!sparePartProcessingQueue.isEmpty()) {
            cout << "\nSpare Part Processing Queue:\n";
            while (!sparePartProcessingQueue.isEmpty()) {
                cout << sparePartProcessingQueue.dequeue() << "\n";
            }
        }

        if (!supplierProcessingQueue.isEmpty()) {
            cout << "\nSupplier Processing Queue:\n";
            while (!supplierProcessingQueue.isEmpty()) {
                cout << supplierProcessingQueue.dequeue() << "\n";
            }
        }

        cout << endl;

        interactionStack.displayHistory();

        cout << endl;

    } while (choice != 0);

    return 0;
}
