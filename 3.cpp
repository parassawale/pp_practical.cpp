#include <iostream>
#include <string>

class Book {
public:
  // Constructor with dynamic memory allocation
  Book(const std::string& title, const std::string& author, double price, const std::string& publisher, int stock) :
      title_(new std::string(title)), author_(new std::string(author)), price_(price), publisher_(new std::string(publisher)), stock_(stock) {}

  // Destructor to release allocated memory
  ~Book() {
    delete title_;
    delete author_;
    delete publisher_;
  }

  // Check book availability
  bool isAvailable(const std::string& title, const std::string& author) const {
    return *title_ == title && *author_ == author && stock_ > 0;
  }

  // Display book details
  void displayDetails() const {
    std::cout << "Title: " << *title_ << std::endl;
    std::cout << "Author: " << *author_ << std::endl;
    std::cout << "Price: $" << price_ << std::endl;
    std::cout << "Publisher: " << *publisher_ << std::endl;
    std::cout << "Stock: " << stock_ << std::endl;
  }

  // Purchase book
  void purchase(int quantity) {
    if (stock_ >= quantity) {
      stock_ -= quantity;
      std::cout << "Total cost: $" << quantity * price_ << std::endl;
    } else {
      std::cout << "Required copies not in stock." << std::endl;
    }
  }

private:
  std::string* title_;
  std::string* author_;
  double price_;
  std::string* publisher_;
  int stock_;
};

int main() {
  // Create books
  Book book1("The Lord of the Rings", "J.R.R. Tolkien", 20.00, "HarperCollins", 5);
  Book book2("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", 15.00, "Pan Macmillan", 3);

  // Search for book
  std::string title, author;
  std::cout << "Enter book title: ";
  std::cin >> title;
  std::cout << "Enter book author: ";
  std::cin >> author;

  // Check availability
  if (book1.isAvailable(title, author)) {
    book1.displayDetails();
    int quantity;
    std::cout << "Enter quantity: ";
    std::cin >> quantity;
    book1.purchase(quantity);
  } else if (book2.isAvailable(title, author)) {
    book2.displayDetails();
    int quantity;
    std::cout << "Enter quantity: ";
    std::cin >> quantity;
    book2.purchase(quantity);
  } else {
    std::cout << "Book not found." << std::endl;
  }

  return 0;
}
