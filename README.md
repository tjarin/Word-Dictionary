# BST Dictionary in C++

This project implements a **Binary Search Tree (BST)** based dictionary in C++. The dictionary supports various operations, including searching, adding, deleting, displaying, finding synonyms, and suggesting similar words. All the words and their meanings are stored in a BST, ensuring efficient operations.

---

## Features

### 1. **Add New Word**
- Allows the user to insert a new word and its meaning into the dictionary.
- Automatically arranges words alphabetically using the Binary Search Tree.

### 2. **Search Word**
- Enables the user to search for the meaning of a word.
- Returns a message if the word is not found.

### 3. **Delete Word**
- Deletes a specified word from the dictionary, maintaining the BST structure.

### 4. **Display All Words**
- Performs an in-order traversal of the BST to display all words in alphabetical order along with their meanings.

### 5. **Find Synonyms**
- Searches for words in the dictionary that have the same meaning as a given word.

### 6. **Word Suggestions**
- Suggests words starting with the same letter as the given input when a search fails.

### 7. **Store in File**
- Saves the entire dictionary (word-meaning pairs) to a text file called `dictionary.txt` when the program starts.

### 8. **User-Friendly Menu**
- A menu-based interface allows users to perform different operations easily.

---

## Code Structure

### **Functions**
1. **`createNode`**: Creates a new node for the BST.
2. **`checkWord`**: Compares two words character by character to determine their order.
3. **`insertNode`**: Inserts a word and its meaning into the BST.
4. **`searchNode`**: Searches for a word in the BST and returns its meaning.
5. **`findWordsWithSimilarMeaning`**: Finds words with the same meaning as a target word.
6. **`deleteWord`**: Deletes a word from the BST.
7. **`suggestWords`**: Suggests words starting with the same letter as the given word.
8. **`inorderTraversal`**: Traverses the BST in-order and prints all words and their meanings.
9. **`StoreInFile`**: Stores the BST dictionary in a text file.

---

## How to Use

### **Compilation**
1. Save the code in a file named `BSTDictionary.cpp`.
2. Compile the code using a C++ compiler, such as:
   ```bash
   g++ -o BSTDictionary BSTDictionary.cpp
   ```

### **Run the Program**
```bash
./BSTDictionary
```

### **Menu Options**
- **1. Search word**: Enter a word to find its meaning.
- **2. Add new word**: Add a word and its meaning to the dictionary.
- **3. Delete word**: Delete a word from the dictionary.
- **4. Display all words**: View all words in alphabetical order.
- **5. Find similar words**: Find synonyms (words with the same meaning).
- **6. Suggest words**: Get suggestions for similar words if a search fails.
- **7. Exit**: Exit the program.

---

## Example Usage

### Adding Words:
```text
Enter a word: apple
Enter the meaning: A fruit

Enter a word: apricot
Enter the meaning: Another fruit
```

### Searching for a Word:
```text
Enter a word to search: apple
Meaning of the word apple: A fruit
```

### Finding Synonyms:
```text
Enter a word to find synonyms: apple
Similar word for apple: apricot (Another fruit)
```

### Word Suggestions:
```text
Enter a word to search: ap
Did you mean?:
- apple
- apricot
```

---

## File Storage
- The dictionary is stored in a file called `dictionary.txt` whenever the program starts.
- The format is:
  ```
  word: meaning
  ```

---

## Limitations
- The program does not persist the dictionary across multiple runs. A persistent storage mechanism could be added.
- Word suggestions are limited to words starting with the same first letter.

---

## Future Improvements
- Add functionality to load the dictionary from `dictionary.txt` when the program starts.
- Improve suggestions to handle partial matches.
- Add a GUI for better user interaction.

---

## Author
This project was created as part of a learning exercise for implementing data structures in C++.

---
