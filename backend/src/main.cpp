#include <httplib.h>
#include <iostream>
#include "renderHTML.h"
int main() {
    httplib::Server server;
    std::cout<<"HELLO start"<<std::endl;
    server.Get("/hello", [](const httplib::Request& req, httplib::Response& res) {
        res.set_content("Hello, World!", "text/plain");
    });
    server.Get("/", [](const httplib::Request& req, httplib::Response& res) {
        res.set_header("Content-Type", "text/html");

        res.set_content(Render::htmlContent("../../template/login.html"), "text/html");
    });
    
    if (server.listen("localhost", 9163)) {
        std::cout << "Server is running on http://localhost:9163" << std::endl;
    } else {
        std::cerr << "Failed to start server." << std::endl;
        return 1;
    }

    return 0;
}
