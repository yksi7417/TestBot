#ifndef md5_h
#define md5_h

class Md5Plugin {
    public:
        Md5Plugin(){};
        std::string getResult(const std::string& input) const; 
};

#endif