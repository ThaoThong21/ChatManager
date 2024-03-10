#include <httplib.h>
#include <iostream>
#include "renderHTML.h"
#include "my_handle.h"
int main() {
    httplib::Server server;
    std::cout<<"HELLO start"<<std::endl;
    server.Post("/login", [&](const httplib::Request& req, httplib::Response& res){
        my_handle::handle_login(req, res);
    });
    server.Get("/chatboard", [&](const httplib::Request& req, httplib::Response& res){
        my_handle::handle_chatboard(req, res);
    });
    server.Get("/errorpage", [](const httplib::Request& req, httplib::Response& res) {
        my_handle::handle_errorpage(req, res);
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
