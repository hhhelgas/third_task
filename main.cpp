#include <iostream>
#include "List.h"


void printDoubleList(List<double>& list) {

    List<double>::Iterator it = list.begin();
    it.start();
    std::cout << std::endl << "List: ";
    while (!it.finish()) {
        std::cout << it.getElement() << " ";
        it.next();

    }
    std::cout << std::endl << "size:" << list.getSize() << std::endl;
}

List<double> getFilteredList(List<double> list, double d) {

    List<double> result;
    List<double>::Iterator it = list.begin();
    List<double>::Iterator resultIt = result.begin();
    it.start();
    while (!it.finish()) {
        if (it.getElement() > d) result.add(it.getElement(),&resultIt);
        it.next();
        resultIt.next();
    }
    return result;
}

int main() {

    List<double> list1;
    List<double>::Iterator it = list1.begin();
    it.start();
    for (double i = 1; i < 6; i++) {
        list1.add(i, &it);
        it.next();
    }
    printDoubleList(list1);
    it.start();
    while (!it.finish()) {
        list1.pop(&it);
    }
    printDoubleList(list1);
    for (double i = 1; i < 11; i++) {
        list1.add(i, &it);
        it.next();
    }
    printDoubleList(list1);
    double f = 11;
    List<double>::Iterator find = list1.findFirstInput(f);
    //std::cout << std::endl << "find 11: " << find.getElement();
    f = 5;
    find = list1.findFirstInput(f);
    std::cout << std::endl << "find 5: " << find.getElement();
    list1.clear();
    printDoubleList(list1);
    it = list1.begin();
    //try {
    //	list1.pop(&it);
    //}
    //catch (ListException& ex) {
    //	std::cout << ex.what();
    //}
    std::cout << std::endl << "List is empty: " << list1.isEmpty();
    printDoubleList(list1);
    for (double i = 1; i < 11; i++) {
        list1.add(i, &it);
        it.next();
    }
    List<double> filteredList;
    filteredList = getFilteredList(list1, 5);
    it = list1.begin();
    find = list1.findFirstInput(10);
    list1.pop(&find);
    printDoubleList(list1);
    printDoubleList(filteredList);
    list1 = filteredList;
    find = filteredList.findFirstInput(7);
    filteredList.pop(&find);
    printDoubleList(list1);
    printDoubleList(filteredList);
}