#ifndef Telebot_PassportElementErrorDataField_H
#define Telebot_PassportElementErrorDataField_H

#include <Telebot/Types/PassportElementError.h>

namespace Telebot
{
    class PassportElementErrorDataField final : public PassportElementError
    {
    public:
        typedef std::shared_ptr<PassportElementErrorDataField> Ptr;

        static const std::string SOURCE;

        PassportElementErrorDataField()
        {
            Source = SOURCE;
        }

        std::string FieldName;
        std::string DataHash;
    };
}

#endif