char* decodeString(char* s) {
    char* stack = ( char * ) malloc( 2000 );
    int top = -1;

    for ( int i = 0; s[i] != '\0'; i++ ){
        if ( s[i] != ']' ){ // pusha no stack até achar ']'
            stack[++top] = s[i];
            continue;
        }

        char temp[110];
        int tempTop = -1;
        while( stack[top] != '[' ){ // pusha no temp até achar '['
            temp[++tempTop] = stack[top--];
        }
        stack[top--];

        int num = 0, k = 1;

        while( top >= 0 && isdigit(stack[top])){ // pega o numero (xyz = z*1 + y*10 + x*100)
            num += (stack[top--] - '0') * k;
            k *= 10;
        }


        for(; num > 0; num-- ){ // pusha no stack o temp num vezes
            for(int j = tempTop; j > -1; j--){
                stack[++top] = temp[j];
            }
        }


    }
    stack[++top] = '\0';
    return stack;
}