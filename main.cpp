#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{

    string words[] = {"france", "canada", "russia", "poland", "berlin", "sydney", "london", "madrid", "norway"};
    int wordCount = 9;


    srand(time(0));
    string word = words[rand() % wordCount];

    string guess(word.length(), '_');
    int lives = 3;

    while (lives > 0 && guess != word) {
        cout << "\nWord: " << guess << endl;
        cout << "Lives remaining: " << lives << endl;
        cout << "Guess a letter: ";

        char letter;
        cin >> letter;
        letter = tolower(letter);

        bool found = false;
        for (int i = 0; i < word.length(); i++) {
            if (word[i] == letter) {
                guess[i] = letter;
                found = true;
            }
        }

        if (!found) {
            lives--;
            cout << "Wrong guess!\n";
        }
    }

    if (guess == word) {
        cout << "\nCongratulations! You Win! The word was: " << word << endl;
    } else {
        cout << "\nYou Lose! The word was: " << word << endl;
    }

    return 0;
}

