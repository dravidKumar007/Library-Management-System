#ifndef USER_FACTORY_H
#define USER_FACTORY_H

#include <memory>
#include "Admin.h"
#include "Member.h"

class UserFactory {
public:
    static std::shared_ptr<User> createUser(const std::string& type) {
        if (type == "admin") {
            return std::make_shared<Admin>();
        } else if (type == "member") {
            return std::make_shared<Member>();
        }
        return nullptr;
    }
};

#endif // USER_FACTORY_H