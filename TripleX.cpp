#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty;
    std::cout << " secure server room...\nEnter the correct codes to continue. \n\n";
}

bool PlayGame(int Difficulty, int Chances)
{
    
    PrintIntroduction(Difficulty);
    
    // Declare and initialize variables for the 3 codes
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;
  
    // Ask the user to enter the 3 codes
    std::cout << "+ There are 3 numbers in the code." << std::endl;
    std::cout << "+ The codes add-up to: " << CodeSum << std::endl;
    std::cout << "+ The codes multiply to give: " << CodeProduct << std::endl;
    
    // Store player's guess in a variable
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if the player's guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n\t***  Great work agent! You have successfully broken into the room and have been granted access. ***\n\n";
        return true;
    }
    else
    {
        Chances--;
        if(Chances > 0)
        {
            std::cout << "\n\t***   You entered the wrong code! Careful, agent! You have " << Chances << " chances left. ***\n\n";
        }
        return false;
    }
}

int main()
{
    srand(time(NULL)); // Seed the random number generator
    int LevelDifficulty = 1;
    int const MaxDifficulty = 3;
    int Chances = 3;

    // Loop until all levels are completed
    while (LevelDifficulty <= MaxDifficulty && Chances > 0)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty, Chances);
        // fix error
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete)
        {
            // increase the level
            ++LevelDifficulty;
        } else {
            // decrease the chances
            --Chances;
        }
    }
    
    if (Chances == 0)
    {
        std::cout << "\n\n\t***  You have failed to break into the server room!  ***\n\n";
    } else
    {
        std::cout << "You have completed all " << MaxDifficulty << " levels.\n";
    }
    return 0;
}