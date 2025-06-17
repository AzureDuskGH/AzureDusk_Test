cmake_minimum_required(VERSION 3.10)
project(DeviceManager)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 创建data目录
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/data)

# 可执行文件
add_executable(device_manager
    src/main.cpp
    src/DeviceManager.cpp
)

# 包含目录
target_include_directories(device_manager PRIVATE include)

# 自动复制配置文件（首次运行）
add_custom_command(TARGET device_manager POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_SOURCE_DIR}/data/device_params.json
    ${CMAKE_BINARY_DIR}/data/device_params.json
)