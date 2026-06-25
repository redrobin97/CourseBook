#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

//***
// Course Structure
//***

struct Course {
    string courseNumber;
    string courseName;
    vector<string> prereqs;
};

//***
// Tree Node
//***

struct Node {
    Course course;
    Node* left;
    Node* right;

    Node(Course newCourse)
    {
        course = newCourse;
        left = nullptr;
        right = nullptr;
    }
};

//***
// Binary Search Tree Class
//***

class BinarySearchTree {

private:
    Node* root;

    void addNode(Node*& current, Course course);
    void inOrder(Node* node);
    Node* search(Node* current, string courseNumber);
    void destroyTree(Node* node);

public:
    BinarySearchTree();
    ~BinarySearchTree();

    void Insert(Course course);
    void PrintCourseList();
    Course Search(string courseNumber);
};

//***
// Function Prototypes
//***

void loadCourses(string fileName, BinarySearchTree& bst);
void printCourseInfo(Course course);
void displayMenu();

//***
// Main
//***

int main() {

    // Create binary search tree
    BinarySearchTree bst;

    // Variables for menu
    string fileName;
    string courseNumber;
    int choice = 0;

    // Welcome message
    cout << "Welcome to the course planner." << endl;

    // Continue until user exits
    while (choice != 9)
    {
        // Show menu and get choice
        displayMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            // Load courses from file
            cout << "Enter file name: ";
            cin >> fileName;
            loadCourses(fileName, bst);
            break;

        case 2:
            // Print all courses
            cout << "Here is a sample schedule:" << endl;
            bst.PrintCourseList();
            break;

        case 3:
        {
            // Search for one course
            cout << "Enter course number: ";
            cin >> courseNumber;

            Course course = bst.Search(courseNumber);

            // Print result
            if (course.courseNumber == "")
            {
                cout << "Course not found." << endl;
            }
            else
            {
                printCourseInfo(course);
            }

            break;
        }

        case 9:
            // Exit program
            cout << "Thank you for using the course planner." << endl;
            break;

        default:
            // Invalid menu choice
            cout << choice << " is not a valid option." << endl;
            break;
        }
    }

    return 0;
}

//***
// BinarySearchTree Functions
//***

BinarySearchTree::BinarySearchTree() {
    // Set root to empty
    root = nullptr;
}

BinarySearchTree::~BinarySearchTree() {
    // Delete all nodes
    destroyTree(root);
}

void BinarySearchTree::Insert(Course course) {

    // If tree is empty, create root node
    if (root == nullptr)
    {
        root = new Node(course);
    }
    else
    {
        // Otherwise insert into tree
        addNode(root, course);
    }
}

void BinarySearchTree::addNode(Node*& current, Course course) {

    // Empty position found, insert new node
    if (current == nullptr)
    {
        current = new Node(course);
    }
    // New course belongs on left
    else if (current->course.courseNumber > course.courseNumber)
    {
        addNode(current->left, course);
    }
    // New course belongs on right
    else
    {
        addNode(current->right, course);
    }
}

void BinarySearchTree::PrintCourseList() {
    // Print courses in alphanumeric order
    inOrder(root);
}

void BinarySearchTree::inOrder(Node* node) {

    // No node to process
    if (node == nullptr)
    {
        return;
    }

    // Visit left side
    inOrder(node->left);

    // Print current course
    printCourseInfo(node->course);

    // Visit right side
    inOrder(node->right);
}

Course BinarySearchTree::Search(string courseNumber) {

    // Search tree starting at root
    Node* foundNode = search(root, courseNumber);

    // Return course if found
    if (foundNode != nullptr)
    {
        return foundNode->course;
    }

    // Return empty course if not found
    Course emptyCourse;
    return emptyCourse;
}

Node* BinarySearchTree::search(Node* current, string courseNumber) {

    // End of branch, course not found
    if (current == nullptr)
    {
        return nullptr;
    }

    // Course found
    if (courseNumber == current->course.courseNumber)
    {
        return current;
    }

    // Continue searching left
    if (courseNumber < current->course.courseNumber)
    {
        return search(current->left, courseNumber);
    }
    // Continue searching right
    else
    {
        return search(current->right, courseNumber);
    }
}

void BinarySearchTree::destroyTree(Node* node) {

    // End of branch
    if (node == nullptr)
    {
        return;
    }

    // Delete left subtree
    destroyTree(node->left);

    // Delete right subtree
    destroyTree(node->right);

    // Delete current node
    delete node;
}

//***
// Helper Functions
//***

void loadCourses(string fileName, BinarySearchTree& bst) {

    // Open input file
    ifstream file(fileName);

    // Check if file opened
    if (!file.is_open())
    {
        cout << "Error opening file." << endl;
        return;
    }

    string line;

    // Read one line at a time
    while (getline(file, line))
    {
        // Create stream from line
        stringstream ss(line);
        string item;
        Course course;

        // Read course number
        getline(ss, course.courseNumber, ',');

        // Read course name
        getline(ss, course.courseName, ',');

        // Read prerequisites
        while (getline(ss, item, ','))
        {
            course.prereqs.push_back(item);
        }

        // Insert course into tree
        bst.Insert(course);
    }

    // Close file
    file.close();

    cout << "Courses loaded successfully." << endl;
}

void printCourseInfo(Course course) {

    // Print course number and title
    cout << course.courseNumber << ", " << course.courseName;

    // Print prerequisites if any
    if (course.prereqs.size() > 0)
    {
        cout << endl << "Prerequisites: ";

        for (unsigned int i = 0; i < course.prereqs.size(); ++i)
        {
            cout << course.prereqs.at(i);

            if (i < course.prereqs.size() - 1)
            {
                cout << ", ";
            }
        }
    }

    cout << endl;
}

void displayMenu() {

    // Display menu options
    cout << endl;
    cout << "1. Load Data Structure" << endl;
    cout << "2. Print Course List" << endl;
    cout << "3. Print Course" << endl;
    cout << "9. Exit" << endl;
    cout << "What would you like to do? ";
}