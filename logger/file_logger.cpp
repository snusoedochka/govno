#include "file_logger.h"
void file_logger::clear() {
    std::fstream clear_file(filename_, std::ios::out);
    clear_file.close();
}
void file_logger::print(std::string message)
{

    if(file.is_open()){
        for(int i=0; i<1000;i++){
        /*std::cout <<*/ file.get();
            file << message;}
        std::cout<< message;
    }else{
        std::cout << "again";}

}

file_logger::file_logger(std::string filename)
{
    std::fstream clear_file(filename_, std::ios::out);
    clear_file.close();
    filename_ = filename;
    file.open(filename_, std::ios_base::app);
}

file_logger::~file_logger()
{
    file.close();
}