#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;

void startGame()
{
    cout << "\n\n";
    cout << "________________________________________\n";
    cout << "______ Welcome To Octopus Academy ______\n";
    cout << "_______________ Math Game ______________\n";
    cout << "________________________________________\n";
    cout << "\n\n";
}

enum enQuestionLevel
{
    easy = 1,
    med,
    hard,
    mix
};
enum enOperationType
{
    add = 1,
    sub,
    mul,
    division,
    opMix
};

int NumberOfTimesPlayed()
{
    int numberOfTimes = 0;
    cout << "How Many Questions Do You Want To Answer? ";
    cin >> numberOfTimes;
    while (numberOfTimes <= 0)
    {
        cout << "Invalid number [" << numberOfTimes << "], try again: ";
        cin >> numberOfTimes;
    }
    return numberOfTimes;
}

int readQuestionLevel()
{
    int level;
    cout << "Enter Question Level [1] Easy [2] Med [3] Hard [4] Mix: ";
    cin >> level;
    while (level < 1 || level > 4)
    {
        cout << "Invalid level [" << level << "], try again: ";
        cin >> level;
    }
    return level;
}

int readOperationType()
{
    int op;
    cout << "Enter Operation Type [1] Add [2] Sub [3] Mul [4] division [5] Mix: ";
    cin >> op;
    while (op < 1 || op > 5)
    {
        cout << "Invalid operation [" << op << "], try again: ";
        cin >> op;
    }
    return op;
}

enQuestionLevel returnQuestionLevel(int level)
{
    return static_cast<enQuestionLevel>(level);
}

enOperationType returnOperationType(int op)
{
    return static_cast<enOperationType>(op);
}

int randomNumberForEasyLevel()
{
    return rand() % 10 + 1;
}

int randomNumberForMedLevel()
{
    return rand() % 100 + 1;
}

int randomNumberForHardLevel()
{
    return rand() % 1000 + 1;
}

int getRandomNumberByLevel(enQuestionLevel level)
{
    switch (level)
    {
    case easy:
        return randomNumberForEasyLevel();
    case med:
        return randomNumberForMedLevel();
    case hard:
        return randomNumberForHardLevel();
    default:
        return randomNumberForEasyLevel();
    }
}

enQuestionLevel getRandomQuestionLevel()
{
    return static_cast<enQuestionLevel>(rand() % 3 + 1);
}

enOperationType getRandomOperationType()
{
    return static_cast<enOperationType>(rand() % 4 + 1);
}

char getOperationSymbol(enOperationType opType)
{
    switch (opType)
    {
    case enOperationType::add:
        return '+';
    case enOperationType::sub:
        return '-';
    case enOperationType::mul:
        return '*';
    case enOperationType::division:
        return '/';
    default:
        return '?';
    }
}

bool askQuestion(enQuestionLevel level, enOperationType opType)
{
    int num1 = getRandomNumberByLevel(level);
    int num2 = getRandomNumberByLevel(level);

    if (opType == enOperationType::division)
    {
        while (num2 == 0)
        {
            num2 = getRandomNumberByLevel(level);
        }
        num1 = num1 * num2;
    }

    char opSymbol = getOperationSymbol(opType);
    int userAnswer;
    double correctAnswer;

    switch (opType)
    {
    case add:
        correctAnswer = num1 + num2;
        break;
    case sub:
        correctAnswer = num1 - num2;
        break;
    case mul:
        correctAnswer = num1 * num2;
        break;
    case division:
        correctAnswer = num1 / num2;
        break;
    default:
        correctAnswer = 0;
        break;
    }

    cout << "\n"
         << num1 << " " << opSymbol << " " << num2 << " = ";
    cin >> userAnswer;

    if (userAnswer == static_cast<int>(correctAnswer))
    {
        cout << "Right Answer :) \n";
        return true;
    }
    else
    {
        cout << "Wrong Answer :(, Correct is: " << correctAnswer << "\n";
        return false;
    }
}

int playAgain()
{
    int choice = 0;
    cout << "\n";
    cout << "Do You Want Play Again : \n";
    cout << "[1] Yes \n";
    cout << "[2] No \n";
    cout << "Enter Your Choice : ";
    cin >> choice;
    while (choice < 1 || choice > 2)
    {
        cout << "Your Choice [" << choice << "] InValid Choice \n";
        cout << "Enter Your Choice : ";
        cin >> choice;
    }
    system("cls");
    return choice;
}

void gameOver()
{
    cout << "\n\n";
    cout << "________________________________________\n";
    cout << "_____________G A M E O V E R____________\n";
    cout << "________________________________________\n";
    cout << "\n\n";
}

void mathGame()
{
    /*
    1 - easy 
    2 - med 
    3 - hard 
    4 - mix 
    */
   
    srand(time(0));
    startGame();
    do
    {
        int numQuestions = NumberOfTimesPlayed();
        enQuestionLevel level = returnQuestionLevel(readQuestionLevel());
        enOperationType opType = returnOperationType(readOperationType());

        int rightAnswers = 0;

        for (int i = 1; i <= numQuestions; i++)
        {
            cout << "\n---------- Question [" << i << "] ----------\n";

            enQuestionLevel currentLevel = (level == mix) ? getRandomQuestionLevel() : level;
            enOperationType currentOp = (opType == opMix) ? getRandomOperationType() : opType;

            if (askQuestion(currentLevel, currentOp))
            {
                rightAnswers++;
            }
        }

        cout << "\n========================================\n";
        cout << "You answered " << rightAnswers << " out of " << numQuestions << " correctly.\n";
        cout << "========================================\n";
    } while (playAgain() == 1);
    gameOver();
}

int main()
{
    mathGame();
    system("pause < 0");
    return 0;
}
