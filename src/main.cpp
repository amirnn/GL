#include "Application/GLApplication.hpp"

int main(){
    GLApplication app{{640, 480},"Hello There"};
    app.Run();
    return  EXIT_SUCCESS;
}