#include <iostream>  
using namespace std;  
  
//Describing the size of the character.  
#define CHAR_SIZE 128  
  
//Here is a class that can be used to store a Trie node.  
class Trie  
{  
public:  
    bool isLeaf;  
    Trie* character[CHAR_SIZE];  
     Trie()  
    {  
        this->isLeaf = false;  
         for (int k = 0; k< CHAR_SIZE; k++) {  
            this->character[k] = NULL;  
        }  
    }  
    void insert(string);  
    bool search(string);  
    bool haveChildren(Trie const*);  
bool deletion(Trie*&, string);  
};  
  
//Here is an iterative function for inserting a key in a Trie.  
void Trie::insert(string key)  
{  
    //Beginning from the root node.  
    Trie* curr = this;  
    for (int k = 0; k< key.length(); k++)  
    {  
        //If the path does not exist, a new node will be created.  
        if (curr->character[key[k]] == NULL) {  
            curr->character[key[k]] = new Trie();  
        }  
         //Moving to the next node.  
        curr = curr->character[key[k]];  
    }  
    //Current node is marked as a leaf.  
    curr->isLeaf = true;  
}  
  
bool Trie::search(string key)  
{  
    //If the Trie is empty, then return false.  
    if (this == NULL) {  
        return false;  
    }  
     Trie* curr = this;  
    for (int k = 0; k< key.length(); k++)  
    {  
        curr = curr->character[key[k]];  
         if (curr == NULL) {  
            return false;  
        }  
    }  
    return curr->isLeaf;  
}  
 //Determines whether or not a specified node has any child nodes.  
bool Trie::haveChildren(Trie const* curr)  
{  
    for (int k = 0; k< CHAR_SIZE; k++)  
    {  
        if (curr->character[k]) {  
            return true;    //A child has beenfound.  
        }  
    }  
     return false;  
}  
 //Here is a recursive function that can be used to delete a key from a Trie.  
bool Trie::deletion(Trie*& curr, string key)  
{  
    //If the Trie is empty, then return false.  
    if (curr == NULL) {  
        return false;  
    }  
     if (key.length())  
    {  
         if (curr != NULL &&  
            curr->character[key[0]] != NULL &&  
            deletion(curr->character[key[0]], key.substr(1)) &&  
            curr->isLeaf == false)  
        {  
            if (!haveChildren(curr))  
            {  
                delete curr;  
                curr = NULL;  
                return true;  
            }  
            else {  
                return false;  
            }  
        }  
    }  
     //If the end of the key has been reached.  
    if (key.length() == 0 && curr->isLeaf)  
    {  
        if (!haveChildren(curr))  
        {  
            //Delete the current node.  
            delete curr;  
            curr = NULL;  
             //Delete the parent nodes that are not at the leaf level.  
            return true;  
        }  
         else {  
            curr->isLeaf = false;  
             return false;  
        }  
    }  
     return false;  
}  
 //Trie data structure C++ implementation  
int main()  
{  
    Trie* head = new Trie();  
    head->insert("java");  
    cout << head->search("java") << " ";      //Returns 1 (If found)  
    head->insert("javatpoint");  
    cout << head->search("javatpoint") << " "; //Returns1  
    cout << head->search("javaa") << " ";      //Returns0 (If not found)  
    head->insert("javac");  
    cout << head->search("javac") << " ";       //Returns1  
    head->insert("j");  
    cout << head->search("j");                 //Returns1  
  
    cout << endl;  
    head->deletion(head, "java");  
    cout << head->search("java") << " ";      //Returns0  
    cout << head->search("javatpoint") << " "; //Returns1  
    cout << head->search("javac");              //Returns1  
    cout << endl;  
    head->deletion(head, "j");  
    cout << head->search("j") << " ";          //Returns0  
    cout << head->search("javac") << " ";       //Returns1  
    cout << head->search("javatpoint");        //Returns1  
    cout << endl;  
    head->deletion(head, "javatpoint");  
    cout << head->search("javatpoint") << " "; //Returns0  
    cout << head->search("javac") << " ";       //Returns1  
    head->deletion(head, "javac");  
    cout << head->search("javac");              //Returns0  
    cout << endl;  
    if (head == NULL) {  
        cout << "Empty!!\n";              //Trie is empty now  
    }  
    cout << head->search("javac");              //Returns0  
    return 0;  
}  
