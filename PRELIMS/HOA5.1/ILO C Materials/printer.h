#ifndef PRINTER_H
#define PRINTER_H

#include <iostream>
#include <string>

class Job{
public:
    int id;
    std::string user;
    int pages;

    Job(){
        id = 0;
        user = "";
        pages = 0;
    }

    Job(int id, std::string user, int pages){
        this->id = id;
        this->user = user;
        this->pages = pages;
    }
};

class Node{
public:
    Job data;
    Node* next;
};

class Printer{
private:
    Node* front;
    Node* back;

public:

    Printer(){
        front = nullptr;
        back = nullptr;
    }

    //Add a new print job
    void addJob(Job newJob){
        //Creates a new node for the new job and inserts data
        Node* newNode = new Node;
        newNode->data = newJob;
        newNode->next = nullptr;

        //Enqueuing on an empty queue
        if(front == nullptr){
            front = newNode;
            back = newNode;
            return;
        }

        //Enqueuing on a non-empty queue
        back->next = newNode;
        back = newNode;
    }

    //Process one print job
    void processJob(){
        //If there are no queue
        if(front == nullptr){
            std::cout << "No print jobs remaining.\n";
            return;
        }

        //creates a temp node to access the current front
        Node* temp = front;

        //accessing the current front
        std::cout << "Printing Job #" << temp->data.id
                  << " | User: " << temp->data.user
                  << " | Pages: " << temp->data.pages << '\n';

        //proceeds to the next in queue
        front = front->next;

        //if the queue is now empty, set back to nullptr
        if(front == nullptr){
            back = nullptr;
        }

        delete temp;
    }

    //Display all pending jobs
    void displayJobs(){
        //returns if the queue is empty
        if(front == nullptr){
            std::cout << "Printer Queue is Empty.\n";
            return;
        }

        //creates a node for the current node
        Node* current = front;

        std::cout << "\nPending Print Jobs\n";

        //iterates through the whole queue
        while(current != nullptr){
            std::cout << "Job #" << current->data.id
                      << " | User: " << current->data.user
                      << " | Pages: " << current->data.pages << '\n';
            current = current->next;
        }

        std::cout << '\n';
    }
};

#endif