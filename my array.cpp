#include <iostream>

using namespace std;

// Wrapper Classes
class MyArray
{
private:
    int *ar;
    int CAPACITY;
    int length;

public:
    MyArray(int capacity=0) 
    {
    	CAPACITY=capacity;
        length = 0;
        ar = new int[CAPACITY];

        for (int i = 0; i < CAPACITY; i++)
        {
            ar[i] = -9999;
            length++;
        }
    }

    int getLength()
    {
        return length;
    }

    int getCapacity()
    {
        return CAPACITY;
    }

    bool isFull()
    {

        if (length == getCapacity())
            return true;

        return false;
    }
	   bool isEmpty()
    {

        if (length == 0)
            return true;

        return false;
    }

    // Delegates
    bool add(int x)
    {
        return insertAtLast(x);
    }

    bool insertAtLast(int x)
    {
        if (!isFull())
        {
            ar[length] = x;
            length++;
            return true;
        }

        return false;
    }
};
int main()
{
	MyArray ma();

	cout<<ma.isEmpty();
}
