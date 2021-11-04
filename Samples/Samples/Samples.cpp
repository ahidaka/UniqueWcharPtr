#include <Windows.h>
#include <memory> // std::unique_ptr
#include <array>
#include <iostream>

#define NUM_SUB (50)

int Sub(std::array<std::unique_ptr<WCHAR[]>, NUM_SUB> &Subs)
{
    PWSTR pw;

    for (size_t i = 0; i < NUM_SUB; i++) {
        Subs[i] = std::unique_ptr<WCHAR[]>(new WCHAR[MAX_PATH]);
        pw = (PWSTR)Subs[i].get();
        _ultow_s(i, pw, MAX_PATH, 10);
    }

    return NUM_SUB;
}

int main()
{
    std::cout << "Allocate many WCHAR buffers with unique_ptr!\n";
    std::array<std::unique_ptr<WCHAR[]>, NUM_SUB> subs{};

    Sub(subs);
    for (auto& e : subs) {
        //std::cout << e << std::endl;
        printf("<%ws>\n", e.get());
    }
}
