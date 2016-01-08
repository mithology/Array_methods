typedef struct{
    void *base;
    int typeSize;
    int length;
}ArrayUtil;
typedef int (MatchFunc) (void *, void *);

ArrayUtil create(int ,int);
int areEqual(ArrayUtil, ArrayUtil);
ArrayUtil resize (ArrayUtil, int);
void dispose(ArrayUtil array);
int findIndex(ArrayUtil array, void* element);
void* findFirst(ArrayUtil array , MatchFunc match, void* hint);
