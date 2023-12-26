#include <iostream>
#include <vector>
#include <string.h>
using namespace std;


vector<string> content = {"tshirts","shoes","glasses"};


class Stock{

 public:
     int tshirts = 20;
     int shoes = 45;
     int glasses = 15;

     int Shopping(int productId, int amount){

      if(productId == 0 && checkAmount(tshirts,amount)){

            tshirts -= amount;

      }else if(productId == 1 && checkAmount(shoes,amount)){

            shoes -= amount;

      }else if(productId == 2 && checkAmount(glasses,amount)){


            glasses -= amount;


      }else{


        return 0;

      }
      return 1;


     }
     bool checkAmount(int stock,int amount){

         if (stock >= amount){
            return true;
         }else{

         return false;

         }


     }





};

class OrderRegistration : public Stock{

 public:
     vector<string> people;
     vector<string> product;
     vector<int> number;


     void registerPerson(string name, int productId, int amount){

      if(Shopping(productId,amount)){

        people.push_back(name);

        product.push_back(content[productId]);

        number.push_back(amount);


      }else{

      cout << "Not enough stock";

      }


     }

     void printList(){

     for(int i = 0; i < number.size();i++){

        cout << "Name: " << people[i] << "-->Product: "  << product[i] << " -->Amount: " << number[i] << endl;


     }

     }

};


int main()
{

    OrderRegistration order;
    string name;
    int productID;
    int amount;
    int check;
    cout << " 0: Tshirts\n 1: Shoes \n 2:Glasses\n";
    cout << "Name: ";
    cin >> name;
    cout << "ProductId: ";
    cin >> productID;
    cout<< "Amount to buy: ";
    cin >> amount;
    order.registerPerson(name,productID,amount);
    cout << "\nTo continue press 1 otherwise press 0: ";
    cin >> check;
    while(check){
    cout << " 0: Tshirts\n 1: Shoes \n 2:Glasses\n";
    cout << "Name: ";
    cin >> name;
    cout << "ProductId: ";
    cin >> productID;
    cout<< "Amount to buy: ";
    cin >> amount;
    order.registerPerson(name,productID,amount);
    cout << "\nTo continue press 1 otherwise press 0: ";
    cin >> check;

    }

    order.printList();










    return 0;
}
