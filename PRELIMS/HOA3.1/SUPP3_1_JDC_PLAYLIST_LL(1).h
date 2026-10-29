#ifndef SUPP3_1_JDC_PLAYLIST_LL_H
#define SUPP3_1_JDC_PLAYLIST_LL_H

#include <iostream>

template <typename T>
class CircularList {
public:
    T data;
    CircularList<T> *next = nullptr;
};

template <typename T>
CircularList<T>* createNode(T newData) {
    CircularList<T>* newNode = new CircularList<T>;
    newNode->data = newData;
    newNode->next = newNode;
    return newNode;
}

template <typename T>
void cllInsertEnd(T newData, CircularList<T>** head) {
    CircularList<T>* newNode = new CircularList<T>;
    newNode->data = newData;

    if (*head == nullptr) {
        newNode->next = newNode;
        *head = newNode;
        return;
    }

    CircularList<T>* currentNode = *head;
    while (currentNode->next != *head) {
        currentNode = currentNode->next;
    }

    currentNode->next = newNode;
    newNode->next = *head;
}

template <typename T>
void cllDeleteNode(T findData, CircularList<T>** head) {
    if (*head == nullptr) return;

    CircularList<T>* currNode = *head;
    CircularList<T>* prevNode = nullptr;

    do {
        if (currNode->data == findData) break;
        prevNode = currNode;
        currNode = currNode->next;
    } while (currNode != *head);

    if (currNode->data != findData) {
        std::cout << "Song not found";
        return;
    }

    if (prevNode == nullptr) {
        CircularList<T>* lastNode = *head;
        while (lastNode->next != *head) {
            lastNode = lastNode->next;
        }
        lastNode->next = currNode->next;
        *head = currNode->next;
    } else {
        prevNode->next = currNode->next;
    }

    delete currNode;
}

template <typename T>
void cllPlayAll(CircularList<T>* head) {
    if (head == nullptr) {
        std::cout << "Playlist is Empty\n";
        return;
    }

    CircularList<T>* currentNode = head;
    do {
        std::cout << currentNode->data;
        currentNode = currentNode->next;
        if (currentNode != head) {
            std::cout << " -> ";
        }
    } while (currentNode != head);
    std::cout << " -> " << head->data << "\n";
}

template <typename T>
CircularList<T>* cllNext(CircularList<T>* currentSong) {
    if (currentSong == nullptr) return nullptr;
    return currentSong->next;
}

template <typename T>
CircularList<T>* cllPrevious(CircularList<T>* head, CircularList<T>* currentSong) {
    if (head == nullptr || currentSong == nullptr) return nullptr;

    CircularList<T>* temp = head;
    while (temp->next != currentSong) {
        temp = temp->next;
    }
    return temp;
}

template <typename T>
void cllDeleteList(CircularList<T>** head) {
    if (*head == nullptr) return;

    CircularList<T>* current = (*head)->next;
    while (current != *head) {
        CircularList<T>* temp = current;
        current = current->next;
        delete temp;
    }
    delete *head;
    *head = nullptr;
}

#endif  