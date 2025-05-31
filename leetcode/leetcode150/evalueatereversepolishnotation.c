bool isInt(char* s){
    if( strlen(s) == 1 && !isdigit(s[0]) ){
        return false;
    }
    
    return true;
}

int evalRPN(char** tokens, int tokensSize) {

    if(tokensSize == 1){
        return atoi(tokens[0]);
    }

    int* stack = ( int* ) malloc( sizeof(int) * tokensSize );
    int top = -1;

    int n1, n2, ans;
    for(int i = 0; i < tokensSize; i++){

        if( isInt(tokens[i]) ){
            stack[++top] = atoi(tokens[i]);
            continue;
        }
        
        n2 = stack[top--];
        n1 = stack[top--];

        // printf(">n1=%d n2=%d ", n1, n2);
        switch( *tokens[i] ){
            case '+':
                ans = n1 + n2;
                break;
            case '-':
                ans = n1 - n2;
                break;
            case '*':
                ans = n1 * n2;
                break;
            case '/':
                ans = n1 / n2;
                break;
        }
        // printf(">ans=%d", ans);
        stack[++top] = ans;
        
    }

    return ans;
}