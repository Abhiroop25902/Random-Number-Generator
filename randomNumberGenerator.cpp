#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
using namespace std;

class notEnoughParameterException : public exception
{
public:
    virtual const char *what() const throw()
    {
        return "Error: Provide a limit to Option!!";
    }
};

class argument1Exception : public exception
{
public:
    virtual const char *what() const throw()
    {
        return "Argument can't be 1";
    }
};

int randomOption(int n)
{
    vector<int> count(n, 0);
    int maxidx = 0;

    srand(time(0));

    const int NUM_TIMES = 97; //big enough prime
    int num;

    for (int i = 1; i <= NUM_TIMES; i++)
    {
        num = rand() % n;
        count[num]++;

        if (count[num] > count[maxidx])
            maxidx = num;
    }

    return maxidx + 1;
}

int main(int argc, char **argv)
{
    try
    {
        if (argc != 2)
            throw notEnoughParameterException();

        if (atoi(argv[1]) == 1)
            throw argument1Exception();

        cout << "Select Option " << randomOption(atoi(argv[1])) << " !!!" << endl;
    }
    catch (notEnoughParameterException &e)
    {
        cout << e.what() << endl;
    }
    catch (argument1Exception &e)
    {
        cout << e.what() << endl;
    }

    return 0;
}