#include <iostream>
#include <queue>
#include <string>

void display(std::queue<std::string> copyQ);

int main(){
    //create an object
    std::queue<std::string> myQ;

    //array of students' names
    std::string students[] = {"Alice","Bob","Charlie","David"};

    //pass the array to the queue
    for(int i = 0; i < 4; i++){
        myQ.push(students[i]);
    }

    std::cout << "Displaying the list: ";
    display(myQ);

    //try all member functions

    //empty
    std::cout << "Is the list empty? A: ";
    if(myQ.empty()){
        std::cout << "Yes\n";
    }
    else{
        std::cout << "No\n";
    }

    //size
    std::cout << "What is the size of the queue? A: ";
    std::cout << "The queue size is: " << myQ.size() << "\n";

    //front
    std::cout << "What is the front? A: The front is = " << myQ.front() << "\n";

    //back
    std::cout << "What is the back? A: The back is = " << myQ.back() << "\n";

    //pop
    std::cout << "Removing: " << myQ.front() << "\n";
    myQ.pop();

    //display
    std::cout << "Displaying the list: ";
    display(myQ);

    //push
    std::string name;
    std::cout << "Enter a student name to push: ";
    std::getline(std::cin >> std::ws, name);

    myQ.push(name);
    std::cout << "Pushing: " << name << "\n";

    //display
    std::cout << "Displaying the list: ";
    display(myQ);

    return 0;
}

void display(std::queue<std::string> copyQ){
    std::queue<std::string> c = copyQ;

    while(!c.empty()){
        std::cout << " | " << c.front();
        c.pop();
    }

    std::cout << "\n";
}