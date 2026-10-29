#include <iostream>
#include <time.h>
#include <cstdlib>
#include <string>
#include "sorting.h"

int main(){
    system("chcp 65001 > nul");

    const int size = 100;
    int randomArray[size];

    srand(time(0));

    for (int i = 0; i < size; ++i) {
        randomArray[i] = rand() % 100 + 1;
    }

    std::cout << "Unsorted and Random: \n";
    displayArray(randomArray, size);

    std::cout << "\n\nBubble Sort: \n";
    bubbleSort<int>(randomArray, size);
    displayArray(randomArray, size);

    std::cout << "\n\nSelection Sort: \n";
    selectionSort<int>(randomArray, size);
    displayArray(randomArray, size);

    std::cout << "\n\nInsertion Sort: \n";
    insertionSort<int>(randomArray, size);
    displayArray(randomArray, size);


    const int voteSize = 100;
    int votes[voteSize];

    std::string candidates[5] = {
        "Bo Dalton Capistrano",
        "Cornelius Raymon Agustín",
        "Deja Jayla Bañaga",
        "Lalla Brielle Yabut",
        "Franklin Relano Castro"
    };

    srand(12345);

    for (int i = 0; i < voteSize; i++) {
        votes[i] = rand() % 5 + 1;
    }

    std::cout << "\n\nUnsorted Votes:\n";
    displayArray(votes, voteSize);
    std::cout << "\n\n";

    insertionSort(votes, voteSize);

    std::cout << "Sorted Votes:\n";
    displayArray(votes, voteSize);
    std::cout << "\n\n";

    int voteCount[5] = {0};

    for (int i = 0; i < voteSize; i++) {
        voteCount[votes[i] - 1]++;
    }

    std::cout << "===== ELECTION VOTING RESULTS =====\n";

    int winner = 0;

    for (int i = 0; i < 5; i++) {
        std::cout << "Candidate " << i + 1 << ": "
                  << candidates[i] << " - "
                  << voteCount[i] << " votes\n";

        if (voteCount[i] > voteCount[winner]) {
            winner = i;
        }
    }

    std::cout << "\nWINNER:\n";
    std::cout << candidates[winner]
              << " with " << voteCount[winner]
              << " votes.\n";

    return 0;
}