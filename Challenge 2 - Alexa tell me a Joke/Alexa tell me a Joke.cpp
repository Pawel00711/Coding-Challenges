//Challenge 2 - Alexa tell me a Joke
//The solution must be no more than 100 lines of code
//The randomJokes.txt file in the resources folder contains a dataset of random jokes. Each joke is on a new line and consists of a setup and punchline separated by a question mark.
//For example:
//Why did the chicken cross the road?To get to the other side.
//What happens if you boil a clown?You get a laughing stock.
//Write a program that responds to the phrase "Alexa, tell me a joke" by selecting a random joke from the file provided. Display the setup first, then wait for user input before revealing the punchline. The program should allow the user to request new jokes using the specified prompt until they choose to quit.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

// Function to read all jokes from the file into memory
std::vector<std::string> loadJokes(const std::string& filename) {
    std::vector<std::string> jokes;
    std::ifstream file(filename);
    std::string line;
    
    if (!file.is_open()) {
        std::cout << "Error: Could not open " << filename << "\n";
        return jokes;
    }
    
    while (std::getline(file, line)) {
        if (!line.empty() && line.find('?') != std::string::npos) {
            jokes.push_back(line);
        }
    }
    return jokes;
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed random number generator
    const std::string filename = "randomJokes.txt";
    std::vector<std::string> jokes = loadJokes(filename);
    
    if (jokes.empty()) {
        std::cout << "No jokes available. Exiting program.\n";
        return 1;
    }
    
    std::string userInput;
    std::cout << "\n";
    
    while (true) {
        std::cout << "Type 'Alexa, tell me a joke' (or 'quit' to exit): ";
        std::getline(std::cin, userInput);
        
        if (userInput == "quit" || userInput == "Quit") {
            std::cout << "Goodbye!\n";
            break;
        }
        
        if (userInput == "Alexa, tell me a joke") {
            // Select a random joke from the vector
            int randomIndex = rand() % jokes.size();
            std::string fullJoke = jokes[randomIndex];
            
            // Find the split point at the question mark
            size_t splitPos = fullJoke.find('?');
            std::string setup = fullJoke.substr(0, splitPos + 1);
            std::string punchline = fullJoke.substr(splitPos + 1);
            
            // Display setup and wait for the user to press enter
            std::cout << "\nSetup: " << setup << "\n";
            std::cout << "[Press ENTER to see the punchline]";
            std::cin.get(); // Wait for user submission
            
            // Reveal punchline
            std::cout << "Punchline: " << punchline << "\n";
            std::cout << "\n\n";
        } else {
            std::cout << "Unrecognized phrase. Please try again.\n";
        }
    }
    return 0;
}
/*
Approach and Problem-Solving Strategy
The program functions as a virtual assistant that tells jokes in a conversational manner. It reads each line from the file randomJokes.txt using file streams and stores the jokes in a vector. The jokes are divided at the question mark so as to separate the setup from the punchline, enabling each part to be presented in a way that mimics real dialogue.
A while loop in the centre keeps waiting for user input and continues doing so until 'quit' is typed. The jokes are selected at random by using the rand function in combination with the modulo operator and the total number of jokes. The random number sequence is seeded with the current time to make sure that the order is different each session.
Rather than using external parsing libraries the program makes use of built-in functions such as find and substr for handling strings. Timing is achieved by means of cin.get, with the program pausing after the setup and then waiting for the user to press Enter before displaying the punchline. This ensures that the delivery remains natural and interactive.
*/