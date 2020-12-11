// Macy So

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

/*void PrintArray(){
    int num[10]; // array
    int ranNum = 0;
    for (int i = 0; i < ranNum; i++){
        cout <<num [i] << " ";
    }
    cout << endl;
}*/

void FillArray(int num[], int size, int&ranNums){
    //int size ;
    cout << "Enter the length of the array: " ;
    cin >> ranNums ; // valid
    
    while (ranNums <= 0){
        cout << "Enter the length of the array: " ;
        cin >> ranNums ; // valid
    }
    if (ranNums > 0){
        srand((unsigned) time(0)) ;
        for (int i = 0; i <ranNums; i++){
            num[i] = rand() % 100  ; // a series of ranNum
            cout << num[i] << " " ;
        }
    }
    cout << endl << endl ;
    
}


void FindHighLowSumAvg(int num[ ], int&ranNums){
    int sum = 0;
    int average = 0;
    
    int largest = num [0] ;
    int smallest = num[0];
    
    if (ranNums < 0 || ranNums == 0){
        cout << "Array not yet created" << endl ;
    }
    else {
        for (int i = 0; i < ranNums ; i++){
            if (num[i] > largest )
                largest = num[i];
        
            if (num [i] < smallest )
                smallest = num[i];
        
            sum += num [i];
        }
    
        average = sum / ranNums ;
    
        cout << "The largest number is " << largest << endl;
        cout << "The smallest number is " << smallest << endl ;
        cout << "The sum is " << sum << endl ;
        cout << "The average is " << average << endl ;
    }
    cout << endl ;
}
// Add Number At End
void AddANumber(int num[ ], int size, int&ranNums){
    // Must check if the array is full, if so display a message indicating that. ** Still need workings **
    cout << "Enter a number to add: " ;
    int userNum ;
    cin >> userNum ;

    if (ranNums < 10){
        num[ranNums]  = userNum ;
        ranNums ++ ;
        size ++ ;
    }
    else {
        cout <<"array is full" << endl ;
    }
    
    
    for (int i = 0; i < ranNums; i++){
        cout << num [i] << " " ;
    }
    cout << endl  << endl ;
    
}

void FindNumber(int num[ ], int&ranNums, int number) {
    cout << "Enter the number to find: " ;
    int Num2Find = 0;
    cin >> Num2Find ;
    
    int i = 0;
    bool numFound = false;
    
    for (i = 0; i < ranNums; i++){
        if (num[i] == Num2Find){
            numFound = true ;
            cout << Num2Find <<"  is at index  "<< i  ;
            break ;
        }
    }
    
    if (numFound == false ){
        cout << Num2Find << " does not exist" ;
    }
    cout << endl ;
    for (int i = 0; i < ranNums; i++){
        cout << num [i] << " " ;
    }
    cout << endl  << endl ;
}
// Insert Number At Index
void insertAtIndex(int num[ ], int size, int&ranNums, int number, int index){
    cout << "Enter a number you want to insert: " ;
    cin >> number ;
    
    cout << "Enter a position where you want the number to be insert in: " ;
    cin >> index;
    
    if (ranNums < 10){
        if (index < ranNums && index >= 0 ){
            for (int i = ranNums - 1; i >= index-1 ; i--){
                num[i+1] = num[i]   ;
            }
            num[index] = number ;
        }
        num[index]  = number ;
        ranNums ++ ;
        cout <<"array is full"<< endl ;
    }
    else {
        cout <<"array is full"<< endl ;
    }
    //check that the specified index is valid, if not display a message like "invalid index" or similar.
   if (index >= ranNums){
        cout << "The specified index is outside the array" << endl ;
        cout << endl;
    }
    
    for (int i = 0; i <= ranNums-1; i++){
        cout << num[i] << " " ;
    }
    cout << endl  << endl ;
    // Must check if the array is full, if so display a message like "array is full" or similar. // DONE
}

void removeAtIndex(int num[ ], int&ranNums, int number, int index){
    
    cout << "Enter the position where you want the number to be deleted: " ;
    cin >> index ;
    
    if (index < ranNums+1 && index >= 0){
        for (int i = index ; i < ranNums - 1; i++){
            num [i] = num [i+1];
        }
    }
    else {
        cout << "Invalid position"  << endl ;
    }
    // check that the specified index is valid, if not display a message like "invalid index" or similar. //DONE
    
    for (int i = 0; i < ranNums-1 ; i++){
        cout << num [i] << " " ;
    }
    cout << endl << endl  ;

}

void removeNumber(int num[ ], int&ranNums, int number){
    cout << "Enter the number to remove: " ;
    cin >> number ;
    
    bool numFound = false;
    for (int i = 0; i < ranNums; i++){
        if (num[i] == number){
            numFound = true ;
            num[i] = num [i+1] ;
            break ;
        }
    }

    if (numFound == false){
        cout << number << " does not exist" << endl ;
    }
    cout << endl ;
    
    for (int i = 0; i < ranNums-1 ; i++){
        cout << num [i] << " " ;
    }
    cout << endl << endl ;

}

void plotHistogram(int num[ ], int& ranNums){
    for (int i = 0; i < ranNums ; i++){
        int dollarSign = num [i] / 10 ;
        for (int i = 0; i < dollarSign ; i++) {
            cout << "$" ;
        }
        int remainder = num [i] % 10 ;
        for (int i = 0 ; i < remainder; i++){
            cout << "*" ;
        }
        cout << endl;
    }
}

string PrintMenu (){
    int num[10]; // array
    int ranNums = 0;
    int choice ;
    int size = 0;
    int number = 0; // Find Number function
    int index = 0; // remove / insert function
    string choice1;

    do {
        cout << "0. Fill array" << endl ;
        cout << "1. Find high, low, sum average" << endl ;
        cout << "2. Add a number to the end" << endl ;
        cout << "3. Find the index of a number" << endl ;
        cout << "4. Insert number at index" << endl;
        cout << "5. Remove number " << endl ;
        cout << "6. Remove number at index" << endl ;
        cout << "7. Plot Histogram" << endl;
        cout << "8. Quit" << endl ;
        cin >> choice ;
    
        if (choice == 8){
            cout << "GoodBye." << endl ;
            break;
        }
        //void CreateArray(int num[], int size, int&ranNums)
        if (choice == 0){
            FillArray(num, size, ranNums); // DONE
        }
        //void findHighLowSum(int arr[ ], int &items)
        if (choice == 1){
            FindHighLowSumAvg(num, ranNums);  // DONE
        }
        //void addToEnd(int arr[ ], int size, int &items)
        if (choice == 2) {
            AddANumber(num, size, ranNums) ;  // DONE
        }
        //int findIndex(int arr[ ], int &items), int number)
        if (choice == 3){
            FindNumber(num, ranNums, number) ;  // DONE
        }
        //void insertAtIndex(int arr[ ], int size, int &items, int number, int index):
        if (choice == 4){
            insertAtIndex(num, size, ranNums, number, index ); // DONE
        }
        //void removeNumber(int arr[ ], int &items, int number)
        if (choice == 5){
            removeNumber(num, ranNums, number); // DONE
        }
        //void removeAtIndex(int arr[ ], int &items, int number, int index)
        if (choice == 6){
            removeAtIndex(num, ranNums, number, index); // DONE
        }
        if (choice == 7){
            plotHistogram(num, ranNums); // DONE
        }
    }
    while (choice != '0' || choice != '1' || choice != '2' || choice!= '3'|| choice != '4' || choice != '5' || choice != '6' || choice != '7');
    
    return choice1;
}

int main() {
    
    PrintMenu();
    
    return 0;
}

