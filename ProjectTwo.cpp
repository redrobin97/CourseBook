#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

//==================================================
// Course Structure
//==================================================

struct Course {
    string courseNumber;
    string courseName;

    string<vector> prereqs;
    

};

//==================================================
// Tree Node
//==================================================

struct Node {

};

//==================================================
// Binary Search Tree Class
//==================================================

class BinarySearchTree {

private:

    Node* root;

    void addNode(Node* node, Course course);

    void inOrder(Node* node);

    Node* search(Node* node, string courseNumber);

    void destroyTree(Node* node);

public:

    BinarySearchTree();

    ~BinarySearchTree();

    void Insert(Course course);

    void PrintCourseList();

    Course Search(string courseNumber);
};

//==================================================
// Function Prototypes
//==================================================

void loadCourses(string fileName, BinarySearchTree& bst);

void printCourseInfo(Course course);

void displayMenu();

//==================================================
// Main
//==================================================

int main() {

}

//==================================================
// BinarySearchTree Functions
//==================================================

BinarySearchTree::BinarySearchTree() {

}

BinarySearchTree::~BinarySearchTree() {

}

void BinarySearchTree::Insert(Course course) {

}

void BinarySearchTree::addNode(Node* node, Course course) {

}

void BinarySearchTree::PrintCourseList() {

}

void BinarySearchTree::inOrder(Node* node) {

}

Course BinarySearchTree::Search(string courseNumber) {

}

Node* BinarySearchTree::search(Node* node, string courseNumber) {

}

void BinarySearchTree::destroyTree(Node* node) {

}

//==================================================
// Helper Functions
//==================================================

void loadCourses(string fileName, BinarySearchTree& bst) {

}

void printCourseInfo(Course course) {

}

void displayMenu() {

}