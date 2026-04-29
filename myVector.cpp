template <typename type> class myVector{
    private:
        long long int size;
        long long int capacity;
        void resize();
    public:
        type* elements;
        myVector(long long int n = 0);
        myVector(long long int n, type x);
        ~myVector();
        void rebuild(long long int n = 0);
        void rebuild(long long int n, type x);
        long long int getSize();
        long long int getCapacity();
        type* begin();
        type* end();
        void push_back(type x);
        void pop_back();
        void push_front(type x);
        void pop_front();
        void insert(type x, long long int pos);
        void erase(long long int pos, long long int count = 1);
        long long int find(type x); //
        long long int find(type x, long long int st, long long int fin); // 
        long long int count(type x); //
        long long int count(type x, long long int st, long long int fin); // 
};
template <typename type> myVector<type>::myVector(long long int n){
    elements = new type[n];
    size = n;
    capacity = n;
}
template <typename type> myVector<type>::myVector(long long int n, type x){
    elements = new type[n];
    for (int i = 0; i < n; i++){
        elements[i] = x;
    }
    size = n;
    capacity = n;
}
template <typename type> myVector<type>::~myVector(){
    delete [] elements;
}
template <typename type> void myVector<type>::resize(){
    type* xelements = elements;
    elements = new type[size * 2];
    for (int i = 0; i < size - 1 ; i++){
        elements[i] = xelements[i];
    }
    delete [] xelements;
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
template <typename type> void myVector<type>::rebuild(long long int n){
    delete [] elements;
    elements = new type[n];
    size = n;
    capacity = n;
}
template <typename type> void myVector<type>::rebuild(long long int n, type x){
    delete [] elements;
    elements = new type[n];
    for (int i = 0; i < n; i++){
        elements[i] = x;
    }
    size = n;
    capacity = n;
}
template <typename type> void myVector<type>::push_back(type x){
    size = size + 1;
    if (size >= capacity){
        resize();
    }
    elements[size-1] = x;
}
template <typename type> void myVector<type>::pop_back(){
    size -= 1;
}
template <typename type> void myVector<type>::push_front(type x){
    size = size + 1;
    if (size >= capacity){
        resize();
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
}
template <typename type> void myVector<type>::insert(type x, long long int pos){
    size = size + 1;
    if (size >= capacity){
        resize();
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
