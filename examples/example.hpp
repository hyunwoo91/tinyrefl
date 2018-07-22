#ifndef TINYREFL_EXAMPLE_HPP
#define TINYREFL_EXAMPLE_HPP

#include <string>

namespace example
{

struct A
{
    int a = 42;
};


struct B
{
    const char* b = "hello";
};

enum class Enum
{
    A, B, C, D, E = 42
};

struct C : public A, public B
{
public:
    [[tinyrefl::ignore]] std::string ignore_me;
    std::string hey_im_here = "hey, I'm here";
    B subobject;

    enum class Enum
    {
        A, B, C, D, E, F, G
    };

    Enum e = Enum::A;
};

std::ostream& operator<<(std::ostream& os, const B& b);
std::ostream& operator<<(std::ostream& os, const Enum& value);
std::ostream& operator<<(std::ostream& os, const C::Enum& value);

}

#endif // TINYREFL_EXAMPLE_HPP
