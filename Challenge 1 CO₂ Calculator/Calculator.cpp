//Coding Challenges/Challenge 1 CO₂ Calculator/hallenge1-CO₂Calculator
//The solution must be no more than 100 lines of code
//Develop a program that calculates that estimates the CO₂ emissions from a car journey based on the distance traveled and the type of fuel used. Your program should have a function to get distance travelled, a function to get fuel type, and a function to calculate the result.
//The following assumptions are made regarding the calculations:
//•	Fuel consumption: 9.66 litres per 100 miles
//•	CO₂ emissions per litre:
//o	Diesel: 2.68kg CO₂
//o	Petrol: 2.31kg CO₂
#include <iostream>
#include <string>
#include <iomanip>

// Function to safely collect the distance travelled from the user
double getDistanceTravelled() {
    double distance = 0.0;
    while (true) {
        std::cout << "Enter the distance travelled in miles: ";
        if (std::cin >> distance && distance >= 0) {
            return distance;
        }
        std::cout << "Invalid input. Please enter a positive number.\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
}

// Function to collect and validate the fuel type
char getFuelType() {
    char fuel = ' ';
    while (true) {
        std::cout << "Enter fuel type (P for Petrol, D for Diesel): ";
        std::cin >> fuel;
        fuel = static_cast<char>(toupper(fuel));
 // Standardise to uppercase
        
        if (fuel == 'P' || fuel == 'D') {
            return fuel;
        }
        std::cout << "Invalid fuel type. Please try again.\n";
    }
}

// Function to calculate the estimated CO2 emissions based on parameters
double calculateEmissions(double distance, char fuelType) {
    // Assumptions provided in the brief
    const double FUEL_CONSUMPTION_PER_100_MILES = 9.66;
    const double CO2_PER_LITRE_DIESEL = 2.68;
    const double CO2_PER_LITRE_PETROL = 2.31;
    
    // Step 1: Calculate total litres used
    double totalLitresUsed = (distance / 100.0) * FUEL_CONSUMPTION_PER_100_MILES;
    
    // Step 2: Determine emission rate and calculate final kg of CO2
    double emissionRate = (fuelType == 'D') ? CO2_PER_LITRE_DIESEL : CO2_PER_LITRE_PETROL;
    return totalLitresUsed * emissionRate;
}

int main() {
    std::cout << "\n";
    std::cout << "Vehicle CO2 Emissions Estimator\n";
    std::cout << "\n\n";
    
    // Execute the required modular functions
    double distance = getDistanceTravelled();
    char fuelType = getFuelType();
    double totalCO2 = calculateEmissions(distance, fuelType);
    
    // Display results formatted neatly to 2 decimal places
    std::cout << "\n\n";
    std::cout << "Journey Summary:\n";
    std::cout << "Distance: " << distance << " miles\n";
    std::cout << "Fuel Type: " << (fuelType == 'D' ? "Diesel" : "Petrol") << "\n";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Estimated CO2 Emissions: " << totalCO2 << " kg\n";
    std::cout << "\n";
    
    return 0;
}
/*
Approach and Problem-Solving Strategy

To simulate a virtual voice assistant, the program reads the jokes from an external file named randomJokes.txt using standard file streams and keeps them in a vector while the program is running. It splits each joke at the question mark in order to separate the setup from the punchline, thereby allowing the system to deliver the jokes in a natural way, as this would take place in a conversation.



Design Decisions and Technical Implementation

The while loop continues to run, waiting for user input and only ending when 'quit' is entered. The jokes are chosen at random by using the rand function together with a modulo operation, and in each session the order is rearranged by seeding the random number generator with the current time.



Instead of relying on external libraries the program uses built-in functions like find and substr when handling strings; timing is obtained through the use of cin.get, the program pausing after the setup and then waiting for the user to press Enter before displaying the punchline, thereby ensuring that the delivery stays natural and interactive.

*/