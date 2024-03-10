#include <httplib.h>
#include <iostream>
#include "my_handle.h"
#include "renderHTML.h"
namespace my_handle {
void handle_login(const httplib::Request& req, httplib::Response& res) {
    std::string username = req.get_param_value("username");
    std::string password = req.get_param_value("password");

    if (username == "admin" && password == "12345678xz") {
        res.set_redirect("/chatboard");
    } else {
        res.set_redirect("/errorpage");
    }
}
void handle_chatboard(const httplib::Request& req, httplib::Response& res){
    res.set_content(Render::htmlContent("../../template/board_chat.html"), "text/html");
}
void handle_errorpage(const httplib::Request& req, httplib::Response& res){
    res.set_content(Render::htmlContent("../../template/error_page.html"), "text/html");
}
} //namespace my_handle

