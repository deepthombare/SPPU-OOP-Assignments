// Write C++ program using STL for sorting and searching user defined records such as Item
// records (Item code, name, cost, quantity etc) using vector container.
// Assignment  : 11

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

// Class Item
class Item
{
public:
    string name;
    int quantity{0};
    int cost{0};
    string code;

    bool operator==(const Item &i)
    {
        return code == i.code;
    }

};

// Vector declaration and methods

vector<Item> items;

void print(Item &i);
void display();
void insert();
void search();
void del();

bool compare(const Item &i1, const Item &i2)
{
    return i1.code < i2.code;
};

int main()
{
    int ch;
    do
    {
        cout << "\n---------------- Menu -----------------------\n";
        cout << "\n1.Add new Item";
        cout << "\n2.Display Items";
        cout << "\n3.Search an item";
        cout << "\n4.Sort all Items";
        cout << "\n5.Delete an item";
        cout << "\n6.Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;
        cin.ignore();
        switch (ch)
        {
        case 1:
            insert();
            break;

        case 2:
            display();
            break;

        case 3:
            search();
            break;

        case 4:
            sort(items.begin(), items.end(),compare);
            cout << "\nSorted on code";
            display();
            break;

        case 5:
            del();
            break;

        case 6:
            exit(0);
        }

    } while (ch < 7);

    return 0;
}

void insert()
{
    Item i1;
    cout << "\nEnter Item Name: ";
    getline(cin, i1.name);
    cout << "\nEnter Item Quantity: ";
    cin >> i1.quantity;
    cout << "\nEnter Item Cost: ";
    cin >> i1.cost;
    cout << "\nEnter Item Code: ";
    cin >> i1.code;
    items.push_back(i1);
}

void display()
{
    for_each(items.begin(), items.end(), print);
}

void print(Item &i1)
{
    cout << "\n\nItem Code:" << i1.code;
    cout << "\nItem Name:" << i1.name;
    cout << "\nItem Quantity:" << i1.quantity;
    cout << "\nItem Cost:" << i1.cost;

}

void search()
{
    vector<Item>::iterator p;
    Item i1;
    cout << "\nEnter Item Code to search:";
    cin >> i1.code;
    p = find(items.begin(), items.end(), i1);
    if (p == items.end())
    {
        cout << "\nNot found.";
    }
    else
    {
        cout << "\nFound.";
        print(*p);
    }
}

void del()
{
    vector<Item>::iterator p;
    Item i1;
    cout << "\nEnter Item Code to delete:";
    cin >> i1.code;
    p = find(items.begin(), items.end(), i1);
    if (p == items.end())
    {
        cout << "\nNot found.";
    }
    else
    {
        items.erase(p);
        cout << "\nDeleted.";
    }
}
