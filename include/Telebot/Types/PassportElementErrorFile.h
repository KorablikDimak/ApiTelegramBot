#ifndef Telebot_PassportElementErrorFile_H
#define Telebot_PassportElementErrorFile_H

#include <Telebot/Types/PassportElementError.h>

namespace Telebot
{
    class PassportElementErrorFile final : public PassportElementError
    {
    public:
        typedef std::shared_ptr<PassportElementErrorFile> Ptr;

        static const std::string SOURCE;

        PassportElementErrorFile()
        {
            Source = SOURCE;
        }

        std::string FileHash;
    };
}

#endif