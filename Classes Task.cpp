#include <iostream>
#include <string>

using namespace std;

class Product {
protected:
    string name;
    string description;
    double price;
    int inventory;

public:
    Product(string name, string description, double price, int inventory)
        : name(name), description(description), price(price), inventory(inventory) {}

    void displayDetails() {
        cout << "Name: " << name << endl;
        cout << "Description: " << description << endl;
        cout << "Price: $" << price << endl;
        cout << "Inventory: " << inventory << endl;
    }

    double getPrice() const {
        return price;
    }

    void decrementInventory() {
        inventory--;
    }
};

class Clothing : public Product {
public:
    Clothing(string name, string description, double price, int inventory)
        : Product(name, description, price, inventory) {}
};

class Electronics : public Product {
public:
    Electronics(string name, string description, double price, int inventory)
        : Product(name, description, price, inventory) {}
};

class Furniture : public Product {
public:
    Furniture(string name, string description, double price, int inventory)
        : Product(name, description, price, inventory) {}
};

class PerishableGrocery : public Product {
public:
    PerishableGrocery(string name, string description, double price, int inventory)
        : Product(name, description, price, inventory) {}
};

int main() {
    // Create some sample products
    Clothing shirt("T-Shirt", "Aesthetic Shirts", 2, 99);
    Electronics laptop("Laptop", "GIKI Smart Laptop", 10000, 4);
    Furniture chair("Chair", "Gaming chair", 50, 19);
    PerishableGrocery milk("Milk", "Ayan Dairy Milk", 3, 29);

    // Shopping cart
    cout << "Welcome to the store!\n";
    cout << "Here are some available products:\n";
    cout << "1. Aesthetic Shirts \n";
    cout << "2. GIKI Smart Laptop (V fast)\n";
    cout << "3. Gaming Chair\n";
    cout << "4. Ayan Dairy Milk\n";

    int choice;
    cout << "Enter the product number to add to your cart (0 to finish): ";
    cin >> choice;

    double totalBill = 0.0;

    while (choice != 0) {
        switch (choice) {
            case 1:
                cout << "\nAdding T-Shirt to your cart:\n";
                shirt.displayDetails();
                shirt.decrementInventory();
             totalBill += shirt.getPrice();
                break;
            case 2:
                cout << "\nAdding Laptop to your cart:\n";
                laptop.displayDetails();
                laptop.decrementInventory();
                totalBill += laptop.getPrice();
                break;
            case 3:
                cout << "\nAdding Chair to your cart:\n";
                chair.displayDetails();
                chair.decrementInventory();
                totalBill += chair.getPrice();
                break;
            case 4:
                cout << "\nAdding Milk to your cart:\n";
                milk.displayDetails();
                milk.decrementInventory();
                totalBill += milk.getPrice();
                break;
            default:
                cout << "Invalid choice!\n";
                break;
        }

        cout << "\nEnter the product number to add to your cart (0 to finish): ";
        cin >> choice;
    }

    cout << "\nYour total bill is: $" << totalBill << endl;

    return 0;
}


