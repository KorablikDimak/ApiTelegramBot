#ifndef Telebot_PassportData_H
#define Telebot_PassportData_H

#include <Telebot/Types/EncryptedPassportElement.h>
#include <Telebot/Types/EncryptedCredentials.h>

namespace Telebot
{
    class PassportData
    {
    public:
        typedef std::shared_ptr<PassportData> Ptr;

        std::vector<EncryptedPassportElement::Ptr> data;
        EncryptedCredentials::Ptr credentials;
    };

    inline void from_json(const Json::Json& json, PassportData& object) noexcept
    {
        OBJECTS_FROM_JSON(data)
        OBJECT_FROM_JSON(credentials)
    }
}

#endif