#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib> // Needed for rand() and srand()
#include <ctime>   // Needed for time()
#include <queue>
using namespace std;
using namespace sf;

int main()
{
    // Reference to get a different random number each time the program runs:
    // https://www.w3schools.com/cpp/cpp_howto_random_number.asp
    // Get a different random number each time the program runs
    srand(time(0));

    // Reference for fullscreen: https://www.sfml-dev.org/tutorials/3.0/window/window/
    RenderWindow window(VideoMode({1600, 800}), "Times Tables Game", Style::Resize, State::Fullscreen);    // Open the application font

    const Font font("C:/Users/Dallin_Stephens/Documents/BYU-I Courses/CSE 310 Applied Programming/CPlusPlusTimesTablesGame/arialuni.ttf");

    // Create a vector called timesTables that will store strings.
    vector<string> timesTables = {"1 X 2", "2 X 1","2 X 3", "3 X 2"};
    vector<int> timesTablesAnswers = {2, 2, 6, 6};
    // Reference for vector:
    // https://www.w3schools.com/cpp/cpp_vectors.asp
    vector<int> firstNumber;
    vector<int> secondNumber;
    vector<int> randomAnswer;
    int j = 0;
    
    while (timesTables.size() >= 1) {
        // Display all elements in the timesTable vector.
        // Reference to iterate through each element in a vector:
        // https://www.w3schools.com/cpp/cpp_vectors.asp
        cout << "Elements in the times tables vector: " << endl;
        for (int i = 0; i < timesTables.size(); i++) {
            cout << timesTables[i] << "\n";
        }
        
        // Generate a random index between 0 and timesTables.size() - 1
        int randomIndex = rand() % timesTables.size();
        // Used for random answers in different answer squares.
        int randomAnswerIndex = rand() % timesTables.size();
        
        cout << "randomIndex: " << randomIndex << "\n";

        // Get the randomIndex element.
        cout << "Random Times Table Chosen: " << timesTables[randomIndex] << "\n";
        
        // References to get first and last word in a string (using find_first_of and find_last_of to do it):
        // https://stackoverflow.com/questions/7853686/c-find-return-the-last-word-in-the-string-variable-text-string-getfirstwordt
        // https://www.geeksforgeeks.org/stdstringfind_last_of-in-c-with-examples/
        int indexOfFirstSpaceCharacter = timesTables[randomIndex].find_first_of(' ');
        cout << "indexOfFirstSpaceCharacter: " << indexOfFirstSpaceCharacter << endl;
        // Reference for substring (using it to get first and last word in a string):
        // https://www.geeksforgeeks.org/substring-in-cpp/
        // substr(pos, len);
        // indexOfFirstSpaceCharacter also happens to be the length of the first word.
        string firstNumberAsString = timesTables[randomIndex].substr(0, indexOfFirstSpaceCharacter);
        cout << "firstNumberAsString: " << firstNumberAsString << endl;
        // Reference on how to convert string to integer using stoi() - (s to i):
        // https://www.geeksforgeeks.org/convert-string-to-int-in-cpp/
        // Reference to add vector element:
        // https://www.w3schools.com/cpp/cpp_vectors.asp
        firstNumber.push_back(stoi(firstNumberAsString));
        cout << "firstNumber as an integer: " << firstNumber[j] << endl;
        
        int indexOfLastSpaceCharacter = timesTables[randomIndex].find_last_of(' ');
        cout << "indexOfLastSpaceCharacter: " << indexOfLastSpaceCharacter << endl;
        // Reference to find the length of a string:
        // https://www.w3schools.com/cpp/cpp_strings_length.asp
        string secondNumberAsString = timesTables[randomIndex].substr(indexOfLastSpaceCharacter + 1, timesTables[randomIndex].length() - (indexOfLastSpaceCharacter + 1));
        cout << "secondNumberAsString: " << secondNumberAsString << endl;
        secondNumber.push_back(stoi(secondNumberAsString));
        cout << "secondNumber as an integer: " << secondNumber[j] << endl;

        randomAnswer.push_back(timesTablesAnswers[randomAnswerIndex]);
        
        // Reference on how to remove element at a specific index from a vector:
        // https://stackoverflow.com/questions/875103/how-do-i-erase-an-element-from-stdvector-by-index
        // vec.erase(vec.begin() + index);
        timesTables.erase(timesTables.begin() + randomIndex);
        timesTablesAnswers.erase(timesTablesAnswers.begin() + randomAnswerIndex);
        
        // Display all elements in the timesTable vector.
        // Reference to iterate through each element in a vector:
        // https://www.w3schools.com/cpp/cpp_vectors.asp
        cout << "Elements left in the times tables vector: " << endl;
        for (int i = 0; i < timesTables.size(); i++) {
            cout << timesTables[i] << "\n";
        }

        j++;
    }

    // NOTE: SQUARE 1 TIMES TABLE DOES NOT NECESSARY GO WITH SQUARE 1 ANSWER, ETC.

    // Square 1 Times Table
    RectangleShape square1TimesTable({120.f, 120.f});
    square1TimesTable.setFillColor(Color(255, 255, 179)); // shade of yellow
    square1TimesTable.setPosition({5.f, 5.f}); // set the absolute position of the square
    int timesTable1FirstNumber = firstNumber[0];
    int timesTable1SecondNumber = secondNumber[0];
    string timesTable1 = to_string(timesTable1FirstNumber) + " X " + to_string(timesTable1SecondNumber);
    Text text1TimesTable(font); // a font is required to make a text object   
    text1TimesTable.setString(timesTable1); // set the string to display    
    text1TimesTable.setPosition({30.f, 50.f}); // set the absolute position of the text1TimesTable
    text1TimesTable.setCharacterSize(24); // set the character size in pixels, not points!        
    text1TimesTable.setFillColor(Color::Black); // set the color        
    text1TimesTable.setStyle(Text::Bold); // set the text style

    // Square 2 Times Table
    RectangleShape square2TimesTable({120.f, 120.f});
    square2TimesTable.setFillColor(Color(255, 255, 179)); // shade of yellow
    square2TimesTable.setPosition({5.f, 5.f}); // set the absolute position of the square
    int timesTable2FirstNumber = firstNumber[1];
    int timesTable2SecondNumber = secondNumber[1];
    string timesTable2 = to_string(timesTable2FirstNumber) + " X " + to_string(timesTable2SecondNumber);
    Text text2TimesTable(font); // a font is required to make a text object   
    text2TimesTable.setString(timesTable2); // set the string to display    
    text2TimesTable.setPosition({30.f, 50.f}); // set the absolute position of the text2TimesTable
    text2TimesTable.setCharacterSize(24); // set the character size in pixels, not points!        
    text2TimesTable.setFillColor(Color::Black); // set the color        
    text2TimesTable.setStyle(Text::Bold); // set the text style

    // Square 3 Times Table
    RectangleShape square3TimesTable({120.f, 120.f});
    square3TimesTable.setFillColor(Color(255, 255, 179)); // shade of yellow
    square3TimesTable.setPosition({5.f, 5.f}); // set the absolute position of the square
    int timesTable3FirstNumber = firstNumber[2];
    int timesTable3SecondNumber = secondNumber[2];
    string timesTable3 = to_string(timesTable3FirstNumber) + " X " + to_string(timesTable3SecondNumber);
    Text text3TimesTable(font); // a font is required to make a text object   
    text3TimesTable.setString(timesTable3); // set the string to display    
    text3TimesTable.setPosition({30.f, 50.f}); // set the absolute position of the text3TimesTable
    text3TimesTable.setCharacterSize(24); // set the character size in pixels, not points!        
    text3TimesTable.setFillColor(Color::Black); // set the color        
    text3TimesTable.setStyle(Text::Bold); // set the text style

    // Square 4 Times Table
    RectangleShape square4TimesTable({120.f, 120.f});
    square4TimesTable.setFillColor(Color(255, 255, 179)); // shade of yellow
    square4TimesTable.setPosition({5.f, 5.f}); // set the absolute position of the square
    int timesTable4FirstNumber = firstNumber[3];
    int timesTable4SecondNumber = secondNumber[3];
    string timesTable4 = to_string(timesTable4FirstNumber) + " X " + to_string(timesTable4SecondNumber);
    Text text4TimesTable(font); // a font is required to make a text object   
    text4TimesTable.setString(timesTable4); // set the string to display    
    text4TimesTable.setPosition({30.f, 50.f}); // set the absolute position of the text4TimesTable
    text4TimesTable.setCharacterSize(24); // set the character size in pixels, not points!        
    text4TimesTable.setFillColor(Color::Black); // set the color        
    text4TimesTable.setStyle(Text::Bold); // set the text style    
    
    // Square 1 Answer
    RectangleShape square1Answer({120.f, 120.f});
    square1Answer.setFillColor(Color(255, 212, 128)); // shade of orange
    square1Answer.setPosition({130 * 0 + 125.f, 130.f}); // set the absolute position of the square
    int answer1 = randomAnswer[0];
    Text text1Answer(font); // a font is required to make a text object
    // Reference on how to convert number to string: https://www.geeksforgeeks.org/converting-number-to-string-in-cpp/ 
    text1Answer.setString(to_string(answer1)); // set the string to display    
    text1Answer.setPosition({150 + 30.f, 120 + 50.f}); // set the absolute position of the text1TimesTable
    text1Answer.setCharacterSize(24); // set the character size in pixels, not points!        
    text1Answer.setFillColor(Color::Black); // set the color        
    text1Answer.setStyle(Text::Bold); // set the text style
    
    // Square 2 Answer
    RectangleShape square2Answer({120.f, 120.f});
    square2Answer.setFillColor(Color(255, 212, 128));
    square2Answer.setPosition({130 * 1 + 125.f, 130.f});
    int answer2 = randomAnswer[1];
    Text text2Answer(font);
    text2Answer.setString(to_string(answer2));    
    text2Answer.setPosition({130 * 1 + 150 + 30.f, 120 + 50.f});
    text2Answer.setCharacterSize(24);       
    text2Answer.setFillColor(Color::Black);       
    text2Answer.setStyle(Text::Bold);

    // Square 3 Answer
    RectangleShape square3Answer({120.f, 120.f});
    square3Answer.setFillColor(Color(255, 212, 128));
    square3Answer.setPosition({130 * 2 + 125.f, 130.f});
    int answer3 = randomAnswer[2];
    Text text3Answer(font);
    text3Answer.setString(to_string(answer3));    
    text3Answer.setPosition({130 * 2 + 150 + 30.f, 120 + 50.f});
    text3Answer.setCharacterSize(24);       
    text3Answer.setFillColor(Color::Black);       
    text3Answer.setStyle(Text::Bold);

    // Square 4 Answer
    RectangleShape square4Answer({120.f, 120.f});
    square4Answer.setFillColor(Color(255, 212, 128));
    square4Answer.setPosition({130 * 3 + 125.f, 130.f});
    int answer4 = randomAnswer[3];
    Text text4Answer(font);
    text4Answer.setString(to_string(answer4));    
    text4Answer.setPosition({130 * 3 + 150 + 30.f, 120 + 50.f});
    text4Answer.setCharacterSize(24);       
    text4Answer.setFillColor(Color::Black);       
    text4Answer.setStyle(Text::Bold);  

    while (window.isOpen())
    {
        // get the local mouse position (relative to a window)
        Vector2i localPosition = Mouse::getPosition(window);

        // Square 1 Times Table Position
        Vector2f square1TimesTablePosition = square1TimesTable.getPosition();
        Vector2f text1TimesTablePosition = text1TimesTable.getPosition();
        
        // Square 2 Times Table Position
        Vector2f square2TimesTablePosition = square2TimesTable.getPosition();
        Vector2f text2TimesTablePosition = text2TimesTable.getPosition();

        // Square 3 Times Table Position
        Vector2f square3TimesTablePosition = square3TimesTable.getPosition();
        Vector2f text3TimesTablePosition = text3TimesTable.getPosition();
        
        // Square 4 Times Table Position
        Vector2f square4TimesTablePosition = square4TimesTable.getPosition();
        Vector2f text4TimesTablePosition = text4TimesTable.getPosition();         

        // Square 1 Answer Position
        Vector2f square1AnswerPosition = square1Answer.getPosition();

        // Square 2 Answer Position
        Vector2f square2AnswerPosition = square2Answer.getPosition();

        // Square 3 Answer Position
        Vector2f square3AnswerPosition = square3Answer.getPosition();

        // Square 4 Answer Position
        Vector2f square4AnswerPosition = square4Answer.getPosition();

        while (const std::optional event = window.pollEvent())
        {
            bool draggable1;
            bool draggable2;
            bool draggable3;
            bool draggable4;
            
            // When cursor is moved
            if (const auto* mouseMoved = event->getIf<sf::Event::MouseMoved>())
            {
                if (draggable1) {
                    square1TimesTable.setPosition({static_cast<float>(localPosition.x) + 0.f, static_cast<float>(localPosition.y) + 0.f});
                    text1TimesTable.setPosition({static_cast<float>(localPosition.x) + 30.f, static_cast<float>(localPosition.y) + 50.f});
                }
                else if (draggable2) {
                    square2TimesTable.setPosition({static_cast<float>(localPosition.x) + 0.f, static_cast<float>(localPosition.y) + 0.f});
                    text2TimesTable.setPosition({static_cast<float>(localPosition.x) + 30.f, static_cast<float>(localPosition.y) + 50.f});
                }
                else if (draggable3) {
                    square3TimesTable.setPosition({static_cast<float>(localPosition.x) + 0.f, static_cast<float>(localPosition.y) + 0.f});
                    text3TimesTable.setPosition({static_cast<float>(localPosition.x) + 30.f, static_cast<float>(localPosition.y) + 50.f});
                }
                else if (draggable4) {
                    square4TimesTable.setPosition({static_cast<float>(localPosition.x) + 0.f, static_cast<float>(localPosition.y) + 0.f});
                    text4TimesTable.setPosition({static_cast<float>(localPosition.x) + 30.f, static_cast<float>(localPosition.y) + 50.f});
                }                                
            }            

            // When button is pressed
            if (const auto* mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>())
            {
                if (mouseButtonPressed->button == sf::Mouse::Button::Left)
                {
                    if (localPosition.x >= square1TimesTablePosition.x && localPosition.x <= square1TimesTablePosition.x + 125 && 
                        localPosition.y >= square1TimesTablePosition.y && localPosition.y <= square1TimesTablePosition.y + 125) 
                    {
                        draggable1 = true;
                        // Reference for color picker: https://www.w3schools.com/colors/colors_picker.asp
                        square1TimesTable.setFillColor(Color(255, 255, 179)); // shade of yellow
                        text1TimesTable.setString(timesTable1);
                        text1TimesTable.setCharacterSize(24);
                        text1TimesTable.setFillColor(Color::Black);   
                        text1TimesTable.setPosition({static_cast<float>(square1TimesTablePosition.x) + 30.f, static_cast<float>(square1TimesTablePosition.y) + 50.f});
                    }
                    else if (localPosition.x >= square2TimesTablePosition.x && localPosition.x <= square2TimesTablePosition.x + 125 && 
                        localPosition.y >= square2TimesTablePosition.y && localPosition.y <= square2TimesTablePosition.y + 125) 
                    {
                        draggable2 = true;
                        // Reference for color picker: https://www.w3schools.com/colors/colors_picker.asp
                        square2TimesTable.setFillColor(Color(255, 255, 179)); // shade of yellow
                        text2TimesTable.setString(timesTable2);
                        text2TimesTable.setCharacterSize(24);
                        text2TimesTable.setFillColor(Color::Black);   
                        text2TimesTable.setPosition({static_cast<float>(square2TimesTablePosition.x) + 30.f, static_cast<float>(square2TimesTablePosition.y) + 50.f});
                    }
                    else if (localPosition.x >= square3TimesTablePosition.x && localPosition.x <= square3TimesTablePosition.x + 125 && 
                        localPosition.y >= square3TimesTablePosition.y && localPosition.y <= square3TimesTablePosition.y + 125) 
                    {
                        draggable3 = true;
                        square3TimesTable.setFillColor(Color(255, 255, 179)); // shade of yellow
                        text3TimesTable.setString(timesTable3);
                        text3TimesTable.setCharacterSize(24);
                        text3TimesTable.setFillColor(Color::Black);   
                        text3TimesTable.setPosition({static_cast<float>(square3TimesTablePosition.x) + 30.f, static_cast<float>(square3TimesTablePosition.y) + 50.f});
                    }
                    else if (localPosition.x >= square4TimesTablePosition.x && localPosition.x <= square4TimesTablePosition.x + 125 && 
                        localPosition.y >= square4TimesTablePosition.y && localPosition.y <= square4TimesTablePosition.y + 125) 
                    {
                        draggable4 = true;
                        square4TimesTable.setFillColor(Color(255, 255, 179)); // shade of yellow
                        text4TimesTable.setString(timesTable4);
                        text4TimesTable.setCharacterSize(24);
                        text4TimesTable.setFillColor(Color::Black);   
                        text4TimesTable.setPosition({static_cast<float>(square4TimesTablePosition.x) + 30.f, static_cast<float>(square4TimesTablePosition.y) + 50.f});
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
                    draggable1 = false;
                    draggable2 = false;
                    draggable3 = false;
                    draggable4 = false;

                    // SQUARE 1 TIMES TABLE
                    if (square1TimesTablePosition.x >= square1AnswerPosition.x - 25 && square1TimesTablePosition.x <= square1AnswerPosition.x + 25 && 
                        square1TimesTablePosition.y >= square1AnswerPosition.y - 25 && square1TimesTablePosition.y <= square1AnswerPosition.y + 25 &&
                        timesTable1FirstNumber * timesTable1SecondNumber == answer1) 
                    {
                        square1TimesTable.setFillColor(Color::Green);
                        // Reference for unicode checkmark: https://en.wikipedia.org/wiki/List_of_Unicode_characters
                        text1TimesTable.setString(L"\u2713");
                        text1TimesTable.setCharacterSize(75);
                        text1TimesTable.setFillColor(Color::White);   
                        text1TimesTable.setPosition({static_cast<float>(square1AnswerPosition.x) + 40.f, static_cast<float>(square1AnswerPosition.y) + 10.f});                   
                        square1TimesTable.setPosition({static_cast<float>(square1AnswerPosition.x) + 0.f, static_cast<float>(square1AnswerPosition.y) + 0.f});
                    }
                    else if (square1TimesTablePosition.x >= square1AnswerPosition.x - 25 && square1TimesTablePosition.x <= square1AnswerPosition.x + 25 && 
                        square1TimesTablePosition.y >= square1AnswerPosition.y - 25 && square1TimesTablePosition.y <= square1AnswerPosition.y + 25 &&
                        timesTable1FirstNumber * timesTable1SecondNumber != answer1)
                    {
                        square1TimesTable.setFillColor(Color::Red);
                        text1TimesTable.setString("X");
                        text1TimesTable.setCharacterSize(75);
                        text1TimesTable.setFillColor(Color::White);   
                        text1TimesTable.setPosition({static_cast<float>(square1AnswerPosition.x) + 35.f, static_cast<float>(square1AnswerPosition.y) + 10.f});                   
                        square1TimesTable.setPosition({static_cast<float>(square1AnswerPosition.x) + 0.f, static_cast<float>(square1AnswerPosition.y) + 0.f});
                    }
                    else if (square1TimesTablePosition.x >= square2AnswerPosition.x - 25 && square1TimesTablePosition.x <= square2AnswerPosition.x + 25 && 
                        square1TimesTablePosition.y >= square2AnswerPosition.y - 25 && square1TimesTablePosition.y <= square2AnswerPosition.y + 25 &&
                        timesTable1FirstNumber * timesTable1SecondNumber == answer2) 
                    {
                        square1TimesTable.setFillColor(Color::Green);
                        text1TimesTable.setString(L"\u2713");
                        text1TimesTable.setCharacterSize(75);
                        text1TimesTable.setFillColor(Color::White);   
                        text1TimesTable.setPosition({static_cast<float>(square2AnswerPosition.x) + 40.f, static_cast<float>(square2AnswerPosition.y) + 10.f});                   
                        square1TimesTable.setPosition({static_cast<float>(square2AnswerPosition.x) + 0.f, static_cast<float>(square2AnswerPosition.y) + 0.f});
                    }    
                    else if (square1TimesTablePosition.x >= square2AnswerPosition.x - 25 && square1TimesTablePosition.x <= square2AnswerPosition.x + 25 && 
                        square1TimesTablePosition.y >= square2AnswerPosition.y - 25 && square1TimesTablePosition.y <= square2AnswerPosition.y + 25 &&
                        timesTable1FirstNumber * timesTable1SecondNumber != answer2) 
                    {
                        square1TimesTable.setFillColor(Color::Red);
                        text1TimesTable.setString("X");
                        text1TimesTable.setCharacterSize(75);
                        text1TimesTable.setFillColor(Color::White);   
                        text1TimesTable.setPosition({static_cast<float>(square2AnswerPosition.x) + 35.f, static_cast<float>(square2AnswerPosition.y) + 10.f});                   
                        square1TimesTable.setPosition({static_cast<float>(square2AnswerPosition.x) + 0.f, static_cast<float>(square2AnswerPosition.y) + 0.f});
                    }
                    else if (square1TimesTablePosition.x >= square3AnswerPosition.x - 25 && square1TimesTablePosition.x <= square3AnswerPosition.x + 25 && 
                        square1TimesTablePosition.y >= square3AnswerPosition.y - 25 && square1TimesTablePosition.y <= square3AnswerPosition.y + 25 &&
                        timesTable1FirstNumber * timesTable1SecondNumber == answer3) 
                    {
                        square1TimesTable.setFillColor(Color::Green);
                        text1TimesTable.setString(L"\u2713");
                        text1TimesTable.setCharacterSize(75);
                        text1TimesTable.setFillColor(Color::White);   
                        text1TimesTable.setPosition({static_cast<float>(square3AnswerPosition.x) + 40.f, static_cast<float>(square3AnswerPosition.y) + 10.f});                   
                        square1TimesTable.setPosition({static_cast<float>(square3AnswerPosition.x) + 0.f, static_cast<float>(square3AnswerPosition.y) + 0.f});
                    }    
                    else if (square1TimesTablePosition.x >= square3AnswerPosition.x - 25 && square1TimesTablePosition.x <= square3AnswerPosition.x + 25 && 
                        square1TimesTablePosition.y >= square3AnswerPosition.y - 25 && square1TimesTablePosition.y <= square3AnswerPosition.y + 25 &&
                        timesTable1FirstNumber * timesTable1SecondNumber != answer3) 
                    {
                        square1TimesTable.setFillColor(Color::Red);
                        text1TimesTable.setString("X");
                        text1TimesTable.setCharacterSize(75);
                        text1TimesTable.setFillColor(Color::White);   
                        text1TimesTable.setPosition({static_cast<float>(square3AnswerPosition.x) + 35.f, static_cast<float>(square3AnswerPosition.y) + 10.f});                   
                        square1TimesTable.setPosition({static_cast<float>(square3AnswerPosition.x) + 0.f, static_cast<float>(square3AnswerPosition.y) + 0.f});
                    }
                    else if (square1TimesTablePosition.x >= square4AnswerPosition.x - 25 && square1TimesTablePosition.x <= square4AnswerPosition.x + 25 && 
                        square1TimesTablePosition.y >= square4AnswerPosition.y - 25 && square1TimesTablePosition.y <= square4AnswerPosition.y + 25 &&
                        timesTable1FirstNumber * timesTable1SecondNumber == answer4) 
                    {
                        square1TimesTable.setFillColor(Color::Green);
                        text1TimesTable.setString(L"\u2713");
                        text1TimesTable.setCharacterSize(75);
                        text1TimesTable.setFillColor(Color::White);   
                        text1TimesTable.setPosition({static_cast<float>(square4AnswerPosition.x) + 40.f, static_cast<float>(square4AnswerPosition.y) + 10.f});                   
                        square1TimesTable.setPosition({static_cast<float>(square4AnswerPosition.x) + 0.f, static_cast<float>(square4AnswerPosition.y) + 0.f});
                    }    
                    else if (square1TimesTablePosition.x >= square4AnswerPosition.x - 25 && square1TimesTablePosition.x <= square4AnswerPosition.x + 25 && 
                        square1TimesTablePosition.y >= square4AnswerPosition.y - 25 && square1TimesTablePosition.y <= square4AnswerPosition.y + 25 &&
                        timesTable1FirstNumber * timesTable1SecondNumber != answer4) 
                    {
                        square1TimesTable.setFillColor(Color::Red);
                        text1TimesTable.setString("X");
                        text1TimesTable.setCharacterSize(75);
                        text1TimesTable.setFillColor(Color::White);   
                        text1TimesTable.setPosition({static_cast<float>(square4AnswerPosition.x) + 35.f, static_cast<float>(square4AnswerPosition.y) + 10.f});                   
                        square1TimesTable.setPosition({static_cast<float>(square4AnswerPosition.x) + 0.f, static_cast<float>(square4AnswerPosition.y) + 0.f});
                    }

                    // SQUARE 2 TIMES TABLE
                    if (square2TimesTablePosition.x >= square1AnswerPosition.x - 25 && square2TimesTablePosition.x <= square1AnswerPosition.x + 25 && 
                        square2TimesTablePosition.y >= square1AnswerPosition.y - 25 && square2TimesTablePosition.y <= square1AnswerPosition.y + 25 &&
                        timesTable2FirstNumber * timesTable2SecondNumber == answer1) 
                    {
                        square2TimesTable.setFillColor(Color::Green);
                        // Reference for unicode checkmark: https://en.wikipedia.org/wiki/List_of_Unicode_characters
                        text2TimesTable.setString(L"\u2713");
                        text2TimesTable.setCharacterSize(75);
                        text2TimesTable.setFillColor(Color::White);   
                        text2TimesTable.setPosition({static_cast<float>(square1AnswerPosition.x) + 40.f, static_cast<float>(square1AnswerPosition.y) + 10.f});                   
                        square2TimesTable.setPosition({static_cast<float>(square1AnswerPosition.x) + 0.f, static_cast<float>(square1AnswerPosition.y) + 0.f});
                    }
                    else if (square2TimesTablePosition.x >= square1AnswerPosition.x - 25 && square2TimesTablePosition.x <= square1AnswerPosition.x + 25 && 
                        square2TimesTablePosition.y >= square1AnswerPosition.y - 25 && square2TimesTablePosition.y <= square1AnswerPosition.y + 25 &&
                        timesTable2FirstNumber * timesTable2SecondNumber != answer1) 
                    {
                        square2TimesTable.setFillColor(Color::Red);
                        text2TimesTable.setString("X");
                        text2TimesTable.setCharacterSize(75);
                        text2TimesTable.setFillColor(Color::White);   
                        text2TimesTable.setPosition({static_cast<float>(square1AnswerPosition.x) + 35.f, static_cast<float>(square1AnswerPosition.y) + 10.f});                   
                        square2TimesTable.setPosition({static_cast<float>(square1AnswerPosition.x) + 0.f, static_cast<float>(square1AnswerPosition.y) + 0.f});
                    }
                    else if (square2TimesTablePosition.x >= square2AnswerPosition.x - 25 && square2TimesTablePosition.x <= square2AnswerPosition.x + 25 && 
                        square2TimesTablePosition.y >= square2AnswerPosition.y - 25 && square2TimesTablePosition.y <= square2AnswerPosition.y + 25 &&
                        timesTable2FirstNumber * timesTable2SecondNumber == answer2) 
                    {
                        square2TimesTable.setFillColor(Color::Green);
                        text2TimesTable.setString(L"\u2713");
                        text2TimesTable.setCharacterSize(75);
                        text2TimesTable.setFillColor(Color::White);   
                        text2TimesTable.setPosition({static_cast<float>(square2AnswerPosition.x) + 40.f, static_cast<float>(square2AnswerPosition.y) + 10.f});                   
                        square2TimesTable.setPosition({static_cast<float>(square2AnswerPosition.x) + 0.f, static_cast<float>(square2AnswerPosition.y) + 0.f});
                    }    
                    else if (square2TimesTablePosition.x >= square2AnswerPosition.x - 25 && square2TimesTablePosition.x <= square2AnswerPosition.x + 25 && 
                        square2TimesTablePosition.y >= square2AnswerPosition.y - 25 && square2TimesTablePosition.y <= square2AnswerPosition.y + 25 &&
                        timesTable2FirstNumber * timesTable2SecondNumber != answer2) 
                    {
                        square2TimesTable.setFillColor(Color::Red);
                        text2TimesTable.setString("X");
                        text2TimesTable.setCharacterSize(75);
                        text2TimesTable.setFillColor(Color::White);   
                        text2TimesTable.setPosition({static_cast<float>(square2AnswerPosition.x) + 35.f, static_cast<float>(square2AnswerPosition.y) + 10.f});                   
                        square2TimesTable.setPosition({static_cast<float>(square2AnswerPosition.x) + 0.f, static_cast<float>(square2AnswerPosition.y) + 0.f});
                    }
                    else if (square2TimesTablePosition.x >= square3AnswerPosition.x - 25 && square2TimesTablePosition.x <= square3AnswerPosition.x + 25 && 
                        square2TimesTablePosition.y >= square3AnswerPosition.y - 25 && square2TimesTablePosition.y <= square3AnswerPosition.y + 25 &&
                        timesTable2FirstNumber * timesTable2SecondNumber == answer3) 
                    {
                        square2TimesTable.setFillColor(Color::Green);
                        text2TimesTable.setString(L"\u2713");
                        text2TimesTable.setCharacterSize(75);
                        text2TimesTable.setFillColor(Color::White);   
                        text2TimesTable.setPosition({static_cast<float>(square3AnswerPosition.x) + 40.f, static_cast<float>(square3AnswerPosition.y) + 10.f});                   
                        square2TimesTable.setPosition({static_cast<float>(square3AnswerPosition.x) + 0.f, static_cast<float>(square3AnswerPosition.y) + 0.f});
                    }    
                    else if (square2TimesTablePosition.x >= square3AnswerPosition.x - 25 && square2TimesTablePosition.x <= square3AnswerPosition.x + 25 && 
                        square2TimesTablePosition.y >= square3AnswerPosition.y - 25 && square2TimesTablePosition.y <= square3AnswerPosition.y + 25 &&
                        timesTable2FirstNumber * timesTable2SecondNumber != answer3) 
                    {
                        square2TimesTable.setFillColor(Color::Red);
                        text2TimesTable.setString("X");
                        text2TimesTable.setCharacterSize(75);
                        text2TimesTable.setFillColor(Color::White);   
                        text2TimesTable.setPosition({static_cast<float>(square3AnswerPosition.x) + 35.f, static_cast<float>(square3AnswerPosition.y) + 10.f});                   
                        square2TimesTable.setPosition({static_cast<float>(square3AnswerPosition.x) + 0.f, static_cast<float>(square3AnswerPosition.y) + 0.f});
                    }
                    else if (square2TimesTablePosition.x >= square4AnswerPosition.x - 25 && square2TimesTablePosition.x <= square4AnswerPosition.x + 25 && 
                        square2TimesTablePosition.y >= square4AnswerPosition.y - 25 && square2TimesTablePosition.y <= square4AnswerPosition.y + 25 &&
                        timesTable2FirstNumber * timesTable2SecondNumber == answer4) 
                    {
                        square2TimesTable.setFillColor(Color::Green);
                        text2TimesTable.setString(L"\u2713");
                        text2TimesTable.setCharacterSize(75);
                        text2TimesTable.setFillColor(Color::White);   
                        text2TimesTable.setPosition({static_cast<float>(square4AnswerPosition.x) + 40.f, static_cast<float>(square4AnswerPosition.y) + 10.f});                   
                        square2TimesTable.setPosition({static_cast<float>(square4AnswerPosition.x) + 0.f, static_cast<float>(square4AnswerPosition.y) + 0.f});
                    }    
                    else if (square2TimesTablePosition.x >= square4AnswerPosition.x - 25 && square2TimesTablePosition.x <= square4AnswerPosition.x + 25 && 
                        square2TimesTablePosition.y >= square4AnswerPosition.y - 25 && square2TimesTablePosition.y <= square4AnswerPosition.y + 25 &&
                        timesTable2FirstNumber * timesTable2SecondNumber != answer4) 
                    {
                        square2TimesTable.setFillColor(Color::Red);
                        text2TimesTable.setString("X");
                        text2TimesTable.setCharacterSize(75);
                        text2TimesTable.setFillColor(Color::White);   
                        text2TimesTable.setPosition({static_cast<float>(square4AnswerPosition.x) + 35.f, static_cast<float>(square4AnswerPosition.y) + 10.f});                   
                        square2TimesTable.setPosition({static_cast<float>(square4AnswerPosition.x) + 0.f, static_cast<float>(square4AnswerPosition.y) + 0.f});
                    }

                    // SQUARE 3 TIMES TABLE
                    if (square3TimesTablePosition.x >= square1AnswerPosition.x - 25 && square3TimesTablePosition.x <= square1AnswerPosition.x + 25 && 
                        square3TimesTablePosition.y >= square1AnswerPosition.y - 25 && square3TimesTablePosition.y <= square1AnswerPosition.y + 25 &&
                        timesTable3FirstNumber * timesTable3SecondNumber == answer1) 
                    {
                        square3TimesTable.setFillColor(Color::Green);
                        // Reference for unicode checkmark: https://en.wikipedia.org/wiki/List_of_Unicode_characters
                        text3TimesTable.setString(L"\u2713");
                        text3TimesTable.setCharacterSize(75);
                        text3TimesTable.setFillColor(Color::White);   
                        text3TimesTable.setPosition({static_cast<float>(square1AnswerPosition.x) + 40.f, static_cast<float>(square1AnswerPosition.y) + 10.f});                   
                        square3TimesTable.setPosition({static_cast<float>(square1AnswerPosition.x) + 0.f, static_cast<float>(square1AnswerPosition.y) + 0.f});
                    }
                    else if (square3TimesTablePosition.x >= square1AnswerPosition.x - 25 && square3TimesTablePosition.x <= square1AnswerPosition.x + 25 && 
                        square3TimesTablePosition.y >= square1AnswerPosition.y - 25 && square3TimesTablePosition.y <= square1AnswerPosition.y + 25 &&
                        timesTable3FirstNumber * timesTable3SecondNumber != answer1) 
                    {
                        square3TimesTable.setFillColor(Color::Red);
                        text3TimesTable.setString("X");
                        text3TimesTable.setCharacterSize(75);
                        text3TimesTable.setFillColor(Color::White);   
                        text3TimesTable.setPosition({static_cast<float>(square1AnswerPosition.x) + 35.f, static_cast<float>(square1AnswerPosition.y) + 10.f});                   
                        square3TimesTable.setPosition({static_cast<float>(square1AnswerPosition.x) + 0.f, static_cast<float>(square1AnswerPosition.y) + 0.f});
                    }
                    else if (square3TimesTablePosition.x >= square2AnswerPosition.x - 25 && square3TimesTablePosition.x <= square2AnswerPosition.x + 25 && 
                        square3TimesTablePosition.y >= square2AnswerPosition.y - 25 && square3TimesTablePosition.y <= square2AnswerPosition.y + 25 &&
                        timesTable3FirstNumber * timesTable3SecondNumber == answer2) 
                    {
                        square3TimesTable.setFillColor(Color::Green);
                        text3TimesTable.setString(L"\u2713");
                        text3TimesTable.setCharacterSize(75);
                        text3TimesTable.setFillColor(Color::White);   
                        text3TimesTable.setPosition({static_cast<float>(square2AnswerPosition.x) + 40.f, static_cast<float>(square2AnswerPosition.y) + 10.f});                   
                        square3TimesTable.setPosition({static_cast<float>(square2AnswerPosition.x) + 0.f, static_cast<float>(square2AnswerPosition.y) + 0.f});
                    }    
                    else if (square3TimesTablePosition.x >= square2AnswerPosition.x - 25 && square3TimesTablePosition.x <= square2AnswerPosition.x + 25 && 
                        square3TimesTablePosition.y >= square2AnswerPosition.y - 25 && square3TimesTablePosition.y <= square2AnswerPosition.y + 25 &&
                        timesTable3FirstNumber * timesTable3SecondNumber != answer2) 
                    {
                        square3TimesTable.setFillColor(Color::Red);
                        text3TimesTable.setString("X");
                        text3TimesTable.setCharacterSize(75);
                        text3TimesTable.setFillColor(Color::White);   
                        text3TimesTable.setPosition({static_cast<float>(square2AnswerPosition.x) + 35.f, static_cast<float>(square2AnswerPosition.y) + 10.f});                   
                        square3TimesTable.setPosition({static_cast<float>(square2AnswerPosition.x) + 0.f, static_cast<float>(square2AnswerPosition.y) + 0.f});
                    }
                    else if (square3TimesTablePosition.x >= square3AnswerPosition.x - 25 && square3TimesTablePosition.x <= square3AnswerPosition.x + 25 && 
                        square3TimesTablePosition.y >= square3AnswerPosition.y - 25 && square3TimesTablePosition.y <= square3AnswerPosition.y + 25 &&
                        timesTable3FirstNumber * timesTable3SecondNumber == answer3) 
                    {
                        square3TimesTable.setFillColor(Color::Green);
                        text3TimesTable.setString(L"\u2713");
                        text3TimesTable.setCharacterSize(75);
                        text3TimesTable.setFillColor(Color::White);   
                        text3TimesTable.setPosition({static_cast<float>(square3AnswerPosition.x) + 40.f, static_cast<float>(square3AnswerPosition.y) + 10.f});                   
                        square3TimesTable.setPosition({static_cast<float>(square3AnswerPosition.x) + 0.f, static_cast<float>(square3AnswerPosition.y) + 0.f});
                    }    
                    else if (square3TimesTablePosition.x >= square3AnswerPosition.x - 25 && square3TimesTablePosition.x <= square3AnswerPosition.x + 25 && 
                        square3TimesTablePosition.y >= square3AnswerPosition.y - 25 && square3TimesTablePosition.y <= square3AnswerPosition.y + 25 &&
                        timesTable3FirstNumber * timesTable3SecondNumber != answer3) 
                    {
                        square3TimesTable.setFillColor(Color::Red);
                        text3TimesTable.setString("X");
                        text3TimesTable.setCharacterSize(75);
                        text3TimesTable.setFillColor(Color::White);   
                        text3TimesTable.setPosition({static_cast<float>(square3AnswerPosition.x) + 35.f, static_cast<float>(square3AnswerPosition.y) + 10.f});                   
                        square3TimesTable.setPosition({static_cast<float>(square3AnswerPosition.x) + 0.f, static_cast<float>(square3AnswerPosition.y) + 0.f});
                    }
                    else if (square3TimesTablePosition.x >= square4AnswerPosition.x - 25 && square3TimesTablePosition.x <= square4AnswerPosition.x + 25 && 
                        square3TimesTablePosition.y >= square4AnswerPosition.y - 25 && square3TimesTablePosition.y <= square4AnswerPosition.y + 25 &&
                        timesTable3FirstNumber * timesTable3SecondNumber == answer4) 
                    {
                        square3TimesTable.setFillColor(Color::Green);
                        text3TimesTable.setString(L"\u2713");
                        text3TimesTable.setCharacterSize(75);
                        text3TimesTable.setFillColor(Color::White);   
                        text3TimesTable.setPosition({static_cast<float>(square4AnswerPosition.x) + 40.f, static_cast<float>(square4AnswerPosition.y) + 10.f});                   
                        square3TimesTable.setPosition({static_cast<float>(square4AnswerPosition.x) + 0.f, static_cast<float>(square4AnswerPosition.y) + 0.f});
                    }    
                    else if (square3TimesTablePosition.x >= square4AnswerPosition.x - 25 && square3TimesTablePosition.x <= square4AnswerPosition.x + 25 && 
                        square3TimesTablePosition.y >= square4AnswerPosition.y - 25 && square3TimesTablePosition.y <= square4AnswerPosition.y + 25 &&
                        timesTable3FirstNumber * timesTable3SecondNumber != answer4) 
                    {
                        square3TimesTable.setFillColor(Color::Red);
                        text3TimesTable.setString("X");
                        text3TimesTable.setCharacterSize(75);
                        text3TimesTable.setFillColor(Color::White);   
                        text3TimesTable.setPosition({static_cast<float>(square4AnswerPosition.x) + 35.f, static_cast<float>(square4AnswerPosition.y) + 10.f});                   
                        square3TimesTable.setPosition({static_cast<float>(square4AnswerPosition.x) + 0.f, static_cast<float>(square4AnswerPosition.y) + 0.f});
                    }

                    // SQUARE 4 TIMES TABLE
                    if (square4TimesTablePosition.x >= square1AnswerPosition.x - 25 && square4TimesTablePosition.x <= square1AnswerPosition.x + 25 && 
                        square4TimesTablePosition.y >= square1AnswerPosition.y - 25 && square4TimesTablePosition.y <= square1AnswerPosition.y + 25 &&
                        timesTable4FirstNumber * timesTable4SecondNumber == answer1) 
                    {
                        square4TimesTable.setFillColor(Color::Green);
                        // Reference for unicode checkmark: https://en.wikipedia.org/wiki/List_of_Unicode_characters
                        text4TimesTable.setString(L"\u2713");
                        text4TimesTable.setCharacterSize(75);
                        text4TimesTable.setFillColor(Color::White);   
                        text4TimesTable.setPosition({static_cast<float>(square1AnswerPosition.x) + 40.f, static_cast<float>(square1AnswerPosition.y) + 10.f});                   
                        square4TimesTable.setPosition({static_cast<float>(square1AnswerPosition.x) + 0.f, static_cast<float>(square1AnswerPosition.y) + 0.f});
                    }
                    else if (square4TimesTablePosition.x >= square1AnswerPosition.x - 25 && square4TimesTablePosition.x <= square1AnswerPosition.x + 25 && 
                        square4TimesTablePosition.y >= square1AnswerPosition.y - 25 && square4TimesTablePosition.y <= square1AnswerPosition.y + 25 &&
                        timesTable4FirstNumber * timesTable4SecondNumber != answer1) 
                    {
                        square4TimesTable.setFillColor(Color::Red);
                        text4TimesTable.setString("X");
                        text4TimesTable.setCharacterSize(75);
                        text4TimesTable.setFillColor(Color::White);   
                        text4TimesTable.setPosition({static_cast<float>(square1AnswerPosition.x) + 35.f, static_cast<float>(square1AnswerPosition.y) + 10.f});                   
                        square4TimesTable.setPosition({static_cast<float>(square1AnswerPosition.x) + 0.f, static_cast<float>(square1AnswerPosition.y) + 0.f});
                    }
                    else if (square4TimesTablePosition.x >= square2AnswerPosition.x - 25 && square4TimesTablePosition.x <= square2AnswerPosition.x + 25 && 
                        square4TimesTablePosition.y >= square2AnswerPosition.y - 25 && square4TimesTablePosition.y <= square2AnswerPosition.y + 25 &&
                        timesTable4FirstNumber * timesTable4SecondNumber == answer2) 
                    {
                        square4TimesTable.setFillColor(Color::Green);
                        text4TimesTable.setString(L"\u2713");
                        text4TimesTable.setCharacterSize(75);
                        text4TimesTable.setFillColor(Color::White);   
                        text4TimesTable.setPosition({static_cast<float>(square2AnswerPosition.x) + 40.f, static_cast<float>(square2AnswerPosition.y) + 10.f});                   
                        square4TimesTable.setPosition({static_cast<float>(square2AnswerPosition.x) + 0.f, static_cast<float>(square2AnswerPosition.y) + 0.f});
                    }    
                    else if (square4TimesTablePosition.x >= square2AnswerPosition.x - 25 && square4TimesTablePosition.x <= square2AnswerPosition.x + 25 && 
                        square4TimesTablePosition.y >= square2AnswerPosition.y - 25 && square4TimesTablePosition.y <= square2AnswerPosition.y + 25 &&
                        timesTable4FirstNumber * timesTable4SecondNumber != answer2) 
                    {
                        square4TimesTable.setFillColor(Color::Red);
                        text4TimesTable.setString("X");
                        text4TimesTable.setCharacterSize(75);
                        text4TimesTable.setFillColor(Color::White);   
                        text4TimesTable.setPosition({static_cast<float>(square2AnswerPosition.x) + 35.f, static_cast<float>(square2AnswerPosition.y) + 10.f});                   
                        square4TimesTable.setPosition({static_cast<float>(square2AnswerPosition.x) + 0.f, static_cast<float>(square2AnswerPosition.y) + 0.f});
                    }
                    else if (square4TimesTablePosition.x >= square3AnswerPosition.x - 25 && square4TimesTablePosition.x <= square3AnswerPosition.x + 25 && 
                        square4TimesTablePosition.y >= square3AnswerPosition.y - 25 && square4TimesTablePosition.y <= square3AnswerPosition.y + 25 &&
                        timesTable4FirstNumber * timesTable4SecondNumber == answer3) 
                    {
                        square4TimesTable.setFillColor(Color::Green);
                        text4TimesTable.setString(L"\u2713");
                        text4TimesTable.setCharacterSize(75);
                        text4TimesTable.setFillColor(Color::White);   
                        text4TimesTable.setPosition({static_cast<float>(square3AnswerPosition.x) + 40.f, static_cast<float>(square3AnswerPosition.y) + 10.f});                   
                        square4TimesTable.setPosition({static_cast<float>(square3AnswerPosition.x) + 0.f, static_cast<float>(square3AnswerPosition.y) + 0.f});
                    }    
                    else if (square4TimesTablePosition.x >= square3AnswerPosition.x - 25 && square4TimesTablePosition.x <= square3AnswerPosition.x + 25 && 
                        square4TimesTablePosition.y >= square3AnswerPosition.y - 25 && square4TimesTablePosition.y <= square3AnswerPosition.y + 25 &&
                        timesTable4FirstNumber * timesTable4SecondNumber != answer3) 
                    {
                        square4TimesTable.setFillColor(Color::Red);
                        text4TimesTable.setString("X");
                        text4TimesTable.setCharacterSize(75);
                        text4TimesTable.setFillColor(Color::White);   
                        text4TimesTable.setPosition({static_cast<float>(square3AnswerPosition.x) + 35.f, static_cast<float>(square3AnswerPosition.y) + 10.f});                   
                        square4TimesTable.setPosition({static_cast<float>(square3AnswerPosition.x) + 0.f, static_cast<float>(square3AnswerPosition.y) + 0.f});
                    }
                    else if (square4TimesTablePosition.x >= square4AnswerPosition.x - 25 && square4TimesTablePosition.x <= square4AnswerPosition.x + 25 && 
                        square4TimesTablePosition.y >= square4AnswerPosition.y - 25 && square4TimesTablePosition.y <= square4AnswerPosition.y + 25 &&
                        timesTable4FirstNumber * timesTable4SecondNumber == answer4) 
                    {
                        square4TimesTable.setFillColor(Color::Green);
                        text4TimesTable.setString(L"\u2713");
                        text4TimesTable.setCharacterSize(75);
                        text4TimesTable.setFillColor(Color::White);   
                        text4TimesTable.setPosition({static_cast<float>(square4AnswerPosition.x) + 40.f, static_cast<float>(square4AnswerPosition.y) + 10.f});                   
                        square4TimesTable.setPosition({static_cast<float>(square4AnswerPosition.x) + 0.f, static_cast<float>(square4AnswerPosition.y) + 0.f});
                    }    
                    else if (square4TimesTablePosition.x >= square4AnswerPosition.x - 25 && square4TimesTablePosition.x <= square4AnswerPosition.x + 25 && 
                        square4TimesTablePosition.y >= square4AnswerPosition.y - 25 && square4TimesTablePosition.y <= square4AnswerPosition.y + 25 &&
                        timesTable4FirstNumber * timesTable4SecondNumber != answer4) 
                    {
                        square4TimesTable.setFillColor(Color::Red);
                        text4TimesTable.setString("X");
                        text4TimesTable.setCharacterSize(75);
                        text4TimesTable.setFillColor(Color::White);   
                        text4TimesTable.setPosition({static_cast<float>(square4AnswerPosition.x) + 35.f, static_cast<float>(square4AnswerPosition.y) + 10.f});                   
                        square4TimesTable.setPosition({static_cast<float>(square4AnswerPosition.x) + 0.f, static_cast<float>(square4AnswerPosition.y) + 0.f});
                    }                    

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
        window.draw(square1Answer);
        window.draw(text1Answer); // put inside the main loop, between window.clear() and window.display()
        window.draw(square2Answer);
        window.draw(text2Answer);
        window.draw(square3Answer);
        window.draw(text3Answer);
        window.draw(square4Answer);
        window.draw(text4Answer);
        window.draw(square4TimesTable);
        window.draw(text4TimesTable);        
        window.draw(square3TimesTable);
        window.draw(text3TimesTable);        
        window.draw(square2TimesTable);
        window.draw(text2TimesTable);          
        window.draw(square1TimesTable); // The drawings will layer on top of the drawings before it.
        window.draw(text1TimesTable); // put inside the main loop, between window.clear() and window.display()               
        window.display();
    }

    

}