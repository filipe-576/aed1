int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int hIndex(int* citations, int citationsSize) {

    if( citationsSize == 1 ) return citations[0] > 0;

    int h;
    int nCit;

    qsort(citations, citationsSize, sizeof(int), compare);
    for( h = 0; h <= citationsSize; h++ ){
        nCit = 0;
        for( int i = 0; i < citationsSize; i++ ){
            if( citations[i] >= h ){
                nCit++;
            } 
        }

        if( nCit < h ){
            return h - 1;
        }
    }

    return h - 1;
}