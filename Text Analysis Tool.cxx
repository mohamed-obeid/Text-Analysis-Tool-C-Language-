#include <stdio.h>
#include <ctype.h>

int main() {
    char text[1000];
    int  i, words, characters, lines ;
    i=words=characters=lines=0;
    int inWord = 0; //Flag to track if the program is currently scanning inside a word

    printf("Please enter your text (type 'END' to finish):\n");

    // Continuous loop to read input line by line from the user  
    while (fgets(text, sizeof(text), stdin)) {
        //Check for the termination string "END" to exit the input loop
        if (text[0] == 'E' && text[1] == 'N' && text[2] == 'D') break;

        lines++; //Increment line counter for each successful input line

        for (i = 0; text[i] != '\0'; i++) {
            //1.Iterate through each character in the current line
            if (text[i] != '\n' && text[i] != '\r') {
                characters++;
            }

          //2.Intelligent word counting logic
            if (isspace(text[i])) { 
                inWord = 0; //If a space is encountered, we are no longer inside a word
            } else if (inWord == 0) {
                inWord = 1; // If a non-space character is found and we were previously outside a word, it marks the beginning of a new word.
                words++;
            }
        }
    }

    // Display the final analysis results
    printf("\n--- Analysis Results ---\n");
    printf("Words: %d\n", words);
    printf("Characters: %d\n", characters);
    printf("Lines: %d\n", lines);

    return 0;
}
