#include <iostream>
// 3-3. Add an Element* previous to Listing 3-9 to make a doubly linked list. Add an insert_before method to Element. Traverse the
// list from front to back, then from back to front, using two separate forloops. Print the operating_number inside each loop.

struct Element {
    Element* next{};
    Element* previous{};
    Element(const char p[], short nmb)
        : operating_number{ nmb } {
        prefix[0] = p[0];
        prefix[1] = p[1];
    };
    void insert_after(Element* new_element) {
        new_element->next = next;
        if(next) {
            next->previous = new_element;
        }
        new_element->previous = this;
        next = new_element;
    }
    void insert_before(Element* new_element) {
        new_element->next = this;
        new_element->previous = previous;
        if(previous) {
            previous->next = new_element;
        }
        previous = new_element;
    }
    char prefix[2];
    short operating_number;
};

void printForwardAndBackward(Element e1, Element e2) {
    std::cout << "Forward \n";
    for(Element* cursor = &e1; cursor; cursor = cursor->next) {
        printf("Storm Trooper %c%c-%d\n", cursor->prefix[0], cursor->prefix[1], cursor->operating_number);
    }
    std::cout << "Backward \n";
    for(Element* cursor = &e2; cursor; cursor = cursor->previous) {
        printf("Storm Trooper %c%c-%d\n", cursor->prefix[0], cursor->prefix[1], cursor->operating_number);
    }
}

int main() {
    // Element trooper1,  trooper2, trooper3;
    Element trooper1{ "TK", 421 };
    Element trooper2{ "FN", 2187 };
    Element trooper3{ "LS", 5 };
    trooper1.insert_after(&trooper2);
    trooper2.insert_after(&trooper3);
    printForwardAndBackward(trooper1, trooper3);
    Element trooper4{ "44", 44 };
    Element trooper5{ "55", 55 };
    trooper1.insert_before(&trooper4);
    trooper3.insert_before(&trooper5);
    printForwardAndBackward(trooper4, trooper3);
}