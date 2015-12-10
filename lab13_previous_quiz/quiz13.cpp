// Quiz 13: sets and hash tables
// Spring 2014
//given:
class Set {
    
private:
    bool array[26];
    int map(char);
public:
    Set();
 	void insert(char);
    bool find(char);
    
    bool isEmpty();
    Set union(Set);
};

// solution below
bool Set::isEmpty() {
    for (int i=0; i<26; i++)
        if (array[i])
            return false;
    return true;
}
Set Set::Union(Set other) {
    Set newSet;
    for (int i=0; i<26; i++)
        if (array[i])
            newSet.array[i] = true;
    for (int i=0; i<26; i++)
        if (other.array[i])
            newSet.array[i] = true;
    return newSet;
}