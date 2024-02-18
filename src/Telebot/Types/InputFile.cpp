#include <fstream>
#include <sstream>
#include <filesystem>

#include <Telebot/Types/InputFile.h>

std::string Read(const std::string& filePath)
{
    std::ifstream in(filePath, std::ios::in | std::ios::binary);
    in.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    std::ostringstream contents;
    contents << in.rdbuf();
    in.close();
    return contents.str();
}

Telebot::InputFile::Ptr Telebot::InputFile::FromFile(const std::string& filePath, const std::string& mimeType)
{
    auto file = std::make_shared<InputFile>();

    file->Data = Read(filePath);
    const std::filesystem::path path(filePath);
    file->MimeType = mimeType;
    file->FileName = path.filename().string();

    return file;
}