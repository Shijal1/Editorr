// // Vehicle Management System
// #include <iostream>
// #include <string>
// using namespace std;

// // Base class
// class Vehicle {
// protected:
//     string brand;
//     int year;
// public:
//     Vehicle(string b, int y) : brand(b), year(y) {}
    
//     // Virtual function for polymorphism
//     virtual void displayInfo() {
//         cout << "Brand: " << brand << ", Year: " << year;
//     }
    
//     // Pure virtual function making this an abstract class
//     virtual void startEngine() = 0;
    
//     virtual ~Vehicle() {
//         cout << "Vehicle destructor called" << endl;
//     }
// };

// // Single Inheritance
// class Car : public Vehicle {
// private:
//     int numDoors;
// public:
//     Car(string b, int y, int d) : Vehicle(b, y), numDoors(d) {}
    
//     // Function overriding
//     void displayInfo() override {
//         Vehicle::displayInfo();
//         cout << ", Doors: " << numDoors << endl;
//     }
    
//     void startEngine() override {
//         cout << "Car engine started with key/button" << endl;
//     }
    
//     // Specific to Car class
//     void openSunroof() {
//         cout << "Sunroof opened" << endl;
//     }
// };

// // Hierarchical Inheritance (another child of Vehicle)
// class Motorcycle : public Vehicle {
// private:
//     bool hasSidecar;
// public:
//     Motorcycle(string b, int y, bool s) : Vehicle(b, y), hasSidecar(s) {}
    
//     void displayInfo() override {
//         Vehicle::displayInfo();
//         cout << ", Has sidecar: " << (hasSidecar ? "Yes" : "No") << endl;
//     }
    
//     void startEngine() override {
//         cout << "Motorcycle engine started with kickstart" << endl;
//     }
// };

// // Multilevel Inheritance
// class ElectricCar : public Car {
// private:
//     int batteryCapacity;
// public:
//     ElectricCar(string b, int y, int d, int bc) : Car(b, y, d), batteryCapacity(bc) {}
    
//     void displayInfo() override {
//         Car::displayInfo();
//         cout << "Battery Capacity: " << batteryCapacity << " kWh" << endl;
//     }
    
//     void startEngine() override {
//         cout << "Electric car silently powered on" << endl;
//     }
    
//     void chargeBattery() {
//         cout << "Battery charging..." << endl;
//     }
// };

// // Multiple Inheritance
// class HybridVehicle : public Car, public Motorcycle {
// private:
//     string hybridType;
// public:
//     // Note: This is a contrived example to show multiple inheritance
//     // In real scenarios, multiple inheritance from two concrete classes is often problematic
//     HybridVehicle(string b, int y, int d, bool s, string ht) : 
//         Car(b, y, d), Motorcycle(b, y, s), hybridType(ht) {}
    
//     void displayInfo() override {
//         cout << "Hybrid Vehicle - Type: " << hybridType << endl;
//         Car::displayInfo();
//     }
    
//     void startEngine() override {
//         cout << "Hybrid engine started with combined system" << endl;
//     }
// };

// int main() {
//     cout << "==== Vehicle Management System ====\n";
    
//     // Polymorphism in action
//     Vehicle* garage[4];
    
//     garage[0] = new Car("Toyota", 2020, 4);
//     garage[1] = new Motorcycle("Harley", 2019, false);
//     garage[2] = new ElectricCar("Tesla", 2022, 4, 75);
    
    
//     for (int i = 0; i < 4; i++) {
//         garage[i]->displayInfo();
//         garage[i]->startEngine();
//         cout << "-------------------\n";
//     }
    
//     // Clean up
//     for (int i = 0; i < 4; i++) {
//         delete garage[i];
//     }
    
//     return 0;
// }
// ---------------------------------------------------------------------------------------------------------
// University System
// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;

// // Base class
// class Person {
// protected:
//     string name;
//     int age;
// public:
//     Person(string n, int a) : name(n), age(a) {}
    
//     virtual void display() {
//         cout << "Name: " << name << ", Age: " << age;
//     }
    
//     virtual ~Person() {}
// };

// // Single Inheritance
// class Student : public Person {
// private:
//     string studentId;
//     double gpa;
// public:
//     Student(string n, int a, string id, double g) : 
//         Person(n, a), studentId(id), gpa(g) {}
    
//     void display() override {
//         Person::display();
//         cout << ", Student ID: " << studentId << ", GPA: " << gpa << endl;
//     }
    
//     void study() {
//         cout << name << " is studying" << endl;
//     }
// };

// // Another child class (Hierarchical Inheritance)
// class Professor : public Person {
// private:
//     string department;
//     vector<string> courses;
// public:
//     Professor(string n, int a, string dept) : 
//         Person(n, a), department(dept) {}
    
//     void display() override {
//         Person::display();
//         cout << ", Department: " << department << ", Courses: ";
//         for (const auto& course : courses) {
//             cout << course << " ";
//         }
//         cout << endl;
//     }
    
//     void addCourse(string course) {
//         courses.push_back(course);
//     }
    
//     void teach() {
//         cout << name << " is teaching" << endl;
//     }
// };

// // Multilevel Inheritance
// class ResearchStudent : public Student {
// private:
//     string researchTopic;
// public:
//     ResearchStudent(string n, int a, string id, double g, string topic) : 
//         Student(n, a, id, g), researchTopic(topic) {}
    
//     void display() override {
//         Student::display();
//         cout << "Research Topic: " << researchTopic << endl;
//     }
    
//     void conductResearch() {
//         cout << name << " is conducting research on " << researchTopic << endl;
//     }
// };

// // Interface (Abstract class with all pure virtual functions)
// class IUniversityMember {
// public:
//     virtual void attendMeeting() = 0;
//     virtual void printIDCard() = 0;
//     virtual ~IUniversityMember() {}
// };

// // Multiple Inheritance
// class TeachingAssistant : public Student, public IUniversityMember {
// private:
//     string courseAssisting;
// public:
//     TeachingAssistant(string n, int a, string id, double g, string course) : 
//         Student(n, a, id, g), courseAssisting(course) {}
    
//     void display() override {
//         Student::display();
//         cout << "Assisting with course: " << courseAssisting << endl;
//     }
    
//     // Implement interface methods
//     void attendMeeting() override {
//         cout << name << " is attending TA meeting for " << courseAssisting << endl;
//     }
    
//     void printIDCard() override {
//         cout << "TA ID Card - Name: " << name << ", Course: " << courseAssisting << endl;
//     }
// };

// int main() {
//     cout << "==== University System ====\n";
    
//     // Polymorphism with Person base class
//     Person* people[4];
    
//     people[0] = new Student("Alice", 20, "S1001", 3.8);
//     people[1] = new Professor("Dr. Smith", 45, "Computer Science");
//     people[2] = new ResearchStudent("Bob", 25, "S2001", 3.9, "Machine Learning");
//     people[3] = new TeachingAssistant("Charlie", 22, "S1002", 3.7, "Data Structures");
    
//     // Dynamic cast example
//     for (int i = 0; i < 4; i++) {
//         people[i]->display();
        
//         // Try to cast to Student
//         Student* student = dynamic_cast<Student*>(people[i]);
//         if (student) {
//             student->study();
//         }
        
//         // Try to cast to Professor
//         Professor* prof = dynamic_cast<Professor*>(people[i]);
//         if (prof) {
//             prof->teach();
//         }
        
//         // Try to cast to IUniversityMember
//         IUniversityMember* uniMember = dynamic_cast<IUniversityMember*>(people[i]);
//         if (uniMember) {
//             uniMember->attendMeeting();
//             uniMember->printIDCard();
//         }
        
//         cout << "-------------------\n";
//     }
    
//     // Clean up
//     for (int i = 0; i < 4; i++) {
//         delete people[i];
//     }
    
//     return 0;
// }
// -------------------------------------------------------------------------------------------------------------------------------
// #include <iostream>
// #include <string>
// using namespace std;

// class Bankaccount {
// protected:
//     string accountholdername;
//     double accountbalance;
// public:
//     Bankaccount(string name, double balance) {
//         accountholdername = name;
//         accountbalance = balance;
//     }
    
//     void deposit(double amount) {
//         accountbalance += amount;
//         cout << "Deposited Successfully." << endl;
//     }
    
//     void withdrawal(double amount) {
//         if (amount > accountbalance) {
//             cout << "INSUFFICIENT BALANCE!" << endl;
//         }
//         else {
//             accountbalance -= amount;
//             cout << "Withdrawal Successful. Remaining Balance: " << accountbalance << endl;
//         }
//     }
    
//     virtual void display() const {
//         cout << "\nAccount Holder Name : " << accountholdername << endl;
//         cout << "Account Balance     : " << accountbalance << endl;
//     }
// };

// class SavingsAccount : public Bankaccount {
// private:
//     double irate;
// public:
//     SavingsAccount(string name, double balance, double rate)
//         : Bankaccount(name, balance), irate(rate) {}
    
//     void display() const override {
//         Bankaccount::display();
//         cout << "Interest Rate      : " << irate << "%" << endl;
//     }
// };

// int main() {
//     // Create a Bankaccount object
//     Bankaccount regularAccount("John Doe", 5000.0);
//     cout << "Regular Bank Account:"; 
//     regularAccount.display();
    
//     regularAccount.deposit(2000.0);
//     regularAccount.withdrawal(1000.0);
//     regularAccount.display();
    
//     // Create a SavingsAccount object
//     SavingsAccount savingsAccount("Jane Smith", 10000.0, 3.5);
//     cout << "\nSavings Account:";
//     savingsAccount.display();
    
//     savingsAccount.deposit(5000.0);
//     savingsAccount.withdrawal(2000.0);
//     savingsAccount.display();
    
//     return 0;
// }
// ................................................................................................................
// . File Duplicator - "Clone Your Files with Precision!"
// #include <iostream>
// #include <fstream>
// using namespace std;

// int main() {
//     string source, destination;
//     cout << "Enter source filename: ";
//     cin >> source;
//     cout << "Enter destination filename: ";
//     cin >> destination;

//     ifstream in(source, ios::binary);
//     ofstream out(destination, ios::binary);

//     if (!in) {
//         cerr << "Source file not found!";
//         return 1;
//     }

//     out << in.rdbuf();
    
//     cout << "File copied successfully!\n";
//     in.close();
//     out.close();
//     return 0;
// }
// .......................................................................................................................................
// File Stat Master - "Know Your Files Inside Out!"
// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <map>
// using namespace std;

// int main() {
//     string filename;
//     cout << "Enter filename: ";
//     cin >> filename;

//     ifstream file(filename);
//     if (!file) {
//         cerr << "File not found!";
//         return 1;
//     }

//     int chars = 0, words = 0, lines = 0;
//     string line, word;
//     map<string, int> wordCount;

//     while (getline(file, line)) {
//         lines++;
//         chars += line.length() + 1; // +1 for newline
//         istringstream iss(line);
//         while (iss >> word) {
//             words++;
//             wordCount[word]++;
//         }
//     }

//     auto mostFrequent = max_element(wordCount.begin(), wordCount.end(),
//         [](const pair<string, int>& a, const pair<string, int>& b) {
//             return a.second < b.second;
//         });

//     cout << "Statistics:\n";
//     cout << "Characters: " << chars << endl;
//     cout << "Words: " << words << endl;
//     cout << "Lines: " << lines << endl;
//     cout << "Most frequent word: " << mostFrequent->first 
//          << " (" << mostFrequent->second << " times)\n";

//     file.close();
//     return 0;
// }
// .....................................................................................................................................
// Student Record Keeper - "Organize Academic Data Effortlessly!"
// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// struct Student {
//     string name;
//     int roll;
//     float marks;
// };

// void addStudent() {
//     ofstream file("students.dat", ios::app | ios::binary);
//     Student s;
    
//     cout << "Enter name: "; cin >> s.name;
//     cout << "Enter roll: "; cin >> s.roll;
//     cout << "Enter marks: "; cin >> s.marks;
    
//     file.write(reinterpret_cast<char*>(&s), sizeof(Student));
//     file.close();
// }

// void displayAll() {
//     ifstream file("students.dat", ios::binary);
//     Student s;
    
//     while (file.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
//         cout << "Name: " << s.name << ", Roll: " << s.roll 
//              << ", Marks: " << s.marks << endl;
//     }
//     file.close();
// }

// int main() {
//     while (true) {
//         cout << "\n1. Add\n2. View All\n3. Exit\nChoice: ";
//         int choice; cin >> choice;
        
//         switch (choice) {
//             case 1: addStudent(); break;
//             case 2: displayAll(); break;
//             case 3: return 0;
//             default: cout << "Invalid choice!";
//         }
//     }
// }
// ................................................................................................................................
// #include <iostream>
// #include <fstream>
// #include <map>
// #include <set>
// #include <vector>
// #include<algorithm>
// using namespace std;

// class InvertedIndex {
//     map<string, set<string>> index;
// public:
//     void addFile(const string& filename) {
//         ifstream file(filename);
//         if (!file) {
//             cerr << "Error opening " << filename << endl;
//             return;
//         }

//         string word;
//         while (file >> word) {
//             // Simple word cleaning
//             word.erase(remove_if(word.begin(), word.end(), 
//                        [](char c) { return !isalpha(c); }), word.end());
//             if (!word.empty()) {
//                 transform(word.begin(), word.end(), word.begin(), ::tolower);
//                 index[word].insert(filename);
//             }
//         }
//         file.close();
//     }

//     void search(const string& term) {
//         string searchTerm = term;
//         transform(searchTerm.begin(), searchTerm.end(), searchTerm.begin(), ::tolower);
        
//         auto it = index.find(searchTerm);
//         if (it != index.end()) {
//             cout << "Found in files:\n";
//             for (const auto& file : it->second) {
//                 cout << "- " << file << endl;
//             }
//         } else {
//             cout << "Term not found!\n";
//         }
//     }
// };

// int main() {
//     InvertedIndex index;
//     vector<string> files = {"file1.txt", "file2.txt", "file3.txt"};
    
//     for (const auto& file : files) {
//         index.addFile(file);
//     }

//     string term;
//     cout << "Enter search term: ";
//     cin >> term;
//     index.search(term);

//     return 0;
// }
// ....................................................................................
// File Differ - "Spot Changes Between Files Instantly!"
// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// vector<string> readLines(const string& filename) {
//     vector<string> lines;
//     ifstream file(filename);
//     string line;
    
//     while (getline(file, line)) {
//         lines.push_back(line);
//     }
    
//     file.close();
//     return lines;
// }

// void compareFiles(const string& file1, const string& file2) {
//     auto lines1 = readLines(file1);
//     auto lines2 = readLines(file2);
    
//     size_t maxLines = max(lines1.size(), lines2.size());
    
//     cout << "Comparison Results:\n";
//     cout << "Line | File 1 | File 2\n";
//     cout << "----------------------\n";
    
//     for (size_t i = 0; i < maxLines; ++i) {
//         string line1 = (i < lines1.size()) ? lines1[i] : "EOF";
//         string line2 = (i < lines2.size()) ? lines2[i] : "EOF";
        
//         if (line1 != line2) {
//             cout << i+1 << " | " << line1 << " | " << line2 << endl;
//         }
//     }
// }

// int main() {
//     string file1, file2;
//     cout << "Enter first file: "; cin >> file1;
//     cout << "Enter second file:";cin >> file2;
    
//     compareFiles(file1, file2);
    
//     return 0;
// }


// -----------------------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------------------------------
//  Inventory Management
// Implement an inventory system that:

// Tracks items with quantity alerts

// Processes transactions

// Generates low stock reports

// #include <iostream>
// #include <map>
// #include <set>
// #include <vector>
// using namespace std;

// class Inventory {
//      map<string, int> stock;
//     map<string, double> prices;
//     set<string> lowStockItems;
//     int threshold = 10;
    
// public:
//     void addItem(const string& item, int quantity, double price) {
//         stock[item] += quantity;
//         prices[item] = price;
//         checkStock(item);
//     }
    
//     bool processOrder(const string& item, int quantity) {
//         if(stock[item] < quantity) return false;
//         stock[item] -= quantity;
//         checkStock(item);
//         return true;
//     }
    
//     void checkStock(const string& item) {
//         if(stock[item] < threshold) {
//             lowStockItems.insert(item);
//         } else {
//             lowStockItems.erase(item);
//         }
//     }
    
//     vector<string> getLowStock() const {
//         return vector<string>(lowStockItems.begin(), lowStockItems.end());
//     }
    
//     void generateReport() const {
//         cout << "Inventory Report:\n";
//         for(const auto& item : stock) {
//             cout << item.first << ": " << item.second 
//                  << " (Price: $" << prices.at(item.first) << ")";
//             if(lowStockItems.count(item.first)) {
//                 cout << " - LOW STOCK!";
//             }
//             cout << endl;
//         }
//     }
// };

// int main() {
//     Inventory store;
    
//     // Add initial stock
//     store.addItem("Laptop", 15, 999.99);
//     store.addItem("Phone", 8, 699.99);  // Will be marked low stock
//     store.addItem("Tablet", 25, 349.99);
    
//     // Process some orders
//     store.processOrder("Laptop", 3);
//     store.processOrder("Phone", 5);
    
//     // Generate report
//     store.generateReport();
    
//     // Check low stock
//     auto lowStock = store.getLowStock();
//     cout << "\nItems needing restock:\n";
//     for(auto& item : lowStock) {
//         cout << "- " << item << endl;
//     }
    
//     return 0;
// }