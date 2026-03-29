#include "Map.h"
#include <iostream>
#include <string>

int main() {
    Map<std::string, int> ages;

    // Create
    ages.Create("Alice", 30);
    ages.Create("Bob", 25);
    ages.Create("Charlie", 35);

    // Read
    std::cout << "Alice: " << ages["Alice"] << "\n";
    std::cout << "Bob: " << ages["Bob"] << "\n";

    // Update
    ages.Update("Bob", 26);
    std::cout << "Bob updated: " << ages["Bob"] << "\n";

    // Delete
    ages.Delete("Alice");
    std::cout << "After deleting Alice:\n";
    try {
        std::cout << "Alice: " << ages["Alice"] << "\n"; // may insert default
    } catch (const std::out_of_range& e) {
        std::cout << e.what() << "\n";
    }

    // Final state
    std::cout << "Charlie: " << ages["Charlie"] << "\n";

    return 0;
}
