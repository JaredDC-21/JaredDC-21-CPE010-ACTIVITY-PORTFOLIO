#include <iostream>
#include <string>

// Attribute: Fruit
class Fruit {
private:
    std::string name;
    double price;
    int quantity;

public:
    // Constructor
    Fruit(std::string newName = "Fruit", double newPrice = 0.0, int newQty = 0) {
        name = newName;
        price = newPrice;
        quantity = newQty;
        std::cout << "Constructor: Fruit Called for " << name << "." << std::endl;
    }

    // Destructor
    virtual ~Fruit() {
        std::cout << "Destructor: Fruit Called for " << name << "." << std::endl;
    }

    // Copy Constructor
    Fruit(const Fruit &copyFruit) {
        std::cout << "Copy Constructor: Fruit Called." << std::endl;
        name = copyFruit.name;
        price = copyFruit.price;
        quantity = copyFruit.quantity;
    }

    // Copy Assignment
    Fruit& operator=(const Fruit &other) {
        std::cout << "Copy Assignment: Fruit Called." << std::endl;
        if (this != &other) {
            name = other.name;
            price = other.price;
            quantity = other.quantity;
        }
        return *this;
    }

    // Member Functions
    double calculateSum() const {
        return price * quantity;
    }

    void printDetails() const {
        std::cout << name << " - PHP each: " << price << " - Pcs" << quantity << " - Subtotal: PHP " << calculateSum() << std::endl;
    }

    std::string getName() const { return name; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }
};

// Attribute: Vegetable
class Vegetable {
private:
    std::string name;
    double price;
    int quantity;

public:
    // Constructor
    Vegetable(std::string newName = "Vegetable", double newPrice = 0.0, int newQty = 0) {
        name = newName;
        price = newPrice;
        quantity = newQty;
        std::cout << "Constructor: Vegetable Called for " << name << "." << std::endl;
    }

    // Destructor
    virtual ~Vegetable() {
        std::cout << "Destructor: Vegetable Called for " << name << "." << std::endl;
    }

    // Copy Constructor
    Vegetable(const Vegetable &copyVeg) {
        std::cout << "Copy Constructor: Vegetable Called." << std::endl;
        name = copyVeg.name;
        price = copyVeg.price;
        quantity = copyVeg.quantity;
    }

    // Copy Assignment
    Vegetable& operator=(const Vegetable &other) {
        std::cout << "Copy Assignment: Vegetable Called." << std::endl;
        if (this != &other) {
            name = other.name;
            price = other.price;
            quantity = other.quantity;
        }
        return *this;
    }

    // Member Functions
    double calculateSum() const {
        return price * quantity;
    }

    void printDetails() const {
        std::cout << name << " - PHP each: " << price << " - Pcs" << quantity << " - Subtotal: PHP " << calculateSum() << std::endl;
    }

    std::string getName() const { return name; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }
};

// Polymorphic Wrappers
class GroceryItem {
private:
    Fruit* fruitPtr;
    Vegetable* vegPtr;

public:
	// Dynamic Constructors
    GroceryItem() : fruitPtr(NULL), vegPtr(NULL) {}
    GroceryItem(const Fruit& f) : fruitPtr(new Fruit(f)), vegPtr(NULL) {}
    GroceryItem(const Vegetable& v) : fruitPtr(NULL), vegPtr(new Vegetable(v)) {}

    // Destructor
    ~GroceryItem() {
        delete fruitPtr;
        delete vegPtr;
    }

    // Copy Constructor
    GroceryItem(const GroceryItem& other) {
        fruitPtr = other.fruitPtr ? new Fruit(*other.fruitPtr) : NULL;
        vegPtr = other.vegPtr ? new Vegetable(*other.vegPtr) : NULL;
    }

    // Copy Assignment
    GroceryItem& operator=(const GroceryItem& other) {
        if (this != &other) {
            delete fruitPtr;
            delete vegPtr;
            fruitPtr = other.fruitPtr ? new Fruit(*other.fruitPtr) : NULL;
            vegPtr = other.vegPtr ? new Vegetable(*other.vegPtr) : NULL;
        }
        return *this;
    }

    double getItemSum() const {
        if (fruitPtr) return fruitPtr->calculateSum();
        if (vegPtr) return vegPtr->calculateSum();
        return 0.0;
    }

    void print() const {
        if (fruitPtr) fruitPtr->printDetails();
        else if (vegPtr) vegPtr->printDetails();
    }

    std::string getName() const {
        if (fruitPtr) return fruitPtr->getName();
        if (vegPtr) return vegPtr->getName();
        return "";
    }
};

// TotalSum Function
double TotalSum(GroceryItem* list, int size) {
    double total = 0.0;
    for (int i = 0; i < size; i++) {
        total += list[i].getItemSum();
    }
    return total;
}

int main() {
    int listSize = 4;

    // Dynamic Array Allocation
    GroceryItem* GroceryList = new GroceryItem[listSize];

    // Dynamic Assignment using Copy Assignment
    GroceryList[0] = GroceryItem(Fruit("Apple", 10.0, 7));
    GroceryList[1] = GroceryItem(Fruit("Banana", 10.0, 8));
    GroceryList[2] = GroceryItem(Vegetable("Broccoli", 60.0, 12));
    GroceryList[3] = GroceryItem(Vegetable("Lettuce", 50.0, 10));

    std::cout << "\nGrocery Details" << std::endl;
    for (int i = 0; i < listSize; i++) {
        GroceryList[i].print();
    }
    
    // Calling TotalSum
    std::cout << "Total Price: PHP " << TotalSum(GroceryList, listSize) << std::endl;

    int newSize = listSize - 1;
    GroceryItem* UpdatedGroceryList = new GroceryItem[newSize];

    int newIdx = 0;
    for (int i = 0; i < listSize; i++) {
        if (GroceryList[i].getName() != "Lettuce") {
            UpdatedGroceryList[newIdx] = GroceryList[i];
            newIdx++;
        } else {
            std::cout << "Removing Lettuce from Grocery List" << std::endl;
        }
    }

    // Deallocation
    delete[] GroceryList;
    GroceryList = UpdatedGroceryList;
    listSize = newSize;

    std::cout << "\nUpdated Grocery List" << std::endl;
    for (int i = 0; i < listSize; i++) {
        GroceryList[i].print();
    }

    std::cout << "\nUpdated Total Price: PHP " << TotalSum(GroceryList, listSize) << std::endl;

    delete[] GroceryList;

    return 0;
}
