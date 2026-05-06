template <typename type> class myVector{
    private:
        long long int size;
        long long int capacity;
        void prResize(); // set capacity = 2 * size and resize array and 
    public:
        type* elements;
        myVector(long long int n = 0); // base constructor with size or stardant size = 0
        myVector(long long int n, type x); // overload constructor with size and standart element
        ~myVector(); // destructor: deleting pointer for array
        void resize(long long int n = 0); // the same as base constructor
        void resize(long long int n, type x); // the same as overload constructor
        long long int getSize(); // return size
        long long int getCapacity(); // return capacity
        type* begin(); //pointer for 1st element
        type* end(); //pointer for last + 1 element
        void push_back(type x); // add new element to end
        void pop_back(); // delete element from end
        void push_front(type x); // add new element to begin
        void pop_front(); // delete element from begin
        void insert(type x, long long int pos); // insert element on position pos
        void erase(long long int pos, long long int count = 1); // erase count elements from position pos
        long long int find(type x); // find element in array or return -1
        long long int find(type x, long long int st, long long int fin); // overloading find with start and finish
        long long int count(type x);  // count how many elemnets array contains
        long long int count(type x, long long int st, long long int fin); // overloading find with start and finish
};
template <typename type> myVector<type>::myVector(long long int n){
    elements = new type[n]; // allocate memory
    size = n;
    capacity = n;
}
template <typename type> myVector<type>::myVector(long long int n, type x){
    elements = new type[n]; // allocate memory
    for (int i = 0; i < n; i++){
        elements[i] = x;
    }
    size = n;
    capacity = n;
}
template <typename type> myVector<type>::~myVector(){
    delete [] elements; // free memory
}
template <typename type> void myVector<type>::prResize(){
    type* xelements = elements; // change variable, that contains pointer for array
    elements = new type[size * 2]; // allocate memory for new array
    for (int i = 0; i < size - 1 ; i++){
        elements[i] = xelements[i];
    }
    delete [] xelements; // free memory of old array
    capacity = 2 * size;
}
template <typename type> long long int myVector<type>::getSize(){
    return size;
}
template <typename type> long long int myVector<type>::getCapacity(){
    return capacity;
}
template <typename type> type* myVector<type>::begin(){
    return elements;
}
template <typename type> type* myVector<type>::end(){
    return elements + size;
}
template <typename type> void myVector<type>::resize(long long int n){
    delete [] elements; // free memory of old array
    elements = new type[n]; // allocate memory for new array
    size = n;
    capacity = n;
}
template <typename type> void myVector<type>::resize(long long int n, type x){
    delete [] elements; // free memory of old array
    elements = new type[n]; // allocate memory for new array
    for (int i = 0; i < n; i++){
        elements[i] = x;
    }
    size = n;
    capacity = n;
}
template <typename type> void myVector<type>::push_back(type x){
    size = size + 1;
    if (size >= capacity){
        prResize(); // resize if array cant save new variable
    }
    elements[size-1] = x;
}
template <typename type> void myVector<type>::pop_back(){
    size -= 1;
    if (size*4 <= capacity){
        prResize(); // resize if capacity >= 4 * size
    }
}
template <typename type> void myVector<type>::push_front(type x){
    size = size + 1;
    if (size >= capacity){
        prResize(); // resize if array cant save new variable
    }
    for (int i = size - 1; i > 0; i--){
        elements[i] = elements[i-1];
    }
    elements[0] = x;
}
template <typename type> void myVector<type>::pop_front(){
    size = size - 1;
    for (int i = 0; i < size; i++){
        elements[i] = elements[i+1];
    }
    if (size*4 <= capacity){
        prResize(); // resize if capacity >= 4 * size
    }
}
template <typename type> void myVector<type>::insert(type x, long long int pos){
    size = size + 1;
    if (size >= capacity){
        prResize(); // resize if array cant save new variable
    }
    for (int i = size - 1; i > pos; i--){
        elements[i] = elements[i-1];
    }
    elements[pos] = x;
}
template <typename type> void myVector<type>::erase(long long int pos, long long int count){
    for (int i = pos; i < pos + count; i++){
        elements[i] = elements[i + count];
    }
    size = size - count;
    if (size*4 <= capacity){
        prResize(); // resize if capacity >= 4 * size
    }
}
template <typename type> long long int myVector<type>::find(type x){
    for (int i = 0; i < size; i++){
        if (x == elements[i]){
            return i;
        }
    }
    return -1;
}
template <typename type> long long int myVector<type>::find(type x, long long int st, long long int fin){
    for (int i = st; i < fin; i++){
        if (x == elements[i]){
            return i;
        }
    }
    return -1;
}
template <typename type> long long int myVector<type>::count(type x){
    long long int count = 0;
    for (int i = 0; i < size; i++){
        if (elements[i] == x){
            count++;
        }
    }
    return count;
}
template <typename type> long long int myVector<type>::count(type x, long long int st, long long int fin){
    long long int count = 0;
    for (int i = st; i < fin; i++){
        if (elements[i] == x){
            count++;
        }
    }
    return count;
}
