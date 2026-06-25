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

    vector<string> prereqs;
    

};

//==================================================
// Tree Node
//==================================================

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

//==================================================
// Binary Search Tree Class
//==================================================

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

//constructor
BinarySearchTree::BinarySearchTree() {

    root = nullptr;

}

//deconstructor
BinarySearchTree::~BinarySearchTree() {

    destroyTree(root);
}

void BinarySearchTree::Insert(Course course) {


    if(root == nullptr)
    {
        root = new Node(course);
    }

    else addNode(root, course);

}

void BinarySearchTree::addNode(Node*& current, Course course) {

    //if current spot empty, assign new node
    if(current == nullptr)
    {
        current = new Node(course);
    }
    //if less than current go left
    else if(current->course.courseNumber > course.courseNumber)
    {
        addNode(current->left, course);
    }
    //else more than current go right
    else
    {
        addNode(current->right, course);
    }
    
}

void BinarySearchTree::PrintCourseList() {

    //call inOrder starting at root
    inOrder(root);

}

void BinarySearchTree::inOrder(Node* node) {

    //no node here (base case)
    if (node == nullptr)
    {
        return;
    }

    //if left exists go left    
    inOrder(node->left);
    
    //if no left then at lowest
    printCourseInfo(node->course);

    //if no lefts remaining try right
    inOrder(node->right);
    
}

Course BinarySearchTree::Search(string courseNumber) {

    //call search to find course
    Node* foundNode = search(root, courseNumber);

    //if found
    if (foundNode != nullptr)
    {
        return foundNode->course;
    }

    //if not found return blank course
    Course emptyCourse;
    return emptyCourse;
    


}

Node* BinarySearchTree::search(Node* current, string courseNumber) {


    //end of search, not found
    if(current == nullptr)
    {
        //notfound
        return nullptr;
    }

    // current = target, return
    if(courseNumber == current->course.courseNumber)
    {
        return current;
    }

    //if coursenumber to left, go left
    if(courseNumber < current->course.courseNumber)
    {
        return search(current->left, courseNumber);
    }

    //if courseNumber is not current and not to left,  go right
    else
    {
        return search(current->right, courseNumber);
    }

    
}

void BinarySearchTree::destroyTree(Node* node) {


    //nothing to delete
    if(node == nullptr)
    {
        return;
    }

    //if something exists to left, go left
    destroyTree(node->left);
   
    //if something exists to right, go right
    destroyTree(node->right);
    
    //nothing exists past this point, delete node
    delete node;

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