#include<iostream>
using namespace std;

// Function to clear the console screen
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
// Function to display colored text
void coloredText(const char* text, const char* colorCode) {
    cout << "\033[" << colorCode << "m" << text << "\033[0m";
}

// Function to print the welcome message with design
void printWelcomeMessage() {
    clearScreen();
    
    // Print top border
    coloredText("***************************************", "1;33"); // Yellow
    
    // Print welcome message
    cout << endl;
    coloredText("*                                      *", "1;34"); // Blue
    cout << endl;
    coloredText("*   Welcome to Ice Cream Shop !      *", "1;35"); // Magenta
    cout << endl;
    coloredText("*                                      *", "1;32"); // Green
    cout << endl;
    
    // Print bottom border
    coloredText("***************************************", "1;31"); // Red
    
    cout << endl << endl;
}

class Customer_order{
	private:
	int cart;
	int item_code[10];

	public:
		
	 void menu(void){
       clearScreen();
        coloredText("Select an Item using its code:", "1;33"); // Yellow
        cout << endl;
        coloredText("1. Vanilla Ice Cream      (20 PKR)", "1;35"); // Magenta
        cout << endl;
        coloredText("2. Chocolate Ice Cream    (30 PKR)", "1;31"); // Red
        cout << endl;
        coloredText("3. Strawberry Ice Cream   (40 PKR)", "1;34"); // Blue
        cout << endl;
        coloredText("4. Blueberry Ice Cream    (50 PKR)", "1;32"); // Green
        cout << endl;
        coloredText("5. Mango Ice Cream        (60 PKR)", "1;36"); // Cyan
        cout<<endl;
    }
	
		void quantity(void){
		cout<<"How many Ice Creams would You like to order : ";
		cin>>cart;
		if(10<cart){
			cout<<"You Can Maximum Order 10 Ice Cream "<<endl;
			cart=10;
		}
	}	
	
	void getdata(void){
		for(int i=0; i<cart;i++){
		cout<<"Select a Item using its code:";
		cin>>item_code[i];
  	  }
	}
	
	void billing(void){
		int price =0;
		 for (int i = 0; i < cart; i++) {
		switch(item_code[i]){
			case 1:
				price += 20;
			break;
			case 2:
				price += 30; 
			break;
			case 3:
				price += 40;
			break;
			case 4:
				price += 50;
			break;
			case 5:
				price += 60;
			break;
			default:
            cout << "Invalid item code: " << item_code[i] << endl;
            break;
		}
	}
	 cout << "Your total is: " << price << " PKR" << endl;		
	}	
};

class Branch_manager{
	
private:	
	int ice1=200,ice2=300,ice3=400,ice4=500,ice5=600;
	
public:
  void inventory(void){
        clearScreen();
        coloredText("Current Inventory:", "1;33");
        cout << endl;
        coloredText("1. Vanilla Ice Cream      (", "1;35");
        cout << ice1 << " in Stock)" << endl;
        coloredText("2. Chocolate Ice Cream    (", "1;31");
        cout << ice2 << " in Stock)" << endl;
        coloredText("3. Strawberry Ice Cream   (", "1;34");
        cout << ice3 << " in Stock)" << endl;
        coloredText("4. Blueberry Ice Cream    (", "1;32");
        cout << ice4 << " in Stock)" << endl;
        coloredText("5. Mango Ice Cream        (", "1;36");
        cout << ice5 << " in Stock)" << endl;
    }
	
	void update_inventory(void){
		
		int choice, quantity;
            cout << "Enter the item code to update stock (1-5): ";
            cin >> choice;
            cout << "Enter the new stock quantity: ";
            cin >> quantity;

            switch (choice) {
                case 1:
                    ice1 += quantity;
                    break;
                case 2:
                    ice2 += quantity;
                    break;
                case 3:
                    ice3 += quantity;
                    break;
                case 4:
                    ice4 += quantity;
                    break;
                case 5:
                    ice5 += quantity;
                    break;
                default:
                    cout << "Invalid item code!" << endl;
                    return;
            }
            cout <<endl<< "Inventory updated successfully!" << endl;
        }
	};
	

int main(){
//	cout<<"Welcome to Ice Cream Shop !"<<endl<<endl;
	printWelcomeMessage();
	int choice;
	jump:
	cout<<"Press 1 to enter as Customer or Press 2 to enter as Branch Manager  : ";
	cin>>choice;
	if (choice==1){
	Customer_order shop;
	shop.menu();
	shop.quantity();
	shop.getdata();
	shop.billing();
}
else if (choice == 2){
	Branch_manager manager;
int option;
jump2:
jump3:
cout<<"Enter 1 to check inventory or Enter 2 to Update the inventory  or click 0 to quit :  ";
cin>>option;

if(option==1){
    manager.inventory();
    goto jump2;
}

else if(option==2){
    manager.update_inventory();
   goto jump3;
}
    cout<<endl<<endl<<"Updated Quantity of stock"<<endl<<endl;
    //manager.inventory();  // Display updated inventory	      
}
else if( choice !=1 || choice !=2){
	cout<<"Invalid Input "<<endl;
	goto jump;
}		
}