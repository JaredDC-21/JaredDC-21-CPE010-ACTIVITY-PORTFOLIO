#include <iostream>
#include <string>
#include "SUPP3_1_JDC_playlist_LL.h"

int main() {
    CircularList<std::string>* playlist = nullptr;

    cllInsertEnd(std::string("Song#1"), &playlist);
    cllInsertEnd(std::string("Song#2"), &playlist);
    cllInsertEnd(std::string("Song#3"), &playlist);
    cllInsertEnd(std::string("Song#4"), &playlist);

    std::cout << "Initial Playlist:\n";
    cllPlayAll(playlist);
    std::cout << std::endl;

    std::cout << "Adding 'Song#3' to the playlist:\n";
    cllInsertEnd(std::string("Song#3"), &playlist);
    cllPlayAll(playlist);
    std::cout << std::endl;

    std::cout << "Removing 'Song#2' from the playlist:\n";
    cllDeleteNode(std::string("Song#2"), &playlist);
    cllPlayAll(playlist);
    std::cout << std::endl;

    CircularList<std::string>* current = playlist;

    std::cout << "Currently Playing: " << current->data << "\n";
    cllPlayAll(playlist);

    current = cllNext(current);
    std::cout << "Next Song: " << current->data << "\n";

    current = cllNext(current);
    std::cout << "Next Song: " << current->data << "\n";

    current = cllPrevious(playlist, current);
    std::cout << "Previous Song: " << current->data << "\n";
    std::cout << std::endl;

    std::cout << "Removing Playslist:\n";
    cllDeleteList(&playlist);
    cllPlayAll(playlist);

    return 0;
}