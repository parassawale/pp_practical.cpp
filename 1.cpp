#include <iostream>
#include <iomanip>

class WeatherReport {
public:
  // Default constructor
  WeatherReport() : day_of_month(99), hightemp(999), lowtemp(-999), amount_rain(0), amount_snow(0) {}

  // Function to prompt user and set values
  void setValues() {
    std::cout << "Enter Day of Month: ";
    std::cin >> day_of_month;
    std::cout << "Enter High Temperature: ";
    std::cin >> hightemp;
    std::cout << "Enter Low Temperature: ";
    std::cin >> lowtemp;
    std::cout << "Enter Amount of Rain: ";
    std::cin >> amount_rain;
    std::cout << "Enter Amount of Snow: ";
    std::cin >> amount_snow;
  }

  // Display weather report
  void displayReport() {
    std::cout << "Day: " << day_of_month << std::endl;
    std::cout << "High Temperature: " << hightemp << "°F" << std::endl;
    std::cout << "Low Temperature: " << lowtemp << "°F" << std::endl;
    std::cout << "Rainfall: " << amount_rain << " mm" << std::endl;
    std::cout << "Snowfall: " << amount_snow << " cm" << std::endl;
  }

private:
  int day_of_month;
  double hightemp;
  double lowtemp;
  double amount_rain;
  double amount_snow;
};

int main() {
  WeatherReport report;
  int choice;

  do {
    std::cout << "1. Enter Data" << std::endl;
    std::cout << "2. Display Report" << std::endl;
    std::cout << "3. Exit" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
      case 1:
        report.setValues();
        break;
      case 2:
        report.displayReport();
        break;
      case 3:
        break;
      default:
        std::cout << "Invalid choice!" << std::endl;
    }
  } while (choice != 3);

  return 0;
}
