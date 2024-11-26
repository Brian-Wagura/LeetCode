#include <stdio.h>
#include <string.h>
#include <ctype.h>

char shift_char(char ch, int shift) {
    if (isalpha(ch)) {
        char base = islower(ch) ? 'a' : 'A';
        return (ch - base - shift + 26) % 26 + base;  // Reverse shift with wrap-around
    }
    return ch;  // Non-alphabetic characters remain unchanged
}

// Function to apply the shift to the entire ciphertext
void apply_shift(char result[], char ciphertext[], int shift) {
    int len = strlen(ciphertext);
    for (int i = 0; i < len; i++) {
        result[i] = shift_char(ciphertext[i], shift);
    }
    result[len] = '\0';
}

// Function to check if a word exists in a string
int contains_word(char text[], char word[]) {
    return strstr(text, word) != NULL;
}

// The decipher function
char *decipher(char ciphertext[], char knownWord[]) {
    static char deciphered[1000];
    int shift;

    // Try all shifts from 0 to 25
    for (shift = 0; shift < 26; shift++) {
        // Apply the current shift
        apply_shift(deciphered, ciphertext, shift);
        
        // Check if the known word appears in the deciphered text
        if (contains_word(deciphered, knownWord)) {
            return deciphered;
        }
    }
    
    // If no valid shift found, return "Invalid"
    return "Invalid";
}

int main() {
    char ciphertext[1000];
    char knownWord[1000];
    char decipheredString[1000];
    char * result = decipheredString;
    
    // Input the ciphertext
    scanf("%[^\n]%*c", ciphertext);
    // Input the knownWord
    scanf("%s", knownWord);

    // Call the decipher function
    result = decipher(ciphertext, knownWord);

    printf("%s\n", result);
    
    return 0;
}
