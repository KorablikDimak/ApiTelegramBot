#ifndef Telebot_InputFile_H
#define Telebot_InputFile_H

#include <memory>
#include <string>

namespace Telebot
{
    class InputFile
    {
    public:
        typedef std::shared_ptr<InputFile> Ptr;

        std::string Data;
        std::string MimeType;
        std::string FileName;

        static InputFile::Ptr FromFile(const std::string& filePath, const std::string& mimeType);
    };
}

#endif