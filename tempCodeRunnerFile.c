    for(i = 0; namesList[i] != '\0'; i++){

        if(namesList[i] == ','){
            if(target[subIndex] == '\0'){
                firstIndex = firstLetter;
                lastIndex = i;
                printf("\n%c %c", namesList[firstIndex], namesList[lastIndex]);
                break;
            }else{
                firstLetter = i + 1;
                subIndex = 0;
            }
            continue;
        }
        
        if(namesList[i] == target[subIndex]){
            subIndex++;
            continue;
        }

        subIndex = 0;


    }