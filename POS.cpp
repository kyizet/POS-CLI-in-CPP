#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// Utility Functions

/* search function */
template <typename list>
int search(list vector, int n, string item)
{
    for (int i = 0; i < n; i++){
        if (vector[i].getName() == item)
            return i;
      }
    return -1;
}

/* sort function */
// compulsory function for timsort
void insertionSort(string arr[], int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        string temp = arr[i];
        int j = i - 1;
        while (arr[j][0] > temp[0] && j >= left)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

// compulsory function for timsort
void merge(string arr[], int l, int m, int r)
{
    int len1 = m - l + 1, len2 = r - m;
    string left[len1], right[len2];
    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];

    int i = 0;
    int j = 0;
    int k = l;
    while (i < len1 && j < len2)
    {
        if (left[i][0] <= right[j][0])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < len1)
    {
        arr[k] = left[i];
        k++;
        i++;
    }

    while (j < len2)
    {
        arr[k] = right[j];
        k++;
        j++;
    }
}

const int RUN = 32;
void timSort(string arr[], int n)
{
    for (int i = 0; i < n; i+=RUN)
        insertionSort(arr, i, min((i+31), (n-1)));
    for (int size = RUN; size < n; size = 2*size)
    {
        for (int left = 0; left < n; left += 2*size)
        {
            int mid = left + size - 1;
            int right = min((left + 2*size - 1), (n-1));
            merge(arr, left, mid, right);
        }
    }
}

/* print function */
template <typename list>
void viewItems(list vector){
  int size = vector.size();
  string arr[size];
  for(int i = 0; i < size; i++){
    arr[i] = vector[i].getName();
  }
  timSort(arr, size);
  for(int i = 0; i < vector.size(); i++){
    cout << i+1 << ". " << arr[i]  << endl;
  }
}

class Coffee{
private:
  string name;
  string type;
  float price;
public:
  Coffee(){
    name = "coffeeName";
    type = "coffeeType";
    price = 0.0f;
  }


  Coffee(string cName, string cType, float cPrice){ // coffee name, coffee type, coffee price;
    name = cName;
    type = cType;
    price = cPrice;
  }
  //getters below
  string getName(){
    return name;
  }
  string getType(){
    return type;
  }
  float getPrice(){
    return price;
  }

  //setters below
  void setName(string cName){
    name = cName;
  }
  void setType(string cType){
    type = cType;
  }
  void setPrice(float cPrice){
    price = cPrice;
  }

};

class Snack{
private:
  string name;
  string type;
  float price;
public:
  Snack(){
    name = "snackName";
    type = "snackType";
    price = 0.0f;
  }


  Snack(string sName, string sType, float sPrice){ // snack name, snack type, snack price;
    name = sName;
    type = sType;
    price = sPrice;
  }
  //getters below
  string getName(){
    return name;
  }
  string getType(){
    return type;
  }
  float getPrice(){
    return price;
  }

  //setters below
  void setName(string sName){
    name = sName;
  }
  void setType(string sType){
    type = sType;
  }
  void setPrice(float sPrice){
    price = sPrice;
  }
};

class Juice{
private:
  string name;
  string type;
  float price;
public:
  Juice(){
    name = "coffeeName";
    type = "coffeeType";
    price = 0;
  }


  Juice(string jName, string jType, float jPrice){ // juice name, juice type, juice price;
    name = jName;
    type = jType;
    price = jPrice;
  }
  //getters below
  string getName(){
    return name;
  }
  string getType(){
    return type;
  }
  float getPrice(){
    return price;
  }

  //setters below
  void setName(string jName){
    name = jName;
  }
  void setType(string jType){
    type = jType;
  }
  void setPrice(float jPrice){
    price = jPrice;
  }
};


class Order{
private:
  string name;
  float price;
public:
  Order(){
    name = "orderItem";
    price = 0.0f;
  }
  Order(string oName, float oPrice){
    name = oName;
    price = oPrice;
  }
  //getters below
  string getName(){
    return name;
  }
  float getPrice(){
    return price;
  }
};

// vectors for objects
vector<Coffee> coffeeList;
vector<Snack> snackList;
vector<Juice> juiceList;

vector<Order> orderedItems;


class Admin : public Coffee, public Snack, public Juice{
private:
  char typeChoice; // To determine which information to be updated (Name, Price, Tag)
  int itemIndex; // to temporarily store the index of the item

  // item-specific variables
  string itemName;
  string itemType;
  float itemPrice;
public:
  void updateItem(char selection){
    switch(selection){
      case 'c':
      case 'C':
      cout << "Coffee List (Type = Coffee)" << endl;
      cout << "---------------------------" << endl;
      viewItems(coffeeList);

      cout << "Item you'd like to update(By Name): ";
      cin >> itemName;
      cout << endl;
      itemIndex = search(coffeeList, coffeeList.size(), itemName);
      if(itemIndex == -1){
        cout << "Item not found!" << endl;
        break;
      } else {
        cout << "Item found at number  " << itemIndex + 1 << endl;
      cout << "--------------------------" << endl;
        cout << "Name " << setw(30) << right << "\t-" << setw(20) << coffeeList[itemIndex].getName() << endl;
        cout << "Price " << setw(30) << right << "\t-" << setw(19) << "$" << coffeeList[itemIndex].getPrice() << endl;
        cout << "Type " << setw(30) << right << "\t-" << setw(20) << coffeeList[itemIndex].getType() << endl;
        cout << endl;
      }
      cout << "Updating an item" << endl;
      cout << "----------------" << endl;
      cout << "Information you'd like to update(N/P/T/A - Name/Price/Type/All): ";
      cin >> typeChoice;
      switch (typeChoice) {
        case 'n':
        case 'N':
        cout << "New name: ";
        cin >> itemName;
        coffeeList[itemIndex].setName(itemName);
        cout << "The name of the item has been successfully changed" << endl;
        break;

        case 'p':
        case 'P':
        cout << "New price: ";
        cin >> itemPrice;
        coffeeList[itemIndex].setPrice(itemPrice);
        cout << "The price of the item has been successfully changed";
        break;

        case 't':
        case 'T':
        cout << "New Type: ";
        cin >> itemType;
        coffeeList[itemIndex].setType(itemName);
        cout << "The type of the item has been successfully changed";
        break;

        case 'a':
        case 'A':
        cout << "New name: ";
        cin >> itemName;
        cout << "New Price: ";
        cin >> itemPrice;
        cout << "New Type: ";
        cin >> itemType;
        coffeeList[itemIndex].setName(itemName);
        coffeeList[itemIndex].setPrice(itemPrice);
        coffeeList[itemIndex].setType(itemType);
        cout << "All the information of the item has been successfully changed";
      }
        break;


        case 's':
        case 'S':
        cout << "Snack List (Type = Snack)" << endl;
        cout << "---------------------------" << endl;
        viewItems(snackList);

        cout << "Item you'd like to update(By Name): ";
        cin >> itemName;
        cout << endl;
        itemIndex = search(snackList, snackList.size(), itemName);
        if(itemIndex == -1){
          cout << "Item not found!" << endl;
          break;
        } else {
          cout << "Item found at number  " << itemIndex + 1 << endl;
          cout << "--------------------------" << endl;
          cout << "Name " << setw(30) << right << "\t-" << setw(20) << snackList[itemIndex].getName() << endl;
          cout << "Price " << setw(30) << right << "\t-" << setw(19) << "$" << snackList[itemIndex].getPrice() << endl;
          cout << "Type " << setw(30) << right << "\t-" << setw(20) << snackList[itemIndex].getType() << endl;
          cout << endl;
        }
        cout << "Updating an item" << endl;
        cout << "----------------" << endl;
        cout << "Information you'd like to update(N/P/T/A - Name/Price/Type/All): ";
        cin >> typeChoice;
        switch (typeChoice) {
          case 'n':
          case 'N':
          cout << "New name: ";
          cin >> itemName;
          snackList[itemIndex].setName(itemName);
          cout << "The name of the item has been successfully changed" << endl;
          break;

          case 'p':
          case 'P':
          cout << "New price: ";
          cin >> itemPrice;
          snackList[itemIndex].setPrice(itemPrice);
          cout << "The price of the item has been successfully changed";
          break;

          case 't':
          case 'T':
          cout << "New Type: ";
          cin >> itemType;
          snackList[itemIndex].setType(itemName);
          cout << "The type of the item has been successfully changed";
          break;

          case 'a':
          case 'A':
          cout << "New name: ";
          cin >> itemName;
          cout << "New Price: ";
          cin >> itemPrice;
          cout << "New Type: ";
          cin >> itemType;
          snackList[itemIndex].setName(itemName);
          snackList[itemIndex].setPrice(itemPrice);
          snackList[itemIndex].setType(itemType);
          cout << "All the information of the item has been successfully changed";
        }
          break;

          case 'j':
          case 'J':
          cout << "Juice List (Type = Juice)" << endl;
          cout << "---------------------------" << endl;
          viewItems(juiceList);

          cout << "Item you'd like to update(By Name): ";
          cin >> itemName;
          cout << endl;
          itemIndex = search(juiceList, juiceList.size(), itemName);
          if(itemIndex == -1){
            cout << "Item not found!" << endl;
            break;
          } else {
            cout << "Item found at number  " << itemIndex + 1 << endl;
            cout << "--------------------------" << endl;
            cout << "Name " << setw(30) << right << "\t-" << setw(20) << juiceList[itemIndex].getName() << endl;
            cout << "Price " << setw(30) << right << "\t-" << setw(19) << "$" << juiceList[itemIndex].getPrice() << endl;
            cout << "Type " << setw(30) << right << "\t-" << setw(20) << juiceList[itemIndex].getType() << endl;
            cout << endl;
          }
          cout << "Updating an item" << endl;
          cout << "----------------" << endl;
          cout << "Information you'd like to update(N/P/T/A - Name/Price/Type/All): ";
          cin >> typeChoice;
          switch (typeChoice) {
            case 'n':
            case 'N':
            cout << "New name: ";
            cin >> itemName;
            juiceList[itemIndex].setName(itemName);
            cout << "The name of the item has been successfully changed" << endl;
            break;

            case 'p':
            case 'P':
            cout << "New price: ";
            cin >> itemPrice;
            juiceList[itemIndex].setPrice(itemPrice);
            cout << "The price of the item has been successfully changed";
            break;

            case 't':
            case 'T':
            cout << "New Type: ";
            cin >> itemType;
            juiceList[itemIndex].setType(itemName);
            cout << "The type of the item has been successfully changed";
            break;

            case 'a':
            case 'A':
            cout << "New name: ";
            cin >> itemName;
            cout << "New Price: ";
            cin >> itemPrice;
            cout << "New Type: ";
            cin >> itemType;
            juiceList[itemIndex].setName(itemName);
            juiceList[itemIndex].setPrice(itemPrice);
            juiceList[itemIndex].setType(itemType);
            cout << "All the information of the item has been successfully changed";
            break;
          }

        default:
        cout << "Please type in one of the given initials!";
      }
    }

  void insertItem(char selection){
      cout << "Adding a new item" << endl;
      cout << "-----------------" << endl;
      cout << "Enter Information for a new item" << endl;
      cout << "--------------------------------" << endl;
      cout << "Name: ";
      cin >> itemName;
      cout << "Price: ";
      cin >> itemPrice;
      cout << "Type: ";
      cin >> itemType;

    switch(selection){
      case 'c':
      case 'C':
      {
      Coffee newCoffee(itemName, itemType, itemPrice);
      coffeeList.push_back(newCoffee);
      }
      cout << "New item has been added!" << endl << endl;
      break;

      case 's':
      case 'S':
      {
      Snack newSnack(itemName, itemType, itemPrice);
      snackList.push_back(newSnack);
      }
      cout << "New item has been added!" << endl << endl;
      break;

      case 'j':
      case 'J':
      {
      Juice newJuice(itemName, itemType, itemPrice);
      juiceList.push_back(newJuice);
      }
      cout << "New item has been added!" << endl << endl;
      break;
    }
  }

  void deleteItem(char selection){
    switch(selection){
      case 'c':
      case 'C':
      cout << "Coffee List (Type = Coffee)" << endl;
      cout << "---------------------------" << endl;
      viewItems(coffeeList);
      cout << endl << "Deleting an item" << endl;
      cout     <<     "----------------" << endl;

      cout << "Item you'd like to delete(By name): ";
      cin >> itemName;
      itemIndex = search(coffeeList, coffeeList.size(), itemName);
      {
      auto cIterator = next(coffeeList.begin(), itemIndex); // iterator for the vector
      coffeeList.erase(cIterator);
      }
      cout << "The item has been successfully deleted!" << endl << endl;
      break;

      case 's':
      case 'S':
      cout << "Snack List (Type = Snack)" << endl;
      cout << "---------------------------" << endl;
      viewItems(coffeeList);
      cout << endl << "Deleting an item" << endl;
      cout     <<     "----------------" << endl;

      cout << "Item you'd like to delete(By name): ";
      cin >> itemName;
      itemIndex = search(snackList, snackList.size(), itemName);
      {
      auto sIterator = next(snackList.begin(), itemIndex); // iterator for the vector
      snackList.erase(sIterator);
      }
      cout << "The item has been successfully deleted!" << endl << endl;
      break;

      case 'j':
      case 'J':
      cout << "Juice List (Type = Juice)" << endl;
      cout << "---------------------------" << endl;
      viewItems(juiceList);
      cout << endl << "Deleting an item" << endl;
      cout     <<     "----------------" << endl;

      cout << "Item you'd like to delete(By name): ";
      cin >> itemName;
      itemIndex = search(juiceList, juiceList.size(), itemName);
      {
      auto jIterator = next(juiceList.begin(), itemIndex); // iterator for the vector
      juiceList.erase(jIterator);
      }
      cout << "The item has been successfully deleted!" << endl << endl;
      break;

    }
  }
};

class Customer{
private:
    int itemIndex; // to temporarily store the index of the item
    int itemNumber; // to store the number of an item that the customer orders
    // item-specific variables
    string itemName;
    int itemQuantity; // to store the number of an item quantity
  public:
    void orderItem(char selection){
      switch (selection) {
        case 'c':
        case 'C':
        cout << "Ordering Coffee" << endl;
        cout << "----------------" << endl;
        cout << "Coffee List" << endl;
        cout << "-----------" << endl;
        viewItems(coffeeList);

        cout << "Coffee you want to order(By name): ";
        cin >> itemName;
        itemIndex = search(coffeeList, coffeeList.size(), itemName);
        if (itemIndex == -1){
          cout << "Please enter a valid item" << endl;
        }
        else {
          cout << "Quantity: ";
          cin >> itemQuantity;
          for(int i = 0; i < itemQuantity; i++){
            Order newOrder(coffeeList[itemIndex].getName(), coffeeList[itemIndex].getPrice());
            orderedItems.push_back(newOrder);
          }
          cout << "The item has been added" << endl << endl;
        }
        break;

        case 's':
        case 'S':
        cout << "Ordering Snack" << endl;
        cout << "----------------" << endl;
        cout << "Snack List" << endl;
        cout << "-----------" << endl;
        viewItems(snackList);

        cout << "Snack you want to order(By name): ";
        cin >> itemName;
        itemIndex = search(snackList, snackList.size(), itemName);
        if (itemIndex == -1){
          cout << "Please enter a valid item" << endl;
        }
        else {
          cout << "Quantity: ";
          cin >> itemQuantity;
          for(int i = 0; i < itemQuantity; i++){
            Order newOrder(snackList[itemIndex].getName(), snackList[itemIndex].getPrice());
            orderedItems.push_back(newOrder);
          }
          cout << "The item has been added" << endl << endl;
        }
        break;

        case 'j':
        case 'J':
        cout << "Ordering Juice" << endl;
        cout << "----------------" << endl;
        cout << "Juice List" << endl;
        cout << "-----------" << endl;
        viewItems(juiceList);

        cout << "Juice you want to order(By name): ";
        cin >> itemName;
        itemIndex = search(juiceList, juiceList.size(), itemName);
        if (itemIndex == -1){
          cout << "Please enter a valid item" << endl;
        }
        else {
          cout << "Quantity: ";
          cin >> itemQuantity;
          for(int i = 0; i < itemQuantity; i++){
            Order newOrder(juiceList[itemIndex].getName(), juiceList[itemIndex].getPrice());
            orderedItems.push_back(newOrder);
          }
          cout << "The item has been added" << endl << endl;
        }
        break;
    }
  }


    void checkout(){
      float totalPrice; // to store total price of items orderedItems
      char checker; // checker to checkout
      for(int i = 0; i < orderedItems.size(); i++){
        totalPrice += orderedItems[i].getPrice();
      }
      cout << "Items you ordered" << endl;
      cout << "-----------------" << endl;
      for(int i = 0; i < orderedItems.size(); i++){
        cout << i+1 << ". " << orderedItems[i].getName() << setw(40) << right << "\t-" << setw(20) << orderedItems[i].getPrice() << endl;
      }
      cout << "Total price: " << "$" << totalPrice << endl << endl;
      cout << "Checkout(Y/N): ";
      cin >> checker;
      if (checker == 'y' || checker == 'Y'){
        cout << "Your request has been accepted" << endl << endl;
      }
    }
};


int main(){
    cout << endl << endl;

    // Test values

    Coffee newCoffee1("Mocha", "Coffee", 14.99);
    Coffee newCoffee2("Latte", "Coffee", 12.99);
    Coffee newCoffee3("Espresso", "Coffee", 10.99);
    coffeeList.push_back(newCoffee1);
    coffeeList.push_back(newCoffee2);
    coffeeList.push_back(newCoffee3);

    Admin admin;
    Customer customer;

    char orderMore = 'y'; //to check if the user wants to order more items
    int logQuit; // to logout or to quit
    char goBack = 'y'; // to loop actions
    char selectUser; // to selectUser between admin and customer
    int action; // a function to be performed
    char selectCat; // to selectUser a category (Coffee/Snack/Juice)

    cout << " --------------------------" << endl;
    cout << "| Welcome to Coffee Circles |" << endl;
    cout << " --------------------------" << endl;


    while(selectUser != 'a' && selectUser != 'A' && selectUser != 'c' && selectUser != 'C') // y for logout
    {
      logQuit = 2; // resetting the value of logQuit
      cout << "User(A/C): ";
      cin >> selectUser;
      switch (selectUser) {

        //Admin Functions Start Here
        case 'a':
        case 'A':
        cout << "You have been logged in as an administrator" << endl << endl;

        goBack = 'y';
        while(goBack == 'y' || goBack == 'Y'){
          cout << "Actions" << endl;
          cout << "-------" << endl;
          cout << "1. Insert a new item" << endl;
          cout << "2. Update an item" << endl;
          cout << "3. Delete an item" << endl;
          cout << "4. View Items" << endl;
          while (action != 1 && action != 2 && action != 3 && action != 4){
            cout << "Choice(by number): ";
            cin >> action;
            if (action != 1 || action != 2 || action != 3 || action != 4){
              cout << "Invalid input" << endl << endl;
            }
          }

          cout << "Choose category" << endl;
          cout << "---------------" << endl;
          cout << "1. Coffee" << endl;
          cout << "2. Snack" << endl;
          cout << "3. Juice" << endl;
          while (selectCat != 'c' && selectCat != 'C' && selectCat != 's' && selectCat != 'S' && selectCat != 'j' && selectCat != 'J'){
            cout << "Choice(by initials C/S/J): ";
            cin >> selectCat;
            cout << endl;
            if (selectCat != 'c' && selectCat != 'C' && selectCat != 's' && selectCat != 'S' && selectCat != 'j' && selectCat != 'J'){
              cout << "Invalid input" << endl << endl;
            }
          }

          switch (action) {
            case 1:
            admin.insertItem(selectCat);
            break;
            case 2:
            admin.updateItem(selectCat);
            break;
            case 3:
            admin.deleteItem(selectCat);
            break;
            case 4:
            switch (selectCat) {
              case 'c':
              case 'C':
              cout << "Coffee List" << endl;
              cout << "-----------" << endl;
              viewItems(coffeeList);
              break;

              case 's':
              case 'S':
              cout << "Snack List" << endl;
              cout << "-----------" << endl;
              viewItems(snackList);
              break;

              case 'j':
              case 'J':
              cout << "Juice List" << endl;
              cout << "-----------" << endl;
              viewItems(juiceList);
              break;
            }
          }

          selectCat = 'y'; // resetting the variable to random value
          action = 5; // resetting the value by setting random number
          cout << "Go back to actions page(Y/N): ";
          cin >> goBack;
          cout << endl << endl;
        }

        cout << "The program has reached to the end" << endl;
        cout << "----------------------------------" << endl;
        cout << "1. Logout" << endl;
        cout << "2. Quit" << endl;
        cout << "Action: ";
        cin >> logQuit;
        if (logQuit == 1){
          selectUser = 'y';
        } else{
          selectUser = 'a';
        }
        break;

        // Customer Functions Start Here
        case 'c':
        case 'C':
        cout << "You have been logged in as a customer" << endl << endl;

        goBack = 'y';
        while(goBack == 'y' || goBack == 'Y'){
          cout << "Actions" << endl;
          cout << "-------" << endl;
          cout << "1. View Items" << endl;
          cout << "2. Order an item" << endl;
          cout << "3. Review Orders and Checkout" << endl;
          while (action != 1 && action != 2 && action != 3){
            cout << "Choice(by number): ";
            cin >> action;
            if (action != 1 || action != 2 || action != 3){
              cout << "Invalid input" << endl << endl;
          }
        }

        if (action == 1 || action == 2){
        cout << "Choose category" << endl;
        cout << "---------------" << endl;
        cout << "1. Coffee" << endl;
        cout << "2. Snack" << endl;
        cout << "3. Juice" << endl;
        while (selectCat != 'c' && selectCat != 'C' && selectCat != 's' && selectCat != 'S' && selectCat != 'j' && selectCat != 'J'){
          cout << "Choice(by initials C/S/J): ";
          cin >> selectCat;
          cout << endl;
          if (selectCat != 'c' && selectCat != 'C' && selectCat != 's' && selectCat != 'S' && selectCat != 'j' && selectCat != 'J'){
            cout << "Invalid input" << endl << endl;
          }
        }
        }

        switch (action) {
          case 1:
          switch (selectCat) {
            case 'c':
            case 'C':
              cout << "Coffee List" << endl;
              cout << "-----------" << endl;
              viewItems(coffeeList);
              break;

            case 's':
            case 'S':
              cout << "Snack List" << endl;
              cout << "-----------" << endl;
              viewItems(snackList);
              break;

            case 'j':
            case 'J':
              cout << "Juice List" << endl;
              cout << "-----------" << endl;
              viewItems(juiceList);
              break;
            }
            break;

            case 2:
              while (orderMore == 'y' || orderMore == 'Y'){
                customer.orderItem(selectCat);
                cout << "Order more(Y/N): ";
                cin >> orderMore;
                cout << endl;
              }
              break;

            case 3:
              customer.checkout();
              break;
          }

        selectCat = 'y'; // resetting the variable to random value
        action = 5; // resetting the value by setting random number
        cout << "Go back to actions page(Y/N): ";
        cin >> goBack;
        cout << endl << endl;
        }

        cout << "The program has reached to the end" << endl;
        cout << "----------------------------------" << endl;
        cout << "1. Logout" << endl;
        cout << "2. Quit" << endl;
        cout << "Action: ";
        cin >> logQuit;
        if (logQuit == 1){
          selectUser = 'y';
        } else{
          selectUser = 'a';
        }
        break;

        default:
        cout << "Invalid user" << endl;

      cout << endl << endl;
    }


    cout << endl << endl;
}
}
