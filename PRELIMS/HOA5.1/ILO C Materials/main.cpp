#include <iostream>
#include "printer.h"

int main(){

    Printer officePrinter;

    //Multiple users submit print jobs
    officePrinter.addJob(Job(101, "Alice", 5));
    officePrinter.addJob(Job(102, "Bob", 10));
    officePrinter.addJob(Job(103, "Charlie", 15));
    officePrinter.addJob(Job(104, "David", 20));
    officePrinter.addJob(Job(105, "Ethan", 15));

    officePrinter.displayJobs();

    std::cout << "\nProcessing Jobs...\n\n";

    officePrinter.processJob();
    officePrinter.processJob();
    officePrinter.processJob();
    officePrinter.processJob();
    officePrinter.processJob();
    officePrinter.processJob();

    return 0;
}