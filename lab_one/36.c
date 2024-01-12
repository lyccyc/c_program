int main() {
    init();

    void *p = &block;
    int *iptr = (int*) p;
    char *cptr = (char*) (iptr + 1);  
    float *fptr = (float*) (cptr + 1);  
    
    printf("%d, %c, %f", *iptr, *cptr, *fptr);
    return 0;
}

