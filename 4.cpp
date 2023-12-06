#include <iostream>
#include <string>

class Person {
public:
  // Default constructor
  Person() : name(""), dob(""), blood_group(""), height(0.0), weight(0.0), insurance_policy_number(0),
              contact_address(""), phone_number(""), driving_license_number("") {}

  // Constructor with parameters
  Person(const std::string& name, const std::string& dob, const std::string& blood_group, double height, double weight,
          int insurance_policy_number, const std::string& contact_address, const std::string& phone_number,
          const std::string& driving_license_number) :
      name(name), dob(dob), blood_group(blood_group), height(height), weight(weight), insurance_policy_number(insurance_policy_number),
      contact_address(contact_address), phone_number(phone_number), driving_license_number(driving_license_number) {}

  // Copy constructor
  Person(const Person& other) {
    name = other.name;
    dob = other.dob;
    blood_group = other.blood_group;
    height = other.height;
    weight = other.weight;
    insurance_policy_number = other.insurance_policy_number;
    contact_address = other.contact_address;
    phone_number = other.phone_number;
    driving_license_number = other.driving_license_number;
  }

  // Destructor
  ~Person() {
    // Release any dynamically allocated memory
  }

  // Static member function to display system information
  static void displaySystemInfo() {
    std::cout << "Personnel Information System" << std::endl;
  }

  // Friend function to display person details
  friend std::ostream& operator<<(std::ostream& os, const Person& person) {
    os << "Name: " << person.name << std::endl;
    os << "Date of Birth: " << person.dob << std::endl;
    os << "Blood Group: " << person.blood_group << std::endl;
    os << "Height: " << person.height << std::endl;
    os << "Weight: " << person.weight << std::endl;
    os << "Insurance Policy Number: " << person.insurance_policy_number << std::endl;
    os << "Contact Address: " << person.contact_address << std::endl;
    os << "Phone Number: " << person.phone_number << std::endl;
    os << "Driving License Number: " << person.driving_license_number << std::endl;
    return os;
  }

  // This pointer example
  void displayThisPointer() const {
    std::cout << "This pointer address: " << this << std::endl;
  }

  // Inline function to calculate body mass index (BMI)
  inline double calculateBMI() const {
    return weight / (height * height);
  }

private:
  std::string name;
  std::string dob;
  std::string blood_group;
  double height;
  double weight;
  int insurance_policy_number;
  std::string contact_address;
  std::string phone_number;
  std::string driving_license_number;
};

int main() {
  // Demonstrate constructors, copy constructor, and destructor
  Person person1("John Doe", "1980-01-01", "A+", 1.80, 75.0, 123456789, "123 Main Street", "123-456-7890", "ABC123");
  Person person2 = person1; // Copy constructor
  std::cout << person1 << std::endl; // Destructor automatically called when program exits

  // Demonstrate static member function
  Person::displaySystemInfo();

  // Demonstrate friend function
  std::cout << person2;

  // Demonstrate this pointer
  person1.displayThisPointer();

  // Demonstrate inline function
  std::cout << "BMI: " << person1.calculateBMI() << std::endl;

  return 0;
}
