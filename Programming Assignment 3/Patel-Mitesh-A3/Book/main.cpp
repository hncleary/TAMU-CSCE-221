#include "Record.h"
#include "TemplateDoublyLinkedList.h"
#include <vector>
#include <fstream>

// insert function
void insertCurrent(vector<DoublyLinkedList<Record> > &v, Record r)
{
    
    const int ASCII = 65;
    string holdLast = r.lastName; // make a new string and let it be the last name in record
    int firstLetter = holdLast[0]; // let the first letter hold the ascii value of the first character in last name
    int index = firstLetter - ASCII; // subtract 65 because it will order the vector correctly. ie v[0] will start with A v[11] starts with L
    v[index].insertOrderly(r); // insert the record into list in order
    
}
// display function
void displayList(vector<DoublyLinkedList<Record> > &v)
{
    for (int i = 0; i<v.size(); ++i)
    {
        cout << "List ["<< i << "]" << endl << endl;
        cout << v[i] << endl;
        cout << endl;
    }
}
// search function
Record* searchBook(vector<DoublyLinkedList<Record> > &v, Record r)
{
    //Make sure to check if more than one person with same last name, if more than one person with same first name
    
    //Create a new Record to return when the right record is found
    Record* correct = new Record;
    
    //Make sure user started with name with capital letter
    const int ASCII = 65;
    string holdLast = r.lastName; // make a new string and let it be the last name in record
    int firstLetter = holdLast[0]; // let the first letter hold the ascii value of the first character in last name
    int index = firstLetter - ASCII; // subtract 65 because it will order the vector correctly. ie v[0] will start with A v[11] starts with L
    
    DoublyLinkedList<Record> tempList; // create a temporary list
    
    DListNode<Record>* correctNode = v[index].getFirst();
    int count = 0; // keeps track of how many people with same last name or same first name. Used in if statements
    
    while(correctNode != v[index].getAfterLast()) // iterate through list
    {
        if(correctNode->getElem().lastName == r.lastName) // if the nodes data (record) last name is = to the one we want to find
        {
            *correct = correctNode->getElem(); // get the last name
            tempList.insertOrderly(*correct); // insert the correct node into the temporary list to hold
            ++count;
        }
        correctNode = correctNode->getNext(); // get next elem to continue search for duplicate
    }
    if(count == 0)
        return NULL;
    if(count == 1)
        return correct;
    cout << "There are " << count <<" people with the last name " << r.lastName << ".\n" << " Enter their first name, and make sure the first letter is capitilized." << endl;
    cin >> r.firstName;
    r.firstName[0] = toupper(r.firstName[0]);
    if((int) r.firstName[0] < 65 )
    {
        throw 3;
    }
    
// checks first name
    
    count = 0;// reset counter
    DoublyLinkedList<Record> tempList2; // create second temp list
    
    correctNode = tempList.getFirst();
    while(correctNode != tempList.getAfterLast())
    {
        if (correctNode->getElem().firstName == r.firstName)
        {
            *correct = correctNode->getElem();
            tempList2.insertOrderly(*correct);
            ++count;
        }
        correctNode = correctNode->getNext();
    }
    if (count == 0)
        return NULL;
    if (count == 1)
        return correct;
    cout<<"There are "<< count <<" people that have the both the last name ("<< r.lastName <<") and first name ("<< r.firstName <<") you provided. \n";
    
// checks UIN
    cout << "Please enter their UIN." << endl;
    cin >> r.UIN;
    
    count = 0; //reset counter
    DoublyLinkedList<Record> tempList3;
    
    correctNode = tempList2.getFirst();
    while(correctNode != tempList2.getAfterLast())
    {
        if (correctNode->getElem().UIN == r.UIN)
        {
            *correct = correctNode->getElem();
            tempList3.insertOrderly(*correct);
            ++count;
        }
        correctNode = correctNode->getNext();
    }
    if (count == 0)
        return NULL;
    if (count == 1)
        return correct;
    
    return correct;
    
}


int main()
{
try {
    
    vector<DoublyLinkedList<Record> > phoneBook(26);
    Record tempRecord;
    ifstream read;
    read.open("PhoneBook.txt");
    
    if(!read.is_open())
        throw 1;
    
    
    
    
    cout << "---------------------------------" << endl;
    if (read.is_open())
    {
        while(read >> tempRecord.lastName >> tempRecord.firstName >> tempRecord.UIN >> tempRecord.number)
            insertCurrent(phoneBook, tempRecord);
        read.close();
    }
   
    displayList(phoneBook); // display phonebook in order
    cout << "---------------------------------" << endl;
    
    
    
    
    
    
    
    
    
    
    
    
    Record input;
    cout << "Please give me a last name to search. The first letter must be capitilized." << endl;
    cin >> input.lastName;
    input.lastName[0] = toupper(input.lastName[0]);
    //we want to search through our phonebook for the last name and print out the record if name found.
    
    if((int) input.lastName[0] < 65 )
    {
        throw 3;
    }
    Record *results = searchBook(phoneBook, input);
    
    if(results == NULL)
        throw 2;
    else
    {
        cout << "Found!" << endl << endl;
        cout << *results;
    }
    
    return 0;

}
    catch (int & e)
    {
        if (e == 1)
            cout << "Error opening the file.\n";
        if (e == 2)
            cout << "No matches by the data you entered found in the book.\n";
        if(e == 3)
            cout << "Error you did not enter a valid input. Try again!\n";
    }
}
































