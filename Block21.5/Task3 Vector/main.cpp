#include <iostream>
#include <math.h>

struct vctr
{
    float abs = 0.0;
    float ord = 0.0;
};

vctr add (vctr frst, vctr scnd)
{
    vctr res;
    res.abs = frst.abs + scnd.abs;
    res.ord = frst.ord + scnd.ord;
    return res;
}

vctr subtrac (vctr frst, vctr scnd)
{
    vctr res;
    res.abs = frst.abs - scnd.abs;
    res.ord = frst.ord - scnd.ord;
    return res;
}

vctr scale (vctr vct, float scl)
{
    vctr res;
    res.abs = vct.abs * scl;
    res.ord = vct.ord * scl;
    return res;
}

float length (vctr vct)
{
    return sqrt(vct.abs * vct.abs + vct.ord * vct.ord);
}

vctr normalize (vctr vct)
{
    vctr res;
    float l = length (vct);
    res.abs = vct.abs / l;
    res.ord = vct.ord / l;
    return res;
}

int main()
{
    std::string command = " ";

    vctr first;
    vctr second;
    vctr result;
    float sclr = 3.0;
    float lgth = 0.0;

    bool correctAnswer = false;

    while (!correctAnswer)
    {
        std::cout << "For adding two vectors enter \'add\'\n";
        std::cout << "For subtracting two vectors enter \'subtract\'\n";
        std::cout << "For multiplying a vector by a scalar enter \'scale\'\n";
        std::cout << "For finding the length of a vector enter \'length\'\n";
        std::cout << "For vector normalization enter \'normalize\'\n";

        std::cin >> command;
        correctAnswer = (command == "add" || command == "subtract"
                         || command == "scale" || command == "length"
                         || command == "normalize");

        if (!correctAnswer)
        {
            std::cout << "Command incorrect. Try agaim\n";
        }
    }

    std::cout << "Enter coordinate of vecor A\n";
    std::cin >> first.abs >> first.ord;

    if (command == "add")
    {
        std::cout << "Enter coordinate of vecor B\n";
        std::cin >> second.abs >> second.ord;
        result = add (first, second);
    }
    else if (command == "subtract")
    {
        std::cout << "Enter coordinate of vecor B\n";
        std::cin >> second.abs >> second.ord;
        result = subtrac (first, second);
    }
    else if (command == "scale")
    {
        std::cout << "Enter sclalar's value\n";
        std::cin >> sclr;
        result = scale (first, sclr);
    }
    else if (command == "length")
    {
        lgth = length (first);
        std::cout << "length of vector A:\n";
        std::cout << lgth << std::endl;
    }
    else
    {
        result = normalize (first);
        lgth = length (result);
        std::cout << "length of norm vector is ";
        std::cout << lgth << std::endl;
    }

    if (command != "length")
    {
       std::cout << "Vector C (" << result.abs << ", " << result.ord << ")" << std::endl;
    }

    return 0;
}
