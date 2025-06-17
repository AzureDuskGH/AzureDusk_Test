#ifndef DEVICEMANAGER_H
#define DEVICEMANAGER_H

#include <string>
#include <vector>
#include "json.hpp"

using json = nlohmann::json;

class DeviceManager {
public:
    struct DeviceParams {
        std::string name = "Default Device";
        int id = 0;
        double voltage = 220.0;
        bool is_active = true;
        std::vector<int> calibration_data;
    };
    
    // 构造函数
    explicit DeviceManager(const std::string& config_path);
    
    // 成员函数
    void update_parameter(const std::string& key, const json& value);
    void print_parameters() const;
    bool load_from_file();
    bool save_to_file() const;
    
private:
    DeviceParams params_;
    std::string config_path_;
    
    // 改为私有实现（不需要在头文件暴露）
    json to_json() const;  // 保持声明
    void from_json(const json& j);
};

#endif