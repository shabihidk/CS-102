#include <iostream>
#include <string>

using namespace std;

// Order structure initialization
struct Order {
    string dish;
    int quantity;
};

// Chef structure initialization
struct Chef {
    string specialization;
    void (*cookFunction)(const Order&);
};

// Functions to cook specific dishes
void cookItalianDish(const Order& order) {
    cout << "Cooking Italian dish: " << order.dish << " x" << order.quantity << "\n";
}

void cookJapaneseDish(const Order& order) {
    cout << "Cooking Japanese dish: " << order.dish << " x" << order.quantity << "\n";
}

void cookPakistaniDish(const Order& order) {
    cout << "Cooking Pakistani dish: " << order.dish << " x" << order.quantity << "\n";
}

int main() {
    // Create specialized chefs
    Chef italianChef{"Italian", cookItalianDish};
    Chef japaneseChef{"Japanese", cookJapaneseDish};
    Chef pakistaniChef{"Pakistani", cookPakistaniDish};

    // Get order from the user
    Order userOrder;
    cout<< "======== Menu ========= \n" << "1. Italian \n" << "2. Japanese \n" << "3. Pakistani \n";
    cout << "Enter the dish name: ";
    cin >> userOrder.dish;
    cout << "Enter the quantity: ";
    cin >> userOrder.quantity;

    // Handle the user's order based on chef specialization
    if (userOrder.dish == italianChef.specialization) {
        italianChef.cookFunction(userOrder);
    } else if (userOrder.dish == japaneseChef.specialization) {
        japaneseChef.cookFunction(userOrder);
    } else if (userOrder.dish == pakistaniChef.specialization) {
        pakistaniChef.cookFunction(userOrder);
    } else {
        cout << "No specialized chef found for " << userOrder.dish << " in kitchen \n";
    }

    return 0;
}




