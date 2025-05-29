char* shortestCompletingWord(char* licensePlate, char** words, int wordsSize) {
    int ascii, j = 0;
    char* plateLetters = licensePlate;

    for ( int i = 0; licensePlate[i] != '\0'; i++ ) {
        ascii = (int) licensePlate[i];

        if ( ascii >= 65 && ascii <= 90 ) {
            ascii += 32;
        } else if ( ascii < 97 || ascii > 122 ) {
            continue;
        }
        ascii = (char) ascii;
        plateLetters[j++] = ascii;
    }
    plateLetters[j] = '\0';

    int plateLettersSize = 0;
    for ( ; plateLetters[plateLettersSize] != '\0'; plateLettersSize++ )
        ;

    int shortestWord, shortestWordSize = 15;
    for ( int i = 0; i < wordsSize; i++ ) {
        char lettersTemp[plateLettersSize + 1];
        strcpy(lettersTemp, plateLetters);

        int lettersCount = 0, j;

        for ( j = 0; j < words[i][j]; j++ ) {
            for ( int k = 0; lettersTemp[k] != '\0'; k++ ) {
                if ( lettersTemp[k] == words[i][j] ) {
                    lettersCount++;
                    // printf("%c : %c |", lettersTemp[k], words[i][j]);
                    lettersTemp[k] = '.';
                    // printf("%s\n", lettersTemp);
                    break;
                }
            }
        }

        // printf("word:%s lettersCount:%d\n", words[i], lettersCount);
        if ( lettersCount == plateLettersSize && j < shortestWordSize ) {
            shortestWord = i;
            shortestWordSize = j;
        }
    }

    return words[shortestWord];
}