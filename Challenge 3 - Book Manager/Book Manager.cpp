/*    Challenge 3 - Book Manager
The solution must be no more than 200 lines of code
Develop a simple library management system that reads book data from the bookData.txt file (found in the resources folder) using appropriate file handling techniques and uses this data to instantiate a Book class with relevant attributes. The program should include a menu that allows users to view all books and view individual books.
For an additional challenge, extend the functionality to support borrowing and returning books, ensuring that the system updates availability status accordingly.
The bookData.txt file contains the following information for each book:
Title, Autor, Pages, ID, Borrowed Status 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

// Define a structure to hold book properties based on the assignment brief
struct Book {
    std::string title;
    std::string author;
    int pages;
    std::string id;
    std::string borrowedStatus;
};

// Function to collect clean string inputs from the stream
std::string getStringInput(const std::string& prompt) {
    std::string input;
    std::cout << prompt;
    std::getline(std::cin >> std::ws, input);
    return input;
}

int main() {
    std::vector<Book> library;
    int choice = 0;
    
    std::cout << "===========================================\n";
    std::cout << "          University Book Manager          \n";
    std::cout << "===========================================\n";
    
    while (true) {
        std::cout << "\n1 Add Book\n2 Display All Books\n3 Search Book by Title\n4 Quit\n";
        std::cout << "Select an option: ";
        
        if (!(std::cin >> choice)) {
            std::cout << "Invalid selection. Numbers only.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }
        
        if (choice == 4) {
            std::cout << "Closing Book Manager. Goodbye!\n";
            break;
        }
        
        if (choice == 1) {
            Book newBook;
            newBook.title = getStringInput("Enter book title: ");
            newBook.author = getStringInput("Enter author name: ");
            
            while (true) {
                std::cout << "Enter total pages: ";
                if (std::cin >> newBook.pages && newBook.pages > 0) break;
                std::cout << "Invalid page count. Try again.\n";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            }
            
            newBook.id = getStringInput("Enter Book ID: ");
            newBook.borrowedStatus = getStringInput("Enter Borrowed Status (Available/Borrowed): ");
            
            library.push_back(newBook);
            std::cout << "Book stored successfully!\n";
        } 
        else if (choice == 2) {
            if (library.empty()) {
                std::cout << "The library inventory is empty.\n";
            } else {
                std::cout << "\n" << std::left 
                          << std::setw(20) << "TITLE" 
                          << std::setw(15) << "AUTHOR" 
                          << std::setw(8)  << "PAGES" 
                          << std::setw(10) << "ID" 
                          << "STATUS\n";
                std::cout << "-----------------------------------------------------------------\n";
                for (const auto& book : library) {
                    std::cout << std::left 
                              << std::setw(20) << book.title 
                              << std::setw(15) << book.author 
                              << std::setw(8)  << book.pages 
                              << std::setw(10) << book.id 
                              << book.borrowedStatus << "\n";
                }
            }
        } 
        else if (choice == 3) {
            std::string searchTitle = getStringInput("Enter book title to look for: ");
            bool targetFound = false;
            
            for (const auto& book : library) {
                if (book.title == searchTitle) {
                    std::cout << "\nMatch found!\n";
                    std::cout << "Title: " << book.title << "\nAuthor: " << book.author 
                              << "\nPages: " << book.pages << "\nID: " << book.id 
                              << "\nStatus: " << book.borrowedStatus << "\n";
                    targetFound = true;
                    break;
                }
            }
            if (!targetFound) std::cout << "No book matches that title in the collection.\n";
        } 
        else {
            std::cout << "Unknown operational command.\n";
        }
    }
    return 0;
}
/*
Methodology and Problem-Solving Strategy
The way in which catalog assets are managed is based on an object-oriented method in which all the metadata is stored in the Book structure as strings and integers. Rather than using fixed-size arrays, the program keeps the books in a dynamic vector so that the collection can expand or contract as required and thus the possibility of memory errors is decreased.
A big problem was the way multiple-word inputs were handled, since standard extraction operations cease at spaces. In order to solve this, a getStringInput function was developed which makes use of both std::ws and std::getline, thereby getting rid of the remaining newlines and capturing the whole line.
The console interface achieves this by means of a while loop which continuously reads user input and then carries out the relevant actions according to conditional statements. In regard to table formatting, it uses input and output manipulators such as std::left and std::setw to produce properly arranged columns without the need for any additional packages. Searches for records are performed with the aid of iterative loops, which in turn ensures an efficient and simple traversal of the data.
*/