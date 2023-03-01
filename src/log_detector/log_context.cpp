#include <Poco/File.h>
#include <Poco/SharedMemory.h>
#include <Poco/Exception.h>
#include "log_detector/log_context.h"
 
class LogContext::Impl {
public:
    Impl(const char* filename_) : filename(filename_) {}

// member remain public - this is an inner class that's not exposed. 
    const char* filename; 
    std::unique_ptr<Poco::File> file; 
    std::unique_ptr<Poco::SharedMemory> sharedMeomry; 
    
};

LogContext::LogContext(const char* filename_)  {
    impl = std::make_unique<Impl>(filename_);
}

void LogContext::loadFile() {
        impl->file = std::make_unique<Poco::File>(impl->filename);
        if (!impl->file->exists() || !impl->file->isFile())
            throw new Poco::FileNotFoundException(); // consider async event / retry when file is ready?? 

        Poco::SharedMemory sm(*(impl->file), Poco::SharedMemory::AM_READ);
        // impl->sharedMeomry = std::make_unique<Poco::SharedMemoryImpl>(*(impl->file), Poco::SharedMemory::AM_READ);
}