# NOTE: This file is generated by yotta: changes will be overwritten!

cmake_minimum_required(VERSION 2.8.11)

include_directories("/Users/Elliot/Documents/Internship/BeeBit/source")


set(YOTTA_AUTO_BEEBOT_CPP_FILES
    "/Users/Elliot/Documents/Internship/BeeBit/source/Controller.cpp"
)
# force dependency on the config header for cpp files, which CMake otherwise wouldn't track:
set_property(SOURCE ${YOTTA_AUTO_BEEBOT_CPP_FILES} PROPERTY OBJECT_DEPENDS "/Users/Elliot/Documents/Internship/BeeBit/build/bbc-microbit-classic-gcc/yotta_config.h")
set(YOTTA_AUTO_BEEBOT_HEADER_FILES
    "/Users/Elliot/Documents/Internship/BeeBit/source/controller.h"
)
# force dependency on the config header for header files, which CMake otherwise wouldn't track:
set_property(SOURCE ${YOTTA_AUTO_BEEBOT_HEADER_FILES} PROPERTY OBJECT_DEPENDS "/Users/Elliot/Documents/Internship/BeeBit/build/bbc-microbit-classic-gcc/yotta_config.h")


add_executable (beebot
    ${YOTTA_AUTO_BEEBOT_CPP_FILES}
    ${YOTTA_AUTO_BEEBOT_HEADER_FILES}
)
set_target_properties(beebot PROPERTIES ENABLE_EXPORTS ON)

yotta_postprocess_target(EXECUTABLE beebot)



target_link_libraries(beebot
    microbit
)

