#include <iostream>
using namespace std;



class subvector {
public:
    subvector();
    bool push_back(int d);
    int pop_back();
    bool resize(unsigned int new_capacity);
    void shrink_to_fit();
    void clear();
    void destructor();
    ~subvector();


private:
    int* mas;
    unsigned int top;
    unsigned int capacity;
};

subvector::subvector() {
    this->capacity = 10;
    this->top = 0;
    this->mas = new int[this->capacity];

};

bool subvector::push_back(int d)
{
    if (this->top + 1 > this->capacity)
    {
        int* p = new int[this->capacity + 1];
        for (int i = 0; i < this->capacity; i++)
            p[i] = this->mas[i];

        if (this->capacity > 0)
            delete[] this->mas;


        this->capacity++;
        this->mas = p;
        this->mas[this->top] = d;
        this->top++;
    }
    else
    {
        this->mas[this->top] = d;
        this->top++;
    }
    return true;
}

int subvector::pop_back()
{
    if (this->top > 0)
    {
        this->top--;
        int d = this->mas[this->top];
        return d;
    }
    else return 0;
}

bool subvector::resize(unsigned int new_capacity) {
    if (new_capacity <= this->capacity) {
        return 0;
    }
    unsigned int *s = &(this->capacity);
    int last = *s;
    *s = new_capacity;
    int *p = new int[*s];
    int i = 0;
    while (i < last) {
        p[i] = this->mas[i];
        i++;
    }
    delete[] this->mas;
    this->mas = p;
    return 1;
}

void subvector::shrink_to_fit(){
    int *b = new int[this->top];
    for(int i = 0; i < this->top; i++){
        b[i] = this->mas[i];
    }
    delete[] this->mas;
    this->mas = b;
    this->capacity = this->top;
}
subvector::~subvector(){
    delete[] this->mas;
    this->mas = nullptr;
    this->top = 0;
    this->capacity = 0;
}

void subvector::clear()
{
    this->top = 0;
}
/*
int main()
{
    subvector new_sub;
    int i;
    for(i = 0; i <= 5; i++)
    {
        new_sub.push_back(i);
    }
    cout << new_sub.pop_back() <<  endl;

}
*/
