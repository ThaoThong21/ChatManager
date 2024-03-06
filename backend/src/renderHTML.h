#include <fstream>
class Render{
public:
    static std::string htmlContent(std::string path){
        std::ifstream html_file(path);
        if(html_file.is_open())
        {
            std::string html_content((std::istreambuf_iterator<char>(html_file)),
                                        std::istreambuf_iterator<char>());
            return html_content;
        }
        std::string html_error= "error";
        return html_error;
    }
};