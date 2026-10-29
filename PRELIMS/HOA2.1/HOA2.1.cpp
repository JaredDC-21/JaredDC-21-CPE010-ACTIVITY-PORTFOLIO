#include <iostream>
#include <string>

class Student{
	private:
		std::string studentName;
		int studentAge;
	public:
		//constructor
		Student(std::string newName = "John Doe", int newAge = 18){
			studentName = newName;
			studentAge = newAge;
			std::cout << "Constructor Called." << std::endl;
		};
		
		//Deconstructor
		~Student(){
			std::cout << "Destructor Called." << std::endl;
		}
		
		//Copy Constructor
		Student(const Student &copyStudent){
			std::cout << "Copy Constructor Called." << std::endl;
			studentName = copyStudent.studentName;
			studentAge = copyStudent.studentAge;
		}
		
		//Display Attributes
		void printDetails(){
			std::cout << this->studentName << "  " << this->studentAge << std::endl;
	}
};

int main(){
	const size_t j = 5;
	
	Student studentList[j] = {};
	std::string namesList[j] = {"Dylan", "Sophia", "Jared", "Kurt", "Brodie"};
	int ageList[j] = {21, 22, 20, 23, 25};
	
	for (int i = 0; i < j; i++) {
    studentList[i] = Student(namesList[i], ageList[i]);
    studentList[i] = *ptr;
    delete ptr;    // Frees the dynamically allocated object}
	}
	
	for(int i = 0; i < j; i++){ //loop B
		studentList[i].printDetails();
	}
	
	return 0;
}
