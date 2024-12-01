// Book ADT which represents a book as a tree of pages, sorted by pageNumber
// Pages are represented as a tree of words, sorted by position

// Imagine book of multiple pages.
// Pages consist of number of words, and instances
// Create a bst to represent a book
// So that we can sort pages by page number, number of words in page, number of certain instance
// Make a CTRL+F function

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book {
    // char *title;
    // char *author;
    // int date;

    int numPages;
    struct page *pages;
};

struct page {
    int pageNumber;
    // bool isChapter;

    int numWords;
    struct word *words;
    struct page *left;
    struct page *right;
};

struct word {
    char *word;
    int position;
    struct word *left;
    struct word *right;
};

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

struct book *createBook();
void insertPage(struct book *b, int pageNumber, char *words, int wordsSize);
struct page *insertPageRec(struct page *root, struct page *new);
struct page *createPage(int pageNumber, char **words, int wordsSize);
struct word *createWord(char *word);
void insertWord(struct page *p, struct word *w);

////////////////////////////////////////////////////////////////////////////////
// Function Implementations

// Function to create a new book with no pages
struct book *createBook() {
    struct book *newBook = malloc(sizeof(struct book));

    newBook->numPages = 0;
    newBook->pages = NULL;

    return newBook;
}

// Function to insert a new page into a book
void insertPage(struct book *b, int pageNumber, char *words, int wordsSize) {
    struct page *newPage = createPage(pageNumber, words, wordsSize);

    struct page *root = b->pages;

    b->pages = insertPageRec(root, newPage);
}

// Helper function to insert a page into a book recursively
struct page *insertPageRec(struct page *root, struct page *new) {
    if (root == NULL) {
        return new;
    }

    if (root->pageNumber < new->pageNumber) {
        root->right = insertPageRec(root->right, new);
    } else if (root->pageNumber > new->pageNumber) {
        root->left = insertPageRec(root->left, new);
    } else {
        fprintf(stderr, "ERROR: Pages cannot have the same page number.\n");
        exit(EXIT_FAILURE);
    }

    return root;
}

// Helper function to create a new page
struct page *createPage(int pageNumber, char **words, int wordsSize) {
    struct page *newPage = malloc(sizeof(struct page));

    newPage->pageNumber = pageNumber;
    newPage->numWords = wordsSize;
    newPage->left = NULL;
    newPage->right = NULL;

    for (int i = 0; i < wordsSize; ++i) {
        struct word *newWord = createWord(words[i]);
        newWord->position = i;
        insertWord(newPage, newWord);
    }

    return newPage;
}

// Helper function to create a new word
struct word *createWord(char *word) {
    struct word *newWord = malloc(sizeof(struct word));

    newWord->word = malloc(sizeof(char) * strlen(word) + 1); // TODO remove +1
    strcpy(word, newWord->word);

    newWord->position = -1;
    newWord->left = NULL;
    newWord->right = NULL;

    return newWord;
}

// Function to store/insert a word in a page
void insertWord(struct page *p, struct word *w) {

}

// Function to print the entire book, in sequential order
void printBook(struct book *b) {
    printf("printBook: not implemented yet\n");
}

// Function to print a given page in a book, in sequential order
void printPage(struct book *b, int pageNumber) {
    printf("printPage: not implemented yet\n");
}
