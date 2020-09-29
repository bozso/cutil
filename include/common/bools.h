typedef struct Bools {
    ArrayMeta meta;
    int array[MAX_COMPONENTS];
} Bools;

Bools cm_new_bools(void);
