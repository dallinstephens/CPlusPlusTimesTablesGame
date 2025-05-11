#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib> // Needed for rand() and srand()
#include <ctime>   // Needed for time()
#include <cmath>
#include <chrono>
#include <thread>
using namespace std;
using namespace sf;

const Font font("C:/Users/Dallin_Stephens/Documents/BYU-I Courses/CSE 310 Applied Programming/CPlusPlusTimesTablesGame/arialuni.ttf");

// Create a vector called timesTables that will store strings.
vector<string> timesTables;
string numberString;

int xTimesTable;
string xTimesTableString;

vector<int> timesTablesAnswers;

bool incorrectAnswer;

int xTimesTableInput;
int xlevelInput;

void initializeGame(int timeTableX, int level) {
    // Reference to get a different random number each time the program runs:
    // https://www.w3schools.com/cpp/cpp_howto_random_number.asp
    // Get a different random number each time the program runs
    srand(time(0));
    xTimesTable = timeTableX;
    xTimesTableString = to_string(xTimesTable);
    level += 1; // At level 12 for example, the number actually needs to be 13 instead of 12.

    for (int i = 0; i < level; i++) {
        numberString = to_string(i);
        if (i == 0) {
            timesTables.push_back(xTimesTableString + " X " + numberString);
            timesTablesAnswers.push_back(xTimesTable * i);
        }
        else {
            timesTables.push_back(numberString + " X " + xTimesTableString);
            timesTables.push_back(xTimesTableString + " X " + numberString);
            timesTablesAnswers.push_back(i * xTimesTable);
            timesTablesAnswers.push_back(xTimesTable * i);
        }
    }
}

void openMenuWindow() {
    // Reference for SFML window text:
    // https://www.sfml-dev.org/tutorials/3.0/graphics/text/#loading-a-font
    Text timesTableQuestion(font); // a font is required to make a text object
    Text exitGame(font);

    // set the string to display
    timesTableQuestion.setString("Enter a letter for times table:\n"
        "A.  1\n"
        "B.  2\n"
        "C.  3\n"
        "D.  4\n"
        "E.  5\n"
        "F.  6\n"
        "G.  7\n"
        "H.  8\n"
        "I.   9\n"
        "J. 10\n"
        "K. 11\n"
        "L. 12"
    );

    string difficultyLevel = "Enter a letter for difficulty level:\n"
        "Easiest is 1 and hardest is 12.\n"
        "M.  1\n"
        "N.  2\n"
        "O.  3\n"
        "P.  4\n"
        "Q.  5\n"
        "R.  6\n"
        "S.  7\n"
        "T.  8\n"
        "U.  9\n"
        "V. 10\n"
        "W. 11\n"
        "X. 12";

    exitGame.setString("To exit the game, press \"Q\" to quit.");
    
    // set the character size
    timesTableQuestion.setCharacterSize(24); // in pixels, not points!
    exitGame.setCharacterSize(24);
    
    // set the color
    timesTableQuestion.setFillColor(sf::Color::Red);
    exitGame.setFillColor(Color::Green);
    
    // set the text style
    timesTableQuestion.setStyle(Text::Bold);
    exitGame.setStyle(sf::Text::Bold);

    // Reference on how to set position:
    // https://www.sfml-dev.org/tutorials/3.0/graphics/transform/
    timesTableQuestion.setPosition({200.f, 70.f});
    exitGame.setPosition({200.f, 20.f});

    RenderWindow windowMenu(VideoMode({800, 600}), "Menu");

    while (windowMenu.isOpen())
    {
        while (const std::optional event = windowMenu.pollEvent())
        {
            // Used to close the window.
            Vector2i localPosition = Mouse::getPosition(windowMenu);
            if (event->is<Event::Closed>()) {
                windowMenu.close();
            }
            else if (Keyboard::isKeyPressed(Keyboard::Key::A)) {
                timesTableQuestion.setString(difficultyLevel);
                xTimesTableInput = 1;                                                                                                              
            }
            else if (Keyboard::isKeyPressed(Keyboard::Key::B)) {
                timesTableQuestion.setString(difficultyLevel);
                xTimesTableInput = 2;                                                                                                                 
            }
            else if (Keyboard::isKeyPressed(Keyboard::Key::C)) {
                timesTableQuestion.setString(difficultyLevel);
                xTimesTableInput = 3;                                                                                                                
            }
            else if (Keyboard::isKeyPressed(Keyboard::Key::D)) {
                timesTableQuestion.setString(difficultyLevel);
                xTimesTableInput = 4;                                                                                                               
            }
            else if (Keyboard::isKeyPressed(Keyboard::Key::E)) {
                timesTableQuestion.setString(difficultyLevel);
                xTimesTableInput = 5;                                                                                        
            }
            else if (Keyboard::isKeyPressed(Keyboard::Key::F)) {
                timesTableQuestion.setString(difficultyLevel);
                xTimesTableInput = 6;                                                                                         
            }
            else if (Keyboard::isKeyPressed(Keyboard::Key::G)) {
                timesTableQuestion.setString(difficultyLevel);
                xTimesTableInput = 7;                                                                                      
            }
            else if (Keyboard::isKeyPressed(Keyboard::Key::H)) {
                timesTableQuestion.setString(difficultyLevel);
                xTimesTableInput = 8;                                                                                          
            }
            else if (Keyboard::isKeyPressed(Keyboard::Key::I)) {
                timesTableQuestion.setString(difficultyLevel);
                xTimesTableInput = 9;                                                                                              
            }
            else if (Keyboard::isKeyPressed(Keyboard::Key::J)) {
                timesTableQuestion.setString(difficultyLevel);
                xTimesTableInput = 10;                                                                                                 
            }                                                                                                
            else if (Keyboard::isKeyPressed(Keyboard::Key::K)) {
                timesTableQuestion.setString(difficultyLevel);
                xTimesTableInput = 11;                                                                                               
            }
            else if (Keyboard::isKeyPressed(Keyboard::Key::L)) {
                timesTableQuestion.setString(difficultyLevel);
                xTimesTableInput = 12;                                                                                                      
            }
            else if (Keyboard::isKeyPressed(Keyboard::Key::M) && xTimesTableInput >= 1 && xTimesTableInput <=12) {
                xlevelInput = 1;       
                windowMenu.close();
            }
            else if (Keyboard::isKeyPressed(Keyboard::Key::N) && xTimesTableInput >= 1 && xTimesTableInput <=12) {
                xlevelInput = 2;       
                windowMenu.close();
            } 
            else if (Keyboard::isKeyPressed(Keyboard::Key::O) && xTimesTableInput >= 1 && xTimesTableInput <=12) {
                xlevelInput = 3;       
                windowMenu.close();
            }
            else if (Keyboard::isKeyPressed(Keyboard::Key::P) && xTimesTableInput >= 1 && xTimesTableInput <=12) {
                xlevelInput = 4;       
                windowMenu.close();
            } 
            else if (Keyboard::isKeyPressed(Keyboard::Key::Q) && xTimesTableInput >= 1 && xTimesTableInput <=12) {
                xlevelInput = 5;       
                windowMenu.close();
            }   
            else if (Keyboard::isKeyPressed(Keyboard::Key::R) && xTimesTableInput >= 1 && xTimesTableInput <=12) {
                xlevelInput = 6;       
                windowMenu.close();
            } 
            else if (Keyboard::isKeyPressed(Keyboard::Key::S) && xTimesTableInput >= 1 && xTimesTableInput <=12) {
                xlevelInput = 7;       
                windowMenu.close();
            } 
            else if (Keyboard::isKeyPressed(Keyboard::Key::T) && xTimesTableInput >= 1 && xTimesTableInput <=12) {
                xlevelInput = 8;       
                windowMenu.close();
            }
            else if (Keyboard::isKeyPressed(Keyboard::Key::U) && xTimesTableInput >= 1 && xTimesTableInput <=12) {
                xlevelInput = 9;       
                windowMenu.close();
            } 
            else if (Keyboard::isKeyPressed(Keyboard::Key::V) && xTimesTableInput >= 1 && xTimesTableInput <=12) {
                xlevelInput = 10;       
                windowMenu.close();
            } 
            else if (Keyboard::isKeyPressed(Keyboard::Key::W) && xTimesTableInput >= 1 && xTimesTableInput <=12) {
                xlevelInput = 11;       
                windowMenu.close();
            } 
            else if (Keyboard::isKeyPressed(Keyboard::Key::X) && xTimesTableInput >= 1 && xTimesTableInput <=12) {
                xlevelInput = 12;       
                windowMenu.close();
            }
            else if (Keyboard::isKeyPressed(Keyboard::Key::Q) && xTimesTableInput == 0) {
                xTimesTableInput = 10;
                xlevelInput = 12;
                windowMenu.close();
            }
        }

        windowMenu.clear();
            // inside the main loop, between window.clear() and window.display()
        windowMenu.draw(timesTableQuestion);
        windowMenu.draw(exitGame);
        windowMenu.display();
    }
}

int main()
{  
    openMenuWindow();
    initializeGame(xTimesTableInput, xlevelInput);

    // Reference to get a different random number each time the program runs:
    // https://www.w3schools.com/cpp/cpp_howto_random_number.asp
    // Get a different random number each time the program runs
    // srand(time(0));
    // int timeTableX = 2;
    // xTimesTable = timeTableX;
    // xTimesTableString = to_string(xTimesTable);

    
    // for (string timesTable : timesTables) {
    //   cout << timesTable << "\n";
    // }
    
    // cout << endl;
    
    // for (int timesTablesAnswer : timesTablesAnswers) {
    //   cout << timesTablesAnswer << "\n";
    // }

    // vector<string> timesTables = {"1 X 2", "2 X 1","2 X 3", "3 X 2"};
    vector<string> timesTablesManipulated = timesTables;
    // vector<int> timesTablesAnswers = {2, 2, 6, 6};
    vector<int> timesTablesManipulatedAnswers = timesTablesAnswers;
    // Reference for vector:
    // https://www.w3schools.com/cpp/cpp_vectors.asp
    vector<int> firstNumber;
    vector<int> secondNumber;
    vector<int> randomAnswer;
    int j = 0;
    
    while (timesTablesManipulated.size() >= 1) {
        // Display all elements in the timesTable vector.
        // Reference to iterate through each element in a vector:
        // https://www.w3schools.com/cpp/cpp_vectors.asp
        cout << "Elements in the times tables vector: " << endl;
        for (int i = 0; i < timesTablesManipulated.size(); i++) {
            cout << timesTablesManipulated[i] << "\n";
        }
        
        // Generate a random index between 0 and timesTablesManipulated.size() - 1
        int randomIndex = rand() % timesTablesManipulated.size();
        // Used for random answers in different answer squares.
        int randomAnswerIndex = rand() % timesTablesManipulated.size();
        
        cout << "randomIndex: " << randomIndex << "\n";

        // Get the randomIndex element.
        cout << "Random Times Table Chosen: " << timesTablesManipulated[randomIndex] << "\n";
        
        // References to get first and last word in a string (using find_first_of and find_last_of to do it):
        // https://stackoverflow.com/questions/7853686/c-find-return-the-last-word-in-the-string-variable-text-string-getfirstwordt
        // https://www.geeksforgeeks.org/stdstringfind_last_of-in-c-with-examples/
        int indexOfFirstSpaceCharacter = timesTablesManipulated[randomIndex].find_first_of(' ');
        cout << "indexOfFirstSpaceCharacter: " << indexOfFirstSpaceCharacter << endl;
        // Reference for substring (using it to get first and last word in a string):
        // https://www.geeksforgeeks.org/substring-in-cpp/
        // substr(pos, len);
        // indexOfFirstSpaceCharacter also happens to be the length of the first word.
        string firstNumberAsString = timesTablesManipulated[randomIndex].substr(0, indexOfFirstSpaceCharacter);
        cout << "firstNumberAsString: " << firstNumberAsString << endl;
        // Reference on how to convert string to integer using stoi() - (s to i):
        // https://www.geeksforgeeks.org/convert-string-to-int-in-cpp/
        // Reference to add vector element:
        // https://www.w3schools.com/cpp/cpp_vectors.asp
        firstNumber.push_back(stoi(firstNumberAsString));
        cout << "firstNumber as an integer: " << firstNumber[j] << endl;
        
        int indexOfLastSpaceCharacter = timesTablesManipulated[randomIndex].find_last_of(' ');
        cout << "indexOfLastSpaceCharacter: " << indexOfLastSpaceCharacter << endl;
        // Reference to find the length of a string:
        // https://www.w3schools.com/cpp/cpp_strings_length.asp
        string secondNumberAsString = timesTablesManipulated[randomIndex].substr(indexOfLastSpaceCharacter + 1, timesTablesManipulated[randomIndex].length() - (indexOfLastSpaceCharacter + 1));
        cout << "secondNumberAsString: " << secondNumberAsString << endl;
        secondNumber.push_back(stoi(secondNumberAsString));
        cout << "secondNumber as an integer: " << secondNumber[j] << endl;

        randomAnswer.push_back(timesTablesManipulatedAnswers[randomAnswerIndex]);
        
        // Reference on how to remove element at a specific index from a vector:
        // https://stackoverflow.com/questions/875103/how-do-i-erase-an-element-from-stdvector-by-index
        // vec.erase(vec.begin() + index);
        timesTablesManipulated.erase(timesTablesManipulated.begin() + randomIndex);
        timesTablesManipulatedAnswers.erase(timesTablesManipulatedAnswers.begin() + randomAnswerIndex);
        
        // Display all elements in the timesTable vector.
        // Reference to iterate through each element in a vector:
        // https://www.w3schools.com/cpp/cpp_vectors.asp
        cout << "Elements left in the times tables vector: " << endl;
        // cout << "timesTablesManipulated.size() - here: " << timesTablesManipulated.size();
        for (int i = 0; i < timesTablesManipulated.size(); i++) {
            cout << timesTablesManipulated[i] << "\n";
        }

        j++;
    }



    // Reference on declaring more than one variable in the same statement:
    // https://www.w3schools.com/cpp/cpp_variables_multiple.asp
    // RectangleShape square1TimesTable, square2TimesTable, square3TimesTable, square4TimesTable;
    // vector<RectangleShape> squareTimesTable = {square1TimesTable, square2TimesTable, square3TimesTable, square4TimesTable};
    vector<RectangleShape> squareTimesTable(timesTables.size());

    vector<int> timesTableFirstNumber(timesTables.size());

    vector<int> timesTableSecondNumber(timesTables.size());
    
    vector<string> timesTable(timesTables.size());

    // Text text1TimesTable(font), text2TimesTable(font), text3TimesTable(font), text4TimesTable(font); // a font is required to make a text object
    // vector<Text> textTimesTable = {text1TimesTable, text2TimesTable, text3TimesTable, text4TimesTable};
    vector<Text> textTimesTable(timesTables.size(), font);

    vector<RectangleShape> squareAnswer(timesTables.size());

    vector<int> answer(timesTables.size());

    vector<Text> textAnswer(timesTables.size(), font); 

    // cout << "timesTables.size(): " << timesTables.size();

    // string direction;

    // squareAnswer[0].setFillColor(Color::Yellow);
    // squareAnswer[1].setFillColor(Color::Red);
    // squareAnswer[2].setFillColor(Color::Green);
    // squareAnswer[3].setFillColor(Color::Blue);    

    // Reference for for loop: https://www.w3schools.com/cpp/cpp_for_loop.asp
    for (int i = 0; i < timesTables.size(); i++) {
        // NOTE: SQUARE i TIMES TABLE DOES NOT NECESSARY GO WITH SQUARE i ANSWER, ETC.

        // Square i Times Table
        squareTimesTable[i].setSize({120.f, 120.f});
        squareTimesTable[i].setFillColor(Color(255, 255, 179)); // shade of yellow
        squareTimesTable[i].setPosition({5.f, 5.f}); // set the absolute position of the square
        timesTableFirstNumber[i] = firstNumber[i];
        timesTableSecondNumber[i] = secondNumber[i];
        timesTable[i] = to_string(timesTableFirstNumber[i]) + " X " + to_string(timesTableSecondNumber[i]);
        // textTimesTable[i].setFont(font); // a font is required to make a text object 
        textTimesTable[i].setString(timesTable[i]); // set the string to display    
        textTimesTable[i].setPosition({30.f, 50.f}); // set the absolute position of the textTimesTable[i]
        textTimesTable[i].setCharacterSize(24); // set the character size in pixels, not points!        
        textTimesTable[i].setFillColor(Color::Black); // set the color        
        textTimesTable[i].setStyle(Text::Bold); // set the text style  
    
        // Square i Answer
        squareAnswer[i].setSize({120.f, 120.f});
        // squareAnswer[i].setFillColor(Color(255, 212, 128)); // shade of orange
        answer[i] = randomAnswer[i];
        // Reference on how to convert number to string: https://www.geeksforgeeks.org/converting-number-to-string-in-cpp/
        // textAnswer[i].setFont(font); 
        textAnswer[i].setString(to_string(answer[i])); // set the string to display  
        textAnswer[i].setCharacterSize(24); // set the character size in pixels, not points!        
        textAnswer[i].setFillColor(Color::Black); // set the color
        textAnswer[i].setStyle(Text::Bold); // set the text style
       
        if (i == 0) {
            squareAnswer[i].setFillColor(sf::Color::Yellow); // Temporarily set a distinctive color
            squareAnswer[i].setPosition({130 * (i + 1) + 615.f, 130 * (i + 3) + 0.f}); // set the absolute position of the square
            textAnswer[i].setPosition({130 * (i + 1) + 50 + 615.f, 130 * (i + 3) + 45.f}); // set the absolute position of the text1TimesTable
        }
        else if (i == 1) {
            squareAnswer[i].setFillColor(sf::Color::Red); // Temporarily set a distinctive color
            textAnswer[i].setFillColor(sf::Color::White);
            squareAnswer[i].setPosition({130 * (i + 1) + 615.f, 130 * (i + 2) + 0.f}); // set the absolute position of the square
            textAnswer[i].setPosition({130 * (i + 1) + 50 + 615.f, 130 * (i + 2) + 45.f}); // set the absolute position of the text1TimesTable
        }
        else if (i == 2) {
            squareAnswer[i].setFillColor(sf::Color::Green); // Temporarily set a distinctive color                
            squareAnswer[i].setPosition({130 * i + 615.f, 130 * (i + 2)  + 0.f}); // set the absolute position of the square
            textAnswer[i].setPosition({130 * i + 50 + 615.f, 130 * (i + 2) + 45.f}); // set the absolute position of the text1TimesTable
        }
        else if (i == 3) {
            squareAnswer[i].setFillColor(sf::Color::Blue); // Temporarily set a distinctive color
            textAnswer[i].setFillColor(sf::Color::White);
            squareAnswer[i].setPosition({130 * (i - 2) + 615.f, 130 * (i + 1) + 0.f}); // set the absolute position of the square
            textAnswer[i].setPosition({130 * (i - 2) + 50 + 615.f, 130 * (i + 1) + 45.f}); // set the absolute position of the text1TimesTable
        }
        else if (i == 4) {
            squareAnswer[i].setFillColor(sf::Color::Yellow); // Temporarily set a distinctive color
            squareAnswer[i].setPosition({130 * (i - 4) + 615.f, 130 * i + 0.f}); // set the absolute position of the square
            textAnswer[i].setPosition({130 * (i - 4) + 50 + 615.f, 130 * i + 45.f}); // set the absolute position of the text1TimesTable
        }
        else if (i == 5) {
            squareAnswer[i].setFillColor(sf::Color::Red); // Temporarily set a distinctive color
            textAnswer[i].setFillColor(sf::Color::White);
            squareAnswer[i].setPosition({130 * (i - 5) + 615.f, 130 * (i - 2) + 0.f}); // set the absolute position of the square
            textAnswer[i].setPosition({130 * (i - 5) + 50 + 615.f, 130 * (i - 2) + 45.f}); // set the absolute position of the text1TimesTable
        }
        else if (i == 6) {
            squareAnswer[i].setFillColor(sf::Color::Green); // Temporarily set a distinctive color                
            squareAnswer[i].setPosition({130 * (i - 6) + 615.f, 130 * (i - 4)  + 0.f}); // set the absolute position of the square
            textAnswer[i].setPosition({130 * (i - 6) + 50 + 615.f, 130 * (i - 4) + 45.f}); // set the absolute position of the text1TimesTable
        }
        else if (i == 7) {
            squareAnswer[i].setFillColor(sf::Color::Blue); // Temporarily set a distinctive color
            textAnswer[i].setFillColor(sf::Color::White);
            squareAnswer[i].setPosition({130 * (i - 6) + 615.f, 130 * (i - 5) + 0.f}); // set the absolute position of the square
            textAnswer[i].setPosition({130 * (i - 6) + 50 + 615.f, 130 * (i - 5) + 45.f}); // set the absolute position of the text1TimesTable
        }
        else if (i == 8) {
            squareAnswer[i].setFillColor(sf::Color::Yellow); // Temporarily set a distinctive color
            squareAnswer[i].setPosition({130 * (i - 6) + 615.f, 130 * (i - 6) + 0.f}); // set the absolute position of the square
            textAnswer[i].setPosition({130 * (i - 6) + 50 + 615.f, 130 * (i - 6) + 45.f}); // set the absolute position of the text1TimesTable
        }
        else if (i == 9) {
            squareAnswer[i].setFillColor(sf::Color::Red); // Temporarily set a distinctive color
            textAnswer[i].setFillColor(sf::Color::White);
            squareAnswer[i].setPosition({130 * (i - 6) + 615.f, 130 * (i - 7) + 0.f}); // set the absolute position of the square
            textAnswer[i].setPosition({130 * (i - 6) + 50 + 615.f, 130 * (i - 7) + 45.f}); // set the absolute position of the text1TimesTable
        }
        else if (i == 10) {
            squareAnswer[i].setFillColor(sf::Color::Green); // Temporarily set a distinctive color                
            squareAnswer[i].setPosition({130 * (i - 7) + 615.f, 130 * (i - 7)  + 0.f}); // set the absolute position of the square
            textAnswer[i].setPosition({130 * (i - 7) + 50 + 615.f, 130 * (i - 7) + 45.f}); // set the absolute position of the text1TimesTable
        }
        else if (i == 11) {
            squareAnswer[i].setFillColor(sf::Color::Blue); // Temporarily set a distinctive color
            textAnswer[i].setFillColor(sf::Color::White);
            squareAnswer[i].setPosition({130 * (i - 8) + 615.f, 130 * (i - 7)  + 0.f}); // set the absolute position of the square
            textAnswer[i].setPosition({130 * (i - 8) + 50 + 615.f, 130 * (i - 7) + 45.f}); // set the absolute position of the text1TimesTable
        }
        else if (i == 12) {
            squareAnswer[i].setFillColor(sf::Color::Yellow); // Temporarily set a distinctive color
            squareAnswer[i].setPosition({130 * (i - 9) + 615.f, 130 * (i - 7)  + 0.f}); // set the absolute position of the square
            textAnswer[i].setPosition({130 * (i - 9) + 50 + 615.f, 130 * (i - 7) + 45.f}); // set the absolute position of the text1TimesTable
        }        
        else if (i == 13) {
            squareAnswer[i].setFillColor(sf::Color::Red); // Temporarily set a distinctive color
            textAnswer[i].setFillColor(sf::Color::White);
            squareAnswer[i].setPosition({130 * (i - 11) + 615.f, 130 * (i - 8)  + 0.f}); // set the absolute position of the square
            textAnswer[i].setPosition({130 * (i - 11) + 50 + 615.f, 130 * (i - 8) + 45.f}); // set the absolute position of the text1TimesTable
        }
        else if (i == 14) {
            squareAnswer[i].setFillColor(sf::Color::Green); // Temporarily set a distinctive color                
            squareAnswer[i].setPosition({130 * (i - 13) + 615.f, 130 * (i - 9)  + 0.f}); // set the absolute position of the square
            textAnswer[i].setPosition({130 * (i - 13) + 50 + 615.f, 130 * (i - 9) + 45.f}); // set the absolute position of the text1TimesTable
        }        
        else if (i == 15) {
            squareAnswer[i].setFillColor(sf::Color::Blue); // Temporarily set a distinctive color
            textAnswer[i].setFillColor(sf::Color::White);
            squareAnswer[i].setPosition({130 * (i - 15) + 615.f, 130 * (i - 10)  + 0.f}); // set the absolute position of the square
            textAnswer[i].setPosition({130 * (i - 15) + 50 + 615.f, 130 * (i - 10) + 45.f}); // set the absolute position of the text1TimesTable
        }
        else if (i == 16) {
            squareAnswer[i].setFillColor(sf::Color::Yellow); // Temporarily set a distinctive color
            squareAnswer[i].setPosition({130 * (i - 17) + 615.f, 130 * (i - 11)  + 0.f}); // set the absolute position of the square
            textAnswer[i].setPosition({130 * (i - 17) + 50 + 615.f, 130 * (i - 11) + 45.f}); // set the absolute position of the text1TimesTable
        }
        else if (i == 17) {
            squareAnswer[i].setFillColor(sf::Color::Red); // Temporarily set a distinctive color
            textAnswer[i].setFillColor(sf::Color::White);
            squareAnswer[i].setPosition({130 * (i - 18) + 615.f, 130 * (i - 13)  + 0.f}); // set the absolute position of the square
            textAnswer[i].setPosition({130 * (i - 18) + 50 + 615.f, 130 * (i - 13) + 45.f}); // set the absolute position of the text1TimesTable
        }
        else if (i == 18) {
            squareAnswer[i].setFillColor(sf::Color::Green); // Temporarily set a distinctive color                
            squareAnswer[i].setPosition({130 * (i - 19) + 615.f, 130 * (i - 15)  + 0.f}); // set the absolute position of the square
            textAnswer[i].setPosition({130 * (i - 19) + 50 + 615.f, 130 * (i - 15) + 45.f}); // set the absolute position of the text1TimesTable
        }
        else if (i == 19) {
            squareAnswer[i].setFillColor(sf::Color::Blue); // Temporarily set a distinctive color
            textAnswer[i].setFillColor(sf::Color::White);
            squareAnswer[i].setPosition({130 * (i - 20) + 615.f, 130 * (i - 17)  + 0.f}); // set the absolute position of the square
            textAnswer[i].setPosition({130 * (i - 20) + 50 + 615.f, 130 * (i - 17) + 45.f}); // set the absolute position of the text1TimesTable
        }
        else if (i == 20) {
            squareAnswer[i].setFillColor(sf::Color::Yellow); // Temporarily set a distinctive color
            squareAnswer[i].setPosition({130 * (i - 21) + 615.f, 130 * (i - 19)  + 0.f}); // set the absolute position of the square
            textAnswer[i].setPosition({130 * (i - 21) + 50 + 615.f, 130 * (i - 19) + 45.f}); // set the absolute position of the text1TimesTable
        }
        else if (i == 21) {
            squareAnswer[i].setFillColor(sf::Color::Red); // Temporarily set a distinctive color
            textAnswer[i].setFillColor(sf::Color::White);
            squareAnswer[i].setPosition({130 * (i - 21) + 615.f, 130 * (i - 20)  + 0.f}); // set the absolute position of the square
            textAnswer[i].setPosition({130 * (i - 21) + 50 + 615.f, 130 * (i - 20) + 45.f}); // set the absolute position of the text1TimesTable
        }
        else if (i == 22) {
            squareAnswer[i].setFillColor(sf::Color::Green); // Temporarily set a distinctive color                
            squareAnswer[i].setPosition({130 * (i - 21) + 615.f, 130 * (i - 21)  + 0.f}); // set the absolute position of the square
            textAnswer[i].setPosition({130 * (i - 21) + 50 + 615.f, 130 * (i - 21) + 45.f}); // set the absolute position of the text1TimesTable
        }
        else if (i == 23) {
            squareAnswer[i].setFillColor(sf::Color::Blue); // Temporarily set a distinctive color
            textAnswer[i].setFillColor(sf::Color::White);
            squareAnswer[i].setPosition({130 * (i - 21) + 615.f, 130 * (i - 22)  + 0.f}); // set the absolute position of the square
            textAnswer[i].setPosition({130 * (i - 21) + 50 + 615.f, 130 * (i - 22) + 45.f}); // set the absolute position of the text1TimesTable
        }
        else if (i == 24) {
            squareAnswer[i].setFillColor(sf::Color::Yellow); // Temporarily set a distinctive color
            squareAnswer[i].setPosition({130 * (i - 21) + 615.f, 130 * (i - 23)  + 0.f}); // set the absolute position of the square
            textAnswer[i].setPosition({130 * (i - 21) + 50 + 615.f, 130 * (i - 23) + 45.f}); // set the absolute position of the text1TimesTable
        }
    }
  
    // vector<bool> draggable = {false, false, false, false};
    vector<bool> draggable(timesTables.size(), false); 
    
    // Reference for fullscreen: https://www.sfml-dev.org/tutorials/3.0/window/window/
    RenderWindow window(VideoMode({1600, 800}), "Times Tables Game", Style::Resize, State::Fullscreen);    // Open the application font

    while (window.isOpen())
    {
        // get the local mouse position (relative to a window)
        Vector2i localPosition = Mouse::getPosition(window);

        // Initiating Square Times Table Position Variables
        // Vector2f square1TimesTablePosition, square2TimesTablePosition, square3TimesTablePosition, square4TimesTablePosition;
        // vector<Vector2f> squareTimesTablePosition = {square1TimesTablePosition, square2TimesTablePosition, square3TimesTablePosition, square4TimesTablePosition};
        vector<Vector2f> squareTimesTablePosition(timesTables.size());
        vector<Vector2f> textTimesTablePosition(timesTables.size());

        // Initiating Square Answer Position Variables
        vector<Vector2f> squareAnswerPosition(timesTables.size());

        for (int i = 0; i < timesTables.size(); i++) {
            // Square i Times Table Position
            squareTimesTablePosition[i] = squareTimesTable[i].getPosition();
            textTimesTablePosition[i] = textTimesTable[i].getPosition();

            // Square i Answer Position
            squareAnswerPosition[i] = squareAnswer[i].getPosition();
        }

        while (const std::optional event = window.pollEvent())
        {
            // cout << "in loop timesTables.size(): " << timesTables.size();
            
            // When cursor is moved
            if (const auto* mouseMoved = event->getIf<sf::Event::MouseMoved>())
            {
                for (int i = 0; i < timesTables.size(); i++) {
                    if (draggable[i]) {
                        squareTimesTable[i].setPosition({static_cast<float>(localPosition.x) + 0.f, static_cast<float>(localPosition.y) + 0.f});
                        textTimesTable[i].setPosition({static_cast<float>(localPosition.x) + 30.f, static_cast<float>(localPosition.y) + 50.f});
                        break;
                    }
                }                               
            }            

            // When button is pressed
            if (const auto* mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>())
            {
                if (mouseButtonPressed->button == sf::Mouse::Button::Left)
                {
                    for (int i = 0; i < timesTables.size(); i++) {
                        if (localPosition.x >= squareTimesTablePosition[i].x && localPosition.x <= squareTimesTablePosition[i].x + 125 && 
                            localPosition.y >= squareTimesTablePosition[i].y && localPosition.y <= squareTimesTablePosition[i].y + 125) 
                        {
                            draggable[i] = true;
                            // Reference for color picker: https://www.w3schools.com/colors/colors_picker.asp
                            squareTimesTable[i].setFillColor(Color(255, 255, 179)); // shade of yellow
                            textTimesTable[i].setString(timesTable[i]);
                            textTimesTable[i].setCharacterSize(24);
                            textTimesTable[i].setFillColor(Color::Black);   
                            textTimesTable[i].setPosition({static_cast<float>(squareTimesTablePosition[i].x) + 30.f, static_cast<float>(squareTimesTablePosition[i].y) + 50.f});
                            break;
                        }                        
                    }
                    // std::cout << "the right button was pressed" << std::endl;
                    // std::cout << "mouse x: " << mouseButtonPressed->position.x << std::endl;
                    // std::cout << "mouse y: " << mouseButtonPressed->position.y << std::endl;
                }
            }

            // When button is released
            if (const auto* mouseButtonReleased = event->getIf<sf::Event::MouseButtonReleased>())
            {
                if (mouseButtonReleased->button == sf::Mouse::Button::Left)
                {   
                    for (int i = 0; i < timesTables.size(); i++) {
                        draggable[i] = false;
                    }

                    for (int i = 0; i < timesTables.size(); i++) {
                        for (int j = 0; j < timesTables.size(); j++) {
                            // SQUARE i TIMES TABLE
                            if (squareTimesTablePosition[i].x >= squareAnswerPosition[j].x - 25 && squareTimesTablePosition[i].x <= squareAnswerPosition[j].x + 25 && 
                                squareTimesTablePosition[i].y >= squareAnswerPosition[j].y - 25 && squareTimesTablePosition[i].y <= squareAnswerPosition[j].y + 25 &&
                                timesTableFirstNumber[i] * timesTableSecondNumber[i] == answer[j])
                            {
                                squareTimesTable[i].setFillColor(Color::Green);
                                // Reference for unicode checkmark: https://en.wikipedia.org/wiki/List_of_Unicode_characters
                                textTimesTable[i].setString(L"\u2713");
                                textTimesTable[i].setCharacterSize(75);
                                textTimesTable[i].setFillColor(Color::White);   
                                textTimesTable[i].setPosition({static_cast<float>(squareAnswerPosition[j].x) + 40.f, static_cast<float>(squareAnswerPosition[j].y) + 10.f});                   
                                squareTimesTable[i].setPosition({static_cast<float>(squareAnswerPosition[j].x) + 0.f, static_cast<float>(squareAnswerPosition[j].y) + 0.f});
                                break;
                            }
                            else if (squareTimesTablePosition[i].x >= squareAnswerPosition[j].x - 25 && squareTimesTablePosition[i].x <= squareAnswerPosition[j].x + 25 && 
                                squareTimesTablePosition[i].y >= squareAnswerPosition[j].y - 25 && squareTimesTablePosition[i].y <= squareAnswerPosition[j].y + 25 &&
                                timesTableFirstNumber[i] * timesTableSecondNumber[i] != answer[j])
                            {
                                squareTimesTable[i].setFillColor(Color::Red);
                                textTimesTable[i].setString("X");
                                textTimesTable[i].setCharacterSize(75);
                                textTimesTable[i].setFillColor(Color::White);   
                                textTimesTable[i].setPosition({static_cast<float>(squareAnswerPosition[j].x) + 35.f, static_cast<float>(squareAnswerPosition[j].y) + 10.f});                   
                                squareTimesTable[i].setPosition({static_cast<float>(squareAnswerPosition[j].x) + 0.f, static_cast<float>(squareAnswerPosition[j].y) + 0.f});
                                incorrectAnswer = true;
                                break;
                            }
                        }
                    }

                    // Reference on how to add a time delay:
                    // https://www.geeksforgeeks.org/how-to-add-timed-delay-in-cpp/
                    // Waiting for 3 seconds
                    // this_thread::sleep_for(chrono::seconds(3));
                    // if (incorrectAnswer) {
                    //     initializeGame(2);
                    // }
                }
            }            

            // Used to close the window.
            Vector2i localPosition = Mouse::getPosition(window);
            if (event->is<Event::Closed>()) {
                window.close();
            }
            // Press "Q" or "q" to quit the program.
            else if (Keyboard::isKeyPressed(Keyboard::Key::Q)) {
                window.close();
            }
        }

        window.clear();

        for (int i = 0; i < timesTables.size(); i++) {
            window.draw(squareAnswer[i]);
            window.draw(textAnswer[i]);
        }
        // window.draw(squareAnswer[3]);
        // window.draw(textAnswer[3]);
        // window.draw(squareAnswer[2]);
        // window.draw(textAnswer[2]);
        // window.draw(squareAnswer[1]);
        // window.draw(textAnswer[1]);
        // window.draw(squareAnswer[0]);
        // window.draw(textAnswer[0]);

        // References on how to do a decreasing for loop: 
        // https://algocademy.com/link/?problem=looping-in-reverse&lang=cpp&solution=1
        for (int i = timesTables.size()-1; i > -1; i--) {
            window.draw(squareTimesTable[i]); // The drawings will layer on top of the drawings before it and so squareTimesTable[0] needs to be last.
            window.draw(textTimesTable[i]); // Put inside the main loop, between window.clear() and window.display().              
        }

        window.display();
    }
}