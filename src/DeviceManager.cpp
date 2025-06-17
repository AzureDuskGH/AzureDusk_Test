#include "DeviceManager.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <unistd.h>

// 构造函数实现
DeviceManager::DeviceManager(const std::string& config_path) 
    : config_path_(config_path) {
    if (!load_from_file()) {
        std::cerr << "使用默认参数初始化\n";
        save_to_file();
    }
}

// to_json() 实现
json DeviceManager::to_json() const {
    return {
        {"device_name", params_.name},
        {"device_id", params_.id},
        {"voltage", params_.voltage},
        {"is_active", params_.is_active},
        {"calibration_data", params_.calibration_data}
    };
}

// print_parameters() 实现
void DeviceManager::print_parameters() const {
    std::cout << "\n===== 当前设备参数 =====\n";
    std::cout << "设备名称: " << params_.name << "\n";
    std::cout << "设备ID: " << params_.id << "\n";
    std::cout << "工作电压: " << params_.voltage << "V\n";
    std::cout << "激活状态: " << (params_.is_active ? "是" : "否") << "\n";
    
    std::cout << "校准数据: [";
    for (size_t i = 0; i < params_.calibration_data.size(); ++i) {
        if (i != 0) std::cout << ", ";
        std::cout << params_.calibration_data[i];
    }
    std::cout << "]\n";
}

// 实现 load_from_file()
bool DeviceManager::load_from_file() {
    std::ifstream file(config_path_);
    if (!file.is_open()) return false;
    
    try {
        json j;
        file >> j;
        from_json(j);
        return true;
    } catch (...) {
        return false;
    }
}

// 实现 save_to_file()
bool DeviceManager::save_to_file() const {
    std::ofstream file(config_path_);
    if (!file.is_open()) return false;
    
    file << to_json().dump(4);
    return true;
}

// 实现 update_parameter()
void DeviceManager::update_parameter(const std::string& key, const json& value) {
    if (key == "name") params_.name = value;
    else if (key == "id") params_.id = value;
    // ... 其他参数处理 ...
}

void DeviceManager::from_json(const json& j) {
    try {
        params_.name = j.at("device_name").get<std::string>();
        params_.id = j.at("device_id").get<int>();
        params_.voltage = j.at("voltage").get<double>();
        params_.is_active = j.at("is_active").get<bool>();
        params_.calibration_data = j.at("calibration_data").get<std::vector<int>>();
    } catch (const json::exception& e) {
        throw std::runtime_error("JSON解析错误: " + std::string(e.what()));
    }
}
// 其他已有实现...