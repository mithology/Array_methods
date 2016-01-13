typedef struct{
    void *base;
    int typeSize;
    int length;
}ArrayUtil;

typedef int (MatchFunc) (void *, void *);
typedef void (ConvertFunc)(void *, void *, void *);
typedef void (OperationFunc)(void *, void *);

typedef void *(ReducerFunc)(void *, void *, void *);




ArrayUtil create(int ,int);
int areEqual(ArrayUtil, ArrayUtil);
ArrayUtil resize (ArrayUtil, int);
void dispose(ArrayUtil array);
int findIndex(ArrayUtil array, void* element);
void* findFirst(ArrayUtil array , MatchFunc match, void* hint);
void* findLast(ArrayUtil array , MatchFunc match, void* hint);
int count(ArrayUtil array, MatchFunc* match, void* hint);
void map(ArrayUtil source, ArrayUtil destination, ConvertFunc* convert, void* hint);
void forEach(ArrayUtil array, OperationFunc* operation, void* hint);
int filter(ArrayUtil array, MatchFunc* match, void* hint, void** destination, int maxItems );
void* reduce(ArrayUtil array, ReducerFunc* reducer, void* hint, void* initialValue);
