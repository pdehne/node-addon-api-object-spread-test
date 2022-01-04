project (nodeaddonapiobjectspreadtest)
include_directories(${CMAKE_JS_INC})

set(ProjectSourcesDir "${PROJECT_SOURCE_DIR}/src")

set(SOURCES
    ${ProjectSourcesDir}/nodeaddonapiobjectspreadtest.cpp
    ${ProjectSourcesDir}/SampleObject.cpp
)

add_library(${PROJECT_NAME} SHARED ${SOURCES} ${CMAKE_JS_SRC})
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "" SUFFIX ".node")
target_link_libraries(${PROJECT_NAME} ${CMAKE_JS_LIB})

execute_process(COMMAND node -p "require('node-addon-api').include"
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    OUTPUT_VARIABLE NODE_ADDON_API_DIR
    )
string(REGEX REPLACE "[\r\n\"]" "" NODE_ADDON_API_DIR ${NODE_ADDON_API_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${NODE_ADDON_API_DIR})

target_include_directories(${PROJECT_NAME} PRIVATE ${ProjectSourcesDir})

add_definitions(-DNAPI_VERSION=8)
add_definitions(-DNAPI_EXPERIMENTAL)