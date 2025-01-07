#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <vector>

using namespace std;


struct Node
{
    string key;
    string meaning;
    Node* left;
    Node* right;
};
Node* root = nullptr;
/* This function creates a new node if the tree is empty
*/

Node* createNode(string key, string meaning)
{
    Node* newNode = new Node();
    newNode->key = key;
    newNode->meaning = meaning;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}
/*
*This function is created to check whetrher the new word should placed righr or left of it's root word
*IT checks character by character
*If 1st alphabet of both the words are same it checks 2nd alphabet and it continues until it reaches '/0'

*/
int checkWord(char a[],char b[])
{
    int i,j;
    int match=1;
    for(i=0,j=0 ; a[i]!='\0'&&b[j]!='\0' ; i++,j++)
    {
        if(a[i]>b[j])
        {
            match=0;
            break;
        }
        else if(b[j]>a[i])
        {
            match=-1;
            break;
        }
        else
            continue;
    }
    if(match==0)
        return 1;
    else if(match==-1)
        return -1;
    else
        return 0;
}
/*
* This function is created to insert word and it's meaning whenever a user chooses to add word
* This function, with the help of checkWord function determines whether a word is should place righr or left and then insert the word into
BST dictionary according it.
*/
Node* insertNode(Node* root, string key, string meaning)
{
    if (root == nullptr)
        return createNode(key, meaning);
    char word[key.size() + 1];
    strcpy(word, key.c_str());
    char Rootword[root->key.size() + 1];
    strcpy(Rootword, root->key.c_str());

    if (checkWord(Rootword,word)<0)
        root->right = insertNode(root->right, key, meaning);

    else if (checkWord(Rootword,word)==0)
        cout<<"The word is already Inserted";
    else
        root->left = insertNode(root->left, key, meaning);
    return root;

}

/* This function is used for storing the BST dictionary in a text file
*/


void StoreInFile(Node* root, ofstream& outFile)
{
    if (root == nullptr)
        return;

    StoreInFile(root->left, outFile);
    outFile << root->key << ": " << root->meaning << "\n";
    StoreInFile(root->right, outFile);
}
/*
This function is used for inorder traverse the BST dictionary which will be helpful for display the BST
*/

void inorderTraversal(Node* root)
{
    if (root == nullptr)
    {
        return;
    }
    inorderTraversal(root->left);
    cout << root->key << ": " << root->meaning << endl;
    inorderTraversal(root->right);
}
/*
*This function is used for displaying the inserted word
*We have used it mainly to show the words are inserting according to our requirements

*/
void display(Node* root)
{
    inorderTraversal(root);
}
/*
* This function is used for finding similar meaning words from a given word
* This function searches for which meaning  of the BST dictionary matches with the meaning of the given word
* If it found any meaning which matches with the target meaning it prints the word as synonym
*/
void findWordsWithSimilarMeaning(Node* root,string Find, string targetMeaning)
{
    if (!root)
    {
        return;
    }

    if (root->meaning == targetMeaning)
    {
        if(root->key == Find)
        {


        }
        else
            cout <<"Similar word for "<<Find<<" :  "<< root->key << " (" << root->meaning << ")\n";
    }

    findWordsWithSimilarMeaning(root->left,Find, targetMeaning);
    findWordsWithSimilarMeaning(root->right,Find, targetMeaning);
}

/*
This function is used for searching a given word from the dictionary
*/
string searchNode(Node* root, string key)
{
    Node* ptr = root;
    int found=0;

    char word[key.size() + 1];
    strcpy(word, key.c_str());
    char Rootword[ptr->key.size() + 1];
    strcpy(Rootword, ptr->key.c_str());
    string str1;
    string str2;
    str2="Not Found";

    while(ptr!=NULL)
    {
        if (checkWord(Rootword,word)<0)
            searchNode(ptr->right, key);

        else if (checkWord(Rootword,word)==0)
        {
            found=1;
            break;

        }
        else
            searchNode(ptr->left, key);


    }
    if (found=1)
    {
        str1=ptr->meaning;

        return str1;
    }

    else
    {
        cout<<str2<<endl;
        return str2;
    }

}



Node* findMin(Node* root)
{
    while (root->left)
    {
        root = root->left;
    }
    return root;
}

/*
This function is used for deleting a given word from the BST dictionary

*/
Node* deleteWord(Node* root, std::string key)
{
    if (!root)
    {
        return root;
    }
    if (key < root->key)
    {
        root->left = deleteWord(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = deleteWord(root->right, key);
    }
    else
    {
        if (!root->left)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->key = temp->key;
        root->right = deleteWord(root->right, temp->key);
    }
    return root;
}
/*
* This function is used for giving word suggestions whenever the user is unable to search for appropiate word
*/

void suggestWords(Node* root, const string& targetWord, vector<string>& suggestions) {
    if (!root) {
        return;
    }

    suggestWords(root->left, targetWord, suggestions);

    if (root->key[0] == targetWord[0]) {
        suggestions.push_back(root->key);
    }

    suggestWords(root->right, targetWord, suggestions);
}

/*
*This is the  main function of the code.
* It  displays a menu for the user to choose various actions.
* It allows the user to search, add new words , delete words, display words , Find Similar words as well as search for word word suggestions.
*It continues until the user chooses to exit.
*/


int main()
{
    ofstream outFile("dictionary.txt");

    if (!outFile.is_open())
    {
        cout << "Error opening file." << endl;
        return 1;
    }

    StoreInFile(root, outFile);

    outFile.close();

    int choice;


    while (true)
    {

        cout << "Menu:\n";
        cout << "1. Search word\n";
        cout << "2. Add new word\n";
        cout << "3. Delete word\n";
        cout << "4. Display all words\n";
        cout << "5. Find similar words\n";
        cout << "6. Suggest  words\n";
        cout << "7. Exit\n";
        cin >> choice;
        cin.ignore(); // Clear newline from the input buffer
        switch (choice)
        {
        case 1:
        {
            string key;
            cout<<"Enter a word to  Search"<<endl;
            getline(cin,key);
            cout<< "Meaning of the word " <<key<<" "<<searchNode(root,key)<<endl;
            break;
        }
        case 2:
        {

            while (true)
            {

                string word, meaning;

                cout << "Enter a word (or 'q' to quit): ";
                getline(cin, word);

                if (word == "q")
                {
                    break;
                }

                cout << "Enter the meaning: ";
                getline(cin, meaning);

                root = insertNode(root, word, meaning);

            }
            break;
        }
        case 3:
        {
            string key;
            cout<<"Enter a word to  delete"<<endl;
            getline(cin,key);
            deleteWord(root,key);

        }

        case 4:
        {
            display(root);
            break;
        }
        case 5:
        {
            string Find;
            cout<<"Enter a word to find Synonym  :  ";
            getline(cin,Find);
            string target= searchNode(root,Find);
            findWordsWithSimilarMeaning(root,Find,target);
            break;
        }
        case 6:
        {
            string key;
            cout << "Enter a word to search: ";
            getline(cin, key);

            vector<string> suggestions;
            suggestWords(root, key, suggestions);

            if (!suggestions.empty())
            {
                cout << "\nDid you mean ?:\n";
                for (const string& suggestion : suggestions)
                {
                    cout << "- " << suggestion << endl;
                }
            }
            break;

        }
        case 7:
        {
            cout << "Exiting the program.\n";
            return 0; // Exit the program
        }
        default:
        {
            cout << "Invalid choice.\n";
            break;
        }


        }



    }



    return 0;

}
