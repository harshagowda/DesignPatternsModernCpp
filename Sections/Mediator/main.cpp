#include <iostream>
#include "Chatroom.h"

int main() {
    // Can't create Chatroom in stack memory due to enable_shared_from_this<>.
    auto room = std::make_shared<Chatroom>();

    auto john = std::make_shared<Person>("John");
    auto jane = std::make_shared<Person>("Jane");
    room->join(john);
    room->join(jane);
    john->say("Hi, my name is John.");
    jane->say("Hi John, my name is Jane.");
    auto simon = std::make_shared<Person>("Simon");
    room->join(simon);
    simon->say("Hi everyone.");
    john->private_message("Simon", "Glad you found us.");

    return 0;
}