
    struct ffi_cif;
    typedef struct ffi_cif ffi_cif;
    void ffi_call(ffi_cif *cif, void (*fn)(void), void *rvalue, void **avalue);
    int main() { ffi_call(0, 0, 0, 0); }
