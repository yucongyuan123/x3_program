#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <nlohmann/json.hpp>

int main(void) {
  std::cout << "test" << std::endl;
  std::string cmd = "ls";
  auto ret = system(cmd.c_str());

  using json = nlohmann::json;
  std::cout << "------------ nlohmann json test start --------------"
            << std::endl;
  // json j_test1 = R"(
  //     {
  //     "name": "Mike",
  //     "age": 15,
  //     "score": 85.5
  // }
  // )"_json;

  // json j_test2{{"name", "Mike"}, {"age", 15}, {"score", 85.5}};

  json json_file;
  const std::string data = "/mnt/learning/x3_program/src/test_json.json";
  std::ifstream f(data.data());
  std::cout << "tag1" << std::endl;
  if (!f.is_open()) {
    throw std::runtime_error("open config file failed, file:" + data);
  }

  std::cout << "tag2" << std::endl;
  f >> json_file;

  if (json_file.contains("test1")) {
    std::cout << "json_file exist 'test1'" << std::endl;
  }

  if (!json_file.contains("test11")) {
    std::cout << "json_file not exist 'test11' 。。" << std::endl;
    std::cout << "tag3" << std::endl;
  }
  std::cout << "------------ nlohmann json test end   --------------"
            << std::endl;
  return 0;
}