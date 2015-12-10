#include <iostream>
using namespace std;

#include "IntList.h"

//Note: this function leaves the cursor at eol
void showList(IntList &list) {
    list.resetFront();
    while (!list.atEOL()) {
        cout << list.getCurrent() << " ";
        list.advance();
    }
    cout << endl;
}

int main() {
    IntList list;

    list.insert(2);
    list.insert(7);
    list.insert(12);

    // Display the values in the list
    showList(list);

    // cursor is now EOL, inserts 100 at the beginning
    list.insert(100);
    showList(list);

    // Test resetLast
    list.resetLast();
    cout << "Last elem " << list.getCurrent() << endl;

    // Remove last element
    list.remove();
    showList(list);

    // Test destroy
    list.destroy();
    if (list.isEmpty())
        cout << "list was destroyed" << endl;
    else
        cout << "Error: list was NOT destroyed!" << endl;

}
