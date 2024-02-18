#ifndef Telebot_PassportElementErrorTranslationFile_H
#define Telebot_PassportElementErrorTranslationFile_H

#include <Telebot/Types/PassportElementError.h>

namespace Telebot
{
    class PassportElementErrorTranslationFile final : public PassportElementError
    {
    public:
        typedef std::shared_ptr<PassportElementErrorTranslationFile> Ptr;

        static const std::string SOURCE;

        PassportElementErrorTranslationFile()
        {
            Source = SOURCE;
        }

        std::string FileHash;
    };
}

#endif